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
;*                            PLOT ROUTINE FOR GIME                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTX   EQU $41 ; $42
PLOTY   EQU $43
PLOTM   EQU $45
PLOTOMA EQU $46
PLOTAMA EQU $47

;--------------

PLOT
    LDA CURRENTTILEMODE
    BEQ PLOTGO
    RTS

PLOTGO
    LDD PLOTY
    CMPD CLIPY2
    BLE PLOTCLIP2
    JMP PLOTP
PLOTCLIP2
    CMPD CLIPY1
    BGE PLOTCLIP3
    JMP PLOTP
PLOTCLIP3
    LDD PLOTX
    CMPD CLIPX2
    BLE PLOTCLIP4
    JMP PLOTP
PLOTCLIP4
    CMPD CLIPX1
    BGE PLOTCLIP5
    JMP PLOTP
PLOTCLIP5

PLOTMODE

    LDB _PEN
    JSR GIMESELECTPALETTE
    STA -42, S

    LDX BITMAPADDRESS

    LDA CURRENTMODE
    ANDA #$E0
    CMPA #$E0
    BEQ PLOTB16
    CMPA #$60
    BEQ PLOTB4
    CMPA #$40
    LBEQ PLOTB2
    RTS

PLOTB16

    LDA CURRENTMODE
    ANDA #$1F
    CMPA #2
    BLE PLOTB16X64
    CMPA #5
    BLE PLOTB16X80
    CMPA #8
    BLE PLOTB16X128
    CMPA #11
    BLE PLOTB16X160
    CMPA #14
    BLE PLOTB16X256
    JMP PLOTB16X320
PLOTB16X64
    LDA #32
    JMP PLOTB16OFFSET
PLOTB16X80
    LDA #40
    JMP PLOTB16OFFSET
PLOTB16X128
    LDA #64
    JMP PLOTB16OFFSET
PLOTB16X160
    LDA #80
    JMP PLOTB16OFFSET
PLOTB16X256
    LDA #128
    JMP PLOTB16OFFSET
PLOTB16X320
    LDA #160
    JMP PLOTB16OFFSET
PLOTB16OFFSET
    LDB PLOTY+1
    MUL
    LEAX D, X

    LDD PLOTX
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT80
    LDB -42, S
    ANDB #$01
    LEAY B, Y
    LDB PLOTX+1
    ANDB #$01
    LEAY B, Y

    LDU #PLOTANDBIT8
    LEAU B, U

    JMP PLOTCOMMON

PLOTB4

    LDA CURRENTMODE
    ANDA #$1F
    CMPA #2
    BLE PLOTB4X64
    CMPA #5
    BLE PLOTB4X80
    CMPA #8
    BLE PLOTB4X128
    CMPA #11
    BLE PLOTB4X160
    CMPA #14
    BLE PLOTB4X256
    CMPA #17
    BLE PLOTB4X320
    CMPA #20
    BLE PLOTB4X512
    JMP PLOTB4X640
PLOTB4X64
    LDA #16
    JMP PLOTB4OFFSET
PLOTB4X80
    LDA #20
    JMP PLOTB4OFFSET
PLOTB4X128
    LDA #32
    JMP PLOTB4OFFSET
PLOTB4X160
    LDA #40
    JMP PLOTB4OFFSET
PLOTB4X256
    LDA #64
    JMP PLOTB4OFFSET
PLOTB4X320
    LDA #80
    JMP PLOTB4OFFSET
PLOTB4X512
    LDA #128
    JMP PLOTB4OFFSET
PLOTB4X640
    LDA #160
    JMP PLOTB4OFFSET
PLOTB4OFFSET
    LDB PLOTY+1
    MUL
    LEAX B, X

    LDD PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT40
    LDB -42, S
    ANDB #$03
    LSLB
    LSLB
    LEAY B, Y
    LDB PLOTX+1
    ANDB #$03
    LEAY B, Y

    LDU #PLOTANDBIT4
    LEAU B, U

    JMP PLOTCOMMON

PLOTB2

    LDA CURRENTMODE
    ANDA #$1F
    CMPA #2
    BLE PLOTB2X128
    CMPA #5
    BLE PLOTB2X160
    CMPA #8
    BLE PLOTB2X256
    CMPA #11
    BLE PLOTB2X320
    CMPA #14
    BLE PLOTB2X512
    JMP PLOTB2X640
PLOTB2X128
    LDA #16
    JMP PLOTB2OFFSET
PLOTB2X160
    LDA #20
    JMP PLOTB2OFFSET
PLOTB2X256
    LDA #32
    JMP PLOTB2OFFSET
PLOTB2X320
    LDA #30
    JMP PLOTB2OFFSET
PLOTB2X512
    LDA #64
    JMP PLOTB2OFFSET
PLOTB2X640
    LDA #80
    JMP PLOTB2OFFSET
PLOTB2OFFSET
    LDB PLOTY+1
    MUL
    LEAX B, X

    LDD PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT
    LDB PLOTX+1
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    JMP PLOTCOMMON

PLOTCOMMON

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
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
    ANDA , U
    ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE                          ;handled same way as setting a point
    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

PLOTG      
    LDA , X           ;get row with point in it
    ANDA , U
    CMPA #0
    BEQ PLOTG0
PLOTG1
    LDA #$ff
    STA PLOTM
    JMP PLOTP
PLOTG0
    LDA #$0
    STA PLOTM
    JMP PLOTP            

PLOTC                          
    LDA , X           ;get row with point in it
    STA PLOTM
    JMP PLOTP

PLOTP
    RTS

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

PLOTORBIT80
    fcb %00001111
    fcb %11110000

PLOTORBIT81
    fcb %11110000
    fcb %00001111

PLOTANDBIT8
    fcb %00001111
    fcb %11110000
