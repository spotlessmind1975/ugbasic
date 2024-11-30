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

TEXTATBITMAPMODERAW:

    LDA _PEN
    ASL
    ASL
    ASL
    ASL
    STA MATHPTR6
    
    LDA TEXTSIZE
    BNE TEXTATRAWBITMAPMODEGO
    RTS

TEXTATRAWBITMAPMODEGO:

    LDA CURRENTMODE
    CMP #3
    BEQ TEXTATRAWBITMAPMODEGOFORCE3
    JMP TEXTATRAWBITMAPMODEGOFORCE2

TEXTATRAWBITMAPMODEGOFORCE3:
    LDX #0
    LDA TEXTATRAWBITMAPMODEGO8LOA, X
    STA TEXTATRAWBITMAPMODEGO8LOB, X
    INX
    LDA TEXTATRAWBITMAPMODEGO8LOA, X
    STA TEXTATRAWBITMAPMODEGO8LOB, X
    INX
    LDA TEXTATRAWBITMAPMODEGO8LOA, X
    STA TEXTATRAWBITMAPMODEGO8LOB, X
    
    LDX #0
    LDA TEXTATRAWBITMAPMODEGO8HIA, X
    STA TEXTATRAWBITMAPMODEGO8HIB, X
    INX
    LDA TEXTATRAWBITMAPMODEGO8HIA, X
    STA TEXTATRAWBITMAPMODEGO8HIB, X
    INX
    LDA TEXTATRAWBITMAPMODEGO8HIA, X
    STA TEXTATRAWBITMAPMODEGO8HIB, X

    LDX #0
    LDA #$D0
    STA TEXTATRAWBMSP0LOLOA, X
    LDA TEXTATRAWBMSP0LOLOA, X
    STA TEXTATRAWBITMAPMODEGOMI0, X
    LDA TEXTATRAWBITMAPMODEGOMI0, X
    STA TEXTATRAWBMSP0MIMI0, X
    LDA TEXTATRAWBMSP0MIMI0, X
    STA TEXTATRAWBMSP0MIMI20, X
    LDA TEXTATRAWBMSP0MIMI20, X

    JMP TEXTATRAWBITMAPMODEGOFORCEGO

TEXTATRAWBITMAPMODEGOFORCE2:
    LDX #0
    LDA #$EA
    STA TEXTATRAWBITMAPMODEGO8LOB, X
    STA TEXTATRAWBITMAPMODEGO8LOA, X
    STA TEXTATRAWBITMAPMODEGO8HIB, X
    STA TEXTATRAWBITMAPMODEGO8HIA, X
    INX
    STA TEXTATRAWBITMAPMODEGO8LOB, X
    STA TEXTATRAWBITMAPMODEGO8LOA, X
    STA TEXTATRAWBITMAPMODEGO8HIB, X
    STA TEXTATRAWBITMAPMODEGO8HIA, X
    INX
    STA TEXTATRAWBITMAPMODEGO8LOB, X
    STA TEXTATRAWBITMAPMODEGO8LOA, X
    STA TEXTATRAWBITMAPMODEGO8HIB, X
    STA TEXTATRAWBITMAPMODEGO8HIA, X

    LDX #0
    LDA #$F0
    STA TEXTATRAWBMSP0LOLOA, X
    STA TEXTATRAWBITMAPMODEGOMI0, X
    STA TEXTATRAWBMSP0MIMI0, X
    STA TEXTATRAWBMSP0MIMI20, X

TEXTATRAWBITMAPMODEGOFORCEGO:

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 2 ) || ( currentMode == 3 ) )

    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    SEI

    LDX XCURSYS
    LDY YCURSYS

    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
TEXTATRAWBITMAPMODEGO8LOA:
    ADC PLOT8LO,X              ;+ (8 * Xcell)
TEXTATRAWBITMAPMODEGO8LOB:
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
TEXTATRAWBITMAPMODEGO8HIA:
    ADC PLOT8HI,X
TEXTATRAWBITMAPMODEGO8HIB:
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
   
TEXTATRAWBITMAPMODEGOMI0:

    BEQ TEXTATRAWBITMAPMODEGOMI1

    CLC

    LDA PLOTCDEST          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCDEST+1
    ADC #0          ;do the high byte
    STA PLOTCDEST+1

TEXTATRAWBITMAPMODEGOMI1:

    LDX TEXTSIZE
    LDY #$0

TEXTATBMPRECHKCONSOLE:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATBMPOSTCHKCONSOLE
    BCC TEXTATBMINCYX
    JMP TEXTATRAWBMNEXT2
TEXTATBMINCYX:
    JMP TEXTATBMPOSTCHKCONSOLE

TEXTATBMPOSTCHKCONSOLE:

TEXTATRAWBMLOOP2:

    LDA (TEXTPTR),Y

    JSR TEXTATDECODE

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

TEXTATRAWBMSP0LOLOA:    

    BNE TEXTATRAWBMSP0LOLOB

    CLC

    LDA PLOTDEST           ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTDEST+1          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    BEQ TEXTATRAWBMSP0LOLOB

TEXTATRAWBMSP0LOLOB:

    CLC

    LDA PLOTCVBASELO,Y          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCVBASEHI,Y          ;do the high byte
    ADC #0
    STA PLOTCDEST+1

    LDA #0

TEXTATRAWBMSP0MIMI0:

    BEQ TEXTATRAWBMSP0MIMI1

    CLC

    LDA PLOTCDEST          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTCDEST               ;= cell address

    LDA PLOTCDEST+1         ;do the high byte
    ADC #0
    STA PLOTCDEST+1

TEXTATRAWBMSP0MIMI1:

    CLC

    LDA PLOTC2VBASELO,Y          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTC2DEST               ;= cell address

    LDA PLOTC2VBASEHI,Y
    ADC #0          ;do the high byte
    STA PLOTC2DEST+1

    LDA #0

TEXTATRAWBMSP0MIMI20:

    BEQ TEXTATRAWBMSP0MIMI21

    CLC

    LDA PLOTC2DEST          ;table of $8400 row base addresses
    ADC XCURSYS
    STA PLOTC2DEST               ;= cell address

    LDA PLOTC2DEST+1
    ADC #0          ;do the high byte
    STA PLOTC2DEST+1

TEXTATRAWBMSP0MIMI21:

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
TEXTATRAWBMSP0L1:
    LDA CURRENTMODE
    CMP #3
    BEQ TEXTATRAWBMSP0L1B3

TEXTATRAWBMSP0L1B2:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    JMP TEXTATRAWBMSP0L1X

TEXTATRAWREMAP:
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

TEXTATRAWBMSP0L1B3:

    TXA
    PHA
    LDA (TMPPTR),Y
    AND #$F0
    LSR
    LSR
    LSR
    LSR
    TAX
    LDA TEXTATRAWREMAP, X

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
    LDA TEXTATRAWREMAP, X

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
    
TEXTATRAWBMSP0L1X:
    INY
    CPY #8
    BNE TEXTATRAWBMSP0L1

    LDA CURRENTMODE
    CMP #3
    BEQ TEXTATRAWBMC3

    LDY #0
    LDA (PLOTCDEST),Y
    AND #$0F
    ORA MATHPTR6
    STA (PLOTCDEST),Y
    LDA (PLOTCDEST),Y
    AND #$f0
    ORA _PAPER
    STA (PLOTCDEST),Y
    JMP TEXTATRAWBMF

TEXTATRAWBMC3:

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

TEXTATRAWBMF:
    PLA
    TAY
    
TEXTATRAWBMINCX:
    INC XCURSYS
    DEX
    BNE TEXTATRAWBMEND2X
    JMP TEXTATRAWBMEND2
TEXTATRAWBMEND2X:
    LDA XCURSYS
    CMP CONSOLEX2
    BEQ TEXTATRAWBMNEXT
    BCS TEXTATRAWBMNEXT2
    JMP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT2:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2
    BCS TEXTATRAWBMNEXT3
    JMP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT3:

    ; scrolling ?

    DEC YCURSYS

TEXTATRAWBMNEXT:
TEXTATRAWBMXLOOP2:
    INY
    CPX #0
    BEQ TEXTATRAWBMEND
    JMP TEXTATRAWBMLOOP2
TEXTATRAWBMEND2:
TEXTATRAWBMEND:
    CLI

@ENDIF
    RTS
