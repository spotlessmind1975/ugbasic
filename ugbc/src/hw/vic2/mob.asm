; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                  MOVABLE OBJECTS UNDER VIC-II (specific algorithms)         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

MOBDRAW_TMP = $F6
MOBDRAW_DY  = $F7
MOBDRAW_DX  = $F8
MOBDRAW_I  = $F9
MOBDRAW_J  = $FA
MOBDRAW_K  = $FB
MOBDRAW_C  = $FC
MOBDRAW_R  = $FE

; ---------------------------------------------------------------------------
; Chipset specific initialization
; MOBINITCS(X:index,draw)
; ---------------------------------------------------------------------------
MOBINITCS:
    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BEQ MOBINITCS2
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BEQ MOBINITCS3
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BEQ MOBINITCS0
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BEQ MOBINITCS1
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BEQ MOBINITCS4
    RTS

; ---------------------------------------------------------------------------
; MODE 2 (BITMAP STANDARD)
; Shift the *current* draw area image of MOBI mob of MOBDRAW_DX pixel 
; to the right. Additional left pixel are put to zero.
; ---------------------------------------------------------------------------
MOBDRAW2_SHIFTRIGHT:

    LDX MOBI

    ; Load first location of draw data
    LDA MOBDESCRIPTOR_DL, X
    STA MOBADDR
    LDA MOBDESCRIPTOR_DH, X
    STA MOBADDR+1

    ; Load height (in pixels) = height (in rows) + 8
    LDA MOBH
    ADC #8
    STA MOBDRAW_R

    ; Load width (in pixels) = width (in cols) + 1
    LDA MOBW
    LSR
    LSR
    LSR
    CLC
    ADC #1
    STA MOBDRAW_C

    ; Load displacement = iteraction for each  line
    LDA MOBDRAW_DX
    STA MOBDRAW_K

    ; Rows loop
MOBDRAW2_SHIFTRIGHTL1:

    ; j = cols
    LDA MOBDRAW_C
    STA MOBDRAW_J

    LDY #0
    CLC

    ; Cols loop
MOBDRAW2_SHIFTRIGHTL2:

    ; Rotate the content of the cell by 1 pixel to the right
    ; and save the last pixel on carry. The carry will be put
    ; on the leftmost pixel.
    LDA (MOBADDR),Y
    ROR
    STA (MOBADDR),Y

    ; Move to the next cell on the same line.
    ; This is placed after 8 bytes from the current position.
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    INY

    ; Repeat for each cell of the same row.
    DEC MOBDRAW_J
    BNE MOBDRAW2_SHIFTRIGHTL2

    ; Repeat for the entire size of the displacement.
    LDY #0
    DEC MOBDRAW_K
    BNE MOBDRAW2_SHIFTRIGHTL1

    ; Move to the next line
    ; If we are at the last line of the cell,
    ; we must advace of an entire row.
    LDA MOBDRAW_I
    AND #$07
    CMP #$01
    BEQ MOBDRAW2_SHIFTRIGHTR8

MOBDRAW2_SHIFTRIGHTR1:
    CLC
    LDA MOBADDR
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR
    JMP MOBDRAW2_SHIFTRIGHTRD

MOBDRAW2_SHIFTRIGHTR8:
    CLC
    LDA MOBADDR
    ADC MOBW
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR
    JMP MOBDRAW2_SHIFTRIGHTRD

MOBDRAW2_SHIFTRIGHTRD:
    ; Repeat for each row of the entire draw.
    DEC MOBDRAW_I
    BNE MOBDRAW2_SHIFTRIGHTL1
    RTS

; ---------------------------------------------------------------------------
; MODE 2 (BITMAP STANDARD)
; Shift the *current* draw area image of MOBI mob of MOBDRAW_DX pixel 
; to the left. Pixels on the right are put to zero.
; ---------------------------------------------------------------------------

MOBDRAW2_SHIFTLEFT:

    LDX MOBI

    ; Load first location of draw data
    LDA MOBDESCRIPTORS_DL, X
    STA MOBADDR
    LDA MOBDESCRIPTORS_DH, X
    STA MOBADDR+1

    ; Load height (in pixels) = height (in rows) + 8
    LDA MOBH
    ADC #8
    STA MOBDRAW_R

    ; Load width (in pixels) = width (in cols) + 1
    LDA MOBW
    LSR
    LSR
    LSR
    CLC
    ADC #1
    STA MOBDRAW_C

    ; Load displacement = iteraction for each  line
    LDA MOBDRAW_DX
    STA MOBDRAW_K

    ; Rows loop
MOBDRAW2_SHIFTLEFTL1:

    ; j = cols
    LDA MOBDRAW_C
    STA MOBDRAW_J

    LDA MOBW
    TAY

    CLC

    ; Cols loop
MOBDRAW2_SHIFTLEFTL2:

    ; Rotate the content of the cell by 1 pixel to the left
    ; and save the first pixel on carry. The carry will be put
    ; on the rightmost pixel.
    LDA (MOBADDR),Y
    ASL
    STA (MOBADDR),Y

    ; Move to the previous cell on the same line.
    ; This is placed after 8 bytes from the current position.
    DEY
    DEY
    DEY
    DEY
    DEY
    DEY
    DEY
    DEY

    ; Repeat for each cell of the same row.
    DEC MOBDRAW_J
    BNE MOBDRAW2_SHIFTLEFTL2

    ; Repeat for the entire size of the displacement.
    LDA MOBW
    TAY
    DEC MOBDRAW_K
    BNE MOBDRAW2_SHIFTLEFTL1

    ; Move to the next line
    ; If we are at the last line of the cell,
    ; we must advace of an entire row.
    LDA MOBDRAW_I
    AND #$07
    CMP #$01
    BEQ MOBDRAW2_SHIFTLEFTR8

MOBDRAW2_SHIFTLEFTR1:
    CLC
    LDA MOBADDR
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR
    JMP MOBDRAW2_SHIFTLEFTRD

MOBDRAW2_SHIFTLEFTR8:
    CLC
    LDA MOBADDR
    ADC MOBW
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR
    JMP MOBDRAW2_SHIFTRIGHTRD

MOBDRAW2_SHIFTLEFTRD:
    ; Repeat for each row of the entire draw.
    DEC MOBDRAW_I
    BNE MOBDRAW2_SHIFTLEFTL1
    RTS

; ---------------------------------------------------------------------------
; MODE 2 (BITMAP STANDARD)
; Shift the *current* draw area image of MOBI mob of MOBDRAW_DY pixel 
; to the bottom. Pixels on the top are put to zero.
; ---------------------------------------------------------------------------

MOBDRAW2_SHIFTDOWN:

    LDX MOBI

    ; Load height (in pixels) = height (in rows) + 8
    LDA MOBDESCRIPTORS_H, X
    ADC #8
    STA MOBDRAW_R

    ; Load width (in pixels) = width (in cols) + 1
    LDA MOBDESCRIPTORS_W, X
    LSR
    LSR
    LSR
    CLC
    ADC #1
    STA MOBDRAW_C

    ; Load displacement = iteraction for each  line
    LDA MOBDRAW_DY
    STA MOBDRAW_K

    ; Calculate the offset for next line by displacement
    LDA #0
    STA MOBSIZE
MOBDRAW2_SHIFTDOWNL1:
    CLC
    LDA MOBSIZE
    ADC MOBDESCRIPTORS_H, X
    ADC #8
    STA MOBSIZE
    DEC MOBDRAW_K
    BNE MOBDRAW2_SHIFTDOWNL1

    ; Reload displacement = iteraction for each  line
    LDA MOBDRAW_DY
    STA MOBDRAW_K

    ; Load first location of draw data
    LDA MOBDESCRIPTORS_DL, X
    STA MOBADDR
    LDA MOBDESCRIPTORS_DH, X
    STA MOBADDR+1

    ; First is last -- the copy is reversed!
    LDY MOBDESCRIPTORS_H, X
    LDX MOBDESCRIPTORS_W, X
MOBDRAW2_SHIFTDOWNL1X:
    CLC
    TXA
    ADC MOBADDR
    STA MOBADDR
    ADC #0
    ADC MOBADDR+1
    STA MOBADDR+1
    DEY
    BNE MOBDRAW2_SHIFTDOWNL1X
    
    ; Load location of draw data on the next (by displacement) line
    SEC
    LDA MOBADDR
    SBC MOBSIZE
    STA TMPPTR
    LDA MOBADDR+1
    SBC #0
    STA TMPPTR+1

    ; Rows loop
MOBDRAW2_SHIFTDOWNL2:

    ; j = cols
    LDA MOBDRAW_C
    STA MOBDRAW_J

    LDY #0
    CLC

    ; Cols loop
MOBDRAW2_SHIFTDOWNL3:

    ; Move the content of the cell by 1 row down.
    LDA (MOBADDR),Y
    STA (TMPPTR),Y

    ; Move to the next cell on the same line.
    ; This is placed after 8 bytes from the current position.
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    INY

    ; Repeat for each cell of the same row.
    DEC MOBDRAW_J
    BNE MOBDRAW2_SHIFTDOWNL3

    ; Move to the next line
    SEC
    LDA MOBADDR
    SBC #8
    STA MOBADDR
    LDA MOBADDR+1
    SBC #0
    STA MOBADDR

    CLC
    LDA TMPPTR
    SBC #8
    STA TMPPTR
    LDA TMPPTR+1
    SBC #0
    STA TMPPTR

    ; Repeat for each row of the entire draw.
    DEC MOBDRAW_I
    BNE MOBDRAW2_SHIFTDOWNL3

    ; At the end, put the bottom area to zero.
    LDX MOBI

    ; First is last -- the copy is reversed!
    LDY MOBDESCRIPTORS_H, X
    LDX MOBDESCRIPTORS_W, X
MOBDRAW2_SHIFTDOWNL1X:
    CLC
    TXA
    ADC MOBADDR
    STA MOBADDR
    ADC #0
    ADC MOBADDR+1
    STA MOBADDR+1
    DEY
    BNE MOBDRAW2_SHIFTDOWNL1X
    
    LDY MOBSIZE
    DEY
    BEQ MOBDRAW2_SHIFTDOWND4 
    LDA #0
MOBDRAW2_SHIFTDOWNL4:
    STA (MOBADDR), Y
    DEY
    BNE MOBDRAW2_SHIFTDOWNL4

MOBDRAW2_SHIFTDOWND4:

    RTS

; ---------------------------------------------------------------------------
; MODE 2 (BITMAP STANDARD)
; Shift the *current* draw area image of MOBI mob of MOBDRAW_DY pixel 
; to the up. Pixels on the bottom are put to zero.
; ---------------------------------------------------------------------------

MOBDRAW2_SHIFTUP:

    LDX MOBI

    ; Load height (in pixels) = height (in rows) + 8
    LDA MOBDESCRIPTORS_H, X
    ADC #8
    STA MOBDRAW_R

    ; Load width (in pixels) = width (in cols) + 1
    LDA MOBDESCRIPTORS_H, X
    LSR
    LSR
    LSR
    CLC
    ADC #1
    STA MOBDRAW_C

    ; Load displacement = iteraction for each  line
    LDA MOBDRAW_DY
    STA MOBDRAW_K

    ; Calculate the offset for previous line by displacement
    LDA #0
    STA MOBSIZE
MOBDRAW2_SHIFTDOWNL1:
    CLC
    LDA MOBSIZE
    ADC MOBDESCRIPTORS_H, X
    ADC #8
    STA MOBSIZE
    DEC MOBDRAW_K
    BNE MOBDRAW2_SHIFTDOWNL1

    ; Reload displacement = iteraction for each  line
    LDA MOBDRAW_DY
    STA MOBDRAW_K

    ; Load location of draw data
    LDA MOBDESCRIPTORS_DL, X
    STA MOBADDR
    LDA MOBDESCRIPTORS_DH, X
    STA MOBADDR+1

    ; Load first location of draw data (by displacement)
    LDA MOBDESCRIPTORS_DL, X
    STA TMPPTR
    LDA MOBDESCRIPTORS_DH, X
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC MOBSIZE
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Rows loop
MOBDRAW2_SHIFTDOWNL2:

    ; j = cols
    LDA MOBDRAW_C
    STA MOBDRAW_J

    LDY #0
    CLC

    ; Cols loop
MOBDRAW2_SHIFTDOWNL3:

    ; Move the content of the cell by 1 row down.
    LDA (TMPPTR),Y
    STA (MOBADDR),Y

    ; Move to the next cell on the same line.
    ; This is placed after 8 bytes from the current position.
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    INY

    ; Repeat for each cell of the same row.
    DEC MOBDRAW_J
    BNE MOBDRAW2_SHIFTDOWNL3

    ; Move to the next line
    CLC
    LDA MOBADDR
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR

    CLC
    LDA TMPPTR
    ADC #8
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR

    ; Repeat for each row of the entire draw.
    DEC MOBDRAW_I
    BNE MOBDRAW2_SHIFTDOWNL3

    ; At the end, put the top area to zero.
    LDX MOBI

    LDA MOBDESCRIPTORS_DL, X
    STA MOBADDR
    LDA MOBDESCRIPTORS_DH, X
    STA MOBADDR+1    

    LDY MOBSIZE
    DEC Y
    BEQ MOBDRAW2_SHIFTDOWND4 
MOBDRAW2_SHIFTDOWNL4:
    STA (MOBADDR), Y
    DEC Y
    BNE MOBDRAW2_SHIFTDOWNL4

MOBDRAW2_SHIFTDOWND4:

    RTS

; Chipset specific initialization
; (we use the data that generic initialization put on descriptor)
MOBINITCS2:
    
    LDX MOBI

    ; Save the actual data into save attribute of descriptor,
    ; in order to avoid to lose it during allocation.
    LDA MOBDESCRIPTORS_DL,X
    STA MOBDESCRIPTORS_SL,X
    LDA MOBDESCRIPTORS_DH,X
    STA MOBDESCRIPTORS_SH,X

    ; Now load the actual size of the image
    ; (in pixel)
    LDA MOBDESCRIPTORS_W, X
    STA MOBW
    LDA MOBDESCRIPTORS_H, X
    STA MOBH

    ; Calculate the needed memory space for the drawing area
    ; that will contain the drawing. It must be 8 pixels (+ 1 cell) wider
    ; and 8 pixel (+ 1 cell) higher.
    LDA MOBW
    ROR
    ROR
    ROR
    CLC
    ADC #1
    STA MOBW

    LDA MOBH
    ROR
    ROR
    ROR
    CLC
    ADC #1
    STA MOBH

    ; Now calculate the product MOBW x MOBH
    ; in MOBSIZE (bytes needed)
    LDA #0
    LDX #8
MOBINITCS21:
    LSR MOBH
    BCC MOBINITCS22
    CLC
    ADC MOBW
MOBINITCS22:
    ROR A
    ROR MOBSIZE
    DEX
    BNE MOBINITCS21
    STA MOBSIZE+1

    ; Now we can allocate the space on the MOBSEGMENT
    JSR MOBALLOC

    LDX MOBI

    ; We now can save the address of freshly allocated
    ; space into the specific descriptor.
    LDA MOBADDR
    STA MOBDESCRIPTORS_DL,X
    LDA MOBADDR+1
    STA MOBDESCRIPTORS_DH,X

    ; Now we can copy the original data to the new space,
    ; at position 0,0 and assuring that is aligned to the
    ; new space.

    ; Recalculate limits (w,h)
    LDA MOBDESCRIPTORS_W, X
    ROR
    ROR
    ROR
    STA MOBDRAW_J
    LDA MOBDESCRIPTORS_H, X
    STA MOBDRAW_I

    ; Move the source data to a temporary pointer,
    ; (the destination area is already on MOBADDR)
    LDA MOBDESCRIPTORS_SL,X
    STA TMPPTR
    LDA MOBDESCRIPTORS_SH,X
    STA TMPPTR+1

    ; Copy one line at a time.
    LDY #0
MOBINITCSL1:
    LDA (TMPPTR),Y
    STA (MOBADDR),Y
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    DEC MOBDRAW_J
    BNE MOBINITCSL1

    ; Move to the next line
    ; If we are at the last line of the cell,
    ; we must advace of an entire row.
    LDA MOBDRAW_I
    AND #$07
    CMP #$01
    BEQ MOBINITCSL1R8

MOBINITCSL1R1:
    CLC
    LDA TMPPTR
    ADC #8
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR

    CLC
    LDA MOBADDR
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR

    JMP MOBINITCSL1RD

MOBINITCSL1R8:
    CLC
    LDA TMPPTR
    ADC MOBW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR

    CLC
    LDA MOBADDR
    ADC MOBW
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR

    JMP MOBINITCSL1RD

MOBINITCSL1RD:

    ; Repeat for each row of the entire draw.
    DEC MOBDRAW_I
    BNE MOBINITCSL1

    ; Now we must adjust the image inside the larger
    ; clip, by right and bottom shifting it, accordingly
    ; to the (relative) position (x,y)
    LDA MOBDESCRIPTORS_XL, X
    STA MOBX
    LDA MOBDESCRIPTORS_YL, X
    STA MOBY

    ; Calculate dx as x & 7: if the result is not zero,
    ; it means that the drawing is not aligned with the
    ; left border of the image.
    LDA MOBX
    AND #$07
    STA MOBDRAW_DX
    BEQ MOBINITCS2A

    ; If not aligned, we must shift it right by dx
    JSR MOBDRAW2_SHIFTRIGHT

MOBINITCS2A:

    ; Calculate dy as y & 7: if the result is not zero,
    ; it means that the drawing is not aligned with the
    ; top border of the image.

    LDA MOBY
    AND #$07
    STA MOBDRAW_DY
    BEQ MOBINITCS2B

    ; If not aligned, we must shift it down by dy
    JSR MOBDRAW2_SHIFTDOWN

    RTS

MOBINITCS0:
MOBINITCS1:
MOBINITCS3:
MOBINITCS4:
    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; MOBSAVE(X:indeX) -> chipset
MOBSAVE:
    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BEQ MOBSAVE2
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BEQ MOBSAVE3
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BEQ MOBSAVE0
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BEQ MOBSAVE1
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BEQ MOBSAVE4
    RTS

MOBSAVE2:
MOBSAVE3:
    RTS

MOBSAVE0:
MOBSAVE1:
MOBSAVE4:
    RTS

; MOBRESTORE(X:indeX) -> chipset
MOBRESTORE:
    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BEQ MOBRESTORE2
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BEQ MOBRESTORE3
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BEQ MOBRESTORE0
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BEQ MOBRESTORE1
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BEQ MOBRESTORE4
    RTS

MOBRESTORE2:
MOBRESTORE3:
    RTS

MOBRESTORE0:
MOBRESTORE1:
MOBRESTORE4:
    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Chipset specific drawing routine
; MOBDRAW(X:indeX) -> chipset
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MOBDRAW:
    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BEQ MOBDRAW2
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BEQ MOBDRAW3
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BEQ MOBDRAW0
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BEQ MOBDRAW1
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BEQ MOBDRAW4

    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; DRAW MODE 2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; This routine will do nothing, by skipping the
; number of bytes (rows in a cell) given by 
; MOBDRAW_DY parameters. 
MOBDRAW2_NOP:
    CLC
    LDA MOBADDR
    ADC MOBDRAW_DY
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR+1
    CLC
    LDA PLOTDEST
    ADC MOBDRAW_DY
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1
    RTS

; This routine will do nothing, by skipping the
; number of bytes (rows in a cell) given by 
; 8-MOBDRAW_DY parameters. 
MOBDRAW2_NOP:
    CLC
    LDA MOBADDR
    ADC #8
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR+1
    SEC
    LDA MOBADDR
    SBC MOBDRAW_DY
    STA MOBADDR
    LDA MOBADDR+1
    SBC #0
    STA MOBADDR+1

    CLC
    LDA PLOTDEST
    ADC #8
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1
    SEC
    LDA PLOTDEST
    SBC MOBDRAW_DY
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1
    RTS

; This routine will do a "left mask", by taking the original pixels
; from the drawing, protecting the first MOBDRAW_DX pixels and
; replacing the others. 
MOBDRAW2_LEFTMASK:
    LDY MOBDRAW_DX
    LDA (MOBDRAW_MASKX),Y       ; maskX
    EOR A                       ; ~ maskX
    LDY #0
    AND (PLOTDEST),Y           ; B & ~ maskX
    STA MOBDRAW_TMP
    LDY MOBDRAW_DX
    LDA (MOBDRAW_MASKX),Y       ; maskX
    LDY #0
    AND (MOBADDR),Y           ; S & maskX
    ORA MOBDRAW_TMP
    STA (PLOTDEST),Y
    RTS

; This routine will do a "right mask", by taking the original pixels
; from the drawing, protecting the last MOBDRAW_DX pixels and
; replacing the others.
MOBDRAW2_RIGHTMASK:
    LDY MOBDRAW_DX
    LDA (MOBDRAW_MASKX),Y       ; maskX
    LDY #0
    AND (PLOTDEST),Y           ; B & maskX
    STA MOBDRAW_TMP
    LDY MOBDRAW_DX
    LDA (MOBDRAW_MASKX),Y       ; maskX
    EOR A                       ; ~ maskX
    LDY #0
    AND (MOBADDR),Y           ; S & ~ maskX
    ORA MOBDRAW_TMP
    STA (PLOTDEST),Y
    RTS

; This routine will do a simple copy of the drawing pixels over the
; original one, replacing them.
MOBDRAW2_COPY:
    LDY #0
    LDA (MOBADDR),Y       ; S
    STA (PLOTDEST),Y       ; D
    RTS

; This routine will increment the position of the operation to the
; next byte (row) of the current cell.
MOBDRAW2_INC:
    CLC
    LDA MOBADDR
    ADC #1
    STA MOBADDR
    LDA MOBADDR+1
    ADC #0
    STA MOBADDR+1

    CLC
    LDA PLOTDEST
    ADC #1
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1
    RTS

; This entry point is needed do draw the image over the screen,
; in standard BITMAP MODE (2).
MOBDRAW2:

    ; Calculate the effective offset of the image,
    ; in order to know how many pixels we have to
    ; skip / mask.
    LDA MOBDESCRIPTORS_YL, x
    AND #$07
    STA MOBDRAW_DY

    LDA MOBDESCRIPTORS_XL, x
    AND #$07
    STA MOBDRAW_DX

    ; +---+---...---+---+
    ; |XXX|         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+

    ; Skip DY rows
    JSR MOBDRAW2_NOP

    ; Copy (masked) 8-DY rows
    LDX MOBDRAW_DY
MOBDRAW2L1:
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    INX
    CPX #8
    BNE MOBDRAWL1

    ; +---+---...---+---+
    ; |   |xxxxxxxxx|   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+

    LDX MOBI

    ; Calculate how many times we have to repeat
    ; the cell copying. If the image's width is less than
    ; 9 pixels, we skip this part.
    LDA MOBDESCRIPTORS_W, X
    LSR
    LSR
    LSR
    BEQ MOBDRAW2L3
    DEC A
    BEQ MOBDRAW2L3
    STA MOBDRAW_J

    ; Repeate an entire cell copy for each column
MOBDRAW2L2A:    
    ; Skip DY rows
    JSR MOBDRAW2_NOP
    ; Copy 8-DY rows
    LDX MOBDRAW_DY
MOBDRAW2L2:
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    INX
    CPX #8
    BNE MOBDRAWL2
    DEC MOBDRAW_J
    BNE MOBDRAW2L2A

MOBDRAW2L3:

    ; +---+---...---+---+
    ; |   |         |xxx|
    ; +---+---...---+---+
    ; |   |         |   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+

    LDX MOBI

    ; Skip DY rows
    JSR MOBDRAW2_NOP

    ; Copy by right masking 8-DY rows
    LDX MOBDRAW2_DY
MOBDRAW2L3B:
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    INX
    CPX #8
    BNE MOBDRAW2L3B

    LDX MOBI

    ; Calculate how many times we have to repeat
    ; the row copying. If the image's height is less than
    ; 8 pixels, we skip this part.
    LDA MOBDESCRIPTORS_H, X
    LSR
    LSR
    LSR
    BEQ MOBDRAW2L6
    DEC A
    BEQ MOBDRAW2L6

    STA MOBDRAW_J

MOBDRAW2L4:
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+
    ; |xxx|         |   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+

    ; Copy "left masked" the left most cell.
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC

    ; Calculate how many times we have to repeat
    ; the cell copying. If the image's width is less than
    ; 9 pixels, we skip this part.
    LDA MOBDESCRIPTORS_W, X
    LSR
    LSR
    LSR
    BEQ MOBDRAW2L5
    DEC A
    BEQ MOBDRAW2L5

    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |xxxxxxxxx|   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+

    ; Repeate an entire cell copy for each column
    TAX
MOBDRAW2L4:
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    DEX
    BNE MOBDRAW2L4

    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |xxx|
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+

    ; Copy "right masked" the left most cell.
MOBDRAW2L5:
    
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC

    DEC MOBDRAW_J
    BNE MOBDRAW2L4

MOBDRAW2L6:
    
    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |XXX|         |   |
    ; +---+---...---+---+

    LDX MOBI

    ; Copy (masked) DY rows
    LDX #0
MOBDRAW2L7:
    JSR MOBDRAW2_LEFTMASK
    JSR MOBDRAW2_INC
    INX
    CPX MOBDRAW_DY
    BNE MOBDRAWL1

    ; Ignore 8-DY rows
    JSR MOBDRAW2_NOP2

    ; +---+---...---+---+
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |         |   |
    ; .   .         .   .
    ; |   |         |   |
    ; +---+---...---+---+
    ; |   |XXXXXXXXX|   |
    ; +---+---...---+---+

    LDX MOBI

    ; Calculate how many times we have to repeat
    ; the cell copying. If the image's width is less than
    ; 9 pixels, we skip this part.
    LDA MOBDESCRIPTORS_W, X
    LSR
    LSR
    LSR
    BEQ MOBDRAW2L9
    DEC A
    BEQ MOBDRAW2L9
    STA MOBDRAW_J

    ; Repeate an entire cell copy for each column
MOBDRAW2L8A:    
    ; Copy DY rows
    LDX #0
MOBDRAW2L8:
    JSR MOBDRAW2_COPY
    JSR MOBDRAW2_INC
    INX
    CPX MOBDRAW_DY
    BNE MOBDRAW2L8
    ; Skip 8-DY rows
    JSR MOBDRAW2_NOP2
    DEC MOBDRAW_J
    BNE MOBDRAW2L8A

MOBDRAW2L9:

    LDX MOBI

    ; Copy by right masking DY rows
    LDX #0
MOBDRAW2L3B:
    JSR MOBDRAW2_RIGHTMASK
    JSR MOBDRAW2_INC
    INX
    CPX MOBDRAW_DY
    BNE MOBDRAW2L3B

    ; Skip 8-DY rows
    JSR MOBDRAW2_NOP2

    RTS

MOBDRAW3:

    RTS

MOBDRAW0:
MOBDRAW1:
MOBDRAW4:

    RTS

; Mask for bit selection / unselection on a single cell
; during drawing operations.
MOBDRAW2_MASKX:
    .byte %11111111
    .byte %01111111
    .byte %00111111
    .byte %00011111
    .byte %00001111
    .byte %00000111
    .byte %00000011
    .byte %00000001

