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
;*                      TEXT AT GIVEN POSITION ON GTIA                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR = $90
TEXTSIZE = $98
TABSTODRAW = $93
SCREENCODE = $97

TEXTAT:
    LDA TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA #0
    STA TABSTODRAW
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDA CURRENTMODE
    CMP #2
    BNE TEXTATANTIC2X
    JMP TEXTATANTIC2
TEXTATANTIC2X:
    CMP #6
    BNE TEXTATANTIC6X
    JMP TEXTATANTIC6
TEXTATANTIC6X:    
    CMP #7
    BNE TEXTATANTIC7X
    JMP TEXTATANTIC7
TEXTATANTIC7X:    
    CMP #3
    BNE TEXTATANTIC3X
    JMP TEXTATANTIC3
TEXTATANTIC3X:    
    CMP #4
    BNE TEXTATANTIC4X
    JMP TEXTATANTIC4
TEXTATANTIC4X:    
    CMP #5
    BNE TEXTATANTIC5X
    JMP TEXTATANTIC5
TEXTATANTIC5X:
    CMP #8
    BNE TEXTATANTIC8X
    JMP TEXTATANTIC8
TEXTATANTIC8X:
    CMP #9
    BNE TEXTATANTIC9X
    JMP TEXTATANTIC9
TEXTATANTIC9X:
    CMP #10
    BNE TEXTATANTIC10X
    JMP TEXTATANTIC10
TEXTATANTIC10X:
    CMP #11
    BNE TEXTATANTIC11X
    JMP TEXTATANTIC11
TEXTATANTIC11X:
    CMP #12
    BNE TEXTATANTIC12X
    JMP TEXTATANTIC12
TEXTATANTIC12X:
    CMP #13
    BNE TEXTATANTIC13X
    JMP TEXTATANTIC13
TEXTATANTIC13X:
    CMP #14
    BNE TEXTATANTIC14X
    JMP TEXTATANTIC14
TEXTATANTIC14X:
    CMP #15
    BNE TEXTATANTIC15X
    JMP TEXTATANTIC15
TEXTATANTIC15X:
    RTS

CALCPOS:
    LDA CURRENTMODE
    CMP #2
    BNE CALCPOS2X
    JMP CALCPOS2
CALCPOS2X:
    CMP #6
    BNE CALCPOS6X
    JMP CALCPOS6
CALCPOS6X:    
    CMP #7
    BNE CALCPOS7X
    JMP CALCPOS7
CALCPOS7X:    
    CMP #3
    BNE CALCPOS3X
    JMP CALCPOS3
CALCPOS3X:    
    CMP #4
    BNE CALCPOS4X
    JMP CALCPOS4
CALCPOS4X:    
    CMP #5
    BNE CALCPOS5X
    JMP CALCPOS5
CALCPOS5X:
    CMP #8
    BNE CALCPOS8X
    JMP CALCPOS8
CALCPOS8X:
    CMP #9
    BNE CALCPOS9X
    JMP CALCPOS9
CALCPOS9X:
    CMP #10
    BNE CALCPOS10X
    JMP CALCPOS10
CALCPOS10X:
    CMP #11
    BNE CALCPOS11X
    JMP CALCPOS11
CALCPOS11X:
    CMP #12
    BNE CALCPOS12X
    JMP CALCPOS12
CALCPOS12X:
    CMP #13
    BNE CALCPOS13X
    JMP CALCPOS13
CALCPOS13X:
    CMP #14
    BNE CALCPOS14X
    JMP CALCPOS14
CALCPOS14X:
    CMP #15
    BNE CALCPOS15X
    JMP CALCPOS15
CALCPOS15X:
    RTS

CALCPOS0:
CALCPOS6:
CALCPOS7:
CALCPOS3:
CALCPOS2:
CALCPOS4:
CALCPOS5:
    LDX YCURSYS
    BEQ CALCPOSSKIP
CALCPOSLOOP1:
    CLC
    LDA CURRENTWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE CALCPOSLOOP1

CALCPOSSKIP:
    CLC
    LDA XCURSYS
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    RTS

CALCPOS8:

    LDA #2
    STA PATTERN

    LDA XCURSYS
    ASL A
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    ; ADC PLOT4LO,X              ;+ (4 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOT4VBASEHI,Y          ;do the high byte
    ; ADC PLOT4HI,X
    STA PLOTDEST+1

    RTS

CALCPOS9:

    LDA #0
    STA PATTERN

    LDA XCURSYS
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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

    RTS

CALCPOS10:

    LDA #2
    STA PATTERN

    LDA XCURSYS
    ASL A
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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

    RTS

CALCPOS11:

    LDA #0
    STA PATTERN

    LDA XCURSYS
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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

    RTS

CALCPOS12:

    LDA #2
    STA PATTERN

    LDA XCURSYS
    ASL A
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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
    
    RTS

CALCPOS13:

    LDA #2
    STA PATTERN

    LDA XCURSYS
    ASL A
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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

    RTS

CALCPOS14:

    LDA #2
    STA PATTERN

    LDA XCURSYS
    ASL A
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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

    RTS

CALCPOS15:

    LDA #0
    STA PATTERN

    LDA XCURSYS
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA YCURSYS
    CLC
    ADC #1
    ASL A
    ASL A
    ASL A
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

    RTS


;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATANTIC8:

    JSR CALCPOS8

    JMP TEXTATBMCOMMON

TEXTATANTIC9:

    JSR CALCPOS9

    JMP TEXTATBMCOMMON

TEXTATANTIC10:

    JSR CALCPOS10

    JMP TEXTATBMCOMMON

TEXTATANTIC11:

    JSR CALCPOS11

    JMP TEXTATBMCOMMON

TEXTATANTIC12:

    JSR CALCPOS12
    
    JMP TEXTATBMCOMMON

TEXTATANTIC13:

    JSR CALCPOS13

    JMP TEXTATBMCOMMON

TEXTATANTIC14:

    JSR CALCPOS14

    JMP TEXTATBMCOMMON

TEXTATANTIC15:

    JSR CALCPOS15

    JMP TEXTATBMCOMMON

TEXTATBMCOMMON:

    LDA TEXTWW
    AND #$2
    BEQ TEXTATBMCNOPEN

    LDA _PEN
    CMP $2C4
    BEQ TEXTATC1
    CMP $2C5
    BEQ TEXTATC2
    CMP $2C6
    BEQ TEXTATC3

    LDA LASTCOLOR
    CMP #1
    BEQ TEXTATC1
    CMP #2
    BEQ TEXTATC2
    CMP #3
    BEQ TEXTATC3

    LDA #2
    STA LASTCOLOR
    JMP TEXTATSC1

TEXTATSC1:
    LDA _PEN
    STA $2C4
    INC LASTCOLOR
TEXTATC1:
    LDA #<TEXTATBMC1
    STA MATHPTR5
    LDA #>TEXTATBMC1
    STA MATHPTR5+1
    JMP TEXTATBMCNOPEN

TEXTATSC2:
    LDA _PEN
    STA $2C5
    INC LASTCOLOR
TEXTATC2:
    LDA #<TEXTATBMC2
    STA MATHPTR5
    LDA #>TEXTATBMC2
    STA MATHPTR5+1
    JMP TEXTATBMCNOPEN

TEXTATSC3:
    LDA _PEN
    STA $2C6
    LDA #1
    STA LASTCOLOR
TEXTATC3:
    LDA #<TEXTATBMC3
    STA MATHPTR5
    LDA #>TEXTATBMC3
    STA MATHPTR5+1
    JMP TEXTATBMCNOPEN

TEXTATBMCNOPEN:

    LDX TEXTSIZE
    LDY #$0
TEXTATBMLOOP2:

    LDA TABSTODRAW
    BEQ TEXTATBMNSKIPTAB
    JMP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB:
    LDA (TEXTPTR),Y
    STA SCREENCODE

    CMP #$7f
    BEQ TEXTATBMTAB
    CMP #10
    BCS TEXTATBMXCC
    JMP TEXTATBMCC

TEXTATBMXCC:
    JSR TEXTATDECODE
    JMP TEXTATBMSP0

TEXTATBMTAB:
    LDA XCURSYS
TEXTATBMTAB2:
    CMP TABCOUNT
    BCC TEXTATBMTAB3
    SEC
    SBC TABCOUNT
    JMP TEXTATBMTAB2
TEXTATBMTAB3:
    STA TMPPTR
    LDA TABCOUNT
    SEC
    SBC TMPPTR
    STA TABSTODRAW
    JMP TEXTATBMNEXT

TEXTATBMCC:
    CMP #13
    BEQ TEXTATBMLF
    CMP #10
    BEQ TEXTATBMLF
    CMP #09
    BEQ TEXTATBMTAB
    CMP #01
    BEQ TEXTATBMPEN
    CMP #02
    BEQ TEXTATBMPAPER
    CMP #03
    BEQ TEXTATBMCMOVEPREPARE
    CMP #04
    BEQ TEXTATBMXAT
    CMP #05
    BEQ TEXTATBMCLS
    JMP TEXTATBMNEXT

TEXTATBMCLS:
    INC TEXTPTR
    DEX
    JSR CLS
    JMP TEXTATBMNEXT

TEXTATBMXAT:
    JMP TEXTATBMAT

TEXTATBMLF:
    INC TEXTPTR
    DEX
    LDA #0
    STA XCURSYS
    INC YCURSYS
    JSR CALCPOS
    JMP TEXTATBMNEXT2

TEXTATBMPEN:
    INC TEXTPTR
    DEX
    LDA TEXTWW
    AND #$2
    BEQ TEXTATBMPENDISABLED
    LDA (TEXTPTR), Y
    ASL A
    ASL A
    ASL A
    ASL A
    STA _PEN
TEXTATBMPENDISABLED:
    INC TEXTPTR
    DEY
    JMP TEXTATBMNEXT

TEXTATBMPAPER:
    INC TEXTPTR
    DEX
    LDA TEXTWW
    AND #$1
    BEQ TEXTATBMPAPERDISABLED
    LDA (TEXTPTR), Y
    STA _PAPER
TEXTATBMPAPERDISABLED:
    INC TEXTPTR
    DEY
    JMP TEXTATBMNEXT

TEXTATBMCMOVEPREPARE:
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    STA CLINEX
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    STA CLINEY

TEXTATBMCMOVE:
    CLC
    LDA CLINEX
    ADC XCURSYS
    STA XCURSYS
    LDA CLINEY
    ADC YCURSYS
    STA YCURSYS

    JMP TEXTATBMNEXT

TEXTATBMAT:
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    SEC
    SBC XCURSYS
    STA CLINEX
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    SEC
    SBC YCURSYS
    STA CLINEY
    JMP TEXTATBMCMOVE

TEXTATBMSP0:

    TXA
    PHA

    TYA
    PHA

    LDY #0

    LDA SCREENCODE
    STA TMPPTR
    LDA #0
    STA TMPPTR+1

    CLC
    ASL TMPPTR
    ROL TMPPTR+1
    CLC
    ASL TMPPTR
    ROL TMPPTR+1
    CLC
    ASL TMPPTR
    ROL TMPPTR+1

    CLC
    LDA #$0
    ADC TMPPTR
    STA TMPPTR
    LDA #$E0
    ADC TMPPTR+1
    STA TMPPTR+1

    LDA PLOTDEST
    STA TMPPTR2
    LDA PLOTDEST+1
    STA TMPPTR2+1
TEXTATBMSP0L1:
    LDA CURRENTMODE
    CMP #10
    BEQ TEXTATBMSP0L1M
    CMP #11
    BEQ TEXTATBMSP0L1M
    CMP #13
    BEQ TEXTATBMSP0L1M

    LDA (TMPPTR),Y
    STA (TMPPTR2),Y
    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M:

    TXA
    PHA

    TYA
    PHA

    LDA (TMPPTR),Y

    AND #$F0
    LSR A
    LSR A
    LSR A
    LSR A

    TAY
    LDA (MATHPTR5), Y

    TAX

    PLA
    TAY

    TXA

    STA (TMPPTR2),Y

    PLA
    TAX

    CLC
    LDA TMPPTR2
    ADC #1
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    TXA
    PHA

    TYA
    PHA

    LDA (TMPPTR),Y

    AND #$0F

    TAY
    LDA (MATHPTR5), Y

    TAX

    PLA
    TAY

    TXA

    STA (TMPPTR2),Y

    PLA
    TAX

    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M2:
    
    CLC
    LDA TMPPTR2
    ADC CURRENTSL
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1
    
    SEC
    LDA TMPPTR2
    SBC PATTERN
    STA TMPPTR2
    LDA TMPPTR2+1
    SBC #0
    STA TMPPTR2+1

    INY
    CPY #8
    BEQ TEXTATBMSP0L1X
    JMP TEXTATBMSP0L1

TEXTATBMSP0L1X:
    CLC
    LDA PLOTDEST
    ADC PATTERN
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    PLA
    TAY

    PLA
    TAX
    
    JMP TEXTATBMINCX

TEXTATBMSKIPTAB:
    DEC TABSTODRAW
    JMP TEXTATBMINCX

TEXTATBMINCX:
    INC XCURSYS
    LDA XCURSYS
    CMP CURRENTWIDTH
    BEQ TEXTATBMNEXT2
    JMP TEXTATBMNEXT
TEXTATBMNEXT2:
    LDA #0
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP #23

    BEQ TEXTATBMNEXT3
    JMP TEXTATBMNEXT
TEXTATBMNEXT3:

    ; scrolling ?

TEXTATBMNEXT:
    LDA TABSTODRAW
    BEQ TEXTATBMXLOOP2
    JMP TEXTATBMLOOP2
TEXTATBMXLOOP2:
    INY
    DEX
    BEQ TEXTATBMEND
    JMP TEXTATBMLOOP2
TEXTATBMEND:
    RTS

TEXTATDECODE:
    CMP #96
    BEQ TEXTATDECODEI1
    BCS TEXTATDECODEI1
    CMP #32
    BEQ TEXTATDECODEI0
    BCS TEXTATDECODEI0
    CLC
    ADC #64
    JMP TEXTATDECODEE
TEXTATDECODEI0:
    SEC
    SBC #32
    JMP TEXTATDECODEE
TEXTATDECODEI1:
    JMP TEXTATDECODEE
TEXTATDECODEE:
    STA SCREENCODE
    RTS

;-----------------------------------------------------------------------------
; TILE MODE
;-----------------------------------------------------------------------------

TEXTATANTIC6:
TEXTATANTIC7:
    LDA _PEN
    STA $2C5
    STA $2C6
    STA $2C7
    STA $2C8
    
TEXTATANTIC3:
TEXTATANTIC2:
TEXTATANTIC4:
TEXTATANTIC5:
    JSR CALCPOS0

    LDX TEXTSIZE
    LDY #$0
TEXTATLOOP2:

    LDA TABSTODRAW
    BEQ TEXTATNSKIPTAB
    JMP TEXTATSKIPTAB

TEXTATNSKIPTAB:
    LDA (TEXTPTR),Y

    CMP #$7f
    BEQ TEXTATTAB
    CMP #31
    BCS TEXTATXCC
    JMP TEXTATCC

PIPPO:
    RTS

TEXTATXCC:
    ; JSR PIPPO
    JSR TEXTATDECODE
    LDA SCREENCODE
    JMP TEXTATSP0

TEXTATTAB:
    LDA XCURSYS
TEXTATTAB2:
    CMP TABCOUNT
    BCC TEXTATTAB3
    SEC
    SBC TABCOUNT
    JMP TEXTATTAB2
TEXTATTAB3:
    STA TMPPTR
    LDA TABCOUNT
    SEC
    SBC TMPPTR
    STA TABSTODRAW
    JMP TEXTATNEXT

TEXTATCC:
    CMP #13
    BEQ TEXTATLF
    CMP #10
    BEQ TEXTATLF
    CMP #09
    BEQ TEXTATTAB
    CMP #01
    BEQ TEXTATPEN
    CMP #02
    BEQ TEXTATPAPER
    CMP #03
    BEQ TEXTATCMOVEPREPARE
    CMP #04
    BEQ TEXTATXAT
    CMP #05
    BEQ TEXTATCLS
    JMP TEXTATNEXT

TEXTATCLS:
    INC TEXTPTR
    DEX
    JSR CLS
    JMP TEXTATBMNEXT

TEXTATXAT:
    JMP TEXTATAT

TEXTATLF:
    SEC
    LDA CURRENTTILESWIDTH
    SBC XCURSYS
    SBC #1
    CLC
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    SEC
    LDA CURRENTTILESWIDTH
    SBC XCURSYS
    SBC #1
    CLC
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    JMP TEXTATNEXT2

TEXTATPEN:
    INC TEXTPTR
    DEX
    LDA TEXTWW
    AND #$2
    BEQ TEXTATPENDISABLED
    LDA (TEXTPTR), Y
    STA _PEN
TEXTATPENDISABLED:
    INC TEXTPTR
    DEY
    JMP TEXTATNEXT

TEXTATPAPER:
    INC TEXTPTR
    DEX
    LDA TEXTWW
    AND #$1
    BEQ TEXTATPAPERDISABLED
    LDA (TEXTPTR), Y
    ; STA $d021
    ; STA $d020
TEXTATPAPERDISABLED:
    INC TEXTPTR
    DEY
    JMP TEXTATNEXT

TEXTATCMOVEPREPARE:
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    STA CLINEX
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    STA CLINEY

TEXTATCMOVE:
    CLC
    LDA CLINEX
    ADC XCURSYS
    CMP #$80
    BCS TEXTATCMOVESKIPX
    CMP CURRENTWIDTH
    BCS TEXTATCMOVESKIPX
    STA XCURSYS
    LDA CLINEX

    CMP #$80
    BCC TEXTATCMOVEADDPX

TEXTATCMOVESUBPX:
    EOR #$FF
    CLC
    ADC #$1
    STA CLINEX
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CLINEX
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    JMP TEXTATCMOVESKIPX

TEXTATCMOVEADDPX:

    CLC
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    JMP TEXTATCMOVESKIPX

TEXTATCMOVESKIPX:

    CLC
    LDA CLINEY
    ADC YCURSYS
    CMP #$80
    BCS TEXTATCMOVESKIPY
    CMP CURRENTHEIGHT
    BCS TEXTATCMOVESKIPY
    STA YCURSYS

TEXTATCMOVEADDPY:
    TXA
    PHA
    LDA CLINEY
    CMP #$80
    BCC TEXTATCMOVELOOPYP
    JMP TEXTATCMOVELOOPYM

TEXTATCMOVELOOPYP:
    TAX
TEXTATCMOVELOOPY:

    CLC
    LDA CURRENTWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    DEX
    BNE TEXTATCMOVELOOPY
    PLA
    TAX
    JMP TEXTATCMOVESKIPY

TEXTATCMOVELOOPYM:
    EOR #$FF
    CLC
    ADC #$1
    STA CLINEY
    TAX
TEXTATCMOVELOOPY2:

    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    DEX
    BNE TEXTATCMOVELOOPY2
    PLA
    TAX
    JMP TEXTATCMOVESKIPY

TEXTATCMOVESKIPY:
    INC TEXTPTR
    DEY
    JMP TEXTATNEXT

TEXTATAT:
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    SEC
    SBC XCURSYS
    STA CLINEX
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    SEC
    SBC YCURSYS
    STA CLINEY
    JMP TEXTATCMOVE

TEXTATSP0:
    STA (COPYOFTEXTADDRESS),Y
    JMP TEXTATINCX

TEXTATSKIPTAB:
    DEC TABSTODRAW
    JMP TEXTATINCX

TEXTATINCX:
    INC XCURSYS
    LDA XCURSYS
    CMP CURRENTWIDTH
    BEQ TEXTATNEXT2
    JMP TEXTATNEXT
TEXTATNEXT2:
    LDA #0
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CURRENTHEIGHT

    BEQ TEXTATNEXT3
    JMP TEXTATNEXT
TEXTATNEXT3:

    LDA COPYOFTEXTADDRESS
    PHA
    LDA COPYOFTEXTADDRESS+1
    PHA

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

    PLA
    STA COPYOFTEXTADDRESS+1
    PLA
    STA COPYOFTEXTADDRESS

    DEC YCURSYS
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

TEXTATNEXT:
    LDA TABSTODRAW
    BEQ TEXTATXLOOP2
    JMP TEXTATLOOP2
TEXTATXLOOP2:
    INY
    DEX
    BEQ TEXTATEND
    JMP TEXTATLOOP2
TEXTATEND:
    RTS

TEXTATBMC1:
    .BYTE   %00000000
    .BYTE   %00000001
    .BYTE   %00000100
    .BYTE   %00000101
    .BYTE   %00010000
    .BYTE   %00010001
    .BYTE   %00010100
    .BYTE   %00010101
    .BYTE   %01000000
    .BYTE   %01000001
    .BYTE   %01000100
    .BYTE   %01000101
    .BYTE   %01010000
    .BYTE   %01010001
    .BYTE   %01010100
    .BYTE   %01010101

TEXTATBMC2:
    .BYTE   %00000000
    .BYTE   %00000010
    .BYTE   %00001000
    .BYTE   %00001010
    .BYTE   %00100000
    .BYTE   %00100010
    .BYTE   %00101000
    .BYTE   %00101010
    .BYTE   %10000000
    .BYTE   %10000010
    .BYTE   %10001000
    .BYTE   %10001010
    .BYTE   %10100000
    .BYTE   %10100010
    .BYTE   %10101000
    .BYTE   %10101010

TEXTATBMC3:
    .BYTE   %00000000
    .BYTE   %00000011
    .BYTE   %00001100
    .BYTE   %00001111
    .BYTE   %00110000
    .BYTE   %00110011
    .BYTE   %00111100
    .BYTE   %00111111
    .BYTE   %11000000
    .BYTE   %11000011
    .BYTE   %11001100
    .BYTE   %11001111
    .BYTE   %11110000
    .BYTE   %11110011
    .BYTE   %11111100
    .BYTE   %11111111
