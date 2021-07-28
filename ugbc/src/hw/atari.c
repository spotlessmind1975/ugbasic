/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

#ifdef __atari__

#include "../ugbc.h"
#include "6502.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void atari_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $0234");    
    outline1("STA %s", _destination);
    outline0("LDA #0");    
    outline1("STA _%s+1", _destination);
    outhead1("%s:", label );

}

void atari_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $235");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s+1", _destination);    
   
}

void atari_inkey( Environment * _environment, char * _pressed, char * _key ) {
    MAKE_LABEL

    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$0");
    outline1("STA %s", _key );

    outline0("LDY $02F2");
    outline0("CPY #$FF");
    outline1("BEQ %snokey", label );

    outline0("LDA #<KEYCODE2ATASCII");
    outline0("STA TMPPTR");
    outline0("LDA #>KEYCODE2ATASCII");
    outline0("STA TMPPTR+1");
    outline0("LDA (TMPPTR),Y" );
    outline1("BEQ %snokey", label );

    outline1("STA %s", _key );
    outline0("LDA #$FF");
    outline1("STA %s", _pressed );
    outline0("STA $02F2" );

    outhead1("%snokey:", label );
   
}

void atari_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$0");
    outline1("STA %s", _scancode );

    outline0("LDA $02FC" );
    outline0("CMP #$FF");
    outline1("BEQ %snokey", label );

    outline1("STA %s", _scancode );
    outline0("LDA #$FF");
    outline1("STA %s", _pressed );
    outline0("STA $02FC" );

    outhead1("%snokey:", label );

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

#endif