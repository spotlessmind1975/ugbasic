/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

    // Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline0("DI" );
    outline0("LD A, 0xc3" );
    outline0("LD ($FD9F), A" );
    outline1("LD HL, %s", _label );
    outline0("LD ($FDA0), HL" );
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

    outline1("LD A, (%s)", _port);
    outline0("LD B, A");
    outline0("CALL JOYSTICK");
    outline1("LD (%s), A", _value );

}

void coleco_joy( Environment * _environment, int _port, char * _value ) {

    deploy( joystick, src_hw_coleco_joystick_asm );

    outline1("LD A, $%2.2x", _port);
    outline0("LD B, A");
    outline0("CALL JOYSTICK");
    outline1("LD (%s), A", _value );

}

void coleco_sys_call( Environment * _environment, int _destination ) {

    outline1("CALL $%4.4x", _destination );

}

#endif