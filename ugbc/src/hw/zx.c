/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
    // { "BLACK", 
        { 0x00, 0x00, 0x00, 0 },        
    // { "BLUE", 
        { 0x00, 0x00, 0xff, 1 },
    // { "RED", 
        { 0x88, 0x00, 0x00, 2 },
    // { "MAGENTA", 
        { 0xff, 0x00, 0xff, 3 },
    // { "GREEN", 
        { 0x00, 0xcc, 0x00, 4 },
    // { "CYAN", 
        { 0xaa, 0xff, 0xe6, 5 },
    // { "YELLOW", 
        { 0xee, 0xee, 0x77, 6 },
    // { "WHITE", 
        { 0xff, 0xff, 0xff, 7 }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __zx__

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

void zx_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char * _paper, char * _ww ) {

    deploy( vars,src_hw_zx_vars_asm);
    deploy( vScroll, src_hw_zx_vscroll_asm );
    deploy( textEncodedAt, src_hw_zx_text_at_asm );

    z80_move_8bit( _environment, _x, "XCURS");
    z80_move_8bit( _environment, _y, "YCURS");
    z80_move_8bit( _environment, _pen, "_PEN");
    z80_move_8bit( _environment, _paper, "_PAPER");
    z80_move_8bit( _environment, _ww, "LOCALWW");
    // z80_move_8bit( _environment, _tab, "TABCOUNT");

    outline1("LD A, (%s)", _text_size );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline1("LD HL, (%s)", _text );
    outline0("CALL TEXTAT");

    z80_move_8bit( _environment, "XCURS", _x );
    z80_move_8bit( _environment, "YCURS", _y );

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

    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed );
    outline1("LD (%s), A", _key );
    outline0("LD A, ($5C08)");
    outline0("CP 13");
    outline1("JR Z, %snokey", label );
    outline1("LD (%s), a", _key );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outline0("LD A, 13");
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

void zx_initialization( Environment * _environment ) {

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE );
    variable_global( _environment, "CURRENTTILESHEIGHT" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 192, 256, 2, "Standard Bitmap Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 32, 25, 8, "(emulated) Standard Character Mode" );

    variable_import( _environment, "XGR", VT_POSITION );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD );
    variable_global( _environment, "LINE" );

    variable_import( _environment, "CLIPX1", VT_POSITION );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION );
    variable_global( _environment, "CLIPY2" );

}

void zx_finalization( Environment * _environment ) {

}

int zx_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    _environment->screenWidth = 256;
    _environment->screenHeight = 192;
    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
}

void zx_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    deploy( vars, src_hw_zx_vars_asm );

}

void zx_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
}

void zx_back( Environment * _environment ) {

    deploy( back, src_hw_zx_back_asm );

    outline0("CALL BACK");

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


/**
 * @brief Calculate the distance between two colors
 *
 * This function calculates the color distance between two colors(_a and _b).
 * By "distance" we mean the geometric distance between two points in a 
 * three-dimensional space, where each dimension corresponds to one of the 
 * components (red, green and blue). The returned value is normalized to 
 * the nearest 8-bit value. 
 * 
 * @param _a First color 
 * @param _b Second color
 * @return int distance
 */

static int calculate_distance(RGBi e1, RGBi e2) {

    long rmean = ( (long)e1.red + (long)e2.red ) / 2;
    long r = (long)e1.red - (long)e2.red;
    long g = (long)e1.green - (long)e2.green;
    long b = (long)e1.blue - (long)e2.blue;
    return (int)( sqrt((((512+rmean)*r*r)>>8) + 4*g*g + (((767-rmean)*b*b)>>8)) );

}

/**
 * @brief Extract the color palette from the given image
 * 
 * @param _source 
 * @param _palette 
 * @param _palette_size 
 * @return int 
 */
static int extract_color_palette(unsigned char* _source, int _width, int _height, RGBi _palette[], int _palette_size) {

    RGBi rgb;

    int image_x, image_y;

    int usedPalette = 0;
    int i = 0;
    unsigned char* source = _source;

    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            for (i = 0; i < usedPalette; ++i) {
                if (_palette[i].red == rgb.red && _palette[i].green == rgb.green && _palette[i].blue == rgb.blue) {
                    break;
                }
            }

            if (i >= usedPalette) {
                _palette[usedPalette].red = rgb.red;
                _palette[usedPalette].green = rgb.green;
                _palette[usedPalette].blue = rgb.blue;
                ++usedPalette;
                if (usedPalette > _palette_size) {
                    break;
                }
            }
            source += 3;
        }
        if (usedPalette > _palette_size) {
            break;
        }
    }

    return usedPalette;

}

static Variable * zx_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = extract_color_palette(_source, _width, _height, palette, MAX_PALETTE);

    if (colorUsed > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = calculate_distance(SYSTEM_PALETTE[j], palette[i]);
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
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
 
    int bufferSize = 2 + ( ( _frame_width >> 3 ) * _frame_height ) + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) );
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

    *(buffer) = _frame_width;
    *(buffer+1) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            for( i=0; i<colorUsed; ++i ) {
                if ( palette[i].red == rgb.red && palette[i].green == rgb.green && palette[i].blue == rgb.blue ) {
                    break;
                }
            }

            // printf("%d", i );

            // Calculate the relative tile
            tile_y = (image_y >> 3);
            tile_x = (image_x >> 3);
            
            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (tile_y * 8 *( _frame_width >> 3 ) ) + (tile_x * 8) + (image_y & 0x07);
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            // If the pixes has enough luminance value, it must be 
            // considered as "on"; otherwise, it is "off".
            // int luminance = calculate_luminance(rgb);

            if ( i == 1 ) {
                *( buffer + offset + 2) |= bitmask;
            } else {
                *( buffer + offset + 2) &= ~bitmask;
            }

            offset = tile_y * ( _frame_width >> 3 ) + tile_x;
            *( buffer + 2 + ( ( _frame_width >> 3 ) * _height ) + offset ) = ( palette[1].index << 3 ) | ( palette[0].index ); 

            _source += 3;

        }

        _source += 3 * ( _width - _frame_width );

        // printf("\n" );

    }

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

Variable * zx_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode ) {

    switch( _mode ) {

        case BITMAP_MODE_STANDARD:
        case TILEMAP_MODE_STANDARD:

            return zx_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height );

            break;
    }

    CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

}

void zx_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _frame_size ) {

    deploy( vars, src_hw_zx_vars_asm);
    deploy( image, src_hw_zx_image_asm );

    outline1("LD HL, (%s)", _image );
    if ( _frame ) {
        outline0("INC HL" );
        outline0("INC HL" );
        if ( strlen(_frame) == 0 ) {

        } else {

            outline1("LD DE, OFFSETS%4.4x", _frame_size );
            outline1("LD A, (%s)", _frame );
            outline0("CMP 0" );
            outline1("JR Z, %sdone", label );
            outhead1("%sloop", label );
            outline0("INC DE" );
            outline0("DEC B" );
            outline0("CMP 0" );
            outline1("JR NZ, %sloop", label );
            outline0("ADD HL, DE" );
        }

    }
    outline1("LD A, (%s)", _x );
    outline0("LD (IMAGEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (IMAGEY), A" );

    outline0("CALL PUTIMAGE");

}

#endif