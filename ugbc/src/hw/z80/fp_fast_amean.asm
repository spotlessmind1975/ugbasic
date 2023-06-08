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

FPFASTAMEAN:

	LD B, A
	AND $7F
	JR Z, FPFASTAMEAN_NOOVERFLOW
	CP $7E
	JR Z, FPFASTAMEAN_OVERFLOW

	LD A, C
	AND $7F
	JR Z, FPFASTAMEAN_NOOVERFLOW
	CP $7E
	JR Z, FPFASTAMEAN_OVERFLOW

FPFASTAMEAN_NOOVERFLOW:
	LD A, B
	CALL FPFASTADD
; #IFDEF INCLUDED_FPFASTDIV2
; 	JP FPFASTDIV2
; #ELSE
; #DEFINE INCLUDED_FPFASTDIV2
FPFASTDIV2:
	LD B, A
	AND $7F
	LD A, B
	RET Z

	LD B, A
	AND $7F
	INC A
	LD A, B
	RET M
	DEC A
	RET

FPFASTAMEAN_OVERFLOW:

	LD A, B
	PUSH DE
	PUSH BC
	CALL FPFASTDIV2
	POP BC
	EX (SP), HL
	PUSH AF
	LD A, C
	CALL FPFASTDIV2
	POP BC
	POP DE
	LD C, B
	JP FPFASTADD
