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
;*                          STARTUP ROUTINE ON TRS-80 COLOR COMPUTER           *
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
    JSR IRQSVC
    ; PSHS CC
    PSHS D
    TFR CC, A
    ANDA #$EF
    STA OLDCC
    JSR TIMERMANAGER
    LDD COCOTIMER
    ADDD #$1
    STD COCOTIMER
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
    PSHS D
    LDA RAMENABLED
    BEQ ISVCIRQ2NORAM
    STA $FFDF
ISVCIRQ2NORAM
    ; PULS CC
    ; PULS A
    LDA OLDCC
    TFR A, CC
    PULS D
    JMP [OLDISVC2]

NMIISVCIRQ
    PSHS D
    PSHS X
    LDD COCOTIMER
    ADDD #$1
    STD COCOTIMER
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

COCOSTARTUP

    LDD OLDISVC
    BNE COCOSTARTUPNOIRQREDEF

    LDD OLDNMIISVC
    BNE COCOSTARTUPNOIRQREDEF

    LDD $010D
    STD OLDISVC

    LDD #ISVCIRQ
    STD $010D

    LDD $010A
    STD OLDNMIISVC

    LDD #NMIISVCIRQ
    STD $010A

COCOSTARTUPNOIRQREDEF

    LDA #0
    STA $011f

@IF dataSegment
    LDD #DATAFIRSTSEGMENT
    STD DATAPTR
@ENDIF

    LDD #$0
COCOSTARTUPL1
    ADDD 1
    STD MATHPTR0
    CMPD #$3100
    BNE COCOSTARTUPL1

    LDA COCOTIMER+1
    CMPA #5
    BGT COCONTSC

COCOPAL
    LDA #50
    STA TICKSPERSECOND
    JMP COCOSTARTUPDONE

COCONTSC
    LDA #60
    STA TICKSPERSECOND
    JMP COCOSTARTUPDONE

COCOSTARTUPDONE

@IF deployed.dcommon
    JSR COCODCOMMONSETUP
@ENDIF

SYSCALLDONE
    LDA #$01
    STA $FFDF
    STA RAMENABLED
    RTS
SYSCALL
    STA $FFDE
    CLR RAMENABLED
SYSCALL0
    JSR $0000
    BRA SYSCALLDONE
    