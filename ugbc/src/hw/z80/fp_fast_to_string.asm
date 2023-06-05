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

S_NAN:
DEFB	3, "NaN"
S_NEGINF:
DEFB	4, "-inf"
S_POSINF:
DEFB	4, "+inf"

FPFASTTOA:
	LD B, A

	ADD A, A
	JR NZ, +FPFASTTOAX
	EX DE, HL
	JR NC, $+5
	LD (HL), '-'
	INC HL
	LD (HL), '0'
	INC HL
	LD (HL), 0
	DEC HL
	RET NC
	DEC HL
	RET
FPFASTTOAX:

	PUSH DE
	CP $FE
	JR NZ, FPFASTTOA_FINITE
	LD A, H
	OR L
	LD HL, S_NAN
	JR NZ, +FPFASTTOAX2
	LD HL, S_NEGINF
	BIT 7, B
	JR NZ, +FPFASTTOAX2
	INC HL
FPFASTTOAX2:
	LDI
	LDI
	LDI
	LDI
	LD A, (HL)
	LD (DE), A
	POP HL
	RET
FPFASTTOA_FINITE:

	LD A, B
	ADD A, A
	JR NC, +FPFASTTOA_FINITEX
	EX DE, HL
	LD (HL), '-'
	INC HL
	EX DE, HL
FPFASTTOA_FINITEX:

	PUSH DE

	PUSH HL

	LD L, A
	LD H, 0
	RRCA
	LD E, A
	LD D, H

	ADD HL, HL
	ADD HL, HL
	ADD HL, DE
	ADD HL, HL
	ADD HL, DE
	ADD HL, HL
	ADD HL, HL
	ADD HL, DE

	LD E, H
	EX (SP), HL

	PUSH HL
	LD HL, FPFASTPOW10_LUT
	ADD HL, DE
	SLA E
	ADD HL, DE
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD C, (HL)
	LD A, B
	AND $7F
	POP HL
	CALL FPFASTMUL

	CP 63
	JR NC,+FPFASTPOW10_LUTX

	POP DE
	DEC D
	PUSH DE
	LD C, $42
	LD DE, $4000
	CALL FPFASTMUL
FPFASTPOW10_LUTX:

	SUB 63
	LD B, A
	LD A, 1
	JR Z, +FPFASTPOW10_LUTX2
	ADD HL, HL
	RLA
	DJNZ $-2
FPFASTPOW10_LUTX2:

	LD BC, 3
	ADD HL, BC
	ADC A, B

	POP BC
	POP DE

	CP 10
	JR NC, +FPFASTPOW10_LUTX3
	ADD A, '0'
	LD (DE), A
	INC DE

	PUSH BC
	CALL FPFASTTOA_SUB
	JR FPFASTTOA_WRITE_DIGITS
FPFASTPOW10_LUTX3:
	INC B

	PUSH BC

	LD BC, 30
	ADD HL, BC
	ADC A, B

	EX DE, HL
	LD (HL), '1'
	SUB 20
	JR C, $+4
	INC (HL)
DEFB $01
	ADD A, 10
	INC HL
	EX DE, HL
	ADD A, '0'
	LD (DE), A
	INC DE
FPFASTTOA_WRITE_DIGITS:
	CALL FPFASTTOA_SUB
	CALL FPFASTTOA_SUB
	CALL FPFASTTOA_SUB
	XOR A
	LD (DE), A

	POP AF

	POP HL
	PUSH HL
	SUB 19
	LD E, A
	ADD A, A
	SBC A, A
	LD D, A
	CALL FORMATSTR
	POP HL
	RET
;
FPFASTTOA_SUB:
	XOR A
	LD B, H
	LD C, L
	ADD HL, HL
  RLA
	ADD HL, HL
  RLA
	ADD HL, BC
  ADC A, '0'/2
	ADD HL, HL
  RLA
	LD (DE), A
	INC DE
	RET
