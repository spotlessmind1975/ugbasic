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
;*                          STARTUP ROUTINE ON TRS-80 COLOR COMPUTER 3         *
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

    JSR IRQSVC
    ; PSHS CC

    PSHS D
    LDA GIMEVIDM
    ANDA #$80
    CMPA #$80
    BEQ ISVCIRQGRAPH
    JMP ISVCIRQTEXT

ISVCIRQGRAPH
    LDA #$3C
    STA GIMEMMU4
    INCA
    STA GIMEMMU5
    INCA
    STA GIMEMMU6
    JMP ISVCIRQMMUOK

ISVCIRQTEXT
    LDA #$3E
    STA GIMEMMU6

ISVCIRQMMUOK

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
    STA $FFDF
    ; PULS CC
    ; PULS A
    PSHS D

    LDA GIMEVIDM
    ANDA #$80
    CMPA #$80
    BEQ ISVCIRQGRAPH2
    JMP ISVCIRQTEXT2

ISVCIRQGRAPH2
    LDA #$30
    STA GIMEMMU4
    INCA
    STA GIMEMMU5
    INCA
    STA GIMEMMU6
    JMP ISVCIRQMMUOK2

ISVCIRQTEXT2
    LDA #$30
    STA GIMEMMU6

ISVCIRQMMUOK2

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
    STA $FFDF
    JMP [OLDNMIISVC2]

COCO3STARTUP

    LDD $010D
    STD OLDISVC

    LDD #ISVCIRQ
    STD $010D

    LDD $010A
    STD OLDNMIISVC

    LDD #NMIISVCIRQ
    STD $010A

    LDA #0
    STA $011f

    LDD #$0
COCO3STARTUPL1
    ADDD #$1
    STD MATHPTR0
    CMPD #$3100
    BNE COCO3STARTUPL1

    LDA COCO3TIMER+1
    CMPA #5
    BGT COCO3NTSC

COCO3PAL
    LDA #50
    STA TICKSPERSECOND
    JMP COCO3STARTUPDONE

COCO3NTSC
    LDA #60
    STA TICKSPERSECOND
    JMP COCO3STARTUPDONE

COCO3STARTUPDONE

SYSCALLDONE
    STA $FFDF
    RTS
SYSCALL
    STA $FFDE
SYSCALL0
    JSR $0000
    BRA SYSCALLDONE
    