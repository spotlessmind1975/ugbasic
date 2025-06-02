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
;*                         KEYBOARD MANAGEMENT ON C=128                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODEREAD:
	DB $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

KEYBOARDQUEUE:          DS 10,$FF
KEYBOARDQUEUERPOS:      DB $00
KEYBOARDQUEUEWPOS:      DB $00
KEYBOARDACTUAL:         DB $FF
KEYBOARDSHIFT:          DB $00
KEYBOARDINKEY:          DB $FF

KEYBOARDTEMP:           DB $00

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

KEYBOARDPRESSED: DB 0

KEYBOARDMANAGERSINGLEKEYPRESSEDLSHIFT:
    PUSH AF
    LD A, (KEYBOARDSHIFT)
    OR $01
    LD (KEYBOARDSHIFT), A
    POP AF
    JP KEYBOARDMANAGERSINGLEKEYL1CONTINUE

KEYBOARDMANAGERSINGLEKEYPRESSEDRSHIFT:
    PUSH AF
    LD A, (KEYBOARDSHIFT)
    OR $02
    LD (KEYBOARDSHIFT), A
    POP AF
    JP KEYBOARDMANAGERSINGLEKEYL1CONTINUE

KEYBOARDMANAGERSINGLEKEYPRESSEDCTRL:
    PUSH AF
    LD A, (KEYBOARDSHIFT)
    OR $08
    LD (KEYBOARDSHIFT), A
    POP AF
    JP KEYBOARDMANAGERSINGLEKEYL1CONTINUE

KEYBOARDMANAGERSINGLEKEY:

    ; This loop will be repeated for each bit
    ; into the A register.

KEYBOARDMANAGERSINGLEKEYL1:

    ; Move first bit in carry flag

	SRL A

    ; If C=1 it means that that key has been pressed.

	JR C, KEYBOARDMANAGERSINGLEKEYPRESSED

    ; Increment the position to check.

	INC B

    ; If A <> 0 it means that some other 
    ; checks are needed.

	CP $0
	JR NZ, KEYBOARDMANAGERSINGLEKEYL1
    
    ; No key has been detected, really.

    LD A, $FF
    LD (KEYBOARDACTUAL), A

    RET

KEYBOARDMANAGERSINGLEKEYPRESSED:

    LD A, B    

    CP $0F
    JR Z, KEYBOARDMANAGERSINGLEKEYPRESSEDLSHIFT

    CP $34
    JR Z, KEYBOARDMANAGERSINGLEKEYPRESSEDRSHIFT

    CP $36
    JR Z, KEYBOARDMANAGERSINGLEKEYPRESSEDRSHIFT

    CP $3A
    JR Z, KEYBOARDMANAGERSINGLEKEYPRESSEDCTRL

    LD (KEYBOARDACTUAL), A

    LD A, 1
    LD (KEYBOARDPRESSED), A

KEYBOARDMANAGERSINGLEKEYL1CONTINUE:
    RET

KEYBOARDMANAGER:
    PUSH HL
    PUSH AF
    PUSH BC

    CALL KEYBOARDEMPTY
    JP NC, KEYBOARDMANAGERDONEYES

    LD A, 0
    LD (KEYBOARDPRESSED), A
    LD (KEYBOARDSHIFT), A

	; Also note you must store $FF in the "row select register" you are not using. 
	; This means if you want to read from any 8 of the $DC00 rows (top 8 rows), 
	; you store $FF in $D02F because you are not using $D02F now. 
	; Likewise, to read any 3 of the $D02F rows, be sure to store $FF into $DC00.

	LD A, $FF

	; LD ($D02F), A
    LD BC, $D02F
    OUT (C), A

	; The normal way (like done by the KERNAL ROM) is to store a value in $DC00 
	; (or $D02F) as indicated on the left-most column that runs up-down the table. 
	; Which ever value you choose corresponds to the row of keys listed to the right. 
	; Then read a value from $DC01. If no key in that row is choosen, you will 
	; read $FF. Otherwise, the value you read will be listed at the top of the table, 
	; in the same column as the key that was pressed.

    LD B, 0

	LD C, 8
	LD A, $FE
    LD HL, SCANCODEREAD
SCANCODEFULLL1:

	; LD ($DC00), A

    PUSH BC
    LD BC, $DC00
    OUT (C), A
    POP BC

	PUSH AF

	; LD A, ($DC01)

    PUSH BC
    LD BC, $DC01
    IN A, (C)
    POP BC

    XOR $FF
	LD (HL),A

    CP $0
    JR Z, SCANCODEFULLL12
    CALL KEYBOARDMANAGERSINGLEKEY
SCANCODEFULLL12:

    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B

	POP AF
    SCF
	RL A
	INC HL
    DEC C
	JR NZ, SCANCODEFULLL1

	; Let's do an example. To read the second $DC00 row, notice the value in left column
	; is $FD. Store $FD in $DC00. In this row you can check 3(#), W, A, 4($), Z, S, E, 
	; and SHIFT keys.

	LD A, $FF
	; LD ($DC00), A

    PUSH BC
    LD BC, $DC00
    OUT (C), A
    POP BC

	; Next read $DC01. If you read $FF then no keys in second row are pressed. If you 
	; read $EF then the "Z" key is pressed (notice at top of table above "Z" is value $EF).

    LD C, 3
	LD A, $FE
	SCF
SCANCODEFULLL2:

	; LD ($D02F), A

    PUSH BC
    LD BC, $D02F
    OUT (C), A
    POP BC

	PUSH AF

	; LD A, ($DC01)

    PUSH BC
    LD BC, $DC01
    IN A, (C)
    POP BC

    XOR $FF

	LD (HL), A

    CP $0
    JR Z, SCANCODEFULLL12B
    CALL KEYBOARDMANAGERSINGLEKEY
SCANCODEFULLL12B:

    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B

	POP AF
    SCF
	RL A
    INC HL
	DEC C
	JR NZ, SCANCODEFULLL2

	; Finally, when you are done checking the keyboard, it is a good idea to store $7F into $DC00 
	; (and also $FF into $D02F). This is because the eigth row contains the STOP key, and the 
	; KERNAL ROM expects this row to be active so it can check for STOP key pressed by 
	; simply reading $DC01.

	LD A, $7F
	; LD ($DC00), A
    PUSH BC
    LD BC, $DC00
    OUT (C), A
    POP BC

	LD A, $FF
	; LD ($D02F), A
    PUSH BC
    LD BC, $D02F
    OUT (C), A
    POP BC

    LD A, (KEYBOARDPRESSED)
    CP 1
    JR Z, SCANCODEFULL23
    LD A, $FF
    LD (KEYBOARDACTUAL), A
SCANCODEFULL23:
KEYBOARDMANAGERDONEYES:

    ; Increase the elapsed timer.

    LD A, (KEYBOARDELAPSED)
    ADD $1
    LD (KEYBOARDELAPSED), A

    ; Update the ASF.

    CALL KEYBOARDASF    

    POP BC
    POP AF
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

KEYBOARDELAPSED:     DB 0

@EMIT keyboardConfig.latency AS KEYBOARDLATENCY
@EMIT keyboardConfig.delay AS KEYBOARDDELAY
@EMIT keyboardConfig.release AS KEYBOARDRELEASE

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

    CALL KEYBOARDEMPTY
    JR C, KEYBOARDASF0B
    CALL KEYBOARDPOP
    LD (KEYBOARDACTUAL), A

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

    CALL KEYBOARDEMPTY
    JR C, KEYBOARDASF1B
    JMP KEYBOARDASFTO0

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
    AND $07
    LD E, A
    LD D, 0
    LD HL, BITMASK
    ADD HL, DE
    LD A, (HL)
    LD B, A
    POP AF

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
    CP $ff
    JR NZ, ASCIICODEDIR
    LD A, 0
    RET
ASCIICODEDIR:
    LD HL, KEYBOARDMAP 
    LD E, A
    LD A, 0
    LD D, A
    ADD HL, DE
    LD A, (HL)
    RET

KEYBOARDMAP:
	; 		INST/DEL, Return, CRSR =>,  F7,  ' ',  F3,  F5,  CRSR|V
	DB 	     $08,    $0d,     $00, $00,  ' ', $00, $00,     $00
	; 		     #/3,    W,       A,    $/4,   Z,   S,   E,   Left Shift/Shift Lock
	DB        '3',  'W',     'A',    '4', 'Z', 'S', 'E',    $00
	;            %/5,    R,       D,    &/6,   C,   F,   T,      X
	DB        '5',  'R',     'D',    '6', 'C', 'F', 'T',    'X'
	;            '/7,    Y,       G,    (/8,   B,   H,   U,      V
	DB        '7',  'Y',     'G',    '8', 'B', 'H', 'U',    'V'
	;	         )/9,    I,       J,      0,   M,   K,   O,      N
	DB        '9',  'I',     'J',    '0', 'M', 'K', 'O',    'N'
	;              +,    P,       L,      -, >/., [/:, @/<,      ,
	DB        '+',  'P',     'L',    '-', '.', ':', '<',    ','
	;              £,    *,     ]/;,     CH,  RS,  =,    ^,   ?//
	DB        'L',  '*',     ';',    $00, $00, '=', '^',    '/'
	;            !/1,   <-,    CTRL,    "/2, SPC,  C=,   Q, RUN STOP
	DB        '1',  $00,     $00,    '2', ' ', $00, 'Q',    $00
	;           HELP,    8,       5,    TAB,   2,   4,   7,      1
	DB		 $00,  '8',     '5',      9, '2', '4', '7',    '1'
	;            ESC,    +,       -,     LF, CR,    6,   9,      3
	DB         27,  '+',     '-',    $00,$0d,  '6', '9',    '3'
	;            ALT,    0,       .,     UP,DWN, LFT, RGT, NOSCROLL
	DB        $00,  '0',     '.',    $00,$00, $00, $00, $00
    DB        $FF
KEYBOARDMAP2:
	; 		INST/DEL, Return, CRSR =>,  F7,  ' ',  F3,  F5,  CRSR|V
	DB 	     $08,    $0d,     $00, $00,  ' ', $00, $00,     $00
	; 		     #/3,    W,       A,    $/4,   Z,   S,   E,   Left Shift/Shift Lock
	DB        '3',  'w',     'a',    '4', 'z', 's', 'e',    $00
	;            %/5,    R,       D,    &/6,   C,   F,   T,      X
	DB        '5',  'r',     'd',    '6', 'c', 'f', 't',    'x'
	;            '/7,    Y,       G,    (/8,   B,   H,   U,      V
	DB        '7',  'y',     'g',    '8', 'b', 'h', 'u',    'v'
	;	         )/9,    I,       J,      0,   M,   K,   O,      N
	DB        '9',  'i',     'j',    '0', 'm', 'k', 'o',    'n'
	;              +,    P,       L,      -, >/., [/:, @/<,      ,
	DB        '+',  'p',     'l',    '-', '.', ':', '<',    ','
	;              £,    *,     ]/;,     CH,  RS,  =,    ^,   ?//
	DB        'l',  '*',     ';',    $00, $00, '=', '^',    '/'
	;            !/1,   <-,    CTRL,    "/2, SPC,  C=,   Q, RUN STOP
	DB        '1',  $00,     $00,    '2', ' ', $00, 'q',    $00
	;           HELP,    8,       5,    TAB,   2,   4,   7,      1
	DB		 $00,  '8',     '5',      9, '2', '4', '7',    '1'
	;            ESC,    +,       -,     LF, CR,    6,   9,      3
	DB         27,  '+',     '-',    $00,$0d,  '6', '9',    '3'
	;            ALT,    0,       .,     UP,DWN, LFT, RGT, NOSCROLL
	DB        $00,  '0',     '.',    $00,$00, $00, $00, $00
    DB        $ff

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
