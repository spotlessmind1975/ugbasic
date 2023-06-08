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

FPSQRT32:
	LD HL, (FPSCRAP+10+2)
	LD IX, (FPSCRAP+10)
	CALL FPSQRTHLIX
	LD (FPSCRAP+8+6), DE
	LD B, D
	LD C, E
	LD DE, (FPSCRAP+12+2)

	RRA
	RR H
	RR L
	RR D
	RR E
	LD IXH, D
	LD IXL, E 

	OR A
	SBC HL, BC
	JR Z, FPSQRT32_HIGHER_PREC
	ADD HL, BC

	CALL FPDIV32_16

	LD (FPSCRAP+8+4), DE
	PUSH HL
	LD B, D
	LD C, E
	CALL FPMUL16
	LD B, H
	LD C, L

	LD HL, (FPSCRAP+12)
	LD A, (FPSCRAP+12+2)
	AND 1
	SBC HL, BC
	LD B, H
	LD C, L

	RRA
	POP HL
	ADC HL, HL
	RLA
	SBC HL, DE
	SBC A, 0
	RET

FPSQRT32_HIGHER_PREC:

	ADD HL, BC
	LD DE, (FPSCRAP+12+2)
	LD A, D
	AND $80
	ADD A, A
	ADC HL, HL
	ADC A, A
	EX DE, HL
	LD BC, $0001

	SBC HL, BC
	EX DE, HL
	LD BC, $FFFE
	SBC HL, BC
	SBC A, 0

	INC C
	LD (FPSCRAP+8+4), BC
	LD B, D
	LD C, E
	RET

FPSQRTHL:

	LD DE, 05040H	; 10
	LD A, H				; 4
	SUB E				 ; 4
	JR NC, FPSQ7		 ;\
	ADD A, E			 ; | BRANCH 1: 12CC
	LD D, 16			 ; | BRANCH 2: 18CC
FPSQ7:						;/

; ----------

	CP D					; 4
	JR C, FPSQ6			;\
	SUB D				 ; | BRANCH 1: 12CC
	SET 5, D			 ; | BRANCH 2: 19CC
FPSQ6:						;/

; ----------
	RES 4, D			 ; 8
	SRL D				 ; 8
	SET 2, D			 ; 8
	CP D					; 4
	JR C, FPSQ5			;\
	SUB D				 ; | BRANCH 1: 12CC
	SET 3, D			 ; | BRANCH 2: 19CC
FPSQ5:						;/
	SRL D				 ; 8

; ----------

	INC A				 ; 4
	SUB D				 ; 4
	JR NC, FPSQ4		 ;\
	DEC D				 ; | BRANCH 1: 12CC
	ADD A, D			 ; | BRANCH 2: 19CC
	DEC D				 ; | <-- THIS RESETS THE LOW BIT OF D, SO `SRL D` RESETS CARRY.
FPSQ4:						;/
	SRL D				 ; 8
	LD H, A				; 4

; ----------

	LD A, E				; 4
	SBC HL, DE		 ; 15
	JR NC, FPSQ3		 ;\
	ADD HL, DE		 ; | 12CC OR 18CC
FPSQ3:						;/
	CCF					 ; 4
	RRA					 ; 4
	SRL D				 ; 8
	RRA					 ; 4

; ----------

	LD E, A				; 4
	SBC HL, DE		 ; 15
	JR C, FPSQ2			;\
	OR 20H				; | BRANCH 1: 23CC
	DEFB 254				; |	 <-- START OF `CP *` WHICH IS 7CC TO SKIP THE NEXT BYTE.
FPSQ2:						; | BRANCH 2: 21CC
	ADD HL, DE		 ;/

	XOR 18H			 ; 7
	SRL D				 ; 8
	RRA					 ; 4

; ----------

	LD E, A				; 4
	SBC HL, DE		 ; 15
	JR C, FPSQ1			;\
	OR 8					; | BRANCH 1: 23CC
	DEFB 254				; |	 <-- START OF `CP *` WHICH IS 7CC TO SKIP THE NEXT BYTE.
FPSQ1:						; | BRANCH 2: 21CC
	ADD HL, DE		 ;/

	XOR 6				 ; 7
	SRL D				 ; 8
	RRA					 ; 4

; ----------

	LD E, A				; 4
	SBC HL, DE		 ; 15
	JR NC, FPSQ1L1			;		\
	ADD HL, DE		 ; 15	|
	SRL D				 ; 8	 |
	RRA					 ; 4	 | BRANCH 1: 38CC
	RET					 ; 10	| BRANCH 2: 40CC
FPSQ1L1:							;		 |
	INC A				 ; 4	 |
	SRL D				 ; 8	 |
	RRA					 ; 4	 |
	RET					 ; 10 /

FPSQRTHLIX:

	CALL FPSQRTHL	 ;EXPECTS RETURNS A AS SQRT, HL AS REMAINDER, D = 0
	ADD A, A
	LD E, A
	RL D

	LD A, IXH
	SLL E 
    RL D
	ADD A, A
    ADC HL, HL
	ADD A, A
    ADC HL, HL
	SBC HL, DE
	JR NC, FPSQRTHLIXL1
	ADD HL, DE
	DEC E
	DEFB $FE		 ;START OF `CP *`
FPSQRTHLIXL1:
	INC E

	SLL E
    RL D
	ADD A, A
    ADC HL, HL
	ADD A, A
    ADC HL, HL
	SBC HL, DE
	JR NC, FPSQRTHLIXL2
	ADD HL, DE
	DEC E
	DEFB $FE		 ;START OF `CP *`
FPSQRTHLIXL2:
	INC E

	SLL E
    RL D
	ADD A, A
    ADC HL, HL
	ADD A, A
    ADC HL, HL
	SBC HL, DE
	JR NC, FPSQRTHLIXL3
	ADD HL, DE
	DEC E
	DEFB $FE		 ;START OF `CP *`
FPSQRTHLIXL3:
	INC E

	SLL E
    RL D
	ADD A, A
    ADC HL, HL
	ADD A, A
    ADC HL, HL
	SBC HL, DE
	JR NC, FPSQRTHLIXL4
	ADD HL, DE
	DEC E
	DEFB $FE		 ;START OF `CP *`
FPSQRTHLIXL4:
	INC E

	LD A, IXL
	SLL E 
    RL D
	ADD A, A
    ADC HL, HL
	ADD A, A
    ADC HL, HL
	SBC HL, DE
	JR NC, FPSQRTHLIXL5
	ADD HL, DE
	DEC E
	DEFB $FE		 ;START OF `CP *`
FPSQRTHLIXL5:
	INC E

	SLL E 
    RL D
	ADD A, A
    ADC HL, HL
	ADD A, A
    ADC HL, HL
	SBC HL, DE
	JR NC, FPSQRTHLIXL6
	ADD HL, DE
	DEC E
	DEFB $FE		 ;START OF `CP *`
FPSQRTHLIXL6:
	INC E

FPSQRT32_ITER15:

	SLL E
    RL D			;SLA E \ RL D \ INC E
	ADD A, A
	ADC HL, HL
	ADD A, A
	ADC HL, HL			 ;THIS MIGHT OVERFLOW!
	JR C, FPSQRT32_ITER15_BR0
;
	SBC HL, DE
	JR NC, FPSQRT32_ITER15L1
	ADD HL, DE
	DEC E
	JR SQRT32_ITER16
SQRT32_ITER15_BR0:
	OR A
	SBC HL, DE
FPSQRT32_ITER15L1:
	INC E

FPSQRT32_ITER16:
	ADD A, A
	LD B, A				;EITHER 0X00 OR 0X80
	ADC HL, HL
	RLA
	ADC HL, HL
	RLA
	SBC HL, DE
    SBC A, B
	INC E
	OR A
	SBC HL, DE
    SBC A, B
	RET P
	ADD HL, DE
	ADC A, B
	DEC E
	ADD HL, DE
	ADC A, B
	RET

FPSQRT24_MANT:
	PUSH BC
	POP IX
	EX DE, HL
	CALL FPSQRTHLIX
	RRA
	LD A, H
	RES 0,L 
    JR C, $+5
    CP D
    JR C, $+4
    SUB D
    INC L
	SLA L
    RLA
    JR C, $+5
    CP D
    JR C, $+4
    SUB D
    INC L
	SLA L
    RLA
    JR C, $+5
    CP D
    JR C, $+4
    SUB D
    INC L
	SLA L
    RLA
    JR C, $+5
    CP D
    JR C, $+4
    SUB D 
    INC L
	SLA L
    RLA
    JR C, $+5
    CP D
    JR C, $+4
    SUB D
    INC L
	SLA L
    RLA
    JR C, $+5
    CP D
    JR C, $+4
    SUB D
    INC L
	SLA L
    RLA
    JR C, $+5
    CP D
    JR C, $+4
    SUB D
    INC L
	SLA L 
    RLA
    JR C, $+5
    CP D
    RET C
    SUB D
    INC L
	RET