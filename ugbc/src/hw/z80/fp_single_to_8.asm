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

FPSINGLETO8S:
	PUSH HL
	PUSH DE
	PUSH BC
	LD A, (HL)
	INC HL
	OR (HL)
	LD D, A
	INC HL
	LD A, (HL)
	RLCA
	SCF
	RRA
	LD C,A
	INC HL
	LD A, (HL)
	ADC A,A

	RR E

	CALL FPSINGLETOI8_GET_INT

FPSINGLETOI8_RETURN:
	POP BC
	POP DE
	POP HL
	RET

FPSINGLETOI8_ZERO_ISH:
	XOR A
	RL E
	RET NC
	LD A, C
	ADD A, A
	OR D
	ADD A, 255
	SBC A, A
	RET

FPSINGLETOI8_INFNAN:
	LD A, C
	ADD A, A
	OR D
	SUB 1
	SBC A, A
	RET Z
FPSINGLETOI8_INF:
	LD A, 127
	RL E
	ADC A, 0
	RET

FPSINGLETOI8_GET_INT:
	INC A
	JR Z, FPSINGLETOI8_INFNAN
	JP P, FPSINGLETOI8_ZERO_ISH
	SUB 128
	CP 7
	JR NC, FPSINGLETOI8_INF

	LD H, 0
	LD L, C		; UPPER 8 BITS OF THE SIGNIFICAND, H IS 0
	LD B, A
	INC B
	ADD HL, HL
	DJNZ $-1
	LD A, H
	RL E
	RET NC
	LD A, L
	OR D
	ADD A, 255
	SBC A, A
	SUB H
	LD H, A
	RET

FPSINGLETOU8:

	PUSH HL
	PUSH DE
	PUSH BC
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD A, (HL)
	RLCA
	SCF
	RRA
	LD C, A
	INC HL
	LD A, (HL)
	ADC A, A
	CCF
	JR NC, FPSINGLETOU8_RETURN_CARRY
	OR A
	JR Z, FPSINGLETOU8_RETURN_CARRY
	INC A
	JR Z, FPSINGLETOU8_INFNAN

	ADD A, 256-135
	JR C, FPSINGLETOU8_RETURN_CARRY
	ADD A, 7
	JR NC, FPSINGLETOU8_RETURN_CARRY

	LD B, A
	INC B
	XOR A
	RL C
	RLA
	DJNZ $-3

	DEFB $FE
FPSINGLETOU8_RETURN_CARRY:
	SBC A, A
FPSINGLETOU8_RETURN:
	POP BC
	POP DE
	POP HL
	RET

FPSINGLETOU8_INFNAN:
	LD A, C
	ADD A, A
	OR D
	OR E
	SUB 1
	JR FPSINGLETOU8_RETURN_CARRY
	