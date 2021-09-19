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

CPUMATHMUL8BITTO16BIT_SOURCE          =   MATHPTR1
CPUMATHMUL8BITTO16BIT_DESTINATION     =   MATHPTR0
CPUMATHMUL8BITTO16BIT_OTHER           =   MATHPTR2 ; MATHPTR3

CPUMATHMUL8BITTO16BIT:
    LDA #0
    LDX #8
CPUMATHMUL8BITTO16BIT2:
    LSR CPUMATHMUL8BITTO16BIT_DESTINATION
    BCC CPUMATHMUL8BITTO16BIT3
    CLC
    ADC CPUMATHMUL8BITTO16BIT_SOURCE
CPUMATHMUL8BITTO16BIT3:
    ROR A
    ROR CPUMATHMUL8BITTO16BIT_OTHER
    DEX
    BNE CPUMATHMUL8BITTO16BIT2
    STA CPUMATHMUL8BITTO16BIT_OTHER+1
    RTS

CPUMATHMUL8BITTO16BIT_SIGNED:

    LDA CPUMATHMUL8BITTO16BIT_SOURCE
    EOR CPUMATHMUL8BITTO16BIT_DESTINATION
    AND #$80
    PHA
    
    LDA CPUMATHMUL8BITTO16BIT_SOURCE
    BIT #$80
    BEQ CPUMATHMUL8BITTO16BIT_SIGNED2
    CLC
    LDA CPUMATHMUL8BITTO16BIT_SOURCE
    EOR #$ff
    ADC #1
    STA CPUMATHMUL8BITTO16BIT_SOURCE

CPUMATHMUL8BITTO16BIT_SIGNED2:
    LDA CPUMATHMUL8BITTO16BIT_DESTINATION
    BIT #$80
    BEQ CPUMATHMUL8BITTO16BIT_SIGNED3
    CLC
    LDA CPUMATHMUL8BITTO16BIT_DESTINATION
    EOR #$ff
    ADC #1
    STA CPUMATHMUL8BITTO16BIT_DESTINATION

CPUMATHMUL8BITTO16BIT_SIGNED3:
    JSR CPUMATHMUL8BITTO16BIT

    PLA
    AND #$80
    BEQ CPUMATHMUL8BITTO16BIT_SIGNED4

    LDA CPUMATHMUL8BITTO16BIT_OTHER
    EOR #$ff
    STA CPUMATHMUL8BITTO16BIT_OTHER
    LDA CPUMATHMUL8BITTO16BIT_OTHER+1
    EOR #$ff
    STA CPUMATHMUL8BITTO16BIT_OTHER+1

    CLC
    LDA CPUMATHMUL8BITTO16BIT_OTHER
    ADC #1
    STA CPUMATHMUL8BITTO16BIT_OTHER
    LDA CPUMATHMUL8BITTO16BIT_OTHER+1
    ADC #0
    STA CPUMATHMUL8BITTO16BIT_OTHER+1

CPUMATHMUL8BITTO16BIT_SIGNED4:
    RTS

