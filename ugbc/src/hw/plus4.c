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

#ifdef __plus4__

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void plus4_xpen( Environment * _environment, char * _destination ) {

}

void plus4_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL
   
}

void plus4_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_plus4_joystick_asm );
    deploy( keyboard, src_hw_plus4_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_plus4_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDA #$%2.2x", _port );
        outline0("JSR WAITKEYFIREA");
    }
   
}

void plus4_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_plus4_joystick_asm );
    deploy( keyboard, src_hw_plus4_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_plus4_wait_key_or_fire_asm );

    if ( !_port ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDA %s", _port );
        outline0("JSR WAITKEYFIREA");
    }
   
}

void plus4_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_plus4_joystick_asm );

    switch( _port ) {
        case -1:
            outline0("JSR WAITFIRE");
            break;
        case 0:
            outline0("JSR WAITFIRE0");
            break;
        case 1:
            outline0("JSR WAITFIRE1");
            break;
    }
   
}

void plus4_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_plus4_joystick_asm );

    if ( ! _port ) {
        outline0("JSR WAITFIRE");
    } else {
        outline1("LDA %s", _port );
        outline0("JSR WAITFIREA");
    }
   
}

void plus4_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_plus4_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void plus4_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_plus4_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void plus4_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_plus4_keyboard_asm );

    outline1("LDX %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void plus4_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_plus4_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void plus4_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_plus4_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void plus4_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_plus4_keyboard_asm );

    outline1("LDX %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void plus4_scanshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    outline0("LDA #0");
    outline1("STA %s", _shifts);
    outline0("LDA #$10");
    outline0("STA $DC00");
    outline0("LDA $DC01");
    outline0("AND #$80");
    outline1("BNE %snoleft", label);
    outline0("LDA #1");
    outline1("STA %s", _shifts);
    outhead1("%snoleft:", label );

    outline0("LDA #$20");
    outline0("STA $DC00");
    outline0("LDA $DC01");
    outline0("AND #$10");
    outline1("BNE %snoright", label);
    outline1("LDA %s", _shifts);
    outline0("ORA #2");
    outline1("STA %s", _shifts);
    outhead1("%snoright:", label );

}

void plus4_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_plus4_keyboard_asm );

    outline0("JSR KEYSHIFT" );
    outline1("STA %s", _shifts );

}

void plus4_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_plus4_keyboard_asm );

    outline0("JSR CLEARKEY");
   
}

void plus4_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    outline1("LDA %s", _string );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _string, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );
    outline0("JSR PUTKEY" );

}

void plus4_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PHA");
    outline1("LDA #$%2.2x", (_destination & 0xff ) );
    outline0("STA SYSCALL0+1");
    outline1("LDA #$%2.2x", ((_destination>>8) & 0xff ) );
    outline0("STA SYSCALL0+2");
    outline0("PLA");
    outline0("JSR SYSCALL");

}

void plus4_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$1" );
    outline0("JSR TIMERSETSTATUS" );

}

void plus4_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$0" );
    outline0("JSR TIMERSETSTATUS" );

}

void plus4_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    if ( _counter ) {
        outline1("LDA %s", _counter );
    } else {
        outline0("LDA #0" );
    }
    outline0("STA MATHPTR2");
    if ( _counter ) {
        outline1("LDA %s", address_displacement( _environment, _counter, "1" ) );
    }
    outline0("STA MATHPTR3");
    outline0("JSR TIMERSETCOUNTER" );

}

void plus4_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline1("LDA %s", _init );
    outline0("STA MATHPTR2");
    outline1("LDA %s", address_displacement( _environment, _init, "1" ) );
    outline0("STA MATHPTR3");
    outline0("JSR TIMERSETINIT" );

}

void plus4_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline1("LDA #<%s", _address );
    outline0("STA MATHPTR2");
    outline1("LDA #>%s", _address );
    outline0("STA MATHPTR3");
    outline0("JSR TIMERSETADDRESS" );

}

void plus4_dojo_ready( Environment * _environment, char * _value ) {

}

void plus4_dojo_read_byte( Environment * _environment, char * _value ) {

}

void plus4_dojo_write_byte( Environment * _environment, char * _value ) {

}

void plus4_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

}

void plus4_dojo_success( Environment * _environment, char * _id, char * _result ) {

}

void plus4_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

}

void plus4_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

}

void plus4_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

}

void plus4_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

}

void plus4_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

}

void plus4_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

}

void plus4_dojo_ping( Environment * _environment, char * _result ) {

}

#endif