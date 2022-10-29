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
;*                        CLEAR LINE ROUTINE FOR CPC                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINE:
    PUSH AF

    LD HL, PLOTVBASE
    LD A, (YCURSYS)
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    ADD HL, DE
    ADD HL, DE

    POP AF

    CP $0
    JP NZ, CLINEC

    LD A, $50
    SUB (XCURSYS)
CLINEC:
    LD C, A
    LD A, 0
    LD B, A

CLINECL:

    LD A, 8

CLINECL2:

    PUSH AF
    PUSH HL
    PUSH BC

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    INC HL

    LD HL, DE

    PUSH BC

    LD A, (XCURSYS)
    LD C, A
    LD A, 0
    LD B, A

    ADD HL, BC
    LD DE, HL

    INC HL

    LD A, 0
    LD (HL),A

    POP BC
    POP BC
    PUSH BC
    LDIR
    POP BC

    POP HL
    POP AF

    INC HL
    INC HL
    DEC A
    JP NZ, CLINECL2

    RET

