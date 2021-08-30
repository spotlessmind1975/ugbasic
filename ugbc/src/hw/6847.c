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

#ifdef __d32__

#include "../ugbc.h"
#include "6809.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    // { "BLACK", 
        { 0x00, 0x00, 0x00, 0 },        
    // { "GREEN", 
        { 0x00, 0xcc, 0x55, 1 },
    // { "YELLOW", 
        { 0xee, 0xee, 0x77, 2 },
    // { "BLUE", 
        { 0x00, 0x00, 0xaa, 3 },
    // { "RED", 
        { 0x88, 0x00, 0x00, 4 },
    // { "BUFF", 
        { 0xf0, 0xf0, 0xf0, 5 },
    // { "CYAN", 
        { 0xaa, 0xff, 0xe6, 6 },
    // { "MAGENTA", <- 
        { 0xcc, 0x44, 0xcc, 7 },
    // { "ORANGE", 
        { 0xa1, 0x68, 0x3c, 8 }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief <i>VIC-II</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void c6847_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void c6847_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void c6847_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void c6847_background_color( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void c6847_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to set raster irq
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
void c6847_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void c6847_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to wait for next raster irq at different position
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
void c6847_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void c6847_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_disable_mcm( Environment * _environment ) {

}

void c6847_bank_select( Environment * _environment, int _bank ) {

}

int c6847_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

}

void c6847_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void c6847_bitmap_disable( Environment * _environment ) {

}

void c6847_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void c6847_bitmap_at( Environment * _environment, char * _address ) {

}

void c6847_colormap_at( Environment * _environment, char * _address ) {

}

void c6847_textmap_at( Environment * _environment, char * _address ) {

}

void c6847_point_at_int( Environment * _environment, int _x, int _y ) {

}

void c6847_point_at_vars( Environment * _environment, char *_x, char *_y ) {

}

void c6847_point( Environment * _environment, char *_x, char *_y, char * _result ) {

}

void c6847_screen_on( Environment * _environment ) {

}

void c6847_screen_off( Environment * _environment ) {

}

void c6847_screen_rows( Environment * _environment, char * _rows ) {

}

void c6847_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void c6847_sprite_enable( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_disable( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void c6847_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void c6847_tiles_at( Environment * _environment, char * _address ) {

}

void c6847_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void c6847_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void c6847_busy_wait( Environment * _environment, char * _timing ) {

}

void c6847_get_width( Environment * _environment, char *_result ) {

}

void c6847_get_height( Environment * _environment, char *_result ) {

}

void c6847_cls( Environment * _environment ) {

}

void c6847_scroll_text( Environment * _environment, int _direction ) {

}

void c6847_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

}

void c6847_initialization( Environment * _environment ) {

}

void c6847_hscroll_line( Environment * _environment, int _direction ) {

}

void c6847_hscroll_screen( Environment * _environment, int _direction ) {

}

void c6847_back( Environment * _environment ) {

}

void c6847_cline( Environment * _environment, char * _characters ) {

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

static Variable * c6847_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

    return NULL;

}

static Variable * c6847_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

    return NULL;

}

Variable * c6847_image_converter( Environment * _environment, char * _data, int _width, int _height, int _mode ) {

    CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

}

void c6847_put_image( Environment * _environment, char * _image, char * _x, char * _y ) {

}

#endif