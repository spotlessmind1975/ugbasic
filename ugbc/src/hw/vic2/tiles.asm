; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                          TILES ROUTINE FOR VIC-II                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TILEX = $92
TILEY = $93
TILET = $94
TILEW = $95
TILEH = $96
TILEX2 = $97
TILEA = $98
TILEW2 = $99
TILEH2 = $9A

; ----------------------------------------------------------------------------
; - Put tile on tilemap
; ----------------------------------------------------------------------------

PUTTILE:
    LDA TILEH2
    BNE PUTTILEEH2
    JMP PUTTILEE
PUTTILEEH2:
    LDA TILEW2
    BNE PUTTILEEW2
    JMP PUTTILEE
PUTTILEEW2:

    LDA _PAPER
    ASL
    ASL
    ASL
    ASL
    ORA _PEN
    STA MATHPTR0
    
    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1

    LDA COLORMAPADDRESS
    STA TMPPTR2
    LDA COLORMAPADDRESS+1
    STA TMPPTR2+1

    LDX TILEX
    CPX CURRENTTILESWIDTH
    BEQ PUTTILEEX
    BCS PUTTILEEX

    LDX TILEY
    BEQ PUTTILEL1

    CPX CURRENTTILESHEIGHT
    BEQ PUTTILEEX
    BCS PUTTILEEX

    JMP PUTTILEL0

PUTTILEEX:
    JMP PUTTILEE

PUTTILEL0:
    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR2
    STA TMPPTR2
    LDA #0
    ADC TMPPTR2+1
    STA TMPPTR2+1

    DEX
    BNE PUTTILEL0

PUTTILEL1:
    CLC
    LDA TILEX
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    CLC
    LDA TILEX
    ADC TMPPTR2
    STA TMPPTR2
    LDA #0
    ADC TMPPTR2+1
    STA TMPPTR2+1

PUTTILEL2A:
    LDA TILEX
    STA TILEX2
    LDX TILEW2
    LDY #0
PUTTILEL2:
    LDA TILET
    STA (TMPPTR),Y
    LDA MATHPTR0
    STA (TMPPTR2),Y
    INC TILET
    INC TILEX2

    LDA TILEX2
    CMP CURRENTTILESWIDTH
    BEQ PUTTILERE
    BCS PUTTILERE

    INY
    DEX
    BNE PUTTILEL2
    JMP PUTTILENL

PUTTILERE:
    INC TILET
    DEX
    BNE PUTTILERE
    DEC TILET

PUTTILENL:

    SEC
    LDA TILEW
    SBC TILEW2
    CLC
    ADC TILET

    LDX TILEH2
    CPX #1
    BEQ PUTTILEE

    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR2
    STA TMPPTR2
    LDA #0
    ADC TMPPTR2+1
    STA TMPPTR2+1

    DEC TILEH2

    INC TILEY
    LDX TILEY
    CPX CURRENTTILESHEIGHT
    BEQ PUTTILEE
    BCS PUTTILEE

    BNE PUTTILEL2A

PUTTILEE:
    RTS

USETILESET:
    RTS

MOVETILE:
    LDA TILET
    STA TMPPTR
    LDA #0
    STA TMPPTR+1

    LDA TILEA
    AND #$80
    CMP #$80
    BNE MOVETILEX

MOVETILEY:
    LDA TILEY
    AND #$07
    ASL
    TAY
    JMP MOVETILEZ

MOVETILEX:
    LDA TILEX
    AND #$07
    ASL
    TAY

MOVETILEZ:
    LDA TMPPTR
    ADC (TMPPTR2), Y
    STA TMPPTR
    INY
    LDA TMPPTR+1
    ADC (TMPPTR2), Y
    STA TMPPTR+1

    LDA TMPPTR
    STA TILET

    LSR TILEX
    LSR TILEX
    LSR TILEX

    LSR TILEY
    LSR TILEY
    LSR TILEY

    JSR PUTTILE

    RTS

TILEAT:
    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1

    LDX TILEX
    CPX CURRENTTILESWIDTH
    BEQ TILEATEE
    BCS TILEATEE

    LDX TILEY
    BEQ TILEATL1

    CPX CURRENTTILESHEIGHT
    BEQ TILEATEE
    BCS TILEATEE

TILEATL0:
    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1
    DEX
    BNE TILEATL0

TILEATL1:
    CLC
    LDA TILEX
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    LDY #0
    LDA (TMPPTR),Y
    STA TILET
    
TILEATEE:
    RTS