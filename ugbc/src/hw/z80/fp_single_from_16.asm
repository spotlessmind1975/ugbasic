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

FPSINGLEFROM16S:
;
	CALL FPPUSHPOP

	XOR A
	LD (BC), A
	INC BC

	LD A, L
	OR H
	LD D, A
	JR Z, I16TOF32_FINISH

	LD A, H
	OR A
	JP P, $+10
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	SCF

	RLA
	LD D, $7F+16

	DEC D
	ADD HL, HL
	JR NC, $-2

	RRA
	RR D
	RR H
	RR L

	LD A, L
I16TOF32_FINISH:
	LD (BC), A
	INC BC
	LD A, H
	LD (BC), A
	INC BC
	LD A, D
	LD (BC), A
	RET

FPSINGLEFROM16U:

	CALL FPPUSHPOP

	XOR A
	LD (BC), A
	INC BC

	LD A, L
	OR H
	LD D, A
	JR Z, U16TOFPSINGLE_FINISH

	LD D, $7F+16

	DEC D
	ADD HL, HL
	JR NC, $-2

	SRL D
	RR H
	RR L

	LD A, L
U16TOFPSINGLE_FINISH:
	LD (BC), A
	INC BC
	LD A, H
	LD (BC), A
	INC BC
	LD A, D
	LD (BC), A
	RET
