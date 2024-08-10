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
;*                         KEYBOARD MANAGEMENT ON C=128                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODEREAD:
	.BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

SCANCODEPTR = $9

KEYBOARDQUEUE:          .RES 10,$FF
KEYBOARDQUEUERPOS:      .BYTE $00
KEYBOARDQUEUEWPOS:      .BYTE $00
KEYBOARDACTUAL:         .BYTE $FF
KEYBOARDSHIFT:          .BYTE $00
KEYBOARDINKEY:          .BYTE $FF

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
    LDX KEYBOARDQUEUEWPOS
    ; CPX KEYBOARDQUEUERPOS
    ; BEQ KEYBOARDPUSHLOST
    STA KEYBOARDQUEUE, X
    INX
    CPX #$0A
    BNE KEYBOARDPUSHDONE
    LDX #0
KEYBOARDPUSHDONE:
    STX KEYBOARDQUEUEWPOS
KEYBOARDPUSHLOST:
    RTS

; ----------------------------------------------------------------------------
; KEYBOARDPOP
; ----------------------------------------------------------------------------
; This routine can be called to pop a character from the keyboard queue. This 
; will get the character from the actual KEYBOARDQUEUERPOS position
; and increment the KEYBOARDQUEUERPOS by 1. If the KEYBOARDQUEUERPOS reachs the
; end of the queue, it will return to 0. Moreover, if it is already 
; KEYBOARDQUEUEWPOS then nothing will be get and it will be returned a $FF.

KEYBOARDPOP:
    LDX KEYBOARDQUEUERPOS
    CPX KEYBOARDQUEUEWPOS
    BEQ KEYBOARDPOPNONE
    LDA KEYBOARDQUEUE, X
    INX
    CPX #$0A
    BNE KEYBOARDPOPGOT
    LDX #0
KEYBOARDPOPGOT:
    STX KEYBOARDQUEUERPOS
    RTS
KEYBOARDPOPNONE:
    LDA #$FF
    RTS

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

KEYBOARDPRESSED: .BYTE 0

KEYBOARDMANAGERSINGLEKEYPRESSEDLSHIFT:
    LDA #$01
    ORA KEYBOARDSHIFT
    STA KEYBOARDSHIFT
    JMP KEYBOARDMANAGERSINGLEKEYL1CONTINUE

KEYBOARDMANAGERSINGLEKEYPRESSEDRSHIFT:
    LDA #$02
    ORA KEYBOARDSHIFT
    STA KEYBOARDSHIFT
    JMP KEYBOARDMANAGERSINGLEKEYL1CONTINUE

KEYBOARDMANAGERSINGLEKEYPRESSEDCTRL:
    LDA #$08
    ORA KEYBOARDSHIFT
    STA KEYBOARDSHIFT
    JMP KEYBOARDMANAGERSINGLEKEYL1CONTINUE

KEYBOARDMANAGERSINGLEKEY:

    ; This loop will be repeated for each bit
    ; into the A register.

KEYBOARDMANAGERSINGLEKEYL1:

    ; Move first bit in carry flag

	LSR

    ; If C=1 it means that that key has been pressed.

	BCS KEYBOARDMANAGERSINGLEKEYPRESSED

KEYBOARDMANAGERSINGLEKEYL1CONTINUE:

    ; Increment the position to check.

	INX

    ; If A <> 0 it means that some other 
    ; checks are needed.

	CMP #$0
	BNE KEYBOARDMANAGERSINGLEKEYL1


    ; No key has been detected, really.

    ; LDA #$FF
    ; STA KEYBOARDACTUAL

    RTS

KEYBOARDMANAGERSINGLEKEYPRESSED:

    ; Save the actual key pressed
    ; in the keyboard queue.
    
    CPX #$0F
    BEQ KEYBOARDMANAGERSINGLEKEYPRESSEDLSHIFT

    CPX #$34
    BEQ KEYBOARDMANAGERSINGLEKEYPRESSEDRSHIFT

    CPX #$3A
    BEQ KEYBOARDMANAGERSINGLEKEYPRESSEDCTRL

    TXA
    JSR KEYBOARDPUSH

    INC KEYBOARDPRESSED

    RTS

KEYBOARDMANAGER:

    ; Preserve used registers.

	PHA
	TYA
	PHA
	TXA
	PHA

    ; Reset the key press detector.

    LDA #0
    STA KEYBOARDPRESSED

    LDA #0
    STA KEYBOARDSHIFT

    ; Prepare to store values into memory.

	LDA #<SCANCODEREAD
	STA SCANCODEPTR
	LDA #>SCANCODEREAD
	STA SCANCODEPTR+1

	; Also note you must store $FF in the "row select register" you are not using. 
	; This means if you want to read from any 8 of the $DC00 rows (top 8 rows), 
	; you store $FF in $D02F because you are not using $D02F now. 
	; Likewise, to read any 3 of the $D02F rows, be sure to store $FF into $DC00.

	LDA #$FF
	STA $D02F

	; The normal way (like done by the KERNAL ROM) is to store a value in $DC00 
	; (or $D02F) as indicated on the left-most column that runs up-down the table. 
	; Which ever value you choose corresponds to the row of keys listed to the right. 
	; Then read a value from $DC01. If no key in that row is choosen, you will 
	; read $FF. Otherwise, the value you read will be listed at the top of the table, 
	; in the same column as the key that was pressed.

	LDY #0
    LDX #0
	LDA #$FE
SCANCODEFULLL1:
	STA $DC00
	PHA
	LDA $DC01
    EOR #$FF
	STA (SCANCODEPTR),Y
    CMP #$0
    BEQ SCANCODEFULLL12
    JSR KEYBOARDMANAGERSINGLEKEY
SCANCODEFULLL12:
    INX
    INX
    INX
    INX
    INX
    INX
    INX
    INX
	PLA
	SEC
	ROL
	INY
	CPY #8
	BNE SCANCODEFULLL1

	; Let's do an example. To read the second $DC00 row, notice the value in left column
	; is $FD. Store $FD in $DC00. In this row you can check 3(#), W, A, 4($), Z, S, E, 
	; and SHIFT keys.

	LDA #$FF
	STA $DC00

	; Next read $DC01. If you read $FF then no keys in second row are pressed. If you 
	; read $EF then the "Z" key is pressed (notice at top of table above "Z" is value $EF).

	LDA #$FE
	SEC
SCANCODEFULLL2:
	STA $D02F
	PHA
	LDA $DC01
    EOR #$FF
	STA (SCANCODEPTR),Y
    CMP #$0
    BEQ SCANCODEFULLL22
    JSR KEYBOARDMANAGERSINGLEKEY
SCANCODEFULLL22:
    INX
    INX
    INX
    INX
    INX
    INX
    INX
    INX
	PLA
	ROL A
	INY
	CPY #11
	BNE SCANCODEFULLL2

	; Finally, when you are done checking the keyboard, it is a good idea to store $7F into $DC00 
	; (and also $FF into $D02F). This is because the eigth row contains the STOP key, and the 
	; KERNAL ROM expects this row to be active so it can check for STOP key pressed by 
	; simply reading $DC01.

	LDA #$FF
	STA $DC00
	LDA #$FF
	STA $D02F

    ; Increase the elapsed timer.

    INC KEYBOARDELAPSED

    ; If is present one key in the
    ; queue, we ignore the pressing key and
    ; try to consume the queue in a rapid way.

    SEC
    LDA KEYBOARDQUEUEWPOS
    SBC KEYBOARDQUEUERPOS
    BEQ KEYBOARDMANAGERDONE2

    JSR KEYBOARDPOP
    STA KEYBOARDACTUAL
    LDA #2
    STA KEYBOARDASFSTATE
    LDA #$FF
    STA KEYBOARDELAPSED
    JMP KEYBOARDMANAGERDONEYES

KEYBOARDMANAGERDONE2:

    ; If no key has been pressed, reset the KEYBOARDACTUAL

    LDA KEYBOARDPRESSED
    BNE SCANCODEFULL23
    LDA #$FF
    STA KEYBOARDACTUAL
SCANCODEFULL23:
KEYBOARDMANAGERDONEYES:

    ; Update the ASF.

    JSR KEYBOARDASF

    ; Restore the used registers.

	PLA
	TAX
	PLA
	TAY
	PLA

	RTS

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

    LDA KEYBOARDACTUAL
    CMP #$FF
    BEQ KEYBOARDDETECTNONE

    SEC

    RTS

KEYBOARDDETECTNONE:
    CLC
    RTS

KEYBOARDELAPSED:     .BYTE 0

@EMIT inputConfig.latency AS KEYBOARDLATENCY
@EMIT inputConfig.delay AS KEYBOARDDELAY
@EMIT inputConfig.release AS KEYBOARDRELEASE

KEYBOARDASFSTATE:    .BYTE 0

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
    LDA KEYBOARDELAPSED
    CMP #KEYBOARDLATENCY
    RTS

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
    LDA KEYBOARDELAPSED
    CMP #KEYBOARDRELEASE
    RTS
    
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
    LDA KEYBOARDELAPSED
    CMP #KEYBOARDDELAY
    RTS

; ----------------------------------------------------------------------------
; KEYBOARDASF
; ----------------------------------------------------------------------------
; This routine will implement the ASF for keyboard. It means that will check
; for events and change the state of the ASF.
;

KEYBOARDASF:

    ; Preserve used registers

    PHA
    TXA
    PHA

    ; Decode the actual state.

    LDX KEYBOARDASFSTATE
    CPX #0
    BEQ KEYBOARDASF0
    DEX
    BEQ KEYBOARDASF1
    DEX
    BEQ KEYBOARDASF2
    DEX
    BEQ KEYBOARDASF3
    JMP KEYBOARDASFDONE

    ; --------------
    ; STATE 0 - FREE
    ; --------------

KEYBOARDASF0:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red)

    JSR KEYBOARDDETECT

    ; If no key has been detected, we can remain
    ; in this state.

    BCC KEYBOARDASFDONE

    ; Move to state 1, and reset the elapsed 
    ; timer at the same time.
    
KEYBOARDASFTO1:

    ; Reset the elapsed timer.

    LDX #0
    STX KEYBOARDELAPSED

    ; Set the state.

    LDX #1
    STX KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

    ; -----------------
    ; STATE 1 - PRESSED
    ; -----------------

KEYBOARDASF1:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red).
    
    JSR KEYBOARDDETECT

    ; If the no key has been pressed, 
    ; we go back to state 0.

    BCC KEYBOARDASFTO0

    ; ; If a different key has been pressed, 
    ; ; we go back to state 0.

    ; BEQ KEYBOARDASFTO0

    ; Chek for latency elapsed.

    JSR KEYBOARDLATENCYELAPSED

    ; If latency has passed, we move to the 
    ; state 2.

    BCS KEYBOARDASFTO2

    ; We remain in state 1.

    JMP KEYBOARDASFDONE

    ; Move to state 0, and reset the elapsed 
    ; timer at the same time.

KEYBOARDASFTO0:

    ; Reset the elapsed timer.

    LDX #0
    STX KEYBOARDELAPSED

    ; Reset the state.

    STX KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

KEYBOARDASFTO2:

    ; Reset the elapsed timer.

    LDX #0
    STX KEYBOARDELAPSED

    ; Set the state.

    LDX #2
    STX KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

    ; -----------------
    ; STATE 2 - PRESSED
    ; -----------------

KEYBOARDASF2:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red).
    
    JSR KEYBOARDDETECT

    ; If the no key has been pressed, 
    ; we go back to state 0.

    BCC KEYBOARDASFTO0

    ; ; If a different key has been pressed, 
    ; ; we go back to state 0.

    ; BEQ KEYBOARDASFTO0

    ; Chek for release elapsed.

    JSR KEYBOARDRELEASEELAPSED

    ; If released has passed, we move to the 
    ; state 3.

    BCS KEYBOARDASFTO3

    ; We remain in state 2.

    JMP KEYBOARDASFDONE

    ; Move to state 3, and reset the elapsed 
    ; timer at the same time.

KEYBOARDASFTO3:

    ; Reset the elapsed timer.

    LDX #0
    STX KEYBOARDELAPSED

    ; Set the next state.

    LDX #3
    STX KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

    ; -------------------
    ; STATE 3 - CONTINUED
    ; -------------------

KEYBOARDASF3:

    ; We just check for detection of a key.
    ; It means both a key pressed (KEYBOARDDETECT green) 
    ; and a different key pressed from the previous
    ; one (KEYBOARDDETECT red).
    
    JSR KEYBOARDDETECT

    ; If the no key has been pressed, 
    ; we go back to state 0.

    BCC KEYBOARDASFTO0

    ; ; If a different key has been pressed, 
    ; ; we go back to state 0.

    ; BEQ KEYBOARDASFTO0

    ; Chek for delay elapsed.

    JSR KEYBOARDDELAYELAPSED

    ; If delay has passed, we move to the 
    ; state 2.

    BCS KEYBOARDASFTO2

    ; We remain in state 3.

    JMP KEYBOARDASFDONE

KEYBOARDASFDONE:

    ; Restore used registers

    PLA
    TAX
    PLA

    RTS

; ----------------------------------------------------------------------------
; WAITKEY
; ----------------------------------------------------------------------------
; This routine will wait for a key press. It means that it will, first, wait
; for the passing FREE(0)->PRESSED(1). Since the keyboard could already have
; a key pressed, we must also wait for FREE(0) state, first.

WAITKEY:
    LDA KEYBOARDASFSTATE
    BEQ WAITKEY1
WAITKEY0:
    LDA KEYBOARDASFSTATE
    BNE WAITKEY0
WAITKEY1:
    LDA KEYBOARDASFSTATE
    BEQ WAITKEY1
    RTS

; ----------------------------------------------------------------------------
; WAITKEYRELEASE
; ----------------------------------------------------------------------------
; This routine will wait for a key press AND for a release. It means that it 
; will, first, WAITKEY. Then, it will wait for a FREE(0) state.

WAITKEYRELEASE:
    JSR WAITKEY
WAITKEYRELEASE0:
    LDA KEYBOARDASFSTATE
    BNE WAITKEYRELEASE0
    RTS

; ----------------------------------------------------------------------------
; KEYSTATE
; ----------------------------------------------------------------------------
; This routine can be called to detect if any key has been pressed. It does
; not disturb the hardware but it will use the memory map, that has been
; refreshed by the last IRQ.
;
; Input:
; - X : key to check
;
; Return values:
; - C : key pressed (1) or not (0)

KEYSTATE:

	LDA #<SCANCODEREAD
	STA TMPPTR
	LDA #>SCANCODEREAD
	STA TMPPTR+1

    TXA
    LSR
    LSR
    LSR
    TAY
    TXA
    AND #$07
    TAX
    LDA BITMASK, X
    AND (TMPPTR), Y
    BEQ KEYSTATEL0
    SEC
    RTS
KEYSTATEL0:
    CLC
    RTS

; ----------------------------------------------------------------------------
; SCANCODE
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the key pressed. It will not disturb
; the hardware, since it will use the KEYBOARDACTUAL value.
;
; Return values:
; - A : KEYBOARDACTUAL

SCANCODE:
    LDA KEYBOARDINKEY
    CMP #$FF
    BNE SCANCODEDONE
    LDA KEYBOARDACTUAL
SCANCODEDONE:
    LDX #$FF
    STX KEYBOARDINKEY
    RTS

; ----------------------------------------------------------------------------
; ASCIICODE
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the key pressed, converted into 
; ASCII code. It will not disturb the hardware, since it will use SCANCODE.
;
; Return values:
; - A : ASCII value

ASCIICODE:
    JSR SCANCODE
    TAY
	LDA #<KEYBOARDMAP
	STA TMPPTR
	LDA #>KEYBOARDMAP
	STA TMPPTR+1
	LDA (TMPPTR),Y
    RTS

KEYBOARDMAP:
	; 		INST/DEL, Return, CRSR =>,  F7,  ' ',  F3,  F5,  CRSR|V
	.BYTE 	     $08,    $0d,     $00, $00,  ' ', $00, $00,     $00
	; 		     #/3,    W,       A,    $/4,   Z,   S,   E,   Left Shift/Shift Lock
	.BYTE        '3',  'W',     'A',    '4', 'Z', 'S', 'E',    $00
	;            %/5,    R,       D,    &/6,   C,   F,   T,      X
	.BYTE        '5',  'R',     'D',    '6', 'C', 'F', 'T',    'X'
	;            '/7,    Y,       G,    (/8,   B,   H,   U,      V
	.BYTE        '7',  'Y',     'G',    '8', 'B', 'H', 'U',    'V'
	;	         )/9,    I,       J,      0,   M,   K,   O,      N
	.BYTE        '9',  'I',     'J',    '0', 'M', 'K', 'O',    'N'
	;              +,    P,       L,      -, >/., [/:, @/<,      ,
	.BYTE        '+',  'P',     'L',    '-', '.', ':', '<',    ','
	;              £,    *,     ]/;,     CH,  RS,  =,    ^,   ?//
	.BYTE        'L',  '*',     ';',    $00, $00, '=', '^',    '/'
	;            !/1,   <-,    CTRL,    "/2, SPC,  C=,   Q, RUN STOP
	.BYTE        '1',  $00,     $00,    '2', ' ', $00, 'Q',    $00
	;           HELP,    8,       5,    TAB,   2,   4,   7,      1
	.BYTE		 $00,  '8',     '5',      9, '2', '4', '7',    '1'
	;            ESC,    +,       -,     LF, CR,    6,   9,      3
	.BYTE         27,  '+',     '-',    $00,$0d,  '6', '9',    '3'
	;            ALT,    0,       .,     UP,DWN, LFT, RGT, NOSCROLL
	.BYTE        $00,  '0',     '.',    $00,$00, $00, $00, $00

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
    LDY KEYBOARDASFSTATE
    CPY #0
    BEQ KEYSINGLE0
    DEY
    BEQ KEYSINGLE1
    DEY
    BEQ KEYSINGLE2
    DEY
    BEQ KEYSINGLE3

KEYSINGLE0:
KEYSINGLE2:
    CLC
    RTS

KEYSINGLE1:
KEYSINGLE3:
    JSR KEYSTATE
    RTS

; ----------------------------------------------------------------------------
; KEYPRESSED
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the pressed key, counting the ASF 
; state. It will return the value only in the duty cycle.
;
; Return values:
; - A : KEYBOARDACTUAL only if KEYBOARDASFSTATE = 1 or 3

KEYPRESSED:
    LDY KEYBOARDASFSTATE
    CPY #0
    BEQ KEYPRESSED0
    DEY
    BEQ KEYPRESSED1
    DEY
    BEQ KEYPRESSED2
    DEY
    BEQ KEYPRESSED3

KEYPRESSED0:
KEYPRESSED2:
    LDA #$FF
    RTS

KEYPRESSED1:
KEYPRESSED3:
    LDA KEYBOARDACTUAL
    RTS

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
    LDX KEYBOARDASFSTATE
    CPX #1
    BEQ WAITKEY02
    CPX #3
    BEQ WAITKEY02
    RTS

INKEY:
    JSR KEYPRESSED
    CMP #$FF
    BEQ INKEY0
    STA KEYBOARDINKEY
    TAY
	LDA #<KEYBOARDMAP
	STA TMPPTR
	LDA #>KEYBOARDMAP
	STA TMPPTR+1
	LDA (TMPPTR),Y
    JSR WAITKEY02
    RTS
INKEY0:
    LDA #0
    RTS

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
    LDA KEYBOARDSHIFT
    RTS

; ----------------------------------------------------------------------------
; CLEAR KEY
; ----------------------------------------------------------------------------
; This routine can be called to clear the keyboard queue.

CLEARKEY:
    LDA #0
    STA KEYBOARDQUEUEWPOS
    STA KEYBOARDQUEUERPOS
    STA KEYBOARDASFSTATE
    STA KEYBOARDELAPSED
    LDA #$FF
    STA KEYBOARDACTUAL
    RTS

; ----------------------------------------------------------------------------
; PUT KEY
; ----------------------------------------------------------------------------
; This routine can be called to put a string into the keyboard queue.
;
; Input:
;      TMPPTR: address of string
;      X: size of the string

PUTKEY:
    LDY #0
    LDA #<KEYBOARDMAP
    STA TMPPTR2
    LDA #>KEYBOARDMAP
    STA TMPPTR2+1
    SEI
PUTKEYL1:
    LDA (TMPPTR), Y
    STA MATHPTR0
    STY MATHPTR1
    LDY #0
PUTKEYL2:    
    LDA (TMPPTR2), Y
    CMP MATHPTR0
    BEQ PUTKEYL2T
    CMP #$FF
    BEQ PUTKEYL2E
    INY
    JMP PUTKEYL2
PUTKEYL2T:
    TXA
    PHA
    TYA
    JSR KEYBOARDPUSH
    PLA
    TAX
    LDY MATHPTR1
    INY
    DEX
    BNE PUTKEYL1
PUTKEYL2E:
    CLI
    RTS
