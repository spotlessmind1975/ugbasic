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
;*                          VERTICAL SCROLL ON EF936X                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLT
    LDA CONSOLEX1
    BNE VSCROLLTNEW
    LDA CONSOLEY1
    BNE VSCROLLTNEW
    LDA CONSOLEW
    CMPA CURRENTTILESWIDTH
    BNE VSCROLLTNEW
    LDA CONSOLEH
    CMPA CURRENTTILESHEIGHT
    BNE VSCROLLTNEW
    JMP VSCROLLTORG

VSCROLLTNEW

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ VSCROLLTNEWORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

VSCROLLTNEWDB
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

VSCROLLTNEWORIG

    ANDCC #$FE
    LDA _PEN
    ANDA #$0F
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    LDA _PAPER
    ANDA #$0F
    ORA <MATHPTR5
    STA <MATHPTR5

    LDA CURRENTMODE
    CMPA #0
    BNE VSCROLLTNEW0X
    JMP VSCROLLTNEW0
VSCROLLTNEW0X
    CMPA #1
    BNE VSCROLLTNEW1X
    JMP VSCROLLTNEW1
VSCROLLTNEW1X
    CMPA #2
    BNE VSCROLLTNEW2X
    JMP VSCROLLTNEW2
VSCROLLTNEW2X
    CMPA #3
    BNE VSCROLLTNEW3X
    JMP VSCROLLTNEW3
VSCROLLTNEW3X
    CMPA #4
    BNE VSCROLLTNEW4X
    JMP VSCROLLTNEW4
VSCROLLTNEW4X
    RTS

VSCROLLTNEW0
VSCROLLTNEW1
VSCROLLTNEW2
VSCROLLTNEW3
VSCROLLTNEW4
    PSHS A,B,X,Y,U
    LDA <DIRECTION
    CMPA #0
    LBGT VSCROLLTNEWDOWN

VSCROLLTNEWUP
    LDA CONSOLEX1
    STA <MATHPTR2
    LDA CONSOLEY1
    STA <MATHPTR3
    JSR TEXTATCALCPOS
    TFR X, Y
    LDA CURRENTSL
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    PSHS X
    PSHS Y
    
VSCROLLTNEWUPYSCR

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

    ANDCC #$FE
    LDB CONSOLEHB
    CMPB #8
    BEQ VSCROLLTNEWUPYSCR1BNO
    CLRA
    TFR D, U
VSCROLLTNEWUPYSCR1
    LDB #0
VSCROLLTNEWUPYSCR1L1
    LDA B,Y
    STA B,X
    INCB
    CMPB CONSOLEWB
    BNE VSCROLLTNEWUPYSCR1L1
    CLRA
    LDB CURRENTSL
    LEAX D, X
    LEAY D, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTNEWUPYSCR1

VSCROLLTNEWUPYSCR1BNO
    CLRA
    LDB #8
    TFR D, U
VSCROLLTNEWUPYSCR1B
    LDB #0
    LDA #0
VSCROLLTNEWUPYSCR1BL1
    STA B,X
    INCB
    CMPB CONSOLEWB
    BNE VSCROLLTNEWUPYSCR1BL1
    CLRA
    LDB CURRENTSL
    LEAX D, X
    LEAY D, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTNEWUPYSCR1B

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

    PULS Y
    PULS X
    
    ANDCC #$FE
    LDB CONSOLEHB
    SUBB #8
    BEQ VSCROLLTNEWUPYSCR1DNO
    CLRA
    TFR D, U
VSCROLLTNEWUPYSCR1C
    LDB #0
VSCROLLTNEWUPYSCR1CL1
    LDA B,Y
    STA B,X
    INCB
    CMPB CONSOLEWB
    BNE VSCROLLTNEWUPYSCR1CL1
    CLRA
    LDB CURRENTSL
    LEAX D, X
    LEAY D, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTNEWUPYSCR1C

VSCROLLTNEWUPYSCR1DNO
    CLRA
    LDB #8
    TFR D, U
VSCROLLTNEWUPYSCR1D
    LDB #0
    LDA #0
VSCROLLTNEWUPYSCR1DL1
    STA B,X
    INCB
    CMPB CONSOLEWB
    BNE VSCROLLTNEWUPYSCR1DL1
    CLRA
    LDB CURRENTSL
    LEAX D, X
    LEAY D, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTNEWUPYSCR1D

    JMP VSCROLLTNEWE

VSCROLLTNEWDOWN
    JMP VSCROLLTNEWE

VSCROLLTNEWE
    PULS A,B,X,Y,U
    RTS

; -------------------------------

VSCROLLTORG

    PSHS D
    LDD BITMAPADDRESS
    ADDD CURRENTFRAMESIZE
    STD <MATHPTR0
    PULS D

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ VSCROLLTORGORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

VSCROLLTORGDB
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

VSCROLLTORGORIG

    ANDCC #$FE
    LDA _PEN
    ANDA #$0F
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    LDA _PAPER
    ANDA #$0F
    ORA <MATHPTR5
    STA <MATHPTR5

    LDA CURRENTMODE
    CMPA #0
    BNE VSCROLLTORG0X
    JMP VSCROLLTORG0
VSCROLLTORG0X
    CMPA #1
    BNE VSCROLLTORG1X
    JMP VSCROLLTORG1
VSCROLLTORG1X
    CMPA #2
    BNE VSCROLLTORG2X
    JMP VSCROLLTORG2
VSCROLLTORG2X
    CMPA #3
    BNE VSCROLLTORG3X
    JMP VSCROLLTORG3
VSCROLLTORG3X
    CMPA #4
    BNE VSCROLLTORG4X
    JMP VSCROLLTORG4
VSCROLLTORG4X
    RTS

VSCROLLTORG0
VSCROLLTORG1
VSCROLLTORG2
VSCROLLTORG3
VSCROLLTORG4
    PSHS A,B,X,Y,U
    LDA <DIRECTION
    CMPA #0
    BGT VSCROLLTORGDOWN

VSCROLLTORGUP
    LDX BITMAPADDRESS
    TFR X, Y
    LDY BITMAPADDRESS
    LDA CURRENTSL
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    
VSCROLLTORGUPYSCR

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

VSCROLLTORGUPYSCR1
    LDA ,Y+
    STA ,X+
    CMPY <MATHPTR0
    BNE VSCROLLTORGUPYSCR1
    LDA #0
VSCROLLTORGUPREFILL
    STA ,X+
    CMPX <MATHPTR0
    BNE VSCROLLTORGUPREFILL

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

    LDX BITMAPADDRESS
    LDY BITMAPADDRESS
    LDA CURRENTSL
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y

VSCROLLTORGUPYSCR1C
    LDA ,Y+
    STA ,X+
    CMPY <MATHPTR0
    BNE VSCROLLTORGUPYSCR1C
    LDA <MATHPTR5
VSCROLLTORGUPREFILLC
    STA ,X+
    CMPX <MATHPTR0
    BNE VSCROLLTORGUPREFILLC

    JMP VSCROLLTORGE

VSCROLLTORGDOWN
    LDX BITMAPADDRESS
    LDY BITMAPADDRESS
    LDA CURRENTFRAMESIZE
    LEAY A, Y
    LEAX A, X
    
    LDA CURRENTSL
    COMA
    LEAX A, X

VSCROLLTORGDOWNYSCR

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

VSCROLLTORGDOWNYSCR1
    LDA ,-X
    STA ,-Y
    CMPX BITMAPADDRESS
    BNE VSCROLLTORGDOWNYSCR1
    LDA #0
VSCROLLTORGDOWNREFILL
    STA ,-Y
    CMPY BITMAPADDRESS
    BNE VSCROLLTORGDOWNREFILL

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

VSCROLLTORGDOWNYSCR1C
    LDA ,-X
    STA ,-Y
    CMPX BITMAPADDRESS
    BNE VSCROLLTORGDOWNYSCR1C
    LDA <MATHPTR5
VSCROLLTORGDOWNREFILLC
    STA ,-Y
    CMPY BITMAPADDRESS
    BNE VSCROLLTORGDOWNREFILLC

    JMP VSCROLLTORGE

VSCROLLTORGE
    PULS A,B,X,Y,U
    RTS