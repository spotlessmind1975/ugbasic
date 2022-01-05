; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                          IMAGES ROUTINE FOR 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

GETIMAGE
    LDA CURRENTMODE
    CMPA #0
    BNE GETIMAGE0X
    JMP GETIMAGE0
GETIMAGE0X
    CMPA #1
    BNE GETIMAGE1X
    JMP GETIMAGE1
GETIMAGE1X
    CMPA #2
    BNE GETIMAGE2X
    JMP GETIMAGE2
GETIMAGE2X
    CMPA #3
    BNE GETIMAGE3X
    JMP GETIMAGE3
GETIMAGE3X
    CMPA #4
    BNE GETIMAGE4X
    JMP GETIMAGE4
GETIMAGE4X
    CMPA #5
    BNE GETIMAGE5X
    JMP GETIMAGE5
GETIMAGE5X
    CMPA #6
    BNE GETIMAGE6X
    JMP GETIMAGE6
GETIMAGE6X
    CMPA #7
    BNE GETIMAGE7X
    JMP GETIMAGE7
GETIMAGE7X
    CMPA #8
    BNE GETIMAGE8X
    JMP GETIMAGE8
GETIMAGE8X
    CMPA #9
    BNE GETIMAGE9X
    JMP GETIMAGE9
GETIMAGE9X
    CMPA #10
    BNE GETIMAGE10X
    JMP GETIMAGE10
GETIMAGE10X
    CMPA #11
    BNE GETIMAGE11X
    JMP GETIMAGE11
GETIMAGE11X
    CMPA #12
    BNE GETIMAGE12X
    JMP GETIMAGE12
GETIMAGE12X
    CMPA #13
    BNE GETIMAGE13X
    JMP GETIMAGE13
GETIMAGE13X
    CMPA #14
    BNE GETIMAGE14X
    JMP GETIMAGE14
GETIMAGE14X
    RTS

GETIMAGE0
GETIMAGE1
    RTS

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
GETIMAGE2
    RTS

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
GETIMAGE3
    RTS

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
GETIMAGE4
    RTS

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
GETIMAGE5
    RTS

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
GETIMAGE6
    RTS

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
GETIMAGE7

    LDX BITMAPADDRESS
    LDD IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMONC

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
GETIMAGE8
    LDX BITMAPADDRESS
    LDD IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
GETIMAGE9

    LDX BITMAPADDRESS
    LDD IMAGEY
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

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMONC

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
GETIMAGE10

    LDX BITMAPADDRESS
    LDD IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
GETIMAGE11

    LDX BITMAPADDRESS
    LDD IMAGEY
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

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMONC

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF,
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
GETIMAGE12

    LDX BITMAPADDRESS
    LDD IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
GETIMAGE13

    LDX BITMAPADDRESS
    LDD IMAGEY
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

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMONC

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
GETIMAGE14

    LDX BITMAPADDRESS
    LDD IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP GETIMAGECOMMON

GETIMAGECOMMON

    LDA ,Y
    LSRA
    LSRA
    LSRA
    STA IMAGEW
    LDA 1,Y
    STA IMAGEH
    STA IMAGEH2

    LEAY 2,Y

    LDB IMAGEW
    DECB
GETIMAGE2L1
    LDA B,X
    STA B,Y
    DECB
    CMPB #0
    BGE GETIMAGE2L1

    LDB IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ GETIMAGECOMMONE

    LDB IMAGEW
    DECB
    JMP GETIMAGE2L1

GETIMAGECOMMONE
    RTS

GETIMAGECOMMONC

    LDA ,Y
    LSRA
    LSRA
    STA IMAGEW
    LDA 1,Y
    STA IMAGEH
    STA IMAGEH2

    LEAY 2,Y

    LDB IMAGEW
    DECB
GETIMAGE2CL1
GETIMAGE2CL1DEF
    LDA B,X
GETIMAGE2CL1FINAL
    STA B,Y
    DECB
    CMPB #0
    BGE GETIMAGE2CL1

    LDB IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ GETIMAGECOMMONCE

    LDB IMAGEW
    DECB
    JMP GETIMAGE2CL1

GETIMAGECOMMONCE
    RTS
