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
;*                          STARTUP ROUTINE ON TRS-80 COLOR COMPUTER 3         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

RESET
    STA $FFDE
    JMP [$FFFE]

COCO3BSTARTUP

    LDMD #1

    LDD OLDISVC
    BNE COCO3BSTARTUPNOIRQ

    LDD OLDISVC2
    BNE COCO3BSTARTUPNOIRQ

    LDD $010D
    STD OLDISVC

    LDD #ISVCIRQ
    STD $010D

    LDD $010A
    STD OLDNMIISVC

    LDD #NMIISVCIRQ
    STD $010A

COCO3BSTARTUPNOIRQ

    LDA #0
    STA $011f

    LDA $FF03
    ORA #$01
    STA $FF03

    LDD #$0
COCO3BSTARTUPL1
    ADDD #$1
    STD <MATHPTR0
    CMPD #$3100
    BNE COCO3BSTARTUPL1

    LDD COCO3BTIMER
    CMPD #$000d
    BGT COCO3BNTSC

COCO3BPAL
    LDA #50
    STA TICKSPERSECOND
    JMP COCO3BSTARTUPDONE

COCO3BNTSC
    LDA #60
    STA TICKSPERSECOND
    JMP COCO3BSTARTUPDONE

COCO3BSTARTUPDONE

@IF deployed.dcommon
    JSR COCO3BDCOMMONSETUP
@ENDIF

@IF dataSegment
    LDD #DATAFIRSTSEGMENT
    STD DATAPTR
@ENDIF

    RTS

WAITTIMER
    LDX COCO3BTIMER
WAITTIMERL1
    CMPX COCO3BTIMER
    BEQ WAITTIMERL1
    SUBD #1
    CMPD #0
    BNE WAITTIMER
    RTS
    