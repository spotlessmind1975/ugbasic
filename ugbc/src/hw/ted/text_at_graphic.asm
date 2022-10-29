; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      TEXT AT GIVEN POSITION ON TED                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATBITMAPMODE:
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
    
    SEI

    LDX XCURSYS
    LDY YCURSYS

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
    JSR CLSG
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
    LDA TEXTWW
    AND #$2
    BEQ TEXTATBMPENDISABLED
    LDA (TEXTPTR), Y
    CMP #$FF
    BNE TEXTATBMPEN2
    LDA #$0
TEXTATBMPEN2:    
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

    CLC

    TXA
    ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
    STA PLOTCDEST               ;= cell address

    LDA #0
    ADC PLOTCVBASEHI,Y          ;do the high byte
    STA PLOTCDEST+1

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
    LDA #$D0
    ADC TMPPTR+1
    STA TMPPTR+1
TEXTATBMSP0L1:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    INY
    CPY #8
    BNE TEXTATBMSP0L1
    LDA TEXTWW
    AND #$2
    BEQ TEXTATBMCNOPEN
    LDY #0
    LDA (PLOTCDEST),Y
    ORA _PEN
    STA (PLOTCDEST),Y
TEXTATBMCNOPEN:
    LDA TEXTWW
    AND #$1
    BEQ TEXTATBMCNOPAPER
    LDA (PLOTCDEST),Y
    AND #$f0
    ORA _PAPER
    STA (PLOTCDEST),Y
TEXTATBMCNOPAPER:
    PLA
    TAY
    JMP TEXTATBMINCX

TEXTATBMSKIPTAB:
    DEC TABSTODRAW
    JMP TEXTATBMINCX

TEXTATBMINCX:
    INC XCURSYS
    LDA XCURSYS
    CMP #40
    BEQ TEXTATBMNEXT2
    JMP TEXTATBMNEXT
TEXTATBMNEXT2:
    LDA #0
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP #25

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
    CLI
    RTS

