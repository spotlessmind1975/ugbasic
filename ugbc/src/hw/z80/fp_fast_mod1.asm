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

FPFASTMOD1:

	LD C,A

	ADD A,A
	RET Z

	CP $FE
	RRCA
	JR NZ, FPFASTMOD1L1
	LD H, A
	RET

FPFASTMOD1L1:

	CP 63
	JR C, MOD_FINISHED

	SUB 63+16
	ADD A, 16
	JR C, FPFASTMOD1L2
	XOR A
	RET

FPFASTMOD1L2:

	LD B, A
	JR Z, FPFASTMOD1L3
	ADD HL, HL
	DJNZ $-1
FPFASTMOD1L3:

	LD A, H
	OR L
	RET Z
	LD A, 63
	DEC A
	ADD HL, HL
	JR NC, $-2
MOD_FINISHED:
	SLA C
	RET NC
	LD C, 63
	LD DE, 0
	JP FPFASTRSUB
