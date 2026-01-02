/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
        { 0x00, 0x00, 0x00, 0xff,  0, "BLACK" },        
        { 0x00, 0x00, 0xff, 0xff,  1, "BLUE" },
        { 0x88, 0x00, 0x00, 0xff,  2, "RED" },
        { 0xff, 0x00, 0xff, 0xff,  3, "MAGENTA" },
        { 0x00, 0xcc, 0x00, 0xff,  4, "GREEN" },
        { 0xaa, 0xff, 0xe6, 0xff,  5, "CYAN" },
        { 0xee, 0xee, 0x77, 0xff,  6, "YELLOW" },
        { 0xff, 0xff, 0xff, 0xff,  7, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __pccga__

void pccga_inkey( Environment * _environment, char * _pressed, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_pccga_keyboard_asm);

    outline0("CALL INKEY");
    outline1("MOV [%s], AL", _key);
    outline1("MOV [%s], BL", _pressed);

}

void pccga_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy_deferred( keyboard, src_hw_pccga_keyboard_asm );

    if ( _release ) {
        outline0("CALL WAITKEYRELEASE");
    } else {
        outline0("CALL WAITKEY");
    }
   
}


void pccga_wait_key_or_fire( Environment * _environment, int _port, int _release ) {
   
}

void pccga_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {
   
}

void pccga_wait_fire( Environment * _environment, int _port, int _release ) {

}

void pccga_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

}

void pccga_scancode( Environment * _environment, char * _scancode ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_pccga_keyboard_asm);

    outline0("CALL SCANCODE");
    outline1("MOV [%s], AL", _scancode);

}

void pccga_asciicode( Environment * _environment, char * _result ) {

    deploy( keyboard, src_hw_pccga_keyboard_asm);

    outline0("CALL ASCIICODE");
    outline1("MOV [%s], AL", _result);   

}

void pccga_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_pccga_keyboard_asm );

    outline1("MOV AL, [%s]", _scancode);
    outline0("CALL KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("MOV [%s], AL", _result);

}

void pccga_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_pccga_keyboard_asm );

    outline1("MOV AL, [%s]", _scancode);
    outline0("CALL KEYSTATE");
    cpu_ctoa( _environment );
    outline1("MOV [%s], AL", _result);

}

void pccga_scanshift( Environment * _environment, char * _shifts ) {

}

void pccga_keyshift( Environment * _environment, char * _shifts ) {

}

void pccga_clear_key( Environment * _environment ) {

}

void pccga_joy_vars( Environment * _environment, char * _port, char * _value ) {

}

void pccga_joy( Environment * _environment, int _port, char * _value ) {

}

void pccga_sys_call( Environment * _environment, int _destination ) {

}

void pccga_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_8086_timer_asm);

    if ( _timer ) {
        outline1("MOV BL, [%s]", _timer );
    } else {
        outline0("MOV BL, 0" );
    }
    outline0("MOV CL, 1" );
    outline0("CALL TIMERSETSTATUS" );

}

void pccga_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_8086_timer_asm);

    if ( _timer ) {
        outline1("MOV BL, [%s]", _timer );
    } else {
        outline0("MOV BL, 0" );
    }
    outline0("LD CL, 0" );
    outline0("CALL TIMERSETSTATUS" );

}

void pccga_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    deploy( timer, src_hw_8086_timer_asm);

    if ( _counter ) {
        outline1("MOV DX, [%s]", _counter );
    } else {
        outline0("MOV DX, 0" );
    }
    if ( _timer ) {
        outline1("MOV BL, [%s]", _timer );
    } else {
        outline0("MOV BL, 0" );
    }
    outline0("CALL TIMERSETCOUNTER" );

}

void pccga_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    deploy( timer, src_hw_8086_timer_asm);

    if ( _init ) {
        outline1("MOV AX, [%s]", _init );
    } else {
        outline0("MOV AX, 0" );
    }
    if ( _timer ) {
        outline1("MOV BL, [%s]", _timer );
    } else {
        outline0("MOV BL, 0" );
    }
    outline0("CALL TIMERSETINIT" );

}

void pccga_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    deploy( timer, src_hw_8086_timer_asm);

    if ( _address ) {
        outline1("MOV DX, %s", _address );
    } else {
        outline0("MOV DX, 0" );
    }
    if ( _timer ) {
        outline1("MOV BL, [%s]", _timer );
    } else {
        outline0("MOV BL, 0" );
    }
    outline0("CALL TIMERSETADDRESS" );

}

#endif