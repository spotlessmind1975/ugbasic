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

PUTIMAGE
    LDA CURRENTMODE
    CMPA #0
    BNE PUTIMAGE0X
    JMP PUTIMAGE0
PUTIMAGE0X
    CMPA #1
    BNE PUTIMAGE1X
    JMP PUTIMAGE1
PUTIMAGE1X
    CMPA #2
    BNE PUTIMAGE2X
    JMP PUTIMAGE2
PUTIMAGE2X
    CMPA #3
    BNE PUTIMAGE3X
    JMP PUTIMAGE3
PUTIMAGE3X
    CMPA #4
    BNE PUTIMAGE4X
    JMP PUTIMAGE4
PUTIMAGE4X
    CMPA #5
    BNE PUTIMAGE5X
    JMP PUTIMAGE5
PUTIMAGE5X
    CMPA #6
    BNE PUTIMAGE6X
    JMP PUTIMAGE6
PUTIMAGE6X
    CMPA #7
    BNE PUTIMAGE7X
    JMP PUTIMAGE7
PUTIMAGE7X
    CMPA #8
    BNE PUTIMAGE8X
    JMP PUTIMAGE8
PUTIMAGE8X
    CMPA #9
    BNE PUTIMAGE9X
    JMP PUTIMAGE9
PUTIMAGE9X
    CMPA #10
    BNE PUTIMAGE10X
    JMP PUTIMAGE10
PUTIMAGE10X
    CMPA #11
    BNE PUTIMAGE11X
    JMP PUTIMAGE11
PUTIMAGE11X
    CMPA #12
    BNE PUTIMAGE12X
    JMP PUTIMAGE12
PUTIMAGE12X
    CMPA #13
    BNE PUTIMAGE13X
    JMP PUTIMAGE13
PUTIMAGE13X
    CMPA #14
    BNE PUTIMAGE14X
    JMP PUTIMAGE14
PUTIMAGE14X
    RTS

PUTIMAGE0
PUTIMAGE1
    RTS

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
PUTIMAGE2
    RTS

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
PUTIMAGE3
    RTS

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
PUTIMAGE4
    RTS

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
PUTIMAGE5
    RTS

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
PUTIMAGE6
    RTS

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
PUTIMAGE7

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

    JMP PUTIMAGECOMMONC

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
PUTIMAGE8
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

    JMP PUTIMAGECOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
PUTIMAGE9

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

    JMP PUTIMAGECOMMONC

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
PUTIMAGE10

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

    JMP PUTIMAGECOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
PUTIMAGE11

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

    JMP PUTIMAGECOMMONC

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF,
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
PUTIMAGE12

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

    JMP PUTIMAGECOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
PUTIMAGE13

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

    JMP PUTIMAGECOMMONC

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
PUTIMAGE14

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

    JMP PUTIMAGECOMMON

PUTIMAGECOMMON

    LDA ,Y
    LSRA
    LSRA
    LSRA
    CMPA #0
    BNE PUTIMAGE2L0
    LDA #32
PUTIMAGE2L0
    STA IMAGEW
    LDA 1,Y
    STA IMAGEH
    STA IMAGEH2

    LEAY 2,Y

    LDB IMAGEW
    DECB
PUTIMAGE2L1
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L1

    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2L1N

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2L1N0

    ORA #65
    STA IMAGEF

    LDB CURRENTSL
    LEAX B, X
    LDB IMAGEW
    DECB
    JMP PUTIMAGE2L1

PUTIMAGE2L1N0
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

PUTIMAGE2L1N
    LDB IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE

    LDB IMAGEW
    DECB
    JMP PUTIMAGE2L1

PUTIMAGECOMMONE
    RTS

PUTIMAGECOMMONC

    LDA ,Y
    LSRA
    LSRA
    CMPA #0
    BNE PUTIMAGECL0
    LDA #64
PUTIMAGECL0
    STA IMAGEW
    LDA 1,Y
    STA IMAGEH
    STA IMAGEH2

    LEAY 2,Y

    LDB IMAGEW
    DECB
PUTIMAGE2CL1
    LDA IMAGET
    BEQ PUTIMAGE2CL1DEF

PUTIMAGE2YTRANS3L1
    LDA #0
    STA <MATHPTR5
    LDA B,Y
    ; 00 01 10 00
    ANDA #$C0
    ; -> 00 00 00 00
    BEQ PUTIMAGE2YTRANS3L1P4X
    LDA <MATHPTR5
    ORA #$C0
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P4X
    LDA B,Y
    ; 00 01 10 00
    ANDA #$30
    ; -> 00 01 00 00
    BEQ PUTIMAGE2YTRANS3L1P3X
    LDA <MATHPTR5
    ORA #$30
    ; MATH PTR = 00 11 00 00
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P3X
    LDA B,Y
    ; 00 01 10 00
    ANDA #$0C
    ; -> 00 00 00 00
    BEQ PUTIMAGE2YTRANS3L1P2X
    LDA <MATHPTR5
    ORA #$0C
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P2X
    LDA B,Y
    ; 00 01 10 00
    ANDA #$03
    ; -> 00 01 00 00
    BEQ PUTIMAGE2YTRANS3L1P1X
    LDA <MATHPTR5
    ORA #$03
    ; MATH PTR = 00 11 00 00
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P1X
    LDA <MATHPTR5
    ; 00 11 11 00
    EORA #$FF
    ; 11 00 00 11
    STA <MATHPTR6
    LDA B,X
    ; 00 00 00 00
    ANDA <MATHPTR6
    STA <MATHPTR6
    ; 00 00 00 00
    LDA B,Y
    ANDA <MATHPTR5
    ORA <MATHPTR6
    JMP PUTIMAGE2CL1FINAL

PUTIMAGE2CL1DEF
    LDA B,Y
PUTIMAGE2CL1FINAL
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2CL1

    LDA IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2CL1N

    LDA IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2CL1N0

    ORA #65
    STA IMAGEF

    LDB CURRENTSL
    LEAX B, X
    LDB IMAGEW
    DECB
    JMP PUTIMAGE2CL1

PUTIMAGE2CL1N0
    LDA IMAGEF
    ANDA #$FE
    STA IMAGEF

PUTIMAGE2CL1N
    LDB IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC IMAGEH
    LDB IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONCE

    LDB IMAGEW
    DECB
    JMP PUTIMAGE2CL1

PUTIMAGECOMMONCE
    RTS
