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

#ifdef __vic20__

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    { 0x00, 0x00, 0x00, 0, "BLACK" },
    { 0xff, 0xff, 0xff, 1, "WHITE" },
    { 0x88, 0x00, 0x00, 2, "RED" },
    { 0xaa, 0xff, 0xe6, 3, "CYAN" },
    { 0xcc, 0x44, 0xcc, 4, "VIOLET" },
    { 0x00, 0xcc, 0x55, 5, "GREEN" },
    { 0x00, 0x00, 0xaa, 6, "BLUE" },
    { 0xee, 0xee, 0x77, 7, "YELLOW" },
    { 0xa1, 0x68, 0x3c, 8, "ORANGE" },
    { 0xdd, 0x88, 0x65, 9, "BROWN" },
    { 0xff, 0x77, 0x77, 10, "LIGHT_RED" },
    { 0x33, 0x33, 0x33, 11, "DARK_GREY" },
    { 0x77, 0x77, 0x77, 12, "GREY" },
    { 0xaa, 0xff, 0x66, 13, "LIGHT GREEN" },
    { 0x00, 0x88, 0xff, 14, "LIGHT BLUE" },
    { 0xbb, 0xbb, 0xbb, 15, "LIGHT GREY" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief <i>VIC</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void vic1_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void vic1_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void vic1_border_color( Environment * _environment, char * _border_color ) {

    outline1("LDA %s", _border_color );
    outline0("AND #$07" );
    outline0("STA $900F");

}

/**
 * @brief <i>VIC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color( Environment * _environment, int _index, int _background_color ) {
 
    outline1("LDA #$%2.2x", ( _background_color >> 4 ) );
    outline0("STA MATHPTR0");
    outline0("LDA $900F");
    outline0("AND #$0F");
    outline0("ORA MATHPTR0");
    outline0("STA $900F");
}

/**
 * @brief <i>VIC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _background_color );
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("STA MATHPTR0");
    outline0("LDA $900F");
    outline0("AND #$0F");
    outline0("ORA MATHPTR0");
    outline0("STA $900F");
}

/**
 * @brief <i>VIC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {
 
    outline1("LDA %s", _background_color );
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("STA MATHPTR0");
    outline0("LDA $900F");
    outline0("AND #$0F");
    outline0("ORA MATHPTR0");
    outline0("STA $900F");
}

/**
 * @brief <i>VIC</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline0("LDA $900F");
    outline0("AND #$F0");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline1("STA %s", _background_color );

}


/**
 * @brief <i>VIC</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void vic1_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {
 
}

/**
 * @brief <i>VIC</i>: emit code to set raster irq
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
void vic1_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void vic1_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>VIC</i>: emit code to wait for next raster irq at different position
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
void vic1_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void vic1_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vic1_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void vic1_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VIC</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vic1_disable_mcm( Environment * _environment ) {

}

void vic1_bank_select( Environment * _environment, int _bank ) {
    
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

int vic1_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    // deploy( bitmap, src_hw_vic1_bitmap_asm );
    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTiles = 255;
    switch( _screen_mode->id ) {
        // case BITMAP_MODE_STANDARD:
        //     _environment->screenTilesWidth = 16;
        //     _environment->screenTilesHeight = 16;

        //     outline0("JSR BITMAPON1" );

        //     cpu_store_8bit( _environment, "_PEN", 0X01 );
        //     cpu_store_8bit( _environment, "_PAPER", 0x00 );
        //     cpu_store_16bit( _environment, "CLIPX1", 0 );
        //     cpu_store_16bit( _environment, "CLIPX2", (_environment->screenTilesWidth*8)-1 );
        //     cpu_store_16bit( _environment, "CLIPY1", 0 );
        //     cpu_store_16bit( _environment, "CLIPY2", (_environment->screenTilesHeight*8)-1 );

        //     break;
        // case BITMAP_MODE_EXTENDED:
        //     _environment->screenTilesWidth = 22;
        //     _environment->screenTilesHeight = 22;

        //     outline0("JSR BITMAPON2" );

        //     cpu_store_8bit( _environment, "_PEN", 0X01 );
        //     cpu_store_8bit( _environment, "_PAPER", 0x00 );
        //     cpu_store_16bit( _environment, "CLIPX1", 0 );
        //     cpu_store_16bit( _environment, "CLIPX2", (_environment->screenTilesWidth*8)-1 );
        //     cpu_store_16bit( _environment, "CLIPY1", 0 );
        //     cpu_store_16bit( _environment, "CLIPY2", (_environment->screenTilesHeight*8)-1 );

        //     break;
        case TILEMAP_MODE_STANDARD:
            _environment->screenTilesWidth = 22;
            _environment->screenTilesHeight = 23;

            // outline0("JSR BITMAPOFF" );

            vic1_cls( _environment );

            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    _environment->screenWidth = _environment->screenTilesWidth * 8;
    _environment->screenHeight = _environment->screenTilesHeight * 8;
    _environment->screenColors = 2;
    _environment->screenShades = 8;

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

}

void vic1_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    if ( mode ) {
        vic1_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        
        _environment->currentMode = mode->id;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void vic1_bitmap_disable( Environment * _environment ) {

}

void vic1_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    if ( mode ) {
        vic1_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
    } else {
        WARNING_SCREEN_MODE( -1 );
    }


}

void vic1_bitmap_at( Environment * _environment, char * _address ) {

}

void vic1_colormap_at( Environment * _environment, char * _address ) {

}

void vic1_textmap_at( Environment * _environment, char * _address ) {

}

void vic1_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( plot, src_hw_vic1_plot_asm );
    
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

void vic1_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( plot, src_hw_vic1_plot_asm );
    
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

void vic1_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( plot, src_hw_vic1_plot_asm );
    
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

void vic1_screen_on( Environment * _environment ) {

}

void vic1_screen_off( Environment * _environment ) {

}

void vic1_screen_rows( Environment * _environment, char * _rows ) {

}

void vic1_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void vic1_sprite_enable( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_disable( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void vic1_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void vic1_tiles_at( Environment * _environment, char * _address ) {

}

void vic1_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void vic1_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void vic1_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline0("LDA #$00");
    outline0("STA TMPPTR");
    outhead1("%sfirst:", label );
    outline0("LDA #$01");
    outhead1("%ssecond:", label );
    outline0("CMP $9004");
    outline1("BNE %ssecond", label);
    outhead1("%sthird:", label );
    outline0("CMP $9004");
    outline1("BEQ %sthird", label);
    outline0("INC TMPPTR");
    outline0("LDA TMPPTR");
    outline1("CMP %s", _timing );
    outline1("BNE %sfirst", label );

}

void vic1_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTWIDTH" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTWIDTH+1" );
    outline1("STA %s+1", _result );

}

void vic1_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILES" );
    outline1("STA %s", _result );

}

void vic1_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESWIDTH" );
    outline1("STA %s", _result );

}

void vic1_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTHEIGHT" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTHEIGHT+1" );
    outline1("STA %s+1", _result );

}

void vic1_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESHEIGHT" );
    outline1("STA %s", _result );

}

void vic1_cls( Environment * _environment ) {
    
    deploy( cls, src_hw_vic1_cls_asm );

    outline0("JSR CLS");

}

void vic1_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollText, src_hw_vic1_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void vic1_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( vScrollText, src_hw_vic1_vscroll_text_asm );
    deploy( cls, src_hw_vic1_cls_asm );
    deploy( textEncodedAt, src_hw_vic1_text_at_asm );

    outline1("LDA %s", _text);
    outline0("STA TEXTPTR" );
    outline1("LDA %s+1", _text);
    outline0("STA TEXTPTR+1" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );

    outline0("JSR TEXTAT");

}

void vic1_initialization( Environment * _environment ) {

    deploy( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );
    src_hw_chipset_mob_asm = src_hw_vic1_mob_asm;
    src_hw_chipset_mob_asm_len = src_hw_vic1_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 166 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 184  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 22 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 23 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 25, 2, "Standard Character Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 128, 64, 8, "Standard Bitmap Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_EXTENDED, 1, 128, 128, 8, "Extended Bitmap Mode" );

    outline0("JSR VIC1STARTUP");

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
    variable_import( _environment, "CLIPX2", VT_POSITION, 165 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 183 );
    variable_global( _environment, "CLIPY2" );

    vic1_cls( _environment );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 22;
    _environment->screenTilesHeight = 23;
    _environment->screenWidth = _environment->screenTilesWidth * 8;
    _environment->screenHeight = _environment->screenTilesHeight * 8;
    _environment->screenColors = 16;
    _environment->descriptors = precalculate_tile_descriptors_for_font( data_fontvic1_bin );
    
    _environment->descriptors->first = 128;
    _environment->descriptors->firstFree  = _environment->descriptors->first;
    _environment->descriptors->lastFree = 255;
    _environment->descriptors->count = 128;

    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 8;

}

void vic1_finalization( Environment * _environment ) {

}

void vic1_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_vic1_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void vic1_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_vic1_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");
}

void vic1_back( Environment * _environment ) {

    deploy( back, src_hw_vic1_back_asm );

    outline0("JSR BACK");

}

void vic1_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_vic1_cline_asm );
    Variable * x = variable_retrieve( _environment, "XCURSYS" );
    Variable * y = variable_retrieve( _environment, "YCURSYS" );

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

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

   switch( _mode ) {

        case BITMAP_MODE_STANDARD:
            return ( _width >> 3 ) * ( _height );
            break;
        case TILEMAP_MODE_STANDARD:
            break;
    }

    return 0;

}

static Variable * vic1_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE);

    if (colorUsed > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

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
                if ( rgbi_equals_rgb( &palette[i], &rgb ) ) {
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
            *( buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) + offset ) = ( palette[1].index << 4 ) | palette[0].index; 

            _source += 3;

        }

        _source += 3 * ( _width - _frame_width );

        // printf("\n" );

    }

    // printf("\n----\n\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

static Variable * vic1_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE);

    if (colorUsed > 4) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

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

    int bufferSize = 2 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 * ( ( _frame_width >> 2 ) * ( _frame_height >> 3 ) ) + 1;
    
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

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    // Loop for all the source surface.
    for (image_y = _offset_y; image_y < _height; ++image_y) {
        for (image_x = _offset_x; image_x < _width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            // Calculate the relative tile
            tile_y = (image_y >> 3);
            tile_x = (image_x >> 2);

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (tile_y * 8 *( _frame_width >> 2 ) ) + (tile_x * 8) + (image_y & 0x07);
            offsetc = (tile_y * ( _frame_width >> 2 ) ) + (tile_x);

            int minDistance = 0xffff;
            int colorIndex = 0;

            for( i=0; i<colorUsed; ++i ) {
                if ( rgbi_equals_rgb( &palette[i], &rgb ) ) {
                    break;
                }
            }

            colorIndex = i;

            // printf( "%1.1x", colorIndex );

            bitmask = colorIndex << (6 - ((image_x & 0x3) * 2));

            switch( colorIndex ) {
                case 0:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 * ( _frame_width >> 2 ) * ( _frame_height >> 3 ) ) = palette[colorIndex].index;
                    break;
                case 1:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) &= 0x0f;
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) |= ( palette[colorIndex].index << 4 );
                    break;
                case 2:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) &= 0xf0;
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) |= palette[colorIndex].index;
                    break;
                case 3:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + ( _frame_width >> 2 ) * ( _frame_height >> 3 ) + offsetc ) = palette[colorIndex].index;
                    break;

            }

            *(buffer + 2 + offset) |= bitmask;

            _source += 3;

        }

        _source += ( _width - _frame_width ) * 3;

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

static Variable * vic1_image_converter_tilemap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE);

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
    
    int bufferSize;
    
    if ( colorUsed == 2 ) {
        bufferSize = 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) + 1;
    } else {
        bufferSize = 3 + 2* ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) );
    } 

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

    if ( colorUsed > 2 ) {
        *(buffer+2) = 1;
    } else {
        *(buffer+2) = 0;
    }

    int cx=0,cy=0;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    // commonTileDescriptors = precalculate_tile_descriptors_for_font( data_fontvic1_bin );

    for( cy=0; cy<(_frame_height >> 3);++cy) {
        for( cx=0; cx<(_frame_width >> 3);++cx) {

            char *source = _source + ( ( cy * 8 * _width ) + cx * 8 ) * 3;

            TileData tileData;
            memset(&tileData,0,sizeof(TileData));

            int mostFrequentColor[16];
            memset(&mostFrequentColor[0],0,sizeof(int)*16);

            int colorIndex = 0;

            // Loop for all the source surface.
            for (image_y = 0; image_y < 8; ++image_y) {
                for (image_x = 0; image_x < 8; ++image_x) {

                    // Take the color of the pixel
                    rgb.red = *source;
                    rgb.green = *(source + 1);
                    rgb.blue = *(source + 2);

                    int minDistance = 9999;
                    for( int i=0; i<colorUsed; ++i ) {
                        int distance = rgbi_distance(&palette[i], &rgb );
                        if ( distance < minDistance ) {
                            minDistance = distance;
                            colorIndex = palette[i].index;
                        }
                    }

                    // printf("%d", i );

                    // Calculate the relative tile
                    
                    // Calculate the offset starting from the tile surface area
                    // and the bit to set.
                    offset = (image_y & 0x07);
                    bitmask = 1 << ( 7 - (image_x & 0x7) );

                    // If the pixes has enough luminance value, it must be 
                    // considered as "on"; otherwise, it is "off".
                    // int luminance = calculate_luminance(rgb);

                    if (colorUsed == 2 ) {
                        if ( colorIndex ) {
                            tileData.data[offset] &= ~bitmask;
                            // printf("%1.1x", colorIndex );
                        } else {
                            tileData.data[offset] |= bitmask;
                            // printf("%1.1x", colorIndex );
                        }
                    } else {
                        if ( colorIndex ) {
                            mostFrequentColor[colorIndex]++;
                            tileData.data[offset] &= ~bitmask;
                            // printf("%1.1x", colorIndex );
                        } else {
                            tileData.data[offset] |= bitmask;
                            // printf("%1.1x", colorIndex );
                        }
                    }

                    source += 3;

                }

                source += 3 * ( _width - 8 );

                // printf("\n" );

            }

            // printf("\n" );
            
            TileDescriptor * t = calculate_tile_descriptor( &tileData );

            int tile = calculate_exact_tile( t, _environment->descriptors );

            if ( tile == -1 ) {
                if ( _environment->descriptors->count < 128 ) {
                    tile = 0x5e + (_environment->descriptors->count++);
                    _environment->descriptors->descriptor[tile] = t; 
                    memcpy( &_environment->descriptors->data[tile], &tileData, sizeof( TileData ) ); 
                } else {
                    tile = calculate_nearest_tile( t, _environment->descriptors );
                }
                // printf("*** tile = %d\n", tile );
            } else {
                // printf("    tile = %d\n", tile );
            }

            *(buffer + 3 + (cy * ( _frame_width >> 3 ) ) + cx ) = tile;
            if ( colorUsed > 2 ) {
                int mostFrequentColorIndex = 1;
                int mostFrequentColorCount = 0;
                for(i=0;i<colorUsed;++i) {
                    if ( mostFrequentColorCount < mostFrequentColor[palette[i].index] ) {
                        mostFrequentColorCount = mostFrequentColor[palette[i].index];
                        mostFrequentColorIndex = palette[i].index;
                    }
                }
                // printf( "c = %1.1x\n", mostFrequentColorIndex );
                *(buffer + 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) + (cy * ( _frame_width >> 3 ) ) + cx ) = ( ( mostFrequentColorIndex & 0x07 ) );
            }

            // printf("\ntile: %2.2x\n", tile );

        }
        // printf("\n");
    }

    if ( colorUsed <= 2 ) {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) ) = palette[0].index == 0 ? palette[1].index : palette[0].index;
    }
    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

Variable * vic1_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

   switch( _mode ) {
        case BITMAP_MODE_STANDARD:
            return vic1_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
            break;
        case TILEMAP_MODE_STANDARD:
            return vic1_image_converter_tilemap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
            break;
    }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return vic1_new_image( _environment, 8, 8, BITMAP_MODE_STANDARD );

}

void vic1_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _frame_size, int _flags ) {

    // currently unused
    (void)!_flags;

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( putimage, src_hw_vic1_put_image_asm );

    outline1("LDA #<%s", _image );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _image );
    outline0("STA TMPPTR+1" );
    if ( _frame ) {
        outline0("CLC" );
        outline0("LDA TMPPTR" );
        outline0("ADC #2" );
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
    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s+1", _x );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s+1", _y );
    outline0("STA IMAGEY+1" );

    outline0("JSR PUTIMAGE");

}

void vic1_wait_vbl( Environment * _environment ) {

    deploy( vbl, src_hw_vic1_vbl_asm);

    outline0("JSR VBL");

}

Variable * vic1_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = calculate_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    // }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    result->size = size;
    
    return result;
}

void vic1_get_image( Environment * _environment, char * _image, char * _x, char * _y ) {
    
}

void vic1_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( scroll, src_hw_vic1_scroll_asm);
    deploy( textHScroll, src_hw_vic1_hscroll_text_asm );
    deploy( vScrollText, src_hw_vic1_vscroll_text_asm );

    outline1("LDA #$%2.2x", (unsigned char)(_dx&0xff) );
    outline0("STA MATHPTR0" );
    outline1("LDA #$%2.2x", (unsigned char)(_dy&0xff) );
    outline0("STA MATHPTR1" );
    outline0("JSR SCROLL");

}

void vic1_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline0("LDA #1" );
    outline0("STA TILEW" );
    outline0("STA TILEH" );

    outline0("JSR PUTTILE");

}

void vic1_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", tile->realName );
    outline0("STA TILET" );
    outline1("LDA %s", x->realName );
    outline0("STA TILEX" );
    outline1("LDA %s", y->realName );
    outline0("STA TILEY" );
    outline1("LDA %s+1", tile->realName );
    outline0("STA TILEW" );
    outline1("LDA %s+2", tile->realName );
    outline0("STA TILEH" );
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

void vic1_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline1("LDA %s+1", _tile );
    outline0("STA TILEW" );
    outline1("LDA %s+2", _tile );
    outline0("STA TILEH" );

    outline0("JSR PUTTILE");

}

void vic1_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _tileset );

    outline0("JSR USETILESET");

}

#endif