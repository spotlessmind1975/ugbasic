; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                            TIMER ROUTINES ON 8086                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TIMERRUNNING:   db   0x00
TIMERSTATUS:    db   0x00
TIMERCOUNTER:   dw   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
TIMERINIT:      dw   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
TIMERADDRESS:   dw   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

TIMERMANAGER:

    ; First of all, we have to save the actual state of registers

	; PUSH	AF
    ; LD A, (TIMERRUNNING)
    ; CP 0
    ; JR Z, TIMERMANAGERGO
    ; POP     AF
    ; RET

	PUSH AX
    MOV AL, [TIMERRUNNING]
    CMP AL, 0
    JZ TIMERMANAGERGO
    POP AX
    RET

TIMERMANAGERGO:

	; PUSH	BC
	; PUSH	DE
	; PUSH	HL
	; PUSH	IX
	; PUSH	IY
	; EX	AF,AF'
	; PUSH	AF
	; EXX
	; PUSH	BC
	; PUSH	DE
	; PUSH	HL

	PUSH	DX
	PUSH	CX
	PUSH	BX
	PUSH	AX
	PUSH	DI
	PUSH	SI

    ; LD A, 1
    ; LD (TIMERRUNNING), A

    MOV AL, 1
    MOV [TIMERRUNNING], AL
    
    ; loop through every specific timer status
    ; looking to the specific bit in the TIMERSTATUS
    ; control word.
    MOV AL, [TIMERSTATUS]

    ; Up to 8 timers.
    MOV BL, 0
    PUSH AX

TIMERMANAGERL1:
    POP AX

    ; Move the first bit into the carry.
    SAR AL, 1

    ; If the carry is cleared, move to the next timer. 
    JNC TIMERMANAGERL2

    PUSH AX
    PUSH DI
    PUSH SI
    PUSH BX

    ; Retrieve the actual time counter, using the current
    ; index (X-1). The Y will be the offset starting from
    ; the TIMERCOUNTER base address: 
    ;
    ;       TIMERCOUNTER + (X-1) * 2 -> Y = (X-1) * 2
    ;
    MOV AL, BL
    SAL AL, 1
    MOV AH, 0 

    MOV SI, TIMERCOUNTER 
    ADD SI, AX

    ; Now we are going to check if the timer is not zero.
    ; If not zero, we must decrement the counter.
    MOV DX, [SI]
    CMP DX, 0
    JNZ TIMERMANAGERL2AL

    ; Ok the counter is zero. So we must reset to the
    ; value we received previously, and call the routine.

    MOV SI, [TIMERINIT]
    ADD DI, AX
    MOV DX, [SI]

    MOV SI, [TIMERCOUNTER]
    ADD DI, AX
    MOV [SI], DX

TIMERMANAGERJMP2:
    MOV SI, [TIMERADDRESS]
    ADD SI, AX

    ; Now we are going to check if the address
    ; to call is zero. In this case, we must
    ; avoid to jump to it.
    MOV DX, [SI]
    CMP DX, 0
    JNZ TIMERMANAGERJMP2AH

    JP TIMERMANAGERL2AL

TIMERMANAGERJMP2AH:
TIMERMANAGERJMP2AL:
    MOV DI, TIMERADDRESS 
    ADD DI, AX

    PUSH AX
    PUSH SI
    PUSH DI

    MOV DX, [DI]
    MOV SI, DX

    ; Disable timer before calling

    MOV CL, 0
    CALL TIMERSETSTATUS

    CALL [SI]

    POP DI
    POP SI
    POP AX

    ; If we reach this line, we are going to decrement the
    ; counter since it is not zero.
TIMERMANAGERL2AH:
    ; Move to the LSB
TIMERMANAGERL2AL:
    ; 16 bit decrement
    MOV SI, TIMERCOUNTER  
    ADD SI, AX
    MOV DX, [SI]
    DEC DX
    MOV [SI], DX

TIMERMANAGERL2ALD:

    POP BX
    POP SI
    POP DI
    POP AX

    ; If we reach this line, we are going to check the next timer.
TIMERMANAGERL2:

    INC BL
    CMP BL, 8
    JNZ TIMERMANAGERL1

    POP AX
    
    ; Finally, restore the actual state of registers

    MOV AL, 0
    MOV [TIMERRUNNING], AL
    
	POP	SI
	POP	DI
	POP	BX

    RET

; TIMERSETSTATUS(B,C)
TIMERSETSTATUS:
    PUSH AX
    PUSH BX
    MOV AL, 1
    CMP BL, 0
    JZ TIMERSETSTATUSDONE
TIMERSETSTATUSL1:
    SAL AL, 1
    DEC BL
    JNZ TIMERSETSTATUSL1
TIMERSETSTATUSDONE:
    CMP CL, 0
    JZ TIMERSETSTATUS0
TIMERSETSTATUS1:
    PUSH AX
    MOV AL, [TIMERSTATUS]
    MOV BL, AL
    POP AX
    OR AL, BL
    MOV [TIMERSTATUS], AL
    POP BX
    POP AX
    RET
TIMERSETSTATUS0:
    MOV AL, [TIMERSTATUS]
    MOV BL, AL
    POP AX
    XOR AL, 0xFF
    AND AL, BL
    MOV [TIMERSTATUS], AL
    POP BX
    POP AX
    RET

; TIMERSETCOUNTER(B,DX)
TIMERSETCOUNTER:
    PUSH AX
    PUSH BX
    PUSH DX
    PUSH DI

    SAL BL, 1
    MOV BH, 0

    MOV SI, TIMERCOUNTER 
    ADD SI, BX
    MOV [SI], DX

    POP DI
    POP DX
    POP BX
    POP AX

    RET

; TIMERSETINIT(B,DX)
TIMERSETINIT:
    PUSH AX
    PUSH BX
    PUSH DX
    PUSH DI

    SAL BL, 1
    MOV BH, 0

    MOV SI, TIMERINIT
    ADD SI, BX
    MOV [SI], DX

    POP DI
    POP DX
    POP BX
    POP AX

    RET


; TIMERSETADDRESS(B,Dx)
TIMERSETADDRESS:
    PUSH AX
    PUSH BX
    PUSH DX
    PUSH DI

    SAL BL, 1
    MOV BH, 0

    MOV SI, TIMERADDRESS
    ADD SI, BX
    MOV [SI], DX

    POP DI
    POP DX
    POP BX
    POP AX

    RET
