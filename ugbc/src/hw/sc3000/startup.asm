; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                         STARTUP ROUTINE FOR SC-3000                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

vdp_control      	= $BF
psg_port         	= $7F
sc_ppi_a         	= $DC
sc_ppi_b         	= $DD
sc_ppi_c         	= $DE
sc_ppi_control   	= $DF

INITIAL_STACK    	= $C400

PPI_Setting         = 0x92
PPI_PortC           = 0xDE
PPI_Control         = 0xDF
JOY_PortA           = 0xDC
JOY_PortB           = 0xDD

KEYB_Detected       = 0x00
KEYB_NotDetected    = 0xFF

	DI
	JP COLD_RESET

; We leave 10 unused bytes free.
; In the original BIOS they were 
; the vdp set reg routine.

	DEFS 10

; source: https://www.msx.org/forum/development/msx-development/how-0?page=0
; returns 1 in a and clears z flag if vdp is 60Hz
; size: 27 bytes
CheckIf60Hz:
		in      a,(vdp_control)
		nop
		nop
		nop
vdpSync:
		in      a,(vdp_control)
		and     $80
		jr      z,vdpSync
		
		ld      hl,$900
vdpLoop:
		dec     hl
		ld      a,h
		or      l
		jr      nz,vdpLoop
		
		in      a,(vdp_control)
		rlca
		and     1
		ret

; We leave 17 unused bytes free.
; In the original BIOS they were 
; the vdp init routine.

	DEFS 17

; This jump starts as $0038
		jp		INT_HANDLER2
	
	DEFS 5

; This label starts as $0040
COLD_RESET:
		im		1
	;*** RESET PSG (silence all channels)
		ld		b, 5
COLD_RESET1:
		ld		a,$9F
		out		(psg_port),a
		ld		a,$BF
		out		(psg_port),a
		ld 		a,$DF
		out		(psg_port),a
		ld		a,$FF
		out		(psg_port),a
		djnz	COLD_RESET1

		in     	a,(vdp_control)
		in     	a,(vdp_control)
		jp		RAM_TEST

		DEFS 9

; This label starts as $0066
		jp		NMI_HANDLER2

		DEFS 7

RAM_TEST:
		ld		sp, INITIAL_STACK

		ld		hl, $55aa
    	push	hl
    	pop		de
    	or		a
    	sbc		hl,de
    	jp		nz, error_beep_2			; Error: Z80/RAM failure


		; call	VDP_INIT
		
KEYB_INIT_AND_TEST:
		ld		a, $92					; Init PPI (if present). PortC = Ouput, PortA + PortB = Input		
		out		(sc_ppi_control),a			

		call	ppi_pause

		xor		a
		ld		(PPIKEYBOARD),a			; default value, 0 = keyboard absent

		ld		a,$55
		call	ppi_test
		ld		c, a
		ld		a,$AA
		call	ppi_test
	
		or		c							; merge the two attempts
		cpl									; invert it
		and		1
		ld		(PPIKEYBOARD),a			; save it, $01 = keyboard present, $00 keyboard absent (SG-1000)

		ld		a, 7						; Set row 7 (joypad) as default
		out		(sc_ppi_c), a

		jp CODESTART

; b = test value
;---------------------------------------
ppi_test:
;---------------------------------------
		ld		b, a
		out		(sc_ppi_c),a
		call	ppi_pause
		in		a,(sc_ppi_c)
		cp		b
		ld		a, $00						; "xor a" cannot be used. Zero Flag must be intact.
		jr		z, ppi_test_noerr
		dec		a								; c = $FF if not detected
ppi_test_noerr:
		ret
ppi_pause:
		nop
		nop
		ret


;---------------------------------------
error_beep_1:
;---------------------------------------
		ld     e,$01
		jr     error_beep

;---------------------------------------
error_beep_2:
;---------------------------------------
		ld     e,$02
		jr     error_beep

;---------------------------------------
error_beep_3:
;---------------------------------------
		ld     e,$03

    ; fall through


; inputs: e = beep count
; never returns
; beeps are of the approximate form (eg. e=2)
; -__-__________________-__-__________________-__-___________
; 0s            1s            2s             3s            4s
; where 1 char is ~70ms, the beep section is variable length but the long pauses arent

;---------------------------------------
error_beep:
;---------------------------------------
    ld     d,e                                   ; e -> d

error_beep_loop:

;===== SOUND ============
		ld     a,0b10001111		; PSG: ch 0 frequency = %0000111111 = 1775.57Hz
		out    (psg_port),a
		ld     a,0b00000011
		out    (psg_port),a			; PSG: ch 0 volume = 0 = full
		ld     a,0b10010000
		out    (psg_port),a

		ld     b,$3e				; sound for 249924 cycles = 69.8ms
error_beep_loop1: 	
		ld     c,$fb
error_beep_loop2: 	
		dec    c
		jr     nz, error_beep_loop2
		djnz   error_beep_loop1


;===== SHORT SILENCE =====
		ld     a,0b10011111
		out    (psg_port),a

		ld     b,$7d				; silence for 503877 cycles = 141ms
error_beep_loop3: 	
		ld     c,$fb
error_beep_loop4:
		dec    c
		jr     	nz, error_beep_loop4
		djnz	error_beep_loop3

		dec    d					; repeat d times
		jp     nz,error_beep_loop

;===== LONG SILENCE ======
		ld     hl,$03e8			; wait 4044005 cycles = 1130ms
error_beep_loop5: 	
		ld     c,$fb
error_beep_loop6: 	
		dec    c
		jr     nz, error_beep_loop6
		dec    hl
		ld     a,h
		or     l
		jr     nz, error_beep_loop5
		jp     error_beep			; loop forever

INT_HANDLER2:
	PUSH	AF
	PUSH	BC
	PUSH	DE
	PUSH	HL
	PUSH	IX
	PUSH	IY
	EX	AF,AF'
	PUSH	AF
	EXX
	PUSH	BC
	PUSH	DE
	PUSH	HL
    LD HL,(SC3000TIMER)
    INC HL
    LD (SC3000TIMER),HL
	LD A, (IRQVECTORREADY)
	CMP 0
	JR Z, IRQVECTORSKIP
    CALL IRQVECTOR
IRQVECTORSKIP:
    CALL MUSICPLAYER
	CALL KBIRQ
	IN A, (vdp_control)
	POP	HL
	POP	DE
	POP	BC
	EXX
	POP	AF
	EX	AF,AF'
	POP	IY
	POP	IX
	POP	HL
	POP	DE
	POP	BC
	POP	AF
	EI
	RETI

NMI_HANDLER2:
	RETN
	
IRQVOID:
    RET

SC3000STARTUP:
    LD DE, IRQVOID
    LD HL, IRQVECTOR
    LD A, $c3
    LD (HL), A
    INC HL
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
	LD A, 1
	LD (IRQVECTORREADY), A

	LD HL, UDCCHAR
	LD BC, 2048
    LD DE, 0
    CALL VDPWRITE

	XOR A
	LD	(KEYBOARD_LAST_CHAR), A
	LD	(KEYBOARD_LAST_CHAR+1), A
	LD	(KEYBOARD_INT_COUNTER), A		
	INC	A
	LD	(KEYBOARD_TYPEMATIC_CNT), A

	LD	HL, KEYBD_BUFFER
	LD	(KEYBD_PUTPNT), HL
	LD	(KEYBD_GETPNT), HL

    CALL CheckIf60Hz
    JR Z, SC3000NTSC

SC3000PAL:
    LDA #60
    STA TICKSPERSECOND
    JMP SC3000STARTUPDONE

SC3000NTSC:
    LDA #50
    STA TICKSPERSECOND
    JMP SC3000STARTUPDONE    

	RET
	
KEYB_READ_MATRIX:
	IN A, (sc_ppi_c)
	AND $F8
	LD C, A
	LD B, 6
	LD HL, KEYBOARD_INPUT_BUFFER
KEYB_READ_MATRIX_LOOP:    
	CALL KEYB_READ_RAWDATA
	LD (HL), A
	RRC E
	RL D
	INC C
	INC HL
	DJNZ KEYB_READ_MATRIX_LOOP
	LD B, E
	CALL KEYB_READ_RAWDATA
	LD (HL), A
	SLA D
	SLA D
	LD A, E
	AND 0b00000011
	ADD A, D
	INC HL
	LD (HL), A
	LD A, E
	AND 0b00001100
	LD E, A
	LD A, B
	RRCA
	AND $2
	OR E
	LD (KEYBOARD_INPUT_BUFFER+8), A
	RET

KEYB_READ_RAWDATA:
	LD A, C
	OUT (sc_ppi_c), A
	CALL PAUSEFORPPI
	IN A, (sc_ppi_b)
	CPL
	LD E, A
	IN A, (sc_ppi_a)
	CPL
	RET

PAUSEFORPPI:
	NOP
	NOP
	RET

KEYB_READ_ASCII:
	LD BC, $0800
	LD DE, KEYBOARD_INPUT_BUFFER
RKEYLOOP:
	LD A, (DE)
	OR A
	JR NZ, RKEYFOUND
	INC DE
	INC C
	DJNZ RKEYLOOP
	XOR A
	JR RKEYEND
RKEYFOUND:
	LD H, 0
	LD L, C
	ADD HL, HL
	ADD HL, HL
	ADD HL, HL
	LD B, A
	LD C, 0
RKEYLOOP2:
	RRC B
	JR C, RKEYADDRES
	INC C
	JR RKEYLOOP2
RKEYADDRES:
	LD B, 0
	ADD HL, BC
	LD A, (KEYBOARD_INPUT_BUFFER+8)
	LD BC, TABLE_CTRL_CHARS
	BIT 2, A
	JR NZ, RKEYADDRETVAL
	BIT 3, A
	LD BC, TABLE_SHIFTED_CHARS
	JR Z, RKEYADDRETVAL
	LD BC, TABLE_UNSHIFTED_CHARS
RKEYADDRETVAL:
	ADD HL, BC
	LD A, (HL)
RKEYEND:
	LD HL, (KEYBOARD_LAST_CHAR)
	LD H, L
	LD L, A
	LD (KEYBOARD_LAST_CHAR), HL
	SUB H
	LD (KEYBOARD_DIFF_CHAR), A
	RET

TABLE_CTRL_CHARS:
	DEFB   0x00, 0x11, 0x01, 0x1A,   0x00, 0x00, 0x0B, 0x09
	DEFB   0x00, 0x17, 0x13, 0x18,   0x00, 0x00, 0x0C, 0x0F
	DEFB   0x00, 0x05, 0x04, 0x03,   0x00, 0x00, 0x00, 0x10
	DEFB   0x00, 0x12, 0x06, 0x16,   0x00, 0x00, 0x00, 0x00

	DEFB   0x00, 0x14, 0x07, 0x02,   0x00, 0x00, 0x1D, 0x1B
	DEFB   0x00, 0x19, 8, 	0x0E,   0x00, 0x00, 0x00, 0x00
	DEFB   0x00, 0x05, 10,   13,     0x00, 0x00, 0x00, 0x00
	DEFB   0x00, 0x00, 0x1C, 0x1E,   0x1F, 0x00, 0x00, 0x00

TABLE_SHIFTED_CHARS:
	DEFB "1", "Q", "A", "Z",  0 , ",", "K", "I"
	DEFB "2", "W", "S", "X",  32, ".", "L", "O"
	DEFB "3", "E", "D", "C",  0 , "/", ";", "P"
	DEFB "4", "R", "F", "V",  8,  0 , ":", "@"

	DEFB "5", "T", "G", "B",  0 ,0x1F, "]", "["
	DEFB "6", "Y", "H", "N",  0 ,0x1D,  13,  0
	DEFB "7", "U", "J", "M",  0 ,0x1C,0x1E,  0
	DEFB  0 ,  0 , '\\', "^", "-", "0", "9", "8"

TABLE_UNSHIFTED_CHARS:
	DEFB  "!", "q", "a", "z",  0 , "<", "k", "i"
	DEFB "\"", "w", "s", "x",  " ", ">", "l", "o"
	DEFB  "#", "e", "d", "c",  0 , "?", "+", "p"
	DEFB  "$", "r", "f", "v",  8 , "_", "*", "`"

	DEFB  "%", "t", "g", "b",  0 ,  0 , "}", "{"
	DEFB  "&", "y", "h", "n",  0 ,  0 ,  13,  0
	DEFB  96, "u", "j", "m",  0 ,  0 ,  0 ,  0
	DEFB   0 ,  0 , "|", "~", "=",  0 , ")", "("

KEYB_BUFTEST:
	LD HL, (KEYBD_PUTPNT)
	LD DE, (KEYBD_GETPNT)
CP_HLDE:
	LD A, H
	CP D
	RET NZ
	LD A, L
	CP E
	RET

KEYB_WRAP_PTR:
	LD A, L
	CP 32
	RET NZ
	LD HL, KEYBD_BUFFER
	RET

KBIRQ:
	CALL KEYB_READ_MATRIX
	CALL KEYB_READ_ASCII
	LD HL, KEYBOARD_TYPEMATIC_CNT
	LD A, (KEYBOARD_DIFF_CHAR)
	OR A
	JR Z, NORESETTYPEMATIC
	XOR A
	LD (HL), A
NORESETTYPEMATIC:
	LD A, (HL)
	OR A
	JR Z, NOTYPEMATIC
	DEC A
	LD (HL), A
	RET
NOTYPEMATIC:
	CALL KEYB_BUFTEST
	RET NZ
	LD A, (KEYBOARD_LAST_CHAR)
	OR A
	RET Z
	CALL KEYB_BUFFERPUTCHAR
	LD B, 3
	LD A, (KEYBOARD_DIFF_CHAR)
	OR A
	JR Z, TMSAMECHAR
	LD B, 15
TMSAMECHAR:
	LD A, B
	LD (KEYBOARD_TYPEMATIC_CNT), A
	RET

KEYB_BUFFERPUTCHAR:
	LD HL, (KEYBD_PUTPNT)
	LD (HL), A
	INC HL
	CALL KEYB_WRAP_PTR
	PUSH DE
	LD DE, (KEYBD_GETPNT)
	CALL CP_HLDE
	POP DE
	RET Z
	LD (KEYBD_PUTPNT), HL
	RET