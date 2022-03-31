; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      JOYSTICK ROUTINE FOR COLECO                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JOYSTICK:
    CALL SCANCODEENTIRE
    LD A, B
    CP 0
    JR Z, JOYSTICK0

JOYSTICK1:
    LD HL, KEYMAP
    ADD HL, 6
    LDA 0
    JMP JOYSTICKC

JOYSTICK0:
    LD HL, KEYMAP
    ADD HL, 9
    LDA 0
    JMP JOYSTICKC

JOYSTICKC:
JOYSTICK1UP:
    LD A, (HL)
    BIT 0, A
    JR NZ, JOYSTICK1DOWN
    LD A, $1
JOYSTICK1DOWN:
    BIT 1, A
    JR NZ, JOYSTICK1LEFT
    OR $2
JOYSTICK1LEFT:
    BIT 2, A
    JR NZ, JOYSTICK1RIGHT
    OR $4
JOYSTICK1RIGHT:
    BIT 3, A
    JR NZ, JOYSTICK1FIRE
    OR $8
JOYSTICK1FIRE:
    BIT 4, A
    JR NZ, JOYSTICK1DONE
    OR $10
JOYSTICK1DONE:
    RET
