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
;*                            PLOT ROUTINE FOR 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTX   EQU $41
PLOTY   EQU $43
PLOTM   EQU $45
PLOTOMA EQU $46
PLOTAMA EQU $47
PLOTNB  EQU $48
PLOTNC  EQU $49
PLOTND  EQU $50
PLOTCPE  EQU $51

;--------------

PLOT

@IF scaleX > 0
    ASL <PLOTX
@ENDIF

@IF scaleX > 1
    ASL <PLOTX
@ENDIF

@IF offsetX > 0
@EMIT offsetX AS offsetX
    LDA <PLOTX
    ADDA #offsetX
    STA <PLOTX
@ENDIF

@IF scaleY > 0
    ASL <PLOTY
@ENDIF

@IF scaleY > 1
    ASL <PLOTY
@ENDIF

@IF offsetY > 0
@EMIT offsetY AS offsetY
    LDA <PLOTY
    ADDA #offsetY
    STA <PLOTY
@ENDIF

@IF optionClip
    LDA <PLOTY
    LDB CLIPY2+1
    CMPA CLIPY2+1
    BLO PLOTCLIP2
    JMP PLOTP
PLOTCLIP2
    CMPA CLIPY1+1
    BHS PLOTCLIP3
    JMP PLOTP
PLOTCLIP3
    LDA <PLOTX
    CMPA CLIPX2+1
    BLO PLOTCLIP4
    JMP PLOTP
PLOTCLIP4
    CMPA CLIPX1+1
    BHS PLOTCLIP5
    JMP PLOTP
PLOTCLIP5
@ENDIF

@IF !vestigialConfig.screenModeUnique

PLOTMODE
    LDA CURRENTMODE
    CMPA #0
    BNE PLOT0X
    JMP PLOT0
PLOT0X
    CMPA #1
    BNE PLOT1X
    JMP PLOT1
PLOT1X
    CMPA #2
    BNE PLOT2X
    JMP PLOT2
PLOT2X
    CMPA #3
    BNE PLOT3X
    JMP PLOT3
PLOT3X
    CMPA #4
    BNE PLOT4X
    JMP PLOT4
PLOT4X
    CMPA #5
    BNE PLOT5X
    JMP PLOT5
PLOT5X
    CMPA #6
    BNE PLOT6X
    JMP PLOT6
PLOT6X
    CMPA #7
    BNE PLOT7X
    JMP PLOT7
PLOT7X
    CMPA #8
    BNE PLOT8X
    JMP PLOT8
PLOT8X
    CMPA #9
    BNE PLOT9X
    JMP PLOT9
PLOT9X
    CMPA #10
    BNE PLOT10X
    JMP PLOT10
PLOT10X
    CMPA #11
    BNE PLOT11X
    JMP PLOT11
PLOT11X
    CMPA #12
    BNE PLOT12X
    JMP PLOT12
PLOT12X
    CMPA #13
    BNE PLOT13X
    JMP PLOT13
PLOT13X
    CMPA #14
    BNE PLOT14X
    JMP PLOT14
PLOT14X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 0) || (currentMode == 1) )

PLOT0
PLOT1
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 2) )

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
PLOT2
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 3) )

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
PLOT3
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 4) )

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
PLOT4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 5) )

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
PLOT5
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 6) )

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
PLOT6
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 7) )

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
PLOT7

    LDA #2
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT40
    LDB PLOTCPE
    ANDB #$03
    LSLB
    LSLB
    LEAY B, Y
    LDB <PLOTX
    ANDB #$03
    LEAY B, Y

    LDU #PLOTANDBIT4
    LEAU B, U

    STB PLOTND
    LDA #3
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 8) )

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
PLOT8

    LDA #1
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT
    LDB <PLOTX
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    STB PLOTND
    LDA #7
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 9) )

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
PLOT9

    LDA #2
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
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

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT40
    LDB PLOTCPE
    ANDB #$03
    LSLB
    LSLB
    LEAY B, Y
    LDB <PLOTX
    ANDB #$03
    LEAY B, Y

    LDU #PLOTANDBIT4
    LEAU B, U

    STB PLOTND
    LDA #3
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 10) )

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
PLOT10

    LDA #1
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT
    LDB <PLOTX
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    STB PLOTND
    LDA #7
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 11) )

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
PLOT11

    LDA #2
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
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

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT40
    LDB PLOTCPE
    ANDB #$03
    LSLB
    LSLB
    LEAY B, Y
    LDB <PLOTX
    ANDB #$03
    LEAY B, Y

    LDU #PLOTANDBIT4
    LEAU B, U

    STB PLOTND
    LDA #3
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 12) )

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF,
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
PLOT12

    LDA #1
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT
    LDB <PLOTX
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    STB PLOTND
    LDA #7
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 13) )

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
PLOT13

    LDA #2
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
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

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT40
    LDB PLOTCPE
    ANDB #$03
    LSLB
    LSLB
    LEAY B, Y
    LDB <PLOTX
    ANDB #$03
    LEAY B, Y

    LDU #PLOTANDBIT4
    LEAU B, U

    STB PLOTND
    LDA #3
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    JMP PLOTCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 14) )

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
PLOT14

    LDA #1
    STA PLOTNB

    LDX BITMAPADDRESS
    LDB <PLOTY
    CLRA
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

    LDB <PLOTX
    CLRA
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT
    LDB <PLOTX
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    STB PLOTND
    LDA #7
    SUBA PLOTND
    STA PLOTND

    JSR PLOTPREPARE

    LDA PLOTCPE
    CMPA #4
    BEQ PLOT14B

    JMP PLOTCOMMON

PLOT14B
    LDA #0
    STA PLOTOMA

    JMP PLOTCOMMON

@ENDIF

PLOTPREPARE
    LDA , U
    STA PLOTAMA
    LDA , Y
    STA PLOTOMA
    RTS

PLOTCOMMON

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA <PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
    CMPA #0
    BEQ PLOTE                  ;if = 0 then branch to clear the point
    CMPA #1
    BEQ PLOTD                  ;if = 1 then branch to draw the point
    CMPA #2
    BEQ PLOTG                  ;if = 2 then branch to get the point (0/1)
    CMPA #3
    BEQ PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JMP PLOTP
PLOTD
    ;---------
    ;set point
    ;---------

    LDA , X           ;get row with point in it
    ANDA PLOTAMA
    ORA PLOTOMA               ;isolate AND set the point
    STA , X           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE                          ;handled same way as setting a point
    LDA , X           ;get row with point in it
    ANDA PLOTAMA
    STA , X           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

PLOTC
    LDA PLOTAMA
    ANDCC #$FE
    COMA
    STA PLOTNC
    LDA , X           ;get row with point in it
    ANDA PLOTNC
    STA PLOTNC
    LDB PLOTND
PLOTCL1
    CMPB #0
    BEQ PLOTCE
    LDA PLOTNB
    CMPA #1
    BEQ PLOTC1
    LSR PLOTNC
PLOTC1
    LSR PLOTNC
    DECB
    JMP PLOTCL1
PLOTCE
    LDA PLOTNC
    STA <PLOTM
    JMP PLOTP            

PLOTG
    JSR PLOTC
    LDA <PLOTM
    JMP PLOTP

PLOTP
    RTS

;----------------------------------------------------------------

PLOTORBIT
    fcb %10000000
    fcb %01000000
    fcb %00100000
    fcb %00010000
    fcb %00001000
    fcb %00000100
    fcb %00000010
    fcb %00000001

PLOTANDBIT
    fcb %01111111
    fcb %10111111
    fcb %11011111
    fcb %11101111
    fcb %11110111
    fcb %11111011
    fcb %11111101
    fcb %11111110

PLOTORBIT40
    fcb %00000000
    fcb %00000000
    fcb %00000000
    fcb %00000000

PLOTORBIT41
    fcb %01000000
    fcb %00010000
    fcb %00000100
    fcb %00000001

PLOTORBIT42
    fcb %10000000
    fcb %00100000
    fcb %00001000
    fcb %00000010

PLOTORBIT43
    fcb %11000000
    fcb %00110000
    fcb %00001100
    fcb %00000011

PLOTANDBIT4
    fcb %00111111
    fcb %11001111
    fcb %11110011
    fcb %11111100
