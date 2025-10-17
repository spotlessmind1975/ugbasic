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
;*                      TEXT AT GIVEN POSITION ON 6847B                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATBMRAWSET
    PSHS D
    CMPA #0 ; COLOR_BLACK
    BEQ TEXTATBMRAWGREEN
    CMPA #1 ; COLOR_RED
    BEQ TEXTATBMRAWYELLOW
    CMPA #2 ; COLOR_YELLOW
    BEQ TEXTATBMRAWBLUE
    CMPA #3 ; COLOR_BLUE
    BEQ TEXTATBMRAWRED
    JMP TEXTATBMRAWGREEN

TEXTATBMRAWGREEN
    LDD #TEXTATBMRAWC0
    ; STD   <MATHPTR5
    STA   <MATHPTR4
    STB   <MATHPTR5
    ; PSHS X,D
    ; LDX <MATHPTR4
    ; TFR X, D
    ; LDX <MATHPTR5
    ; TFR X, D
    ; LDX <MATHPTR6
    ; TFR X, D
    ; PULS D,X
    JMP TEXTATBMRAWCNOPEN

TEXTATBMRAWRED
    LDD #TEXTATBMRAWC3
    ; STD   <MATHPTR5
    STA   <MATHPTR4
    STB   <MATHPTR5
    ; PSHS X,D
    ; LDX <MATHPTR4
    ; TFR X, D
    ; LDX <MATHPTR5
    ; TFR X, D
    ; LDX <MATHPTR6
    ; TFR X, D
    ; PULS D,X
    JMP TEXTATBMRAWCNOPEN

TEXTATBMRAWYELLOW
    LDD #TEXTATBMRAWC1
    ; STD   <MATHPTR5
    STA   <MATHPTR4
    STB   <MATHPTR5    
    JMP TEXTATBMRAWCNOPEN

TEXTATBMRAWBLUE
    LDD #TEXTATBMRAWC2
    ; STD   <MATHPTR5
    STA   <MATHPTR4
    STB   <MATHPTR5
    JMP TEXTATBMRAWCNOPEN

TEXTATBMRAWCNOPEN
    PULS D
    RTS

TEXTATBITMAPMODERAW
    LDA <TEXTSIZE
    BNE TEXTATBMRAWGO
    RTS

TEXTATBMRAWGO

    LDA <XCURSYS
    STA <MATHPTR0
    LDA <YCURSYS
    STA <MATHPTR1

    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS
    LDA #0
    STA <TABSTODRAW

    LDY <TEXTPTR
    LDA CURRENTMODE
    CMPA #7
    BNE TEXTATBMRAW7X
    JMP TEXTATBMRAW7
TEXTATBMRAW7X
    CMPA #8
    BNE TEXTATBMRAW8X
    JMP TEXTATBMRAW8
TEXTATBMRAW8X
    CMPA #9
    BNE TEXTATBMRAW9X
    JMP TEXTATBMRAW9
TEXTATBMRAW9X
    CMPA #10
    BNE TEXTATBMRAW10X
    JMP TEXTATBMRAW10
TEXTATBMRAW10X
    CMPA #11
    BNE TEXTATBMRAW11X
    JMP TEXTATBMRAW11
TEXTATBMRAW11X
    CMPA #12
    BNE TEXTATBMRAW12X
    JMP TEXTATBMRAW12
TEXTATBMRAW12X
    CMPA #13
    BNE TEXTATBMRAW13X
    JMP TEXTATBMRAW13
TEXTATBMRAW13X
    CMPA #14
    BNE TEXTATBMRAW14X
    JMP TEXTATBMRAW14
TEXTATBMRAW14X
    RTS

;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
TEXTATBMRAW7

    JSR CALCPOS7

    JMP TEXTATBMRAWCOMMON

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
TEXTATBMRAW8

    JSR CALCPOS8

    JMP TEXTATBMRAWCOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
TEXTATBMRAW9

    JSR CALCPOS9

    JMP TEXTATBMRAWCOMMON

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
TEXTATBMRAW10

    JSR CALCPOS10

    JMP TEXTATBMRAWCOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
TEXTATBMRAW11

    JSR CALCPOS11

    JMP TEXTATBMRAWCOMMON

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
TEXTATBMRAW12

    JSR CALCPOS12

    JMP TEXTATBMRAWCOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
TEXTATBMRAW13

    JSR CALCPOS13

    JMP TEXTATBMRAWCOMMON

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
TEXTATBMRAW14

    JSR CALCPOS14

    JMP TEXTATBMRAWCOMMON

TEXTATBMRAWCOMMON

    LDB <TEXTSIZE
    LDY <TEXTPTR

TEXTATBMRAWTMPRECHKCONSOLE
    LDA XCURSYS
    CMPA CONSOLEX2
    BEQ TEXTATBMRAWTMPOSTCHKCONSOLE
    BCS TEXTATBMRAWTMINCYX
    JMP TEXTATBMRAWTMINCY
TEXTATBMRAWTMINCYX
    JMP TEXTATBMRAWTMPOSTCHKCONSOLE

TEXTATBMRAWTMPOSTCHKCONSOLE

TEXTATBMRAWLOOP2

    LDA <XCURSYS
    CMPA CONSOLEX2
    LBGT TEXTATBMRAWNEXT2

    LDA <TABSTODRAW
    BEQ TEXTATBMRAWNSKIPTAB
    JMP TEXTATBMRAWSKIPTAB

TEXTATBMRAWNSKIPTAB
    LDA ,Y+
    DECB
    STA <SCREENCODE

    CMPA #$7f
    BEQ TEXTATBMRAWTAB
    CMPA #14
    BHI TEXTATBMRAWXCC
    JMP TEXTATBMRAWCC

TEXTATBMRAWXCC
    ; JSR TEXTATDECODE
    JMP TEXTATBMRAWSP0

TEXTATBMRAWTAB
    LDA <XCURSYS
TEXTATBMRAWTAB2
    CMPA TABCOUNT
    BCC TEXTATBMRAWTAB3
    SUBA TABCOUNT
    JMP TEXTATBMRAWTAB2
TEXTATBMRAWTAB3
    STA <TMPPTR
    LDA TABCOUNT
    SUBA <TMPPTR
    STA <TABSTODRAW
    JMP TEXTATBMRAWNEXT

TEXTATBMRAWCC
    CMPA #13
    BEQ TEXTATBMRAWLF
    CMPA #10
    BEQ TEXTATBMRAWLF
    CMPA #09
    BEQ TEXTATBMRAWTAB
    CMPA #01
    BEQ TEXTATBMRAWPEN
    CMPA #02
    BEQ TEXTATBMRAWPAPER
    CMPA #03
    BEQ TEXTATBMRAWCMOVEPREPARE
    CMPA #04
    BEQ TEXTATBMRAWXAT
    CMPA #05
    BEQ TEXTATBMRAWCLS
    JMP TEXTATBMRAWNEXT

TEXTATBMRAWCLS
    JSR CLSG
    JMP TEXTATBMRAWNEXT

TEXTATBMRAWXAT
    JMP TEXTATBMRAWAT

TEXTATBMRAWLF
    JMP TEXTATBMRAWNEXT2
    
TEXTATBMRAWPEN
    LDA ,Y+
    DECB
    CMPA #$FF
    BNE TEXTATBMRAWPEN2
    LDA #$0
TEXTATBMRAWPEN2
    STA _PEN
    JMP TEXTATBMRAWNEXT

TEXTATBMRAWPAPER
    LDA , Y+
    DECB
    STA _PAPER
    JMP TEXTATBMRAWNEXT

TEXTATBMRAWCMOVEPREPARE
    LDA , Y+
    DECB
    ADDA <XCURSYS
    CMPA CONSOLEX1
    BLT TEXTATBMRAWCMOVEPREPARESKIPX
    CMPA CONSOLEX2
    BGT TEXTATBMRAWCMOVEPREPARESKIPX
    STA <XCURSYS
TEXTATBMRAWCMOVEPREPARESKIPX
    LDA , Y+
    DECB
    ADDA <YCURSYS
    CMPA CONSOLEY1
    BLT TEXTATBMRAWCMOVEPREPARESKIPY
    CMPA CONSOLEY2
    BGT TEXTATBMRAWCMOVEPREPARESKIPY
    STA <YCURSYS
TEXTATBMRAWCMOVEPREPARESKIPY
    JSR CALCPOSG
    JMP TEXTATBMRAWNEXTX

TEXTATBMRAWAT
    LDA , Y+
    DECB
    ADDA CONSOLEX1
    CMPA CONSOLEX2
    BGT TEXTATBMRAWATSKIPX
    STA <XCURSYS
TEXTATBMRAWATSKIPX
    LDA , Y+
    DECB
    ADDA CONSOLEY1
    CMPA CONSOLEY2
    BGT TEXTATBMRAWATSKIPY
    STA <YCURSYS
TEXTATBMRAWATSKIPY
    JSR CALCPOSG
    JMP TEXTATBMRAWNEXTX

TEXTATBMRAWSP0

    PSHS D,Y,X

    LDU #0
    LDY #UDCCHAR
    LDA <SCREENCODE
    LDB #8
    MUL
    LEAY D, Y

TEXTATBMRAWSP0L1
    LDA CURRENTMODE
    CMPA #7
    BEQ TEXTATBMRAWSP0L1M
    CMPA #9
    BEQ TEXTATBMRAWSP0L1M
    CMPA #11
    BEQ TEXTATBMRAWSP0L1M
    CMPA #13
    BEQ TEXTATBMRAWSP0L1M

    LDA ,Y
    STA ,X
    JMP TEXTATBMRAWSP0L1M2

TEXTATBMRAWSP0L1M

    LDA _PEN
    JSR TEXTATSET

    PSHS X
    LDX <MATHPTR4
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
    LDX <MATHPTR4
    LDA ,Y
    ANDA #$0F
    LDA A, X
    PULS X

    STA , X

    LDA _PAPER
    JSR TEXTATBMRAWSET

    LEAX -1, X

    PSHS X
    LDX <MATHPTR4
    LDA ,Y
    EORA #$FF
    ANDA #$F0
    LSRA
    LSRA
    LSRA
    LSRA
    LDA A, X
    PULS X
    
    ORA , X
    STA , X

    LEAX 1, X

    PSHS X
    LDX <MATHPTR4
    LDA ,Y
    EORA #$FF
    ANDA #$0F
    LDA A, X
    PULS X

    ORA , X
    STA , X

    JMP TEXTATBMRAWSP0L1M2

TEXTATBMRAWSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    ANDCC #$FE
    LDA <PATTERN
    EORA #$FF
    ADDA #1
    LEAX A, X 
        
    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMRAWSP0L1X
    JMP TEXTATBMRAWSP0L1

TEXTATBMRAWSP0L1X

    PULS D,Y,X

    LDA <PATTERN
    LEAX A, X 
    LEAX 1, X

    JMP TEXTATBMRAWINCX

TEXTATBMRAWSKIPTAB
    INC <XCURSYS
    DEC <TABSTODRAW
    BNE TEXTATBMRAWSKIPTAB2
TEXTATBMRAWSKIPTAB2
    JMP TEXTATBMRAWNEXTX

TEXTATBMRAWINCX
    INC <XCURSYS
    CMPB #0
    LBEQ TEXTATBMRAWEND2
TEXTATBMRAWNEXTX
    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATBMRAWNEXT2
    JMP TEXTATBMRAWNEXT
TEXTATBMRAWNEXT2
TEXTATBMRAWTMINCY
    LDA CONSOLEX1
    STA <XCURSYS
    INC <YCURSYS
TEXTATBMRAWNEXT2A
    LDA <YCURSYS
    CMPA CONSOLEY2

    BGT TEXTATBMRAWNEXT3
    JMP TEXTATBMRAWNEXTB
TEXTATBMRAWNEXT3
    DEC <YCURSYS

    LDA #$FF
    STA <DIRECTION
    JSR VSCROLLG

TEXTATBMRAWNEXTB
    PSHS D
    LDA <XCURSYS
    STA <MATHPTR0
    LDA <YCURSYS
    STA <MATHPTR1
    JSR CALCPOSG
    PULS D
TEXTATBMRAWNEXT
    LDA <TABSTODRAW
    BEQ TEXTATBMRAWXLOOP2
    JMP TEXTATBMRAWLOOP2
TEXTATBMRAWXLOOP2
    CMPB #0
    BEQ TEXTATBMRAWEND
    JMP TEXTATBMRAWLOOP2
TEXTATBMRAWEND2
TEXTATBMRAWEND
    RTS

TEXTATBMRAWC0
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000
    fcb   %00000000

TEXTATBMRAWC1
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

TEXTATBMRAWC2
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

TEXTATBMRAWC3
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
