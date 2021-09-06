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

    // TODO: implementation
    
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

    // TODO: implementation
    
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

    // TODO: implementation
    
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

    // TODO: implementation

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

    // TODO: implementation
    
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

    // TODO: implementation
    
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

    // TODO: implementation
    
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

    // TODO: implementation
    

}

/**
 * @brief <i>VIC-II</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_enable_ecm( Environment * _environment ) {

    // TODO: implementation
    

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_disable_ecm( Environment * _environment ) {

    // TODO: implementation
    

}

/**
 * @brief <i>VIC-II</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void c6847_enable_mcm( Environment * _environment ) {

    // TODO: implementation
    

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_disable_mcm( Environment * _environment ) {

    // TODO: implementation
    

}

void c6847_bank_select( Environment * _environment, int _bank ) {

    // TODO: implementation
    

}

int c6847_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    // TODO: implementation
    

}

void c6847_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    // TODO: implementation
    

}

void c6847_bitmap_disable( Environment * _environment ) {

    // TODO: implementation
    

}

void c6847_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    // TODO: implementation
    

}

void c6847_bitmap_at( Environment * _environment, char * _address ) {

    // TODO: implementation
    

}

void c6847_colormap_at( Environment * _environment, char * _address ) {

    // TODO: implementation
    

}

void c6847_textmap_at( Environment * _environment, char * _address ) {

    // TODO: implementation
    

}

void c6847_point_at_int( Environment * _environment, int _x, int _y ) {

    // TODO: implementation
    

}

void c6847_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    // TODO: implementation
    

}

void c6847_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    // TODO: implementation
    

}

void c6847_screen_on( Environment * _environment ) {

    // TODO: implementation
    

}

void c6847_screen_off( Environment * _environment ) {

    // TODO: implementation
    

}

void c6847_screen_rows( Environment * _environment, char * _rows ) {

    // TODO: implementation
    

}

void c6847_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

    // TODO: implementation
    

}

void c6847_sprite_enable( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_disable( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    // TODO: implementation
    

}

void c6847_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_multicolor( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_monocolor( Environment * _environment, char * _sprite ) {

    // TODO: implementation
    

}

void c6847_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

    // TODO: implementation
    

}

void c6847_tiles_at( Environment * _environment, char * _address ) {

    // TODO: implementation
    

}

void c6847_vertical_scroll( Environment * _environment, char * _displacement ) {

    // TODO: implementation
    

}

void c6847_horizontal_scroll( Environment * _environment, char * _displacement ) {

    // TODO: implementation
    

}

void c6847_get_width( Environment * _environment, char *_result ) {

    // TODO: implementation
    

}

void c6847_get_height( Environment * _environment, char *_result ) {

    // TODO: implementation
    

}

void c6847_cls( Environment * _environment ) {

    deploy( clsDeployed, src_hw_6847_cls_asm );

    outline0("JSR CLS");

}

void c6847_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollTextDeployed, src_hw_6847_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void c6847_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

    deploy( c6847varsDeployed, src_hw_6847_vars_asm);
    deploy( vScrollTextDeployed, src_hw_6847_vscroll_text_asm );
    deploy( textEncodedAtDeployed, src_hw_6847_text_at_asm );

    outline1("LDY %s", _text);
    outline0("STY TEXTPTR" );
    outline0("LDY TEXTADDRESS" );
    outline0("STY COPYOFTEXTADDRESS" );
    outline1("LDA %s", _x );
    outline0("STA XCURSYS" );
    outline1("LDA %s", _y );
    outline0("STA YCURSYS" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );
    outline0("LDA #0" );
    outline0("STA TABSTODRAW" );
    outline1("LDA %s", _ww );
    outline0("STA TEXTWW" );
    outline1("LDA %s", _pen );
    outline0("STA TEXTPEN" );
    outline0("LDA _PAPER" );
    outline0("STA TEXTPAPER" );

    outline0("JSR TEXTAT");

    outline0("LDA YCURSYS" );
    outline1("STA %s", _y );
    outline0("LDA XCURSYS");
    outline1("STA %s", _x );

}

void c6847_initialization( Environment * _environment ) {

    deploy( c6847varsDeployed, src_hw_6847_vars_asm );
    deploy( c6847startupDeployed, src_hw_6847_startup_asm );
    // src_hw_chipset_mob_asm = src_hw_c6847_mob_asm;
    // src_hw_chipset_mob_asm_len = src_hw_c6847_mob_asm_len;

    // SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 320, 200, 2, "Standard Bitmap Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 160, 200, 4, "Multicolor Bitmap Mode"  );
    // SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 25, 2, "Standard Character Mode" );
    // SCREEN_MODE_DEFINE( TILEMAP_MODE_MULTICOLOR, 0, 40, 25, 16, "Multicolor Character Mode" );
    // SCREEN_MODE_DEFINE( TILEMAP_MODE_EXTENDED, 0, 40, 25, 20, "Extended Multicolor Character Mode" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_INTERNAL, 0, 32, 16, 2, "Alphanumeric Internal");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_EXTERNAL, 1, 32, 16, 2, "Alphanumeric External");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_SEMIGRAPHICS4, 2, 64, 32, 8, "Semigraphics 4" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_SEMIGRAPHICS6, 3, 64, 48, 4, "Semigraphics 6" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR1, 4, 64, 64, 4, "Color Graphics 1" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION1, 5, 128, 64, 2, "Resolution Graphics 1" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR2, 6, 128, 64, 4, "Color Graphics 2" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION2, 7, 128, 96, 2, "Resolution Graphics 2" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR3, 8, 128, 96, 4, "Color Graphics 3" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION3, 9, 128, 192, 2, "Resolution Graphics 3" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR6, 10, 128, 192, 4, "Color Graphics 6" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION6, 11, 256, 192, 2, "Resolution Graphics 6" );

    outline0("JSR C6847STARTUP");

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

    c6847_cls( _environment );

}

void c6847_hscroll_line( Environment * _environment, int _direction ) {

    // TODO: implementation
    

}

void c6847_hscroll_screen( Environment * _environment, int _direction ) {

    // TODO: implementation
    

}

void c6847_back( Environment * _environment ) {

    // TODO: implementation
    

}

void c6847_cline( Environment * _environment, char * _characters ) {

    deploy( textClineDeployed, src_hw_6847_cline_asm );
    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );

    if ( _characters ) {
        outline1("LDA %s", _characters);
    } else {
        outline0("LDA #0");
    }
    outline0("STA CHARACTERS");
    outline1("LDA %s", x->realName );
    outline0("STA CLINEX" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");
    outline0("JSR CLINE");

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


    // TODO: implementation
    

    return NULL;

}

static Variable * c6847_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {


    // TODO: implementation
    

    return NULL;

}

Variable * c6847_image_converter( Environment * _environment, char * _data, int _width, int _height, int _mode ) {


    // TODO: implementation
    

    CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

}

void c6847_put_image( Environment * _environment, char * _image, char * _x, char * _y ) {


    // TODO: implementation
    

}

#endif