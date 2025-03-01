/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
        { 0xff, 0xff, 0xff, 0xff, 0, "WHITE", 0 },
        { 0xa0, 0xa0, 0xa0, 0xff, 1, "LIGHT GRAY", 1 },
        { 0x50, 0x50, 0x50, 0xff, 2, "DARK GRAY", 2 },
        { 0x00, 0x00, 0x00, 0xff, 3, "BLACK", 3 }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __gb__

void gb_joy( Environment * _environment, int _port, char * _value ) {

    deploy( joystick, src_hw_gb_joystick_asm );

    outline0("CALL JOYSTICKREAD0" );

    outline1("LD (%s), A", _value);

}

void gb_joy_vars( Environment * _environment, char * _port, char * _value ) {

    deploy( joystick, src_hw_gb_joystick_asm );

    outline0("CALL JOYSTICKREAD0" );

    outline1("LD (%s), A", _value);

}

void gb_inkey( Environment * _environment, char * _key ) {

    outline0("LD A, 255");
    outline1("LD (%s), A", _key);

}

void gb_wait_key( Environment * _environment, int _release ) {
   
}

void gb_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    deploy( joystick, src_hw_gb_joystick_asm );

    outline1("LD B, $%2.2x", _release );
    outline0("CALL WAITFIRE" );

}

void gb_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    deploy( joystick, src_hw_gb_joystick_asm );

    outline1("LD B, $%2.2x", _release );
    outline0("CALL WAITFIRE" );
   
}

void gb_wait_fire( Environment * _environment, int _port, int _release ) {

    deploy( joystick, src_hw_gb_joystick_asm );

    outline1("LD B, $%2.2x", _release );
    outline0("CALL WAITFIRE" );
  
}

void gb_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    deploy( joystick, src_hw_gb_joystick_asm );

    outline1("LD B, $%2.2x", _release );
    outline0("CALL WAITFIRE" );

}

void gb_key_state( Environment * _environment, char *_scancode, char * _result ) {

    outline0("LD A, 0");
    outline1("LD (%s), A", _result);

}

void gb_scancode( Environment * _environment, char * _result ) {

    outline0("LD A, 255");
    outline1("LD (%s), A", _result);
   
}

void gb_asciicode( Environment * _environment, char * _result ) {

    outline0("LD A, 0");
    outline1("LD (%s), A", _result);
   
}

void gb_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    outline0("LD A, 255");
    outline1("LD (%s), A", _scancode);
    outline0("LD A, 0");
    outline1("LD (%s), A", _result);

}


void gb_scanshift( Environment * _environment, char * _shifts ) {

    outline0("LD A, 0");
    outline1("LD (%s), A", _shifts);

}

void gb_keyshift( Environment * _environment, char * _shifts ) {

    outline0("LD A, 0");
    outline1("LD (%s), A", _shifts);

}

void gb_clear_key( Environment * _environment ) {

}

void gb_sys_call( Environment * _environment, int _destination ) {

    outline1("CALL $%4.4x", _destination );

}

void gb_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_sm83_timer_asm);

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

void gb_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_sm83_timer_asm);

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

void gb_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    deploy( timer, src_hw_sm83_timer_asm);

    if ( _counter ) {
        outline1("LD A, (%s)", _counter );
        outline0("LD (IXLR), A" );
        outline1("LD A, (%s)", address_displacement( _environment, _counter, "1" ) );
        outline0("LD (IXHR), A" );
    } else {
        outline0("LD A, 0" );
        outline0("LD (IXLR), A" );
        outline0("LD (IXHR), A" );
    }
    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("CALL TIMERSETCOUNTER" );

}

void gb_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    deploy( timer, src_hw_sm83_timer_asm);

    if ( _init ) {
        outline1("LD A, (%s)", _init );
        outline0("LD (IXLR), A" );
        outline1("LD A, (%s)", address_displacement( _environment, _init, "1" ) );
        outline0("LD (IXHR), A" );
    } else {
        outline0("LD A, 0" );
        outline0("LD (IXLR), A" );
        outline0("LD (IXHR), A" );
    }
    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("CALL TIMERSETINIT" );

}

void gb_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    deploy( timer, src_hw_sm83_timer_asm);

    if ( _address ) {
        outline1("LD HL, %s", _address );
        outline0("LD A, L" );
        outline0("LD (IXLR), A" );
        outline0("LD A, H" );
        outline0("LD (IXHR), A" );
    } else {
        outline0("LD A, 0" );
        outline0("LD (IXLR), A" );
        outline0("LD (IXHR), A" );
    }
    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD B, A" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("CALL TIMERSETADDRESS" );

}

void gb_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

}

void gb_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

}


void gb_put_key(  Environment * _environment, char *_string, char * _size ) {

}

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * gb_image_nearest_system_color( RGBi * _color ) {

    unsigned int minDistance = 0xffff;
    int colorIndex = 0;
    for (int j = 0; j < COLOR_COUNT; ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], _color);
        if ( _color->alpha < 255 ) {
            if ( rgbi_equals_rgb( &SYSTEM_PALETTE[j], _color ) ) {
                minDistance = 0;
                distance = 0;
                colorIndex = j;
            }
        } else {
            if ( SYSTEM_PALETTE[j].alpha < 255 ) {
                continue;
            }
            if (distance < minDistance) {
                minDistance = distance;
                colorIndex = j;
            }
        }
    }

    return &SYSTEM_PALETTE[colorIndex];

}

/**
 * This method can be used to convert 
 *     8x8 RGB (3/4 bytes) pixel (_source) [8x8x3/4 = 192/256 bytes]
 * into 
 *     8x8 bitmap (2 bit) pixel [8x2 = 16 bytes]
 *       foreground and background color encoded (_dest)
 * 
 * Since the 8x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze.
 */
static void gb_image_converter_tile( Environment * _environment, char * _source, char * _dest, int _width, int _depth, int _source_width ) {

    char * source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(source + 3);
            } else {
                rgb.alpha = 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            RGBi *systemRgb = gb_image_nearest_system_color( &rgb );

            char bitmask = 1 << ( 7 - ((x) & 0x7) );
            int pos0 = ( y * 2 );
            int pos1 = ( y * 2 + 1 );

            if ( systemRgb->index & 0x01 ) {
                *( _dest + pos0 ) |= bitmask;
            } else {
                *( _dest + pos0 ) &= ~bitmask;
            }

            if ( systemRgb->index & 0x02 ) {
                *( _dest + pos1 ) |= bitmask;
            } else {
                *( _dest + pos1 ) &= ~bitmask;
            }

            adilinepixel(systemRgb->index);

            source += _depth;

        }
        
        source += _depth * ( _source_width - 8 );

    }

}

/**
 * @brief <i>GB</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * gb_collision( Environment * _environment, char * _sprite ) {

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(collision)" );

    return result;
    
}

/**
 * @brief <i>GB</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void gb_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>GB</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void gb_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>GB</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color( Environment * _environment, int _index, int _background_color ) {

    int colorIndex = _index & 0x03;
    int colorValue = _background_color & 0x03;

    int raw = ( colorValue ) << ( colorIndex * 2 );
    int notRaw = ~ ( 3 << ( colorIndex * 2 ) );

    outline1("LD B, $%2.2x", raw);
    outline0("LD A, ($FF47)");
    outline1("AND $%2.2x", notRaw);
    outline1("OR $%2.2x", raw);
    outline0("LD ($FF47), A");

}

/**
 * @brief <i>GB</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    MAKE_LABEL

    outline0("LD A, 3");
    outline0("PUSH AF");
    outline1("LD A, (%s)", _index);
    outline0("AND $03");
    outline0("CP 0");
    outline0("POP AF");
    outline1("JR Z, %snorotm", label);
    outline1("LD A, (%s)", _index);
    outline0("AND $03");
    outline0("LD C, A");
    outline0("LD A, 3");
    outhead1("%srotm:", label);
    outline0("SLA A");
    outline0("SLA A");
    outline0("DEC C");
    outline1("JR NZ, %srotm", label);
    outhead1("%snorotm:", label);
    outline0("XOR $FF");
    outline0("LD B, A");
    outline1("LD A, (%s)", _background_color);
    outline0("AND $03");
    outline0("LD D, A");
    outline1("LD A, (%s)", _index);
    outline0("CP 0");
    outline1("JR Z, %snorot", label);
    outline0("LD C, A");
    outline1("LD A, (%s)", _background_color);
    outline0("AND $03");
    outhead1("%srot:", label);
    outline0("SLA A");
    outline0("SLA A");
    outline0("DEC C");
    outline1("JR NZ, %srot", label);
    outline0("LD D, A");
    outhead1("%snorot:", label);
    outline0("LD A, ($FF47)");
    outline0("AND B");
    outline0("OR D");
    outline0("LD ($FF47), A");

}

/**
 * @brief <i>GB</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    int colorIndex = _index & 0x03;

    int notRaw = ~ ( 3 << ( colorIndex * 2 ) );

    outline1("LD A, (%s)", _background_color);
    outline0("AND $03");
    for( int i=0; i<colorIndex; ++i ) {
        outline0("SLA A");
    }
    outline0("LD B, A");
    outline0("LD A, ($FF47)");
    outline1("AND $%2.2x", notRaw);
    outline0("OR B");
    outline0("LD ($FF47), A");

}

/**
 * @brief <i>GB</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

    MAKE_LABEL

    outline0("LD A, 3");
    outline0("PUSH AF");
    outline1("LD A, (%s)", _index);
    outline0("AND $03");
    outline0("CP 0");
    outline0("POP AF");
    outline1("JR Z, %snorotm", label);
    outline1("LD A, (%s)", _index);
    outline0("AND $03");
    outline0("LD C, A");
    outline0("LD A, 3");
    outhead1("%srotm:", label);
    outline0("SLA A");
    outline0("SLA A");
    outline0("DEC C");
    outline1("JR NZ, %srotm", label);
    outhead1("%snorotm:", label);
    outline0("LD B, A");
    outline0("LD A, ($FF47)");
    outline0("AND B");
    outline0("LD D, A");
    outline1("LD A, (%s)", _index);
    outline0("CP 0");
    outline1("JR Z, %snorot", label);
    outline0("LD C, A");
    outline0("LD A, D");
    outhead1("%srot:", label);
    outline0("SRA A");
    outline0("SRA A");
    outline0("DEC C");
    outline1("JR NZ, %srot", label);
    outline0("LD D, A");
    outhead1("%snorot:", label);
    outline0("LD A, D");
    outline1("LD (%S), A", _background_color);

}

/**
 * @brief <i>GB</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void gb_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>GB</i>: emit code to set raster irq
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
void gb_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>GB</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void gb_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>GB</i>: emit code to wait for next raster irq at different position
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
void gb_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

void gb_bank_select( Environment * _environment, int _bank ) {
    
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
            colorIndex = j;
        }
    }

    return colorIndex;

}

int gb_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    cpu_store_8bit( _environment, "_PEN", _environment->defaultPenColor );
    cpu_store_8bit( _environment, "_PAPER", _environment->defaultPaperColor );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 20;
    _environment->screenTilesHeight = 18;
    _environment->screenTiles = 255;
    _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
    _environment->screenColors = 4;
    _environment->currentModeBW = 0;

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
    cpu_store_8bit( _environment, "CURRENTTILESWIDTHX8", _environment->screenTilesWidth * 8 );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );
    cpu_store_8bit( _environment, "CONSOLEX1", 0 );
    cpu_store_8bit( _environment, "CONSOLEY1", 0 );
    cpu_store_8bit( _environment, "CONSOLEX2", _environment->consoleTilesWidth-1 );
    cpu_store_8bit( _environment, "CONSOLEY2", _environment->consoleTilesHeight-1 );
    cpu_store_8bit( _environment, "CONSOLEW", _environment->consoleTilesWidth );
    cpu_store_8bit( _environment, "CONSOLEH", _environment->consoleTilesHeight );

    console_calculate( _environment );
    
    if (_environment->vestigialConfig.clsImplicit ) {
        gb_cls( _environment );
    }

}

void console_calculate( Environment * _environment ) {

    int startAddress = 0x9800;

    int consoleSA = startAddress + ( _environment->activeConsole.y1 * _environment->screenTilesWidth ) + _environment->activeConsole.x1;
    int consoleWB = _environment->activeConsole.width * _environment->currentModeBW;
    int consoleHB = _environment->activeConsole.height * 8;

    cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    outline0( "CALL CONSOLECALCULATE" );

}

void gb_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        gb_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        if (_environment->vestigialConfig.clsImplicit ) {
            gb_cls( _environment );
        }

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gb_bitmap_disable( Environment * _environment ) {

}

void gb_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        gb_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        if (_environment->vestigialConfig.clsImplicit ) {
            gb_cls( _environment );
        }

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gb_bitmap_at( Environment * _environment, char * _address ) {

}

void gb_colormap_at( Environment * _environment, char * _address ) {

}

void gb_textmap_at( Environment * _environment, char * _address ) {

}

void gb_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

}

void gb_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

}

void gb_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

}

void gb_screen_on( Environment * _environment ) {

    outline0("LD A, (rLCDC)");
    outline0("OR $80");
    outline0("LD (rLCDC), A");

}

void gb_screen_off( Environment * _environment ) {

    outline0("LD A, (rLCDC)");
    outline0("OR $7F");
    outline0("LD (rLCDC), A");

}

void gb_screen_rows( Environment * _environment, char * _rows ) {

}

void gb_screen_columns( Environment * _environment, char * _columns ) {

}

void gb_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * address = variable_retrieve_or_define( _environment, _address, VT_BYTE, 0 );

    deploy( sprite, src_hw_gb_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline1("LD A, (%s)", address->realName );
    outline0("CALL SPRITEDATASET");

}

void gb_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * image = variable_retrieve_or_define( _environment, _image, VT_IMAGE, 0 );

    deploy( sprite, src_hw_gb_sprites_asm );
    
    char dataLabel[MAX_TEMPORARY_STORAGE]; sprintf( dataLabel, "%sdata", image->realName );
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    sprintf(dataLabel, "%sdata", image->realName);
    outline1("LD HL, %s", dataLabel );
    outline0("CALL SPRITEDATAFROM");

}

void gb_sprite_enable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_gb_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline0("CALL SPRITEENABLE");

}

void gb_sprite_disable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_gb_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline0("CALL SPRITEDISABLE");

}

void gb_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( sprite, src_hw_gb_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", y->realName );
    outline0("LD E, A");
    outline0("CALL SPRITEAT");

}

void gb_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void gb_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void gb_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void gb_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void gb_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void gb_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void gb_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void gb_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void gb_tiles_at( Environment * _environment, char * _address ) {

}

void gb_vertical_scroll( Environment * _environment, char * _displacement ) {

    outline1("LD A, (%s)", _displacement);
    outline0("CALL WAITSTATE");
    outline0("LD (rSCY), A");

}

void gb_horizontal_scroll( Environment * _environment, char * _displacement ) {

    outline1("LD A, (%s)", _displacement);
    outline0("CALL WAITSTATE");
    outline0("LD (rSCX), A");

}

void gb_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LD C, (%s)", _timing);
    outhead1("%sfirst:", label);
    outline0("CALL WAITVBL");
    outline0("DEC C");
    outline1("JP NZ, %sfirst", label);

}

void gb_get_width( Environment * _environment, char *_result ) {

    outline0("LD HL, 160" );
    outline1("LD (%s), HL", _result );

}

void gb_tiles_get( Environment * _environment, char *_result ) {

    outline0("LD A, 255" );
    outline1("LD (%s), A", _result );

}

void gb_get_height( Environment * _environment, char *_result ) {

    outline0("LD HL, 144" );
    outline1("LD (%s), HL", _result );

}

void gb_cls( Environment * _environment ) {
    
    deploy( clsText, src_hw_gb_cls_asm );
    outline0("CALL CLS");

}

void gb_scroll_text( Environment * _environment, int _direction, int _overlap ) {

    if ( _direction > 0 ) {
        deploy( vScrollTextDown, src_hw_gb_vscroll_text_down_asm );
        outline0("CALL VSCROLLTDOWN");
    } else {
        deploy( vScrollTextUp, src_hw_gb_vscroll_text_up_asm );
        outline0("CALL VSCROLLTUP");
    }

}

void gb_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy( gbvars, src_hw_gb_vars_asm );

    deploy( vScrollTextUp, src_hw_gb_vscroll_text_up_asm );

    outline1("LD HL, (%s)", _text);
    outline0("PUSH HL");
    outline0("POP DE");
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    if ( _raw ) {

        // deploy( clsGraphic, src_hw_gb_cls_graphic_asm );
        // deploy( textEncodedAt, src_hw_gb_text_asm );
        // deploy( textEncodedAtGraphicRaw, src_hw_gb_text_at_raw_asm );
        outline0("CALL TEXTATBITMAPMODERAW");

    } else {

        // deploy( clsGraphic, src_hw_gb_cls_graphic_asm );
        // deploy( textEncodedAt, src_hw_gb_text_asm );
        deploy( textEncodedAtGraphic, src_hw_gb_text_at_asm );
        outline0("CALL TEXTATBITMAPMODE");

    }

}

void gb_initialization( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    // // deploy( GBvars, src_hw_gb_vars_asm );
    // deploy_preferred( GBstartup, src_hw_gb_startup_asm );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 192  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESWIDTHX8", VT_WORD, 320 );
    variable_global( _environment, "CURRENTTILESWIDTHX8" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 24 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    variable_import( _environment, "TILESETSLOTFIRST", VT_BYTE, 1 );
    variable_global( _environment, "TILESETSLOTFIRST" );
    variable_import( _environment, "TILESETSLOTLAST", VT_BYTE, 1 );
    variable_global( _environment, "TILESETSLOTLAST" );

    variable_import( _environment, "PUTIMAGECOUNT", VT_BYTE, 0 );
    variable_global( _environment, "PUTIMAGECOUNT" );
    variable_import( _environment, "PUTIMAGEWIDTH", VT_BYTE, 0 );
    variable_global( _environment, "PUTIMAGEWIDTH" );
    variable_import( _environment, "PUTIMAGEINDEX", VT_BYTE, 0 );
    variable_global( _environment, "PUTIMAGEINDEX" );
    variable_import( _environment, "PUTIMAGETILEINDEX", VT_BYTE, 0 );
    variable_global( _environment, "PUTIMAGETILEINDEX" );
    variable_import( _environment, "PUTIMAGEX", VT_BYTE, 0 );
    variable_global( _environment, "PUTIMAGEX" );

    variable_import( _environment, "IMAGEX", VT_POSITION, 0 );
    variable_global( _environment, "IMAGEX" );    
    variable_import( _environment, "IMAGEY", VT_POSITION, 0 );
    variable_global( _environment, "IMAGEY" );    

    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x9800 );
    variable_global( _environment, "TEXTADDRESS" );    

    SCREEN_MODE_DEFINE( TILEMAP_MODE_BGB, 0, 20, 18, 2, 8, 8, "Tilemap mode (BGB)" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_CGB, 0, 20, 18, 4, 8, 8, "Tilemap mode (CGB)" );

    variable_import( _environment, "LINE", VT_WORD, 0 );
    variable_global( _environment, "LINE" );

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );

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

    variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    variable_global( _environment, "TABSTODRAW" );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "SPRITECOUNT", VT_SPRITE, 0 );
    variable_global( _environment, "SPRITECOUNT" );

    variable_import( _environment, "GBMUSICREADY", VT_BYTE, 0 );
    variable_global( _environment, "GBMUSICREADY" );
    variable_import( _environment, "GBMUSICPAUSE", VT_BYTE, 0 );
    variable_global( _environment, "GBMUSICPAUSE" );
    variable_import( _environment, "GBMUSICLOOP", VT_BYTE, 0 );
    variable_global( _environment, "GBMUSICLOOP" );
    variable_import( _environment, "GBBLOCKS", VT_BYTE, 0 );
    variable_global( _environment, "GBBLOCKS" );
    variable_import( _environment, "GBLASTBLOCK", VT_BYTE, 0 );
    variable_global( _environment, "GBLASTBLOCK" );
    variable_import( _environment, "GBTMPPTR2", VT_ADDRESS, 0 );
    variable_global( _environment, "GBTMPPTR2" );
    variable_import( _environment, "GBTMPPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "GBTMPPTR" );
    variable_import( _environment, "GBTMPOFS", VT_BYTE, 0 );
    variable_global( _environment, "GBTMPOFS" );
    variable_import( _environment, "GBTMPLEN", VT_BYTE, 0 );
    variable_global( _environment, "GBTMPLEN" );
    variable_import( _environment, "GBJIFFIES", VT_BYTE, 0 );
    variable_global( _environment, "GBJIFFIES" );

    variable_import( _environment, "GBBLOCKS_BACKUP", VT_BYTE, 0 );
    variable_global( _environment, "GBBLOCKS_BACKUP" );
    variable_import( _environment, "GBLASTBLOCK_BACKUP", VT_BYTE, 0 );
    variable_global( _environment, "GBLASTBLOCK_BACKUP" );
    variable_import( _environment, "GBTMPPTR_BACKUP", VT_ADDRESS, 0 );
    variable_global( _environment, "GBTMPPTR_BACKUP" );

    variable_import( _environment, "GBTIMER", VT_WORD, 0 );
    variable_global( _environment, "GBTIMER" );
    variable_import( _environment, "GBAUDIOTIMERS", VT_BUFFER, 8 );
    variable_global( _environment, "GBAUDIOTIMERS" );

    // variable_import( _environment, "SPRITEXY", VT_BUFFER, SPRITE_COUNT * 2 );
    // variable_global( _environment, "SPRITEXY" );

    // variable_import( _environment, "XSCROLLPOS", VT_BYTE, 0 );
    // variable_global( _environment, "XSCROLLPOS" );
    // variable_import( _environment, "YSCROLLPOS", VT_BYTE, 0 );
    // variable_global( _environment, "YSCROLLPOS" );
    // variable_import( _environment, "XSCROLL", VT_BYTE, 0 );
    // variable_global( _environment, "XSCROLL" );
    // variable_import( _environment, "YSCROLL", VT_BYTE, 0 );
    // variable_global( _environment, "YSCROLL" );
    // variable_import( _environment, "DIRECTION", VT_BYTE, 0 );
    // variable_global( _environment, "DIRECTION" );

    // variable_import( _environment, "ONSCROLLUP", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLUP" );

    // variable_import( _environment, "ONSCROLLDOWN", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLDOWN" );

    // variable_import( _environment, "ONSCROLLLEFT", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLLEFT" );

    // variable_import( _environment, "ONSCROLLRIGHT", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLRIGHT" );

    // variable_import( _environment, "IMAGEF", VT_BYTE, 0 );
    // variable_global( _environment, "IMAGEF" );

    // variable_import( _environment, "IMAGET", VT_BYTE, 0 );
    // variable_global( _environment, "IMAGET" );

    // variable_import( _environment, "IMAGEY", VT_BYTE, 0 );
    // variable_global( _environment, "IMAGEY" );

    // variable_import( _environment, "BLITIMAGEBLITTINGADDR", VT_ADDRESS, 0 );
    // variable_global( _environment, "BLITIMAGEBLITTINGADDR" );
    // variable_import( _environment, "BLITTMPPTR", VT_ADDRESS, 0 );
    // variable_global( _environment, "BLITTMPPTR" );
    // variable_import( _environment, "BLITTMPPTR2", VT_ADDRESS, 0 );
    // variable_global( _environment, "BLITTMPPTR2" );

    // // #if __coleco__
    // //     variable_import( _environment, "VDP_HOOK", VT_BUFFER, 10 );
    // //     variable_global( _environment, "VDP_HOOK" );
    // // #endif

    // variable_import( _environment, "VBLFLAG", VT_BYTE, 0 );
    // variable_global( _environment, "VBLFLAG" ); 
    // variable_import( _environment, "VDPINUSE", VT_BYTE, 0 );
    // variable_global( _environment, "VDPINUSE" );

    // variable_import( _environment, "SLICEX", VT_POSITION, 0 );
    // variable_global( _environment, "SLICEX" );
    // variable_import( _environment, "SLICEY", VT_POSITION, 0 );
    // variable_global( _environment, "SLICEY" );
    // variable_import( _environment, "SLICEDTARGET", VT_POSITION, 0 );
    // variable_global( _environment, "SLICEDTARGET" );

    variable_import( _environment, "CONSOLESA", VT_ADDRESS, 0x0 );
    variable_global( _environment, "CONSOLESA" );
    variable_import( _environment, "CONSOLEHB", VT_BYTE, 0x0 );
    variable_global( _environment, "CONSOLEHB" );
    variable_import( _environment, "CONSOLEWB", VT_BYTE, 0x0 );
    variable_global( _environment, "CONSOLEWB" );

    gb_tilemap_enable( _environment, 40, 24, 1, 8, 8 );

    _environment->fontConfig.schema = FONT_SCHEMA_ASCII;

    font_descriptors_init( _environment, 0 );
    
    console_calculate( _environment );

    // _environment->currentRgbConverterFunction = rgbConverterFunction;
    // _environment->screenShades = 16;

    // outline0("CALL GBAFTERINIT");

}

void gb_finalization( Environment * _environment ) {

    // if ( _environment->vestigialConfig.clsImplicit ) {
    //     // deploy( clsText, src_hw_gb_cls_text_asm );
    // }
    
}

void gb_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

    // // deploy( textHScroll, src_hw_gb_hscroll_text_asm );

    // Variable * y = variable_retrieve( _environment, "YCURSYS" );
    // outline1("LD A, $%2.2x", ( _direction & 0xff ) );
    // outline1("LD B, (%s)", y->realName );
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL HSCROLLLT");
    // } else {
    //     outline0("CALL HSCROLLLTNMI2");
    // }

}

void gb_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

    // // deploy( textHScroll, src_hw_gb_hscroll_text_asm );

    // outline1("LD A, $%2.2x", ( _direction & 0xff ) );
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL HSCROLLST");
    // } else {
    //     outline0("CALL HSCROLLSTNMI2");
    // }

}

void gb_back( Environment * _environment ) {

    // // deploy( back, src_hw_gb_back_asm );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL BACK");
    // } else {
    //     outline0("CALL BACKNMI2");
    // }

}

void gb_cline( Environment * _environment, char * _characters ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);

    // Variable * x = variable_retrieve( _environment, "XCURSYS" );
    // Variable * y = variable_retrieve( _environment, "YCURSYS" );

    // outline1("LD A, (%s)", x->realName );
    // outline0("LD (CLINEX), A" );
    // outline1("LD A, (%s)", y->realName );
    // outline0("LD (CLINEY), A");

    // if ( _characters ) {
    //     outline1("LD A, (%s)", _characters);
    //     outline0("LD C, A");
    // } else {
    //     outline0("LD A, 0");
    //     outline0("LD C, A");
    // }

    // if ( ( _environment->currentMode == 2 || _environment->currentMode == 3 ) && !_environment->currentTileMode ) {
    //     // deploy( textClineGraphic, src_hw_gb_cline_graphic_asm );
    //     if ( ! _environment->hasGameLoop ) {
    //         outline0("CALL CLINEG");
    //     } else {
    //         outline0("CALL CLINEGGMI2");
    //     }
    // } else {
    //     // deploy( textCline, src_hw_gb_cline_text_asm );
    //     if ( ! _environment->hasGameLoop ) {
    //         outline0("CALL CLINE");
    //     } else {
    //         outline0("CALL CLINENMI2");
    //     }
    // }

}

int gb_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case TILEMAP_MODE_BGB:
        case TILEMAP_MODE_CGB: {

            int size = ( ( _width >> 3 ) * ( _height >> 3 ) );

            return 3 + size + size * 16;

            break;
        }
    }

    return 0;

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case TILEMAP_MODE_BGB:
        case TILEMAP_MODE_CGB: {

            int size = ( ( _width >> 3 ) * ( _height >> 3 ) );

            return 3 + ( 3 + size + size * 16 ) * _frames;

            break;
        }
    }

    return 0;

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case TILEMAP_MODE_BGB:
        case TILEMAP_MODE_CGB: {

            int size = ( ( _width >> 3 ) * ( _height >> 3 ) );

            return 3 + ( ( 3 + size + size * 16 ) * _frames ) * _sequences;

            break;
        }
    }

    return 0;

}

static Variable * gb_image_converter_tilemap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }
    
    if ( _environment->freeImageHeight ) {
        if ( _height % 8 ) {
            _height = ( ( ( _height - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_height % 8 ) {
            _frame_height = ( ( ( _frame_height - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(image)");

    result->locked = 1;

    // timeslot: 1 byte
    // width: 1 byte
    // size: 1 byte
    // (indexes): size bytes
    // tiles' data

    int size = ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) );

    int bufferSize = 3 + size + size * 16;

    char * buffer = malloc ( bufferSize );

    memset( buffer, 0, bufferSize );

    buffer[0] = 0xff; // force update at first PUT IMAGE
    buffer[1] = ( _frame_width >> 3 );
    buffer[2] = size;

    int cx, cy;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    for( cy=0; cy<(_frame_height >> 3);++cy) {
        for( cx=0; cx<(_frame_width >> 3);++cx) {

            int tileDataOffset = 3 + size + ( (cy * ( _frame_width >> 3 ) ) + cx ) * ( 16 );

            char * source = _source + ( ( cy * 8 * _width ) + cx * 8 ) * _depth;

            char convertedTile[16];

            gb_image_converter_tile( _environment, source, convertedTile, _width, _depth, _width );
            
            memcpy( &buffer[tileDataOffset], convertedTile, 16 );

        }

    }

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * gb_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color, int _slot_x, int _slot_y ) {

    if ( _width != 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH_EXACT( _width );
    }

    if ( _height != 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH_EXACT( _height );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(image)");

    result->locked = 1;

    int size = 1;

    int bufferSize = 3 + size + size * 16;

    char * buffer = malloc ( bufferSize );

    memset( buffer, 0, bufferSize );

    buffer[0] = 0xff;
    buffer[1] = 1;
    buffer[2] = size;

    int cx, cy;

    int tileDataOffset = 3 + size;

    char * source = _source;

    char convertedTile[16];

    gb_image_converter_tile( _environment, source, convertedTile, _width, _depth, _width );
    
    memcpy( &buffer[tileDataOffset], convertedTile, 16 );

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    result->readonly = 1;

    return result;

}

Variable * gb_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {

        case TILEMAP_MODE_BGB:
        case TILEMAP_MODE_CGB:

            return gb_image_converter_tilemap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

            break;
    }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return gb_new_image( _environment, 8, 8, TILEMAP_MODE_STANDARD );

}

static void gb_load_image_address_to_other_register( Environment * _environment, char * _register, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    // outline1("LD HL, %s", _source );
    // if ( _sequence ) {

    //     outline0("LD DE, $0003" );
    //     outline0("ADD HL, DE" );
    //     if ( strlen(_sequence) == 0 ) {

    //     } else {
    //         outline0("PUSH HL" );
    //         outline1("LD A, (%s)", _sequence );
    //         outline0("LD L, A" );
    //         outline0("LD H, 0" );
    //         outline0("ADD HL, HL" );
    //         outline0("LD DE, HL" );
    //         outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
    //         outline0("ADD HL, DE" );
    //         outline0("LD A, (HL)" );
    //         outline0("LD E, A" );
    //         outline0("INC HL" );
    //         outline0("LD A, (HL)" );
    //         outline0("LD D, A" );
    //         outline0("POP HL" );
    //         outline0("ADD HL, DE" );
    //     }

    //     if ( _frame ) {
    //         if ( strlen(_frame) == 0 ) {

    //         } else {
    //             outline0("PUSH HL" );
    //             outline1("LD A, (%s)", _frame );
    //             outline0("LD L, A" );
    //             outline0("LD H, 0" );
    //             outline0("ADD HL, HL" );
    //             outline0("LD DE, HL" );
    //             outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
    //             outline0("ADD HL, DE" );
    //             outline0("LD A, (HL)" );
    //             outline0("LD E, A" );
    //             outline0("INC HL" );
    //             outline0("LD A, (HL)" );
    //             outline0("LD D, A" );
    //             outline0("POP HL" );
    //             outline0("ADD HL, DE" );
    //         }
    //     }

    // } else {

    //     if ( _frame ) {
    //         outline0("LD DE, $0003" );
    //         outline0("ADD HL, DE" );
    //         if ( strlen(_frame) == 0 ) {

    //         } else {
    //             outline0("PUSH HL" );
    //             outline1("LD A, (%s)", _frame );
    //             outline0("LD L, A" );
    //             outline0("LD H, 0" );
    //             outline0("ADD HL, HL" );
    //             outline0("LD DE, HL" );
    //             outline1("LD HL, OFFSETS%4.4x", _frame_size );
    //             outline0("ADD HL, DE" );
    //             outline0("LD A, (HL)" );
    //             outline0("LD E, A" );
    //             outline0("INC HL" );
    //             outline0("LD A, (HL)" );
    //             outline0("LD D, A" );
    //             outline0("POP HL" );
    //             outline0("ADD HL, DE" );
    //         }
    //     }

    // }

    // if ( _register ) {
    //     outline1("LD (%s), HL", _register );
    // }

}

static void gb_load_image_address_to_register( Environment * _environment, char * _register, Resource * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( _source->isAddress ) {
        outline1("LD HL, (%s)", _source->realName );
    } else {
        outline1("LD HL, %s", _source->realName );
        char dataLabel[MAX_TEMPORARY_STORAGE];
        sprintf(dataLabel, "%sdata", _source->realName);
        outline1("LD DE, %s", dataLabel );
    }

    if ( _frame_size ) {

        if ( !_sequence && !_frame ) {
        } else {
            if ( _sequence ) {
                outline0("LD DE, $0003" );
                outline0("ADD HL, DE" );
                if ( strlen(_sequence) == 0 ) {

                } else {
                    outline1("LD A, (%s)", _sequence );
                    outline0("LD (IXR), HL" );
                    outline1("CALL %soffsetsequence", _source->realName );
                }
                if ( _frame ) {
                    if ( strlen(_frame) == 0 ) {

                    } else {
                        outline1("LD A, (%s)", _frame );
                        outline0("LD (IXR), HL" );
                        outline1("CALL %soffsetframe", _source->realName );
                    }
                }

            } else {

                if ( _frame ) {
                    outline0("LD DE, $0003" );
                    outline0("ADD HL, DE" );
                    if ( strlen(_frame) == 0 ) {

                    } else {
                        outline0("LD (IXR), HL" );
                        outline1("LD A, (%s)", _frame );
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


void gb_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm );
    // // deploy( blitimage, src_hw_gb_blit_image_asm );

    // if ( _source_count > 2 ) {
    //     CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    // }

    // MAKE_LABEL

    // outline1("LD HL, %s", _blit );
    // outline0("LD (BLITIMAGEBLITTINGADDR), HL");

    // outhead1("blitimage%s:", label);
    // if ( _source_count > 0 ) {
    //     Resource resource;
    //     resource.realName = strdup( _sources[0] );
    //     resource.type = VT_IMAGE;
    //     resource.isAddress = 0;
    //     gb_load_image_address_to_register( _environment, "BLITTMPPTR", &resource, _sequence, _frame, _frame_size, _frame_count );
    // } else {
    //     outline0( "LD HL, 0" );
    //     outline0( "LD (BLITTMPPTR), HL" );
    // }

    // if ( _source_count > 1 ) {
    //     Resource resource;
    //     resource.realName = strdup( _sources[0] );
    //     resource.type = VT_IMAGE;
    //     resource.isAddress = 0;
    //     gb_load_image_address_to_register( _environment, "BLITTMPPTR2", &resource, _sequence, _frame, _frame_size, _frame_count );
    // } else {
    //     outline0( "LD HL, 0" );
    //     outline0( "LD (BLITTMPPTR2), HL" );
    // }

    // outline1("LD A, (%s)", _x );
    // outline0("LD E, A" );
    // outline1("LD A, (%s)", _y );
    // outline0("LD D, A" );

    // outline0("PUSH HL" );
    // outline1("LD HL, %4.4x", _flags );
    // outline0("LD A, L" );
    // outline0("LD (IMAGEF), A" );
    // outline0("LD A, H" );
    // outline0("LD (IMAGET), A" );
    // outline0("POP HL" );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL BLITIMAGE");
    // } else {
    //     outline0("CALL BLITIMAGENMI2");
    // }

}

void gb_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

    deploy( gbvars, src_hw_gb_vars_asm);
    deploy( putimage, src_hw_gb_put_image_asm );

    // MAKE_LABEL

    // outhead1("putimage%s:", label);

    outline1("LD HL, (%s)", _x );
    outline0("LD (IMAGEX), HL" );
    outline1("LD HL, (%s)", _y );
    outline0("LD (IMAGEY), HL" );

    gb_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );

    // outline1("LD A, (%s)", _flags );
    // outline0("LD (IMAGEF), A" );
    // outline1("LD A, (%s)", address_displacement(_environment, _flags, "1") );
    // outline0("LD (IMAGET), A" );

    outline0("CALL PUTIMAGE");

}

void gb_wait_vbl( Environment * _environment, char * _raster_line ) {

    outline0("CALL WAITVBL");

}

void gb_screen_on_off( Environment * _environment, int _on_off ) {

    outline1("LD A, $%2.2x", _on_off );
    outline0("CALL SCREENONOFF");

}

Variable * gb_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = gb_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    buffer[0] = 0xff; // force update at first PUT IMAGE
    buffer[1] = ( _width >> 3 );
    buffer[2] = size;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

Variable * gb_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm );

    // int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    // int frameSize = gb_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    // }

    // Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    // char * buffer = malloc ( size );
    // memset( buffer, 0, size );

    // *(buffer) = _frames;
    // *(buffer+1) = ( _width & 0xff );
    // *(buffer+2) = ( _width >> 8 ) & 0xff;
    // for( int i=0; i<_frames; ++i ) {
    //     *(buffer+3+(i*frameSize)) = ( _width & 0xff );
    //     *(buffer+3+(i*frameSize)+1) = ( ( _width >> 8 ) & 0xff );
    //     *(buffer+3+(i*frameSize)+2) = ( _height & 0xff );
    // }

    // result->valueBuffer = buffer;
    // result->frameSize = frameSize;
    // result->size = size;
    // result->frameCount = _frames;

    // return result;

}

Variable * gb_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm );

    // int size2 = calculate_sequence_size( _environment, _sequences, _frames, _width, _height, _mode );
    // int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    // int frameSize = gb_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    // }

    // Variable * result = variable_temporary( _environment, VT_SEQUENCE, "(new sequence)" );

    // char * buffer = malloc ( size2 );
    // memset( buffer, 0, size2 );

    // *(buffer) = _frames;
    // *(buffer+1) = _width;
    // *(buffer+2) = _sequences;
    // for( int i=0; i<(_frames*_sequences); ++i ) {
    //     *(buffer+3+(i*frameSize)) = ( _width & 0xff );
    //     *(buffer+3+(i*frameSize)+1) = ( ( _width >> 8 ) & 0xff );
    //     *(buffer+3+(i*frameSize)+2) = ( _height & 0xff );
    // }

    // result->valueBuffer = buffer;
    // result->frameSize = frameSize;
    // result->size = size2;
    // result->frameCount = _frames;

    // return result;

}

void gb_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm );
    // // deploy( getimage, src_hw_gb_get_image_asm );

    // MAKE_LABEL

    // gb_load_image_address_to_other_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );

    // outline1("LD A, (%s)", _x );
    // outline0("LD E, A" );
    // outline1("LD A, (%s)", _y );
    // outline0("LD D, A" );
    // outline1("LD A, $%2.2x", _palette );
    // outline0("LD IXH, A" );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL GETIMAGE");
    // } else {
    //     outline0("CALL GETIMAGENMI2");
    // }

}


void gb_scroll( Environment * _environment, int _dx, int _dy ) {

    // // deploy( vic2vars, src_hw_gb_vars_asm);
    // // deploy( scroll, src_hw_gb_scroll_asm);
    // // deploy( textHScroll, src_hw_gb_hscroll_text_asm );
    // // deploy( vScrollTextDown, src_hw_gb_vscroll_text_down_asm );
    // // deploy( vScrollTextUp, src_hw_gb_vscroll_text_up_asm );

    // outline1("LD A, $%2.2x", (unsigned char)(_dx&0xff) );
    // outline0("LD B, A" );
    // outline1("LD A, $%2.2x", (unsigned char)(_dy&0xff) );
    // outline0("LD C, A" );
    // outline0("CALL SCROLL");

}

void gb_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( tiles, src_hw_gb_tiles_asm );

    // outline1("LD A, (%s)", _tile );
    // outline0("LD (TILET), A" );
    // outline1("LD A, (%s)", _x );
    // outline0("LD (TILEX), A" );
    // outline1("LD A, (%s)", _y );
    // outline0("LD (TILEY), A" );
    // outline0("LD A, 1" );
    // outline0("LD (TILEW), A" );
    // outline0("LD (TILEH), A" );
    // outline0("LD (TILEW2), A" );
    // outline0("LD (TILEH2), A" );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL PUTTILE");
    // } else {
    //     outline0("CALL PUTTILENMI2");
    // }

}

void gb_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    // Variable * tile = variable_retrieve( _environment, _tile );
    // Variable * x = variable_retrieve( _environment, _x );
    // Variable * y = variable_retrieve( _environment, _y );

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( tiles, src_hw_gb_tiles_asm );

    // int size = ( tile->originalWidth >> 3 ) * ( tile->originalHeight >> 3 );

    // if ( size ) {
    //     outline1("LD HL, OFFSETS%4.4x", size );
    //     outline0("LD A, L" );
    //     outline0("LD (TILEO), A" );
    //     outline0("LD A, H" );
    //     outline0("LD (TILEO+1), A" );
    // } else {
    //     outline0("LD A, 0" );
    //     outline0("LD (TILEO), A" );
    //     outline0("LD (TILEO+1), A" );
    // }

    // outline1("LD A, (%s)", tile->realName );
    // outline0("LD (TILET), A" );
    // outline1("LD A, (%s)", x->realName );
    // outline0("LD (TILEX), A" );
    // outline1("LD A, (%s)", y->realName );
    // outline0("LD (TILEY), A" );
    // outline1("LD A, (%s)", address_displacement(_environment, tile->realName, "1") );
    // outline0("LD (TILEW), A" );
    // outline0("LD (TILEW2), A" );
    // outline1("LD A, (%s)", address_displacement(_environment, tile->realName, "2") );
    // outline0("LD (TILEH), A" );
    // outline0("LD (TILEH2), A" );
    // outline1("LD A, (%s)", address_displacement(_environment, tile->realName, "3") );
    // outline0("LD (TILEA), A" );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL MOVETILE");
    // } else {
    //     outline0("CALL MOVETILENMI2");
    // }

}

void gb_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( tiles, src_hw_gb_tiles_asm );

    // outline1("LD A, (%s)", _tile );
    // outline0("LD (TILET), A" );
    // outline1("LD A, (%s)", _x );
    // outline0("LD (TILEX), A" );
    // outline1("LD A, (%s)", _y );
    // outline0("LD (TILEY), A" );
    // outline1("LD A, (%s)", address_displacement(_environment, _tile, "1") );
    // outline0("LD (TILEW), A" );
    // if ( _w ) {
    //     outline1("LD A, (%s)", _w );
    // }
    // outline0("LD (TILEW2), A" );
    // outline1("LD A, (%s)", address_displacement(_environment, _tile, "2") );
    // outline0("LD (TILEH), A" );
    // if ( _h ) {
    //     outline1("LD A, (%s)", _h );
    // }
    // outline0("LD (TILEH2), A" );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL PUTTILE");
    // } else {
    //     outline0("CALL PUTTILENMI2");
    // }

}

void gb_tile_at( Environment * _environment, char * _x, char * _y, char *_result ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( tiles, src_hw_gb_tiles_asm );

    // outline1("LD A, (%s)", _x );
    // outline0("LD (TILEX), A" );
    // outline1("LD A, (%s)", _y );
    // outline0("LD (TILEY), A" );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL TILEAT");
    // } else {
    //     outline0("CALL TILEATNMI2");
    // }

    // outline0("LD A, (TILET)" );
    // outline1("LD (%s), A", _result );

}

void gb_use_tileset( Environment * _environment, char * _tileset ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( tiles, src_hw_gb_tiles_asm );

    // outline1("LD A, (%s)", _tileset );

    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL USETILESET");
    // } else {
    //     outline0("CALL USETILESETNMI2");
    // }

}

Variable * gb_get_raster_line( Environment * _environment ) {

    // Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    // variable_store( _environment, result->name, 0 );

    // return result;
    
}

void gb_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

    // outline1("LD HL, (%s)", _from );
    // outline1("LD DE, (%s)", _to );
    // outline1("LD BC, (%s)", _size );
    // outline0("CALL VDPWRITE" );

}

void gb_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

    // outline1("LD HL, (%s)", _to );
    // outline1("LD DE, (%s)", _from );
    // outline1("LD BC, (%s)", _size );
    // outline0("CALL VDPREAD" );

}

void gb_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    // outline1("LD E, %2.2x", VDP_RCOLOR );
    // outline0("CALL VDPREGIN" );
    // outline1("LD A, (%s)", _foreground_color );
    // outline0("SLA A" );
    // outline0("SLA A" );
    // outline0("SLA A" );
    // outline0("SLA A" );
    // outline0("LD B, A" );
    // outline1("LD A, (%s)", _background_color );
    // outline0("OR B" );
    // outline0("CALL VDPSETREG" );
// #ifdef __coleco__
//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET" );
//         outhead1("%sskip:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK" );
//     }
// #endif

}

void gb_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

void gb_slice_image_copy( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm);
    // // deploy( duff, src_hw_sm83_duff_asm );
    // // deploy( sliceimagecopy, src_hw_gb_slice_image_copy_asm );

    // MAKE_LABEL

    // Resource resource;
    // resource.realName = strdup( _image );
    // resource.type = VT_IMAGE;
    // gb_load_image_address_to_register( _environment, NULL, &resource, _sequence, _frame, _frame_size, _frame_count );

    // outline1( "LD DE, %s", _destination );

    // outline0("CALL SLICEIMAGECOPY");

}

void gb_slice_image_extract( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm);
    // // deploy( duff, src_hw_sm83_duff_asm );
    // // deploy( sliceimageextract, src_hw_gb_slice_image_extract_asm );

    // MAKE_LABEL

    // Resource resource;
    // resource.realName = strdup( _image );
    // resource.type = VT_IMAGE;
    // gb_load_image_address_to_register( _environment, NULL, &resource, _sequence, _frame, _frame_size, _frame_count );

    // Variable * sliceImageX = variable_retrieve( _environment, _environment->sliceImageX );
    // Variable * sliceImageY = variable_retrieve( _environment, _environment->sliceImageY );
    // outline1( "LD DE, (%s)", sliceImageX->realName );
    // outline0( "LD (SLICEX), DE" );
    // outline1( "LD DE, (%s)", sliceImageY->realName );
    // outline0( "LD (SLICEY), DE" );
    // outline1( "LD DE, %s", _destination );

    // outline0("CALL SLICEIMAGEEXT");

}

int gb_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    // int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    // memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    // int uniquePaletteCount = 0;

    // memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    // return uniquePaletteCount;

}

void gb_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    // if ( !_sequence && !_frame ) {
    //     outline0("LD HL, 0" );
    // } else {
    //     outline0("LD HL, 0" );

    //     if ( _sequence ) {
    //         outline0("LD DE, $0003" );
    //         outline0("ADD HL, DE" );
    //         if ( strlen(_sequence) == 0 ) {

    //         } else {
    //             outline1("LD A, (%s)", _sequence );
    //             outline0("PUSH HL" );
    //             outline0("POP IX" );
    //             outline1("CALL OFFSETS%4.4X", _frame_count * _frame_size );
    //         }
    //         if ( _frame ) {
    //             if ( strlen(_frame) == 0 ) {

    //             } else {
    //                 outline1("LD A, (%s)", _frame );
    //                 outline0("PUSH HL" );
    //                 outline0("POP IX" );
    //                 outline1("CALL OFFSETS%4.4X", _frame_size );
    //             }
    //         }

    //     } else {

    //         if ( _frame ) {
    //             outline0("LD DE, $0003" );
    //             outline0("ADD HL, DE" );
    //             if ( strlen(_frame) == 0 ) {

    //             } else {
    //                 outline0("PUSH HL" );
    //                 outline0("POP IX" );
    //                 outline1("LD A, (%s)", _frame );
    //                 outline1("CALL OFFSETS%4.4X", _frame_size );
    //             }
    //         }

    //     }

    // }
    // outline1("LD (%s), HL", _offset );

}

void gb_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

    // // deploy( GBvars, src_hw_gb_vars_asm);
    // // deploy( GBvarsGraphic, src_hw_gb_vars_graphic_asm );

    // MAKE_LABEL

    // if ( _direction & FLAG_FLIP_X ) {
    //     gb_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
    //     // deploy( flipimagex, src_hw_gb_flip_image_x_asm );
    //     outline0("CALL FLIPIMAGEX");
    // } 
    
    // if ( _direction & FLAG_FLIP_Y ) {
    //     ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
    //     // deploy( flipimagey, src_hw_gb_flip_image_y_asm );
    //     outline0("CALL FLIPIMAGEY");
    // }

}

static unsigned int SOUND_FREQUENCIES[] = {
    -5969,  -5518,  -5094,  -4693,  -4315,  -3958,  -3621,  -3303,
    -3002,  -2719,  -2451,  -2199,  -1960,  -1735,  -1523,  -1323,
    -1134,   -955,   -787,   -627,   -477,   -336,   -202,    -76,
       44,    156,    262,    362,    457,    546,    630,    710,
      785,    856,    923,    986,   1046,   1102,   1155,   1205,
     1252,    1297,  1339,   1379,   1416,   1452,   1485,   1517,
     1547,    1575,  1601,   1626,   1650,   1672,   1693,   1713,
     1732,    1750,  1766,   1782,   1797,   1811,   1824,   1837,
     1849,    1860,  1870,   1880,   1890,   1899,   1907,   1915,
     1922,    1929,  1936,   1942,   1948,   1954,   1959,   1964,
     1969,    1973,  1977,   1981,   1985,   1988,   1992,   1995,
     1998,    2001,  2003,   2006,   2008,   2010,   2012,   2014,
     2016,    2018,  2020,   2021,   2023,   2024,   2025,   2027,
     2028,    2029,  2030,   2031,   2032,   2033,   2034,   2034,
     2035,    2036,  2036,   2037,   2038,   2038,   2039,   2039
};

void gb_start( Environment * _environment, int _channels ) {

    if ( _channels & 0x01 ) {
        outline0("CALL GBSTART0");
    }
    if ( _channels & 0x02 ) {
        outline0("CALL GBSTART1");
    }
    if ( _channels & 0x04 ) {
        outline0("CALL GBSTART2");
    }
    if ( _channels & 0x08 ) {
        outline0("CALL GBSTART3");
    }

}

void gb_set_volume( Environment * _environment, int _channels, int _volume ) {

    outline1("LD A, $%2.2x", ( _volume & 0x0f ) );
    outline0("LD E, A" );
    outline1("LD A, $%2.2x", ( _channels & 0x07 ) );
    outline0("CALL GBSTARTVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL GBPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL GBPROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL GBPROGFREQ2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("CALL GBPROGFREQ3" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LD A, (%s)", f ); \
    outline0("LD E, A" ); \
    outline1("LD A, (%s)", address_displacement(_environment, f, "1") ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBFREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBFREQ2" );

#define     PROGRAM_DURATION( c, d ) \
    outline1("LD A, $%2.2x", ( d & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( d >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL GBPROGDUR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL GBPROGDUR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL GBPROGDUR2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("CALL GBPROGDUR3" );

#define     WAIT_DURATION( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("CALL GBWAITDUR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL GBWAITDUR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL GBWAITDUR2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("CALL GBWAITDUR3" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL GBPROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL GBPROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL GBPROGFREQ2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("CALL GBPROGFREQ3" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LD A, (%s)", f ); \
    outline0("LD E, A" ); \
    outline1("LD A, (%s)", address_displacement(_environment, f, "1") ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBPROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LD A, $%2.2x", ( f & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( f >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBPROGFREQ" );

#define     PROGRAM_PULSE( c, p ) \
    outline1("LD A, $%2.2x", ( p & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( ( c & 0x01 ) ) \
        outline0("CALL GBPROGPULSE0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL GBPROGPULSE1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL GBPROGPULSE2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("CALL GBPROGPULSE3" );

#define     PROGRAM_PULSE_V( c, p ) \
    outline1("LD A, (%s)", p ); \
    outline0("LD E, A" ); \
    outline1("LD A, (%s)", address_displacement(_environment, p, "1") ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBPROGPULSE" );

#define     PROGRAM_PULSE_SV( c, p ) \
    outline1("LD A, $%2.2x", ( p & 0xff ) ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", ( ( p >> 8 ) & 0xff ) ); \
    outline0("LD D, A" ); \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBPROGPULSE" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("CALL GBSTOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("CALL GBSTOP1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("CALL GBSTOP2" ); \
    if ( ( c & 0x08 ) ) \
        outline0("CALL GBSTOP3" );

#define     STOP_FREQUENCY_V( c ) \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBSTOP" );

#define     STOP_FREQUENCY_SV( c ) \
    if ( c == NULL ) { \
        outline0("LD A, $3"); \
    } else { \
        outline1("LD A, (%s)", c ); \
    } \
    outline0("CALL GBSTOP" );

void gb_set_program( Environment * _environment, int _channels, int _program ) {

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            break;
    }

}

void gb_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void gb_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void gb_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    PROGRAM_PITCH( _channels, _pitch );

}

void gb_set_note( Environment * _environment, int _channels, int _note ) {

    gb_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void gb_stop( Environment * _environment, int _channels ) {

    STOP_FREQUENCY( _channels );

}

void gb_start_var( Environment * _environment, char * _channels ) {

    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $3" );
    }
    outline0("CALL GBSTART");

}

void gb_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    outline1("LD A, (%s)", _volume );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("LD E, A" );
    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $3" );
    }
    outline0("CALL GBSTARTVOL");

}

void gb_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    outline1("LD A, $%2.2x", _volume );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("SRL A" );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _channel );
    outline0("CALL GBSTARTVOL");

}

void gb_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            break;
    }

}

void gb_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    outline1("LD A, (%s)", _frequency );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _frequency, "1") );
    outline0("LD D, A" );
    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $3" );
    }

    outline0("CALL GBFREQ");

}

void gb_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    outline1("LD A, (%s)", _pitch );
    outline0("LD E, A" );
    outline1("LD A, (%s)", address_displacement(_environment, _pitch, "1") );
    outline0("LD D, A" );
    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $3" );
    }

    outline0("CALL GBPROGFREQ");

}

void gb_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    outline0("LD HL, GBFREQTABLE");
    outline1("LD A, (%s)", _note);
    outline0("LD E, A");
    outline0("LD A, 0");
    outline0("LD D, A");
    outline0("SLA E");
    outline0("RL D");
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline0("LD E, A");
    outline0("INC HL");
    outline0("LD A, (HL)");
    outline0("LD D, A");

    if ( _channels ) {
        outline1("LD A, (%s)", _channels );
    } else {
        outline0("LD A, $3" );
    }

    outline0("CALL GBPROGFREQ");

}

void gb_stop_vars( Environment * _environment, char * _channels ) {

    outline1("LD A, (%s)", _channels );
    outline0("CALL GBSTOP");

}

void gb_music( Environment * _environment, char * _music, int _size, int _loop ) {

    deploy( music, src_hw_gb_music_asm );

    // HL: music address, B: blocks, C: last block
    outline0("DI");
    outline1("LD HL, %s", _music);
    outline1("LD A, $%2.2x", ( _size>>8 ) & 0xff);
    outline0("LD B, A");
    outline1("LD A, $%2.2x", _size & 0xff );
    outline0("LD C, A");
    outline1("LD A, $%2.2x", _loop );
    outline0("LD (GBMUSICLOOP), A");
    outline0("CALL MUSICPLAYERRESET");
    outline0("EI");

}

void gb_set_duration( Environment * _environment, int _channel, int _duration ) {

    PROGRAM_DURATION( _channel, _duration );

}

void gb_wait_duration( Environment * _environment, int _channel ) {

    WAIT_DURATION( _channel );

}

void gb_set_duration_vars( Environment * _environment, char * _channel, char * _duration ) {

    if ( _duration ) {
        outline1("LD HL, (%s)", _duration );
        outline0("LD DE, HL" );
    } else {
        outline0("LD DE, 50" );
    }
    if ( _channel ) {
        outline1("LD A, (%s)", _channel );
    } else {
        outline0("LD A, $3" );
    }

    outline0("CALL GBPROGDUR" );

}

void gb_wait_duration_vars( Environment * _environment, char *  _channel ) {

    if ( _channel ) {
        outline1("LD A, (%s)", _channel );
    } else {
        outline0("LD A, $3" );
    }
    
    outline0("CALL GBWAITDUR" );

}

void gb_screen( Environment * _environment, char * _x, char * _y, char * _c ) {

    deploy( screen, src_hw_gb_screen_asm);

    outline1("LD A, (%s)", _x );
    outline0("LD C, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD B, A" );
    outline0("CALL SCREEN" );
    outline1("LD (%s), A", _c );

}

#endif