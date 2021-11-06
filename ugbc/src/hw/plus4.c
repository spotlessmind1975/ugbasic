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

#ifdef __plus4__

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void plus4_xpen( Environment * _environment, char * _destination ) {

}

void plus4_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL
   
}

void plus4_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    // Keyboard buffer lies between 1319-1328 memory area ($0527-$0530), and the index 
    // assigned for its length is 239 ($EF), but you can change the overall length of the buffer 
    // changing the value 10 ($0A) in 1343 ($053F).
    
    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$0");
    outline1("STA %s", _key );

    outline0("LDX $ef");
    outline0("CPX #$0");
    outline1("BEQ %snokey", label );

    outline0("LDA $0527" );
    outline0("CMP #$FF");
    outline1("BEQ %snopetscii", label );
    outline1("STA %s", _key );
    outline0("LDA #$FF");
    outline1("STA %s", _pressed );

    outline0("LDX #0");
    outhead1("%sclkeys:", label);
    outline0("LDA $0528,X" );
    outline0("LDA $0527,X" );
    outline0("INX");
    outline0("CPX $ef");
    outline1("BNE %sclkeys", label);
    outline0("DEC $ef");

    outline1("JMP %snokey", label );

    outhead1("%snopetscii:", label );
    outline0("LDA #0");
    outline1("STA %s", _key );
    outhead1("%snokey:", label );
   
}

void plus4_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

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
    outline0("LDA #$0");
    outline1("STA %s", _scancode );

    outline0("LDX $ef");
    outline0("CPX #$0");
    outline1("BEQ %snokey", label );

    outline0("LDY $0527");
    outline0("CPY #0");
    outline1("BEQ %snokey", label );

    outline0("DEC $ef");

    outline1("STY %s", _scancode );
    outline0("LDA #$ff");
    outline1("STA %s", _pressed );

    outhead1("%snokey:", label );
   
}

void plus4_scanshift( Environment * _environment, char * _shifts ) {

    // 653	
    // Shift key indicator. Bits:
    // Bit #0: 1 = One or more of left Shift, right Shift or Shift Lock is currently being pressed or locked.
    // Bit #1: 1 = Commodore is currently being pressed.
    // Bit #2: 1 = Control is currently being pressed.
    // NO SHIFT (0) - if no SHIFT key pressed;
    // LEFT SHIFT (1) - if the left SHIFT pressed;
    // RIGHT SHIFT (2) - if the right SHIFT pressed;
    // BOTH SHIFTS (3) - if both keys pressed.

    MAKE_LABEL

    outline0("LDA #0");
    outline1("STA %s", _shifts);
    outline0("LDA $0543");
    outline0("AND #$01");
    outline1("BEQ %se", label);
    outline0("LDA #$03");
    outline1("STA %s", _shifts);
    outhead1("%se:", label);

}

void plus4_keyshift( Environment * _environment, char * _shifts ) {

    // On the same way, KEY SHIFT is used to report the current status of those keys 
    // which cannot be detected by either INKEY$ or SCANCODE because they do not 
    // carry the relevant codes. These control keys cannot be tested individually, or a test 
    // can be set up for any combination of such keys pressed together. A single call to the KEY SHIFT 
    // function can test for all eventualities, by examining a bit map in the following format:

    MAKE_LABEL

    outline0("LDA #0");
    outline1("STA %s", _shifts);
    outline0("LDA $0543");
    outline0("AND #$01");
    outline1("BEQ %snoshift", label);
    outline0("LDA #3");
    outline1("STA %s", _shifts);
    outhead1("%snoshift:", label );
    outline0("LDA $0543");
    outline0("AND #$04");
    outline1("BEQ %snoctrl", label);
    outline1("LDA %s", _shifts);
    outline0("ORA #8");
    outline1("STA %s", _shifts);
    outhead1("%snoctrl:", label );

}

void plus4_clear_key( Environment * _environment ) {

    outline0("LDA #$0");
    outline0("STA $ef");
   
}

#endif