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

FPSINGLEBGI:

	CALL FPPUSHPOP
	PUSH BC

	PUSH DE
	LD DE, FPSCRAP
	LDI
	LDI
	LD A, (HL)
	ADD A, A
	LDI
	LD A, (HL)
	ADC A, A
	LDI
	POP HL

	INC A
	JR Z,FPSINGLEBGI_INFNAN_OP2

; #IF FPSCRAP+4 != FPSCRAP+4
; 	LD DE,FPSCRAP+4
; #ENDIF
	LDI
	LDI
	LD A, (HL)
	ADD A, A
	LDI
	LD A, (HL)
	LDI
	ADC A, A
	JP Z, FPSINGLEBGI_OP1_0
	INC A
	JP Z, FPSINGLEBGI_OP2_INFNAN

	LD A, -11
	; LD BC,FPSCRAP+8
	LD B, D
	LD C, E
	LD HL, FPSCRAP
	CALL FPSINGLEMULPOW2

	LD HL, FPSCRAP
	LD DE, FPSCRAP+4
	LD B, H
	LD C, L
	CALL FPSINGLEAMEAN

	LD HL, FPSCRAP
	LD DE, 15F7H		;D IS 21, E IS -9
	LD BC, FPSCRAP+12
	CALL FPSINGLE_MULU8_DIVPOW2

	LD H, B
	LD L, C
	LD DE, FPSCRAP+8
	CALL FPSINGLESUB

	LD HL, FPSCRAP
	LD DE, FPSCRAP+4
	LD B, D
	LD C, E
	CALL FPSINGLEGEOMEAN

	LD B, H
	LD C, L
	CALL FPSINGLEAMEAN

	LD B, D
	LD C, E
	CALL FPSINGLEGEOMEAN

	LD DE, 0BFBH
	LD B, H
	LD C, L
	CALL FPSINGLE_MULU8_DIVPOW2

	LD DE, FPSCRAP+12
	CALL FPSINGLEADD

	LD DE, FPSCRAP+4
	CALL FPSINGLEADD

	EX DE, HL
	LD HL, FPSINGLE_CONT_1P38427734375
	POP BC
	JP FPSINGLEDIV

FPSINGLE_CONT_1P38427734375: 
    DEFB $00, $30, $B1, $3F	;1.38427734375



FPSINGLEBGI_INFNAN_OP2:
;1/BG(-INF, Y) ==> NAN
	JR C,FPSINGLEBGI_RETURN_NAN
;1/BG(NAN, X) ==> NAN
	EX DE,HL
	DEC HL
	LD C,(HL)
	DEC HL
	LD A,(HL)
	ADD A,A
	DEC HL
	OR (HL)
	DEC HL
	OR (HL)
	JR NZ,FPSINGLEBGI_RETURN_NAN

;1/BG(+INF, 0)		==> NAN
;1/BG(+INF, FIN)	==> 0
;1/BG(+INF, -INF) ==> NAN
;1/BG(+INF, NAN)	==> NAN
;1/BG(+INF, +INF) ==> 0
	EX DE,HL
	LD A,(HL)
	INC HL
	OR (HL)
	INC HL
	LD B,A
	LD A,(HL)
	ADD A,A
	LD D,A
	INC HL
	LD A,(HL)
	ADC A,A
	JR Z,FPSINGLEBGI_RETURN_NAN
;1/BG(+INF, -X) ==> NAN
	JR C,FPSINGLEBGI_RETURN_NAN
	INC A
	JR NZ,FPSINGLEBGI_RETURN_0
;1/BG(+INF, NAN)	==> NAN
	LD A,D
	OR B
	JR NZ,FPSINGLEBGI_RETURN_NAN
FPSINGLEBGI_RETURN_0:
	LD HL,FPSINGLE_CONST_0
	JR FPSINGLEBGI_RETURN

FPSINGLEBGI_OP2_INFNAN:
;1/BG(X,+-INF) ==> 0
;1/BG(X, NAN) ==> NAN
	DEC HL
	DEC HL
	LD A,(HL)
	ADD A,A
	DEC HL
	OR (HL)
	DEC HL
	OR (HL)
	JR Z,FPSINGLEBGI_RETURN_0
FPSINGLEBGI_OP1_0:
; 1/BG(X, 0) ==> NAN
FPSINGLEBGI_RETURN_NAN:
	LD HL,FPSINGLE_CONST_NAN
FPSINGLEBGI_RETURN:
	POP DE
	JP FPMOV4
