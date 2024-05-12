; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      TEXT AT GIVEN POSITION ON EF936X                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
SCREENCODE equ $08

TEXTATDECODE
    CMPA #$1F
    BHI TEXTATDECODEX1F
    LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODEX1F
    CMPA #$40
    BHS TEXTATDECODEX39
    ADDA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX39
    CMPA #$5F
    BHI TEXTATDECODEX5A
    SUBA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX5A
    CMPA #$7F
    BHI TEXTATDECODEX7F
    SUBA #$20
    JMP TEXTATDECODE0
TEXTATDECODEX7F
    LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODE0
    STA <SCREENCODE
    RTS

TEXTAT
    LDA <TEXTSIZE
    BNE TEXTATGO
    RTS

TEXTATGO

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ TEXTATGOORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

TEXTATGODB
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

TEXTATGOORIG

    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS
    LDA #0
    STA <TABSTODRAW

    LDY <TEXTPTR
    LDA CURRENTMODE
    CMPA #0
    BNE TEXTAT0X
    JMP TEXTAT0
TEXTAT0X
    CMPA #1
    BNE TEXTAT1X
    JMP TEXTAT1
TEXTAT1X
    CMPA #2
    BNE TEXTAT2X
    JMP TEXTAT2
TEXTAT2X
    CMPA #3
    BNE TEXTAT3X
    JMP TEXTAT3
TEXTAT3X
    CMPA #4
    BNE TEXTAT4X
    JMP TEXTAT4
TEXTAT4X
    RTS
    
TEXTATBITMAPMODE

TEXTAT0
TEXTAT1
TEXTAT2
TEXTAT3
TEXTAT4

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3

    JSR TEXTATCALCPOS

    JMP TEXTATCOMMON

TEXTATCOMMON

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

    LDB <TEXTSIZE
    LDY <TEXTPTR
TEXTATBMLOOP2

    LDA <TABSTODRAW
    BEQ TEXTATBMNSKIPTAB
    JMP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB
    LDA ,Y
    STA <SCREENCODE

    CMPA #$09
    BEQ TEXTATBMTAB
    CMPA #14
    BHI TEXTATBMXCC
    JMP TEXTATBMCC

TEXTATBMXCC
    JSR TEXTATDECODE
    JMP TEXTATBMSP0

TEXTATBMTAB
    LDA <XCURSYS
TEXTATBMTAB2
    CMPA TABCOUNT
    BLS TEXTATBMTAB3
    SUBA TABCOUNT
    JMP TEXTATBMTAB2
TEXTATBMTAB3
    STA <TMPPTR
    LDA TABCOUNT
    SUBA <TMPPTR
    STA <TABSTODRAW
    JMP TEXTATBMNEXT

TEXTATBMCC
    CMPA #13
    BEQ TEXTATBMLF
    CMPA #10
    BEQ TEXTATBMLF
    CMPA #01
    BEQ TEXTATBMPEN
    CMPA #02
    BEQ TEXTATBMPAPER
    CMPA #03
    BEQ TEXTATBMCMOVEPREPARE
    CMPA #04
    BEQ TEXTATBMXAT
    CMPA #05
    BEQ TEXTATBMCLS
    JMP TEXTATBMNEXT

TEXTATBMCLS
    LEAY 1,Y
    DECB
    JSR CLS
    JMP TEXTATBMNEXT

TEXTATBMXAT
    JMP TEXTATBMAT

TEXTATBMLF
    LDA #0
    STA <XCURSYS
    INC <YCURSYS
    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS
    JMP TEXTATBMNEXT2A

TEXTATBMPEN
    LEAY 1,Y
    DECB
    LDA , Y
    CMPA #$FF
    BNE TEXTATBMPEN2
    LDA #$0
TEXTATBMPEN2
    STA _PEN
    JMP TEXTATBMNEXT

TEXTATBMPAPER
    LEAY 1,Y
    DECB
    LDA , Y
    STA _PAPER
    JMP TEXTATBMNEXT

TEXTATBMCMOVEPREPARE
    LEAY 1,Y
    DECB
    LDA , Y
    STA <CLINEX
    LEAY 1,Y
    LEAX -1,X
    LDA , Y
    STA <CLINEY

TEXTATBMCMOVE
    LDA <CLINEX
    ADDA <XCURSYS
    STA <XCURSYS
    LDA <CLINEY
    ADDA <YCURSYS
    STA <YCURSYS

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS

    JMP TEXTATBMNEXT

TEXTATBMAT
    LEAY 1,Y
    DECB
    LDA , Y
    SUBA <XCURSYS
    STA <CLINEX
    LEAY 1,Y
    LEAX -1,X
    LDA , Y
    SUBA <YCURSYS
    STA <CLINEY
    JMP TEXTATBMCMOVE

TEXTATBMSP0

    PSHS D,Y,X

    LDU #0
    LDY #UDCCHAR
    LDA <SCREENCODE
    ANDA #$3F
    LDB #8
    MUL
    LEAY D, Y

    LDA CURRENTMODE
    CMPA #0
    BNE TEXTATBMSP00X
    JMP TEXTATBMSP00
TEXTATBMSP00X
    CMPA #1
    BNE TEXTATBMSP01X
    JMP TEXTATBMSP01
TEXTATBMSP01X
    CMPA #2
    BNE TEXTATBMSP02X
    JMP TEXTATBMSP02
TEXTATBMSP02X
    CMPA #3
    BNE TEXTATBMSP03X
    JMP TEXTATBMSP03
TEXTATBMSP03X
    CMPA #4
    BNE TEXTATBMSP04X
    JMP TEXTATBMSP04
TEXTATBMSP04X
    JMP TEXTATBMSP0E

TEXTATBMSP00
TEXTATBMSP01
TEXTATBMSP04

TEXTATBMSP0L1

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

    LDA ,Y
    STA ,X

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

    LDA <MATHPTR5
    STA ,X

    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M

    PSHS X

    LDX <MATHPTR5

    LDA ,Y

    ANDA #$F0
    LSRA
    LSRA
    LSRA
    LSRA

    LDA A, X

    PULS X

    STA , X

    LEAX 1, X

    PSHS X

    LDX <MATHPTR5

    LDA ,Y

    ANDA #$0F

    LDA A, X

    PULS X

    STA , X

    JMP TEXTATBMSP0L1M2

TEXTATBMSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP0L1X
    JMP TEXTATBMSP0L1

TEXTATBMSP0L1X
    LDA #1
    JMP TEXTATBMSP0E

TEXTATBMSP02

TEXTATBMSP02L1

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

    LDA _PEN
    ANDA #$01
    CMPA #$01
    BEQ TEXTATBMSP02L1NO
    LDA ,Y
    STA ,X
    JMP TEXTATBMSP02L1DONE

TEXTATBMSP02L1NO
    LDA #0
    STA ,X

TEXTATBMSP02L1DONE

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

    LDA _PEN
    ANDA #$02
    CMPA #$02
    BEQ TEXTATBMSP02L2NO
    LDA ,Y
    STA ,X
    JMP TEXTATBMSP02L2DONE

TEXTATBMSP02L2NO
    LDA #0
    STA ,X

TEXTATBMSP02L2DONE

    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP02L1X
    JMP TEXTATBMSP02L1

TEXTATBMSP02L1X
    LDA #1
    JMP TEXTATBMSP0E

;

TEXTATBMSP03

    LDA ,Y

    PSHS Y,D
    LDY #TEXTATFLIP
    ANDA #$0F
    LEAY A, Y
    LDA , Y
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR0
    PULS D, Y

    PSHS Y,D
    LDY #TEXTATFLIP
    ANDA #$F0
    LSRA
    LSRA
    LSRA
    LSRA
    LEAY A, Y
    LDA , Y
    ORA <MATHPTR0
    STA <MATHPTR0
    PULS D, Y

    PSHS U
    LDU #2

TEXTATBMSP03L1

    LDA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATBITMASK
    LDB A, Y
    LDA _PEN
    ANDA #$0F
    MUL
    TFR B, A
    PULS Y

@IF TO8

    LDB BASE_SEGMENT+$c3
    ANDB #$fe
    STB BASE_SEGMENT+$c3

@ELSE

    LDB BASE_SEGMENT+$c0
    ORB #$01
    STB BASE_SEGMENT+$c0

@ENDIF

    STA ,X

    LDA <MATHPTR0
    LSRA
    LSRA
    STA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATBITMASK
    LDB A, Y
    LDA _PEN
    ANDA #$0F
    MUL
    TFR B, A
    PULS Y

@IF TO8

    LDB BASE_SEGMENT+$c3
    ORB #$01
    STB BASE_SEGMENT+$c3

@ELSE

    LDB BASE_SEGMENT+$c0
    ANDB #$fe
    STB BASE_SEGMENT+$c0

@ENDIF

    STA ,X+

    LDA <MATHPTR0
    LSRA
    LSRA
    STA <MATHPTR0

    LEAU -1, U

    CMPU #0
    BNE TEXTATBMSP03L1

    LEAX -2, X 

    PULS U
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATBMSP03L1X
    JMP TEXTATBMSP03

TEXTATBMSP03L1X
    LDA #2
    JMP TEXTATBMSP0E

;

TEXTATBMSP0E

    PULS D,Y,X

    LDA CURRENTMODE
    CMPA #3
    BEQ TEXTATBMSP0E3

    LEAX 1, X

    JMP TEXTATBMINCX

TEXTATBMSP0E3
    LEAX 2, X

    JMP TEXTATBMINCX

TEXTATBMSKIPTAB
    DEC <TABSTODRAW
    LDA <TABSTODRAW
    CMPA #0
    BNE TEXTATBMSKIPTAB2
    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS
TEXTATBMSKIPTAB2
    JMP TEXTATBMINCX

TEXTATBMINCX
    INC <XCURSYS
    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATBMNEXT2
    JMP TEXTATBMNEXT
TEXTATBMNEXT2
    LDA CONSOLEX1
    STA <XCURSYS
    LDA CURRENTSL
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    LEAX A, X
    INC <YCURSYS
TEXTATBMNEXT2A
    LDA <YCURSYS
    CMPA CONSOLEY2
    BGT TEXTATBMNEXT3
    JMP TEXTATBMNEXT
TEXTATBMNEXT3

    LDA #$FF
    STA <DIRECTION
    JSR VSCROLLT

    DEC <YCURSYS

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS

TEXTATBMNEXT
    LDA <TABSTODRAW
    BEQ TEXTATBMXLOOP2
    JMP TEXTATBMLOOP2
TEXTATBMXLOOP2
    LEAY 1,Y
    DECB
    BEQ TEXTATBMEND
    JMP TEXTATBMLOOP2
TEXTATBMEND
    RTS

TEXTATBITMASK
    fcb $00, $10, $01, $11

TEXTATFLIP
    fcb $0, $8, $4, $c, $2, $a, $6, $e
    fcb $1, $9, $5, $d, $3, $b, $7, $f
