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

FPMUL16:
	LD	A, D
	LD	D, 0
	LD	H, B
	LD	L, C
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT14
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT13
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT12
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT11
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT10
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT9
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT8
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT7
	LD	A, E
 	AND	%11111110
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT6
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT5
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT4
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT3
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT2
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT1
	ADD	A, A
	JR	C, FPMUL_BC_DE_DEHL_BIT0
	RR	E
	RET	C
	LD	H, D
	LD	L, E
	RET

FPMUL_BC_DE_DEHL_BIT14:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT13
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT13:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT12
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT12:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT11
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT11:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT10
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT10:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT9
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT9:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT8
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT8:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT7
	ADD	HL, BC
	ADC	A, D
FPMUL_BC_DE_DEHL_BIT7:
	LD	D, A
	LD	A, E
	AND	%11111110
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT6
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT6:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT5
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT5:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT4
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT4:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT3
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT3:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT2
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT2:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT1
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT1:
	ADD	HL, HL
	ADC	A, A
	JR	NC, FPMUL_BC_DE_DEHL_BIT0
	ADD	HL, BC
	ADC	A, 0
FPMUL_BC_DE_DEHL_BIT0:
	ADD	HL, HL
	ADC	A, A
	JR	C, FPMUL_BC_DE_DEHL_FUNKYCARRY
	RR	E
	LD	E, A
	RET	NC
	ADD	HL, BC
	RET	NC
	INC	E
	RET	NZ
	INC	D
	RET

FPMUL_BC_DE_DEHL_FUNKYCARRY:
	INC	D
	RR	E
	LD	E, A
	RET	NC
	ADD	HL, BC
	RET	NC
	INC	E
	RET
