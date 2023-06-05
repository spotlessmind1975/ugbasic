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

FPFASTCOS:

	ADD A,A
	RET Z

	RRCA
	CP $7F
	JR NZ, FPFASTCOSL1
	LD H,A
	RET
FPFASTCOSL1:

	LD C, $3C
	LD DE, $45F3
	CALL FPFASTMUL

	LD C, $3E
	LD DE, $0
	CALL FPFASTADD

	CALL FPFASTMOD1

XCOS_STEPIN:

	LD C, $BE
	LD DE, $0
	CALL FPFASTADD

	AND $7F

	CP $3D
	JR C, FPFASTCOSL2
	XOR 80H
	LD C, $3E
	LD DE, $0
	CALL FPFASTADD
	CALL FPFASTCOSL2
	XOR 80H
	RET
FPFASTCOSL2:

	CP $3C
	JR C, FPFASTCOSL3
	XOR $80
	LD C, $3D
	LD DE, $0
	CALL FPFASTADD
	JP FPFASTSIN_RANGE_REDUCED

FPFASTCOSL3:

FPFASTCOS_RANGE_REDUCED:

	LD C, $41
	LD DE, $9220
	CALL FPFASTMUL

	CALL FPFASTSQR
	XOR $80

	PUSH HL
	LD C, A
	PUSH BC

	LD C, $35
	LD DE, $65A9
	CALL FPFASTMUL

	LD C, $3A
	LD DE, $5549
	CALL FPFASTADD

	POP BC
	POP DE
	PUSH DE
	PUSH BC
	CALL FPFASTMUL

	LD C, $3E
	LD DE, $0
	CALL FPFASTADD

	POP BC
	POP DE
	CALL FPFASTMUL

	LD C, $3F
	LD DE, $0
	JP FPFASTADD
