; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                      TEXT AT GIVEN POSITION ON GTIA                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ******************************************************************************
; COMMON FUNCTIONS
; ******************************************************************************
; Write a char to the text screen.
; Input: A - screencode to print
;        COPYOFTEXTADDRESS - pointer to the interested screen memory
;        Y - offset inside the screen
; Output: -
TEXTATTMWRITECHAR:
    STA (COPYOFTEXTADDRESS),Y
    INC COPYOFTEXTADDRESS
    BNE TEXTATTMWRITECHARL1
    INC COPYOFTEXTADDRESS+1
TEXTATTMWRITECHARL1:
    RTS

; ******************************************************************************
; ENTRY POINT
; ******************************************************************************

TEXTATTILEMODE:
    LDA TEXTSIZE
    BNE TEXTATTMGO
    RTS

; ******************************************************************************
; PREPARATION
; ******************************************************************************

TEXTATTMGO:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA #0
    STA TABSTODRAW
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDA CURRENTMODE
    CMP #2
    BNE TEXTATTMANTIC2X
    JMP TEXTATTMANTIC2
TEXTATTMANTIC2X:
    CMP #6
    BNE TEXTATTMANTIC6X
    JMP TEXTATTMANTIC6
TEXTATTMANTIC6X:    
    CMP #7
    BNE TEXTATTMANTIC7X
    JMP TEXTATTMANTIC7
TEXTATTMANTIC7X:    
    CMP #3
    BNE TEXTATTMANTIC3X
    JMP TEXTATTMANTIC3
TEXTATTMANTIC3X:    
    CMP #4
    BNE TEXTATTMANTIC4X
    JMP TEXTATTMANTIC4
TEXTATTMANTIC4X:    
    CMP #5
    BNE TEXTATTMANTIC5X
    JMP TEXTATTMANTIC5
TEXTATTMANTIC5X:
    RTS

CALCPOS:

    TXA
    PHA

    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDX YCURSYS
    BEQ CALCPOSSKIP
CALCPOSLOOP1:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE CALCPOSLOOP1

CALCPOSSKIP:
    CLC
    LDA XCURSYS
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    PLA
    TAX

    RTS

;-----------------------------------------------------------------------------
; TILE MODE
;-----------------------------------------------------------------------------

TEXTATTMANTIC6:
TEXTATTMANTIC7:
@INLINE PALETTEPRESERVE2C5 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C6 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C7 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C8 [_PEN], [#$0]
    JMP TEXTATTMANTICX

TEXTATTMANTIC3:
TEXTATTMANTIC2:
TEXTATTMANTIC4:
TEXTATTMANTIC5:
@INLINE PALETTEPRESERVE2C5 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C6 [_PAPER], [#$0]

TEXTATTMANTICX:
    JSR CALCPOS

; ******************************************************************************
; MAIN LOOP
; ******************************************************************************

    ; x = text size, Y = screen position
    LDX TEXTSIZE
    LDY #$0

    ; Main writing loop
TEXTATTMLOOP:

    ; Skip writing if we are inside a tabulation.
    LDA TABSTODRAW
    BEQ TEXTATTMMAIN
    JMP TEXTATTMSKIPTAB

TEXTATTMMAIN:
    JSR TEXTATREADCHAR

    CMP #$7f
    BEQ TEXTATTMPARSETAB
    CMP #14
    BCS TEXTATTMPRINT
    JMP TEXTATTMPARSE

TEXTATTMPRINT:
    JSR TEXTATDECODE
    LDA SCREENCODE
    JSR TEXTATTMWRITECHAR
    JMP TEXTATTMINCX

TEXTATTMPARSETAB:
    JSR TEXTATTAB
    JMP TEXTATTMNEXT

TEXTATTMPARSE:
    CMP #13
    BEQ TEXTATTMPARSELF
    CMP #10
    BEQ TEXTATTMPARSELF
    CMP #09
    BEQ TEXTATTMPARSETAB
    CMP #01
    BEQ TEXTATTMPARSEPEN
    CMP #02
    BEQ TEXTATTMPARSEPAPER
    CMP #03
    BEQ TEXTATTMPARSECMOVE
    CMP #04
    BEQ TEXTATTMPARSEAT
    CMP #05
    BEQ TEXTATTMPARSECLS
    JMP TEXTATTMNEXT

TEXTATTMPARSECLS:
    TYA
    PHA
    TXA
    PHA
    JSR CLS
    PLA
    TAX
    PLA
    TAY
    JMP TEXTATTMNEXT

TEXTATTMPARSEAT:
    JMP TEXTATTMAT

TEXTATTMPARSELF:
    JMP TEXTATTMINCY

TEXTATTMPARSEPEN:
    JSR TEXTATREADCHAR
    CMP #$FF
    BNE TEXTATTMPARSEPENOK
    LDA #$0
TEXTATTMPARSEPENOK:    
    STA _PEN
    JMP TEXTATTMNEXT

TEXTATTMPARSEPAPER:
    JSR TEXTATREADCHAR
    JMP TEXTATTMNEXT

TEXTATTMPARSECMOVE:
    JSR TEXTATREADCHAR
    STA CLINEX
    JSR TEXTATREADCHAR
    STA CLINEY

TEXTATTMCMOVE:
    CLC
    LDA CLINEX
    ADC XCURSYS
    CMP CONSOLEX1
    BCC TEXTATTMCMOVESKIPX
    CMP CONSOLEX2
    BCS TEXTATTMCMOVESKIPX
    STA XCURSYS
    LDA CLINEX

    CMP #$80
    BCC TEXTATTMCMOVEADDPX

TEXTATTMCMOVESUBPX:
    EOR #$FF
    CLC
    ADC #$1
    STA CLINEX
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CLINEX
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    JMP TEXTATTMCMOVESKIPX

TEXTATTMCMOVEADDPX:

    CLC
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    JMP TEXTATTMCMOVESKIPX

TEXTATTMCMOVESKIPX:

    CLC
    LDA CLINEY
    ADC YCURSYS
    CMP CONSOLEY1
    BCC TEXTATTMCMOVESKIPY
    CMP CONSOLEY2
    BCS TEXTATTMCMOVESKIPY
    STA YCURSYS

TEXTATTMCMOVEADDPY:
    TXA
    PHA
    LDA CLINEY
    CMP #$80
    BCC TEXTATTMCMOVELOOPYP
    JMP TEXTATTMCMOVELOOPYM

TEXTATTMCMOVELOOPYP:
    TAX
TEXTATTMCMOVELOOPY:

    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    DEX
    BNE TEXTATTMCMOVELOOPY
    PLA
    TAX
    JMP TEXTATTMCMOVESKIPY

TEXTATTMCMOVELOOPYM:
    EOR #$FF
    CLC
    ADC #$1
    STA CLINEY
    TAX
TEXTATTMCMOVELOOPY2:

    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    DEX
    BNE TEXTATTMCMOVELOOPY2
    PLA
    TAX
    JMP TEXTATTMCMOVESKIPY

TEXTATTMCMOVESKIPY:
    JMP TEXTATTMNEXT

TEXTATTMAT:
    JSR TEXTATREADCHAR
    SEC
    SBC XCURSYS
    ADC CONSOLEX1
    STA CLINEX
    JSR TEXTATREADCHAR
    SEC
    SBC YCURSYS
    ADC CONSOLEY1
    STA CLINEY
    JMP TEXTATTMCMOVE

TEXTATTMSKIPTAB:
    DEC TABSTODRAW
    INC XCURSYS
    JMP TEXTATTMCHKCONSOLE

TEXTATTMINCX:
    INC XCURSYS
    
    CPX #0
    BNE TEXTATTMCHKCONSOLE
    JMP TEXTATTMDONE

TEXTATTMCHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATTMNEXT
    BCS TEXTATTMINCY
    JMP TEXTATTMNEXT
TEXTATTMINCY:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BEQ TEXTATTMNEXTCALCPOS
    BCS TEXTATTMSCROLLY
    JMP TEXTATTMNEXTCALCPOS
TEXTATTMSCROLLY:

    LDA COPYOFTEXTADDRESS
    PHA
    LDA COPYOFTEXTADDRESS+1
    PHA

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

    PLA
    STA COPYOFTEXTADDRESS+1
    PLA
    STA COPYOFTEXTADDRESS

    DEC YCURSYS

TEXTATTMNEXTCALCPOS:
    JSR CALCPOS

TEXTATTMNEXT:
    LDA TABSTODRAW
    BEQ TEXTATTMLOOP2
    JMP TEXTATTMLOOP
TEXTATTMLOOP2:
    CPX #0
    BEQ TEXTATTMDONE
    JMP TEXTATTMLOOP
TEXTATTMDONE:
    RTS