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


FPDIV24_24:
	XOR A
	SUB E
	LD E, A

	LD A, 0
	SBC A, D
	LD D, A

	SBC A, A
	SUB A, C
	LD C, A

	LD A, B
	CALL FPDIV24_24_SUB_1
	CALL FPDIV24_24_SUB_8
	PUSH BC
	CALL FPDIV24_24_SUB_8
	PUSH BC
	CALL FPDIV24_24_SUB_8

	POP DE
	LD E,B
	POP BC
	RET

FPDIV24_24_SUB_8:
	CALL FPDIV24_24_SUB_4
FPDIV24_24_SUB_4:
	CALL FPDIV24_24_SUB_2
FPDIV24_24_SUB_2:
	CALL FPDIV24_24_SUB_1
FPDIV24_24_SUB_1:
	RL B
	ADD HL, HL
	ADC A, A
	JR C, FPDIV24_24_SUB_OVERFLOW
	ADD HL, DE
	ADC A, C
	RET C
	SBC HL, DE
	SBC A, C
	RET
FPDIV24_24_SUB_OVERFLOW:
	ADD HL, DE
	ADC A, C
	SCF
	RET
