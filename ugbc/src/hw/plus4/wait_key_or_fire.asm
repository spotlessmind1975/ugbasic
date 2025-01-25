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
;*                            WAIT KEY OR FIRE ON PLUS/4                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; WAITKEYFIRE
; ----------------------------------------------------------------------------
; This routine will wait for a key press OR a fire press. 

@IF joystickConfig.sync

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;- SYNCHRONIZED JOYSTICK READING
;-
;- This is the actual implementation that will be used, where the programmer 
;- chooses to read the joystick position at the specific moment the JOY or 
;- similar instruction is executed.
;-
;- To enable: DEFINE JOYSTICK SYNC
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    WAITKEYFIREA0:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIREA1
    WAITKEYFIREA0X:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIREA0X
    WAITKEYFIREA1:        
        JSR JOYSTICKREAD0
        AND #$40
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        LDA MATHPTR0
        BEQ WAITKEYFIREA1
        RTS

    WAITKEYFIREA:
        CMP #0
        BEQ WAITKEYFIREA0

    WAITKEYFIREB0:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIREB1
    WAITKEYFIREB0X:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIREB0X
    WAITKEYFIREB1:
        JSR JOYSTICKREAD1
        AND #$10
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        LDA MATHPTR0
        BEQ WAITKEYFIREB1
        RTS

    WAITKEYFIRE:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIRE1
    WAITKEYFIRE0:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIRE0
    WAITKEYFIRE1:        
        JSR JOYSTICKREAD0
        AND #$40
        STA MATHPTR0
        JSR JOYSTICKREAD1
        AND #$40
        ORA MATHPTR0
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        LDA MATHPTR0
        BEQ WAITKEYFIRE1
        RTS

@ELSE

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;- ASYNCRONOUS JOYSTICK READING (default)
;-
;- This is the implementation used where the programmer chooses to use 
;- interrupts to read the joystick position.
;-
;- To enable: DEFINE JOYSTICK ASYNC
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    WAITKEYFIREA0:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIREA1
    WAITKEYFIREA0X:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIREA0X
    WAITKEYFIREA1:
        LDA JOYSTICK0
        AND #$40
        ORA MATHPTR0
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        BEQ WAITKEYFIREA1
        RTS

    WAITKEYFIREA:
        CMP #0
        BEQ WAITKEYFIREA0

    WAITKEYFIREB0:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIREB1
    WAITKEYFIREB0X:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIREB0X
    WAITKEYFIREB1:
        LDA JOYSTICK1
        AND #$40
        ORA MATHPTR0
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        BEQ WAITKEYFIREA1
        RTS

    WAITKEYFIRE:
        LDA KEYBOARDASFSTATE
        BEQ WAITKEYFIRE1
    WAITKEYFIRE0:
        LDA KEYBOARDASFSTATE
        BNE WAITKEYFIRE0
    WAITKEYFIRE1:
        LDA JOYSTICK0
        AND #$40
        STA MATHPTR0
        LDA JOYSTICK1
        AND #$40
        ORA MATHPTR0
        STA MATHPTR0
        LDA KEYBOARDASFSTATE
        ORA MATHPTR0
        BEQ WAITKEYFIRE1
        RTS

@ENDIF
