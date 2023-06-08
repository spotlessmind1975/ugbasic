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

FPDIV32_16:

	PUSH BC
	LD A, B
	SRL A
	CPL
	LD B, A
	LD A, C
	RRA
	CPL
	LD C, A
	INC BC
	LD A, D
	ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	LD D, A
	LD A,E
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
	LD E, A
	POP BC
	BIT 0, C
	RET Z

	SBC HL, DE
	RET NC
	ADD HL, BC
	DEC DE
	RET C
	ADD HL, BC
	DEC DE
	RET
