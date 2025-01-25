; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers   *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                         SCROLL TEXT ROUTINES FOR GB                         *
;*                                                                             *
;*                          by Marco Spedaletti                                *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLTUP:

    LD A, (CONSOLEW)
    LD B, A
    LD A, 32
    SBC B

    LD (IXLR), A

    LD HL, _SCRN0

    LD A, (CONSOLEY1)
    CP 0
    JR Z, VSCROLLTUPY0

    LD C, A
VSCROLLTUPYL1:
    ADD HL, 32
    DEC C
    JR NZ, VSCROLLTUPYL1

VSCROLLTUPY0:
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    ADD HL, 32

    LD A, (CONSOLEH)
    DEC A
    CP 0
    JR Z, VSCROLLTUPDONE
    LD B, A
VSCROLLTUPL1A:
    LD A, (CONSOLEW)
    LD C, A
VSCROLLTUPL1:
    CALL WAITSTATE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC C
    JR NZ, VSCROLLTUPL1
    PUSH BC
    LD HL, DE
    LD B, 0
    LD A, (IXLR)
    LD C, A
    ADD HL, BC
    POP BC
    LD DE, HL
    ADD HL, 32

    DEC B
    JR NZ, VSCROLLTUPL1A
VSCROLLTUPDONE:

    LD A, (CONSOLEW)
    LD C, A
VSCROLLTUPCL1:
    CALL WAITSTATE
    LD A, (EMPTYTILE)
    LD (DE), A
    INC DE
    DEC C
    JR NZ, VSCROLLTUPCL1

    RET
