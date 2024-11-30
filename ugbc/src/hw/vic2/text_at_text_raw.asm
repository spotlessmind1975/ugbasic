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
;*                      TEXT AT GIVEN POSITION ON VIC-II                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATTILEMODERAW:

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 1 ) )

    LDA TEXTSIZE
    BNE TEXTATRAWTILEMODEGO
    RTS

TEXTATRAWTILEMODEGO:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    SEI

TEXTATRAWPRECHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATRAWPOSTCHKCONSOLE
    BCC TEXTATRAWNEXT2X
    JMP TEXTATRAWNEXT2
TEXTATRAWNEXT2X:
    JMP TEXTATRAWTMPOSTCHKCONSOLE

TEXTATRAWTMPOSTCHKCONSOLE:

    ; LDA #23
    ; STA 53272
    
    LDX YCURSYS
    BEQ TEXTATRAWSKIP
TEXTATRAWLOOP1:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE TEXTATRAWLOOP1

    LDX YCURSYS
TEXTATRAWLOOPC1:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    DEX
    BNE TEXTATRAWLOOPC1

TEXTATRAWSKIP:
    CLC
    LDA XCURSYS
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA XCURSYS
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDX TEXTSIZE
    LDY #$0
TEXTATRAWLOOP2:

    LDA (TEXTPTR),Y

    JSR TEXTATDECODE

    STA (COPYOFTEXTADDRESS),Y
    LDA _PEN
    ; ASL
    ; ASL
    ; ASL
    ; ASL
    ; ORA _PAPER
    STA (COPYOFCOLORMAPADDRESS),Y

TEXTATRAWINCX:
    INC XCURSYS
    DEX
    BNE TEXTATRAWEND2X
    JMP TEXTATRAWEND2
TEXTATRAWEND2X:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATRAWNEXT
    BCS TEXTATRAWNEXT2
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT2:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BEQ TEXTATRAWNEXT
    BCS TEXTATRAWNEXT3
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT3:

    LDA COPYOFTEXTADDRESS
    PHA
    LDA COPYOFTEXTADDRESS+1
    PHA

    JSR VSCROLLTUP

    PLA
    STA COPYOFTEXTADDRESS+1
    PLA
    STA COPYOFTEXTADDRESS

    DEC YCURSYS
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    SEC
    LDA COPYOFCOLORMAPADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    SBC #0
    STA COPYOFCOLORMAPADDRESS+1

TEXTATRAWNEXT:
TEXTATRAWXLOOP2:
    INY
    CPX #0
    BEQ TEXTATRAWEND
    JMP TEXTATRAWLOOP2
TEXTATRAWEND2:
TEXTATRAWEND:
    CLI

@ENDIF

    RTS
