; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
aaaaaaa=1
bbbbbbb=2
ccccccc=3
ddddddd=4
eeeeeee=5
INT_HANDLER      	= $0104
NMI_HANDLER      	= $0108
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
		and     80
		jr      z,vdpSync
		
		ld      hl,900
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
		jp		NMI_HANDLER

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
		
		call	CheckIf60Hz
		ld		(VDP60HZ),a				; save it, 00/01 = 50/60 Hz		
		
		
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
    CALL IRQVECTOR
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
	JP INT_HANDLER

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

	LD HL, TEXTATBMFONT
	LD BC, 2048
    LD DE, 0
    CALL VDPWRITE

