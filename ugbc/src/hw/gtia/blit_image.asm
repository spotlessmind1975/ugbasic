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

BLITIMAGEBLITADDR:  .WORD $0

BLITIMAGEBLIT:
    JMP  (BLITIMAGEBLITADDR) 

BLITIMAGE:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE BLITIMAGE8X
    JMP BLITIMAGE8
BLITIMAGE8X:
    CMP #9
    BNE BLITIMAGE9X
    JMP BLITIMAGE9
BLITIMAGE9X:
    CMP #10
    BNE BLITIMAGE10X
    JMP BLITIMAGE10
BLITIMAGE10X:
    CMP #11
    BNE BLITIMAGE11X
    JMP BLITIMAGE11
BLITIMAGE11X:
    CMP #13
    BNE BLITIMAGE13X
    JMP BLITIMAGE13
BLITIMAGE13X:
    CMP #15
    BNE BLITIMAGE15X
    JMP BLITIMAGE15
BLITIMAGE15X:
    CMP #12
    BNE BLITIMAGE12X
    JMP BLITIMAGE12
BLITIMAGE12X:
    CMP #14
    BNE BLITIMAGE14X
    JMP BLITIMAGE14
BLITIMAGE14X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

BLITIMAGE9:

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

    JMP BLITIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

BLITIMAGE11:

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

    JMP BLITIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

BLITIMAGE15:

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
    ADC PLOT6VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT6VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    JMP BLITIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

BLITIMAGE12:

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

    JMP BLITIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

BLITIMAGE8:

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

    JMP BLITIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

BLITIMAGE10:

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

    JMP BLITIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

BLITIMAGE13:

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

    JMP BLITIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

BLITIMAGE14:

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

    JMP BLITIMAGECOMMONC

@ENDIF

BLITIMAGECOMMON:
    LDY #0
    LDA (BLITTMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (BLITTMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (BLITTMPPTR),Y
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

    LDA IMAGEW
    TAY
    DEY
BLITIMAGECOMMONL1:
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
    BNE BLITIMAGECOMMONL1

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGECOMMONL1N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGECOMMONL1N0

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
    JMP BLITIMAGECOMMONL1

BLITIMAGECOMMONL1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGECOMMONL1N:

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
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ BLITIMAGECOMMON3

    LDA IMAGEW
    TAY
    DEY
    JMP BLITIMAGECOMMONL1

BLITIMAGECOMMON3:

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

    LDA CURRENTMODE
    CMP #9
    BNE BLITIMAGECOMMON3M9X
    JMP BLITIMAGECOMMON3M9
BLITIMAGECOMMON3M9X:
    CMP #11
    BNE BLITIMAGECOMMON3M11X
    JMP BLITIMAGECOMMON3M11
BLITIMAGECOMMON3M11X:
    CMP #15
    BNE BLITIMAGECOMMON3M15X
    JMP BLITIMAGECOMMON3M15
BLITIMAGECOMMON3M15X:
    CMP #12
    BNE BLITIMAGECOMMON3M12X
    JMP BLITIMAGECOMMON3M12
BLITIMAGECOMMON3M12X:
    RTS

BLITIMAGECOMMON3M9:
BLITIMAGECOMMON3M11:
BLITIMAGECOMMON3M12:
    LDA IMAGET
    AND #2
    CMP #2
    BNE BLITIMAGECOMMONC0E

    LDY #0
@INLINE PALETTEPRESERVE2C8 [(BLITTMPPTR),Y], [#$0]
    LDY #1
@INLINE PALETTEPRESERVE2C5 [(BLITTMPPTR),Y], [#$0]

BLITIMAGECOMMONC0E:

    JMP BLITIMAGECOMMONE

BLITIMAGECOMMON3M15:

    LDA IMAGET
    AND #2
    CMP #2
    BNE BLITIMAGECOMMON3M15E

    LDY #0
@INLINE PALETTEPRESERVE2C8 [(BLITTMPPTR),Y], [#$0]
    LDY #1
@INLINE PALETTEPRESERVE2C6 [(BLITTMPPTR),Y], [#$0]
    LDY #2
@INLINE PALETTEPRESERVE2C5 [(BLITTMPPTR),Y], [#$0]

BLITIMAGECOMMON3M15E:

    JMP BLITIMAGECOMMONE

BLITIMAGECOMMONE:
    RTS

;;;;;;;;;;;;;;;;;

BLITIMAGECOMMONC:

    LDY #0
    LDA (BLITTMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (BLITTMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (BLITTMPPTR),Y
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

    LDA IMAGEW
    ASL
    TAY
    DEY
BLITIMAGECOMMONCL1:
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
    BNE BLITIMAGECOMMONCL1

    LDA IMAGEF
    AND #64
    BEQ BLITIMAGECOMMONCL1N

    LDA IMAGEF
    AND #1
    BNE BLITIMAGECOMMONCL1N0

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
    JMP BLITIMAGECOMMONCL1

BLITIMAGECOMMONCL1N0:
    LDA IMAGEF
    AND #$FE
    STA IMAGEF

BLITIMAGECOMMONCL1N:

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
    ADC CURRENTSL
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    DEC IMAGEH
    BEQ BLITIMAGECOMMONCC

    LDA IMAGEW
    ASL
    TAY
    DEY
    JMP BLITIMAGECOMMONCL1

BLITIMAGECOMMONCC:

    LDA CURRENTMODE
    CMP #10
    BNE BLITIMAGECOMMON3M10X
    JMP BLITIMAGECOMMON3M10
BLITIMAGECOMMON3M10X:
    CMP #8
    BNE BLITIMAGECOMMON3M8X
    JMP BLITIMAGECOMMON3M8
BLITIMAGECOMMON3M8X:
    CMP #13
    BNE BLITIMAGECOMMON3M13X
    JMP BLITIMAGECOMMON3M13
BLITIMAGECOMMON3M13X:
    CMP #14
    BNE BLITIMAGECOMMON3M14X
    JMP BLITIMAGECOMMON3M14
BLITIMAGECOMMON3M14X:
    RTS

BLITIMAGECOMMON3M10:
BLITIMAGECOMMON3M8:
BLITIMAGECOMMON3M13:
BLITIMAGECOMMON3M14:

    LDA IMAGET
    AND #2
    CMP #2
	BEQ BLITIMAGECOMMON3M14EX
	JMP BLITIMAGECOMMON3M14E
BLITIMAGECOMMON3M14EX:

    LDA IMAGEF
    AND #32
    CMP #32
    BNE BLITIMAGECOMMON3M1NDEF
    LDY #0
@INLINE PALETTEPRESERVE2C8 [(BLITTMPPTR),Y], [#$0]
BLITIMAGECOMMON3M1NDEF:
    LDY #1
    LDA (BLITTMPPTR),Y
    CMP #$FF
    BEQ BLITIMAGECOMMON3M1NDEF1
@INLINE PALETTEPRESERVE2C4 [(BLITTMPPTR),Y], [#$0]
BLITIMAGECOMMON3M1NDEF1:
    LDY #2
    LDA (BLITTMPPTR),Y
    CMP #$FF
    BEQ BLITIMAGECOMMON3M1NDEF2
@INLINE PALETTEPRESERVE2C5 [(BLITTMPPTR),Y], [#$0]
BLITIMAGECOMMON3M1NDEF2:
    LDY #3
    LDA (BLITTMPPTR),Y
    CMP #$FF
    BEQ BLITIMAGECOMMON3M1NDEF3
@INLINE PALETTEPRESERVE2C6 [(BLITTMPPTR),Y], [#$0]
BLITIMAGECOMMON3M1NDEF3:
    JMP BLITIMAGECOMMONCE

BLITIMAGECOMMON3M14E:
BLITIMAGECOMMONCE:
    RTS
