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

FPSINGLEMOD1:

	CALL FPPUSHPOP
	PUSH BC
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD A, (HL)
	RLCA
	SCF
	RRA
	LD C, A
	INC HL
	LD A, (HL)
	ADC A, A
	POP HL

	JR Z, FPSINGLEMOD1_RETURN_0

	INC A
	JR Z, FPSINGLEMOD1_RETURN_NAN
	JR NC, FPSINGLEMOD1_POS

	CALL FPSINGLEMOD1_POS

	RET Z
	DEC HL
	DEC HL
	DEC HL
	LD B, H
	LD C, L
	LD DE, FPSINGLE_CONST_1
	JP FPSINGLERSUB

FPSINGLEMOD1_POS:

	SUB 128
	JR C, FPSINGLEMOD1_MODDED

	SUB 7
	JR C, FPSINGLEMOD1_SHIFT_BITS
	LD C, D
	LD D, E
	LD E, 0
	SUB 8
	JR C, FPSINGLEMOD1_SHIFT_BITS
	LD C, D
	LD D, E
	SUB 8
	JR NC, FPSINGLEMOD1_RETURN_0

FPSINGLEMOD1_SHIFT_BITS:
	ADD A, 8
	LD B, A
	EX DE, HL
	LD A, C
	JR Z, FPSINGLEMOD1_SHIFT_BITS_DONE

FPSINGLEMOD1_LOOP:
	ADD HL, HL
	ADC A, A
	DJNZ FPSINGLEMOD1_LOOP

FPSINGLEMOD1_SHIFT_BITS_DONE:
	DEC B
	LD C, A
	OR H
	OR L
	EX DE, HL
	JR Z, FPSINGLEMOD1_RETURN_0
	EX DE, HL
	LD A, C
	OR A
	JR FPSINGLEMOD1_NORM_START

FPSINGLEMOD1_NORM_LOOP:
	DEC B
	ADD HL, HL
	ADC A, A
FPSINGLEMOD1_NORM_START:
	JP P, FPSINGLEMOD1_NORM_LOOP

	EX DE, HL
	LD C, A
	LD A, B
FPSINGLEMOD1_MODDED:

	ADD A, 127
	LD (HL), E
	INC HL
	LD (HL), D
	SRL A
	RL C
	RRC C
	INC HL
	LD (HL), C
	INC HL
	LD (HL), A
	OR A
	RET

FPSINGLEMOD1_RETURN_NAN:
	DEC A
	DEFB $FE

FPSINGLEMOD1_RETURN_0:

	XOR A
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	LD (HL), A
	RET
