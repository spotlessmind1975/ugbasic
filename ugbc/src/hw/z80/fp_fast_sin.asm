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

FPFASTSIN:

	LD B,A

	ADD A, A
	RET Z

	RRCA
	CP $7F
	JR NZ, FPFASTSINL1
	LD H, A
	RET

FPFASTSINL1:

	LD A, B

	LD C, $3C
	LD DE, $45F3
	CALL FPFASTMUL

	LD C, $3D
	LD DE, $0
	CALL FPFASTADD

	CALL FPFASTMOD1

	JP XCOS_STEPIN

FPFASTSIN_RANGE_REDUCED:

	LD C, $41
	LD DE, $9220
	CALL FPFASTMUL

	PUSH HL
	PUSH AF

	CALL FPFASTSQR
	XOR $80

	PUSH HL
	LD C, A
	PUSH BC

	LD C, $38
	LD DE, $0B7A
	CALL FPFASTMUL

	LD C, $3C
	LD DE, $5544
	CALL FPFASTADD

	POP BC
	POP DE
	CALL FPFASTMUL

	LD C, $3F
	LD DE, $0
	CALL FPFASTADD

	POP BC
	POP DE
	LD C, B
	JP FPFASTMUL
