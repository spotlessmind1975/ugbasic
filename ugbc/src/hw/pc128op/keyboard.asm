; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                          KEYBOARD MANAGEMENT ON PC128OP                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODEREAD
	FCB $00, $00, $00, $00, $00, $00, $00, $00
	FCB $00, $00, $00, $00, $00, $00, $00, $00
SCANCODEREADE

SCANCODETBL
    FCB      $6E, $5E, $4E, $3E, $2E, $1E, $0E
    FCB      $6C, $5C, $4C, $3C, $2C, $1C, $0C, $62
    FCB      $6A, $5A, $4A, $3A, $2A, $1A, $0A
    FCB           $58, $48, $38, $28, $18, $08, $52, $32
    FCB $66, $22, $56, $46, $36, $26, $16, $06
    FCB                     $34, $24, $14, $04, $68, $42
    FCB $80, $60, $50, $64, $54, $44, $00, $10, $20, $30
    FCB $72, $12, $02, $40

    FCB     $FF

KEYBOARDBUFFERRESET
    PSHS X
    PSHS D
    LDX #SCANCODEREAD
    LDB #15
    LDA #$00
KEYBOARDBUFFERRESETL1
    STA , X+
    DECB
    CMPB #$FF
    BNE KEYBOARDBUFFERRESETL1
    PULS D
    PULS X
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

    ALIGN 2, $00
KEYBOARDPRESSED FCB 0
    ALIGN 2, $00
KEYBOARDTEMP FCB 0

KEYBOARDSHIFTPRESSED
    LDA #$03
    ORA KEYBOARDSHIFT
    STA KEYBOARDSHIFT
    JMP SCANCODENEXT2AB

KEYBOARDCTRLPRESSED
    LDA #$08
    ORA KEYBOARDSHIFT
    STA KEYBOARDSHIFT
    JMP SCANCODENEXT2AB

KEYBOARDMANAGER

    PSHS D
    PSHS X
    PSHS Y

    ; JSR KEYBOARDEMPTY
    ; LBCC KEYBOARDMANAGERDONEYES

    ; Reset the key press detector.

    CLR KEYBOARDSHIFT
    CLR KEYBOARDPRESSED
    JSR KEYBOARDBUFFERRESET

    LDX #SCANCODETBL
    ; LDY #SCANCODEREAD

    CLRB
    LDA B, X
SCANCODEL1
    STA BASE_SEGMENT+$C1
    LDA BASE_SEGMENT+$C1
    ANDA #$80
    CMPA #$80
    BEQ SCANCODEL2

    CMPB #$0f
    BEQ KEYBOARDCTRLPRESSED

    CMPB #$36
    BEQ KEYBOARDSHIFTPRESSED

    INC KEYBOARDPRESSED
    STB KEYBOARDACTUAL

    PSHS X
    LDX #BITMASK
    TFR B, A
    ANDA #$07
    LDA A, X
    PULS X
    ORA ,Y
    STA ,Y

SCANCODEL2
SCANCODENEXT2AB
    INCB
    TFR B, A
    ANDA #7
    BNE SCANCODEL22
    LEAY 1, Y
SCANCODEL22
    LDA B, X
    CMPA #$FF
    BNE SCANCODEL1

    LDA KEYBOARDPRESSED
    BNE SCANCODEL22Q
    LDB #$FF
    STB KEYBOARDACTUAL

SCANCODEL22Q
KEYBOARDMANAGERDONEYES
    ; Increase the elapsed timer.

    INC KEYBOARDELAPSED

    ; Update the ASF.

    JSR KEYBOARDASF

    ; Restore the used registers.

    PULS Y
    PULS X
    PULS D
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

KEYBOARDDETECT

    ; Check if any key has been pressed.

    LDA KEYBOARDACTUAL
    CMPA #$FF
    BEQ KEYBOARDDETECTNONE

    ORCC #$01
    RTS

KEYBOARDDETECTNONE
    ANDCC #$FE
    RTS

KEYBOARDELAPSED     FCB 0

@EMIT keyboardConfig.latency AS KEYBOARDLATENCY
@EMIT keyboardConfig.delay AS KEYBOARDDELAY
@EMIT keyboardConfig.release AS KEYBOARDRELEASE

KEYBOARDASFSTATE    FCB 0

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

KEYBOARDLATENCYELAPSED
    LDA KEYBOARDELAPSED
    CMPA #KEYBOARDLATENCY
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

KEYBOARDRELEASEELAPSED
    LDA KEYBOARDELAPSED
    CMPA #KEYBOARDRELEASE
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

KEYBOARDDELAYELAPSED
    LDA KEYBOARDELAPSED
    CMPA #KEYBOARDDELAY
    RTS

; ----------------------------------------------------------------------------
; KEYBOARDASF
; ----------------------------------------------------------------------------
; This routine will implement the ASF for keyboard. It means that will check
; for events and change the state of the ASF.
;

KEYBOARDASF

    ; Preserve used registers

    PSHS X
    PSHS D

    ; Decode the actual state.

    LDA KEYBOARDASFSTATE
    CMPA #0
    BEQ KEYBOARDASF0
    DECA
    BEQ KEYBOARDASF1
    DECA
    BEQ KEYBOARDASF2
    DECA
    BEQ KEYBOARDASF3
    JMP KEYBOARDASFDONE

    ; --------------
    ; STATE 0 - FREE
    ; --------------

KEYBOARDASF0

    ; JSR KEYBOARDEMPTY
    ; BCS KEYBOARDASF0B
    ; JSR KEYBOARDPOP
    ; STB KEYBOARDACTUAL

KEYBOARDASF0B

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
    
KEYBOARDASFTO1

    ; Reset the elapsed timer.

    LDA #0
    STA KEYBOARDELAPSED

    ; Set the state.

    LDA #1
    STA KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

    ; -----------------
    ; STATE 1 - PRESSED
    ; -----------------

KEYBOARDASF1

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

    BCC KEYBOARDASFTO2

    ; We remain in state 1.

    JMP KEYBOARDASFDONE

    ; Move to state 0, and reset the elapsed 
    ; timer at the same time.

KEYBOARDASFTO0

    ; Reset the elapsed timer.

    LDA #0
    STA KEYBOARDELAPSED

    ; Reset the state.

    STA KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

KEYBOARDASFTO2

    ; Reset the elapsed timer.

    LDA #0
    STA KEYBOARDELAPSED

    ; Set the state.

    LDA #2
    STA KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

    ; -----------------
    ; STATE 2 - PRESSED
    ; -----------------

KEYBOARDASF2

    ; JSR KEYBOARDEMPTY
    ; BCS KEYBOARDASF2B
    ; JMP KEYBOARDASFTO0

KEYBOARDASF2B

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

    BCC KEYBOARDASFTO3

    ; We remain in state 2.

    JMP KEYBOARDASFDONE

    ; Move to state 3, and reset the elapsed 
    ; timer at the same time.

KEYBOARDASFTO3

    ; Reset the elapsed timer.

    LDA #0
    STA KEYBOARDELAPSED

    ; Set the next state.

    LDA #3
    STA KEYBOARDASFSTATE

    JMP KEYBOARDASFDONE

    ; -------------------
    ; STATE 3 - CONTINUED
    ; -------------------

KEYBOARDASF3

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

    BCC KEYBOARDASFTO2

    ; We remain in state 3.

    JMP KEYBOARDASFDONE

KEYBOARDASFDONE

    ; Restore used registers

    PULS D
    PULS X

    RTS

; ----------------------------------------------------------------------------
; WAITKEY
; ----------------------------------------------------------------------------
; This routine will wait for a key press. It means that it will, first, wait
; for the passing FREE(0)->PRESSED(1). Since the keyboard could already have
; a key pressed, we must also wait for FREE(0) state, first.

WAITKEY
    LDA KEYBOARDASFSTATE
    BEQ WAITKEY1
WAITKEY0
    LDA KEYBOARDASFSTATE
    BNE WAITKEY0
WAITKEY1
    LDA KEYBOARDASFSTATE
    BEQ WAITKEY1
    RTS

; ----------------------------------------------------------------------------
; WAITKEYRELEASE
; ----------------------------------------------------------------------------
; This routine will wait for a key press AND for a release. It means that it 
; will, first, WAITKEY. Then, it will wait for a FREE(0) state.

WAITKEYRELEASE
    JSR WAITKEY
WAITKEYRELEASE0
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

KEYSTATE
    TFR A, B
    LSRA
    LSRA
    LSRA
	LDX #SCANCODEREAD
    LDA A,X

	LDX #BITMASK
    ANDB #$07
    LDB B, X

    STB <MATHPTR0
    ANDA <MATHPTR0
    BEQ KEYSTATEL0
    
    ORCC #$1
    RTS

KEYSTATEL0
    ANDCC #$FE
    RTS

; ----------------------------------------------------------------------------
; SCANCODE
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the key pressed. It will not disturb
; the hardware, since it will use the KEYBOARDACTUAL value.
;
; Return values:
; - A : KEYBOARDACTUAL

SCANCODE
    LDA KEYBOARDINKEY
    CMPA #$FF
    BEQ SCANCODEB
    RTS
SCANCODEB
    LDA KEYBOARDACTUAL
    RTS

; ----------------------------------------------------------------------------
; ASCIICODE
; ----------------------------------------------------------------------------
; This routine can be called to retrieve the key pressed, converted into 
; ASCII code. It will not disturb the hardware, since it will use SCANCODE.
;
; Return values:
; - A : ASCII value

ASCIICODE
    JSR SCANCODE
ASCIICODEDIR
	LDX #KEYBOARDMAP
    TFR A, B
	LDA B, X
    RTS

KEYBOARDMAP
    FCB     $00,    '1',    '2',     '3',    '4',    '5',    '6',    $00
    FCB     $00,    $00,    '0',     '9',    '8',    '7',    $00,    $00
    FCB     'Q',    'W',    'E',     'R',    'T',    'Y',    $00,    $00
    FCB     'P',    'O',    'I',     'U',    $00,    $00,    $00,    $00
    FCB     'A',    'S',    'D',     'F',    'G',    'H',    'M',    'L'
    FCB     'K',    'J',     13,     $00,    $00,    'Z',    'X',    'C'
    FCB     'V',    'B',    'N',     ',',    '.',    $00,    $88,    $00
    FCB       8,    ' ',    $00,     $00,    $00,    $00,    $00,    $00
KEYBOARDMAP2
    FCB     $00,    '1',    '2',     '3',    '4',    '5',    '6',    $00
    FCB     $00,    $00,    '0',     '9',    '8',    '7',    $00,    $00
    FCB     'q',    'w',    'e',     'r',    't',    'y',    $00,    $00
    FCB     'p',    'o',    'i',     'u',    $00,    $00,    $00,    $00
    FCB     'a',    's',    'd',     'f',    'g',    'h',    'm',    'l'
    FCB     'k',    'j',     13,     $00,    $00,    'z',    'x',    'c'
    FCB     'v',    'b',    'n',     ',',    '.',    $00,    $88,    $00
    FCB       8,    ' ',    $00,     $00,    $00,    $00,    $00,    $00
KEYBOARDMAPE

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

KEYPRESS
    LDA KEYBOARDASFSTATE
    BEQ KEYSINGLE0
    DECA
    BEQ KEYSINGLE1
    DECA
    BEQ KEYSINGLE2
    DECA
    BEQ KEYSINGLE3

KEYSINGLE0
KEYSINGLE2
    ANDCC #$FE
    RTS

KEYSINGLE1
KEYSINGLE3
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

KEYPRESSED
    LDA KEYBOARDASFSTATE
    BEQ KEYPRESSED0
    DECA
    BEQ KEYPRESSED1
    DECA
    BEQ KEYPRESSED2
    DECA
    BEQ KEYPRESSED3

KEYPRESSED0
KEYPRESSED2
    LDA #$FF
    RTS

KEYPRESSED1
KEYPRESSED3
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

WAITKEY02
    PSHS D
WAITKEY02L1
    LDA KEYBOARDASFSTATE
    CMPA #1
    BEQ WAITKEY02L1
    CMPA #3
    BEQ WAITKEY02L1
    PULS D
    RTS

INKEY
    JSR KEYBOARDEMPTY
    BCS INKEYB
    JSR KEYBOARDPOP
    TFR B, A
    JSR ASCIICODEDIR
    RTS
INKEYB
    JSR KEYPRESSED
    CMPA #$FF
    BEQ INKEY0
    STA KEYBOARDINKEY
	LDX #KEYBOARDMAP
    LDB A, X
    TFR B, A
    JSR WAITKEY02
    RTS
INKEY0
    LDA #0
    RTS

KEYBOARDQUEUE           FCB $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
KEYBOARDQUEUERPOS       FCB $00
KEYBOARDQUEUEWPOS       FCB $00
KEYBOARDACTUAL          FCB $00
KEYBOARDINKEY           FCB $FF

    ALIGN 2
KEYBOARDSHIFT           FCB $00

; ----------------------------------------------------------------------------
; PUT KEY
; ----------------------------------------------------------------------------
; This routine can be called to put a string into the keyboard queue.
;
; Input:
;      X: address of string
;      B: size of the string

PUTKEY

PUTKEYL1
    LDA , X
    LDY #KEYBOARDMAP
    PSHS D
    LDU #0
PUTKEYL1A
    CMPA , Y
    BEQ PUTKEYL1T
    LEAY 1, Y
    LEAU 1, U
    CMPY #KEYBOARDMAP2
    BNE PUTKEYL1A
    LDU #0
PUTKEYL1B
    CMPA , Y
    BEQ PUTKEYL1T
    LEAY 1, Y
    LEAU 1, U
    CMPY #KEYBOARDMAPE
    BNE PUTKEYL1B
PUTKEYL2
    PULS D    
    LEAX 1, X
    DECB
    BNE PUTKEYL1
    RTS
PUTKEYL1T
    TFR U, D
    BSR KEYBOARDPUSH
    BRA PUTKEYL2

; ----------------------------------------------------------------------------
; KEYBOARDEMPTY
; ----------------------------------------------------------------------------
; This routine can be called to understand if the keyboard queue is empty.

KEYBOARDEMPTY
    LDA KEYBOARDQUEUEWPOS
    CMPA KEYBOARDQUEUERPOS
    BEQ KEYBOARDEMPTY1
    ANDCC #$FE
    RTS
KEYBOARDEMPTY1
    ORCC #$01
    RTS

; ----------------------------------------------------------------------------
; KEYBOARDPUSH
; ----------------------------------------------------------------------------
; This routine can be called to push a character in front of the keyboard
; queue. This will put the character in the actual KEYBOARDQUEUEWPOS position
; and increment the KEYBOARDQUEUEWPOS by 1. If the KEYBOARDQUEUEWPOS reachs the
; end of the queue, it will return to 0. Moreover, if it is already 
; KEYBOARDQUEUERPOS then nothing will be done, and the character will be lost.
;

KEYBOARDPUSH
    PSHS X
    PSHS D
    LDX #KEYBOARDQUEUE
    LDA KEYBOARDQUEUEWPOS
    STB A, X
    INCA
    CMPA #$0a
    BNE KEYBOARDPUSHDONE
    LDA #0
KEYBOARDPUSHDONE
    STA KEYBOARDQUEUEWPOS
KEYBOARDPUSHLOST
    PULS D
    PULS X
    RTS

; ----------------------------------------------------------------------------
; KEYBOARDPOP
; ----------------------------------------------------------------------------
; This routine can be called to pop a character from the keyboard queue. This 
; will get the character from the actual KEYBOARDQUEUERPOS position
; and increment the KEYBOARDQUEUERPOS by 1. If the KEYBOARDQUEUERPOS reachs the
; end of the queue, it will return to 0. Moreover, if it is already 
; KEYBOARDQUEUEWPOS then nothing will be get and it will be returned a $FF.

KEYBOARDPOP
    LDA KEYBOARDQUEUERPOS
    CMPA KEYBOARDQUEUEWPOS
    BEQ KEYBOARDPOPNONE
    LDX #KEYBOARDQUEUE
    LDB A, X
    INCA
    CMPA #$0A
    BNE KEYBOARDPOPGOT
    LDA #0
KEYBOARDPOPGOT
    STA KEYBOARDQUEUERPOS
    RTS
KEYBOARDPOPNONE
    LDB #$FF
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

KEYSHIFT
    LDA KEYBOARDSHIFT
    RTS

; ----------------------------------------------------------------------------
; CLEAR KEY
; ----------------------------------------------------------------------------
; This routine can be called to clear the keyboard queue.

CLEARKEY
    LDA #0
    STA KEYBOARDQUEUEWPOS
    STA KEYBOARDQUEUERPOS
    STA KEYBOARDASFSTATE
    STA KEYBOARDELAPSED
    LDA #$FF
    STA KEYBOARDACTUAL
    RTS
