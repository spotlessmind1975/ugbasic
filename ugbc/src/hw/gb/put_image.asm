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
; Allocate a new slot of used tiles.
;  In : -
;  Out: -
; ------------------------------------------------------------------------------

TILESETSLOTALLOC:
    PUSH HL
    PUSH DE
    PUSH BC

    ; First of all, retrieve the offset inside the
    ; TILESETSLOTUSED for the current last slot.

    LD A, (TILESETSLOTLAST)
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, TILESETSLOTUSED
    ADD HL, DE

    ; Move to the next last slot: if LAST is reached,
    ; move to the first.

    LD A, (TILESETSLOTLAST)
    INC A
    CP 8
    JR NZ, TILESETSLOTALLOCDONE
    LD A, 0
    LD (TILESETSLOTLAST), A
TILESETSLOTALLOCDONE:

    ; Next, retrieve the offset inside the
    ; TILESETSLOTUSED for the actual last slot.

    PUSH HL

    LD A, (TILESETSLOTLAST)
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, TILESETSLOTUSED
    ADD HL, DE

    LD D, H
    LD E, L

    POP HL

    ; Copy the 32 bytes (256 used tiles) from
    ; the last to the actual slot.

    LD B, 32
TILESETSLOTALLOCL1:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, TILESETSLOTALLOCL1

    POP BC
    POP DE
    POP HL

    RET

; ------------------------------------------------------------------------------
; Find the first free tile inside the current last slot.
;  In : -
;  Out: A - free slot, 255 = no free slot present
; ------------------------------------------------------------------------------

TILESETSLOTFINDFREE:

    PUSH HL
    PUSH DE
    PUSH BC
    
    LD B, 32
    LD C, 0

    ; Start from the first tile.

    LD A, (TILESETSLOTLAST)
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, TILESETSLOTUSED
    ADD HL, DE

TILESETSLOTFINDFREEL1:

    ; Check if, in the actual group of 8 tiles,
    ; any tile is free. If such, move to calculate
    ; the exact number of the tile.

    LD A, (HL)
    CP $FF
    JR NZ, TILESETSLOTFOUNDFREE

    ; Move to the next 8 tiles group.

    INC HL
    INC C

    ; Are there more group tiles?
    ; If so, repeat.

    DEC B
    JR NZ, TILESETSLOTFINDFREEL1

    ; No free tiles left.

    LD A, 255

    POP BC
    POP DE
    POP HL

    RET

TILESETSLOTFOUNDFREE:

    ; Calculate the starting offset of the free tiles,
    ; that is the ( group index - last ) x 8.

    LD B, C
    SLA B
    SLA B
    SLA B
    LD C, 0

TILESETSLOTFOUNDFREEL1:

    ; Check if the right most bit is zero. This means
    ; that that tile is free.

    SRA A
    JR NC, TILESETSLOTFOUNDFREEDONE

    ; Increment the offset of the free tile,
    ; and repeat. This branch should always be
    ; executed, since the value must 
    ; have at least one bit to zero.

    INC B
    INC C
    JR TILESETSLOTFOUNDFREEL1

TILESETSLOTFOUNDFREEDONE:

    LD A, B

    PUSH AF
    
    PUSH HL
    LD HL, BITMASK
    LD D, 0
    LD E, C
    ADD HL, DE
    LD A, (HL)
    POP HL
    LD C, A
    LD A, (HL)
    OR C
    LD (HL), A
    
    POP AF

    POP BC
    POP DE
    POP HL

    RET

; ------------------------------------------------------------------------------
; REALLOC THE FREE TILES
;  In : TMPPTR address of TILEDIMAGE
;  Out: -
; ------------------------------------------------------------------------------

TILESETSLOTRECALCFREESLOT:

    PUSH HL
    PUSH DE
    PUSH BC

    ; We are going to restore the actual slot with the previous one.

    LD A, (TILESETSLOTLAST)
    DEC A
    CP $FF
    JR NZ, TILESETSLOTRECALCFREESLOTA1
    LD A, 7
TILESETSLOTRECALCFREESLOTA1:
    LD (TILESETSLOTLAST), A
    CALL TILESETSLOTALLOC

    ; Now wwe retrieve the offset inside the
    ; TILESETSLOTUSED for the current first slot.

    LD A, (TILESETSLOTFIRST)
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, TILESETSLOTUSED
    ADD HL, DE

    ; Move to the next first slot: if LAST is reached,
    ; move to the first.

    LD A, (TILESETSLOTFIRST)
    INC A
    CP 8
    JR NZ, TILESETSLOTRECALCFREEDONE
    LD A, 0
TILESETSLOTRECALCFREEDONE:
    LD (TILESETSLOTFIRST), A

    ; Next, retrieve the offset inside the
    ; TILESETSLOTUSED for the actual last slot.

    PUSH HL
    LD A, (TILESETSLOTLAST)
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    LD E, A
    LD D, 0
    LD HL, TILESETSLOTUSED
    ADD HL, DE
    LD D, H
    LD E, L
    POP HL

    ; Mask the 32 bytes (256 used tiles) from
    ; the first to the actual slot.

    LD B, 32
TILESETSLOTRECALCL2:
    LD A, (HL)
    XOR $FF
    LD C, A
    LD A, (DE)
    AND C
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, TILESETSLOTRECALCL2

    POP BC
    POP DE
    POP HL

    RET

; ------------------------------------------------------------------------------
; PUT IMAGE
;  In : HL address of TILEDIMAGE
;  Out: -
; ------------------------------------------------------------------------------

PUTIMAGE:

    PUSH HL

    ; Retrieve the width of the TILEDIMAGE

    INC HL
    LD A, (HL)
    LD (PUTIMAGEWIDTH), A
    DEC HL

    ; Retrieve if the TILEDIMAGE has been already rendered at least once.
    LD A, (HL)

    ; If FLAGS / TIMESLOT == $ff, the TILEDIMAGE has never been rendered,
    ; so we need to allocate tiles to draw this image.

    CMP $FF
    JR Z, PUTIMAGEALLOC

    ; Tiles have been already set -- move to draw the image.

    JP PUTIMAGEDRAW

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

    CP 255
    JR Z, PUTIMAGEALLOCFL1

    JP PUTIMAGEALLOCOK

PUTIMAGEALLOCFL1:

    ; Free the oldest tiles.

    CALL TILESETSLOTRECALCFREESLOT

    ; Repeat the allocation procedure

    JP PUTIMAGEALLOC2

PUTIMAGEALLOCOK:

    ; Set the tile index inside the TILEDIMAGE

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

    ; Add the offset to the current TILEDIMAGE starting 
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

    ; Add the offset to the current TILEDIMAGE starting 
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

    ; Set that the TILEDIMAGE has been already rendered at least once.
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

    ; Now we are already at the starting address inside the TILEDIMAGE
    ; for the various tiles indexes.

PUTIMAGEDRAWL2:

    CALL WAITSTATE

    ; Load the index from the TILEDIMAGE.

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

    ; We reached the width of the TILEDIMAGE?
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

