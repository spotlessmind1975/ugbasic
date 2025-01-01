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
;*                      TEXT AT GIVEN POSITION ON VIC-I                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATRAWDECODE:
    CMP #32
    BCS TEXTATRAWXSP128
    JMP TEXTATRAWSP128
TEXTATRAWXSP128:
    CMP #64
    BCS TEXTATRAWXSP0
    JMP TEXTATRAWDECODE0
TEXTATRAWXSP0:
    CMP #96
    BCS TEXTATRAWXSM64
    JMP TEXTATRAWSM64
TEXTATRAWXSM64:
    CMP #160
    BCS TEXTATRAWXSP64
    JMP TEXTATRAWSP64
TEXTATRAWXSP64:
    CMP #192
    BCS TEXTATRAWX2SM64
    JMP TEXTATRAWSM64
TEXTATRAWX2SM64:
    CMP #224
    BCS TEXTATRAWX2SM192
    JMP TEXTATRAWSM192
TEXTATRAWX2SM192:
    JMP TEXTATRAWDECODE0
TEXTATRAWSP64:
    CLC
    ADC #64
    JMP TEXTATRAWDECODE0
TEXTATRAWSP128:
    ADC #128
    JMP TEXTATRAWDECODE0
TEXTATRAWSM64:
    SBC #63
    JMP TEXTATRAWDECODE0
TEXTATRAWSM192:
    SBC #191
    JMP TEXTATRAWDECODE0
TEXTATRAWDECODE0:
    STA SCREENCODE
    RTS

TEXTATRAW:
    LDA TEXTSIZE
    BNE TEXTATRAWGO
    RTS

TEXTATRAWGO:
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
    LDA CURRENTMODE
    CMP #0
    BNE TEXTATRAWGO0X
    JMP TEXTATTILEMODERAW
TEXTATRAWGO0X:
    CMP #1
    BNE TEXTATRAWGO1X
    JMP TEXTATTILEMODERAW
TEXTATRAWGO1X:
    CMP #2
    BNE TEXTATRAWGO2X
TEXTATRAWGO2X:
    CMP #3
    BNE TEXTATRAWGO3X
TEXTATRAWGO3X:
    CMP #4
    BNE TEXTATRAWGO4X
    JMP TEXTATTILEMODERAW
TEXTATRAWGO4X:
    CLI
    RTS
    
;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

TEXTATWBITMAPMODERAW:
    RTS

;-----------------------------------------------------------------------------
; TILE MODE
;-----------------------------------------------------------------------------

TEXTATTILEMODERAW:    
    LDX YCURSYS
    BEQ TEXTATRAWSKIP
TEXTATRAWLOOP1:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    DEX
    BNE TEXTATRAWLOOP1

    LDX YCURSYS
TEXTATRAWLOOPC1:
    CLC
    LDA CURRENTTILESWIDTH
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1
    DEX
    BNE TEXTATRAWLOOPC1

TEXTATRAWSKIP:
    CLC
    LDA XCURSYS
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    CLC
    LDA XCURSYS
    ADC COPYOFCOLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA #0
    ADC COPYOFCOLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDX TEXTSIZE
    LDY #$0
TEXTATRAWLOOP2:

    LDA TABSTODRAW
    BEQ TEXTATRAWNSKIPTAB
    JMP TEXTATRAWSKIPTAB

TEXTATRAWNSKIPTAB:
    LDA (TEXTPTR),Y

    JSR TEXTATRAWDECODE

    STA (COPYOFTEXTADDRESS),Y
    LDA _PEN
    AND #$07
    STA (COPYOFCOLORMAPADDRESS),Y
    JMP TEXTATRAWINCX

TEXTATRAWSKIPTAB:
    DEC TABSTODRAW
    JMP TEXTATRAWINCX

TEXTATRAWINCX:
    INC XCURSYS
    DEX
    BNE TEXTATRAWEND2X
    JMP TEXTATRAWEND2
TEXTATRAWEND2X:
    LDA XCURSYS
    CMP CONSOLEX2    
    BEQ TEXTATRAWNEXT
    BCS TEXTATRAWNEXT2
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT2:
    LDA CONSOLEX1
    STA XCURSYS
    INC YCURSYS
    LDA YCURSYS
    CMP CONSOLEY2

    BEQ TEXTATRAWNEXT
    BCS TEXTATRAWNEXT3
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT3:

    LDA COPYOFTEXTADDRESS
    PHA
    LDA COPYOFTEXTADDRESS+1
    PHA

    JSR VSCROLLTUP

    PLA
    STA COPYOFTEXTADDRESS+1
    PLA
    STA COPYOFTEXTADDRESS
    
    DEC YCURSYS
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1

    SEC
    LDA COPYOFCOLORMAPADDRESS
    SBC CURRENTTILESWIDTH
    STA COPYOFCOLORMAPADDRESS
    LDA COPYOFCOLORMAPADDRESS+1
    SBC #0
    STA COPYOFCOLORMAPADDRESS+1

TEXTATRAWNEXT:
    LDA TABSTODRAW
    BEQ TEXTATRAWXLOOP2
    JMP TEXTATRAWLOOP2
TEXTATRAWXLOOP2:
    INY
    CPX #0
    BEQ TEXTATRAWEND
    JMP TEXTATRAWLOOP2
TEXTATRAWEND2:
TEXTATRAWEND:
    CLI
    RTS
