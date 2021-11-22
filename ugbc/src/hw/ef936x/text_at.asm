; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                      TEXT AT GIVEN POSITION ON EF936X                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
TEXTPEN equ $06
TEXTPAPER equ $07
SCREENCODE equ $08

TEXTATDECODE
    CMPA #$1F
    BHI TEXTATDECODEX1F
    LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODEX1F
    CMPA #$40
    BHS TEXTATDECODEX39
    ADDA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX39
    CMPA #$5F
    BHI TEXTATDECODEX5A
    SUBA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX5A
    CMPA #$7F
    BHI TEXTATDECODEX7F
    SUBA #$20
    JMP TEXTATDECODE0
TEXTATDECODEX7F
    LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODE0
    STA <SCREENCODE
    RTS

TEXTAT
    LDA <TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO
    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS
    LDA #0
    STA <TABSTODRAW
    LDA _PAPER
    STA <TEXTPAPER

    LDY <TEXTPTR
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
    RTS
    
;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATCALCPOS
    PSHS D,Y

    LDA CURRENTMODE
    CMPA #3
    BEQ TEXTATCALCPOS3

    LDX BITMAPADDRESS
    ANDCC #$FE
    LDB YCURSYS
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    TFR D, Y

    ANDCC #$FE
    LDB YCURSYS
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA

    LEAY D, Y
    TFR Y, D
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LEAX D, X

    PULS D,Y

    RTS

TEXTATCALCPOS3

    LDB <(YCURSYS)
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    ADDD #PLOTVBASE
    TFR D, X
    LDD , X
    TFR D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LEAX B, X

    PULS D,Y

    RTS

TEXTATBITMAPMODE

TEXTAT0
TEXTAT1
TEXTAT2
TEXTAT3
TEXTAT4

    JSR TEXTATCALCPOS

    JMP TEXTATCOMMON

TEXTATCOMMON

    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATBMCNOPEN

    ANDCC #$FE
    LDA _PEN
    ANDA #$0F
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    LDA _PAPER
    ANDA #$0F
    ORA <MATHPTR5
    STA <MATHPTR5

TEXTATBMCNOPEN

    LDB <TEXTSIZE
    LDY <TEXTPTR
TEXTATBMLOOP2

    LDA <TABSTODRAW
    BEQ TEXTATBMNSKIPTAB
    JMP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB
    LDA ,Y
    STA <SCREENCODE

    CMPA #$09
    BEQ TEXTATBMTAB
    CMPA #10
    BHI TEXTATBMXCC
    JMP TEXTATBMCC

TEXTATBMXCC
    JSR TEXTATDECODE
    JMP TEXTATBMSP0

TEXTATBMTAB
    LDA XCURSYS
TEXTATBMTAB2
    CMPA TABCOUNT
    BLS TEXTATBMTAB3
    SUBA TABCOUNT
    JMP TEXTATBMTAB2
TEXTATBMTAB3
    STA <TMPPTR
    LDA TABCOUNT
    SUBA <TMPPTR
    STA <TABSTODRAW
    JMP TEXTATBMNEXT

TEXTATBMCC
    CMPA #01
    BEQ TEXTATBMPEN
    CMPA #02
    BEQ TEXTATBMPAPER
    CMPA #03
    BEQ TEXTATBMCMOVEPREPARE
    CMPA #04
    BEQ TEXTATBMXAT
    JMP TEXTATBMNEXT

TEXTATBMXAT
    JMP TEXTATBMAT

TEXTATBMPEN
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATBMPENDISABLED
    LDA , Y
    ASL A
    ASL A
    ASL A
    ASL A
    STA <TEXTPEN
TEXTATBMPENDISABLED
    JMP TEXTATBMNEXT

TEXTATBMPAPER
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$1
    BEQ TEXTATBMPAPERDISABLED
    LDA , Y
    STA <TEXTPAPER
TEXTATBMPAPERDISABLED
    JMP TEXTATBMNEXT

TEXTATBMCMOVEPREPARE
    LEAY 1,Y
    DECB
    LDA , Y
    STA <CLINEX
    LEAY 1,Y
    LEAX -1,X
    LDA , Y
    STA <CLINEY

TEXTATBMCMOVE
    LDA <CLINEX
    ADDA XCURSYS
    STA XCURSYS
    LDA <CLINEY
    ADDA YCURSYS
    STA YCURSYS

    JSR TEXTATCALCPOS

    JMP TEXTATBMNEXT

TEXTATBMAT
    LEAY 1,Y
    DECB
    LDA , Y
    SUBA XCURSYS
    STA <CLINEX
    LEAY 1,Y
    LEAX -1,X
    LDA , Y
    SUBA YCURSYS
    STA <CLINEY
    JMP TEXTATBMCMOVE

TEXTATBMSP0

    PSHS D,Y,X

    LDU #0
    LDY #TEXTATFONT
    LDA <SCREENCODE
    ANDA #$3F
    LDB #8
    MUL
    LEAY D, Y

    LDA CURRENTMODE
    CMPA #0
    BNE TEXTATBMSP00X
    JMP TEXTATBMSP00
TEXTATBMSP00X
    CMPA #1
    BNE TEXTATBMSP01X
    JMP TEXTATBMSP01
TEXTATBMSP01X
    CMPA #2
    BNE TEXTATBMSP02X
    JMP TEXTATBMSP02
TEXTATBMSP02X
    CMPA #3
    BNE TEXTATBMSP03X
    JMP TEXTATBMSP03
TEXTATBMSP03X
    CMPA #4
    BNE TEXTATBMSP04X
    JMP TEXTATBMSP04
TEXTATBMSP04X
    JMP TEXTATBMSP0E

TEXTATBMSP00
TEXTATBMSP01
TEXTATBMSP04

TEXTATBMSP0L1

    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA ,Y
    STA ,X

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDA <MATHPTR5
    STA ,X

    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M

    PSHS X

    LDX <MATHPTR5

    LDA ,Y

    ANDA #$F0
    LSRA
    LSRA
    LSRA
    LSRA

    LDA A, X

    PULS X

    STA , X

    LEAX 1, X

    PSHS X

    LDX <MATHPTR5

    LDA ,Y

    ANDA #$0F

    LDA A, X

    PULS X

    STA , X

    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP0L1X
    JMP TEXTATBMSP0L1

TEXTATBMSP0L1X
    LDA #1
    JMP TEXTATBMSP0E

TEXTATBMSP02

TEXTATBMSP02L1

    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA _PEN
    ANDA #$01
    CMPA #$01
    BEQ TEXTATBMSP02L1NO
    LDA ,Y
    STA ,X
    JMP TEXTATBMSP02L1DONE

TEXTATBMSP02L1NO
    LDA #0
    STA ,X

TEXTATBMSP02L1DONE

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDA _PEN
    ANDA #$02
    CMPA #$02
    BEQ TEXTATBMSP02L2NO
    LDA ,Y
    STA ,X
    JMP TEXTATBMSP02L2DONE

TEXTATBMSP02L2NO
    LDA #0
    STA ,X

TEXTATBMSP02L2DONE

    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP02L1X
    JMP TEXTATBMSP02L1

TEXTATBMSP02L1X
    LDA #1
    JMP TEXTATBMSP0E

;

TEXTATBMSP03

    LDA ,Y

    PSHS Y,A
    LDY #TEXTATFLIP
    ANDA #$0F
    LEAY A, Y
    LDA , Y
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR0
    PULS Y,A

    PSHS Y,A
    LDY #TEXTATFLIP
    ANDA #$F0
    LSRA
    LSRA
    LSRA
    LSRA
    LEAY A, Y
    LDA , Y
    ORA <MATHPTR0
    STA <MATHPTR0
    PULS Y,A

    PSHS U
    LDU #2

TEXTATBMSP03L1

    LDA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATBITMASK
    LDB A, Y
    LDA _PEN
    ANDA #$0F
    MUL
    TFR B, A
    PULS Y

    LDB $a7c0
    ORB #$01
    STB $a7c0

    STA ,X

    LDA <MATHPTR0
    LSRA
    LSRA
    STA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATBITMASK
    LDB A, Y
    LDA _PEN
    ANDA #$0F
    MUL
    TFR B, A
    PULS Y

    LDB $a7c0
    ANDB #$fe
    STB $a7c0

    STA ,X+

    LDA <MATHPTR0
    LSRA
    LSRA
    STA <MATHPTR0

    LEAU -1, U

    CMPU #0
    BNE TEXTATBMSP03L1

    LEAX -2, X 

    PULS U
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP03L1X
    JMP TEXTATBMSP03

TEXTATBMSP03L1X
    LDA #2
    JMP TEXTATBMSP0E

;

TEXTATBMSP0E

    PULS D,Y,X

    LDA CURRENTMODE
    CMPA #3
    BEQ TEXTATBMSP0E3

    LEAX 1, X

    JMP TEXTATBMINCX

TEXTATBMSP0E3
    LEAX 2, X

    JMP TEXTATBMINCX

TEXTATBMSKIPTAB
    DEC <TABSTODRAW
    LDA <TABSTODRAW
    CMPA #0
    BNE TEXTATBMSKIPTAB2
    JSR TEXTATCALCPOS
TEXTATBMSKIPTAB2
    JMP TEXTATBMINCX

TEXTATBMINCX
    INC XCURSYS
    LDA XCURSYS
    CMPA CURRENTTILESWIDTH
    BEQ TEXTATBMNEXT2
    JMP TEXTATBMNEXT
TEXTATBMNEXT2
    LDA #0
    STA XCURSYS
    LDA CURRENTSL
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    INC YCURSYS
    LDA YCURSYS
    CMPA CURRENTTILESHEIGHT

    BEQ TEXTATBMNEXT3
    JMP TEXTATBMNEXT
TEXTATBMNEXT3

    LDA #$FF
    STA <DIRECTION
    JSR VSCROLLT

    DEC YCURSYS

    JSR TEXTATCALCPOS

TEXTATBMNEXT
    LDA <TABSTODRAW
    BEQ TEXTATBMXLOOP2
    JMP TEXTATBMLOOP2
TEXTATBMXLOOP2
    LEAY 1,Y
    DECB
    BEQ TEXTATBMEND
    JMP TEXTATBMLOOP2
TEXTATBMEND
    RTS

TEXTATFONT
   fcb $3c, $66, $6e, $6e, $60, $62, $3c, $00
   fcb $18, $3c, $66, $7e, $66, $66, $66, $00
   fcb $7c, $66, $66, $7c, $66, $66, $7c, $00
   fcb $3c, $66, $60, $60, $60, $66, $3c, $00
   fcb $78, $6c, $66, $66, $66, $6c, $78, $00
   fcb $7e, $60, $60, $78, $60, $60, $7e, $00
   fcb $7e, $60, $60, $78, $60, $60, $60, $00
   fcb $3c, $66, $60, $6e, $66, $66, $3c, $00
   fcb $66, $66, $66, $7e, $66, $66, $66, $00
   fcb $3c, $18, $18, $18, $18, $18, $3c, $00
   fcb $1e, $0c, $0c, $0c, $0c, $6c, $38, $00
   fcb $66, $6c, $78, $70, $78, $6c, $66, $00
   fcb $60, $60, $60, $60, $60, $60, $7e, $00
   fcb $63, $77, $7f, $6b, $63, $63, $63, $00
   fcb $66, $76, $7e, $7e, $6e, $66, $66, $00
   fcb $3c, $66, $66, $66, $66, $66, $3c, $00
   fcb $7c, $66, $66, $7c, $60, $60, $60, $00
   fcb $3c, $66, $66, $66, $66, $3c, $0e, $00
   fcb $7c, $66, $66, $7c, $78, $6c, $66, $00
   fcb $3c, $66, $60, $3c, $06, $66, $3c, $00
   fcb $7e, $18, $18, $18, $18, $18, $18, $00
   fcb $66, $66, $66, $66, $66, $66, $3c, $00
   fcb $66, $66, $66, $66, $66, $3c, $18, $00
   fcb $63, $63, $63, $6b, $7f, $77, $63, $00
   fcb $66, $66, $3c, $18, $3c, $66, $66, $00
   fcb $66, $66, $66, $3c, $18, $18, $18, $00
   fcb $7e, $06, $0c, $18, $30, $60, $7e, $00
   fcb $3c, $30, $30, $30, $30, $30, $3c, $00
   fcb $00, $40, $60, $30, $18, $0c, $06, $00
   fcb $3c, $0c, $0c, $0c, $0c, $0c, $3c, $00
   fcb $00, $18, $3c, $7e, $18, $18, $18, $18
   fcb $00, $10, $30, $7f, $7f, $30, $10, $00
   fcb $00, $00, $00, $00, $00, $00, $00, $00
   fcb $18, $18, $18, $18, $00, $00, $18, $00
   fcb $66, $66, $66, $00, $00, $00, $00, $00
   fcb $66, $66, $ff, $66, $ff, $66, $66, $00
   fcb $18, $3e, $60, $3c, $06, $7c, $18, $00
   fcb $62, $66, $0c, $18, $30, $66, $46, $00
   fcb $3c, $66, $3c, $38, $67, $66, $3f, $00
   fcb $06, $0c, $18, $00, $00, $00, $00, $00
   fcb $0c, $18, $30, $30, $30, $18, $0c, $00
   fcb $30, $18, $0c, $0c, $0c, $18, $30, $00
   fcb $00, $66, $3c, $ff, $3c, $66, $00, $00
   fcb $00, $18, $18, $7e, $18, $18, $00, $00
   fcb $00, $00, $00, $00, $00, $18, $18, $30
   fcb $00, $00, $00, $7e, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $00, $18, $18, $00
   fcb $00, $03, $06, $0c, $18, $30, $60, $00
   fcb $3c, $66, $6e, $76, $66, $66, $3c, $00
   fcb $18, $18, $38, $18, $18, $18, $7e, $00
   fcb $3c, $66, $06, $0c, $30, $60, $7e, $00
   fcb $3c, $66, $06, $1c, $06, $66, $3c, $00
   fcb $06, $0e, $1e, $66, $7f, $06, $06, $00
   fcb $7e, $60, $7c, $06, $06, $66, $3c, $00
   fcb $3c, $66, $60, $7c, $66, $66, $3c, $00
   fcb $7e, $66, $0c, $18, $18, $18, $18, $00
   fcb $3c, $66, $66, $3c, $66, $66, $3c, $00
   fcb $3c, $66, $66, $3e, $06, $66, $3c, $00
   fcb $00, $00, $18, $00, $00, $18, $00, $00
   fcb $00, $00, $18, $00, $00, $18, $18, $30
   fcb $0e, $18, $30, $60, $30, $18, $0e, $00
   fcb $00, $00, $7e, $00, $7e, $00, $00, $00
   fcb $70, $18, $0c, $06, $0c, $18, $70, $00
   fcb $3c, $66, $06, $0c, $18, $00, $18, $00
   fcb $00, $00, $00, $ff, $ff, $00, $00, $00
   fcb $08, $1c, $3e, $7f, $7f, $1c, $3e, $00
   fcb $18, $18, $18, $18, $18, $18, $18, $18
   fcb $00, $00, $00, $ff, $ff, $00, $00, $00
   fcb $00, $00, $ff, $ff, $00, $00, $00, $00
   fcb $00, $ff, $ff, $00, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $ff, $ff, $00, $00
   fcb $30, $30, $30, $30, $30, $30, $30, $30
   fcb $0c, $0c, $0c, $0c, $0c, $0c, $0c, $0c
   fcb $00, $00, $00, $e0, $f0, $38, $18, $18
   fcb $18, $18, $1c, $0f, $07, $00, $00, $00
   fcb $18, $18, $38, $f0, $e0, $00, $00, $00
   fcb $c0, $c0, $c0, $c0, $c0, $c0, $ff, $ff
   fcb $c0, $e0, $70, $38, $1c, $0e, $07, $03
   fcb $03, $07, $0e, $1c, $38, $70, $e0, $c0
   fcb $ff, $ff, $c0, $c0, $c0, $c0, $c0, $c0
   fcb $ff, $ff, $03, $03, $03, $03, $03, $03
   fcb $00, $3c, $7e, $7e, $7e, $7e, $3c, $00
   fcb $00, $00, $00, $00, $00, $ff, $ff, $00
   fcb $36, $7f, $7f, $7f, $3e, $1c, $08, $00
   fcb $60, $60, $60, $60, $60, $60, $60, $60
   fcb $00, $00, $00, $07, $0f, $1c, $18, $18
   fcb $c3, $e7, $7e, $3c, $3c, $7e, $e7, $c3
   fcb $00, $3c, $7e, $66, $66, $7e, $3c, $00
   fcb $18, $18, $66, $66, $18, $18, $3c, $00
   fcb $06, $06, $06, $06, $06, $06, $06, $06
   fcb $08, $1c, $3e, $7f, $3e, $1c, $08, $00
   fcb $18, $18, $18, $ff, $ff, $18, $18, $18
   fcb $c0, $c0, $30, $30, $c0, $c0, $30, $30
   fcb $18, $18, $18, $18, $18, $18, $18, $18
   fcb $00, $00, $03, $3e, $76, $36, $36, $00
   fcb $ff, $7f, $3f, $1f, $0f, $07, $03, $01
   fcb $00, $00, $00, $00, $00, $00, $00, $00
   fcb $f0, $f0, $f0, $f0, $f0, $f0, $f0, $f0
   fcb $00, $00, $00, $00, $ff, $ff, $ff, $ff
   fcb $ff, $00, $00, $00, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $00, $00, $00, $ff
   fcb $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   fcb $cc, $cc, $33, $33, $cc, $cc, $33, $33
   fcb $03, $03, $03, $03, $03, $03, $03, $03
   fcb $00, $00, $00, $00, $cc, $cc, $33, $33
   fcb $ff, $fe, $fc, $f8, $f0, $e0, $c0, $80
   fcb $03, $03, $03, $03, $03, $03, $03, $03
   fcb $18, $18, $18, $1f, $1f, $18, $18, $18
   fcb $00, $00, $00, $00, $0f, $0f, $0f, $0f
   fcb $18, $18, $18, $1f, $1f, $00, $00, $00
   fcb $00, $00, $00, $f8, $f8, $18, $18, $18
   fcb $00, $00, $00, $00, $00, $00, $ff, $ff
   fcb $00, $00, $00, $1f, $1f, $18, $18, $18
   fcb $18, $18, $18, $ff, $ff, $00, $00, $00
   fcb $00, $00, $00, $ff, $ff, $18, $18, $18
   fcb $18, $18, $18, $f8, $f8, $18, $18, $18
   fcb $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   fcb $e0, $e0, $e0, $e0, $e0, $e0, $e0, $e0
   fcb $07, $07, $07, $07, $07, $07, $07, $07
   fcb $ff, $ff, $00, $00, $00, $00, $00, $00
   fcb $ff, $ff, $ff, $00, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $00, $ff, $ff, $ff
   fcb $03, $03, $03, $03, $03, $03, $ff, $ff
   fcb $00, $00, $00, $00, $f0, $f0, $f0, $f0
   fcb $0f, $0f, $0f, $0f, $00, $00, $00, $00
   fcb $18, $18, $18, $f8, $f8, $00, $00, $00
   fcb $f0, $f0, $f0, $f0, $00, $00, $00, $00
   fcb $f0, $f0, $f0, $f0, $0f, $0f, $0f, $0f
   fcb $c3, $99, $91, $91, $9f, $99, $c3, $ff
   fcb $e7, $c3, $99, $81, $99, $99, $99, $ff
   fcb $83, $99, $99, $83, $99, $99, $83, $ff
   fcb $c3, $99, $9f, $9f, $9f, $99, $c3, $ff
   fcb $87, $93, $99, $99, $99, $93, $87, $ff
   fcb $81, $9f, $9f, $87, $9f, $9f, $81, $ff
   fcb $81, $9f, $9f, $87, $9f, $9f, $9f, $ff
   fcb $c3, $99, $9f, $91, $99, $99, $c3, $ff
   fcb $99, $99, $99, $81, $99, $99, $99, $ff
   fcb $c3, $e7, $e7, $e7, $e7, $e7, $c3, $ff
   fcb $e1, $f3, $f3, $f3, $f3, $93, $c7, $ff
   fcb $99, $93, $87, $8f, $87, $93, $99, $ff
   fcb $9f, $9f, $9f, $9f, $9f, $9f, $81, $ff
   fcb $9c, $88, $80, $94, $9c, $9c, $9c, $ff
   fcb $99, $89, $81, $81, $91, $99, $99, $ff
   fcb $c3, $99, $99, $99, $99, $99, $c3, $ff
   fcb $83, $99, $99, $83, $9f, $9f, $9f, $ff
   fcb $c3, $99, $99, $99, $99, $c3, $f1, $ff
   fcb $83, $99, $99, $83, $87, $93, $99, $ff
   fcb $c3, $99, $9f, $c3, $f9, $99, $c3, $ff
   fcb $81, $e7, $e7, $e7, $e7, $e7, $e7, $ff
   fcb $99, $99, $99, $99, $99, $99, $c3, $ff
   fcb $99, $99, $99, $99, $99, $c3, $e7, $ff
   fcb $9c, $9c, $9c, $94, $80, $88, $9c, $ff
   fcb $99, $99, $c3, $e7, $c3, $99, $99, $ff
   fcb $99, $99, $99, $c3, $e7, $e7, $e7, $ff
   fcb $81, $f9, $f3, $e7, $cf, $9f, $81, $ff
   fcb $c3, $cf, $cf, $cf, $cf, $cf, $c3, $ff
   fcb $f3, $ed, $cf, $83, $cf, $9d, $03, $ff
   fcb $c3, $f3, $f3, $f3, $f3, $f3, $c3, $ff
   fcb $ff, $e7, $c3, $81, $e7, $e7, $e7, $e7
   fcb $ff, $ef, $cf, $80, $80, $cf, $ef, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $e7, $e7, $e7, $e7, $ff, $ff, $e7, $ff
   fcb $99, $99, $99, $ff, $ff, $ff, $ff, $ff
   fcb $99, $99, $00, $99, $00, $99, $99, $ff
   fcb $e7, $c1, $9f, $c3, $f9, $83, $e7, $ff
   fcb $9d, $99, $f3, $e7, $cf, $99, $b9, $ff
   fcb $c3, $99, $c3, $c7, $98, $99, $c0, $ff
   fcb $f9, $f3, $e7, $ff, $ff, $ff, $ff, $ff
   fcb $f3, $e7, $cf, $cf, $cf, $e7, $f3, $ff
   fcb $cf, $e7, $f3, $f3, $f3, $e7, $cf, $ff
   fcb $ff, $99, $c3, $00, $c3, $99, $ff, $ff
   fcb $ff, $e7, $e7, $81, $e7, $e7, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $e7, $e7, $cf
   fcb $ff, $ff, $ff, $81, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $e7, $e7, $ff
   fcb $ff, $fc, $f9, $f3, $e7, $cf, $9f, $ff
   fcb $c3, $99, $91, $89, $99, $99, $c3, $ff
   fcb $e7, $e7, $c7, $e7, $e7, $e7, $81, $ff
   fcb $c3, $99, $f9, $f3, $cf, $9f, $81, $ff
   fcb $c3, $99, $f9, $e3, $f9, $99, $c3, $ff
   fcb $f9, $f1, $e1, $99, $80, $f9, $f9, $ff
   fcb $81, $9f, $83, $f9, $f9, $99, $c3, $ff
   fcb $c3, $99, $9f, $83, $99, $99, $c3, $ff
   fcb $81, $99, $f3, $e7, $e7, $e7, $e7, $ff
   fcb $c3, $99, $99, $c3, $99, $99, $c3, $ff
   fcb $c3, $99, $99, $c1, $f9, $99, $c3, $ff
   fcb $ff, $ff, $e7, $ff, $ff, $e7, $ff, $ff
   fcb $ff, $ff, $e7, $ff, $ff, $e7, $e7, $cf
   fcb $f1, $e7, $cf, $9f, $cf, $e7, $f1, $ff
   fcb $ff, $ff, $81, $ff, $81, $ff, $ff, $ff
   fcb $8f, $e7, $f3, $f9, $f3, $e7, $8f, $ff
   fcb $c3, $99, $f9, $f3, $e7, $ff, $e7, $ff
   fcb $ff, $ff, $ff, $00, $00, $ff, $ff, $ff
   fcb $f7, $e3, $c1, $80, $80, $e3, $c1, $ff
   fcb $e7, $e7, $e7, $e7, $e7, $e7, $e7, $e7
   fcb $ff, $ff, $ff, $00, $00, $ff, $ff, $ff
   fcb $ff, $ff, $00, $00, $ff, $ff, $ff, $ff
   fcb $ff, $00, $00, $ff, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $00, $00, $ff, $ff
   fcb $cf, $cf, $cf, $cf, $cf, $cf, $cf, $cf
   fcb $f3, $f3, $f3, $f3, $f3, $f3, $f3, $f3
   fcb $ff, $ff, $ff, $1f, $0f, $c7, $e7, $e7
   fcb $e7, $e7, $e3, $f0, $f8, $ff, $ff, $ff
   fcb $e7, $e7, $c7, $0f, $1f, $ff, $ff, $ff
   fcb $3f, $3f, $3f, $3f, $3f, $3f, $00, $00
   fcb $3f, $1f, $8f, $c7, $e3, $f1, $f8, $fc
   fcb $fc, $f8, $f1, $e3, $c7, $8f, $1f, $3f
   fcb $00, $00, $3f, $3f, $3f, $3f, $3f, $3f
   fcb $00, $00, $fc, $fc, $fc, $fc, $fc, $fc
   fcb $ff, $c3, $81, $81, $81, $81, $c3, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $00, $00, $ff
   fcb $c9, $80, $80, $80, $c1, $e3, $f7, $ff
   fcb $9f, $9f, $9f, $9f, $9f, $9f, $9f, $9f
   fcb $ff, $ff, $ff, $f8, $f0, $e3, $e7, $e7
   fcb $3c, $18, $81, $c3, $c3, $81, $18, $3c
   fcb $ff, $c3, $81, $99, $99, $81, $c3, $ff
   fcb $e7, $e7, $99, $99, $e7, $e7, $c3, $ff
   fcb $f9, $f9, $f9, $f9, $f9, $f9, $f9, $f9
   fcb $f7, $e3, $c1, $80, $c1, $e3, $f7, $ff
   fcb $e7, $e7, $e7, $00, $00, $e7, $e7, $e7
   fcb $3f, $3f, $cf, $cf, $3f, $3f, $cf, $cf
   fcb $e7, $e7, $e7, $e7, $e7, $e7, $e7, $e7
   fcb $ff, $ff, $fc, $c1, $89, $c9, $c9, $ff
   fcb $00, $80, $c0, $e0, $f0, $f8, $fc, $fe
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $0f, $0f, $0f, $0f, $0f, $0f, $0f, $0f
   fcb $ff, $ff, $ff, $ff, $00, $00, $00, $00
   fcb $00, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $ff, $00
   fcb $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   fcb $33, $33, $cc, $cc, $33, $33, $cc, $cc
   fcb $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   fcb $ff, $ff, $ff, $ff, $33, $33, $cc, $cc
   fcb $00, $01, $03, $07, $0f, $1f, $3f, $7f
   fcb $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   fcb $e7, $e7, $e7, $e0, $e0, $e7, $e7, $e7
   fcb $ff, $ff, $ff, $ff, $f0, $f0, $f0, $f0
   fcb $e7, $e7, $e7, $e0, $e0, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $07, $07, $e7, $e7, $e7
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $00, $00
   fcb $ff, $ff, $ff, $e0, $e0, $e7, $e7, $e7
   fcb $e7, $e7, $e7, $00, $00, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $00, $00, $e7, $e7, $e7
   fcb $e7, $e7, $e7, $07, $07, $e7, $e7, $e7
   fcb $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   fcb $1f, $1f, $1f, $1f, $1f, $1f, $1f, $1f
   fcb $f8, $f8, $f8, $f8, $f8, $f8, $f8, $f8
   fcb $00, $00, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $00, $00, $00, $ff, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $00, $00, $00
   fcb $fc, $fc, $fc, $fc, $fc, $fc, $00, $00
   fcb $ff, $ff, $ff, $ff, $0f, $0f, $0f, $0f
   fcb $f0, $f0, $f0, $f0, $ff, $ff, $ff, $ff
   fcb $e7, $e7, $e7, $07, $07, $ff, $ff, $ff
   fcb $0f, $0f, $0f, $0f, $ff, $ff, $ff, $ff
   fcb $0f, $0f, $0f, $0f, $f0, $f0, $f0, $f0
   fcb $3c, $66, $6e, $6e, $60, $62, $3c, $00
   fcb $00, $00, $3c, $06, $3e, $66, $3e, $00
   fcb $00, $60, $60, $7c, $66, $66, $7c, $00
   fcb $00, $00, $3c, $60, $60, $60, $3c, $00
   fcb $00, $06, $06, $3e, $66, $66, $3e, $00
   fcb $00, $00, $3c, $66, $7e, $60, $3c, $00
   fcb $00, $0e, $18, $3e, $18, $18, $18, $00
   fcb $00, $00, $3e, $66, $66, $3e, $06, $7c
   fcb $00, $60, $60, $7c, $66, $66, $66, $00
   fcb $00, $18, $00, $38, $18, $18, $3c, $00
   fcb $00, $06, $00, $06, $06, $06, $06, $3c
   fcb $00, $60, $60, $6c, $78, $6c, $66, $00
   fcb $00, $38, $18, $18, $18, $18, $3c, $00
   fcb $00, $00, $66, $7f, $7f, $6b, $63, $00
   fcb $00, $00, $7c, $66, $66, $66, $66, $00
   fcb $00, $00, $3c, $66, $66, $66, $3c, $00
   fcb $00, $00, $7c, $66, $66, $7c, $60, $60
   fcb $00, $00, $3e, $66, $66, $3e, $06, $06
   fcb $00, $00, $7c, $66, $60, $60, $60, $00
   fcb $00, $00, $3e, $60, $3c, $06, $7c, $00
   fcb $00, $18, $7e, $18, $18, $18, $0e, $00
   fcb $00, $00, $66, $66, $66, $66, $3e, $00
   fcb $00, $00, $66, $66, $66, $3c, $18, $00
   fcb $00, $00, $63, $6b, $7f, $3e, $36, $00
   fcb $00, $00, $66, $3c, $18, $3c, $66, $00
   fcb $00, $00, $66, $66, $66, $3e, $0c, $78
   fcb $00, $00, $7e, $0c, $18, $30, $7e, $00
   fcb $3c, $30, $30, $30, $30, $30, $3c, $00
   fcb $0c, $12, $30, $7c, $30, $62, $fc, $00
   fcb $3c, $0c, $0c, $0c, $0c, $0c, $3c, $00
   fcb $00, $18, $3c, $7e, $18, $18, $18, $18
   fcb $00, $10, $30, $7f, $7f, $30, $10, $00
   fcb $00, $00, $00, $00, $00, $00, $00, $00
   fcb $18, $18, $18, $18, $00, $00, $18, $00
   fcb $66, $66, $66, $00, $00, $00, $00, $00
   fcb $66, $66, $ff, $66, $ff, $66, $66, $00
   fcb $18, $3e, $60, $3c, $06, $7c, $18, $00
   fcb $62, $66, $0c, $18, $30, $66, $46, $00
   fcb $3c, $66, $3c, $38, $67, $66, $3f, $00
   fcb $06, $0c, $18, $00, $00, $00, $00, $00
   fcb $0c, $18, $30, $30, $30, $18, $0c, $00
   fcb $30, $18, $0c, $0c, $0c, $18, $30, $00
   fcb $00, $66, $3c, $ff, $3c, $66, $00, $00
   fcb $00, $18, $18, $7e, $18, $18, $00, $00
   fcb $00, $00, $00, $00, $00, $18, $18, $30
   fcb $00, $00, $00, $7e, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $00, $18, $18, $00
   fcb $00, $03, $06, $0c, $18, $30, $60, $00
   fcb $3c, $66, $6e, $76, $66, $66, $3c, $00
   fcb $18, $18, $38, $18, $18, $18, $7e, $00
   fcb $3c, $66, $06, $0c, $30, $60, $7e, $00
   fcb $3c, $66, $06, $1c, $06, $66, $3c, $00
   fcb $06, $0e, $1e, $66, $7f, $06, $06, $00
   fcb $7e, $60, $7c, $06, $06, $66, $3c, $00
   fcb $3c, $66, $60, $7c, $66, $66, $3c, $00
   fcb $7e, $66, $0c, $18, $18, $18, $18, $00
   fcb $3c, $66, $66, $3c, $66, $66, $3c, $00
   fcb $3c, $66, $66, $3e, $06, $66, $3c, $00
   fcb $00, $00, $18, $00, $00, $18, $00, $00
   fcb $00, $00, $18, $00, $00, $18, $18, $30
   fcb $0e, $18, $30, $60, $30, $18, $0e, $00
   fcb $00, $00, $7e, $00, $7e, $00, $00, $00
   fcb $70, $18, $0c, $06, $0c, $18, $70, $00
   fcb $3c, $66, $06, $0c, $18, $00, $18, $00
   fcb $00, $00, $00, $ff, $ff, $00, $00, $00
   fcb $18, $3c, $66, $7e, $66, $66, $66, $00
   fcb $7c, $66, $66, $7c, $66, $66, $7c, $00
   fcb $3c, $66, $60, $60, $60, $66, $3c, $00
   fcb $78, $6c, $66, $66, $66, $6c, $78, $00
   fcb $7e, $60, $60, $78, $60, $60, $7e, $00
   fcb $7e, $60, $60, $78, $60, $60, $60, $00
   fcb $3c, $66, $60, $6e, $66, $66, $3c, $00
   fcb $66, $66, $66, $7e, $66, $66, $66, $00
   fcb $3c, $18, $18, $18, $18, $18, $3c, $00
   fcb $1e, $0c, $0c, $0c, $0c, $6c, $38, $00
   fcb $66, $6c, $78, $70, $78, $6c, $66, $00
   fcb $60, $60, $60, $60, $60, $60, $7e, $00
   fcb $63, $77, $7f, $6b, $63, $63, $63, $00
   fcb $66, $76, $7e, $7e, $6e, $66, $66, $00
   fcb $3c, $66, $66, $66, $66, $66, $3c, $00
   fcb $7c, $66, $66, $7c, $60, $60, $60, $00
   fcb $3c, $66, $66, $66, $66, $3c, $0e, $00
   fcb $7c, $66, $66, $7c, $78, $6c, $66, $00
   fcb $3c, $66, $60, $3c, $06, $66, $3c, $00
   fcb $7e, $18, $18, $18, $18, $18, $18, $00
   fcb $66, $66, $66, $66, $66, $66, $3c, $00
   fcb $66, $66, $66, $66, $66, $3c, $18, $00
   fcb $63, $63, $63, $6b, $7f, $77, $63, $00
   fcb $66, $66, $3c, $18, $3c, $66, $66, $00
   fcb $66, $66, $66, $3c, $18, $18, $18, $00
   fcb $7e, $06, $0c, $18, $30, $60, $7e, $00
   fcb $18, $18, $18, $ff, $ff, $18, $18, $18
   fcb $c0, $c0, $30, $30, $c0, $c0, $30, $30
   fcb $18, $18, $18, $18, $18, $18, $18, $18
   fcb $33, $33, $cc, $cc, $33, $33, $cc, $cc
   fcb $33, $99, $cc, $66, $33, $99, $cc, $66
   fcb $00, $00, $00, $00, $00, $00, $00, $00
   fcb $f0, $f0, $f0, $f0, $f0, $f0, $f0, $f0
   fcb $00, $00, $00, $00, $ff, $ff, $ff, $ff
   fcb $ff, $00, $00, $00, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $00, $00, $00, $ff
   fcb $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   fcb $cc, $cc, $33, $33, $cc, $cc, $33, $33
   fcb $03, $03, $03, $03, $03, $03, $03, $03
   fcb $00, $00, $00, $00, $cc, $cc, $33, $33
   fcb $cc, $99, $33, $66, $cc, $99, $33, $66
   fcb $03, $03, $03, $03, $03, $03, $03, $03
   fcb $18, $18, $18, $1f, $1f, $18, $18, $18
   fcb $00, $00, $00, $00, $0f, $0f, $0f, $0f
   fcb $18, $18, $18, $1f, $1f, $00, $00, $00
   fcb $00, $00, $00, $f8, $f8, $18, $18, $18
   fcb $00, $00, $00, $00, $00, $00, $ff, $ff
   fcb $00, $00, $00, $1f, $1f, $18, $18, $18
   fcb $18, $18, $18, $ff, $ff, $00, $00, $00
   fcb $00, $00, $00, $ff, $ff, $18, $18, $18
   fcb $18, $18, $18, $f8, $f8, $18, $18, $18
   fcb $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   fcb $e0, $e0, $e0, $e0, $e0, $e0, $e0, $e0
   fcb $07, $07, $07, $07, $07, $07, $07, $07
   fcb $ff, $ff, $00, $00, $00, $00, $00, $00
   fcb $ff, $ff, $ff, $00, $00, $00, $00, $00
   fcb $00, $00, $00, $00, $00, $ff, $ff, $ff
   fcb $01, $03, $06, $6c, $78, $70, $60, $00
   fcb $00, $00, $00, $00, $f0, $f0, $f0, $f0
   fcb $0f, $0f, $0f, $0f, $00, $00, $00, $00
   fcb $18, $18, $18, $f8, $f8, $00, $00, $00
   fcb $f0, $f0, $f0, $f0, $00, $00, $00, $00
   fcb $f0, $f0, $f0, $f0, $0f, $0f, $0f, $0f
   fcb $c3, $99, $91, $91, $9f, $99, $c3, $ff
   fcb $ff, $ff, $c3, $f9, $c1, $99, $c1, $ff
   fcb $ff, $9f, $9f, $83, $99, $99, $83, $ff
   fcb $ff, $ff, $c3, $9f, $9f, $9f, $c3, $ff
   fcb $ff, $f9, $f9, $c1, $99, $99, $c1, $ff
   fcb $ff, $ff, $c3, $99, $81, $9f, $c3, $ff
   fcb $ff, $f1, $e7, $c1, $e7, $e7, $e7, $ff
   fcb $ff, $ff, $c1, $99, $99, $c1, $f9, $83
   fcb $ff, $9f, $9f, $83, $99, $99, $99, $ff
   fcb $ff, $e7, $ff, $c7, $e7, $e7, $c3, $ff
   fcb $ff, $f9, $ff, $f9, $f9, $f9, $f9, $c3
   fcb $ff, $9f, $9f, $93, $87, $93, $99, $ff
   fcb $ff, $c7, $e7, $e7, $e7, $e7, $c3, $ff
   fcb $ff, $ff, $99, $80, $80, $94, $9c, $ff
   fcb $ff, $ff, $83, $99, $99, $99, $99, $ff
   fcb $ff, $ff, $c3, $99, $99, $99, $c3, $ff
   fcb $ff, $ff, $83, $99, $99, $83, $9f, $9f
   fcb $ff, $ff, $c1, $99, $99, $c1, $f9, $f9
   fcb $ff, $ff, $83, $99, $9f, $9f, $9f, $ff
   fcb $ff, $ff, $c1, $9f, $c3, $f9, $83, $ff
   fcb $ff, $e7, $81, $e7, $e7, $e7, $f1, $ff
   fcb $ff, $ff, $99, $99, $99, $99, $c1, $ff
   fcb $ff, $ff, $99, $99, $99, $c3, $e7, $ff
   fcb $ff, $ff, $9c, $94, $80, $c1, $c9, $ff
   fcb $ff, $ff, $99, $c3, $e7, $c3, $99, $ff
   fcb $ff, $ff, $99, $99, $99, $c1, $f3, $87
   fcb $ff, $ff, $81, $f3, $e7, $cf, $81, $ff
   fcb $c3, $cf, $cf, $cf, $cf, $cf, $c3, $ff
   fcb $f3, $ed, $cf, $83, $cf, $9d, $03, $ff
   fcb $c3, $f3, $f3, $f3, $f3, $f3, $c3, $ff
   fcb $ff, $e7, $c3, $81, $e7, $e7, $e7, $e7
   fcb $ff, $ef, $cf, $80, $80, $cf, $ef, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $e7, $e7, $e7, $e7, $ff, $ff, $e7, $ff
   fcb $99, $99, $99, $ff, $ff, $ff, $ff, $ff
   fcb $99, $99, $00, $99, $00, $99, $99, $ff
   fcb $e7, $c1, $9f, $c3, $f9, $83, $e7, $ff
   fcb $9d, $99, $f3, $e7, $cf, $99, $b9, $ff
   fcb $c3, $99, $c3, $c7, $98, $99, $c0, $ff
   fcb $f9, $f3, $e7, $ff, $ff, $ff, $ff, $ff
   fcb $f3, $e7, $cf, $cf, $cf, $e7, $f3, $ff
   fcb $cf, $e7, $f3, $f3, $f3, $e7, $cf, $ff
   fcb $ff, $99, $c3, $00, $c3, $99, $ff, $ff
   fcb $ff, $e7, $e7, $81, $e7, $e7, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $e7, $e7, $cf
   fcb $ff, $ff, $ff, $81, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $e7, $e7, $ff
   fcb $ff, $fc, $f9, $f3, $e7, $cf, $9f, $ff
   fcb $c3, $99, $91, $89, $99, $99, $c3, $ff
   fcb $e7, $e7, $c7, $e7, $e7, $e7, $81, $ff
   fcb $c3, $99, $f9, $f3, $cf, $9f, $81, $ff
   fcb $c3, $99, $f9, $e3, $f9, $99, $c3, $ff
   fcb $f9, $f1, $e1, $99, $80, $f9, $f9, $ff
   fcb $81, $9f, $83, $f9, $f9, $99, $c3, $ff
   fcb $c3, $99, $9f, $83, $99, $99, $c3, $ff
   fcb $81, $99, $f3, $e7, $e7, $e7, $e7, $ff
   fcb $c3, $99, $99, $c3, $99, $99, $c3, $ff
   fcb $c3, $99, $99, $c1, $f9, $99, $c3, $ff
   fcb $ff, $ff, $e7, $ff, $ff, $e7, $ff, $ff
   fcb $ff, $ff, $e7, $ff, $ff, $e7, $e7, $cf
   fcb $f1, $e7, $cf, $9f, $cf, $e7, $f1, $ff
   fcb $ff, $ff, $81, $ff, $81, $ff, $ff, $ff
   fcb $8f, $e7, $f3, $f9, $f3, $e7, $8f, $ff
   fcb $c3, $99, $f9, $f3, $e7, $ff, $e7, $ff
   fcb $ff, $ff, $ff, $00, $00, $ff, $ff, $ff
   fcb $e7, $c3, $99, $81, $99, $99, $99, $ff
   fcb $83, $99, $99, $83, $99, $99, $83, $ff
   fcb $c3, $99, $9f, $9f, $9f, $99, $c3, $ff
   fcb $87, $93, $99, $99, $99, $93, $87, $ff
   fcb $81, $9f, $9f, $87, $9f, $9f, $81, $ff
   fcb $81, $9f, $9f, $87, $9f, $9f, $9f, $ff
   fcb $c3, $99, $9f, $91, $99, $99, $c3, $ff
   fcb $99, $99, $99, $81, $99, $99, $99, $ff
   fcb $c3, $e7, $e7, $e7, $e7, $e7, $c3, $ff
   fcb $e1, $f3, $f3, $f3, $f3, $93, $c7, $ff
   fcb $99, $93, $87, $8f, $87, $93, $99, $ff
   fcb $9f, $9f, $9f, $9f, $9f, $9f, $81, $ff
   fcb $9c, $88, $80, $94, $9c, $9c, $9c, $ff
   fcb $99, $89, $81, $81, $91, $99, $99, $ff
   fcb $c3, $99, $99, $99, $99, $99, $c3, $ff
   fcb $83, $99, $99, $83, $9f, $9f, $9f, $ff
   fcb $c3, $99, $99, $99, $99, $c3, $f1, $ff
   fcb $83, $99, $99, $83, $87, $93, $99, $ff
   fcb $c3, $99, $9f, $c3, $f9, $99, $c3, $ff
   fcb $81, $e7, $e7, $e7, $e7, $e7, $e7, $ff
   fcb $99, $99, $99, $99, $99, $99, $c3, $ff
   fcb $99, $99, $99, $99, $99, $c3, $e7, $ff
   fcb $9c, $9c, $9c, $94, $80, $88, $9c, $ff
   fcb $99, $99, $c3, $e7, $c3, $99, $99, $ff
   fcb $99, $99, $99, $c3, $e7, $e7, $e7, $ff
   fcb $81, $f9, $f3, $e7, $cf, $9f, $81, $ff
   fcb $e7, $e7, $e7, $00, $00, $e7, $e7, $e7
   fcb $3f, $3f, $cf, $cf, $3f, $3f, $cf, $cf
   fcb $e7, $e7, $e7, $e7, $e7, $e7, $e7, $e7
   fcb $cc, $cc, $33, $33, $cc, $cc, $33, $33
   fcb $cc, $66, $33, $99, $cc, $66, $33, $99
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $0f, $0f, $0f, $0f, $0f, $0f, $0f, $0f
   fcb $ff, $ff, $ff, $ff, $00, $00, $00, $00
   fcb $00, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $ff, $00
   fcb $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   fcb $33, $33, $cc, $cc, $33, $33, $cc, $cc
   fcb $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   fcb $ff, $ff, $ff, $ff, $33, $33, $cc, $cc
   fcb $33, $66, $cc, $99, $33, $66, $cc, $99
   fcb $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   fcb $e7, $e7, $e7, $e0, $e0, $e7, $e7, $e7
   fcb $ff, $ff, $ff, $ff, $f0, $f0, $f0, $f0
   fcb $e7, $e7, $e7, $e0, $e0, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $07, $07, $e7, $e7, $e7
   fcb $ff, $ff, $ff, $ff, $ff, $ff, $00, $00
   fcb $ff, $ff, $ff, $e0, $e0, $e7, $e7, $e7
   fcb $e7, $e7, $e7, $00, $00, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $00, $00, $e7, $e7, $e7
   fcb $e7, $e7, $e7, $07, $07, $e7, $e7, $e7
   fcb $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   fcb $1f, $1f, $1f, $1f, $1f, $1f, $1f, $1f
   fcb $f8, $f8, $f8, $f8, $f8, $f8, $f8, $f8
   fcb $00, $00, $ff, $ff, $ff, $ff, $ff, $ff
   fcb $00, $00, $00, $ff, $ff, $ff, $ff, $ff
   fcb $ff, $ff, $ff, $ff, $ff, $00, $00, $00
   fcb $fe, $fc, $f9, $93, $87, $8f, $9f, $ff
   fcb $ff, $ff, $ff, $ff, $0f, $0f, $0f, $0f
   fcb $f0, $f0, $f0, $f0, $ff, $ff, $ff, $ff
   fcb $e7, $e7, $e7, $07, $07, $ff, $ff, $ff
   fcb $0f, $0f, $0f, $0f, $ff, $ff, $ff, $ff
   fcb $0f, $0f, $0f, $0f, $f0, $f0, $f0, $f0

TEXTATBITMASK
    fcb $00, $10, $01, $11

TEXTATFLIP
    fcb $0, $8, $4, $c, $2, $a, $6, $e
    fcb $1, $9, $5, $d, $3, $b, $7, $f
