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
;*                          IMAGES ROUTINE FOR VIC-II (RAM only)               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PUTIMAGERAMRLE:

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BNE PUTIMAGERLE2X
    JMP PUTIMAGERLE2
PUTIMAGERLE2X:
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BNE PUTIMAGERLE3X
    JMP PUTIMAGERLE3
PUTIMAGERLE3X:
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BNE PUTIMAGERLE0X
    JMP PUTIMAGERLE0
PUTIMAGERLE0X:
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BNE PUTIMAGERLE1X
    JMP PUTIMAGERLE1
PUTIMAGERLE1X:
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BNE PUTIMAGERLE4X
    JMP PUTIMAGERLE4
PUTIMAGERLE4X:
    RTS

@ENDIF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 0 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGERLE0:

        LDY #2
        LDA (TMPPTR),Y
        STA MATHPTR2
    PUTIMAGERLE02C:
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
    PUTIMAGERLE0L1:
        LDA (TMPPTR),Y
        STA (PLOTDEST),Y
        DEY
        CPY #255
        BNE PUTIMAGERLE0L1

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE0L1N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE0L1N0

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
        JMP PUTIMAGERLE0L1

    PUTIMAGERLE0L1N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGERLE0L1N:


        CLC
        LDA TMPPTR
        ADC IMAGEW
        STA TMPPTR
        LDA TMPPTR+1
        ADC #0
        STA TMPPTR+1

        CLC
        LDA PLOTDEST
        ADC CURRENTTILESWIDTH
        STA PLOTDEST
        LDA PLOTDEST+1
        ADC #$0
        STA PLOTDEST+1

        DEC IMAGEH
        BEQ PUTIMAGERLE0C

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
        BEQ PUTIMAGERLE0CAX
        BCS PUTIMAGERLE0CAX
        JMP PUTIMAGERLE0CAY

    PUTIMAGERLE0CAX:
        JMP PUTIMAGERLE0CA

    PUTIMAGERLE0CAY:

        LDA IMAGEW
        TAY
        DEY
        JMP PUTIMAGERLE0L1

    PUTIMAGERLE0CA:

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
        BNE PUTIMAGERLE0CA

    PUTIMAGERLE0C:
        LDA MATHPTR2
        BEQ PUTIMAGERLE0C2
        JMP PUTIMAGERLE0C16

    PUTIMAGERLE0C2:
        LDY #0
        LDA (TMPPTR),Y
        STA MATHPTR1

        LDA IMAGEH2
        STA IMAGEH
        LDA IMAGEW
        TAY
        DEY
        LDA MATHPTR1
    PUTIMAGERLE02L2:
        STA (PLOTCDEST),Y
        DEY
        CPY #255
        BNE PUTIMAGERLE02L2

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE02L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE02L2N0

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
        JMP PUTIMAGERLE02L2

    PUTIMAGERLE02L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGERLE02L2N:

        DEC IMAGEH
        BNE PUTIMAGERLE0EX
        JMP PUTIMAGERLE0E

    PUTIMAGERLE0EX:

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
        BNE PUTIMAGERLE0EX2
        BCC PUTIMAGERLE0EX2
        JMP PUTIMAGERLE0EA

    PUTIMAGERLE0EX2:
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
        JMP PUTIMAGERLE02L2

    PUTIMAGERLE0C16:
        LDA IMAGEH2
        STA IMAGEH
        LDA IMAGEW
        TAY
        DEY
        LDA MATHPTR1
    PUTIMAGERLE016L2:
        LDA (TMPPTR),Y
        STA (PLOTCDEST),Y
        DEY
        CPY #255
        BNE PUTIMAGERLE016L2

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE016L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE016L2N0

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
        JMP PUTIMAGERLE016L2

    PUTIMAGERLE016L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGERLE016L2N:

        DEC IMAGEH
        BEQ PUTIMAGERLE0E

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
        JMP PUTIMAGERLE016L2

    PUTIMAGERLE0E:
    PUTIMAGERLE0EA:
        RTS


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 1 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGERLE1:

        LDY #2
        LDA (TMPPTR),Y
        STA MATHPTR2
    PUTIMAGERLE12C:
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
    PUTIMAGERLE1L1:
        LDA (TMPPTR),Y
        STA (PLOTDEST),Y
        DEY
        CPY #255
        BNE PUTIMAGERLE1L1

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE1L1N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE1L1N0

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
        JMP PUTIMAGERLE1L1

    PUTIMAGERLE1L1N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGERLE1L1N:


        CLC
        LDA TMPPTR
        ADC IMAGEW
        STA TMPPTR
        LDA TMPPTR+1
        ADC #0
        STA TMPPTR+1

        CLC
        LDA PLOTDEST
        ADC CURRENTTILESWIDTH
        STA PLOTDEST
        LDA PLOTDEST+1
        ADC #$0
        STA PLOTDEST+1

        DEC IMAGEH
        BEQ PUTIMAGERLE1C

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
        BEQ PUTIMAGERLE1CAX
        BCS PUTIMAGERLE1CAX
        JMP PUTIMAGERLE1CAY

    PUTIMAGERLE1CAX:
        JMP PUTIMAGERLE1CA

    PUTIMAGERLE1CAY:

        LDA IMAGEW
        TAY
        DEY
        JMP PUTIMAGERLE1L1

    PUTIMAGERLE1CA:

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
        BNE PUTIMAGERLE1CA

    PUTIMAGERLE1C:
    PUTIMAGERLE1C16:
        LDA IMAGEH2
        STA IMAGEH
        LDA IMAGEW
        TAY
        DEY
        LDA MATHPTR1
    PUTIMAGERLE116L2:
        LDA (TMPPTR),Y
        STA (PLOTCDEST),Y
        DEY
        CPY #255
        BNE PUTIMAGERLE116L2

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE116L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE116L2N0

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
        JMP PUTIMAGERLE116L2

    PUTIMAGERLE116L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGERLE116L2N:

        DEC IMAGEH
        BEQ PUTIMAGERLE1E

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
        JMP PUTIMAGERLE116L2

    PUTIMAGERLE1E:
    PUTIMAGERLE1EA:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 4 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 4 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGERLE4:
    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 2 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGERLE2:

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
    PUTIMAGERLE2L1:
        LDA (TMPPTR),Y

        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGERLE2L1DEFX
        JMP PUTIMAGERLE2L1DEF

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 00 = transparency, any other combination = opaque
    PUTIMAGERLE2L1DEFX:
        LDA #0
        STA MATHPTR5
        LDA (TMPPTR),Y
        AND #$80
        ; -> 00 00 00 00
        BEQ PUTIMAGERLE2L1P1
        LDA MATHPTR5
        ORA #$80
        STA MATHPTR5
    PUTIMAGERLE2L1P1:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$40
        ; -> 00 01 00 00
        BEQ PUTIMAGERLE2L1P2
        LDA MATHPTR5
        ORA #$40
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGERLE2L1P2:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$20
        ; -> 00 00 10 00
        BEQ PUTIMAGERLE2L1P3
        LDA MATHPTR5
        ORA #$20
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGERLE2L1P3:
        LDA (TMPPTR),Y
        AND #$10
        BEQ PUTIMAGERLE2L1P4
        LDA MATHPTR5
        ORA #$10
        STA MATHPTR5
    PUTIMAGERLE2L1P4:
        LDA (TMPPTR),Y
        AND #$08
        ; -> 00 00 00 00
        BEQ PUTIMAGERLE2L1P5
        LDA MATHPTR5
        ORA #$08
        STA MATHPTR5
    PUTIMAGERLE2L1P5:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$04
        ; -> 00 01 00 00
        BEQ PUTIMAGERLE2L1P6
        LDA MATHPTR5
        ORA #$04
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGERLE2L1P6:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$02
        ; -> 00 00 10 00
        BEQ PUTIMAGERLE2L1P7
        LDA MATHPTR5
        ORA #$02
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGERLE2L1P7:
        LDA (TMPPTR),Y
        AND #$01
        BEQ PUTIMAGERLE2L1P8
        LDA MATHPTR5
        ORA #$01
        STA MATHPTR5
    PUTIMAGERLE2L1P8:
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
        JMP PUTIMAGERLE2L1FINAL

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGERLE2L1DEF:
        LDA (TMPPTR),Y

    PUTIMAGERLE2L1FINAL:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Increment the offset. Note that Y starts from 0 (zero)
        ; upto the IMAGEW.

        INY
        CPY IMAGEW
        BEQ PUTIMAGERLE2L1X
        JMP PUTIMAGERLE2L1

        ; Now we must understand if we are in the > 256 case.
        ; The case is that the high byte is non zero.
    PUTIMAGERLE2L1X:

        LDA IMAGEW+1
        BNE PUTIMAGERLE2L1XX2
        JMP PUTIMAGERLE2L1XX

    PUTIMAGERLE2L1XX2:

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
    PUTIMAGERLE2L1B:

        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGERLE2L1BDEFX
        JMP PUTIMAGERLE2L1BDEF

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 0 = transparency, 1 = opaque
    PUTIMAGERLE2L1BDEFX:
        LDA #0
        STA MATHPTR5
        LDA (TMPPTR),Y
        AND #$80
        ; -> 00 00 00 00
        BEQ PUTIMAGERLE2L1BP1
        LDA MATHPTR5
        ORA #$80
        STA MATHPTR5
    PUTIMAGERLE2L1BP1:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$40
        ; -> 00 01 00 00
        BEQ PUTIMAGERLE2L1BP2
        LDA MATHPTR5
        ORA #$40
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGERLE2L1BP2:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$20
        ; -> 00 00 10 00
        BEQ PUTIMAGERLE2L1BP3
        LDA MATHPTR5
        ORA #$20
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGERLE2L1BP3:
        LDA (TMPPTR),Y
        AND #$10
        BEQ PUTIMAGERLE2L1BP4
        LDA MATHPTR5
        ORA #$10
        STA MATHPTR5
    PUTIMAGERLE2L1BP4:
        LDA (TMPPTR),Y
        AND #$08
        ; -> 00 00 00 00
        BEQ PUTIMAGERLE2L1BP5
        LDA MATHPTR5
        ORA #$08
        STA MATHPTR5
    PUTIMAGERLE2L1BP5:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$04
        ; -> 00 01 00 00
        BEQ PUTIMAGERLE2L1BP6
        LDA MATHPTR5
        ORA #$04
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGERLE2L1BP6:
        LDA (TMPPTR),Y
        ; 00 01 10 00
        AND #$02
        ; -> 00 00 10 00
        BEQ PUTIMAGERLE2L1BP7
        LDA MATHPTR5
        ORA #$02
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGERLE2L1BP7:
        LDA (TMPPTR),Y
        AND #$01
        BEQ PUTIMAGERLE2L1BP8
        LDA MATHPTR5
        ORA #$01
        STA MATHPTR5
    PUTIMAGERLE2L1BP8:
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
        JMP PUTIMAGERLE2L1BFINAL

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGERLE2L1BDEF:
        LDA (TMPPTR),Y

    PUTIMAGERLE2L1BFINAL:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Loop until all bytes are written.

        INY
        BEQ PUTIMAGERLE2L1BX
        JMP PUTIMAGERLE2L1B

    PUTIMAGERLE2L1BX:

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

    PUTIMAGERLE2L1XX:

        ; If the bit 6 of IMAGEF flag is set, a DOUBLE
        ; effect has been required. So we have to copy
        ; another time the very same line.
        ; If not, we can go ahead.

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE2L1N

        ; If bit 1 of IMAGEF flag is set, the DOUBLE
        ; effect has been already applied. So we can
        ; go ahead.

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE2L1N0

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
        JMP PUTIMAGERLE2L1

        ; If we reach this line, it means that
        ; DOUBLE effect has been executed. So,
        ; we can disable any related flag.

    PUTIMAGERLE2L1N0:

        LDA IMAGEF
        AND #$FE
        STA IMAGEF

        ; If we reach this line, no DOUBLE
        ; effect has been required.

    PUTIMAGERLE2L1N:

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
        BEQ PUTIMAGERLE2C

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
        BEQ PUTIMAGERLE2CA
        BCS PUTIMAGERLE2CA

        ; Reload the width and repeat the drawing.

        LDY #0
        JMP PUTIMAGERLE2L1

        ; If we reached this line, it means that the PUT IMAGE
        ; was unable to draw the entire image on the screen,
        ; since the ordinate value was too far low.

    PUTIMAGERLE2CA:

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
        BNE PUTIMAGERLE2CA

    ; Starting from this line, we are drawing the second
    ; color map, the map for 11 bitmap.

    PUTIMAGERLE2C:

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
        BEQ PUTIMAGERLE2L2CC
        ORA #$20
        STA IMAGEW
    PUTIMAGERLE2L2CC:
        TAY
        DEY
    PUTIMAGERLE2L2:
        LDA (TMPPTR),Y
        STA (PLOTCDEST),Y
        DEY
        CPY #255
        BNE PUTIMAGERLE2L2

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGERLE2L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGERLE2L2N0

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
        JMP PUTIMAGERLE2L2

    PUTIMAGERLE2L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGERLE2L2N:

        DEC IMAGEH
        BEQ PUTIMAGERLE2E

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
        BEQ PUTIMAGERLE2EA
        BCS PUTIMAGERLE2EA

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
        JMP PUTIMAGERLE2L2

    PUTIMAGERLE2EA:
    PUTIMAGERLE2E:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; ;;; -----------------------------------> MODE 3 <-----------------------------------
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGERLE3:

        ; Extract width and height of the image. Currently we are
        ; extracting a 2 byte width but the horiz. resolution max
        ; is just 160 so it could be useless.

        ; Width (in pixel)

        ; LDY #0
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        STA IMAGEW
        ; LDY #1
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        STA IMAGEW+1

        ; Height (in "tiles" of 8 pixels)

        ; LDY #2
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
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

;;;;;;;;;;;;;;;;;;;;;;;; FIRST HALF

    PUTIMAGERLE3L1U:

        LDY #0
    PUTIMAGERLE3L1:

        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGERLE3L1DEFX
        JMP PUTIMAGERLE3L1DEF

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 00 = transparency, any other combination = opaque
    PUTIMAGERLE3L1DEFX:
        LDA #0
        STA MATHPTR5
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        ; 00 01 10 00
        AND #$C0
        ; -> 00 00 00 00
        BEQ PUTIMAGERLE3L1P4
        LDA MATHPTR5
        ORA #$C0
        STA MATHPTR5
    PUTIMAGERLE3L1P4:
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        ; 00 01 10 00
        AND #$30
        ; -> 00 01 00 00
        BEQ PUTIMAGERLE3L1P3
        LDA MATHPTR5
        ORA #$30
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGERLE3L1P3:
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        ; 00 01 10 00
        AND #$0C
        ; -> 00 00 10 00
        BEQ PUTIMAGERLE3L1P2
        LDA MATHPTR5
        ORA #$0C
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGERLE3L1P2:
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        AND #$03
        BEQ PUTIMAGERLE3L1P1
        LDA MATHPTR5
        ORA #$03
        STA MATHPTR5
    PUTIMAGERLE3L1P1:
        LDA MATHPTR5
        ; 00 11 11 00
        EOR #$FF
        ; 11 00 00 11
        STA MATHPTR6
        ; LDA (PLOTDEST),Y
        LDA RLECURRENT
        ; 00 00 00 00
        AND MATHPTR6
        STA MATHPTR6
        ; 00 00 00 00
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        AND MATHPTR5
        ORA MATHPTR6
        JMP PUTIMAGERLE3L1FINAL

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGERLE3L1DEF:
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS

    PUTIMAGERLE3L1FINAL:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        CPY IMAGEW
        BNE PUTIMAGERLE3L1

        CLC
        LDA PLOTDEST
        ADC IMAGEW
        STA PLOTDEST
        LDA PLOTDEST+1
        ADC #0
        STA PLOTDEST+1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;; SEC0ND HALF

    PUTIMAGERLE3L1U2:

        LDY #0
    PUTIMAGERLE3L12:

        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGERLE3L1DEFX2
        JMP PUTIMAGERLE3L1DEF2

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 00 = transparency, any other combination = opaque
    PUTIMAGERLE3L1DEFX2:
        LDA #0
        STA MATHPTR5
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        ; 00 01 10 00
        AND #$C0
        ; -> 00 00 00 00
        BEQ PUTIMAGERLE3L1P42
        LDA MATHPTR5
        ORA #$C0
        STA MATHPTR5
    PUTIMAGERLE3L1P42:
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        ; 00 01 10 00
        AND #$30
        ; -> 00 01 00 00
        BEQ PUTIMAGERLE3L1P32
        LDA MATHPTR5
        ORA #$30
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGERLE3L1P32:
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        ; 00 01 10 00
        AND #$0C
        ; -> 00 00 10 00
        BEQ PUTIMAGERLE3L1P22
        LDA MATHPTR5
        ORA #$0C
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGERLE3L1P22:
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        AND #$03
        BEQ PUTIMAGERLE3L1P12
        LDA MATHPTR5
        ORA #$03
        STA MATHPTR5
    PUTIMAGERLE3L1P12:
        LDA MATHPTR5
        ; 00 11 11 00
        EOR #$FF
        ; 11 00 00 11
        STA MATHPTR6
        ; LDA (PLOTDEST),Y
        LDA RLECURRENT
        ; 00 00 00 00
        AND MATHPTR6
        STA MATHPTR6
        ; 00 00 00 00
        ; LDA (TMPPTR),Y
        LDA RLECURRENT
        AND MATHPTR5
        ORA MATHPTR6
        JMP PUTIMAGERLE3L1FINAL2

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGERLE3L1DEF2:
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS

    PUTIMAGERLE3L1FINAL2:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        ; DEY
        ; CPY #255
        INY
        CPY IMAGEW
        BNE PUTIMAGERLE3L12

        SEC
        LDA PLOTDEST
        SBC IMAGEW
        STA PLOTDEST
        LDA PLOTDEST+1
        SBC #0
        STA PLOTDEST+1

        CLC
        LDA PLOTDEST
        ADC #$40
        STA PLOTDEST
        LDA PLOTDEST+1
        ADC #1
        STA PLOTDEST+1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        ; Decrement the number of lines to draw.
        ; If we reach the 0, it means that no more
        ; line has to be drawn. So we can move to
        ; the color part of the data.

        DEC IMAGEH
        BEQ PUTIMAGERLE3C

        ; There is at least one line to draw. So, we must
        ; move down of 8 lines (since we can draw 8 lines
        ; at a time...) and we must check if we are inside
        ; the limits of the video.

        ; reload the width, and repeat another time.

        JMP PUTIMAGERLE3L1U

;;;;;;;;;;;;;;;;;;;;

    PUTIMAGERLE3C:

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

        LDY #0
    PUTIMAGERLE3L2:

        ; Note that, in case that bit 5 of IMAGEF is set, the
        ; PUT IMAGE has been requested with the transparency
        ; effect. In this particular case, we do not touch
        ; the color component.

        LDA IMAGEF
        AND #32
        CMP #32
        BNE PUTIMAGERLE3L2DEF    
        JMP PUTIMAGERLE3L2FINAL

        ; Let's update the color map.

    PUTIMAGERLE3L2DEF:
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        STA (PLOTCDEST),Y

    PUTIMAGERLE3L2FINAL:

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        CPY IMAGEW
        BNE PUTIMAGERLE3L2

        ; Move ahead in the colour data.

        ; Move ahead in the colour video map.
        
        CLC
        LDA PLOTCDEST
        ADC #$28
        STA PLOTCDEST
        LDA PLOTCDEST+1
        ADC #0
        STA PLOTCDEST+1

        ; There are lines to draw? If not, we move to the next
        ; color map to draw.
        DEC IMAGEH
        BEQ PUTIMAGERLE3C2

        ; Move to the next
        
        ; Reload the width and repeat the drawing.

        LDY #0
        JMP PUTIMAGERLE3L2

    PUTIMAGERLE3C2:

        ; Restore the IMAGEY
        LDA MATHPTR4
        STA IMAGEY

        ; First of all, we reset the IMAGEH (in bytes), that could be
        ; destroyed by a previous elaboration.

        LDA IMAGEH2
        STA IMAGEH

        ; Then reset the width, and restart.
        LDA IMAGEW

        LDY #0
    PUTIMAGERLE3C2L2:

        ; Note that, in case that bit 5 of IMAGEF is set, the
        ; PUT IMAGE has been requested with the transparency
        ; effect. In this particular case, we do not touch
        ; the color component.

        LDA IMAGEF
        AND #32
        CMP #32
        BNE PUTIMAGERLE3C2L2DEF
        JMP PUTIMAGERLE3C2L2FINAL

        ; Update the color map.
    PUTIMAGERLE3C2L2DEF:
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        STA (PLOTC2DEST),Y

    PUTIMAGERLE3C2L2FINAL:

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        CPY IMAGEW
        BNE PUTIMAGERLE3C2L2

        ; Move ahead to the next line (on video memory).
        
        CLC
        LDA PLOTC2DEST
        ADC #$28
        STA PLOTC2DEST
        LDA PLOTC2DEST+1
        ADC #0
        STA PLOTC2DEST+1

        ; Are there still lines to draw?
        DEC IMAGEH
        BEQ PUTIMAGERLE3E

        LDY #0
        JMP PUTIMAGERLE3C2L2

    PUTIMAGERLE3E:

        ; IF bit 5 of IMAGEF is enabled it means that the image must be
        ; drawn as transparency -- and it means that colors cannot be
        ; touched.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGERLE3EFINAL

        ; IF bit 1 of IMAGET is cleared, it means that the image must be
        ; drawn without colors.

        LDA IMAGET
        AND #2
        CMP #2
        BNE PUTIMAGERLE3EFINAL

        ; Finally, load the last byte of the image: this is the
        ; background color for the entire image. To be set, if
        ; this is the case.

        ; LDY #0
        ; LDA (TMPPTR),Y
        JSR RLEDECOMPRESS
        STA $D021

    PUTIMAGERLE3EFINAL:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF
