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
;*                          CLS BOXED ROUTINE FOR 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

CLSBOX

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMPA #0
    BNE CLSBOX0X
    JMP CLSBOX0
CLSBOX0X
    CMPA #1
    BNE CLSBOX1X
    JMP CLSBOX1
CLSBOX1X
    CMPA #2
    BNE CLSBOX2X
    JMP CLSBOX2
CLSBOX2X
    CMPA #3
    BNE CLSBOX3X
    JMP CLSBOX3
CLSBOX3X
    CMPA #4
    BNE CLSBOX4X
    JMP CLSBOX4
CLSBOX4X
    CMPA #5
    BNE CLSBOX5X
    JMP CLSBOX5
CLSBOX5X
    CMPA #6
    BNE CLSBOX6X
    JMP CLSBOX6
CLSBOX6X
    CMPA #7
    BNE CLSBOX7X
    JMP CLSBOX7
CLSBOX7X
    CMPA #8
    BNE CLSBOX8X
    JMP CLSBOX8
CLSBOX8X
    CMPA #9
    BNE CLSBOX9X
    JMP CLSBOX9
CLSBOX9X
    CMPA #10
    BNE CLSBOX10X
    JMP CLSBOX10
CLSBOX10X
    CMPA #11
    BNE CLSBOX11X
    JMP CLSBOX11
CLSBOX11X
    CMPA #12
    BNE CLSBOX12X
    JMP CLSBOX12
CLSBOX12X
    CMPA #13
    BNE CLSBOX13X
    JMP CLSBOX13
CLSBOX13X
    CMPA #14
    BNE CLSBOX14X
    JMP CLSBOX14
CLSBOX14X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 0) || (currentMode == 1) )

CLSBOX0
CLSBOX1
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 2) )

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
CLSBOX2
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 3) )

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
CLSBOX3
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 4) )

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
CLSBOX4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 5) )

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
CLSBOX5
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 6) )

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
CLSBOX6
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 7) )

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
CLSBOX7

    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 8) )

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
CLSBOX8
    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 9) )

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
CLSBOX9

    LDX BITMAPADDRESS
    LDD <IMAGEY
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

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 10) )

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
CLSBOX10

    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 11) )

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
CLSBOX11

    LDX BITMAPADDRESS
    LDD <IMAGEY
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

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 12) )

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF,
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
CLSBOX12

    LDX BITMAPADDRESS
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 13) )

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
CLSBOX13

    LDX BITMAPADDRESS
    LDD <IMAGEY
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

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 14) )

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
CLSBOX14

    LDX BITMAPADDRESS
    LDD <IMAGEY
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

    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    JMP CLSBOXCOMMON

@ENDIF

CLSBOXCOMMON

    LDA <IMAGEW
    LSRA
    LSRA
    LSRA
    CMPA #0
    BNE CLSBOX2L0
    LDA #32
CLSBOX2L0
    STA <IMAGEW
    LDA <IMAGEH
    STA <IMAGEH2

    LDB <IMAGEW
    DECB
    CLRA
CLSBOX2L1
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L1

    LDB <IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE

    LDB <IMAGEW
    DECB
    CLRA
    JMP CLSBOX2L1

CLSBOXCOMMONE
    RTS

CLSBOXCOMMONC

    LDA <IMAGEW
    LSRA
    LSRA
    CMPA #0
    BNE CLSBOXCL0
    LDA #64
CLSBOXCL0
    STA <IMAGEW
    LDA <IMAGEH
    STA <IMAGEH2

    LDB <IMAGEW
    DECB
    CLRA
CLSBOX2CL1
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2CL1

    LDB <IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONCE

    LDB <IMAGEW
    DECB
    CLRA
    JMP CLSBOX2CL1

CLSBOXCOMMONCE
    RTS
