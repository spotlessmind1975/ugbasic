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
;*                          CLS BOXED ROUTINE FOR TED                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

CLSBOX:

    LDA IMAGEY
    STA IMAGEY2

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

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 1 ) || ( currentMode == 4 ) )

CLSBOX0:
CLSBOX1:
CLSBOX4:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 )  )

CLSBOX2:
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

    LDY #0
    LDA #0
CLSBOX2L1:
    STA (PLOTDEST),Y
    INY
    CPY IMAGEW
    BNE CLSBOX2L1

    LDA IMAGEW+1
    BNE CLSBOX2L1XXY
    JMP CLSBOX2L1XX
    
CLSBOX2L1XXY:
    CLC
    LDA PLOTDEST
    ADC IMAGEW
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDY #0
    LDA #0
CLSBOX2L1B:
CLSBOX3L1DEF:
CLSBOX3L1FINALY:
    STA (PLOTDEST),Y
    INY
    BNE CLSBOX2L1B

    SEC
    LDA PLOTDEST
    SBC IMAGEW
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1

CLSBOX2L1XX:

    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$1
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ CLSBOX2C

    LDY #0
    LDA #0
    JMP CLSBOX2L1

CLSBOX2C:

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

    DEC IMAGEH
    BEQ CLSBOX2C2

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
    LDA #0
    JMP CLSBOX2L2

CLSBOX2C2:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    DEY
    LDA #$fe
CLSBOX2L22:
    STA (PLOTC2DEST),Y
    DEY
    CPY #255
    BNE CLSBOX2L22

    CLC
    LDA PLOTC2DEST
    ADC #40
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    DEC IMAGEH
    BEQ CLSBOX2E

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
    LDA #0
    JMP CLSBOX2L22

CLSBOX2E:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 )  )

CLSBOX3:
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
    BCC CLSBOX3L1U
    LDX #1
CLSBOX3L1U:
    TAY
    DEY
    LDA #0
CLSBOX3L1:
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE CLSBOX3L1

    TXA
    BNE CLSBOX3L1FX
    JMP CLSBOX3L1F

CLSBOX3L1FX:

    LDA IMAGEW
    ASL
    CLC
    ADC PLOTDEST
    STA PLOTDEST
    LDA #0
    ADC PLOTDEST+1
    STA PLOTDEST+1

    LDA #$FF
    TAY
    LDA #0
CLSBOX3L1X:
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE CLSBOX3L1X

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

CLSBOX3L1F:
    CLC
    LDA PLOTDEST
    ADC #$40
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #$1
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ CLSBOX3C

    LDA IMAGEW
    ASL
    TAY
    DEY
    LDA #0
    JMP CLSBOX3L1

CLSBOX3C:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    LSR A
    LSR A
    STA IMAGEW
    TAY
    DEY
    LDA #0
CLSBOX3L2:
    STA (PLOTCDEST),Y
    DEY
    CPY #255
    BNE CLSBOX3L2

    CLC
    LDA PLOTCDEST
    ADC #40
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    DEC IMAGEH
    BEQ CLSBOX3C2

    LDA IMAGEW
    TAY
    DEY
    LDA #0
    JMP CLSBOX3L2

CLSBOX3C2:

    LDA IMAGEH2
    STA IMAGEH
    LDA IMAGEW
    TAY
    LDA #0
CLSBOX3C2L2:
    STA (PLOTC2DEST),Y
    DEY
    CPY #255
    BNE CLSBOX3C2L2

    CLC
    LDA PLOTC2DEST
    ADC #40
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    DEC IMAGEH
    BEQ CLSBOX3E

    LDA IMAGEW
    TAY
    DEY
    LDA #0
    JMP CLSBOX3C2L2
@ENDIF

CLSBOX3E:

    RTS
