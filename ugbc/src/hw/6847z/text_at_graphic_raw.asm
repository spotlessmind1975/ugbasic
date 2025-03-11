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
;*                     RAW TEXT AT GIVEN POSITION ON 6847                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATRAWSET
    RET
    
;     PSHS D
;     CMPA #0 ; COLOR_BLACK
;     BEQ TEXTATRAWRED
;     CMPA #1 ; COLOR_RED
;     BEQ TEXTATRAWRED
;     CMPA #2 ; COLOR_YELLOW
;     BEQ TEXTATRAWYELLOW
;     CMPA #3 ; COLOR_BLUE
;     BEQ TEXTATRAWBLUE
    
; TEXTATRAWYELLOW
;     LDD #TEXTATRAWBMC1
;     ; STD   <MATHPTR5
;     STA   <MATHPTR4
;     STB   <MATHPTR5
;     ; PSHS X,D
;     ; LDX <MATHPTR4
;     ; TFR X, D
;     ; LDX <MATHPTR5
;     ; TFR X, D
;     ; LDX <MATHPTR6
;     ; TFR X, D
;     ; PULS D,X
;     JMP TEXTATRAWBMCNOPEN

; TEXTATRAWBLUE
;     LDD #TEXTATRAWBMC2
;     ; STD   <MATHPTR5
;     STA   <MATHPTR4
;     STB   <MATHPTR5    
;     JMP TEXTATRAWBMCNOPEN

; TEXTATRAWRED
;     LDD #TEXTATRAWBMC3
;     ; STD   <MATHPTR5
;     STA   <MATHPTR4
;     STB   <MATHPTR5
;     JMP TEXTATRAWBMCNOPEN

; TEXTATRAWBMCNOPEN
;     PULS D
;     RTS

; TEXTATBITMAPMODERAW
;     LDA <TEXTSIZE
;     BNE TEXTATRAWBMGO
;     RTS

; TEXTATRAWBMGO
;     LDA <XCURSYS
;     STA <MATHPTR0
;     LDA <YCURSYS
;     STA <MATHPTR1

;     LDY TEXTADDRESS
;     STY <COPYOFTEXTADDRESS

;     LDY <TEXTPTR
;     LDA CURRENTMODE
;     CMPA #7
;     BNE TEXTATRAW7X
;     JMP TEXTATRAW7
; TEXTATRAW7X
;     CMPA #8
;     BNE TEXTATRAW8X
;     JMP TEXTATRAW8
; TEXTATRAW8X
;     CMPA #9
;     BNE TEXTATRAW9X
;     JMP TEXTATRAW9
; TEXTATRAW9X
;     CMPA #10
;     BNE TEXTATRAW10X
;     JMP TEXTATRAW10
; TEXTATRAW10X
;     CMPA #11
;     BNE TEXTATRAW11X
;     JMP TEXTATRAW11
; TEXTATRAW11X
;     CMPA #12
;     BNE TEXTATRAW12X
;     JMP TEXTATRAW12
; TEXTATRAW12X
;     CMPA #13
;     BNE TEXTATRAW13X
;     JMP TEXTATRAW13
; TEXTATRAW13X
;     CMPA #14
;     BNE TEXTATRAW14X
;     JMP TEXTATRAW14
; TEXTATRAW14X
;     RTS

; ;-----------------------------------------------------------------------------
; ; BITMAP MODE
; ;-----------------------------------------------------------------------------

; ; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; ; elements wide by 64 elements high. Each element may be one of four 
; ; colors. A 1K x 8 display memory is required. Each pixel equals 
; ; four dot-clocks by three scan lines.
; TEXTATRAW7

;     JSR CALCPOS7

;     JMP TEXTATRAWBMCOMMON

; ; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; ; by 64 elements high. Each element may be either ON or OFF. However, 
; ; the entire display may be one of two colors, selected by using the 
; ; color set select pin. A 1K x 8 display memory is required. Each 
; ; pixel equals two dotclocks by three scan lines.
; TEXTATRAW8

;     JSR CALCPOS8

;     JMP TEXTATRAWBMCOMMON

; ; The 128 x 64 Color Graphics mode generates a display matrix 128 
; ; elements wide by 64 elements high. Each element may be one of four 
; ; colors. A 2K x 8 display memory is required. Each pixel equals
; ; two dot-clocks by three scan lines.
; TEXTATRAW9

;     JSR CALCPOS9

;     JMP TEXTATRAWBMCOMMON

; ; The 128 x 96 Graphics mode generates a display matrix 128 
; ; elements wide by 96 elements high. Each element may be either 
; ; ON or OFF. However, the entire display may be one of two colors
; ; selected by using the color select pin. A 2K x 8 display memory 
; ; is required. Each pixel equals two dot-clocks by two scan lines.
; TEXTATRAW10

;     JSR CALCPOS10

;     JMP TEXTATRAWBMCOMMON

; ; The 128 x 96 Color Graphics mode generates a display 128 elements 
; ; wide by 96 elements high. Each element may be one of four colors. 
; ; A 3K x 8 display memory is required. Each pixel equals two 
; ; dot-clocks by two scan lines.
; TEXTATRAW11

;     JSR CALCPOS11

;     JMP TEXTATRAWBMCOMMON

; ; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; ; wide by 192 elements high. Each element may be either ON or OFF
; ; but the ON elements may be one of two colors selected with color 
; ; set select pin. A 3K x 8 display memory is required. Each pixel 
; ; equals two dot-clocks by one scan line.
; TEXTATRAW12

;     JSR CALCPOS12

;     JMP TEXTATRAWBMCOMMON

; ;  The 128 x 192 Color Graphics mode generates a display 128 elements 
; ;  wide by 192 elements high. Each element may be one of four colors.
; ;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
; ;  by one scan line.
; TEXTATRAW13

;     JSR CALCPOS13

;     JMP TEXTATRAWBMCOMMON

; ; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; ; 192 elements high. Each element may be either ON or OFF, but the ON 
; ; element may be one of two colors selected with the color set select pin. 
; ; A 6K x 8 display memory is required. Each pixel equals one 
; ; dot-clock by one scan line.
; TEXTATRAW14

;     JSR CALCPOS14

;     JMP TEXTATRAWBMCOMMON

; TEXTATRAWBMCOMMON

;     LDB <TEXTSIZE
;     LDY <TEXTPTR
; TEXTATRAWBMLOOP2

;     LDA ,Y
;     STA <SCREENCODE

;     PSHS D,Y,X

;     LDU #0
;     LDY #UDCCHAR
;     LDA <SCREENCODE
;     LDB #8
;     MUL
;     LEAY D, Y

; TEXTATRAWBMSP0L1
;     LDA CURRENTMODE
;     CMPA #7
;     BEQ TEXTATRAWBMSP0L1M
;     CMPA #9
;     BEQ TEXTATRAWBMSP0L1M
;     CMPA #11
;     BEQ TEXTATRAWBMSP0L1M
;     CMPA #13
;     BEQ TEXTATRAWBMSP0L1M

;     LDA ,Y
;     STA ,X
;     JMP TEXTATRAWBMSP0L1M2

; TEXTATRAWBMSP0L1M

;     LDA _PEN
;     JSR TEXTATRAWSET

;     PSHS X
;     LDX <MATHPTR4
;     LDA ,Y
;     ANDA #$F0
;     LSRA
;     LSRA
;     LSRA
;     LSRA
;     LDA A, X
;     PULS X

;     STA , X

;     LEAX 1, X

;     PSHS X
;     LDX <MATHPTR4
;     LDA ,Y
;     ANDA #$0F
;     LDA A, X
;     PULS X

;     STA , X

;     LDA _PAPER
;     JSR TEXTATRAWSET

;     LEAX -1, X

;     PSHS X
;     LDX <MATHPTR4
;     LDA ,Y
;     EORA #$FF
;     ANDA #$F0
;     LSRA
;     LSRA
;     LSRA
;     LSRA
;     LDA A, X
;     PULS X
    
;     ORA , X
;     STA , X

;     LEAX 1, X

;     PSHS X
;     LDX <MATHPTR4
;     LDA ,Y
;     EORA #$FF
;     ANDA #$0F
;     LDA A, X
;     PULS X

;     ORA , X
;     STA , X

;     JMP TEXTATRAWBMSP0L1M2

; TEXTATRAWBMSP0L1M2
    
;     LDA CURRENTSL
;     LEAX A, X 

;     ANDCC #$FE
;     LDA <PATTERN
;     EORA #$FF
;     ADDA #1
;     LEAX A, X 
        
;     LEAY 1, Y

;     LEAU 1, U
;     CMPU #8
;     BEQ TEXTATRAWBMSP0L1X
;     JMP TEXTATRAWBMSP0L1

; TEXTATRAWBMSP0L1X

;     PULS D,Y,X

;     LDA <PATTERN
;     LEAX A, X 
;     LEAX 1, X

;     INC <XCURSYS
;     DECB
;     LBEQ TEXTATRAWBMEND2
; TEXTATRAWBMNEXTX
;     LDA <XCURSYS
;     CMPA CONSOLEX2
;     BGT TEXTATRAWBMNEXT2
;     JMP TEXTATRAWBMNEXT
; TEXTATRAWBMNEXT2
;     LDA CONSOLEX1
;     STA <XCURSYS
;     INC <YCURSYS
; TEXTATRAWBMNEXT2A
;     LDA <YCURSYS
;     CMPA CONSOLEY2

;     BGT TEXTATRAWBMNEXT3
;     JMP TEXTATRAWBMNEXTB
; TEXTATRAWBMNEXT3
;     DEC <YCURSYS

;     LDA #$FF
;     STA <DIRECTION
;     JSR VSCROLLG

; TEXTATRAWBMNEXTB
;     PSHS D
;     LDA <XCURSYS
;     STA <MATHPTR0
;     LDA <YCURSYS
;     STA <MATHPTR1
;     JSR CALCPOSG
;     PULS D
; TEXTATRAWBMNEXT
;     LEAY 1,Y
;     CMPB #0
;     BEQ TEXTATRAWBMEND
;     JMP TEXTATRAWBMLOOP2
; TEXTATRAWBMEND2
; TEXTATRAWBMEND
;     RTS


; TEXTATRAWBMC1
;     fcb   %00000000
;     fcb   %00000001
;     fcb   %00000100
;     fcb   %00000101
;     fcb   %00010000
;     fcb   %00010001
;     fcb   %00010100
;     fcb   %00010101
;     fcb   %01000000
;     fcb   %01000001
;     fcb   %01000100
;     fcb   %01000101
;     fcb   %01010000
;     fcb   %01010001
;     fcb   %01010100
;     fcb   %01010101

; TEXTATRAWBMC2
;     fcb   %00000000
;     fcb   %00000010
;     fcb   %00001000
;     fcb   %00001010
;     fcb   %00100000
;     fcb   %00100010
;     fcb   %00101000
;     fcb   %00101010
;     fcb   %10000000
;     fcb   %10000010
;     fcb   %10001000
;     fcb   %10001010
;     fcb   %10100000
;     fcb   %10100010
;     fcb   %10101000
;     fcb   %10101010

; TEXTATRAWBMC3
;     fcb   %00000000
;     fcb   %00000011
;     fcb   %00001100
;     fcb   %00001111
;     fcb   %00110000
;     fcb   %00110011
;     fcb   %00111100
;     fcb   %00111111
;     fcb   %11000000
;     fcb   %11000011
;     fcb   %11001100
;     fcb   %11001111
;     fcb   %11110000
;     fcb   %11110011
;     fcb   %11111100
;     fcb   %11111111
