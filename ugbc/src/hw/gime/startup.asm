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
;*                            STARTUP ROUTINE FOR GIME                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

GIMEINIT0   equ   $FF90
GIMEINIT1   equ   $FF91
GIMEIRQENR  equ   $FF92
GIMEFIRQENR equ   $FF93
GIMETIMSB   equ   $FF94
GIMETILSB   equ   $FF95
GIMERSVD1   equ   $FF96
GIMERSVD2   equ   $FF97
GIMEVIDM    equ   $FF98
GIMEVIDR    equ   $FF99
GIMEBRDR    equ   $FF9A
GIMERSVD3   equ   $FF9B
GIMEVSCRL   equ   $FF9C
GIMEVOFF1   equ   $FF9D
GIMEVOFF0   equ   $FF9E
GIMEHOFF    equ   $FF9F

GIMEMMU0   equ   $FFA0
GIMEMMU1   equ   $FFA1
GIMEMMU2   equ   $FFA2
GIMEMMU3   equ   $FFA3
GIMEMMU4   equ   $FFA4
GIMEMMU5   equ   $FFA5
GIMEMMU6   equ   $FFA6
GIMEMMU7   equ   $FFA7

GIMEMMU8   equ   $FFA8
GIMEMMU9   equ   $FFA9
GIMEMMUA   equ   $FFAA
GIMEMMUB   equ   $FFAB
GIMEMMUC   equ   $FFAC
GIMEMMUD   equ   $FFAD
GIMEMMUE   equ   $FFAE
GIMEMMUF   equ   $FFAF

; This routine is needed to implement the BANK command.
; It changes the $c000 address mapping on TASK 0.

GIMEBANKSHADOWCHANGE
    PSHS D
    LDA BANKSHADOW
    CMPA #$2F
    BGT GIMEBANKSHADOWCHANGERESET2
    STA GIMEMMU6
    PULS D
    RTS
GIMEBANKSHADOWCHANGERESET
    PSHS D
GIMEBANKSHADOWCHANGERESET2
    LDA #$3E
    STA GIMEMMU6
    PULS D
    RTS

; This routine is needed to setup the video RAM
; segments at screen mode change. It is setup
; on the TASK 1. The TASK 0 is left for 
; standard ROM / RAM

GIMERAM
	PSHS D, X
    ANDCC #$FE
    LDA GIMEMMUSTART
    LDX #GIMEMMUB
    LEAX A, X
    ANDCC #$FE
    LDA GIMESCREENCURRENT
    ADDA #$28
    LDB #0
GIMERAML2
    STA ,X
	LEAX 1, X
    INCA
    INCB
    CMPB GIMEMMUCOUNT
    BNE GIMERAML2
	PULS D, X
	RTS

; This routine is needed to save the current
; state of TASK bank selection (TASK 0 / TASK1).

GIMEBANKSAVE
    PSHS D
    LDA GIMEINIT1SHADOW
    STA GIMEINIT1BACKUP
    PULS D
    RTS

; This routine is needed to restore the
; state of TASK bank selection (TASK 0 / TASK1).

GIMEBANKRESTORE
    PSHS D
    LDA GIMEINIT1BACKUP
    STA GIMEINIT1
    STA GIMEINIT1SHADOW
    PULS D
    RTS

; This routine will give back the need of
; switch between video and memory RAM ad each
; read / write cycle.
;    Input: Y = address to check
;           U = size to check
;    Output: A = 1 switch is needed

GIMEBANKISNEEDED
    PSHS Y, D
    TFR U, D
    LEAY D, Y
    LDA GIMEMMUSTART
    BEQ GIMEBANKISNEEDED0
    CMPA #1
    BEQ GIMEBANKISNEEDED1
    CMPA #2
    BEQ GIMEBANKISNEEDED2
    CMPA #3
    BEQ GIMEBANKISNEEDED3
GIMEBANKISNEEDEDN
    PULS Y, D
    LDA #0
    RTS
GIMEBANKISNEEDED0
    CMPY #$5FFF
    BHI GIMEBANKISNEEDEDY
    JMP GIMEBANKISNEEDEDN
GIMEBANKISNEEDED1
    CMPY #$7FFF
    BHI GIMEBANKISNEEDEDY
    JMP GIMEBANKISNEEDEDN
GIMEBANKISNEEDED2
    CMPY #$9FFF
    BHI GIMEBANKISNEEDEDY
    JMP GIMEBANKISNEEDEDN
GIMEBANKISNEEDED3
    CMPY #$bFFF
    BHI GIMEBANKISNEEDEDY
    JMP GIMEBANKISNEEDEDN
GIMEBANKISNEEDEDY
    PULS Y, D
    LDA #1
    RTS

; This routine is needed to switch to video RAM.

GIMEBANKVIDEO
    PSHS D
    LDA GIMEINIT1SHADOW
    ORA #$1
    STA GIMEINIT1
    STA GIMEINIT1SHADOW
    PULS D
    RTS

; This routine is needed to setup the standard
; RAM / ROM segment. It actually does nothing
; since we preserve the default configuration.

GIMEROM
	RTS

; This routine is needed to switch to ROM/RAM.

GIMEBANKROM
    PSHS D
    LDA GIMEINIT1SHADOW
    ANDA #$FE
    STA GIMEINIT1
    STA GIMEINIT1SHADOW
    PULS D
    RTS

; This is the startup routine.

GIMESTARTUP

    ; Standard initialization

	LDA   #%01001100
	STA   GIMEINIT0
	LDA   #%00000011
    LDA   GIMEVIDM
    ANDA  #$8
    ORA   #%00000011
    STA   GIMEVIDM
    STA   GIMEVIDMSHADOW
	LDA   #%00100101
	STA   GIMEVIDR
	LDA   #0
	STA   GIMEBRDR
	CLR   GIMEVSCRL
    LDD   #$C000
	STD   GIMEVOFF1
	CLR   GIMEHOFF

    LDX #GIMEMMU8
    LDA #$38
    STA ,X+
    INCA
    STA ,X+
    INCA
    STA ,X+
    INCA
    STA ,X+
    INCA
    STA ,X+
    INCA
    STA ,X+
    INCA
    STA ,X+
    INCA
    STA ,X+

    ; Reset the palette.

	JSR GIMERESETPALETTE

    ; Setup the video RAM segments.
    JSR GIMERAM

    ; Turn on ROM/RAM
    JSR GIMEBANKROM

    LDA #$00
    STA GIMEBRDR

@IF vestigialConfig.clsImplicit
	JSR CLST
@ENDIF

    RTS

; Look for a specific (pen) color into the palette.
;   input: B = color to look for
;   output: A = index of ink, $FF if not found
GIMELOOKFORPALETTEPEN
	PSHS X
	LDA #0
	LDX #PALETTEPEN
GIMELOOKFORPALETTEPENL1
	CMPB A, X
	BEQ GIMELOOKFORPALETTEPEND
	INCA
	CMPA #8
	BNE GIMELOOKFORPALETTEPENL1
	LDA #$FF
GIMELOOKFORPALETTEPEND
	PULS X
	RTS

; Look for a specific (paper) color into the palette.
;   input: B = color to look for
;   output: A = index of ink, $FF if not found
GIMELOOKFORPALETTEPAPER
	PSHS X
	LDA #0
	LDX #PALETTEPAPER
GIMELOOKFORPALETTEPAPERL1
	CMPB A, X
	BEQ GIMELOOKFORPALETTEPAPERD
	INCA
	CMPA #8
	BNE GIMELOOKFORPALETTEPAPERL1
	LDA #$FF
GIMELOOKFORPALETTEPAPERD
	PULS X
	RTS

; Look for a specific color into the (paper+pen) palette.
;   input: B = color to look for
;   output: A = index of ink, $FF if not found
GIMELOOKFORPALETTE
	PSHS X
	LDA #0
	LDX #PALETTEPAPER
GIMELOOKFORPALETTEL1
	CMPB A, X
	BEQ GIMELOOKFORPALETTED
	INCA
	CMPA PALETTELIMIT
	BNE GIMELOOKFORPALETTEL1
	LDA #$FF
GIMELOOKFORPALETTED
	PULS X
	RTS

; Insert a specific color into the (pen) palette.
;   input: B = color to insert
;   output: A = index of ink allocated
GIMEINSERTPALETTEPEN
	PSHS X
    CMPB #$FF
    BEQ GIMEINSERTPALETTEPENDONE
	LDA PALETTEPENUNUSED
	INCA
	CMPA #8
	BEQ GIMEINSERTPALETTEPENDONE8
; 	LDA #0
; GIMEINSERTPALETTEPENUNDER
	STA PALETTEPENUNUSED
	LDX #PALETTEPEN
	STB A,X
	LDX #$FFB8
	STB A,X
GIMEINSERTPALETTEPENDONE
	PULS X
    RTS
GIMEINSERTPALETTEPENDONE8
    LDA #1
	PULS X
    RTS

; Insert a specific color into the (paper) palette.
;   input: B = color to insert
;   output: A = index of ink allocated
GIMEINSERTPALETTEPAPER
	PSHS X
    CMPB #$FF
    BEQ GIMEINSERTPALETTEPAPERDONE
	LDA PALETTEPAPERUNUSED
	INCA
	CMPA #8
	BNE GIMEINSERTPALETTEPAPERUNDER
	LDA #0
GIMEINSERTPALETTEPAPERUNDER
	STA PALETTEPAPERUNUSED
	LDX #PALETTEPAPER
	STB A,X
	LDX #$FFB0
	STB A,X
GIMEINSERTPALETTEPAPERDONE
	PULS X
    RTS

; Insert a specific color into the (paper+pen) palette.
;   input: B = color to insert
;   output: A = index of ink allocated
GIMEINSERTPALETTE
	PSHS X
    CMPB #$FF
    BEQ GIMEINSERTPALETTEDONE
	LDA PALETTEPAPERUNUSED
	INCA
	CMPA PALETTELIMIT
	BEQ GIMEINSERTPALETTEUNDERLIMIT
	; LDA #0
; GIMEINSERTPALETTEUNDER
	STA PALETTEPAPERUNUSED
	LDX #PALETTEPAPER
	STB A,X
	LDX #$FFB0
	STB A,X
GIMEINSERTPALETTEDONE
	PULS X
    RTS
GIMEINSERTPALETTEUNDERLIMIT
    LDA #1
	PULS X
    RTS
; Update a specific color into the (pen) palette.
;   input: 
;           A = index of ink to update
;           B = color to update
GIMEUPDATEPALETTEPEN
	PSHS X
	CMPB #$FF
	BEQ GIMEUPDATEPALETTEPENDONE
	LDX #PALETTEPEN
	STB A,X
	LDX #$FFB8
	STB A,X
GIMEUPDATEPALETTEPENDONE
	PULS X
	RTS

; Update a specific color into the (paper) palette.
;   input: 
;           A = index of ink to update
;           B = color to update
GIMEUPDATEPALETTEPAPER
	PSHS X
	CMPB #$FF
	BEQ GIMEUPDATEPALETTEPAPERDONE
	LDX #PALETTEPAPER
	STB A,X
	LDX #$FFB0
	STB A,X
GIMEUPDATEPALETTEPAPERDONE
	PULS X
	RTS

; Update a specific color into the (paper+pen) palette.
;   input: 
;           A = index of ink to update
;           B = color to update
GIMEUPDATEPALETTE
	PSHS X
	CMPB #$FF
	BEQ GIMEUPDATEPALETTEDONE
	LDX #PALETTEPAPER
	STB A,X
	LDX #$FFB0
	STB A,X
GIMEUPDATEPALETTEDONE
	PULS X
	RTS

; Get a specific color from the (pen) palette.
;   input: 
;           A = index of ink
;   output: 
;           B = color
GIMEGETPALETTEPEN
	PSHS X
	LDX #PALETTEPEN
	LDB A,X
	PULS X
	RTS

; Get a specific color from the (paper) palette.
;   input: 
;           A = index of ink
;   output: 
;           B = color
GIMEGETPALETTEPAPER
	PSHS X
	LDX #PALETTEPAPER
	LDB A,X
	PULS X
	RTS

; Get a specific color from the (paper+pen) palette.
;   input: 
;           A = index of ink
;   output: 
;           B = color
GIMEGETPALETTE
	PSHS X
	LDX #PALETTEPAPER
	LDB A,X
	PULS X
	RTS

; Look for a specific color into the (pen) palette and, if missing,
; insert it into palette.
;   input: 
;           B = color to look for / insert
;   output: 
;           A = index of ink
GIMESELECTPALETTEPEN
    JSR GIMELOOKFORPALETTEPEN
    CMPA #$FF
	BNE GIMESELECTPALETTEPENDONE
    JSR GIMEINSERTPALETTEPEN
GIMESELECTPALETTEPENDONE
    RTS
GIMESELECTPALETTEPENDONE0
    LDA #0
    RTS

; Look for a specific color into the (paper) palette and, if missing,
; insert it into palette.
;   input: 
;           B = color to look for / insert
;   output: 
;           A = index of ink
GIMESELECTPALETTEPAPER
    JSR GIMELOOKFORPALETTEPAPER
    CMPA #$FF
	BNE GIMESELECTPALETTEPAPERDONE
    JSR GIMEINSERTPALETTEPAPER
GIMESELECTPALETTEPAPERDONE
    RTS

; Look for a specific color into the (paper+pen) palette and, if missing,
; insert it into palette.
;   input: 
;           B = color to look for / insert
;   output: 
;           A = index of ink
GIMESELECTPALETTE
    JSR GIMELOOKFORPALETTE
    CMPA #$FF
	BNE GIMESELECTPALETTEDONE
    JSR GIMEINSERTPALETTE
GIMESELECTPALETTEDONE
    RTS

; Reset palette.
GIMERESETPALETTE
	PSHS Y, X, D
	LDA #0
	LDB #0
	LDX #PALETTEPAPER
	LDY #$FFB0
GIMERESETPALETTEL1
	STA B, X
	STA B, Y
	INCB
	CMPB #16
	BNE GIMERESETPALETTEL1
	PULS Y, X, D
	RTS

; Calculate the starting address (byte) of the first pixel
; positioned at <PLOTX, <PLOTY for the current screen mode.
;		Input: <PLOTX, <PLOTY
;		Output: 
;				X -> address
GIMECALCPOSBM
	PSHS D
    LDX BITMAPADDRESS

    LDA CURRENTMODE
    ANDA #$E0
    CMPA #$E0
    BEQ GIMECALCPOSBM16
    CMPA #$60
    BEQ GIMECALCPOSBM4
    CMPA #$40
    LBEQ GIMECALCPOSBM2
	PULS D
    RTS 

GIMECALCPOSBM16

    LDA CURRENTMODE
    ANDA #$1F
    CMPA #2
    BLE GIMECALCPOSBM16X64
    CMPA #5
    BLE GIMECALCPOSBM16X80
    CMPA #8
    BLE GIMECALCPOSBM16X128
    CMPA #11
    BLE GIMECALCPOSBM16X160
    CMPA #14
    BLE GIMECALCPOSBM16X256
    JMP GIMECALCPOSBM16X320
GIMECALCPOSBM16X64
    LDA #32
    JMP GIMECALCPOSBM16OFFSET
GIMECALCPOSBM16X80
    LDA #40
    JMP GIMECALCPOSBM16OFFSET
GIMECALCPOSBM16X128
    LDA #64
    JMP GIMECALCPOSBM16OFFSET
GIMECALCPOSBM16X160
    LDA #80
    JMP GIMECALCPOSBM16OFFSET
GIMECALCPOSBM16X256
    LDA #128
    JMP GIMECALCPOSBM16OFFSET
GIMECALCPOSBM16X320
    LDA #160
    JMP GIMECALCPOSBM16OFFSET
GIMECALCPOSBM16OFFSET
    LDB <PLOTY+1
    MUL
    LEAX D, X

    LDD <PLOTX
    LSRA
    RORB
    LEAX D, X

	PULS D
    RTS

GIMECALCPOSBM4

    LDA CURRENTMODE
    ANDA #$1F
    CMPA #2
    BLE GIMECALCPOSBM4X64
    CMPA #5
    BLE GIMECALCPOSBM4X80
    CMPA #8
    BLE GIMECALCPOSBM4X128
    CMPA #11
    BLE GIMECALCPOSBM4X160
    CMPA #14
    BLE GIMECALCPOSBM4X256
    CMPA #17
    BLE GIMECALCPOSBM4X320
    CMPA #20
    BLE GIMECALCPOSBM4X512
    JMP GIMECALCPOSBM4X640
GIMECALCPOSBM4X64
    LDA #16
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X80
    LDA #20
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X128
    LDA #32
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X160
    LDA #40
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X256
    LDA #64
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X320
    LDA #80
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X512
    LDA #128
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4X640
    LDA #160
    JMP GIMECALCPOSBM4OFFSET
GIMECALCPOSBM4OFFSET
    LDB <PLOTY+1
    MUL
    LEAX D, X

    LDD <PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

	PULS D
    RTS

GIMECALCPOSBM2

    LDA CURRENTMODE
    ANDA #$1F
    CMPA #2
    BLE GIMECALCPOSBM2X128
    CMPA #5
    BLE GIMECALCPOSBM2X160
    CMPA #8
    BLE GIMECALCPOSBM2X256
    CMPA #11
    BLE GIMECALCPOSBM2X320
    CMPA #14
    BLE GIMECALCPOSBM2X512
    JMP GIMECALCPOSBM2X640
GIMECALCPOSBM2X128
    LDA #16
    JMP GIMECALCPOSBM2OFFSET
GIMECALCPOSBM2X160
    LDA #20
    JMP GIMECALCPOSBM2OFFSET
GIMECALCPOSBM2X256
    LDA #32
    JMP GIMECALCPOSBM2OFFSET
GIMECALCPOSBM2X320
    LDA #40
    JMP GIMECALCPOSBM2OFFSET
GIMECALCPOSBM2X512
    LDA #64
    JMP GIMECALCPOSBM2OFFSET
GIMECALCPOSBM2X640
    LDA #80
    JMP GIMECALCPOSBM2OFFSET
GIMECALCPOSBM2OFFSET
    LDB <PLOTY+1
    MUL
    LEAX D, X

    LDD <PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

	PULS D
    RTS

GIMESCREENSWAP
    LDA GIMESCREENCURRENT
    BEQ GIMESCREENSWAPTO1
GIMESCREENSWAPTO0
    CLR GIMESCREENCURRENT
    LDD #$c000
    STD GIMEVOFF1
    JSR GIMERAM
    RTS
GIMESCREENSWAPTO1
    LDA #$8
    STA GIMESCREENCURRENT
    LDD #$a000
    STD GIMEVOFF1
    JSR GIMERAM
    RTS
