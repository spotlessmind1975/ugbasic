; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                      RAW TEXT AT GIVEN POSITION ON EF936X                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATRAWDECODE
    CMPA #$1F
    BHI TEXTATRAWDECODEX1F
    LDA #$20
    JMP TEXTATRAWDECODE0
TEXTATRAWDECODEX1F
    CMPA #$40
    BHS TEXTATRAWDECODEX39
    SUBA #$40
    JMP TEXTATRAWDECODE0
TEXTATRAWDECODEX39
    CMPA #$5F
    BHI TEXTATRAWDECODEX5A
    ; SUBA #$20
    JMP TEXTATRAWDECODE0
TEXTATRAWDECODEX5A
    CMPA #$7F
    BHI TEXTATRAWDECODEX7F
    SUBA #$60
    JMP TEXTATRAWDECODE0
TEXTATRAWDECODEX7F
    LDA #$20
    JMP TEXTATRAWDECODE0
TEXTATRAWDECODE0
    STA <SCREENCODE
    RTS

TEXTATRAW
    LDA <TEXTSIZE
    BNE TEXTATRAWGO
    RTS

TEXTATRAWGO

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    LBEQ TEXTATRAWGOORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

; **********************************************************************************
; **********************************************************************************
; **********************************************************************************
; **********************************************************************************
; **********************************************************************************
; **********************************************************************************

TEXTATRAWGODB
    
    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS

    LDY <TEXTPTR
    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3

    JSR TEXTATCALCPOS

    PSHS D
    TFR X, D
    ADDD BITMAPADDRESS
    TFR D, X
    PULS D

TEXTATRAWDBCOMMON

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
TEXTATRAWDBBMLOOP2

    LDA ,Y
    STA <SCREENCODE
    DECB

    JSR TEXTATRAWDECODE
    PSHS D,Y,X

    ORCC #$50

    LDU #0
    LDY #UDCCHAR
    LDA <SCREENCODE
    LDB #8
    MUL
    LEAY D, Y

TEXTATRAWDBBMSP03

    LDA ,Y
    PSHS Y,D
    LDY #TEXTATRAWFLIP
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
    LDY #TEXTATRAWFLIP
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

TEXTATRAWDBBMSP03L1

    LDA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATRAWBITMASK
    LDB A, Y
    LDA _PEN
    ANDA #$0F
    MUL
    TFR B, A
    PULS Y

@IF PC128OP

    PSHS D
    LDA BANKSHADOW
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    STA <MATHPTR1
    LDA $2000,X
    ORA <MATHPTR1
    STA $2000,X

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    LDA <MATHPTR0
    LSRA
    LSRA
    STA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATRAWBITMASK
    LDB A, Y
    LDA _PEN
    ANDA #$0F
    MUL
    TFR B, A
    PULS Y

@IF PC128OP

    PSHS D
    LDA BANKSHADOW
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    STA <MATHPTR1
    LDA ,X
    ORA <MATHPTR1
    STA ,X

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF


    LEAX 1, X

    LDA <MATHPTR0
    LSRA
    LSRA
    STA <MATHPTR0

    LEAU -1, U

    CMPU #0
    BNE TEXTATRAWDBBMSP03L1

    LEAX -2, X 

    PULS U
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATRAWDBBMSP03L1X
    JMP TEXTATRAWDBBMSP03

TEXTATRAWDBBMSP03L1X
    LDA #2
    JMP TEXTATRAWDBBMSP0E

TEXTATRAWDBBMSP0E

    ANDCC #$AF

    PULS D,Y,X

    LDA CURRENTMODE
    CMPA #3
    BEQ TEXTATRAWDBBMSP0E3

TEXTATRAWDBBMSP0E3
    LEAX 2, X

    JMP TEXTATRAWDBBMINCX

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS

    PSHS D
    TFR X, D
    ADDD BITMAPADDRESS
    TFR D, X
    PULS D

TEXTATRAWDBBMSKIPTAB2
    JMP TEXTATRAWDBBMINCX

TEXTATRAWDBBMINCX
    INC <XCURSYS
    CMPB #0
    BEQ TEXTATRAWDBBMEND2
    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATRAWDBBMNEXT2
    JMP TEXTATRAWDBBMNEXT
TEXTATRAWDBBMNEXT2
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
TEXTATRAWDBBMNEXT2A
    LDA <YCURSYS
    CMPA CONSOLEY2
    BGT TEXTATRAWDBBMNEXT3
    JMP TEXTATRAWDBBMNEXT
TEXTATRAWDBBMNEXT3

    LDA #$FF
    STA <DIRECTION
    JSR VSCROLLT

    DEC <YCURSYS

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS

    PSHS D
    TFR X, D
    ADDD BITMAPADDRESS
    TFR D, X
    PULS D

TEXTATRAWDBBMNEXT
    LEAY 1,Y
    JMP TEXTATRAWDBBMLOOP2
TEXTATRAWDBBMEND2
TEXTATRAWDBBMEND

    RTS

; **********************************************************************************
; **********************************************************************************
; **********************************************************************************
; **********************************************************************************
; **********************************************************************************
; **********************************************************************************

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

TEXTATRAWGOORIG

    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS
    LDA #0
    STA <TABSTODRAW

    LDY <TEXTPTR
    LDA CURRENTMODE
    CMPA #0
    BNE TEXTATRAW0X
    JMP TEXTATRAW0
TEXTATRAW0X
    CMPA #1
    BNE TEXTATRAW1X
    JMP TEXTATRAW1
TEXTATRAW1X
    CMPA #2
    BNE TEXTATRAW2X
    JMP TEXTATRAW2
TEXTATRAW2X
    CMPA #3
    BNE TEXTATRAW3X
    JMP TEXTATRAW3
TEXTATRAW3X
    CMPA #4
    BNE TEXTATRAW4X
    JMP TEXTATRAW4
TEXTATRAW4X
    RTS
    
TEXTATRAWBITMAPMODE

TEXTATRAW0
TEXTATRAW1
TEXTATRAW2
TEXTATRAW3
TEXTATRAW4

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3

    JSR TEXTATCALCPOS

    JMP TEXTATRAWCOMMON

TEXTATRAWCOMMON

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
TEXTATRAWBMLOOP2

    LDA ,Y
    STA <SCREENCODE
    DECB

    JSR TEXTATRAWDECODE

TEXTATRAWBMSP0

    PSHS D,Y,X

    LDU #0
    LDY #UDCCHAR
    LDA <SCREENCODE
    LDB #8
    MUL
    LEAY D, Y

    LDA CURRENTMODE
    CMPA #0
    BNE TEXTATRAWBMSP00X
    JMP TEXTATRAWBMSP00
TEXTATRAWBMSP00X
    CMPA #1
    BNE TEXTATRAWBMSP01X
    JMP TEXTATRAWBMSP01
TEXTATRAWBMSP01X
    CMPA #2
    BNE TEXTATRAWBMSP02X
    JMP TEXTATRAWBMSP02
TEXTATRAWBMSP02X
    CMPA #3
    BNE TEXTATRAWBMSP03X
    JMP TEXTATRAWBMSP03
TEXTATRAWBMSP03X
    CMPA #4
    BNE TEXTATRAWBMSP04X
    JMP TEXTATRAWBMSP04
TEXTATRAWBMSP04X
    JMP TEXTATRAWBMSP0E

TEXTATRAWBMSP00
TEXTATRAWBMSP01
TEXTATRAWBMSP04

TEXTATRAWBMSP0L1

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

    JMP TEXTATRAWBMSP0L1M2

TEXTATRAWBMSP0L1M

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

    JMP TEXTATRAWBMSP0L1M2

TEXTATRAWBMSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATRAWBMSP0L1X
    JMP TEXTATRAWBMSP0L1

TEXTATRAWBMSP0L1X
    LDA #1
    JMP TEXTATRAWBMSP0E

TEXTATRAWBMSP02

TEXTATRAWBMSP02L1

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
    BEQ TEXTATRAWBMSP02L1NO
    LDA ,Y
    STA ,X
    JMP TEXTATRAWBMSP02L1DONE

TEXTATRAWBMSP02L1NO
    LDA #0
    STA ,X

TEXTATRAWBMSP02L1DONE

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
    BEQ TEXTATRAWBMSP02L2NO
    LDA ,Y
    STA ,X
    JMP TEXTATRAWBMSP02L2DONE

TEXTATRAWBMSP02L2NO
    LDA #0
    STA ,X

TEXTATRAWBMSP02L2DONE

    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATRAWBMSP02L1X
    JMP TEXTATRAWBMSP02L1

TEXTATRAWBMSP02L1X
    LDA #1
    JMP TEXTATRAWBMSP0E

;

TEXTATRAWBMSP03

    LDA ,Y

    PSHS Y,D
    LDY #TEXTATRAWFLIP
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
    LDY #TEXTATRAWFLIP
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

TEXTATRAWBMSP03L1

    LDA <MATHPTR0
    ANDA #$03

    PSHS Y
    LDY #TEXTATRAWBITMASK
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
    LDY #TEXTATRAWBITMASK
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
    BNE TEXTATRAWBMSP03L1

    LEAX -2, X 

    PULS U
    
    LDA CURRENTSL
    LEAX A, X 

    LEAY 1, Y

    LEAU 1, U
    CMPU #8
    BEQ TEXTATRAWBMSP03L1X
    JMP TEXTATRAWBMSP03

TEXTATRAWBMSP03L1X
    LDA #2
    JMP TEXTATRAWBMSP0E

;

TEXTATRAWBMSP0E

    PULS D,Y,X

    LDA CURRENTMODE
    CMPA #3
    BEQ TEXTATRAWBMSP0E3

    LEAX 1, X

    JMP TEXTATRAWBMINCX

TEXTATRAWBMSP0E3
    LEAX 2, X

TEXTATRAWBMINCX
    INC <XCURSYS
    CMPB #0
    LBEQ TEXTATRAWBMEND2
    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATRAWBMNEXT2
    JMP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT2
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
TEXTATRAWBMNEXT2A
    LDA <YCURSYS
    CMPA CONSOLEY2
    BGT TEXTATRAWBMNEXT3
    JMP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT3

    LDA #$FF
    STA <DIRECTION
    JSR VSCROLLT

    DEC <YCURSYS

    LDA <XCURSYS
    STA <MATHPTR2
    LDA <YCURSYS
    STA <MATHPTR3
    JSR TEXTATCALCPOS

TEXTATRAWBMNEXT
    LEAY 1,Y
    CMPB #0
    BEQ TEXTATRAWBMEND
    JMP TEXTATRAWBMLOOP2
TEXTATRAWBMEND
TEXTATRAWBMEND2
    RTS

TEXTATRAWBITMASK
    fcb $00, $10, $01, $11

TEXTATRAWFLIP
    fcb $0, $8, $4, $c, $2, $a, $6, $e
    fcb $1, $9, $5, $d, $3, $b, $7, $f
