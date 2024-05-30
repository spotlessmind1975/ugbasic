; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      CHECK A BIT INSIDE A BYTE/WORD/DWORD                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Check a bit inside a byte/word/dword
;  - TMPPTR - address of the byte/word/dword
;  - A - position to check (0...31)
; Result in A / C flag
CPUBITCHECKEXTENDED:
    PHA
    AND #$07
    BEQ CPUBITCHECKEXTENDEDL3
    TAX
    LDA #$1
CPUBITCHECKEXTENDEDL1:
    ASL A
    DEX
    BNE CPUBITCHECKEXTENDEDL1
    JMP CPUBITCHECKEXTENDEDL2
CPUBITCHECKEXTENDEDL3:
    LDA #$1
CPUBITCHECKEXTENDEDL2:
    STA MATHPTR0
    LDY #0
    PLA
    CMP #8
    BCC CPUBITCHECKEXTENDEDB0
    CMP #16
    BCC CPUBITCHECKEXTENDEDB1
    CMP #24
    BCC CPUBITCHECKEXTENDEDB2
    JMP CPUBITCHECKEXTENDEDB3
CPUBITCHECKEXTENDEDB3:
    INY
CPUBITCHECKEXTENDEDB2:
    INY
CPUBITCHECKEXTENDEDB1:
    INY
CPUBITCHECKEXTENDEDB0:
    LDA (TMPPTR),Y
    AND MATHPTR0
    BEQ CPUBITCHECKEXTENDEDZERO
CPUBITCHECKEXTENDEDONE:
    LDA #$ff
    SEC    
    RTS
CPUBITCHECKEXTENDEDZERO:
    LDA #$0
    CLC
    RTS
