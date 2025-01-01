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

; Set/reset bit A of byte DE
;  - DE = byte to operate
;  - A = position
;  - set to 1 if carry flag is set
CPUBITINPLACE:
    JR NC, CPUBITINPLACE0

; Set bit A of byte DE to 1
;  - DE = byte to operate
;  - A = position
CPUBITINPLACE1:
    PUSH DE
    LD D, 0
    LD E, A
    LD HL, BITMASK
    ADD HL, DE
    POP DE
    LD A, (DE)
    OR (HL)
    LD (DE), A
    RET

; Set bit A of byte DE to 0
;  - DE = byte to operate
;  - A = position
CPUBITINPLACE0:
    PUSH DE
    LD D, 0
    LD E, A
    LD HL, BITMASKN
    ADD HL, DE
    POP DE
    LD A, (DE)
    AND (HL)
    LD (DE), A
    RET