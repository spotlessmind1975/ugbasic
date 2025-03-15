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
;*                            PLOT ROUTINE FOR GIME                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTM   EQU $46
PLOTNB  EQU $48
PLOTNC  EQU $49
PLOTND  EQU $50
PLOTCPE   EQU $51

;--------------

PLOT
    LDA CURRENTTILEMODE
    BEQ PLOTGO
    RTS

PLOTGO

@IF scaleX > 0
    ASL <PLOTX+1
    ROL <PLOTX
@ENDIF

@IF scaleX > 1
    ASL <PLOTX+1
    ROL <PLOTX
@ENDIF

@IF offsetX > 0
@EMIT offsetX AS offsetX
    LDD <PLOTX
    ADDD #offsetX
    STD <PLOTX
@ENDIF

@IF scaleY > 0
    ASL <PLOTY+1
    ROL <PLOTY
@ENDIF

@IF scaleY > 1
    ASL <PLOTY+1
    ROL <PLOTY
@ENDIF

@IF offsetY > 0
@EMIT offsetY AS offsetY
    LDd <PLOTY
    ADDD #offsetY
    STD <PLOTY
@ENDIF

@IF optionClip

    LDD <PLOTY
    CMPD CLIPY2
    BLE PLOTCLIP2
    JMP PLOTP
PLOTCLIP2
    CMPD CLIPY1
    BGE PLOTCLIP3
    JMP PLOTP
PLOTCLIP3
    LDD <PLOTX
    CMPD CLIPX2
    BLE PLOTCLIP4
    JMP PLOTP
PLOTCLIP4
    CMPD CLIPX1
    BGE PLOTCLIP5
    JMP PLOTP
PLOTCLIP5

@ENDIF

PLOTMODE

    LDB PLOTCPE
    JSR GIMESELECTPALETTE
    STA <PLOTC

    JSR GIMECALCPOSBM

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

    LDA #4
    STA PLOTNB

    LDU #PLOTANDBIT8
    LDD <PLOTX
    ANDB #$1
    LEAU B, U

    CMPB #$1
    BEQ PLOTB16SKIP
    LDA <PLOTC
    LSLA
    LSLA
    LSLA
    LSLA
    JMP PLOTB16SKIPE
PLOTB16SKIP
    LDA <PLOTC
PLOTB16SKIPE
    STA <PLOTC

    STB PLOTND
    LDA #1
    SUBA PLOTND
    STA PLOTND

    JMP PLOTCOMMON

PLOTB4

    LDA #2
    STA PLOTNB

    LDB <(PLOTX+1)
    LDA <PLOTC
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    ANDB #$03
    BEQ PLOTB4SKIPE
    LSRA
    LSRA
    DECB
    BEQ PLOTB4SKIPE
    LSRA
    LSRA
    DECB
    BEQ PLOTB4SKIPE
    LSRA
    LSRA
    DECB
    BEQ PLOTB4SKIPE
    LSRA
    LSRA
PLOTB4SKIPE
    STA <PLOTC

    LDB <PLOTX+1
    ANDB #$03
    LDU #PLOTANDBIT4
    LEAU B, U

    STB PLOTND
    LDA #3
    SUBA PLOTND
    STA PLOTND

    JMP PLOTCOMMON

PLOTB2

    LDA #1
    STA PLOTNB

    LDY #PLOTORBIT
    LDB <PLOTX+1
    ANDB #$07
    LDA <PLOTC
    BEQ PLOTB2SKIPE
    LDA B, Y
    STA <PLOTC
    JMP PLOTB2SFINAL

PLOTB2SKIPE
    LDA #0
    STA <PLOTC
        
PLOTB2SFINAL
    LDU #PLOTANDBIT
    LEAU B, U

    STB PLOTND
    LDA #7
    SUBA PLOTND
    STA PLOTND

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
    BEQ PLOTCL                 ;if = 2 then branch to get the point (0/1)
    CMPA #3
    BEQ PLOTG                  ;if = 3 then branch to get the color index (0...15)
    JMP PLOTP

PLOTD
    ;---------
    ;set point
    ;---------

    ; The PLOT command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    ORCC #$50

    JSR GIMEBANKVIDEO

    LDA , X           ;get row with point in it
    ANDA , U
    ORA <PLOTC
    ; ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000

    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE                          ;handled same way as setting a point

    ; The PLOT command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKVIDEO

    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000

    JMP PLOTP                  ;skip the erase-point section

PLOTCL

    ; The PLOT command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKVIDEO

    LDA , U
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
    CMPA #2
    BEQ PLOTC2
    CMPA #1
    BEQ PLOTC1
    LSR PLOTNC
    LSR PLOTNC
PLOTC2
    LSR PLOTNC
PLOTC1
    LSR PLOTNC
    DECB
    JMP PLOTCL1
PLOTCE
    LDA PLOTNC
    STA PLOTM
    JMP PLOTP            

PLOTG                  

    JSR PLOTCL

    LDA PLOTM
    JSR GIMEGETPALETTE
    STB PLOTM

    JMP PLOTP

PLOTP

    ; The PLOT command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKROM
    
    ANDCC #$AF

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

PLOTORBIT8
    fcb %11110000
    fcb %00001111

PLOTANDBIT8
    fcb %00001111
    fcb %11110000
