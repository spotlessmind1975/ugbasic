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
;*                          VERTICAL SCROLL ON VIC-I                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLTUP:

    TXA
    PHA
    TYA
    PHA

    LDA CONSOLESA
    STA COPYOFTEXTADDRESS
    LDA CONSOLESA+1
    STA COPYOFTEXTADDRESS+1
    CLC
    LDA CONSOLESA
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA CONSOLESA+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    LDX CONSOLEH
    DEX
    BEQ VSCROLLTUPYSCRNO
VSCROLLTUPYSCRRPT:    
    LDY CONSOLEW
    DEY
VSCROLLTUPYSCR:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    DEY
    CPY #$FF
    BNE VSCROLLTUPYSCR

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
    BNE VSCROLLTUPYSCRRPT

VSCROLLTUPYSCRNO:
    LDY CONSOLEW
    DEY
VSCROLLTUPREFILL:
    LDA EMPTYTILE
    STA (COPYOFTEXTADDRESS),Y
    DEY
    CPY #$FF
    BNE VSCROLLTUPREFILL

VSCROLLTUEND:

    LDA CONSOLECA
    STA COPYOFTEXTADDRESS
    LDA CONSOLECA+1
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA CONSOLECA
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA CONSOLECA+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    LDX CONSOLEH
    DEX
    BEQ VSCROLLTUPCYSCRNO
VSCROLLTUPCYSCRRPT:    
    LDY CONSOLEW
    DEY
VSCROLLTUPCYSCR:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    DEY
    CPY #$FF
    BNE VSCROLLTUPCYSCR

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
    BNE VSCROLLTUPCYSCRRPT

VSCROLLTUPCYSCRNO:
    LDY CONSOLEW
    DEY
    LDA _PEN
    ; ORA _PAPER
VSCROLLTUPREFILLC:
    STA (COPYOFTEXTADDRESS),Y
    DEY
    CPY #$FF
    BNE VSCROLLTUPREFILLC

VSCROLLTCUEND:

    PLA
    TAY
    PLA
    TAX

    RTS