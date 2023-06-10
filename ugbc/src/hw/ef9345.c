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

#if defined(__vg5000__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0xff, 1, "BLACK" },
        { 0x00, 0x00, 0x00, 0xff, 0, "TRANSPARENT" },
        { 0x00, 0x80, 0x00, 0xff, 2, "GREEN" },
        { 0x00, 0xff, 0x00, 0xff, 3, "LIGHT_GREEN" },
        { 0x00, 0x00, 0x80, 0xff, 4, "DARK_BLUE" },
        { 0x00, 0x00, 0xff, 0xff, 5, "LIGHT_BLUE" },
        { 0x80, 0x00, 0x00, 0xff, 6, "DARK_RED" },
        { 0x00, 0xff, 0xff, 0xff, 7, "CYAN" },
        { 0x80, 0x00, 0x00, 0xff, 8, "RED" },
        { 0xff, 0x00, 0x00, 0xff, 9, "LIGHT_RED" },
        { 0xff, 0xff, 0x20, 0xff, 10, "DARK_YELLOW" },
        { 0xff, 0xff, 0xee, 0xff, 11, "LIGHT_YELLOW" },
        { 0x00, 0x40, 0x00, 0xff, 12, "DARK_GREEN" },
        { 0xaa, 0x00, 0xaa, 0xff, 13, "MAGENTA" },
        { 0xaa, 0xaa, 0xaa, 0xff, 14, "GRAY" },
        { 0xff, 0xff, 0xff, 0xff, 15, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * ef9345_image_nearest_system_color( RGBi * _color ) {

    int minDistance = 0xffff;
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

/**
 * This method can be used to convert 
 *     8x8 RGB (3/4 bytes) pixel (_source) [8x8x3/4 = 192/256 bytes]
 * into 
 *     8x8 bitmap (1 bit) pixel + 8 (byte) [8x1 + 8 = 16 bytes]
 *       foreground and background color (_dest)
 * 
 * Since the 8x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze.
 */
static void ef9345_image_converter_tile( char * _source, char * _dest, int _width, int _depth, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];

    int colorBackgroundMax = 0;
    int colorBackground[8];
    memset( colorBackground, 0, 8 );
    
    int colorForegroundMax = 0;
    int colorForeground[8];
    memset( colorForeground, 0, 8 );

    char * source = _source;

    // Clear the box and colors
    memset( _dest, 0, 16 );

    // Loop for all the box surface
    for (int y=0; y<8; ++y) {

        memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );
        colorBackgroundMax = 0;
        colorForegroundMax = 0;

        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            // Take the color of the pixel
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = ef9345_image_nearest_system_color( &rgb );

            ++colorIndexesCount[systemRgb->index];

            source += _depth;

        }

        for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
            if ( colorIndexesCount[xx] > colorBackgroundMax ) {
                colorBackground[y] = xx;
                colorBackgroundMax = colorIndexesCount[xx];
            };
        }

        colorIndexesCount[colorBackground[y]] = 0;

        for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
            if ( colorIndexesCount[xx] > colorForegroundMax ) {
                colorForeground[y] = xx;
                colorForegroundMax = colorIndexesCount[xx];
            };
        }

        if ( colorForeground[y] == colorBackground[y] ) {
            colorForeground[y] = ( colorBackground[y] == 0 ) ? 1 : 0;
        }

        source += _depth * ( _source_width - 8 );

    }

    source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = ef9345_image_nearest_system_color( &rgb );

            char bitmask = 1 << ( 7 - ((x) & 0x7) );

            if ( systemRgb->index != colorBackground[y] ) {
                *( _dest + y ) |= bitmask;
                // printf("*");
            } else {
                *( _dest + y ) &= ~bitmask;
                // printf(" ");
            }

            source += _depth;

        }

        source += _depth * ( _source_width - 8 );

    }

    for( int i=0; i<8; ++i ) {
        *( _dest + 8 + i ) = ( colorForeground[i] << 4 ) | colorBackground[i] ;
    }

}

/**
 * This method can be used to convert 
 *     WxH RGB (3/4 bytes) pixel (_source) [WxHx3/4 bytes]
 * into 
 *     WxH bitmap (1 bit) pixel + (W/8xH + W/8xH) (bytes)
 *       foreground and background color (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze.
 */
static void ef9345_image_converter_tiles( char * _source, char * _dest, int _width, int _height, int _depth, int _source_width ) {

    int bitmapSize = ( _width>>3 ) * _height;
    int colormapSize = ( _width>>3 ) * _height;

    memset( _dest, 0, bitmapSize + colormapSize );

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=8 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * _depth;
            char tile[16];

            ef9345_image_converter_tile( source, tile, _width, _depth, _source_width );

            int offset = ((y>>3) * 8 *( _width >> 3 ) ) + ((x>>3) * 8) + ((y) & 0x07);
            // x = 8, y = 8
            // offset = ((8 >> 3) * 8 * (16>>3) ) + ((8>>3) * 8) + ((8) & 7)
            // offset = (1 * 8 * 2 ) + (1 * 8)
            // offset = 16 + 8 = 24

            char * destBitmap = _dest + offset;
            char * destColormap = _dest + bitmapSize + offset;
            for( int i=0; i<8; ++i ) {
                *destBitmap = tile[i];
                *destColormap = tile[i+8];
                ++destBitmap;
                ++destColormap;
            }
        }
    }
}

/**
 * @brief <i>EF9345</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * ef9345_collision( Environment * _environment, char * _sprite ) {

}

/**
 * @brief <i>EF9345</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void ef9345_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    //todo

}

/**
 * @brief <i>EF9345</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void ef9345_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>EF9345</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ef9345_background_color( Environment * _environment, int _index, int _background_color ) {

}

/**
 * @brief <i>EF9345</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ef9345_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>EF9345</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ef9345_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

}

/**
 * @brief <i>EF9345</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ef9345_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>EF9345</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void ef9345_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>EF9345</i>: emit code to set raster irq
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
void ef9345_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>EF9345</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void ef9345_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>EF9345</i>: emit code to wait for next raster irq at different position
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
void ef9345_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>EF9345</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void ef9345_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>EF9345</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void ef9345_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>EF9345</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void ef9345_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>EF9345</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void ef9345_disable_mcm( Environment * _environment ) {

}

void ef9345_bank_select( Environment * _environment, int _bank ) {
    
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

int ef9345_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    cpu_store_8bit( _environment, "_PEN", DEFAULT_PEN_COLOR );
    cpu_store_8bit( _environment, "_PAPER", DEFAULT_PAPER_COLOR );

    switch( _screen_mode->id ) {
        case TILEMAP_MODE_STANDARD:
            _environment->fontWidth = 8;
            _environment->fontHeight = 10;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 21;
            _environment->screenTiles = 127;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 8;

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );

            break;
    }

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

void ef9345_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        ef9345_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        ef9345_cls( _environment );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }
}

void ef9345_bitmap_disable( Environment * _environment ) {

    //todo

}

void ef9345_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        // printf("ef9345_tilemap_enable() -> %d\n", mode->id );
        
        ef9345_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        ef9345_cls( _environment );

    } else {
        // printf("ef9345_tilemap_enable() -> -1\n" );
        WARNING_SCREEN_MODE( -1 );
    }

}

void ef9345_bitmap_at( Environment * _environment, char * _address ) {

}

void ef9345_colormap_at( Environment * _environment, char * _address ) {

}

void ef9345_textmap_at( Environment * _environment, char * _address ) {

}

void ef9345_point_at_int( Environment * _environment, int _x, int _y ) {

}

void ef9345_point_at_vars( Environment * _environment, char *_x, char *_y ) {

}

void ef9345_point( Environment * _environment, char *_x, char *_y, char * _result ) {

}

void ef9345_screen_on( Environment * _environment ) {

}

void ef9345_screen_off( Environment * _environment ) {

}

void ef9345_screen_rows( Environment * _environment, char * _rows ) {

}

void ef9345_screen_columns( Environment * _environment, char * _columns ) {

}

void ef9345_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

}

void ef9345_sprite_enable( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_disable( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void ef9345_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void ef9345_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void ef9345_tiles_at( Environment * _environment, char * _address ) {

}

void ef9345_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void ef9345_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void ef9345_busy_wait( Environment * _environment, char * _timing ) {

}

void ef9345_get_width( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTWIDTH)" );
    outline1("LD (%s), HL", _result );

}

void ef9345_tiles_get( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILES)" );
    outline1("LD (%s), A", _result );

}

void ef9345_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILESWIDTH)" );
    outline1("LD (%s), A", _result );

}

void ef9345_get_height( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTHEIGHT)" );
    outline1("LD (%s), HL", _result );

}

void ef9345_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILESHEIGHT)" );
    outline1("LD (%s), A", _result );

}

void ef9345_cls( Environment * _environment ) {
    
    deploy( clsText, src_hw_ef9345_cls_asm );
    outline0("CALL CLS");

}

void ef9345_scroll_text( Environment * _environment, int _direction ) {

}

void ef9345_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( ef9345vars, src_hw_ef9345_vars_asm);
    deploy( textEncodedAt, src_hw_ef9345_text_at_asm );
    // deploy( vScrollTextUp, src_hw_ef9345_vscroll_text_up_asm );
    // deploy( clsText, src_hw_tms9918_cls_text_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    outline0("CALL TEXTAT");

}

void ef9345_initialization( Environment * _environment ) {

    deploy( ef9345vars, src_hw_ef9345_vars_asm );
    deploy( ef9345startup, src_hw_ef9345_startup_asm );
    // src_hw_chipset_mob_asm = src_hw_ef9345_mob_asm;
    // src_hw_chipset_mob_asm_len = src_hw_ef9345_mob_asm_len;

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

    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 24, 20, 6, 8, "Text Mode" );
 
    outline0("CALL EF9345STARTUP");

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

    ef9345_tilemap_enable( _environment, 40, 21, 1, 8, 10 );
    
    font_descriptors_init( _environment, 0 );
    
    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

void ef9345_finalization( Environment * _environment ) {

}

void ef9345_hscroll_line( Environment * _environment, int _direction ) {

}

void ef9345_hscroll_screen( Environment * _environment, int _direction ) {

}

void ef9345_back( Environment * _environment ) {

}

void ef9345_cline( Environment * _environment, char * _characters ) {

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case TILEMAP_MODE_STANDARD:
            break;
    }

    return 0;

}

Variable * ef9345_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color ) {

    // deploy( ef9345varsGraphic, src_hw_ef9345_vars_graphic_asm );

    // RGBi palette[MAX_PALETTE];

    // int colorUsed = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, 1 /* sorted */);

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    // result->originalColors = colorUsed;

    // int i, j, k;

    // for( i=0; i<colorUsed; ++i ) {
    //     int minDistance = 0xffff;
    //     int colorIndex = 0;
    //     for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
    //         int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
    //         if (distance < minDistance) {
    //             for( k=0; k<i; ++k ) {
    //                 if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
    //                     break;
    //                 }
    //             }
    //             if ( k>=i ) {
    //                 minDistance = distance;
    //                 colorIndex = j;
    //             }
    //         }
    //     }
    //     palette[i].index = SYSTEM_PALETTE[colorIndex].index;
    //     strcpy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
    // }

    // memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    // int bufferSize = ( ( _width >> 3 ) * _height ) + 3;
    
    // char * buffer = malloc ( bufferSize );
    // memset( buffer, 0, bufferSize );

    // // Position of the pixel in the original image
    // int image_x, image_y;
    
    // // Position of the pixel, in terms of tiles
    // int tile_x, tile_y;
    
    // // Position of the pixel, in terms of offset and bitmask
    // int offset, bitmask;

    // // Color of the pixel to convert
    // RGBi rgb;

    // // Loop for all the source surface.
    // for (image_y = 0; image_y < _height; ++image_y) {
    //     if ( image_y == 8 ) {
    //         break;
    //     }
    //     for (image_x = 0; image_x < _width; ++image_x) {
    //         if ( image_x == 8 ) {
    //             break;
    //         }

    //         // Take the color of the pixel
    //         rgb.red = *_source;
    //         rgb.green = *(_source + 1);
    //         rgb.blue = *(_source + 2);
            // if ( _depth > 3 ) {
            //     rgb.alpha = *(_source + 3);
            // } else {
            //     rgb.alpha = 255;
            // }

    //         // Calculate the relative tile

    //         // Calculate the offset starting from the tile surface area
    //         // and the bit to set.
    //         offset = (image_y * ( _width>>3 ) ) + (image_x >> 3);

    //         int minDistance = 0xffff;
    //         int colorIndex = 0;

    //         if ( rgbi_equals_rgba( _color, &rgb ) ) {
    //             i = 1;
    //         } else {
    //             i = 0;
    //         }

    //         colorIndex = i;

    //         if ( _environment->debugImageLoad ) {
    //             printf( "%1.1x", ( palette[colorIndex].index & 0x0f ) );
    //         }

    //         bitmask = ( colorIndex == 0 ? 0 : 1 ) << (7 - ((image_x & 0x7)));
    //         *(buffer + 2 + offset) |= bitmask;

    //         _source += 3;

    //     }

    //     _source += 3 * ( _width - image_x );

    //     if ( _environment->debugImageLoad ) {
    //         printf("\n" );
    //     }
    // }

    // *(buffer + 2 + ( ( _width >> 3 ) * _height )) = _color->index | ( _color->index << 4 );

    // if ( _environment->debugImageLoad ) {
    //     printf("\n" );
    
    //     printf("PALETTE:\n" );
    //     for( i=0; i<colorUsed; ++i ) {
    //         printf("  (%2.2d) = %2.2d (%s)\n", i, palette[i].index, palette[i].description );
    //     }
    //     // if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
    //     //     printf("  background  (00) = %2.2x (%s)\n", palette[0].index, palette[0].description );
    //     // } else {
    //     //     printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", palette[0].index, palette[0].description );
    //     // }
    //     // printf("  low screen  (01) = %2.2x (%s)\n", palette[1].index, palette[1].description );
    //     // printf("  high screen (10) = %2.2x (%s)\n", palette[2].index, palette[2].description );
    //     // printf("  colormap    (11) = %2.2x (%s)\n", palette[3].index, palette[3].description );
    //     // printf("\n" );
    //     // printf("\n" );
    // }
    
    // variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );
 
    return result;

}

Variable * ef9345_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return ef9345_new_image( _environment, 8, 8, TILEMAP_MODE_STANDARD );

}

void ef9345_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

}

void ef9345_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

}

void ef9345_wait_vbl( Environment * _environment ) {

}

Variable * ef9345_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = calculate_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = (_width & 0xff);
    *(buffer+1) = (_width>>8) & 0xff;
    *(buffer+2) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void ef9345_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette ) {

}


void ef9345_scroll( Environment * _environment, int _dx, int _dy ) {

}

void ef9345_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void ef9345_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void ef9345_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

}

void ef9345_tile_at( Environment * _environment, char * _x, char * _y, char *_result ) {

}

void ef9345_use_tileset( Environment * _environment, char * _tileset ) {

}

Variable * ef9345_get_raster_line( Environment * _environment ) {

}

void ef9345_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void ef9345_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void ef9345_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color ) {

}

#endif