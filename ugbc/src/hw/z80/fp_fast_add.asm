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

FPFASTADD:

	LD B, A

	AND $7F
	JR NZ, FPFASTADDL1

FPFASTADDRCDE:
	LD A,C
	EX DE,HL
	RET

FPFASTADDL1:

	INC A
	JP M, FPFASTADD_OP1_INF_NAN

	LD A,C
	AND $7F
	JP Z, FPFAST_RETURN_EXP_B

	INC A
	JP M, FPFASTADDRCDE


	LD A,B
	XOR C
	JP M, FPFASTADD_SUBTRACT

	CALL FPFASTADD_REORDER
	JR Z, FPFASTADD_ADD_SAME_EXP
	RET NC
	PUSH BC
	CALL RSHIFT_1DE
	SLA B
	ADC HL, DE

	POP DE
	LD A, D
	RET NC

	AND $7F
	CP $7E
	LD A, D
	JR Z, FPFAST_RETURN_INF
	INC A

	SRL H
	RR L
	RET NC
	INC HL
	RET

FPFASTADD_ADD_SAME_EXP:
	LD A, B
	AND $7F
	CP $7E
	LD A, B
	JR Z, FPFAST_RETURN_INF
	INC A
	ADD HL, DE
	RR H
	RR L
	RET NC
	INC L
	RET NZ
	INC H
	RET NZ
	INC A
	RET

FPFAST_RETURN_INF:
	OR %01111111
	LD HL, 0
	RET

FPFASTADD_SUBTRACT:
	CALL FPFASTADD_REORDER
	JR Z, FPFASTADD_SUBTRACT_SAME_EXP
	RET NC
	PUSH BC
	CALL RSHIFT_1DE
	SUB C
	LD C, A
	LD A, 0
	SBC A, B
	LD B, A
	SBC HL, DE

	POP DE
	LD A, D
	RET NC

NORMALIZE_D_HLBC:
	LD A, H
	OR L
	OR B
	OR C
	RET Z

	LD A, D
NORMALIZE_D_HLBC_NONZERO:
	ADD A, A
	PUSH AF
	RRCA

NORMALIZE_D_HLBC_NONZEROL1:
	DEC A
	JR Z, NORMALIZE_D_HLBC_NONZEROL2
	SLA C
	RL B
	ADC HL, HL
	JP NC, NORMALIZE_D_HLBC_NONZEROL1

	SLA C
	LD BC, 0
	ADC HL, BC

	ADC A, B
	ADD A, A
NORMALIZE_D_HLBC_NONZEROL2:
	LD D, A
	POP AF
	LD A, D
	RRA
	RET

FPFASTADD_SUBTRACT_SAME_EXP:
	LD A, B
	SBC HL, DE

	JR NZ, $+5
	AND %10000000
	RET

	LD BC, 0
	JR NC, NORMALIZE_D_HLBC_NONZERO
	XOR $80
	LD D, A
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	LD A, D
	JR NORMALIZE_D_HLBC_NONZERO

FPFASTADD_REORDER:
	XOR C
	RLC C
	RLA

	SUB C
	RET Z
	JR NC, FPFASTADD_REORDERL1
	NEG

	RRC C
	LD B, C
	EX DE, HL
FPFASTADD_REORDERL1:

	OR A
	RRA
	CP 18
	RET C

FPFAST_RETURN_EXP_B:
	LD A, B
	RET

FPFASTADD_OP1_INF_NAN:
	LD A, H
	OR L
	JR NZ, FPFAST_RETURN_EXP_B

	OR C
	JR Z, FPFAST_RETURN_EXP_B
	INC A
	ADD A, A
	JR NZ, FPFAST_RETURN_EXP_B

	LD A, D
	OR E
	LD A, C
	JR NZ, FPFASTADD_OP1_INF_NANL1

	CP B
	RET Z
FPFASTADD_OP1_INF_NANL1:
	DEC HL
	RET

RSHIFT_1DE:
	LD BC, 0
	SCF
RSHIFT_1DEL1:
	RR D
	RR E
	RR B
	RR C
	DEC A
	JR NZ, RSHIFT_1DEL1
	RET
