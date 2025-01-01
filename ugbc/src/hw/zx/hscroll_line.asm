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
;*                           HORIZONTAL LINE SCROLL ON ZX                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLLINE:
    PUSH AF

    LD HL, ROWSADDRESS

    LD A, B
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    ADD HL, DE
    ADD HL, DE

    POP AF

    CP $80
    JP C, HSCROLLLINER

HSCROLLLINEL:

    LD BC, 8

HSCROLLLINEL1:

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
    JP NZ, HSCROLLLINEL1

    RET

HSCROLLLINER:

    LD BC, $8

HSCROLLLINER1:

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
    LD B, A
    LD C, 0
    LDDR

    POP DE
    LD (DE), 0

    POP HL
    POP BC

    INC HL
    INC HL
    DEC C
    JP NZ, HSCROLLLINER1

    RET    