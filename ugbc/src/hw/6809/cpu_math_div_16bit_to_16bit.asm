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

CPUMATHDIV16BITTO16BIT
    PSHS Y,X,D,CC
    LDB #$10
    PSHS B
    CLRB
    CLRA
CPUMATHDIV16BITTO16BITL1    
    ASL 5,S
    ROL 4,S
    ROLB
    ROLA
    CMPD 6,S
    BLO CPUMATHDIV16BITTO16BITL2
    SUBD 6,S
    INC 5,S
CPUMATHDIV16BITTO16BITL2
    DEC ,S
    BNE CPUMATHDIV16BITTO16BITL1
    STD 6,S
    LEAS 1,S
    PULS Y,X,D,CC
    RTS

CPUMATHDIV16BITTO16BIT_SIGNED
    STX MATHPTR0
    TFR Y, D
    EORA MATHPTR0
    ANDA #$80
    PSHS A

    TFR X, D
    ANDA #$80
    BEQ CPUMATHDIV16BITTO16BIT_SIGNEDL1
    TFR X, D
    EORA #$FF
    EORB #$FF
    ADDD #1
    TFR D, X
    JMP CPUMATHDIV16BITTO16BIT_SIGNEDL2
CPUMATHDIV16BITTO16BIT_SIGNEDL1

CPUMATHDIV16BITTO16BIT_SIGNEDL2
    TFR Y, D
    ANDA #$80
    BEQ CPUMATHDIV16BITTO16BIT_SIGNEDL3
    TFR Y, D
    EORA #$FF
    EORB #$FF
    ADDD #1
    TFR D, Y
    JMP CPUMATHDIV16BITTO16BIT_SIGNEDL4
CPUMATHDIV16BITTO16BIT_SIGNEDL3

CPUMATHDIV16BITTO16BIT_SIGNEDL4

    JSR CPUMATHDIV16BITTO16BIT

    PULS A
    ANDA #$80
    BEQ CPUMATHDIV16BITTO16BIT_SIGNEDL5
    TFR X, D
    EORA #$ff
    EORB #$ff
    ADDD #1
    TFR D, X
CPUMATHDIV16BITTO16BIT_SIGNEDL5
    RTS