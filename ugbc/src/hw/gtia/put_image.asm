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
;*                          IMAGES ROUTINE FOR GTIA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

PUTIMAGE:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE PUTIMAGE8X
    JMP PUTIMAGE8
PUTIMAGE8X:
    CMP #9
    BNE PUTIMAGE9X
    JMP PUTIMAGE9
PUTIMAGE9X:
    CMP #10
    BNE PUTIMAGE10X
    JMP PUTIMAGE10
PUTIMAGE10X:
    CMP #11
    BNE PUTIMAGE11X
    JMP PUTIMAGE11
PUTIMAGE11X:
    CMP #13
    BNE PUTIMAGE13X
    JMP PUTIMAGE13
PUTIMAGE13X:
    CMP #15
    BNE PUTIMAGE15X
    JMP PUTIMAGE15
PUTIMAGE15X:
    CMP #12
    BNE PUTIMAGE12X
    JMP PUTIMAGE12
PUTIMAGE12X:
    CMP #14
    BNE PUTIMAGE14X
    JMP PUTIMAGE14
PUTIMAGE14X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

PUTIMAGE9:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT4VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

PUTIMAGE11:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

PUTIMAGE15:

    LDA IMAGEX
    ROR IMAGEX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT6XVBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT6XVBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

PUTIMAGE12:

    LDA IMAGEX
    ROR IMAGEX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

PUTIMAGE8:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    ADC PLOT4LO,X              ;+ (4 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOT4VBASEHI,Y          ;do the high byte
    ADC PLOT4HI,X
    STA PLOTDEST+1

    JMP PUTIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

PUTIMAGE10:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

PUTIMAGE13:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT6VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT6VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

PUTIMAGE14:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA IMAGEY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP PUTIMAGECOMMONC

@ENDIF

PUTIMAGECOMMON:
    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (TMPPTR),Y
    STA IMAGEH
    STA IMAGEH2

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    LDA IMAGEW
    TAY
    DEY
PUTIMAGECOMMONL1:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    DEY
    CPY #255
    BNE PUTIMAGECOMMONL1

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGECOMMONL1N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGECOMMONL1N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGECOMMONL1

PUTIMAGECOMMONL1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGECOMMONL1N:

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    CLC
    LDA PLOTDEST
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ PUTIMAGECOMMON3

    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGECOMMON3A

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGECOMMONL1

PUTIMAGECOMMON3A:

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1
    DEC IMAGEH
    BEQ PUTIMAGECOMMON3A

PUTIMAGECOMMON3:

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    LDA CURRENTMODE
    CMP #9
    BNE PUTIMAGECOMMON3M9X
    JMP PUTIMAGECOMMON3M9
PUTIMAGECOMMON3M9X:
    CMP #11
    BNE PUTIMAGECOMMON3M11X
    JMP PUTIMAGECOMMON3M11
PUTIMAGECOMMON3M11X:
    CMP #15
    BNE PUTIMAGECOMMON3M15X
    JMP PUTIMAGECOMMON3M15
PUTIMAGECOMMON3M15X:
    CMP #12
    BNE PUTIMAGECOMMON3M12X
    JMP PUTIMAGECOMMON3M12
PUTIMAGECOMMON3M12X:
    RTS

PUTIMAGECOMMON3M9:
PUTIMAGECOMMON3M11:
PUTIMAGECOMMON3M12:
    LDA IMAGET
    AND #2
    CMP #2
    BNE PUTIMAGECOMMONC0E

    LDY #0
@INLINE PALETTEPRESERVE2C8 [(TMPPTR),Y], [#$0]
    LDY #1
@INLINE PALETTEPRESERVE2C5 [(TMPPTR),Y], [#$0]

PUTIMAGECOMMONC0E:

    JMP PUTIMAGECOMMONE

PUTIMAGECOMMON3M15:

    LDA IMAGET
    AND #2
    CMP #2
    BNE PUTIMAGECOMMON3M15E

    LDY #0
@INLINE PALETTEPRESERVE2C8 [(TMPPTR),Y], [#$0]
    LDY #1
@INLINE PALETTEPRESERVE2C6 [(TMPPTR),Y], [#$0]
    LDY #2
@INLINE PALETTEPRESERVE2C5 [(TMPPTR),Y], [#$0]

PUTIMAGECOMMON3M15E:

    JMP PUTIMAGECOMMONE

PUTIMAGECOMMONE:
    RTS

;;;;;;;;;;;;;;;;;

PUTIMAGECOMMONC:

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (TMPPTR),Y
    STA IMAGEH
    STA IMAGEH2

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    LDA IMAGEW
    ASL
    TAY
    DEY
PUTIMAGECOMMONCL1:
    LDA IMAGEF
    AND #32
    CMP #32
    BNE PUTIMAGE3L1DEFX
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
    BNE PUTIMAGECOMMONCL1

    LDA IMAGEF
    AND #64
    BEQ PUTIMAGECOMMONCL1N

    LDA IMAGEF
    AND #1
    BNE PUTIMAGECOMMONCL1N0

    ORA #65
    STA IMAGEF

    CLC
    LDA PLOTDEST
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDA IMAGEW
    TAY
    DEY
    JMP PUTIMAGECOMMONCL1

PUTIMAGECOMMONCL1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

PUTIMAGECOMMONCL1N:

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
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ PUTIMAGECOMMONCC

    INC IMAGEY
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BEQ PUTIMAGECOMMONCCA

    LDA IMAGEW
    ASL
    TAY
    DEY
    JMP PUTIMAGECOMMONCL1

PUTIMAGECOMMONCCA:

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

    DEC IMAGEH
    BEQ PUTIMAGECOMMONCCA

PUTIMAGECOMMONCC:

    LDA CURRENTMODE
    CMP #10
    BNE PUTIMAGECOMMON3M10X
    JMP PUTIMAGECOMMON3M10
PUTIMAGECOMMON3M10X:
    CMP #8
    BNE PUTIMAGECOMMON3M8X
    JMP PUTIMAGECOMMON3M8
PUTIMAGECOMMON3M8X:
    CMP #13
    BNE PUTIMAGECOMMON3M13X
    JMP PUTIMAGECOMMON3M13
PUTIMAGECOMMON3M13X:
    CMP #14
    BNE PUTIMAGECOMMON3M14X
    JMP PUTIMAGECOMMON3M14
PUTIMAGECOMMON3M14X:
    RTS

PUTIMAGECOMMON3M10:
PUTIMAGECOMMON3M8:
PUTIMAGECOMMON3M13:
PUTIMAGECOMMON3M14:

    LDA IMAGET
    AND #2
    CMP #2
	BEQ PUTIMAGECOMMON3M14EX
	JMP PUTIMAGECOMMON3M14E
PUTIMAGECOMMON3M14EX:

    LDA IMAGEF
    AND #32
    CMP #32
    BEQ PUTIMAGECOMMON3M1NDEF

    LDY #0
@INLINE PALETTEPRESERVE2C8 [(TMPPTR),Y], [#$0]
PUTIMAGECOMMON3M1NDEF:
    LDY #1
    LDA (TMPPTR),Y
    CMP #$FF
    BEQ PUTIMAGECOMMON3M1NDEF1
@INLINE PALETTEPRESERVE2C4 [(TMPPTR),Y], [#$0]
PUTIMAGECOMMON3M1NDEF1:
    LDY #2
    LDA (TMPPTR),Y
    CMP #$FF
    BEQ PUTIMAGECOMMON3M1NDEF2
@INLINE PALETTEPRESERVE2C6 [(TMPPTR),Y], [#$0]
PUTIMAGECOMMON3M1NDEF2:
    LDY #3
    LDA (TMPPTR),Y
    CMP #$FF
    BEQ PUTIMAGECOMMON3M1NDEF3
@INLINE PALETTEPRESERVE2C5 [(TMPPTR),Y], [#$0]
PUTIMAGECOMMON3M1NDEF3:
    JMP PUTIMAGECOMMONCE

PUTIMAGECOMMON3M14E:
PUTIMAGECOMMONCE:
    RTS
