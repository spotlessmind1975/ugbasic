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

VSCROLLTUP:
    TXA
    PHA
    TYA
    PHA

    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    CLC
    LDA TEXTADDRESS
    ADC #40
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
    CPY #192
    BNE VSCROLLTUPYSCR2
VSCROLLTUPYSCRNXT:
    DEX
    BNE VSCROLLTUPYSCR
    LDY #192
VSCROLLTUPREFILL:
    LDA #32
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY #232
    BNE VSCROLLTUPREFILL
VSCROLLTUEND:

    LDA COLORMAPADDRESS
    STA COPYOFTEXTADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFTEXTADDRESS+1
    CLC
    LDA COLORMAPADDRESS
    ADC #40
    STA COPYOFTEXTADDRESS2
    LDA COLORMAPADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    LDX #3
    LDY #0
VSCROLLTCUPYSCR:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    BNE VSCROLLTCUPYSCR
    INC COPYOFTEXTADDRESS+1
    INC COPYOFTEXTADDRESS2+1
    CPX #1
    BNE VSCROLLTCUPYSCRNXT
VSCROLLTCUPYSCR2:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY #192
    BNE VSCROLLTCUPYSCR2
VSCROLLTCUPYSCRNXT:
    DEX
    BNE VSCROLLTCUPYSCR
    LDY #192
VSCROLLTCUPREFILL:
    LDA #32
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY #232
    BNE VSCROLLTCUPREFILL
VSCROLLTCUEND:

    PLA
    TAY
    PLA
    TAX
    RTS