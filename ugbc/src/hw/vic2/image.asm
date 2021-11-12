; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

IMAGEX = $34
IMAGEY = $36
IMAGEW = $32
IMAGEH = $33
IMAGEH2 = $31
IMAGET = $30

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

PUTIMAGE:
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

PUTIMAGE0:
    LDY #2
    LDA (TMPPTR),Y
    STA MATHPTR2
PUTIMAGE02C:
    LDA (TMPPTR),Y
    AND #$7F
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
    RTS


PUTIMAGE1:
PUTIMAGE4:
    RTS

PUTIMAGE2:
    LDY #0
    LDA (TMPPTR),Y
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
    
    JSR PUTIMAGEWAITLINE

    LDA IMAGEW
    TAY
    DEY
PUTIMAGE2L1:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE2L1

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
    BEQ PUTIMAGE2C

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGE2L1

PUTIMAGE2C:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    LSR A
    LSR A
    LSR A
    STA IMAGEW
    TAY
    DEY
PUTIMAGE2L2:
    LDA (TMPPTR),Y
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE2L2

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

PUTIMAGE2E:
    RTS

;;;;;;;;;;;;;;;;;

PUTIMAGE3:
    LDY #0
    LDA (TMPPTR),Y
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
    BEQ PUTIMAGE3L1DEF
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
PUTIMAGE3L1DEF:
    LDA (TMPPTR),Y
PUTIMAGE3L1FINAL:
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGE3L1

    TXA
    BEQ PUTIMAGE3L1F

    LDA #$FF
    TAY
    DEY
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
    LDA (TMPPTR),Y
    STA (PLOTCDEST),Y
PUTIMAGE3L2D:
    DEY
    CPY #255
    BNE PUTIMAGE3L2

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

    LDY #0
    LDA (TMPPTR),Y
    STA $D021

    RTS

PUTIMAGEWAITLINE:
    CMP $D012
    BCS PUTIMAGEWAITLINE
    RTS