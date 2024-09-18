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

#ifdef __coleco__

void coleco_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    deploy( scancode, src_hw_coleco_scancode_asm );

    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed );
    outline1("LD (%s), A", _key );
    outline0("CALL SCANCODE");
    outline0("CP 0");
    outline1("JR Z, %snokey", label );
    outline1("LD (%s), a", _key );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outhead1("%snokey:", label );
   
}

void coleco_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    coleco_wait_fire( _environment, _port, _release );
   
}

void coleco_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_coleco_joystick_asm );

    outline0("CALL WAITFIRE");
   
}

void coleco_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_coleco_scancode_asm );

    outline0("LD A, 0");
    outline1("LD (%s), A", _scancode );
    outline1("LD (%s), A", _pressed );
    outline0("CALL SCANCODE");
    outline0("CP 0");
    outline1("JR Z,%snokey", label);
    outline1("LD (%s), A", _scancode );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outhead1("%snokey:", label );
   
}

void coleco_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    coleco_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_jump( _environment, label );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_label( _environment, label );

}

void coleco_scanshift( Environment * _environment, char * _shifts ) {

    outline0("LD A, ($FBEB)");
    outline1("LD (%s), A", _shifts );

}

void coleco_keyshift( Environment * _environment, char * _shifts ) {

    outline0("LD A, ($FBEB)");
    outline1("LD (%s), A", _shifts );

}

void coleco_clear_key( Environment * _environment ) {

}


void coleco_irq_at( Environment * _environment, char * _label ) {

    outline0("DI" );
    outline1("LD DE, %s", _label );
    outline0("LD HL, IRQVECTOR" );
    // outline0("LD A, $c3" );
    // outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, E" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, D" );
    outline0("LD (HL), A" );
    outline0("EI" );
    
}

void coleco_follow_irq( Environment * _environment ) {

    // Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    // outline1("LD HL, (%s)", irq->realName );
    // outline0("JP (HL)" );
    
    outline0("EI" );
    outline0("RET" );

}

void coleco_joy_vars( Environment * _environment, char * _port, char * _value ) {

    deploy( joystick, src_hw_coleco_joystick_asm );

    MAKE_LABEL

    outline1("LD A, (%s)", _port);
    outline0("CP 0");
    outline1("JR NZ, %spt1", label );
    outline0("LD A, (JOYSTICK0)");
    outline1("LD (%s), A", _value);
    outline1("JR %sptx", label );
    outhead1("%spt1:", label);
    outline0("LD A, (JOYSTICK1)");
    outline1("LD (%s), A", _value);
    outline1("JR %sptx", label );
    outhead1("%sptx:", label);

}

void coleco_joy( Environment * _environment, int _port, char * _value ) {

    deploy( joystick, src_hw_coleco_joystick_asm );

    switch ( _port ) {
        case 0:
            outline0("LD A, (JOYSTICK0)");
            outline1("LD (%s), A", _value);
            break;
        case 1:
            outline0("LD A, (JOYSTICK1)");
            outline1("LD (%s), A", _value);
            break;
    }

}

void coleco_sys_call( Environment * _environment, int _destination ) {

    outline1("CALL $%4.4x", _destination );

}

void coleco_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_z80_timer_asm);

    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD A, B" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("LD A, 1" );
    outline0("LD C, A" );
    outline0("CALL TIMERSETSTATUS" );

}

void coleco_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_z80_timer_asm);

    if ( _timer ) {
        outline1("LD A, (%s)", _timer );
        outline0("LD A, B" );
    } else {
        outline0("LD B, 0" );
    }
    outline0("LD A, 0" );
    outline0("LD C, A" );
    outline0("CALL TIMERSETSTATUS" );


}

void coleco_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void coleco_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void coleco_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void coleco_dojo_ready( Environment * _environment, char * _value ) {

}

void coleco_dojo_read_byte( Environment * _environment, char * _value ) {

}

void coleco_dojo_write_byte( Environment * _environment, char * _value ) {

}

void coleco_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

}

void coleco_dojo_success( Environment * _environment, char * _id, char * _result ) {

}

void coleco_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

}

void coleco_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

}

void coleco_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

}

void coleco_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

}

void coleco_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

}

void coleco_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

}

void coleco_dojo_ping( Environment * _environment, char * _result ) {

}

#endif