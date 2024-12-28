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

    // outline1("CALL $%4.4x", _destination );

}

void gb_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    // // deploy( timer, src_hw_sm83_timer_asm);

    // if ( _timer ) {
    //     outline1("LD A, (%s)", _timer );
    //     outline0("LD A, B" );
    // } else {
    //     outline0("LD B, 0" );
    // }
    // outline0("LD A, 1" );
    // outline0("LD C, A" );
    // outline0("CALL TIMERSETSTATUS" );

}

void gb_timer_set_status_off( Environment * _environment, char * _timer ) {

    // // deploy( timer, src_hw_sm83_timer_asm);

    // if ( _timer ) {
    //     outline1("LD A, (%s)", _timer );
    //     outline0("LD A, B" );
    // } else {
    //     outline0("LD B, 0" );
    // }
    // outline0("LD A, 0" );
    // outline0("LD C, A" );
    // outline0("CALL TIMERSETSTATUS" );

}

void gb_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    // // deploy( timer, src_hw_sm83_timer_asm);

    // if ( _counter ) {
    //     outline1("LD A, (%s)", _counter );
    //     outline0("LD IXL, A" );
    //     outline1("LD A, (%s)", address_displacement( _environment, _counter, "1" ) );
    //     outline0("LD IXH, A" );
    // } else {
    //     outline0("LD IX, 0" );
    // }
    // if ( _timer ) {
    //     outline1("LD A, (%s)", _timer );
    //     outline0("LD B, A" );
    // } else {
    //     outline0("LD B, 0" );
    // }
    // outline0("CALL TIMERSETCOUNTER" );

}

void gb_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    // // deploy( timer, src_hw_sm83_timer_asm);

    // if ( _init ) {
    //     outline1("LD A, (%s)", _init );
    //     outline0("LD IXL, A" );
    //     outline1("LD A, (%s)", address_displacement( _environment, _init, "1" ) );
    //     outline0("LD IXH, A" );
    // } else {
    //     outline0("LD IX, 0" );
    // }
    // if ( _timer ) {
    //     outline1("LD A, (%s)", _timer );
    //     outline0("LD B, A" );
    // } else {
    //     outline0("LD B, 0" );
    // }
    // outline0("CALL TIMERSETINIT" );

}

void gb_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    // // deploy( timer, src_hw_sm83_timer_asm);

    // if ( _address ) {
    //     outline1("LD HL, %s", _address );
    //     outline0("LD A, L" );
    //     outline0("LD IXL, A" );
    //     outline0("LD A, H" );
    //     outline0("LD IXH, A" );
    // } else {
    //     outline0("LD IX, 0" );
    // }
    // if ( _timer ) {
    //     outline1("LD A, (%s)", _timer );
    //     outline0("LD B, A" );
    // } else {
    //     outline0("LD B, 0" );
    // }
    // outline0("CALL TIMERSETADDRESS" );

}

void gb_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    // // deploy( dcommon, src_hw_gb_dcommon_asm );
    // // deploy( dload, src_hw_gb_dload_asm );

    // MAKE_LABEL
    
    // Variable * filename = variable_retrieve( _environment, _filename );
    // Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    // Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    // Variable * address = NULL;
    // if ( _address ) {
    //     address = variable_retrieve( _environment, _address );
    // }
    // Variable * size = NULL;
    // if ( _size ) {
    //     size = variable_retrieve( _environment, _size );
    // }
    // Variable * offset = NULL;
    // if ( _offset ) {
    //     offset = variable_retrieve( _environment, _offset );
    // }

    // switch( filename->type ) {
    //     case VT_STRING:
    //         cpu_move_8bit( _environment, filename->realName, tnsize->realName );
    //         cpu_addressof_16bit( _environment, filename->realName, tnaddress->realName );
    //         cpu_inc_16bit( _environment, tnaddress->realName );
    //         break;
    //     case VT_DSTRING:
    //         cpu_dsdescriptor( _environment, filename->realName, tnaddress->realName, tnsize->realName );
    //         break;
    // }

    // outline1("LD HL, (%s)", tnaddress->realName);
    // outline1("LD A, (%s)", tnsize->realName);
    // outline0("LD B, A");

    // if ( address ) {

    //     outline1("LD DE, (%s)", address->realName);

    // }

    // outline0("CALL GBDLOAD");

}

void gb_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    // // deploy( dcommon, src_hw_gb_dcommon_asm );
    // // deploy( dsave, src_hw_gb_dsave_asm );

    // MAKE_LABEL
    
    // Variable * filename = variable_retrieve( _environment, _filename );
    // Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    // Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    // Variable * address = NULL;
    // if ( _address ) {
    //     address = variable_retrieve( _environment, _address );
    // }
    // Variable * size = NULL;
    // if ( _size ) {
    //     size = variable_retrieve( _environment, _size );
    // }
    // Variable * offset = NULL;
    // if ( _offset ) {
    //     offset = variable_retrieve( _environment, _offset );
    // }

    // switch( filename->type ) {
    //     case VT_STRING:
    //         cpu_move_8bit( _environment, filename->realName, tnsize->realName );
    //         cpu_addressof_16bit( _environment, filename->realName, tnaddress->realName );
    //         cpu_inc_16bit( _environment, tnaddress->realName );
    //         break;
    //     case VT_DSTRING:
    //         cpu_dsdescriptor( _environment, filename->realName, tnaddress->realName, tnsize->realName );
    //         break;
    // }

    // outline1("LD HL, (%s)", tnaddress->realName);
    // outline1("LD A, (%s)", tnsize->realName);
    // outline0("LD B, A");

    // if ( address ) {

    //     outline1("LD DE, (%s)", address->realName);

    // }

    // if ( size ) {

    //     outline1("LD IX, (%s)", size->realName);

    // }

    // outline0("CALL GBDSAVE");

}


void gb_put_key(  Environment * _environment, char *_string, char * _size ) {

    // _environment->bitmaskNeeded = 1;

    // // deploy( keyboard, src_hw_gb_keyboard_asm);

    // outline1("LD HL, (%s)", _string );
    // outline1("LD A, (%s)", _size );
    // outline0("LD C, A" );
    // outline0("CALL PUTKEY" );

}

void gb_dojo_ready( Environment * _environment, char * _value ) {

}

void gb_dojo_read_byte( Environment * _environment, char * _value ) {

}

void gb_dojo_write_byte( Environment * _environment, char * _value ) {

}

void gb_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

}

void gb_dojo_success( Environment * _environment, char * _id, char * _result ) {

}

void gb_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

}

void gb_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

}

void gb_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

}

void gb_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

}

void gb_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

}

void gb_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

}

void gb_dojo_ping( Environment * _environment, char * _result ) {

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
 * This method can be used to convert 
 *     WxH RGB (3/4 bytes) pixel (_source) [WxHx3/4 bytes]
 * into 
 *     WxH bitmap (1 bit) pixel + (W/8xH + W/8xH) (bytes)
 *       foreground and background color (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze.
 */
static void gb_image_converter_tiles( Environment * _environment, char * _source, char * _dest, int _width, int _height, int _depth, int _source_width ) {

    // int bitmapSize = ( _width>>3 ) * _height;
    // int colormapSize = ( _width>>3 ) * _height;

    // memset( _dest, 0, bitmapSize + colormapSize );

    // adilinebeginbitmap("BMD2");

    // for( int y=0; y<_height; y+=8 ) {
    //     for( int x=0; x<_width; x+=8 ) {

    //         char * source = _source + ( ( y * _source_width ) + x ) * _depth;
    //         char tile[16];

    //         gb_image_converter_tile( _environment, source, tile, _width, _depth, _source_width );

    //         int offset = ((y>>3) * 8 *( _width >> 3 ) ) + ((x>>3) * 8) + ((y) & 0x07);
    //         // x = 8, y = 8
    //         // offset = ((8 >> 3) * 8 * (16>>3) ) + ((8>>3) * 8) + ((8) & 7)
    //         // offset = (1 * 8 * 2 ) + (1 * 8)
    //         // offset = 16 + 8 = 24

    //         char * destBitmap = _dest + offset;
    //         char * destColormap = _dest + bitmapSize + offset;
    //         for( int i=0; i<8; ++i ) {
    //             *destBitmap = tile[i];
    //             *destColormap = tile[i+8];
    //             ++destBitmap;
    //             ++destColormap;
    //         }
    //     }
    // }

    // adilineendbitmap();

}

/**
 * @brief <i>TMS9918</i>: emit code to check for collision
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

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    // Variable * result = variable_temporary( _environment, VT_SBYTE, "(collision)" );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITECOL");
    // } else {
    //     outline0("CALL SPRITECOLNMI2");
    // }

    // outline1("LD (%s), A", result->realName )

    // return result;
    
}

/**
 * @brief <i>TMS9918</i>: emit code to check for collision
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

    //todo

}

/**
 * @brief <i>TMS9918</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void gb_border_color( Environment * _environment, char * _border_color ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    // outline1("LD E, %2.2x", VDP_RCOLOR );
    // outline0("CALL VDPREGIN" );
    // outline0("AND $F0" );
    // outline0("LD B, A" );
    // outline1("LD E, %2.2x", VDP_RCOLOR );
    // outline1("LD A, (%s)", _border_color );
    // outline0("AND $0F" );
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

/**
 * @brief <i>TMS9918</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color( Environment * _environment, int _index, int _background_color ) {

    // char value[MAX_TEMPORARY_STORAGE]; sprintf( value, "$%2.2x", _background_color );

    // gb_background_color_vars( _environment, NULL, value );
    
}

/**
 * @brief <i>TMS9918</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    // MAKE_LABEL

    // sm83_compare_and_branch_8bit_const( _environment, _index, 0, label, 0 );

    // gb_border_color( _environment, _background_color );

    // cpu_label( _environment, label );
    // outline1( "LD A, (%s)", _index );
    // outline0( "LD E, A" );
    // outline0( "LD A, 0" );
    // outline0( "LD D, A" );
    // outline0( "LD HL, PALETTE" );
    // outline0( "ADD HL, DE" );
    // outline1( "LD A, (%s)", _background_color );
    // outline0( "LD (HL), A" );

}

/**
 * @brief <i>TMS9918</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    // if ( ! _index ) {
    //     gb_border_color( _environment, _background_color );
    // }

    // outline1( "LD A, $%2.2x", _index );
    // outline0( "LD E, A" );
    // outline0( "LD A, 0" );
    // outline0( "LD D, A" );
    // outline0( "LD HL, PALETTE" );
    // outline0( "ADD HL, DE" );
    // outline1( "LD A, (%s)", _background_color );
    // outline0( "LD (HL), A" );

}

/**
 * @brief <i>TMS9918</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gb_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

    // outline1( "LD A, (%s)", _index );
    // outline0( "LD E, A" );
    // outline0( "LD A, 0" );
    // outline0( "LD D, A" );
    // outline0( "LD HL, PALETTE" );
    // outline0( "ADD HL, DE" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _background_color );

}

/**
 * @brief <i>TMS9918</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void gb_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    // outline0("LD HL, $1000");
    // outline1("LD E, (%s)", _index );
    // outline0("SLA E");
    // outline0("SLA E");
    // outline0("INC E");
    // outline0("INC E");
    // outline0("INC E");
    // outline0("LD D, 0");
    // outline0("ADD HL, DE");
    // outline0("CALL VDPINCHAR");
    // outline0("AND $F0");
    // outline0("LD B, A");
    // outline1("LD A, (%s)", _common_color );
    // outline0("OR B");
    // outline0("CALL VDPOUTCHAR");
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

/**
 * @brief <i>TMS9918</i>: emit code to set raster irq
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
 * @brief <i>TMS9918</i>: emit code to wait for next raster irq
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
 * @brief <i>TMS9918</i>: emit code to wait for next raster irq at different position
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
    
    // int colorIndex = 0;
    // unsigned int minDistance = 0xffffffff;
    // int j;

    // RGBi rgb;
    // rgb.red = _red;
    // rgb.green = _green;
    // rgb.blue = _blue;

    // for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
    //     int distance = rgbi_distance(&SYSTEM_PALETTE[j], &rgb);
    //     if (distance < minDistance) {
    //         minDistance = distance;
    //         colorIndex = j;
    //     }
    // }

    // return colorIndex;

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

    // cpu_store_16bit( _environment, "CLIPX1", 0 );
    // cpu_store_16bit( _environment, "CLIPX2", (_environment->screenWidth-1) );
    // cpu_store_16bit( _environment, "CLIPY1", 0 );
    // cpu_store_16bit( _environment, "CLIPY2", (_environment->screenHeight-1) );

    // cpu_store_16bit( _environment, "ORIGINX", 0 );
    // cpu_store_16bit( _environment, "ORIGINY", 0 );

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

    int startAddress = 0x9000;

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

    //todo

}

void gb_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        // printf("gb_tilemap_enable() -> %d\n", mode->id );
        
        gb_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        if (_environment->vestigialConfig.clsImplicit ) {
            gb_cls( _environment );
        }

    } else {
        // printf("gb_tilemap_enable() -> -1\n" );
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

    // deploy( tms9918vars, src_hw_gb_vars_asm);
    // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );
    // deploy( plot, src_hw_gb_plot_asm );
    
    // if ( _c ) {
    //     outline1("LD A, #$%2.2x", ( *_c & 0xff ) );
    // } else {
    //     Variable * c = variable_retrieve( _environment, "PEN" );
    //     outline1("LD A, (%s)", c->realName );
    // }
    // outline0("LD (PLOTCPE), A");
    // outline1("LD A, $%2.2x", ( _y & 0xff ) );
    // outline0("LD D, A");
    // outline1("LD A, $%2.2x", ( _x & 0xff ) );
    // outline0("LD E, A");
    // outline1("LD A, $%2.2x", ( ( _x >> 8 ) & 0xff ) );
    // outline0("LD IXH, A");
    // outline0("LD A, 1");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL PLOT");
    // } else {
    //     outline0("CALL PLOTNMI2");
    // }

}

void gb_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

    // Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    // Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    // Variable * c;
    
    // if ( _c ) {
    //     c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    // } else {
    //     c = variable_retrieve( _environment, "PEN" );
    // }

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );
    // // deploy( plot, src_hw_gb_plot_asm );
    
    // outline1("LD A, (%s)", c->realName );
    // outline0("LD (PLOTCPE), A");
    // outline1("LD A, (%s)", y->realName );
    // outline0("LD D, A");
    // outline1("LD A, (%s)", x->realName );
    // outline0("LD E, A");
    // outline1("LD A, (%s)", address_displacement(_environment, x->realName, "1") );
    // outline0("LD IXH, A");
    // outline0("LD A, 1");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL PLOT");
    // } else {
    //     outline0("CALL PLOTNMI2");
    // }

}

void gb_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

    // Variable * x = variable_retrieve( _environment, _x );
    // Variable * y = variable_retrieve( _environment, _y );
    // Variable * result = variable_retrieve( _environment, _result );

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );
    // // deploy( plot, src_hw_gb_plot_asm );
    
    // outline1("LD A, (%s)", y->realName );
    // outline0("LD D, A");
    // outline1("LD A, (%s)", x->realName );
    // outline0("LD E, A");
    // outline1("LD A, (%s)", address_displacement( _environment, x->realName, "1" ) );
    // outline0("LD IXH, A");
    // outline0("LD A, 3");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL PLOT");
    // } else {
    //     outline0("CALL PLOTNMI2");
    // }    
    // outline1("LD (%s), A", result->realName);

}

void gb_screen_on( Environment * _environment ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    // outline1("LD E, %2.2x", VDP_R1 );
    // outline0("CALL VDPREGIN" );
    // outline0("OR $40" );
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

void gb_screen_off( Environment * _environment ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    // outline1("LD E, %2.2x", VDP_R1 );
    // outline0("CALL VDPREGIN" );
    // outline0("AND $BF" );
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

void gb_screen_rows( Environment * _environment, char * _rows ) {

}

void gb_screen_columns( Environment * _environment, char * _columns ) {

}

void gb_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    // Variable * address = variable_retrieve_or_define( _environment, _address, VT_BYTE, 0 );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // outline1("LD A, (%s)", sprite->realName );
    // outline0("LD B, A");
    // outline1("LD A, (%s)", address->realName );
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEDATASET");
    // } else {
    //     outline0("CALL SPRITEDATASETNMI2");
    // }

}

void gb_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    // Variable * image = variable_retrieve_or_define( _environment, _image, VT_IMAGE, 0 );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // outline1("LD A, (%s)", sprite->realName );
    // outline0("LD B, A");
    // outline1("LD HL, %s", image->realName );
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEDATAFROM");
    // } else {
    //     outline0("CALL SPRITEDATAFROMNMI2");
    // }

}

void gb_sprite_enable( Environment * _environment, char * _sprite ) {

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // outline1("LD A, (%s)", sprite->realName );
    // outline0("LD B, A");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEENABLE");
    // } else {
    //     outline0("CALL SPRITEENABLENMI2");
    // }

}

void gb_sprite_disable( Environment * _environment, char * _sprite ) {

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // outline1("LD A, (%s)", sprite->realName );
    // outline0("LD B, A");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEDISABLE");
    // } else {
    //     outline0("CALL SPRITEDISABLENMI2");
    // }

}

void gb_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    // Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    // Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // outline1("LD A, (%s)", sprite->realName );
    // outline0("LD B, A");
    // outline1("LD A, (%s)", x->realName );
    // outline0("LD H, A");
    // outline1("LD A, (%s)", y->realName );
    // outline0("LD L, A");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEAT");
    // } else {
    //     outline0("CALL SPRITEATNMI2");
    // }

}

void gb_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

    // _sprite = NULL;

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEEXPAND");
    // } else {
    //     outline0("CALL SPRITEEXPANDNMI2");
    // }

}

void gb_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

    // _sprite = NULL;

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITEEXPAND");
    // } else {
    //     outline0("CALL SPRITEEXPANDNMI2");
    // }

}

void gb_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

    // _sprite = NULL;

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITECOMPRESS");
    // } else {
    //     outline0("CALL SPRITECOMPRESSNMI2");
    // }

}

void gb_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

    // _sprite = NULL;

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITECOMPRESS");
    // } else {
    //     outline0("CALL SPRITECOMPRESSNMI2");
    // }

}

void gb_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void gb_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void gb_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

    // Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    // Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    // // deploy( sprite, src_hw_gb_sprites_asm );
    
    // outline1("LD A, (%s)", sprite->realName );
    // outline0("LD B, A");
    // outline1("LD A, (%s)", color->realName );
    // outline0("LD C, A");
    // if ( ! _environment->hasGameLoop ) {
    //     outline0("CALL SPRITECOLOR");
    // } else {
    //     outline0("CALL SPRITECOLORNMI2");
    // }

}

void gb_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void gb_tiles_at( Environment * _environment, char * _address ) {

}

void gb_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void gb_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void gb_busy_wait( Environment * _environment, char * _timing ) {

    // MAKE_LABEL

    // outline1("LD C, (%s)", _timing);
    // outline0("CALL VDPREGIN");
    // outhead1("%sfirst:", label );
    // outline0("CALL VDPREGIN");
    // outline0("AND $01");
    // outline1("JP Z, %sfirst", label);
    // outline0("DEC C");
    // outline1("JP NZ, %sfirst", label);

}

void gb_get_width( Environment * _environment, char *_result ) {

    // outline0("LD HL, (CURRENTWIDTH)" );
    // outline1("LD (%s), HL", _result );

}

void gb_tiles_get( Environment * _environment, char *_result ) {

    // outline0("LD A, (CURRENTTILES)" );
    // outline1("LD (%s), A", _result );

}

void gb_get_height( Environment * _environment, char *_result ) {

    // outline0("LD HL, (CURRENTHEIGHT)" );
    // outline1("LD (%s), HL", _result );

}

void gb_cls( Environment * _environment ) {
    
    deploy( clsText, src_hw_gb_cls_asm );
    outline0("CALL CLS");

}

void gb_scroll_text( Environment * _environment, int _direction ) {

    // if ( _direction > 0 ) {
    //     // deploy( vScrollTextDown, src_hw_gb_vscroll_text_down_asm );
    //     if ( ! _environment->hasGameLoop ) {
    //         outline0("CALL VSCROLLTDOWN");
    //     } else {
    //         outline0("CALL VSCROLLTDOWNNMI2");
    //     }
    // } else {
    //     // deploy( vScrollTextUp, src_hw_gb_vscroll_text_up_asm );
    //     if ( ! _environment->hasGameLoop ) {
    //         outline0("CALL VSCROLLTUP");
    //     } else {
    //         outline0("CALL VSCROLLTUPNMI2");
    //     }
    // }

}

void gb_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy( gbvars, src_hw_gb_vars_asm );

    // deploy( vScrollTextUp, src_hw_gb_vscroll_text_up_asm );

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

    // // deploy( tms9918vars, src_hw_gb_vars_asm );
    // deploy_preferred( tms9918startup, src_hw_gb_startup_asm );

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

    variable_import( _environment, "TILESETSLOTFIRST", VT_BYTE, 0 );
    variable_global( _environment, "TILESETSLOTFIRST" );
    variable_import( _environment, "TILESETSLOTLAST", VT_BYTE, 0 );
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

    // variable_import( _environment, "SPRITEADDRESS", VT_ADDRESS, 0x0000 );
    // variable_global( _environment, "SPRITEADDRESS" );    
    // variable_import( _environment, "SPRITEAADDRESS", VT_ADDRESS, 0x1000 );
    // variable_global( _environment, "SPRITEAADDRESS" );    
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x9800 );
    variable_global( _environment, "TEXTADDRESS" );    
    // variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x3800 );
    // variable_global( _environment, "COLORMAPADDRESS" );    
    // variable_import( _environment, "PATTERNADDRESS", VT_ADDRESS, 0x0000 );
    // variable_global( _environment, "PATTERNADDRESS" );    
    // variable_import( _environment, "PALETTE", VT_BUFFER, 16 );
    // variable_global( _environment, "PALETTE" ); 

    // char defaultPalette[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    // variable_store_buffer( _environment, "PALETTE", &defaultPalette[0], 16, 0 );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_BGB, 0, 20, 18, 2, 8, 8, "Tilemap mode (BGB)" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_CGB, 0, 20, 18, 4, 8, 8, "Tilemap mode (CGB)" );

    // outline0("CALL TMS9918STARTUP");

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    // variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    // variable_global( _environment, "LINE" );

    // variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    // variable_global( _environment, "CLIPX1" );
    // variable_import( _environment, "CLIPX2", VT_POSITION, 255 );
    // variable_global( _environment, "CLIPX2" );
    // variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    // variable_global( _environment, "CLIPY1" );
    // variable_import( _environment, "CLIPY2", VT_POSITION, 191 );
    // variable_global( _environment, "CLIPY2" );

    // variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    // variable_global( _environment, "ORIGINX" );
    // variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    // variable_global( _environment, "ORIGINY" );

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

    // variable_import( _environment, "PLOTCPE", VT_BYTE, 0 );
    // variable_global( _environment, "PLOTCPE" );

    variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    variable_global( _environment, "TABSTODRAW" );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    // variable_import( _environment, "SPRITECOUNT", VT_SPRITE, 0 );
    // variable_global( _environment, "SPRITECOUNT" );

    // variable_import( _environment, "SPRITEXY", VT_BUFFER, SPRITE_COUNT * 2 );
    // variable_global( _environment, "SPRITEXY" );

    // variable_import( _environment, "TILEX", VT_BYTE, 0 );
    // variable_global( _environment, "TILEX" );
    // variable_import( _environment, "TILEY", VT_BYTE, 0 );
    // variable_global( _environment, "TILEY" );
    // variable_import( _environment, "TILEX2", VT_BYTE, 0 );
    // variable_global( _environment, "TILEX2" );
    // variable_import( _environment, "TILET", VT_BYTE, 0 );
    // variable_global( _environment, "TILET" );
    // variable_import( _environment, "TILEW", VT_BYTE, 0 );
    // variable_global( _environment, "TILEW" );
    // variable_import( _environment, "TILEH", VT_BYTE, 0 );
    // variable_global( _environment, "TILEH" );
    // variable_import( _environment, "TILEW2", VT_BYTE, 0 );
    // variable_global( _environment, "TILEW2" );
    // variable_import( _environment, "TILEH2", VT_BYTE, 0 );
    // variable_global( _environment, "TILEH2" );
    // variable_import( _environment, "TILEA", VT_BYTE, 0 );
    // variable_global( _environment, "TILEA" );
    // variable_import( _environment, "TILEO", VT_WORD, 0 );
    // variable_global( _environment, "TILEO" );

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

    // outline0("CALL TMS9918AFTERINIT");

}

void gb_finalization( Environment * _environment ) {

    // if ( _environment->vestigialConfig.clsImplicit ) {
    //     // deploy( clsText, src_hw_gb_cls_text_asm );
    // }
    
}

void gb_hscroll_line( Environment * _environment, int _direction ) {

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

void gb_hscroll_screen( Environment * _environment, int _direction ) {

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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);

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

    // switch( _mode ) {

    //     case BITMAP_MODE_GRAPHIC2:

    //         return 3 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height ) );

    //     case BITMAP_MODE_MULTICOLOR:
    //     case TILEMAP_MODE_STANDARD:
    //     case TILEMAP_MODE_GRAPHIC1:
    //         break;
    // }

    // return 0;

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    // switch( _mode ) {

    //     case BITMAP_MODE_GRAPHIC2:

    //         return 3 + ( 3 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height ) ) ) * _frames;

    //     case BITMAP_MODE_MULTICOLOR:
    //     case TILEMAP_MODE_STANDARD:
    //     case TILEMAP_MODE_GRAPHIC1:
    //         break;
    // }

    // return 0;

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    // switch( _mode ) {

    //     case BITMAP_MODE_GRAPHIC2:

    //         return 3 + ( ( 3 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height ) ) ) * _frames ) * _sequences;

    //     case BITMAP_MODE_MULTICOLOR:
    //     case TILEMAP_MODE_STANDARD:
    //     case TILEMAP_MODE_GRAPHIC1:
    //         break;
    // }

    return 0;

}

static Variable * gb_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );

    // // ignored on bitmap mode
    // (void)!_transparent_color;

    // image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    // if ( _environment->freeImageWidth ) {
    //     if ( _width % 8 ) {
    //         _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
    //     }
    //     if ( _frame_width % 8 ) {
    //         _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
    //     }
    // }
    
    // if ( _environment->freeImageHeight ) {
    //     if ( _height % 8 ) {
    //         _height = ( ( ( _height - 1 ) / 8 ) - 1 ) * 8;
    //     }
    //     if ( _frame_height % 8 ) {
    //         _frame_height = ( ( ( _frame_height - 1 ) / 8 ) - 1 ) * 8;
    //     }
    // }

    // RGBi * palette = malloc_palette( MAX_PALETTE );
    
    // int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    // if (paletteColorCount > 16) {
    //     CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    // }

    // // printf("X PALETTE (%dx%d):\n", _frame_width, _frame_height );
    // // for( int i=0; i<paletteColorCount; ++i ) {
    // //     printf("  (%2.2d) = %2.2x%2.2x%2.2x%2.2x (%s)\n", i, palette[i].alpha, palette[i].red, palette[i].green, palette[i].blue, palette[i].description );
    // // }

    // int i, j, k;

    // commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
    // commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
    // lastUsedSlotInCommonPalette = paletteColorCount;
    // adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    // adilinepalette( "CPMS:%d", (int)(sizeof(SYSTEM_PALETTE) / sizeof(RGBi)), SYSTEM_PALETTE );

    // Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    // result->originalColors = lastUsedSlotInCommonPalette;
    // memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    // int bufferSize = gb_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );
    
    // adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );

    // char * buffer = malloc ( bufferSize );
    // memset( buffer, 0, bufferSize );

    // // Position of the pixel in the original image
    // int image_x, image_y;
    
    // // Position of the pixel, in terms of tiles
    // int tile_x, tile_y;
    
    // // Position of the pixel, in terms of offset and bitmask
    // int offset, offsetc, bitmask;

    // // Color of the pixel to convert
    // RGBi rgb;

    // *(buffer) = (_frame_width & 0xff);
    // *(buffer+1) = (_frame_width >> 8 ) & 0xff;
    // *(buffer+2) = _frame_height;

    // _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // gb_image_converter_tiles( _environment, _source, buffer+3, _frame_width, _frame_height, _depth, _width );

    // if ( _environment->debugImageLoad ) {
    //     printf("\n" );
    
    //     printf("PALETTE:\n" );
    //     for( i=0; i<lastUsedSlotInCommonPalette; ++i ) {
    //         printf("  (%2.2d) = %2.2d (%s)\n", i, palette[i].index, palette[i].description );
    //     }
    //     // if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
    //     //     printf("  background  (00) = %2.2x (%s)\n", palette[0].index, palette[0].description );
    //     // } else {
    //     //     printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", palette[0].index, palette[0].description );
    //     // }
    //     // printf("  low screen  (01) = %2.2x (%s)\n", palette[1].index, palette[1].description );
    //     // printf("  high screen (10) = %2.2x (%s)\n", palette[2].index, palette[2].description );
    //     // printf("  colormap    (11) = %2.2x (%s)\n", palette[3].index, palette[3].description );
    //     // printf("\n" );
    //     // printf("\n" );
    // }
    
    // variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );
 
    // return result;

}

static Variable * gb_image_converter_tilemap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    _environment->bitmaskNeeded = 1;

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

    Variable * result = variable_temporary( _environment, VT_TILEDIMAGE, "(tiledimage)");

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

    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );

    // RGBi palette[MAX_PALETTE];

    // int colorUsed = gb_palette_extract( _environment, _source, _width, _height, _depth, 0 /* flags */, &palette[0] );

    // if ( ! _color ) {

    //     if (colorUsed > 2) {
    //         CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    //     }

    // }

    // // int colorUsed = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, 1 /* sorted */);

    // Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    // result->originalColors = colorUsed;

    // // int i, j, k;

    // // for( i=0; i<colorUsed; ++i ) {
    // //     int minDistance = 0xffff;
    // //     int colorIndex = 0;
    // //     for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
    // //         int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
    // //         if (distance < minDistance) {
    // //             for( k=0; k<i; ++k ) {
    // //                 if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
    // //                     break;
    // //                 }
    // //             }
    // //             if ( k>=i ) {
    // //                 minDistance = distance;
    // //                 colorIndex = j;
    // //             }
    // //         }
    // //     }
    // //     palette[i].index = SYSTEM_PALETTE[colorIndex].index;
    // //     strcpy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
    // // }

    // memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    // int bufferSize = ( ( _width >> 3 ) * _height ) + 1;
    
    // char * buffer = malloc ( bufferSize );
    // memset( buffer, 0, bufferSize );

    // // Position of the pixel in the original image
    // int image_x, image_y;
    
    // // Position of the pixel, in terms of tiles
    // int tile_x, tile_y;
    
    // // Position of the pixel, in terms of offset and bitmask
    // int offset, bitmask;

    // int i = 0;

    // // Color of the pixel to convert
    // RGBi rgb;

    // int spriteWidth = 16;
    // int spriteHeight = 16;

    // char * source = _source + ( ( _slot_y * spriteHeight * spriteWidth ) + _slot_x * spriteWidth ) * _depth;

    // // Loop for all the source surface.
    // for (image_y = 0; image_y < spriteHeight; ++image_y) {
    //     if ( ( image_y + ( _slot_y * spriteHeight ) )  == _height ) {
    //         // printf( "Y" );
    //         break;
    //     }
    //     for (image_x = _slot_x * spriteWidth; image_x < ( _slot_x * spriteWidth ) + spriteWidth; ++image_x) {
    //         if ( ( image_x + ( _slot_x * spriteWidth ) )  == _width ) {
    //             // printf( "X" );
    //             break;
    //         }

    //         // Take the color of the pixel
    //         rgb.red = *source;
    //         rgb.green = *(source + 1);
    //         rgb.blue = *(source + 2);
    //         if ( _depth > 3 ) {
    //             rgb.alpha = *(source + 3);
    //         } else {
    //             rgb.alpha = 255;
    //         }

    //         // Calculate the relative tile

    //         // Calculate the offset starting from the tile surface area
    //         // and the bit to set.
    //         offset = image_y * ( _width >> 4 ) + ( ( image_x & 0x07 ) >> 3 );
    //         if ( image_x > 7 ) {
    //             offset += 16;
    //         }
            
    //         if ( rgb.alpha < 255 ) {
    //             i = 0;
    //         } else {

    //             if ( ! _color ) {
    //                 int minDistance = 0xffff;
    //                 RGBi * color = NULL;
    //                 int i = 0;
    //                 for( int k=0; k<colorUsed; ++k ) {
    //                     int distance = rgbi_distance( &palette[k], &rgb );
    //                     if ( distance < minDistance ) {
    //                         minDistance = distance;
    //                         color = &palette[k];
    //                         i = k;
    //                     }
    //                 }
    //                 // for( i=0; i<colorUsed; ++i ) {
    //                 //     // printf( "%d) %2.2x%2.2x%2.2x == %2.2x%2.2x%2.2x\n", i, palette[i].red, palette[i].green, palette[i].blue, rgb.red, rgb.green, rgb.blue );
    //                 //     if ( rgbi_equals_rgba( &palette[i], color ) ) {
    //                 //         break;
    //                 //     }
    //                 // }
    //             } else {
    //                 int minDistance = 0xffff;
    //                 RGBi * color = NULL;
    //                 for( int k=0; k<colorUsed; ++k ) {
    //                     if ( palette[k].alpha < 255 ) continue;
    //                     int distance = rgbi_distance( &palette[k], &rgb );
    //                     if ( distance < minDistance ) {
    //                         minDistance = distance;
    //                         color = &palette[k];
    //                     }
    //                 }
    //                 if ( rgbi_equals_rgba( _color, color ) ) {
    //                     i = 1;
    //                 } else {
    //                     i = 0;
    //                 }
    //             }

    //         }

    //         int colorIndex = i;

    //         if ( _environment->debugImageLoad ) {
    //             printf( "%1.1x", colorIndex == 0 ? 0 : _color->index );
    //         }

    //         bitmask = ( colorIndex == 0 ? 0 : 1 ) << (7 - ((image_x & 0x7)));
    //         *(buffer + offset) |= bitmask;

    //         source += _depth;

    //     }

    //     source += _depth * ( _width - image_x );

    //     if ( _environment->debugImageLoad ) {
    //         printf("\n" );
    //     }
    // }

    // // printf("\n" );
    // // printf("\n" );

    // if ( _color ) {
    //     *(buffer + ( ( _width >> 3 ) * _height )) = _color->index;
    // } else {
    //     *(buffer + ( ( _width >> 3 ) * _height )) = palette[1].index;
    // }

    // if ( _environment->debugImageLoad ) {
    //     printf("\n" );
    
    //     printf("PALETTE:\n" );
    //     for( i=0; i<colorUsed; ++i ) {
    //         printf("  (%2.2d) = %2.2d (%s)\n", i, palette[i].index, palette[i].description );
    //     }
    //     // if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
    //     //     printf("  background  (00) = %2.2x (%s)\n", palette[0].index, palette[0].description );
    //     // } else {
    //     //     printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", palette[0].index, palette[0].description );
    //     // }
    //     // printf("  low screen  (01) = %2.2x (%s)\n", palette[1].index, palette[1].description );
    //     // printf("  high screen (10) = %2.2x (%s)\n", palette[2].index, palette[2].description );
    //     // printf("  colormap    (11) = %2.2x (%s)\n", palette[3].index, palette[3].description );
    //     // printf("\n" );
    //     // printf("\n" );
    // }
    
    // variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );
 
    // result->readonly = 1;

    // return result;

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
                    outline0("PUSH HL" );
                    outline0("POP IX" );
                    outline1("CALL %soffsetsequence", _source->realName );
                }
                if ( _frame ) {
                    if ( strlen(_frame) == 0 ) {

                    } else {
                        outline1("LD A, (%s)", _frame );
                        outline0("PUSH HL" );
                        outline0("POP IX" );
                        outline1("CALL %soffsetframe", _source->realName );
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );
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

    deploy( vbl, src_hw_gb_vbl_asm);

    outline0("CALL WAITVBL");

}

void gb_screen_on_off( Environment * _environment, int _on_off ) {

    deploy( vbl, src_hw_gb_screen_on_off_asm);

    outline1("LD A, $%2.2x", _on_off );
    outline0("CALL WAITVBL");

}

Variable * gb_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );

    // int size = gb_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    // }

    // Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    // char * buffer = malloc ( size );
    // memset( buffer, 0, size );

    // *(buffer) = (_width & 0xff);
    // *(buffer+1) = (_width>>8) & 0xff;
    // *(buffer+2) = _height;

    // result->valueBuffer = buffer;
    // result->size = size;
    
    // return result;

}

Variable * gb_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );

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

    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );

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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm);
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

    // // deploy( tms9918vars, src_hw_gb_vars_asm);
    // // deploy( tms9918varsGraphic, src_hw_gb_vars_graphic_asm );

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

#endif