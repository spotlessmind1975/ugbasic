/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

#ifdef __plus4__

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    { 0x00, 0x00, 0x00, 0, "BLACK" },
    { 0xff, 0xff, 0xff, 1, "WHITE" },
    { 0xbc, 0x68, 0x59, 2, "RED"  },
    { 0x43, 0x97, 0xa6, 3, "CYAN"   }, 
    { 0xbc, 0x52, 0xcc, 4, "PURPLE"  }, 
    { 0x43, 0xad, 0x33, 5, "GREEN"  }, 
    { 0x80, 0x71, 0xcc, 6, "BLUE"  }, 
    { 0x80, 0x8e, 0x33, 7, "YELLOW"  }, 
    { 0xbc, 0x6f, 0x33, 8, "ORANGE" }, 
    { 0x9e, 0x7f, 0x33, 9, "BROWN" }, 
    { 0x61, 0x9e, 0x33, 10, "YELLOW GREEN"  }, 
    { 0xbc, 0x61, 0x80, 11, "PINK" }, 
    { 0x43, 0x9e, 0x80, 12, "BLUE GREEN" }, 
    { 0x43, 0x90, 0xcc, 13, "LIGHT BLUE"  }, 
    { 0x9e, 0x61, 0xcc, 14, "DARK BLUE" },
    { 0x43, 0xa6, 0x59, 15, "LIGHT GREEN"  } 
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * ted_image_nearest_system_color( RGBi * _color ) {

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
 *     8x8 RGB (3 bytes) pixel (_source) [8x8x3 = 192 bytes]
 * into 
 *     8x8 bitmap (1 bit) pixel + 1 (byte) [8x1 + 1 = 9 bytes]
 *       foreground and background color (_dest)
 * 
 * Since the 8x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze.
 */
static void ted_image_converter_tile( char * _source, char * _dest, int _width, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];
    memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );

    char * source = _source;

    // Clear the box and colors
    memset( _dest, 0, 9 );

    // Loop for all the box surface
    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            // Take the color of the pixel
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = ted_image_nearest_system_color( &rgb );

            ++colorIndexesCount[systemRgb->index];

// printf( "%2.2x %2.2x\n", systemRgb->index, colorIndexesCount[systemRgb->index] );

            source += 3;

        }

        source += 3 * ( _source_width - 8 );

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

    source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = ted_image_nearest_system_color( &rgb );

            char bitmask = 1 << ( 7 - ((x) & 0x7) );

            if ( systemRgb->index != colorBackground ) {
                *( _dest + y ) |= bitmask;
                // printf("*");
            } else {
                *( _dest + y ) &= ~bitmask;
                // printf(" ");
            }

            source += 3;

        }

        source += 3 * ( _source_width - 8 );

    }

    *( _dest + 8 ) = ( colorForeground << 4 ) | colorBackground ;

    // printf( "%2.2x ", *( _dest + 8 ) );

}

/**
 * This method can be used to convert 
 *     WxH RGB (3 bytes) pixel (_source) [WxHx3 bytes]
 * into 
 *     WxH bitmap (1 bit) pixel + (W/8xH + W/8xH/8) (bytes)
 *       foreground and background color (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze.
 */
static void ted_image_converter_tiles( char * _source, char * _dest, int _width, int _height, int _source_width ) {

    int bitmapSize = ( _width>>3 ) * _height;
    int colormapSize = ( _width>>3 ) * (_height>>3);

    memset( _dest, 0, bitmapSize + colormapSize );

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=8 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * 3;
            char tile[9];

            ted_image_converter_tile( source, tile, _width, _source_width );

            int offset = ((y>>3) * 8 *( _width >> 3 ) ) + ((x>>3) * 8) + ((y) & 0x07);
            // x = 8, y = 8
            // offset = ((8 >> 3) * 8 * (16>>3) ) + ((8>>3) * 8) + ((8) & 7)
            // offset = (1 * 8 * 2 ) + (1 * 8)
            // offset = 16 + 8 = 24

            char * destBitmap = _dest + offset;
            char * destColormap = _dest + bitmapSize + ( ( ( y >> 3 ) * ( _width >> 3 ) ) + ( x >> 3 ) );
            for( int i=0; i<8; ++i ) {
                *destBitmap = tile[i];
                ++destBitmap;
            }
            // printf("tile at %d,%d color = %2.2x\n", x, y, (unsigned char)(tile[8]) );
            *destColormap = tile[8];            
        }
    }
}

/**
 * This method can be used to convert 
 *     4x8 RGB (3 bytes) pixel (_source) [8x8x3 = 192 bytes]
 * into 
 *     4x8 colormap (2 bit) pixel + 1 (bytes) [8x1 + 2 = 10 bytes]
 *       color1 [hi], color2, color3 [hi], background (_dest)
 * 
 * Since the 4x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze. Moreover, background
 * color should be given since it is not settable and it will
 * be returned as low nibble of second color byte.
 */
static void ted_image_converter_tile_multicolor( char * _source, char * _dest, int _width, int _background, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];
    memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );

    char * source = _source;

    // Clear the box and colors
    memset( _dest, 0, 10 );

    // Loop for all the box surface
    for (int y=0; y<8; ++y) {
        for (int x=0; x<4; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            // Take the color of the pixel
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = ted_image_nearest_system_color( &rgb );

            ++colorIndexesCount[systemRgb->index];

            source += 3;

        }

        source += 3 * ( _source_width - 4 );

    }

    colorIndexesCount[_background] = 0;

    int colorFirst = 0;
    int colorFirstMax = 0;
    int colorSecond = 0;
    int colorSecondMax = 0;
    int colorThird = 0;
    int colorThirdMax = 0;

    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorFirstMax ) {
            colorFirst = xx;
            colorFirstMax = colorIndexesCount[xx];
        };
    }

    colorIndexesCount[colorFirst] = 0;

    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorSecondMax ) {
            colorSecond = xx;
            colorSecondMax = colorIndexesCount[xx];
        };
    }

    colorIndexesCount[colorSecond] = 0;

    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorThirdMax ) {
            colorThird = xx;
            colorThirdMax = colorIndexesCount[xx];
        };
    }

    colorIndexesCount[colorThird] = 0;

    source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<4; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = ted_image_nearest_system_color( &rgb );

            char colorIndex = 0;

            if ( systemRgb->index == colorFirst ) {
                colorIndex = 1;
            } else if ( systemRgb->index == colorSecond ) {
                colorIndex = 2;
            } else if ( systemRgb->index == colorThird ) {
                colorIndex = 3;
            }
            
            char bitmask = colorIndex << (6 - ((x & 0x3) * 2));

            *(_dest + y) |= bitmask;

            source += 3;

        }

        source += 3 * ( _source_width - 4 );

    }

    *( _dest + 8 ) = ( colorFirst << 4 ) | colorSecond ;
    *( _dest + 9 ) = ( _background << 4 ) | colorThird;

}

/**
 * This method can be used to convert 
 *     WxH RGB (3 bytes) pixel (_source) [WxHx3 bytes]
 * into 
 *     WxH bitmap (2 bit) pixel + (W/4xH + 2*(W/4xH/8)) (bytes)
 *       color1 [hi], color2, color3 [hi], background (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze. Moreover, background
 * color is fixed also if it is returned as lower nibble
 * of one byte of 2 of colors.
 */
static void ted_image_converter_tiles_multicolor( char * _source, char * _dest, int _width, int _height, int _source_width, int _background ) {

    int bitmapSize = ( _width>>2 ) * _height;
    int colormap1Size = ( _width>>2 ) * (_height>>3);
    int colormap2Size = ( _width>>2 ) * (_height>>3);

    memset( _dest, 0, bitmapSize + colormap1Size + colormap2Size );

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=4 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * 3;
            char tile[10];

            ted_image_converter_tile_multicolor( source, tile, _width, _background, _source_width );

            int offset = ((y>>3) * 8 *( _width >> 2 ) ) + ((x>>2) * 8) + ((y) & 0x07);

            char * destBitmap = _dest + offset;
            char * destColormap1 = _dest + bitmapSize + ( ( ( y >> 3 ) * ( _width >> 2 ) ) + ( x >> 2 ) );
            char * destColormap2 = _dest + bitmapSize + colormap1Size + ( ( ( y >> 3 ) * ( _width >> 2 ) ) + ( x >> 2 ) );
            for( int i=0; i<8; ++i ) {
                *destBitmap = tile[i];
                ++destBitmap;
            }
            *destColormap1 = tile[8];
            *destColormap2 = tile[9];
        }
    }
}

void ted_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

}

void ted_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>TED</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void ted_border_color( Environment * _environment, char * _border_color ) {

    outline1("LDA %s", _border_color );
    outline0("AND #$0f" );
    outline0("STA $FF19");

}

/**
 * @brief <i>TED</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ted_background_color( Environment * _environment, int _index, int _background_color ) {
 
    outline1("LDA %2.2x", _background_color);
    outline0("AND #$0f");
    outline1("STA $FF15+%d", ( _index & 0x03 ) );
}

/**
 * @brief <i>TED</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ted_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $FF15,X");
}

/**
 * @brief <i>TED</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ted_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {
 
    outline1("LDA #$%2.2x", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $FF15,X");
}

/**
 * @brief <i>TED</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ted_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline0("LDA $FF15,X");
    outline0("AND #$0f" );
    outline1("STA %s", _background_color );
    
}

void ted_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>TED</i>: emit code to set raster irq
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
void ted_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    MAKE_LABEL

    outline0("SEI");
    outline1("LDA #<%s", _label);
    outline0("STA TEDISRSVC+1");
    outline1("LDA #>%s", _label);
    outline0("STA TEDISRSVC+2");
    outline0("LDA #%00000010");
    outline0("STA $FF0A");
    outline1("LDA %s", _positionlo );
    outline0("STA $FF0B");
    outline1("LDA %s", _positionhi );
    outline0("AND #%00000001" );
    cpu6502_beq(_environment, label);
    outline0("LDA $FF0A" );
    outline0("AND #%01111111" );
    outline0("ORA #%10000000" );
    outline0("STA $FF0A");
    outhead1("%s:", label );
    outline0("CLI");

}

/**
 * @brief <i>TED</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void ted_next_raster( Environment * _environment ) {

    outline0("ASL $FF09"); // acknowledge
    outline0("JMP $FCB3"); // KERNAL's standard interrupt service routine

}

/**
 * @brief <i>TED</i>: emit code to wait for next raster irq at different position
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
void ted_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    MAKE_LABEL

    outline1("LDA %s", _positionlo );
    outline0("STA $FF0B");
    outline1("LDA %s", _positionhi );
    outline0("AND #%00000001" );
    cpu6502_beq(_environment, label);
    outline0("LDA $FF0A" );
    outline0("AND #%01111111" );
    outline0("ORA #%10000000" );
    outline0("STA $FF0A");
    outhead1("%s:", label );
    outline1("LDA #<%s", _label);
    outline0("STA $TEDISRSVC+1");
    outline1("LDA #>%s", _label);
    outline0("STA $TEDISRSVC+2");

    ted_next_raster( _environment );

}

void ted_enable_ecm( Environment * _environment ) {

}

void ted_disable_ecm( Environment * _environment ) {

}

void ted_enable_mcm( Environment * _environment ) {

}

void ted_disable_mcm( Environment * _environment ) {

}

void ted_bank_select( Environment * _environment, int _bank ) {

}

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int colorIndex = 0;
    int minDistance = 0xffffffff;
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

int ted_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    _environment->screenTiles = 255;
    switch( _screen_mode->id ) {
        case BITMAP_MODE_STANDARD:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenColors = 2;
            // Enable graphics.
            outline0("LDA $FF06" );
            outline0("ORA #%00100000");
            outline0("STA $FF06" );

            // Let's enable monocolor graphics!
            outline0("LDA $FF07" );
            outline0("AND #%11101111");
            outline0("STA $FF07" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0x0800 );

            cpu_store_8bit( _environment, "_PEN", 0x01 );
            cpu_store_8bit( _environment, "_PAPER", 0x00 );
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 319 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 199 );
            
            break;
        case BITMAP_MODE_MULTICOLOR:
            _environment->fontWidth = 4;
            _environment->fontHeight = 8;
            _environment->screenWidth = 160;
            _environment->screenHeight = 200;
            _environment->screenColors = 4;
            // Enable graphics.
            outline0("LDA $FF06" );
            outline0("ORA #%00100000");
            outline0("STA $FF06" );

            // Let's enable multicolor graphics!
            outline0("LDA $FF07" );
            outline0("ORA #%00010000");
            outline0("STA $FF07" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0x0800 );
            
            cpu_store_8bit( _environment, "_PEN", 0x01 );
            cpu_store_8bit( _environment, "_PAPER", 0x00 );
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 159 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 199 );

            break;
        case TILEMAP_MODE_STANDARD:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenColors = 16;
            // Let's disable graphics (and extended color)!
            outline0("LDA $FF06" );
            outline0("AND #%10011111");
            outline0("STA $FF06" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0x0800 );

            cpu_store_8bit( _environment, "_PEN", 0x01 );
            cpu_store_8bit( _environment, "_PAPER", 0x00 );
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 39 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 24 );

            break;
        case TILEMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_EXTENDED:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenColors = 16;
            // Let's disable graphics and enable extended color!
            outline0("LDA $FF06" );
            outline0("AND #%11011111");
            outline0("ORA #%01000000");
            outline0("STA $FF06" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0x0800 );

            cpu_store_8bit( _environment, "_PEN", 0x01 );
            cpu_store_8bit( _environment, "_PAPER", 0x00 );
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 39 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 24 );

            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    _environment->screenTilesWidth = _environment->screenWidth / 8;
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    _environment->screenTilesHeight = _environment->screenHeight / 8;
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );

}

void ted_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        ted_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void ted_bitmap_disable( Environment * _environment ) {

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    // Let's disable graphics!
    outline0("LDA $FF06" );
    outline0("AND #%11011111");
    outline0("STA $FF06" );

    cpu_store_16bit( _environment, colormapAddress->realName, 0xd800 );

}

void ted_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {
        ted_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void ted_bitmap_at( Environment * _environment, char * _address ) {

}

void ted_colormap_at( Environment * _environment, char * _address ) {

}

void ted_textmap_at( Environment * _environment, char * _address ) {

}

void ted_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedvarsGraphic, src_hw_ted_vars_graphic_asm );
    deploy( plot, src_hw_ted_plot_asm );
    
    outline1("LDA %2.2x", (_x & 0xff ) );
    outline0("STA PLOTX");
    outline1("LDA %2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0("STA PLOTX+1");
    outline1("LDA %2.2x", ( _y & 0xff ) );
    outline0("STA PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void ted_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedvarsGraphic, src_hw_ted_vars_graphic_asm );
    deploy( plot, src_hw_ted_plot_asm );
    
    outline1("LDA %s", x->realName );
    outline0("STA PLOTX");
    outline1("LDA %s+1", x->realName );
    outline0("STA PLOTX+1");
    outline1("LDA %s", y->realName );
    outline0("STA PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void ted_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedvarsGraphic, src_hw_ted_vars_graphic_asm );
    deploy( plot, src_hw_ted_plot_asm );
    
    outline1("LDA %s", x->realName );
    outline0("STA PLOTX");
    outline1("LDA %s+1", x->realName );
    outline0("STA PLOTX+1");
    outline1("LDA %s", y->realName );
    outline0("STA PLOTY");
    outline0("LDA #3");
    outline0("STA PLOTM");
    outline0("JSR PLOT");
    outline0("LDA PLOTM");
    outline1("STA %s", result->realName);

}

void ted_screen_on( Environment * _environment ) {

}

void ted_screen_off( Environment * _environment ) {
    
}

void ted_screen_rows( Environment * _environment, char * _rows ) {

    MAKE_LABEL

    outline1("LDA %s", _rows);
    outline0("CMP #24");
    outline1("BEQ %s", label);
    outline0("LDA $FF06" );
    outline0("ORA #%00001000");
    outline0("STA $FF06" );
    outline1("JMP %s_2", label);
    outhead1("%s:", label );
    outline0("LDA $FF06" );
    outline0("AND #%11110111");
    outline0("STA $FF06" );
    outline1("JMP %s_2", label);
    outhead1("%s_2:", label );

}

void ted_screen_columns( Environment * _environment, char * _columns ) {

    MAKE_LABEL

    outline1("LDA %s", _columns);
    outline0("CMP #38");
    outline1("BEQ %s", label);
    outline0("LDA $FF07" );
    outline0("ORA #%00010000");
    outline0("STA $FF07" );
    outline1("JMP %s_2", label);
    outhead1("%s:", label );
    outline0("LDA $FF07" );
    outline0("AND #%11101111");
    outline0("STA $FF07" );
    outline1("JMP %s_2", label);
    outhead1("%s_2:", label );

}

void ted_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void ted_sprite_enable( Environment * _environment, char * _sprite ) {

}

void ted_sprite_disable( Environment * _environment, char * _sprite ) {

}

void ted_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void ted_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void ted_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void ted_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void ted_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void ted_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void ted_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void ted_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void ted_tiles_at( Environment * _environment, char * _address ) {

}

void ted_vertical_scroll( Environment * _environment, char * _displacement ) {

    outline0("LDA $FF06" );
    outline0("AND #%11111000");
    outline1("ORA %s", _displacement );
    outline0("STA $FF06" );

}

void ted_horizontal_scroll( Environment * _environment, char * _displacement ) {

    outline0("LDA $FF07" );
    outline0("AND #%11111000");
    outline1("ORA %s", _displacement );
    outline0("STA $FF07" );

}

void ted_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline0("LDA #$00");
    outline0("STA TMPPTR");
    outhead1("%sfirst:", label );
    outline0("LDA #$01");
    outhead1("%ssecond:", label );
    outline0("CMP $FF1D");
    outline1("BNE %ssecond", label);
    outhead1("%sthird:", label );
    outline0("CMP $FF1D");
    outline1("BEQ %sthird", label);
    outline0("INC TMPPTR");
    outline0("LDA TMPPTR");
    outline1("CMP %s", _timing );
    outline1("BNE %sfirst", label );

}

void ted_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTWIDTH" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTWIDTH+1" );
    outline1("STA %s+1", _result );

}

void ted_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILES" );
    outline1("STA %s", _result );

}

void ted_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESWIDTH" );
    outline1("STA %s", _result );

}

void ted_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTHEIGHT" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTHEIGHT+1" );
    outline1("STA %s+1", _result );

}

void ted_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESHEIGHT" );
    outline1("STA %s", _result );

}

void ted_cls( Environment * _environment ) {

    if ( _environment->currentMode == 2 || _environment->currentMode == 3 ) {
        deploy( clsGraphic, src_hw_ted_cls_graphic_asm );
        outline0("JSR CLSG");
    } else {
        deploy( clsText, src_hw_ted_cls_text_asm );
        outline0("JSR CLST");
    }

}

void ted_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollText, src_hw_ted_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void ted_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( scroll, src_hw_ted_scroll_asm);
    deploy( textHScroll, src_hw_ted_hscroll_text_asm );
    deploy( vScrollText, src_hw_ted_vscroll_text_asm );

    outline1("LDA #$%2.2x", (unsigned char)(_dx&0xff) );
    outline0("STA MATHPTR0" );
    outline1("LDA #$%2.2x", (unsigned char)(_dy&0xff) );
    outline0("STA MATHPTR1" );
    outline0("JSR SCROLL");

}

void ted_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( vScrollText, src_hw_ted_vscroll_text_asm );
    deploy( textEncodedAt, src_hw_ted_text_at_asm );

    outline1("LDA %s", _text);
    outline0("STA TEXTPTR" );
    outline1("LDA %s+1", _text);
    outline0("STA TEXTPTR+1" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );

    if ( _environment->currentMode == 2 || _environment->currentMode == 3 ) {
        deploy( tedvarsGraphic, src_hw_ted_vars_graphic_asm );
        deploy( clsGraphic, src_hw_ted_cls_graphic_asm );
        deploy( textEncodedAtGraphic, src_hw_ted_text_at_graphic_asm );
        outline0("JSR TEXTATBITMAPMODE");
    } else {
        deploy( clsText, src_hw_ted_cls_text_asm );
        deploy( textEncodedAtText, src_hw_ted_text_at_text_asm );
        outline0("JSR TEXTATTILEMODE");
    }

}

void ted_initialization( Environment * _environment ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );
    src_hw_chipset_mob_asm = src_hw_ted_mob_asm;
    src_hw_chipset_mob_asm_len = src_hw_ted_mob_asm_len;

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 320 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 200  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 25 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 320, 200, 2, 8, 8, "Standard Bitmap Mode" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 160, 200, 4, 8, 8, "Multicolor Bitmap Mode"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 25, 16, 8, 8, "Standard Character Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_EXTENDED, 0, 40, 25, 20, 8, 8, "Extended Multicolor Character Mode" );

    outline0("JSR TEDSTARTUP");
    outline0("JSR TEDUDCCHAR" );

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD, (unsigned short) (0xffff) );
    variable_global( _environment, "LINE" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

    variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION, 319 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 199 );
    variable_global( _environment, "CLIPY2" );

    ted_tilemap_enable( _environment, 40, 25, 16, 8, 8 );

    ted_cls( _environment );

    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

void ted_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.tedstartup ) {
        cpu_label( _environment, "TEDSTARTUP" );
        outline0( "RTS" );
        cpu_label( _environment, "MUSICPLAYER" );
        outline0( "RTS" );
    }

}

void ted_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_ted_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void ted_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_ted_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");
}

void ted_back( Environment * _environment ) {

    deploy( back, src_hw_ted_back_asm );

    outline0("JSR BACK");

}

/**
 * @brief Calculate the luminance of a color
 * 
 * This function calculates the luminance of a color. 
 * By luminance we mean the modulus of the three-dimensional 
 * vector, drawn in the space composed of the three components 
 * (red, green and blue). The returned value is normalized to
 * the nearest 8-bit value.
 * 
 * @param _a 
 * @return int 
 */
// 

static int calculate_luminance(RGBi _a) {

    // Extract the vector's components 
    // (each partecipate up to 1/3 of the luminance).
    double red = (double) _a.red / 3;
    double green = (double)_a.green / 3;
    double blue = (double)_a.blue / 3;

    // Calculate luminance using Pitagora's Theorem
    return (int)sqrt(pow(red, 2) + pow(green, 2) + pow(blue, 2));

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case BITMAP_MODE_STANDARD:

            return 3 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height >> 3 ) );

        case BITMAP_MODE_MULTICOLOR:

            return 3 + ( ( _width >> 2 ) * _height ) + 2 * ( ( _width >> 2 ) * ( _height >> 3 ) ) + 2;

        case TILEMAP_MODE_STANDARD:
        case TILEMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_EXTENDED:
            break;
    }

    return 0;

}

static Variable * ted_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );
    
    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE, 1 /* sorted */);

    // if (colorUsed > 2) {
    //     CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    // }
    
    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            // printf("%d <-> %d [%d] = %d [min = %d]\n", i, j, SYSTEM_PALETTE[j].index, distance, minDistance );
            if (distance < minDistance) {
                // printf(" candidated...\n" );
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        // printf(" ...used!\n" );
                        break;
                    }
                }
                if ( k>=i ) {
                    // printf(" ...ok! (%d)\n", SYSTEM_PALETTE[j].index );
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcpy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }
 
    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_STANDARD );
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

    *(buffer) = (_frame_width & 0xff );
    *(buffer+1) = (_frame_width >> 8 ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    ted_image_converter_tiles( _source, buffer+3, _frame_width, _frame_height, _width );

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}


static Variable * ted_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE, 1 /* sorted */);

    // if (colorUsed > 4) {
    //     CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    // }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            //printf("%d <-> %d [%d] = %d [min = %d]\n", i, j, SYSTEM_PALETTE[j].index, distance, minDistance );
            if (distance < minDistance) {
                //printf(" candidated...\n" );
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        //printf(" ...used!\n" );
                        break;
                    }
                }
                if ( k>=i ) {
                    //printf(" ...ok! (%d)\n", SYSTEM_PALETTE[j].index );
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcpy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );
    
    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_MULTICOLOR );
    
    char * buffer = malloc ( bufferSize );
    memset( buffer, 0, bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, offsetc, bitmask;

    // Color of the pixel to convert
    RGBi rgb;

    *(buffer) = (_frame_width & 0xff );
    *(buffer+1) = (_frame_width >> 8 ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _frame_width ) + _offset_x ) * 3;

    ted_image_converter_tiles_multicolor( _source, buffer+3, _frame_width, _frame_height, _width, palette[0].index );

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * ted_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {
        case BITMAP_MODE_STANDARD:

            return ted_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

        case BITMAP_MODE_MULTICOLOR:

            return ted_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

        case TILEMAP_MODE_STANDARD:
        case TILEMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_EXTENDED:
            break;
    }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return ted_new_image( _environment, 8, 8, BITMAP_MODE_STANDARD );

}

void ted_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tedvarsGraphic, src_hw_ted_vars_graphic_asm );
    deploy( putimage, src_hw_ted_put_image_asm );

    outline1("LDA #$%2.2x", _flags );
    outline0("STA IMAGET" );
    outline1("LDA #<%s", _image );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _image );
    outline0("STA TMPPTR+1" );

    if ( _sequence ) {

        outline0("CLC" );
        outline0("LDA TMPPTR" );
        outline0("ADC #3" );
        outline0("STA TMPPTR" );
        outline0("LDA TMPPTR+1" );
        outline0("ADC #0" );
        outline0("STA TMPPTR+1" );
        if ( strlen(_frame) == 0 ) {

        } else {
            outline1("LDA #<OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("STA TMPPTR2" );
            outline1("LDA #>OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("STA TMPPTR2+1" );
            outline0("CLC" );
            outline1("LDA %s", _sequence );
            outline0("ASL" );
            outline0("TAY" );
            outline0("LDA TMPPTR" );
            outline0("ADC (TMPPTR2), Y" );
            outline0("STA TMPPTR" );
            outline0("INY" );
            outline0("LDA TMPPTR+1" );
            outline0("ADC (TMPPTR2), Y" );
            outline0("STA TMPPTR+1" );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA #<OFFSETS%4.4x", _frame_size );
                outline0("STA TMPPTR2" );
                outline1("LDA #>OFFSETS%4.4x", _frame_size );
                outline0("STA TMPPTR2+1" );
                outline0("CLC" );
                outline1("LDA %s", _frame );
                outline0("ASL" );
                outline0("TAY" );
                outline0("LDA TMPPTR" );
                outline0("ADC (TMPPTR2), Y" );
                outline0("STA TMPPTR" );
                outline0("INY" );
                outline0("LDA TMPPTR+1" );
                outline0("ADC (TMPPTR2), Y" );
                outline0("STA TMPPTR+1" );
            }
        }

    } else {

        if ( _frame ) {
            outline0("CLC" );
            outline0("LDA TMPPTR" );
            outline0("ADC #3" );
            outline0("STA TMPPTR" );
            outline0("LDA TMPPTR+1" );
            outline0("ADC #0" );
            outline0("STA TMPPTR+1" );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA #<OFFSETS%4.4x", _frame_size );
                outline0("STA TMPPTR2" );
                outline1("LDA #>OFFSETS%4.4x", _frame_size );
                outline0("STA TMPPTR2+1" );
                outline0("CLC" );
                outline1("LDA %s", _frame );
                outline0("ASL" );
                outline0("TAY" );
                outline0("LDA TMPPTR" );
                outline0("ADC (TMPPTR2), Y" );
                outline0("STA TMPPTR" );
                outline0("INY" );
                outline0("LDA TMPPTR+1" );
                outline0("ADC (TMPPTR2), Y" );
                outline0("STA TMPPTR+1" );
            }
        }

    }
    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s+1", _x );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s+1", _y );
    outline0("STA IMAGEY+1" );
    outline1("LDA #$%2.2x", ( _flags & 0xff ) );
    outline0("STA IMAGEF" );

    outline0("JSR PUTIMAGE");

}

void ted_wait_vbl( Environment * _environment ) {

    deploy( vbl, src_hw_ted_vbl_asm);

    outline0("JSR VBL");

}

Variable * ted_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = calculate_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = ( _width & 0xff );
    *(buffer+1) = ( _width >> 8 ) & 0xff;
    *(buffer+2) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void ted_get_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tedvarsGraphic, src_hw_ted_vars_graphic_asm );
    deploy( getimage, src_hw_ted_get_image_asm );

    outline1("LDA #<%s", _image );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _image );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s+1", _x );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s+1", _y );
    outline0("STA IMAGEY+1" );

    outline0("JSR GETIMAGE");

}

void ted_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tiles, src_hw_ted_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline0("LDA #1" );
    outline0("STA TILEW" );
    outline0("STA TILEH" );
    outline0("STA TILEW2" );
    outline0("STA TILEH2" );

    outline0("JSR PUTTILE");

}

void ted_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tiles, src_hw_ted_tiles_asm );

    outline1("LDA %s", tile->realName );
    outline0("STA TILET" );
    outline1("LDA %s", x->realName );
    outline0("STA TILEX" );
    outline1("LDA %s", y->realName );
    outline0("STA TILEY" );
    outline1("LDA %s+1", tile->realName );
    outline0("STA TILEW" );
    outline0("STA TILEW2" );
    outline1("LDA %s+2", tile->realName );
    outline0("STA TILEH" );
    outline0("STA TILEH2" );
    outline1("LDA %s+3", tile->realName );
    outline0("STA TILEA" );

    int size = ( tile->originalWidth >> 3 ) * ( tile->originalHeight >> 3 );

    if ( size ) {
        outline1("LDA #<OFFSETS%4.4x", size );
        outline0("STA TMPPTR2" );
        outline1("LDA #>OFFSETS%4.4x", size );
        outline0("STA TMPPTR2+1" );
    } else {
        outline0("LDA #0" );
        outline0("STA TMPPTR2" );
        outline0("STA TMPPTR2+1" );
    }

    outline0("JSR MOVETILE");

}

void ted_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tiles, src_hw_ted_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline1("LDA %s+1", _tile );
    outline0("STA TILEW" );
    if ( _w ) {
        outline1("LDA %s", _w );
    }
    outline0("STA TILEW2" );
    outline1("LDA %s+2", _tile );
    outline0("STA TILEH" );
    if ( _h ) {
        outline1("LDA %s", _h );
    }
    outline0("STA TILEH2" );

    outline0("JSR PUTTILE");

}

void ted_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tiles, src_hw_ted_tiles_asm );

    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );

    outline0("JSR TILEAT");

    outline0("LDA TILET" );
    outline1("STA %s", _result );

}

void ted_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( tedvars, src_hw_ted_vars_asm);
    deploy( tiles, src_hw_ted_tiles_asm );

    outline1("LDA %s", _tileset );

    outline0("JSR USETILESET");

}

Variable * ted_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    outline0( "LDA $FF0B" );
    outline1( "STA %s", result->realName );
    outline0( "LDA $FF0A" );
    outline0( "AND #$01" );
    outline1( "STA %s+1", result->realName );

    return result;
    
}

/* audio */

static unsigned int SOUND_FREQUENCIES[] = {
    0,		0,		0,		0,		0,		0,		0,		0,		0,		0,
    0,		0,		0,		0,		0,		0,		0,		0,		0,		0,
    0,		0,		0,		-5816,  -5432,  -5070,  -4728,  -4405,  -4100,  -3812,
    -3541,  -3285,  -3043,  -2815,  -2599,  -2396,  -2204,  -2023,  -1852,  -1690,
    -1538,  -1394,  -1258,  -1130,  -1009,  -895,   -788,   -686,   -590,   -499,
    -414,   -333,   -257,   -185,   -117,   -53,    7,      64,     118,    169,
    217,    262,    305,    345,    383,    419,    453,    485,    516,    544,
    571,    597,    621,    643,    665,    685,    704,    722,    739,    755,
    770,    784,    798,    810,    822,    834,    844,    854,    864,    873,
    881,    889,    897,    904,    911,    917,    923,    929,    934,    939,
    944,    948,    953,    957,    960,    964,    967,    971,    974,    976,
    979,    982,    984,    986,    988,    990,    992,    994,    996
};

void ted_start( Environment * _environment, int _channels ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    if ( _channels & 0x01 ) {
        outline0("JSR TEDSTART0");
    }
    if ( _channels & 0x02 ) {
        outline0("JSR TEDSTART1");
    }

}

void ted_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    outline1("LDX #%2.2x", ( _volume & 0x0f ) );
    outline0("JSR TEDSTARTVOL");

}

#define FREQTED( f ) ( 1024 - (111841 / (f) ) )

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LDX #$%2.2x", ( FREQTED( f ) ) & 0xff ); \
    outline1("LDY #$%2.2x", ( ( FREQTED( f ) ) >> 8 ) & 0xff ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGFREQ1" ); \

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s+1", f ); \
    outline0("JSR TEDFREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LDX #$%2.2x", ( FREQTED( f ) ) & 0xff ); \
    outline1("LDY #$%2.2x", ( ( FREQTED( f ) ) >> 8 ) & 0xff ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDFREQ2" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGFREQ1" ); \

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s+1", f ); \
    outline0("JSR TEDPROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDPROGFREQ" );

#define     PROGRAM_PULSE( c, p ) \
    outline1("LDX #$%2.2x", ( p & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGPULSE0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGPULSE1" ); \

#define     PROGRAM_PULSE_V( c, p ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline1("LDX %s", p ); \
    outline1("LDY %s+1", p ); \
    outline0("JSR TEDPROGPULSE" );

#define     PROGRAM_PULSE_SV( c, p ) \
    outline1("LDX #$%2.2x", ( p & 0xff ) ); \
    outline1("LDY #$%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDPROGPULSE" );

#define     PROGRAM_NOISE( c ) \
    outline0("LDX #$82" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGCTR1" ); \

#define     PROGRAM_NOISE_V( c, p ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("LDX #$82" ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_NOISE_SV( c ) \
    outline0("LDX #$82" ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_SAW( c ) \
    outline0("LDX #$22" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGCTR1" ); \

#define     PROGRAM_SAW_V( c) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("LDX #$22" ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_SAW_SV( c ) \
    outline0("LDX #$22" ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_TRIANGLE( c ) \
    outline0("LDX #$12" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGCTR1" ); \

#define     PROGRAM_TRIANGLE_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("LDX #$12" ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_TRIANGLE_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("LDX #$12" ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_SAW_TRIANGLE( c ) \
    outline0("LDX #$32" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGCTR1" ); \

#define     PROGRAM_SAW_TRIANGLE_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("LDX #$32" ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_SAW_TRIANGLE_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("LDX #$32" ); \
    outline0("JSR TEDPROGCTR" );

#define     PROGRAM_ATTACK_DECAY( c, a, d ) \
    outline1("LDX #$%2.2x", ( a & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( d & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGAD0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGAD1" ); \

#define     PROGRAM_ATTACK_DECAY_V( c, a, d ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline1("LDX %s", a ); \
    outline1("LDY %s", d ); \
    outline0("JSR TEDPROGAD" );

#define     PROGRAM_ATTACK_DECAY_SV( c, a, d ) \
    outline1("LDX #$%2.2x", ( a & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( d & 0x0f ) ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDPROGAD" );

#define     PROGRAM_SUSTAIN_RELEASE( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDPROGSR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDPROGSR1" ); \

#define     PROGRAM_SUSTAIN_RELEASE_V( c, s, r ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline1("LDX %s", s ); \
    outline1("LDY %s", r ); \
    outline0("JSR TEDPROGSR" );

#define     PROGRAM_SUSTAIN_RELEASE_SV( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDPROGSR" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR TEDSTOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR TEDSTOP1" ); \

#define     STOP_FREQUENCY_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDSTOP" );

#define     STOP_FREQUENCY_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$3" : c ) ); \
    outline0("JSR TEDSTOP" );

void ted_set_program( Environment * _environment, int _channels, int _program ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 11);
            PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 4);
            PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 4, 2);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            PROGRAM_PULSE(_channels, 1024);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 1, 2);
            PROGRAM_SUSTAIN_RELEASE(_channels, 4, 3);
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 1, 14);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;
    }

}

void ted_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void ted_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void ted_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void ted_set_note( Environment * _environment, int _channels, int _note ) {

    ted_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void ted_stop( Environment * _environment, int _channels ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    STOP_FREQUENCY( _channels );

}

void ted_start_var( Environment * _environment, char * _channels ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$3" );
    }
    outline0("JSR TEDSTART");

}

void ted_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    outline1("LDA %s", _volume );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("TAX" );
    outline0("JSR TEDSTARTVOL");

}

void ted_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    outline1("LDX #$%2.2x", _volume );
    outline0("JSR TEDSTARTVOL");

}

void ted_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 11);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 4);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 4, 2);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            PROGRAM_PULSE_SV(_channels, 1024);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 1, 2);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 4, 3);
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 1, 14);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            PROGRAM_SAW_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_SAW_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;
    }

}

void ted_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$3" );
    }
    outline1("LDX %s", _frequency );
    outline1("LDY %s+1", _frequency );

    outline0("JSR TEDFREQ");

}

void ted_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$3" );
    }
    outline1("LDX %s", _pitch );
    outline1("LDY %s+1", _pitch );

    outline0("JSR TEDPROGFREQ");

}

void ted_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    outline0("LDA #<TEDFREQTABLE");
    outline0("STA TMPPTR");
    outline0("LDA #>TEDFREQTABLE");
    outline0("STA TMPPTR+1");
    outline1("LDY %s", _note);
    outline0("TYA");
    outline0("ASL");
    outline0("TAY");
    outline0("LDA (TMPPTR),Y");
    outline0("TAX");
    outline0("INY");
    outline0("LDA (TMPPTR),Y");
    outline0("TAY");

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$3" );
    }

    outline0("JSR TEDPROGFREQ");

}

void ted_stop_vars( Environment * _environment, char * _channels ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    outline1("LDA %s", _channels );
    outline0("JSR TEDSTOP");

}

void ted_music( Environment * _environment, char * _music, int _size ) {

    deploy( tedvars, src_hw_ted_vars_asm );
    deploy( tedstartup, src_hw_ted_startup_asm );

    outline0("SEI");
    outline0("LDA #$0");
    outline0("STA TEDJIFFIES");
    outline0("STA TEDTMPOFS");
    outline0("LDA #$1");
    outline0("STA TEDMUSICREADY");
    outline1("LDA #<%s", _music);
    outline0("STA TEDTMPPTR");
    outline1("LDA #>%s", _music);
    outline0("STA TEDTMPPTR+1");
    outline1("LDA #$%2.2x", ( _size>>8 ) & 0xff);
    outline0("STA TEDBLOCKS");
    outline1("LDA #$%2.2x", _size & 0xff );
    outline0("STA TEDLASTBLOCK");
    if ( _size > 255 ) {
        outline0("LDA #$ff");
    }
    outline0("STA TEDTMPLEN");
    outline0("CLI");

}

#endif