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

FPSINGLEMULPOW2:
	
    CALL FPPUSHPOP
	LD D, B
	LD E, C
	LD C, A	;COPY A TO BC, EXTENDING THE SIGN
	ADD A, A
	SBC A, A
	LD B, A
	LDI
	LDI
	INC BC
	INC BC
	LD A, (HL)
	ADD A, A
	LD (DE), A
	INC HL
	LD A, (HL)
	ADC A, A
	JR Z, FPSINGLEMULPOW2_RETURN
	INC A
	JR Z, FPSINGLEMULPOW2_RETURN_INFNAN
	DEC A
	RL L	; SAVE THE SIGN
	ADD A, C
	JR NC, $+3
	INC B

	INC B
	JR Z, FPSINGLEMULPOW2_ZERO
	DJNZ FPSINGLEMULPOW2_RETURN_INFNAN
	DEFB $06 ; START OF `LD B,*` TO EAT THE NEXT BYTE
FPSINGLEMULPOW2_RETURN_INFNAN:
	DEC A
FPSINGLEMULPOW2_RETURN:
	RR L	; SHIFT OUT THE SIGN
	RRA
	EX DE, HL
	RR (HL)
	INC HL
	LD (HL) ,A
	RET

FPSINGLEMULPOW2_INF:
	LD D, -1
	DEFB 1 ;START OF `LD BC,**` TO EAT THE NEXT TWO BYTES
FPSINGLEMULPOW2_ZERO:
	LD D, 0
	RR D
	LD (HL), A
	DEC HL
	LD A, 0
	RRA
	LD (HL), A
	DEC HL
	XOR A
	LD (HL), A
	DEC HL
	LD (HL), A
	RET
