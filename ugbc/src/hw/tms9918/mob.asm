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
;*                  MOVABLE OBJECTS UNDER MSX1 (specific algorithms)           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

MOBDRAW_TMP: DB 0
MOBDRAW_PD: DB 0
MOBDRAW_DY: DB 0
MOBDRAW_DY2: DB 0
MOBDRAW_DX: DB 0
MOBDRAW_I: DB 0
MOBDRAW_J: DB 0
MOBDRAW_K: DB 0
MOBDRAW_C: DB 0
MOBDRAW_R: DB 0

; ; ---------------------------------------------------------------------------
; ; Chipset specific initialization
; ; MOBINITCS(X:index,draw)
; ; ---------------------------------------------------------------------------

; MOBDRAW2_SHIFTRIGHT:

;     ; Load first location of draw data
;     LD A, (IX+11)
;     LD (MOBADDR), A
;     LD A, (IX+12)
;     LD (MOBADDR+1), A

;     ; Load height (in pixels) = height (in rows) + 8
;     LD A, (IX+10)
;     LD (MOBH), A
;     ADD A, 8
;     LD (MOBDRAW_R), A
;     LD (MOBDRAW_I), A

;     ; Load width (in pixels) = width (in cols) + 1
;     LD A, (IX+9)
;     SRL A
;     SRL A
;     SRL A
;     ADD A, 1
;     LD (MOBDRAW_C), A
;     SLA A
;     SLA A
;     SLA A
;     LD (MOBW), A

;     ; Load displacement = iteraction for each  line
;     LD A, (MOBDRAW_DX)
;     AND A, 7
;     LD (MOBDRAW_K), A

;     LD A, MOBDRAW_K
;     LD E, A

;     ; Rows loop
; MOBDRAW2_SHIFTRIGHTL1:

;     ; j = cols
;     LD A, (MOBDRAW_C)
;     LD (MOBDRAW_J), A

;     LD A, MOBDRAW_J
;     LD C, A

;     AND A

;     LD HL, (MOBADDR)

;     ; Cols loop
; MOBDRAW2_SHIFTRIGHTL2:

;     ; Rotate the content of the cell by 1 pixel to the right
;     ; and save the last pixel on carry. The carry will be put
;     ; on the leftmost pixel.
;     LD A, (HL)
;     RR A
;     LD (HL), A

;     ; Move to the next cell on the same line.
;     INC HL

;     ; Repeat for each cell of the same row.
;     DEC C
;     JR NZ, MOBDRAW2_SHIFTRIGHTL2

;     ; Repeat for the entire size of the displacement.
;     LD HL, (MOBADDR)
;     DEC E
;     JR NZ, MOBDRAW2_SHIFTRIGHTL1

;     ; Move to the next line

;     LD HL, (MOBADDR)
;     LD A, MOBDRAW_C
;     LD E, A
;     LD A, 0
;     LD D, 0
;     ADD HL, DE
;     LD (MOBADDR), HL

;     LD A, MOBDRAW_K
;     LD E, A

;     ; Repeat for each row of the entire draw.
;     LD A, (MOBDRAW_I)
;     DEC A
;     LD (MOBDRAW_I), A
;     CP0
;     JR NZ, MOBDRAW2_SHIFTRIGHTL1
;     RET

; ; ---------------------------------------------------------------------------
; ; MODE 2 (BITMAP STANDARD)
; ; Shift the *current* draw area image of MOBI mob of MOBDRAW_DX pixel 
; ; to the left. Pixels on the right are put to zero.
; ; ---------------------------------------------------------------------------

; MOBDRAW2_SHIFTLEFT:

;     ; Load first location of draw data
;     LD A, (IX+11)
;     LD (MOBADDR), A
;     LD A, (IX+12)
;     LD (MOBADDR+1), A

;     LD A, (IX+15)
;     LD (MOBSIZE), A
;     LD A, (IX+16)
;     LD (MOBSIZE+1), A

;     ; Load height (in pixels) = height (in rows) + 8
;     LD A, (IX+10)
;     LD (MOBH), A
;     ADD 8
;     LD (MOBDRAW_R), A
;     LD (MOBDRAW_I), A

;     ; Load width (in pixels) = width (in cols) + 1
;     LD A, (IX+9)
;     SRL A
;     SRL A
;     SRL A
;     ADD A, 1
;     LD (MOBDRAW_C), A
;     SUB A, 1
;     SLA A
;     SLA A
;     SLA A
;     LD (MOBW), A

;     ; Load displacement = iteraction for each  line
;     LD A, (MOBDRAW_DX)
;     AND A, 7
;     LD (MOBDRAW_K), A

;     LD A, (MOBDRAW_K)
;     LD E, A

;     ; Rows loop
; MOBDRAW2_SHIFTLEFTL1:

;     ; j = cols
;     LD A, (MOBDRAW_C)
;     LD (MOBDRAW_J), A

;     LD A, (MOBDRAW_C)
;     LD C, A

;     LD HL, (MODADDR)
;     AND A

;     ; Cols loop
; MOBDRAW2_SHIFTLEFTL2:

;     ; Rotate the content of the cell by 1 pixel to the left
;     ; and save the first pixel on carry. The carry will be put
;     ; on the rightmost pixel.
;     LD A, (HL)
;     RL A
;     LD (HL), A

;     ; Move to the previous cell on the same line.
;     ; This is placed after 8 bytes from the current position.
;     DEC HL

;     ; Repeat for each cell of the same row.
;     DEC C
;     JR NZ, MOBDRAW2_SHIFTLEFTL2

;     ; Repeat for the entire size of the displacement.
;     LD A, (MOBDRAW_C)
;     LD C, A

;     LD HL, (MODADDR)
;     AND A

;     DEC E
;     JR NZ, MOBDRAW2_SHIFTLEFTL1

;     ; Move to the next line

;     LD HL, (MODADDR)
;     LD A, MOBDRAW_C
;     LD E, A
;     LD A, 0
;     LD D, A

;     LD A, (MOBDRAW_DX)
;     AND A, 7
;     LD (MOBDRAW_K), A

;     LD A, (MOBDRAW_K)
;     LD E, A

;     ; Repeat for each row of the entire draw.
;     LD A, (MOBDRAW_I)
;     DEC A
;     LD (MOBDRAW_I), A
;     CP0
;     JR NZ, MOBDRAW2_SHIFTLEFTL1
;     RET

; ; ---------------------------------------------------------------------------
; ; MODE 2 (BITMAP STANDARD)
; ; Shift the *current* draw area image of MOBI mob of MOBDRAW_DY pixel 
; ; to the top. Pixels on the bottom are put to zero.
; ; ---------------------------------------------------------------------------

; MOBDRAW2_SHIFTUP:

;     LD A, (MOBDRAW_DY)
;     AND A, 7
;     LD (MOBDRAW_K), A

;     LD A, (IX+9)
;     SRL A
;     SRL A
;     SRL A
;     ADD A, 1
;     LD (MOBDRAW_C), A
;     SLA A
;     SLA A
;     SLA A
;     LD (MOBW), A
;     LD A, 0
;     LD (MOBDRAW_J), A

;     ; Load height (in pixels) = height (in rows) + 8
;     LD A, (IX+10)
;     ADD A, 8
;     LD (MOBH), A
;     LD (MOBDRAW_I), A
;     SRL A
;     SRL A
;     SRL A
;     LD (MOBDRAW_R), A

; MOBDRAW2_SHIFTUPL0:

;     ; MOBSIZE = WC x WR
;     LD A, (IX+15)
;     LD (MOBSIZE), A
;     LD A, (IX+16)
;     LD (MOBSIZE+1), A

;     LD A, (MOBDRAW_C)
;     LD (MOBDRAW_TMP), A

; MOBDRAW2_SHIFTUPLCC:

;     LD A, (IX+11)
;     LD (MOBADDR), A
;     LD A, (IX+12)
;     LD (MOBADDR+1), A

;     LD HL, (MOBADDR)
;     LD (TMPPTR), HL

;     LD A, (MOBDRAW_C)
;     LD E, A
;     LD A, 0
;     LD D, A
;     ADD HL, DE

;     LD A, 0
;     LD (MOBDRAW_J), A

; MOBDRAW2_SHIFTUPL1:

;     LD HL, (MOBADDR)
;     LD DE, (TMPPTR)
;     LD C, 0

; MOBDRAW2_SHIFTUPLA:
;     LD A, (HL)
;     LD (DE),A
;     INC C
;     LD A, C
;     CP (MOBDRAW_C)
;     JR NZ, MOBDRAW2_SHIFTUPLA

;     LD HL, (MOBADDR)
;     LD A, MOBDRAW_C
;     LD E, A
;     LD A, 0
;     LD D, A
;     ADD HL, DE
;     LD (MOBADDR), HL

;     LD HL, (TMPPTR)
;     LD A, MOBDRAW_C
;     LD E, A
;     LD A, 0
;     LD D, A
;     SUB HL, DE
;     LD (TMPPTR), HL

;     ; se C < 0 FINE

;     LD A, 0
;     LD C, 0
;     LD (MOBDRAW_J), A

;     LD HL, (MOBADDR)
;     LD DE, (TMPPTR)

;     LD A, (MOBDRAW_I)
;     DEC A
;     LD (MOBDRAW_I), A 
;     CP 0
;     JR Z, MOBDRAW2_SHIFTUPL1X2
;     JMP MOBDRAW2_SHIFTUPL1

; MOBDRAW2_SHIFTUPL1X2:
    
;     LD A, (MOBH)
;     LD (MOBDRAW_I), A

;     LD A, (MOBDRAW_K)
;     DEC A
;     LD (MOBDRAW_K), A

;     CP0
;     JR Z, MOBDRAW2_SHIFTUPL1X3 
;     JMP MOBDRAW2_SHIFTUPLCC

; MOBDRAW2_SHIFTUPL1X3:

;     LD HL, (MOBADDR)
;     LD DE, (TMPPTR)
;     LD C, (MOBDRAW_C)
    
; MOBDRAW2_SHIFTUPLAB:
;     LD A, #0
;     LD (DE), A
;     INC DE
;     DEC C
;     JR NZ, MOBDRAW2_SHIFTUPLAB

; MOBDRAW2_SHIFTUPL0X:

;     RET

; ; ---------------------------------------------------------------------------
; ; MODE 2 (BITMAP STANDARD)
; ; Shift the *current* draw area image of MOBI mob of MOBDRAW_DY pixel 
; ; to the bottom. Pixels on the top are put to zero.
; ; ---------------------------------------------------------------------------

; MOBDRAW2_SHIFTDOWN:

;     LD A, (MOBDRAW_DY)
;     AND A, 7
;     LD (MOBDRAW_K), A

;     LD A, (IX+9)
;     SRL A
;     SRL A
;     SRL A
;     ADD A, 1
;     LD (MOBDRAW_C), A
;     SLA A
;     SLA A
;     SLA A
;     LD (MOBW), A
;     LD A, 0
;     LD (MOBDRAW_J), A

;     ; Load height (in pixels) = height (in rows) + 8
;     LD A, (IX+10)
;     LD (MOBH), A
;     ADD A, 8
;     LD (MOBH), A
;     SRL A
;     SRL A
;     SRL A
;     LD (MOBDRAW_R), A
;     LD A, (MOBH)
;     LD (MOBDRAW_I), A

; MOBDRAW2_SHIFTDOWNL0:

;     ; MOBSIZE = WC x WR
;     LD A, (IX+15)
;     LD (MOBSIZE), A
;     LD A, (IX+16)
;     LD (MOBSIZE+1), A

; MOBDRAW2_SHIFTDOWNLCC:

;     LD A, (IX+11)
;     LD (MOBADDR), A
;     LD A, (IX+12)
;     LD (MOBADDR+1), A

;     LD HL, (MOBADDR)
;     LD DE, (MOBSIZE)
;     ADD HL, DE
;     LD (TMPPTR), HL

;     LD HL, (TMPPTR)
;     LD A, (MOBDRAW_C)
;     LD E, A
;     LD A, 0
;     LD D, A
;     SUB HL, DE
;     LD (MOBADDR), HL

;     LD A, 0
;     LD (MOBDRAW_J), A

; MOBDRAW2_SHIFTDOWNL1:

;     ; se C > WC121 allora

;     LD HL, (MOBADDR)
;     LD DE, (TMPPTR)
;     LD A, (MOBDRAW_C)
;     LD C, A

; MOBDRAW2_SHIFTDOWNLA:
;     ; sposta da [C+6] a [C+7]
;     ; ...
;     ; sposta da [C+1] a [C+2]
;     ; sposta da [C] a [C+1]
;     LD A, (HL)
;     LD (DE), A
;     DEC C
;     JR NZ, MOBDRAW2_SHIFTDOWNLA

;     ; C = C - 8

;     LD HL, (MOBADDR)
;     LD A, (MOBDRAW_C)
;     LD E, A
;     LD A, 0
;     LD D, A
;     SUB HL, DE
;     LD (MOBADDR), HL

;     LD HL, (TMPPTR)
;     LD A, (MOBDRAW_C)
;     LD E, A
;     LD A, 0
;     LD D, A
;     SUB HL, DE
;     LD (TMPPTR), HL

;     ; se C < 0 FINE

;     LD A, 0
;     LD (MOBDRAW_J), 0

;     LD HL, (MOBADDR)
;     LD DE, (TMPPTR)
;     LD A, (MOBDRAW_C)
;     LD C, A

;     LD A, (MOBDRAW_I)
;     DEC A
;     LD (MOBDRAW_I), A
;     CP 0
;     JR Z, MOBDRAW2_SHIFTDOWNL1X2
;     JMP MOBDRAW2_SHIFTDOWNL1

; MOBDRAW2_SHIFTDOWNL1X2:
    
;     LD A, (MOBH)
;     INC A
;     LD (MOBDRAW_I), A

;     LD A, (MOBDRAW_K)
;     DEC A
;     LD (MOBDRAW_K), A

;     CP 0
;     JR Z, MOBDRAW2_SHIFTDOWNL1X3
;     JMP MOBDRAW2_SHIFTDOWNLCC

; MOBDRAW2_SHIFTDOWNL1X3:

;     LD HL, (MOBADDR)
;     LD DE, (TMPPTR)
;     LD A, (MOBDRAW_C)
;     LD C, A

; MOBDRAW2_SHIFTDOWNLAB:
;     LD A, 0
;     LD (DE),A
;     DEC C
;     JR NZ, MOBDRAW2_SHIFTDOWNLAB

; MOBDRAW2_SHIFTDOWNL0X:

;     RET
  
; ; Chipset specific initialization
; ; (we use the data that generic initialization put on descriptor)
; MOBINITCS:

;     LD A, (MOBI)
;     LD B, A

;     CALL MOBDESCRIPTOR

;     ; Save the actual data into save attribute of descriptor,
;     ; in order to avoid to lose it during allocation.
;     LD A, (IX+11)
;     LD (IX+13), A
;     LD A, (IX+12)
;     LD (IX+14), A

;     ; Now load the actual size of the image
;     ; (in pixel)
;     LD A, (IX+9)
;     LD (MOBW), A
;     LD A, (IX+10)
;     LD (MOBH), A

;     ; Calculate the needed memory space for the drawing area
;     ; that will contain the drawing. It must be 8 pixels (+ 1 cell) wider
;     ; and 8 pixel (+ 1 cell) higher.
;     LD A, (MOBW)
;     SRL A
;     SRL A
;     SRL A
;     ADD A, 1
;     LD (MOBDRAW_C), A

;     LD A, (MOBH)
;     SRL A
;     SRL A
;     SRL A
;     ADD A, 1
;     LD (MOBDRAW_R), A
;     SLA A
;     SLA A
;     SLA A
;     LD (MOBH), A

;     LD A, (MOBDRAW_R)
;     DEC A
;     LD (MOBDRAW_R), A

;     ; Now calculate the product MOBW x MOBH
;     ; in MOBSIZE (bytes needed)
    
;     LD A, (MOBW)
;     LD H, A
;     LD A, (MOBH)
;     LD E, A

;     LD D, 0
;     LD L, D
;     LD B, 8
; MOBINITCSLSIZE:
;     ADD HL, HL
;     JR NC, MOBINITCSLSIZE2
;     ADD HL, DE

; MOBINITCSLSIZE2:
;     DJNZ MOBINITCSLSIZE
;     LD (MOBSIZE), HL

;     LD A, (MOBI)
;     LD B, A

;     LD HL, (MOBSIZE)
;     LD (IX+15), HL

;     LD A, (IX+10)
;     LD (MOBH), A

; MOBINITCS22X:
;     ; Now we can allocate the space on the MOBSEGMENT
;     CALL MOBALLOC

;     LD A, (MOBI)
;     LD B, A

;     ; We now can save the address of freshly allocated
;     ; space into the specific descriptor.
;     LD HL, (MOBADDR)
;     LD (IX+11), HL

;     ; Now we can copy the original data to the new space,
;     ; at position 0,0 and assuring that is aligned to the
;     ; new space.

;     ; Recalculate limits (w,h)
;     LD A, (MOBDRAW_C)
;     LD (MOBDRAW_J), A
;     SLA A
;     SLA A
;     SLA A
;     LD (MOBW), A
;     LD A, (MOBH)
;     LD (MOBDRAW_I), A

;     ; Move the source data to a temporary pointer,
;     ; (the destination area is already on MOBADDR)
;     LD HL, (IX+13)
;     LD (TMPPTR), HL

;     ; Copy one line at a time.
; MOBINITCSL1A:
;     DEC MOBDRAW_J
;     LDY #0
; MOBINITCSL1:
;     LDA (TMPPTR),Y
;     STA (MOBADDR),Y
;     INY
;     DEC MOBDRAW_J
;     BNE MOBINITCSL1

;     LDA #0
;     STA (MOBADDR),Y

;     CLC
;     LDA TMPPTR
;     ADC MOBDRAW_C
;     STA TMPPTR
;     LDA TMPPTR+1
;     ADC #0
;     STA TMPPTR+1

;     SEC
;     LDA TMPPTR
;     SBC #1
;     STA TMPPTR
;     LDA TMPPTR+1
;     SBC #0
;     STA TMPPTR+1

;     CLC
;     LDA MOBADDR
;     ADC MOBDRAW_C
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     ; Repeat for each row of the entire draw.
;     LDA MOBDRAW_C
;     STA MOBDRAW_J
;     DEC MOBDRAW_I
;     BEQ MOBINITCSL1AX
;     JMP MOBINITCSL1A

; MOBINITCSL1AX:

;     LDA MOBDRAW_C
;     STA MOBDRAW_J

;     LDA #8
;     STA MOBDRAW_I
; MOBINITCSL1HG:
;     LDY #0
; MOBINITCSL1H:
;     LDA #0
;     STA (MOBADDR),Y
;     INY
;     DEC MOBDRAW_J
;     BNE MOBINITCSL1H

;     CLC
;     LDA MOBADDR
;     ADC MOBDRAW_C
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     LDA MOBDRAW_C
;     STA MOBDRAW_J
;     DEC MOBDRAW_I
;     BEQ MOBINITCSL1HGX
;     JMP MOBINITCSL1HG

; MOBINITCSL1HGX:

;     ; Now we must adjust the image inside the larger
;     ; clip, by right and bottom shifting it, accordingly
;     ; to the (relative) position (x,y)
;     LDA MOBDESCRIPTORS_XL, X
;     STA MOBX
;     LDA MOBDESCRIPTORS_YL, X
;     STA MOBY

;     ; Calculate dx as x & 7: if the result is not zero,
;     ; it means that the drawing is not aligned with the
;     ; left border of the image.
;     LDA MOBX
;     AND #$07
;     STA MOBDRAW_DX
;     BEQ MOBINITCS2A

;     ; If not aligned, we must shift it right by dx
;     JSR MOBDRAW2_SHIFTRIGHT

; MOBINITCS2A:

;     ; Calculate dy as y & 7: if the result is not zero,
;     ; it means that the drawing is not aligned with the
;     ; top border of the image.

;     LDA MOBY
;     AND #$07
;     STA MOBDRAW_DY
;     BEQ MOBINITCS2B

;     ; If not aligned, we must shift it down by dy
;     JSR MOBDRAW2_SHIFTDOWN

; MOBINITCS2B:

;     RET

; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ; MOBSAVE(X:indeX) -> chipset
; MOBSAVE:
;     LDA (CURRENTMODE)
;     CMP #8
;     BNE MOBSAVE8X
;     JMP MOBSAVE8
; MOBSAVE8X:
;     CMP #9
;     BNE MOBSAVE9X
;     JMP MOBSAVE9
; MOBSAVE9X:
;     CMP #10
;     BNE MOBSAVE10X
;     JMP MOBSAVE10
; MOBSAVE10X:
;     CMP #11
;     BNE MOBSAVE11X
;     JMP MOBSAVE11
; MOBSAVE11X:
;     CMP #13
;     BNE MOBSAVE13X
;     JMP MOBSAVE13
; MOBSAVE13X:
;     CMP #15
;     BNE MOBSAVE15X
;     JMP MOBSAVE15
; MOBSAVE15X:
;     CMP #12
;     BNE MOBSAVE12X
;     JMP MOBSAVE12
; MOBSAVE12X:
;     CMP #14
;     BNE MOBSAVE14X
;     JMP MOBSAVE14
; MOBSAVE14X:
;     RET

; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ;; SAVE MODE 2
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ; This routine will increment the position of the operation to the
; ; next byte (row) of the current cell.
; MOBSAVE2_INC:
;     CLC
;     LDA MOBADDR
;     ADC #1
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     CLC
;     LDA PLOTDEST
;     ADC #1
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1
;     RET

; MOBSAVE8:
; MOBSAVE10:
; MOBSAVE13:
; MOBSAVE14:
;     RET

; ; This entry point is needed do save the screen into the reserved area,
; ; in standard BITMAP MODE (2).

; MOBSAVE9:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     LSR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT4VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT4VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBSAVECOMMON

; MOBSAVE11:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     LSR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT5VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBSAVECOMMON

; MOBSAVE15:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     ROR MOBDESCRIPTORS_XH,X                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT6VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT6VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBSAVECOMMON

; MOBSAVE12:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     ROR MOBDESCRIPTORS_XH,X                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT5VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBSAVECOMMON

; MOBSAVECOMMON:

;     LDX MOBI

;     LDA (IX+15)
;     STA MOBSIZE
;     LDA MOBDESCRIPTORS_SIZEH,X
;     STA MOBSIZE+1

;     JSR MOBALLOC

;     LDA MOBADDR
;     STA MOBDESCRIPTORS_SL, X
;     LDA MOBADDR+1
;     STA MOBDESCRIPTORS_SH, X

;     ; +---+---...---+---+
;     ; |xxx|xxxxxxxxx|xxx|
;     ; +---+---...---+---+
;     ; |   |         |   |
;     ; .   .         .   .
;     ; |   |         |   |
;     ; +---+---...---+---+
;     ; |   |         |   |
;     ; +---+---...---+---+

;     LDX MOBI

;     ; Calculate how many times we have to repeat
;     ; the row copying. If the image's height is less than
;     ; 0 pixels, we skip this part.
;     LDA (IX+10)
;     BNE MOBSAVE2L3X1
;     JMP MOBSAVE2L3

; MOBSAVE2L3X1:

;     CLC
;     ADC #8
;     STA MOBDRAW_I

;     ; Calculate how many times we have to repeat
;     ; the cell copying. If the image's width is less than
;     ; 9 pixels, we skip this part.
;     LDA (IX+9)
;     LSR
;     LSR
;     LSR
;     BNE MOBSAVE2L3X2
;     JMP MOBSAVE2L3
; MOBSAVE2L3X2:

;     CLC
;     ADC #1
;     STA MOBDRAW_J
;     STA MOBDRAW_C

;     ; Repeate an entire cell copy for each column
; MOBSAVE2L2A:    
;     LDY #0
; MOBSAVE2L2:
;     LDA (PLOTDEST),Y       ; D
;     STA (MOBADDR),Y       ; S
;     INY
;     DEC MOBDRAW_J
;     BEQ MOBSAVE2L2X
;     JMP MOBSAVE2L2

; MOBSAVE2L2X:

;     CLC
;     LDA PLOTDEST
;     ADC CURRENTSL
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1

;     CLC
;     LDA MOBADDR
;     ADC MOBDRAW_C
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     LDA MOBDRAW_C
;     STA MOBDRAW_J
;     DEC MOBDRAW_I
;     BEQ MOBSAVE2L2AX
;     JMP MOBSAVE2L2A

; MOBSAVE2L2AX:

; MOBSAVE2L3:

;     RET

; ; MOBRESTORE(X:indeX) -> chipset
; MOBRESTORE:
;     LDA (CURRENTMODE)
;     CMP #8
;     BNE MOBRESTORE8X
;     JMP MOBRESTORE8
; MOBRESTORE8X:
;     CMP #9
;     BNE MOBRESTORE9X
;     JMP MOBRESTORE9
; MOBRESTORE9X:
;     CMP #10
;     BNE MOBRESTORE10X
;     JMP MOBRESTORE10
; MOBRESTORE10X:
;     CMP #11
;     BNE MOBRESTORE11X
;     JMP MOBRESTORE11
; MOBRESTORE11X:
;     CMP #13
;     BNE MOBRESTORE13X
;     JMP MOBRESTORE13
; MOBRESTORE13X:
;     CMP #15
;     BNE MOBRESTORE15X
;     JMP MOBRESTORE15
; MOBRESTORE15X:
;     CMP #12
;     BNE MOBRESTORE12X
;     JMP MOBRESTORE12
; MOBRESTORE12X:
;     CMP #14
;     BNE MOBRESTORE14X
;     JMP MOBRESTORE14
; MOBRESTORE14X:
;     RET

; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ;; RESTORE MODE 2
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ; This routine will do a simple copy of the screen pixels over the
; ; save area one, replacing them.
; MOBRESTORE2_COPY:
;     LDY #0
;     LDA (MOBADDR),Y       ; S
;     ; LDA #$AA
;     STA (PLOTDEST),Y       ; D
;     RET

; ; This routine will increment the position of the operation to the
; ; next byte (row) of the current cell.
; MOBRESTORE2_INC:
;     CLC
;     LDA MOBADDR
;     ADC #1
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     CLC
;     LDA PLOTDEST
;     ADC #1
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1
;     RET

; MOBRESTORE2_INCL:
;     CLC
;     LDA PLOTDEST
;     ADC CURRENTSL
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1

;     SEC
;     LDA PLOTDEST
;     SBC MOBDRAW_C
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     SBC #0
;     STA PLOTDEST+1

;     RET

; MOBRESTORE8:
; MOBRESTORE10:
; MOBRESTORE13:
; MOBRESTORE14:
;     RET

; ; This entry point is needed do save the screen into the reserved area,
; ; in standard BITMAP MODE (2).

; MOBRESTORE9:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_PYL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_PXL,X
;     LSR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT4VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT4VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBRESTORECOMMON

; MOBRESTORE11:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_PYL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_PXL,X
;     LSR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT5VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBRESTORECOMMON

; MOBRESTORE15:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_PYL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_PXL,X
;     ROR MOBDESCRIPTORS_PXH,X
;     ROR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT6VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT6VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBRESTORECOMMON

; MOBRESTORE12:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_PYL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_PXL,X
;     ROR MOBDESCRIPTORS_PXH,X
;     ROR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT5VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBRESTORECOMMON
    
; MOBRESTORECOMMON:

;     LDX MOBI

;     LDA MOBDESCRIPTORS_SL, X
;     STA MOBADDR
;     LDA MOBDESCRIPTORS_SH, X
;     STA MOBADDR+1

;     ; +---+---...---+---+
;     ; |xxx|xxxxxxxxx|xxx|
;     ; +---+---...---+---+
;     ; |   |         |   |
;     ; .   .         .   .
;     ; |   |         |   |
;     ; +---+---...---+---+
;     ; |   |         |   |
;     ; +---+---...---+---+

;     LDX MOBI

;     ; Calculate how many times we have to repeat
;     ; the row copying. If the image's height is less than
;     ; 8 pixels, we skip this part.
;     LDA (IX+10)
;     STA MOBH
;     LSR
;     LSR
;     LSR
;     BEQ MOBRESTORE2L3
;     CLC
;     ADC #1
;     STA MOBDRAW_R

;     ; Calculate how many times we have to repeat
;     ; the cell copying. If the image's width is less than
;     ; 9 pixels, we skip this part.
;     LDA (IX+9)
;     LSR
;     LSR
;     LSR
;     BEQ MOBRESTORE2L3
;     CLC
;     ADC #1
;     STA MOBDRAW_J
;     STA MOBDRAW_C
;     ASL
;     ASL
;     ASL
;     STA MOBW

;     ; Repeate an entire cell copy for each column
; MOBRESTORE2L2A:    
; MOBRESTORE2L2:
;     JSR MOBRESTORE2_COPY
;     JSR MOBRESTORE2_INC
;     DEC MOBDRAW_J
;     BNE MOBRESTORE2L2A

;     JSR MOBRESTORE2_INCL

;     LDA MOBDRAW_C
;     STA MOBDRAW_J
;     DEC MOBDRAW_I
;     BNE MOBRESTORE2L2A

; MOBRESTORE2L3:

;     LDX MOBI

;     LDA (IX+15)
;     STA MOBSIZE
;     LDA MOBDESCRIPTORS_SIZEH,X
;     STA MOBSIZE+1

;     JSR MOBFREE

;     LDA #0
;     STA MOBDESCRIPTORS_SL, X
;     LDA #0
;     STA MOBDESCRIPTORS_SH, X

;     RET

; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ; Chipset specific drawing routine
; ; MOBDRAW(X:indeX) -> chipset
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; MOBDRAW:
;     LDA (CURRENTMODE)
;     CMP #8
;     BNE MOBDRAW8X
;     JMP MOBDRAW8
; MOBDRAW8X:
;     CMP #9
;     BNE MOBDRAW9X
;     JMP MOBDRAW9
; MOBDRAW9X:
;     CMP #10
;     BNE MOBDRAW10X
;     JMP MOBDRAW10
; MOBDRAW10X:
;     CMP #11
;     BNE MOBDRAW11X
;     JMP MOBDRAW11
; MOBDRAW11X:
;     CMP #13
;     BNE MOBDRAW13X
;     JMP MOBDRAW13
; MOBDRAW13X:
;     CMP #15
;     BNE MOBDRAW15X
;     JMP MOBDRAW15
; MOBDRAW15X:
;     CMP #12
;     BNE MOBDRAW12X
;     JMP MOBDRAW12
; MOBDRAW12X:
;     CMP #14
;     BNE MOBDRAW14X
;     JMP MOBDRAW14
; MOBDRAW14X:
;     RET

; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ;; DRAW MODE 2
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ; This routine will do nothing, by skipping the
; ; number of bytes (rows in a cell) given by 
; ; MOBDRAW_DY parameters. 
; MOBDRAW2_NOP:
;     LDA MOBDRAW_DY
;     STA MOBDRAW_TMP
;     BEQ MOBDRAW2_NOPE
; MOBDRAW2_NOPL1:
;     CLC
;     LDA MOBADDR
;     ADC MOBDRAW_C
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1
;     CLC
;     LDA PLOTDEST
;     ADC CURRENTSL
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1
;     DEC MOBDRAW_TMP
;     BNE MOBDRAW2_NOPL1
; MOBDRAW2_NOPE:
;     RET

; ; This routine will do nothing, by skipping the
; ; number of bytes (rows in a cell) given by 
; ; 8-MOBDRAW_DY parameters. 
; MOBDRAW2_NOP2:
;     CLC
;     LDA MOBADDR
;     ADC #1
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     CLC
;     LDA PLOTDEST
;     ADC #1
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1
;     RET

; ; This routine will do a "left mask", by taking the original pixels
; ; from the drawing, protecting the first MOBDRAW_DX pixels and
; ; replacing the others. 
; MOBDRAW2_LEFTMASK:
;     LDX MOBDRAW_DX
;     LDA MOBDRAW2_MASKX,X       ; maskX
;     EOR #$FF                       ; ~ maskX
;     LDY #0
;     AND (PLOTDEST),Y           ; B & ~ maskX
;     STA MOBDRAW_TMP
;     LDX MOBDRAW_DX
;     LDA MOBDRAW2_MASKX,X       ; maskX
;     LDY #0
;     AND (MOBADDR),Y           ; S & maskX
;     ORA MOBDRAW_TMP
;     STA (PLOTDEST),Y
;     RET

; ; This routine will do a "right mask", by taking the original pixels
; ; from the drawing, protecting the last MOBDRAW_DX pixels and
; ; replacing the others.
; MOBDRAW2_RIGHTMASK:
;     LDX MOBDRAW_DX
;     LDA MOBDRAW2_MASKX,X       ; maskX
;     LDY #0
;     AND (PLOTDEST),Y           ; B & maskX
;     STA MOBDRAW_TMP
;     LDX MOBDRAW_DX
;     LDA MOBDRAW2_MASKX,X       ; maskX
;     EOR #$FF                       ; ~ maskX
;     LDY #0
;     AND (MOBADDR),Y           ; S & ~ maskX
;     ORA MOBDRAW_TMP
;     STA (PLOTDEST),Y
;     RET

; ; This routine will do a simple copy of the drawing pixels over the
; ; original one, replacing them.
; MOBDRAW2_COPY:
;     LDY #0
;     LDA (MOBADDR),Y       ; S
;     STA (PLOTDEST),Y       ; D
;     RET

; ; This routine will increment the position of the operation to the
; ; next byte (row) of the current cell.
; MOBDRAW2_INC:
;     CLC
;     LDA MOBADDR
;     ADC #1
;     STA MOBADDR
;     LDA MOBADDR+1
;     ADC #0
;     STA MOBADDR+1

;     CLC
;     LDA PLOTDEST
;     ADC #1
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1
;     RET

; MOBDRAW2_INCL:
;     CLC
;     LDA PLOTDEST
;     ADC CURRENTSL
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #0
;     STA PLOTDEST+1

;     SEC
;     LDA PLOTDEST
;     SBC MOBDRAW_C
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     SBC #$0
;     STA PLOTDEST+1

;     RET

; MOBDRAW2:

; MOBDRAW8:
; MOBDRAW10:
; MOBDRAW13:
; MOBDRAW14:
;     RET

; ; This entry point is needed do draw the image over the screen,
; ; in standard BITMAP MODE (2).

; MOBDRAW9:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     LSR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT4VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT4VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBDRAWCOMMON

; MOBDRAW11:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     LSR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT5VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBDRAWCOMMON

; MOBDRAW15:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     ROR MOBDESCRIPTORS_XH,X                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT6VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT6VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBDRAWCOMMON

; MOBDRAW12:

;     ;-------------------------
;     ;calc Y-cell
;     ;-------------------------
;     LDA MOBDESCRIPTORS_YL,X
;     TAY                         ;tbl_8,y index

;     LDA MOBDESCRIPTORS_XL,X
;     ROR MOBDESCRIPTORS_XH,X                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     TXA
;     ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
;     STA PLOTDEST               ;= cell address

;     LDA #0
;     ADC PLOT5VBASEHI,Y          ;do the high byte
;     STA PLOTDEST+1

;     JMP MOBDRAWCOMMON

; MOBDRAWCOMMON:

;     LDX MOBI

;     LDA (IX+11)
;     STA MOBADDR
;     LDA (IX+12)
;     STA MOBADDR+1

;     ; Calculate how many times we have to repeat
;     ; the cell copying. If the image's width is less than
;     ; 9 pixels, we skip this part.

;     LDA (IX+9)
;     LSR
;     LSR
;     LSR
;     BNE MOBDRAW2EX
;     JMP MOBDRAW2E
; MOBDRAW2EX:
;     ADC #1
;     STA MOBDRAW_C
;     STA MOBDRAW_J
;     ASL
;     ASL
;     ASL
;     STA MOBW

;     ; Calculate how many times we have to repeat
;     ; the row copying. If the image's height is less than
;     ; 8 pixels, we skip this part.
;     LDA (IX+10)
;     LSR
;     LSR
;     LSR
;     BNE MOBDRAW2L6X
;     JMP MOBDRAW2E
; MOBDRAW2L6X:
;     CLC
;     ADC #1
;     STA MOBDRAW_R
;     ASL
;     ASL
;     ASL
;     STA MOBH

;     STA MOBDRAW_I

;     LDX MOBI

;     ; Calculate the effective offset of the image,
;     ; in order to know how many pixels we have to
;     ; skip / mask.
;     LDA MOBDESCRIPTORS_YL, X
;     AND #$07
;     STA MOBDRAW_DY
;     STA MOBDRAW_DY2
;     STA MOBDRAW_I

;     LDA MOBDESCRIPTORS_XL, X
;     AND #$07
;     STA MOBDRAW_DX

;     ; Skip DY rows
;     ; JSR MOBDRAW2_NOP

;     LDA MOBH
;     SEC
;     SBC #8
;     STA MOBH

;     STA MOBDRAW_I

;     ; +---+---...---+---+
;     ; |XXX|xxxxxxxxx|XXX|
;     ; +---+---...---+---+
;     ; |   |         |   |x
;     ; .   .         .   .x
;     ; |   |         |   |x
;     ; +---+---...---+---+x
;     ; |   |         |   |V
;     ; +---+---...---+---+

;     DEC MOBDRAW_J
; MOBDRAW2L1A:
;     JSR MOBDRAW2_LEFTMASK
;     JSR MOBDRAW2_INC
;     DEC MOBDRAW_J
; MOBDRAW2L1:
;     JSR MOBDRAW2_COPY
;     JSR MOBDRAW2_INC
;     DEC MOBDRAW_J
;     BNE MOBDRAW2L1
;     JSR MOBDRAW2_RIGHTMASK
;     JSR MOBDRAW2_INC

;     JSR MOBDRAW2_INCL

;     ; Calculate how many times we have to repeat
;     ; the cell copying. If the image's width is less than
;     ; 9 pixels, we skip this part.
;     LDA MOBDRAW_C
;     STA MOBDRAW_J
;     DEC MOBDRAW_J

;     DEC MOBDRAW_I
;     BEQ MOBDRAW2L1X
;     JMP MOBDRAW2L1A

; MOBDRAW2L1X:

; MOBDRAW2L6:

; MOBDRAW2E:

;     RET

; MOBATCS:

;     LDX MOBI

;     ; Now we must adjust the image inside the larger
;     ; clip, by right and bottom shifting it, accordingly
;     ; to the (relative) position (x,y)
;     ;
;     ; DX for *next* position (DXn)
;     LDA MOBDESCRIPTORS_XL, X
;     STA MOBX
;     AND #$07
;     STA MOBDRAW_DX

;     ; DX for *previous* position (DXp)
;     LDA MOBDESCRIPTORS_PXL, X
;     AND #$07

;     ; DX = (DXp-DXn)
;     ; So: if DX > 0 ---> DXp > DXn ---> shift left
;     ;     if DX < 0 ---> DXp < DXn ---> shift right
;     SEC
;     SBC MOBDRAW_DX
;     STA MOBDRAW_DX

;     ; DY for *next* position (DYn)
;     LDA MOBDESCRIPTORS_YL, X
;     STA MOBY
;     AND #$07
;     STA MOBDRAW_DY

;     ; DY for *previous* position (DYp)
;     LDA MOBDESCRIPTORS_PYL, X
;     AND #$07

;     ; DY = (DYp-DYn)
;     ; So: if DY > 0 ---> DYp > DYn ---> shift up
;     ;     if DY < 0 ---> DYp < DYn ---> shift down
;     SEC
;     SBC MOBDRAW_DY
;     STA MOBDRAW_DY

;     LDA MOBDRAW_DX
;     BEQ MOBATCS_VERT
;     AND $80
;     BEQ MOBATCS_LEFT

; MOBATCS_RIGHT:

;     LDA MOBDRAW_DX
;     CLC
;     EOR #$FF
;     ADC #1
;     STA MOBDRAW_DX
;     JSR MOBDRAW2_SHIFTRIGHT
;     JMP MOBATCS_VERT

; MOBATCS_LEFT:

;     JSR MOBDRAW2_SHIFTLEFT
;     JMP MOBATCS_VERT

; MOBATCS_VERT:

;     LDA MOBDRAW_DY
;     BEQ MOBATCS_DONE
;     AND #$80
;     BEQ MOBATCS_UP

; MOBATCS_DOWN:

;     LDA MOBDRAW_DY
;     CLC
;     EOR #$FF
;     ADC #1
;     STA MOBDRAW_DY
;     ; JSR MOBDRAW2_SHIFTDOWN
;     JMP MOBATCS_DONE

; MOBATCS_UP:

;     ; JSR MOBDRAW2_SHIFTUP

; MOBATCS_DONE:

;     RET

; ; Mask for bit selection / unselection on a single cell
; ; during drawing operations.
; MOBDRAW2_MASKX:
;     DB %11111111
;     DB %01111111
;     DB %00111111
;     DB %00011111
;     DB %00001111
;     DB %00000111
;     DB %00000011
;     DB %00000001

