; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                      CONVERT A NUMBER TO A STRING OF BITS (1/0)             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BINSTR:
    PUSH BC
    PUSH AF
    LD HL, BINSTRBUF
    LD C, 32
    LD A, (BINTOSTRDIGIT0)
BINSTRXZ:
    LD (HL), A
    INC HL
    DEC C
    JR NZ, BINSTRXZ
    POP AF
    POP BC
    LD HL, BINSTRBUF
    ADD HL, 31
BINSTRL:
    SRA B
    RR C
    RR D
    RR E
    JR C, BINSTRO1
    JMP BINSTRO0
BINSTRO0:
    PUSH AF
    LD A, (BINTOSTRDIGIT0)
    LD (HL), A
    DEC HL
    POP AF
    JMP BINSTRO
BINSTRO1:
    PUSH AF
    LD A, (BINTOSTRDIGIT1)
    LD (HL), A
    DEC HL
    POP AF
    JMP BINSTRO
BINSTRO:
    DEC A
    JR NZ, BINSTRL
    INC HL
    RET
