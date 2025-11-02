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
        { 0x00, 0x00, 0x00, 0xff, 0, "BLACK" },        
        { 0x00, 0x00, 0xff, 0xff, 1, "BLUE" },
        { 0x88, 0x00, 0x00, 0xff, 2, "RED" },
        { 0xff, 0x00, 0xff, 0xff, 3, "MAGENTA" },
        { 0x00, 0xcc, 0x00, 0xff, 4, "GREEN" },
        { 0xaa, 0xff, 0xe6, 0xff, 5, "CYAN" },
        { 0xee, 0xee, 0x77, 0xff, 6, "YELLOW" },
        { 0xff, 0xff, 0xff, 0xff, 7, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __sg1000__

void sg1000_inkey( Environment * _environment, char * _pressed, char * _key ) {

    cpu_store_8bit( _environment, _pressed, 0 );
    cpu_store_8bit( _environment, _key, 0 );
  
}

void sg1000_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    sg1000_wait_fire( _environment, _port, _release );
   
}

void sg1000_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    sg1000_wait_fire_semivar( _environment, _port, _release );
   
}

void sg1000_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_sg1000_joystick_asm );

    outline1("LD B, $%2.2X", _release);
    outline0("CALL WAITFIRE");
   
}

void sg1000_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_sg1000_joystick_asm );

    outline1("LD B, $%2.2X", _release);
    outline0("CALL WAITFIRE");
   
}

void sg1000_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    cpu_store_8bit( _environment, _pressed, 0 );
    cpu_store_8bit( _environment, _scancode, 0 );

}

void sg1000_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    sg1000_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_jump( _environment, label );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_label( _environment, label );

}


void sg1000_scanshift( Environment * _environment, char * _shifts ) {

    cpu_store_8bit( _environment, _shifts, 0 );

}

void sg1000_keyshift( Environment * _environment, char * _shifts ) {

    cpu_store_8bit( _environment, _shifts, 0 );

}

void sg1000_clear_key( Environment * _environment ) {

}


void sg1000_sys_call( Environment * _environment, int _destination ) {

    outline1("CALL $%4.4x", _destination );

}

void sg1000_timer_set_status_on( Environment * _environment, char * _timer ) {
    
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

void sg1000_timer_set_status_off( Environment * _environment, char * _timer ) {

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

void sg1000_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void sg1000_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void sg1000_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void sg1000_put_key(  Environment * _environment, char *_string, char * _size ) {

}

#endif