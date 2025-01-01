; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                       KEYBOARD MANAGEMENT ON C128 (Z80)                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR Z, WAITKEYFIREA1
    WAITKEYFIREA0X:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR NZ, WAITKEYFIREA0X
    WAITKEYFIREA1:
        CALL JOYSTICKREAD0
        AND $10
        LD B, A
        LD A, (KEYBOARDASFSTATE)
        OR B
        CP 0
        JR Z, WAITKEYFIREA1
        RET

    WAITKEYFIREA:
        CP 0
        JR Z, WAITKEYFIREA0
        
    WAITKEYFIREB0:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR Z, WAITKEYFIREB1
    WAITKEYFIREB0X:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR NZ, WAITKEYFIREB0X
    WAITKEYFIREB1:
        CALL JOYSTICKREAD1
        AND $10
        LD B, A
        LD A, (KEYBOARDASFSTATE)
        OR B
        CP 0
        JR Z, WAITKEYFIREB1
        RET

    WAITKEYFIRE:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR Z, WAITKEYFIRE1
    WAITKEYFIRE0:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR NZ, WAITKEYFIRE0
    WAITKEYFIRE1:
        CALL JOYSTICKREAD0
        AND $10
        LD B, A
        CALL JOYSTICKREAD1
        AND $10
        OR B
        LD B, A
        LD A, (KEYBOARDASFSTATE)
        OR B
        CP 0
        JR Z, WAITKEYFIRE1
        RET

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
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR Z, WAITKEYFIREA1
    WAITKEYFIREA0X:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR NZ, WAITKEYFIREA0X
    WAITKEYFIREA1:
        LD A, (JOYSTICK0)
        AND $10
        LD B, A
        LD A, (KEYBOARDASFSTATE)
        OR B
        CP 0
        JR Z, WAITKEYFIREA1
        RET

    WAITKEYFIREA:
        CP 0
        JR Z, WAITKEYFIREA0
        
    WAITKEYFIREB0:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR Z, WAITKEYFIREB1
    WAITKEYFIREB0X:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR NZ, WAITKEYFIREB0X
    WAITKEYFIREB1:
        LD A, (JOYSTICK1)
        AND $10
        LD B, A
        LD A, (KEYBOARDASFSTATE)
        OR B
        CP 0
        JR Z, WAITKEYFIREB1
        RET

    WAITKEYFIRE:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR Z, WAITKEYFIRE1
    WAITKEYFIRE0:
        LD A, (KEYBOARDASFSTATE)
        CP 0
        JR NZ, WAITKEYFIRE0
    WAITKEYFIRE1:
        LD A, (JOYSTICK0)
        AND $10
        LD B, A
        LD A, (JOYSTICK1)
        AND $10
        OR B
        LD B, A
        LD A, (KEYBOARDASFSTATE)
        OR B
        CP 0
        JR Z, WAITKEYFIRE1
        RET

@ENDIF

