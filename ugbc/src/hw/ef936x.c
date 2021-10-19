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

#if defined(__pc128op__)

#include "../ugbc.h"
#include "6809.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    // { "BLACK", 
        { 0x00, 0x00, 0x00, 0 },        
    // { "WHITE", 
        { 0xff, 0xff, 0xff, 1 },
    // { "RED", 
        { 0x88, 0x00, 0x00, 2 },
    // { "CYAN", 
        { 0xaa, 0xff, 0xe6, 3 },
    // { "VIOLET", 
        { 0xcc, 0x44, 0xcc, 4 },
    // { "GREEN", 
        { 0x00, 0xcc, 0x55, 5 },
    // { "BLUE", 
        { 0x00, 0x00, 0xaa, 6 },
    // { "YELLOW", 
        { 0xee, 0xee, 0x77, 7 },
    // { "ORANGE", 
        { 0xa1, 0x68, 0x3c, 8 },
    // { "BROWN", 
        { 0xdd, 0x88, 0x65, 9 },
    // { "LIGHT_RED", 
        { 0xff, 0x77, 0x77, 10 },
    // { "DARK_GREY", 
        { 0x33, 0x33, 0x33, 11 },
    // { "GREY", 
        { 0x77, 0x77, 0x77, 12 },
    // { "LIGHT_GREEN", 
        { 0xaa, 0xff, 0x66, 13 },
    // { "LIGHT_BLUE", 
        { 0x00, 0x88, 0xff, 14 },
    // { "LIGHT_GREY", 
        { 0xbb, 0xbb, 0xbb, 15 }
};

static RGBi * commonPalette;

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
void ef936x_collision( Environment * _environment, char * _sprite_mask, char * _result ) {
    
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
void ef936x_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

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
void ef936x_border_color( Environment * _environment, char * _border_color ) {

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
void ef936x_background_color( Environment * _environment, char * _index, char * _background_color ) {

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
void ef936x_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

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
void ef936x_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

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
void ef936x_next_raster( Environment * _environment ) {

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
void ef936x_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void ef936x_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void ef936x_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void ef936x_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void ef936x_disable_mcm( Environment * _environment ) {

}

void ef936x_bank_select( Environment * _environment, int _bank ) {

}

int ef936x_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    deploy( ef936xvars, src_hw_ef936x_vars_asm );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    switch( _screen_mode->id ) {
        case BITMAP_MODE_40_COLUMN:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            outline0("LDA #%00000000");
            outline0("STA $A7DC");
            break;
        case BITMAP_MODE_80_COLUMN:
            _environment->screenWidth = 640;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            outline0("LDA #%00101010");
            outline0("STA $A7DC");
            break;
        case BITMAP_MODE_BITMAP_4:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            outline0("LDA #%00100001");
            outline0("STA $A7DC");
            break;
        case BITMAP_MODE_BITMAP_16:
            _environment->screenWidth = 160;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            outline0("LDA #%01111011");
            outline0("STA $A7DC");
            break;
        case BITMAP_MODE_PAGE:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            outline0("LDA #%00100100");
            outline0("STA $A7DC");
            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", _environment->screenWidth-1 );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", _environment->screenHeight-1 );
    cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 40*200 );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

}

void ef936x_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    if ( mode ) {
        ef936x_screen_mode_enable( _environment, mode );
        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        _environment->currentMode = mode->id;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void ef936x_bitmap_disable( Environment * _environment ) {    

}

void ef936x_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    if ( mode ) {
        ef936x_screen_mode_enable( _environment, mode );
        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        _environment->currentMode = mode->id;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void ef936x_bitmap_at( Environment * _environment, char * _address ) {

}

void ef936x_colormap_at( Environment * _environment, char * _address ) {    

}

void ef936x_textmap_at( Environment * _environment, char * _address ) {  

}

void ef936x_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( plot, src_hw_ef936x_plot_asm );
    
    outline1("LDX %4.4x", (_x & 0xffff ) );
    outline0("STX <PLOTX");
    outline1("LDD %4.4x", ( _y & 0xffff ) );
    outline0("STD <PLOTY");
    outline0("LDA #1");
    outline0("STA <PLOTM");
    outline0("JSR PLOT");
    

}

void ef936x_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( plot, src_hw_ef936x_plot_asm );
    
    outline1("LDX %s", x->realName );
    outline0("STX <PLOTX");
    outline1("LDD %s", y->realName );
    outline0("STD <PLOTY");
    outline0("LDA #1");
    outline0("STA <PLOTM");
    outline0("JSR PLOT");

}

void ef936x_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * result = variable_retrieve_or_define( _environment, _result, VT_BYTE, 0 );

    deploy( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( plot, src_hw_ef936x_plot_asm );
    
    outline1("LDD %s", x->realName );
    outline0("STD <PLOTX");
    outline1("LDD %s", y->realName );
    outline0("STD <PLOTY");
    outline0("LDA #3");
    outline0("STA <PLOTM");
    outline0("JSR PLOT");
    outline0("LDA <PLOTM");
    outline1("STA %s", result->realName );    

}

void ef936x_screen_on( Environment * _environment ) {

}

void ef936x_screen_off( Environment * _environment ) {

}

void ef936x_screen_rows( Environment * _environment, char * _rows ) {

}

void ef936x_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void ef936x_sprite_enable( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_disable( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void ef936x_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void ef936x_tiles_at( Environment * _environment, char * _address ) {

}

void ef936x_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void ef936x_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void ef936x_get_width( Environment * _environment, char *_result ) {

    outline0("LDX CURRENTWIDTH" );
    outline1("STX %s", _result );

}

void ef936x_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESWIDTH" );
    outline1("STA %s", _result );

}

void ef936x_get_height( Environment * _environment, char *_result ) {

    outline0("LDX CURRENTHEIGHT" );
    outline1("STX %s", _result );

}

void ef936x_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESHEIGHT" );
    outline1("STA %s", _result );

}

void ef936x_cls( Environment * _environment ) {

    deploy( cls, src_hw_ef936x_cls_asm );

    outline0("JSR CLS");

}

void ef936x_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollText, src_hw_ef936x_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA <DIRECTION" );

    outline0("JSR VSCROLLT");

}

void ef936x_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

    deploy( ef936xvars, src_hw_ef936x_vars_asm);
    deploy( vScrollText, src_hw_ef936x_vscroll_text_asm );
    deploy( textEncodedAt, src_hw_ef936x_text_at_asm );

    outline1("LDY %s", _text);
    outline0("STY <TEXTPTR" );
    outline1("LDA %s", _x );
    outline0("STA <XCURSYS" );
    outline1("LDA %s", _y );
    outline0("STA <YCURSYS" );
    outline1("LDA %s", _text_size);
    outline0("STA <TEXTSIZE" );
    outline1("LDA %s", _ww );
    outline0("STA <TEXTWW" );
    outline1("LDA %s", _pen );
    outline0("STA <TEXTPEN" );

    outline0("JSR TEXTAT");

    outline0("LDA <YCURSYS" );
    outline1("STA %s", _y );
    outline0("LDA <XCURSYS");
    outline1("STA %s", _x );

}

void ef936x_initialization( Environment * _environment ) {

    deploy( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( ef936xstartup, src_hw_ef936x_startup_asm );
    // src_hw_chipset_mob_asm = src_hw_ef936x_mob_asm;
    // src_hw_chipset_mob_asm_len = src_hw_ef936x_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE );
    variable_global( _environment, "CURRENTTILESHEIGHT" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_40_COLUMN, 1, 320, 200, 4, "BITMAP MODE 40 COLUMN" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_80_COLUMN, 1, 640, 200, 2, "BITMAP MODE 80 COLUMN" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_BITMAP_4, 1, 320, 200, 4, "BITMAP MODE BITMAP 4" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_BITMAP_16, 1, 160, 200, 16, "BITMAP MODE BITMAP 16" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_PAGE, 1, 320, 200, 4, "BITMAP MODE PAGE" );

    outline0("JSR EF936XSTARTUP");

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

    ef936x_cls( _environment );

}

void ef936x_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_ef936x_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA <DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA <CLINEY");

    outline0("JSR HSCROLLLT");    

}

void ef936x_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_ef936x_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA <DIRECTION" );

    outline0("JSR HSCROLLST");    

}

void ef936x_back( Environment * _environment ) {

}

void ef936x_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_ef936x_cline_asm );
    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );

    if ( _characters ) {
        outline1("LDA %s", _characters);
    } else {
        outline0("LDA #0");
    }
    outline0("STA <CHARACTERS");
    outline1("LDA %s", x->realName );
    outline0("STA <CLINEX" );
    outline1("LDA %s", y->realName );
    outline0("STA <CLINEY");
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

static Variable * ef936x_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

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
 
    int bufferSize = 2 + ( ( _width >> 3 ) * _height );
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

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = ( image_y * ( _width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            // If the pixes has enough luminance value, it must be 
            // considered as "on"; otherwise, it is "off".
            // int luminance = calculate_luminance(rgb);

            if ( i == 1 ) {
                *( buffer + offset + 2) |= bitmask;
                // printf("*");
            } else {
                *( buffer + offset + 2) &= ~bitmask;
                // printf(" ");
            }

            _source += 3;

        }

        // printf("\n" );

    }

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

static Variable * ef936x_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

    if ( _width % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( _width );
    }

    if ( _height % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_HEIGHT( _height );
    }

    if ( ! commonPalette ) {

        int colorUsed;

        RGBi * palette = malloc( sizeof(SYSTEM_PALETTE) );

        colorUsed = extract_color_palette(_source, _width, _height, palette, MAX_PALETTE);

        if (colorUsed > 16) {
            CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        }

        int i, j, k;

        for( i=0; i<colorUsed; ++i ) {
            int minDistance = 0xffff;
            int colorIndex = 0;
            for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
                int distance = calculate_distance(SYSTEM_PALETTE[j], palette[i]);
                // printf("%d (%2.2x%2.2x%2.2x) <-> %d (%2.2x%2.2x%2.2x) [%d] = %d [min = %d]\n", i, SYSTEM_PALETTE[j].red, SYSTEM_PALETTE[j].green, SYSTEM_PALETTE[j].blue, j, palette[i].red, palette[i].green, palette[i].blue, SYSTEM_PALETTE[j].index, distance, minDistance );
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
            // printf("%d) %d * %d %2.2x%2.2x%2.2x\n", i, colorIndex, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
        }

        commonPalette = palette;

    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
 
    int bufferSize = 2 + 2 * ( ( _width >> 3 ) * _height );
    
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

    *(buffer) = _width;
    *(buffer+1) = _height;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            int colorIndex = 0;

            int minDistance = 9999;
            for( int i=0; i<sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++i ) {
                int distance = calculate_distance(commonPalette[i], rgb );
                if ( distance < minDistance ) {
                    minDistance = distance;
                    colorIndex = i;
                }
            }

            offset = ( image_y * ( _width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            // If the pixes has enough luminance value, it must be 
            // considered as "on"; otherwise, it is "off".
            // int luminance = calculate_luminance(rgb);

            if ( colorIndex ) {
                *( buffer + offset + 2) |= bitmask;
                // printf("*");
            } else {
                *( buffer + offset + 2) &= ~bitmask;
                // printf(" ");
            }

            offset = ( image_y * ( _width >> 3 ) ) + ( image_x >> 3 );

            // printf( "%1.1x", colorIndex );

            bitmask = colorIndex << 4;

            *(buffer + 2 + ( ( _width >> 3 ) * _height ) + offset) |= bitmask;

            _source += 3;

        }

        // printf("\n" );
    }

    // for(i=0; i<4; ++i ) {
    //     printf( "%1.1x = %2.2x\n", i, palette[i].index );
    // }

    // printf("\n" );
    // printf("\n" );

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * ef936x_image_converter( Environment * _environment, char * _data, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case BITMAP_MODE_40_COLUMN:
            return ef936x_image_converter_multicolor_mode_standard( _environment, _data, _width, _height );
        case BITMAP_MODE_80_COLUMN:
        case BITMAP_MODE_BITMAP_4:
        case BITMAP_MODE_BITMAP_16:
        case BITMAP_MODE_PAGE:
            CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );
            break;
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    
    return result;

}

void ef936x_put_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    deploy( ef936xvars, src_hw_ef936x_vars_asm);
    deploy( image, src_hw_ef936x_image_asm );

    outline1("LDY #%s", _image );
    outline1("LDD %s", _x );
    outline0("STD <IMAGEX" );
    outline1("LDD %s", _y );
    outline0("STD <IMAGEY" );

    outline0("JSR PUTIMAGE");
    
}

#endif