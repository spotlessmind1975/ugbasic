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
;*                      CLEAR SCREEN ROUTINE FOR VIC-II                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



CLS:
    JSR NSEI
    LDA #$36
    STA $01

    LDA $D011
    AND #$20
    BEQ CLST
    JMP CLSG
    
CLSG:
    LDA BITMAPADDRESS
    STA COPYOFBITMAPADDRESS
    LDA BITMAPADDRESS+1
    STA COPYOFBITMAPADDRESS+1
    LDX #31
    LDY #0
    LDA #$0
CLSGY:
    STA (COPYOFBITMAPADDRESS),Y
    INY
    BNE CLSGY
    INC COPYOFBITMAPADDRESS+1
    DEX
    BNE CLSGY
    LDX #64
CLSGY2:
    STA (COPYOFBITMAPADDRESS),Y
    INY
    DEX
    BNE CLSGY2

    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    LDX #3
    LDY #0
    LDA _PEN
    ASL A
    ASL A
    ASL A
    ASL A
    ORA _PAPER
CLGC:
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    BNE CLGC
    INC COPYOFCOLORMAPADDRESS+1
    CPX #1
    BNE CLGCNB
CLGC2:
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    CPY #232
    BNE CLGC2
CLGCNB:
    DEX
    BNE CLGC

    LDA #$37
    STA $01
    JSR NCLI

    RTS

CLST:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDX #3
    LDY #0
    LDA EMPTYTILE
CLST2:
    STA (COPYOFTEXTADDRESS),Y
    INY
    BNE CLST2
    INC COPYOFTEXTADDRESS+1
    CPX #1
    BNE CLSTNB
CLST2X:
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY #232
    BNE CLST2X
CLSTNB:
    DEX
    BNE CLST2

    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    LDX #3
    LDY #0
    LDA _PEN
CLSTC:
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    BNE CLSTC
    INC COPYOFCOLORMAPADDRESS+1
    CPX #1
    BNE CLSTCNB
CLSTC2:
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    CPY #232
    BNE CLSTC2
CLSTCNB:
    DEX
    BNE CLSTC

    LDA #$37
    STA $01
    JSR NCLI

    RTS
