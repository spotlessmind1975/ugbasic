; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
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
;*                          SPRITES ROUTINE FOR GB                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SPRITEDATASET:
    PUSH AF
    LD A, B
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, $FE00
    ADD HL, DE
    POP AF
    INC HL
    INC HL
    CALL WAITSTATEM0
    LD (HL), A
    RET

SPRITEDATAFROMFAILED:
    POP AF
    LD (TILESETSLOTLAST), A
    POP AF
    RET

SPRITEDATAFROM:

    PUSH HL
    PUSH AF
    LD A, B
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, $FE00
    ADD HL, DE
    POP AF

    INC HL
    INC HL

    LD A, (TILESETSLOTLAST)
    PUSH AF
    LD A, 0
    LD (TILESETSLOTLAST), A
    CALL TILESETSLOTFINDFREE
    JR NC, SPRITEDATAFROMFAILED
    LD B, A
    POP AF
    LD (TILESETSLOTLAST), A
    CALL TILESETSLOTRESETFREESLOT

    LD A, B
    CALL WAITSTATEM0
    LD (HL), A

    POP HL

    ; Now we do the same with the hardware TILESET.
    
    PUSH HL

    LD C, A
    LD B, 0

    SLA C
    RL B
    SLA C
    RL B
    SLA C
    RL B
    SLA C
    RL B

    ; Add the offset to the current IMAGE starting 
    ; address, and then we add the current SIZE and,
    ; finally, the size of the header.

    LD HL, _VRAM
    ADD HL, BC

    LD D, H
    LD E, L

    POP HL

    ; Let's repeat the copy for 16 bytes.

    LD B, 16
SPRITEDATAFROML1:
    CALL WAITSTATE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, SPRITEDATAFROML1

    RET

SPRITEENABLE:
    LD A, B
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, $FE00
    ADD HL, DE
    INC HL
    INC HL
    INC HL
    LD A, 0
    CALL WAITSTATEM0
    LD (HL), A
    RET

SPRITEDISABLE:
    LD A, B
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, $FE00
    ADD HL, DE
    LD A, 255
    CALL WAITSTATEM0
    LD (HL), A
    RET

SPRITEAT:
    PUSH DE
    LD A, B
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, $FE00
    ADD HL, DE
    POP DE
    LD A, E
    CALL WAITSTATEM0
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
    INC HL
    INC HL
    LD A, 0
    LD (HL), A
    RET
