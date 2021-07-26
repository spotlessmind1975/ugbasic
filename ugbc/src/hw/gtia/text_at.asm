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
TEXTSIZE = $92
TABSTODRAW = $93
TEXTWW = $94
TEXTPEN = $95
TEXTPAPER = $96
SCREENCODE = $97

TEXTAT:
    LDA TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO:
    LDA CURRENTMODE
    CMP #2
    BNE TEXTATANTIC2X
    JMP TEXTATANTIC2
TEXTATANTIC2X:
    CMP #6
    BNE TEXTATANTIC6X
    JMP TEXTATANTIC6
TEXTATANTIC6X:    
    ; CMP #7
    ; BEQ TEXTATANTIC7
    ; CMP #3
    ; BEQ TEXTATANTIC3
    ; CMP #4
    ; BEQ TEXTATANTIC4
    ; CMP #5
    ; BEQ TEXTATANTIC5

    CMP #8
    BNE TEXTATANTIC8X
    JMP TEXTATANTIC8
TEXTATANTIC8X:
    ; CMP #9
    ; BEQ PLOTANTIC9
    ; CMP #10
    ; BEQ PLOTANTIC10
    ; CMP #11
    ; BEQ PLOTANTIC11
    ; CMP #13
    ; BEQ PLOTANTIC13
    ; CMP #15
    ; BEQ PLOTANTIC15
    ; CMP #12
    ; BEQ PLOTANTIC12
    ; CMP #14
    ; BEQ PLOTANTIC14
    RTS
    
;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATANTIC8:

    LDX XCURSYS
    LDY YCURSYS

    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    LDX TEXTSIZE
    LDY #$0
TEXTATBMLOOP2:

    LDA TABSTODRAW
    BEQ TEXTATBMNSKIPTAB
    JMP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB:
    LDA (TEXTPTR),Y

    CMP #$7f
    BEQ TEXTATBMTAB
    CMP #10
    BCS TEXTATBMXCC
    JMP TEXTATBMCC

TEXTATBMXCC:
    JMP TEXTATBMSP0

TEXTATBMTAB:
    LDA XCURSYS
TEXTATBMTAB2:
    CMP TABCOUNT
    BCC TEXTATBMTAB3
    DEC TABCOUNT
    JMP TEXTATBMTAB2
TEXTATBMTAB3:
    CLC
    ADC TABCOUNT
    STA TABSTODRAW
    JMP TEXTATBMNEXT

TEXTATBMCC:
    CMP #01
    BEQ TEXTATBMPEN
    CMP #02
    BEQ TEXTATBMPAPER
    CMP #03
    BEQ TEXTATBMCMOVEPREPARE
    CMP #04
    BEQ TEXTATBMXAT
    JMP TEXTATBMNEXT

TEXTATBMXAT:
    JMP TEXTATBMAT

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
    STA TEXTPEN
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
    STA TEXTPAPER
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
    LDA #$E0
    ADC TMPPTR+1
    STA TMPPTR+1
TEXTATBMSP0L1:
    LDA (TMPPTR),Y
    STA (PLOTDEST),Y
    INY
    CPY #8
    BNE TEXTATBMSP0L1
;     LDA TEXTWW
;     AND #$2
;     BEQ TEXTATBMCNOPEN
;     LDY #0
;     LDA (PLOTCDEST),Y
;     ORA TEXTPEN
;     STA (PLOTCDEST),Y
; TEXTATBMCNOPEN:
;     LDA TEXTWW
;     AND #$1
;     BEQ TEXTATBMCNOPAPER
;     LDA (PLOTCDEST),Y
;     AND #$f0
;     ORA TEXTPAPER
;     STA (PLOTCDEST),Y
; TEXTATBMCNOPAPER:
    PLA
    TAY
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

TEXTATANTIC2:
    LDA _PEN
    STA $2C5
    STA $2C6
    STA $2C7
    STA $2C8
    
TEXTATANTIC6:
    LDX YCURSYS
    BEQ TEXTATSKIP
TEXTATLOOP1:
    CLC
    LDA CURRENTWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE TEXTATLOOP1

TEXTATSKIP:
    CLC
    LDA XCURSYS
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

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
    CMP #10
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
    DEC TABCOUNT
    JMP TEXTATTAB2
TEXTATTAB3:
    CLC
    ADC TABCOUNT
    STA TABSTODRAW
    JMP TEXTATNEXT

TEXTATCC:
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
    JMP TEXTATNEXT

TEXTATXAT:
    JMP TEXTATAT

TEXTATPEN:
    INC TEXTPTR
    DEX
    LDA TEXTWW
    AND #$2
    BEQ TEXTATPENDISABLED
    LDA (TEXTPTR), Y
    STA TEXTPEN
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
    CMP #23

    BEQ TEXTATNEXT3
    JMP TEXTATNEXT
TEXTATNEXT3:

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

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
