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
;*                          FLIP Y ROUTINE FOR 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Flip image
; ----------------------------------------------------------------------------

FLIPIMAGEY
    RET

;     LDA CURRENTMODE
;     CMPA #0
;     BNE FLIPIMAGEY0X
;     JMP FLIPIMAGEY0
; FLIPIMAGEY0X
;     CMPA #1
;     BNE FLIPIMAGEY1X
;     JMP FLIPIMAGEY1
; FLIPIMAGEY1X
;     CMPA #2
;     BNE FLIPIMAGEY2X
;     JMP FLIPIMAGEY2
; FLIPIMAGEY2X
;     CMPA #3
;     BNE FLIPIMAGEY3X
;     JMP FLIPIMAGEY3
; FLIPIMAGEY3X
;     CMPA #4
;     BNE FLIPIMAGEY4X
;     JMP FLIPIMAGEY4
; FLIPIMAGEY4X
;     CMPA #5
;     BNE FLIPIMAGEY5X
;     JMP FLIPIMAGEY5
; FLIPIMAGEY5X
;     CMPA #6
;     BNE FLIPIMAGEY6X
;     JMP FLIPIMAGEY6
; FLIPIMAGEY6X
;     CMPA #7
;     BNE FLIPIMAGEY7X
;     JMP FLIPIMAGEY7
; FLIPIMAGEY7X
;     CMPA #8
;     BNE FLIPIMAGEY8X
;     JMP FLIPIMAGEY8
; FLIPIMAGEY8X
;     CMPA #9
;     BNE FLIPIMAGEY9X
;     JMP FLIPIMAGEY9
; FLIPIMAGEY9X
;     CMPA #10
;     BNE FLIPIMAGEY10X
;     JMP FLIPIMAGEY10
; FLIPIMAGEY10X
;     CMPA #11
;     BNE FLIPIMAGEY11X
;     JMP FLIPIMAGEY11
; FLIPIMAGEY11X
;     CMPA #12
;     BNE FLIPIMAGEY12X
;     JMP FLIPIMAGEY12
; FLIPIMAGEY12X
;     CMPA #13
;     BNE FLIPIMAGEY13X
;     JMP FLIPIMAGEY13
; FLIPIMAGEY13X
;     CMPA #14
;     BNE FLIPIMAGEY14X
;     JMP FLIPIMAGEY14
; FLIPIMAGEY14X
;     RTS

; FLIPIMAGEY0
; FLIPIMAGEY1
;     RTS

; ; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; ; element in the standard 8 x 12 dot box. Three data bits may be used to select
; ; one of eight colors for the entire character box. The extra bit is used to 
; ; switch to alphanumeric. A 512 byte display memory is required. A density of 
; ; 64 x 32 elements is available in the display area. The element area is four
; ; dot-clocks wide by six lines high.
; FLIPIMAGEY2
;     RTS

; ; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; ; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; ; Six bits are used to generate this map and two data bits may be used to select 
; ; one of four colors in the display box. A 512 byte display memory is required. 
; ; The element area is four dot-clocks wide by four lines high.
; FLIPIMAGEY3
;     RTS

; ; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; ; standard 8 x 12 dot box. This mode requires four memory locations per box 
; ; and each memory location may specify one of eight colors or black. 
; ; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; ; available in the display area. The element area is four dot-clocks wide 
; ; by three lines high.
; FLIPIMAGEY4
;     RTS

; ; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; ; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; ; each memory location may specify one of eight colors or black. A 3072 byte 
; ; display memory is required. A density of 64 x 96 elements is available in the
; ; display area. The element area is four dot-clocks wide by two lineshigh.
; FLIPIMAGEY5
;     RTS

; ; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; ; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; ; per box and each memory location may specify one of eight colors or black. 
; ; A 6144 byte display memory is required. A density of 64 x 192
; ; elements is available in the display are. The element area is four 
; ; dot-clocks wide by one line high.
; FLIPIMAGEY6
;     RTS

; ; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; ; elements wide by 64 elements high. Each element may be one of four 
; ; colors. A 1K x 8 display memory is required. Each pixel equals 
; ; four dot-clocks by three scan lines.
; FLIPIMAGEY7

;     JMP FLIPIMAGEYCOMMONC

; ; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; ; by 64 elements high. Each element may be either ON or OFF. However, 
; ; the entire display may be one of two colors, selected by using the 
; ; color set select pin. A 1K x 8 display memory is required. Each 
; ; pixel equals two dotclocks by three scan lines.
; FLIPIMAGEY8

;     JMP FLIPIMAGEYCOMMON

; ; The 128 x 64 Color Graphics mode generates a display matrix 128 
; ; elements wide by 64 elements high. Each element may be one of four 
; ; colors. A 2K x 8 display memory is required. Each pixel equals
; ; two dot-clocks by three scan lines.
; FLIPIMAGEY9

;     JMP FLIPIMAGEYCOMMONC

; ; The 128 x 96 Graphics mode generates a display matrix 128 
; ; elements wide by 96 elements high. Each element may be either 
; ; ON or OFF. However, the entire display may be one of two colors
; ; selected by using the color select pin. A 2K x 8 display memory 
; ; is required. Each pixel equals two dot-clocks by two scan lines.
; FLIPIMAGEY10

;     JMP FLIPIMAGEYCOMMON

; ; The 128 x 96 Color Graphics mode generates a display 128 elements 
; ; wide by 96 elements high. Each element may be one of four colors. 
; ; A 3K x 8 display memory is required. Each pixel equals two 
; ; dot-clocks by two scan lines.
; FLIPIMAGEY11

;     JMP FLIPIMAGEYCOMMONC

; ; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; ; wide by 192 elements high. Each element may be either ON or OFF,
; ; but the ON elements may be one of two colors selected with color 
; ; set select pin. A 3K x 8 display memory is required. Each pixel 
; ; equals two dot-clocks by one scan line.
; FLIPIMAGEY12

;     JMP FLIPIMAGEYCOMMON

; ;  The 128 x 192 Color Graphics mode generates a display 128 elements 
; ;  wide by 192 elements high. Each element may be one of four colors.
; ;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
; ;  by one scan line.
; FLIPIMAGEY13

;     JMP FLIPIMAGEYCOMMONC

; ; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; ; 192 elements high. Each element may be either ON or OFF, but the ON 
; ; element may be one of two colors selected with the color set select pin. 
; ; A 6K x 8 display memory is required. Each pixel equals one 
; ; dot-clock by one scan line.
; FLIPIMAGEY14

;     JMP FLIPIMAGEYCOMMON

; FLIPIMAGEYCOMMON

;     ; Retrieve the width (in bytes) and the height 
;     ; (in bytes) of the image to flip horizontally.

;     LDA ,Y
;     LSRA
;     LSRA
;     LSRA
;     STA <IMAGEW
;     LDA 1,Y
;     STA <IMAGEH
;     STA <IMAGEH2

;     ; Move the image pointer ahead of header.

;     LEAY 2,Y

;     JMP FLIPIMAGEYCOMMONCL0

; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; FLIPIMAGEYCOMMONC

;     ; Retrieve the width (in bytes) and the height 
;     ; (in bytes) of the image to flip horizontally.

;     LDA ,Y
;     LSRA
;     LSRA
;     STA <IMAGEW
;     LDA 1,Y
;     STA <IMAGEH
;     STA <IMAGEH2

;     ; Move the image pointer ahead of header.

;     LEAY 2,Y

; FLIPIMAGEYCOMMONCL0

;     ; Copy the starting line pointer to the ending line pointer.

;     TFR Y, X

;     LDA <IMAGEW
;     LDB <IMAGEH
;     DECB
; FLIPIMAGEYCOMMONCL0L
;     ; Move ahead the ending line pointer of 2 x IMAGE WIDTH - 1
;     LEAX A, X
;     DECB
;     BNE FLIPIMAGEYCOMMONCL0L

;     CLRA
;     LDB <IMAGEH
;     LSRB
;     TFR D, U

; FLIPIMAGEYCOMMONCL1
;     LDB #0
; FLIPIMAGEYCOMMONCLN
;     LDA B, Y
;     PSHS D
;     LDA B, X
;     STA B, Y
;     PULS D
;     STA B, X
;     INCB
;     CMPB <IMAGEW
;     BNE FLIPIMAGEYCOMMONCLN

;     LEAY B, Y
;     EORB #$FF
;     INCB
;     LEAX B, X

;     ; Decrement the number of lines to flip.

;     LEAU -1, U

;     ; If not finished, repeat the loop.

;     CMPU #0
;     BNE FLIPIMAGEYCOMMONCL1

;     RTS
