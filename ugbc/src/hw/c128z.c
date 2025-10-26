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

#ifdef __c128z__

void c128z_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm);

    outline0("CALL INKEY");
    outline1("LD (%s), A", _key);

}

void c128z_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm );

    if ( _release ) {
        outline0("CALL WAITKEYRELEASE");
    } else {
        outline0("CALL WAITKEY");
    }
   
}

void c128z_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_c128z_joystick_asm );
    deploy( keyboard, src_hw_c128z_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_c128z_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("CALL WAITKEYFIRE");
    } else {
        outline1("LD A, (%d)", _port );
        outline0("CALL WAITKEYFIREA");
    }

}

void c128z_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_c128z_joystick_asm );
    deploy( keyboard, src_hw_c128z_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_c128z_wait_key_or_fire_asm );

    if ( ! _port ) {
        outline0("CALL WAITKEYFIRE");
    } else {
        outline1("LD A, (%s)", _port );
        outline0("CALL WAITKEYFIREA");
    }

}


void c128z_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;
    
    deploy( joystick, src_hw_c128z_joystick_asm );

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

void c128z_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;
    
    deploy( joystick, src_hw_c128z_joystick_asm );

    if ( ! _port ) {
        outline0("CALL WAITFIRE");
    } else {
        outline1("LD A, (%s)", _port );
        outline0("CALL WAITFIREA");
    }

}

void c128z_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_c128z_keyboard_asm );

    outline1("LD A, (%s)", _scancode);
    outline0("CALL KEYSTATE");
    cpu_ctoa( _environment );
    outline1("LD (%s), A", _result);

}

void c128z_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm);

    outline0("CALL SCANCODE");
    if ( _environment->vestigialConfig.rchack_falling_balls_1163 ) {
        MAKE_LABEL
        outline0("CP $FF");
        outline1("JR NZ, %s", label );
        outline0("LD A, 0");
        outhead1("%s:", label );
    }
    outline1("LD (%s), A", _result );
   
}

void c128z_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm);

    outline0("CALL ASCIICODE");
    outline1("LD A, (%s)", _result );
   
}

void c128z_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_c128z_keyboard_asm );

    outline1("LD A, (%s)", _scancode);
    outline0("CALL KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("LD (%s), A", _result);

}

void c128z_scanshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    outline0("LD A, 0");
    outline1("LD (%s), A", _shifts);
    outline0("LD A, $10");
    outline0("LD BC, $DC00");
    outline0("OUT (C), A");
    outline0("INC BC");
    outline0("IN A, (C)");
    outline0("AND $80");
    outline0("CP 0");
    outline1("JR NZ, %snoleft", label);
    outline0("LD A, 1");
    outline1("LD A, (%s)", _shifts);
    outhead1("%snoleft:", label );

    outline0("LD A, $20");
    outline0("LD BC, $DC00");
    outline0("OUT (C), A");
    outline0("INC BC");
    outline0("IN A, (C)");
    outline0("AND $10");
    outline1("JR NZ, %snoright", label);
    outline1("LD A, (%s)", _shifts);
    outline0("OR 2");
    outline1("LD (%s), A", _shifts);
    outhead1("%snoright:", label );

}

void c128z_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm );

    outline0("CALL KEYSHIFT" );
    outline1("LD (%s), A", _shifts );

}

void c128z_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm );

    outline0("CALL CLEARKEY" );

}

void c128z_joy_vars( Environment * _environment, char * _port, char * _value ) {

}

void c128z_joy( Environment * _environment, int _port, char * _value ) {

}

void c128z_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PUSH HL" );
    outline0("LD HL, SYSCALL0" );
    outline0("INC HL" );
    outline1("LD (HL), $%2.2x", (_destination & 0xff ) );
    outline0("INC HL" );
    outline1("LD (HL), $%2.2x", ((_destination>>8) & 0xff ) );
    outline0("POP HL" );
    outline0("CALL SYSCALL");

}

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void c128z_timer_set_status_on( Environment * _environment, char * _timer ) {
    
}

void c128z_timer_set_status_off( Environment * _environment, char * _timer ) {

}

void c128z_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

}

void c128z_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

}

void c128z_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

}

void c128z_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_c128z_keyboard_asm);

    outline1("LD HL, (%s)", _string );
    outline1("LD A, (%s)", _size );
    outline0("LD C, A" );
    outline0("CALL PUTKEY" );

}

#endif