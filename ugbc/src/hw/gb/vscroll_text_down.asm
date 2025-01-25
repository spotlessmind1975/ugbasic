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

VSCROLLTDOWN:
    
    LD A, (CONSOLEW)
    LD B, A
    LD A, 32
    SBC B

    LD HL, _SCRN0 + (18*32) - 32
    LD DE, _SCRN0 + (18*32)

    LD (IXLR), A

    LD HL, _SCRN0

    LD A, (CONSOLEY2)
    CP 0
    JR Z, VSCROLLTDOWNY0

    DEC A
    LD C, A
VSCROLLTDOWNYL1:
    ADD HL, 32
    DEC C
    JR NZ, VSCROLLTDOWNYL1

VSCROLLTDOWNY0:
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    ADD DE, 32

    LD A, (CONSOLEH)
    DEC A
    CP 0
    JR Z, VSCROLLTDOWNDONE
    LD B, A
VSCROLLTDOWNL1A:
    LD A, (CONSOLEW)
    LD C, A
VSCROLLTDOWNL1:
    CALL WAITSTATE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC C
    JR NZ, VSCROLLTDOWNL1
    PUSH DE
    LD HL, DE
    LD D, 0
    LD A, (IXLR)
    LD E, A
    CALL SUB_HL_DE
    POP DE
    LD DE, HL
    ADD DE, 32

    DEC B
    JR NZ, VSCROLLTDOWNL1A
VSCROLLTDOWNDONE:

    LD A, (CONSOLEW)
    LD C, A
VSCROLLTDOWNCL1:
    CALL WAITSTATE
    LD A, (EMPTYTILE)
    LD (DE), A
    INC DE
    DEC C
    JR NZ, VSCROLLTDOWNCL1

    RET
