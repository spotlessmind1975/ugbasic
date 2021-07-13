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
;*                          HIRIZONTAL SCROLL ON TED                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLST:
    LDA TEXTADDRESS
    STA $22
    LDA TEXTADDRESS+1
    STA $23
    LDA COLORMAPADDRESS 
    STA $29
    LDA COLORMAPADDRESS+1
    STA $2a
 
    LDX #24

    LDA $22
    STA $24
    LDA $23
    STA $25

    CLC
    LDA #1
    ADC $24
    STA $24
    LDA #0
    ADC $25
    STA $25

HSCROLLSTL1:
    LDA $26
    CMP #$80
    BCC HSCROLLSTRIGHT

HSCROLLSTLEFT:
    LDY #0
HSCROLLSTLEFTL1:
    LDA ($24),Y
    STA ($22),Y
    INY
    CPY #39
    BNE HSCROLLSTLEFTL1
    LDA #32
    STA ($22),Y

    CLC
    LDA #40
    ADC $22
    STA $22
    LDA #0
    ADC $23
    STA $23

    CLC
    LDA #40
    ADC $24
    STA $24
    LDA #0
    ADC $25
    STA $25

    DEX
    BNE HSCROLLSTLEFT
    RTS

HSCROLLSTRIGHT:
    LDY #40
HSCROLLSTRIGHTL1:
    LDA ($22),Y
    STA ($24),Y
    DEY
    CPY #0
    BNE HSCROLLSTRIGHTL1
    LDA #32
    STA ($24),Y

    CLC
    LDA #40
    ADC $22
    STA $22
    LDA #0
    ADC $23
    STA $23

    CLC
    LDA #40
    ADC $24
    STA $24
    LDA #0
    ADC $25
    STA $25

    DEX
    BNE HSCROLLSTRIGHT
    RTS

HSCROLLLT:

    LDA TEXTADDRESS
    STA $22
    LDA TEXTADDRESS+1
    STA $23
    LDA COLORMAPADDRESS 
    STA $29
    LDA COLORMAPADDRESS+1 
    STA $2a
 
    LDX $31
    BEQ HSCROLLLTLS
HSCROLLLTLL1:
    CLC
    LDA #40
    ADC $22
    STA $22
    LDA #0
    ADC $23
    STA $23
    DEX
    BNE HSCROLLLTLL1

    LDX $31
HSCROLLLTLC1:
    CLC
    LDA #40
    ADC $29
    STA $29
    LDA #0
    ADC $2a
    STA $2a
    DEX
    BNE HSCROLLLTLC1

HSCROLLLTLS:
    LDA $22
    STA $24
    LDA $23
    STA $25

    CLC
    LDA #1
    ADC $24
    STA $24
    LDA #0
    ADC $25
    STA $25

    LDA $26
    CMP #$80
    BCC HSCROLLLRIGHT

HSCROLLLLEFT:
    LDY #0
HSCROLLLLEFTL1:
    LDA ($24),Y
    STA ($22),Y
    INY
    CPY #39
    BNE HSCROLLLLEFTL1
    LDA #32
    STA ($22),Y
    RTS

HSCROLLLRIGHT:
    CLC
    LDA #1
    ADC $24
    STA $24
    LDA #0
    ADC $25
    STA $25
    LDY #40
HSCROLLLRIGHTL1:
    LDA ($22),Y
    STA ($24),Y
    DEY
    CPY #0
    BNE HSCROLLLRIGHTL1
    LDA #32
    STA ($24),Y
    RTS