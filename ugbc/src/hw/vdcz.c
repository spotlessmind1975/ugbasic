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
            return 3 + ( ( _width >> 3 ) * _height );
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

    commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE[0]) / sizeof(RGBi) );
    commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
    lastUsedSlotInCommonPalette = paletteColorCount;
    adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    adilinepalette( "CPMS:%ld", sizeof(SYSTEM_PALETTE[0]) / sizeof(RGBi), SYSTEM_PALETTE );

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
    *(buffer+1) = ( (_frame_width>>3) & 0XFF );
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
                    colorIndex = i;
                }
            }

            offset = ( image_y * ( _frame_width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( colorIndex > 0) {
                *( buffer + offset + 2) |= bitmask;
            } else {
                *( buffer + offset + 2) &= ~bitmask;
            }

            adilinepixel(colorIndex);

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        // printf("\n" );

    }

    adilineendbitmap();

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

    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", _background_color & 0x0f );
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

    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline1("LD A, (%s)", _background_color );
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

    outline0("LD A, 26");
    outline0("LD IXH, A");
    outline1("LD A, (%s)", _background_color );
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

            outline0("LD A, 25");
            outline0("LD IXH, A");
            outline0("CALL VDCZREAD");
            outline0("AND $7F");
            outline0("LD IXL, A");
            outline0("CALL VDCZWRITE");

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
            _environment->screenColors = 16;
            _environment->currentModeBW = 1;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );
            cpu_store_16bit( _environment, "COLORMAPADDRESS", 0x4000 );

            outline0("LD A, 25");
            outline0("LD IXH, A");
            outline0("CALL VDCZREAD");
            outline0("AND $BF");
            outline0("OR $80");
            outline0("LD IXL, A");
            outline0("CALL VDCZWRITE");

            break;
    }

    outline0("LD A, 12");
    outline0("LD IXH, A");
    outline0("LD A, (TEXTADDRESS+1)");
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");
    outline0("LD A, 13");
    outline0("LD IXH, A");
    outline0("LD A, (TEXTADDRESS)");
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

    outline0("LD A, 20");
    outline0("LD IXH, A");
    outline0("LD A, (COLORMAPADDRESS+1)");
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");
    outline0("LD A, 21");
    outline0("LD IXH, A");
    outline0("LD A, (COLORMAPADDRESS)");
    outline0("LD IXL, A");
    outline0("CALL VDCZWRITE");

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
    outline1( "LD A, $%2.2x", _y );
    outline0( "LD IYL, A" );
    outline0( "LD A, 1" );
    outline0( "CALL PLOT" );

}

void vdcz_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( plot, src_hw_vdcz_plot_asm );

    outline1( "LD A, (%s)", x->realName );
    outline0( "LD E, A" );
    outline1( "LD A, (%s+1)", x->realName );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", y->realName );
    outline0( "LD IYL, A" );
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

    if ( _environment->currentMode == BITMAP_MODE_STANDARD ) {
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
    deploy( vScrollTextUp, src_hw_vdcz_vscroll_text_up_asm );
    deploy( clsText, src_hw_vdcz_cls_text_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    deploy( textEncodedAt, src_hw_vdcz_text_at_asm );
    deploy( textEncodedAtText, src_hw_vdcz_text_at_text_asm );
    outline0("CALL TEXTATTILEMODE");

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

}

Variable * vdcz_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

Variable * vdcz_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color, int _flags ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

void vdcz_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( putimage, src_hw_vdcz_put_image_asm );

}

void vdcz_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( vdczvars, src_hw_vdcz_vars_asm);
    deploy( vdczvarsGraphic, src_hw_vdcz_vars_graphic_asm );
    deploy( blitimage, src_hw_vdcz_blit_image_asm );

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