; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

VSCROLLTUP:

    LD BC, 192
    LD HL, PLOTVBASE

VSCROLLTUPL1:

    PUSH BC
    PUSH HL

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    INC HL

    ADD HL, 14

    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A
    LD HL, BC

    LD BC, $50
    LDIR

    POP HL
    POP BC

    INC HL
    INC HL
    DEC C
    JP NZ, VSCROLLTUPL1

    LD BC, 8

VSCROLLTUPL2:

    PUSH BC
    PUSH HL

    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A
    LD HL, BC

    LD A, 0
    LD (HL), A
    LD E, L
    LD D, H
    INC DE
    LD BC, $0050
    LDIR

    POP HL
    POP BC

    INC HL
    INC HL
    DEC C
    JP NZ, VSCROLLTUPL2

    RET