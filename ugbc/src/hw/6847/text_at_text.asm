; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
    LDA <TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO
    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS
    LDA #0
    STA <TABSTODRAW

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
    STX <COPYOFTEXTADDRESS
    LDB <YCURSYS
    BEQ CALCPOSSKIP
CALCPOSLOOP1
    ANDCC #$FE
    LDX <COPYOFTEXTADDRESS
    LDA CURRENTTILESWIDTH
    LEAX A, X
    STX <COPYOFTEXTADDRESS
    DECB
    BNE CALCPOSLOOP1

CALCPOSSKIP
    ANDCC #$FE
    LDA #0
    LDB <XCURSYS
    ADDD <COPYOFTEXTADDRESS
    STD <COPYOFTEXTADDRESS
    LDX <COPYOFTEXTADDRESS
    RTS

TEXTAT0
TEXTAT1
TEXTAT2
TEXTAT3
TEXTAT4
TEXTAT5
TEXTAT6
    JSR CALCPOS0

    LDB <TEXTSIZE
TEXTATLOOP2

    LDA <TABSTODRAW
    BEQ TEXTATNSKIPTAB
    JMP TEXTATSKIPTAB

TEXTATNSKIPTAB
    LDA ,Y

    CMPA #31
    BHI TEXTATXCC
    JMP TEXTATCC

TEXTATXCC
    JSR TEXTATDECODE
    JMP TEXTATSP0

TEXTATTAB
    LDA <XCURSYS
TEXTATTAB2
    CMPA TABCOUNT
    BLO TEXTATTAB3
    ANDCC #$01
    SUBA TABCOUNT
    JMP TEXTATTAB2
TEXTATTAB3
    STA <TMPPTR
    LDA TABCOUNT
    ANDCC #$01
    SUBA <TMPPTR
    STA <TABSTODRAW
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
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT2

TEXTATPEN
    LEAY 1,Y
    DECB
    LDA , Y
    CMPA #$FF
    BNE TEXTATPEN2
    LDA #$0
TEXTATPEN2
    STA _PEN
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATPAPER
    LEAY 1,Y
    DECB
    LDA , Y
    STA $d021
    STA $d020
    LEAY 1,Y
    DECB
    JMP TEXTATNEXT

TEXTATCMOVEPREPARE
    LEAY 1,Y
    DECB
    LDA , Y
    ADDA <XCURSYS
    CMPA CONSOLEX1
    BLT TEXTATCMOVEPREPARESKIPX
    CMPA CONSOLEX2
    BGT TEXTATCMOVEPREPARESKIPX
    STA <XCURSYS
TEXTATCMOVEPREPARESKIPX
    LEAY 1,Y
    DECB
    LDA , Y
    ADDA YCURSYS
    CMPA CONSOLEY1
    BLT TEXTATCMOVEPREPARESKIPY
    CMPA CONSOLEY2
    BGT TEXTATCMOVEPREPARESKIPY
    STA YCURSYS
TEXTATCMOVEPREPARESKIPY
    JSR CALCPOS
    JMP TEXTATNEXTX

TEXTATAT
    LEAY 1,Y
    DECB
    LDA , Y
    ADDA CONSOLEX1
    CMPA CONSOLEX2
    BGT TEXTATATSKIPX
    STA <XCURSYS
TEXTATATSKIPX
    LEAY 1,Y
    DECB
    LDA , Y
    ADDA CONSOLEY1
    CMPA CONSOLEY2
    BGT TEXTATATSKIPY
    STA YCURSYS
TEXTATATSKIPY
    JSR CALCPOS
    JMP TEXTATNEXTX

TEXTATSP0
    STA , X
    LEAY 1, Y
    LDA _PEN
    ; STA (COPYOFCOLORMAPADDRESS),Y
    JMP TEXTATINCX

TEXTATSKIPTAB
    INC <XCURSYS
    DEC <TABSTODRAW
    BNE TEXTATSKIPTAB2
    DECB
TEXTATSKIPTAB2
    JMP TEXTATNEXTX

TEXTATINCX
    INC <XCURSYS
    DECB
    LBEQ TEXTATEND2
TEXTATNEXTX
    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATNEXT2
    JMP TEXTATNEXT
TEXTATNEXT2
    LDA CONSOLEX1
    STA <XCURSYS
    LDA CURRENTTILESWIDTH
    SUBA CONSOLEW
    LEAX A,X
    INC <YCURSYS
    LDA <YCURSYS
    CMPA CONSOLEY2
    BGT TEXTATNEXT3
    JMP TEXTATNEXT
TEXTATNEXT3

    LDA #$FE
    STA <DIRECTION
    JSR VSCROLLT

    DEC <YCURSYS
    ANDCC #$01
    PSHS D
    LDB CURRENTTILESWIDTH
    CLRA
    NEGA
    NEGB
    SBCA #0
    ; ADDD #1
    LEAX D, X
    PULS D

TEXTATNEXT
    LDA <TABSTODRAW
    BEQ TEXTATXLOOP2
    JMP TEXTATLOOP2
TEXTATXLOOP2
    LEAX 1, X
    CMPB #0
    BEQ TEXTATEND
    JMP TEXTATLOOP2
TEXTATEND2
TEXTATEND
    
    RTS
