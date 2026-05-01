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
;*                       JOYSTICK DETECTION ON C128 (Z80)                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF joystickConfig.values

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
;-
;- Change the reading values based on its convention.
;-
;- To enable: DEFINE JOYSTICK VALUES TSB
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ; This is the four bit map used to "map" each read value with the TSB.
    JOYSTICKTSBREMAP:
        DB   $0, $1, $5, $0
        DB   $7, $8, $6, $0
        DB   $3, $2, $4, $0
        DB   $0, $0, $0, $0

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
        AND $10
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

; Read the position and button for first joystick (JOY(0))
JOYSTICKREAD0:
    PUSH BC
    LD A, $7F
    ; STA $DC00
    LD BC, $DC00
    OUT (C), A
    ; LDA $DC01
    LD BC, $DC01
    IN A, (C)
    AND $1F
    XOR $1F
    POP BC

    CP 0
    JR Z, JOYSTICKREAD0DONE

    NOP
    NOP
    NOP

JOYSTICKREAD0DONE:
    RET

; Read the position and button for second joystick (JOY(1))
JOYSTICKREAD1:
    PUSH BC
    LD A, $E0
    ; LDY #$FF
    ; STA $DC02
    LD BC, $DC02
    OUT (C), A
    ; LDA $DC00
    LD BC, $DC00
    IN A, (C)
    ; STY $DC02
    PUSH AF
    LD A, $FF
    LD BC, $DC02
    OUT (C), A
    POP AF
    AND $1F
    XOR $1F
    POP BC
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

        AND $10

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

    ; Wait for any fire is pressed on JOY(0)

    WAITFIRE0:
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE0
        RET

    WAITFIREA:
        CP 0
        JR Z, WAITFIRE0

    ; Wait for any fire is pressed on JOY(1)

    WAITFIRE1:
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE1
        RET

    ; Wait for any fire is pressed, for any joystick.

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

        AND $10

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


    ; Dedicated storage space for JOY(0) and JOY(1)

    JOYSTICK0:      DB   $0
    JOYSTICK1:      DB   $0

    ; IRQ service for joystick

    JOYSTICKMANAGER:

        ; Save registers on stack, just in case.

        PUSH AF
        PUSH BC

        ; Read JOY(0)

        CALL JOYSTICKREAD0

        ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
        ;-
        ;- Change the reading values based on its convention.
        ;-
        ;- To enable: DEFINE JOYSTICK VALUES TSB
        ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        @IF joystickConfig.values
            CALL JOYSTICKTSB
        @ENDIF

        ; Store the value into the dedicated storage.

        LD (JOYSTICK0), A

        ; Read JOY(1)

        CALL JOYSTICKREAD1

        ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
        ;-
        ;- Change the reading values based on its convention.
        ;-
        ;- To enable: DEFINE JOYSTICK VALUES TSB
        ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        @IF joystickConfig.values
            CALL JOYSTICKTSB
        @ENDIF

        ; Store value into the dedicated storage.
        
        LD (JOYSTICK1), A

        ; Restore registers on stack, just in case.

        POP BC
        POP AF

        RET

    ; Wait for any fire is pressed on JOY(0)

    WAITFIRE0:
        LD A, 0
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE0
        RET

    WAITFIREA:
        CP 0
        JR Z, WAITFIRE0
        JR WAITFIRE1

    ; Wait for any fire is pressed on JOY(1)

    WAITFIRE1:
        LD A, 1
        CALL JFIRE
        CP 0
        JR Z, WAITFIRE1
        RET

    ; Wait for any fire is pressed, for any joystick.
    
    WAITFIRE:

        ; Read dedicated storage for JOY(0)

        LD A, 0
        CALL JFIRE
        LD B, A

        ; Read dedicated storage for JOY(1)

        LD A, 1
        CALL JFIRE
        OR B

        ; If both are zero, recheck again.
        CP 0
        JR Z, WAITFIRE

        RET

@ENDIF
