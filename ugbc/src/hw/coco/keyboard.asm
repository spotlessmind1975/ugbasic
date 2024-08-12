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
;*                         KEYBOARD MANAGEMENT ON COCO                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODEREAD
	FCB $00, $00, $00, $00, $00, $00, $00, $00
	FCB $00, $00, $00, $00, $00, $00, $00, $00
SCANCODEREADE

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

    ALIGN 2
KEYBOARDPRESSED FCB 0
    ALIGN 2
KEYBOARDTEMP FCB 0

KEYBOARDSHIFTPRESSED
    LDA #$3
    STA KEYBOARDSHIFT
    JMP SCANCODENEXT2AB

KEYBOARDMANAGER

    PSHS D
    PSHS X

    JSR KEYBOARDEMPTY
    LBCC KEYBOARDMANAGERDONEYES

    ; Reset the key press detector.

    CLR KEYBOARDSHIFT
    CLR KEYBOARDPRESSED
    CLR KEYBOARDTEMP

    LDA #$FF
    STA $FF02
    LDX #SCANCODEREAD
    LDA #$FE
SCANCODE0
    STA $FF02
    LDB $FF00
    EORB #$FF
    STB ,X+
    ANDB #$7F
    CMPB #$0
    BEQ SCANCODENEXT

    PSHS D

    TFR B, A
SCANCODENEXT2A
    TFR A, B
    ANDA #1
    CMPA #1
    BNE SCANCODENEXT2

    INC KEYBOARDPRESSED
    LDA KEYBOARDTEMP

    CMPA #$3e
    BEQ KEYBOARDSHIFTPRESSED
    STA KEYBOARDACTUAL 

SCANCODENEXT2AB
    JMP SCANCODENEXT3
SCANCODENEXT2
    TFR B, A
    LSRA
    INC KEYBOARDTEMP
    CMPA #0
    BNE SCANCODENEXT2A

SCANCODENEXT3

    PULS D

SCANCODENEXT
    LDB KEYBOARDTEMP
    ADDB #8
    STB KEYBOARDTEMP

    ORCC #$01
    ROLA
    CMPX #SCANCODEREADE
    BLO SCANCODE0
SCANCODEE

    LDA KEYBOARDPRESSED
    BNE SCANCODEE2
    LDA #$FF
    STA KEYBOARDACTUAL

SCANCODEE2
KEYBOARDMANAGERDONEYES

    ; Increase the elapsed timer.

    INC KEYBOARDELAPSED

    ; Update the ASF.

    JSR KEYBOARDASF

    ; Restore the used registers.

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

@EMIT inputConfig.latency AS KEYBOARDLATENCY
@EMIT inputConfig.delay AS KEYBOARDDELAY
@EMIT inputConfig.release AS KEYBOARDRELEASE

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

    JSR KEYBOARDEMPTY
    BCS KEYBOARDASF0B
    JSR KEYBOARDPOP
    STB KEYBOARDACTUAL

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

    JSR KEYBOARDEMPTY
    BCS KEYBOARDASF2B
    JMP KEYBOARDASFTO0

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
    LSRB
    LSRB
    LSRB
	LDX #SCANCODEREAD
    LDB B,X
    ANDA #$07
    LDX #BITMASK
    LDA A,X
    STA MATHPTR0
    ANDB MATHPTR0
    BNE KEYSTATEL1
    ANDCC #$FE
    RTS

KEYSTATEL1
    ORCC #$01
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
	LDX #KEYBOARDMAP
    TFR A, B
	LDA B, X
    RTS

KEYBOARDMAP
    fcb '@','H','P','X','0','8',$0d,$E3     ; // UNUSED
    fcb 'A','I','Q','Y','1','9',$F9,$E4     ; // CLR, UNUSED
    fcb 'B','J','R','Z','2',':',$D5,$E5     ; // BRK, UNUSED
    fcb 'C','K','S',$FA,'3',';',$D6,$E6     ; // UP $FA, UNUSED, UNUSED
    fcb 'D','L','T',$FB,'4',',',$D7,$E7     ; // DOWN $FB, UNUSED, UNUSED
    fcb 'E','M','U',  8,'5','-',$D8,$E8     ; // ?? $FC, .., LEFT, UNUSED, UNUSED
    fcb 'F','N','V',$FD,'6','.',$D9,$E9     ; // RIGHT $FD, UNUSED, UNUSED
    fcb 'G','O','W',' ','7','/',$F0,$FE     ; // UNUSED, SHIFT
KEYBOARDMAP2
    fcb '@','h','p','x','0','8',$0d,$E3     ; // UNUSED
    fcb 'a','i','q','y','1','9',$F9,$E4     ; // CLR, UNUSED
    fcb 'b','j','r','z','2',':',$D5,$E5     ; // BRK, UNUSED
    fcb 'c','k','s',$FA,'3',';',$D6,$E6     ; // UP $FA, UNUSED, UNUSED
    fcb 'd','l','t',$FB,'4',',',$D7,$E7     ; // DOWN $FB, UNUSED, UNUSED
    fcb 'e','m','u',  8,'5','-',$D8,$E8     ; // ?? $FC, .., LEFT, UNUSED, UNUSED
    fcb 'f','n','v',$FD,'6','.',$D9,$E9     ; // RIGHT $FD, UNUSED, UNUSED
    fcb 'g','o','w',' ','7','/',$F0,$FE     ; // UNUSED, SHIFT
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
KEYBOARDSHIFT           FCB $00
KEYBOARDINKEY           FCB $00

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
