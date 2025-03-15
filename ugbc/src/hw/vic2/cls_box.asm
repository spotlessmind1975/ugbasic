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
;*                          CLS BOXED ROUTINE FOR VIC-II                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLSBOX:

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BNE CLSBOX2X
    JMP CLSBOX2
CLSBOX2X:
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BNE CLSBOX3X
    JMP CLSBOX3
CLSBOX3X:
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BNE CLSBOX0X
    JMP CLSBOX0
CLSBOX0X:
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BNE CLSBOX1X
    JMP CLSBOX1
CLSBOX1X:
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BNE CLSBOX4X
    JMP CLSBOX4
CLSBOX4X:
    RTS

@ENDIF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 0 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX0:
        RTS


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 1 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX1:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 4 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 4 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX4:
    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 2 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2:

        LDA IMAGEW
        LSR
        LSR
        LSR
        ASL
        ASL
        ASL
        STA IMAGEW

        ; Height (in "tiles" of 8 pixels)

        LDA IMAGEH
        LSR
        LSR
        LSR
        STA IMAGEH
        STA IMAGEH2

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
        LDA #0
    CLSBOX2L1:
        STA (PLOTDEST),Y

        ; Increment the offset. Note that Y starts from 0 (zero)
        ; upto the IMAGEW.

        INY
        CPY IMAGEW
        BEQ CLSBOX2L1X
        JMP CLSBOX2L1

        ; Now we must understand if we are in the > 256 case.
        ; The case is that the high byte is non zero.
    CLSBOX2L1X:

        LDA IMAGEW+1
        BNE CLSBOX2L1XX2
        JMP CLSBOX2L1XX

    CLSBOX2L1XX2:

        ; We must draw an image greater than 256 pixels.
        ; So move forward on the video bitmap.

        CLC
        LDA PLOTDEST
        ADC IMAGEW
        STA PLOTDEST
        LDA PLOTDEST+1
        ADC #0
        STA PLOTDEST+1

        LDY #0
    CLSBOX2L1B:

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
        ; Now store the bitmap data on the video bitmap.
    CLSBOX2L1BDEF:
        LDA #0
        STA (PLOTDEST),Y

        ; Loop until all bytes are written.

        INY
        BEQ CLSBOX2L1BX
        JMP CLSBOX2L1B

    CLSBOX2L1BX:

        ; Move back the pointer to the start
        ; of the drawed line.

        SEC
        LDA PLOTDEST
        SBC IMAGEW
        STA PLOTDEST
        LDA PLOTDEST+1
        SBC #0
        STA PLOTDEST+1

    CLSBOX2L1XX:

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
        BEQ CLSBOX2C

        ; Move to the next
        
        ; Reload the width and repeat the drawing.

        LDY #0
        LDA #0
        JMP CLSBOX2L1

    ; Starting from this line, we are drawing the second
    ; color map, the map for 11 bitmap.

    CLSBOX2C:

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
        BEQ CLSBOX2L2CC
        ORA #$20
        STA IMAGEW
    CLSBOX2L2CC:
        TAY
        DEY
        LDA #0
    CLSBOX2L2:
        STA (PLOTCDEST),Y
        DEY
        CPY #255
        BNE CLSBOX2L2

    CLSBOX2L2N:

        DEC IMAGEH
        BEQ CLSBOX2E

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
        LDA #0
        JMP CLSBOX2L2

    CLSBOX2E:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 3 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX3:

        ; Extract width and height of the image. Currently we are
        ; extracting a 2 byte width but the horiz. resolution max
        ; is just 160 so it could be useless.

        LDA IMAGEW
        LSR
        LSR
        LSR
        ASL
        ASL
        ASL
        STA IMAGEW
        
        ; Height (in "tiles" of 8 pixels)

        LDA IMAGEH
        LSR
        LSR
        LSR
        STA IMAGEH
        STA IMAGEH2

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
        BCC CLSBOX3L1U
        LDX #1
    CLSBOX3L1U:

        ; Now if X = 1 we are going to draw an image of 256 + Y bytes.
        ; Otherwise, we are going to draw an image of Y bytes.
        ; Since we are using indirect indexed access to the memory,
        ; Y will contain the LAST data to copy. So we must decrement
        ; it by 1, in order to start from the end of the line.

        TAY
        DEY
        LDA #0
    CLSBOX3L1:
        ; Now store the bitmap data on the video bitmap.
        STA (PLOTDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        DEY
        CPY #255
        BNE CLSBOX3L1

        ; Now we must understand if we are in the 256+Y case or
        ; in the Y case. The former is denoted by having X = 1.
        CPX #1
        BEQ CLSBOX3L1FX
        JMP CLSBOX3L1F

        ; We are in the 256 + Y case. So we have to move ahead of Y
        ; bytes and to repeat an entire 256 bytes row copy.

    CLSBOX3L1FX:

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

        ; Now we repeat a 256-full width byte copying, from the graphical
        ; data source address to the video bitmap address.

        LDA #$FF
        TAY
        LDA #0
    CLSBOX3L1X:
        ; Now store the bitmap data on the video bitmap.
        STA (PLOTDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        DEY
        CPY #255
        BNE CLSBOX3L1X

        ; Now we must go ahead, in order to access to the
        ; data of the next line. Again, since each pixel
        ; occupy 2 bits, we have to double the IMAGEW
        ; value. So we add this size twice.
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
        BEQ CLSBOX3C

        ; Otherwise, reload the width, and repeat another time.

        LDA IMAGEW
        ASL
        LDA #0
        JMP CLSBOX3L1U

    CLSBOX3L1F:
    CLSBOX3C:

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
    CLSBOX3L2:

        ; Let's update the color map.

        LDA #0
    CLSBOX3L2DEF:
        STA (PLOTCDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        DEY
        CPY #255
        BNE CLSBOX3L2

    CLSBOX3L2N:

        ; Move ahead in the colour video map.
        
        CLC
        LDA PLOTCDEST
        ADC CURRENTTILESWIDTH
        STA PLOTCDEST
        LDA PLOTCDEST+1
        ADC #0
        STA PLOTCDEST+1

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
        BEQ CLSBOX3C2

        ; Move to the next
        
        ; Reload the width and repeat the drawing.

        LDA IMAGEW
        TAY
        DEY
        LDA #0
        JMP CLSBOX3L2

        ; If we reached this line, it means that the PUT IMAGE
        ; was unable to draw the entire image on the screen,
        ; since the ordinate value was too far low.
    CLSBOX3C2A:

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
        BNE CLSBOX3C2A

    ; Starting from this line, we are drawing the second
    ; color map, the map for 11 bitmap.

    CLSBOX3C2:

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

    CLSBOX3C2L2:

        ; Note that, in case that bit 5 of IMAGEF is set, the
        ; PUT IMAGE has been requested with the transparency
        ; effect. In this particular case, we do not touch
        ; the color component.

        LDA IMAGEF
        AND #32
        CMP #32
        BNE CLSBOX3C2L2DEF
        JMP CLSBOX3C2L2FINAL

        ; Update the color map.
    CLSBOX3C2L2DEF:
        LDA (TMPPTR),Y
        STA (PLOTC2DEST),Y

    CLSBOX3C2L2FINAL:

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        DEY
        CPY #255
        BNE CLSBOX3C2L2

        ; Move ahead to the next line (on video memory).
        
        CLC
        LDA PLOTC2DEST
        ADC CURRENTTILESWIDTH
        STA PLOTC2DEST
        LDA PLOTC2DEST+1
        ADC #0
        STA PLOTC2DEST+1

        CLC
        LDA PLOTC2DEST
        ADC CURRENTTILESWIDTH
        STA PLOTC2DEST
        LDA PLOTC2DEST+1
        ADC #0
        STA PLOTC2DEST+1
        
        ; Are there still lines to draw?
        DEC IMAGEH
        BEQ CLSBOX3E

        ; Restart the drawing...

        LDA IMAGEW
        TAY
        DEY
        LDA #0
        JMP CLSBOX3C2L2

    CLSBOX3E:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF
