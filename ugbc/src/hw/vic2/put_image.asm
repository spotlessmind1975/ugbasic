; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                          IMAGES ROUTINE FOR VIC-II                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

PUTIMAGE:

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BNE PUTIMAGE2X
    JMP PUTIMAGE2
PUTIMAGE2X:
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BNE PUTIMAGE3X
    JMP PUTIMAGE3
PUTIMAGE3X:
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BNE PUTIMAGE0X
    JMP PUTIMAGE0
PUTIMAGE0X:
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BNE PUTIMAGE1X
    JMP PUTIMAGE1
PUTIMAGE1X:
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BNE PUTIMAGE4X
    JMP PUTIMAGE4
PUTIMAGE4X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) )

PUTIMAGE0:

    LDY #2
    LDA (TMPPTR),Y
    STA MATHPTR2
PUTIMAGE02C:
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
    ADC #2
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ;-------------------------
    ;calc Y-cell, divide by 8
    ;y/8 is y-cell table index
    ;-------------------------
    LDA IMAGEY
    STA MATHPTR4
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

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE0L1N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE0L1N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTTILESWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE0L1

PUTIMAGE0L1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE0L1N:


    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTDEST
    ADC #40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$0
    STA PLOTDEST+1

    DEC IMAGEH
    LDA IMAGEH
    CMP #$FF
    BEQ PUTIMAGE0C

    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGE3CAX
    BCS PUTIMAGE3CAX
    JMP PUTIMAGE3CAY

PUTIMAGE3CAX:
    JMP PUTIMAGE0CA

PUTIMAGE3CAY:

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE0L1

PUTIMAGE0CA:

    LDA MATHPTR4
    STA IMAGEY

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    DEC IMAGEH
    LDA IMAGEH
    CMP #$FF
    BNE PUTIMAGE0CA

PUTIMAGE0C:
    LDA MATHPTR2
    BEQ PUTIMAGE0C2
    JMP PUTIMAGE0C16

PUTIMAGE0C2:
    LDY #0
    LDA (TMPPTR),Y
    STA MATHPTR1

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

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE02L2N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE02L2N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTTILESWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE02L2

PUTIMAGE02L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE02L2N:

    DEC IMAGEH
    BNE PUTIMAGE0EX
    JMP PUTIMAGE0E

PUTIMAGE0EX:

    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BNE PUTRIMAGE0EX2
    BCC PUTRIMAGE0EX2
    JMP PUTIMAGE0EA

PUTRIMAGE0EX2:
    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTCDEST
    ADC #40
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

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE016L2N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE016L2N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTTILESWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE016L2

PUTIMAGE016L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE016L2N:

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
    ADC #40
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE016L2

PUTIMAGE0E:
PUTIMAGE0EA:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

PUTIMAGE1:
PUTIMAGE4:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) )

PUTIMAGE2:

    ; Extract width and height of the image. 
    ; Width (in pixel)

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1

    ; Height (in "tiles" of 8 pixels)

    LDY #2
    LDA (TMPPTR),Y
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    ; Move ahead of 3 bytes, where the bitmap data begins.

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
    STA MATHPTR4
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
    TAX                        ;tbl_8,x index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    TXA
    ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
    STA PLOTCDEST               ;= cell address

    LDA #0
    ADC PLOTCVBASEHI,Y          ;do the high byte
    STA PLOTCDEST+1
   
    ; Arrived here, we have the following address updated:
    ;
    ;  - PLOTDEST start address of video bitmap
    ;  - PLOTCDEST start address of color map for color 1
    ;

    ; The first loop go from zero to IMAGEW
    ; Note that IMAGEW could be > 256: this
    ; case will be threated after this one.

    LDY #0
PUTIMAGE2L1:
    LDA (TMPPTR),Y

    ; At the beginning of each byte copy, we are going to
    ; check if a transparency effect has been requested.
    ; If bit 5 of IMAGEF is set, a transparency is requested.

    LDA IMAGEF
    AND #32
    CMP #32
    BEQ PUTIMAGE2L1DEFX
    JMP PUTIMAGE2L1DEF

    ; PUT IMAGE with transparency
    ; Load the byte about the bitmap data and draw on the
    ; screen at the given position. Before storing it, you
    ; have to check if a transparency mask has to be applied.
    ; 00 = transparency, any other combination = opaque
PUTIMAGE2L1DEFX:
    LDA #0
    STA MATHPTR5
    LDA (TMPPTR),Y
    AND #$80
    ; -> 00 00 00 00
    BEQ PUTIMAGE2L1P1
    LDA MATHPTR5
    ORA #$80
    STA MATHPTR5
PUTIMAGE2L1P1:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$40
    ; -> 00 01 00 00
    BEQ PUTIMAGE2L1P2
    LDA MATHPTR5
    ORA #$40
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE2L1P2:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$20
    ; -> 00 00 10 00
    BEQ PUTIMAGE2L1P3
    LDA MATHPTR5
    ORA #$20
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE2L1P3:
    LDA (TMPPTR),Y
    AND #$10
    BEQ PUTIMAGE2L1P4
    LDA MATHPTR5
    ORA #$10
    STA MATHPTR5
PUTIMAGE2L1P4:
    LDA (TMPPTR),Y
    AND #$08
    ; -> 00 00 00 00
    BEQ PUTIMAGE2L1P5
    LDA MATHPTR5
    ORA #$08
    STA MATHPTR5
PUTIMAGE2L1P5:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$04
    ; -> 00 01 00 00
    BEQ PUTIMAGE2L1P6
    LDA MATHPTR5
    ORA #$04
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE2L1P6:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$02
    ; -> 00 00 10 00
    BEQ PUTIMAGE2L1P7
    LDA MATHPTR5
    ORA #$02
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE2L1P7:
    LDA (TMPPTR),Y
    AND #$01
    BEQ PUTIMAGE2L1P8
    LDA MATHPTR5
    ORA #$01
    STA MATHPTR5
PUTIMAGE2L1P8:
    LDA MATHPTR5
    ; 00 11 11 00
    EOR #$FF
    ; 11 00 00 11
    STA MATHPTR6
    LDA (PLOTDEST),Y
    ; 00 00 00 00
    AND MATHPTR6
    STA MATHPTR6
    ; 00 00 00 00
    LDA (TMPPTR),Y
    AND MATHPTR5
    ORA MATHPTR6
    JMP PUTIMAGE2L1FINAL

    ; PUT IMAGE without transparency.
    ; Simply load the bitmap data "as is".
PUTIMAGE2L1DEF:
    LDA (TMPPTR),Y

PUTIMAGE2L1FINAL:

    ; Now store the bitmap data on the video bitmap.

    STA (PLOTDEST),Y

    ; Increment the offset. Note that Y starts from 0 (zero)
    ; upto the IMAGEW.

    INY
    CPY IMAGEW
    BEQ PUTIMAGE2L1X
    JMP PUTIMAGE2L1

    ; Now we must understand if we are in the > 256 case.
    ; The case is that the high byte is non zero.
PUTIMAGE2L1X:

    LDA IMAGEW+1
    BNE PUTIMAGE2L1XX2
    JMP PUTIMAGE2L1XX

PUTIMAGE2L1XX2:

    ; We must draw an image greater than 256 pixels.
    ; So move forward on the memory and video bitmap.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTDEST
    ADC IMAGEW
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDY #0
PUTIMAGE2L1B:

    ; At the beginning of each byte copy, we are going to
    ; check if a transparency effect has been requested.
    ; If bit 5 of IMAGEF is set, a transparency is requested.

    LDA IMAGEF
    AND #32
    CMP #32
    BEQ PUTIMAGE2L1BDEFX
    JMP PUTIMAGE2L1BDEF

    ; PUT IMAGE with transparency
    ; Load the byte about the bitmap data and draw on the
    ; screen at the given position. Before storing it, you
    ; have to check if a transparency mask has to be applied.
    ; 0 = transparency, 1 = opaque
PUTIMAGE2L1BDEFX:
    LDA #0
    STA MATHPTR5
    LDA (TMPPTR),Y
    AND #$80
    ; -> 00 00 00 00
    BEQ PUTIMAGE2L1BP1
    LDA MATHPTR5
    ORA #$80
    STA MATHPTR5
PUTIMAGE2L1BP1:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$40
    ; -> 00 01 00 00
    BEQ PUTIMAGE2L1BP2
    LDA MATHPTR5
    ORA #$40
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE2L1BP2:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$20
    ; -> 00 00 10 00
    BEQ PUTIMAGE2L1BP3
    LDA MATHPTR5
    ORA #$20
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE2L1BP3:
    LDA (TMPPTR),Y
    AND #$10
    BEQ PUTIMAGE2L1BP4
    LDA MATHPTR5
    ORA #$10
    STA MATHPTR5
PUTIMAGE2L1BP4:
    LDA (TMPPTR),Y
    AND #$08
    ; -> 00 00 00 00
    BEQ PUTIMAGE2L1BP5
    LDA MATHPTR5
    ORA #$08
    STA MATHPTR5
PUTIMAGE2L1BP5:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$04
    ; -> 00 01 00 00
    BEQ PUTIMAGE2L1BP6
    LDA MATHPTR5
    ORA #$04
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE2L1BP6:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$02
    ; -> 00 00 10 00
    BEQ PUTIMAGE2L1BP7
    LDA MATHPTR5
    ORA #$02
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE2L1BP7:
    LDA (TMPPTR),Y
    AND #$01
    BEQ PUTIMAGE2L1BP8
    LDA MATHPTR5
    ORA #$01
    STA MATHPTR5
PUTIMAGE2L1BP8:
    LDA MATHPTR5
    ; 00 11 11 00
    EOR #$FF
    ; 11 00 00 11
    STA MATHPTR6
    LDA (PLOTDEST),Y
    ; 00 00 00 00
    AND MATHPTR6
    STA MATHPTR6
    ; 00 00 00 00
    LDA (TMPPTR),Y
    AND MATHPTR5
    ORA MATHPTR6
    JMP PUTIMAGE2L1BFINAL

    ; PUT IMAGE without transparency.
    ; Simply load the bitmap data "as is".
PUTIMAGE2L1BDEF:
    LDA (TMPPTR),Y

PUTIMAGE2L1BFINAL:

    ; Now store the bitmap data on the video bitmap.

    STA (PLOTDEST),Y

    ; Loop until all bytes are written.

    INY
    BEQ PUTIMAGE2L1BX
    JMP PUTIMAGE2L1B

PUTIMAGE2L1BX:

    ; Move back the pointer to the start
    ; of the drawed line.

    SEC
    LDA TMPPTR
    SBC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    SBC #0
    STA TMPPTR+1

    SEC
    LDA PLOTDEST
    SBC IMAGEW
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1

PUTIMAGE2L1XX:

    ; If the bit 6 of IMAGEF flag is set, a DOUBLE
    ; effect has been required. So we have to copy
    ; another time the very same line.
    ; If not, we can go ahead.

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE2L1N

    ; If bit 1 of IMAGEF flag is set, the DOUBLE
    ; effect has been already applied. So we can
    ; go ahead.

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE2L1N0

    ; Enable both bits 6 and 1, so DOUBLE effect is
    ; taking place.

    ORA #65
    STA IMAGEF

    ; Move ahead to the next line.

    CLC
    LDA PLOTDEST
    ADC CURRENTTILESWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    ; Reload and restart!

    LDY #0
    JMP PUTIMAGE2L1

    ; If we reach this line, it means that
    ; DOUBLE effect has been executed. So,
    ; we can disable any related flag.

PUTIMAGE2L1N0:

    LDA IMAGEF
    AND #$FE
    STA IMAGEF

    ; If we reach this line, no DOUBLE
    ; effect has been required.

PUTIMAGE2L1N:

    ; Move ahead in the data.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC IMAGEW+1
    STA TMPPTR+1

    ; Move ahead in the video map.

    CLC
    LDA PLOTDEST
    ADC CURRENTWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC CURRENTWIDTH+1
    STA PLOTDEST+1

    ; There are lines to draw? If not, we move to the next
    ; color map to draw.
    
    DEC IMAGEH
    BEQ PUTIMAGE2C

    ; Move to the next
    
    ; There is at least one line to draw. So, we must
    ; move down of 8 lines (since we can draw 8 lines
    ; at a time...) and we must check if we are inside
    ; the limits of the video.

    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGE2CA
    BCS PUTIMAGE2CA

    ; Reload the width and repeat the drawing.

    LDY #0
    JMP PUTIMAGE2L1

    ; If we reached this line, it means that the PUT IMAGE
    ; was unable to draw the entire image on the screen,
    ; since the ordinate value was too far low.

PUTIMAGE2CA:

    ; Now we must go ahead, in order to access to the
    ; colormap data.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC IMAGEW+1
    STA TMPPTR+1

    ; Are still lines to draw?

    DEC IMAGEH
    BNE PUTIMAGE2CA

   ; Starting from this line, we are drawing the second
   ; color map, the map for 11 bitmap.

PUTIMAGE2C:

    ; Restore the IMAGEY
    LDA MATHPTR4
    STA IMAGEY

    ; First of all, we reset the IMAGEH (in bytes), that could be
    ; destroyed by a previous elaboration.
    
    LDA IMAGEH2
    STA IMAGEH

    ; Then reset the width, and restart.
    LDA IMAGEW+1
    TAX
    LDA IMAGEW
    LSR A
    LSR A
    LSR A
    STA IMAGEW
    CPX #0
    BEQ PUTIMAGE2L2CC
    ORA #$20
    STA IMAGEW
PUTIMAGE2L2CC:
    TAY
    DEY
PUTIMAGE2L2:
    LDA (TMPPTR),Y
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE2L2

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE2L2N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE2L2N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTCDEST
    ADC CURRENTTILESWIDTH
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE2L2

PUTIMAGE2L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE2L2N:

    DEC IMAGEH
    BEQ PUTIMAGE2E

    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGE2EA
    BCS PUTIMAGE2EA

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTCDEST
    ADC CURRENTTILESWIDTH
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE2L2

PUTIMAGE2EA:
PUTIMAGE2E:
    RTS

@ENDIF

;;;;;;;;;;;;;;;;;

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

PUTIMAGE3:

    ; Extract width and height of the image. Currently we are
    ; extracting a 2 byte width but the horiz. resolution max
    ; is just 160 so it could be useless.

    ; Width (in pixel)

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1

    ; Height (in "tiles" of 8 pixels)

    LDY #2
    LDA (TMPPTR),Y
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    ; Move ahead of 3 bytes, where the bitmap data begins.

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
    STA MATHPTR4
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
    TAX                        ;tbl_8,x index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    CLC

    TXA
    ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
    STA PLOTCDEST               ;= cell address

    LDA #0
    ADC PLOTCVBASEHI,Y          ;do the high byte
    STA PLOTCDEST+1

    CLC

    TXA
    ADC PLOTC2VBASELO,Y          ;table of $8400 row base addresses
    STA PLOTC2DEST               ;= cell address

    LDA #0
    ADC PLOTC2VBASEHI,Y          ;do the high byte
    STA PLOTC2DEST+1

    ; Arrived here, we have the following address updated:
    ;
    ;  - PLOTDEST start address of video bitmap
    ;  - PLOTCDEST start address of color map for color 01 and 10
    ;  - PLOTC2DEST start address of color map for color 11
    ;

    ; Since each pixel occupy 2 bits, we have to double the
    ; width to put. This means that, if the width of the
    ; image is equal to 128 pixel or more, we are going to
    ; overflow the IMAGEW byte. To avoid this, we are going
    ; to "take apart" the highest bit of the width, in order
    ; to move an additional 255 bytes, if needed:
    ;
    ;     7654 3210
    ;     1000 0010 = 128 + 2 = 130 pixel
    ;               x 2 = 260
    ;   1 0000 0100 = 4 + carry = 256 + 4 = 260

    LDX #0
    LDA IMAGEW
    ASL
    BCC PUTIMAGE3L1U
    LDX #1
PUTIMAGE3L1U:

    ; Now if X = 1 we are going to draw an image of 256 + Y bytes.
    ; Otherwise, we are going to draw an image of Y bytes.
    ; Since we are using indirect indexed access to the memory,
    ; Y will contain the LAST data to copy. So we must decrement
    ; it by 1, in order to start from the end of the line.

    TAY
    DEY
PUTIMAGE3L1:

    ; At the beginning of each byte copy, we are going to
    ; check if a transparency effect has been requested.
    ; If bit 5 of IMAGEF is set, a transparency is requested.

    LDA IMAGEF
    AND #32
    CMP #32
    BEQ PUTIMAGE3L1DEFX
    JMP PUTIMAGE3L1DEF

    ; PUT IMAGE with transparency
    ; Load the byte about the bitmap data and draw on the
    ; screen at the given position. Before storing it, you
    ; have to check if a transparency mask has to be applied.
    ; 00 = transparency, any other combination = opaque
PUTIMAGE3L1DEFX:
    LDA #0
    STA MATHPTR5
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$C0
    ; -> 00 00 00 00
    BEQ PUTIMAGE3L1P4
    LDA MATHPTR5
    ORA #$C0
    STA MATHPTR5
PUTIMAGE3L1P4:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$30
    ; -> 00 01 00 00
    BEQ PUTIMAGE3L1P3
    LDA MATHPTR5
    ORA #$30
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE3L1P3:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$0C
    ; -> 00 00 10 00
    BEQ PUTIMAGE3L1P2
    LDA MATHPTR5
    ORA #$0C
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE3L1P2:
    LDA (TMPPTR),Y
    AND #$03
    BEQ PUTIMAGE3L1P1
    LDA MATHPTR5
    ORA #$03
    STA MATHPTR5
PUTIMAGE3L1P1:
    LDA MATHPTR5
    ; 00 11 11 00
    EOR #$FF
    ; 11 00 00 11
    STA MATHPTR6
    LDA (PLOTDEST),Y
    ; 00 00 00 00
    AND MATHPTR6
    STA MATHPTR6
    ; 00 00 00 00
    LDA (TMPPTR),Y
    AND MATHPTR5
    ORA MATHPTR6
    JMP PUTIMAGE3L1FINAL

    ; PUT IMAGE without transparency.
    ; Simply load the bitmap data "as is".
PUTIMAGE3L1DEF:
    LDA (TMPPTR),Y

PUTIMAGE3L1FINAL:

    ; Now store the bitmap data on the video bitmap.

    STA (PLOTDEST),Y

    ; Decrement the offset. Note that Y starts from the
    ; end of the row, so 0 (zero) is a valid offset.

    DEY
    CPY #255
    BNE PUTIMAGE3L1

    ; Now we must understand if we are in the 256+Y case or
    ; in the Y case. The former is denoted by having X = 1.
    CPX #1
    BEQ PUTIMAGE3L1FX
    JMP PUTIMAGE3L1F

    ; We are in the 256 + Y case. So we have to move ahead of Y
    ; bytes and to repeat an entire 256 bytes row copy.

PUTIMAGE3L1FX:

    ; Take the width of the image, double it (carry will be lost)
    ; and add to the video bitmap address.
    ;
    ;     7654 3210
    ;     1000 0010 = 128 + 2 = 130 pixel
    ;               x 2 = 260
    ;   1 0000 0100 = 4 + carry = 4
    
    LDA IMAGEW
    ASL
    CLC
    ADC PLOTDEST
    STA PLOTDEST
    LDA #0
    ADC PLOTDEST+1
    STA PLOTDEST+1

    ; Take the width of the image, double it (carry will be lost)
    ; and add to the graphical data source address.

    LDA IMAGEW
    ASL
    CLC
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    ; Now we repeat a 256-full width byte copying, from the graphical
    ; data source address to the video bitmap address.

    LDA #$FF
    TAY
PUTIMAGE3L1X:

    ; At the beginning of each (256 bytes full) byte copy, we are going to
    ; check if a transparency effect has been requested.
    ; If bit 5 of IMAGEF is set, a transparency is requested.

    LDA IMAGEF
    AND #32
    CMP #32
    BEQ PUTIMAGE3L1XDEFX
    JMP PUTIMAGE3L1XDEF

    ; PUT IMAGE (full 256 bytes copy) with transparency
    ; Load the byte about the bitmap data and draw on the
    ; screen at the given position. Before storing it, you
    ; have to check if a transparency mask has to be applied.
    ; 00 = transparency, any other combination = opaque
PUTIMAGE3L1XDEFX:
    LDA #0
    STA MATHPTR5
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$C0
    ; -> 00 00 00 00
    BEQ PUTIMAGE3L1P4X
    LDA MATHPTR5
    ORA #$C0
    STA MATHPTR5
PUTIMAGE3L1P4X:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$30
    ; -> 00 01 00 00
    BEQ PUTIMAGE3L1P3X
    LDA MATHPTR5
    ORA #$30
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE3L1P3X:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$0C
    ; -> 00 00 10 00
    BEQ PUTIMAGE3L1P2X
    LDA MATHPTR5
    ORA #$0C
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE3L1P2X:
    LDA (TMPPTR),Y
    AND #$03
    BEQ PUTIMAGE3L1P1X
    LDA MATHPTR5
    ORA #$03
    STA MATHPTR5
PUTIMAGE3L1P1X:
    LDA MATHPTR5
    ; 00 11 11 00
    EOR #$FF
    ; 11 00 00 11
    STA MATHPTR6
    LDA (PLOTDEST),Y
    ; 00 00 00 00
    AND MATHPTR6
    STA MATHPTR6
    ; 00 00 00 00
    LDA (TMPPTR),Y
    AND MATHPTR5
    ORA MATHPTR6
    JMP PUTIMAGE3L1FINALX

    ; PUT IMAGE (full 256-bytes copy) without transparency.
    ; Simply load the bitmap data "as is".

PUTIMAGE3L1XDEF:
    LDA (TMPPTR),Y

PUTIMAGE3L1FINALX:

    ; Now store the bitmap data on the video bitmap.

    STA (PLOTDEST),Y

    ; Decrement the offset. Note that Y starts from the
    ; end of the row, so 0 (zero) is a valid offset.

    DEY
    CPY #255
    BNE PUTIMAGE3L1X

    ; Now that we finished, we have to manage the case that
    ; a PUT ... DOUBLE has been asked. In this case, we have
    ; to "rewind" the address, such that a second copy with
    ; the very same data can take place.

    LDA IMAGEW
    ASL
    STA MATHPTR5

    ; Move back the video bitmap address.
    
    SEC
    LDA PLOTDEST
    SBC MATHPTR5
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1

    ; Move back the source bitmap address.

    SEC
    LDA TMPPTR
    SBC MATHPTR5
    STA TMPPTR
    LDA TMPPTR+1
    SBC #0
    STA TMPPTR+1

    ; IF the bit 6 of IMAGEF flag is set, a DOUBLE
    ; effect has been required. So we have to copy
    ; another time the very same line.
    ; If not, we can go ahead.

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE3L1XN

    ; If bit 1 of IMAGEF flag is set, the DOUBLE
    ; effect has been already applied. So we can
    ; go ahead.

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE3L1XN0

    ; Enable both bits 6 and 1, so DOUBLE effect is
    ; taking place.

    ORA #65
    STA IMAGEF

    ; Move ahead the video bitmap address of an entire
    ; line, in order to copy the same bitmap on the
    ; next video line.

    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    ; Reload the width, and repeat another time.

    LDA IMAGEW
    ASL
    JMP PUTIMAGE3L1U

    ; If we reach this line, it means that
    ; DOUBLE effect has been executed. So,
    ; we can disable any related flag.

PUTIMAGE3L1XN0:

    LDA IMAGEF
    AND #$FE
    STA IMAGEF

    ; If we reach this line, no DOUBLE
    ; effect has been required.

PUTIMAGE3L1XN:
PUTIMAGE3L1F:

    ; Now we must go ahead, in order to access to the
    ; data of the next line. Again, since each pixel
    ; occupy 2 bits, we have to double the IMAGEW
    ; value. So we add this size twice.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Instead, we move the video bitmap address ahead
    ; of precomputed size, since the width (in bytes)
    ; of a line is fixed.

    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$1
    STA PLOTDEST+1

    ; Decrement the number of lines to draw.
    ; If we reach the 0, it means that no more
    ; line has to be drawn. So we can move to
    ; the color part of the data.

    DEC IMAGEH
    BEQ PUTIMAGE3C

    ; There is at least one line to draw. So, we must
    ; move down of 8 lines (since we can draw 8 lines
    ; at a time...) and we must check if we are inside
    ; the limits of the video.

    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT

    ; If we reached (or overcame) the limits, 
    ; we must stop drawing.

    BEQ PUTIMAGE3CA
    BCS PUTIMAGE3CA

    ; Otherwise, reload the width, and repeat another time.

    LDA IMAGEW
    ASL
    JMP PUTIMAGE3L1U

    ; If we reached this line, it means that the PUT IMAGE
    ; was unable to draw the entire image on the screen,
    ; since the ordinate value was too far low.
PUTIMAGE3CA:

    ; Now we must go ahead, in order to access to the
    ; colormap data. Again, since each pixel
    ; occupy 2 bits, we have to double the IMAGEW
    ; value. So we add this size twice.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; We repeat the adding as long as remain lines to draw.

    DEC IMAGEH
    BEQ PUTIMAGE3C

    ; Starting from this line, we are drawing the first
    ; color map, the map for 01 and 10 bitmap.

PUTIMAGE3C:

    ; Restore the IMAGEY
    LDA MATHPTR4
    STA IMAGEY

    ; First of all, we reset the IMAGEH (in bytes), that could be
    ; destroyed by a previous elaboration.

    LDA IMAGEH2    
    STA IMAGEH

    ; Then we take the width (in pixel) and we have to divide
    ; by 8, since the color of each pixel in the bitmap is
    ; driven by the color cell in the color map.

    LDA IMAGEW
    LSR A
    LSR A
    STA IMAGEW

    ; Now we can copy the data from the source graphical
    ; data address to the video bitmap address. Remember
    ; that, since we are using indirect indexed access to the memory,
    ; Y will contain the LAST data to copy. So we must decrement
    ; it by 1, in order to start from the end of the line.

    TAY
    DEY
PUTIMAGE3L2:

    ; Note that, in case that bit 5 of IMAGEF is set, the
    ; PUT IMAGE has been requested with the transparency
    ; effect. In this particular case, we do not touch
    ; the color component.

    LDA IMAGEF
    AND #32
    CMP #32
    BNE PUTIMAGE3L2DEF    
    JMP PUTIMAGE3L2FINAL

    ; Let's update the color map.

PUTIMAGE3L2DEF:
    LDA (TMPPTR),Y
    STA (PLOTCDEST),Y

PUTIMAGE3L2FINAL:

    ; Decrement the offset. Note that Y starts from the
    ; end of the row, so 0 (zero) is a valid offset.

    DEY
    CPY #255
    BNE PUTIMAGE3L2

    ; If the bit 6 of IMAGEF flag is set, a DOUBLE
    ; effect has been required. So we have to copy
    ; another time the very same line.
    ; If not, we can go ahead.

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE3L2N

    ; If bit 1 of IMAGEF flag is set, the DOUBLE
    ; effect has been already applied. So we can
    ; go ahead.

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE3L2N0

    ; Enable both bits 6 and 1, so DOUBLE effect is
    ; taking place.

    ORA #65
    STA IMAGEF

    ; Move ahead to the next (color) line.

    CLC
    LDA PLOTCDEST
    ADC CURRENTTILESWIDTH
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    ; Reload the width and repeat the drawing.

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE3L2

    ; If we reach this line, it means that
    ; DOUBLE effect has been executed. So,
    ; we can disable any related flag.

PUTIMAGE3L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

    ; If we reach this line, no DOUBLE
    ; effect has been required.

PUTIMAGE3L2N:

    ; Move ahead in the colour data.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Move ahead in the colour video map.
    
    CLC
    LDA PLOTCDEST
    ADC CURRENTTILESWIDTH
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    ; There are lines to draw? If not, we move to the next
    ; color map to draw.
    DEC IMAGEH
    BEQ PUTIMAGE3C2

    ; Move to the next
    
    ; There is at least one line to draw. So, we must
    ; move down of 8 lines (since we can draw 8 lines
    ; at a time...) and we must check if we are inside
    ; the limits of the video.

    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGE3C2A
    BCS PUTIMAGE3C2A

    ; Reload the width and repeat the drawing.

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE3L2

    ; If we reached this line, it means that the PUT IMAGE
    ; was unable to draw the entire image on the screen,
    ; since the ordinate value was too far low.
PUTIMAGE3C2A:

    ; Now we must go ahead, in order to access to the
    ; colormap data.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Are still lines to draw?

    DEC IMAGEH
    BNE PUTIMAGE3C2A

   ; Starting from this line, we are drawing the second
   ; color map, the map for 11 bitmap.

PUTIMAGE3C2:

    ; Restore the IMAGEY
    LDA MATHPTR4
    STA IMAGEY

    ; First of all, we reset the IMAGEH (in bytes), that could be
    ; destroyed by a previous elaboration.

    LDA IMAGEH2
    STA IMAGEH

    ; Then reset the width, and restart.
    LDA IMAGEW
    TAY
    DEY

PUTIMAGE3C2L2:

    ; Note that, in case that bit 5 of IMAGEF is set, the
    ; PUT IMAGE has been requested with the transparency
    ; effect. In this particular case, we do not touch
    ; the color component.

    LDA IMAGEF
    AND #32
    CMP #32
    BNE PUTIMAGE3C2L2DEF
    JMP PUTIMAGE3C2L2FINAL

    ; Update the color map.
PUTIMAGE3C2L2DEF:
    LDA (TMPPTR),Y
    STA (PLOTC2DEST),Y

PUTIMAGE3C2L2FINAL:

    ; Decrement the offset. Note that Y starts from the
    ; end of the row, so 0 (zero) is a valid offset.

    DEY
    CPY #255
    BNE PUTIMAGE3C2L2

    ; IF the bit 6 of IMAGEF flag is set, a DOUBLE
    ; effect has been required. So we have to copy
    ; another time the very same line.
    ; If not, we can go ahead.

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE3C2L2N

    ; If bit 1 of IMAGEF flag is set, the DOUBLE
    ; effect has been already applied. So we can
    ; go ahead.

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE3C2L2N0

    ; Enable both bits 6 and 1, so DOUBLE effect is
    ; taking place.

    ORA #65
    STA IMAGEF

    ; Move ahead in video color map...

    CLC
    LDA PLOTDEST
    ADC CURRENTTILESWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    ; ... and recopy another time the same colour.

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE3C2L2

    ; If we reach this line, it means that
    ; DOUBLE effect has been executed. So,
    ; we can disable any related flag.

PUTIMAGE3C2L2N0:

    LDA IMAGEF
    AND #$FE
    STA IMAGEF

    ; If we reach this line, no DOUBLE
    ; effect has been required.

PUTIMAGE3C2L2N:

    ; Move ahead to the next line (in memory).

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Move ahead to the next line (on video memory).
    
    CLC
    LDA PLOTC2DEST
    ADC CURRENTTILESWIDTH
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    ; Are there still lines to draw?
    DEC IMAGEH
    BEQ PUTIMAGE3E

    ; There is at least one line to draw. So, we must
    ; move down of 8 lines (since we can draw 8 lines
    ; at a time...) and we must check if we are inside
    ; the limits of the video.
    
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGE3EA
    BCS PUTIMAGE3EA

    ; Restart the drawing...

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE3C2L2

    ; If we reached this line, it means that the PUT IMAGE
    ; was unable to draw the entire image on the screen,
    ; since the ordinate value was too far low.

PUTIMAGE3EA:

    ; Move ahead in memory still exist lines to be drawn.

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    DEC IMAGEH
    BNE PUTIMAGE3EA

    ; Finally, we reached the end of the image,
    ; with the various palette and colors. Let's
    ; consider or ignore it, based on flags.

PUTIMAGE3E:

    ; SEC
    ; LDA TMPPTR
    ; SBC #1
    ; STA TMPPTR
    ; LDA TMPPTR+1
    ; SBC #0
    ; STA TMPPTR+1

    ; IF bit 5 of IMAGEF is enabled it means that the image must be
    ; drawn as transparency -- and it means that colors cannot be
    ; touched.

    LDA IMAGEF
    AND #32
    CMP #32
    BEQ PUTIMAGE3EFINAL

    ; IF bit 1 of IMAGET is cleared, it means that the image must be
    ; drawn without colors.

    LDA IMAGET
    AND #2
    CMP #2
    BNE PUTIMAGE3EFINAL

    ; Finally, load the last byte of the image: this is the
    ; background color for the entire image. To be set, if
    ; this is the case.

    LDY #0
    LDA (TMPPTR),Y
    LSR
    LSR
    LSR
    LSR
    STA $D021

PUTIMAGE3EFINAL:
    RTS

@ENDIF
