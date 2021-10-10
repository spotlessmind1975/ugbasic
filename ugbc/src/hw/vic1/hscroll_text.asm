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
;*                          HIRIZONTAL SCROLL ON VIC-I                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLST:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA COLORMAPADDRESS 
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
 
    LDX #24

    LDA COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS2+1

    CLC
    LDA #1
    ADC COPYOFTEXTADDRESS2
    STA COPYOFTEXTADDRESS2
    LDA #0
    ADC COPYOFTEXTADDRESS2+1
    STA COPYOFTEXTADDRESS2+1

HSCROLLSTL1:
    LDA DIRECTION
    CMP #$80
    BCC HSCROLLSTRIGHT

HSCROLLSTLEFT:
    LDY #0
HSCROLLSTLEFTL1:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY #39
    BNE HSCROLLSTLEFTL1
    LDA #32
    STA (COPYOFTEXTADDRESS),Y

    CLC
    LDA #40
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA #40
    ADC COPYOFTEXTADDRESS2
    STA COPYOFTEXTADDRESS2
    LDA #0
    ADC COPYOFTEXTADDRESS2+1
    STA COPYOFTEXTADDRESS2+1

    DEX
    BNE HSCROLLSTLEFT
    RTS

HSCROLLSTRIGHT:
    LDY #40
HSCROLLSTRIGHTL1:
    LDA (COPYOFTEXTADDRESS),Y
    STA (COPYOFTEXTADDRESS2),Y
    DEY
    CPY #0
    BNE HSCROLLSTRIGHTL1
    LDA #32
    STA (COPYOFTEXTADDRESS2),Y

    CLC
    LDA #40
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA #40
    ADC COPYOFTEXTADDRESS2
    STA COPYOFTEXTADDRESS2
    LDA #0
    ADC COPYOFTEXTADDRESS2+1
    STA COPYOFTEXTADDRESS2+1

    DEX
    BNE HSCROLLSTRIGHT
    RTS

HSCROLLLT:

    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA COLORMAPADDRESS 
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1 
    STA COPYOFCOLORMAPADDRESS+1
 
    LDX CLINEY
    BEQ HSCROLLLTLS
HSCROLLLTLL1:
    CLC
    LDA #40
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE HSCROLLLTLL1

    LDX CLINEY
HSCROLLLTLC1:
    CLC
    LDA #40
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    DEX
    BNE HSCROLLLTLC1

HSCROLLLTLS:
    LDA COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS2+1

    CLC
    LDA #1
    ADC COPYOFTEXTADDRESS2
    STA COPYOFTEXTADDRESS2
    LDA #0
    ADC COPYOFTEXTADDRESS2+1
    STA COPYOFTEXTADDRESS2+1

    LDA DIRECTION
    CMP #$80
    BCC HSCROLLLRIGHT

HSCROLLLLEFT:
    LDY #0
HSCROLLLLEFTL1:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    INY
    CPY #39
    BNE HSCROLLLLEFTL1
    LDA #32
    STA (COPYOFTEXTADDRESS),Y
    RTS

HSCROLLLRIGHT:
    CLC
    LDA #1
    ADC COPYOFTEXTADDRESS2
    STA COPYOFTEXTADDRESS2
    LDA #0
    ADC COPYOFTEXTADDRESS2+1
    STA COPYOFTEXTADDRESS2+1
    LDY #40
HSCROLLLRIGHTL1:
    LDA (COPYOFTEXTADDRESS),Y
    STA (COPYOFTEXTADDRESS2),Y
    DEY
    CPY #0
    BNE HSCROLLLRIGHTL1
    LDA #32
    STA (COPYOFTEXTADDRESS2),Y
    RTS