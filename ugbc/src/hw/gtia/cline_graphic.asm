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
;*                      CLEAR LINE ROUTINE FOR GTIA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINEG:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE CLINEG8X
    JMP CLINEG8
CLINEG8X:
    CMP #9
    BNE CLINEG9X
    JMP CLINEG9
CLINEG9X:
    CMP #10
    BNE CLINEG10X
    JMP CLINEG10
CLINEG10X:
    CMP #11
    BNE CLINEG11X
    JMP CLINEG11
CLINEG11X:
    CMP #12
    BNE CLINEG12X
    JMP CLINEG12
CLINEG12X:
    CMP #13
    BNE CLINEG13X
    JMP CLINEG13
CLINEG13X:
    CMP #14
    BNE CLINEG14X
    JMP CLINEG14
CLINEG14X:
    CMP #15
    BNE CLINEG15X
    JMP CLINEG15
CLINEG15X:
    RTS
@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

CLINEG8:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS8

    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

CLINEG9:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS9

    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

CLINEG10:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS10

    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

CLINEG11:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS11

    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

CLINEG12:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS12
    
    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

CLINEG13:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS13

    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

CLINEG14:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS14

    JMP CLINEGCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

CLINEG15:

    LDA CLINEX
    STA MATHPTR6
    LDA CLINEY
    STA MATHPTR7
    JSR CALCPOS15

    JMP CLINEGCOMMON

@ENDIF

CLINEGCOMMON:

    LDX CHARACTERS
    LDY #$0
CLINEGLOOP2:

CLINEGSP0:

    LDY #0
    LDA PLOTDEST
    STA TMPPTR2
    LDA PLOTDEST+1
    STA TMPPTR2+1
CLINEGSP0L1:
    LDA CURRENTMODE
    CMP #10
    BEQ CLINEGSP0L1M
    ; CMP #11
    ; BEQ CLINEGSP0L1M
    CMP #13
    BEQ CLINEGSP0L1M

    LDA #0
    STA (TMPPTR2),Y
    JMP CLINEGSP0L1M2

CLINEGSP0L1M:

    LDA #0
    STA (TMPPTR2),Y

    CLC
    LDA TMPPTR2
    ADC #1
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    LDA #0
    STA (TMPPTR2),Y

    JMP CLINEGSP0L1M2

CLINEGSP0L1M2:
    
    CLC
    LDA TMPPTR2
    ADC CURRENTSL
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1
    
    SEC
    LDA TMPPTR2
    SBC PATTERN
    STA TMPPTR2
    LDA TMPPTR2+1
    SBC #0
    STA TMPPTR2+1

    INY
    CPY #8
    BEQ CLINEGSP0L1X
    JMP CLINEGSP0L1

CLINEGSP0L1X:
    CLC
    LDA PLOTDEST
    ADC PATTERN
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    JMP CLINEGINCX

CLINEGINCX:
    INC CLINEX
    LDA CLINEX
    CMP CONSOLEX2
    BCS CLINEGNEXT2
    JMP CLINEGNEXT
CLINEGNEXT2:
    RTS
CLINEGNEXT:
    INY
    DEX
    BEQ CLINEGEND
    JMP CLINEGLOOP2
CLINEGEND:
    RTS
