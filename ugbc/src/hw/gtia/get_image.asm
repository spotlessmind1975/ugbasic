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

GETIMAGE:
    LDA IMAGEY
    CMP CURRENTHEIGHT
    BCC GETIMAGEHY
    RTS
GETIMAGEHY:
    LDA IMAGEX
    CMP CURRENTWIDTH
    BCC GETIMAGEHX
    RTS
GETIMAGEHX:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE GETIMAGE8X
    JMP GETIMAGE8
GETIMAGE8X:
    CMP #9
    BNE GETIMAGE9X
    JMP GETIMAGE9
GETIMAGE9X:
    CMP #10
    BNE GETIMAGE10X
    JMP GETIMAGE10
GETIMAGE10X:
    CMP #11
    BNE GETIMAGE11X
    JMP GETIMAGE11
GETIMAGE11X:
    CMP #13
    BNE GETIMAGE13X
    JMP GETIMAGE13
GETIMAGE13X:
    CMP #15
    BNE GETIMAGE15X
    JMP GETIMAGE15
GETIMAGE15X:
    CMP #12
    BNE GETIMAGE12X
    JMP GETIMAGE12
GETIMAGE12X:
    CMP #14
    BNE GETIMAGE14X
    JMP GETIMAGE14
GETIMAGE14X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

GETIMAGE9:

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

    JMP GETIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

GETIMAGE11:

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

    JMP GETIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

GETIMAGE15:

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

    JMP GETIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

GETIMAGE12:

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

    JMP GETIMAGECOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

GETIMAGE8:

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

    JMP GETIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

GETIMAGE10:

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

    JMP GETIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

GETIMAGE13:

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

    JMP GETIMAGECOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

GETIMAGE14:

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

    JMP GETIMAGECOMMONC

@ENDIF

GETIMAGECOMMON:
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
GETIMAGECOMMONL1:
    LDA (PLOTDEST),Y
    STA (TMPPTR),Y
    DEY
    CPY #255
    BNE GETIMAGECOMMONL1

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
    BEQ GETIMAGECOMMON3

    LDA IMAGEW
    TAY
    DEY
    JMP GETIMAGECOMMONL1

GETIMAGECOMMON3:

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    LDA CURRENTMODE
    CMP #9
    BNE GETIMAGECOMMON3M9X
    JMP GETIMAGECOMMON3M9
GETIMAGECOMMON3M9X:
    CMP #11
    BNE GETIMAGECOMMON3M11X
    JMP GETIMAGECOMMON3M11
GETIMAGECOMMON3M11X:
    CMP #15
    BNE GETIMAGECOMMON3M15X
    JMP GETIMAGECOMMON3M15
GETIMAGECOMMON3M15X:
    CMP #12
    BNE GETIMAGECOMMON3M12X
    JMP GETIMAGECOMMON3M12
GETIMAGECOMMON3M12X:
    RTS

GETIMAGECOMMON3M9:
GETIMAGECOMMON3M11:
GETIMAGECOMMON3M12:
    LDA IMAGET
    BNE GETIMAGECOMMONEX
    JMP GETIMAGECOMMONE
GETIMAGECOMMONEX:
    LDA $2C8
    LDY #0
    STA (TMPPTR),Y
    LDA $2C5
    LDY #1
    STA (TMPPTR),Y

    JMP GETIMAGECOMMONE

GETIMAGECOMMON3M15:
    LDA IMAGET
    BNE GETIMAGECOMMONEX2
    JMP GETIMAGECOMMONE
GETIMAGECOMMONEX2:
    LDA $2C8
    LDY #0
    STA (TMPPTR),Y
    LDA $2C6
    LDY #1
    STA (TMPPTR),Y
    LDA $2C5
    LDY #2
    STA (TMPPTR),Y
    JMP GETIMAGECOMMONE

GETIMAGECOMMONE:
    RTS

;;;;;;;;;;;;;;;;;

GETIMAGECOMMONC:

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
GETIMAGECOMMONCL1:
GETIMAGE3L1DEFX:
    LDA (PLOTDEST),Y
GETIMAGE3L1FINALX:
    STA (TMPPTR),Y
    DEY
    CPY #255
    BNE GETIMAGECOMMONCL1

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
    BEQ GETIMAGECOMMONCC

    LDA IMAGEW
    ASL
    TAY
    DEY
    JMP GETIMAGECOMMONCL1

GETIMAGECOMMONCC:

    LDA CURRENTMODE
    CMP #10
    BNE GETIMAGECOMMON3M10X
    JMP GETIMAGECOMMON3M10
GETIMAGECOMMON3M10X:
    CMP #8
    BNE GETIMAGECOMMON3M8X
    JMP GETIMAGECOMMON3M8
GETIMAGECOMMON3M8X:
    CMP #13
    BNE GETIMAGECOMMON3M13X
    JMP GETIMAGECOMMON3M13
GETIMAGECOMMON3M13X:
    CMP #14
    BNE GETIMAGECOMMON3M14X
    JMP GETIMAGECOMMON3M14
GETIMAGECOMMON3M14X:
    RTS

GETIMAGECOMMON3M10:
GETIMAGECOMMON3M8:
GETIMAGECOMMON3M13:
GETIMAGECOMMON3M14:
    LDA IMAGET
    BNE GETIMAGECOMMONEX3
    JMP GETIMAGECOMMONE
GETIMAGECOMMONEX3:
    LDA $2C8
    LDY #0
    STA (TMPPTR),Y
    LDY #1
    LDA $2C4
    STA (TMPPTR),Y
    LDY #2
    LDA $2C6
    STA (TMPPTR),Y
    LDY #3
    LDA $2C5
    STA (TMPPTR),Y

    JMP GETIMAGECOMMONCE

GETIMAGECOMMONCE:
    RTS
