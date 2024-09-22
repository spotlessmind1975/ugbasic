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
;*                          IMAGES ROUTINE FOR VIC-II (REU version)            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PUTIMAGEHEADER:
    .BYTE $00, $00, $00

PUTIMAGEREU:

    ; First of all, reset the source address from expanded
    ; memory, since we are going to refer to it in a relative way.
    LDA TMPPTR
    STA REUREUBASE
    LDA TMPPTR+1
    STA REUREUBASE+1
    LDA BANKPTR
    STA REUREUBASE+2

    ; Then, reset the destination address to the auxiliary area
    ; with the space for the header, that is the first thing we read.
    LDA #<PUTIMAGEHEADER
    STA REUC64BASE
    LDA #>PUTIMAGEHEADER
    STA REUC64BASE+1

    ; Set the legth of the header and read it.
    LDA #3
    STA REUTRANSLEN
    LDA #0
    STA REUTRANSLEN+1
    STA REUCONTROL
    LDA #%10010001
    STA REUCOMMAND

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BNE PUTIMAGEREU2X
    JMP PUTIMAGEREU2
PUTIMAGEREU2X:
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BNE PUTIMAGEREU3X
    JMP PUTIMAGEREU3
PUTIMAGEREU3X:
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BNE PUTIMAGEREU0X
    JMP PUTIMAGEREU0
PUTIMAGEREU0X:
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BNE PUTIMAGEREU1X
    JMP PUTIMAGEREU1
PUTIMAGEREU1X:
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BNE PUTIMAGEREU4X
    JMP PUTIMAGEREU4
PUTIMAGEREU4X:
    RTS

@ENDIF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) )

PUTIMAGEREU0:
        ; LDY #2
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER+2
        STA MATHPTR2
    PUTIMAGEREU02C:
        ; LDY #0
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER
        STA IMAGEW
        LSR
        LSR
        LSR
        STA IMAGEW
        ; LDY #1
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER+1
        LSR
        LSR
        LSR
        STA IMAGEH
        STA IMAGEH2

        ; Remove increment since it is implicit.
        ;
        ; CLC
        ; LDA TMPPTR
        ; ADC #3
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

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

        ; Reset the destination address to the video memory
        LDA PLOTDEST
        STA REUC64BASE
        LDA PLOTDEST+1
        STA REUC64BASE+1

        ; We make a check: if the width of a row to copy is equal to the
        ; width of the entire screen, we can skip the 6502 loop and use
        ; directly the DMA on the entire size.

        LDA IMAGEW
        CMP CURRENTTILESWIDTH
        ;BEQ PUTIMAGE0L1DMA

        ; Copy a row at a time.

    ;     TAY
    ;     DEY
    ; PUTIMAGE0L1:
    ;     LDA (TMPPTR),Y
    ;     STA (PLOTDEST),Y
    ;     DEY
    ;     CPY #255
    ;     BNE PUTIMAGE0L1

    PUTIMAGEREU0L1:

        STA REUTRANSLEN
        LDA #0
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND

        ; Check for double flag repetition.

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU0L1N

        ; Check for double flag.

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU0L1N0

        ; Set the double flag.

        ORA #65
        STA IMAGEF

        ; Increase manually the destination address.

        CLC
        LDA REUC64BASE
        ADC CURRENTTILESWIDTH
        STA REUC64BASE
        LDA REUC64BASE+1
        ADC #0
        STA REUC64BASE+1

        SEC
        LDA REUC64BASE
        SBC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        SBC #0
        STA REUC64BASE+1

        ; Decrease manually the source address.

        CLC
        LDA REUREUBASE
        SBC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        SBC #0
        STA REUC64BASE+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU0L1

    PUTIMAGEREU0L1N0:

        ; Reset the double flag.

        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGEREU0L1N:

        ; Omit increase source address, since it is automatic.
        ;
        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        ; Increase destination address, since it is automatic.
        CLC
        LDA REUC64BASE
        ADC CURRENTTILESWIDTH
        STA REUC64BASE
        LDA REUC64BASE+1
        ADC #$0
        STA REUC64BASE+1

        SEC
        LDA REUC64BASE
        SBC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        SBC #0
        STA REUC64BASE+1

        ; Decrease the height.

        DEC IMAGEH

        ; If no more rows must be wrote, we can move to the color component.

        BEQ PUTIMAGEREU0C

        ; Move to the next line.

        INC IMAGEY
        INC IMAGEY
        INC IMAGEY
        INC IMAGEY
        INC IMAGEY
        INC IMAGEY
        INC IMAGEY
        INC IMAGEY

        ; If we reach the end of the screen, avoid to write further.

        LDA IMAGEY
        CMP CURRENTHEIGHT
        BEQ PUTIMAGEREU0CAX
        BCS PUTIMAGEREU0CAX
        JMP PUTIMAGEREU0CAY

        ; Screen is ended.

    PUTIMAGEREU0CAX:
        JMP PUTIMAGEREU0CA

    PUTIMAGEREU0CAY:

        ; Do the next row!

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU0L1

    PUTIMAGEREU0CA:

        ; Reset the y component.

        LDA MATHPTR4
        STA IMAGEY

        ; Skip row on source.

        CLC
        LDA REUC64BASE
        ADC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        ADC #0
        STA REUC64BASE+1

        ; Decrease the remaining rows, and skip again if remains.

        DEC IMAGEH
        LDA IMAGEH
        CMP #$FF
        BNE PUTIMAGEREU0CA

        JMP PUTIMAGEREU0C

        ; This is the entry point for copy the entire
        ; image on the screen, directly.
    PUTIMAGEREU0L1DMA:
        LDA IMAGEW
        STA CPUMATHMUL8BITTO16BIT_SOURCE
        LDA IMAGEH
        STA CPUMATHMUL8BITTO16BIT_DESTINATION
        JSR CPUMATHMUL8BITTO16BIT
        LDA CPUMATHMUL8BITTO16BIT_OTHER
        STA REUTRANSLEN
        LDA CPUMATHMUL8BITTO16BIT_OTHER+1
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND

        ; Read the color map flag
        ; 0 = 2 colors
        ; 1 = CxR colors
    PUTIMAGEREU0C:
        LDA MATHPTR2
        BEQ PUTIMAGEREU0C2
        JMP PUTIMAGEREU0C16

        ; 0 = 2 colors
    PUTIMAGEREU0C2:
        ; LDY #0
        ; LDA (TMPPTR),Y

        LDA #$7F
        STA REUCONTROL

        ; STA MATHPTR1

        LDA IMAGEH2
        STA IMAGEH

        ; We make a check: if the width of a row to copy is equal to the
        ; width of the entire screen, we can skip the 6502 loop and use
        ; directly the DMA on the entire size.

        LDA IMAGEW
        CMP CURRENTTILESWIDTH
        ;BEQ PUTIMAGEREU02L2DMA

    PUTIMAGEREU02L2:

    ;     TAY
    ;     DEY
    ;     LDA MATHPTR1
    ; PUTIMAGEREU02L2:
    ;     STA (PLOTCDEST),Y
    ;     DEY
    ;     CPY #255
    ;     BNE PUTIMAGEREU02L2

        STA REUTRANSLEN
        LDA #0
        STA REUTRANSLEN+1
        LDA #%10010001
        STA REUCOMMAND

        ; Check for double flag.

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU02L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU02L2N0

        ; Set double flag.
        ORA #65
        STA IMAGEF

        ; CLC
        ; LDA PLOTDEST
        ; ADC CURRENTTILESWIDTH
        ; STA PLOTDEST
        ; LDA PLOTDEST+1
        ; ADC #0
        ; STA PLOTDEST+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU02L2

    PUTIMAGEREU02L2N0:

        ; Reset the double flag.

        LDA IMAGEF
        AND #$FE
        STA IMAGEF

        ; Draw next row

    PUTIMAGEREU02L2N:

        DEC IMAGEH
        BNE PUTIMAGEREU0EX
        JMP PUTIMAGEREU0E

        ; Check if inside the screen.

    PUTIMAGEREU0EX:

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
        BNE PUTIMAGEREU0EX2
        BCC PUTIMAGEREU0EX2
        JMP PUTIMAGEREU0EA

        ; Move to the next row
    PUTIMAGEREU0EX2:
        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        ; CLC
        ; LDA PLOTCDEST
        ; ADC #40
        ; STA PLOTCDEST
        ; LDA PLOTCDEST+1
        ; ADC #0
        ; STA PLOTCDEST+1

        LDA IMAGEW
        ; TAY
        ; DEY
        ; LDA MATHPTR1
        JMP PUTIMAGEREU02L2

        ; This is the entry point for copy the entire
        ; image on the screen, directly.
    PUTIMAGEREU02L2DMA:
        LDA IMAGEW
        STA CPUMATHMUL8BITTO16BIT_SOURCE
        LDA IMAGEH
        STA CPUMATHMUL8BITTO16BIT_DESTINATION
        JSR CPUMATHMUL8BITTO16BIT
        LDA CPUMATHMUL8BITTO16BIT_OTHER
        STA REUTRANSLEN
        LDA CPUMATHMUL8BITTO16BIT_OTHER+1
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND
        JMP PUTIMAGEREU0EA

    PUTIMAGEREU0C16:
        LDA IMAGEH2
        STA IMAGEH

        ; We make a check: if the width of a row to copy is equal to the
        ; width of the entire screen, we can skip the 6502 loop and use
        ; directly the DMA on the entire size.

        LDA IMAGEW
        CMP CURRENTTILESWIDTH
        ; BEQ PUTIMAGEREU0C16L2DMA

    ;     LDA IMAGEW
    ;     TAY
    ;     DEY
    ;     LDA MATHPTR1
    ; PUTIMAGEREU016L2:
    ;     LDA (TMPPTR),Y
    ;     STA (PLOTCDEST),Y
    ;     DEY
    ;     CPY #255
    ;     BNE PUTIMAGEREU016L2

    PUTIMAGEREU016L2:
        STA REUTRANSLEN
        LDA #0
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU016L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU016L2N0

        ORA #65
        STA IMAGEF

        ; CLC
        ; LDA PLOTDEST
        ; ADC CURRENTTILESWIDTH
        ; STA PLOTDEST
        ; LDA PLOTDEST+1
        ; ADC #0
        ; STA PLOTDEST+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU016L2

    PUTIMAGEREU016L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGEREU016L2N:

        DEC IMAGEH
        BEQ PUTIMAGEREU0E

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        ; CLC
        ; LDA PLOTCDEST
        ; ADC #40
        ; STA PLOTCDEST
        ; LDA PLOTCDEST+1
        ; ADC #0
        ; STA PLOTCDEST+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU016L2

    PUTIMAGEREU0E:
    PUTIMAGEREU0EA:
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) )

PUTIMAGEREU1:

        ; LDY #2
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER+2
        STA MATHPTR2
    PUTIMAGEREU12C:
        ; LDY #0
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER
        STA IMAGEW
        LSR
        LSR
        LSR
        STA IMAGEW
        ; LDY #1
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER+1
        LSR
        LSR
        LSR
        STA IMAGEH
        STA IMAGEH2

        ; Automatic move forward by REU.
        ;
        ; CLC
        ; LDA TMPPTR
        ; ADC #3
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

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

        ; TYA
        ; ADC IMAGEH
            
        ; We make a check: if the width of a row to copy is equal to the
        ; width of the entire screen, we can skip the 6502 loop and use
        ; directly the DMA on the entire size.

        LDA IMAGEW
        CMP CURRENTTILESWIDTH
        ;BEQ PUTIMAGE1L1DMA

    PUTIMAGEREU1L1:

    ;     TAY
    ;     DEY
    ; PUTIMAGE1L1:
    ;     LDA (TMPPTR),Y
    ;     STA (PLOTDEST),Y
    ;     DEY
    ;     CPY #255
    ;     BNE PUTIMAGE1L1

        STA REUTRANSLEN
        LDA #0
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU1L1N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU1L1N0

        ORA #65
        STA IMAGEF

        ; Increase manually the destination address.

        CLC
        LDA REUC64BASE
        ADC CURRENTTILESWIDTH
        STA REUC64BASE
        LDA REUC64BASE+1
        ADC #0
        STA REUC64BASE+1

        SEC
        LDA REUC64BASE
        SBC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        SBC #0
        STA REUC64BASE+1

        ; Decrease manually the source address.

        LDA REUREUBASE
        STA TMPPTR2
        LDA REUREUBASE+1
        STA TMPPTR2+1

        SEC
        LDA TMPPTR2
        SBC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        SBC #0
        STA TMPPTR2+1

        LDA TMPPTR2
        STA REUREUBASE
        LDA TMPPTR2+1
        STA REUREUBASE+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU1L1

    PUTIMAGEREU1L1N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGEREU1L1N:

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        ; Increase manually the destination address.

        CLC
        LDA REUC64BASE
        ADC CURRENTTILESWIDTH
        STA REUC64BASE
        LDA REUC64BASE+1
        ADC #0
        STA REUC64BASE+1

        SEC
        LDA REUC64BASE
        SBC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        SBC #0
        STA REUC64BASE+1

        DEC IMAGEH
        BEQ PUTIMAGEREU1C

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
        BEQ PUTIMAGEREU1CAX
        BCS PUTIMAGEREU1CAX
        JMP PUTIMAGEREU1CAY

    PUTIMAGEREU1CAX:
        JMP PUTIMAGEREU1CA

    PUTIMAGEREU1CAY:

        LDA IMAGEW
        TAY
        DEY
        JMP PUTIMAGEREU1L1

    PUTIMAGEREU1L1DMA:
        LDA IMAGEW
        STA CPUMATHMUL8BITTO16BIT_SOURCE
        LDA IMAGEH
        STA CPUMATHMUL8BITTO16BIT_DESTINATION
        JSR CPUMATHMUL8BITTO16BIT
        LDA CPUMATHMUL8BITTO16BIT_OTHER
        STA REUTRANSLEN
        LDA CPUMATHMUL8BITTO16BIT_OTHER+1
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND

    PUTIMAGEREU1CA:

        LDA MATHPTR4
        STA IMAGEY

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        DEC IMAGEH
        LDA IMAGEH
        CMP #$FF
        BNE PUTIMAGEREU1CA

    PUTIMAGEREU1C:
    PUTIMAGEREU1C16:
        LDA IMAGEH2
        STA IMAGEH
        LDA IMAGEW

        ; We make a check: if the width of a row to copy is equal to the
        ; width of the entire screen, we can skip the 6502 loop and use
        ; directly the DMA on the entire size.

        CMP CURRENTTILESWIDTH
        ; BEQ PUTIMAGEREU1C16DMA

    PUTIMAGEREU116L2:

    ;     TAY
    ;     DEY
    ;     LDA MATHPTR1
    ; PUTIMAGEREU116L2:
    ;     LDA (TMPPTR),Y
    ;     STA (PLOTCDEST),Y
    ;     DEY
    ;     CPY #255
    ;     BNE PUTIMAGEREU116L2

        STA REUTRANSLEN
        LDA #0
        STA REUTRANSLEN+1
        STA REUCONTROL
        LDA #%10010001
        STA REUCOMMAND

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU116L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU116L2N0

        ORA #65
        STA IMAGEF

        ; CLC
        ; LDA PLOTDEST
        ; ADC CURRENTTILESWIDTH
        ; STA PLOTDEST
        ; LDA PLOTDEST+1
        ; ADC #0
        ; STA PLOTDEST+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU116L2

    PUTIMAGEREU116L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGEREU116L2N:

        DEC IMAGEH
        BEQ PUTIMAGEREU1E

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        CLC
        LDA REUC64BASE
        ADC CURRENTTILESWIDTH
        STA REUC64BASE
        LDA REUC64BASE+1
        ADC #0
        STA REUC64BASE+1

        SEC
        LDA REUC64BASE
        SBC IMAGEW
        STA REUC64BASE
        LDA REUC64BASE+1
        SBC #0
        STA REUC64BASE+1

        LDA IMAGEW
        ; TAY
        ; DEY
        JMP PUTIMAGEREU116L2

    PUTIMAGEREU1C16DMA:
        ; @todo

    PUTIMAGEREU0C16L2DMA:
        ; @todo

    PUTIMAGEREU1E:
    PUTIMAGEREU1EA:
        RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

PUTIMAGEREU4:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) )

PUTIMAGEREU2:

        ; Extract width and height of the image. 
        ; Width (in pixel)

        ; LDY #0
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER
        STA IMAGEW
        ; LDY #1
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER+1
        STA IMAGEW+1

        ; Height (in "tiles" of 8 pixels)

        ; LDY #2
        ; LDA (TMPPTR),Y
        LDA PUTIMAGEHEADER+2
        LSR
        LSR
        LSR
        STA IMAGEH
        STA IMAGEH2

        ; Moved ahed by REU
        ;
        ; CLC
        ; LDA TMPPTR
        ; ADC #3
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

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

        LDA #<C64REUBANKTMPBUF
        STA REUC64BASE
        LDA #>C64REUBANKTMPBUF
        STA REUC64BASE+1
        LDA #1
        STA REUTRANSLEN
        LDA #0
        STA REUTRANSLEN+1
        LDA #$BF
        STA REUCONTROL

        ; LDY #0
    PUTIMAGEREU2L1:
        ; LDA (TMPPTR),Y

        LDA #%10010001
        STA REUCOMMAND
        LDA C64REUBANKTMPBUF

        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGEREU2L1DEFX
        JMP PUTIMAGEREU2L1DEF

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 00 = transparency, any other combination = opaque
    PUTIMAGEREU2L1DEFX:
        ; LDA #0
        STA MATHPTR5
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$80
        ; -> 00 00 00 00
        BEQ PUTIMAGEREU2L1P1
        LDA MATHPTR5
        ORA #$80
        STA MATHPTR5
    PUTIMAGEREU2L1P1:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$40
        ; -> 00 01 00 00
        BEQ PUTIMAGEREU2L1P2
        LDA MATHPTR5
        ORA #$40
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGEREU2L1P2:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$20
        ; -> 00 00 10 00
        BEQ PUTIMAGEREU2L1P3
        LDA MATHPTR5
        ORA #$20
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGEREU2L1P3:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$10
        BEQ PUTIMAGEREU2L1P4
        LDA MATHPTR5
        ORA #$10
        STA MATHPTR5
    PUTIMAGEREU2L1P4:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$08
        ; -> 00 00 00 00
        BEQ PUTIMAGEREU2L1P5
        LDA MATHPTR5
        ORA #$08
        STA MATHPTR5
    PUTIMAGEREU2L1P5:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$04
        ; -> 00 01 00 00
        BEQ PUTIMAGEREU2L1P6
        LDA MATHPTR5
        ORA #$04
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGEREU2L1P6:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$02
        ; -> 00 00 10 00
        BEQ PUTIMAGEREU2L1P7
        LDA MATHPTR5
        ORA #$02
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGEREU2L1P7:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$01
        BEQ PUTIMAGEREU2L1P8
        LDA MATHPTR5
        ORA #$01
        STA MATHPTR5
    PUTIMAGEREU2L1P8:
        LDA MATHPTR5
        ; 00 11 11 00
        EOR #$FF
        ; 11 00 00 11
        STA MATHPTR6
        ; LDA (PLOTDEST),Y
        LDA C64REUBANKTMPBUF
        ; 00 00 00 00
        AND MATHPTR6
        STA MATHPTR6
        ; 00 00 00 00
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND MATHPTR5
        ORA MATHPTR6
        JMP PUTIMAGEREU2L1FINAL

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGEREU2L1DEF:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF

    PUTIMAGEREU2L1FINAL:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Increment the offset. Note that Y starts from 0 (zero)
        ; upto the IMAGEW.

        INY
        CPY IMAGEW
        BEQ PUTIMAGEREU2L1X
        JMP PUTIMAGEREU2L1

        ; Now we must understand if we are in the > 256 case.
        ; The case is that the high byte is non zero.
    PUTIMAGEREU2L1X:

        LDA IMAGEW+1
        BNE PUTIMAGEREU2L1XX2
        JMP PUTIMAGEREU2L1XX

    PUTIMAGEREU2L1XX2:

        ; We must draw an image greater than 256 pixels.
        ; So move forward on the memory and video bitmap.

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        CLC
        LDA PLOTDEST
        ADC IMAGEW
        STA PLOTDEST
        LDA PLOTDEST+1
        ADC #0
        STA PLOTDEST+1

        LDY #0
    PUTIMAGEREU2L1B:

        LDA #%10010001
        STA REUCOMMAND
        
        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGEREU2L1BDEFX
        JMP PUTIMAGEREU2L1BDEF

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 0 = transparency, 1 = opaque
    PUTIMAGEREU2L1BDEFX:
        LDA #0
        STA MATHPTR5
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$80
        ; -> 00 00 00 00
        BEQ PUTIMAGEREU2L1BP1
        LDA MATHPTR5
        ORA #$80
        STA MATHPTR5
    PUTIMAGEREU2L1BP1:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$40
        ; -> 00 01 00 00
        BEQ PUTIMAGEREU2L1BP2
        LDA MATHPTR5
        ORA #$40
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGEREU2L1BP2:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$20
        ; -> 00 00 10 00
        BEQ PUTIMAGEREU2L1BP3
        LDA MATHPTR5
        ORA #$20
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGEREU2L1BP3:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$10
        BEQ PUTIMAGEREU2L1BP4
        LDA MATHPTR5
        ORA #$10
        STA MATHPTR5
    PUTIMAGEREU2L1BP4:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$08
        ; -> 00 00 00 00
        BEQ PUTIMAGEREU2L1BP5
        LDA MATHPTR5
        ORA #$08
        STA MATHPTR5
    PUTIMAGEREU2L1BP5:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$04
        ; -> 00 01 00 00
        BEQ PUTIMAGEREU2L1BP6
        LDA MATHPTR5
        ORA #$04
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGEREU2L1BP6:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$02
        ; -> 00 00 10 00
        BEQ PUTIMAGEREU2L1BP7
        LDA MATHPTR5
        ORA #$02
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGEREU2L1BP7:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$01
        BEQ PUTIMAGEREU2L1BP8
        LDA MATHPTR5
        ORA #$01
        STA MATHPTR5
    PUTIMAGEREU2L1BP8:
        LDA MATHPTR5
        ; 00 11 11 00
        EOR #$FF
        ; 11 00 00 11
        STA MATHPTR6
        ; LDA (PLOTDEST),Y
        LDA C64REUBANKTMPBUF
        ; 00 00 00 00
        AND MATHPTR6
        STA MATHPTR6
        ; 00 00 00 00
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND MATHPTR5
        ORA MATHPTR6
        JMP PUTIMAGEREU2L1BFINAL

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGEREU2L1BDEF:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF

    PUTIMAGEREU2L1BFINAL:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Loop until all bytes are written.

        INY
        BEQ PUTIMAGEREU2L1BX
        JMP PUTIMAGEREU2L1B

    PUTIMAGEREU2L1BX:

        ; Move back the pointer to the start
        ; of the drawed line.

        ; SEC
        ; LDA TMPPTR
        ; SBC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; SBC #0
        ; STA TMPPTR+1

        ; SEC
        ; LDA REUREUBASE
        ; SBC IMAGEW
        ; STA REUREUBASE
        ; LDA REUREUBASE+1
        ; SBC #0
        ; STA REUREUBASE+1

        SEC
        LDA PLOTDEST
        SBC IMAGEW
        STA PLOTDEST
        LDA PLOTDEST+1
        SBC #0
        STA PLOTDEST+1

    PUTIMAGEREU2L1XX:

        ; If the bit 6 of IMAGEF flag is set, a DOUBLE
        ; effect has been required. So we have to copy
        ; another time the very same line.
        ; If not, we can go ahead.

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU2L1N

        ; If bit 1 of IMAGEF flag is set, the DOUBLE
        ; effect has been already applied. So we can
        ; go ahead.

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU2L1N0

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
        JMP PUTIMAGEREU2L1

        ; If we reach this line, it means that
        ; DOUBLE effect has been executed. So,
        ; we can disable any related flag.

    PUTIMAGEREU2L1N0:

        LDA IMAGEF
        AND #$FE
        STA IMAGEF

        ; If we reach this line, no DOUBLE
        ; effect has been required.

    PUTIMAGEREU2L1N:

        ; Move ahead in the data.

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC IMAGEW+1
        ; STA TMPPTR+1

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
        BEQ PUTIMAGEREU2C

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
        BEQ PUTIMAGEREU2CA
        BCS PUTIMAGEREU2CA

        ; Reload the width and repeat the drawing.

        LDY #0
        JMP PUTIMAGEREU2L1

        ; If we reached this line, it means that the PUT IMAGE
        ; was unable to draw the entire image on the screen,
        ; since the ordinate value was too far low.

    PUTIMAGEREU2CA:

        ; Now we must go ahead, in order to access to the
        ; colormap data.

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC IMAGEW+1
        ; STA TMPPTR+1

        ; Are still lines to draw?

        DEC IMAGEH
        BNE PUTIMAGEREU2CA

    ; Starting from this line, we are drawing the second
    ; color map, the map for 11 bitmap.

    PUTIMAGEREU2C:

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
        BEQ PUTIMAGEREU2L2CC
        ORA #$20
        STA IMAGEW
    PUTIMAGEREU2L2CC:
        LDY #0
    PUTIMAGEREU2L2:

        LDA #%10010001
        STA REUCOMMAND
        LDA C64REUBANKTMPBUF

        STA (PLOTCDEST),Y
        INY
        CPY IMAGEW
        BNE PUTIMAGEREU2L2

        LDA IMAGEF
        AND #64
        BEQ PUTIMAGEREU2L2N

        LDA IMAGEF
        AND #1
        BNE PUTIMAGEREU2L2N0

        ORA #65
        STA IMAGEF

        CLC
        LDA PLOTCDEST
        ADC CURRENTTILESWIDTH
        STA PLOTCDEST
        LDA PLOTCDEST+1
        ADC #0
        STA PLOTCDEST+1

        LDA REUREUBASE
        STA TMPPTR2
        LDA REUREUBASE+1
        STA TMPPTR2+1

        SEC
        LDA TMPPTR2
        SBC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        SBC #0
        STA TMPPTR2+1

        LDA TMPPTR2
        STA REUREUBASE
        LDA TMPPTR2+1
        STA REUREUBASE+1

        LDY #0
        JMP PUTIMAGEREU2L2

    PUTIMAGEREU2L2N0:
        LDA IMAGEF
        AND #$FE
        STA IMAGEF

    PUTIMAGEREU2L2N:

        DEC IMAGEH
        BEQ PUTIMAGEREU2E

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
        BEQ PUTIMAGEREU2EA
        BCS PUTIMAGEREU2EA

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        CLC
        LDA PLOTCDEST
        ADC CURRENTTILESWIDTH
        STA PLOTCDEST
        LDA PLOTCDEST+1
        ADC #0
        STA PLOTCDEST+1

        LDY #0
        JMP PUTIMAGEREU2L2

    PUTIMAGEREU2EA:
    PUTIMAGEREU2E:
        RTS

@ENDIF

;;;;;;;;;;;;;;;;;

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

PUTIMAGEREU3:

    ; Extract width and height of the image. Currently we are
    ; extracting a 2 byte width but the horiz. resolution max
    ; is just 160 so it could be useless.

    ; Width (in pixel)

    ; LDY #0
    ; LDA (TMPPTR),Y
    LDA PUTIMAGEHEADER
    STA IMAGEW
    ; LDY #1
    ; LDA (TMPPTR),Y
    LDA PUTIMAGEHEADER+1
    STA IMAGEW+1

    ; Height (in "tiles" of 8 pixels)

    ; LDY #2
    ; LDA (TMPPTR),Y
    LDA PUTIMAGEHEADER+2
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    ; Move ahead of 3 bytes, where the bitmap data begins.
    ;
    ; CLC
    ; LDA TMPPTR
    ; ADC #3
    ; STA TMPPTR
    ; LDA TMPPTR+1
    ; ADC #0
    ; STA TMPPTR+1

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

    LDA #<C64REUBANKTMPBUF
    STA REUC64BASE
    LDA #>C64REUBANKTMPBUF
    STA REUC64BASE+1
    LDA #1
    STA REUTRANSLEN
    LDA #0
    STA REUTRANSLEN+1
    LDA #$BF
    STA REUCONTROL

    PUTIMAGEREU3D0:

        LDX #0
        LDA IMAGEW
        ASL
        STA IMAGEW2
        BCC PUTIMAGEREU3L1U

        LDX #1
        LDY #0
    PUTIMAGEREU3L1:

        LDA #%10010001
        STA REUCOMMAND
        
        ; At the beginning of each byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGEREU3L1DEFX
        JMP PUTIMAGEREU3L1DEF

        ; PUT IMAGE with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 00 = transparency, any other combination = opaque
    PUTIMAGEREU3L1DEFX:
        LDA #0
        STA MATHPTR5
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$C0
        ; -> 00 00 00 00
        BEQ PUTIMAGEREU3L1P4
        LDA MATHPTR5
        ORA #$C0
        STA MATHPTR5
    PUTIMAGEREU3L1P4:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$30
        ; -> 00 01 00 00
        BEQ PUTIMAGEREU3L1P3
        LDA MATHPTR5
        ORA #$30
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGEREU3L1P3:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$0C
        ; -> 00 00 10 00
        BEQ PUTIMAGEREU3L1P2
        LDA MATHPTR5
        ORA #$0C
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGEREU3L1P2:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$03
        BEQ PUTIMAGEREU3L1P1
        LDA MATHPTR5
        ORA #$03
        STA MATHPTR5
    PUTIMAGEREU3L1P1:
        LDA MATHPTR5
        ; 00 11 11 00
        EOR #$FF
        ; 11 00 00 11
        STA MATHPTR6
        ; LDA (PLOTDEST),Y
        LDA C64REUBANKTMPBUF
        ; 00 00 00 00
        AND MATHPTR6
        STA MATHPTR6
        ; 00 00 00 00
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND MATHPTR5
        ORA MATHPTR6
        JMP PUTIMAGEREU3L1FINAL

        ; PUT IMAGE without transparency.
        ; Simply load the bitmap data "as is".
    PUTIMAGEREU3L1DEF:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF

    PUTIMAGEREU3L1FINAL:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        BNE PUTIMAGEREU3L1
        LDA IMAGEW2
        BEQ PUTIMAGEREU3L1F

        INC PLOTDEST+1

    PUTIMAGEREU3L1U:

        
        ; Now if X = 1 we are going to draw an image of 256 + Y bytes.
        ; Otherwise, we are going to draw an image of Y bytes.
        ; Since we are using indirect indexed access to the memory,
        ; Y will contain the LAST data to copy. So we must decrement
        ; it by 1, in order to start from the end of the line.

        ; Now we must understand if we are in the 256+Y case or
        ; in the Y case. The former is denoted by having X = 1.

        ; We are in the 256 + Y case. So we have to move ahead of Y
        ; bytes and to repeat an entire 256 bytes row copy.

    PUTIMAGEREU3L1FX:

        ; Take the width of the image, double it (carry will be lost)
        ; and add to the video bitmap address.
        ;
        ;     7654 3210
        ;     1000 0010 = 128 + 2 = 130 pixel
        ;               x 2 = 260
        ;   1 0000 0100 = 4 + carry = 4
        
        ; Take the width of the image, double it (carry will be lost)
        ; and add to the graphical data source address.

        ; LDA IMAGEW
        ; ASL
        ; CLC
        ; ADC TMPPTR
        ; STA TMPPTR
        ; LDA #0
        ; ADC TMPPTR+1
        ; STA TMPPTR+1

        ; Now we repeat a 256-full width byte copying, from the graphical
        ; data source address to the video bitmap address.

        LDY #0

    PUTIMAGEREU3L1X:

        LDA #%10010001
        STA REUCOMMAND

        ; At the beginning of each (256 bytes full) byte copy, we are going to
        ; check if a transparency effect has been requested.
        ; If bit 5 of IMAGEF is set, a transparency is requested.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGEREU3L1XDEFX
        JMP PUTIMAGEREU3L1XDEF

        ; PUT IMAGE (full 256 bytes copy) with transparency
        ; Load the byte about the bitmap data and draw on the
        ; screen at the given position. Before storing it, you
        ; have to check if a transparency mask has to be applied.
        ; 00 = transparency, any other combination = opaque
    PUTIMAGEREU3L1XDEFX:
        LDA #0
        STA MATHPTR5
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$C0
        ; -> 00 00 00 00
        BEQ PUTIMAGEREU3L1P4X
        LDA MATHPTR5
        ORA #$C0
        STA MATHPTR5
    PUTIMAGEREU3L1P4X:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$30
        ; -> 00 01 00 00
        BEQ PUTIMAGEREU3L1P3X
        LDA MATHPTR5
        ORA #$30
        ; MATH PTR = 00 11 00 00
        STA MATHPTR5
    PUTIMAGEREU3L1P3X:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        ; 00 01 10 00
        AND #$0C
        ; -> 00 00 10 00
        BEQ PUTIMAGEREU3L1P2X
        LDA MATHPTR5
        ORA #$0C
        ; -> 00 11 11 00
        STA MATHPTR5
    PUTIMAGEREU3L1P2X:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND #$03
        BEQ PUTIMAGEREU3L1P1X
        LDA MATHPTR5
        ORA #$03
        STA MATHPTR5
    PUTIMAGEREU3L1P1X:
        LDA MATHPTR5
        ; 00 11 11 00
        EOR #$FF
        ; 11 00 00 11
        STA MATHPTR6
        ; LDA (PLOTDEST),Y
        LDA C64REUBANKTMPBUF
        ; 00 00 00 00
        AND MATHPTR6
        STA MATHPTR6
        ; 00 00 00 00
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF
        AND MATHPTR5
        ORA MATHPTR6
        JMP PUTIMAGEREU3L1FINALX

        ; PUT IMAGE (full 256-bytes copy) without transparency.
        ; Simply load the bitmap data "as is".

    PUTIMAGEREU3L1XDEF:
        ; LDA (TMPPTR),Y
        LDA C64REUBANKTMPBUF

    PUTIMAGEREU3L1FINALX:

        ; Now store the bitmap data on the video bitmap.

        STA (PLOTDEST),Y

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        CPY IMAGEW2
        BNE PUTIMAGEREU3L1X

    PUTIMAGEREU3L1XN:
    PUTIMAGEREU3L1F:

        ; Now we must go ahead, in order to access to the
        ; data of the next line. Again, since each pixel
        ; occupy 2 bits, we have to double the IMAGEW
        ; value. So we add this size twice.

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

        ; Instead, we move the video bitmap address ahead
        ; of precomputed size, since the width (in bytes)
        ; of a line is fixed.

        CPX #1
        BNE PUTIMAGEREU3L1FY
        LDA IMAGEW2
        BEQ PUTIMAGEREU3L1FY

        DEC PLOTDEST+1

    PUTIMAGEREU3L1FY:

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
        BEQ PUTIMAGEREU3C

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

        BEQ PUTIMAGEREU3CA
        BCS PUTIMAGEREU3CA

        ; Otherwise, reload the width, and repeat another time.

        ; LDA IMAGEW
        ; ASL
        JMP PUTIMAGEREU3D0

        ; If we reached this line, it means that the PUT IMAGE
        ; was unable to draw the entire image on the screen,
        ; since the ordinate value was too far low.
    PUTIMAGEREU3CA:

        ; Now we must go ahead, in order to access to the
        ; colormap data. Again, since each pixel
        ; occupy 2 bits, we have to double the IMAGEW
        ; value. So we add this size twice.

        LDA REUREUBASE
        STA TMPPTR2
        LDA REUREUBASE+1
        STA TMPPTR2+1

        CLC
        LDA TMPPTR2
        ADC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        ADC #0
        STA TMPPTR2+1

        CLC
        LDA TMPPTR2
        ADC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        ADC #0
        STA TMPPTR2+1

        LDA TMPPTR2
        STA REUREUBASE
        LDA TMPPTR2+1
        STA REUREUBASE+1

        ; We repeat the adding as long as remain lines to draw.

        DEC IMAGEH
        BNE PUTIMAGEREU3CA

        ; Starting from this line, we are drawing the first
        ; color map, the map for 01 and 10 bitmap.

    PUTIMAGEREU3C:

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
    PUTIMAGEREU3L2:

        LDA #%10010001
        STA REUCOMMAND

        ; Note that, in case that bit 5 of IMAGEF is set, the
        ; PUT IMAGE has been requested with the transparency
        ; effect. In this particular case, we do not touch
        ; the color component.

        LDA IMAGEF
        AND #32
        CMP #32
        BNE PUTIMAGEREU3L2DEF    
        JMP PUTIMAGEREU3L2FINAL

        ; Let's update the color map.

    PUTIMAGEREU3L2DEF:

        LDA C64REUBANKTMPBUF

        STA (PLOTCDEST),Y

    PUTIMAGEREU3L2FINAL:

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        CPY IMAGEW
        BNE PUTIMAGEREU3L2

        ; Move ahead in the colour data.

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

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
        BEQ PUTIMAGEREU3C2

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
        BEQ PUTIMAGEREU3C2A
        BCS PUTIMAGEREU3C2A

        ; Reload the width and repeat the drawing.

        LDY #0
        JMP PUTIMAGEREU3L2

        ; If we reached this line, it means that the PUT IMAGE
        ; was unable to draw the entire image on the screen,
        ; since the ordinate value was too far low.
    PUTIMAGEREU3C2A:

        ; Now we must go ahead, in order to access to the
        ; colormap data.

        LDA REUREUBASE
        STA TMPPTR2
        LDA REUREUBASE+1
        STA TMPPTR2+1

        CLC
        LDA TMPPTR2
        ADC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        ADC #0
        STA TMPPTR2+1

        CLC
        LDA TMPPTR2
        ADC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        ADC #0
        STA TMPPTR2+1

        LDA TMPPTR2
        STA REUREUBASE
        LDA TMPPTR2+1
        STA REUREUBASE+1

        ; Are still lines to draw?

        DEC IMAGEH
        BNE PUTIMAGEREU3C2A

    ; Starting from this line, we are drawing the second
    ; color map, the map for 11 bitmap.

    PUTIMAGEREU3C2:

        ; Restore the IMAGEY
        LDA MATHPTR4
        STA IMAGEY

        ; First of all, we reset the IMAGEH (in bytes), that could be
        ; destroyed by a previous elaboration.

        LDA IMAGEH2
        STA IMAGEH

        ; Then reset the width, and restart.
        LDY #0

    PUTIMAGEREU3C2L2:

        LDA #%10010001
        STA REUCOMMAND
        
        ; Note that, in case that bit 5 of IMAGEF is set, the
        ; PUT IMAGE has been requested with the transparency
        ; effect. In this particular case, we do not touch
        ; the color component.

        LDA IMAGEF
        AND #32
        CMP #32
        BNE PUTIMAGEREU3C2L2DEF
        JMP PUTIMAGEREU3C2L2FINAL

        ; Update the color map.
    PUTIMAGEREU3C2L2DEF:

        LDA C64REUBANKTMPBUF
        STA (PLOTC2DEST),Y

    PUTIMAGEREU3C2L2FINAL:

        ; Decrement the offset. Note that Y starts from the
        ; end of the row, so 0 (zero) is a valid offset.

        INY
        CPY IMAGEW
        BNE PUTIMAGEREU3C2L2

        ; Move ahead to the next line (in memory).

        ; CLC
        ; LDA TMPPTR
        ; ADC IMAGEW
        ; STA TMPPTR
        ; LDA TMPPTR+1
        ; ADC #0
        ; STA TMPPTR+1

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
        BEQ PUTIMAGEREU3E

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
        BEQ PUTIMAGEREU3EA
        BCS PUTIMAGEREU3EA

        ; Restart the drawing...

        LDY #0
        JMP PUTIMAGEREU3C2L2

        ; If we reached this line, it means that the PUT IMAGE
        ; was unable to draw the entire image on the screen,
        ; since the ordinate value was too far low.

    PUTIMAGEREU3EA:

        ; Move ahead in memory still exist lines to be drawn.

        LDA REUREUBASE
        STA TMPPTR2
        LDA REUREUBASE+1
        STA TMPPTR2+1

        CLC
        LDA TMPPTR2
        ADC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        ADC #0
        STA TMPPTR2+1

        CLC
        LDA TMPPTR2
        ADC IMAGEW
        STA TMPPTR2
        LDA TMPPTR2+1
        ADC #0
        STA TMPPTR2+1

        LDA TMPPTR2
        STA REUREUBASE
        LDA TMPPTR2+1
        STA REUREUBASE+1

        DEC IMAGEH
        BNE PUTIMAGEREU3EA

        ; Finally, we reached the end of the image,
        ; with the various palette and colors. Let's
        ; consider or ignore it, based on flags.

    PUTIMAGEREU3E:

        ; LDA REUREUBASE
        ; STA TMPPTR2
        ; LDA REUREUBASE+1
        ; STA TMPPTR2+1

        ; SEC
        ; LDA TMPPTR2
        ; SBC #1
        ; STA TMPPTR2
        ; LDA TMPPTR2+1
        ; SBC #0
        ; STA TMPPTR2+1

        ; LDA TMPPTR2
        ; STA REUREUBASE
        ; LDA TMPPTR2+1
        ; STA REUREUBASE+1

        ; IF bit 5 of IMAGEF is enabled it means that the image must be
        ; drawn as transparency -- and it means that colors cannot be
        ; touched.

        LDA IMAGEF
        AND #32
        CMP #32
        BEQ PUTIMAGEREU3EFINAL

        ; IF bit 1 of IMAGET is cleared, it means that the image must be
        ; drawn without colors.

        LDA IMAGET
        AND #2
        CMP #2
        BNE PUTIMAGEREU3EFINAL

        ; Finally, load the last byte of the image: this is the
        ; background color for the entire image. To be set, if
        ; this is the case.

        LDA #%10010001
        STA REUCOMMAND
        NOP
        NOP
        LDA C64REUBANKTMPBUF
        STA $D021

    PUTIMAGEREU3EFINAL:
        RTS

@ENDIF

