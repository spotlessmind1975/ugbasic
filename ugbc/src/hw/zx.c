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

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0xff, 0, "BLACK" },        
        { 0x00, 0x00, 0xff, 0xff, 1, "BLUE" },
        { 0x88, 0x00, 0x00, 0xff, 2, "RED" },
        { 0xff, 0x00, 0xff, 0xff, 3, "MAGENTA" },
        { 0x00, 0xcc, 0x00, 0xff, 4, "GREEN" },
        { 0xaa, 0xff, 0xe6, 0xff, 5, "CYAN" },
        { 0xee, 0xee, 0x77, 0xff, 6, "YELLOW" },
        { 0xff, 0xff, 0xff, 0xff, 7, "WHITE" }
};

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __zx__

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case BITMAP_MODE_STANDARD:
        case TILEMAP_MODE_STANDARD:
            return 2 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height >> 3 ) );

    }

    return 0;

}

void zx_color_border( Environment * _environment, char * _color ) {

    char port[MAX_TEMPORARY_STORAGE]; sprintf(port, "$%2.2x", PORT_COLOR_BORDER);

    z80_port_out( _environment, port, _color );

}

void zx_vscroll( Environment * _environment, int _displacement ) {

    outline1("LD A, $%2.2x", ( _displacement & 0xff ) );

    deploy( vars,src_hw_zx_vars_asm);
    deploy( vScroll,src_hw_zx_vscroll_asm );

    outline0("CALL VSCROLL");

}

void zx_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( vars,src_hw_zx_vars_asm);
    deploy( vScroll, src_hw_zx_vscroll_asm );
    deploy( textEncodedAt, src_hw_zx_text_at_asm );

    // z80_move_8bit( _environment, _tab, "TABCOUNT");

    outline1("LD A, (%s)", _text_size );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline1("LD HL, (%s)", _text );
    outline0("CALL TEXTAT");

}

void zx_cls( Environment * _environment, char * _pen, char * _paper ) {

    deploy( vars,src_hw_zx_vars_asm);
    deploy( cls, src_hw_zx_cls_asm );

    if ( _pen ) {
        z80_move_8bit( _environment, _pen, "_PEN");
    }
    if ( _paper ) {
        z80_move_8bit( _environment, _paper, "_PAPER");
    }

    outline0("CALL CLS");

}

void zx_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    outhead1("zxinkey%s:",label);
    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed );
    outline1("LD (%s), A", _key );
    outline0("LD A, ($5C08)");
    outline0("CP 0");
    outline1("JR Z, %snokey", label );
    outline1("LD (%s), a", _key );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outline0("LD A, 0");
    outline0("LD ($5C08), A");
    outhead1("%snokey:", label );
   
}

void zx_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_zx_scancode_asm );

    outline0("LD A, 0");
    outline1("LD (%s), A", _scancode );
    outline1("LD (%s), A", _pressed );
    outline0("CALL SCANCODE");
    outline0("CP 0");
    outline1("JR Z,%snokey", label);
    outline1("LD (%s), A", _scancode );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outhead1("%snokey:", label );
   
}

void zx_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    zx_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_return( _environment );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_return( _environment );

}

void zx_scanshift( Environment * _environment, char * _shifts ) {

    // 653	
    // Shift key indicator. Bits:
    // Bit #0: 1 = One or more of left Shift, right Shift or Shift Lock is currently being pressed or locked.
    // Bit #1: 1 = Commodore is currently being pressed.
    // Bit #2: 1 = Control is currently being pressed.
    // NO SHIFT (0) - if no SHIFT key pressed;
    // LEFT SHIFT (1) - if the left SHIFT pressed;
    // RIGHT SHIFT (2) - if the right SHIFT pressed;
    // BOTH SHIFTS (3) - if both keys pressed.

    MAKE_LABEL

    deploy( scancode, src_hw_zx_scancode_asm );

    outline0("CALL SCANCODE");
    outline0("CP $f1");
    outline1("JR NZ,%snokey", label);
    outline0("LD A, $03");
    outline1("LD (%s), A", _shifts );
    outhead1("%snokey:", label );

}

void zx_keyshift( Environment * _environment, char * _shifts ) {

    // On the same way, KEY SHIFT is used to report the current status of those keys 
    // which cannot be detected by either INKEY$ or SCANCODE because they do not 
    // carry the relevant codes. These control keys cannot be tested individually, or a test can be set up for any combination of such keys pressed together. A single call to the KEY SHIFT function can test for all eventualities, by examining a bit map in the following format:

    MAKE_LABEL

    deploy( scancode, src_hw_zx_scancode_asm );

    outline0("CALL SCANCODE");
    outline0("CP $f1");
    outline1("JR NZ,%snokey", label);
    outline0("LD A, $03");
    outline1("LD (%s), A", _shifts );
    outhead1("%snokey:", label );

}

void zx_clear_key( Environment * _environment ) {

}

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int colorIndex = 0;
    int j = 0;
    unsigned int minDistance = 0xffffffff;

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

void zx_initialization( Environment * _environment ) {

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256);
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 192  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 32 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 24 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 192, 256, 2, 8, 8, "Standard Bitmap Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 32, 25, 8, 8, 8, "(emulated) Standard Character Mode" );

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    variable_global( _environment, "LINE" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

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
    variable_global( _environment, "XCURS" );
    variable_import( _environment, "YCURSYS", VT_BYTE, 0 );
    variable_global( _environment, "YCURS" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

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

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );
    
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );

    _environment->currentRgbConverterFunction = rgbConverterFunction;

    _environment->screenWidth = 256;
    _environment->screenHeight = 192;
    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenColors = COLOR_COUNT;

}

void zx_finalization( Environment * _environment ) {

}

void zx_screen_rows( Environment * _environment, char * _rows ) {

}

void zx_screen_columns( Environment * _environment, char * _columns ) {

}

int zx_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    _environment->screenWidth = 256;
    _environment->screenHeight = 192;
    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenColors = 8;
}

void zx_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    deploy( vars, src_hw_zx_vars_asm );

}

void zx_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void zx_back( Environment * _environment ) {

    deploy( back, src_hw_zx_back_asm );

    outline0("CALL BACK");

}

static Variable * zx_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    (void)!_transparent_color;

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

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
    
    int bufferSize = 2 + ( ( _frame_width >> 3 ) * _frame_height ) + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) );
    // printf("bufferSize = %d\n", bufferSize );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_DEFAULT );

    adilinebeginbitmap("BMD");

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

    *(buffer) = _frame_width;
    *(buffer+1) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; image_x+=8) {

            int colorIndexCount[16];
            memset( colorIndexCount, 0, 16 * sizeof(int) );

            int xx;

            int colorIndex = 0;

            for( xx = 0; xx < 8; ++xx ) {
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

                colorIndex = 0;

                int minDistance = 9999;
                for( int i=0; i<(sizeof(SYSTEM_PALETTE)/sizeof(RGBi)); ++i ) {
                    int distance = rgbi_distance(&SYSTEM_PALETTE[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = SYSTEM_PALETTE[i].index;
                    }
                }

                ++colorIndexCount[colorIndex];

                _source += _depth;

            }

            *_source -= 8 * ( _depth );

            int colorBackgroundMax = 0;
            int colorBackground = 0;
            int colorForegroundMax = 0;
            int colorForeground = 0;

            for( int xx = 0; xx<(sizeof(SYSTEM_PALETTE)/sizeof(RGBi)); ++xx ) {
                if ( colorIndexCount[xx] > colorBackgroundMax ) {
                    colorBackground = xx;
                    colorBackgroundMax = colorIndexCount[xx];
                };
            }

            colorIndexCount[colorBackground] = 0;

            for( int xx = 0; xx<(sizeof(SYSTEM_PALETTE)/sizeof(RGBi)); ++xx ) {
                if ( colorIndexCount[xx] > colorForegroundMax ) {
                    colorForeground = xx;
                    colorForegroundMax = colorIndexCount[xx];
                };
            }

            colorIndexCount[colorForeground] = 0;

            for( xx = 0; xx < 8; ++xx ) {
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

                colorIndex = 0;

                int minDistance = 9999;
                for( int i=0; i<(sizeof(SYSTEM_PALETTE)/sizeof(RGBi)); ++i ) {
                    int distance = rgbi_distance(&SYSTEM_PALETTE[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = SYSTEM_PALETTE[i].index;
                    }
                }

                // printf("%d", i );

                // Calculate the relative tile
                tile_y = (image_y >> 3);
                tile_x = (image_x >> 3);
                
                // Calculate the offset starting from the tile surface area
                // and the bit to set.
                offset = (tile_y * 8 *( _frame_width >> 3 ) ) + (tile_x * 8) + (image_y & 0x07);
                bitmask = 1 << ( 7 - ((image_x+xx) & 0x7) );

                if ( colorIndex == colorForeground ) {
                    adilinepixel(colorForeground);
                    *( buffer + offset + 2) |= bitmask;
                } else {
                    adilinepixel(colorBackground);
                    *( buffer + offset + 2) &= ~bitmask;
                }

                offset = tile_y * ( _frame_width >> 3 ) + tile_x;
                *( buffer + 2 + ( ( _frame_width >> 3 ) * _height ) + offset ) = ( colorForeground << 3 ) | ( colorBackground ); 

                _source += _depth;

            }

        }

        _source += _depth * ( _width - _frame_width );

        // printf("\n" );

    }

    adilineendbitmap();

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

Variable * zx_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {

        case BITMAP_MODE_STANDARD:
        case TILEMAP_MODE_STANDARD:

            return zx_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

            break;
    }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return zx_new_image( _environment, 8, 8, BITMAP_MODE_STANDARD );

}

void zx_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    // currently unused
    (void)!_flags;

    MAKE_LABEL

    deploy( vars, src_hw_zx_vars_asm);
    deploy( putimage, src_hw_zx_put_image_asm );

    outline1("LD HL, %s", _image );
    if ( _sequence ) {

        outline0("INC HL" );
        outline0("INC HL" );
        outline0("INC HL" );
        if ( strlen(_sequence) == 0 ) {

        } else {

            outline1("LD DE, OFFSETS%4.4x", _frame_size * _frame_count );
            outline1("LD A, (%s)", _sequence );
            outline0("CMP 0" );
            outline1("JR Z, %sdone", label );
            outhead1("%sloop:", label );
            outline0("INC DE" );
            outline0("DEC B" );
            outline0("CMP 0" );
            outline1("JR NZ, %sloop", label );
            outline0("ADD HL, DE" );
            outhead1("%sdone:", label );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {

                outline1("LD DE, OFFSETS%4.4x", _frame_size );
                outline1("LD A, (%s)", _frame );
                outline0("CMP 0" );
                outline1("JR Z, %s2done", label );
                outhead1("%s2loop:", label );
                outline0("INC DE" );
                outline0("DEC B" );
                outline0("CMP 0" );
                outline1("JR NZ, %s2loop", label );
                outline0("ADD HL, DE" );
                outhead1("%s2done:", label );
            }

        }

    } else {

        if ( _frame ) {
            outline0("INC HL" );
            outline0("INC HL" );
            if ( strlen(_frame) == 0 ) {

            } else {

                outline1("LD DE, OFFSETS%4.4x", _frame_size );
                outline1("LD A, (%s)", _frame );
                outline0("CMP 0" );
                outline1("JR Z, %sdone", label );
                outhead1("%sloop:", label );
                outline0("INC DE" );
                outline0("DEC B" );
                outline0("CMP 0" );
                outline1("JR NZ, %sloop", label );
                outline0("ADD HL, DE" );
                outhead1("%sdone:", label );
            }

        }

    }
    outline1("LD A, (%s)", _x );
    outline0("LD (IMAGEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (IMAGEY), A" );
    outline1("LD A, $%2.2x", ( _flags & 0xff ) );
    outline0("LD (IMAGEF), A" );
    outline1("LD A, $%2.2x", ( (_flags>>8) & 0xff ) );
    outline0("LD (IMAGET), A" );

    outline0("CALL PUTIMAGE");

}

Variable * zx_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    deploy( vars, src_hw_zx_vars_asm );

    int size = calculate_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = ( _width & 0xff );
    *(buffer+1) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void zx_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette ) {
    
    MAKE_LABEL

    deploy( vars, src_hw_zx_vars_asm);
    deploy( getimage, src_hw_zx_get_image_asm );

    outline1("LD HL, %s", _image );
    outline1("LD A, (%s)", _x );
    outline0("LD (IMAGEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (IMAGEY), A" );
    outline1("LD A, $%2.2x", _palette & 0xff );
    outline0("LD (IMAGET), A" );

    outline0("CALL GETIMAGE");

}

void zx_scroll( Environment * _environment, int _dx, int _dy ) {

};

void zx_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( zxvars, src_hw_zx_vars_asm);
    deploy( tiles, src_hw_zx_tiles_asm );

    outline1("LD A, (%s)", _tile );
    outline0("LD (TILET), A" );
    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );
    outline0("LD A, 1" );
    outline0("LD (TILEW), A" );
    outline0("LD (TILEH), A" );
    outline0("LD (TILEW2), A" );
    outline0("LD (TILEH2), A" );

    outline0("CALL PUTTILE");

}

void zx_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( zxvars, src_hw_zx_vars_asm);
    deploy( tiles, src_hw_zx_tiles_asm );

    int size = ( tile->originalWidth >> 3 ) * ( tile->originalHeight >> 3 );

    if ( size ) {
        outline1("LD HL, OFFSETS%4.4x", size );
        outline0("LD A, L" );
        outline0("LD (TILEO), A" );
        outline0("LD A, H" );
        outline0("LD (TILEO+1), A" );
    } else {
        outline0("LD A, 0" );
        outline0("LD (TILEO), A" );
        outline0("LD (TILEO+1), A" );
    }

    outline1("LD A, (%s)", tile->realName );
    outline0("LD (TILET), A" );
    outline1("LD A, (%s)", x->realName );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", y->realName );
    outline0("LD (TILEY), A" );
    outline1("LD A, (%s+1)", tile->realName );
    outline0("LD (TILEW), A" );
    outline0("LD (TILEW2), A" );
    outline1("LD A, (%s+2)", tile->realName );
    outline0("LD (TILEH), A" );
    outline0("LD (TILEH2), A" );
    outline1("LD A, (%s+3)", tile->realName );
    outline0("LD (TILEA), A" );

    outline0("CALL MOVETILE");

}

void zx_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( zxvars, src_hw_zx_vars_asm);
    deploy( tiles, src_hw_zx_tiles_asm );

    outline1("LD A, (%s)", _tile );
    outline0("LD (TILET), A" );
    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );
    outline1("LD A, (%s+1)", _tile );
    outline0("LD (TILEW), A" );
    if ( _w ) {
        outline1("LD A, (%s)", _w );
    }
    outline0("LD (TILEW2), A" );
    outline1("LD A, (%s+2)", _tile );
    outline0("LD (TILEH), A" );
    if ( _h ) {
        outline1("LD A, (%s)", _h );
    }
    outline0("LD (TILEH2), A" );

    outline0("CALL PUTTILE");

}

void zx_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( zxvars, src_hw_zx_vars_asm);
    deploy( tiles, src_hw_zx_tiles_asm );

    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );

    outline0("CALL TILEAT");

    outline0("LD A, (TILET)" );
    outline1("LD (%s), A", _result );

}

void zx_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( zxvars, src_hw_zx_vars_asm);
    deploy( tiles, src_hw_zx_tiles_asm );

    outline1("LD A, (%s)", _tileset );

    outline0("CALL USETILESET");

}

Variable * zx_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

#endif