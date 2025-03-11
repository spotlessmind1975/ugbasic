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
;*                          FLIP IMAGE ROUTINE FOR 6847                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; FLIPIMAGEDATA1
;    fcb $00, $80, $40, $c0, $20, $a0, $60, $e0
;    fcb $10, $90, $50, $d0, $30, $b0, $70, $f0
;    fcb $08, $88, $48, $c8, $28, $a8, $68, $e8
;    fcb $18, $98, $58, $d8, $38, $b8, $78, $f8
;    fcb $04, $84, $44, $c4, $24, $a4, $64, $e4
;    fcb $14, $94, $54, $d4, $34, $b4, $74, $f4
;    fcb $0c, $8c, $4c, $cc, $2c, $ac, $6c, $ec
;    fcb $1c, $9c, $5c, $dc, $3c, $bc, $7c, $fc
;    fcb $02, $82, $42, $c2, $22, $a2, $62, $e2
;    fcb $12, $92, $52, $d2, $32, $b2, $72, $f2
;    fcb $0a, $8a, $4a, $ca, $2a, $aa, $6a, $ea
;    fcb $1a, $9a, $5a, $da, $3a, $ba, $7a, $fa
;    fcb $06, $86, $46, $c6, $26, $a6, $66, $e6
;    fcb $16, $96, $56, $d6, $36, $b6, $76, $f6
;    fcb $0e, $8e, $4e, $ce, $2e, $ae, $6e, $ee
;    fcb $1e, $9e, $5e, $de, $3e, $be, $7e, $fe
;    fcb $01, $81, $41, $c1, $21, $a1, $61, $e1
;    fcb $11, $91, $51, $d1, $31, $b1, $71, $f1
;    fcb $09, $89, $49, $c9, $29, $a9, $69, $e9
;    fcb $19, $99, $59, $d9, $39, $b9, $79, $f9
;    fcb $05, $85, $45, $c5, $25, $a5, $65, $e5
;    fcb $15, $95, $55, $d5, $35, $b5, $75, $f5
;    fcb $0d, $8d, $4d, $cd, $2d, $ad, $6d, $ed
;    fcb $1d, $9d, $5d, $dd, $3d, $bd, $7d, $fd
;    fcb $03, $83, $43, $c3, $23, $a3, $63, $e3
;    fcb $13, $93, $53, $d3, $33, $b3, $73, $f3
;    fcb $0b, $8b, $4b, $cb, $2b, $ab, $6b, $eb
;    fcb $1b, $9b, $5b, $db, $3b, $bb, $7b, $fb
;    fcb $07, $87, $47, $c7, $27, $a7, $67, $e7
;    fcb $17, $97, $57, $d7, $37, $b7, $77, $f7
;    fcb $0f, $8f, $4f, $cf, $2f, $af, $6f, $ef
;    fcb $1f, $9f, $5f, $df, $3f, $bf, $7f, $ff

; FLIPIMAGEDATA2
;    fcb $00, $40, $80, $c0, $10, $50, $90, $d0
;    fcb $20, $60, $a0, $e0, $30, $70, $b0, $f0
;    fcb $04, $44, $84, $c4, $14, $54, $94, $d4
;    fcb $24, $64, $a4, $e4, $34, $74, $b4, $f4
;    fcb $08, $48, $88, $c8, $18, $58, $98, $d8
;    fcb $28, $68, $a8, $e8, $38, $78, $b8, $f8
;    fcb $0c, $4c, $8c, $cc, $1c, $5c, $9c, $dc
;    fcb $2c, $6c, $ac, $ec, $3c, $7c, $bc, $fc
;    fcb $01, $41, $81, $c1, $11, $51, $91, $d1
;    fcb $21, $61, $a1, $e1, $31, $71, $b1, $f1
;    fcb $05, $45, $85, $c5, $15, $55, $95, $d5
;    fcb $25, $65, $a5, $e5, $35, $75, $b5, $f5
;    fcb $09, $49, $89, $c9, $19, $59, $99, $d9
;    fcb $29, $69, $a9, $e9, $39, $79, $b9, $f9
;    fcb $0d, $4d, $8d, $cd, $1d, $5d, $9d, $dd
;    fcb $2d, $6d, $ad, $ed, $3d, $7d, $bd, $fd
;    fcb $02, $42, $82, $c2, $12, $52, $92, $d2
;    fcb $22, $62, $a2, $e2, $32, $72, $b2, $f2
;    fcb $06, $46, $86, $c6, $16, $56, $96, $d6
;    fcb $26, $66, $a6, $e6, $36, $76, $b6, $f6
;    fcb $0a, $4a, $8a, $ca, $1a, $5a, $9a, $da
;    fcb $2a, $6a, $aa, $ea, $3a, $7a, $ba, $fa
;    fcb $0e, $4e, $8e, $ce, $1e, $5e, $9e, $de
;    fcb $2e, $6e, $ae, $ee, $3e, $7e, $be, $fe
;    fcb $03, $43, $83, $c3, $13, $53, $93, $d3
;    fcb $23, $63, $a3, $e3, $33, $73, $b3, $f3
;    fcb $07, $47, $87, $c7, $17, $57, $97, $d7
;    fcb $27, $67, $a7, $e7, $37, $77, $b7, $f7
;    fcb $0b, $4b, $8b, $cb, $1b, $5b, $9b, $db
;    fcb $2b, $6b, $ab, $eb, $3b, $7b, $bb, $fb
;    fcb $0f, $4f, $8f, $cf, $1f, $5f, $9f, $df
;    fcb $2f, $6f, $af, $ef, $3f, $7f, $bf, $ff


; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

FLIPIMAGEX
    RET

;     LDA CURRENTMODE
;     CMPA #0
;     BNE FLIPIMAGEX0X
;     JMP FLIPIMAGEX0
; FLIPIMAGEX0X
;     CMPA #1
;     BNE FLIPIMAGEX1X
;     JMP FLIPIMAGEX1
; FLIPIMAGEX1X
;     CMPA #2
;     BNE FLIPIMAGEX2X
;     JMP FLIPIMAGEX2
; FLIPIMAGEX2X
;     CMPA #3
;     BNE FLIPIMAGEX3X
;     JMP FLIPIMAGEX3
; FLIPIMAGEX3X
;     CMPA #4
;     BNE FLIPIMAGEX4X
;     JMP FLIPIMAGEX4
; FLIPIMAGEX4X
;     CMPA #5
;     BNE FLIPIMAGEX5X
;     JMP FLIPIMAGEX5
; FLIPIMAGEX5X
;     CMPA #6
;     BNE FLIPIMAGEX6X
;     JMP FLIPIMAGEX6
; FLIPIMAGEX6X
;     CMPA #7
;     BNE FLIPIMAGEX7X
;     JMP FLIPIMAGEX7
; FLIPIMAGEX7X
;     CMPA #8
;     BNE FLIPIMAGEX8X
;     JMP FLIPIMAGEX8
; FLIPIMAGEX8X
;     CMPA #9
;     BNE FLIPIMAGEX9X
;     JMP FLIPIMAGEX9
; FLIPIMAGEX9X
;     CMPA #10
;     BNE FLIPIMAGEX10X
;     JMP FLIPIMAGEX10
; FLIPIMAGEX10X
;     CMPA #11
;     BNE FLIPIMAGEX11X
;     JMP FLIPIMAGEX11
; FLIPIMAGEX11X
;     CMPA #12
;     BNE FLIPIMAGEX12X
;     JMP FLIPIMAGEX12
; FLIPIMAGEX12X
;     CMPA #13
;     BNE FLIPIMAGEX13X
;     JMP FLIPIMAGEX13
; FLIPIMAGEX13X
;     CMPA #14
;     BNE FLIPIMAGEX14X
;     JMP FLIPIMAGEX14
; FLIPIMAGEX14X
;     RTS

; FLIPIMAGEX0
; FLIPIMAGEX1
;     RTS

; ; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; ; element in the standard 8 x 12 dot box. Three data bits may be used to select
; ; one of eight colors for the entire character box. The extra bit is used to 
; ; switch to alphanumeric. A 512 byte display memory is required. A density of 
; ; 64 x 32 elements is available in the display area. The element area is four
; ; dot-clocks wide by six lines high.
; FLIPIMAGEX2
;     RTS

; ; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; ; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; ; Six bits are used to generate this map and two data bits may be used to select 
; ; one of four colors in the display box. A 512 byte display memory is required. 
; ; The element area is four dot-clocks wide by four lines high.
; FLIPIMAGEX3
;     RTS

; ; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; ; standard 8 x 12 dot box. This mode requires four memory locations per box 
; ; and each memory location may specify one of eight colors or black. 
; ; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; ; available in the display area. The element area is four dot-clocks wide 
; ; by three lines high.
; FLIPIMAGEX4
;     RTS

; ; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; ; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; ; each memory location may specify one of eight colors or black. A 3072 byte 
; ; display memory is required. A density of 64 x 96 elements is available in the
; ; display area. The element area is four dot-clocks wide by two lineshigh.
; FLIPIMAGEX5
;     RTS

; ; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; ; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; ; per box and each memory location may specify one of eight colors or black. 
; ; A 6144 byte display memory is required. A density of 64 x 192
; ; elements is available in the display are. The element area is four 
; ; dot-clocks wide by one line high.
; FLIPIMAGEX6
;     RTS

; ; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; ; elements wide by 64 elements high. Each element may be one of four 
; ; colors. A 1K x 8 display memory is required. Each pixel equals 
; ; four dot-clocks by three scan lines.
; FLIPIMAGEX7

;     JMP FLIPIMAGEXCOMMONC

; ; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; ; by 64 elements high. Each element may be either ON or OFF. However, 
; ; the entire display may be one of two colors, selected by using the 
; ; color set select pin. A 1K x 8 display memory is required. Each 
; ; pixel equals two dotclocks by three scan lines.
; FLIPIMAGEX8

;     JMP FLIPIMAGEXCOMMON

; ; The 128 x 64 Color Graphics mode generates a display matrix 128 
; ; elements wide by 64 elements high. Each element may be one of four 
; ; colors. A 2K x 8 display memory is required. Each pixel equals
; ; two dot-clocks by three scan lines.
; FLIPIMAGEX9

;     JMP FLIPIMAGEXCOMMONC

; ; The 128 x 96 Graphics mode generates a display matrix 128 
; ; elements wide by 96 elements high. Each element may be either 
; ; ON or OFF. However, the entire display may be one of two colors
; ; selected by using the color select pin. A 2K x 8 display memory 
; ; is required. Each pixel equals two dot-clocks by two scan lines.
; FLIPIMAGEX10

;     JMP FLIPIMAGEXCOMMON

; ; The 128 x 96 Color Graphics mode generates a display 128 elements 
; ; wide by 96 elements high. Each element may be one of four colors. 
; ; A 3K x 8 display memory is required. Each pixel equals two 
; ; dot-clocks by two scan lines.
; FLIPIMAGEX11

;     JMP FLIPIMAGEXCOMMONC

; ; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; ; wide by 192 elements high. Each element may be either ON or OFF,
; ; but the ON elements may be one of two colors selected with color 
; ; set select pin. A 3K x 8 display memory is required. Each pixel 
; ; equals two dot-clocks by one scan line.
; FLIPIMAGEX12

;     JMP FLIPIMAGEXCOMMON

; ;  The 128 x 192 Color Graphics mode generates a display 128 elements 
; ;  wide by 192 elements high. Each element may be one of four colors.
; ;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
; ;  by one scan line.
; FLIPIMAGEX13

;     JMP FLIPIMAGEXCOMMONC

; ; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; ; 192 elements high. Each element may be either ON or OFF, but the ON 
; ; element may be one of two colors selected with the color set select pin. 
; ; A 6K x 8 display memory is required. Each pixel equals one 
; ; dot-clock by one scan line.
; FLIPIMAGEX14

;     JMP FLIPIMAGEXCOMMON

; FLIPIMAGEXCOMMON

;     ; Retrieve the precalculated matrix for 2 bit colors

;     LDU #FLIPIMAGEDATA1

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

;     CLRA
;     LDB <IMAGEW
;     LSRB
;     STB <IMAGEW2

;     JMP FLIPIMAGEXCOMMONCL0

; FLIPIMAGEXCOMMONC

;     ; Retrieve the precalculated matrix for 2 bit colors

;     LDU #FLIPIMAGEDATA2

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

;     CLRA
;     LDB <IMAGEW
;     LSRB
;     STB <IMAGEW2

; FLIPIMAGEXCOMMONCL0

;     ; Copy the starting line pointer to the ending line pointer.

;     TFR Y, X

;     LDB <IMAGEW

;     ; Move ahead the ending line pointer of 2 x IMAGE WIDTH - 1

;     LEAX B, X
;     LEAX -1, X

;     ; Loop in both directions
;     ; <TMPPTR ---->
;     ;        <---- <TMPPTR2

; FLIPIMAGEXCOMMONCL1
;     CLRA
;     ; Take first left byte and invert it.
;     LDB , Y
;     LDB D, U
;     ; Save it on the stack.
;     PSHS D

;     ; Take first right byte and invert it.
;     LDB , X
;     LDB D, U
;     ; Store it on the first left byte.
;     STB , Y
;     ; Store the one stacked on the first right byte.
;     PULS D
;     STB , X

;     ; Move back the <TMPPTR2 pointer.

;     LEAX -1, X

;     ; Move ahead the <TMPPTR pointer.

;     LEAY 1, Y

;     ; Decrement the number of bytes to flip.

;     DEC <IMAGEW2

;     ; If not finished, repeat the loop.

;     BNE FLIPIMAGEXCOMMONCL1

;     LDA <IMAGEW
;     LSRA
;     STA <IMAGEW2

;     LDB <IMAGEW
;     LSRB
;     BCC FLIPIMAGEXCOMMONCNEXTLINE

;     CLRA
;     LDB , Y
;     LDB D, U
;     STB , Y

;     LEAY 1, Y

;     ; Move to the next line.
; FLIPIMAGEXCOMMONCNEXTLINE
;     LDB <IMAGEW2
;     LEAY B, Y

;     ; Decrement the number of line flipped.

;     DEC <IMAGEH

;     ; If there are lines to flip, repeat the loop.

;     LDB <IMAGEH
;     LBNE FLIPIMAGEXCOMMONCL0

;     RTS
