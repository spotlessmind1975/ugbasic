; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;  - X - address of the byte/word/dword
;  - A - position to check (0...31)
; Result in A / C flag
CPUBITCHECKEXTENDED
    PSHS D
    TFR A, B
    ANDB #$07
    BEQ CPUBITCHECKEXTENDEDL3
    LDA #$1
CPUBITCHECKEXTENDEDL1
    ASLA
    DECB
    BNE CPUBITCHECKEXTENDEDL1
    JMP CPUBITCHECKEXTENDEDL2
CPUBITCHECKEXTENDEDL3
    LDA #$1
CPUBITCHECKEXTENDEDL2
    STA <MATHPTR0
    PULS D
    CMPA #8
    BCS CPUBITCHECKEXTENDEDB0
    CMPA #16
    BCS CPUBITCHECKEXTENDEDB1
    CMPA #24
    BCS CPUBITCHECKEXTENDEDB2
    JMP CPUBITCHECKEXTENDEDB3
CPUBITCHECKEXTENDEDB3
    LEAX -1, X
CPUBITCHECKEXTENDEDB2
    LEAX -1, X
CPUBITCHECKEXTENDEDB1
    LEAX -1, X
CPUBITCHECKEXTENDEDB0
    LDA <MATHPTR0
    LDB , X
    ANDB <MATHPTR0
    BEQ CPUBITCHECKEXTENDEDZERO
CPUBITCHECKEXTENDEDONE
    LDA #$ff
    ORCC #$01
    RTS
CPUBITCHECKEXTENDEDZERO
    LDA #$0
    ANDCC #$FE
    RTS
