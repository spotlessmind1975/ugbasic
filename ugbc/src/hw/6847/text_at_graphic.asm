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

TEXTATBITMAPMODE
    LDA TEXTSIZE
    BNE TEXTATBMGO
    RTS

TEXTATBMGO
    LDY TEXTADDRESS
    STY COPYOFTEXTADDRESS
    LDA #0
    STA TABSTODRAW

    LDY TEXTPTR
    LDA CURRENTMODE
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

CALCPOSG
    LDA CURRENTMODE
    CMPA #7
    BNE CALCPOS7X
    JSR CALCPOS7
    RTS
CALCPOS7X
    CMPA #8
    BNE CALCPOS8X
    JSR CALCPOS8
    RTS
CALCPOS8X
    CMPA #9
    BNE CALCPOS9X
    JSR CALCPOS9
    RTS
CALCPOS9X
    CMPA #10
    BNE CALCPOS10X
    JSR CALCPOS10
    RTS
CALCPOS10X
    CMPA #11
    BNE CALCPOS11X
    JSR CALCPOS11
    RTS
CALCPOS11X
    CMPA #12
    BNE CALCPOS12X
    JSR CALCPOS12
    RTS
CALCPOS12X
    CMPA #13
    BNE CALCPOS13X
    JSR CALCPOS13
    RTS
CALCPOS13X
    CMPA #14
    BNE CALCPOS14X
    JSR CALCPOS14
    RTS
CALCPOS14X
    RTS

CALCPOS7

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

    RTS

CALCPOS8

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

    RTS

CALCPOS9

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

    RTS

CALCPOS10

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

    RTS

CALCPOS11

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

    RTS

CALCPOS12

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

    RTS

CALCPOS13

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

    RTS

CALCPOS14

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
    LSLB
    ROLA
    LEAX D, X

    LDB XCURSYS
    LDA #0
    LEAX D, X

    RTS

;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
TEXTAT7

    JSR CALCPOS7

    JMP TEXTATBMCOMMON

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
TEXTAT8

    JSR CALCPOS8

    JMP TEXTATBMCOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
TEXTAT9

    JSR CALCPOS9

    JMP TEXTATBMCOMMON

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
TEXTAT10

    JSR CALCPOS10

    JMP TEXTATBMCOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
TEXTAT11

    JSR CALCPOS11

    JMP TEXTATBMCOMMON

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
TEXTAT12

    JSR CALCPOS12

    JMP TEXTATBMCOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
TEXTAT13

    JSR CALCPOS13

    JMP TEXTATBMCOMMON

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
TEXTAT14

    JSR CALCPOS14

    JMP TEXTATBMCOMMON

TEXTATBMCOMMON

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
    CMPA #14
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
    CMPA #13
    BEQ TEXTATBMLF
    CMPA #10
    BEQ TEXTATBMLF
    CMPA #09
    BEQ TEXTATBMTAB
    CMPA #01
    BEQ TEXTATBMPEN
    CMPA #02
    BEQ TEXTATBMPAPER
    CMPA #03
    BEQ TEXTATBMCMOVEPREPARE
    CMPA #04
    BEQ TEXTATBMXAT
    CMPA #05
    BEQ TEXTATBMCLS
    JMP TEXTATBMNEXT

TEXTATBMCLS
    LEAY 1,Y
    DECB
    JSR CLSG
    JMP TEXTATBMNEXT

TEXTATBMXAT
    JMP TEXTATBMAT

TEXTATBMLF
    INC YCURSYS
    LDA #0
    STA XCURSYS
    PSHS D,Y
    JSR CALCPOSG
    PULS D,Y
    JMP TEXTATBMNEXT2A
    
TEXTATBMPEN
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATBMPENDISABLED
    LDA , Y
    CMPA #$FF
    BNE TEXTATBMPEN2
    LDA #$0
TEXTATBMPEN2
    ASL A
    ASL A
    ASL A
    ASL A
    STA _PEN
TEXTATBMPENDISABLED
    JMP TEXTATBMNEXT

TEXTATBMPAPER
    LEAY 1,Y
    DECB
    LDA TEXTWW
    ANDA #$1
    BEQ TEXTATBMPAPERDISABLED
    LDA , Y
    STA _PAPER
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
    LDY #UDCCHAR
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
    LEAX 1, X

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
    LEAX 127, X
    LEAX 127, X
    LEAX 2, X
TEXTATBMNEXT2A
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
