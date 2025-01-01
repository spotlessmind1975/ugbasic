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

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__c128__) || defined(__c64__) || defined(__c64reu__)

void cia_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cia_joystick_asm );
    deploy( keyboard, src_hw_cia_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_cia_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDA #$%2.2x", _port );
        outline0("JSR WAITKEYFIREA");
    }
   
}

void cia_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cia_joystick_asm );
    deploy( keyboard, src_hw_cia_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_cia_wait_key_or_fire_asm );

    if ( !_port ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDA %s", _port );
        outline0("JSR WAITKEYFIREA");
    }
   
}

void cia_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cia_joystick_asm );

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

void cia_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_cia_joystick_asm );

    if ( ! _port ) {
        outline0("JSR WAITFIRE");
    } else {
        outline1("LDA %s", _port );
        outline0("JSR WAITFIREA");
    }
   
}

void cia_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_cia_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void cia_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_cia_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void cia_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_cia_keyboard_asm );

    outline1("LDX %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void cia_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_cia_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void cia_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_cia_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void cia_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_cia_keyboard_asm );

    outline1("LDX %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void cia_scanshift( Environment * _environment, char * _shifts ) {

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

void cia_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_cia_keyboard_asm );

    outline0("JSR KEYSHIFT" );
    outline1("STA %s", _shifts );

}

void cia_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_cia_keyboard_asm );

    outline0("JSR CLEARKEY");
   
}

void cia_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    outline1("LDA %s", _string );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _string, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );
    outline0("JSR PUTKEY" );

}

#endif