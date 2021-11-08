; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

CPUMATHDIV16BITTO16BIT_SOURCE           = MATHPTR0 ; MATHPTR1
CPUMATHDIV16BITTO16BIT_DESTINATION      = MATHPTR2 ; MATHPTR3
CPUMATHDIV16BITTO16BIT_OTHER            = MATHPTR4 ; MATHPTR5
CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER  = MATHPTR6 ; MATHPTR7

CPUMATHDIV16BITTO16BITD:            .BYTE       $80

CPUMATHDIV16BITTO16BIT:
    LDA CPUMATHDIV16BITTO16BIT_SOURCE
    STA CPUMATHDIV16BITTO16BIT_OTHER
    LDA CPUMATHDIV16BITTO16BIT_SOURCE+1
    STA CPUMATHDIV16BITTO16BIT_OTHER+1

    LDA #0
    STA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER
    STA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1
    LDX #16

CPUMATHDIV16BITTO16BITL1:    
    ASL CPUMATHDIV16BITTO16BIT_OTHER
    ROL CPUMATHDIV16BITTO16BIT_OTHER+1
    ROL CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER
    ROL CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1
    
    LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER
    SEC
    SBC CPUMATHDIV16BITTO16BIT_DESTINATION 
    TAY
    
    LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1
    SBC CPUMATHDIV16BITTO16BIT_DESTINATION+1
    BCC CPUMATHDIV16BITTO16BITL2
    STA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1
    STY CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER 
    INC CPUMATHDIV16BITTO16BIT_OTHER

CPUMATHDIV16BITTO16BITL2:
    DEX
    BNE CPUMATHDIV16BITTO16BITL1
    RTS

CPUMATHDIV16BITTO16BIT_SIGNED:
    LDA CPUMATHDIV16BITTO16BIT_SOURCE+1
    EOR CPUMATHDIV16BITTO16BIT_DESTINATION+1
    AND #$80
    PHA
    
    LDA CPUMATHDIV16BITTO16BIT_SOURCE+1
    BIT CPUMATHDIV16BITTO16BITD
    BEQ CPUMATHDIV16BITTO16BIT_SIGNED2

    CLC
    LDA CPUMATHDIV16BITTO16BIT_SOURCE
    EOR #$ff
    STA CPUMATHDIV16BITTO16BIT_SOURCE
    LDA CPUMATHDIV16BITTO16BIT_SOURCE+1
    EOR #$ff
    STA CPUMATHDIV16BITTO16BIT_SOURCE+1

    CLC
    LDA CPUMATHDIV16BITTO16BIT_SOURCE
    ADC #1
    STA CPUMATHDIV16BITTO16BIT_SOURCE
    LDA CPUMATHDIV16BITTO16BIT_SOURCE+1
    ADC #0
    STA CPUMATHDIV16BITTO16BIT_SOURCE+1

CPUMATHDIV16BITTO16BIT_SIGNED2:
    LDA CPUMATHDIV16BITTO16BIT_DESTINATION+1
    BIT CPUMATHDIV16BITTO16BITD
    BEQ CPUMATHDIV16BITTO16BIT_SIGNED3

    CLC
    LDA CPUMATHDIV16BITTO16BIT_DESTINATION
    EOR #$ff
    STA CPUMATHDIV16BITTO16BIT_DESTINATION
    LDA CPUMATHDIV16BITTO16BIT_DESTINATION+1
    EOR #$ff
    STA CPUMATHDIV16BITTO16BIT_DESTINATION+1

    CLC
    LDA CPUMATHDIV16BITTO16BIT_DESTINATION
    ADC #1
    STA CPUMATHDIV16BITTO16BIT_DESTINATION
    LDA CPUMATHDIV16BITTO16BIT_DESTINATION+1
    ADC #0
    STA CPUMATHDIV16BITTO16BIT_DESTINATION+1

CPUMATHDIV16BITTO16BIT_SIGNED3:
    JSR CPUMATHDIV16BITTO16BIT

    PLA
    AND #$80
    BEQ CPUMATHDIV16BITTO16BIT_SIGNED4

    CLC
    LDA CPUMATHDIV16BITTO16BIT_OTHER
    EOR #$ff
    STA CPUMATHDIV16BITTO16BIT_OTHER
    LDA CPUMATHDIV16BITTO16BIT_OTHER+1
    EOR #$ff
    STA CPUMATHDIV16BITTO16BIT_OTHER+1

    CLC
    LDA CPUMATHDIV16BITTO16BIT_OTHER
    ADC #1
    STA CPUMATHDIV16BITTO16BIT_OTHER
    LDA CPUMATHDIV16BITTO16BIT_OTHER+1
    ADC #0
    STA CPUMATHDIV16BITTO16BIT_OTHER+1

CPUMATHDIV16BITTO16BIT_SIGNED4:
    RTS
