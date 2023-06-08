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

FPSINGLETO16S:
	PUSH DE
	PUSH BC
	PUSH AF

	LD C, (HL)
	INC HL
	LD E, (HL)
	INC HL
	LD A, (HL)
	RLCA
	SCF
	RRA
	LD D, A
	INC HL
	LD A, (HL)
	ADC A, A
	CALL FPSINGLETOI16_GET_INT
FPSINGLETOI16_RETURN:
	POP AF
	POP BC
	POP DE
	RET

FPSINGLETOI16_INFNAN:
	LD A, D
	ADD A, A
	OR E
	OR C
	RET NZ
FPSINGLETOI16_INF:
	LD HL, 32767
	RR B
	RET NC
	INC HL
	RET

FPSINGLETOI16_ZERO_ISH:
	RR B
	RET NC
	LD A, D
	ADD A, A
	OR E
	OR C
	RET Z
	DEC HL
	RET

FPSINGLETOI16_GET_INT:
	RL B
	LD HL, 0
	INC A
	JR Z, FPSINGLETOI16_INFNAN
	JP P, FPSINGLETOI16_ZERO_ISH
	SUB 128
	CP 15
	JR NC, FPSINGLETOI16_INF
	EX DE, HL
	CP 7
	JR C, $+7
	SUB 8
	LD E, H
	LD H, L
	LD L, D

	LD D, B
	LD B, A
	XOR A
	INC B
	JR Z, $+8
	ADD HL, HL
	RL E
	RLA
	DJNZ $-4

	LD B, D
	LD D, A
	EX DE, HL

	RRC B
	RET NC

	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A

	LD A, C
	OR D
	OR E
	RET Z
	DEC HL
	RET

FPSINGLETO16U:
	PUSH DE
	PUSH BC
	PUSH AF
	LD C, (HL)
	INC HL
	LD E, (HL)
	INC HL
	LD A, (HL)
	RLCA
	SCF
	RRA
	LD D, A
	INC HL
	LD A, (HL)
	ADC A, A
	CCF
	JR NC, FPSINGLETOU16_RETURN_CARRY
	OR A
	JR Z, FPSINGLETOU16_RETURN_CARRY
	INC A
	JR Z, FPSINGLETOU16_INFNAN

	ADD A, 256-143
	JR C, FPSINGLETOU16_RETURN_CARRY
	ADD A, 15
	JR NC, FPSINGLETOU16_RETURN_CARRY

	LD B, A
	INC B
	EX DE, HL
	XOR A
	LD E, A

	ADD HL, HL
	RL E
	RLA
	DJNZ $-4

	LD L, E
	LD H, A

	DEFB $01 ; START OF `LD BC,**` TO SKIP THE NEXT TWO BYTES
FPSINGLETOU16_RETURN_CARRY:
	SBC HL, HL

FPSINGLETOU16_RETURN:
	POP AF
	POP BC
	POP DE
	RET

FPSINGLETOU16_INFNAN:
	LD A, D
	ADD A, A
	OR E
	OR C
	SUB 1
	JR FPSINGLETOU16_RETURN_CARRY
