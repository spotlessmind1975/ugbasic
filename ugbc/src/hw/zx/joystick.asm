
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
;*                            JOYSTICK EMULATION ON ZX                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JOYSTICK:

JOYSTICK0:
    LD C, 0

; #define KEY_W                      11
JOYSTICK0UP:
    LD A, 11
    CALL KEYSTATE
    JR NC, JOYSTICK0DOWN
    LD C, 1

; #define KEY_S                       6
JOYSTICK0DOWN:
    LD A, 6
    CALL KEYSTATE
    JR NC, JOYSTICK0LEFT
    LD A, C
    OR 2
    LD C, A

; #define KEY_A                       5
JOYSTICK0LEFT:
    LD A, 5
    CALL KEYSTATE
    JR NC, JOYSTICK0RIGHT
    LD A, C
    OR 4
    LD C, A

; #define KEY_D                       7
JOYSTICK0RIGHT:
    LD A, 7
    CALL KEYSTATE
    JR NC, JOYSTICK0FIRE
    LD A, C
    OR 8
    LD C, A

; #define KEY_SPACE					35
JOYSTICK0FIRE:
    LD A, 35
    CALL KEYSTATE
    JR NC, JOYSTICK0DONE
    LD A, C
    OR 16
    LD C, A

JOYSTICK0DONE:
    LD A, C
    RET

WAITFIREX:
WAITFIRE:
    LD A, 35
    CALL KEYSTATE
    JR NC, WAITFIRE
    RET
