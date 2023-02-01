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

#ifdef __c128__

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void c128_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $D013");    
    outline0("ASL" );
    outline1("STA %s", _destination);
    outline1("BCC %s", label );
    outline0("LDA #1");    
    outline1("STA _%s+1", _destination);
    outhead1("%s:", label );

}

void c128_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $d014");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s+1", _destination);    
   
}

void c128_inkey( Environment * _environment, char * _pressed, char * _key ) {

    deploy( scancode, src_hw_c128_scancode_asm);

    MAKE_LABEL

    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$0");
    outline1("STA %s", _key );

    outline0("JSR SCANCODE");

    outline0("LDX $c6");
    outline0("CPX #$0");
    outline1("BEQ %snokey", label );

    outline0("LDA $0277" );
    outline0("CMP #$FF");
    outline1("BEQ %snopetscii", label );
    outline1("STA %s", _key );
    outline0("LDA #$FF");
    outline1("STA %s", _pressed );

    outline0("LDX #0");
    outhead1("%sclkeys:", label);
    outline0("LDA $0278,X" );
    outline0("LDA $0277,X" );
    outline0("INX");
    outline0("CPX $c6");
    outline1("BNE %sclkeys", label);
    outline0("DEC $c6");

    outline1("JMP %snokey", label );

    outhead1("%snopetscii:", label );
    outline0("LDA #0");
    outline1("STA %s", _key );
    outhead1("%snokey:", label );
   
}

void c128_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    deploy( scancode, src_hw_c128_scancode_asm);

    MAKE_LABEL

    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$0");
    outline1("STA %s", _scancode );

    outline0("JSR SCANCODE");

    outline0("LDY $c5");
    outline0("CPY #$40");
    outline1("BEQ %snokey", label );

    outline1("STY %s", _scancode );
    outline0("LDA #$ff");
    outline1("STA %s", _pressed );

    outhead1("%snokey:", label );
   
}

void c128_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    c128_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_return( _environment );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_return( _environment );

}

void c128_scanshift( Environment * _environment, char * _shifts ) {

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

void c128_keyshift( Environment * _environment, char * _shifts ) {

    deploy( scancode, src_hw_c128_scancode_asm);

    MAKE_LABEL

    outline0("JSR SCANCODE");

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

    outline0("LDA $028D");
    outline0("AND #$01");
    outline1("BEQ %snocaps", label);
    outline1("LDA %s", _shifts);
    outline0("ORA #4");
    outline1("STA %s", _shifts);
    outhead1("%snocaps:", label );

    outline0("LDA $028D");
    outline0("AND #$04");
    outline1("BEQ %snocontrol", label);
    outline1("LDA %s", _shifts);
    outline0("ORA #8");
    outline1("STA %s", _shifts);
    outhead1("%snocontrol:", label );

    outline0("LDA $028D");
    outline0("AND #$02");
    outline1("BEQ %snoalt", label);
    outline1("LDA %s", _shifts);
    outline0("ORA #$30");
    outline1("STA %s", _shifts);
    outhead1("%snoalt:", label );

}

void c128_clear_key( Environment * _environment ) {

    outline0("LDA #$0");
    outline0("STA $c6");
   
}

#endif