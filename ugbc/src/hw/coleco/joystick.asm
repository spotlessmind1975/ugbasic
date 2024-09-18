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
;*                      JOYSTICK ROUTINE FOR COLECO                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IO_Joy1		EQU	0FCH		; Joystick 1 input port
IO_Joy2		EQU	0FFH		; Joystick 2 input port

@IF joystickConfig.values

JOYSTICKTSBREMAP:

    db  $0, $1, $3, $2
    db  $5, $0, $4, $0
    db  $7, $8, $0, $0
    db  $6

JOYSTICKTSB:
    PUSH BC
    PUSH HL
    PUSH DE
    LD B, A
    AND $0F
    LD HL, JOYSTICKTSBREMAP
    LD E, A
    LD D, 0
    ADD HL, DE
    LD A, (HL)
    LD C, A
    LD A, B
    AND $40
    CP 0
    JR Z, JOYSTICKTSBNOFIRE
JOYSTICKXTSBNOFIRE:
    LD A, C
    OR $80
    LD C, A
JOYSTICKTSBNOFIRE:
    LD A, C
    POP DE
    POP HL
    POP BC
    RET    

@ENDIF

JOYSTICKMANAGER:
    PUSH AF
    PUSH BC
    LD A, 0
    OUT	($C0),A
    NOP
    NOP
    NOP
    NOP

    IN	A, ($FC)
    CPL
    AND $7F

@IF joystickConfig.values
    CALL JOYSTICKTSB
@ENDIF

    LD (JOYSTICK0), A

    LD A, 1
    OUT	($C0),A
    NOP
    NOP
    NOP
    NOP

    IN	A, ($FF)
    CPL
    AND $7F

@IF joystickConfig.values
    CALL JOYSTICKTSB
@ENDIF

    LD (JOYSTICK1), A

    POP BC
    POP AF
    RET

WAITFIRE:
    LD A, (JOYSTICK0)
    LD B, A
    LD A, (JOYSTICK1)
    OR B
    CP 0
    JR Z, WAITFIRE
    RET