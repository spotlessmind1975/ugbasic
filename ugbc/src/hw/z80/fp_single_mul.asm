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

FPSINGLEMUL:
	CALL FPPUSHPOP
	PUSH BC
	PUSH DE
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD B, (HL)
	LD A, B
	ADD A, A
	INC HL
	LD A, (HL)
	LD C, A
	ADC A, A
	POP HL
	JP Z, FPSINGLEMUL_0_OP2
	INC A
	JP Z, FPSINGLEMUL_INFNAN_OP2
	DEC A
	PUSH AF

	PUSH DE
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD C, (HL)
	LD A, C
	ADD A, A
	INC HL
	LD A, (HL)
	ADC A, A
	JR Z, FPSINGLEMUL_OP1_0
	INC A
	JR Z, FPSINGLEMUL_OP1_INFNAN
	POP HL
	EX DE, HL
	PUSH AF

	SET 7, B
	SET 7, C

	CALL FPMUL24

	POP AF
	RR E
	BIT 7, B
	JR NZ, FPSINGLEMULL1
	DEC A
	SLA D
	ADC HL, HL
	RL B
FPSINGLEMULL1:

	SLA D
	EX DE, HL
	JR NC, FPSINGLEMULL2
	INC E
	JR NZ, FPSINGLEMULL2
	INC D
	JR NZ, FPSINGLEMULL2
	INC B
	JR NZ, FPSINGLEMULL2
	INC A
FPSINGLEMULL2:
	LD H, A
	POP AF
	RR L

	ADD A, H
	LD H, 0
	RL H
	SUB $7E
	DEC A
	JR NC, $+3
	DEC H

	DEC H
	JP Z, FPSINGLEMUL_INF_L
	INC H
	JR Z, $+3
	XOR A

	SLA B

	LD C, A
	LD A, L
	AND %11000000
	JP PE, $+4
	SCF

FPSINGLEMUL_RETURN2:
	RR C
	RR B

FPSINGLEMUL_RETURN:
	POP HL
	LD (HL), E
	INC HL
	LD (HL), D
	INC HL
	LD (HL), B
	INC HL
	LD (HL), C
	RET

FPSINGLEMUL_OP1_0:
	POP BC
	RRA
	LD C, A
	POP AF
	RRA
	XOR C
	AND %10000000
	LD C, A
	LD B, 0
	JR FPSINGLEMUL_RETURN

FPSINGLEMUL_OP1_INFNAN:
	POP HL
	RRA
	LD B, A
	POP AF
	RRA
	XOR B
	LD H, A

	LD A, C
	ADD A, A
	OR D
	OR E
	LD B, A
	ADD HL, HL
	LD C, -1
	JR FPSINGLEMUL_RETURN2

FPSINGLEMUL_0_OP2:
	RRA
	LD B, A
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD A, (HL)
	ADD A,A
	LD C, A
	INC HL
	LD A, (HL)
	LD H, A
	ADC A, A
	INC A
	JR Z, FPSINGLEMUL_RETURN_NAN
	RRA
	XOR B
	AND %10000000
	LD C, A
	LD B, 0
	JR FPSINGLEMUL_RETURN
FPSINGLEMUL_RETURN_NAN:
	LD BC, $FF7F
	JR FPSINGLEMUL_RETURN

FPSINGLEMUL_INFNAN_OP2:
	RRA
	LD C, A
	LD A, B
	ADD A, A
	OR D
	OR E
	JR NZ, FPSINGLEMUL_RETURN_NAN
FPSINGLEMUL_INF_OP2:
	INC HL
	INC HL
	LD A, (HL)
	INC HL
	ADD A, A
	LD A, (HL)
	ADC A, A
	JR Z, FPSINGLEMUL_RETURN_NAN
	INC A
	JR Z, FPSINGLEMUL_CHECK_NAN
	RRA
	XOR C
	AND %10000000
	OR %01111111
	LD C, A
	JR FPSINGLEMUL_RETURN
FPSINGLEMUL_CHECK_NAN:
	RRA
	XOR C
	AND %10000000
	OR %01111111
	LD C, A
	DEC HL
	LD A, (HL)
	ADD A, A
	DEC HL
	OR (HL)
	DEC HL
	OR (HL)
	JR NZ, FPSINGLEMUL_RETURN_NAN
	JR FPSINGLEMUL_RETURN

FPSINGLEMUL_INF_L:
	LD A, L
	AND %11000000
	JP PE, $+4
	SCF
FPSINGLEMUL_INF:
	POP HL
	LD (HL), 0
	INC HL
	LD (HL), 0
	INC HL
	LD (HL), %10000000
	INC HL
	LD A, -1
	RRA
	LD (HL), A
	RET
