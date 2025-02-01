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
;*                          KEYBOARD MANAGEMENT ON ZX                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

KEYBOARDPORTS:
    DB $FE, $FD, $FB, $F7, $EF, $DF, $BF, $7F

SCANCODERECALCPOS:
    DB $0, $0, $0, $0, $0
    DB $1, $1, $1, $1, $1
    DB $2, $2, $2, $2, $2
    DB $3, $3, $3, $3, $3
    DB $4, $4, $4, $4, $4
    DB $5, $5, $5, $5, $5
    DB $6, $6, $6, $6, $6
    DB $7, $7, $7, $7, $7

SCANCODERECALCBIT:
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10
    DB $1, $2, $4, $8, $10


; ----------------------------------------------------------------------------
; KEYBOARDEMPTY
; ----------------------------------------------------------------------------
; This routine can be called to understand if the keyboard queue is empty.

KEYBOARDEMPTY:
    PUSH AF
    PUSH BC
    LD A, (KEYBOARDQUEUEWPOS)
    LD B, A
    LD A, (KEYBOARDQUEUERPOS)
    CP B
    JR Z, KEYBOARDEMPTY1
    POP BC
    POP AF
    SCF
    CCF
    RET
KEYBOARDEMPTY1:
    POP BC
    POP AF
    SCF
    RET

; ----------------------------------------------------------------------------
; KEYBOARDPUSH
; ----------------------------------------------------------------------------
; This routine can be called to push a character in front of the keyboard
; queue. This will put the character in the actual KEYBOARDQUEUEWPOS position
; and increment the KEYBOARDQUEUEWPOS by 1. If the KEYBOARDQUEUEWPOS reachs the
; end of the queue, it will return to 0. Moreover, if it is already 
; KEYBOARDQUEUERPOS then nothing will be done, and the character will be lost.
;

KEYBOARDPUSH:
    PUSH HL
    PUSH DE
    PUSH AF
    LD A,  (KEYBOARDQUEUEWPOS)
    LD E, A
    LD D, 0
    LD HL, KEYBOARDQUEUE
    ADD HL, DE
    POP AF
    LD (HL), A
    LD A,  (KEYBOARDQUEUEWPOS)
    ADD 1
    CP $0A
    JR NZ, KEYBOARDPUSHDONE
    LD A, 0
KEYBOARDPUSHDONE:
    LD (KEYBOARDQUEUEWPOS), A
KEYBOARDPUSHLOST:
    POP DE
    POP HL
    RET

; ----------------------------------------------------------------------------
; KEYBOARDPOP
; ----------------------------------------------------------------------------
; This routine can be called to pop a character from the keyboard queue. This 
; will get the character from the actual KEYBOARDQUEUERPOS position
; and increment the KEYBOARDQUEUERPOS by 1. If the KEYBOARDQUEUERPOS reachs the
; end of the queue, it will return to 0. Moreover, if it is already 
; KEYBOARDQUEUEWPOS then nothing will be get and it will be returned a $FF.

KEYBOARDPOP:
    PUSH HL
    PUSH DE
    PUSH BC
    LD A, (KEYBOARDQUEUEWPOS) 
    LD B, A
    LD A, (KEYBOARDQUEUERPOS) 
    CP B
    JR Z, KEYBOARDPOPNONE
    LD E, A
    LD D, 0
    LD HL, KEYBOARDQUEUE
    ADD HL, DE
    LD A, (HL)
    PUSH AF
    LD A, (KEYBOARDQUEUERPOS)
    ADD 1
    CP $0A
    JR NZ, KEYBOARDPOPGOT
    LD A, 0
KEYBOARDPOPGOT:
    LD (KEYBOARDQUEUERPOS), A
    POP AF
    POP BC
    POP DE
    POP HL
    RET
KEYBOARDPOPNONE:
    LD A, $FF
    POP BC
    POP DE
    POP HL
    RET

; ----------------------------------------------------------------------------
; KEYBOARDMANAGER
; ----------------------------------------------------------------------------
; This routine will be called during IRQ, and it will take some actions.
; First of all, the KEYBOARDACTUAL will be put to $FF (no key pressed).
; Then, hardware keyboard matrix will be decoded and stored it into the
; memory locations. If any key is pressed, it will be decoded and put into
; KEYBOARDACTUAL. Finally, the elapsed timer will be increased. Moreover,
; the ASF will be moved one step forward.

; This routine will decode the actual key.
;   Input: A - bitmap of key pressed
;          X - starting value of key pressed
;   Ouput: -
;   Changes: KEYBOARDACTUAL, KEYBOARDASFSTATE

KEYBOARDMANAGER:

    ; Save registers

    PUSH HL
    PUSH BC
    PUSH DE
    PUSH AF
    PUSH IX
    PUSH IY

    ; Initialize to zero the index used to track the key code.

    LD IY, 0

    ; Now, we register that no key has been pressed, yet.

    LD A, 0
    LD (KEYBOARDPRESSED), A

    ; Retrieve the address of list of I/O ports to use to retrieve the
    ; key read from a specific keyboard matrix row.

    LD HL, KEYBOARDPORTS

    ; Retrieve the address of the key state buffer.

    LD IX, SCANCODEREAD

    ; Initialize the row matrix index.

    LD D, 8

    ; Use the base I/O register ($FE)

    LD C, $FE
SCANCODE0:

    ; Load the I/O port to use,
    ; move to the next I/O port and
    ; read the valure from this port.

    LD B, (HL)
    INC HL
    IN A, (C)

    ; Complement and extract the meaningful
    ; data from it.

    XOR $FF
    AND $1F

    ; Save the value read into the keyboard state buffer,
    ; and move forward to the next keyboard matrix row.

    LD (IX), A
    INC IX
    
    LD IYH, 5

    ; If the key is zero, we have nothing to do.
    ; Otherwise, we will loop throught it, 
    ; to identify the key pressed.

    CP 0
    JR Z, SCANCODE0X

SCANCODE0L1:

    ; Move the least important bit into the carry.
    ; If the carry is set, the key has been pressed.

    SRL A
    JR C, SCANCODE0L1Y

    ; If the rest of the data read is zero, we can skip 
    ; the rest of the check.

    CP 0
    JR Z, SCANCODE0X

    ; Increase the current key code read,
    ; and decrement the number of bit to check.
    ; If there are still bits to check, go on.

    INC IYL
    DEC IYH
    JR SCANCODE0L1

    ; If we reach this line, it means that a key
    ; has been pressed. Now check for shifting state.    

SCANCODE0L1Y:

    ; LD A, (SCANCODEREAD)
    ; AND $1
    ; CP $0
    ; JR Z, SCANCODE0L1YNOSHIFT

    ; ; Key is shifted: we save the key actual pressed.
    ; LD A, IYL
    ; LD (KEYBOARDACTUAL), A
    ; JR SCANCODE0L1YDONE

SCANCODE0L1YNOSHIFT:
SCANCODE0L1YNOZERO:

    LD A, (KEYBOARDPRESSED)
    CP 0
    JR NZ, SCANCODE0L1YDONE
    
    ; Key is not shifted: we save the key actual pressed.
    LD A, IYL
    LD (KEYBOARDACTUAL), A

SCANCODE0L1YDONE:
    ; Key is pressed.
    LD A, 1
    LD (KEYBOARDPRESSED), A

SCANCODE0X:

    LD A, IYL
    ADD IYH
    LD IYL, A

    ; Move to the next keyboard's matrix row.
    DEC D
    JR NZ, SCANCODE0

    ; If any key has been pressed, 
    ; move to the rest of the routine.

    LD A, (KEYBOARDPRESSED)
    CP 1
    JR Z, SCANCODEFULLLN

    ; No key has been pressed -- we update the actual key.

    LD A, $FF
    LD (KEYBOARDACTUAL), A

SCANCODEFULLLN:

    ; Increase the elapsed timer.

    LD A, (KEYBOARDELAPSED)
    ADD $1
    LD (KEYBOARDELAPSED), A

    ; Update the ASF.

    CALL KEYBOARDASF    

    ; Restore registers.

    POP IY
    POP IX
    POP AF
    POP DE
    POP BC
    POP HL

    RET

; ----------------------------------------------------------------------------
; KEYBOARDDETECT
; ----------------------------------------------------------------------------
; This routine can be called to dectect if any key has been pressed. The
; actual key is read by KEYBOARD MANAGER that runs on IRQ, and the actual
; and previous values are stored by it.
;
; Return values:
; - C : key pressed (1) or not (0)
; - Z : key is equal to the previous detection (1) or different (0)
;
; The four values allowed by keyboard state machine follows:
;
; - DETECT (white): C = 0, Z = any
; - DETECT (green): C = 1, Z = 1
; - DETECT (red)  : C = 1, Z = 0

KEYBOARDDETECT:

    ; Check if any key has been pressed.

    LD A, (KEYBOARDACTUAL)
    CP $FF
    JR Z, KEYBOARDDETECTNONE

    SCF

    RET

KEYBOARDDETECTNONE:
    SCF
    CCF
    RET

@EMIT keyboardConfig.latency AS KEYBOARDLATENCY
@EMIT keyboardConfig.delay AS KEYBOARDDELAY
@EMIT keyboardConfig.release AS KEYBOARDRELEASE

; ----------------------------------------------------------------------------
; KEYBOARDLATENCYELAPSED
; ----------------------------------------------------------------------------
; This routine can be called to dectect if the latency time has elapsed.
; The KEYBOARDELAPSED timer is incremented by IRQ.
;
; Return values:
; - C : latency elapsed (1) or not (0)
;
; The four values allowed by keyboard state machine follows:
;
; - LATENCYELAPSED (white): C = 0
; - LATENCYELAPSED (green): C = 1

KEYBOARDLATENCYELAPSED:
    LD A, (KEYBOARDELAPSED)
    CP KEYBOARDLATENCY
    RET

; ----------------------------------------------------------------------------
; KEYBOARDRELEASEELAPSED
; ----------------------------------------------------------------------------
; This routine can be called to dectect if the release time has elapsed.
; The KEYBOARDELAPSED timer is incremented by IRQ.
;
; Return values:
; - C : release elapsed (1) or not (0)
;
; The four values allowed by keyboard state machine follows:
;
; - RELEASEELAPSED (white): C = 0
; - RELEASEELAPSED (green): C = 1

KEYBOARDRELEASEELAPSED:
    LD A, (KEYBOARDELAPSED)
    CP KEYBOARDRELEASE
    RET
    
; ----------------------------------------------------------------------------
; KEYBOARDDELAYLAPSED
; ----------------------------------------------------------------------------
; This routine can be called to dectect if the delay time has elapsed.
; The KEYBOARDELAPSED timer is incremented by IRQ.
;
; Return values:
; - C : delay elapsed (1) or not (0)
;
; The four values allowed by keyboard state machine follows:
;
; - DELAYELAPSED (white): C = 0
; - DELAYELAPSED (green): C = 1

KEYBOARDDELAYELAPSED:
    LD A, (KEYBOARDELAPSED)
    CP KEYBOARDDELAY
    RET

; ----------------------------------------------------------------------------
; KEYBOARDASF
; ----------------------------------------------------------------------------
; This routine will implement the ASF for keyboard. It means that will check
; for events and change the state of the ASF.
;

KEYBOARDASF:

    ; Preserve used registers

    PUSH AF
    PUSH BC
    PUSH HL

    ; Decode the actual state.

    LD A, (KEYBOARDASFSTATE)
    
    CP 0
    JR Z, KEYBOARDASF0
    LD B, A
    DEC B
    JR Z, KEYBOARDASF1
    DEC B
    JR Z, KEYBOARDASF2
    DEC B
    JR Z, KEYBOARDASF3
    JP KEYBOARDASFDONE

    ; --------------
    ; STATE 0 - FREE
    ; --------------

KEYBOARDASF0:

    ; CALL KEYBOARDEMPTY
    ; JR C, KEYBOARDASF0B
    ; CALL KEYBOARDPOP
    ; LD (KEYBOARDACTUAL), A

KEYBOARDASF0B:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red)

    CALL KEYBOARDDETECT

    ; If no key has been detected, we can remain
    ; in this state.

    JR NC, KEYBOARDASFDONE

    ; Move to state 1, and reset the elapsed 
    ; timer at the same time.
    
KEYBOARDASFTO1:

    ; Reset the elapsed timer.

    LD A, 0
    LD (KEYBOARDELAPSED), A

    ; Set the state.

    LD A, 1
    LD (KEYBOARDASFSTATE), A

    JP KEYBOARDASFDONE

    ; -----------------
    ; STATE 1 - PRESSED
    ; -----------------

KEYBOARDASF1:

    ; CALL KEYBOARDEMPTY
    ; JR C, KEYBOARDASF1B
    ; JMP KEYBOARDASFTO0

KEYBOARDASF1B:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red).
    
    CALL KEYBOARDDETECT

    ; If the no key has been pressed, 
    ; we go back to state 0.

    JR NC, KEYBOARDASFTO0

    ; ; If a different key has been pressed, 
    ; ; we go back to state 0.

    ; BEQ KEYBOARDASFTO0

    ; Chek for latency elapsed.

    CALL KEYBOARDLATENCYELAPSED

    ; If latency has passed, we move to the 
    ; state 2.

    JR NC, KEYBOARDASFTO2

    ; We remain in state 1.

    JP KEYBOARDASFDONE

    ; Move to state 0, and reset the elapsed 
    ; timer at the same time.

KEYBOARDASFTO0:

    ; Reset the elapsed timer.

    LD A, 0
    LD (KEYBOARDELAPSED), A

    ; Reset the state.

    LD (KEYBOARDASFSTATE), A

    JP KEYBOARDASFDONE

KEYBOARDASFTO2:

    ; Reset the elapsed timer.

    LD A, 0
    LD (KEYBOARDELAPSED), A

    ; Set the state.

    LD A, 2
    LD (KEYBOARDASFSTATE), A

    JP KEYBOARDASFDONE

    ; -----------------
    ; STATE 2 - PRESSED
    ; -----------------

KEYBOARDASF2:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red).
    
    CALL KEYBOARDDETECT

    ; If the no key has been pressed, 
    ; we go back to state 0.

    JR NC, KEYBOARDASFTO0

    ; ; If a different key has been pressed, 
    ; ; we go back to state 0.

    ; BEQ KEYBOARDASFTO0

    ; Chek for release elapsed.

    CALL KEYBOARDRELEASEELAPSED

    ; If released has passed, we move to the 
    ; state 3.

    JR NC, KEYBOARDASFTO3

    ; We remain in state 2.

    JP KEYBOARDASFDONE

    ; Move to state 3, and reset the elapsed 
    ; timer at the same time.

KEYBOARDASFTO3:

    ; Reset the elapsed timer.

    LD A, 0
    LD (KEYBOARDELAPSED), A

    ; Set the next state.

    LD A, 3
    LD (KEYBOARDASFSTATE), A

    JP KEYBOARDASFDONE

    ; -------------------
    ; STATE 3 - CONTINUED
    ; -------------------

KEYBOARDASF3:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red).
    
    CALL KEYBOARDDETECT

    ; If the no key has been pressed, 
    ; we go back to state 0.

    JR NC, KEYBOARDASFTO0

    ; ; If a different key has been pressed, 
    ; ; we go back to state 0.

    ; BEQ KEYBOARDASFTO0

    ; Chek for delay elapsed.

    CALL KEYBOARDDELAYELAPSED

    ; If delay has passed, we move to the 
    ; state 2.

    JR NC, KEYBOARDASFTO2

    ; We remain in state 3.

    JP KEYBOARDASFDONE

KEYBOARDASFDONE:

    ; Restore used registers

    POP HL
    POP BC
    POP AF
    
    RET

; ----------------------------------------------------------------------------
; WAITKEY
; ----------------------------------------------------------------------------
; This routine will wait for a key press. It means that it will, first, wait
; for the passing FREE(0)->PRESSED(1). Since the keyboard could already have
; a key pressed, we must also wait for FREE(0) state, first.

WAITKEY:
    LD A, (KEYBOARDASFSTATE)
    CP 0
    JR Z, WAITKEY1
WAITKEY0:
    LD A, (KEYBOARDASFSTATE)
    CP 0
    JR NZ, WAITKEY0
WAITKEY1:
    LD A, (KEYBOARDASFSTATE)
    CP 0
    JR Z, WAITKEY1
    RET

; ----------------------------------------------------------------------------
; WAITKEYRELEASE
; ----------------------------------------------------------------------------
; This routine will wait for a key press AND for a release. It means that it 
; will, first, WAITKEY. Then, it will wait for a FREE(0) state.

WAITKEYRELEASE:
    CALL WAITKEY
WAITKEYRELEASE0:
    LD A, (KEYBOARDASFSTATE)
    CP 0
    JR NZ, WAITKEYRELEASE0
    RET

; ----------------------------------------------------------------------------
; KEYSTATE
; ----------------------------------------------------------------------------
; This routine can be called to detect if any key has been pressed. It does
; not disturb the hardware but it will use the memory map, that has been
; refreshed by the last IRQ.
;
; Input:
; - A : key to check
;
; Return values:
; - C : key pressed (1) or not (0)

KEYSTATE:

    PUSH HL
    PUSH DE

    PUSH AF
    LD E, A
    LD D, 0
    LD HL, SCANCODERECALCBIT
    ADD HL, DE
    LD A, (HL)
    LD B, A
    POP AF

    PUSH AF
    LD E, A
    LD D, 0
    LD HL, SCANCODERECALCPOS
    ADD HL, DE
    LD A, (HL)
    LD E, A
    LD D, 0
    POP AF

    LD HL, SCANCODEREAD 
    ADD HL, DE
    LD A, (HL)
    AND B
    CP 0
    JR Z, KEYSTATE0

    POP DE
    POP HL
    SCF
    RET
KEYSTATE0:
    POP DE
    POP HL
    SCF
    CCF
    RET

; ----------------------------------------------------------------------------
; SCANCODE
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the key pressed. It will not disturb
; the hardware, since it will use the KEYBOARDACTUAL value.
;
; Return values:
; - A : KEYBOARDACTUAL

SCANCODE:
    LD A, (KEYBOARDINKEY)
    CP $FF
    JR Z, SCANCODE1
    RET
SCANCODE1:
    LD A, (KEYBOARDACTUAL)
    RET

; ----------------------------------------------------------------------------
; ASCIICODE
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the key pressed, converted into 
; ASCII code. It will not disturb the hardware, since it will use SCANCODE.
;
; Return values:
; - A : ASCII value

ASCIICODE:
    CALL SCANCODE
ASCIICODEDIR:
    LD HL, KEYBOARDMAP 
    LD E, A
    LD A, 0
    LD D, A
    ADD HL, DE
    LD A, (HL)
    RET


; ----------------------------------------------------------------------------
; KEYPRESS
; ----------------------------------------------------------------------------
; This routine can be called to retrieve if a specific key is pressed, 
; counting the ASF state. It will return the value only in the duty cycle.
;
; Input:
; - X : key to check
;
; Return values:
; - C : key pressed (1) or not (0)

KEYPRESS:

    LD A, (KEYBOARDASFSTATE)
    CP 0
    JR Z, KEYSINGLE0
    LD B, A
    DEC B
    JR Z, KEYSINGLE1
    DEC B
    JR Z, KEYSINGLE2
    DEC B
    JR Z, KEYSINGLE3
    JP KEYBOARDASFDONE

KEYSINGLE0:
KEYSINGLE2:
    SCF
    CCF
    RET

KEYSINGLE1:
KEYSINGLE3:
    CALL KEYSTATE
    RET

; ----------------------------------------------------------------------------
; KEYPRESSED
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the pressed key, counting the ASF 
; state. It will return the value only in the duty cycle.
;
; Return values:
; - A : KEYBOARDACTUAL only if KEYBOARDASFSTATE = 1 or 3

KEYPRESSED:
    LD A, (KEYBOARDASFSTATE)
    CP 0
    JR Z, KEYPRESSED0
    LD B, A
    DEC B
    JR Z, KEYPRESSED1
    DEC B
    JR Z, KEYPRESSED2
    DEC B
    JR Z, KEYPRESSED3
    RET

KEYPRESSED0:
KEYPRESSED2:
    LD A, $FF
    RET

KEYPRESSED1:
KEYPRESSED3:
    LD A, (KEYBOARDACTUAL)
    RET

KEYBOARDMAP:
    DB $08,"Z","X","C","V"
    DB "A","S","D","F","G"
    DB "Q","W","E","R","T"
    DB "1","2","3","4","5"
    DB "0","9","8","7","6"
    DB "P","O","I","U","Y"
    DB "#","L","K","J","H"
    DB " ","#","M","N","B"
    DB $FF
KEYBOARDMAP2:
    DB $08,"z","x","c","v"
    DB "a","s","d","f","g"
    DB "q","w","e","r","t"
    DB "1","2","3","4","5"
    DB "0","9","8","7","6"
    DB "p","o","i","u","y"
    DB "#","l","k","j","h"
    DB " ","#","m","n","b"
    DB $FF

; ----------------------------------------------------------------------------
; INKEY
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the pressed key, counting the ASF 
; state, and converted to ASCII. It will return the value only in 
; the duty cycle.
;
; Return values:
; - A : ASCII CODE of KEYBOARDACTUAL only if KEYBOARDASFSTATE = 1 or 3

WAITKEY02:
    PUSH AF
WAITKEY02L:
    LD A, (KEYBOARDASFSTATE)
    CP 1
    JR Z, WAITKEY02L
    CP 3
    JR Z, WAITKEY02L
    POP AF
    RET

INKEY:
    CALL KEYBOARDEMPTY
    JR C, INKEYB
    CALL KEYBOARDPOP
    CALL ASCIICODEDIR
    RET
INKEYB:
    CALL KEYPRESSED
    CP $FF
    JR Z, INKEY0
    LD (KEYBOARDINKEY), A
    LD HL, KEYBOARDMAP
    LD E, A
    LD A, 0
    LD D, A
    ADD HL, DE
    LD A, (HL)
    CALL WAITKEY02
    RET
INKEY0:
    LD A, 0
    RET

; ----------------------------------------------------------------------------
; KEY SHIFT
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the status of key / control buttons.
;
; Return values:
; - A : bitmap of key pressed
;           0	Left SHIFT
;           1	Right SHIFT
;           2	CAPS LOCK
;           3	CONTROL
;           4	Left ALT
;           5	Right ALT

KEYSHIFT:
    LD A, (KEYBOARDSHIFT)
    RET

; ----------------------------------------------------------------------------
; CLEAR KEY
; ----------------------------------------------------------------------------
; This routine can be called to clear the keyboard queue.

CLEARKEY:
    LD A, 0
    LD (KEYBOARDQUEUEWPOS), A
    LD (KEYBOARDQUEUERPOS), A
    LD (KEYBOARDASFSTATE), A
    LD (KEYBOARDELAPSED), A
    LD A, $FF
    LD (KEYBOARDACTUAL), A
    RET

; ----------------------------------------------------------------------------
; PUT KEY
; ----------------------------------------------------------------------------
; This routine can be called to put a string into the keyboard queue.
;
; Input:
;      HL: address of string
;      C: size of the string

PUTKEY:
    PUSH HL
    PUSH DE
    DI
PUTKEYL1:
    PUSH BC
    LD C, 0
    LD A, (HL)
    LD DE, KEYBOARDMAP
    LD B, A
PUTKEYL2:
    LD A, (DE)
    CP B
    JR Z, PUTKEYL2T
    CP $FF
    JR Z, PUTKEYL2E
    INC DE
    INC C
    JP PUTKEYL2
PUTKEYL2E:
    LD DE, KEYBOARDMAP2
    LD C, 0
PUTKEYL2EL1:    
    LD A, (DE)
    CP B
    JR Z, PUTKEYL2T
    CP $FF
    JR Z, PUTKEYL2E2
    INC DE
    INC C
    JP PUTKEYL2EL1
PUTKEYL2T:
    LD A, C
    CALL KEYBOARDPUSH
    POP BC
    DEC C
    INC HL
    JR NZ, PUTKEYL1
PUTKEYL2E2:
    POP DE
    POP HL
    EI
    RET
