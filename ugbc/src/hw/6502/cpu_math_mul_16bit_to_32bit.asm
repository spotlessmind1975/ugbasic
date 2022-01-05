; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

CPUMATHMUL16BITTO32BIT_SOURCE       =   MATHPTR0 ; MATHPTR1
CPUMATHMUL16BITTO32BIT_DESTINATION  =   MATHPTR2 ; MATHPTR3
CPUMATHMUL16BITTO32BIT_OTHER        =   MATHPTR4 ; MATHPTR5 MATHPTR6 MATHPTR7

CPUMATHMUL16BITTO32BITD:         .BYTE $80

CPUMATHMUL16BITTO32BIT:
    LDA #$00
    STA CPUMATHMUL16BITTO32BIT_OTHER
    STA CPUMATHMUL16BITTO32BIT_OTHER+1
    STA CPUMATHMUL16BITTO32BIT_OTHER+2
    STA CPUMATHMUL16BITTO32BIT_OTHER+3
    
    LDX #$10
    
CPUMATHMUL16BITTO32BIT2:
    LSR CPUMATHMUL16BITTO32BIT_SOURCE+1
    ROR CPUMATHMUL16BITTO32BIT_SOURCE
    BCC CPUMATHMUL16BITTO32BIT3
    LDA CPUMATHMUL16BITTO32BIT_OTHER+2
    CLC
    ADC CPUMATHMUL16BITTO32BIT_DESTINATION
    STA CPUMATHMUL16BITTO32BIT_OTHER+2
    LDA CPUMATHMUL16BITTO32BIT_OTHER+3
    ADC CPUMATHMUL16BITTO32BIT_DESTINATION+1
    
CPUMATHMUL16BITTO32BIT3:
    ROR
    STA CPUMATHMUL16BITTO32BIT_OTHER+3
    ROR CPUMATHMUL16BITTO32BIT_OTHER+2
    ROR CPUMATHMUL16BITTO32BIT_OTHER+1
    ROR CPUMATHMUL16BITTO32BIT_OTHER
    DEX
    BNE CPUMATHMUL16BITTO32BIT2
    RTS

CPUMATHMUL16BITTO32BIT_SIGNED:
    LDA CPUMATHMUL16BITTO32BIT_SOURCE+1
    EOR CPUMATHMUL16BITTO32BIT_DESTINATION+1
    AND #$80
    PHA
    
    LDA CPUMATHMUL16BITTO32BIT_SOURCE+1
    BIT CPUMATHMUL16BITTO32BITD
    BEQ CPUMATHMUL16BITTO32BIT_SIGNED2

    CLC
    LDA CPUMATHMUL16BITTO32BIT_SOURCE
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_SOURCE
    LDA CPUMATHMUL16BITTO32BIT_SOURCE+1
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_SOURCE+1

    CLC
    LDA CPUMATHMUL16BITTO32BIT_SOURCE
    ADC #1
    STA CPUMATHMUL16BITTO32BIT_SOURCE
    LDA CPUMATHMUL16BITTO32BIT_SOURCE+1
    ADC #0
    STA CPUMATHMUL16BITTO32BIT_SOURCE+1

CPUMATHMUL16BITTO32BIT_SIGNED2:
    LDA CPUMATHMUL16BITTO32BIT_DESTINATION+1
    BIT CPUMATHMUL16BITTO32BITD
    BEQ CPUMATHMUL16BITTO32BIT_SIGNED3

    CLC
    LDA CPUMATHMUL16BITTO32BIT_DESTINATION
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_DESTINATION
    LDA CPUMATHMUL16BITTO32BIT_DESTINATION+1
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_DESTINATION+1

    CLC
    LDA CPUMATHMUL16BITTO32BIT_DESTINATION
    ADC #1
    STA CPUMATHMUL16BITTO32BIT_DESTINATION
    LDA CPUMATHMUL16BITTO32BIT_DESTINATION+1
    ADC #0
    STA CPUMATHMUL16BITTO32BIT_DESTINATION+1

CPUMATHMUL16BITTO32BIT_SIGNED3:
    JSR CPUMATHMUL16BITTO32BIT

    PLA
    AND #$80
    BEQ CPUMATHMUL16BITTO32BIT_SIGNED4

    CLC
    LDA CPUMATHMUL16BITTO32BIT_OTHER
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_OTHER
    LDA CPUMATHMUL16BITTO32BIT_OTHER+1
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_OTHER+1
    LDA CPUMATHMUL16BITTO32BIT_OTHER+2
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_OTHER+2
    LDA CPUMATHMUL16BITTO32BIT_OTHER+3
    EOR #$ff
    STA CPUMATHMUL16BITTO32BIT_OTHER+3

    CLC
    LDA CPUMATHMUL16BITTO32BIT_OTHER
    ADC #1
    STA CPUMATHMUL16BITTO32BIT_OTHER
    LDA CPUMATHMUL16BITTO32BIT_OTHER+1
    ADC #0
    STA CPUMATHMUL16BITTO32BIT_OTHER+1
    LDA CPUMATHMUL16BITTO32BIT_OTHER+2
    ADC #0
    STA CPUMATHMUL16BITTO32BIT_OTHER+2
    LDA CPUMATHMUL16BITTO32BIT_OTHER+3
    ADC #0
    STA CPUMATHMUL16BITTO32BIT_OTHER+3

CPUMATHMUL16BITTO32BIT_SIGNED4:
    RTS
