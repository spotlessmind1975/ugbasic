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
;*                          KEYBOARD MANAGEMENT ON CPC                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODEREAD:
	DB $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

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
;   Changes: KEYBOARDACTUAL, KEYBOARDPREVIOUS, KEYBOARDASFSTATE

KEYBOARDPRESSED: DB 0

KEYBOARDMANAGER:

    PUSH HL
    PUSH BC
    PUSH DE
    PUSH AF

    LD IXL, 0
    LD A, 0
    LD (KEYBOARDPRESSED), A

    LD HL, SCANCODEREAD
    LD BC, $f782
    OUT (C), C
    LD BC, $f40e
    LD E, B
    OUT (C), C
    LD BC, $f6c0
    LD D, B
    OUT (C), C
    XOR A
    OUT (C), A
    LD BC, $f792
    OUT (C), C
    LD A, $40
    LD C, $4A
SCANCODEENTIREL1:
    LD B, D
    OUT (C), A
    LD B, E
    
    PUSH AF
    IN A, (C)
    XOR $FF
    LD (HL), A
    INC HL
    CP 0
    JR Z, SCANCODEENTIREL1B

SCANCODEENTIREL1BL1:
    CP 0
    JR Z, SCANCODEENTIREL1B
    SRL A
    JR NC, SCANCODEENTIREL1BL2

    LD A, (KEYBOARDACTUAL)
    LD (KEYBOARDPREVIOUS), A
    LD A, IXL
    LD (KEYBOARDACTUAL), A
    LD A, 1
    LD (KEYBOARDPRESSED), A
    JR SCANCODEENTIREL1B

SCANCODEENTIREL1BL2:
    INC IXL
    JR SCANCODEENTIREL1BL1

SCANCODEENTIREL1B:
    POP AF

    INC IXL
    INC IXL
    INC IXL
    INC IXL
    INC IXL
    INC IXL
    INC IXL
    INC IXL

    INC A
    CP C
    JR C, SCANCODEENTIREL1
    LD BC, $f782
    OUT (C), C

    LD A, (KEYBOARDPRESSED)
    CP 1
    JR Z, SCANCODEENTIREL1XX

    LD A, (KEYBOARDACTUAL)
    LD (KEYBOARDPREVIOUS), A
    LD A, $FF
    LD (KEYBOARDACTUAL), A

SCANCODEENTIREL1XX:

    ; Increase the elapsed timer.

    LD A, (KEYBOARDELAPSED)
    ADD $1
    LD (KEYBOARDELAPSED), A

    ; Update the ASF.

    CALL KEYBOARDASF

    POP AF
    POP DE
    POP BC
    POP HL

	RET

KEYBOARDACTUAL:          DB $FF
KEYBOARDPREVIOUS:        DB $FF

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

    ; A key has been pressed. Set the carry flag and check
    ; if it is the same as the previous pressed.

    ; CMP KEYBOARDPREVIOUS
    
    SCF

    RET

KEYBOARDDETECTNONE:
    SCF
    CCF
    RET

KEYBOARDELAPSED:     DB 0

@EMIT inputConfig.latency AS KEYBOARDLATENCY
@EMIT inputConfig.delay AS KEYBOARDDELAY
@EMIT inputConfig.release AS KEYBOARDRELEASE

KEYBOARDASFSTATE:    DB 0

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
    JR Z, WAITKEY1
WAITKEY0:
    LD A, (KEYBOARDASFSTATE)
    JR NZ, WAITKEY0
WAITKEY1:
    LD A, (KEYBOARDASFSTATE)
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

    LD HL, SCANCODEREAD 

    PUSH AF
    SRL A
    SRL A
    SRL A
    LD E, A
    LD A, 0
    LD D, A
    ADD HL, DE
    POP AF

    PUSH AF
    AND $07
    LD B, A
    POP AF

    LD A, (HL)

KEYSTATEL1:
    SRL A
    JR C, KEYSTATE10
    CP 0
    JR Z, KEYSTATE10
    DEC B
    JP KEYSTATEL1

KEYSTATE10:
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
    LD HL, KEYBOARDMAP 
    LD E, A
    LD A, 0
    LD D, A
    ADD HL, DE
    LD A, (HL)
    RET

KEYBOARDMAP:
    ; 0
    ;       0   1   2   3   4   5   6   7   8   9
    DB      0, 00, 00,  0,  0,'V',  0,  0, 00,  0
    ; 1
    ;       0   1   2   3   4   5   6   7   8   9
    DB      0,  0,  0,  0,  0,  0, 00,  0, 13,'\\'
    ; 2
    ;       0   1   2   3   4   5   6   7   8   9
    DB      0, 00,  0, 00, 00, '-',  0,'P',  0,  0
    ; 3
    ;       0   1   2   3   4   5   6   7   8   9
    DB      0, '.','+','9','O','I','L','K','M',','
    ; 4
    ;       0   1   2   3   4   5   6   7   8   9
    DB     '0','7','U','Y','H','J','N',' ', '8','5'
    ; 5
    ;       0   1   2   3   4   5   6   7   8   9
    DB     'R','T','G','F','B','V','6','3','E','W'
    ; 6
    ;       0   1   2   3   4   5   6   7   8   9
    DB     'S','D','C','X','4','2', 27,'Q',  9,'A'
    ; 7
    ;       0   1   2   3   4   5   6   7   8   9
    DB     00,'Z','1',  0,  0,  0,  0,  0,  0,  8

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
    CALL KEYPRESSED
    CP $FF
    JR Z, INKEY0
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
