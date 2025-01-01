; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                          HSCROLL FOR ZX SPECTRUM                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                           HORIZONTAL SCREEN SCROLL ON ZX                    *
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
    LD HL, ROWSADDRESS

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

    PUSH HL
    POP IX

    LD HL, COLRADDRESS

    LD A, (CONSOLEY1)
    LD E, A
    LD D, 0
    ADD HL, DE
    ADD HL, DE

    PUSH HL
    POP IY

HSCROLLSCREENL1:

    PUSH BC

    PUSH IX
    POP HL

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

    LD A, (CONSOLEW)
    LD C, A
    LD B, 0
    LDIR

    POP HL

    INC HL
    INC HL

    PUSH HL
    POP IX

    POP BC
    
    DEC C

    LD A, C
    AND $7
    CP 0
    JR NZ, HSCROLLSCREENL1

    PUSH BC

    PUSH IY
    POP HL

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

    LD A, (CONSOLEW)
    LD C, A
    LD B, 0
    LDIR

    POP HL

    INC HL
    INC HL

    PUSH HL
    POP IY

    POP BC
    
    LD A, C
    CP 0
    JR NZ, HSCROLLSCREENL1

    RET

HSCROLLSCREENR:

    ; text

    LD A, (CONSOLEHB)
    LD C, A
    LD B, 0
    LD HL, ROWSADDRESS

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

    PUSH HL
    POP IX

    ; text

    LD HL, COLRADDRESS

    LD A, (CONSOLEY1)
    LD E, A
    LD D, 0
    ADD HL, DE
    ADD HL, DE

    PUSH HL
    POP IY

HSCROLLSCREENRL1:

    PUSH BC

    PUSH IX
    POP HL

    PUSH HL

    ; text

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
    LD A, (CONSOLEW)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    DEC HL

    LD A, (CONSOLEW)
    LD C, A
    LD B, 0
    LDDR

    POP DE
    LD A, (EMPTYTILE)
    LD (DE), A

    POP HL
    POP BC

    INC HL
    INC HL

    PUSH HL
    POP IX

    ; color

    DEC C
    LD A, C
    AND $07
    JR NZ, HSCROLLSCREENRL1

    PUSH BC

    PUSH IY
    POP HL

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
    LD A, (CONSOLEW)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    DEC HL

    LD A, (CONSOLEW)
    LD C, A
    LD B, 0
    LDDR

    POP DE
    LD (DE), 0

    POP HL
    POP BC

    INC HL
    INC HL

    PUSH HL
    POP IY

    LD A, C
    CP 0
    JP NZ, HSCROLLSCREENRL1

    RET    

