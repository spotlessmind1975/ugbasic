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

FORMATSTR:

	LD A, (HL)
	CP '-'
	JR NZ, $+3
	INC HL
	PUSH DE ; SAVE THE EXPONENT
	PUSH HL

	LD D, H
	LD E, L
	LD A, '0'
	CP (HL)
	JR NZ, FORMATSTR_NO_LEADING_ZEROS
FORMATSTR_STRIP_LEADING_ZEROS:
	CPI
	JR Z, FORMATSTR_STRIP_LEADING_ZEROS
	DEC HL

	LD A, 12 ; FORMAT_LEN
	LD C, A

	XOR A
	LD B, A
FORMATSTR_COPY_DIGITS:
	CP (HL)
	LDI
	JP PO, +FORMATSTR_COPY_DIGITS2
	JR NZ, FORMATSTR_COPY_DIGITS
FORMATSTR_COPY_DIGITS2:
	DEC HL
	LD (HL), 0

FORMATSTR_NO_LEADING_ZEROS:

	CALL FORMATSTR_REMOVE_TRAILING_ZEROS
	POP HL
	POP DE

	LD A, (HL)
	OR A
	JR NZ, +FORMATSTR_NO_LEADING_ZEROS2
	LD (HL), '0'
	INC HL
	LD (HL), A
	RET
FORMATSTR_NO_LEADING_ZEROS2:

	CALL FORMATSTR_CHECK_ENG
	JR C, FORMATSTR_ENG
	INC DE
	BIT 7, D
	JR NZ, FORMATSTR_NEG_EXP

	LD B, D
	LD C, E
	XOR A
	CP E
	JR Z, FORMATSTR_INSERT_DECIMAL
	CPIR

	JR Z, FORMATSTR_PAD_RIGHT

FORMATSTR_INSERT_DECIMAL:
	LD A, (HL)
	OR A
	RET Z
	LD A, '.'
FORMATSTR_INSERT_DECIMAL_LOOP:
	LD C, (HL)
	LD (HL), A
	INC HL
	LD A, C
	OR A
	JR NZ, FORMATSTR_INSERT_DECIMAL_LOOP
	LD (HL), A
	RET

FORMATSTR_NEG_EXP:

	XOR A
	LD C, A
	CPIR
	LD B, A
	SUB C
	LD C, A

	XOR A
	LD D, A
	SUB E
	LD E, A
	EX DE, HL
	ADD HL, DE
	EX DE, HL
	DEC HL

	LDDR

	EX DE, HL
	LD B, A
	LD (HL), '0'
	DEC HL
	DJNZ $-3

	LD (HL), '.'
	RET

FORMATSTR_PAD_RIGHT:

	DEC HL
	INC BC
FORMATSTR_PAD_RIGHT2:
	LD (HL), '0'
	CPI
	JP PE, FORMATSTR_PAD_RIGHT2
	LD (HL), 0
	RET

FORMATSTR_ENG:

	INC HL
	CALL FORMATSTR_INSERT_DECIMAL
	LD (HL), 'E'
	INC HL
	BIT 7, D
	JR Z, FORMATSTR_EXP_TO_STR
	LD (HL), '-'
	INC HL
	XOR A
	SUB E
	LD E, A
	SBC A, A
	SUB D
	LD D, A
FORMATSTR_EXP_TO_STR:
	EX DE, HL
	LD A, '0'-1
	LD BC, -10000
FORMATSTR_EXP_TO_STR2:
	INC A
	ADD HL, BC
	JR C, FORMATSTR_EXP_TO_STR2
	CP '0'
	JR Z, $+4
	LD (DE), A
	INC DE

	LD A, '9'+1
	LD BC, 1000
FORMATSTR_EXP_TO_STR3:
	DEC A
	ADD HL, BC
	JR NC, FORMATSTR_EXP_TO_STR3
	CP '0'
	JR Z, $+4
	LD (DE), A
	INC DE

	LD A, '0'-1
	LD BC, -100
FORMATSTR_EXP_TO_STR4:
	INC A
	ADD HL, BC
	JR C, FORMATSTR_EXP_TO_STR4
	CP '0'
	JR Z, $+4
	LD (DE), A
	INC DE

	LD B, 10
	LD A, L
FORMATSTR_EXP_TO_STR5:
	ADD A, 10
	DEC B
	JR NC, FORMATSTR_EXP_TO_STR5
	EX DE, HL
	JR Z, FORMATSTR_ENG_LAST_DIGIT
	SET 4, B
	SET 5, B
	LD (HL), B
	INC HL
FORMATSTR_ENG_LAST_DIGIT:
	ADD A, '0'
	LD (HL), A
	INC HL
	LD (HL), 0
	RET

FORMATSTR_REMOVE_TRAILING_ZEROS:
	XOR A
	LD C, A
	LD B, A
	CPIR
	DEC HL
	LD A, '0'
FORMATSTR_REMOVE_TRAILING_ZEROS2:
	DEC HL
	CP (HL)
	JR Z, FORMATSTR_REMOVE_TRAILING_ZEROS2
	INC HL
	LD (HL), 0
	RET

FORMATSTR_CHECK_ENG:
	LD A, D
	INC A
	JR Z, FORMATSTR_CHECK_ENG_NEG
	ADD A, 254
	RET C
    
	LD A, 12 ; FORMAT_LEN

FORMATSTR_CHECK_ENG2:
	LD A, 12 ; FORMAT_LEN
	CP E
	RET

FORMATSTR_CHECK_ENG_NEG:

	LD A, 7 ; FORMAT_MIN_ENGINEERING
	CP E
	CCF
	RET
