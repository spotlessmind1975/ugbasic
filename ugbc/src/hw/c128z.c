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

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __c128z__

void c128z_inkey( Environment * _environment, char * _pressed, char * _key ) {

    deploy( scancode, src_hw_c128z_scancode_asm);

    MAKE_LABEL

    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed );
    outline0("LD A, 0");
    outline1("LD (%s), A", _key );

    outline0("CALL INKEY");

    outline0("CMP 0");
    outline1("JR Z, %snokey", label );

    outline1("LD (%s), A", _key );
    outline0("LD A, $ff");
    outline1("LD (%s), A", _pressed );
    
    outhead1("%snokey:", label );

}

void c128z_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    deploy( scancode, src_hw_c128z_scancode_asm);

    MAKE_LABEL

    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed );
    outline0("LD A, $0");
    outline1("LD (%s), A", _scancode );

    outline0("CALL SCANCODE");

    outline0("CMP 0");
    outline1("JR Z, %snokey", label );

    outline1("LD (%s), A", _scancode );
    outline0("LD A, $ff");
    outline1("LD (%s), A", _pressed );
    
    outhead1("%snokey:", label );

}

void c128z_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    c128z_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_return( _environment );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_return( _environment );

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

    deploy( scancode, src_hw_c128z_scancode_asm);

    MAKE_LABEL

    outline0("CALL SCANCODE");

    outline0("LD A, 0");
    outline1("LD (%s), A", _shifts);
    outline0("LD A, $10");
    outline0("LD ($DC00), A");
    outline0("LD A, ($DC01)");
    outline0("AND $80");
    outline1("JR NZ, %snoleft", label);
    outline0("LD A, 1");
    outline1("LD (%s), A", _shifts);
    outhead1("%snoleft:", label );

    outline0("LD A, $20");
    outline0("LD ($DC00), A");
    outline0("LD A, ($DC01)");
    outline0("AND $10");
    outline1("JR NZ, %snoright", label);
    outline1("LD A, (%s)", _shifts);
    outline0("OR 2");
    outline1("LD (%s), A", _shifts);
    outhead1("%snoright:", label );

    outline0("LD A, ($028D)");
    outline0("AND $01");
    outline1("JR Z, %snocaps", label);
    outline1("LD A, (%s)", _shifts);
    outline0("OR 4");
    outline1("LD (%s), A", _shifts);
    outhead1("%snocaps:", label );

    outline0("LD A, ($028D)");
    outline0("AND $4");
    outline1("JR Z, %snocontrol", label);
    outline1("LD A, (%s)", _shifts);
    outline0("OR 8");
    outline1("LD (%s), A", _shifts);
    outhead1("%snocontrol:", label );

    outline0("LD A, ($028D)");
    outline0("AND $02");
    outline1("JR Z, %snoalt", label);
    outline1("LD A, (%s)", _shifts);
    outline0("OR $30");
    outline1("LD A, (%s)", _shifts);
    outhead1("%snoalt:", label );

}

void c128z_clear_key( Environment * _environment ) {

}

void c128z_irq_at( Environment * _environment, char * _label ) {

}

void c128z_follow_irq( Environment * _environment ) {

}

void c128z_joy_vars( Environment * _environment, char * _port, char * _value ) {

}

void c128z_joy( Environment * _environment, int _port, char * _value ) {

}

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#endif