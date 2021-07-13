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
;*                      CLEAR SCREEN ROUTINE FOR TED                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLS:
    LDA $FF06
    AND #%00100000
    BEQ CLST
    JMP CLSG
    
CLSG:
    LDA BITMAPADDRESS
    STA $25
    LDA BITMAPADDRESS+1
    STA $26
    LDX #31
    LDY #0
    LDA #$0
CLSGY:
    STA ($25),Y
    INY
    BNE CLSGY
    INC $26
    DEX
    BNE CLSGY
    LDX #64
CLSGY2:
    STA ($25),Y
    INY
    DEX
    BNE CLSGY2

    LDA COLORMAPADDRESS
    STA $25
    LDA COLORMAPADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA _PEN
    ASL A
    ASL A
    ASL A
    ASL A
    ORA _PAPER
CLGC:
    STA ($25),Y
    INY
    BNE CLGC
    INC $26
    CPX #1
    BNE CLGCNB
CLGC2:
    STA ($25),Y
    INY
    CPY #232
    BNE CLGC2
CLGCNB:
    DEX
    BNE CLGC

    RTS

CLST:
    LDA TEXTADDRESS
    STA $25
    LDA TEXTADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA EMPTYTILE
CLST2:
    STA ($25),Y
    INY
    BNE CLST2
    INC $26
    CPX #1
    BNE CLSTNB
CLST2X:
    STA ($25),Y
    INY
    CPY #232
    BNE CLST2X
CLSTNB:
    DEX
    BNE CLST2

    LDA COLORMAPADDRESS
    STA $25
    LDA COLORMAPADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA _PEN
CLSTC:
    STA ($25),Y
    INY
    BNE CLSTC
    INC $26
    CPX #1
    BNE CLSTCNB
CLSTC2:
    STA ($25),Y
    INY
    CPY #232
    BNE CLSTC2
CLSTCNB:
    DEX
    BNE CLSTC

    RTS
