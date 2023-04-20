; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

BLITIMAGEBLITADDR  fdb $0

BLITIMAGE
    LDA CURRENTMODE
    CMPA #0
    BNE BLITIMAGE0X
    JMP BLITIMAGE0
BLITIMAGE0X
    CMPA #1
    BNE BLITIMAGE1X
    JMP BLITIMAGE1
BLITIMAGE1X
    CMPA #2
    BNE BLITIMAGE2X
    JMP BLITIMAGE2
BLITIMAGE2X
    CMPA #3
    BNE BLITIMAGE3X
    JMP BLITIMAGE3
BLITIMAGE3X
    CMPA #4
    BNE BLITIMAGE4X
    JMP BLITIMAGE4
BLITIMAGE4X
    CMPA #5
    BNE BLITIMAGE5X
    JMP BLITIMAGE5
BLITIMAGE5X
    CMPA #6
    BNE BLITIMAGE6X
    JMP BLITIMAGE6
BLITIMAGE6X
    CMPA #7
    BNE BLITIMAGE7X
    JMP BLITIMAGE7
BLITIMAGE7X
    CMPA #8
    BNE BLITIMAGE8X
    JMP BLITIMAGE8
BLITIMAGE8X
    CMPA #9
    BNE BLITIMAGE9X
    JMP BLITIMAGE9
BLITIMAGE9X
    CMPA #10
    BNE BLITIMAGE10X
    JMP BLITIMAGE10
BLITIMAGE10X
    CMPA #11
    BNE BLITIMAGE11X
    JMP BLITIMAGE11
BLITIMAGE11X
    CMPA #12
    BNE BLITIMAGE12X
    JMP BLITIMAGE12
BLITIMAGE12X
    CMPA #13
    BNE BLITIMAGE13X
    JMP BLITIMAGE13
BLITIMAGE13X
    CMPA #14
    BNE BLITIMAGE14X
    JMP BLITIMAGE14
BLITIMAGE14X
    RTS

BLITIMAGE0
BLITIMAGE1
    RTS

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
BLITIMAGE2
    RTS

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
BLITIMAGE3
    RTS

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
BLITIMAGE4
    RTS

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
BLITIMAGE5
    RTS

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
BLITIMAGE6
    RTS

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
BLITIMAGE7

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

    JMP BLITIMAGECOMMONC

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
BLITIMAGE8
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

    JMP BLITIMAGECOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
BLITIMAGE9

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

    JMP BLITIMAGECOMMONC

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
BLITIMAGE10

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

    JMP BLITIMAGECOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
BLITIMAGE11

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

    JMP BLITIMAGECOMMONC

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF,
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
BLITIMAGE12

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

    JMP BLITIMAGECOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
BLITIMAGE13

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

    JMP BLITIMAGECOMMONC

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
BLITIMAGE14

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
    LSRA
    RORB
    LEAX D, X

    JMP BLITIMAGECOMMON

BLITIMAGECOMMON

    LDY BLITTMPPTR
    LDA , Y
    LSRA
    LSRA
    LSRA
    CMPA #0
    BNE BLITIMAGE2L0
    LDA #32
BLITIMAGE2L0
    STA IMAGEW
    LDA 1, Y
    STA IMAGEH
    STA IMAGEH2

    LEAY 2, Y

    STY BLITTMPPTR

    LDY BLITTMPPTR2
    LEAY 2, Y
    STY BLITTMPPTR2

    LDB IMAGEW
    DECB
BLITIMAGE2L1
    LDA B,X
    STA BLITS0
    LDY BLITTMPPTR
    LDA B, Y
    STA BLITS1
    LDY BLITTMPPTR2
    LDA B, Y
    STA BLITS2
    JSR [BLITIMAGEBLITADDR]
    STA B,X
    DECB
    CMPB #0
    BGE BLITIMAGE2L1

    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGE2L1N

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGE2L1N0

    ORA #65
    STA IMAGEF

    LDB CURRENTSL
    LEAX B, X
    LDB IMAGEW
    DECB
    JMP BLITIMAGE2L1

BLITIMAGE2L1N0
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

BLITIMAGE2L1N
    LDB IMAGEW

    LDY BLITTMPPTR
    LEAY B, Y
    STY BLITTMPPTR

    LDY BLITTMPPTR2
    LEAY B, Y
    STY BLITTMPPTR2

    LDB CURRENTSL
    LEAX B, X

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONE

    LDB IMAGEW
    DECB
    JMP BLITIMAGE2L1

BLITIMAGECOMMONE
    RTS

BLITIMAGECOMMONC

    LDY BLITTMPPTR

    LDA , Y
    LSRA
    LSRA
    CMPA #0
    BNE BLITIMAGECL0
    LDA #64
BLITIMAGECL0
    STA IMAGEW
    LDA 1, Y
    STA IMAGEH
    STA IMAGEH2

    LEAY 2, Y

    STY BLITTMPPTR

    LDY BLITTMPPTR2
    LEAY 2, Y
    STY BLITTMPPTR2

    LDB IMAGEW
    DECB
BLITIMAGE2CL1
BLITIMAGE2CL1DEF

    LDA B,X
    STA BLITS0
    LDY BLITTMPPTR
    LDA B, Y
    STA BLITS1
    LDY BLITTMPPTR2
    LDA B, Y
    STA BLITS2
    JSR [BLITIMAGEBLITADDR]
    STA B, X
    DECB
    CMPB #0
    BGE BLITIMAGE2CL1

    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGE2CL1N

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGE2CL1N0

    ORA #65
    STA IMAGEF

    LDB CURRENTSL
    LEAX B, X
    LDB IMAGEW
    DECB
    JMP BLITIMAGE2CL1

BLITIMAGE2CL1N0
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

BLITIMAGE2CL1N
    LDB IMAGEW

    LDY BLITTMPPTR
    LEAY B, Y
    STY BLITTMPPTR

    LDY BLITTMPPTR2
    LEAY B, Y
    STY BLITTMPPTR2

    LDB CURRENTSL
    LEAX B, X

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONCE

    LDB IMAGEW
    DECB
    JMP BLITIMAGE2CL1

BLITIMAGECOMMONCE
    RTS
