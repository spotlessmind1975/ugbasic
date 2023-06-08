; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      STARTUP ROUTINE FOR C128Z                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	DEFB $01, $1C, $0F, $1C, $00, $00, $FE, $02
	DEFB $30, $3A, $9E, $37, $31, $38, $35, $00
	DEFB $00, $00, $78, $A9, $C3, $8D, $EE, $FF
	DEFB $A9, $2F, $8D, $EF, $FF, $A9, $1C, $8D
	DEFB $F0, $FF, $A9, $3E, $8D, $00, $FF, $A9
	DEFB $B0, $8D, $05, $D5, $EA, $EA, $EA, $EA

	JP CODESTART

; IRQTIMERVOID:
; 	RET

; C128ZISVC:
; 	PUSH	AF
; 	PUSH	BC
; 	PUSH	DE
; 	PUSH	HL
; 	PUSH	IX
; 	PUSH	IY
; 	EX	AF,AF'
; 	PUSH	AF
; 	EXX
; 	PUSH	BC
; 	PUSH	DE
; 	PUSH	HL
;     LD A, (C128ZTIMER2)
;     DEC A
;     LD (C128ZTIMER2), A
;     CP 0
;     JR NZ,IRQVECTORSKIP
;     LD A,6
;     LD (C128ZTIMER2), A
;     LD HL,(C128ZTIMER)
;     INC HL
;     LD (C128ZTIMER),HL
; 	CALL MUSICPLAYER
; 	LD A, (EVERYCOUNTER)
; 	CP 0
; 	JR Z, IRQTIMERADDR2
; 	DEC A
; 	LD (EVERYCOUNTER), A
; 	JP IRQVECTORSKIP
; IRQTIMERADDR2:
; 	LD A, (EVERYSTATUS)
; 	CP 0
; 	JR Z, IRQVECTORSKIP
; 	LD A, (EVERYTIMING)
; 	LD (EVERYCOUNTER), A
; IRQTIMERADDR:
; 	CALL IRQTIMERVOID
; IRQVECTORSKIP:
; 	POP	HL
; 	POP	DE
; 	POP	BC
; 	EXX
; 	POP	AF
; 	EX	AF,AF'
; 	POP	IY
; 	POP	IX
; 	POP	HL
; 	POP	DE
; 	POP	BC
; 	POP	AF
;     EI
;     RET   

C128ZSTARTUP:

	LD A, $FF
    PUSH BC
    LD BC, $DC02
    OUT (C), A
    POP BC

	LD A, $00
    PUSH BC
    LD BC, $DC03
    OUT (C), A
    POP BC

    RET
