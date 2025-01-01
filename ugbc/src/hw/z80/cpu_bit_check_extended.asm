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
;*                        SET/UNSET A BIT INSIDE A BYTE                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Check bit A of byte/word/dword at DE
;  - DE = byte/word/dword to operate
;  - A = position
;  - set to 1 if carry flag is set
CPUBITCHECKEXTENDED:
    PUSH AF
    SRA A
    SRA A
    SRA A
    CP 3
    JR Z, CPUBITCHECKEXTENDED3
    CP 2
    JR Z, CPUBITCHECKEXTENDED2
    CP 1
    JR Z, CPUBITCHECKEXTENDED1
    JR CPUBITCHECKEXTENDEDEND
CPUBITCHECKEXTENDED3:
    INC DE
CPUBITCHECKEXTENDED2:
    INC DE
CPUBITCHECKEXTENDED1:
    INC DE
CPUBITCHECKEXTENDEDEND:
    POP AF
    AND $07
    LD B, 1
    CP 0
    JR Z, CPUBITCHECKEXTENDEDDONE2
CPUBITCHECKEXTENDEDLOOP2:
    SLA B
    DEC A
    JR NZ, CPUBITCHECKEXTENDEDLOOP2
CPUBITCHECKEXTENDEDDONE2:
    LD A, (DE)
    AND A, B
    CP 0
    JR Z, CPUBITCHECKEXTENDEDZERO
    LD A, 0
    CP $FF
    LD A, $FF
    RET
CPUBITCHECKEXTENDEDZERO:
    LD A, 0
    CP 0
    RET
