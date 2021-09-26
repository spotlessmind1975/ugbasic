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

#ifdef __d64__

void d64_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void d64_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void d64_color_border( Environment * _environment, char * _color ) {

}

void d64_vscroll( Environment * _environment, int _displacement ) {

}

void d64_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char * _paper, char * _ww ) {

}

void d64_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void d64_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    d64_scancode( _environment, _pressed, _key );

    outline1("LDA %s", _pressed );
    outline0("CMPA #0" );
    outline1("BEQ %sskip", label );
    outline1("LDA %s", _key );
    outline0("ANDA #$80" );
    outline0("CMPA #0" );
    outline1("BNE %snoascii", label );
    outline1("LDA %s", _key );
    outline0("CMPA $011d" );
    outline1("BNE %sdifferent", label );
    outline0("INC $011f" );
    outline0("LDB $011f" );
    outline0("CMPB #$7f" );
    outline1("BEQ %sascii", label );
    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("JMP %sskip", label );
    outhead1("%snoascii", label );
    outline0("LDA #0" );
    outline1("STA %s", _key );
    outline1("JMP %sskip", label );
    outhead1("%sdifferent", label );
    outline0("STA $011d" );
    outhead1("%sascii", label );
    outline0("LDB #0" );
    outline0("STB $011f" );
    outhead1("%sskip", label );

}

void d64_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_d64_scancode_asm );

    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("STA %s", _scancode );

    outline0("JSR SCANCODE" );
    outline0("CMPA #0" );
    outline1("BEQ %snokey", label );
    outline1("STA %s", _scancode );
    outline0("LDA #$FF" );
    outline1("STA %s", _pressed );
    outhead1("%snokey", label );

}

void d64_scanshift( Environment * _environment, char * _shifts ) {

    d64_keyshift( _environment, _shifts );
    
}

void d64_keyshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(pressed)" );
    Variable * scancode = variable_temporary( _environment, VT_BYTE, "(scancode)" );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    
    d64_scancode( _environment, pressed->realName, scancode->realName );

    outline1("LDA %s", result->realName );
    outline1("CMPA #$%2.2x", (unsigned char) KEY_SHIFT);
    outline0("BEQ %sshift");
    outline0("LDA #0");
    outline1("STA %s", _shifts);
    outline1("JMP %sdone", label );
    outhead1("%sshift", label);
    outline0("LDA #3");
    outline1("STA %s", _shifts);
    outline1("JMP %sdone", label );
    outhead1("%sdone", label );


}

void d64_clear_key( Environment * _environment ) {

    outline0("LDA #$0");
    outline0("LDX $35");
    outline0("STA ,X");

    outline0("LDA #$0");
    outline0("sta $87");

}

void d64_initialization( Environment * _environment ) {

}

int d64_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void d64_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void d64_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
}

void d64_back( Environment * _environment ) {

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

static Variable * d64_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

    if ( _width % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( _width );
    }

    if ( _height % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_HEIGHT( _height );
    }

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
 
    int bufferSize = 2 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height >> 3 ) );
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

    *(buffer) = _width;
    *(buffer+1) = _height;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {

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
            offset = (tile_y * 8 *( _width >> 3 ) ) + (tile_x * 8) + (image_y & 0x07);
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            // If the pixes has enough luminance value, it must be 
            // considered as "on"; otherwise, it is "off".
            // int luminance = calculate_luminance(rgb);

            if ( i == 1 ) {
                *( buffer + offset + 2) |= bitmask;
            } else {
                *( buffer + offset + 2) &= ~bitmask;
            }

            offset = tile_y * ( _width >> 3 ) + tile_x;
            *( buffer + 2 + ( ( _width >> 3 ) * _height ) + offset ) = ( palette[1].index << 3 ) | ( palette[0].index ); 

            _source += 3;

        }

        // printf("\n" );

    }

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

Variable * d64_image_converter( Environment * _environment, char * _data, int _width, int _height, int _mode ) {

}

void d64_put_image( Environment * _environment, char * _image, char * _x, char * _y ) {

}

void d64_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX $0112");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    outline0("CMPX $0112");
    outline1("BGT %sfirst", label);
}

void d64_irq_at( Environment * _environment, char * _label ) {

    Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline0("LDA #$7e" );
    outline0("STA $010c" );
    outline0("LDX $010d" );
    outline1("STX %s", irq->realName );
    outline1("LDX #%s", _label );
    outline0("STX $010d" );
    
}

void d64_follow_irq( Environment * _environment ) {

    Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline1("LDX %s", irq->realName );
    outline0("PSHS X" );
    outline0("RTS" );
    
}
#endif