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
COPYOFTEXTADDRESS = $D9
COPYOFCOLORMAPADDRESS = $DB

HSCROLLST:
    LDA TEXTADDRESS
    STA COPYTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYTEXTADDRESS+1
    LDA COLORMAPADDRESS 
    STA COPYCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYCOLORMAPADDRESS+1
 
    LDX #24

    LDA COPYTEXTADDRESS
    STA $24
    LDA COPYTEXTADDRESS+1
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
    STA (COPYTEXTADDRESS),Y
    INY
    CPY #39
    BNE HSCROLLSTLEFTL1
    LDA #32
    STA (COPYTEXTADDRESS),Y

    CLC
    LDA #40
    ADC COPYTEXTADDRESS
    STA COPYTEXTADDRESS
    LDA #0
    ADC COPYTEXTADDRESS+1
    STA COPYTEXTADDRESS+1

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
    LDA (COPYTEXTADDRESS),Y
    STA ($24),Y
    DEY
    CPY #0
    BNE HSCROLLSTRIGHTL1
    LDA #32
    STA ($24),Y

    CLC
    LDA #40
    ADC COPYTEXTADDRESS
    STA COPYTEXTADDRESS
    LDA #0
    ADC COPYTEXTADDRESS+1
    STA COPYTEXTADDRESS+1

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
    STA COPYTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYTEXTADDRESS+1
    LDA COLORMAPADDRESS 
    STA COPYCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1 
    STA COPYCOLORMAPADDRESS+1
 
    LDX $31
    BEQ HSCROLLLTLS
HSCROLLLTLL1:
    CLC
    LDA #40
    ADC COPYTEXTADDRESS
    STA COPYTEXTADDRESS
    LDA #0
    ADC COPYTEXTADDRESS+1
    STA COPYTEXTADDRESS+1
    DEX
    BNE HSCROLLLTLL1

    LDX $31
HSCROLLLTLC1:
    CLC
    LDA #40
    ADC COPYCOLORMAPADDRESS
    STA COPYCOLORMAPADDRESS
    LDA #0
    ADC COPYCOLORMAPADDRESS+1
    STA COPYCOLORMAPADDRESS+1
    DEX
    BNE HSCROLLLTLC1

HSCROLLLTLS:
    LDA COPYTEXTADDRESS
    STA $24
    LDA COPYTEXTADDRESS+1
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
    STA (COPYTEXTADDRESS),Y
    INY
    CPY #39
    BNE HSCROLLLLEFTL1
    LDA #32
    STA (COPYTEXTADDRESS),Y
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
    LDA (COPYTEXTADDRESS),Y
    STA ($24),Y
    DEY
    CPY #0
    BNE HSCROLLLRIGHTL1
    LDA #32
    STA ($24),Y
    RTS