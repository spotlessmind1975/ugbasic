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

FPMUL24:
	PUSH HL
	POP IX
	CALL FP_C_TIMES_BDE
	PUSH HL
	LD L, A
	LD H, C
	EX (SP), HL
	PUSH HL

	LD A, B
	PUSH IX
	POP BC
	LD B, A
	CALL FP_C_TIMES_BDE

	EX (SP), HL
	ADD A, L
	LD L, A
	LD A, C
	ADC A, H
	LD H, A

	LD A, B
	PUSH IX
	POP BC
	LD C, B
	LD B, A
	POP IX

	JR NC, FPMUL24L1
	EX (SP), HL
	INC HL
	EX (SP), HL
FPMUL24L1:
	PUSH HL
	PUSH IX

	CALL FP_C_TIMES_BDE
	DEC SP

	POP DE
	LD B, D
	POP DE
	ADD HL, DE
	LD D, C
	LD E, A
	EX (SP), HL
	ADC HL, DE
	POP DE
	LD A, B
	DEC SP
	POP BC
	RET NC
	INC B
	RET
