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
        { 0x00, 0x00, 0x00, 0xff,  0, "BLACK", 0x14 },        
        { 0x00, 0x00, 0x80, 0xff,  1, "BLUE", 0x04 },
        { 0x00, 0x00, 0xff, 0xff,  2, "LIGHT BLUE", 0x15 },
        { 0x80, 0x00, 0x00, 0xff,  3, "RED", 0x1c },
        { 0x80, 0x00, 0x80, 0xff,  4, "MAGENTA", 0x18 },
        { 0x80, 0x00, 0xff, 0xff,  5, "MAUVE", 0x1d },
        { 0xff, 0x00, 0x00, 0xff,  6, "LIGHT RED", 0x0c },
        { 0xff, 0x00, 0x80, 0xff,  7, "PURPLE", 0x08 },
        { 0xff, 0x00, 0xff, 0xff,  8, "LIGHT MAGENTA", 0x08 },
        { 0x00, 0x80, 0x00, 0xff,  9, "GREEN", 0x16 },
        { 0x00, 0x80, 0x80, 0xff, 10, "CYAN", 0x06 },
        { 0x00, 0x80, 0xff, 0xff, 11, "DARK CYAN", 0x17 },
        { 0x80, 0x80, 0x00, 0xff, 12, "YELLOW", 0x1e },
        { 0x80, 0x80, 0x80, 0xff, 13, "WHITE", 0x00 },
        { 0x80, 0x80, 0xff, 0xff, 14, "PASTEL BLUE", 0x5f },
        { 0xff, 0x80, 0x00, 0xff, 15, "ORANGE", 0x0e },
        { 0xff, 0x80, 0x80, 0xff, 16, "PINK", 0x07 },
        { 0xff, 0x80, 0xff, 0xff, 17, "PASTEL MAGENTA", 0x0f },
        { 0x00, 0xff, 0x00, 0xff, 18, "LIGHT GREEN", 0x12 },
        { 0x00, 0xff, 0x80, 0xff, 19, "SEA GREEN", 0x02 },
        { 0x00, 0xff, 0xff, 0xff, 20, "LIGHT CYAN", 0x13 },
        { 0x80, 0xff, 0x00, 0xff, 21, "LIME", 0x1a },
        { 0x80, 0xff, 0x80, 0xff, 22, "PASTEL GREEN", 0x19 },
        { 0x80, 0xff, 0xff, 0xff, 23, "PASTEL CYAN", 0x1b },
        { 0xff, 0xff, 0x00, 0xff, 24, "LIGHT YELLOW", 0x0a },
        { 0xff, 0xff, 0x80, 0xff, 25, "PASTEL YELLOW", 0x03 },
        { 0xff, 0xff, 0xff, 0xff, 26, "LIGHT WHITE", 0x0b },
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __cpc__

static RGBi * commonPalette;
static int lastUsedSlotInCommonPalette = 0;

void cpc_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );

    outline0("CALL INKEY");
    outline0("CP 0");
    outline1("JR NZ, %skey", label);
    outhead1("%snokey:", label);
    outline1("LD (%s), A", _pressed);
    outline1("LD (%s), A", _key);
    outline1("JP %sdone", label);
    outhead1("%skey:", label);
    outline1("LD (%s), A", _key);
    outline0("LD B, A");
    outline0("LD A, 1");
    outline1("LD (%s), A", _pressed);
    // outhead1("%srelease:", label);
    // outline0("PUSH BC");
    // outline0("CALL INKEY");
    // outline0("POP BC");
    // outline0("CP B");
    // outline1("JR Z, %sequal", label);
    // outline1("JP %sdone", label);
    // outhead1("%sequal:", label);
    // outline0("NOP");
    // outline1("JP %srelease", label);
    outhead1("%sdone:", label);

}

void cpc_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );

    outline0("CALL SCANCODE");
    outline0("LD A, E");
    outline0("CP 0");
    outline1("JR NZ, %skey", label);
    outhead1("%snokey:", label);
    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed);
    outline1("LD (%s), A", _scancode);
    outline1("JP %sdone", label);
    outhead1("%skey:", label);
    outline0("LD A, 1");
    outline1("LD (%s), A", _pressed);
    outline0("LD A, E");
    outline1("LD (%s), A", _scancode);
    outhead1("%sdone:", label);
   
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

    outline0("DI");
    outline1("LD HL, %s", _label);
    outline0("LD DE, IRQTIMERADDR");
    outline0("INC DE");
    outline0("LD A, L");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("LD A, H");
    outline0("LD (DE), A");
    outline0("EI");

}

void cpc_follow_irq( Environment * _environment ) {

}

void cpc_joy_vars( Environment * _environment, char * _port, char * _value ) {

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );
    deploy( joystick, src_hw_cpc_joystick_asm );

    outline1("LD A, (%s)", _port );
    outline0("LD B, A" );
    outline0("CALL JOYSTICK");
    outline1("LD (%s), A", _value );

}

void cpc_joy( Environment * _environment, int _port, char * _value ) {

    _environment->bitmaskNeeded = 1;

    deploy( scancode, src_hw_cpc_scancode_asm );
    deploy( joystick, src_hw_cpc_joystick_asm );

    outline1("LD A, $%2.2x", (unsigned char)(_port & 0xff) );
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

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    outline1("LD A, $%2.2x", ( _index & 0x0f ));
    outline0("LD IXH, A");
    outline1("LD A, $%2.2x", ( _background_color & 0x0f ));
    outline0("LD IXL, A");
    outline0("LD A, 1");
    outline0("LD IYL, A");
    outline0("CALL CPCUPDATEPALETTE");

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

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    outline1("LD A, (%s)", _index);
    outline0("LD IXH, A");
    outline1("LD A, (%s)", _background_color);
    outline0("LD IXL, A");
    outline0("LD A, 1");
    outline0("LD IYL, A");
    outline0("CALL CPCUPDATEPALETTE");

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

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    MAKE_LABEL

    outline1("%sbackgroundcolor:", label );
    outline1("LD A, $%2.2x", ( _index & 0x0f ));
    outline0("LD IXH, A");
    outline1("LD A, (%s)", _background_color);
    outline0("LD IXL, A");
    outline0("LD A, 1");
    outline0("LD IYL, A");
    outline0("CALL CPCUPDATEPALETTE");

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

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    outline1("LD A, (%s)", _index);
    outline0("LD IXH, A");
    outline0("CALL CPCGETPALETTE");
    outline0("LD A, IXL");
    outline1("LD (%s), A", _background_color);
    
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
            colorIndex = SYSTEM_PALETTE[j].hardwareIndex;
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
            _environment->currentModeBW = 4;
            CPC_GA_MASK( 0xc2, 0x80 );
            break;
        // "Mode 1" 320×200 pixels with 4 colors
        case BITMAP_MODE_GRAPHIC1:
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            CPC_GA_MASK( 0xc2, 0x81 );
            break;
        // "Mode 2" 640×200 pixels with 2 colors
        case BITMAP_MODE_GRAPHIC2:
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            CPC_GA_MASK( 0xc2, 0x82 );
            break;
        // "Mode 3" 160×200 pixels with 4 colors (2bpp) (this is not an official mode, but rather a side-effect of the hardware)
        case BITMAP_MODE_GRAPHIC3:
            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            CPC_GA_MASK( 0xc2, 0x83 );
            break;
    }

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", (_environment->screenWidth-1) );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", (_environment->screenHeight-1) );

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );
    cpu_store_8bit( _environment, "PALETTELIMIT", _environment->screenColors );
    

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
    outline1("LD A, $%2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0("LD IXL, A");
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
    if ( VT_BITWIDTH( x->type ) > 8 ) {
        outline1("LD A, (%s)", address_displacement(_environment, x->realName, "1") );
    } else {
        outline0("LD A, 0" );
    }
    outline0("LD IXL, A");
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
    if ( VT_BITWIDTH( x->type ) > 8 ) {
        outline1("LD A, (%s)", address_displacement(_environment, x->realName, "1") );
    } else {
        outline0("LD A, 0" );
    }
    outline0("LD IXL, A");
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
    outline0("CALL TEXTATBITMAPMODE");

}

void cpc_initialization( Environment * _environment ) {

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
    variable_import( _environment, "PALETTELIMIT", VT_BYTE, 16 );
    variable_global( _environment, "PALETTELIMIT" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 1, 640, 200, 2, 8, 8, "Graphic Mode 2" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC0, 1, 160, 200, 16, 8, 8, "Graphic Mode 0" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC1, 1, 320, 200, 4, 8, 8, "Graphic Mode 1" );
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

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );

    variable_import( _environment, "XCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "XCURSYS" );
    variable_import( _environment, "YCURSYS", VT_SBYTE, 0 );
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
    variable_import( _environment, "IMAGET", VT_BYTE, 0 );
    variable_global( _environment, "IMAGET" );

    variable_import( _environment, "CPCTIMER", VT_WORD, 0 );
    variable_global( _environment, "CPCTIMER" );
    variable_import( _environment, "CPCTIMER2", VT_BYTE, 6 );
    variable_global( _environment, "CPCTIMER2" );

    variable_import( _environment, "EVERYSTATUS", VT_BYTE, 0 );
    variable_global( _environment, "EVERYSTATUS" );
    variable_import( _environment, "EVERYCOUNTER", VT_BYTE, 0 );
    variable_global( _environment, "EVERYCOUNTER" );
    variable_import( _environment, "EVERYTIMING", VT_BYTE, 0 );
    variable_global( _environment, "EVERYTIMING" );

    variable_import( _environment, "FPSCRAP", VT_BUFFER, 16 );
    variable_global( _environment, "FPSCRAP" );

    variable_import( _environment, "IMAGEY", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEY" );

    variable_import( _environment, "SLICEX", VT_POSITION, 0 );
    variable_global( _environment, "SLICEX" );
    variable_import( _environment, "SLICEY", VT_POSITION, 0 );
    variable_global( _environment, "SLICEY" );
    variable_import( _environment, "SLICEDTARGET", VT_POSITION, 0 );
    variable_global( _environment, "SLICEDTARGET" );
    variable_import( _environment, "GAVALUE", VT_BYTE, 0xfc );
    variable_global( _environment, "GAVALUE" );

    cpc_screen_mode_enable( _environment, find_screen_mode_by_id( _environment, BITMAP_MODE_DEFAULT ) );

    font_descriptors_init( _environment, 0 );
    
    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 80;
    _environment->screenTilesHeight = 25;
    _environment->screenTiles = 255;
    _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
    _environment->currentModeBW = 1;
    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;
    _environment->screenColors = 2;

}

void cpc_finalization( Environment * _environment ) {

}

void cpc_hscroll_line( Environment * _environment, int _direction ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textHScrollLine, src_hw_cpc_hscroll_line_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LD A, (%s)", y->realName );
    outline0("LD B, A");
    outline1("LD A, $%2.2x", _direction);
    outline0("CALL HSCROLLLINE");

}

void cpc_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textHScrollScreen, src_hw_cpc_hscroll_screen_asm );

    outline1("LD A, $%2.2x", (unsigned char)(_direction));
    outline0("CALL HSCROLLSCREEN");

}

void cpc_back( Environment * _environment ) {

}

void cpc_cline( Environment * _environment, char * _characters ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textCline, src_hw_cpc_cline_asm );

    if ( _characters ) {
        outline1("LD A, (%s)", _characters);
    } else {
        outline0("LD A, 0");
    }
    outline0("CALL CLINE");

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case BITMAP_MODE_GRAPHIC0:

            return 3 + ( ( _width >> 1 ) * _height ) + 16;

        case BITMAP_MODE_GRAPHIC1:
        case BITMAP_MODE_GRAPHIC3:

            return 3 + ( ( _width >> 2 ) * _height ) + 4;

        case BITMAP_MODE_GRAPHIC2:

            return 3 + ( ( _width >> 3 ) * _height ) + 2;
    }

    return 0;

}

static Variable * cpc_image_converter_bitmap_mode_hires( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 2 );
            paletteColorCount = 2;
        }

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 2 );
            paletteColorCount = 2;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 2 ) {
            lastUsedSlotInCommonPalette = 2;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );

    adilinebeginbitmap("BMD");

    char * buffer = malloc ( bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, bitmask;

    int colorIndex;

    // Color of the pixel to convert
    RGBi rgb;

    *(buffer) = (_frame_width & 0xff);
    *(buffer+1) = ( _frame_width >> 8 ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

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

            if ( rgb.alpha < 255 ) {
                colorIndex = 0;
            } else {
                int minDistance = 9999;
                for( int i=0; i<lastUsedSlotInCommonPalette; ++i ) {
                    int distance = rgbi_distance(&commonPalette[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            adilinepixel(colorIndex);

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y *( _frame_width >> 3 ) ) + (image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( colorIndex == 1 ) {
                *( buffer + offset + 3) |= bitmask;
            } else {
                *( buffer + offset + 3) &= ~bitmask;
            }

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

    }

    adilineendbitmap();

    int hwIndex;

    if ( lastUsedSlotInCommonPalette > 1 ) {
        hwIndex = commonPalette[1].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) + 1 ) = hwIndex;

    if ( lastUsedSlotInCommonPalette > 1 ) {
        hwIndex = commonPalette[0].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) ) = hwIndex;

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

static Variable * cpc_image_converter_multicolor_mode_midres( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 4) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 4 );
            paletteColorCount = 4;
        }
        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 4 );
            paletteColorCount = 4;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 4 ) {
            lastUsedSlotInCommonPalette = 4;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC1 );
    
    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_GRAPHIC1 );

    adilinebeginbitmap("BMD");

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

    *(buffer) = (_frame_width & 0xff);
    *(buffer+1) = (_frame_width >> 8 ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

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

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y * ( _frame_width >> 2 ) ) + (image_x>>2);

            int colorIndex = 0;

            if ( rgb.alpha < 255 ) {
                colorIndex = 0;
            } else {
                int minDistance = 9999;
                for( int i=0; i<lastUsedSlotInCommonPalette; ++i ) {
                    int distance = rgbi_distance(&commonPalette[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            if ( _environment->debugImageLoad ) {
                printf("%1.1x", colorIndex );
            }
            
            adilinepixel(colorIndex);

            bitmask = ( ( colorIndex & 0x1 ) ) << (3 - ((image_x & 0x3)));
            bitmask |= ( ( ( colorIndex & 0x2 ) ) << 3 ) << (3 - ((image_x & 0x3)));

            *(buffer + 3 + offset) |= bitmask;

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        if ( _environment->debugImageLoad ) {
            printf("\n" );
        }
    }

    adilineendbitmap();

    if ( _environment->debugImageLoad ) {
        printf("\n" );
    
        printf("PALETTE:\n" );
        if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
            printf("  background  (00) = %2.2x (%s)\n", commonPalette[0].hardwareIndex, commonPalette[0].description );
        } else {
            printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", commonPalette[0].index, commonPalette[0].description );
        }
        printf("  pen         (01) = %2.2x (%s)\n", commonPalette[1].hardwareIndex, commonPalette[1].description );
        printf("  pen         (10) = %2.2x (%s)\n", commonPalette[2].hardwareIndex, commonPalette[2].description );
        printf("  pen         (11) = %2.2x (%s)\n", commonPalette[3].hardwareIndex, commonPalette[3].description );
        printf("\n" );
        printf("\n" );
    }

    int hwIndex = 0;
    if ( lastUsedSlotInCommonPalette > 0 ) {
        hwIndex = commonPalette[0].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) )= hwIndex;

    if ( lastUsedSlotInCommonPalette > 1 ) {
        hwIndex = commonPalette[1].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 ) = hwIndex;

    if ( lastUsedSlotInCommonPalette > 2 ) {
        hwIndex = commonPalette[2].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 1 ) = hwIndex;

    if ( lastUsedSlotInCommonPalette > 3 ) {
        hwIndex = commonPalette[3].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 3 ) = hwIndex;

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

static Variable * cpc_image_converter_multicolor_mode_lores( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 16) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 16 );
            paletteColorCount = 16;
        }

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 16 );
            paletteColorCount = 16;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 16 ) {
            lastUsedSlotInCommonPalette = 16;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC0 );
    
    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_GRAPHIC0 );

    adilinebeginbitmap("BMD");

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

    *(buffer) = (_frame_width & 0xff);
    *(buffer+1) = (_frame_width >> 8 ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

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

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y * ( _frame_width >> 1 ) ) + (image_x>>1);

            int colorIndex = 0;

            if ( rgb.alpha < 255 ) {
                colorIndex = 0;
            } else {
                int minDistance = 9999;
                for( int i=0; i<lastUsedSlotInCommonPalette; ++i ) {
                    int distance = rgbi_distance(&commonPalette[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            if ( _environment->debugImageLoad ) {
                printf("%1.1x", colorIndex );
            }

            adilinepixel(colorIndex);
            
            bitmask = ( ( colorIndex & 0x8 ) >> 3 ) << (1 - ((image_x & 0x1)));
            bitmask |= ( ( ( colorIndex & 0x2 ) ) << 1 ) << (1 - ((image_x & 0x1)));
            bitmask |= ( ( ( colorIndex & 0x4 ) ) << 2 ) << (1 - ((image_x & 0x1)));
            bitmask |= ( ( ( colorIndex & 0x1 ) ) << 6 ) << (1 - ((image_x & 0x1)));

            *(buffer + 3 + offset) |= bitmask;

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        if ( _environment->debugImageLoad ) {
            printf("\n" );
        }
    }

    adilineendbitmap();

    if ( _environment->debugImageLoad ) {
        printf("\n" );
    
        printf("PALETTE:\n" );
        if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
            printf("  background  (0000) = %2.2x (%s)\n", commonPalette[0].hardwareIndex, commonPalette[0].description );
        } else {
            printf("  background  (0000) = %2.2x (%s) [currently ignored since it can be overlayed]\n", commonPalette[0].index, commonPalette[0].description );
        }
        for(int i=1;i<lastUsedSlotInCommonPalette;++i) {
            printf("  pen         (%d) = %2.2x (%s)\n", i, commonPalette[i].hardwareIndex, commonPalette[i].description );
        }
        printf("\n" );
        printf("\n" );
    }

    for( int i=0; i<16; ++i ) {
        int hwIndex = 0xff;
        if ( lastUsedSlotInCommonPalette > ( i ) ) {
            hwIndex = commonPalette[i].hardwareIndex;    
        }
        *(buffer + 3 + ( ( _frame_width >> 1 ) * _frame_height ) + i ) = hwIndex;
    }

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * cpc_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    switch( _mode ) {

        case BITMAP_MODE_GRAPHIC2:

            return cpc_image_converter_bitmap_mode_hires( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
            
        case BITMAP_MODE_GRAPHIC1:

            return cpc_image_converter_multicolor_mode_midres( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

        case BITMAP_MODE_GRAPHIC0:
        case BITMAP_MODE_GRAPHIC3:

            return cpc_image_converter_multicolor_mode_lores( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

    }

    return cpc_new_image( _environment, 8, 8, _mode );

}

static void cpc_load_image_address_to_register( Environment * _environment, char * _register, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    outline2("LD %s, %s", _register, _source );
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

    } else {

        if ( _frame ) {
            outline0("LD DE, $0003" );
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

}

void cpc_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( putimage, src_hw_cpc_put_image_asm );

    MAKE_LABEL

    cpc_load_image_address_to_register( _environment, "HL", _image, _sequence, _frame, _frame_size, _frame_count );

    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _x, "1") );
    outline0("LD IXL, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, $%2.2x", (_flags & 0Xff) );
    outline0("LD (IMAGEF), A" );
    outline1("LD A, $%2.2x", ((_flags>>8) & 0Xff) );
    outline0("LD (IMAGET), A" );

    outline0("CALL PUTIMAGE");

}

void cpc_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( blitimage, src_hw_cpc_blit_image_asm );

    if ( _source_count > 2 ) {
        CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    }

    MAKE_LABEL

    outhead1("blitimage%s:", label);
    if ( _source_count > 0 ) {
        cpc_load_image_address_to_register( _environment, "HL", _sources[0], _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LD HL, 0" );
    }

    outline0("DI");
    outline0("EXX");
    outline0("EI");

    if ( _source_count > 1 ) {
        cpc_load_image_address_to_register( _environment, "HL", _sources[1], _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LD HL, 0" );
    }

    outline1("LD DE, %s", _blit );

    outline0("DI");
    outline0("EXX");
    outline0("EI");

    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _x, "1") );
    outline0("LD IXL, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, $%2.2x", (_flags & 0Xff) );
    outline0("LD (IMAGEF), A" );
    outline1("LD A, $%2.2x", ((_flags>>8) & 0Xff) );
    outline0("LD (IMAGET), A" );

    outline0("CALL BLITIMAGE");

}

void cpc_wait_vbl( Environment * _environment ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( vbl, src_hw_cpc_vbl_asm);

    outline0("CALL WAITVBL");

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

    *(buffer) = ( _width & 0xff );
    *(buffer+1) = ( ( _width >> 8 ) & 0xff );
    *(buffer+2) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void cpc_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( getimage, src_hw_cpc_get_image_asm );

    MAKE_LABEL

    outline1("LD HL, %s", _image );
    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _x, "1") );
    outline0("LD IXL, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, $%2.2x", _palette );
    outline0("LD IXH, A" );

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
    outline1("LD A, (%s)", address_displacement(_environment, tile->realName, "1") );
    outline0("LD (TILEW), A" );
    outline0("LD (TILEW2), A" );
    outline1("LD A, (%s)", address_displacement(_environment, tile->realName, "2") );
    outline0("LD (TILEH), A" );
    outline0("LD (TILEH2), A" );
    outline1("LD A, (%s)", address_displacement(_environment, tile->realName, "3") );
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
    outline1("LD A, (%s)", address_displacement(_environment, _tile, "1") );
    outline0("LD (TILEW), A" );
    if ( _w ) {
        outline1("LD A, (%s)", _w );
    }
    outline0("LD (TILEW2), A" );
    outline1("LD A, (%s)", address_displacement(_environment, _tile, "2") );
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

void cpc_slice_image_copy( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( duff, src_hw_z80_duff_asm );
    deploy( sliceimagecopy, src_hw_cpc_slice_image_copy_asm );

    MAKE_LABEL

    cpc_load_image_address_to_register( _environment, "HL", _image, _sequence, _frame, _frame_size, _frame_count );

    outline1( "LD DE, %s", _destination );

    outline0("CALL SLICEIMAGECOPY");

}

void cpc_slice_image_extract( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

    deploy( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( duff, src_hw_z80_duff_asm );
    deploy( sliceimageextract, src_hw_cpc_slice_image_extract_asm );

    MAKE_LABEL

    cpc_load_image_address_to_register( _environment, "HL", _image, _sequence, _frame, _frame_size, _frame_count );

    Variable * sliceImageX = variable_retrieve( _environment, _environment->sliceImageX );
    Variable * sliceImageY = variable_retrieve( _environment, _environment->sliceImageY );
    outline1( "LD DE, (%s)", sliceImageX->realName );
    outline0( "LD (SLICEX), DE" );
    outline1( "LD DE, (%s)", sliceImageY->realName );
    outline0( "LD (SLICEY), DE" );
    outline1( "LD DE, %s", _destination );

    outline0("CALL SLICEIMAGEEXT");

}

void cpc_sys_call( Environment * _environment, int _destination ) {

    outline0("PUSH HL" );
    outline0("LD HL, SYSCALL0" );
    outline0("INC HL" );
    outline1("LD (HL), $%2.2x", (_destination & 0xff ) );
    outline0("INC HL" );
    outline1("LD (HL), $%2.2x", ((_destination>>8) & 0xff ) );
    outline0("POP HL" );
    outline0("CALL SYSCALL");

}

int cpc_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

#endif