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
;*                      JOYSTICK ROUTINE FOR SG-1000                           *
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
	cpl
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
	jr		nz, JoyRead


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
