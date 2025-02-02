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
;*                      TEXT AT GIVEN POSITION ON GTIA                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATRAWBMPENSSET:

    LDA _PEN
    CMP $2C4
    BNE TEXTATRAWC1X
    JMP TEXTATRAWC1
TEXTATRAWC1X:
    CMP $2C5
    BNE TEXTATRAWC2X
    JMP TEXTATRAWC2
TEXTATRAWC2X:
    CMP $2C6
    BNE TEXTATRAWC3X
    JMP TEXTATRAWC3
TEXTATRAWC3X:

    JSR FINDLASTCOLORUSED
    CMP #1
    BEQ TEXTATRAWC1
    CMP #2
    BEQ TEXTATRAWC2
    CMP #3
    BEQ TEXTATRAWC3

    JMP TEXTATRAWSC1

TEXTATRAWSC1:
TEXTATRAWC1:
@INLINE PALETTEPRESERVE2C4 [_PEN], [#$1]
    LDA #<TEXTATRAWBMC1
    STA MATHPTR5
    LDA #>TEXTATRAWBMC1
    STA MATHPTR5+1
    JMP TEXTATRAWBMPENSSETDONE

TEXTATRAWSC2:
TEXTATRAWC2:
@INLINE PALETTEPRESERVE2C5 [_PEN], [#$1]
    LDA #<TEXTATRAWBMC2
    STA MATHPTR5
    LDA #>TEXTATRAWBMC2
    STA MATHPTR5+1
    JMP TEXTATRAWBMPENSSETDONE

TEXTATRAWSC3:
TEXTATRAWC3:
@INLINE PALETTEPRESERVE2C6 [_PEN], [#$1]
    LDA #<TEXTATRAWBMC3
    STA MATHPTR5
    LDA #>TEXTATRAWBMC3
    STA MATHPTR5+1
    JMP TEXTATRAWBMPENSSETDONE

TEXTATRAWBMPENSSETDONE:
    RTS

TEXTATBITMAPMODERAW:
    LDA TEXTSIZE
    BNE TEXTATRAWBITMAPMODEGO
    RTS
TEXTATRAWBITMAPMODEGO:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE TEXTATRAWANTIC8X
    JMP TEXTATRAWANTIC8
TEXTATRAWANTIC8X:
    CMP #9
    BNE TEXTATRAWANTIC9X
    JMP TEXTATRAWANTIC9
TEXTATRAWANTIC9X:
    CMP #10
    BNE TEXTATRAWANTIC10X
    JMP TEXTATRAWANTIC10
TEXTATRAWANTIC10X:
    CMP #11
    BNE TEXTATRAWANTIC11X
    JMP TEXTATRAWANTIC11
TEXTATRAWANTIC11X:
    CMP #12
    BNE TEXTATRAWANTIC12X
    JMP TEXTATRAWANTIC12
TEXTATRAWANTIC12X:
    CMP #13
    BNE TEXTATRAWANTIC13X
    JMP TEXTATRAWANTIC13
TEXTATRAWANTIC13X:
    CMP #14
    BNE TEXTATRAWANTIC14X
    JMP TEXTATRAWANTIC14
TEXTATRAWANTIC14X:
    CMP #15
    BNE TEXTATRAWANTIC15X
    JMP TEXTATRAWANTIC15
TEXTATRAWANTIC15X:
    RTS
@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATRAWANTIC8:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS8

    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

TEXTATRAWANTIC9:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS9

    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

TEXTATRAWANTIC10:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS10

    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

TEXTATRAWANTIC11:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS11

    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

TEXTATRAWANTIC12:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS12
    
    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

TEXTATRAWANTIC13:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS13

    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

TEXTATRAWANTIC14:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS14

    JMP TEXTATRAWBMCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

TEXTATRAWANTIC15:

    LDA XCURSYS
    STA MATHPTR6
    LDA YCURSYS
    STA MATHPTR7
    JSR CALCPOS15

    JMP TEXTATRAWBMCOMMON

@ENDIF

TEXTATRAWBMCOMMON:

    JSR TEXTATRAWBMPENSSET

    LDX TEXTSIZE
    LDY #$0
TEXTATRAWBMLOOP2:
    LDA (TEXTPTR),Y
    STA SCREENCODE

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
TEXTATRAWBMSP0L1:
    LDA CURRENTMODE
    CMP #10
    BEQ TEXTATRAWBMSP0L1M
    CMP #13
    BEQ TEXTATRAWBMSP0L1M

    LDA (TMPPTR),Y
    STA (TMPPTR2),Y
    JMP TEXTATRAWBMSP0L1M2

TEXTATRAWBMSP0L1M:

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
    LDA (MATHPTR5), Y

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
    LDA (MATHPTR5), Y

    TAX

    PLA
    TAY

    TXA

    STA (TMPPTR2),Y

    PLA
    TAX

    JMP TEXTATRAWBMSP0L1M2

TEXTATRAWBMSP0L1M2:
    
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
    BEQ TEXTATRAWBMSP0L1X
    JMP TEXTATRAWBMSP0L1

TEXTATRAWBMSP0L1X:
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
    
    INC XCURSYS
    DEX
    BNE TEXTATRAWBMEND2X
    JMP TEXTATRAWBMEND2
TEXTATRAWBMEND2X:
    LDA XCURSYS
    CMP CONSOLEX2
    BCS TEXTATRAWBMNEXT2
    JMP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT2:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BCS TEXTATRAWBMNEXT3
    JMP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT3:

    ; scrolling ?

    DEC YCURSYS

TEXTATRAWBMNEXT:
TEXTATRAWBMXLOOP2:
    INY
    CPX #0
    BEQ TEXTATRAWBMEND
    JMP TEXTATRAWBMLOOP2
TEXTATRAWBMEND2:
TEXTATRAWBMEND:
    RTS

TEXTATRAWBMC1:
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

TEXTATRAWBMC2:
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

TEXTATRAWBMC3:
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
