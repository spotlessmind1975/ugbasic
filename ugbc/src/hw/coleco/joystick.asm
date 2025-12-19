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
;*                      JOYSTICK ROUTINE FOR COLECO                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IO_Joy1		EQU	0FCH		; Joystick 1 input port
IO_Joy2		EQU	0FFH		; Joystick 2 input port

@IF joystickConfig.values

    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
    ;-
    ;- Change the reading values based on its convention.
    ;-
    ;- To enable: DEFINE JOYSTICK VALUES TSB
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
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

JOYSTICKREAD0:
    OUT	($C0),A
    NOP
    NOP
    NOP
    NOP
    IN	A, ($FC)
    CPL
    AND $7F
    RET

JOYSTICKREAD1:
    OUT	($C0),A
    NOP
    NOP
    NOP
    NOP
    IN	A, ($FF)
    CPL
    AND $7F
    RET

JOYSTICKREAD:
    CP 0
    JR Z, JOYSTICKREAD0
    JR JOYSTICKREAD1

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

    ; Read the FIRE button's latch for a specific joystick
    ;
    ;   A = joystick button id
    ;   A = $00 FIRE was not pressed
    ;       $ff FIRE was pressed
    ;
    STRIG:

        ; Is the button odd? So we can read directly
        ; the fire button.

        SRL A
        JR C, JFIRE

        ; Load the latch value.

        LD E, A
        LD D, 0
        LD HL, JFIRELATCH
        ADD HL, DE
        LD A, (HL)

        ; Check if latch is not zero.
        
        CP 0
        JR Z, STRIGNONE

        ; Reset the latch.

        LD B, A
        LD A, 0
        LD (HL), A

        ; TRUE, the joystick fire was pressed in the past.

        LD A, $FF

    STRIGNONE:
        RET

    ; Read the FIRE button for a specific joystick
    ;
    ;   A = joystick number
    ;   A = $00 FIRE was not pressed
    ;       $01 FIRE was pressed
    ;
    JFIREX:

        PUSH AF
        LD E, A
        LD D, 0
        LD HL, JFIRELATCH
        ADD HL, DE
        POP AF
        
        ; Load the STRIG register from the hardware port.

        CALL JOYSTICKREAD

        ; Isolate the FIRE bit.

        AND $40

        ; Update the FIRE latch.

        PUSH AF
        OR (HL)
        LD (HL), A
        POP AF

        ; Done.

        RET

    ; Read the FIRE button for a specific joystick
    ;
    ;   A = joystick number
    ;   A = $00 FIRE was not pressed
    ;       $FF FIRE was pressed
    ;
    JFIRE:
        CALL JFIREX
        CP 0
        JR Z, JFIRENONE
        LD A, $FF
    JFIRENONE:
        RET

    WAITFIRE0:
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE0
        RET

    WAITFIREA:
        CP 0
        JR Z, WAITFIRE0

    WAITFIRE1:
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE1
        RET

    WAITFIRE:
        LD A, 0
        CALL JFIRE
        LD B, A
        LD A, 1
        CALL JFIRE
        OR B
        CP 0
        JR Z, WAITFIRE
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

    ; Read the FIRE button's latch for a specific joystick
    ;
    ;   A = joystick button id
    ;   A = $00 FIRE was not pressed
    ;       $ff FIRE was pressed
    ;
    STRIG:
    
        ; Is the button odd? So we can read directly
        ; the fire button.

        SRL A
        JR C, JFIRE

        ; Load the latch value.

        LD E, A
        LD D, 0
        LD HL, JFIRELATCH
        ADD HL, DE
        LD A, (HL)

        ; Check if latch is not zero.
        
        CP 0
        JR Z, STRIGNONE

        ; Reset the latch.

        LD B, A
        LD A, 0
        LD (HL), A

        ; TRUE, the joystick fire was pressed in the past.

        LD A, $FF

    STRIGNONE:
        RET

    ; Read the FIRE button for a specific joystick
    ;
    ;   A = joystick number
    ;   A = $00 FIRE was not pressed
    ;       $01 FIRE was pressed
    ;
    JFIREX:

        LD B, A

        PUSH AF
        LD E, A
        LD D, 0
        LD HL, JOYSTICK0
        ADD HL, DE
        LD A, (HL)
        LD DE, HL
        POP AF
        
        ; Load the STRIG register from the hardware port.

        LD A, (DE)

        ; Isolate the FIRE bit.

        AND $40

        ; Update the FIRE latch.

        PUSH AF
        PUSH AF
        LD A, B
        LD E, A
        LD D, 0
        LD HL, JFIRELATCH
        ADD HL, DE
        POP AF
        OR (HL)
        LD (HL), A
        POP AF

        ; Done.

        RET

        ; Read the FIRE button for a specific joystick
        ;
        ;   A = joystick number
        ;   A = $00 FIRE was not pressed
        ;       $FF FIRE was pressed
        ;
        JFIRE:
            CALL JFIREX
            CP 0
            JR Z, JFIRENONE
            LD A, $FF
        JFIRENONE:
            RET

    ; IRQ service routine

    JOYSTICKMANAGER:

        ; Save registers

        PUSH AF
        PUSH BC

        ; Read JOY(0)

        CALL JOYSTICKREAD0

        ; Store it on dedicated storage

        LD (JOYSTICK0), A

        ; Read JOY(1)

        CALL JOYSTICKREAD1

        ; Store it on dedicated storage

        LD (JOYSTICK1), A

        ; Restore registers

        POP BC
        POP AF
        RET

    WAITFIRE0:
        LD A, 0
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE0
        RET

    WAITFIREA:
        CP $0
        JR Z, WAITFIRE0

    WAITFIRE1:
        LD A, 0
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE1
        RET

    WAITFIRE:
        LD A, 0
        CALL JFIRE
        LD B, A
        LD A, 1
        CALL JFIRE
        OR B
        CP 0
        JR Z, WAITFIRE
        RET

@ENDIF
