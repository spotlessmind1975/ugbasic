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
;*                          VERTICAL SCROLL ON VIC-1                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 1 ) || ( currentMode == 4 ) )

VSCROLLTUP:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDX CONSOLEY1
    BEQ VSCROLLTUPL1B
VSCROLLTUPL1X:
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDA CURRENTTILESWIDTH
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    DEX
    BNE VSCROLLTUPL1X
VSCROLLTUPL1B:
    LDA CONSOLEX1
    BEQ VSCROLLTUPL1C

    CLC
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA CONSOLEX1
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

VSCROLLTUPL1C:

    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    CLC
    LDA COPYOFCOLORMAPADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS2
    LDA COPYOFCOLORMAPADDRESS+1
    ADC #0
    STA COPYOFCOLORMAPADDRESS2+1

    LDX CONSOLEH
VSCROLLTUPYSCR0:
    LDY #0
VSCROLLTUPYSCR:
    LDA (COPYOFTEXTADDRESS2),Y
    STA (COPYOFTEXTADDRESS),Y
    LDA (COPYOFCOLORMAPADDRESS2),Y
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    CPY CONSOLEW
    BNE VSCROLLTUPYSCR

    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA COPYOFCOLORMAPADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    ADC #0
    STA COPYOFCOLORMAPADDRESS+1

    CLC
    LDA COPYOFTEXTADDRESS2
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS2
    LDA COPYOFTEXTADDRESS2+1
    ADC #0
    STA COPYOFTEXTADDRESS2+1

    CLC
    LDA COPYOFCOLORMAPADDRESS2
    ADC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS2
    LDA COPYOFCOLORMAPADDRESS2+1
    ADC #0
    STA COPYOFCOLORMAPADDRESS2+1

    DEX
    BNE VSCROLLTUPYSCR0

    LDY #0
VSCROLLTUPYSCR2:
    LDA EMPTYTILE
    STA (COPYOFTEXTADDRESS),Y
    LDA #0
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    CPY CONSOLEW
    BNE VSCROLLTUPYSCR2

    RTS

@ENDIF
