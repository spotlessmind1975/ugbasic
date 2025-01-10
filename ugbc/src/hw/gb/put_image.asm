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
;*                          IMAGES ROUTINE FOR GB                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ------------------------------------------------------------------------------
; PUT IMAGE
;  In : HL address of IMAGE
;  Out: -
; ------------------------------------------------------------------------------

PUTIMAGE:

    PUSH HL

    ; Retrieve the width of the IMAGE

    INC HL
    LD A, (HL)
    LD (PUTIMAGEWIDTH), A
    DEC HL

    ; Retrieve if the IMAGE has been already rendered at least once.
    LD A, (HL)

    ; If FLAGS / TIMESLOT == $ff, the IMAGE has never been rendered,
    ; so we need to allocate tiles to draw this image.

    ; CMP $FF
    ; JR Z, PUTIMAGEALLOC

    ; ; Tiles have been already set -- move to draw the image.

    ; JP PUTIMAGEDRAW

PUTIMAGEALLOC:

    ; Allocate a new slot of free tiles.

    CALL TILESETSLOTALLOC

PUTIMAGEALLOC2:

    ; Load the size of the image, in terms of tiles.

    INC HL
    INC HL
    LD A, (HL)
    LD (PUTIMAGECOUNT), A
    INC HL

    LD A, 0
    LD (PUTIMAGEINDEX), A

PUTIMAGEALLOCL1:

    ; Find the first free tile available.

    CALL TILESETSLOTFINDFREE

    ; If no more tiles are free, we must free the oldest one.

    JR NC, PUTIMAGEALLOCFL1

    JP PUTIMAGEALLOCOK

PUTIMAGEALLOCFL1:

    ; Free the oldest tiles.

    CALL TILESETSLOTRECALCFREESLOT

    ; Repeat the allocation procedure

    JP PUTIMAGEALLOCL1

PUTIMAGEALLOCOK:

    ; Set the tile index inside the IMAGE

    LD (HL), A

    LD (PUTIMAGETILEINDEX), A

    ; Now we have to copy the bitmap inside the TILESET.
    ; This means that we have to calculate the offset 
    ; inside the TILESET, multiplying the index by 16.

    PUSH DE

    PUSH HL

    LD H, D
    LD L, E

    LD A, (PUTIMAGEINDEX)
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

    ADD HL, BC

    ; Now we do the same with the hardware TILESET.
    
    PUSH HL

    LD A, (PUTIMAGETILEINDEX)
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
PUTIMAGEALLOCOKL1:
    CALL WAITSTATE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, PUTIMAGEALLOCOKL1

    POP HL

    POP DE

    ; Move to the next index.

    INC HL

    LD A, (PUTIMAGEINDEX)
    INC A
    LD (PUTIMAGEINDEX), A

    LD A, (PUTIMAGECOUNT)
    DEC A
    LD (PUTIMAGECOUNT), A

    JR Z, PUTIMAGEALLOCDONE
    JP PUTIMAGEALLOCL1

PUTIMAGEALLOCDONE:

    POP HL
    PUSH HL

    ; Set that the IMAGE has been already rendered at least once.
    LD A, 0
    LD (HL), A

PUTIMAGEDRAW:

    POP HL

    LD A, 0
    LD (PUTIMAGEX), A

    ; Load the size of the image, in terms of tiles.

    INC HL
    INC HL
    LD A, (HL)
    LD C, A
    INC HL

    ; Calculate the first coordinates.

    PUSH HL
    LD HL, (IMAGEX)
    SRA H
    RR L
    SRA H
    RR L
    SRA H
    RR L
    LD (IMAGEX), HL

    LD HL, (IMAGEY)
    SRA H
    RR L
    SRA H
    RR L
    SRA H
    RR L
    LD (IMAGEY), HL
    POP HL

    PUSH HL
    LD HL, (TEXTADDRESS)

    LD A, (IMAGEY)
    CP 0
    JR Z, PUTIMAGEDRAWL1B
    LD D, 0
    LD A, 32
    LD E, A
    LD A, (IMAGEY)
PUTIMAGEDRAWL1:
    ADD HL, DE
    DEC A
    JR NZ, PUTIMAGEDRAWL1

PUTIMAGEDRAWL1B:
    LD D, 0
    LD A, (IMAGEX)
    LD E, A
    ADD HL, DE
    LD DE, HL
    POP HL

    ; Now we are already at the starting address inside the IMAGE
    ; for the various tiles indexes.

PUTIMAGEDRAWL2:

    CALL WAITSTATE

    ; Load the index from the IMAGE.

    LD A, (HL)

    ; Store the index into the TILEMAP.

    LD (DE), A

    ; Decrement the tiles to copy.

    DEC C

    ; If the tiles have been copied, exit!

    JR NZ, PUTIMAGEDRAWL2NEXT
    JP PUTIMAGEDRAWDONE

PUTIMAGEDRAWL2NEXT:

    ; Move forward by one tile.

    INC HL
    INC DE

    ; We reached the width of the IMAGE?
    ; No, so we have to repeat.

    LD A, (PUTIMAGEX)
    INC A
    LD (PUTIMAGEX), A
    LD B, A
    LD A, (PUTIMAGEWIDTH)
    CP B
    JR NZ, PUTIMAGEDRAWL2

    LD A, 0
    LD (PUTIMAGEX), A

    ; Move forward on the TILEMAP & COLORMAP memory only!

    PUSH HL
    LD H, D
    LD L, E
    LD DE, 32
    ADD HL, DE
    LD D, 0
    LD A, (PUTIMAGEWIDTH)
    LD E, A
    CALL SUB_HL_DE
    LD DE, HL
    POP HL

    JP PUTIMAGEDRAWL2

PUTIMAGEDRAWDONE:
    RET

