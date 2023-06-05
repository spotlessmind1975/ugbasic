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

FPFASTTOS16:
	LD C, A
	ADD A, A
	JR Z, FPFASTTOI16_RETURN_0

	CP $FE
	JR NZ, FPFASTTOS16L1
	LD A, H
	OR L
	JR NZ,FPFASTTOI16_RETURN_0
FPFASTTOI16_RETURN_INF:
	SLA C
	LD HL, 32767
	RET NC
	INC HL
	RET
FPFASTTOS16L1:

	CP 63*2
	JR NC, FPFASTTOS16L2
FPFASTTOI16_RETURN_0:
	LD HL, 0
	RET
FPFASTTOS16L2:

	RRA
	SUB 63
	CP 15
	JR NC, FPFASTTOI16_RETURN_INF

	OR A
	LD B, A
	LD D, 0
	LD A, 1
	JR Z, FPFASTTOS16L3

	ADD HL, HL
	RLA
	RL D
	DJNZ $-4
FPFASTTOS16L3:
	SLA C
	LD E, A
	EX DE, HL
	RET NC
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	RET

FPFASTTOU16:
	LD C,A

	ADD A, A
	JR Z, FPFASTTOU16_RETURN_0

	CP $FE
	JR NZ, FPFASTTOU16L1
	LD A, H
	OR L
	JR NZ, FPFASTTOU16_RETURN_0
FPFASTTOU16_RETURN_INF:
	LD HL, -1
	RET
FPFASTTOU16L1:

	CP 63*2
	JR NC, FPFASTTOU16L2
FPFASTTOU16_RETURN_0:
	LD HL, 0
	RET
FPFASTTOU16L2:

	RRA
	SUB 63
	CP 16
	JR NC, FPFASTTOU16_RETURN_INF

	LD B, A
	OR A
	LD A, 1
	LD D, 0
	JR Z, FPFASTTOU16L3

	ADD HL, HL
	RLA
	RL D
	DJNZ $-4
FPFASTTOU16L3:
	SLA C
	LD E, A
	EX DE, HL
	RET NC
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	RET
