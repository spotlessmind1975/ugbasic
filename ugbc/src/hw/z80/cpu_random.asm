; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                        RANDOM NUMBER GENERATOR FOR Z80                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPURANDOM32:
    LD HL, (CPURANDOM_SEED)
    LD B, (HL)
    INC HL
    LD A, (HL)
    XOR B
    ; LD DE, (MATHPTR0)
    PUSH DE
    LD C, L
    ADD HL, HL
    RL E
    RL D
    ADD HL, DE
    RL E
    RL D
    INC L
    ADD HL, BC
    LD (CPURANDOM_SEED), HL
    LD HL, (CPURANDOM_SEED+2)
    ADD HL, DE
    LD (CPURANDOM_SEED+1), HL
    EX DE, HL
    LD HL, (CPURANDOM_SEED)
    ; LD DE, (MATHPTR0)
    POP DE
    ADD HL, HL
    RL C
    RL B
    LD (CPURANDOM_SEED+1), BC
    SBC A, A
    AND %11000101
    XOR L
    LD L, A
    LD (CPURANDOM_SEED+1), HL
    EX DE, HL
    ADD HL, BC
    RET

CPURANDOM16:
    LD HL, (CPURANDOM_SEED)
    LD B, (HL)
    INC HL
    LD A, (HL)
    XOR B
    ; LD DE, (MATHPTR0)
    LD C, L
    ADD HL, HL
    RL E
    RL D
    ADD HL, DE
    RL E
    RL D
    INC L
    ADD HL, BC
    LD (CPURANDOM_SEED), HL
    RET
    