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
;*                          VERTICAL SCROLL ON GTIA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF verticalOverlapRequired

VSCROLLBUFFERLINE: .RES 40,  0

@ENDIF

VSCROLLT:
    LDA CURRENTMODE
    CMP #2
    BNE VSCROLLTANTIC2X
    JMP VSCROLLTANTIC2
VSCROLLTANTIC2X:
    CMP #6
    BNE VSCROLLTANTIC6X
    JMP VSCROLLTANTIC6
VSCROLLTANTIC6X:
    CMP #7
    BNE VSCROLLTANTIC7X
    JMP VSCROLLTANTIC7
VSCROLLTANTIC7X:
    CMP #3
    BNE VSCROLLTANTIC3X
    JMP VSCROLLTANTIC3
VSCROLLTANTIC3X:
    CMP #4
    BNE VSCROLLTANTIC4X
    JMP VSCROLLTANTIC4
VSCROLLTANTIC4X:
    CMP #5
    BNE VSCROLLTANTIC5X
    JMP VSCROLLTANTIC5
VSCROLLTANTIC5X:

    ; CMP #8
    ; BNE VSCROLLTANTIC8X
    ; JMP VSCROLLTANTIC8
    ; CMP #9
    ; BEQ PLOTANTIC9
    ; CMP #10
    ; BEQ PLOTANTIC10
    ; CMP #11
    ; BEQ PLOTANTIC11
    ; CMP #13
    ; BEQ PLOTANTIC13
    ; CMP #15
    ; BEQ PLOTANTIC15
    ; CMP #12
    ; BEQ PLOTANTIC12
    ; CMP #14
    ; BEQ PLOTANTIC14
    RTS

VSCROLLTANTIC2:
VSCROLLTANTIC6:
VSCROLLTANTIC7:
VSCROLLTANTIC3:
VSCROLLTANTIC4:
VSCROLLTANTIC5:
    TXA
    PHA
    TYA
    PHA
    LDA DIRECTION
    CMP #$80
    BCS VSCROLLTDOWNX
    JMP VSCROLLTDOWN
VSCROLLTDOWNX:

VSCROLLTUP:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDY CONSOLEY1
    BEQ VSCROLLTUPY10
VSCROLLTUPL1:
    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1
    DEY
    BNE VSCROLLTUPL1
VSCROLLTUPY10:
    CLC
    LDA COPYOFTEXTADDRESS
    ADC CONSOLEX1
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

@IF verticalOverlapRequired

    LDA PORT
    BEQ VSCROLLTUPNOW

    LDY #0
VSCROLLTUPYSCRCOPYL1:
    LDA (COPYOFTEXTADDRESS),Y
    STA VSCROLLBUFFERLINE, Y
    INY
    CPY CONSOLEW
    BNE VSCROLLTUPYSCRCOPYL1

VSCROLLTUPNOW:

@ENDIF

    LDX CONSOLEH
    DEX
VSCROLLTUPYSCR0:
    LDY #0
VSCROLLTUPYSCR:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY CONSOLEW
    BEQ VSCROLLTUPYSCR
    BCS VSCROLLTUPYSCR2
    JMP VSCROLLTUPYSCR

VSCROLLTUPYSCR2:
    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA COPYOFTEXTADDRESS2
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS2+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    DEX
    BNE VSCROLLTUPYSCR0

@IF verticalOverlapRequired

    LDA PORT
    BEQ VSCROLLTUPREFILLNOW

VSCROLLTUPREFILLW:
    LDY #0
    LDA #0
VSCROLLTUPREFILLWL1:
    LDA VSCROLLBUFFERLINE, Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY CONSOLEW
    BCS VSCROLLTUEND
    JMP VSCROLLTUPREFILLWL1

VSCROLLTUPREFILLNOW:

@ENDIF

    LDY #0
    LDA #0
VSCROLLTUPREFILL:
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY CONSOLEW
    BCS VSCROLLTUEND
    JMP VSCROLLTUPREFILL
VSCROLLTUEND:

    PLA
    TAY
    PLA
    TAX
    RTS

VSCROLLTDOWN:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDY CONSOLEY2
    BEQ VSCROLLTDOWNY10
VSCROLLTDOWNL1:
    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1
    DEY
    BNE VSCROLLTDOWNL1
VSCROLLTDOWNY10:
    CLC
    LDA COPYOFTEXTADDRESS
    ADC CONSOLEX1
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS2+1
    
@IF verticalOverlapRequired

    LDA PORT
    BEQ VSCROLLTDOWNNOW

    LDY #0
VSCROLLTDOWNYSCRCOPYL1:
    LDA (COPYOFTEXTADDRESS),Y
    STA VSCROLLBUFFERLINE, Y
    INY
    CPY CONSOLEW
    BNE VSCROLLTDOWNYSCRCOPYL1

VSCROLLTDOWNNOW:

@ENDIF

    LDX CONSOLEH
    DEX
VSCROLLTDOWNYS3L1:
    LDY CONSOLEW
VSCROLLTDOWNYS3:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    DEY
    CPY #255
    BNE VSCROLLTDOWNYS3

    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    SEC
    LDA COPYOFTEXTADDRESS2
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS2+1
    SBC #0
    STA COPYOFTEXTADDRESS2+1

    DEX 
    BNE VSCROLLTDOWNYS3L1

@IF verticalOverlapRequired

    LDA PORT
    BEQ VSCROLLTDOWNREFILLNOW

VSCROLLTDOWNREFILLW:
    LDY #0
    LDA #0
VSCROLLTDOWNPREFILLWL1:
    LDA VSCROLLBUFFERLINE, Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY CONSOLEW
    BCS VSCROLLTDOWNDONE
    JMP VSCROLLTDOWNPREFILLWL1

    JMP VSCROLLTDOWNDONE

VSCROLLTDOWNREFILLNOW:

@ENDIF

    LDY CONSOLEW
    DEY
SCROLLFILLUP:
    LDA EMPTYTILE
    STA (COPYOFTEXTADDRESS),Y
    DEY
    CPY #$FF
    BNE SCROLLFILLUP

VSCROLLTDOWNDONE:

    PLA
    TAY
    PLA
    TAX

    RTS
