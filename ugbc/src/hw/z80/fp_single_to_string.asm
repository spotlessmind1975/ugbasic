; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2023 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from modules/z80float, copyright 2018 Zeda A.K. Thomas
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

FPSINGLETOA:
	CALL FPPUSHPOP
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD (FPSCRAP), DE
	LD A, (HL)
	LD E, A
	ADD A, A
	INC HL
	LD A, (HL)
	LD D, A
	ADC A, A
	LD H, B
	LD L, C
	INC A
	JP Z, FPSINGLETOA_RETURN_INFNAN
	RES 7, D
	LD (FPSCRAP+2), DE
	JR NC, FPSINGLETOAL1
	LD (HL), '-'
	INC HL
FPSINGLETOAL1:
	DEC A
	JP Z, FPSINGLETOA_RETURN_0

	PUSH HL

	LD (HL), '0'
	INC HL

	PUSH HL

	LD H, 0
	LD L, A
	LD B, H
	LD C, A
	ADD HL, HL
	ADD HL, HL
	ADD HL, HL
	ADD HL, BC
	ADD HL, HL
	ADD HL, BC
	ADD HL, HL
	ADD HL, HL
	ADD HL, BC

	LD A, 205
	ADD A, L
	LD A, 217
	ADC A, H

	PUSH AF
	CALL NZ, FPSINGLETOA_ADJUST
	LD HL, (FPSCRAP)
	LD DE, (FPSCRAP+2)
	LD A, E
	RLCA
	SCF
	RRA
	LD E, A
	LD A, D
	ADC A, A
	SUB 126

	LD B, A
	XOR A
FPSINGLETOA_FIRST_DIGIT_LOOP:
	ADD HL, HL
	RL E
	RLA
	DJNZ FPSINGLETOA_FIRST_DIGIT_LOOP

	POP BC
	EX (SP), HL
	LD D, 0
	CP 10
	JR C, FPSINGLETOA_FIRST_DIGIT_FIXED
	INC D
	DEC HL
	LD (HL), '1'
	INC HL
	SUB 10
FPSINGLETOA_FIRST_DIGIT_FIXED:
	ADD A, '0'
	LD (HL), A

	LD A, B
	EX (SP), HL
	POP BC

	PUSH AF
	CALL FPSINGLETOA_DIGITS

	LD H, B
	LD L, C
	LD A, (HL)
	LD (HL), 0
	ADD A, 5
	JR FPSINGLETOA_ROUND_START
FPSINGLETOA_ROUND_LOOP:
	DEC HL
	INC (HL)
	LD A, (HL)
FPSINGLETOA_ROUND_START:
	CP '9'+1
	JR NC, FPSINGLETOA_ROUND_LOOP
	INC HL
	LD (HL), 0

	POP AF
	LD E, A
	ADD A, A
	SBC A, A
	LD D, A
	POP HL

	LD A, (HL)
	CP '0'
	JP Z, FORMATSTR
	INC DE
	JP FORMATSTR

FPSINGLETOA_DIGITS:
	; THE NUMBER OF DIGITS IS NOT DECLARED EXTERNALLY
	; THE FIRST DIGIT IS WRITTEN.
	; IF WE ONLY WANTED 1 DIGIT, THEN A IS 0 AND WE SHOULD STOP
	LD A, 14

FPSINGLETOA_DIGITS_LOOP:
	PUSH AF
	CALL FPSINGLETOA_NEXT_DIGIT
	POP AF
FPSINGLETOA_DIGITS_START:
	DEC A
	JR NZ, FPSINGLETOA_DIGITS_LOOP
	RET

FPSINGLETOA_NEXT_DIGIT:
	PUSH BC
	LD B, H
	LD C, L
	LD A, E
	LD D, 6

	ADD HL, HL
	ADC A, A
	RL D

	ADD HL, HL
	ADC A, A
	RL D

	ADD HL, BC
	ADC A, E
	JR NC, $+3
	INC D

	ADD HL, HL
	ADC A, A
	LD E, A
	LD A, D
	ADC A, A

	POP BC
	INC BC
	LD (BC), A
	RET

FPSINGLETOA_ADJUST:
	LD HL, FPSINGLE_POWN10_LUT-4
	JR C, FPSINGLETOA_POW10LUT_MUL
	NEG
	LD HL, FPSINGLE_POW10_LUT-4
FPSINGLETOA_POW10LUT_MUL:
	LD DE, FPSCRAP
	LD B,D
	LD C,E
	CALL FPSINGLETOA_POW10LUT_MUL_SUB3
FPSINGLETOA_POW10LUT_MUL_SUB3:
	CALL FPSINGLETOA_POW10LUT_MUL_SUB
	CALL FPSINGLETOA_POW10LUT_MUL_SUB
FPSINGLETOA_POW10LUT_MUL_SUB:
	INC HL
	INC HL
	INC HL
	INC HL
	RRA
	JP C, FPSINGLEMUL
	RET

FPSINGLETOA_RETURN_0:
	LD (HL), '0'
	INC HL
	LD (HL), 0
	RET

FPSINGLETOA_RETURN_INFNAN:
	RL B	; SAVE THE SIGN
	LD A, E
	ADD A, A
	LD DE, (FPSCRAP)
	OR D
	OR E
	EX DE, HL
	LD HL, STR_NAN
	JR NZ, FPSINGLETOA_RETURN
	LD HL, STR_INF
	RR B
	JR NC, FPSINGLETOA_RETURN
	LD A, '-'
	LD (DE), A
	INC DE
FPSINGLETOA_RETURN:
	JP FPMOV4
