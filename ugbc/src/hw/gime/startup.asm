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

GIMESTARTUP

	LDA   #%01001100
	STA   GIMEINIT0
	LDA   #%00000011
	STA   GIMEVIDM
	LDA   #%00100101
	STA   GIMEVIDR
	LDA   #0
	STA   GIMEBRDR
	CLR   GIMEVSCRL
	LDA   #$C0
	STA   GIMEVOFF1
	CLR   GIMEVOFF0
	CLR   GIMEHOFF

    LDA   #$30
    STA   GIMEMMU6

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
	BNE GIMEINSERTPALETTEPENUNDER
	LDA #0
GIMEINSERTPALETTEPENUNDER
	STA PALETTEPENUNUSED
	LDX #PALETTEPEN
	STB A,X
	LDX #$FFB0
	STB A,X
GIMEINSERTPALETTEPENDONE
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
	LDX #$FFB8
	STB A,X
GIMEINSERTPALETTEPAPERDONE
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
	LDX #$FFB0
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
	LDX #$FFB8
	STB A,X
GIMEUPDATEPALETTEPAPERDONE
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
