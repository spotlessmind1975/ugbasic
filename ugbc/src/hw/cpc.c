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

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0, "BLACK", 0x54 },        
        { 0x00, 0x00, 0x80, 1, "BLUE", 0x44 },
        { 0x00, 0x00, 0xff, 2, "LIGHT BLUE", 0x55 },
        { 0x80, 0x00, 0x00, 3, "RED", 0x5c },
        { 0x80, 0x00, 0x80, 4, "MAGENTA", 0x58 },
        { 0x80, 0x00, 0xff, 5, "MAUVE", 0x5d },
        { 0xff, 0x00, 0x00, 6, "LIGHT RED", 0x4c },
        { 0xff, 0x00, 0x80, 7, "PURPLE", 0x48 },
        { 0xff, 0x00, 0xff, 8, "LIGHT MAGENTA", 0x48 },
        { 0x00, 0x80, 0x00, 9, "GREEN", 0x56 },
        { 0x00, 0x80, 0x80, 10, "CYAN", 0x46 },
        { 0x00, 0x80, 0xff, 11, "DARK CYAN", 0x57 },
        { 0x80, 0x80, 0x00, 12, "YELLOW", 0x5e },
        { 0x80, 0x80, 0x80, 13, "WHITE", 0x40 },
        { 0x80, 0x80, 0xff, 14, "PASTEL BLUE", 0x5f },
        { 0xff, 0x80, 0x00, 15, "ORANGE", 0x5f },
        { 0xff, 0x80, 0x80, 16, "PINK", 0x47 },
        { 0xff, 0x80, 0xff, 17, "PASTEL MAGENTA", 0x4f },
        { 0x00, 0xff, 0x00, 18, "LIGHT GREEN", 0x52 },
        { 0x00, 0xff, 0x80, 19, "SEA GREEN", 0x42 },
        { 0x00, 0xff, 0xff, 20, "LIGHT CYAN", 0x53 },
        { 0x80, 0xff, 0x00, 21, "LIME", 0x5a },
        { 0x80, 0xff, 0x80, 22, "PASTEL GREEN", 0x59 },
        { 0x80, 0xff, 0xff, 23, "PASTEL CYAN", 0x5b },
        { 0xff, 0xff, 0x00, 24, "LIGHT YELLOW", 0x4a },
        { 0xff, 0xff, 0x80, 25, "PASTEL YELLOW", 0x43 },
        { 0xff, 0xff, 0xff, 26, "LIGHT WHITE", 0x4b },
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __cpc__

void cpc_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );

    outline0("CALL SCANCODE");
    outline0("LD A, E");
    outline0("CP 0");
    outline1("JR NZ, %skey", label);
    outline0("LD A, D");
    outline0("CP 0");
    outline1("JR NZ, %skey", label);
    outhead1("%snokey:", label);
    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed);
    outline1("JP %sdone", label);
    outhead1("%skey:", label);
    outline0("LD A, 1");
    outline1("LD (%s), A", _pressed);
    outline1("LD (%s), DE", _key);
    outhead1("%sdone:", label);
   
}

void cpc_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    cpc_inkey( _environment, _pressed, _scancode );
   
}

void cpc_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );

    outline1("LD HL, (%s)", _scancode);
    outline0("LD DE, HL");
    outline0("CALL SCANCODEPRECISE");
    outline1("JR NZ, %skey", label);
    outhead1("%snokey:", label);
    outline0("LD A, 0");
    outline1("LD (%s), A", _result);
    outline1("JP %sdone", label);
    outhead1("%skey:", label);
    outline0("LD A, 1");
    outline1("LD (%s), A", _result);
    outhead1("%sdone:", label);

}

void cpc_scanshift( Environment * _environment, char * _shifts ) {

}

void cpc_keyshift( Environment * _environment, char * _shifts ) {

}

void cpc_clear_key( Environment * _environment ) {

}

void cpc_irq_at( Environment * _environment, char * _label ) {

}

void cpc_follow_irq( Environment * _environment ) {

}

void cpc_joy( Environment * _environment, char * _port, char * _value ) {

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );
    deploy( joystick, src_hw_cpc_joystick_asm );

    outline1("LD A, (%s)", _port );
    outline0("LD B, A" );
    outline0("CALL JOYSTICK");
    outline1("LD (%s), A", _value );

}

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief <i>cpc</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * cpc_collision( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(collision)" );

    return result;
    
}

/**
 * @brief <i>cpc</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void cpc_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>cpc</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void cpc_border_color( Environment * _environment, char * _border_color ) {

    outline0("LD BC,$7F10");
    outline0("OUT (C), C");
    outline1("LD A, (%s)", _border_color);
    outline0("OR A, $40");
    outline0("OUT (C), A");

}

/**
 * @brief <i>cpc</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cpc_background_color( Environment * _environment, int _index, int _background_color ) {

    outline1("LD BC,$%4.4x", 0x7f00 | ( _index & 0x0f ));
    outline0("OUT (C), C");
    outline1("LD A, $%2.2x", 0x40 | ( _background_color & 0x1f ) );
    outline0("OUT (C), A");

}

/**
 * @brief <i>cpc</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cpc_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    outline0("LD BC,$7F00");
    outline1("LD A, (%s)", _index);
    outline0("AND A, $F");
    outline0("LD C, A");
    outline0("OUT (C), C");
    outline1("LD A, (%s)", _background_color);
    outline0("AND A, $1F");
    outline0("OR A, $40");
    outline0("OUT (C), A");

}

/**
 * @brief <i>cpc</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cpc_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    outline1("LD BC,$%4.4x", 0x7f00 | ( _index & 0x0f ));
    outline0("OUT (C), C");
    outline1("LD A, (%s)", _background_color);
    outline0("AND A, $1F");
    outline0("OR A, $40");
    outline0("OUT (C), A");

}

/**
 * @brief <i>cpc</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cpc_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>cpc</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void cpc_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>cpc</i>: emit code to set raster irq
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
void cpc_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>cpc</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void cpc_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>cpc</i>: emit code to wait for next raster irq at different position
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
void cpc_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>cpc</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void cpc_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>cpc</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void cpc_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>cpc</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void cpc_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>cpc</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void cpc_disable_mcm( Environment * _environment ) {

}

void cpc_bank_select( Environment * _environment, int _bank ) {
    
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

int cpc_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    cpu_store_8bit( _environment, "_PEN", DEFAULT_PEN_COLOR );
    cpu_store_8bit( _environment, "_PAPER", DEFAULT_PAPER_COLOR );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;

    switch( _screen_mode->id ) {

        // "Mode 0" 160×200 pixels with 16 colors
        case BITMAP_MODE_GRAPHIC0:
            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;
            CPC_GA_MASK( 0xc3, 0x80 );
            break;
        // "Mode 1" 320×200 pixels with 4 colors
        case BITMAP_MODE_GRAPHIC1:
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 4;
            CPC_GA_MASK( 0xc3, 0x81 );
            break;
        // "Mode 2" 640×200 pixels with 2 colors
        case BITMAP_MODE_GRAPHIC2:
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 2;
            CPC_GA_MASK( 0xc3, 0x82 );
            break;
        // "Mode 3" 160×200 pixels with 4 colors (2bpp) (this is not an official mode, but rather a side-effect of the hardware)
        case BITMAP_MODE_GRAPHIC3:
            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 4;
            CPC_GA_MASK( 0xc3, 0x83 );
            break;
    }

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", (_environment->screenWidth-1) );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", (_environment->screenHeight-1) );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );

}

void cpc_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        cpc_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        cpc_cls( _environment );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }
}

void cpc_bitmap_disable( Environment * _environment ) {

}

void cpc_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        cpc_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        cpc_cls( _environment );

    } else {
        // printf("cpc_tilemap_enable() -> -1\n" );
        WARNING_SCREEN_MODE( -1 );
    }

}

void cpc_bitmap_at( Environment * _environment, char * _address ) {

}

void cpc_colormap_at( Environment * _environment, char * _address ) {

}

void cpc_textmap_at( Environment * _environment, char * _address ) {

}

void cpc_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( plot, src_hw_cpc_plot_asm );
    
    outline1("LD A, $%2.2x", ( _y & 0xff ) );
    outline0("LD D, A");
    outline1("LD A, $%2.2x", ( _x & 0xff ) );
    outline0("LD E, A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

}

void cpc_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( plot, src_hw_cpc_plot_asm );
    
    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

}

void cpc_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( plot, src_hw_cpc_plot_asm );
    
    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A");
    outline0("LD A, 3");
    outline0("CALL PLOT");
    outline1("LD (%s), A", result->realName);

}

void cpc_screen_on( Environment * _environment ) {

}

void cpc_screen_off( Environment * _environment ) {

}

void cpc_screen_rows( Environment * _environment, char * _rows ) {

}

void cpc_screen_columns( Environment * _environment, char * _columns ) {

}

void cpc_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

}

void cpc_sprite_enable( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_disable( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void cpc_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void cpc_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void cpc_tiles_at( Environment * _environment, char * _address ) {

}

void cpc_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void cpc_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void cpc_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _timing);
    outline0("LD D, A");
    outline0("LD B, $f5");
    outline1("%swait", label );
    outline0("IN A, (C)");
    outline0("RRA");
    outline1("JP NC, %swait", label);
    outline0("DEC D");
    outline1("JP NZ, %swait", label);

}

void cpc_get_width( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTWIDTH)" );
    outline1("LD (%s), HL", _result );

}

void cpc_tiles_get( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILES)" );
    outline1("LD (%s), A", _result );

}

void cpc_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILESWIDTH)" );
    outline1("LD (%s), A", _result );

}

void cpc_get_height( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTHEIGHT)" );
    outline1("LD (%s), HL", _result );

}

void cpc_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILESHEIGHT)" );
    outline1("LD (%s), A", _result );

}

void cpc_cls( Environment * _environment ) {
    
    deploy( clsGraphic, src_hw_cpc_cls_graphic_asm );
    outline0("CALL CLSG");

}

void cpc_scroll_text( Environment * _environment, int _direction ) {

    if ( _direction > 0 ) {
        deploy( vScrollTextDown, src_hw_cpc_vscroll_text_down_asm );
        outline0("CALL VSCROLLTDOWN");
    } else {
        deploy( vScrollTextUp, src_hw_cpc_vscroll_text_up_asm );
        outline0("CALL VSCROLLTUP");
    }
    
}

void cpc_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( vScrollTextUp, src_hw_cpc_vscroll_text_up_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    deploy( clsGraphic, src_hw_cpc_cls_graphic_asm );
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    // deploy( textEncodedAt, src_hw_cpc_text_at_asm );
    deploy( textEncodedAtGraphic, src_hw_cpc_text_at_graphic_asm );
    deploy( font, src_hw_cpc_font_asm );
    outline0("CALL TEXTATBITMAPMODE");

}

void cpc_initialization( Environment * _environment ) {

    src_hw_chipset_mob_asm = src_hw_cpc_mob_asm;
    src_hw_chipset_mob_asm_len = src_hw_cpc_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 160 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 200  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 20 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 25 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC0, 1, 160, 200, 16, 8, 8, "Graphic Mode 0" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC1, 1, 320, 200, 4, 8, 8, "Graphic Mode 1" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 1, 640, 200, 2, 8, 8, "Graphic Mode 2" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC3, 1, 160, 200, 4, 8, 8, "Graphic Mode 3" );

    outline0("CALL CPCVIDEOSTARTUP");

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

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 2 );
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

    variable_import( _environment, "CPCTIMER", VT_WORD, 0 );
    variable_global( _environment, "CPCTIMER" );
    variable_import( _environment, "CPCTIMER2", VT_BYTE, 6 );
    variable_global( _environment, "CPCTIMER2" );
    
    cpc_screen_mode_enable( _environment, find_screen_mode_by_id( _environment, BITMAP_MODE_DEFAULT ) );

    cpc_cls( _environment );

    _environment->descriptors = precalculate_tile_descriptors_for_font( data_fontcpc_bin );

    _environment->descriptors->first = 0;
    _environment->descriptors->firstFree = 128;
    _environment->descriptors->lastFree = 255;
    _environment->descriptors->count = 128;
    
    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

void cpc_finalization( Environment * _environment ) {

}

void cpc_hscroll_line( Environment * _environment, int _direction ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textHScrollLine, src_hw_cpc_hscroll_line_asm );

    outline1("LD A, $%2.2x", _direction);
    outline0("CALL HSCROLLLINE");

}

void cpc_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textHScrollScreen, src_hw_cpc_hscroll_screen_asm );

    outline1("LD A, $%2.2x", _direction);
    outline0("CALL HSCROLLSCREEN");

}

void cpc_back( Environment * _environment ) {

}

void cpc_cline( Environment * _environment, char * _characters ) {

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

        case BITMAP_MODE_GRAPHIC0:

            return 2 + ( ( _width >> 1 ) * _height ) + 16;

        case BITMAP_MODE_GRAPHIC1:
        case BITMAP_MODE_GRAPHIC3:

            return 2 + ( ( _width >> 2 ) * _height ) + 4;

        case BITMAP_MODE_GRAPHIC2:

            return 2 + ( ( _width >> 3 ) * _height ) + 2;
    }

    return 0;

}

Variable * cpc_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return cpc_new_image( _environment, 8, 8, _mode );

}

void cpc_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( putimage, src_hw_cpc_put_image_asm );

    MAKE_LABEL

    outhead1("putimage%s:", label);
    outline1("LD A, $%2.2x", ( _flags & 0xff ) );
    outline1("LD HL, %s", _image );
    if ( _sequence ) {

        outline0("LD DE, $0003" );
        outline0("ADD HL, DE" );
        if ( strlen(_sequence) == 0 ) {

        } else {
            outline0("PUSH HL" );
            outline1("LD A, (%s)", _sequence );
            outline0("LD L, A" );
            outline0("LD H, 0" );
            outline0("ADD HL, HL" );
            outline0("LD DE, HL" );
            outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("ADD HL, DE" );
            outline0("LD A, (HL)" );
            outline0("LD E, A" );
            outline0("INC HL" );
            outline0("LD A, (HL)" );
            outline0("LD D, A" );
            outline0("POP HL" );
            outline0("ADD HL, DE" );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }

    } else {

        if ( _frame ) {
            outline0("LD DE, $0002" );
            outline0("ADD HL, DE" );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }


    }
    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, $%2.2x", _flags );
    outline0("LD (IMAGEF), A" );

    outline0("CALL PUTIMAGE");

}

void cpc_wait_vbl( Environment * _environment ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( vbl, src_hw_cpc_vbl_asm);

    outline0("JSR WAITVBL");

}

Variable * cpc_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    int size = calculate_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = _width;
    *(buffer+1) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void cpc_get_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( getimage, src_hw_cpc_get_image_asm );

    MAKE_LABEL

    outline1("LD HL, %s", _image );
    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );

    outline0("CALL GETIMAGE");

}


void cpc_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( vic2vars, src_hw_cpc_vars_asm);
    deploy( scroll, src_hw_cpc_scroll_asm);
    deploy( textHScrollLine, src_hw_cpc_hscroll_line_asm );
    deploy( textHScrollScreen, src_hw_cpc_hscroll_screen_asm );
    deploy( vScrollTextDown, src_hw_cpc_vscroll_text_down_asm );
    deploy( vScrollTextUp, src_hw_cpc_vscroll_text_up_asm );

    outline1("LD A, $%2.2x", (unsigned char)(_dx&0xff) );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", (unsigned char)(_dy&0xff) );
    outline0("LD C, A" );
    outline0("CALL SCROLL");

}

void cpc_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( tiles, src_hw_cpc_tiles_asm );

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

void cpc_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( tiles, src_hw_cpc_tiles_asm );

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

void cpc_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( tiles, src_hw_cpc_tiles_asm );

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

void cpc_tile_at( Environment * _environment, char * _x, char * _y, char *_result ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( tiles, src_hw_cpc_tiles_asm );

    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );

    outline0("CALL TILEAT");

    outline0("LD A, (TILET)" );
    outline1("LD (%s), A", _result );

}

void cpc_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( tiles, src_hw_cpc_tiles_asm );

    outline1("LD A, (%s)", _tileset );

    outline0("CALL USETILESET");

}

Variable * cpc_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

void cpc_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void cpc_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void cpc_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color ) {

}

#endif