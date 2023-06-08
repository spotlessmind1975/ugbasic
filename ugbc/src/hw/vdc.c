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

#if defined(__c128xx__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0xff, 0, "BLACK" },
        { 0xff, 0xff, 0xff, 0xff, 1, "WHITE" },
        { 0x80, 0x00, 0x00, 0xff, 2, "RED" },
        { 0xaa, 0xff, 0xe6, 0xff, 3, "CYAN" },
        { 0xcc, 0x44, 0xcc, 0xff, 4, "VIOLET" },
        { 0x00, 0xcc, 0x55, 0xff, 5, "GREEN" },
        { 0x00, 0x00, 0xaa, 0xff, 6, "BLUE" },
        { 0xee, 0xee, 0x77, 0xff, 7, "YELLOW" },
        { 0xa1, 0x68, 0x3c, 0xff, 8, "ORANGE" },
        { 0xdd, 0x88, 0x65, 0xff, 9, "BROWN" },
        { 0xff, 0x77, 0x77, 0xff, 10, "LIGHT_RED" },
        { 0x33, 0x33, 0x33, 0xff, 11, "DARK_GREY" },
        { 0x77, 0x77, 0x77, 0xff, 12, "GREY" },
        { 0xaa, 0xff, 0x66, 0xff, 13, "LIGHT GREEN" },
        { 0x00, 0x88, 0xff, 0xff, 14, "LIGHT BLUE" },
        { 0xbb, 0xbb, 0xbb, 0xff, 15, "LIGHT GREY" }
};

static RGBi * commonPalette;
static int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * vdc_image_nearest_system_color( RGBi * _color ) {

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
static void vdc_image_converter_tile( Environment * _environment, char * _source, char * _dest, int _width, int _depth, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];
    memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );
    int trans = 0;

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
                RGBi *systemRgb = vdc_image_nearest_system_color( &rgb );
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

    source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

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

            RGBi *systemRgb = vdc_image_nearest_system_color( &rgb );

            char bitmask = 1 << ( 7 - ((x) & 0x7) );

            if ( rgb.alpha < 255 ) {
                *( _dest + y ) &= ~bitmask;
                adilinepixel(colorBackground);
            } else {
                if ( systemRgb->index != colorBackground ) {
                    adilinepixel(colorForeground);
                    *( _dest + y ) |= bitmask;
                    // printf("*");
                } else {
                   adilinepixel(colorBackground);
                     *( _dest + y ) &= ~bitmask;
                    // printf(" ");
                }
            }

            source += _depth;

        }

        source += _depth * ( _source_width - 8 );

    }

    *( _dest + 8 ) = ( colorForeground << 4 ) | colorBackground ;

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
static void vdc_image_converter_tiles( Environment * _environment, char * _source, char * _dest, int _width, int _height, int _depth, int _source_width ) {

    int bitmapSize = ( _width>>3 ) * _height;
    int colormapSize = ( _width>>3 ) * (_height>>3);

    memset( _dest, 0, bitmapSize + colormapSize );

    adilinebeginbitmap("BMD2");

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=8 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * _depth;
            char tile[9];

            vdc_image_converter_tile( _environment, source, tile, _width, _depth, _source_width );

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
            // printf("tile at %d,%d color = %2.2x\n", x, y, tile[8] );
            *destColormap = tile[8];            
        }
    }

    adilineendbitmap();

}

/**
 * This method can be used to convert 
 *     4x8 RGB (3/4 bytes) pixel (_source) [8x8x3/4 = 192/256 bytes]
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
static void vdc_image_converter_tile_multicolor( Environment * _environment, char * _source, char * _dest, int _width, int _depth, int _background, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];
    memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );
    int trans = 0;

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

                RGBi *systemRgb = vdc_image_nearest_system_color( &rgb );

                ++colorIndexesCount[systemRgb->index];

            }

            source += _depth;

        }

        source += _depth * ( _source_width - 4 );

    }

    if ( trans ) {
        _background = 0;
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

            char colorIndex = 0;

            if ( rgb.alpha < 255 ) {
                adilinepixel(_background);
                colorIndex = 0;
            } else {

                RGBi *systemRgb = vdc_image_nearest_system_color( &rgb );

                if ( systemRgb->index == colorFirst ) {
                    adilinepixel(colorFirst);
                    colorIndex = 1;
                } else if ( systemRgb->index == colorSecond ) {
                    adilinepixel(colorSecond);
                    colorIndex = 2;
                } else if ( systemRgb->index == colorThird ) {
                    adilinepixel(colorThird);
                    colorIndex = 3;
                } else {
                    adilinepixel(_background);
                }

            }

            char bitmask = colorIndex << (6 - ((x & 0x3) * 2));

            *(_dest + y) |= bitmask;

            source += _depth;

        }

        source += _depth * ( _source_width - 4 );

    }

    *( _dest + 8 ) = ( colorFirst << 4 ) | colorSecond ;
    *( _dest + 9 ) = ( _background << 4 ) | colorThird;

}

/**
 * This method can be used to convert 
 *     WxH RGB (3/4 bytes) pixel (_source) [WxHx3/4 bytes]
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
static void vdc_image_converter_tiles_multicolor( Environment * _environment, char * _source, char * _dest, int _width, int _height, int _depth, int _source_width, int _background ) {

    int bitmapSize = ( _width>>2 ) * _height;
    int colormap1Size = ( _width>>2 ) * (_height>>3);
    int colormap2Size = ( _width>>2 ) * (_height>>3);

    memset( _dest, 0, bitmapSize + colormap1Size + colormap2Size );

    adilinebeginbitmap("BMD4");

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=4 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * _depth;
            char tile[10];

            vdc_image_converter_tile_multicolor( _environment, source, tile, _width, _depth, _background, _source_width );

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

    adilineendbitmap();

}

/**
 * @brief <i>VDC</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * vdc_collision( Environment * _environment, char * _sprite ) {

    _environment->bitmaskNeeded = 1;

    deploy( sprite, src_hw_vdc_sprites_asm );

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_SPRITE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(collision result)");

    MAKE_LABEL

    return result;

}

/**
 * @brief <i>VDC</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void vdc_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    // Generate unique label for ASM code.
    MAKE_LABEL

}

/**
 * @brief <i>VDC</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void vdc_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>VDC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdc_background_color( Environment * _environment, int _index, int _background_color ) {
 
}

/**
 * @brief <i>VDC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdc_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {
 
}

/**
 * @brief <i>VDC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdc_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {
 
}

/**
 * @brief <i>VDC</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vdc_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {
 
}

/**
 * @brief <i>VDC</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void vdc_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {
 
}

/**
 * @brief <i>VDC</i>: emit code to set raster irq
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
void vdc_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VDC</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void vdc_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>VDC</i>: emit code to wait for next raster irq at different position
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
void vdc_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VDC</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void vdc_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VDC</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vdc_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VDC</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void vdc_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VDC</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vdc_disable_mcm( Environment * _environment ) {

}

void vdc_bank_select( Environment * _environment, int _bank ) {
    
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

int vdc_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

}

void vdc_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void vdc_bitmap_disable( Environment * _environment ) {

}

void vdc_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

}

void vdc_bitmap_at( Environment * _environment, char * _address ) {

}

void vdc_colormap_at( Environment * _environment, char * _address ) {

}

void vdc_textmap_at( Environment * _environment, char * _address ) {

}

void vdc_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( plot, src_hw_vdc_plot_asm );
    
}

void vdc_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( plot, src_hw_vdc_plot_asm );
    
}

void vdc_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( plot, src_hw_vdc_plot_asm );
    
}

void vdc_screen_on( Environment * _environment ) {

}

void vdc_screen_off( Environment * _environment ) {
    
}

void vdc_screen_rows( Environment * _environment, char * _rows ) {

}

void vdc_screen_columns( Environment * _environment, char * _columns ) {

}

void vdc_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

    _environment->bitmaskNeeded = 1;

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * image = variable_retrieve_or_define( _environment, _image, VT_IMAGE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );

}

void vdc_sprite_enable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );

}

void vdc_sprite_disable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_multicolor( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_monocolor( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    deploy( sprite, src_hw_vdc_sprites_asm );
    
}

void vdc_tiles_at( Environment * _environment, char * _address ) {

}

void vdc_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void vdc_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void vdc_busy_wait( Environment * _environment, char * _timing ) {

}

void vdc_get_width( Environment * _environment, char *_result ) {

}

void vdc_tiles_get( Environment * _environment, char *_result ) {

}

void vdc_tiles_get_width( Environment * _environment, char *_result ) {

}

void vdc_get_height( Environment * _environment, char *_result ) {

}

void vdc_tiles_get_height( Environment * _environment, char *_result ) {

}

void vdc_cls( Environment * _environment ) {
    
}

void vdc_scroll_text( Environment * _environment, int _direction ) {

}

void vdc_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vScrollTextUp, src_hw_vdc_vscroll_text_up_asm );
    deploy( textEncodedAt, src_hw_vdc_text_at_asm );

}

void vdc_initialization( Environment * _environment ) {

}

static RGBi * multicolorSpritePalette[2];

void vdc_finalization( Environment * _environment ) {

}

void vdc_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_vdc_hscroll_text_asm );

}

void vdc_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_vdc_hscroll_text_asm );

}

void vdc_back( Environment * _environment ) {

    deploy( back, src_hw_vdc_back_asm );

}

void vdc_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_vdc_cline_asm );

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    return 0;

}

Variable * vdc_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

Variable * vdc_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color, int _flags ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

void vdc_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( putimage, src_hw_vdc_put_image_asm );

}

void vdc_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( blitimage, src_hw_vdc_blit_image_asm );

}

void vdc_wait_vbl( Environment * _environment ) {

    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( vbl, src_hw_vdc_vbl_asm);

}

Variable * vdc_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    return result;

}

void vdc_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( vdcvarsGraphic, src_hw_vdc_vars_graphic_asm );
    deploy( getimage, src_hw_vdc_get_image_asm );

}

void vdc_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( scroll, src_hw_vdc_scroll_asm);
    deploy( textHScroll, src_hw_vdc_hscroll_text_asm );
    deploy( vScrollTextDown, src_hw_vdc_vscroll_text_down_asm );
    deploy( vScrollTextUp, src_hw_vdc_vscroll_text_up_asm );

}

void vdc_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( tiles, src_hw_vdc_tiles_asm );

}

void vdc_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( tiles, src_hw_vdc_tiles_asm );

}

void vdc_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( tiles, src_hw_vdc_tiles_asm );

}

void vdc_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( tiles, src_hw_vdc_tiles_asm );

}

void vdc_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( vdcvars, src_hw_vdc_vars_asm);
    deploy( tiles, src_hw_vdc_tiles_asm );

}

Variable * vdc_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    return result;
    
}


#endif