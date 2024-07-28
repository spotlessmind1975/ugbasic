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
;*                          IRQ MANAGEMENT ON TRS-80 COLOR COMPUTER 3          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IRQSVC
    PSHS D
    PSHS X
    PSHS Y
    PSHS U
    PSHS DP
    PSHS CC
IRQSVC2
    NOP
    NOP
    NOP
    PULS CC
    PULS DP
    PULS U
    PULS Y
    PULS X
    PULS D
    RTS
    
OLDISVC
    fdb $0

OLDISVC2
    fdb $0

OLDNMIISVC
    fdb $0

OLDNMIISVC2
    fdb $0

OLDCC
    fcb $0

ISVCIRQ

    PSHS D
    TFR CC, A
    ANDA #$EF
    STA OLDCC
    PULS D

    ; PSHS CC

    PSHS D

    LDA GIMEVIDMSHADOW
    BEQ SKIPGIMEROM

    JSR GIMEBANKSAVE
    JSR GIMEBANKROM

SKIPGIMEROM    

    LDA GIMEMMU6
    STA BANKSHADOWSHADOW
    LDA #$3e
    STA GIMEMMU6

    JSR TIMERMANAGER
    JSR KEYBOARDMANAGER
    JSR MUSICPLAYER

    JSR IRQSVC

    LDD COCO3TIMER
    ADDD #$1
    STD COCO3TIMER
    PSHS X
    LDD #0
    STD $00e3
    STA $FFDE
    TFR S, X
    LEAX +14,X
    LDD ,X
    STD OLDISVC2
    LDD #ISVCIRQ2
    STD ,X
    PULS X
    PULS D
    JMP [OLDISVC]
ISVCIRQ2
    ; PULS CC
    ; PULS A
    PSHS D
    LDA RAMENABLED
    BEQ ISVCIRQ2NORAM
    STA $FFDF
ISVCIRQ2NORAM
    LDA GIMEVIDMSHADOW
    BEQ ISVCIRQMMUOK2

    JSR GIMEBANKRESTORE

ISVCIRQMMUOK2

    LDA BANKSHADOWSHADOW
    STA GIMEMMU6

    LDA OLDCC

    TFR A, CC

    PULS D
    JMP [OLDISVC2]

NMIISVCIRQ
    PSHS D
    PSHS X
    LDD COCO3TIMER
    ADDD #$1
    STD COCO3TIMER
    LDD #0
    STD $00e3
    STA $FFDE
    TFR S, X
    LEAX +14,X
    LDD ,X
    STD OLDNMIISVC2
    LDD #NMIISVCIRQ2
    STD ,X
    PULS X
    PULS D
    JMP [OLDNMIISVC]
NMIISVCIRQ2
    PSHS D
    LDA RAMENABLED
    BEQ NMIISVCIRQ2NORAM
    STA $FFDF
NMIISVCIRQ2NORAM
    PULS D
    JMP [OLDNMIISVC2]

SYSCALLDONE
    STA $FFDF
    RTS
SYSCALL
    STA $FFDE
SYSCALL0
    JSR $0000
    BRA SYSCALLDONE
    