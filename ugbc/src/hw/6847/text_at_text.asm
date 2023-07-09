; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      TEXT AT GIVEN POSITION ON 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATTILEMODE
    LDA TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO
    LDY TEXTADDRESS
    STY COPYOFTEXTADDRESS
    LDA #0
    STA TABSTODRAW

    LDY TEXTPTR
    LDA CURRENTMODE
    CMPA #0
    BNE TEXTAT0X
    JMP TEXTAT0
TEXTAT0X
    CMPA #1
    BNE TEXTAT1X
    JMP TEXTAT1
TEXTAT1X
    CMPA #2
    BNE TEXTAT2X
    JMP TEXTAT2
TEXTAT2X
    CMPA #3
    BNE TEXTAT3X
    JMP TEXTAT3
TEXTAT3X
    CMPA #4
    BNE TEXTAT4X
    JMP TEXTAT4
TEXTAT4X
    CMPA #5
    BNE TEXTAT5X
    JMP TEXTAT5
TEXTAT5X
    CMPA #6
    BNE TEXTAT6X
    JMP TEXTAT6
TEXTAT6X
    RTS

CALCPOS
    LDA CURRENTMODE
    CMPA #0
    BNE CALCPOS0X
    JSR CALCPOS0
    RTS
CALCPOS0X
    CMPA #1
    BNE CALCPOS1X
    JSR CALCPOS1
    RTS
CALCPOS1X
    CMPA #2
    BNE CALCPOS2X
    JSR CALCPOS2
    RTS
CALCPOS2X
    CMPA #3
    BNE CALCPOS3X
    JSR CALCPOS3
    RTS
CALCPOS3X
    CMPA #4
    BNE CALCPOS4X
    JSR CALCPOS4
    RTS
CALCPOS4X
    CMPA #5
    BNE CALCPOS5X
    JSR CALCPOS5
    RTS
CALCPOS5X
    CMPA #6
    BNE CALCPOS6X
    JSR CALCPOS6
    RTS
CALCPOS6X
    RTS

CALCPOS0
CALCPOS1
CALCPOS2
CALCPOS3
CALCPOS4
CALCPOS5
CALCPOS6
    LDX TEXTADDRESS
    STX COPYOFTEXTADDRESS
    LDB YCURSYS
    BEQ CALCPOSSKIP
CALCPOSLOOP1
    ANDCC #$FE
    LDX COPYOFTEXTADDRESS
    LEAX 32, X
    STX COPYOFTEXTADDRESS
    DECB
    BNE CALCPOSLOOP1

CALCPOSSKIP
    ANDCC #$FE
    LDA #0
    LDB XCURSYS
    ADDD COPYOFTEXTADDRESS
    STD COPYOFTEXTADDRESS
    LDX COPYOFTEXTADDRESS
    RTS

TEXTAT0
TEXTAT1
TEXTAT2
TEXTAT3
TEXTAT4
TEXTAT5
TEXTAT6
    JSR CALCPOS0

    LDB TEXTSIZE
TEXTATLOOP2

    LDA TABSTODRAW
    BEQ TEXTATNSKIPTAB
    JMP TEXTATSKIPTAB

TEXTATNSKIPTAB
    LDA ,Y

    CMPA #31
    BHI TEXTATXCC
    JMP TEXTATCC

TEXTATXCC
    JMP TEXTATSP0

TEXTATTAB
    LDA XCURSYS
TEXTATTAB2
    CMPA TABCOUNT
    BLO TEXTATTAB3
    ANDCC #$01
    SUBA TABCOUNT
    JMP TEXTATTAB2
TEXTATTAB3
    STA TMPPTR
    LDA TABCOUNT
    ANDCC #$01
    SUBA TMPPTR
    STA TABSTODRAW
    JMP TEXTATNEXT

TEXTATCC
    CMPA #13
    BEQ TEXTATLF
    CMPA #10
    BEQ TEXTATLF
    CMPA #09
    BEQ TEXTATTAB
    CMPA #01
    BEQ TEXTATPEN
    CMPA #02
    BEQ TEXTATPAPER
    CMPA #03
    BEQ TEXTATCMOVEPREPARE
    CMPA #04
    BEQ TEXTATXAT
    CMPA #05
    BEQ TEXTATCLS
    JMP TEXTATNEXT

TEXTATCLS
    LEAY 1,Y
    DECB
    JSR CLST
    JMP TEXTATNEXT

TEXTATXAT
    JMP TEXTATAT

TEXTATLF
    LDA CURRENTTILESWIDTH
    SUBA XCURSYS
    SUBA #1
    LEAX A,X
    LEAY 1,Y
    JMP TEXTATNEXT2

TEXTATPEN
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATPENDISABLED
    LDA , Y
    CMPA #$FF
    BNE TEXTATPEN2
    LDA #$0
TEXTATPEN2
    STA _PEN
TEXTATPENDISABLED
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATPAPER
    LEAY 1,Y
    DECB
    LDA TEXTWW
     ANDA #$1
    BEQ TEXTATPAPERDISABLED
    LDA , Y
    STA $d021
    STA $d020
TEXTATPAPERDISABLED
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATCMOVEPREPARE
    LEAY 1,Y
    DECB
    LDA , Y
    STA CLINEX
    LEAY 1,Y
    DECB
    LDA , Y
    STA CLINEY

TEXTATCMOVE
    ANDCC #$FE
    LDA CLINEX
    ADDA XCURSYS
    CMPA #$0
    BLT TEXTATCMOVESKIPX
    CMPA CURRENTWIDTH+1
    BGE TEXTATCMOVESKIPX
    STA XCURSYS
    LDA CLINEX
    LDX COPYOFTEXTADDRESS
    LEAX A, X
    STX COPYOFTEXTADDRESS

TEXTATCMOVESKIPX
    ANDCC #$FE
    LDA CLINEY
    ADDA YCURSYS
    CMPA #$0
    BLT TEXTATCMOVESKIPY
    CMPA CURRENTHEIGHT+1
    BGE TEXTATCMOVESKIPY
    STA YCURSYS

    LDB YCURSYS
    LDA CURRENTWIDTH+1
TEXTATCMOVELOOPY
    ANDCC #$FE
    LDX COPYOFTEXTADDRESS
    LEAX A, X
    STX COPYOFTEXTADDRESS
    DECB
    BNE TEXTATCMOVELOOPY

TEXTATCMOVESKIPY
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATAT
    LEAY 1,Y
    DECB
    LDA , Y
    ANDCC #$01
    SUBA XCURSYS
    STA CLINEX
    LEAY 1,Y
    DECB
    LDA , Y
    ANDCC #$01
    SUBA YCURSYS
    STA CLINEY
    JMP TEXTATCMOVE

TEXTATSP0
    STA , X
    LEAY 1, Y
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATCNOPEN
    LDA _PEN
    ; STA (COPYOFCOLORMAPADDRESS),Y
TEXTATCNOPEN
    JMP TEXTATINCX

TEXTATSKIPTAB
    DEC TABSTODRAW
    JMP TEXTATINCX

TEXTATINCX
    INC XCURSYS
    LDA XCURSYS
    CMPA #32
    BEQ TEXTATNEXT2
    JMP TEXTATNEXT
TEXTATNEXT2
    LDA #0
    STA XCURSYS
    INC YCURSYS
    STX COPYOFTEXTADDRESS
    LDA YCURSYS
    CMPA #16

    BEQ TEXTATNEXT3
    JMP TEXTATNEXT
TEXTATNEXT3

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

    DEC YCURSYS
    ANDCC #$01
    LDX COPYOFTEXTADDRESS
    LEAX -32, X
    STX COPYOFTEXTADDRESS

TEXTATNEXT
    LDA TABSTODRAW
    BEQ TEXTATXLOOP2
    JMP TEXTATLOOP2
TEXTATXLOOP2
    LEAX 1, X
    DECB
    BEQ TEXTATEND
    JMP TEXTATLOOP2
TEXTATEND
    
    RTS
