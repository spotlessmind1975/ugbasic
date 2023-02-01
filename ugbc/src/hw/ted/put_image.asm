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
;*                          IMAGES ROUTINE FOR TED                             *
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

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 1 ) || ( currentMode == 4 ) )

PUTIMAGE0:
PUTIMAGE1:
PUTIMAGE4:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 )  )

PUTIMAGE2:
    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LDY #2
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

    SEC
    LDA PLOTCDEST
    SBC #$0
    STA PLOTC2DEST
    LDA PLOTCDEST+1
    SBC #$04
    STA PLOTC2DEST+1

    TYA
    JSR PUTIMAGEWAITLINE

    LDY #0
PUTIMAGE2L1:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    INY
    CPY IMAGEW
    BNE PUTIMAGE2L1

    LDA IMAGEW+1
    BNE PUTIMAGE2L1XXY
    JMP PUTIMAGE2L1XX
    
PUTIMAGE2L1XXY:
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
    LDA IMAGET
    BEQ PUTIMAGE3L1DEF
    LDA #0
    STA MATHPTR5
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$C0
    ; -> 00 00 00 00
    BEQ PUTIMAGE3L1P4Y
    LDA MATHPTR5
    ORA #$C0
    STA MATHPTR5
PUTIMAGE3L1P4Y:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$30
    ; -> 00 01 00 00
    BEQ PUTIMAGE3L1P3Y
    LDA MATHPTR5
    ORA #$30
    ; MATH PTR = 00 11 00 00
    STA MATHPTR5
PUTIMAGE3L1P3Y:
    LDA (TMPPTR),Y
    ; 00 01 10 00
    AND #$0C
    ; -> 00 00 10 00
    BEQ PUTIMAGE3L1P2Y
    LDA MATHPTR5
    ORA #$0C
    ; -> 00 11 11 00
    STA MATHPTR5
PUTIMAGE3L1P2Y:
    LDA (TMPPTR),Y
    AND #$03
    BEQ PUTIMAGE3L1P1Y
    LDA MATHPTR5
    ORA #$03
    STA MATHPTR5
PUTIMAGE3L1P1Y:
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
    JMP PUTIMAGE3L1FINALY
PUTIMAGE3L1DEF:
    LDA (TMPPTR),Y
PUTIMAGE3L1FINALY:
    STA (PLOTDEST),Y
    INY
    BNE PUTIMAGE2L1B

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

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE2L1N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE2L1N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDY #0
    JMP PUTIMAGE2L1

PUTIMAGE2L1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE2L1N:

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC IMAGEW+1
    STA TMPPTR+1

    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$1
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ PUTIMAGE2C

    LDY #0
    JMP PUTIMAGE2L1

PUTIMAGE2C:

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
    ADC #40
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
    BEQ PUTIMAGE2C2

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
    JMP PUTIMAGE2L2

PUTIMAGE2C2:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    DEY
PUTIMAGE2L22:
    LDA #$fe
    STA (PLOTC2DEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE2L22

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE2L2N2

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE2L2N022

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTC2DEST
    ADC #40
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE2L22

PUTIMAGE2L2N022:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE2L2N2:

    DEC IMAGEH
    BEQ PUTIMAGE2E

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTC2DEST
    ADC #40
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE2L22

PUTIMAGE2E:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 )  )

PUTIMAGE3:
    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LDY #2
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

    LDX #0
    LDA IMAGEW
    ASL
    BCC PUTIMAGE3L1U
    LDX #1
PUTIMAGE3L1U:
    TAY
    DEY
PUTIMAGE3L1:
    LDA IMAGET
    BEQ PUTIMAGE3L1DEFY
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
PUTIMAGE3L1DEFY:
    LDA (TMPPTR),Y
PUTIMAGE3L1FINAL:
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE3L1

    TXA
    BNE PUTIMAGE3L1FX
    JMP PUTIMAGE3L1F

PUTIMAGE3L1FX:

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
    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1

    LDA #$FF
    TAY
PUTIMAGE3L1X:
    LDA IMAGET
    BEQ PUTIMAGE3L1DEFX
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
PUTIMAGE3L1DEFX:
    LDA (TMPPTR),Y
PUTIMAGE3L1FINALX:
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE3L1X

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
    LDA TMPPTR
    SBC MATHPTR5
    STA TMPPTR
    LDA TMPPTR+1
    SBC #0
    STA TMPPTR+1

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE3L1XN

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE3L1XN0

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
    JMP PUTIMAGE3L1X

PUTIMAGE3L1XN0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE3L1XN:


PUTIMAGE3L1F:
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

    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$1
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ PUTIMAGE3C

    LDA IMAGEW
    ASL
    TAY
    DEY
    JMP PUTIMAGE3L1

PUTIMAGE3C:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    LSR A
    LSR A
    STA IMAGEW
    TAY
    DEY
PUTIMAGE3L2:
    LDA IMAGET
    BEQ PUTIMAGE3L2DEF
    LDA (PLOTCDEST),Y
    AND #$F0
    STA (PLOTCDEST),Y
    LDA (TMPPTR),Y
    AND #$0F
    ORA (PLOTCDEST),Y
    STA (PLOTCDEST),Y
    JMP PUTIMAGE3L2FINAL
PUTIMAGE3L2DEF:
    LDA (TMPPTR),Y
    STA (PLOTCDEST),Y
PUTIMAGE3L2FINAL:
    DEY
    CPY #255
    BNE PUTIMAGE3L2

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE3L2N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE3L2N0

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
    JMP PUTIMAGE3L2

PUTIMAGE3L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE3L2N:

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

    DEC IMAGEH
    BEQ PUTIMAGE3C2

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE3L2
PUTIMAGE3C2:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
PUTIMAGE3C2L2:
    LDA (TMPPTR),Y
    STA (PLOTC2DEST),Y
PUTIMAGE3C2L2D:
    DEY
    CPY #255
    BNE PUTIMAGE3C2L2

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGE3C2L2N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGE3C2L2N0

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
    JMP PUTIMAGE3C2L2

PUTIMAGE3C2L2N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGE3C2L2N:

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTC2DEST
    ADC #40
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    DEC IMAGEH
    BEQ PUTIMAGE3E

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE3C2L2

PUTIMAGE3E:

    SEC
    LDA TMPPTR
    SBC #1
    STA TMPPTR
    LDA TMPPTR+1
    SBC #0
    STA TMPPTR+1

    LDY #0
    LDA (TMPPTR),Y
    STA $FF15
    LDY #1
    LDA (TMPPTR),Y
    STA $FF16

@ENDIF

    RTS

PUTIMAGEWAITLINE:
    CMP $FF1D
    BCS PUTIMAGEWAITLINE
    RTS
