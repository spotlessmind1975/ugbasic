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
;*                      CLEAR SCREEN ROUTINE FOR VIC-II                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



CLSG:

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) || ( currentMode == 3 ) )

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

@IF !vestigialConfig.screenModeUnique
    LDA CURRENTMODE
    CMP #3
    BNE CLSGDONE
@ENDIF

@IF !vestigialConfig.screenModeUnique || ( currentMode == 3 ) 

    LDA #$00
    STA COPYOFCOLORMAPADDRESS
    LDA #$D8
    STA COPYOFCOLORMAPADDRESS+1
    LDX #3
    LDY #0
    LDA _PEN
    ASL A
    ASL A
    ASL A
    ASL A
    ORA _PAPER
CLGC3:
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    BNE CLGC3
    INC COPYOFCOLORMAPADDRESS+1
    CPX #1
    BNE CLGCNB3
CLGC23:
    STA (COPYOFCOLORMAPADDRESS),Y
    INY
    CPY #232
    BNE CLGC23
CLGCNB3:
    DEX
    BNE CLGC3

@ENDIF

@ENDIF

CLSGDONE:

    RTS