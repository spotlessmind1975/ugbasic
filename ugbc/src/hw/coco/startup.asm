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
;*                          STARTUP ROUTINE ON TRS-80 COLOR COMPUTER           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
    STD <MATHPTR0
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

@IF deployed.serial && deployed.fujinet
    JSR FUJINETREADY
@ENDIF

@IF sysCallUsed

SYSCALLDONE

@ENDIF

    LDA #$01
    STA $FFDF
    STA RAMENABLED
    RTS

@IF sysCallUsed

SYSCALL
    STA $FFDE
    CLR RAMENABLED
SYSCALL0
    JSR $0000
    BRA SYSCALLDONE
    
@ENDIF

WAITTIMER
    LDX COCOTIMER
WAITTIMERL1
    CPX COCOTIMER
    BEQ WAITTIMERL1
    SUBD #1
    CMPD #0
    BNE WAITTIMER
    RTS
    
