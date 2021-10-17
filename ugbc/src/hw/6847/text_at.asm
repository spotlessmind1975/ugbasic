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
;*                      TEXT AT GIVEN POSITION ON 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
TEXTWW equ $05
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
    STA SCREENCODE
    RTS

TEXTAT
    LDA TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO
    LDY TEXTADDRESS
    STY COPYOFTEXTADDRESS
    LDA #0
    STA TABSTODRAW
    LDA _PAPER
    STA TEXTPAPER

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
    CMPA #7
    BNE TEXTAT7X
    JMP TEXTAT7
TEXTAT7X
    CMPA #8
    BNE TEXTAT8X
    JMP TEXTAT8
TEXTAT8X
    CMPA #9
    BNE TEXTAT9X
    JMP TEXTAT9
TEXTAT9X
    CMPA #10
    BNE TEXTAT10X
    JMP TEXTAT10
TEXTAT10X
    CMPA #11
    BNE TEXTAT11X
    JMP TEXTAT11
TEXTAT11X
    CMPA #12
    BNE TEXTAT12X
    JMP TEXTAT12
TEXTAT12X
    CMPA #13
    BNE TEXTAT13X
    JMP TEXTAT13
TEXTAT13X
    CMPA #14
    BNE TEXTAT14X
    JMP TEXTAT14
TEXTAT14X
    RTS
    
;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATBITMAPMODE

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
TEXTAT7

    LDA #1
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
TEXTAT8

    LDA #0
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
TEXTAT9

    LDA #1
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
TEXTAT10

    LDA #0
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
TEXTAT11

    LDA #1
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
TEXTAT12

    LDA #0
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
TEXTAT13

    LDA #1
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
TEXTAT14

    LDA #0
    STA PATTERN

    LDX BITMAPADDRESS
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
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    JMP TEXTATCOMMON

TEXTATCOMMON

    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATBMCNOPEN

    LDA _PEN
    CMPA #0 ; COLOR_BLACK
    BEQ TEXTATC2
    CMPA #1 ; COLOR_GREEN
    BEQ TEXTATC3
    CMPA #2 ; COLOR_YELLOW
    BEQ TEXTATC1
    CMPA #3 ; COLOR_BLUE
    BEQ TEXTATC2
    CMPA #4 ; COLOR_RED
    BEQ TEXTATC3
    CMPA #5 ; COLOR_WHITE
    BEQ TEXTATC1
    CMPA #6 ; COLOR_CYAN
    BEQ TEXTATC3
    CMPA #7 ; COLOR_MAGENTA
    BEQ TEXTATC3
    CMPA #8 ; COLOR_ORANGE
    BEQ TEXTATC3

TEXTATC1
    LDD #TEXTATBMC1
    STD MATHPTR5
    JMP TEXTATBMCNOPEN

TEXTATC2
    LDD #TEXTATBMC2
    STD MATHPTR5
    JMP TEXTATBMCNOPEN

TEXTATC3
    LDD #TEXTATBMC3
    STD MATHPTR5
    JMP TEXTATBMCNOPEN

TEXTATBMCNOPEN

    LDB TEXTSIZE
    LDY TEXTPTR
TEXTATBMLOOP2

    LDA TABSTODRAW
    BEQ TEXTATBMNSKIPTAB
    JMP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB
    LDA ,Y
    STA SCREENCODE

    CMPA #$7f
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
    BCC TEXTATBMTAB3
    SUBA TABCOUNT
    JMP TEXTATBMTAB2
TEXTATBMTAB3
    STA TMPPTR
    LDA TABCOUNT
    SUBA TMPPTR
    STA TABSTODRAW
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
    STA TEXTPEN
TEXTATBMPENDISABLED
    JMP TEXTATBMNEXT

TEXTATBMPAPER
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$1
    BEQ TEXTATBMPAPERDISABLED
    LDA , Y
    STA TEXTPAPER
TEXTATBMPAPERDISABLED
    JMP TEXTATBMNEXT

TEXTATBMCMOVEPREPARE
    LEAY 1,Y
    DECB
    LDA , Y
    STA CLINEX
    LEAY 1,Y
    LEAX -1,X
    LDA , Y
    STA CLINEY

TEXTATBMCMOVE
    LDA CLINEX
    ADDA XCURSYS
    STA XCURSYS
    LDA CLINEY
    ADDA YCURSYS
    STA YCURSYS

    JMP TEXTATBMNEXT

TEXTATBMAT
    LEAY 1,Y
    DECB
    LDA , Y
    SUBA XCURSYS
    STA CLINEX
    LEAY 1,Y
    LEAX -1,X
    LDA , Y
    SUBA YCURSYS
    STA CLINEY
    JMP TEXTATBMCMOVE

TEXTATBMSP0

    PSHS D,Y,X

    LDU #0
    LDY #TEXTATFONT
    LDA SCREENCODE
    ANDA #$3F
    LDB #8
    MUL
    LEAY D, Y

TEXTATBMSP0L1
    LDA CURRENTMODE
    CMPA #7
    BEQ TEXTATBMSP0L1M
    CMPA #9
    BEQ TEXTATBMSP0L1M
    CMPA #11
    BEQ TEXTATBMSP0L1M
    CMPA #13
    BEQ TEXTATBMSP0L1M

    LDA ,Y
    STA ,X
    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M

    PSHS X

    LDX MATHPTR5

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

    LDX MATHPTR5

    LDA ,Y

    ANDA #$0F

    LDA A, X

    PULS X

    STA , X

    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    ANDCC #$FE
    LDA PATTERN
    EORA #$FF
    ADDA #1
    LEAX A, X 
        
    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP0L1X
    JMP TEXTATBMSP0L1

TEXTATBMSP0L1X

    PULS D,Y,X

    LDA PATTERN
    LEAX A, X 
    LEAX A, X 

    JMP TEXTATBMINCX

TEXTATBMSKIPTAB
    DEC TABSTODRAW
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
    INC YCURSYS
    LDA YCURSYS
    CMPA CURRENTTILESHEIGHT

    BEQ TEXTATBMNEXT3
    JMP TEXTATBMNEXT
TEXTATBMNEXT3

    ; scrolling ?

TEXTATBMNEXT
    LDA TABSTODRAW
    BEQ TEXTATBMXLOOP2
    JMP TEXTATBMLOOP2
TEXTATBMXLOOP2
    LEAY 1,Y
    DECB
    BEQ TEXTATBMEND
    JMP TEXTATBMLOOP2
TEXTATBMEND
    RTS

;-----------------------------------------------------------------------------
; TILE MODE
;-----------------------------------------------------------------------------

TEXTAT0
TEXTAT1
TEXTAT2
TEXTAT3
TEXTAT4
TEXTAT5
TEXTAT6
TEXTATTILEMODE
    LDB YCURSYS
    BEQ TEXTATSKIP
TEXTATLOOP1
    ANDCC #$FE
    LDX COPYOFTEXTADDRESS
    LEAX 32, X
    STX COPYOFTEXTADDRESS
    DECB
    BNE TEXTATLOOP1

TEXTATSKIP
    ANDCC #$FE
    LDA #0
    LDB XCURSYS
    ADDD COPYOFTEXTADDRESS
    STD COPYOFTEXTADDRESS

    LDX COPYOFTEXTADDRESS
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
    JSR TEXTATDECODE
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
    JMP TEXTATNEXT

TEXTATXAT
    JMP TEXTATAT

TEXTATPEN
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATPENDISABLED
    LDA , Y
    STA TEXTPEN
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
    LDA TEXTPEN
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

TEXTATBMC1
    fcb   %00000000
    fcb   %00000001
    fcb   %00000100
    fcb   %00000101
    fcb   %00010000
    fcb   %00010001
    fcb   %00010100
    fcb   %00010101
    fcb   %01000000
    fcb   %01000001
    fcb   %01000100
    fcb   %01000101
    fcb   %01010000
    fcb   %01010001
    fcb   %01010100
    fcb   %01010101

TEXTATBMC2
    fcb   %00000000
    fcb   %00000010
    fcb   %00001000
    fcb   %00001010
    fcb   %00100000
    fcb   %00100010
    fcb   %00101000
    fcb   %00101010
    fcb   %10000000
    fcb   %10000010
    fcb   %10001000
    fcb   %10001010
    fcb   %10100000
    fcb   %10100010
    fcb   %10101000
    fcb   %10101010

TEXTATBMC3
    fcb   %00000000
    fcb   %00000011
    fcb   %00001100
    fcb   %00001111
    fcb   %00110000
    fcb   %00110011
    fcb   %00111100
    fcb   %00111111
    fcb   %11000000
    fcb   %11000011
    fcb   %11001100
    fcb   %11001111
    fcb   %11110000
    fcb   %11110011
    fcb   %11111100
    fcb   %11111111
