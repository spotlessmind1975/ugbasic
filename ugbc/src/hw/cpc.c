/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
        { 0xff, 0x00, 0xff, 0xff,  8, "LIGHT MAGENTA", 0x0d },
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

static int plotVBase[] = {
    0xC000, 0xC800, 0xD000, 0xD800, 0xE000, 0xE800, 0xF000, 0xF800,
    0xC050, 0xC850, 0xD050, 0xD850, 0xE050, 0xE850, 0xF050, 0xF850,
    0xC0A0, 0xC8A0, 0xD0A0, 0xD8A0, 0xE0A0, 0xE8A0, 0xF0A0, 0xF8A0,
    0xC0F0, 0xC8F0, 0xD0F0, 0xD8F0, 0xE0F0, 0xE8F0, 0xF0F0, 0xF8F0,
    0xC140, 0xC940, 0xD140, 0xD940, 0xE140, 0xE940, 0xF140, 0xF940,
    0xC190, 0xC990, 0xD190, 0xD990, 0xE190, 0xE990, 0xF190, 0xF990,
    0xC1E0, 0xC9E0, 0xD1E0, 0xD9E0, 0xE1E0, 0xE9E0, 0xF1E0, 0xF9E0,
    0xC230, 0xCA30, 0xD230, 0xDA30, 0xE230, 0xEA30, 0xF230, 0xFA30,
    0xC280, 0xCA80, 0xD280, 0xDA80, 0xE280, 0xEA80, 0xF280, 0xFA80,
    0xC2D0, 0xCAD0, 0xD2D0, 0xDAD0, 0xE2D0, 0xEAD0, 0xF2D0, 0xFAD0,
    0xC320, 0xCB20, 0xD320, 0xDB20, 0xE320, 0xEB20, 0xF320, 0xFB20,
    0xC370, 0xCB70, 0xD370, 0xDB70, 0xE370, 0xEB70, 0xF370, 0xFB70,
    0xC3C0, 0xCBC0, 0xD3C0, 0xDBC0, 0xE3C0, 0xEBC0, 0xF3C0, 0xFBC0,
    0xC410, 0xCC10, 0xD410, 0xDC10, 0xE410, 0xEC10, 0xF410, 0xFC10,
    0xC460, 0xCC60, 0xD460, 0xDC60, 0xE460, 0xEC60, 0xF460, 0xFC60,
    0xC4B0, 0xCCB0, 0xD4B0, 0xDCB0, 0xE4B0, 0xECB0, 0xF4B0, 0xFCB0,
    0xC500, 0xCD00, 0xD500, 0xDD00, 0xE500, 0xED00, 0xF500, 0xFD00,
    0xC550, 0xCD50, 0xD550, 0xDD50, 0xE550, 0xED50, 0xF550, 0xFD50,
    0xC5A0, 0xCDA0, 0xD5A0, 0xDDA0, 0xE5A0, 0xEDA0, 0xF5A0, 0xFDA0,
    0xC5F0, 0xCDF0, 0xD5F0, 0xDDF0, 0xE5F0, 0xEDF0, 0xF5F0, 0xFDF0,
    0xC640, 0xCE40, 0xD640, 0xDE40, 0xE640, 0xEE40, 0xF640, 0xFE40,
    0xC690, 0xCE90, 0xD690, 0xDE90, 0xE690, 0xEE90, 0xF690, 0xFE90,
    0xC6E0, 0xCEE0, 0xD6E0, 0xDEE0, 0xE6E0, 0xEEE0, 0xF6E0, 0xFEE0,
    0xC730, 0xCF30, 0xD730, 0xDF30, 0xE730, 0xEF30, 0xF730, 0xFF30,
    0xC780, 0xCF80, 0xD780, 0xDF80, 0xE780, 0xEF80, 0xF780, 0xFF80
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __cpc__

static RGBi * commonPalette;
static int lastUsedSlotInCommonPalette = 0;

void cpc_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm);

    outline0("CALL INKEY");
    outline1("LD (%s), A", _key);

}

void cpc_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );

    if ( _release ) {
        outline0("CALL WAITKEYRELEASE");
    } else {
        outline0("CALL WAITKEY");
    }
   
}


void cpc_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cpc_joystick_asm );
    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_cpc_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("CALL WAITKEYFIRE");
    } else {
        outline1("LD A, %2.2x", _port);
        outline0("CALL WAITKEYFIREA");
    }
   
}

void cpc_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cpc_joystick_asm );
    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_cpc_wait_key_or_fire_asm );

    if ( ! _port ) {
        outline0("CALL WAITKEYFIRE");
    } else {
        outline1("LD A, (%s)", _port);
        outline0("CALL WAITKEYFIREA");
    }
   
}

void cpc_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cpc_joystick_asm );
    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );

    switch( _port ) {
        case -1:
            outline0("CALL WAITFIRE");
            break;
        case 0:
            outline0("CALL WAITFIRE0");
            break;
        case 1:
            outline0("CALL WAITFIRE1");
            break;
    }
      
}

void cpc_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cpc_joystick_asm );

    if ( ! _port ) {
        outline0("CALL WAITFIRE");
    } else {
        outline1("LD A, (%s)", _port);
        outline0("CALL WAITKEYFIREA");
    }

}

void cpc_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );

    outline1("LD A, (%s)", _scancode);
    outline0("CALL KEYSTATE");
    cpu_ctoa( _environment );
    outline1("LD (%s), A", _result);

}

void cpc_scancode( Environment * _environment, char * _result ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm);

    outline0("CALL SCANCODE");
    if ( _environment->vestigialConfig.rchack_falling_balls_1163 ) {
        outline0("CP $FF");
        outline1("JR NZ, %s", label );
        outline0("XOR $FF");
        outhead1("%s:", label );
    }
    outline1("LD (%s), A", _result );
   
}

void cpc_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm);

    outline0("CALL ASCIICODE");
    outline1("LD (%s), A", _result );
   
}

void cpc_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );

    outline1("LD A, (%s)", _scancode);
    outline0("CALL KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("LD (%s), A", _result);

}

void cpc_scanshift( Environment * _environment, char * _shifts ) {

}

void cpc_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );

    outline0("CALL KEYSHIFT" );
    outline1("LD (%s), A", _shifts );

}

void cpc_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );

    outline0("CALL CLEARKEY" );

}

void cpc_joy_vars( Environment * _environment, char * _port, char * _value ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );
    deploy( joystick, src_hw_cpc_joystick_asm );

    MAKE_LABEL

    if ( _environment->keyboardConfig.sync ) {
        outline0("CALL SCANCODERAW" );
    }
    outline1("LD A, (%s)", _port);
    outline0("CP 0");
    outline1("JR NZ, %spt1", label );
    if ( _environment->joystickConfig.sync ) {
        outline0("CALL JOYSTICKREAD0" );
    } else {
        outline0("LD A, (JOYSTICK0)" );
    }
    if ( _environment->joystickConfig.values ) {
        outline0("CALL JOYSTICKTSB" );
    }
    outline1("LD (%s), A", _value);
    outline1("JR %sptx", label );
    outhead1("%spt1:", label);
    if ( _environment->joystickConfig.sync ) {
        outline0("CALL JOYSTICKREAD1" );
    } else {
        outline0("LD A, (JOYSTICK1)" );
    }
    if ( _environment->joystickConfig.values ) {
        outline0("CALL JOYSTICKTSB" );
    }
    outline1("LD (%s), A", _value);
    outline1("JR %sptx", label );
    outhead1("%sptx:", label);

}

void cpc_joy( Environment * _environment, int _port, char * _value ) {

    _environment->bitmaskNeeded = 1;
    
    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm );
    deploy( joystick, src_hw_cpc_joystick_asm );
    if ( _environment->keyboardConfig.sync ) {
        outline0("CALL SCANCODERAW" );
    }
    switch ( _port ) {
        case 0:
            if ( _environment->joystickConfig.sync ) {
                outline0("CALL JOYSTICKREAD0" );
            } else {
                outline0("LD A, (JOYSTICK0)" );
            }
            break;
        case 1:
            if ( _environment->joystickConfig.sync ) {
                outline0("CALL JOYSTICKREAD0" );
            } else {
                outline0("LD A, (JOYSTICK0)" );
            }
            break;
    }
    if ( _environment->joystickConfig.values ) {
        outline0("CALL JOYSTICKTSB" );
    }
    outline1("LD (%s), A", _value);

}

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief <i>cpc</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * cpc_collision( Environment * _environment, char * _sprite ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(collision)" );

    return result;
    
}

/**
 * @brief <i>cpc</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 0xff = 
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
    outline0("LD (PALETTEB), A");
    outline0("AND $1f");
    outline0("OR A, 0x40");
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    outline1("LD A, 0x%2.2x", ( _index & 0x0f ));
    outline0("LD IXH, A");
    outline1("LD A, 0x%2.2x", ( _background_color & 0x0f ));
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    MAKE_LABEL

    outline1("%sbackgroundcolor:", label );
    outline1("LD A, 0x%2.2x", ( _index & 0x0f ));
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

void console_calculate( Environment * _environment ) {

    int consoleSA = plotVBase[ ( _environment->activeConsole.y1 * 8 ) ] + ( _environment->activeConsole.x1 * _environment->currentModeBW ) ;
    int consoleWB = _environment->activeConsole.width * _environment->currentModeBW;
    int consoleHB = _environment->activeConsole.height * 8;

    cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    outline0( "CALL CONSOLECALCULATE" );

}

int cpc_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    _screen_mode->selected = 1;

    cpu_store_8bit( _environment, "_PEN", _environment->defaultPenColor );
    cpu_store_8bit( _environment, "_PAPER", _environment->defaultPaperColor );

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
            _environment->currentModeBW = 2;
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
            _environment->currentModeBW = 1;
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
            _environment->currentModeBW = 2;
            CPC_GA_MASK( 0xc3, 0x83 );
            break;
    }

    _environment->consoleTilesWidth = _environment->screenTilesWidth;
    _environment->consoleTilesHeight = _environment->screenTilesHeight;

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

    console_init( _environment );

    if (_environment->vestigialConfig.clsImplicit ) {
        cpc_cls( _environment );
    }

}

void cpc_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        cpc_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        if (_environment->vestigialConfig.clsImplicit ) {
            cpc_cls( _environment );
        }

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

        if (_environment->vestigialConfig.clsImplicit ) {
            cpc_cls( _environment );
        }

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

void cpc_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( plot, src_hw_cpc_plot_asm );
    
    outline1("LD A, 0x%2.2x", ( _y & 0xff ) );
    outline0("LD D, A");
    outline1("LD A, 0x%2.2x", ( _x & 0xff ) );
    outline0("LD E, A");
    outline1("LD A, 0x%2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0("LD IXL, A");
    if ( _c ) {
        outline1("LD A, $%2.2x", ( *_c & 0Xff ) );
    } else {
        Variable * c = variable_retrieve( _environment, "PEN" );
        outline1("LD A, (%s)", c->realName );
    }
    outline0("LD (PLOTCPE), A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

}

void cpc_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * c;
    
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    } else {
        c = variable_retrieve( _environment, "PEN" );
    }

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( plot, src_hw_cpc_plot_asm );
    
    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A");
    outline1("LD A, (%s)", c->realName );
    outline0("LD (PLOTCPE), A");
    if ( VT_BITWIDTH( x->type ) > 8 ) {
        outline1("LD A, (%s)", address_displacement(_environment, x->realName, "1") );
    } else {
        outline0("LD A, 0" );
    }
    outline0("LD IXL, A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

}

void cpc_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

void cpc_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void cpc_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

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

void cpc_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

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
    outline0("LD B, 0xf5");
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

void cpc_get_height( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTHEIGHT)" );
    outline1("LD (%s), HL", _result );

}

void cpc_cls( Environment * _environment ) {
    
    deploy( clsGraphic, src_hw_cpc_cls_graphic_asm );
    outline0("CALL CLSG");

}

void cpc_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {
    
    deploy( clsBox, src_hw_cpc_cls_box_asm );

    outline1("LD A, (%s)", _x1);
    outline0("LD E, A");
    outline1("LD A, (%s)", address_displacement( _environment, _x1, "1" ) );
    outline0("LD IXH, A");

    outline1("LD A, (%s)", _y1);
    outline0("LD D, A");

    outline1("LD A, (%s)", _x1);
    outline0("LD E, A");
    outline1("LD A, (%s)", address_displacement( _environment, _x1, "1" ) );
    outline0("LD IXH, A");

    outline1("LD A, (%s)", _w);
    outline0("LD C, A");
    outline1("LD A, (%s)", _h);
    outline0("LD B, A");
    outline0("CALL CLSBOX");

}

void cpc_scroll_text( Environment * _environment, int _direction, int _overlap ) {

    if ( _direction > 0 ) {
        deploy_preferred( vScrollTextDown, src_hw_cpc_vscroll_text_down_asm );
        outline1("LD IYL, $%2.2x", (unsigned char)(_overlap&0xff) );
        outline0("CALL VSCROLLTDOWN");
    } else {
        deploy_preferred( vScrollTextUp, src_hw_cpc_vscroll_text_up_asm );
        outline1("LD IYL, $%2.2x", (unsigned char)(_overlap&0xff) );
        outline0("CALL VSCROLLTUP");
    }
    
}

void cpc_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy_preferred( vScrollTextUp, src_hw_cpc_vscroll_text_up_asm );

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
    variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 20 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 25 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );
    variable_import( _environment, "PALETTELIMIT", VT_BYTE, 16 );
    variable_global( _environment, "PALETTELIMIT" );

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

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );

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

    variable_import( _environment, "XCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "XCURSYS" );
    variable_import( _environment, "YCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "YCURSYS" );

    variable_import( _environment, "CONSOLESA", VT_ADDRESS, 0x0 );
    variable_global( _environment, "CONSOLESA" );
    variable_import( _environment, "CONSOLEHB", VT_BYTE, 0x0 );
    variable_global( _environment, "CONSOLEHB" );
    variable_import( _environment, "CONSOLEWB", VT_BYTE, 0x0 );
    variable_global( _environment, "CONSOLEWB" );

    variable_import( _environment, "PENT", VT_BYTE, 0x0 );
    variable_global( _environment, "PENT" );
    variable_import( _environment, "PAPERT", VT_BYTE, 0x0 );
    variable_global( _environment, "PAPERT" );

    cpc_screen_mode_enable( _environment, find_screen_mode_by_id( _environment, BITMAP_MODE_DEFAULT ) );

    console_init( _environment );

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
    _environment->currentModeBW = 1;

}

void cpc_finalization( Environment * _environment ) {

    if ( ! _environment->vestigialConfig.rchack_pick_the_star_1163 ) {
        outhead0("PALETTE:");
        int defaultPalette[] = { 
                4,  10,  19,  12,
                11,  20,  21,  13,
                6,  30,  31,   7,
                18, 25,  10,   7
        };

        if ( ! commonPalette ) {
            out0("DB ");
            for( int i=0; i<15; ++i ) {
                out1("%d,", defaultPalette[i] );
            }
            outline1("%d", defaultPalette[15] );
        } else {
            out0("DB ");
            for( int i=0; i<lastUsedSlotInCommonPalette; ++i ) {
                out1("%d,", commonPalette[i].hardwareIndex );
            }
            for( int i=lastUsedSlotInCommonPalette; i<16; ++i ) {
                out1("%d,", defaultPalette[i] );
            }
            outline0("0");
        }
    }

    if ( _environment->vestigialConfig.clsImplicit ) {
        deploy( clsGraphic, src_hw_cpc_cls_graphic_asm );
    }
    
}

void cpc_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textHScrollLine, src_hw_cpc_hscroll_line_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LD A, (%s)", y->realName );
    outline0("LD B, A");
    outline1("LD A, 0x%2.2x", (unsigned char)(_direction));
    outline1("LD IYL, 0x%2.2x", (unsigned char)(_overlap));
    outline0("CALL HSCROLLLINE");

}

void cpc_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textHScrollScreen, src_hw_cpc_hscroll_screen_asm );

    outline1("LD A, 0x%2.2x", (unsigned char)(_direction));
    outline1("LD IYL, 0x%2.2x", (unsigned char)(_overlap));
    outline0("CALL HSCROLLSCREEN");

}

void cpc_back( Environment * _environment ) {

}

void cpc_cline( Environment * _environment, char * _characters ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( textCline, src_hw_cpc_cline_asm );

    if ( _characters ) {
        outline1("LD A, (%s)", _characters);
    } else {
        outline0("LD A, 0");
    }
    outline0("CALL CLINE");

}

int cpc_image_size( Environment * _environment, int _width, int _height, int _mode ) {

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

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case BITMAP_MODE_GRAPHIC0:

            return 3 + ( 3 + ( ( _width >> 1 ) * _height ) + 16 ) * _frames;

        case BITMAP_MODE_GRAPHIC1:
        case BITMAP_MODE_GRAPHIC3:

            return 3 + ( 3 + ( ( _width >> 2 ) * _height ) + 4 ) * _frames;

        case BITMAP_MODE_GRAPHIC2:

            return 3 + ( 3 + ( ( _width >> 3 ) * _height ) + 2 ) * _frames;
    }

    return 0;

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case BITMAP_MODE_GRAPHIC0:

            return 3 + ( ( 3 + ( ( _width >> 1 ) * _height ) + 16 ) * _frames ) * _sequences;

        case BITMAP_MODE_GRAPHIC1:
        case BITMAP_MODE_GRAPHIC3:

            return 3 + ( ( 3 + ( ( _width >> 2 ) * _height ) + 4 ) * _frames ) * _sequences;

        case BITMAP_MODE_GRAPHIC2:

            return 3 + ( ( 3 + ( ( _width >> 3 ) * _height ) + 2 ) * _frames ) * _sequences;
    }

    return 0;

}

static Variable * cpc_image_converter_bitmap_mode_hires( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }
    
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
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 2 );
            mergedCommonPalette = 2;
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

    int bufferSize = cpc_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );

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
                for( int i=(_transparent_color)?1:0; i<lastUsedSlotInCommonPalette; ++i ) {
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

    if ( _environment->freeImageWidth ) {
        if ( _width % 4 ) {
            _width = ( ( ( _width - 1 ) / 4 ) - 1 ) * 4;
        }
        if ( _frame_width % 4 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 4 ) - 1 ) * 4;
        }
    }

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
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 4 );
            mergedCommonPalette = 4;
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

    int bufferSize = cpc_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC1 );
    
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
                for( int i=(_transparent_color)?1:0; i<lastUsedSlotInCommonPalette; ++i ) {
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

            bitmask = ( ( colorIndex & 0x2 ) >> 1 ) << (3 - ((image_x & 0x3)));
            bitmask |= ( ( ( colorIndex & 0x1 ) ) << 4 ) << (3 - ((image_x & 0x3)));

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
    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 1 ) = hwIndex;

    if ( lastUsedSlotInCommonPalette > 2 ) {
        hwIndex = commonPalette[2].hardwareIndex;
    } else {
        hwIndex = 0xff;
    }
    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 ) = hwIndex;

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

    if ( _environment->freeImageWidth ) {
        if ( _width % 2 ) {
            _width = ( ( ( _width - 1 ) / 2) - 1 ) * 2;
        }
        if ( _frame_width % 2 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 2 ) - 1 ) * 2;
        }
    }

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
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 16 );
            mergedCommonPalette = 16;
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

    int bufferSize = cpc_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC0 );
    
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
                for( int i=(_transparent_color)?1:0; i<lastUsedSlotInCommonPalette; ++i ) {
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

static void cpc_load_image_address_to_hl( Environment * _environment, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    outline1("LD HL, %s", _source );
    if ( _sequence ) {

        outline0("LD DE, 0x0003" );
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
            outline0("LD DE, 0x0003" );
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

static void cpc_load_image_address_to_register( Environment * _environment, char * _register, Resource * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( !_sequence && !_frame ) {
        if ( _source->isAddress ) {
            outline1("LD HL, (%s)", _source->realName );
        } else {
            outline1("LD HL, %s", _source->realName );
        }
    } else {
        if ( _source->isAddress ) {
            outline1("LD HL, (%s)", _source->realName );
        } else {
            outline1("LD HL, %s", _source->realName );
        }

        if ( _sequence ) {
            outline0("LD DE, $0003" );
            outline0("ADD HL, DE" );
            if ( strlen(_sequence) == 0 ) {

            } else {
                outline1("LD A, (%s)", _sequence );
                outline0("PUSH HL" );
                outline0("POP IX" );
                if ( _frame_size ) {
                    outline1("CALL fs%4.4xoffsetsequence", _frame_size * _frame_count );
                } else {
                    outline1("CALL %soffsetsequence", _source->realName );
                }
            }
            if ( _frame ) {
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline1("LD A, (%s)", _frame );
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    if ( _frame_size ) {
                        outline1("CALL fs%4.4xoffsetframe", _frame_size );
                    } else {
                        outline1("CALL %soffsetframe", _source->realName );
                    }

                }
            }

        } else {

            if ( _frame ) {
                outline0("LD DE, $0003" );
                outline0("ADD HL, DE" );
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    outline1("LD A, (%s)", _frame );
                    if ( _frame_size ) {
                        outline1("CALL fs%4.4xoffsetframe", _frame_size );
                    } else {
                        outline1("CALL %soffsetframe", _source->realName );
                    }
                }
            }

        }

    }
    if ( _register ) {
        outline1("LD (%s), HL", _register );
    }

}

void cpc_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( putimage, src_hw_cpc_put_image_asm );

    MAKE_LABEL

    if ( _frame_size ) {
        cpc_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
    }

    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _x, "1") );
    outline0("LD IXL, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline0("PUSH HL" );
    outline1("LD HL, %s", _flags );
    outline0("LD A, L" );
    outline0("LD (IMAGEF), A" );
    outline0("LD A, H" );
    outline0("LD (IMAGET), A" );
    outline0("POP HL" );

    outline0("CALL PUTIMAGE");

}

void cpc_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( blitimage, src_hw_cpc_blit_image_asm );

    if ( _source_count > 2 ) {
        CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    }

    MAKE_LABEL

    outhead1("blitimage%s:", label);
    if ( _source_count > 0 ) {
        Resource resource;
        resource.realName = strdup( _sources[0] );
        resource.type = VT_IMAGE;
        resource.isAddress = 0;
        cpc_load_image_address_to_register( _environment, NULL, &resource, _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LD HL, 0" );
    }

    outline0("DI");
    outline0("EXX");
    outline0("EI");

    if ( _source_count > 1 ) {
        Resource resource;
        resource.realName = strdup( _sources[0] );
        resource.type = VT_IMAGE;
        resource.isAddress = 0;
        cpc_load_image_address_to_register( _environment, NULL, &resource, _sequence, _frame, _frame_size, _frame_count );
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
    outline1("LD A, 0x%2.2x", (_flags & 0Xff) );
    outline0("LD (IMAGEF), A" );
    outline1("LD A, 0x%2.2x", ((_flags>>8) & 0Xff) );
    outline0("LD (IMAGET), A" );

    outline0("CALL BLITIMAGE");

}

void cpc_wait_vbl( Environment * _environment, char * _raster_line ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( vbl, src_hw_cpc_vbl_asm);

    if ( _raster_line ) {
        Variable * raster_line = variable_retrieve_or_define( _environment, _raster_line, VT_BYTE, 255 );
        outline0("LD HL, 0x1000" );
        outline1("LD A, (%s)", raster_line->realName );
        outline0("LD E, A" );
        outline0("LD D, 0" );
        outline0("SLA E" );
        outline0("RL D" );
        outline0("SLA E" );
        outline0("RL D" );
        outline0("SLA E" );
        outline0("RL D" );
        outline0("SLA E" );
        outline0("RL D" );
        outline0("SLA E" );
        outline0("RL D" );
        outline0("SLA E" );
        outline0("RL D" );
        outline0("ADD HL, DE" );
        outline0("LD DE, HL" );
    } else {
        outline0("LD DE, 0x1000" );
    }
    outline0("CALL WAITVBL");

}

Variable * cpc_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    int size = cpc_image_size( _environment, _width, _height, _mode );

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

Variable * cpc_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = cpc_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = _frames;
    *(buffer+1) = ( _width & 0xff );
    *(buffer+2) = ( _width >> 8 ) & 0xff;
    for( int i=0; i<_frames; ++i ) {
        *(buffer+3+(i*frameSize)) = ( _width & 0xff );
        *(buffer+3+(i*frameSize)+1) = ( ( _width >> 8 ) & 0xff );
        *(buffer+3+(i*frameSize)+2) = ( _height & 0xff );
    }

    result->valueBuffer = buffer;
    result->frameSize = frameSize;
    result->size = size;
    result->frameCount = _frames;

    return result;

}

Variable * cpc_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    int size2 = calculate_sequence_size( _environment, _sequences, _frames, _width, _height, _mode );
    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = cpc_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_SEQUENCE, "(new sequence)" );

    char * buffer = malloc ( size2 );
    memset( buffer, 0, size2 );

    *(buffer) = _frames;
    *(buffer+1) = _width;
    *(buffer+2) = _sequences;
    for( int i=0; i<(_frames*_sequences); ++i ) {
        *(buffer+3+(i*frameSize)) = ( _width & 0xff );
        *(buffer+3+(i*frameSize)+1) = ( ( _width >> 8 ) & 0xff );
        *(buffer+3+(i*frameSize)+2) = ( _height & 0xff );
    }

    result->valueBuffer = buffer;
    result->frameSize = frameSize;
    result->size = size2;
    result->frameCount = _frames;

    return result;

}

void cpc_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( getimage, src_hw_cpc_get_image_asm );

    MAKE_LABEL

    cpc_load_image_address_to_hl( _environment, _image, _sequence, _frame, _frame_size, _frame_count );

    outline1("LD A, (%s)", _x );
    outline0("LD IYL, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _x, "1") );
    outline0("LD IYH, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, 0x%2.2x", _palette );
    outline0("LD IXH, A" );

    outline0("CALL GETIMAGE");

}

void cpc_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( vic2vars, src_hw_cpc_vars_asm);
    deploy( scroll, src_hw_cpc_scroll_asm);
    deploy( textHScrollLine, src_hw_cpc_hscroll_line_asm );
    deploy( textHScrollScreen, src_hw_cpc_hscroll_screen_asm );
    deploy_preferred( vScrollTextDown, src_hw_cpc_vscroll_text_down_asm );
    deploy_preferred( vScrollTextUp, src_hw_cpc_vscroll_text_up_asm );

    outline1("LD A, 0x%2.2x", (unsigned char)(_dx&0xff) );
    outline0("LD B, A" );
    outline1("LD A, 0x%2.2x", (unsigned char)(_dy&0xff) );
    outline0("LD C, A" );
    outline0("CALL SCROLL");

}

void cpc_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
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

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( duff, src_hw_z80_duff_asm );
    deploy( sliceimagecopy, src_hw_cpc_slice_image_copy_asm );

    MAKE_LABEL

    Resource resource;
    resource.realName = strdup( _image );
    resource.type = VT_IMAGE;
    cpc_load_image_address_to_register( _environment, "HL", &resource, _sequence, _frame, _frame_size, _frame_count );

    outline1( "LD DE, %s", _destination );

    outline0("CALL SLICEIMAGECOPY");

}

void cpc_slice_image_extract( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( duff, src_hw_z80_duff_asm );
    deploy( sliceimageextract, src_hw_cpc_slice_image_extract_asm );

    MAKE_LABEL

    Resource resource;
    resource.realName = strdup( _image );
    resource.type = VT_IMAGE;
    cpc_load_image_address_to_register( _environment, "HL", &resource, _sequence, _frame, _frame_size, _frame_count );

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

    _environment->sysCallUsed = 1;

    outline0("PUSH HL" );
    outline0("LD HL, SYSCALL0" );
    outline0("INC HL" );
    outline1("LD (HL), 0x%2.2x", (_destination & 0xff ) );
    outline0("INC HL" );
    outline1("LD (HL), 0x%2.2x", ((_destination>>8) & 0xff ) );
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

void cpc_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_z80_timer_asm);

    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("LD A, 1" );
    outline0("LD C, A" );
    outline0("CALL TIMERSETSTATUS" );

}

void cpc_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_z80_timer_asm);

    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("LD A, 0" );
    outline0("LD C, A" );
    outline0("CALL TIMERSETSTATUS" );


}

void cpc_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    deploy( timer, src_hw_z80_timer_asm);

    if ( _counter ) {
        outline1("LD A, (%s)", _counter );
        outline0("LD IXL, A" );
        outline1("LD A, (%s)", address_displacement( _environment, _counter, "1" ) );
        outline0("LD IXH, A" );
    } else {
        outline0("LD IX, 0" );
    }
    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("CALL TIMERSETCOUNTER" );

}

void cpc_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    deploy( timer, src_hw_z80_timer_asm);

    if ( _init ) {
        outline1("LD A, (%s)", _init );
        outline0("LD IXL, A" );
        outline1("LD A, (%s)", address_displacement( _environment, _init, "1" ) );
        outline0("LD IXH, A" );
    } else {
        outline0("LD IX, 0" );
    }
    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("CALL TIMERSETINIT" );

}

void cpc_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    deploy( timer, src_hw_z80_timer_asm);

    if ( _address ) {
        outline1("LD HL, %s", _address );
        outline0("LD A, L" );
        outline0("LD IXL, A" );
        outline0("LD A, H" );
        outline0("LD IXH, A" );
    } else {
        outline0("LD IX, 0" );
    }
    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("CALL TIMERSETADDRESS" );

}

void cpc_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy( dload, src_hw_cpc_dload_asm );

    MAKE_LABEL
    
    Variable * filename = variable_retrieve( _environment, _filename );
    Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    Variable * address = NULL;
    if ( _address ) {
        address = variable_retrieve( _environment, _address );
    }
    Variable * size = NULL;
    if ( _size ) {
        size = variable_retrieve( _environment, _size );
    }
    Variable * offset = NULL;
    if ( _offset ) {
        offset = variable_retrieve( _environment, _offset );
    }

    switch( filename->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, filename->realName, tnsize->realName );
            cpu_addressof_16bit( _environment, filename->realName, tnaddress->realName );
            cpu_inc_16bit( _environment, tnaddress->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, filename->realName, tnaddress->realName, tnsize->realName );
            break;
    }

    outline1("LD HL, (%s)", tnaddress->realName);
    outline1("LD A, (%s)", tnsize->realName);
    outline0("LD B, A");

    if ( address ) {

        outline1("LD DE, (%s)", address->realName);

    }

    outline0("CALL CPCDLOAD");

}

void cpc_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy( dsave, src_hw_cpc_dsave_asm );

    MAKE_LABEL
    
    Variable * filename = variable_retrieve( _environment, _filename );
    Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    Variable * address = NULL;
    if ( _address ) {
        address = variable_retrieve( _environment, _address );
    }
    Variable * size = NULL;
    if ( _size ) {
        size = variable_retrieve( _environment, _size );
    }
    Variable * offset = NULL;
    if ( _offset ) {
        offset = variable_retrieve( _environment, _offset );
    }

    switch( filename->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, filename->realName, tnsize->realName );
            cpu_addressof_16bit( _environment, filename->realName, tnaddress->realName );
            cpu_inc_16bit( _environment, tnaddress->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, filename->realName, tnaddress->realName, tnsize->realName );
            break;
    }

    outline1("LD HL, (%s)", tnaddress->realName);
    outline1("LD A, (%s)", tnsize->realName);
    outline0("LD B, A");

    if ( address ) {

        outline1("LD DE, (%s)", address->realName);

    }

    if ( size ) {

        outline1("LD IX, (%s)", size->realName);

    }

    outline0("CALL CPCDSAVE");

}

void cpc_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( !_sequence && !_frame ) {
        outline0("LD HL, 0" );
    } else {
        outline0("LD HL, 0" );

        if ( _sequence ) {
            outline0("LD DE, 0x0003" );
            outline0("ADD HL, DE" );
            if ( strlen(_sequence) == 0 ) {

            } else {
                outline1("LD A, (%s)", _sequence );
                outline0("PUSH HL" );
                outline0("POP IX" );
                outline1("CALL OFFSETS%4.4X", _frame_count * _frame_size );
            }
            if ( _frame ) {
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline1("LD A, (%s)", _frame );
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    outline1("CALL OFFSETS%4.4X", _frame_size );
                }
            }

        } else {

            if ( _frame ) {
                outline0("LD DE, 0x0003" );
                outline0("ADD HL, DE" );
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    outline1("LD A, (%s)", _frame );
                    outline1("CALL OFFSETS%4.4X", _frame_size );
                }
            }

        }

    }
    outline1("LD (%s), HL", _offset );

}

void cpc_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

    // deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    // deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );

    // MAKE_LABEL

    // if ( _direction & FLAG_FLIP_X ) {
    //     cpc_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
    //     deploy( flipimagex, src_hw_cpc_flip_image_x_asm );
    //     outline0("CALL FLIPIMAGEX");
    // } 
    
    // if ( _direction & FLAG_FLIP_Y ) {
    //     ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
    //     deploy( flipimagey, src_hw_cpc_flip_image_y_asm );
    //     outline0("CALL FLIPIMAGEY");
    // }

}


void cpc_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_cpc_keyboard_asm);

    outline1("LD HL, (%s)", _string );
    outline1("LD A, (%s)", _size );
    outline0("LD C, A" );
    outline0("CALL PUTKEY" );

}

void cpc_fade( Environment * _environment, char * _ticks ) {

    deploy_preferred( cpcvars, src_hw_cpc_vars_asm);
    deploy( cpcvarsGraphic, src_hw_cpc_vars_graphic_asm );
    deploy( fade, src_hw_cpc_fade_asm );

    outline0( "DI" );
    outline0( "LD A, 0" );
    outline0( "LD (FADESTEP), A" );
    outline1( "LD HL, (%s)", _ticks );
    outline0( "LD (FADEDURATION), HL" );
    outline0( "LD (FADERESETDURATION), HL" );
    outline0( "EI" );

}
#endif