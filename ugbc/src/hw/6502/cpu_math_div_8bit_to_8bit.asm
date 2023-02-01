; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUMATHDIV8BITTO8BIT_SOURCE             =   MATHPTR0
CPUMATHDIV8BITTO8BIT_DESTINATION        =   MATHPTR1
CPUMATHDIV8BITTO8BIT_OTHER              =   MATHPTR2
CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER    =   MATHPTR3

CPUMATHDIV8BITTO8BITD:          .byte       $80

CPUMATHDIV8BITTO8BIT:
    LDA CPUMATHDIV8BITTO8BIT_SOURCE
    STA CPUMATHDIV8BITTO8BIT_OTHER
    LDA #0
    STA CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER
    LDX #8
CPUMATHDIV8BITTO8BIT2:
    ASL CPUMATHDIV8BITTO8BIT_OTHER
    ROL CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER
    LDA CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER
    SEC
    SBC CPUMATHDIV8BITTO8BIT_DESTINATION
    TAY
    BCC CPUMATHDIV8BITTO8BIT3
    STY CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER
    INC CPUMATHDIV8BITTO8BIT_OTHER
CPUMATHDIV8BITTO8BIT3:
    DEX
    BNE CPUMATHDIV8BITTO8BIT2
    RTS

CPUMATHDIV8BITTO8BIT_SIGNED:
    LDA CPUMATHDIV8BITTO8BIT_SOURCE
    EOR CPUMATHDIV8BITTO8BIT_DESTINATION
    AND #$80
    PHA
    
    LDA CPUMATHDIV8BITTO8BIT_SOURCE
    BIT CPUMATHDIV8BITTO8BITD
    BEQ CPUMATHDIV8BITTO8BIT_SIGNED2
    CLC
    LDA CPUMATHDIV8BITTO8BIT_SOURCE
    EOR #$ff
    ADC #1
    STA CPUMATHDIV8BITTO8BIT_SOURCE

CPUMATHDIV8BITTO8BIT_SIGNED2:
    LDA CPUMATHDIV8BITTO8BIT_DESTINATION
    BIT CPUMATHDIV8BITTO8BITD
    BEQ CPUMATHDIV8BITTO8BIT_SIGNED3
    CLC
    LDA CPUMATHDIV8BITTO8BIT_DESTINATION
    EOR #$ff
    ADC #1
    STA CPUMATHDIV8BITTO8BIT_DESTINATION

CPUMATHDIV8BITTO8BIT_SIGNED3:
    JSR CPUMATHDIV8BITTO8BIT

    PLA
    AND #$80
    BEQ CPUMATHDIV8BITTO8BIT_SIGNED4

    LDA CPUMATHDIV8BITTO8BIT_OTHER
    EOR #$ff
    STA CPUMATHDIV8BITTO8BIT_OTHER

    CLC
    LDA CPUMATHDIV8BITTO8BIT_OTHER
    ADC #1
    STA CPUMATHDIV8BITTO8BIT_OTHER

CPUMATHDIV8BITTO8BIT_SIGNED4:
    RTS
