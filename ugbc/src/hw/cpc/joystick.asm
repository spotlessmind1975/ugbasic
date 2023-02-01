; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      JOYSTICK ROUTINE FOR    CPC                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JOYSTICK:
    LD IXL, $0
    PUSH BC
    CALL SCANCODEENTIRE
    POP BC
    LD A, B
    CP 0
    JR Z, JOYSTICK0

JOYSTICK1:
    LD HL, KEYMAP
    ADD HL, 6
    LD A,0
    JMP JOYSTICKC

JOYSTICK0:
    LD HL, KEYMAP
    ADD HL, 9
    LD A,0
    JMP JOYSTICKC

JOYSTICKC:
JOYSTICK1UP:
    LD A, (HL)
    BIT 0, A
    JR NZ, JOYSTICK1DOWN
    LD IXL, $1
JOYSTICK1DOWN:
    BIT 1, A
    JR NZ, JOYSTICK1LEFT
    PUSH AF
    LD A, IXL
    OR $2
    LD IXL, A
    POP AF
JOYSTICK1LEFT:
    BIT 2, A
    JR NZ, JOYSTICK1RIGHT
    PUSH AF
    LD A, IXL
    OR $4
    LD IXL, A
    POP AF
JOYSTICK1RIGHT:
    BIT 3, A
    JR NZ, JOYSTICK1FIRE
    PUSH AF
    LD A, IXL
    OR $8
    LD IXL, A
    POP AF
JOYSTICK1FIRE:
    BIT 4, A
    JR NZ, JOYSTICK1DONE
    PUSH AF
    LD A, IXL
    OR $10
    LD IXL, A
    POP AF
JOYSTICK1DONE:
    LD A, IXL
    RET
