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

FPSINGLESQRT:

	CALL FPPUSHPOP
	PUSH BC
	LD B, (HL)
	INC HL
	LD E, (HL)
	INC HL
	LD D, (HL)
	LD A, D
	ADD A, A
	INC HL
	LD A, (HL)
	ADC A, A
	JR C, FPSINGLESQRT_NEG
	JR Z, FPSINGLESQRT_ZERO
	INC A
	JR Z, FPSINGLESQRT_INFNAN

	SET 7,D

	LD C, 0
	RRA
	JR C, FPSINGLESQRTL1
	SRL D
	RR E
	RR B
	RR C
FPSINGLESQRTL1:

	ADD A,3FH

	PUSH AF

	CALL FPSQRT24_MANT

	LD B, L
	POP AF
	SLA D
	SRL A
	RR D
FPSINGLESQRT_ZERO:
	POP HL
	LD (HL), B
	INC HL
	LD (HL), E
	INC HL
	LD (HL), D
	INC HL
	LD (HL), A
	RET
FPSINGLESQRT_NEG:
	JR Z, FPSINGLESQRT_NEG0
	LD A, -1
FPSINGLESQRT_NEG0:
	POP HL
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	XOR %10000000
	LD (HL), A
	RET

FPSINGLESQRT_INFNAN:
	POP HL
	LD A, D
	AND %01111111 ;MASK OUT THE EXPONENT BIT
	OR E
	OR B
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	OR %10000000
	LD (HL), A
	INC HL
	LD (HL), %01111111
	RET
