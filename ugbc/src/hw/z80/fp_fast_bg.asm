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

FPFASTBG:

	PUSH AF
	PUSH HL

	PUSH BC
	PUSH DE

	CALL FPFASTAMEAN

	POP DE
	POP BC

	PUSH AF
	PUSH HL

	CALL FPFASTGEOMEAN

	POP DE
	POP BC

	PUSH AF
	PUSH HL

	LD A,B
	EX DE,HL
	CALL FPFASTMUL3
	LD B, 3
	CALL FPFASTDIV_POW2

	POP DE
	POP BC
	LD C, B

	CALL FPFASTADD

	POP DE
	POP BC

	PUSH AF
	PUSH HL

	LD A, B
	EX DE, HL
	LD B, 5
	CALL FPFASTDIV_POW2

	POP DE
	POP BC
	LD C, B

	CALL FPFASTADD

	EX DE, HL
	LD C, A
	LD A, $3F
    LD HL, 26624	;45/32
	JP FPFASTDIV