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
;*                          VERTICAL SCROLL ON VIC-II                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLT:
    TXA
    PHA
    TYA
    PHA
    LDA #$36
    STA $01
    LDA DIRECTION
    CMP #$80
    BCC VSCROLLTDOWN

VSCROLLTUP:
    LDA TEXTADDRESS
    STA $35
    LDA TEXTADDRESS+1
    STA $36
    CLC
    LDA TEXTADDRESS
    ADC #40
    STA $37
    LDA TEXTADDRESS+1
    ADC #0
    STA $38

    LDX #3
    LDY #0
VSCROLLTUPYSCR:
    LDA ($37),Y
    STA ($35),Y
    INY
    BNE VSCROLLTUPYSCR
    INC $36
    INC $38
    CPX #1
    BNE VSCROLLTUPYSCRNXT
VSCROLLTUPYSCR2:
    LDA ($37),Y
    STA ($35),Y
    INY
    CPY #192
    BNE VSCROLLTUPYSCR2
VSCROLLTUPYSCRNXT:
    DEX
    BNE VSCROLLTUPYSCR
    LDY #192
VSCROLLTUPREFILL:
    LDA #32
    STA ($35),Y
    INY
    CPY #232
    BNE VSCROLLTUPREFILL
VSCROLLTUEND:
    LDA #$37
    STA $01

    PLA
    TAY
    PLA
    TAX
    RTS

VSCROLLTDOWN:
    LDA TEXTADDRESS
    STA $35
    LDA TEXTADDRESS+1
    STA $36
    CLC
    LDA TEXTADDRESS
    ADC #40
    STA $37
    LDA TEXTADDRESS+1
    ADC #0
    STA $38
    
    INC $36
    INC $38
    INC $36
    INC $38
    INC $36
    INC $38
    LDY #232
VSCROLLTDOWNYS3:
    LDA ($35),Y
    STA ($37),Y
    DEY
    CPY #255
    BNE VSCROLLTDOWNYS3

    DEC $36
    DEC $38
    LDX #3
    LDY #255
VSCROLLTDOWNYS4:
    LDA ($35),Y
    STA ($37),Y
    DEY
    CPY #255
    BNE VSCROLLTDOWNYS4

    DEC $36
    DEC $38
    LDY #255
    DEX
    BNE VSCROLLTDOWNYS4

    LDA TEXTADDRESS
    STA $35
    LDA TEXTADDRESS+1
    STA $36

    LDY #0
SCROLLFILLUP:
    LDA EMPTYTILE
    STA ($35),Y
    INY
    CPY #40
    BNE SCROLLFILLUP

    LDA #$37
    STA $01

    PLA
    TYA
    PLA
    TXA
    RTS
