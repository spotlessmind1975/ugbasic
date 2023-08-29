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

BLITIMAGEBLITADDR:
BLITIMAGEBLIT:
    JMP $0000

BLITIMAGE:

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BNE BLITIMAGE2X
    JMP BLITIMAGE2
BLITIMAGE2X:
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BNE BLITIMAGE3X
    JMP BLITIMAGE3
BLITIMAGE3X:
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BNE BLITIMAGE0X
    JMP BLITIMAGE0
BLITIMAGE0X:
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BNE BLITIMAGE1X
    JMP BLITIMAGE1
BLITIMAGE1X:
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BNE BLITIMAGE4X
    JMP BLITIMAGE4
BLITIMAGE4X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) )

BLITIMAGE0:

    LDY #2
    LDA (BLITTMPPTR),Y
    STA MATHPTR2
BLITIMAGE02C:
    LDA (BLITTMPPTR),Y
    STA IMAGEW
    LSR
    LSR
    LSR
    STA IMAGEW
    LDY #1
    LDA (BLITTMPPTR),Y
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    CLC
    LDA BLITTMPPTR
    ADC #2
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC #2
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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
BLITIMAGE0L1:
    LDA (PLOTDEST),Y
    STA BLITS0
    LDA (BLITTMPPTR),Y
    STA BLITS1
    LDA (BLITTMPPTR2),Y
    STA BLITS2
    JSR BLITIMAGEBLIT
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE0L1

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE0L1N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE0L1N0

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
    JMP BLITIMAGE0L1

BLITIMAGE0L1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE0L1N:


    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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
    BEQ BLITIMAGE0C

    LDA IMAGEW
    TAY
    DEY
    JMP BLITIMAGE0L1

BLITIMAGE0C:
    LDA MATHPTR2
    BEQ BLITIMAGE0C2
    JMP BLITIMAGE0C16

BLITIMAGE0C2:
    LDY #0
    LDA (BLITTMPPTR),Y
    STA MATHPTR1

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    DEY
    LDA MATHPTR1
BLITIMAGE02L2:
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE02L2

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE02L2N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE02L2N0

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
    JMP BLITIMAGE02L2

BLITIMAGE02L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE02L2N:





    DEC IMAGEH
    BNE BLITIMAGE0EX
    JMP BLITIMAGE0E

BLITIMAGE0EX:
    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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
    JMP BLITIMAGE02L2

BLITIMAGE0C16:
    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    DEY
    LDA MATHPTR1
BLITIMAGE016L2:
    ; LDA (PLOTCDEST),Y
    ; STA BLITS0
    LDA (BLITTMPPTR),Y
    ; STA BLITS1
    ; LDA (BLITTMPPTR2),Y
    ; STA BLITS2
    ; JSR BLITIMAGEBLIT
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE016L2

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE016L2N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE016L2N0

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
    JMP BLITIMAGE016L2

BLITIMAGE016L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE016L2N:




    DEC IMAGEH
    BEQ BLITIMAGE0E

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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
    JMP BLITIMAGE016L2

BLITIMAGE0E:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

BLITIMAGE1:
BLITIMAGE4:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) )

BLITIMAGE2:
    LDY #0
    LDA (BLITTMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (BLITTMPPTR),Y
    STA IMAGEW+1
    LDY #2
    LDA (BLITTMPPTR),Y
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    CLC
    LDA BLITTMPPTR
    ADC #3
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC #3
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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

    TYA
    ADC IMAGEH
    
    ; LDA #200
    ; JSR BLITIMAGEWAITLINE
    
    LDY #0
BLITIMAGE2L1:
    LDA (PLOTDEST),Y
    STA BLITS0
    LDA (BLITTMPPTR),Y
    STA BLITS1
    LDA (BLITTMPPTR2),Y
    STA BLITS2
    JSR BLITIMAGEBLIT
    STA (PLOTDEST),Y
    INY
    CPY IMAGEW
    BEQ BLITIMAGE2L1X
    JMP BLITIMAGE2L1
BLITIMAGE2L1X:

    LDA IMAGEW+1
    BEQ BLITIMAGE2L1XX

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA PLOTDEST
    ADC IMAGEW
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDY #0
BLITIMAGE2L1B:
    LDA (PLOTDEST), Y
    STA BLITS0
    LDA (BLITTMPPTR), Y
    STA BLITS1
    LDA (BLITTMPPTR2), Y
    STA BLITS2
    JSR BLITIMAGEBLIT
    STA (PLOTDEST),Y
    INY
    BNE BLITIMAGE2L1B

    SEC
    LDA BLITTMPPTR
    SBC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    SBC #0
    STA BLITTMPPTR+1

    SEC
    LDA BLITTMPPTR2
    SBC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    SBC #0
    STA BLITTMPPTR2+1

    SEC
    LDA PLOTDEST
    SBC IMAGEW
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1

BLITIMAGE2L1XX:
    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE2L1N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE2L1N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTTILESWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDY #0
    JMP BLITIMAGE2L1

BLITIMAGE2L1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE2L1N:

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC IMAGEW+1
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC IMAGEW+1
    STA BLITTMPPTR2+1

    CLC
    LDA PLOTDEST
    ADC CURRENTWIDTH
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC CURRENTWIDTH+1
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ BLITIMAGE2C

    LDY #0
    JMP BLITIMAGE2L1

BLITIMAGE2C:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW+1
    TAX
    LDA IMAGEW
    LSR A
    LSR A
    LSR A
    STA IMAGEW
    CPX #0
    BEQ BLITIMAGE2L2CC
    ORA #$20
    STA IMAGEW
BLITIMAGE2L2CC:
    TAY
    DEY
BLITIMAGE2L2:
    ; LDA (PLOTCDEST),Y
    ; STA BLITS0
    LDA (BLITTMPPTR),Y
    ; STA BLITS1
    ; LDA (BLITTMPPTR2),Y
    ; STA BLITS2
    ; JSR BLITIMAGEBLIT
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE2L2

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE2L2N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE2L2N0

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
    JMP BLITIMAGE2L2

BLITIMAGE2L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE2L2N:



    DEC IMAGEH
    BEQ BLITIMAGE2E

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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
    JMP BLITIMAGE2L2

BLITIMAGE2E:
    RTS

@ENDIF

;;;;;;;;;;;;;;;;;

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

BLITIMAGE3:
    LDY #0
    LDA (BLITTMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (BLITTMPPTR),Y
    STA IMAGEW+1
    LDY #2
    LDA (BLITTMPPTR),Y
    LSR
    LSR
    LSR
    STA IMAGEH
    STA IMAGEH2

    CLC
    LDA BLITTMPPTR
    ADC #3
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC #3
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

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

    ; LDA #200
    ; JSR BLITIMAGEWAITLINE

    LDX #0
    LDA IMAGEW
    ASL
    BCC BLITIMAGE3L1U
    LDX #1
BLITIMAGE3L1U:
    TAY
    DEY
BLITIMAGE3L1:
    LDA (PLOTDEST),Y
    STA BLITS0
    LDA (BLITTMPPTR),Y
    STA BLITS1
    LDA (BLITTMPPTR2),Y
    STA BLITS2
    JSR BLITIMAGEBLIT
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE3L1

    TXA
    BNE BLITIMAGE3L1FX
    JMP BLITIMAGE3L1F

BLITIMAGE3L1FX:

    LDA IMAGEW
    ASL
    CLC
    ADC PLOTDEST
    STA PLOTDEST
    LDA #0
    ADC PLOTDEST+1
    STA PLOTDEST+1

    LDA IMAGEW
    ASL
    CLC
    ADC BLITTMPPTR
    STA BLITTMPPTR
    LDA #0
    ADC BLITTMPPTR+1
    STA BLITTMPPTR+1

    LDA IMAGEW
    ASL
    CLC
    ADC BLITTMPPTR2
    STA BLITTMPPTR2
    LDA #0
    ADC BLITTMPPTR2+1
    STA BLITTMPPTR2+1

    LDA #$FF
    TAY
BLITIMAGE3L1X:
BLITIMAGE3L1XDEF:
    LDA (PLOTDEST),Y
    STA BLITS0
    LDA (BLITTMPPTR),Y
    STA BLITS1
    LDA (BLITTMPPTR2),Y
    STA BLITS2
    JSR BLITIMAGEBLIT
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE3L1X

    LDA IMAGEW
    ASL
    STA MATHPTR5

    SEC
    LDA PLOTDEST
    SBC MATHPTR5
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1

    SEC
    LDA BLITTMPPTR
    SBC MATHPTR5
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    SBC #0
    STA BLITTMPPTR+1

    SEC
    LDA BLITTMPPTR2
    SBC MATHPTR5
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    SBC #0
    STA BLITTMPPTR2+1
    
    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE3L1XN

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE3L1XN0

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
    JMP BLITIMAGE3L1X

BLITIMAGE3L1XN0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE3L1XN:


BLITIMAGE3L1F:
    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$1
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ BLITIMAGE3C

    LDA IMAGEW
    ASL
    TAY
    DEY
    JMP BLITIMAGE3L1

BLITIMAGE3C:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    LSR A
    LSR A
    STA IMAGEW
    TAY
    DEY
BLITIMAGE3L2:
    ; LDA (PLOTCDEST),Y
    ; STA BLITS0
    LDA (BLITTMPPTR),Y
    ; STA BLITS1
    ; LDA (BLITTMPPTR2),Y
    ; STA BLITS2
    ; JSR BLITIMAGEBLIT
    STA (PLOTCDEST),Y
BLITIMAGE3L2FINAL:
    DEY
    CPY #255
    BNE BLITIMAGE3L2

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE3L2N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE3L2N0

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
    JMP BLITIMAGE3L2

BLITIMAGE3L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE3L2N:

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

    CLC
    LDA PLOTCDEST
    ADC #40
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    DEC IMAGEH
    BEQ BLITIMAGE3C2

    LDA IMAGEW
    TAY
    DEY
    JMP BLITIMAGE3L2
BLITIMAGE3C2:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
BLITIMAGE3C2L2:
BLITIMAGE3C2L2DEF:
    ; LDA (PLOTC2DEST),Y
    ; STA BLITS0
    LDA (BLITTMPPTR),Y
    ; STA BLITS1
    ; LDA (BLITTMPPTR2),Y
    ; STA BLITS2
    ; jsr BLITIMAGEBLIT
    STA (PLOTC2DEST),Y
BLITIMAGE3C2L2FINAL:
    DEY
    CPY #255
    BNE BLITIMAGE3C2L2

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGE3C2L2N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGE3C2L2N0

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
    JMP BLITIMAGE3C2L2

BLITIMAGE3C2L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGE3C2L2N:

    CLC
    LDA BLITTMPPTR
    ADC IMAGEW
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    ADC #0
    STA BLITTMPPTR+1

    CLC
    LDA BLITTMPPTR2
    ADC IMAGEW
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    ADC #0
    STA BLITTMPPTR2+1

    CLC
    LDA PLOTC2DEST
    ADC #40
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    DEC IMAGEH
    BEQ BLITIMAGE3E

    LDA IMAGEW
    TAY
    DEY
    JMP BLITIMAGE3C2L2

BLITIMAGE3E:

    SEC
    LDA BLITTMPPTR
    SBC #1
    STA BLITTMPPTR
    LDA BLITTMPPTR+1
    SBC #0
    STA BLITTMPPTR+1

    SEC
    LDA BLITTMPPTR2
    SBC #1
    STA BLITTMPPTR2
    LDA BLITTMPPTR2+1
    SBC #0
    STA BLITTMPPTR2+1

    LDA IMAGET
    AND #2
    CMP #2
    BNE BLITIMAGE3EFINAL
    
    LDY #0
    LDA (BLITTMPPTR),Y
    LSR
    LSR
    LSR
    LSR
    STA $D021

BLITIMAGE3EFINAL:
    RTS

@ENDIF
