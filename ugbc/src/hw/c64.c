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

#ifdef __c64__

#include "../ugbc.h"
#include "6502.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void c64_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $D013");    
    outline0("ASL" );
    outline1("STA %s", _destination);
    outline1("BCC %s", label );
    outline0("LDA #1");    
    outline1("STA _%s+1", _destination);
    outhead1("%s:", label );

}

void c64_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $d014");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s+1", _destination);    
   
}

void c64_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    // The KERNAL ROM contains four tables used by the system to convert keyboard codes into PETSCII character codes:
    // Each table contains 65 bytes; one PETSCII code for each of the 64 keys assigned a keyboard code, plus a 
    // 255/$FF which will be returned for the keyboard code of 64/$40 (indicating no key pressed).

    // 60289–60353/$EB81–$EBC1: PETSCII codes for keys pressed without simultaneously using Shift, Commodore or Ctrl keys. 
    // In this table, the entries for those three keys are 1, 2 and 4; values which get "sorted out" by the keyboard scan 
    // routines in ROM and thus never "show up" in the adresses 203 and 197.

    // 60354–60418/$EBC2–$EC02: PETSCII codes for keys pressed simultaneously with a Shift or the Shift Lock keys.
    // 60419–60483/$EC03–$EC43: PETSCII codes for keys pressed simultaneously with the Commodore logo key.
    // 60536–60600/$EC78–$ECB8: PETSCII codes for keys pressed simultaneously with the Ctrl key. 
    // This table has several bytes with 255/$FF, indicating no character; if you press Ctrl along with e.g. Inst/Del, 
    // the 64 behaves as if nothing was typed at all.

    outline0("LDA #$0");
    outline1("STA %s", _pressed );

    outline0("LDY $c5");
    outline0("CPY #$40");
    outline1("BEQ %snokey", label );

    outline0("LDA $EB81,Y" );
    outline0("CMP #$FF");
    outline1("BEQ %snopetscii", label );
    outline1("STA %s", _key );
    outline0("LDA #$1");
    outline1("STA %s", _pressed );
    outline1("JMP %snokey", label );

    outhead1("%snopetscii:", label );
    outline0("LDA #0");
    outline1("STA %s", _key );
    outhead1("%snokey:", label );
   
}

#endif