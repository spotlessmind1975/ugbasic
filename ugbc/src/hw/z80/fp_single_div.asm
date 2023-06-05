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

FPSINGLEDIV:
	CALL FPPUSHPOP
	PUSH BC
	PUSH DE
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD B, (HL)
	INC HL
	LD A, B
	ADD A, A
	LD A, (HL)
	ADC A, A

	POP HL
	JP Z, FPSINGLEDIV_0_OP2
	INC A
	JP Z, FPSINGLEDIV_INFNAN_OP2
	DEC A
	PUSH AF
	PUSH DE

	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD C, (HL)
	INC HL
	LD A, C
	ADD A, A
	LD A, (HL)
	ADC A, A

	POP HL
	JP Z, FPSINGLEDIV_OP1_0
	INC A
	JP Z, FPSINGLEDIV_OP1_INFNAN
	PUSH AF

	SET 7, C
	SET 7, B

	OR A
	SBC HL, DE
	LD A, B
	SBC A, C
	JR NC, FPSINGLEDIVL1
	ADD HL, DE
	ADC A, C
FPSINGLEDIVL1:
	LD B, A
	SBC A, A
	INC A

	PUSH AF
	CALL FPDIV24_24
	POP HL

	RR H
	JR NC, FPSINGLEDIVL2
	RR B
	RR D
	RR E
	POP AF
	DEC A
	DEFB $0E ;START OF `LD C,*` TO EAT THE NEXT BYTE
FPSINGLEDIVL2:
	POP AF
	LD L, A
	RR H
	POP AF
	RR H		;TOP 2 BITS OF H ARE SIGNS

	BIT 5, H
	JR Z, FPSINGLEDIVL3
	INC E
	JR NZ, FPSINGLEDIVL3
	INC D
	JR NZ, FPSINGLEDIVL3
	INC B
	JR NZ, FPSINGLEDIVL3
	DEC L
FPSINGLEDIVL3:

	SUB L
	LD L, 0
	JR NC, $+3
	DEC L
	ADD A, 7FH
	JR NC, $+3
	INC L
	DEC L
	JR Z, FPSINGLEDIV_RETURN_INF
	INC L
	JR NZ, FPSINGLEDIV_RETURN_ZERO

FPSINGLEDIV_RETURN:
	SLA B
	LD L, A
	LD A, H
	AND %11000000
	JP PE, $+4
	SCF
	LD A, L
	RRA
	RR B
	POP HL
	LD (HL), E
	INC HL
	LD (HL), D
	INC HL
	LD (HL), B
	INC HL
	LD (HL), A
	RET

FPSINGLEDIV_0_OP2:
	RR B
	LD A, (HL)
	INC HL
	OR (HL)
	INC HL
	LD C, (HL)
	SLA C
	OR C
	LD C,A
	LD A, (HL)
	ADD A, A
	INC HL
	LD A, (HL)
	ADC A, A
	LD H, B
	JR Z, FPSINGLEDIV_RETURN_NAN
	RR H
	INC A
	JR NZ,FPSINGLEDIV_RETURN_ZERO
	OR C
	JR Z,FPSINGLEDIV_RETURN_ZERO
	JR FPSINGLEDIV_RETURN_NAN2

FPSINGLEDIV_INFNAN_OP2:
	RR C
	INC HL
	INC HL
	LD A, (HL)
	ADD A, A
	INC HL
	LD A, (HL)
	ADC A, A
	LD H, C
	JR Z, FPSINGLEDIV_RETURN_NAN
	INC A
	JR Z, FPSINGLEDIV_RETURN_NAN
	RR H
	LD A ,-1
	JR FPSINGLEDIV_RETURN

FPSINGLEDIV_OP1_0:
	RR H
	POP AF
FPSINGLEDIV_RETURN_NAN:
	RR H
FPSINGLEDIV_RETURN_NAN2:
	LD A, -1
	LD B, A
	JR FPSINGLEDIV_RETURN

FPSINGLEDIV_OP1_INFNAN:
	RR H
	POP AF
	RR H
	LD A, C
	ADD A, A
	OR D
	OR E
	JR Z,FPSINGLEDIV_RETURN_ZERO
	JR FPSINGLEDIV_RETURN_NAN2

FPSINGLEDIV_RETURN_INF:
	LD A,$FF
	DEFB $FE
FPSINGLEDIV_RETURN_ZERO:
	XOR A
	LD B, A
	JR FPSINGLEDIV_RETURN
