; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
    BCC VSCROLLTDOWN

VSCROLLTUP:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    CLC
    LDA TEXTADDRESS
    ADC CURRENTWIDTH
    STA COPYOFTEXTADDRESS2
    LDA TEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    LDX #3
    LDY #0
VSCROLLTUPYSCR:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    BNE VSCROLLTUPYSCR
    INC COPYOFTEXTADDRESS+1
    INC COPYOFTEXTADDRESS2+1
    CPX #1
    BNE VSCROLLTUPYSCRNXT
VSCROLLTUPYSCR2:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY TEXTBLOCKREMAIN
    BNE VSCROLLTUPYSCR2
VSCROLLTUPYSCRNXT:
    DEX
    BNE VSCROLLTUPYSCR

    LDY TEXTBLOCKREMAIN
VSCROLLTUPREFILL:
    LDA #0
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY TEXTBLOCKREMAINPW
    BNE VSCROLLTUPREFILL
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
    CLC
    LDA TEXTADDRESS
    ADC CURRENTWIDTH
    STA COPYOFTEXTADDRESS2
    LDA TEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1
    
    INC COPYOFTEXTADDRESS+1
    INC COPYOFTEXTADDRESS2+1
    INC COPYOFTEXTADDRESS+1
    INC COPYOFTEXTADDRESS2+1
    INC COPYOFTEXTADDRESS+1
    INC COPYOFTEXTADDRESS2+1
    CLC
    LDA TEXTBLOCKREMAIN
    ADC CURRENTWIDTH 
    ADC CURRENTWIDTH 
    TAY
VSCROLLTDOWNYS3:
    LDA (COPYOFTEXTADDRESS),Y
    STA (COPYOFTEXTADDRESS2),Y
    DEY
    CPY #255
    BNE VSCROLLTDOWNYS3

    DEC COPYOFTEXTADDRESS+1
    DEC COPYOFTEXTADDRESS2+1
    LDX #3
    LDY #255
VSCROLLTDOWNYS4:
    LDA (COPYOFTEXTADDRESS),Y
    STA (COPYOFTEXTADDRESS2),Y
    DEY
    CPY #255
    BNE VSCROLLTDOWNYS4

    DEC COPYOFTEXTADDRESS+1
    DEC COPYOFTEXTADDRESS2+1
    LDY #255
    DEX
    BNE VSCROLLTDOWNYS4

    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDY #0
SCROLLFILLUP:
    LDA EMPTYTILE
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY CURRENTWIDTH
    BNE SCROLLFILLUP

    PLA
    TAY
    PLA
    TAX
    RTS
