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
;*                           HORIZONTAL SCREEN SCROLL ON CPC                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLSCREEN:
    CP $80
    JP C, HSCROLLSCREENR

    LD A, (CONSOLEHB)
    LD C, A
    LD B, 0
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

HSCROLLSCREENL1:

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

    INC HL

    LD A, (CONSOLEWB)
    LD C, A
    LD B, 0
    LDIR

    POP HL
    POP BC

    INC HL
    INC HL
    DEC C
    JP NZ, HSCROLLSCREENL1

    RET

HSCROLLSCREENR:

    LD A, (CONSOLEHB)
    LD C, A
    LD B, 0
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

HSCROLLSCREENRL1:

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

    PUSH DE

    LD HL, DE
    LD A, (CONSOLEWB)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    DEC HL

    LD A, (CONSOLEWB)
    LD C, A
    LD B, 0
    LDDR

    POP DE
    LD (DE), 0

    POP HL
    POP BC

    INC HL
    INC HL
    DEC C
    JP NZ, HSCROLLSCREENRL1

    RET    