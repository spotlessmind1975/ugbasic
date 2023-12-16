; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                            TIMER ROUTINES ON ZX                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TIMERMANAGER:

    ; First of all, we have to save the actual state of registers

	PUSH	AF
    LD A, (TIMERRUNNING)
    CP 0
    JR Z, TIMERMANAGERGO
    POP     AF
    RET

TIMERMANAGERGO:

	PUSH	BC
	PUSH	DE
	PUSH	HL
	PUSH	IX
	PUSH	IY
	EX	AF,AF'
	PUSH	AF
	EXX
	PUSH	BC
	PUSH	DE
	PUSH	HL

    LD A, 1
    LD (TIMERRUNNING), A

    ; loop through every specific timer status
    ; looking to the specific bit in the TIMERSTATUS
    ; control word.
    LD A, (TIMERSTATUS)

    ; Up to 8 timers.
    LD B, 0
    PUSH AF

TIMERMANAGERL1:
    POP AF

    ; Move the first bit into the carry.
    SRA A

    ; If the carry is cleared, move to the next timer. 
    JR NC, TIMERMANAGERL2

    PUSH AF
    PUSH DE
    PUSH HL
    PUSH BC

    ; Retrieve the actual time counter, using the current
    ; index (X-1). The Y will be the offset starting from
    ; the TIMERCOUNTER base address: 
    ;
    ;       TIMERCOUNTER + (X-1) * 2 -> Y = (X-1) * 2
    ;
    LD A, B
    SLA A
    LD E, A
    LD A, 0
    LD D, A 

    LD HL, TIMERCOUNTER 
    ADD HL, DE

    ; Now we are going to check if the timer is not zero.
    ; If not zero, we must decrement the counter.
    INC HL
    LD A, (HL)
    CP 0
    JR NZ, TIMERMANAGERL2AH
    DEC HL
    LD A, (HL)
    CP 0
    JR NZ, TIMERMANAGERL2AL

    ; Ok the counter is zero. So we must reset to the
    ; value we received previously, and call the routine.

    LD HL, TIMERINIT
    ADD HL, DE
    LD A, (HL)
    LD IXL, A
    INC HL
    LD A, (HL)
    LD IXH, A

    LD HL, TIMERCOUNTER 
    ADD HL, DE
    LD A, IXL
    LD (HL), A
    INC HL
    LD A, IXH
    LD (HL), A

TIMERMANAGERJMP2:
    LD HL, TIMERADDRESS
    ADD HL, DE

    ; Now we are going to check if the address
    ; to call is zero. In this case, we must
    ; avoid to jump to it.
    INC HL
    LD A, (HL)
    CP 0
    JR NZ, TIMERMANAGERJMP2AH
    DEC HL
    LD A, (HL)
    CP 0
    JR NZ, TIMERMANAGERJMP2AL

    JP TIMERMANAGERL2AL

TIMERMANAGERJMP:
    JP (HL)

TIMERMANAGERJMP2AH:
TIMERMANAGERJMP2AL:
    LD HL, TIMERADDRESS
    ADD HL, DE
    LD A, (HL)
    LD IXL, A
    INC HL
    LD A, (HL)
    LD IXH, A

    PUSH AF
    PUSH HL
    PUSH DE
    
    LD A, IXL
    LD L, A
    LD A, IXH
    LD H, A

    CALL TIMERMANAGERJMP

    POP DE
    POP HL
    POP AF

    ; If we reach this line, we are going to decrement the
    ; counter since it is not zero.
TIMERMANAGERL2AH:
    ; Move to the LSB
TIMERMANAGERL2AL:
    ; 16 bit decrement
    LD HL, TIMERCOUNTER 
    ADD HL, DE
    PUSH DE
    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    DEC HL
    DEC DE
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
    POP DE
TIMERMANAGERL2ALD:

    POP BC
    POP HL
    POP DE
    POP AF

    ; If we reach this line, we are going to check the next timer.
TIMERMANAGERL2:

    INC B
    PUSH AF
    LD A, B
    CP 8
    JR NZ, TIMERMANAGERL1
    POP AF
    
    ; Finally, restore the actual state of registers

    LD A, 0
    LD (TIMERRUNNING), A
    
	POP	HL
	POP	DE
	POP	BC
	EXX
	POP	AF
	EX	AF,AF'
	POP	IY
	POP	IX
	POP	HL
	POP	DE
	POP	BC
	POP	AF

    RET

; TIMERSETSTATUS(B,C)
TIMERSETSTATUS:
    LD A, B
    CP 0
    LD A, 1
    JR Z, TIMERSETSTATUSDONE
TIMERSETSTATUSL1:
    SLA A
    DEC B
    JR NZ, TIMERSETSTATUSL1
TIMERSETSTATUSDONE:
    PUSH AF
    LD A, C
    CP 0
    JR Z, TIMERSETSTATUS0
TIMERSETSTATUS1:
    LD A, (TIMERSTATUS)
    LD B, A
    POP AF
    OR B
    LD (TIMERSTATUS), A
    RET
TIMERSETSTATUS0:
    LD A, (TIMERSTATUS)
    LD B, A
    POP AF
    XOR $FF
    AND B
    LD (TIMERSTATUS), A
    RET

; TIMERSETCOUNTER(B,IX)
TIMERSETCOUNTER:
    PUSH AF
    PUSH BC
    PUSH IX
    PUSH DE

    LD A, B
    SLA A
    LD E, A
    LD A, 0
    LD D, A 

    LD HL, TIMERCOUNTER 
    ADD HL, DE
    LD A, IXL
    LD (HL), A
    INC HL
    LD A, IXH
    LD (HL), A

    POP DE
    POP IX
    POP BC
    POP AF

    RET

; TIMERSETINIT(B,IX)
TIMERSETINIT:
    PUSH AF
    PUSH BC
    PUSH IX
    PUSH DE

    LD A, B
    SLA A
    LD E, A
    LD A, 0
    LD D, A 

    LD HL, TIMERINIT
    ADD HL, DE
    LD A, IXL
    LD (HL), A
    INC HL
    LD A, IXH
    LD (HL), A

    POP DE
    POP IX
    POP BC
    POP AF

    RET


; TIMERSETADDRESS(B,IX)
TIMERSETADDRESS:
    PUSH AF
    PUSH BC
    PUSH IX
    PUSH DE

    LD A, B
    SLA A
    LD E, A
    LD A, 0
    LD D, A 

    LD HL, TIMERADDRESS
    ADD HL, DE
    LD A, IXL
    LD (HL), A
    INC HL
    LD A, IXH
    LD (HL), A

    POP DE
    POP IX
    POP BC
    POP AF

    RET

