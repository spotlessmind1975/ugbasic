; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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

.localchar      '?'

; ******************************************************************************
; COMMON FUNCTIONS
; ******************************************************************************
; Write a char to the text screen.
; Input: A - screencode to print
;        COPYOFTEXTADDRESS - pointer to the interested screen memory
;        Y - offset inside the screen
; Output: -
TEXTATRAWTMWRITECHAR:
    STA (COPYOFTEXTADDRESS),Y
    INC COPYOFTEXTADDRESS
    BNE TEXTATRAWTMWRITECHARL1
    INC COPYOFTEXTADDRESS+1
TEXTATRAWTMWRITECHARL1:
    LDA _PEN
    ; ASL
    ; ASL
    ; ASL
    ; ASL
    ; ORA _PAPER
    STA (COPYOFCOLORMAPADDRESS),Y
    INC COPYOFCOLORMAPADDRESS
    BNE TEXTATRAWTMWRITECHARL2
    INC COPYOFCOLORMAPADDRESS+1
TEXTATRAWTMWRITECHARL2:
    RTS

TEXTATRAWTMCALCPOS:
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
    BEQ TEXTATRAWTMSKIPPREPY
TEXTATRAWTMPREPY:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE TEXTATRAWTMPREPY

    LDX YCURSYS
TEXTATRAWTMPREPYC:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    DEX
    BNE TEXTATRAWTMPREPYC

TEXTATRAWTMSKIPPREPY:
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

TEXTATTILEMODERAW:

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 1 ) )

    LDA TEXTSIZE
    BNE TEXTATRAWTMGO
    RTS

; ******************************************************************************
; PREPARATION
; ******************************************************************************

TEXTATRAWTMGO:
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

@IF printSafe
@IF deployed.timer
    LDA TIMERRUNNING
    BNE ?skipsafe
@ENDIF
    SEI
@IF deployed.timer
?skipsafe:
@ENDIF
@ENDIF

    ; LDA #23
    ; STA 53272
    
; ******************************************************************************
; MAIN LOOP
; ******************************************************************************
    JSR TEXTATRAWTMCALCPOS

    LDX TEXTSIZE
    LDY #$0
    
TEXTATRAWTMPRECHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATRAWTMPOSTCHKCONSOLE
    BCC TEXTATRAWTMINCYX
    JMP TEXTATRAWTMINCY
TEXTATRAWTMINCYX:
    JMP TEXTATRAWTMPOSTCHKCONSOLE

TEXTATRAWTMPOSTCHKCONSOLE:


TEXTATRAWTMLOOP:

    LDA TABSTODRAW
    BEQ TEXTATRAWTMMAIN
    JMP TEXTATRAWTMSKIPTAB

TEXTATRAWTMMAIN:
    JSR TEXTATREADCHAR

TEXTATRAWTMPRINT:
    JSR TEXTATDECODE
    JSR TEXTATRAWTMWRITECHAR
    JMP TEXTATRAWTMINCX

TEXTATRAWTMINCX:
    INC XCURSYS
    CPX #0
    BNE TEXTATRAWTMCHKCONSOLE
    JMP TEXTATRAWTMDONE
TEXTATRAWTMCHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATRAWTMNEXT
    BCS TEXTATRAWTMINCY
    JMP TEXTATRAWTMNEXT
TEXTATRAWTMINCY:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BEQ TEXTATRAWTMNEXTCALCPOS
    BCS TEXTATRAWTMSCROLLY
    JMP TEXTATRAWTMNEXTCALCPOS
TEXTATRAWTMSCROLLY:

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
TEXTATRAWTMNEXTCALCPOS:
    JSR TEXTATRAWTMCALCPOS
TEXTATRAWTMNEXT:
    LDA TABSTODRAW
    BEQ TEXTATRAWTMXLOOP2
    JMP TEXTATRAWTMLOOP
TEXTATRAWTMXLOOP2:
    CPX #0
    BEQ TEXTATRAWTMDONE
    JMP TEXTATRAWTMLOOP
TEXTATRAWTMDONE:

@IF printSafe
@IF deployed.timer
    LDA TIMERRUNNING
    BNE ?skipsafe
@ENDIF
    CLI
@IF deployed.timer
?skipsafe:
@ENDIF
@ENDIF

@ENDIF

    RTS
