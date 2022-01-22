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
;*                          TILES ROUTINE FOR GTIA                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TILEX = $92
TILEY = $93
TILET = $94
TILEW = $95
TILEH = $96

; ----------------------------------------------------------------------------
; - Put tile on tilemap
; ----------------------------------------------------------------------------

PUTTILE:
    LDA TEXTADDRESS
    STA TMPPTR
    LDA TEXTADDRESS+1
    STA TMPPTR+1
    
    LDX TILEY
    BEQ PUTTILEL1

PUTTILEL0:
    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR
    STA TMPPTR
    DEX
    BNE PUTTILEL0

PUTTILEL1:
    CLC
    LDA TILEX
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR
    STA TMPPTR

PUTTILEL2A:
    LDX TILEW
    LDY #0
PUTTILEL2:
    LDA TILET
    STA (TMPPTR),Y
    INC TILET
    INY
    DEX
    BNE PUTTILEL2

    LDX TILEH
    CPX #1
    BEQ PUTTILEE

    CLC
    LDA CURRENTTILESWIDTH
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR
    STA TMPPTR

    DEC TILEH
    BNE PUTTILEL2A

PUTTILEE:
    RTS
