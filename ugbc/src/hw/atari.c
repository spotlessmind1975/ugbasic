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

#if defined(__atari__) || defined(__atarixl__)

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void atari_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $0234");    
    outline1("STA %s", _destination);
    outline0("LDA #0");    
    outline1("STA _%s", address_displacement(_environment, _destination, "1"));
    outhead1("%s:", label );

}

void atari_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $235");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s", address_displacement(_environment, _destination, "1"));    
   
}

void atari_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    deploy( scancode, src_hw_atari_scancode_asm);

    outline0("JSR INKEY");

    outline1("STX %s", _pressed );
    outline1("STA %s", _key );

}

void atari_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_atari_scancode_asm);

    outline0("JSR SCANCODE");

    outline1("STX %s", _pressed );
    outline1("STY %s", _scancode );

}

void atari_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    atari_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_jump( _environment, label );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_label( _environment, label );

}


void atari_scanshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    outline0("LDA #0" );
    outline1("STA %s", _shifts );

    outline0("LDA $02F2" );
    outline0("AND #$40");
    outline1("BNE %snokey", label );

    outline0("LDA #3" );
    outline1("STA %s", _shifts );
   
    outhead1("%snokey:", label );

}

void atari_keyshift( Environment * _environment, char * _shifts ) {


    MAKE_LABEL

    outline0("LDA #0" );
    outline1("STA %s", _shifts );

    outline0("LDA $02F2" );
    outline0("AND #$40");
    outline1("BNE %snoshifts", label );

    outline0("LDA #3" );
    outline1("STA %s", _shifts );
   
    outhead1("%snoshifts:", label );

    outline0("LDA $02BE" );
    outline0("AND #$40");
    outline1("BEQ %snocaps", label );

    outline1("LDA %s", _shifts);
    outline0("ORA #4");
    outline1("STA %s", _shifts);

    outhead1("%snocaps:", label );

    outline0("LDA $02BE" );
    outline0("AND #$80");
    outline1("BEQ %snoctrl", label );

    outline1("LDA %s", _shifts);
    outline0("ORA #8");
    outline1("STA %s", _shifts);

    outhead1("%snoctrl:", label );

}

void atari_clear_key( Environment * _environment ) {

    outline0("LDA #$FF");
    outline0("STA $02F2");
   
}

void atari_sys_call( Environment * _environment, int _destination ) {

    outline1("JSR $%4.4x", _destination);

}

#endif