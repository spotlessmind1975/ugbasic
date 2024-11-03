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
; ******************************************************************************
; COMMON FUNCTIONS
; ******************************************************************************
; Write a char to the text screen.
; Input: A - screencode to print
;        COPYOFTEXTADDRESS - pointer to the interested screen memory
;        Y - offset inside the screen
; Output: -
TEXTATTMWRITECHAR:
    STA (COPYOFTEXTADDRESS),Y
    INC COPYOFTEXTADDRESS
    BNE TEXTATTMWRITECHARL1
    INC COPYOFTEXTADDRESS+1
TEXTATTMWRITECHARL1:
    LDA _PEN
    ; ASL
    ; ASL
    ; ASL
    ; ASL
    ; ORA _PAPER
    STA (COPYOFCOLORMAPADDRESS),Y
    INC COPYOFCOLORMAPADDRESS
    BNE TEXTATTMWRITECHARL2
    INC COPYOFCOLORMAPADDRESS+1
TEXTATTMWRITECHARL2:
    RTS

TEXTATTMCALCPOS:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    TXA
    PHA
    LDX YCURSYS
    BEQ TEXTATTMSKIPPREPY
TEXTATTMPREPY:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE TEXTATTMPREPY

    LDX YCURSYS
TEXTATTMPREPYC:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    DEX
    BNE TEXTATTMPREPYC

TEXTATTMSKIPPREPY:
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

    PLA
    TAX
    RTS

; ******************************************************************************
; ENTRY POINT
; ******************************************************************************

TEXTATTILEMODE:

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 1 ) )

    LDA TEXTSIZE
    BNE TEXTATTMGO
    RTS

; ******************************************************************************
; PREPARATION
; ******************************************************************************

TEXTATTMGO:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA #0
    STA TABSTODRAW
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    SEI

    ; LDA #23
    ; STA 53272
    
; ******************************************************************************
; MAIN LOOP
; ******************************************************************************

    JSR TEXTATTMCALCPOS

    LDX TEXTSIZE
    LDY #$0
TEXTATTMLOOP:

    LDA TABSTODRAW
    BEQ TEXTATTMMAIN
    JMP TEXTATTMSKIPTAB

TEXTATTMMAIN:
    JSR TEXTATREADCHAR

    CMP #31
    BCS TEXTATTMPRINT
    JMP TEXTATTMPARSE

TEXTATTMPRINT:
    JSR TEXTATDECODE
    JSR TEXTATTMWRITECHAR
    JMP TEXTATTMINCX

TEXTATTMPARSETAB:
    JSR TEXTATTAB
    JMP TEXTATTMNEXT

TEXTATTMPARSE:
    CMP #13
    BEQ TEXTATTMPARSELF
    CMP #10
    BEQ TEXTATTMPARSELF
    CMP #09
    BEQ TEXTATTMPARSETAB
    CMP #01
    BEQ TEXTATTMPARSEPEN
    CMP #02
    BEQ TEXTATTMPARSEPAPER
    CMP #03
    BEQ TEXTATTMPARSECMOVE
    CMP #04
    BEQ TEXTATTMPARSEAT
    CMP #05
    BEQ TEXTATTMPARSECLS
    JMP TEXTATTMNEXT

TEXTATTMPARSECLS:
    TYA
    PHA
    TXA
    PHA
    JSR CLST
    PLA
    TAX
    PLA
    TAY
    JMP TEXTATTMNEXT

TEXTATTMPARSELF:
    JMP TEXTATTMINCY

TEXTATTMPARSEAT:
    JMP TEXTATTMAT

TEXTATTMPARSEPEN:
    JSR TEXTATREADCHAR
    CMP #$FF
    BNE TEXTATTMPARSEPEN2
    LDA #$0
TEXTATTMPARSEPEN2:    
    STA _PEN
    JMP TEXTATTMNEXT

TEXTATTMPARSEPAPER:
    JSR TEXTATREADCHAR
    STA $d021
    STA $d020
    JMP TEXTATTMNEXT

TEXTATTMPARSECMOVE:
    JSR TEXTATREADCHAR
    STA CLINEX
    JSR TEXTATREADCHAR
    STA CLINEY

TEXTATTMCMOVE:
    CLC
    LDA CLINEX
    ADC XCURSYS
    CMP CONSOLEX1
    BCC TEXTATTMCMOVESKIPX
    CMP CONSOLEX2
    BCS TEXTATTMCMOVESKIPX
    STA XCURSYS

TEXTATTMCMOVESKIPX:
    CLC
    LDA CLINEY
    ADC YCURSYS
    CMP CONSOLEY1
    BCS TEXTATTMCMOVESKIPY
    CMP CONSOLEY2
    BCS TEXTATTMCMOVESKIPY
    STA YCURSYS

TEXTATTMCMOVESKIPY:
    JSR TEXTATTMCALCPOS
    JMP TEXTATTMNEXT

TEXTATTMAT:
    JSR TEXTATREADCHAR
    SEC
    SBC XCURSYS
    ADC CONSOLEX1
    STA CLINEX
    JSR TEXTATREADCHAR
    SEC
    SBC YCURSYS
    ADC CONSOLEY1
    STA CLINEY
    JMP TEXTATTMCMOVE

TEXTATTMSKIPTAB:
    DEC TABSTODRAW
    INC XCURSYS
    JMP TEXTATTMCHKCONSOLE

TEXTATTMINCX:
    INC XCURSYS
    CPX #0
    BNE TEXTATTMCHKCONSOLE
    JMP TEXTATTMDONE
TEXTATTMCHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATTMNEXT
    BCS TEXTATTMINCY
    JMP TEXTATTMNEXT
TEXTATTMINCY:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BEQ TEXTATTMNEXTCALCPOS
    BCS TEXTATTMSCROLLY
    JMP TEXTATTMNEXTCALCPOS
TEXTATTMSCROLLY:

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
TEXTATTMNEXTCALCPOS:
    JSR TEXTATTMCALCPOS
TEXTATTMNEXT:
    LDA TABSTODRAW
    BEQ TEXTATTMXLOOP2
    JMP TEXTATTMLOOP
TEXTATTMXLOOP2:
    CPX #0
    BEQ TEXTATTMDONE
    JMP TEXTATTMLOOP
TEXTATTMDONE:
    CLI

@ENDIF

    RTS
