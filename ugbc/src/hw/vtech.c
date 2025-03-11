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

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __vtech__

void vtech_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm);

    outline0("CALL INKEY");
    outline1("LD (%s), A", _key);

}

void vtech_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );

    if ( _release ) {
        outline0("CALL WAITKEYRELEASE");
    } else {
        outline0("CALL WAITKEY");
    }
   
}


void vtech_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_vtech_joystick_asm );
    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_vtech_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("CALL WAITKEYFIRE");
    } else {
        outline1("LD A, %2.2x", _port);
        outline0("CALL WAITKEYFIREA");
    }
   
}

void vtech_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_vtech_joystick_asm );
    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_vtech_wait_key_or_fire_asm );

    if ( ! _port ) {
        outline0("CALL WAITKEYFIRE");
    } else {
        outline1("LD A, (%s)", _port);
        outline0("CALL WAITKEYFIREA");
    }
   
}

void vtech_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_vtech_joystick_asm );
    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );

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

void vtech_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_vtech_joystick_asm );

    if ( ! _port ) {
        outline0("CALL WAITFIRE");
    } else {
        outline1("LD A, (%s)", _port);
        outline0("CALL WAITKEYFIREA");
    }

}

void vtech_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );

    outline1("LD A, (%s)", _scancode);
    outline0("CALL KEYSTATE");
    cpu_ctoa( _environment );
    outline1("LD (%s), A", _result);

}

void vtech_scancode( Environment * _environment, char * _result ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm);

    outline0("CALL SCANCODE");
    if ( _environment->vestigialConfig.rchack_falling_balls_1163 ) {
        outline0("CP $FF");
        outline1("JR NZ, %s", label );
        outline0("XOR $FF");
        outhead1("%s:", label );
    }
    outline1("LD (%s), A", _result );
   
}

void vtech_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm);

    outline0("CALL ASCIICODE");
    outline1("LD (%s), A", _result );
   
}

void vtech_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );

    outline1("LD A, (%s)", _scancode);
    outline0("CALL KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("LD (%s), A", _result);

}

void vtech_scanshift( Environment * _environment, char * _shifts ) {

}

void vtech_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );

    outline0("CALL KEYSHIFT" );
    outline1("LD (%s), A", _shifts );

}

void vtech_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );

    outline0("CALL CLEARKEY" );

}

void vtech_joy_vars( Environment * _environment, char * _port, char * _value ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );
    deploy( joystick, src_hw_vtech_joystick_asm );

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

void vtech_joy( Environment * _environment, int _port, char * _value ) {

    _environment->bitmaskNeeded = 1;
    
    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm );
    deploy( joystick, src_hw_vtech_joystick_asm );
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

void vtech_bank_select( Environment * _environment, int _bank ) {
    
}

void vtech_busy_wait( Environment * _environment, char * _timing ) {

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

void vtech_initialization( Environment * _environment ) {

    variable_import( _environment, "VTECHTIMER", VT_WORD, 0 );
    variable_global( _environment, "VTECHTIMER" );
    variable_import( _environment, "VTECHTIMER2", VT_BYTE, 6 );
    variable_global( _environment, "VTECHTIMER2" );

    variable_import( _environment, "EVERYCOUNTER", VT_BYTE, 0 );
    variable_global( _environment, "EVERYCOUNTER" );
    variable_import( _environment, "EVERYTIMING", VT_BYTE, 0 );
    variable_global( _environment, "EVERYTIMING" );

    variable_import( _environment, "FPSCRAP", VT_BUFFER, 16 );
    variable_global( _environment, "FPSCRAP" );

}

void vtech_finalization( Environment * _environment ) {

}

void vtech_timer_set_status_on( Environment * _environment, char * _timer ) {
    
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

void vtech_timer_set_status_off( Environment * _environment, char * _timer ) {

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

void vtech_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void vtech_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void vtech_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void vtech_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy( dload, src_hw_vtech_dload_asm );

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

    outline0("CALL VTECHDLOAD");

}

void vtech_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy( dsave, src_hw_vtech_dsave_asm );

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

    outline0("CALL VTECHDSAVE");

}

void vtech_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_vtech_keyboard_asm);

    outline1("LD HL, (%s)", _string );
    outline1("LD A, (%s)", _size );
    outline0("LD C, A" );
    outline0("CALL PUTKEY" );

}

#endif