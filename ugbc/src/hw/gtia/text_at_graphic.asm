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
; Set the proper color register using the PEN value
; Input: PEN - color to use
; Output: -
TEXTATBMPARSEPENSSET:
    LDA _PEN
    CMP $2C4
    BNE TEXTATBMPARSEPENSET1X
    JMP TEXTATBMPARSEPENSET1
TEXTATBMPARSEPENSET1X:
    CMP $2C5
    BNE TEXTATBMPARSEPENSET2X
    JMP TEXTATBMPARSEPENSET2
TEXTATBMPARSEPENSET2X:
    CMP $2C6
    BNE TEXTATBMPARSEPENSET3X
    JMP TEXTATBMPARSEPENSET3
TEXTATBMPARSEPENSET3X:

    LDA LASTCOLOR
    CMP #1
    BEQ TEXTATBMPARSEPENSET1
    CMP #2
    BEQ TEXTATBMPARSEPENSET2
    CMP #3
    BEQ TEXTATBMPARSEPENSET3

    LDA #2
    STA LASTCOLOR
    JMP TEXTATSC1

TEXTATSC1:
@INLINE PALETTEPRESERVE2C4 [_PEN], [#$1]
TEXTATBMPARSEPENSET1:
    LDA #<TEXTATBMBITMASKC1
    STA MATHPTR4
    LDA #>TEXTATBMBITMASKC1
    STA MATHPTR4+1
    JMP TEXTATBMPARSEPENSSETDONE

TEXTATSC2:
@INLINE PALETTEPRESERVE2C5 [_PEN], [#$1]
TEXTATBMPARSEPENSET2:
    LDA #<TEXTATBMBITMASKC2
    STA MATHPTR4
    LDA #>TEXTATBMBITMASKC2
    STA MATHPTR4+1
    JMP TEXTATBMPARSEPENSSETDONE

TEXTATSC3:
@INLINE PALETTEPRESERVE2C6 [_PEN], [#$1]
TEXTATBMPARSEPENSET3:
    LDA #<TEXTATBMBITMASKC3
    STA MATHPTR4
    LDA #>TEXTATBMBITMASKC3
    STA MATHPTR4+1
    JMP TEXTATBMPARSEPENSSETDONE

TEXTATBMPARSEPENSSETDONE:
    RTS

; ******************************************************************************
; ENTRY POINT
; ******************************************************************************

TEXTATBITMAPMODE:
    LDA TEXTSIZE
    BNE TEXTATBMGO
    RTS

; ******************************************************************************
; PREPARATION
; ******************************************************************************

TEXTATBMGO:
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

    JMP TEXTATBMCOMMON

TEXTATBMANTIC:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE TEXTATBMANTIC8X
    JMP TEXTATBMANTIC8
TEXTATBMANTIC8X:
    CMP #9
    BNE TEXTATBMANTIC9X
    JMP TEXTATBMANTIC9
TEXTATBMANTIC9X:
    CMP #10
    BNE TEXTATBMANTIC10X
    JMP TEXTATBMANTIC10
TEXTATBMANTIC10X:
    CMP #11
    BNE TEXTATBMANTIC11X
    JMP TEXTATBMANTIC11
TEXTATBMANTIC11X:
    CMP #12
    BNE TEXTATBMANTIC12X
    JMP TEXTATBMANTIC12
TEXTATBMANTIC12X:
    CMP #13
    BNE TEXTATBMANTIC13X
    JMP TEXTATBMANTIC13
TEXTATBMANTIC13X:
    CMP #14
    BNE TEXTATBMANTIC14X
    JMP TEXTATBMANTIC14
TEXTATBMANTIC14X:
    CMP #15
    BNE TEXTATBMANTIC15X
    JMP TEXTATBMANTIC15
TEXTATBMANTIC15X:
    RTS
@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATBMANTIC8:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS8

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

TEXTATBMANTIC9:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS9

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

TEXTATBMANTIC10:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS10

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

TEXTATBMANTIC11:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS11

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

TEXTATBMANTIC12:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS12
    
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

TEXTATBMANTIC13:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS13

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

TEXTATBMANTIC14:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS14

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

TEXTATBMANTIC15:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS15

    RTS

@ENDIF

TEXTATBMCOMMON:

    JSR TEXTATBMANTIC
    JSR TEXTATBMPARSEPENSSET

; ******************************************************************************
; MAIN LOOP
; ******************************************************************************

    LDX TEXTSIZE
    LDY #$0
TEXTATBMLOOP:

    LDA TABSTODRAW
    BEQ TEXTATBMMAIN
    JMP TEXTATBMSKIPTAB

TEXTATBMMAIN:
    JSR TEXTATREADCHAR
    STA SCREENCODE

    CMP #$7f
    BEQ TEXTATBMPARSETAB
    CMP #14
    BCS TEXTATBMPRINT
    JMP TEXTATBMPARSE

TEXTATBMPRINT:
    JMP TEXTATBMPRINTDO

TEXTATBMPARSETAB:
    JSR TEXTATTAB
    JMP TEXTATBMNEXT

TEXTATBMPARSE:
    CMP #13
    BEQ TEXTATBMPARSELF
    CMP #10
    BEQ TEXTATBMPARSELF
    CMP #09
    BEQ TEXTATBMPARSETAB
    CMP #01
    BEQ TEXTATBMPARSEPEN
    CMP #02
    BEQ TEXTATBMPARSEPAPER
    CMP #03
    BEQ TEXTATBMPARSECMOVE
    CMP #04
    BEQ TEXTATBMPARSEAT
    CMP #05
    BEQ TEXTATBMPARSECLS
    JMP TEXTATBMNEXT

TEXTATBMPARSECLS:
    TYA
    PHA
    TXA
    PHA
    JSR CLS
    PLA
    TAX
    PLA
    TAY
    JMP TEXTATBMNEXT

TEXTATBMPARSEAT:
    JMP TEXTATBMAT

TEXTATBMPARSELF:
    JMP TEXTATBMINCY

TEXTATBMPARSEPEN:
    JSR TEXTATREADCHAR
    CMP #$FF
    BNE TEXTATBMPARSEPENOK
    LDA #$0
TEXTATBMPARSEPENOK:    
    STA _PEN
    JSR TEXTATBMPARSEPENSSET
    JMP TEXTATBMNEXT

TEXTATBMPARSEPAPER:
    JSR TEXTATREADCHAR
    CMP #$FF
    BNE TEXTATBMPARSEPAPEROK
    LDA #$0
TEXTATBMPARSEPAPEROK:    
    STA _PAPER
    JSR TEXTATBMPARSEPENSSET
    JMP TEXTATBMNEXT

TEXTATBMPARSECMOVE:
    JSR TEXTATREADCHAR
    STA CLINEX
    JSR TEXTATREADCHAR
    STA CLINEY

TEXTATBMCMOVE:
    CLC
    LDA CLINEX
    ADC XCURSYS
    CMP CONSOLEX1
    BCC TEXTATBMCMOVESKIPX
    CMP CONSOLEX2
    BCS TEXTATBMCMOVESKIPX
    STA XCURSYS

TEXTATBMCMOVESKIPX:
    CLC
    LDA CLINEY
    ADC YCURSYS
    CMP CONSOLEY1
    BCC TEXTATBMCMOVESKIPY
    CMP CONSOLEY2
    BCS TEXTATBMCMOVESKIPY
    STA YCURSYS

TEXTATBMCMOVESKIPY:
    JSR TEXTATBMANTIC
    LDY #0
    JMP TEXTATBMNEXT

TEXTATBMAT:
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
    JMP TEXTATBMCMOVE

TEXTATBMPRINTDO:
    JSR TEXTATDECODE

    TXA
    PHA
    TYA
    PHA

    LDY #0

    LDA SCREENCODE
    STA TMPPTR
    LDA #0
    STA TMPPTR+1

    CLC
    ASL TMPPTR
    ROL TMPPTR+1
    CLC
    ASL TMPPTR
    ROL TMPPTR+1
    CLC
    ASL TMPPTR
    ROL TMPPTR+1

    CLC
    LDA #$0
    ADC TMPPTR
    STA TMPPTR
    LDA #$E0
    ADC TMPPTR+1
    STA TMPPTR+1

    LDA PLOTDEST
    STA TMPPTR2
    LDA PLOTDEST+1
    STA TMPPTR2+1
TEXTATBMPRINTDOL1:
    LDA CURRENTMODE
    CMP #10
    BEQ TEXTATBMPRINTDOL1M
    CMP #13
    BEQ TEXTATBMPRINTDOL1M

    LDA (TMPPTR),Y
    STA (TMPPTR2),Y
    JMP TEXTATBMPRINTDOL1M2

TEXTATBMPRINTDOL1M:

    TXA
    PHA

    TYA
    PHA

    LDA (TMPPTR),Y

    AND #$F0
    LSR A
    LSR A
    LSR A
    LSR A

    TAY
    LDA (MATHPTR4), Y

    TAX

    PLA
    TAY

    TXA

    STA (TMPPTR2),Y

    PLA
    TAX

    CLC
    LDA TMPPTR2
    ADC #1
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    TXA
    PHA

    TYA
    PHA

    LDA (TMPPTR),Y

    AND #$0F

    TAY
    LDA (MATHPTR4), Y

    TAX

    PLA
    TAY

    TXA

    STA (TMPPTR2),Y

    PLA
    TAX

    JMP TEXTATBMPRINTDOL1M2

TEXTATBMPRINTDOL1M2:
    
    CLC
    LDA TMPPTR2
    ADC CURRENTSL
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1
    
    SEC
    LDA TMPPTR2
    SBC PATTERN
    STA TMPPTR2
    LDA TMPPTR2+1
    SBC #0
    STA TMPPTR2+1

    INY
    CPY #8
    BEQ TEXTATBMPRINTDOL1X
    JMP TEXTATBMPRINTDOL1

TEXTATBMPRINTDOL1X:
    CLC
    LDA PLOTDEST
    ADC PATTERN
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    PLA
    TAY

    PLA
    TAX
    
    JMP TEXTATBMINCX

TEXTATBMSKIPTAB:
    DEC TABSTODRAW
    INC XCURSYS
    JMP TEXTATBMCHKCONSOLE

TEXTATBMINCX:
    INC XCURSYS
    CPX #0
    BNE TEXTATBMCHKCONSOLE
    JMP TEXTATBMDONE
TEXTATBMCHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATBMNEXT
    BCS TEXTATBMINCY
    JMP TEXTATBMNEXT
TEXTATBMINCY:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BEQ TEXTATTMNEXTCALCPOS
    BCS TEXTATBMSCROLLY
    JMP TEXTATTMNEXTCALCPOS
TEXTATBMSCROLLY:

    ; scrolling ?

    DEC YCURSYS

TEXTATTMNEXTCALCPOS:
    JSR TEXTATBMANTIC
    LDY #0
TEXTATBMNEXT:
    LDA TABSTODRAW
    BEQ TEXTATBMXLOOP2
    JMP TEXTATBMLOOP
TEXTATBMXLOOP2:
    CPX #0
    BEQ TEXTATBMDONE
    JMP TEXTATBMLOOP
TEXTATBMDONE:
    RTS

TEXTATBMBITMASKC1:
    .BYTE   %00000000
    .BYTE   %00000001
    .BYTE   %00000100
    .BYTE   %00000101
    .BYTE   %00010000
    .BYTE   %00010001
    .BYTE   %00010100
    .BYTE   %00010101
    .BYTE   %01000000
    .BYTE   %01000001
    .BYTE   %01000100
    .BYTE   %01000101
    .BYTE   %01010000
    .BYTE   %01010001
    .BYTE   %01010100
    .BYTE   %01010101

TEXTATBMBITMASKC2:
    .BYTE   %00000000
    .BYTE   %00000010
    .BYTE   %00001000
    .BYTE   %00001010
    .BYTE   %00100000
    .BYTE   %00100010
    .BYTE   %00101000
    .BYTE   %00101010
    .BYTE   %10000000
    .BYTE   %10000010
    .BYTE   %10001000
    .BYTE   %10001010
    .BYTE   %10100000
    .BYTE   %10100010
    .BYTE   %10101000
    .BYTE   %10101010

TEXTATBMBITMASKC3:
    .BYTE   %00000000
    .BYTE   %00000011
    .BYTE   %00001100
    .BYTE   %00001111
    .BYTE   %00110000
    .BYTE   %00110011
    .BYTE   %00111100
    .BYTE   %00111111
    .BYTE   %11000000
    .BYTE   %11000011
    .BYTE   %11001100
    .BYTE   %11001111
    .BYTE   %11110000
    .BYTE   %11110011
    .BYTE   %11111100
    .BYTE   %11111111
