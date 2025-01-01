; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
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
;*                          WAIT KEY OR FIRE ON COCO                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; WAITKEYFIRE
; ----------------------------------------------------------------------------
; This routine will wait for a key press. It means that it will, first, wait
; for the passing FREE(0)->PRESSED(1). Since the keyboard could already have
; a key pressed, we must also wait for FREE(0) state, first.

@IF keyboardConfig.sync

WAITKEYFIREA0
    @IF joystickConfig.sync
        JSR JOYSTICKREAD0
    @ELSE
        LDA JOYSTICK0
    @ENDIF
    ANDA #$10
    STA MATHPTR0
    JSR SCANCODE
    LDA KEYPRESS
    ORA MATHPTR0
    BEQ WAITKEYFIREA0
    RTS

WAITKEYFIREA
    CMPA #0
    BEQ WAITKEYFIREA0

WAITKEYFIREB0
    @IF joystickConfig.sync
        JSR JOYSTICKREAD1
    @ELSE
        LDA JOYSTICK1
    @ENDIF
    ANDA #$10
    STA MATHPTR0
    JSR SCANCODE
    LDA KEYPRESS
    ORA MATHPTR0
    BEQ WAITKEYFIREB0
    RTS

WAITKEYFIRE
    @IF joystickConfig.sync
        JSR JOYSTICKREAD0
    @ELSE
        LDA JOYSTICK0
    @ENDIF
    ANDA #$10
    STA MATHPTR0
    @IF joystickConfig.sync
        JSR JOYSTICKREAD1
    @ELSE
        LDA JOYSTICK1
    @ENDIF
    ANDA #$10
    ORA MATHPTR0
    STA MATHPTR0
    JSR SCANCODE
    LDA KEYPRESS
    ORA MATHPTR0
    BEQ WAITKEYFIRE
    RTS

@ELSE

WAITKEYFIREA0
    LDA KEYBOARDASFSTATE
    BEQ WAITKEYFIREA1
WAITKEYFIREA0
    LDA KEYBOARDASFSTATE
    BNE WAITKEYFIREA0
WAITKEYFIREA1
    @IF joystickConfig.sync
        JSR JOYSTICKREAD0
    @ELSE
        LDA JOYSTICK0
    @ENDIF
    ANDA #$10
    STA MATHPTR0
    LDA KEYBOARDASFSTATE
    ORA MATHPTR0
    BEQ WAITKEYFIREA1
    RTS

WAITFIREA
    CMPA #0
    BEQ WAITFIREA0

WAITKEYFIREB0
    LDA KEYBOARDASFSTATE
    BEQ WAITKEYFIREB1
WAITKEYFIREB0
    LDA KEYBOARDASFSTATE
    BNE WAITKEYFIREB0
WAITKEYFIREB1
    @IF joystickConfig.sync
        JSR JOYSTICKREAD1
    @ELSE
        LDA JOYSTICK1
    @ENDIF
    ANDA #$10
    STA MATHPTR0
    LDA KEYBOARDASFSTATE
    ORA MATHPTR0
    BEQ WAITKEYFIREB1
    RTS

WAITKEYFIRE
    LDA KEYBOARDASFSTATE
    BEQ WAITKEYFIRE1
WAITKEYFIRE0
    LDA KEYBOARDASFSTATE
    BNE WAITKEYFIRE0
WAITKEYFIRE1
    @IF joystickConfig.sync
        JSR JOYSTICKREAD0
    @ELSE
        LDA JOYSTICK0
    @ENDIF
    ANDA #$10
    STA MATHPTR0
    @IF joystickConfig.sync
        JSR JOYSTICKREAD1
    @ELSE
        LDA JOYSTICK1
    @ENDIF
    ANDA #$10
    ORA MATHPTR0
    STA MATHPTR0
    LDA KEYBOARDASFSTATE
    ORA MATHPTR0
    BEQ WAITKEYFIRE1
    RTS

@ENDIF
