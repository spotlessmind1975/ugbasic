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
;*                          IMAGES ROUTINE FOR VIC-I                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BLITIMAGEBLITADDR:
BLITIMAGEBLIT:
    JMP $0000

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

BLITIMAGE:
;     LDA CURRENTMODE
;     ; BITMAP_MODE_STANDARD
;     CMP #2
;     BNE BLITIMAGE2X
;     JMP BLITIMAGE2
; BLITIMAGE2X:
;     ; BITMAP_MODE_MULTICOLOR
;     CMP #3
;     BNE BLITIMAGE3X
;     JMP BLITIMAGE3
; BLITIMAGE3X:
;     ; TILEMAP_MODE_STANDARD
;     CMP #0
;     BNE BLITIMAGE0X
;     JMP BLITIMAGE0
; BLITIMAGE0X:
;     ; TILEMAP_MODE_MULTICOLOR
;     CMP #1
;     BNE BLITIMAGE1X
;     JMP BLITIMAGE1
; BLITIMAGE1X:
;     ; TILEMAP_MODE_EXTENDED
;     CMP #4
;     BNE BLITIMAGE4X
;     JMP BLITIMAGE4
; BLITIMAGE4X:
;     RTS

BLITIMAGE0:
    LDY #2
    LDA (BLITTMPPTR),Y
    STA MATHPTR2
BLITIMAGE02C:
    LDY #0
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
    ADC #22
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$0
    STA PLOTDEST+1

    DEC IMAGEH
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
    ADC #22
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
    LDA (BLITTMPPTR),Y
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE BLITIMAGE016L2

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
    ADC #22
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

; BLITIMAGE0:
; BLITIMAGE1:
; BLITIMAGE4:
;     RTS

; BLITIMAGE2:
;     LDY #0
;     LDA (BLITTMPPTR),Y
;     STA IMAGEW
;     LDY #1
;     LDA (BLITTMPPTR),Y
;     LSR
;     LSR
;     LSR
;     STA IMAGEH
;     STA IMAGEH2

;     CLC
;     LDA BLITTMPPTR
;     ADC #2
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

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
    
;     JSR BLITIMAGEWAITLINE

;     LDA IMAGEW
;     TAY
;     DEY
; BLITIMAGE2L1:
;     LDA (BLITTMPPTR),Y
;     STA (PLOTDEST),Y
;     DEY
;     CPY #255
;     BNE BLITIMAGE2L1

;     CLC
;     LDA BLITTMPPTR
;     ADC IMAGEW
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

;     CLC
;     LDA PLOTDEST
;     ADC #$40
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #$1
;     STA PLOTDEST+1

;     DEC IMAGEH
;     BEQ BLITIMAGE2C

;     LDA IMAGEW
;     TAY
;     DEY
;     JMP BLITIMAGE2L1

; BLITIMAGE2C:

;     LDA IMAGEH2
;     STA IMAGEH
;     LDA IMAGEW
;     LSR A
;     LSR A
;     LSR A
;     STA IMAGEW
;     TAY
;     DEY
; BLITIMAGE2L2:
;     LDA (BLITTMPPTR),Y
;     STA (PLOTCDEST),Y
;     DEY
;     CPY #255
;     BNE BLITIMAGE2L2

;     DEC IMAGEH
;     BEQ BLITIMAGE2E

;     CLC
;     LDA BLITTMPPTR
;     ADC IMAGEW
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

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
;     JMP BLITIMAGE2L2

; BLITIMAGE2E:
;     RTS

; ;;;;;;;;;;;;;;;;;

; BLITIMAGE3:
;     LDY #0
;     LDA (BLITTMPPTR),Y
;     STA IMAGEW
;     LDY #1
;     LDA (BLITTMPPTR),Y
;     LSR
;     LSR
;     LSR
;     STA IMAGEH
;     STA IMAGEH2

;     CLC
;     LDA BLITTMPPTR
;     ADC #2
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

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
; BLITIMAGE3L1:
;     LDA (BLITTMPPTR),Y
;     STA (PLOTDEST),Y
;     DEY
;     CPY #255
;     BNE BLITIMAGE3L1

;     CLC
;     LDA BLITTMPPTR
;     ADC IMAGEW
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

;     CLC
;     LDA BLITTMPPTR
;     ADC IMAGEW
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

;     CLC
;     LDA PLOTDEST
;     ADC #$40
;     STA PLOTDEST
;     LDA PLOTDEST+1
;     ADC #$1
;     STA PLOTDEST+1

;     DEC IMAGEH
;     BEQ BLITIMAGE3C

;     LDA IMAGEW
;     ASL
;     TAY
;     DEY
;     JMP BLITIMAGE3L1

; BLITIMAGE3C:

;     LDA IMAGEH2
;     STA IMAGEH
;     LDA IMAGEW
;     LSR A
;     LSR A
;     STA IMAGEW
;     TAY
;     DEY
; BLITIMAGE3L2:
;     LDA (BLITTMPPTR),Y
;     STA (PLOTCDEST),Y
;     DEY
;     CPY #255
;     BNE BLITIMAGE3L2

;     DEC IMAGEH
;     BEQ BLITIMAGE3C2

;     CLC
;     LDA BLITTMPPTR
;     ADC IMAGEW
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

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
;     JMP BLITIMAGE3L2
; BLITIMAGE3C2:

;     LDA IMAGEH2
;     STA IMAGEH
;     LDA IMAGEW
;     TAY
; BLITIMAGE3C2L2:
;     LDA (BLITTMPPTR),Y
;     STA (PLOTC2DEST),Y
;     DEY
;     CPY #255
;     BNE BLITIMAGE3C2L2

;     DEC IMAGEH
;     BEQ BLITIMAGE3E

;     CLC
;     LDA BLITTMPPTR
;     ADC IMAGEW
;     STA BLITTMPPTR
;     LDA BLITTMPPTR+1
;     ADC #0
;     STA BLITTMPPTR+1

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
;     JMP BLITIMAGE3C2L2

; BLITIMAGE3E:
;     LDY #0
;     LDA (BLITTMPPTR),Y
;     STA $D021

;     RTS

; BLITIMAGEWAITLINE:
;     CMP $D012
;     BCS BLITIMAGEWAITLINE
    RTS