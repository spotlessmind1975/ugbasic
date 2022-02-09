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

PPI_Setting         = 0x92
PPI_PortC           = 0xDE
PPI_Control         = 0xDF
JOY_PortA           = 0xDC
JOY_PortB           = 0xDD

KEYB_Detected       = 0x00
KEYB_NotDetected    = 0xFF

DEFS $35

rst_38:
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
    CALL VDPREGIN
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
	RETI

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

    JP SC3K_InputInit

; Originally published on:
; https://github.com/siriokds/SC-3000-Keyboard-support/blob/main/SC3000_SG1000_KeybJoy.asm

; b = test value
ppi_test:
	ld		b, a
	out		(PPI_PortC),a
	in		a,(PPI_PortC)
	cp		b
	ld		a, KEYB_Detected	; "xor a" cannot be used. Zero Flag must be intact.
	jr		z, ppi_test_noerr
	dec		a					; c = 0xFF if not detected
ppi_test_noerr:
	ret

; 1) Call this at start of the game
;----------------------------------------------------------------
;================================================================
SC3K_InputInit:
;================================================================
;----------------------------------------------------------------
	ld		a,PPI_Setting
	out		(PPI_Control),a

	ld		a, KEYB_NotDetected
	ld		(PPIKEYBOARD),a	; save it, 0 = keyboard present

	ld		a,0x55
	call	ppi_test
	ld		c, a
	ld		a,0xaa
	call	ppi_test
	
	or		c					; merge the two attempts
	ld		(PPIKEYBOARD),a	; save it, 0 = keyboard present

	ld		a,0x07				; default row 7 (joystick)
	out		(PPI_PortC),a

    RET

