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
;*                      JOYSTICK ROUTINE FOR SC-3000                           *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Originally published on:
; https://github.com/siriokds/SC-3000-Keyboard-support/blob/main/SC3000_SG1000_KeybJoy.asm

; PPI_Setting         = 0x92
; PPI_PortC           = 0xDE
; PPI_Control         = 0xDF
; JOY_PortA           = 0xDC
; JOY_PortB           = 0xDD

; KEYB_Detected       = 0x00
; KEYB_NotDetected    = 0xFF

; PPIKEYBOARD		DS 1		; this byte must be defined in RAM area (>= $C000 for internal RAM)


; 2) Call this to obtain joystick + keyboard keys
;
; OUTPUT:
;    A = joy/key bits (1 = pressed, 0 = not pressed)
;
;    format bits:   5   |   4   |   3   |   2   |   1   |   0   
;                 TrigR | TrigL | Right | Left  | Down  |  Up  |
;----------------------------------------------------------------
;================================================================
JOYSTICK:
;================================================================
;----------------------------------------------------------------
	call	KeybJoyRead
	and		3Fh
	ret

;---------------------------------------------------------------
PpiRowRead:
;---------------------------------------------------------------
	ld		a, b
	out		(PPI_PortC), a	; no effect on SG-1000
;===============================================================
JoyRead:
;===============================================================
	in		a, (JOY_PortA)
	dec		b
	ret


; Destroy registers: BC
; OUTPUT: A
;===============================================================
KeybJoyRead:
;===============================================================
	ld		a, (PPIKEYBOARD)
	or		a
	jr		z, JoyRead


; --- ROW 7 --------------------------------------------
	ld		b, 7			; READ JOYSTICK ROW
	call	PpiRowRead
	ld		c, a

; --- ROW 6 --------------------------------------------
	call	PpiRowRead
    bit		5,a
	jr		nz, noKeyRIGHT
	res		3, c			; CURSOR RIGHT => Joy Right
noKeyRIGHT:
    bit		6,a
	jr		nz, noKeyUP
	res		0, c			; CURSOR UP => Joy Up
noKeyUP:
	in		a, (JOY_PortB)
	bit		1,a				; Graph
	jr		nz,noKeyGraph
	res		4, c			; Left Trigger
noKeyGraph:

; --- ROW 5 --------------------------------------------
	call	PpiRowRead
    bit		5,a
	jr		nz, noKeyLEFT
	res		2, c			; CURSOR LEFT => Joy Left
noKeyLEFT:

; --- ROW 4 --------------------------------------------
	call	PpiRowRead
    bit		5,a
	jr		nz, noKeyDOWN
	res		1, c			; CURSOR DOWN => Joy Down
noKeyDOWN:

; --- ROW 3 --------------------------------------------
	call	PpiRowRead
	bit		4,a				; InsDel
	jr		nz,noKeyInsDel
	res		5, c			; Right Trigger
noKeyInsDel:
	
; --- ROW 2 --------------------------------------------
	call	PpiRowRead
	bit		4,a				; Home
	jr		nz,noKeyHome
	res		4, c			; Left Trigger
noKeyHome:

; --- ROW 1 --------------------------------------------
	dec		b

; --- ROW 0 --------------------------------------------
	call	PpiRowRead
	bit		4,a				; Eng Dier's

	jr		nz,noKeyEngDiers
	res		5, c			; Right Trigger
noKeyEngDiers:
	ld 		a, c
	
keybExit:
	cpl
	ret

; Read the FIRE button's latch for a specific joystick
;
;   A = joystick button id
;   A = $00 FIRE was not pressed
;       $ff FIRE was pressed
;
STRIG:

	; Is the button odd? So we can read directly
	; the fire button.

	SRL A
	JR C, JFIRE

	; Load the latch value.

	LD E, A
	LD D, 0
	LD HL, JFIRELATCH
	ADD HL, DE
	LD A, (HL)

	; Check if latch is not zero.
	
	CP 0
	JR Z, STRIGNONE

	; Reset the latch.

	LD B, A
	LD A, 0
	LD (HL), A

	; TRUE, the joystick fire was pressed in the past.

	LD A, $FF

STRIGNONE:
	RET

; Read the FIRE button for a specific joystick
;
;   A = joystick number
;   A = $00 FIRE was not pressed
;       $01 FIRE was pressed
;
JFIREX:

	PUSH AF
	LD E, A
	LD D, 0
	LD HL, JFIRELATCH
	ADD HL, DE
	POP AF
	
	; Load the STRIG register from the hardware port.

	CALL JOYSTICK

	; Isolate the FIRE bit.

	AND $10

	; Update the FIRE latch.

	PUSH AF
	OR (HL)
	LD (HL), A
	POP AF

	; Done.

	RET

; Read the FIRE button for a specific joystick
;
;   A = joystick number
;   A = $00 FIRE was not pressed
;       $FF FIRE was pressed
;
JFIRE:
	CALL JFIREX
	CP 0
	JR Z, JFIRENONE
	LD A, $FF
JFIRENONE:
	RET

WAITFIRE:
	CALL JFIRE
	CP 0
	JR Z, WAITFIRE
	LD A, B
	CP 0
	JR Z, WAITFIRED
WAITFIREL1:
	CALL JFIRE
	CP 0
	JR NZ, WAITFIREL1
WAITFIRED:
	RET
