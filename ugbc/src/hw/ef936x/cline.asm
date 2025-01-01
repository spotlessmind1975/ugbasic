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
;*                       CLEAR LINE ROUTINE FOR GIME                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINEGGO

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ CLINEGGOORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

CLINEGGODB
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

CLINEGGOORIG

    LDY TEXTADDRESS
    STY <COPYOFTEXTADDRESS

    LDA CURRENTMODE
    CMPA #0
    BNE CLINEG0X
    JMP CLINEG0
CLINEG0X
    CMPA #1
    BNE CLINEG1X
    JMP CLINEG1
CLINEG1X
    CMPA #2
    BNE CLINEG2X
    JMP CLINEG2
CLINEG2X
    CMPA #3
    BNE CLINEG3X
    JMP CLINEG3
CLINEG3X
    CMPA #4
    BNE CLINEG4X
    JMP CLINEG4
CLINEG4X
    RTS
    
CLINEG

CLINEG0
CLINEG1
CLINEG2
CLINEG3
CLINEG4

    LDA <CLINEX
    STA <MATHPTR2
    LDA <CLINEY
    STA <MATHPTR3

    JSR TEXTATCALCPOS

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

    LDB <CHARACTERS
CLINEGBMLOOP2

CLINEGBMSP0

    PSHS D,Y,X

    LDA CURRENTMODE
    CMPA #0
    BNE CLINEGBMSP00X
    JMP CLINEGBMSP00
CLINEGBMSP00X
    CMPA #1
    BNE CLINEGBMSP01X
    JMP CLINEGBMSP01
CLINEGBMSP01X
    CMPA #2
    BNE CLINEGBMSP02X
    JMP CLINEGBMSP02
CLINEGBMSP02X
    CMPA #3
    BNE CLINEGBMSP03X
    JMP CLINEGBMSP03
CLINEGBMSP03X
    CMPA #4
    BNE CLINEGBMSP04X
    JMP CLINEGBMSP04
CLINEGBMSP04X
    JMP CLINEGBMSP0E

CLINEGBMSP00
CLINEGBMSP01
CLINEGBMSP04

    LDU #0

CLINEGBMSP0L1

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

    CLRA
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

    CLRA
    STA ,X

    JMP CLINEGBMSP0L1M2

CLINEGBMSP0L1M

    CLRA
    STA , X+
    STA , X

    JMP CLINEGBMSP0L1M2

CLINEGBMSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    LEAU 1, U
    CMPU #8
    BEQ CLINEGBMSP0L1X
    JMP CLINEGBMSP0L1

CLINEGBMSP0L1X
    LDA #1
    JMP CLINEGBMSP0E

CLINEGBMSP02

CLINEGBMSP02L1

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

    CLRA
    STA ,X
    JMP CLINEGBMSP02L1DONE

CLINEGBMSP02L1NO
    CLRA
    STA ,X

CLINEGBMSP02L1DONE

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

    CLRA
    STA ,X
    JMP CLINEGBMSP02L2DONE

CLINEGBMSP02L2NO
    CLRA
    STA ,X

CLINEGBMSP02L2DONE

    LDA CURRENTSL
    LEAX A, X 

    LEAU 1, U
    CMPU #8
    BEQ CLINEGBMSP02L1X
    JMP CLINEGBMSP02L1

CLINEGBMSP02L1X
    LDA #1
    JMP CLINEGBMSP0E

;

CLINEGBMSP03

    LDU #0

CLINEGBMSP03L1X2

    LDA #0

    PSHS U
    LDU #2

CLINEGBMSP03L1

@IF TO8

    LDB BASE_SEGMENT+$c3
    ANDB #$fe
    STB BASE_SEGMENT+$c3

@ELSE

    LDB BASE_SEGMENT+$c0
    ORB #$01
    STB BASE_SEGMENT+$c0

@ENDIF

    CLRA
    STA ,X

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

    LEAU -1, U

    CMPU #0
    BNE CLINEGBMSP03L1

    LEAX -2, X 

    PULS U
    
    LDA CURRENTSL
    LEAX A, X 

    LEAU 1, U
    CMPU #8
    BEQ CLINEGBMSP03L1X
    JMP CLINEGBMSP03L1X2

CLINEGBMSP03L1X
    LDA #2
    JMP CLINEGBMSP0E

;

CLINEGBMSP0E

    PULS D,Y,X

    LDA CURRENTMODE
    CMPA #3
    BEQ CLINEGBMSP0E3

    LEAX 1, X

    JMP CLINEGBMINCX

CLINEGBMSP0E3
    LEAX 2, X

    JMP CLINEGBMINCX

CLINEGBMINCX
    INC <CLINEX
    LDA <CLINEX
    CMPA CONSOLEX2
    BGT CLINEGBMNEXT2
    JMP CLINEGBMNEXT
CLINEGBMNEXT2
    RTS

CLINEGBMNEXT
    DECB
    BEQ CLINEGBMEND
    JMP CLINEGBMLOOP2
CLINEGBMEND
    RTS
