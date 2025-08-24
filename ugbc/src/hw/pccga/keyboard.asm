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
;*                          KEYBOARD MANAGEMENT ON PC IBM                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

KEYBOARDMAP:
    ; 0
    ;       0   1   2   3   4   5   6   7   8   9
    DB      0, 27,'1','2','3','4','5','6','7','8'
    ; 1
    ;       0   1   2   3   4   5   6   7   8   9
    DB    '9','0',  0,  0, 8, 9, 'Q', 'W', 13,'R'
    ; 2
    ;       0   1   2   3   4   5   6   7   8   9
    DB     'T', 'Y', 'U', 'I', 'O', 'P',  0,'+',13, 0
    ; 3
    ;       0   1   2   3   4   5   6   7   8   9
    DB    'A', 'S','D','F','G','H','J','K','L',','
    ; 4
    ;       0   1   2   3   4   5   6   7   8   9
    DB     '8',92,  0,0,'Z','X','C','V', 'B','N'
    ; 5
    ;       0   1   2   3   4   5   6   7   8   9
    DB     'M',',','.', 0,'B','V','4',' ', 0,0
    ; 6
    ;       0   1   2   3   4   5   6   7   8   9
    DB       0,  0,  0,  0,  0,  0, 0,'Q',  9,'A'
    ; 7
    ;       0   1   2   3   4   5   6   7   8   9
    DB      00,  0, 0,  0,  0,  0,  0,  0,  0,  8
    DB     0xFF

KEYBOARDMAP2:
    ; 0
    ;       0   1   2   3   4   5   6   7   8   9
    db      0, 27,'1','2','3','4','5','6','7','8'
    ; 1
    ;       0   1   2   3   4   5   6   7   8   9
    db    '9','0',  0,  0, 8, 9, 'q', 'w', 13,'r'
    ; 2
    ;       0   1   2   3   4   5   6   7   8   9
    db     't', 'y', 'u', 'i', 'o', 'p',  0,'+',13, 0
    ; 3
    ;       0   1   2   3   4   5   6   7   8   9
    db    'a', 's','d','f','g','h','j','k','l',','
    ; 4
    ;       0   1   2   3   4   5   6   7   8   9
    db     '8','\\',  0, 0,'z','x','c','v', 'b','n'
    ; 5
    ;       0   1   2   3   4   5   6   7   8   9
    db     'm',',','.', 0,'b','v','4',' ', 0,0
    ; 6
    ;       0   1   2   3   4   5   6   7   8   9
    db       0,  0,  0,  0,  0,  0, 0,'q',  9,'a'
    ; 7
    ;       0   1   2   3   4   5   6   7   8   9
    db      00,  0, 0,  0,  0,  0,  0,  0,  0,  8
    db     0xff

KEYBOARDSHIFT:          DB 0x00
KEYBOARDPRESSED:        db 0
KEYBOARDACTUAL:         DB 0xff
KEYBOARDINKEY:          DB 0xff
KEYBOARDTIMER:          DW 0x0000

@IF keyboardConfig.sync

    SCANCODERAW:
    SCANCODERAWL1:
        IN AL, 0x64
        TEST AL, 1
        JZ SCANCODERAWNOKEY
        TEST AL, 0x20
        JNZ SCANCODERAWNOKEY
        IN AL, 0x60
        MOV BL, AL
        AND AL, 0x7f
        CMP AL, BL
        JNZ SCANCODERAWNOKEY
        PUSH AX
        MOV AL, 0xff
        MOV [KEYBOARDPRESSED], AL
        MOV DX, [PCCGATIMER]
        MOV [KEYBOARDTIMER], DX
        POP AX
        JMP SCANCODERAWNOKEYSKIP
    SCANCODERAWNOKEY:
        MOV AL, 0
        MOV DX, [PCCGATIMER]
        MOV BX, [KEYBOARDTIMER]
        SUB DX, BX
        CMP DX, 5
        JL SCANCODERAWNOKEYSKIP
        MOV AL, 0
        MOV [KEYBOARDPRESSED], AL
    SCANCODERAWNOKEYSKIP:
        RET

    ; SCANCODESINGLEKEYPRESSEDSHIFT:
    ;     PUSH AF
    ;     LD A, (KEYBOARDSHIFT)
    ;     OR $03
    ;     LD (KEYBOARDSHIFT), A
    ;     POP AF
    ;     JP SCANCODEENTIREL1B

    ; SCANCODESINGLEKEYPRESSEDCTRL:
    ;     PUSH AF
    ;     LD A, (KEYBOARDSHIFT)
    ;     OR $08
    ;     LD (KEYBOARDSHIFT), A
    ;     POP AF
    ;     JP SCANCODEENTIREL1B

    ; SCANCODESINGLEKEYPRESSECAPSLOCK:
    ;     PUSH AF
    ;     LD A, (KEYBOARDSHIFT)
    ;     XOR $04
    ;     LD (KEYBOARDSHIFT), A
    ;     POP AF
    ;     JP SCANCODEENTIREL1B

    ; SCANCODERAW:

    ;     PUSH HL
    ;     PUSH BC
    ;     PUSH DE
    ;     PUSH AF

    ;     LD IXL, 0
    ;     LD A, 0
    ;     LD (KEYBOARDPRESSED), A

    ;     LD HL, SCANCODEREAD
    ;     LD BC, $f782
    ;     OUT (C), C
    ;     LD BC, $f40e
    ;     LD E, B
    ;     OUT (C), C
    ;     LD BC, $f6c0
    ;     LD D, B
    ;     OUT (C), C
    ;     XOR A
    ;     OUT (C), A
    ;     LD BC, $f792
    ;     OUT (C), C
    ;     LD A, $40
    ;     LD C, $4A
    ; SCANCODEENTIREL1:
    ;     LD B, D
    ;     OUT (C), A
    ;     LD B, E
        
    ;     PUSH AF
    ;     IN A, (C)
    ;     XOR $FF
    ;     LD (HL), A
    ;     INC HL

    ;     CP 0
    ;     JR Z, SCANCODESINGLEKEYL1CONTINUE

    ;     PUSH IX

    ; SCANCODEENTIREL1BL1:
    ;     CP 0
    ;     JR Z, SCANCODEENTIREL1B
    ;     SRL A
    ;     JR NC, SCANCODEENTIREL1BL2

    ;     LD A, IXL

    ;     CP 23
    ;     JR Z, SCANCODESINGLEKEYPRESSEDCTRL

    ;     CP $46
    ;     JR Z, SCANCODESINGLEKEYPRESSECAPSLOCK

    ;     LD (KEYBOARDACTUAL), A
    ;     LD A, 1
    ;     LD (KEYBOARDPRESSED), A
    ;     JR SCANCODEENTIREL1B

    ; SCANCODEENTIREL1BL2:
    ;     INC IXL
    ;     JR SCANCODEENTIREL1BL1

    ; SCANCODEENTIREL1B:
    ;     POP IX
    ; SCANCODESINGLEKEYL1CONTINUE:
    ;     POP AF

    ;     INC IXL
    ;     INC IXL
    ;     INC IXL
    ;     INC IXL
    ;     INC IXL
    ;     INC IXL
    ;     INC IXL
    ;     INC IXL

    ;     INC A
    ;     CP C
    ;     JR C, SCANCODEENTIREL1
    ;     LD BC, $f782
    ;     OUT (C), C

    ;     LD A, (KEYBOARDPRESSED)
    ;     CP 1
    ;     JR Z, SCANCODEENTIREL1XX

    ;     LD A, $FF
    ;     LD (KEYBOARDACTUAL), A

    ;     JP SCANCODEDONEYES

    ; SCANCODEENTIREL1XX:
    ;     NOP
    ; SCANCODEDONEYES:

    ;     POP AF
    ;     POP DE
    ;     POP BC
    ;     POP HL

    ;     RET

    ; ----------------------------------------------------------------------------
    ; WAITKEY
    ; ----------------------------------------------------------------------------
    ; This routine will wait for a key press. It means that it will, first, wait
    ; for the passing FREE(0)->PRESSED(1). Since the keyboard could already have
    ; a key pressed, we must also wait for FREE(0) state, first.

    WAITKEY:
        CALL SCANCODERAW
        MOV AL, [KEYBOARDPRESSED]
        CMP AL, 0
        JZ WAITKEY1
    WAITKEY0:
        CALL SCANCODERAW
        MOV AL, [KEYBOARDPRESSED]
        CMP AL, 0
        JNZ WAITKEY0
    WAITKEY1:
        CALL SCANCODERAW
        MOV AL, [KEYBOARDPRESSED]
        CMP AL, 0
        JZ WAITKEY1
        RET

    ; ----------------------------------------------------------------------------
    ; WAITKEYRELEASE
    ; ----------------------------------------------------------------------------
    ; This routine will wait for a key press AND for a release. It means that it 
    ; will, first, WAITKEY. Then, it will wait for a FREE(0) state.

    WAITKEYRELEASE:
        CALL WAITKEY
    WAITKEYRELEASE0:
        CALL SCANCODERAW
        MOV AL, [KEYBOARDPRESSED]
        CMP AL, 0
        JNZ WAITKEYRELEASE0
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
        CLC
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
        MOV AL, [KEYBOARDINKEY]
        CMP AL, 0xFF
        JZ SCANCODE0
        RET
    SCANCODE0:
        CALL SCANCODERAW
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
        CMP AL, 0xff
        JNZ ASCIICODEDIR
        MOV AL, 0
        RET
    ASCIICODEDIR:
        MOV SI, KEYBOARDMAP 
        MOV BL, AL
        MOV BH, 0
        MOV AL, [SI+BX]
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
        CLC
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
        MOV BL, AL
        CALL SCANCODERAW
        CMP AL, BL
        JNZ KEYPRESSED0
        MOV AL, 0xff
        RET
    KEYPRESSED0:
        MOV AL, 0x00
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
        PUSH AX
    WAITKEY02L:
        CALL SCANCODERAW
        MOV BL, [KEYBOARDPRESSED]
        CMP BL, 0
        JNZ WAITKEY02L
        POP AX
        RET

    INKEY:
        CALL SCANCODERAW
        MOV BL, [KEYBOARDPRESSED]
        CMP BL, 0
        JZ INKEY0
        MOV [KEYBOARDINKEY], AL
        ; MOV AL, [KEYBOARDSHIFT]
        ; AND $04
        ; CP $04
        ; JZ INKEYUP
        ; MOV SI, KEYBOARDMAP2
        ; JR INKEYCOMMON
    INKEYUP:
        MOV SI, KEYBOARDMAP
    INKEYCOMMON:
        MOV BL, [KEYBOARDINKEY]
        MOV BH, 0
        MOV AL, [SI+BX]
        CALL WAITKEY02
        MOV BL, 0xff
        RET
    INKEY0:
        MOV BL, 0
        MOV AL, 0
        RET

        ; ; ----------------------------------------------------------------------------
        ; ; KEY SHIFT
        ; ; ----------------------------------------------------------------------------
        ; ; This routine can be called to retrieve the status of key / control buttons.
        ; ;
        ; ; Return values:
        ; ; - A : bitmap of key pressed
        ; ;           0	Left SHIFT
        ; ;           1	Right SHIFT
        ; ;           2	CAPS LOCK
        ; ;           3	CONTROL
        ; ;           4	Left ALT
        ; ;           5	Right ALT

        ; KEYSHIFT:
        ;     CALL SCANCODERAW
        ;     LD A, (KEYBOARDSHIFT)
        ;     RET

        ; ; ----------------------------------------------------------------------------
        ; ; CLEAR KEY
        ; ; ----------------------------------------------------------------------------
        ; ; This routine can be called to clear the keyboard queue.

        ; CLEARKEY:
        ;     RET

        ; ; ----------------------------------------------------------------------------
        ; ; PUT KEY
        ; ; ----------------------------------------------------------------------------
        ; ; This routine can be called to put a string into the keyboard queue.
        ; ;
        ; ; Input:
        ; ;      HL: address of string
        ; ;      C: size of the string

        ; PUTKEY:
        ;     RET

        ; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ELSE

    SCANCODEREAD:
        DB $00, $00, $00, $00, $00, $00, $00, $00
        DB $00, $00, $00, $00, $00, $00, $00, $00
    SCANCODEREADE:
        DB $00, $00, $00, $00, $00, $00, $00, $00
        DB $00, $00, $00, $00, $00, $00, $00, $00

    KEYBOARDBUFFER:     db 0

    ; KEYBOARDQUEUE:          DS 10,$FF
    ; KEYBOARDQUEUERPOS:      DB $00
    ; KEYBOARDQUEUEWPOS:      DB $00

    ; KEYBOARDTEMP:           DB $00

    ;     ; ----------------------------------------------------------------------------
    ;     ; KEYBOARDEMPTY
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine can be called to understand if the keyboard queue is empty.

    ;     KEYBOARDEMPTY:
    ;         PUSH AF
    ;         PUSH BC
    ;         LD A, (KEYBOARDQUEUEWPOS)
    ;         LD B, A
    ;         LD A, (KEYBOARDQUEUERPOS)
    ;         CP B
    ;         JR Z, KEYBOARDEMPTY1
    ;         POP BC
    ;         POP AF
    ;         SCF
    ;         CCF
    ;         RET
    ;     KEYBOARDEMPTY1:
    ;         POP BC
    ;         POP AF
    ;         SCF
    ;         RET

    ;     ; ----------------------------------------------------------------------------
    ;     ; KEYBOARDPUSH
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine can be called to push a character in front of the keyboard
    ;     ; queue. This will put the character in the actual KEYBOARDQUEUEWPOS position
    ;     ; and increment the KEYBOARDQUEUEWPOS by 1. If the KEYBOARDQUEUEWPOS reachs the
    ;     ; end of the queue, it will return to 0. Moreover, if it is already 
    ;     ; KEYBOARDQUEUERPOS then nothing will be done, and the character will be lost.
    ;     ;

    ;     KEYBOARDPUSH:
    ;         PUSH HL
    ;         PUSH DE
    ;         PUSH AF
    ;         LD A,  (KEYBOARDQUEUEWPOS)
    ;         LD E, A
    ;         LD D, 0
    ;         LD HL, KEYBOARDQUEUE
    ;         ADD HL, DE
    ;         POP AF
    ;         LD (HL), A
    ;         LD A,  (KEYBOARDQUEUEWPOS)
    ;         ADD 1
    ;         CP $0A
    ;         JR NZ, KEYBOARDPUSHDONE
    ;         LD A, 0
    ;     KEYBOARDPUSHDONE:
    ;         LD (KEYBOARDQUEUEWPOS), A
    ;     KEYBOARDPUSHLOST:
    ;         POP DE
    ;         POP HL
    ;         RET

    ;     ; ----------------------------------------------------------------------------
    ;     ; KEYBOARDPOP
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine can be called to pop a character from the keyboard queue. This 
    ;     ; will get the character from the actual KEYBOARDQUEUERPOS position
    ;     ; and increment the KEYBOARDQUEUERPOS by 1. If the KEYBOARDQUEUERPOS reachs the
    ;     ; end of the queue, it will return to 0. Moreover, if it is already 
    ;     ; KEYBOARDQUEUEWPOS then nothing will be get and it will be returned a $FF.

    ;     KEYBOARDPOP:
    ;         PUSH HL
    ;         PUSH DE
    ;         PUSH BC
    ;         LD A, (KEYBOARDQUEUEWPOS) 
    ;         LD B, A
    ;         LD A, (KEYBOARDQUEUERPOS) 
    ;         CP B
    ;         JR Z, KEYBOARDPOPNONE
    ;         LD E, A
    ;         LD D, 0
    ;         LD HL, KEYBOARDQUEUE
    ;         ADD HL, DE
    ;         LD A, (HL)
    ;         PUSH AF
    ;         LD A, (KEYBOARDQUEUERPOS)
    ;         ADD 1
    ;         CP $0A
    ;         JR NZ, KEYBOARDPOPGOT
    ;         LD A, 0
    ;     KEYBOARDPOPGOT:
    ;         LD (KEYBOARDQUEUERPOS), A
    ;         POP AF
    ;         POP BC
    ;         POP DE
    ;         POP HL
    ;         RET
    ;     KEYBOARDPOPNONE:
    ;         LD A, $FF
    ;         POP BC
    ;         POP DE
    ;         POP HL
    ;         RET

    ;     ; ----------------------------------------------------------------------------
    ;     ; KEYBOARDMANAGER
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine will be called during IRQ, and it will take some actions.
    ;     ; First of all, the KEYBOARDACTUAL will be put to $FF (no key pressed).
    ;     ; Then, hardware keyboard matrix will be decoded and stored it into the
    ;     ; memory locations. If any key is pressed, it will be decoded and put into
    ;     ; KEYBOARDACTUAL. Finally, the elapsed timer will be increased. Moreover,
    ;     ; the ASF will be moved one step forward.

    ;     ; This routine will decode the actual key.
    ;     ;   Input: A - bitmap of key pressed
    ;     ;          X - starting value of key pressed
    ;     ;   Ouput: -
    ;     ;   Changes: KEYBOARDACTUAL, KEYBOARDASFSTATE

    ;     KEYBOARDMANAGERSINGLEKEYPRESSEDSHIFT:
    ;         PUSH AF
    ;         LD A, (KEYBOARDSHIFT)
    ;         OR $03
    ;         LD (KEYBOARDSHIFT), A
    ;         POP AF
    ;         JP SCANCODEENTIREL1B

    ;     KEYBOARDMANAGERSINGLEKEYPRESSEDCTRL:
    ;         PUSH AF
    ;         LD A, (KEYBOARDSHIFT)
    ;         OR $08
    ;         LD (KEYBOARDSHIFT), A
    ;         POP AF
    ;         JP SCANCODEENTIREL1B

    ;     KEYBOARDMANAGERSINGLEKEYPRESSECAPSLOCK:
    ;         PUSH AF
    ;         LD A, (KEYBOARDSHIFT)
    ;         XOR $04
    ;         LD (KEYBOARDSHIFT), A
    ;         POP AF
    ;         JP SCANCODEENTIREL1B

    ;   AL = rawcode (0x00..0xff)
    ;   AH = make (0) or break (1)
    ;   BL = scancode (0x00..0x7f); BX = offset inside SCANCODE table
    ;   CL = (spare)
    ;   CH = (spare)

    KEYBOARDMANAGER:
        PUSH AX
        PUSH BX
        PUSH CX

        MOV AL, 0xff
        MOV [KEYBOARDACTUAL], AL
        
        ; rawcode = inp(0x60); /* read scancode from keyboard controller */
        IN AL, 0x60
        MOV BL, AL
        ; make_break = !(rawcode & 0x80); /* bit 7: 0 = make, 1 = break */
        MOV AH, AL
        AND AH, 0x80
        XOR AH, 0xff

        ; scancode = rawcode & 0x7F;
        AND BL, 0x7f
        MOV BH, 0

        MOV CL, [KEYBOARDBUFFER]
        ; if (buffer == 0xE0) { /* second byte of an extended key */
        CMP CL, 0x0e
        JNE KEYBOARDMANAGERJ1

        ;     if (scancode < 0x60) {
        CMP AL, 0x60
        JA KEYBOARDMANAGERJ1B

        MOV [KEYBOARDACTUAL], BL
        
        MOV CL, BL
        SAR BL, 1
        SAR BL, 1
        SAR BL, 1
        MOV CH, [SCANCODEREADE+BX]
        PUSH BX
        MOV BL, CL
        AND BL, 0x07

        CMP AH, 0x00
        JZ KEYBOARDMANAGERJ1BSPACE

        MOV CL, [BITMASK+BX]
        OR CH, CL
        
        PUSH AX
        MOV AL, 0xff
        MOV [KEYBOARDPRESSED], AL
        POP AX

        JMP KEYBOARDMANAGERJ1BDONE

    KEYBOARDMANAGERJ1BSPACE:
        MOV CL, [BITMASKN+BX]
        AND CH, CL

        PUSH AX
        MOV AL, 0x00
        MOV [KEYBOARDPRESSED], AL
        POP AX

    KEYBOARDMANAGERJ1BDONE:
        POP BX
        MOV [SCANCODEREADE+BX], CH

        ;         extended_keys[scancode] = make_break;
        ;     }

    KEYBOARDMANAGERJ1B:
        ;     buffer = 0;
        MOV AL, 0
        MOV [KEYBOARDBUFFER], AL
        JMP KEYBOARDMANAGERJ4

    KEYBOARDMANAGERJ1:
        ; } else if (buffer >= 0xE1 && buffer <= 0xE2) {
        CMP CL, 0xe1
        JB KEYBOARDMANAGERJ2
        CMP CL, 0x0e2
        JA KEYBOARDMANAGERJ2

        ;     buffer = 0; /* ingore these extended keys */
        MOV AL, 0
        MOV [KEYBOARDBUFFER], AL
        JMP KEYBOARDMANAGERJ4

    KEYBOARDMANAGERJ2:
        ; } else if (rawcode >= 0xE0 && rawcode <= 0xE2) {
        CMP AH, 0xe0
        JB KEYBOARDMANAGERJ3
        CMP AH, 0x0e2
        JA KEYBOARDMANAGERJ3

            ; buffer = rawcode; /* first byte of an extended key */
        MOV [KEYBOARDBUFFER], AL
        JMP KEYBOARDMANAGERJ4

    KEYBOARDMANAGERJ3:
        ; } else if (scancode < 0x60) {
        CMP AL, 0x60
        JA KEYBOARDMANAGERJ4

            ; normal_keys[scancode] = make_break;

        MOV [KEYBOARDACTUAL], BL
        
        MOV CL, BL
        SAR BL, 1
        SAR BL, 1
        SAR BL, 1
        MOV CH, [SCANCODEREAD+BX]
        PUSH BX
        MOV BL, CL
        AND BL, 0x07

        CMP AH, 0x00
        JZ KEYBOARDMANAGERJ3BSPACE

        MOV CL, [BITMASK+BX]
        OR CH, CL

        PUSH AX
        MOV AL, 0xff
        MOV [KEYBOARDPRESSED], AL
        POP AX

        JMP KEYBOARDMANAGERJ3BDONE

    KEYBOARDMANAGERJ3BSPACE:
        MOV CL, [BITMASKN+BX]
        AND CH, CL

        PUSH AX
        MOV AL, 0x00
        MOV [KEYBOARDPRESSED], AL
        POP AX

    KEYBOARDMANAGERJ3BDONE:
        POP BX
        MOV [SCANCODEREAD+BX], CH

        ; }

    KEYBOARDMANAGERJ4:

        MOV AL, [KEYBOARDELAPSED]
        INC AL
        MOV [KEYBOARDELAPSED], AL

        ; Update the ASF.

        CALL KEYBOARDASF

        MOV AL, 0x20
        OUT 0x20, AL

        POP CX
        POP BX
        POP AX
        ; JMP FAR [KEYBOARDIRQSAVED]
        IRET

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

            MOV AL, [KEYBOARDACTUAL]
            CMP AL, 0xFF
            JZ KEYBOARDDETECTNONE

            STC

            RET

        KEYBOARDDETECTNONE:
            CLC
            RET

    KEYBOARDELAPSED:     db 0

    @EMIT keyboardConfig.latency AS KEYBOARDLATENCY
    @EMIT keyboardConfig.delay AS KEYBOARDDELAY
    @EMIT keyboardConfig.release AS KEYBOARDRELEASE

    KEYBOARDASFSTATE:    db 0

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
            MOV AL, [KEYBOARDELAPSED]
            CMP AL, KEYBOARDLATENCY
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
            MOV AL, [KEYBOARDELAPSED]
            CMP AL, KEYBOARDRELEASE
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
            MOV AL, [KEYBOARDELAPSED]
            CMP AL, KEYBOARDDELAY
            RET

        ; ----------------------------------------------------------------------------
        ; KEYBOARDASF
        ; ----------------------------------------------------------------------------
        ; This routine will implement the ASF for keyboard. It means that will check
        ; for events and change the state of the ASF.
        ;

        KEYBOARDASF:

            ; Preserve used registers

            PUSH AX
            PUSH BX
            PUSH CX

            ; Decode the actual state.

            MOV Al, [KEYBOARDASFSTATE]
            
            CMP AL, 0
            JZ KEYBOARDASF0
            MOV BL, AL
            DEC BL
            JZ KEYBOARDASF1
            DEC BL
            JZ KEYBOARDASF2
            DEC BL
            JZ KEYBOARDASF3
            JMP KEYBOARDASFDONE

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

            JNC KEYBOARDASFDONE

            ; Move to state 1, and reset the elapsed 
            ; timer at the same time.
            
        KEYBOARDASFTO1:

            ; Reset the elapsed timer.

            MOV AL, 0
            MOV [KEYBOARDELAPSED], AL

            ; Set the state.

            MOV Al, 1
            MOV [KEYBOARDASFSTATE], AL

            JMP KEYBOARDASFDONE

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

            JNC KEYBOARDASFTO0

            ; ; If a different key has been pressed, 
            ; ; we go back to state 0.

            ; BEQ KEYBOARDASFTO0

            ; Chek for latency elapsed.

            CALL KEYBOARDLATENCYELAPSED

            ; If latency has passed, we move to the 
            ; state 2.

            JNC KEYBOARDASFTO2

            ; We remain in state 1.

            JMP KEYBOARDASFDONE

            ; Move to state 0, and reset the elapsed 
            ; timer at the same time.

        KEYBOARDASFTO0:

            ; Reset the elapsed timer.

            MOV AL, 0
            MOV [KEYBOARDELAPSED], AL

            ; Reset the state.

            MOV [KEYBOARDASFSTATE], AL

            JMP KEYBOARDASFDONE

        KEYBOARDASFTO2:

            ; Reset the elapsed timer.

            MOV AL, 0x00
            MOV [KEYBOARDELAPSED], AL

            ; Set the state.

            MOV Al, 2
            MOV [KEYBOARDASFSTATE], AL

            JMP KEYBOARDASFDONE

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

            JNC KEYBOARDASFTO0

            ; ; If a different key has been pressed, 
            ; ; we go back to state 0.

            ; BEQ KEYBOARDASFTO0

            ; Chek for release elapsed.

            CALL KEYBOARDRELEASEELAPSED

            ; If released has passed, we move to the 
            ; state 3.

            JNC KEYBOARDASFTO3

            ; We remain in state 2.

            JMP KEYBOARDASFDONE

            ; Move to state 3, and reset the elapsed 
            ; timer at the same time.

        KEYBOARDASFTO3:

            ; Reset the elapsed timer.

            MOV AL, 0
            MOV [KEYBOARDELAPSED], AL

            ; Set the next state.

            MOV AL, 3
            MOV [KEYBOARDASFSTATE], AL

            JMP KEYBOARDASFDONE

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

            JNC KEYBOARDASFTO0

            ; ; If a different key has been pressed, 
            ; ; we go back to state 0.

            ; BEQ KEYBOARDASFTO0

            ; Chek for delay elapsed.

            CALL KEYBOARDDELAYELAPSED

            ; If delay has passed, we move to the 
            ; state 2.

            JNC KEYBOARDASFTO2

            ; We remain in state 3.

            JMP KEYBOARDASFDONE

        KEYBOARDASFDONE:

            ; Restore used registers

            POP CX
            POP BX
            POP AX
            
            RET

    ;     ; ----------------------------------------------------------------------------
    ;     ; WAITKEY
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine will wait for a key press. It means that it will, first, wait
    ;     ; for the passing FREE(0)->PRESSED(1). Since the keyboard could already have
    ;     ; a key pressed, we must also wait for FREE(0) state, first.

        WAITKEY:
            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 0
            JZ WAITKEY1
        WAITKEY0:
            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 0
            JNZ WAITKEY0
        WAITKEY1:
            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 0
            JZ WAITKEY1
            RET

        ; ----------------------------------------------------------------------------
        ; WAITKEYRELEASE
        ; ----------------------------------------------------------------------------
        ; This routine will wait for a key press AND for a release. It means that it 
        ; will, first, WAITKEY. Then, it will wait for a FREE(0) state.

        WAITKEYRELEASE:
            CALL WAITKEY
        WAITKEYRELEASE0:
            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 0
            JNZ WAITKEYRELEASE0
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

            MOV DI, SCANCODEREAD 
            MOV SI, BITMASK

            MOV BL, AL
            SAR BL, 1
            SAR BL, 1
            SAR BL, 1
            MOV BH, 0
            MOV CL, [DI+BX]

            AND AL, 0x07
            MOV BL, AL

            MOV CH, [SI+BX]
            AND CL, CH
            CMP CL, CH
            JE KEYSTATEL1Y
            CLC
            RET
        KEYSTATEL1Y:
            STC
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
            MOV AL, [KEYBOARDINKEY]
            CMP AL, 0xff
            JZ SCANCODE0
            RET
        SCANCODE0:
            MOV AL, [KEYBOARDACTUAL]
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
            CMP AL, 0xff
            JZ ASCIICODEDIR
            MOV AL, 0
            RET
        ASCIICODEDIR:
            MOV DI, [KEYBOARDMAP]
            MOV BL, AL
            MOV BH, 0
            MOV AL, [DI+BX]
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

            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 0
            JZ KEYSINGLE0
            MOV BL, AL
            DEC BL
            JZ KEYSINGLE1
            DEC BL
            JZ KEYSINGLE2
            DEC BL
            JZ KEYSINGLE3
            JMP KEYBOARDASFDONE

        KEYSINGLE0:
        KEYSINGLE2:
            CLC
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
            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 0
            JZ KEYPRESSED0
            MOV BL, AL
            DEC BL
            JZ KEYPRESSED1
            DEC BL
            JZ KEYPRESSED2
            DEC BL
            JZ KEYPRESSED3
            RET

        KEYPRESSED0:
        KEYPRESSED2:
            MOV AL, 0xff
            RET

        KEYPRESSED1:
        KEYPRESSED3:
            MOV AL, [KEYBOARDACTUAL]
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
            PUSH AX
        WAITKEY02L:
            MOV AL, [KEYBOARDASFSTATE]
            CMP AL, 1
            JZ WAITKEY02L
            CMP AL, 3
            JZ WAITKEY02L
            POP AX
            RET

        INKEY:
            ; CALL KEYBOARDEMPTY
            ; JC INKEYB
            ; CALL KEYBOARDPOP
            ; CALL ASCIICODEDIR
            ; RET
        INKEYB:
            CALL KEYPRESSED
            CMP AL, 0xff
            JZ INKEY0
            MOV [KEYBOARDINKEY], AL
            MOV AL, [KEYBOARDSHIFT]
            AND AL, 0x04
            CMP AL, 0x04
            JZ INKEYUP
            MOV DI, KEYBOARDMAP2
            JMP INKEYCOMMON
        INKEYUP:
            MOV DI, KEYBOARDMAP
        INKEYCOMMON:
            MOV AL, [KEYBOARDINKEY]
            MOV BL, AL
            MOV BH, 0
            MOV AL, [DI+BX]
            CALL WAITKEY02
            MOV BL, 0xff
            RET
        INKEY0:
            MOV BL, 0
            MOV AL, 0
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
            MOV AL, [KEYBOARDSHIFT]
            RET

    ;     ; ----------------------------------------------------------------------------
    ;     ; CLEAR KEY
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine can be called to clear the keyboard queue.

    ;     CLEARKEY:
    ;         LD A, 0
    ;         LD (KEYBOARDQUEUEWPOS), A
    ;         LD (KEYBOARDQUEUERPOS), A
    ;         LD (KEYBOARDASFSTATE), A
    ;         LD (KEYBOARDELAPSED), A
    ;         LD A, $FF
    ;         LD (KEYBOARDACTUAL), A
    ;         RET

    ;     ; ----------------------------------------------------------------------------
    ;     ; PUT KEY
    ;     ; ----------------------------------------------------------------------------
    ;     ; This routine can be called to put a string into the keyboard queue.
    ;     ;
    ;     ; Input:
    ;     ;      HL: address of string
    ;     ;      C: size of the string

    ;     PUTKEY:
    ;         PUSH HL
    ;         PUSH DE
    ;         DI
    ;     PUTKEYL1:
    ;         PUSH BC
    ;         LD C, 0
    ;         LD A, (HL)
    ;         LD DE, KEYBOARDMAP
    ;         LD B, A
    ;     PUTKEYL2:
    ;         LD A, (DE)
    ;         CP B
    ;         JR Z, PUTKEYL2T
    ;         CP $FF
    ;         JR Z, PUTKEYL2E
    ;         INC DE
    ;         INC C
    ;         JP PUTKEYL2
    ;     PUTKEYL2E:
    ;         LD DE, KEYBOARDMAP2
    ;         LD C, 0
    ;     PUTKEYL2EL1:    
    ;         LD A, (DE)
    ;         CP B
    ;         JR Z, PUTKEYL2T
    ;         CP $FF
    ;         JR Z, PUTKEYL2E2
    ;         INC DE
    ;         INC C
    ;         JP PUTKEYL2EL1
    ;     PUTKEYL2T:
    ;         LD A, C
    ;         CALL KEYBOARDPUSH
    ;         POP BC
    ;         DEC C
    ;         INC HL
    ;         JR NZ, PUTKEYL1
    ;     PUTKEYL2E2:
    ;         POP DE
    ;         POP HL
    ;         EI
    ;         RET

@ENDIF