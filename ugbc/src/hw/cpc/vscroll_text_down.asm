; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                          VERTICAL SCROLL ON CPC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLTDOWN:

    LD A, (CONSOLEHB)
    SUB 1
    LD C, A
    LD B, 0
    LD HL, PLOTVBASE
    ADD HL, BC
    ADD HL, BC

@IF verticalOverlapRequired

    LD A, IYL
    CP 0
    JR Z, VSCROLLTDOWNNOW

VSCROLLTDOWNW:

    PUSH HL
    PUSH DE
    PUSH BC

    LD HL, PLOTVBASE
    LD A, (CONSOLEY2)
    LD E, A
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE

    LD DE, VSCROLLBUFFERLINE

    LD C, 8

VSCROLLTDOWNWL1:
    
    PUSH BC
    PUSH HL

    PUSH DE

    LD E, (HL)
    INC HL
    LD D, (HL)
    LD A, (XCURSYS)
    PUSH AF
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD (COPYOFTEXTADDRESS), DE
    CALL TEXTATPIXPOSH
    LD DE, (COPYOFTEXTADDRESS)
    POP AF
    LD (XCURSYS), A
    LD HL, DE
    POP DE

    LD A, IXL
    LD C, A
    LD B, 0
    LDIR

    POP HL
    POP BC

    INC HL
    INC HL

    DEC C
    JR NZ, VSCROLLTDOWNWL1

    POP BC
    POP DE
    POP HL

VSCROLLTDOWNNOW:

@ENDIF

    LD A, (CONSOLEY1)
    LD E, A
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE

    LD A, (CONSOLEHB)
    SUB 8
    LD C, A
    LD B, 0

VSCROLLTDOWNL1:

    PUSH BC
    PUSH HL

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    INC HL

    PUSH HL    
    LD HL, DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    POP HL

    AND 0
    LD BC, 18
    SBC HL, BC

    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A
    LD HL, BC

    PUSH DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE

    LD A, (CONSOLEW)
    LD C, A
    LD B, 0
    LDIR

    POP HL
    POP BC

    DEC HL
    DEC HL
    DEC C
    JP NZ, VSCROLLTDOWNL1

    LD HL, PLOTVBASE

    LD A, (CONSOLEY1)
    LD E, A
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE

    DEC HL
    DEC HL

    LD BC, 8

VSCROLLTDOWNL2:

@IF verticalOverlapRequired

    LD A, IYL
    CP 0
    JR Z, VSCROLLDOWNREFILLNOW

VSCROLLDOWNREFILLW:

    PUSH HL
    PUSH DE
    PUSH BC

    LD HL, PLOTVBASE

    LD A, (CONSOLEY1)
    LD E, A
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE

    LD IY, VSCROLLBUFFERLINE

    LD C, 8

VSCROLLDOWNREFILLWL1:
    
    PUSH BC
    PUSH HL

    LD E, (HL)
    INC HL
    LD D, (HL)
    LD A, (XCURSYS)
    PUSH AF
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD (COPYOFTEXTADDRESS), DE
    CALL TEXTATPIXPOSH
    LD DE, (COPYOFTEXTADDRESS)
    POP AF
    LD (XCURSYS), A
        
    PUSH IY
    POP HL

    LD A, IXL
    LD C, A
    LD B, 0
    LDIR

    PUSH HL
    POP IY

    POP HL
    POP BC

    INC HL
    INC HL

    DEC C
    JR NZ, VSCROLLDOWNREFILLWL1

    POP BC
    POP DE
    POP HL

    JP VSCROLLDOWNREFILLDONE

@ENDIF

VSCROLLDOWNREFILLNOW:

    PUSH BC
    PUSH HL

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    INC HL

    LD HL, DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL

    LD HL, DE

    LD A, (CONSOLEW)
    LD C, A
    LD B, 0

    LD A, 0
VSCROLLTDOWNL2L:
    LD (HL), A
    INC HL
    DEC C
    JR NZ, VSCROLLTDOWNL2L

    POP HL
    POP BC

    INC HL
    INC HL
    DEC C
    JP NZ, VSCROLLDOWNREFILLNOW

VSCROLLDOWNREFILLDONE:

    RET