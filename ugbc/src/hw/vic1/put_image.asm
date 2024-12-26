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
;*                          IMAGES ROUTINE FOR VIC-I                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TILESETSLOTFIRST: .byte 0
TILESETSLOTLAST: .byte 0
TILESETSLOTUSED: .res 256, 0
TILESETSLOTATTRIBUTE: .res 256, 0

; ------------------------------------------------------------------------------
; Allocate a new slot of used tiles.
;  In : -
;  Out: -
; ------------------------------------------------------------------------------

TILESETSLOTALLOC:
    TYA
    PHA
    TXA
    PHA

    ; First of all, retrieve the offset inside the
    ; TILESETSLOTUSED for the current last slot.

    LDA TILESETSLOTLAST
    ASL
    ASL
    ASL
    ASL
    ASL
    TAX

    ; Move to the next last slot: if LAST is reached,
    ; move to the first.

    INC TILESETSLOTLAST
    LDA TILESETSLOTLAST
    CMP #8
    BNE TILESETSLOTALLOCDONE
    LDA #0
    STA TILESETSLOTLAST
TILESETSLOTALLOCDONE:

    ; Next, retrieve the offset inside the
    ; TILESETSLOTUSED for the actual last slot.

    LDA TILESETSLOTLAST
    ASL
    ASL
    ASL
    ASL
    ASL
    TAY

    ; The TMPPTR2 pointer will contain the base
    ; address of TILESETSLOTUSED, to be indexed
    ; by the offset of the actual last slot.

    LDA #<TILESETSLOTUSED
    STA TMPPTR2
    LDA #>TILESETSLOTUSED
    STA TMPPTR2+1

    ; Copy the 32 bytes (256 used tiles) from
    ; the last to the actual slot.

    LDA #32
    STA MATHPTR0
TILESETSLOTALLOCL1:
    LDA TILESETSLOTUSED,X
    STA (TMPPTR2),Y
    INX
    INY
    DEC MATHPTR0
    BNE TILESETSLOTALLOCL1

    PLA
    TAX
    PLA
    TAY

    RTS

; ------------------------------------------------------------------------------
; Find the first free tile inside the current last slot.
;  In : -
;  Out: X - free slot, 255 = no free slot present
; ------------------------------------------------------------------------------

TILESETSLOTFINDFREE:

    TYA
    PHA

    LDY #32

    ; Start from the first tile.

    LDA TILESETSLOTLAST
    ASL
    ASL
    ASL
    ASL
    ASL
    TAX

TILESETSLOTFINDFREEL1:

    ; Check if, in the actual group of 8 tiles,
    ; any tile is free. If such, move to calculate
    ; the exact number of the tile.

    LDA TILESETSLOTUSED, X
    CMP #$FF
    BNE TILESETSLOTFOUNDFREE

    ; Move to the next 8 tiles group.

    INX

    ; Are there more group tiles?
    ; If so, repeat.

    DEY 
    BNE TILESETSLOTFINDFREEL1

    ; No free tiles left.

    LDX #255

    PLA
    TAY

    RTS

TILESETSLOTFOUNDFREE:

    ; Calculate the starting offset of the free tiles,
    ; that is the ( group index - last ) x 32.

    PHA
    STX MATHPTR6
    TXA
    LSR
    LSR
    LSR
    LSR
    LSR
    SEC
    SBC TILESETSLOTLAST
    TAX
    PLA

    LDY #0

TILESETSLOTFOUNDFREEL1:

    ; Check if the right most bit is zero. This means
    ; that that tile is free.

    LSR
    BCC TILESETSLOTFOUNDFREEDONE

    ; Increment the offset of the free tile,
    ; and repeat. This branch should always be
    ; executed, since the value must 
    ; have at least one bit to zero.

    INX
    INY
    BNE TILESETSLOTFOUNDFREEL1

TILESETSLOTFOUNDFREEDONE:

    TXA
    PHA

    TYA
    TAX
    LDA BITMASK,X

    LDX MATHPTR6
    ORA TILESETSLOTUSED,X
    STA TILESETSLOTUSED,X
    
    PLA
    TAX

    PLA
    TAY

    RTS

; ------------------------------------------------------------------------------
; REALLOC THE FREE TILES
;  In : TMPPTR address of TILEDIMAGE
;  Out: -
; ------------------------------------------------------------------------------

TILESETSLOTRECALCFREESLOT:

    TYA
    PHA
    TXA
    PHA

    ; We are going to restore the actual slot with the previous one.

    DEC TILESETSLOTLAST
    LDA TILESETSLOTLAST
    CMP #$FF
    BNE TILESETSLOTRECALCFREESLOTA1
    LDA #7
    STA TILESETSLOTLAST
TILESETSLOTRECALCFREESLOTA1:
    JSR TILESETSLOTALLOC

    ; Now wwe retrieve the offset inside the
    ; TILESETSLOTUSED for the current first slot.

    LDA TILESETSLOTFIRST
    ASL
    ASL
    ASL
    ASL
    ASL
    TAX

    ; Move to the next first slot: if LAST is reached,
    ; move to the first.

    INC TILESETSLOTFIRST
    LDA TILESETSLOTFIRST
    CMP #8
    BNE TILESETSLOTRECALCFREEDONE
    LDA #0
    STA TILESETSLOTFIRST
TILESETSLOTRECALCFREEDONE:

    ; Next, retrieve the offset inside the
    ; TILESETSLOTUSED for the actual last slot.

    LDA TILESETSLOTLAST
    ASL
    ASL
    ASL
    ASL
    ASL
    TAY

    ; The TMPPTR2 pointer will contain the base
    ; address of TILESETSLOTUSED, to be indexed
    ; by the offset of the actual last slot.

    LDA #<TILESETSLOTUSED
    STA TMPPTR2
    LDA #>TILESETSLOTUSED
    STA TMPPTR2+1

    ; Mask the 32 bytes (256 used tiles) from
    ; the first to the actual slot.

    LDA #32
    STA MATHPTR0
TILESETSLOTRECALCL2:
    LDA TILESETSLOTUSED,X
    EOR #$FF
    AND (TMPPTR2),Y
    STA (TMPPTR2),Y
    INX
    INY
    DEC MATHPTR0
    BNE TILESETSLOTRECALCL2

    PLA
    TAX
    PLA
    TAY

    RTS

; ------------------------------------------------------------------------------
; PUT IMAGE
;  In : TMPPTR address of TILEDIMAGE
;  Out: -
; ------------------------------------------------------------------------------

PUTIMAGECOUNT:      .BYTE 0
PUTIMAGEWIDTH:      .BYTE 0
PUTIMAGEINDEX:      .BYTE 0
PUTIMAGEX:          .BYTE 0

PUTIMAGE:

    ; Retrieve the width of the TILEDIMAGE

    LDY #1
    LDA (TMPPTR), Y
    STA PUTIMAGEWIDTH

    ; Retrieve if the TILEDIMAGE has been already rendered at least once.
    LDY #0
    LDA (TMPPTR),Y

    ; If FLAGS / TIMESLOT == $ff, the TILEDIMAGE has never been rendered,
    ; so we need to allocate tiles to draw this image.

    CMP #$FF
    BEQ PUTIMAGEALLOC

    ; Tiles have been already set -- move to draw the image.

    JMP PUTIMAGEDRAW

PUTIMAGEALLOC:

    ; Allocate a new slot of free tiles.

    JSR TILESETSLOTALLOC

PUTIMAGEALLOC2:

    ; Load the size of the image, in terms of tiles.

    LDY #2
    LDA (TMPPTR),Y
    STA PUTIMAGECOUNT

    LDY #3
    STY PUTIMAGEINDEX

PUTIMAGEALLOCL1:

    ; Find the first free tile available.

    JSR TILESETSLOTFINDFREE

    ; If no more tiles are free, we must free the oldest one.

    CPX #255
    BEQ PUTIMAGEALLOCFL1

    JMP PUTIMAGEALLOCOK

PUTIMAGEALLOCFL1:

    ; Free the oldest tiles.

    JSR TILESETSLOTRECALCFREESLOT

    ; Repeat the allocation procedure

    JMP PUTIMAGEALLOC2

PUTIMAGEALLOCOK:

    ; Set the tile index inside the TILEDIMAGE

    TXA
    PHA
    LDY PUTIMAGEINDEX
    STA (TMPPTR), Y

    ; Now we have to copy the bitmap inside the TILESET.
    ; This means that we have to calculate the offset 
    ; inside the TILESET, multiplying the index by 8.

    STA MATHPTR2
    LDA #0
    STA MATHPTR3

    ASL MATHPTR2
    ROL MATHPTR3
    ASL MATHPTR2
    ROL MATHPTR3
    ASL MATHPTR2
    ROL MATHPTR3

    ; Add the offset to the current TILEDIMAGE starting 
    ; address, and then we add the current SIZE and,
    ; finally, the size of the header.

    CLC
    LDA MATHPTR2
    ADC TMPPTR
    STA TMPPTR2
    LDA MATHPTR3
    ADC TMPPTR+1
    STA TMPPTR2+1

    LDY #2
    CLC
    LDA TMPPTR2
    ADC (TMPPTR), Y
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    CLC
    LDA TMPPTR2
    ADC #3
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    ; Now we do the same with the hardware TILESET.
    ; Since we want to optimize the calculation,
    ; we are going to use a self modify code.

    CLC
    LDA MATHPTR2
    ADC PUTIMAGEALLOCOKL1ADDR+1
    STA PUTIMAGEALLOCOKL1ADDR+1
    LDA MATHPTR3
    ADC PUTIMAGEALLOCOKL1ADDR+2
    STA PUTIMAGEALLOCOKL1ADDR+2

    ; Let's repeat the copy for 8 bytes.

    LDA #8
    STA MATHPTR0
    LDX #0
    LDY #0
PUTIMAGEALLOCOKL1:
    LDA (TMPPTR2),Y
PUTIMAGEALLOCOKL1ADDR:
    STA $1800, X
    INX
    INY
    DEC MATHPTR0
    BNE PUTIMAGEALLOCOKL1

    ; Restore the original address of the TILESET.

    LDA #$00
    STA PUTIMAGEALLOCOKL1ADDR+1
    LDA #$18
    STA PUTIMAGEALLOCOKL1ADDR+2

    ; Add the offset to the current TILEDIMAGE starting 
    ; address, and then we add the current SIZE * 8 and,
    ; finally, the size of the header.

    CLC
    PLA
    PHA
    ADC TMPPTR
    STA TMPPTR2
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR2+1

    LDY #2
    LDA (TMPPTR), Y

    CLC
    ADC TMPPTR2
    STA TMPPTR2
    LDA #0
    ADC TMPPTR2+1
    STA TMPPTR2+1

    LDY #2
    LDA (TMPPTR), Y
    ASL
    ASL
    ASL

    CLC
    ADC TMPPTR2
    STA TMPPTR2
    LDA #0
    ADC TMPPTR2+1
    STA TMPPTR2+1

    CLC
    LDA TMPPTR2
    ADC #3
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    ; Now we do the same with the attribute table.
    ; Since we want to optimize the calculation,
    ; we are going to use a self modify code.

    CLC
    PLA
    ADC PUTIMAGEALLOCOKL2ADDR+1
    STA PUTIMAGEALLOCOKL2ADDR+1
    LDA #0
    ADC PUTIMAGEALLOCOKL2ADDR+2
    STA PUTIMAGEALLOCOKL2ADDR+2

    LDY #0
    LDX #0
    LDA (TMPPTR2),Y
PUTIMAGEALLOCOKL2ADDR:
    STA TILESETSLOTATTRIBUTE, X

    ; Restore the original address of the ATTRIBUTE.

    LDA #<TILESETSLOTATTRIBUTE
    STA PUTIMAGEALLOCOKL2ADDR+1
    LDA #>TILESETSLOTATTRIBUTE
    STA PUTIMAGEALLOCOKL2ADDR+2

    ; Move to the next index.

    INC PUTIMAGEINDEX
    DEC PUTIMAGECOUNT
    BEQ PUTIMAGEALLOCDONE
    JMP PUTIMAGEALLOCL1

PUTIMAGEALLOCDONE:

    ; Set that the TILEDIMAGE has been already rendered at least once.
    LDY #0
    LDA #0
    STA (TMPPTR),Y

PUTIMAGEDRAW:

    ; Load the size of the image, in terms of tiles.

    LDY #2
    LDA (TMPPTR),Y
    STA PUTIMAGECOUNT

    ; Calculate the first coordinates.

    LSR IMAGEX+1
    ROR IMAGEX
    LSR IMAGEX+1
    ROR IMAGEX
    LSR IMAGEX+1
    ROR IMAGEX

    LSR IMAGEY+1
    ROR IMAGEY
    LSR IMAGEY+1
    ROR IMAGEY
    LSR IMAGEY+1
    ROR IMAGEY

    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDA IMAGEY
    BEQ PUTIMAGEDRAWL1B
PUTIMAGEDRAWL1:
    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA COPYOFCOLORMAPADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    ADC #0
    STA COPYOFCOLORMAPADDRESS+1

    DEC IMAGEY
    BNE PUTIMAGEDRAWL1

PUTIMAGEDRAWL1B:

    CLC
    LDA COPYOFTEXTADDRESS
    ADC IMAGEX
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA COPYOFCOLORMAPADDRESS
    ADC IMAGEX
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    ADC #0
    STA COPYOFCOLORMAPADDRESS+1

    ; Now we calculate the starting address inside the TILEDIMAGE
    ; for the various tiles indexes.

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR2
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR2+1

PUTIMAGEDRAWL2:

    LDY #0

    ; Load the index from the TILEDIMAGE.

    LDA (TMPPTR2), Y
    TAX

    ; Store the index into the TILEMAP.

    STA (COPYOFTEXTADDRESS), Y

    ; Load the attribute

    LDA TILESETSLOTATTRIBUTE, X

    ; Store the index into the COLORMAP

    STA (COPYOFCOLORMAPADDRESS), Y

    ; Decrement the tiles to copy.

    DEC PUTIMAGECOUNT

    ; If the tiles have been copied, exit!

    BNE PUTIMAGEDRAWL2NEXT
    JMP PUTIMAGEDRAWDONE

PUTIMAGEDRAWL2NEXT:

    ; Move forward by one tile.

    INC TMPPTR2
    BNE PUTIMAGEDRAWL2A
    INC TMPPTR2+1
PUTIMAGEDRAWL2A:

    INC COPYOFTEXTADDRESS
    BNE PUTIMAGEDRAWL2B
    INC COPYOFTEXTADDRESS+1
PUTIMAGEDRAWL2B:

    INC COPYOFCOLORMAPADDRESS
    BNE PUTIMAGEDRAWL2C
    INC COPYOFCOLORMAPADDRESS+1
PUTIMAGEDRAWL2C:

    ; We reached the width of the TILEDIMAGE?
    ; No, so we have to repeat.

    INC PUTIMAGEX
    LDA PUTIMAGEX
    CMP PUTIMAGEWIDTH
    BNE PUTIMAGEDRAWL2

    LDA #0
    STA PUTIMAGEX

    ; Move forward on the TILEMAP & COLORMAP memory only!

    CLC
    LDA COPYOFTEXTADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    ADC #0
    STA COPYOFTEXTADDRESS+1

    SEC
    LDA COPYOFTEXTADDRESS
    SBC PUTIMAGEWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA COPYOFCOLORMAPADDRESS
    ADC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    ADC #0
    STA COPYOFCOLORMAPADDRESS+1

    SEC
    LDA COPYOFCOLORMAPADDRESS
    SBC PUTIMAGEWIDTH
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    SBC #0
    STA COPYOFCOLORMAPADDRESS+1

    JMP PUTIMAGEDRAWL2

PUTIMAGEDRAWDONE:
    RTS

PUTIMAGEOLD:
;     LDA CURRENTMODE
;     ; BITMAP_MODE_STANDARD
;     CMP #2
;     BNE PUTIMAGE2X
;     JMP PUTIMAGE2
; PUTIMAGE2X:
;     ; BITMAP_MODE_MULTICOLOR
;     CMP #3
;     BNE PUTIMAGE3X
;     JMP PUTIMAGE3
; PUTIMAGE3X:
;     ; TILEMAP_MODE_STANDARD
;     CMP #0
;     BNE PUTIMAGE0X
;     JMP PUTIMAGE0
; PUTIMAGE0X:
;     ; TILEMAP_MODE_MULTICOLOR
;     CMP #1
;     BNE PUTIMAGE1X
;     JMP PUTIMAGE1
; PUTIMAGE1X:
;     ; TILEMAP_MODE_EXTENDED
;     CMP #4
;     BNE PUTIMAGE4X
;     JMP PUTIMAGE4
; PUTIMAGE4X:
;     RTS

PUTIMAGE0:
    LDY #2
    LDA (TMPPTR),Y
    STA MATHPTR2
PUTIMAGE02C:
    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LSR
    LSR
    LSR
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ;-------------------------
    ;calc Y-cell, divide by 8
    ;y/8 is y-cell table index
    ;-------------------------
    LDA IMAGEY
    LSR                         ;/ 2
    LSR                         ;/ 4
    LSR                         ;/ 8
    TAY                         ;tbl_8,y index

    CLC

    ;------------------------
    ;calc X-cell, divide by 8
    ;divide 2-byte PLOTX / 8
    ;------------------------
    LDA IMAGEX
    ROR IMAGEX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2 (rotate C into low byte)
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    STA MATHPTR0               ;tbl_8,x index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOTCVBASELO,Y          ;table of $A000 row base addresses
    ADC MATHPTR0               ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTCVBASEHI,Y          ;do the high byte
    ADC #0
    STA PLOTDEST+1

    CLC
    LDA PLOTC2VBASELO,Y          ;table of $A000 row base addresses
    ADC MATHPTR0               ;+ (8 * Xcell)
    STA PLOTCDEST               ;= cell address

    LDA PLOTC2VBASEHI,Y          ;do the high byte
    ADC #0
    STA PLOTCDEST+1

    TYA
    ADC IMAGEH
    
    LDA IMAGEW
    TAY
    DEY
PUTIMAGE0L1:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE0L1

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTDEST
    ADC #22
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$0
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ PUTIMAGE0C

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE0L1

PUTIMAGE0C:
    LDA MATHPTR2
    BEQ PUTIMAGE0C2
    JMP PUTIMAGE0C16

PUTIMAGE0C2:
    LDY #0
    LDA (TMPPTR),Y
    STA MATHPTR1

    LDA $900F
    AND #$0F
    LDY #1
    ORA (TMPPTR),Y
    STA $900F

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    DEY
    LDA MATHPTR1
PUTIMAGE02L2:
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE02L2

    DEC IMAGEH
    BEQ PUTIMAGE0E

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTCDEST
    ADC #22
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDA IMAGEW
    TAY
    DEY
    LDA MATHPTR1
    JMP PUTIMAGE02L2

PUTIMAGE0C16:
    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    DEY
    LDA MATHPTR1
PUTIMAGE016L2:
    LDA (TMPPTR),Y
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE016L2

    DEC IMAGEH
    BEQ PUTIMAGE0E2

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTCDEST
    ADC #22
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE016L2

PUTIMAGE0E2:
    LDA $900F
    AND #$0F
    LDY #0
    ORA (TMPPTR),Y

PUTIMAGE0E:
    RTS

; PUTIMAGE0:
; PUTIMAGE1:
; PUTIMAGE4:
;     RTS

; PUTIMAGE2:
;     LDY #0
;     LDA (TMPPTR),Y
;     STA IMAGEW
;     LDY #1
;     LDA (TMPPTR),Y
;     LSR
;     LSR
;     LSR
;     STA IMAGEH
;     STA IMAGEH2

;     CLC
;     LDA TMPPTR
;     ADC #2
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     ;-------------------------
;     ;calc Y-cell, divide by 8
;     ;y/8 is y-cell table index
;     ;-------------------------
;     LDA IMAGEY
;     LSR                         ;/ 2
;     LSR                         ;/ 4
;     LSR                         ;/ 8
;     TAY                         ;tbl_8,y index

;     CLC

;     ;------------------------
;     ;calc X-cell, divide by 8
;     ;divide 2-byte PLOTX / 8
;     ;------------------------
;     LDA IMAGEX
;     ROR IMAGEX+1                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2 (rotate C into low byte)
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
;     ADC PLOT8LO,X              ;+ (8 * Xcell)
;     STA PLOTDEST               ;= cell address

;     LDA PLOTVBASEHI,Y          ;do the high byte
;     ADC PLOT8HI,X
;     STA PLOTDEST+1

;     TXA
;     ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTCDEST               ;= cell address

;     LDA #0
;     ADC PLOTCVBASEHI,Y          ;do the high byte
;     STA PLOTCDEST+1

;     TYA
;     ADC IMAGEH
    
;     JSR PUTIMAGEWAITLINE

;     LDA IMAGEW
;     TAY
;     DEY
; PUTIMAGE2L1:
;     LDA (TMPPTR),Y
;     STA (PLOTDEST),Y
;     DEY
;     CPY #255
;     BNE PUTIMAGE2L1

;     CLC
;     LDA TMPPTR
;     ADC IMAGEW
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     CLC
;     LDA PLOTDEST
;     ADC #$40
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #$1
;     STA PLOTDEST+1

;     DEC IMAGEH
;     BEQ PUTIMAGE2C

;     LDA IMAGEW
;     TAY
;     DEY
;     JMP PUTIMAGE2L1

; PUTIMAGE2C:

;     LDA IMAGEH2
;     STA IMAGEH
;     LDA IMAGEW
;     LSR A
;     LSR A
;     LSR A
;     STA IMAGEW
;     TAY
;     DEY
; PUTIMAGE2L2:
;     LDA (TMPPTR),Y
;     STA (PLOTCDEST),Y
;     DEY
;     CPY #255
;     BNE PUTIMAGE2L2

;     DEC IMAGEH
;     BEQ PUTIMAGE2E

;     CLC
;     LDA TMPPTR
;     ADC IMAGEW
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     CLC
;     LDA PLOTCDEST
;     ADC #40
;     STA PLOTCDEST
;     LDA PLOTCDEST+1
;     ADC #0
;     STA PLOTCDEST+1

;     LDA IMAGEW
;     TAY
;     DEY
;     JMP PUTIMAGE2L2

; PUTIMAGE2E:
;     RTS

; ;;;;;;;;;;;;;;;;;

; PUTIMAGE3:
;     LDY #0
;     LDA (TMPPTR),Y
;     STA IMAGEW
;     LDY #1
;     LDA (TMPPTR),Y
;     LSR
;     LSR
;     LSR
;     STA IMAGEH
;     STA IMAGEH2

;     CLC
;     LDA TMPPTR
;     ADC #2
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     ;-------------------------
;     ;calc Y-cell, divide by 8
;     ;y/8 is y-cell table index
;     ;-------------------------
;     LDA IMAGEY
;     LSR                         ;/ 2
;     LSR                         ;/ 4
;     LSR                         ;/ 8
;     TAY                         ;tbl_8,y index

;     CLC

;     ;------------------------
;     ;calc X-cell, divide by 8
;     ;divide 2-byte PLOTX / 8
;     ;------------------------
;     LDA IMAGEX
;     ROR IMAGEX+1                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2 (rotate C into low byte)
;     LSR                        ;lo byte / 4
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
;     ADC PLOT8LO,X              ;+ (8 * Xcell)
;     STA PLOTDEST               ;= cell address

;     LDA PLOTVBASEHI,Y          ;do the high byte
;     ADC PLOT8HI,X
;     STA PLOTDEST+1

;     CLC

;     TXA
;     ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTCDEST               ;= cell address

;     LDA #0
;     ADC PLOTCVBASEHI,Y          ;do the high byte
;     STA PLOTCDEST+1

;     CLC

;     TXA
;     ADC PLOTC2VBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTC2DEST               ;= cell address

;     LDA #0
;     ADC PLOTC2VBASEHI,Y          ;do the high byte
;     STA PLOTC2DEST+1

;     LDA IMAGEW
;     ASL
;     TAY
;     DEY
; PUTIMAGE3L1:
;     LDA (TMPPTR),Y
;     STA (PLOTDEST),Y
;     DEY
;     CPY #255
;     BNE PUTIMAGE3L1

;     CLC
;     LDA TMPPTR
;     ADC IMAGEW
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     CLC
;     LDA TMPPTR
;     ADC IMAGEW
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     CLC
;     LDA PLOTDEST
;     ADC #$40
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #$1
;     STA PLOTDEST+1

;     DEC IMAGEH
;     BEQ PUTIMAGE3C

;     LDA IMAGEW
;     ASL
;     TAY
;     DEY
;     JMP PUTIMAGE3L1

; PUTIMAGE3C:

;     LDA IMAGEH2
;     STA IMAGEH
;     LDA IMAGEW
;     LSR A
;     LSR A
;     STA IMAGEW
;     TAY
;     DEY
; PUTIMAGE3L2:
;     LDA (TMPPTR),Y
;     STA (PLOTCDEST),Y
;     DEY
;     CPY #255
;     BNE PUTIMAGE3L2

;     DEC IMAGEH
;     BEQ PUTIMAGE3C2

;     CLC
;     LDA TMPPTR
;     ADC IMAGEW
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     CLC
;     LDA PLOTCDEST
;     ADC #40
;     STA PLOTCDEST
;     LDA PLOTCDEST+1
;     ADC #0
;     STA PLOTCDEST+1

;     LDA IMAGEW
;     TAY
;     DEY
;     JMP PUTIMAGE3L2
; PUTIMAGE3C2:

;     LDA IMAGEH2
;     STA IMAGEH
;     LDA IMAGEW
;     TAY
; PUTIMAGE3C2L2:
;     LDA (TMPPTR),Y
;     STA (PLOTC2DEST),Y
;     DEY
;     CPY #255
;     BNE PUTIMAGE3C2L2

;     DEC IMAGEH
;     BEQ PUTIMAGE3E

;     CLC
;     LDA TMPPTR
;     ADC IMAGEW
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     CLC
;     LDA PLOTC2DEST
;     ADC #40
;     STA PLOTC2DEST
;     LDA PLOTC2DEST+1
;     ADC #0
;     STA PLOTC2DEST+1

;     LDA IMAGEW
;     TAY
;     DEY
;     JMP PUTIMAGE3C2L2

; PUTIMAGE3E:
;     LDY #0
;     LDA (TMPPTR),Y
;     STA $D021

;     RTS

; PUTIMAGEWAITLINE:
;     CMP $D012
;     BCS PUTIMAGEWAITLINE
    RTS