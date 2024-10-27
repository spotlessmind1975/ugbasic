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
;*                      TEXT AT GIVEN POSITION ON VIC-II                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATBITMAPMODE:

    LDA _PEN
    ASL
    ASL
    ASL
    ASL
    STA MATHPTR6
    
    LDA TEXTSIZE
    BNE TEXTATBITMAPMODEGO
    RTS

TEXTATBITMAPMODEGO:

    LDA CURRENTMODE
    CMP #3
    BEQ TEXTATBITMAPMODEGOFORCE3
    JMP TEXTATBITMAPMODEGOFORCE2

TEXTATBITMAPMODEGOFORCE3:
    LDX #0
    LDA TEXTATBITMAPMODEGO8LOA, X
    STA TEXTATBITMAPMODEGO8LOB, X
    INX
    LDA TEXTATBITMAPMODEGO8LOA, X
    STA TEXTATBITMAPMODEGO8LOB, X
    INX
    LDA TEXTATBITMAPMODEGO8LOA, X
    STA TEXTATBITMAPMODEGO8LOB, X
    
    LDX #0
    LDA TEXTATBITMAPMODEGO8HIA, X
    STA TEXTATBITMAPMODEGO8HIB, X
    INX
    LDA TEXTATBITMAPMODEGO8HIA, X
    STA TEXTATBITMAPMODEGO8HIB, X
    INX
    LDA TEXTATBITMAPMODEGO8HIA, X
    STA TEXTATBITMAPMODEGO8HIB, X

    LDX #0
    LDA #$D0
    STA TEXTATBMSP0LOLOA, X
    LDA TEXTATBMSP0LOLOA, X
    STA TEXTATBITMAPMODEGOMI0, X
    LDA TEXTATBITMAPMODEGOMI0, X
    STA TEXTATBMSP0MIMI0, X
    LDA TEXTATBMSP0MIMI0, X
    STA TEXTATBMSP0MIMI20, X
    LDA TEXTATBMSP0MIMI20, X

    JMP TEXTATBITMAPMODEGOFORCEGO

TEXTATBITMAPMODEGOFORCE2:
    LDX #0
    LDA #$EA
    STA TEXTATBITMAPMODEGO8LOB, X
    STA TEXTATBITMAPMODEGO8LOA, X
    STA TEXTATBITMAPMODEGO8HIB, X
    STA TEXTATBITMAPMODEGO8HIA, X
    INX
    STA TEXTATBITMAPMODEGO8LOB, X
    STA TEXTATBITMAPMODEGO8LOA, X
    STA TEXTATBITMAPMODEGO8HIB, X
    STA TEXTATBITMAPMODEGO8HIA, X
    INX
    STA TEXTATBITMAPMODEGO8LOB, X
    STA TEXTATBITMAPMODEGO8LOA, X
    STA TEXTATBITMAPMODEGO8HIB, X
    STA TEXTATBITMAPMODEGO8HIA, X

    LDX #0
    LDA #$F0
    STA TEXTATBMSP0LOLOA, X
    STA TEXTATBITMAPMODEGOMI0, X
    STA TEXTATBMSP0MIMI0, X
    STA TEXTATBMSP0MIMI20, X

TEXTATBITMAPMODEGOFORCEGO:

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) || ( currentMode == 3 ) )

    LDA #0
    STA TABSTODRAW
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    SEI

    LDX XCURSYS
    LDY YCURSYS

    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
TEXTATBITMAPMODEGO8LOA:
    ADC PLOT8LO,X              ;+ (8 * Xcell)
TEXTATBITMAPMODEGO8LOB:
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
TEXTATBITMAPMODEGO8HIA:
    ADC PLOT8HI,X
TEXTATBITMAPMODEGO8HIB:
    ADC PLOT8HI,X
    STA PLOTDEST+1

    CLC

    LDA PLOTCVBASELO,Y          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCVBASEHI,Y
    ADC #0          ;do the high byte
    STA PLOTCDEST+1

    LDA #0
   
TEXTATBITMAPMODEGOMI0:

    BEQ TEXTATBITMAPMODEGOMI1

    CLC

    LDA PLOTCDEST          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCDEST+1
    ADC #0          ;do the high byte
    STA PLOTCDEST+1

TEXTATBITMAPMODEGOMI1:

    LDX TEXTSIZE
    LDY #$0
TEXTATBMLOOP2:

    LDA TABSTODRAW
    BEQ TEXTATBMNSKIPTAB
    JMP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB:
    LDA (TEXTPTR),Y

    CMP #31
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
    TYA
    PHA
    TXA
    PHA
    JSR CLSG
    PLA
    TAX
    PLA
    TAY
    JMP TEXTATBMNEXT

TEXTATBMXAT:
    JMP TEXTATBMAT

TEXTATBMLF:
    INC TEXTPTR
    DEX
    JMP TEXTATBMNEXT2

TEXTATBMPEN:
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    CMP #$FF
    BNE TEXTATBMPEN2
    LDA #$0
TEXTATBMPEN2:
    STA _PEN
    ASL
    ASL
    ASL
    ASL
    STA MATHPTR6
    INC TEXTPTR
    DEY
    JMP TEXTATBMNEXT

TEXTATBMPAPER:
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    STA _PAPER
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
    ADC CONSOLEX1
    STA CLINEX
    INC TEXTPTR
    DEX
    LDA (TEXTPTR), Y
    SEC
    SBC YCURSYS
    ADC CONSOLEY1
    STA CLINEY
    JMP TEXTATBMCMOVE

TEXTATBMSP0:

    TYA
    PHA

    TXA
    PHA

    LDX XCURSYS
    LDY YCURSYS

    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    LDA #0

TEXTATBMSP0LOLOA:    

    BNE TEXTATBMSP0LOLOB

    CLC

    LDA PLOTDEST           ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTDEST+1          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    BEQ TEXTATBMSP0LOLOB

TEXTATBMSP0LOLOB:

    CLC

    LDA PLOTCVBASELO,Y          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCVBASEHI,Y          ;do the high byte
    ADC #0
    STA PLOTCDEST+1

    LDA #0

TEXTATBMSP0MIMI0:

    BEQ TEXTATBMSP0MIMI1

    CLC

    LDA PLOTCDEST          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCDEST+1         ;do the high byte
    ADC #0
    STA PLOTCDEST+1

TEXTATBMSP0MIMI1:

    CLC

    LDA PLOTC2VBASELO,Y          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTC2DEST               ;= cell address

    LDA PLOTC2VBASEHI,Y
    ADC #0          ;do the high byte
    STA PLOTC2DEST+1

    LDA #0

TEXTATBMSP0MIMI20:

    BEQ TEXTATBMSP0MIMI21

    CLC

    LDA PLOTC2DEST          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTC2DEST               ;= cell address

    LDA PLOTC2DEST+1
    ADC #0          ;do the high byte
    STA PLOTC2DEST+1

TEXTATBMSP0MIMI21:

    PLA
    TAX
    
    PLA
    TAY

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

    LDA #$98
    ADC TMPPTR+1
    STA TMPPTR+1
TEXTATBMSP0L1:
    LDA CURRENTMODE
    CMP #3
    BEQ TEXTATBMSP0L1B3

TEXTATBMSP0L1B2:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    JMP TEXTATBMSP0L1X

TEXTATREMAP:
    .BYTE %00000000	
    .BYTE %00000001	
    .BYTE %00000100
    .BYTE %00000101
    .BYTE %00010000
    .BYTE %00010001
    .BYTE %00010100
    .BYTE %00010101
    .BYTE %01000000
    .BYTE %01000001
    .BYTE %01000100
    .BYTE %01000101
    .BYTE %01010000
    .BYTE %01010001
    .BYTE %01010100
    .BYTE %01010101

TEXTATBMSP0L1B3:

    TXA
    PHA
    LDA (TMPPTR),Y
    AND #$F0
    LSR
    LSR
    LSR
    LSR
    TAX
    LDA TEXTATREMAP, X

    TAX
    TYA
    PHA
    LDY #0
    TXA
    STA (PLOTDEST), Y
    PLA
    TAY

    CLC
    LDA PLOTDEST
    ADC #8
    STA PLOTDEST
    LDA PLOTDEST+1
    ADC #0
    STA PLOTDEST+1

    LDA (TMPPTR),Y
    AND #$0F
    TAX
    LDA TEXTATREMAP, X

    TAX
    TYA
    PHA
    LDY #0
    TXA
    STA (PLOTDEST), Y
    PLA
    TAY

    SEC
    LDA PLOTDEST
    SBC #7
    STA PLOTDEST
    LDA PLOTDEST+1
    SBC #0
    STA PLOTDEST+1

    PLA
    TAX
    
TEXTATBMSP0L1X:
    INY
    CPY #8
    BNE TEXTATBMSP0L1

    LDA CURRENTMODE
    CMP #3
    BEQ TEXTATBMC3

    LDY #0
    LDA (PLOTCDEST),Y
    AND #$0F
    ORA MATHPTR6
    STA (PLOTCDEST),Y
    LDA (PLOTCDEST),Y
    AND #$f0
    ORA _PAPER
    STA (PLOTCDEST),Y
    JMP TEXTATBMF

TEXTATBMC3:

    LDY #0
    LDA MATHPTR6
    STA (PLOTCDEST),Y
    LDA #0
    STA (PLOTCDEST),Y
    LDA MATHPTR6
    ORA (PLOTCDEST),Y
    STA (PLOTCDEST),Y

    CLC
    LDA PLOTCDEST
    ADC #1
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDY #0
    LDA MATHPTR6
    STA (PLOTCDEST),Y
    LDA #0
    STA (PLOTCDEST),Y
    LDA MATHPTR6
    ORA (PLOTCDEST),Y
    STA (PLOTCDEST),Y

    CLC
    LDA PLOTCDEST
    ADC #1
    STA PLOTCDEST
    LDA PLOTCDEST+1
    ADC #0
    STA PLOTCDEST+1

    LDY #0
    LDA MATHPTR6
    STA (PLOTC2DEST),Y
    LDA #0
    STA (PLOTC2DEST),Y
    LDA MATHPTR6
    ORA (PLOTC2DEST),Y
    STA (PLOTC2DEST),Y

    CLC
    LDA PLOTC2DEST
    ADC #1
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

    LDY #0
    LDA MATHPTR6
    STA (PLOTC2DEST),Y
    LDA #0
    STA (PLOTC2DEST),Y
    LDA MATHPTR6
    ORA (PLOTC2DEST),Y
    STA (PLOTC2DEST),Y

    CLC
    LDA PLOTC2DEST
    ADC #1
    STA PLOTC2DEST
    LDA PLOTC2DEST+1
    ADC #0
    STA PLOTC2DEST+1

TEXTATBMF:
    PLA
    TAY
    
    JMP TEXTATBMINCX

TEXTATBMSKIPTAB:
    DEC TABSTODRAW
    JMP TEXTATBMINCX

TEXTATBMINCX:
    INC XCURSYS
    DEX
    BNE TEXTATBMEND2X
    JMP TEXTATBMEND2
TEXTATBMEND2X:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATBMNEXT
    BCS TEXTATBMNEXT2
    JMP TEXTATBMNEXT
TEXTATBMNEXT2:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BCS TEXTATBMNEXT3
    JMP TEXTATBMNEXT
TEXTATBMNEXT3:

    ; scrolling ?

    DEC YCURSYS

TEXTATBMNEXT:
    LDA TABSTODRAW
    BEQ TEXTATBMXLOOP2
    JMP TEXTATBMLOOP2
TEXTATBMXLOOP2:
    INY
    CPX #0
    BEQ TEXTATBMEND
    JMP TEXTATBMLOOP2
TEXTATBMEND2:
TEXTATBMEND:
    CLI

@ENDIF
    RTS
