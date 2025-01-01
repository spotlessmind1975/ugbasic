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

TEXTATTILEMODERAW:
    LDA TEXTSIZE
    BNE TEXTATRAWTILEMODEGO
    RTS

TEXTATRAWTILEMODEGO:
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
    BNE TEXTATRAWANTIC2X
    JMP TEXTATRAWANTIC2
TEXTATRAWANTIC2X:
    CMP #6
    BNE TEXTATRAWANTIC6X
    JMP TEXTATRAWANTIC6
TEXTATRAWANTIC6X:    
    CMP #7
    BNE TEXTATRAWANTIC7X
    JMP TEXTATRAWANTIC7
TEXTATRAWANTIC7X:    
    CMP #3
    BNE TEXTATRAWANTIC3X
    JMP TEXTATRAWANTIC3
TEXTATRAWANTIC3X:    
    CMP #4
    BNE TEXTATRAWANTIC4X
    JMP TEXTATRAWANTIC4
TEXTATRAWANTIC4X:    
    CMP #5
    BNE TEXTATRAWANTIC5X
    JMP TEXTATRAWANTIC5
TEXTATRAWANTIC5X:
    RTS

CALCPOSRAW:

    LDX YCURSYS
    BEQ CALCPOSRAWSKIP
CALCPOSRAWLOOP1:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE CALCPOSRAWLOOP1

CALCPOSRAWSKIP:
    CLC
    LDA XCURSYS
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    RTS

;-----------------------------------------------------------------------------
; TILE MODE
;-----------------------------------------------------------------------------

TEXTATRAWANTIC6:
TEXTATRAWANTIC7:
@INLINE PALETTEPRESERVE2C5 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C6 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C7 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C8 [_PEN], [#$0]
    JMP TEXTATRAWANTICX

TEXTATRAWANTIC3:
TEXTATRAWANTIC2:
TEXTATRAWANTIC4:
TEXTATRAWANTIC5:
@INLINE PALETTEPRESERVE2C5 [_PEN], [#$0]
@INLINE PALETTEPRESERVE2C6 [_PAPER], [#$0]

TEXTATRAWANTICX:
    JSR CALCPOSRAW

    LDX TEXTSIZE
    LDY #$0
TEXTATRAWLOOP2:

    LDA (TEXTPTR),Y

    JSR TEXTATDECODE
    LDA SCREENCODE

    STA (COPYOFTEXTADDRESS),Y

    INC XCURSYS
    DEX
    BNE TEXTATRAWEND2X
    JMP TEXTATRAWEND2
TEXTATRAWEND2X:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATRAWNEXT
    BCS TEXTATRAWNEXT2
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT2:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BEQ TEXTATRAWNEXT
    BCS TEXTATRAWNEXT3
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT3:

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
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

TEXTATRAWNEXT:
    INY
    CPX #0
    BEQ TEXTATRAWEND
    JMP TEXTATRAWLOOP2
TEXTATRAWEND2:
TEXTATRAWEND:
    RTS