/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#if defined(__c128z__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0xFF,  0, "BLACK" },
        { 0x22, 0x22, 0x22, 0xFF,  1, "LIGHT BLACK" },
        { 0x00, 0x00, 0x88, 0xFF,  2, "DARK BLUE" },
        { 0x00, 0x00, 0xFF, 0xFF,  3, "LIGHT BLUE" },
        { 0x00, 0x88, 0x00, 0xFF,  4, "DARK GREEN" },
        { 0x00, 0xFF, 0x00, 0xFF,  5, "LIGHT GREEN" },
        { 0x00, 0x88, 0x88, 0xFF,  6, "DARK CYAN" },
        { 0x00, 0xFF, 0xFF, 0xFF,  7, "LIGHT CYAN" },
        { 0x88, 0x00, 0x00, 0xFF,  8, "DARK RED" },
        { 0xFF, 0x00, 0x00, 0xFF,  9, "LIGHT RED" },
        { 0x80, 0x40, 0x80, 0xFF, 10, "DARK PURPLE" },
        { 0xFF, 0x80, 0xFF, 0xFF, 11, "LIGHT PURPLE" },
        { 0x80, 0x80, 0x40, 0xFF, 12, "DARK YELLOW" },
        { 0xFF, 0xFF, 0x80, 0xFF, 13, "LIGHT YELLOW" },
        { 0x80, 0x80, 0x80, 0xFF, 14, "DARK WHITE" },
        { 0xFF, 0xFF, 0xFF, 0xFF, 15, "LIGHT WHITE" },
};

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * vdcz_image_nearest_system_color( RGBi * _color ) {

    unsigned int minDistance = 0xffff;
    int colorIndex = 0;
    for (int j = 0; j < COLOR_COUNT; ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], _color);
        if (distance < minDistance) {
            minDistance = distance;
            colorIndex = j;
        }
    }

    return &SYSTEM_PALETTE[colorIndex];

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case BITMAP_MODE_STANDARD:
        case BITMAP_MODE_STANDARD_INT:
            return 3 + ( ( _width >> 3 ) * _height ) + 1;
        case BITMAP_MODE_MULTICOLOR:
        case BITMAP_MODE_MULTICOLOR_INT:
            return 3 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height >> 3 ) );
    }
    return 0;

}

static Variable * vcdz_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
    commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
    lastUsedSlotInCommonPalette = paletteColorCount;
    adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );
    adilinepalette( "CPMS:%ld", sizeof(SYSTEM_PALETTE) / sizeof(RGBi), SYSTEM_PALETTE );

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_STANDARD );
    // printf("bufferSize = %d\n", bufferSize );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_STANDARD );

    char * buffer = malloc ( bufferSize );
    memset( buffer, 0, bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, bitmask;

    // Color of the pixel to convert
    RGBi rgb;

    *(buffer) = (_frame_width & 0XFF );
    *(buffer+1) = ( (_frame_width>>8) & 0XFF );
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    adilinebeginbitmap("BMD");

    int colorIndex = 0;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            int minDistance = 9999;
            for( int i=0; i<2; ++i ) {
                int distance = rgbi_distance(&commonPalette[i], &rgb );
                if ( distance < minDistance ) {
                    minDistance = distance;
                    colorIndex = commonPalette[i].index;
                }
            }

            offset = ( image_y * ( _frame_width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( colorIndex == commonPalette[1].index) {
                *( buffer + offset + 3) |= bitmask;
            } else {
                *( buffer + offset + 3) &= ~bitmask;
            }

            adilinepixel(colorIndex);

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        // printf("\n" );

    }

    *( buffer + 3 + ( ( _frame_width >> 3 ) * _height ) ) = ( commonPalette[1].index << 4 ) | commonPalette[0].index;

    adilineendbitmap();

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

/**
 * This method can be used to convert 
 *     8x8 RGB (3 bytes) pixel (_source) [8x8x3 = 192 bytes]
 * into 
 *       foreground and background color (_dest)
 * 
 * Since the 8x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze.
 */
static void vdcz_image_converter_tile( Environment * _environment, char * _source, char * _dest, int _width, int _depth, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];
    memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );
    int trans = 0;

    char * source = _source;

    // Clear the colors
    *_dest = 0;

    // Loop for all the box surface
    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            // Take the color of the pixel
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            if ( rgb.alpha < 255 ) {
                trans = 1;
            } else {
                RGBi *systemRgb = vdcz_image_nearest_system_color( &rgb );
                ++colorIndexesCount[systemRgb->index];
            }

            source += _depth;

        }

        source += _depth * ( _source_width - 8 );

    }

    int colorBackground = 0;
    int colorBackgroundMax = 0;
    int colorForeground = 0;
    int colorForegroundMax = 0;
    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorBackgroundMax ) {
            colorBackground = xx;
            colorBackgroundMax = colorIndexesCount[xx];
        };
    }

    colorIndexesCount[colorBackground] = 0;

    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorForegroundMax ) {
            colorForeground = xx;
            colorForegroundMax = colorIndexesCount[xx];
        };
    }

    if ( trans ) {
        if ( colorForeground == 0 ) {
            colorForeground = colorBackground; 
            colorBackground = 0;
        } else {
            colorBackground = 0;
        }
    }

    *( _dest ) = ( colorForeground << 4 ) | colorBackground ;

}

/**
 * This method can be used to convert 
 *     WxH RGB (3/4 bytes) pixel (_source) [WxHx3/4 bytes]
 * into 
 *     WxH bitmap (1 bit) pixel + (W/8xH + W/8xH/8) (bytes)
 *       foreground and background color (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze.
 */
static void vdcz_image_converter_tiles( Environment * _environment, char * _source, char * _dest, int _width, int _height, int _depth, int _source_width ) {

    int bitmapSize = ( _width>>3 ) * _height;
    int colormapSize = ( _width>>3 ) * (_height>>3);

    char * destBitmap = _dest;
    char * destColormap = _dest + bitmapSize;

    memset( _dest, 0, bitmapSize + colormapSize );

    adilinebeginbitmap("BMD3");

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=8 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * _depth;
            char tile;

            vdcz_image_converter_tile( _environment, source, &tile, _width, _depth, _source_width );

            int offset = ((y>>3) * 8 *( _width >> 3 ) ) + ((x>>3) * 8) + ((y) & 0x07);

            destColormap[offset] = tile;
        }
    }

    // Color of the pixel to convert
    RGBi rgb;

    int offset, bitmask;

    int colorIndex = 0;

    // Loop for all the source surface.
    for (int image_y = 0; image_y < _height; ++image_y) {
        for (int image_x = 0; image_x < _width; ++image_x) {

            int offsetColor = ((image_y>>3) * 8 *( _width >> 3 ) ) + ((image_x>>3) * 8) + ((image_y) & 0x07);

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            int minDistance = 9999;
            for( int i=0; i<2; ++i ) {
                int distance = rgbi_distance(&commonPalette[i], &rgb );
                if ( distance < minDistance ) {
                    minDistance = distance;
                    colorIndex = rgb.index;
                }
            }

            offset = ( image_y * ( _width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( colorIndex != ( ( destColormap[offsetColor] >> 4 ) & 0x0f ) ) {
                *( destBitmap + offset + 3) |= bitmask;
                adilinepixel( destColormap[offsetColor] & 0x0f );
            } else {
                *( destBitmap + offset + 3) &= ~bitmask;
                adilinepixel( ( destColormap[offsetColor] >> 4 ) & 0x0f );
            }

            _source += _depth;

        }
    }

    adilineendbitmap();

}

static Variable * vdcz_image_converter_bitmap_mode_multicolor( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 16) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
    commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
    lastUsedSlotInCommonPalette = paletteColorCount;
    adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    adilinepalette( "CPMS:%ld", sizeof(SYSTEM_PALETTE) / sizeof(RGBi), SYSTEM_PALETTE );

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_MULTICOLOR );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_MULTICOLOR );

    // printf("bufferSize = %d\n", bufferSize );

    char * buffer = malloc ( bufferSize );
    memset( buffer, 0, bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, bitmask;

    // Color of the pixel to convert
    RGBi rgb;

    *(buffer) = ( _frame_width & 0xff );
    *(buffer+1) = ( (_frame_width>>8) & 0xff );
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    vdcz_image_converter_tiles( _environment, _source, buffer+3, _frame_width, _frame_height, _depth, _width );

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

/**
 * @brief <i>VDCZ</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * vdcz_collision( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_SPRITE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(collision result)");

    MAKE_LABEL

    return result;

}

/**
 * @brief <i>VDCZ</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void vdcz_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    // Generate unique label for ASM code.
    MAKE_LABEL

}

/**
 * @brief <i>VDCZ</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void vdcz_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdcz_background_color( Environment * _environment, int _index, int _background_color ) {

    outline1("LD A, $%2.2x", _background_color & 0x0f );
    outline0("LD B, A" );
    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline0("CALL VDCZREAD");
    outline0("AND $F0" );
    outline0("OR B" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");


}

/**
 * @brief <i>VDCZ</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdcz_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    outline1("LD A, (%s)", _background_color );
    outline0("LD B, A" );
    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline0("CALL VDCZREAD");
    outline0("AND $F0" );
    outline0("OR B" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

}

/**
 * @brief <i>VDCZ</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdcz_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    outline1("LD A, (%s)", _background_color );
    outline0("SLA A" );
    outline0("SLA A" );
    outline0("SLA A" );
    outline0("SLA A" );
    outline0("LD B, A" );
    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline0("CALL VDCZREAD");
    outline0("AND $F0" );
    outline0("OR B" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

}

/**
 * @brief <i>VDCZ</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdcz_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline0("CALL VDCZREAD");
    outline1("LD (%s), A", _background_color );

}

/**
 * @brief <i>VDCZ</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void vdcz_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {
 
}

/**
 * @brief <i>VDCZ</i>: emit code to set raster irq
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void vdcz_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void vdcz_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to wait for next raster irq at different position
 * 
 * This function outputs assembly code needed to wait for the
 * next raster on a different position with a different code to
 * execute. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void vdcz_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void vdcz_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vdcz_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void vdcz_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VDCZ</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vdcz_disable_mcm( Environment * _environment ) {

}

void vdcz_bank_select( Environment * _environment, int _bank ) {
    
}

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int colorIndex = 0;
    unsigned int minDistance = 0xffffffff;
    int j;

    RGBi rgb;
    rgb.red = _red;
    rgb.green = _green;
    rgb.blue = _blue;

    for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], &rgb);
        if (distance < minDistance) {
            minDistance = distance;
            colorIndex = j;
        }
    }

    return colorIndex;

}

int vdcz_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    cpu_store_8bit( _environment, "_PEN", DEFAULT_PEN_COLOR );
    cpu_store_8bit( _environment, "_PAPER", DEFAULT_PAPER_COLOR );

    int horizontalCharactersPositions = 127;
    int horizontalVerticalSyncWidth = 0x49;
    int horizontalSyncPosition = 102;
    int totalNumberOfScreenRows = 39;
    int verticalFineAdjustment = 0;
    int numberOfVisibleScreenRows;
    int verticalSyncPosition = 32;
    int interlaceModeControl = 0;
    int totalScanLinePerCharacter = 7;
    int verticalSmoothScrollingAndControl = 8;
    int horizontalSmoothScrollingAndControl = 0;
    int addressIncrementPerRowOfChars = 0;
    int characterPatternAddress = 1;

    switch( _screen_mode->id ) {
        case TILEMAP_MODE_STANDARD:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;
            _environment->currentModeBW = 0;

            numberOfVisibleScreenRows = _environment->screenTilesHeight;
            horizontalSmoothScrollingAndControl = 0x07;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );
            cpu_store_16bit( _environment, "COLORMAPADDRESS", 0x0800 );

            break;

        case BITMAP_MODE_STANDARD:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;

            numberOfVisibleScreenRows = _environment->screenTilesHeight;
            horizontalSmoothScrollingAndControl = 0x87;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );
            cpu_store_16bit( _environment, "COLORMAPADDRESS", 0x4000 );

            break;

        case BITMAP_MODE_MULTICOLOR:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 22;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;
            _environment->currentModeBW = 1;

            numberOfVisibleScreenRows = _environment->screenTilesHeight;
            horizontalSmoothScrollingAndControl = 0x87;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );
            cpu_store_16bit( _environment, "COLORMAPADDRESS", 0x3700 );

            outline0("LD A, $08");
            outline0("LD IXH, A");
            outline0("LD A, 0");
            outline0("LD IXL, A");
            outline0("CALL VDCZWRITE");

            break;

        case BITMAP_MODE_STANDARD_INT:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 50;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;

            horizontalCharactersPositions = 0x7e;
            horizontalVerticalSyncWidth = 0x89;
            horizontalSyncPosition = 0x66;
            totalNumberOfScreenRows = 0x4c;
            verticalFineAdjustment = 6;
            numberOfVisibleScreenRows = 0x4c;
            verticalSyncPosition = 0x47;
            interlaceModeControl = 3;
            totalScanLinePerCharacter = 6;
            verticalSmoothScrollingAndControl = 0;
            horizontalSmoothScrollingAndControl = 0x87;
            addressIncrementPerRowOfChars = 0;
            characterPatternAddress = 16;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );
            cpu_store_16bit( _environment, "COLORMAPADDRESS", 0x4000 );

            break;

        case BITMAP_MODE_MULTICOLOR_INT:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 44;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;
            _environment->currentModeBW = 1;

            horizontalCharactersPositions = 0x7e;
            horizontalVerticalSyncWidth = 0x89;
            horizontalSyncPosition = 0x66;
            totalNumberOfScreenRows = 0x4c;
            verticalFineAdjustment = 6;
            numberOfVisibleScreenRows = 0x4c;
            verticalSyncPosition = 0x47;
            interlaceModeControl = 3;
            totalScanLinePerCharacter = 6;
            verticalSmoothScrollingAndControl = 0;
            horizontalSmoothScrollingAndControl = 0x87;
            addressIncrementPerRowOfChars = 0;
            characterPatternAddress = 16;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );
            cpu_store_16bit( _environment, "COLORMAPADDRESS", 0x3700 );
            
            break;

    }

    /////////////////////////////////////////////////////////////////
    // -- [ $00 ] --
    /////////////////////////////////////////////////////////////////

    // Total number of horizontal character positions

    // The value in this register determines the total width (in character
    // positions) of each horizontal line of the display. The
    // value stored here should be one less than the desired number
    // of horizontal character positions. This total includes the active
    // portion of the display (where characters can be displayed), the
    // left and right borders, and the horizontal sync width. The total
    // number of horizontal pixels is given by multiplying the value
    // here (plus 1) by the total number of pixels per character position
    // (the value in bits 4-7 of register 22/$16 plus 1).

    // The default value for this register, established during the
    // IO1NIT routine [$E109], is 126/$7E, This provides 127 horizontal
    // character positions. You'll need to reduce this by half if
    // you enable the pixel double feature (see the entry for bit 4 of
    // register 25/$19). You may need to increase the value here
    // slightly if you use one of the interlaced modes.

    outline0("LD A, $00");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", horizontalCharactersPositions );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $01 ] --
    /////////////////////////////////////////////////////////////////

    // Number of active horizontal character positions

    // The value in this register determines how many of the horizontal
    // character positions specified in register 0/$00 can actually
    // be used to display characters. The value stored here
    // should be the desired number of columns for the display. The
    // value here must be less than the value in register 0/$00. The
    // default value for this register is 80/$50, since the default VDC
    // display is an 80-column text screen. The value here also determines
    // the width of the bitmap when the VDC is set for graphic
    // mode. The bitmap width is given by multiplying the number
    // of character positions by the character-position width specified
    // in bits 0-3 of register 22/$16.

    outline0("LD A, $01");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", _environment->screenTilesWidth );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $02 ] --
    /////////////////////////////////////////////////////////////////

    // Horizontal sync position

    // The value in this register determines the character position at
    // which the vertical sync pulse begins. The value here also determines
    // the horizontal position of the active portion of the
    // screen within the total display. The default value here is
    // 102/$66. Increasing this value moves the active screen area to
    // the left; decreasing it moves the active area to the right.

    outline0("LD A, $02");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", horizontalSyncPosition );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $03 ] --
    /////////////////////////////////////////////////////////////////

    // Horizontal and vertical sync width

    // Bits 0-3: These bits specify the width of the horizontal sync
    // pulse. The value here should be one greater than the desired
    // number of character positions for the pulse. The default value
    // for these bits is 9/$9, for a pulse eight character positions wide.
    // Bits 4-7: These bits specify the width of the vertical sync
    // pulse. The bit value here should be equal to the desired number
    // of scan lines for the pulse, unless the interlaced sync and
    // video mode is being used (in that case, use a value that is
    // twice the desired number of scan lines). The default value for
    // these bits is 4/$4, for a pulse four scan lines wide.

    outline0("LD A, $03");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", horizontalVerticalSyncWidth );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $04 ] --
    /////////////////////////////////////////////////////////////////

    // Total number of screen rows

    // This register specifies the total height (in character positions)
    // of the VDC display. The value stored here should be one less
    // than the desired number of vertical character positions. The
    // total includes the rows for the active display, the top and bottom
    // portions of the border, and the vertical sync width. To determine
    // the height of the raster in scan lines, multiply the
    // value in this register (plus 1) by the number of scan lines per
    // character position (the value in register 9/S09 plus 1) and add
    // any additional scan lines specified in register 5/$05.

    // The proper number of scan lines for the display is a function
    // of the video system being used; it's different for NTSC
    // (North American) and PAL (European) systems. During the
    // IOINIT routine [$E109], the 128 checks the VIC chip to deter-
    // mine which system is being used (since the VIC isn't programmable
    // like the VDC, there is a different version of the
    // VIC for each of the two video systems). This register is then
    // initialized accordingly: to 32/$20 for NTSC systems or 39/$27
    // for PAL systems, selecting 33 or 40 rows, respectively. Since
    // the default character-position height is eight scan lines, the respective
    // total heights are 33 * 8, or 264 lines, for NTSC, and
    // 40 * 8, or 320 scan lines, for PAL. These scan-line totals
    // should remain constant, so if you increase the character height
    // you must decrease the total number of rows, and vice versa.

    outline0("LD A, $04");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", totalNumberOfScreenRows );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $05 ] --
    /////////////////////////////////////////////////////////////////

    // Vertical fine adjustment

    // Bits 0-4: The total number of scan lines in the VDC's video
    // display should be 264 for an NTSC (North American) system
    // or 320 for a PAL (European) system. The number of scan lines
    // used in the VDC display is given by the total number of vertical
    // positions (specified in register 4/S04) multiplied by the
    // number of scan lines per character position (specified in register
    // 9/$09). If the result doesn't come out exactly equal to the
    // required 264 or 320, the VDC can add a few extra scan lines at
    // the end to achieve the proper result. The value in this register
    // specifies the number of extra scan lines to add. The available
    // five bits allow up to % 11111 = 31 / $1f additional scan lines.
    // The default character height of eight scan lines is an exact
    // multiple of both 264 and 320 (33 * 8 = 264 and 40 * 8 =
    // 320). Thus, no extra scan lines are required, so this register is
    // initialized to 0/$00 by the Kernal IOINIT routine [$E109]. As
    // an example of the use of this register, assume that you increased
    // the character height to nine scan lines. For an NTSC
    // system, 264 / 9 = 29 with a remainder of 3. Thus, for this
    // case you should specify 29 for the total number of vertical
    // character positions and store a 3 in this register to provide the
    // required additional scan lines.

    outline0("LD A, $05");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", verticalFineAdjustment );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $06 ] --
    /////////////////////////////////////////////////////////////////

    // Number of visible screen rows

    // The value in this register determines how many of the vertical
    // character positions specified in register 4/S04 can actually be
    // used to display characters. The value here must be less than
    // the total number specified in register 4/$04. The default value
    // established for this register by the Kernal IOINIT routine
    // [$E109] is 25/$19, which sets up the standard 25-row display.

    outline0("LD A, $06");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", numberOfVisibleScreenRows );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $07 ] --
    /////////////////////////////////////////////////////////////////

    // Vertical sync position

    // The value in this register determines the vertical character position
    // at which the vertical sync signal will be generated. This
    // register can be used to adjust the vertical location of the active
    // display area within the screen. The default value for this register,
    // established by the IOINIT routine [$E109], is 29/S1D for
    // NTSC (North American) systems or 32/S20 for PAL (European)
    // systems. Decreasing the value here will move the active
    // display area down the screen, while increasing the value will
    // move the active display area upwards. However, you should
    // not increase the value here above the maximum number of
    // rows specified in register 4/$04.

    outline0("LD A, $07");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", verticalSyncPosition );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $08 ] --
    /////////////////////////////////////////////////////////////////

    // Interlace mode control

    // Bits 0-1: The value in these bits controls the interlace mode of
    // the screen. The complete standard for NTSC video calls for a
    // frame (raster) of 525 lines to be redrawn 30 times per second,
    // while the PAL standard calls for 625 lines redrawn 25 times
    // per second. The full screen isn't drawn all at once; instead, it's
    // drawn in two passes with half the lines for the frame drawn
    // on each pass. The lines for the second pass of the frame are
    // 439 drawn between the lines for the first. Like most computer displays,
    // the VDC normally takes a shortcut and draws half the
    // full number of lines at twice the rate. This noninterlaced display
    // provides sufficiently sharp output for most uses. However,
    // the VDC is also capable of producing two interlaced
    // display modes. The modes are selected as follows:

    // Bits
    // 1 0 Value Interlace mode
    // x 0 0 or 2 noninterlaced
    // 0 1 1 interlaced sync
    // 1 1 3 interlaced sync and video

    // The default value is 0/$00, which selects the standard
    // noninterlaced mode. The system never uses any other mode.
    // In the interlaced sync mode, the number of scan lines is doubled.
    // Each horizontal scan line is drawn twice, once on the
    // first pass and very slightly lower on the second pass. The result
    // should be greatly improved vertical resolution, but you'll
    // probably be disappointed. Remember that each tiny dot on the
    // screen glows only very briefly after being struck by the raster
    // video beam. Since this mode must draw twice as many lines,
    // it draws each line only half as often. On most video monitors,
    // the first set of lines will have started to fade before the second
    // set is completely drawn. As a result, the screen will appear to
    // jitter annoyingly in this mode.

    outline0("LD A, $08");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", interlaceModeControl );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $09 ] --
    /////////////////////////////////////////////////////////////////

    // Total number of scan lines per character

    // Bits 0-4: These bits determine the total vertical height (in scan
    // lines) of each character position. The value stored here should
    // be one less than the desired number of scan lines. The total
    // vertical height value includes the scan lines for the active portion
    // of each character position, plus any desired number of
    // blank scan lines for intercharacter vertical spacing. The height
    // of the active portion of the character position is determined by
    // the value in register 23/$17.

    // The default value for this register, established during the
    // IOINIT routine [SE109], is 7/$07, for a total character-position
    // height of eight scan lines. In this case, there will be no vertical
    // intercharacter spacing because this is less than the active character
    // height. (In the default character set, intercharacter spacing
    // is achieved by leaving the bottom row of the character pattern
    // blank.) The five available bits allow values up to %11111 =
    // 31/$IF, for character-position heights of up to 32 scan lines.
    // However, when changing this value to allow for greater vertical
    // resolution, you must keep in mind that the value here multiplied
    // by the total number of rows specified in register 4/$04
    // (and plus the number of extra scan lines specified in register
    // 5/$05) determines the number of scan lines in the display.
    // This total should always be 264 lines for NTSC (North American)
    // systems or 320 lines for PAL (European) systems.
    // The value here also determines how much memory is required
    // for character pattern memory. While the value here is
    // less than or equal to 15 (while the character height is 16 or
    // fewer scan lines), each character pattern is allocated 16 bytes.
    // Since the VDC supports two complete 256-character sets, a total
    // of 512 * 16, or 8192 bytes, are required for character memory'
    // However, if the character height exceeds 16 scan lines (if
    // the value here is greater than 15), then 32 bytes are allocated
    // for each character pattern. In this case, 512 * 32, or 16,384
    // bytes, are required for character memory. Note that this is all
    // the memory available to the VDC.

    outline0("LD A, $09");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", totalScanLinePerCharacter );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $0A ] --
    /////////////////////////////////////////////////////////////////

    // Cursor mode control

    // Bits 0-4: The value in these bits determines the scan line
    // within each character position for the top of the cursor. Scan
    // lines within character positions are numbered beginning with
    // 0 for the top line of the position. Bits 0-4 of register ll/$0B
    // determine the bottom line, and together these registers determine
    // the height of the cursor. The available five bits allow
    // starting row numbers as large as %11111 = 31/$1F. The default
    // value for these bits is %00000, to start the cursor at character
    // scan line 0, the top line of the character, for the standard
    // full-height block cursor. The operating system also supports
    // an underline cursor, selected by printing ESC U [$CAFE], In
    // this case, the value here is changed to %00111 (7) to start the
    // cursor on the bottom line of the standard character position.
    // The value for the top scan line should be no greater than the
    // maximum number of scan lines specified in register 9/$09, or
    // else the cursor will not be visible.

    // Bits 5-6: These bits control the type of cursor provided. Unlike
    // the VIC, where the cursor is an effect maintained by software,
    // the VDC has hardware to generate a cursor automatically. The
    // possible modes are as follows:

    // Bit values Cursor mode
    // 0/$00 solid {nonblinking) cursor
    // 32/S20 no cursor
    // 64/$40 blinking at 1/16 screen refresh rate
    // 96/$60 blinking at 1/32 screen refresh rate

    // The default setting for these bits is %11, specifying a cursor
    // blinking at the slower of the two rates. The operating system
    // also supports a nonblinking cursor, selected by printing ESC E
    // [$CB0B]. In this case, the bits are changed to %00. To rum the
    // cursor off when the system is not accepting input (as when a
    // program is running), these bits are reset to %01 [$CD9F].

    outline0("LD A, $0a");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", 0x20 );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $0B ] --
    /////////////////////////////////////////////////////////////////

    // Bottom scan line for cursor

    // Bits 0-4: These bits determine the scan line within a character
    // position for the bottom of the cursor. Together with bits 0-4
    // of register 10/$0A, this serves to determine the height of the
    // cursor. The value here should be one greater than the desired
    // bottom scan line (scan-line numbering starts with 0 for the top
    // scan line of the character position). The five available bits
    // allow values up to % 11111 = 31/$1F, so the cursor can go as
    // low as scan line 30, However, the actual displayed cursor
    // height will never be greater than the character-position height
    // specified in register 9/$09. The default value for this register,
    // established by the IOINIT routine [$E109], is 7/$07, so the
    // normal bottom scan line of the cursor is scan line 6 of the
    // character position.

    outline0("LD A, $0b");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", 7 );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $0C+$0D ] --
    /////////////////////////////////////////////////////////////////

    // Starting address for screen memory

    // For standard text mode, the value in this register pair determines
    // the starting address for screen memory, the area which
    // holds screen codes specifying which character will be displayed
    // in each screen position. The size of the screen memory area is
    // determined by the number of active horizontal positions (specified
    // in register l/$01) multiplied by the number of active rows
    // (specified in register 6/$06) and the address increment per
    // row (specified in register 27/$lB). The order of bytes for the
    // pair is opposite that normally used in the 128 system: The first
    // register (12/$0C) holds the high byte and the second (13/$0D)
    // holds the low byte. Unlike VIC screen memory, which must
    // begin on an even IK address boundary, VDC screen memory
    // can begin at any address in the VDC's address space. 
    
    // For graphic mode, the value in this register pair determines
    // the starting address for the bitmap of the graphic
    // screen. The amount of memory required for the bitmap is
    // found by multiplying the number of horizontal character positions
    // (from register l/$01) by the number of vertical character
    // positions (in register 6/$06) times the total height of each
    // character position (from register 9/$09 plus 1). The bitmap
    // can be started at any address in the VDC address space.
    // Even if you change the value here, the screen editor ROM
    // routines will continue to assume that screen memory is located
    // in its default position unless you also change the value in the
    // screen memory starting-page pointer at 2606/$0A2E.

    outline0("LD A, $0c");
    outline0("LD IXH, A");
    outline0("LD A, (TEXTADDRESS+1)" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");
    outline0("LD A, $0d");
    outline0("LD IXH, A");
    outline0("LD A, (TEXTADDRESS)" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $0E+$0F ] --
    /////////////////////////////////////////////////////////////////

    // Address of current cursor position

    // For the VIC chip's display, the cursor is an effect laboriously
    // maintained by software. The VDC, by contrast, has hardware
    // to maintain the cursor for its display automatically. The cursor
    // will appear at the character position with the screen memory
    // location specified in this register pair. If the address specified
    // here is outside the area of VDC memory currently being used
    // for screen memory, no cursor will be visible. Other characteristics
    // of the cursor such as its blinking status and position within
    // the character are specified in registers 10/$OA and 11/$OB.
    // 444

    // outline0("LD A, $0e");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");
    // outline0("LD A, $0f");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $10-$11 ] --
    /////////////////////////////////////////////////////////////////

    // Light pen vertical and horizontal positions

    // Whenever the LP input line to the VDC chip is brought to a
    // low (0 volts) state, the row and column values for the current
    // position of the raster beam are latched into these registers. The
    // vertical (row) number will be latched into register 16/$10, and
    // the horizontal (column) number will be latched into register
    // 17/$11. To signal that a value has been latched, the LP flag
    // (bit 6 of the external register at 54784/SD600) will be set to
    // %1. That bit will remain at %1 until either of these registers is
    // read, at which time it will be reset to %0. However, reading
    // these registers does not clear them; the latched values will be
    // retained until the LP line is brought low again.

    // The VDC's LP line is connected to pin 6 of control port 1
    // (control port 2 does not support a light pen). A light pen has
    // at its tip an electronic device known as a phototransistor,
    // which is connected so as to cause a low pulse whenever the
    // video beam moves past the pen. Note that the pen will not be
    // triggered if the screen position is black or one of the other
    // dark colors. Only positions which have bright characters can
    // be read. The ideal character to read with a light pen is a white
    // reverse video space.

    // When a light pen is used, the range of values in these
    // registers depends on the screen width and height selected by
    // other VDC registers. Unlike the VIC chip, whose light pen
    // registers return scan line and dot position values, these registers
    // return row and column numbers corresponding to the
    // light pen position. This makes the results much easier to interpret,
    // but does not allow precise positioning, so it is unlikely
    // that you'll see any 80-column drawing programs using the
    // light pen as an input device. For the standard 80-column X
    // 25-line screen, the value in register 16/$ 10 corresponds very
    // closely to the row number: ranging from l/$01 at the top of
    // the screen to 25/$19 at the bottom. Actually, you may find
    // that if you position the pen slightly below the bottom screen
    // line you can get a reading of 26/S1A.

    // While the vertical resolution is good, the horizontal resolution
    // is quite poor. The horizontal reading won't correspond
    // to the row number (1-80). Instead, it corresponds approximately
    // to the absolute horizontal character position, which includes
    // the border areas on the left and right edges of the
    // screen. You should find that when the pen is pointed at the
    // leftmost character position, you get a reading of about 27-29
    // in register 17/$11. This implies that the rightmost character
    // position should give readings of about 106-108. Actually, you
    // may get higher readings—120 or more. In fact, even if you
    // hold the pen perfectly stil] you may see the character position
    // vary up or down by 4 or 5. The moral is that the light pen is
    // much better at reading vertical than horizontal positions.
    // You'll have better luck if you limit yourself to checking
    // whether the pen is within a range of horizontal positions. For
    // example, if you read the horizontal position and store the result
    // in the variable H, then an expression such as H = INT({H
    // — 30) / 8) will return a range of values 0-9 indicating
    // roughly which one of ten eight-column horizontal areas the
    // pen is pointing to.

    // You should be aware that these registers can be tricked
    // into reading false values. Pin 6 of control port 1 is also used
    // for light pen input for the VIC chip, and a light pen signal
    // generated on the 40-column screen will latch meaningless values
    // in these registers. In lieu of a light pen, several other
    // events can cause a pulse on the LP line. That control port pin
    // is also used for the joystick fire button, so pressing the button
    // of a joystick plugged into port 1 will also latch values in these
    // registers. Because of this joystick button function, the port line
    // is also connected to the line from row 4 of the keyboard matrix.
    // This has two consequences. First, pressing any of the following
    // keys with no light pen connected will latch meaningless
    // values: Fl, Z, C, B, M, period, right SHIFT, space, the 2 and
    // ENTER keys on the numeric keypad, and the ^ key in the
    // cursor group. More significantly, while a light pen is connected,
    // all of these keys will be "dead," and cannot be typed.

    // outline0("LD A, $10");
    // outline0("LD IXH, A");
    // outline0("CALL VDCZREAD");
    // outline0("LD A, $11");
    // outline0("LD IXH, A");
    // outline0("CALL VDCZREAD");

    /////////////////////////////////////////////////////////////////
    // -- [ $12-$13 ] --
    /////////////////////////////////////////////////////////////////

    // Current memory address

    // This register pair specifies which address in the VDC's private
    // block of RAM will be referenced by the next read or store operation
    // involving register 31/S1F. As with the other VDC address
    // register pairs, the first register (18/$12) holds the high
    // byte of the address and the second (19/$13) holds the low
    // byte. A value stored in register 31/$1F is transferred to the
    // VDC memory location specified in this register pair. Reading
    // register 31/$1F returns the value in the location in VDC memory
    // with the address specified in this register pair. For copy or
    // fill operations, the value in these registers determines the destination
    // address for the operation. These registers are autoincrementing,
    // meaning that the address value here is automatically
    // increased by 1 after each read or store to register
    // 31/S1F. Thus, when you wish to read or load a continuous series
    // of VDC memory locations you only need to set the memory
    // address in these registers before the first read or store.
    // After that, you can just read from or write to register 31/$1F
    // and the address will be handled automatically.

    // outline0("LD A, $12");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");
    // outline0("LD A, $13");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $14-$15 ] --
    /////////////////////////////////////////////////////////////////

    // Starting address for attribute memory

    // When attributes are activated, this register pair determines the
    // starting address for attribute memory, the area which holds
    // attribute values for each active character position on the
    // screen. (Attributes can be turned on and off by setting bit 6 of
    // register 25/$19.) The size of the attribute memory area depends
    // on the number of active rows and columns specified in
    // registers 2/$02 and 6/$06, and will be the same as the size of
    // the screen memory area. See the discussion of attributes in the
    // introduction to this section for more information.

    // These locations are initialized to 2048/S0800, the default
    // starting address for attribute memory. Like the other address
    // pairs in the VDC, the first register (20/$14) holds the high
    // byte and the second (21/$15) holds the low byte. Attribute
    // memory can start at any address within the VDC's address
    // space. Even if you change the value here, the screen editor
    // ROM routines will continue to assume that attribute memory
    // is in its default position unless you also change the value in
    // the attribute starting-page pointer at 2607/$0A2F.

    outline0("LD A, $14");
    outline0("LD IXH, A");
    outline0("LD A, (COLORMAPADDRESS+1)" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");
    outline0("LD A, $15");
    outline0("LD IXH, A");
    outline0("LD A, (COLORMAPADDRESS)" );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $16 ] --
    /////////////////////////////////////////////////////////////////

    // Character horizontal size control

    // Bits 0-3: The value in these bits determines how many of the
    // total horizontal pixels in the character position will be used to
    // display character pattern data. (The total number is specified
    // in bits 4-7 of this register.) If the number of active pixels is
    // less than the total number of pixels, the extra pixels will be
    // blank for intercharacter spacing. If you specify a value here
    // that is greater than the total number of pixels available for the
    // position, only the specified total number of pixels will be visible.
    // However, the value here should not exceed 8, since a
    // maximum of eight bits are available per byte of character pattern
    // data. Even for values greater than 8, no more than eight
    // pixels will be active per horizontal scan line within the character
    // position. For graphic mode, the value here should be equal
    // to the total number of pixels; otherwise there will be gaps in
    // the display.

    // The default value for these bits is 8, for eight active horizontal
    // pixels per character-position scan line. This is the same
    // as the total number of pixels per position, so there will be no
    // intercharacter spacing. (For the default character set, the
    // rightmost column of each character pattern is left blank to provide
    // the effect of intercharacter spacing,)

    // Bits 4-7: The value in these bits determines the width of each
    // character position (in pixels). The value stored here should be
    // one less than the desired total number of pixels. If the total is
    // greater than the number of active pixels specified in bits 0-3
    // of this register, the extra pixels will be blank for intercharacter
    // spacing. The default value for these bits is 7, for eight total
    // pixels per character position. The total number of horizontal
    // pixels is determined by multiplying the value here (plus 1) by
    // the total number of character positions (from register 0/$00).

    outline0("LD A, $16");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", ( ( _environment->fontWidth - 1 ) << 4 ) | ( _environment->fontWidth ) );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $17 ] --
    /////////////////////////////////////////////////////////////////

    // Character vertical size control

    // Bits 0-4: The value in these bits determines how many of the
    // total scan lines for each character position (specified in register
    // 9/$09) will be used to display character pattern data. The
    // available five bits allow you to specify values up to % 11111
    // = 31/$1F. If the value here is less than the total number of
    // scan lines for the character position, the extra lines will be
    // blank for intercharacter spacing. If the value here is greater
    // than the total number of scan lines, only the total number of
    // scan lines will be displayed. For graphic mode, the value here
    // should be at least equal to the total number of scan lines (the
    // value in register 9/$09 plus 1); otherwise there will be gaps in
    // the display.

    // The default value stored in this register is 8/$08, for eight
    // active scan lines per character position. This is equal to the default
    // total number of scan lines for the position, so there will
    // be no intercharacter spacing. (For the standard character set,
    // intercharacter spacing is achieved by leaving the bottom row
    // of most character definition patterns blank.)

    outline0("LD A, $17");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", _environment->fontHeight );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $18 ] --
    /////////////////////////////////////////////////////////////////

    // Vertical smooth scrolling and control

    // Bits 0-4; These bits can be used to smoothly scroll the screen
    // vertically upward. The value here specifies the number of scan
    // lines the display should be shifted upward. Although five bits
    // are available, the value here should not exceed the value in
    // register 9/$09.

    // Bit 5: This bit controls the blinking rate for all characters on
    // the screen with the flash attribute. A character position has the
    // flash attribute when bit 4 of its corresponding attribute memory
    // is set to %1. The two available blinking rates are once
    // each 16 times the screen is refreshed (selected when this bit is
    // set to %0) or once each 32 times (selected when this bit is set
    // to %l). For NTSC (North American) systems, the screen is redrawn
    // 60 times per second, so the corresponding blinking
    // rates are about four times per second when the bit is %0 and
    // about twice per second when the bit is %1.

    // The default setting for this bit is %1, for the slower blinking
    // rate. This is established during the IOINIT routine [$E109],
    // part of both the reset and RUN/STOP-RE STORE sequences.
    // This setting is not changed by any other ROM routine.

    // Bit 6: This bit controls a special VDC feature known as reverse
    // mode. While this bit is %0, all pixels on the screen represented
    // by %0 bits in character patterns or the graphic screen
    // bitmap take the background color specified in bits 0-3 of register
    // 26/$lA, and all pixels represented by %1 bits take the
    // foreground color specified in a corresponding attribute memory
    // location (or in bits 4-7 of register 26/$lA if attributes are
    // disabled). Setting this bit to %1 reverses the color sources, so
    // that all pixels for %0 bits take the foreground color and all
    // pixels for %1 bits take the background color.
    // This bit is initialized to %0 for a normal screen display.
    // The screen editor ROM supports escape sequences to change
    // this bit. The ESC R sequence will set the bit to %1, reversing
    // the screen display. The ESC N sequence will clear the bit to
    // %0, returning the display to normal.

    // Bit 7: This bit determines whether the next block operation
    // initiated by writing to register 3O/$1E will be a copy or a fill.
    // Setting this bit to %0 specifies a fill operation, while setting it
    // to %1 specifies a copy operation. See the entry for register
    // 3O/$1E for more information on VDC block operations. This
    // bit is set to %0 when the register is initialized during the
    // IOINIT routine [$E109].

    outline0("LD A, $18");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", verticalSmoothScrollingAndControl );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $19 ] --
    /////////////////////////////////////////////////////////////////

    // Horizontal smooth scrolling and control

    // Bits 0-3: These bits can be used to smoothly scroll the screen
    // horizontally. The use of these bits depends on the version of
    // the VDC in your 128. (The version number can be determined
    // by reading bits 0-2 of the external communications register at
    // 54784/$D600.) For version 1 of the VDC, which includes most
    // 128s, this register should be initialized to the maximum character
    // width (in bits 4-7 of register 22/$16). Each decrement of
    // this register shifts the display one pixel to the left. For the
    // older version 0 of the VDC, these bits should be initialized to
    // %0000. In this case, each increment of these bits shifts the display
    // one pixel to the right.

    // Bit 4: This bit controls the VDC's pixel double feature. While
    // this bit is %0, pixels will be their normal size. Setting this bit
    // to %1 will double the size of all horizontal screen pixels. Since
    // each pixel is twice as large, there will be room for only half as
    // many on the screen. Thus, you must reduce the values in the
    // horizontal screen width registers (0-2/$00-$02) to half their
    // normal values.
    
    // Bit 5: This bit controls a special VDC feature called
    // semigraphic mode. When semigraphic mode is activated
    // (when this bit is %1), the rightmost active pixel will be repeated
    // through the intercharacter spacing pixels. For this
    // mode to have any visible effect, there must be some
    // intercharacter spacing (the value in bits 0-3 of register 22/$16
    // must be less than the total number of pixels specified in bits
    // 4-7 of that register). This mode has no effect in graphic mode.
    // One use of this mode is to create a simple "digital" character
    // effect. 
    
    // Bit 6: The VDC has two methods of supplying foreground
    // information for its display. When this attribute enable bit is set
    // to %1, each character position will have a corresponding
    // attribute memory location. Refer to the introduction to this
    // section for details on attributes. The starting address of attribute
    // memory is determined by the value in registers 20-21/$14-
    // $15, When this bit is %0, attribute memory is not used. Instead,
    // all character positions take the foreground color specified
    // in bits 4-7 of register 26/$lA. In this case, the character positions
    // cannot have the flash, underline, or reverse attributes,
    // and only the first of the two character sets will be available.
    // Bit 7: This bit determines whether the VDC will operate as a
    // text or graphics display. Text mode, selected when the bit is
    // set to %0, is the only one supported by the 128 operating system
    // (%0 is the default value for this bit). In that mode, each
    // screen memory position holds a screen code which serves as
    // an index into character memory to specify the pattern to be
    // displayed in that position.
    // When this bit is set to %1, graphics mode is selected. In
    // that mode, screen memory is replaced with a bitmap. (There is
    // no cursor on the graphic display.) Each bit in the bitmap controls
    // the state of one pixel in the display. The layout of the
    // bitmap is much simpler than that for'the VIC screen. Each
    // horizontal scan line is controlled by a sequential series of
    // bytes. The size of the bitmap (in bytes) is determined by the
    // number of active horizontal positions times the number of vertical
    // positions times the number of scan lines per vertical position.
    // For the standard screen setup, this means that 80 * 25 *
    // 8, or 16,000 bytes, are required—almost all of the available
    // VDC memory. At eight pixels per byte, there are 128,000 individual
    // pixels on the graphic display.

    // The graphic display can use attribute memory for color
    // information. In this case, the relationship of attribute locations
    // to bitmap positions is similar to that for the VIC screen. Each
    // attribute memory location controls the color for all pixeis
    // within a character-position area on the screen. However, there
    // isn't enough free memory available for a full bitmap and a full
    // attribute memory area. One solution is to turn off attributes
    // (set bit 6 of register 25/$19 to %0). This limits all screen positions
    // to the same foreground and background colors (as specified
    // in register 26/$lA). The other solution is to reduce the
    // size of the active screen area to free up enough memory for an
    // attribute area. For example, if you reduce the number of active
    // rows to 22, then 80 * 22 * 8, or 14,080 bytes, will be required
    // for the bitmap, and 80 * 22, or 1760 bytes, will be required for
    // attribute memory, so there will be enough room within VDC
    // memory for both bitmap and attributes.
    // When attribute memory is enabled for a graphic display,
    // the lower four bits of each attribute memory location determine
    // the color of all foreground (%1) pixels in the corresponding
    // character-position area, and the upper four bits determine
    // the color of all background (%0) pixels in the character
    // position.

    outline0("LD A, $19");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", horizontalSmoothScrollingAndControl );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $1a ] --
    /////////////////////////////////////////////////////////////////

    // Background and foreground colors

    // Bits 0-3: The value in these bits determines the background
    // color of the display. For text mode, this is the color of all
    // pixels represented by %0 bits in the pattern definition for the
    // character in each screen position. For graphic mode with
    // attribute memory disabled, the value here determines the color
    // all pixels represented by %0 bits in the bitmap. The correspondence
    // between register value and background color is
    // as shown in Table 8-5. For graphic mode with attribute memory
    // enabled, the value here determines the color of the screen
    // border only.

    // The default background color value, 0/$00 (black), is established
    // by the Kernal IOINIT routine [$E109], part of both
    // the reset and RUN/STOP-RESTORE sequences.
    
    // Bits 4-7: When attributes are disabled (by setting bit 6 of register
    // 25/$19 to %0), the value in these bits specifies the foreground
    // color for the display. For text mode, this is the color
    // for all pixels represented by %1 bits in the pattern definitions
    // for all screen positions. For graphic mode, the value here determines
    // the color of all pixels represented by %1 bits in the
    // bitmap. For either mode, if the screen is switched to reverse
    // mode (by setting bit 6 of register 24/S18), the value here will
    // instead determine the color for all pixels represented by %0
    // bits in the character pattern or bitmap. The correspondence
    // between bit values and colors is as shown in Table 8-5.

    // outline0("LD A, $1a");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x00 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $1b ] --
    /////////////////////////////////////////////////////////////////    

    // Address increment per row of characters

    // The value in this register will be added to the value in register
    // 1/S01 to determine the amount by which to increase the screen
    // memory address for each new row of the display. This allows
    // you to set up a virtual screen wider than the actual screen.
    // You can scroll back and forth across the virtual screen by adjusting
    // the screen starting address in registers 12-13/$0C-$0D.
    // The default value for this register is 0/$00, since no extra
    // columns are used with the 80-column text display. The screen
    // editor routines that support printing to the VDC screen all assume
    // an 80-column screen line. If you reduce the number of
    // active columns in register l/$01, you should increase the value
    // in this register correspondingly so that the total remains 80.

    outline0("LD A, $1b");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", addressIncrementPerRowOfChars );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $1c ] --
    /////////////////////////////////////////////////////////////////    

    // Character pattern address and memory type

    // Bit 4: This bit specifies the type of RAM chip used for VDC
    // video memory. When the bit is %0, the VDC is configured for
    // 4416 chips (16K X 4 bits). When the bit is %1, the VDC is
    // configured for 4164 chips (64K X 1 bit). Since the 16K VDC
    // video memory space in the 128 is provided by two 4416 chips,
    // this bit is initialized to %0 by the Kernal IO1NIT routine
    // [$E109]. It is theoretically possible to replace the existing chips
    // with the 64K variety to quadruple the amount of available
    // VDC RAM. However, the swap involves unsoldering the existing
    // chips from the circuit board and soldering the new ones in
    // their place. This is not a task for the inexperienced, and will
    // most certainly void any warranty on your 128.

    // Bits 5-7: These bits determine where within VDC memory the
    // character pattern definitions will be located. The amount of
    // memory required for the character set depends on the value in
    // register 9/$09. If the character height is 16 or fewer scan lines,
    // each character set requires 4K (4096 bytes). Character heights
    // of 17-32 scan lines require 8K (8192-b'yte) character sets. The
    // VDC normally supports a pair of character sets, using bit 7 of
    // the attribute memory location to select between them for each
    // character position. Thus, 8K is normally used for character sets
    // when the character height is 16 or fewer scan lines, and 16K is
    // used when the character height is greater than 16 scan lines.

    // In the latter case, bit 5 is not used in the address selection.
    // The possible starting addresses for character patterns are as
    // follows (the asterisks indicate valid selections for 16K-character
    // set pairs):

    // Bits Character memory
    // 7 6 5 starting address
    // 0 0 0 0/$0000 *
    // 0 0 1 8192/$2000
    // 0 1 0 16384/$4000 *
    // 0 1 1 24576/$6000
    // 1 0 0 32768/$8000 *
    // 1 0 1 40960/SAOOO
    // 1 1 0 39152/SC0O0 *
    // 1 1 1 57344/$E000

    // Since the 128 has only 16K of RAM for the VDC, only the
    // first two settings are currently valid. (Note that there is insufficient
    // room in the 128's 16K of VDC video memory for a 16K
    // character set plus screen and attribute memory.) These bits are
    // initialized to %001 by the IOINIT routine [$E109], part of the
    // reset and RUN/STOP-RESTORE sequences, so the default
    // character set starting address is 8192/$2000. Since this area is
    // RAM, not ROM, it is necessary to copy character patterns into
    // this area of memory if the VDC is to display recognizable
    // characters. This step is performed during the IOINIT routine
    // by calling the screen editor INIT80 routine [$CE0C].

    outline0("LD A, $1c");
    outline0("LD IXH, A");
    outline0("CALL VDCZREAD");
    outline0("AND $1F");
    outline1("OR $%2.2x", ( characterPatternAddress << 5 ) );
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");
    
    /////////////////////////////////////////////////////////////////
    // -- [ $1d ] --
    /////////////////////////////////////////////////////////////////        

    // Underline scan-line control

    // Bits 0-4: The value in these bits determines which scan line
    // within the character position will be filled for any characters
    // with the underline attribute. (A character position has the underline
    // attribute when the corresponding attribute memory position
    // has bit 5 set to %1.) Since the line can appear on any
    // horizontal scan line of the character position, it's not strictly
    // correct to call it an underline. For example, you could move
    // the line to the top line of the position to be an overbar, or to
    // the middle line of the position to serve as an overstrike. Scan
    // line 0 is the top line of the character position. The available
    // five bits allow a maximum scan-line value of %11111 = 31/
    // $1F. However, the underline will not be visible if the value is
    // greater than the maximum character-position height in bits
    // 4-7 of register 22/$16.

    // outline0("LD A, $1d");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x08 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $1e ] --
    /////////////////////////////////////////////////////////////////        

    // Number of bytes to copy or fill

    // The VDC has the capability to copy blocks of data up to 255
    // characters long from one area of VDC memory to another, and
    // to fill areas up to 255 bytes long with a specified value. The
    // value in this register determines the number of bytes to be
    // copied or filled. The copy or fill operation begins immediately
    // after the count value is stored here. The setting of bit 7 of register
    // 24/$18 determines whether the operation will be a copy
    // or a fill.

    // outline0("LD A, $1e");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x00 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $1f ] --
    /////////////////////////////////////////////////////////////////        

    // Memory read/write

    // This register is the gateway between the VDC's private block
    // of RAM and the rest of the 128 system. When read, this
    // location reflects the contents of the VDC memory location addressed
    // in registers IS—19/$12—$13. Writing a value to this
    // register will cause the value to be transferred to the location
    // addressed in registers 18—19/$12—13. For both reading and
    // writing, the address in registers 18-19/$12-$13 will automatically
    // be incremented after this register is accessed. Thus, to
    // read or write a sequential series of locations you need only
    // load the starting address of the series into registers 18—19/
    // $12—$13. You can then read or write repeatedly to register
    // 31/$1F; the destination address will automatically increment
    // after each read or write.

    // outline0("LD A, $1f");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x00 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    /////////////////////////////////////////////////////////////////
    // -- [ $20-$21 ] --
    /////////////////////////////////////////////////////////////////        

    // Source address for block copy

    // The VDC has the capability to copy blocks of data up to 255
    // bytes long from one area of memory to another (see the entry
    // for register 3O/$1E for details). The value in this register pair
    // determines the source address for copy operations, the address
    // from which data will be copied. Like all other address register
    // pairs in the VDC, the first register (32/$20) holds the high
    // byte of the address and the second (33/$21) holds the low
    // byte—the opposite of the normal 8502 address format. The
    // registers should be loaded with the desired source starting address
    // before the copy operation is initiated. Upon completion
    // of the operation, the registers will hold the address of the next
    // location beyond the last one involved in the operation. Thus,
    // it is possible to copy blocks of more than 255 successive bytes
    // by using repeated copy operations without reloading these
    // registers.

    // outline0("LD A, $20");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x00 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");
    // outline0("LD A, $21");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x00 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");    

    /////////////////////////////////////////////////////////////////
    // -- [ $22-$23 ] --
    /////////////////////////////////////////////////////////////////        

    // Horizontal blanking positions

    // The VDC can adjust its horizontal blanking interval to blank a
    // portion of the screen. These locations control the horizontal
    // width and position of the blanked area. If the blanked area extends
    // onto the active portion of the screen, any text under the
    // blanked area is only covered, not erased. The value in register
    // 34/$22 determines the rightmost blanked column, and the
    // value in register 35/$23 determines the leftmost blanked column.
    // The blanked area extends the entire height of the screen.
    // The value in register 34/$22 must be less than the value
    // in register 0/$00; otherwise, the entire display will be
    // blanked. The value in 34/$22 here must also be greater than
    // the value in register 35/$23 to prevent an entirely blank display.
    // The default values for these locations are 125/S7D and
    // 100/$64, respectively. This positions the blanking interval entirely
    // outside the active screen area. For purposes of blanking
    // an area of the screen, a value of 6/$06 in these registers corresponds
    // to the leftmost column of the standard screen and a
    // value of 85/$55 corresponds to the rightmost column.

    // outline0("LD A, $22");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x06 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");
    // outline0("LD A, $23");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x55 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");    

    /////////////////////////////////////////////////////////////////
    // -- [ $24 ] --
    /////////////////////////////////////////////////////////////////        

    // Number of memory refresh cycles per scan line

    // Bits 0-3: The value in these bits determines the number of
    // memory refresh cycles per scan line. The RAM chip used for
    // the VDC's video memory is a type known as dynamic RAM.
    // A dynamic RAM can hold data only briefly without external
    // support. Just as the image on the video screen must be constantly
    // redrawn to keep it from fading away, dynamic RAM
    // must be constantly refreshed to keep it from losing its contents.
    // The VDC handles this refresh function automatically for
    // its video RAM, just as the VIC automatically handles the refreshing
    // of system RAM. However, for the VDC, the number
    // of refresh cycles provided during each scan line is programmable.
    // The IOINIT routine [SE109] initializes these bits to %0101
    // for five refresh cycles per scan line, and there's no reason to
    // change that setting.

    // outline0("LD A, $24");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 0x05 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", (_environment->screenWidth-1) );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", (_environment->screenHeight-1) );

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );

}

void vdcz_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        vdcz_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        vdcz_cls( _environment );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void vdcz_bitmap_disable( Environment * _environment ) {

}

void vdcz_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        vdcz_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        vdcz_cls( _environment );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void vdcz_bitmap_at( Environment * _environment, char * _address ) {

}

void vdcz_colormap_at( Environment * _environment, char * _address ) {

}

void vdcz_textmap_at( Environment * _environment, char * _address ) {

}

void vdcz_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( plot, src_hw_vdcz_plot_asm );

    outline1( "LD A, $%2.2x", ( _x & 0xff ) );
    outline0( "LD E, A" );
    outline1( "LD A, $%2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0( "LD D, A" );
    outline1( "LD A, $%2.2x", ( _y & 0xff ) );
    outline0( "LD IYL, A" );
    outline1( "LD A, $%2.2x", ( ( _y >> 8 ) & 0xff ) );
    outline0( "LD IYH, A" );
    outline0( "LD A, 1" );
    outline0( "CALL PLOT" );

}

void vdcz_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( plot, src_hw_vdcz_plot_asm );

    outline1( "LD A, (%s)", x->realName );
    outline0( "LD E, A" );
    outline1( "LD A, (%s+1)", x->realName );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", y->realName );
    outline0( "LD IYL, A" );
    outline1( "LD A, (%s+1)", y->realName );
    outline0( "LD IYH, A" );
    outline0( "LD A, 1" );
    outline0( "CALL PLOT" );
    
}

void vdcz_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( plot, src_hw_vdcz_plot_asm );

    outline1( "LD A, (%s)", x->realName );
    outline0( "LD E, A" );
    outline1( "LD A, (%s+1)", x->realName );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", y->realName );
    outline0( "LD IYL, A" );
    outline1( "LD A, (%s+1)", y->realName );
    outline0( "LD IYH, A" );
    outline0( "LD A, 3" );
    outline0( "CALL PLOT" );
    outline1( "LD (%s), A", result->realName );

}

void vdcz_screen_on( Environment * _environment ) {

}

void vdcz_screen_off( Environment * _environment ) {
    
}

void vdcz_screen_rows( Environment * _environment, char * _rows ) {

}

void vdcz_screen_columns( Environment * _environment, char * _columns ) {

}

void vdcz_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

    _environment->bitmaskNeeded = 1;

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * image = variable_retrieve_or_define( _environment, _image, VT_IMAGE, 0 );

}

void vdcz_sprite_enable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

}

void vdcz_sprite_disable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

}

void vdcz_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    
}

void vdcz_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

}

void vdcz_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    
}

void vdcz_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    
}

void vdcz_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    
}

void vdcz_sprite_multicolor( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    
}

void vdcz_sprite_monocolor( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    
}

void vdcz_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );
    
}

void vdcz_tiles_at( Environment * _environment, char * _address ) {

}

void vdcz_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void vdcz_horizontal_scroll( Environment * _environment, char * _displacement ) {

    // outline0("LD A, 2");
    // outline0("LD IXH, A");
    // outline0("LD A, $%2.2x", 102 );
    // outline0("LD IXL, A");
    // outline0("CALL VDCZWRITE");

}

void vdcz_busy_wait( Environment * _environment, char * _timing ) {

}

void vdcz_get_width( Environment * _environment, char *_result ) {

}

void vdcz_tiles_get( Environment * _environment, char *_result ) {

}

void vdcz_tiles_get_width( Environment * _environment, char *_result ) {

}

void vdcz_get_height( Environment * _environment, char *_result ) {

}

void vdcz_tiles_get_height( Environment * _environment, char *_result ) {

}

void vdcz_cls( Environment * _environment ) {

    if ( _environment->currentMode != TILEMAP_MODE_STANDARD ) {
        deploy( clsGraphic, src_hw_vdcz_cls_graphic_asm );
        outline0("CALL CLSG");
    } else {
        deploy( clsText, src_hw_vdcz_cls_text_asm );
        outline0("CALL CLST");
    }

}

void vdcz_scroll_text( Environment * _environment, int _direction ) {

    if ( _direction > 0 ) {
        deploy( vScrollTextDown, src_hw_vdcz_vscroll_text_down_asm );
        outline0("CALL VSCROLLTDOWN");
    } else {
        deploy( vScrollTextUp, src_hw_vdcz_vscroll_text_up_asm );
        outline0("CALL VSCROLLTUP");
    }

}

void vdcz_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( textEncodedAt, src_hw_vdcz_text_at_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    if ( _environment->currentMode != TILEMAP_MODE_STANDARD ) {
        deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm);
        deploy( vScroll, src_hw_vdcz_vscroll_asm );
        deploy( clsGraphic, src_hw_vdcz_cls_graphic_asm );
        deploy( textEncodedAtGraphic, src_hw_vdcz_text_at_graphic_asm );
        outline0("CALL TEXTATBITMAPMODE");
    } else {
        deploy( vScrollTextUp, src_hw_vdcz_vscroll_text_up_asm );
        deploy( clsText, src_hw_vdcz_cls_text_asm );
        deploy( textEncodedAtText, src_hw_vdcz_text_at_text_asm );
        outline0("CALL TEXTATTILEMODE");
    }


}

void vdcz_initialization( Environment * _environment ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm );
    deploy( vdczstartup, src_hw_vdcz_startup_asm );
    src_hw_chipset_mob_asm = src_hw_vdcz_mob_asm;
    src_hw_chipset_mob_asm_len = src_hw_vdcz_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 192  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 24 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );
    variable_import( _environment, "SPRITEADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "SPRITEADDRESS" );    
    variable_import( _environment, "SPRITEAADDRESS", VT_ADDRESS, 0x1000 );
    variable_global( _environment, "SPRITEAADDRESS" );    
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x1800 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x3800 );
    variable_global( _environment, "COLORMAPADDRESS" );    
    variable_import( _environment, "PATTERNADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "PATTERNADDRESS" );    
    variable_import( _environment, "PALETTE", VT_BUFFER, 16 );
    variable_global( _environment, "PALETTE" ); 

    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 80, 25, 8, 8, 8, "Text Mode" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 640, 200, 1, 8, 8, "Bitmap Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 640, 200, 16, 8, 8, "Multicolor Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD_INT, 1, 640, 176, 1, 8, 8, "Interlaced bitmap Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR_INT, 1, 640, 352, 1, 8, 8, "Interlaced multicolor Mode" );
 
    outline0("CALL VDCZSTARTUP");

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    variable_global( _environment, "LINE" );

    variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION, 255 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 191 );
    variable_global( _environment, "CLIPY2" );

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );
    
    variable_import( _environment, "XCURSYS", VT_BYTE, 0 );
    variable_global( _environment, "XCURSYS" );
    variable_import( _environment, "YCURSYS", VT_BYTE, 0 );
    variable_global( _environment, "YCURSYS" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

    variable_import( _environment, "CLINEX", VT_BYTE, 0 );
    variable_global( _environment, "CLINEX" );

    variable_import( _environment, "CLINEY", VT_BYTE, 0 );
    variable_global( _environment, "CLINEY" );

    variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    variable_global( _environment, "TABSTODRAW" );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "SPRITECOUNT", VT_SPRITE, 0 );
    variable_global( _environment, "SPRITECOUNT" );

    variable_import( _environment, "SPRITEXY", VT_BUFFER, SPRITE_COUNT * 2 );
    variable_global( _environment, "SPRITEXY" );

    variable_import( _environment, "TILEX", VT_BYTE, 0 );
    variable_global( _environment, "TILEX" );
    variable_import( _environment, "TILEY", VT_BYTE, 0 );
    variable_global( _environment, "TILEY" );
    variable_import( _environment, "TILEX2", VT_BYTE, 0 );
    variable_global( _environment, "TILEX2" );
    variable_import( _environment, "TILET", VT_BYTE, 0 );
    variable_global( _environment, "TILET" );
    variable_import( _environment, "TILEW", VT_BYTE, 0 );
    variable_global( _environment, "TILEW" );
    variable_import( _environment, "TILEH", VT_BYTE, 0 );
    variable_global( _environment, "TILEH" );
    variable_import( _environment, "TILEW2", VT_BYTE, 0 );
    variable_global( _environment, "TILEW2" );
    variable_import( _environment, "TILEH2", VT_BYTE, 0 );
    variable_global( _environment, "TILEH2" );
    variable_import( _environment, "TILEA", VT_BYTE, 0 );
    variable_global( _environment, "TILEA" );
    variable_import( _environment, "TILEO", VT_WORD, 0 );
    variable_global( _environment, "TILEO" );

    variable_import( _environment, "XSCROLLPOS", VT_BYTE, 0 );
    variable_global( _environment, "XSCROLLPOS" );
    variable_import( _environment, "YSCROLLPOS", VT_BYTE, 0 );
    variable_global( _environment, "YSCROLLPOS" );
    variable_import( _environment, "XSCROLL", VT_BYTE, 0 );
    variable_global( _environment, "XSCROLL" );
    variable_import( _environment, "YSCROLL", VT_BYTE, 0 );
    variable_global( _environment, "YSCROLL" );
    variable_import( _environment, "DIRECTION", VT_BYTE, 0 );
    variable_global( _environment, "DIRECTION" );

    variable_import( _environment, "ONSCROLLUP", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLUP" );

    variable_import( _environment, "ONSCROLLDOWN", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLDOWN" );

    variable_import( _environment, "ONSCROLLLEFT", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLLEFT" );

    variable_import( _environment, "ONSCROLLRIGHT", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLRIGHT" );

    variable_import( _environment, "IMAGEF", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEF" );

    variable_import( _environment, "IMAGET", VT_BYTE, 0 );
    variable_global( _environment, "IMAGET" );

    variable_import( _environment, "BLITIMAGEBLITTINGADDR", VT_ADDRESS, 0 );
    variable_global( _environment, "BLITIMAGEBLITTINGADDR" );
    variable_import( _environment, "BLITTMPPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "BLITTMPPTR" );
    variable_import( _environment, "BLITTMPPTR2", VT_ADDRESS, 0 );
    variable_global( _environment, "BLITTMPPTR2" );

    variable_import( _environment, "VBLFLAG", VT_BYTE, 0 );
    variable_global( _environment, "VBLFLAG" ); 

    vdcz_tilemap_enable( _environment, 80, 25, 8, 8, 8 );

    font_descriptors_init( _environment, 0 );
    
    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

static RGBi * multicolorSpritePalette[2];

void vdcz_finalization( Environment * _environment ) {

}

void vdcz_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_vdcz_hscroll_text_asm );

}

void vdcz_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_vdcz_hscroll_text_asm );

}

void vdcz_back( Environment * _environment ) {

    deploy( back, src_hw_vdcz_back_asm );

}

void vdcz_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_vdcz_cline_asm );

    if ( _characters ) {
        outline1("LD A, (%s)", _characters);
        outline0("LD C, A");
    } else {
        outline0("LD A, 0");
        outline0("LD C, A");
    }
    outline0("CALL CLINE");

}

Variable * vdcz_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {

        case BITMAP_MODE_STANDARD:
        case BITMAP_MODE_STANDARD_INT:

            return vcdz_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
            
        case BITMAP_MODE_MULTICOLOR:
        case BITMAP_MODE_MULTICOLOR_INT:

            return vdcz_image_converter_bitmap_mode_multicolor( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

    }

    return vdcz_new_image( _environment, 8, 8, _mode );

}

Variable * vdcz_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color, int _flags ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

void vdcz_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( putimage, src_hw_vdcz_put_image_asm );

    MAKE_LABEL

    outhead1("putimage%s:", label);
    outline1("LD A, $%2.2x", ( _flags & 0xff ) );
    outline1("LD HL, %s", _image );
    if ( _sequence ) {

        outline0("LD DE, $0003" );
        outline0("ADD HL, DE" );
        if ( strlen(_sequence) == 0 ) {

        } else {
            outline0("PUSH HL" );
            outline1("LD A, (%s)", _sequence );
            outline0("LD L, A" );
            outline0("LD H, 0" );
            outline0("ADD HL, HL" );
            outline0("LD DE, HL" );
            outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("ADD HL, DE" );
            outline0("LD A, (HL)" );
            outline0("LD E, A" );
            outline0("INC HL" );
            outline0("LD A, (HL)" );
            outline0("LD D, A" );
            outline0("POP HL" );
            outline0("ADD HL, DE" );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }

    } else {

        if ( _frame ) {
            outline0("LD DE, $0003" );
            outline0("ADD HL, DE" );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }


    }
    outline1("LD DE, (%s)", _x );
    outline1("LD IY, (%s)", _y );
    outline1("LD A, $%2.2x", ( _flags & 0xff ) );
    outline0("LD (IMAGEF), A" );
    outline1("LD A, $%2.2x", ( (_flags>>8) & 0xff ) );
    outline0("LD (IMAGET), A" );

    outline0("CALL PUTIMAGE");

}

static void vdcz_load_image_address_to_register( Environment * _environment, char * _register, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    outline1("LD HL, %s", _source );
    if ( _sequence ) {

        outline0("LD DE, $0003" );
        outline0("ADD HL, DE" );
        if ( strlen(_sequence) == 0 ) {

        } else {
            outline0("PUSH HL" );
            outline1("LD A, (%s)", _sequence );
            outline0("LD L, A" );
            outline0("LD H, 0" );
            outline0("ADD HL, HL" );
            outline0("LD DE, HL" );
            outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("ADD HL, DE" );
            outline0("LD A, (HL)" );
            outline0("LD E, A" );
            outline0("INC HL" );
            outline0("LD A, (HL)" );
            outline0("LD D, A" );
            outline0("POP HL" );
            outline0("ADD HL, DE" );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }

    } else {

        if ( _frame ) {
            outline0("LD DE, $0003" );
            outline0("ADD HL, DE" );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }

    }
    outline1("LD (%s), HL", _register );

}

void vdcz_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( blitimage, src_hw_vdcz_blit_image_asm );

    if ( _source_count > 2 ) {
        CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    }

    MAKE_LABEL

    outline1("LD HL, %s", _blit );
    outline0("LD (BLITIMAGEBLITTINGADDR), HL");

    outhead1("blitimage%s:", label);
    if ( _source_count > 0 ) {
        vdcz_load_image_address_to_register( _environment, "BLITTMPPTR", _sources[0], _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LD HL, 0" );
        outline0( "LD (BLITTMPPTR), HL" );
    }

    if ( _source_count > 1 ) {
        vdcz_load_image_address_to_register( _environment, "BLITTMPPTR2", _sources[1], _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LD HL, 0" );
        outline0( "LD (BLITTMPPTR2), HL" );
    }

    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, $%2.2x", ( _flags & 0xff ) );
    outline0("LD (IMAGEF), A" );
    outline1("LD A, $%2.2x", ( (_flags>>8) & 0xff ) );
    outline0("LD (IMAGET), A" );

    outline0("CALL BLITIMAGE");

}

void vdcz_wait_vbl( Environment * _environment ) {

    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( vbl, src_hw_vdcz_vbl_asm);

}

Variable * vdcz_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    return result;

}

void vdcz_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( getimage, src_hw_vdcz_get_image_asm );

}

void vdcz_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( scroll, src_hw_vdcz_scroll_asm);
    deploy( textHScroll, src_hw_vdcz_hscroll_text_asm );
    deploy( vScrollTextDown, src_hw_vdcz_vscroll_text_down_asm );
    deploy( vScrollTextUp, src_hw_vdcz_vscroll_text_up_asm );

}

void vdcz_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( tiles, src_hw_vdcz_tiles_asm );

}

void vdcz_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( tiles, src_hw_vdcz_tiles_asm );

}

void vdcz_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( tiles, src_hw_vdcz_tiles_asm );

}

void vdcz_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( tiles, src_hw_vdcz_tiles_asm );

}

void vdcz_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( tiles, src_hw_vdcz_tiles_asm );

}

Variable * vdcz_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    return result;
    
}


#endif