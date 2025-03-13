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
;*                           IMAGES ROUTINE FOR EF936X                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;--------------

CLSBOX

@IF vestigialConfig.doubleBufferSelected 

@ELSE

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    LBEQ CLSBOXORIG

@ENDIF

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

@IF !vestigialConfig.doubleBufferSelected || vestigialConfig.doubleBuffer

    ORCC #$50

@IF PC128OP

    PSHS D
    LDA BANKSHADOW
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

@IF vestigialConfig.screenModeUnique

@ELSE

CLSBOXDB
    LDA CURRENTMODE
    CMPA #0
    BNE CLSBOX0XDB
    JMP CLSBOX0DB
CLSBOX0XDB
    CMPA #1
    BNE CLSBOX1XDB
    JMP CLSBOX1DB
CLSBOX1XDB
    CMPA #2
    BNE CLSBOX2XDB
    JMP CLSBOX2DB
CLSBOX2XDB
    CMPA #3
    BNE CLSBOX3XDB
    JMP CLSBOX3DB
CLSBOX3XDB
    CMPA #4
    BNE CLSBOX4XDB
    JMP CLSBOX4DB
CLSBOX4XDB

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    ANDCC #$AF

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

CLSBOX1DB
CLSBOX4DB

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    ANDCC #$AF

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

CLSBOX0DB
CLSBOX2DB

    PSHS Y

    LDX BITMAPADDRESS

    ANDCC #$FE
    LDD <IMAGEY
    STD <IMAGEY2
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA

    TFR D, Y

    ANDCC #$FE
    LDD <IMAGEY
    STD <IMAGEY2
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA

    LEAY D, Y
    TFR Y, D
    LEAX D, X

    ANDCC #$FE
    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    PULS Y

    ; 128 -> 32768 pixels
    LDD ,Y
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW
    STD <IMAGEW2
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    ; 128 -> 32768 pixels
    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP CLSBOX2YDB

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

CLSBOX3DB

    PSHS Y

    CLRA
    STA <IMAGEY
    STA <IMAGEY2
    LDB <IMAGEY+1
    STB <IMAGEY2+1
    LSLB
    ROLA
    ADDD #PLOTVBASE
    TFR D, X
    LDD , X
    TFR D, X

    CLRA
    STA <(IMAGEX)
    LDB <(IMAGEX+1)
    LSRB
    LSRB
    LEAX B, X

    PULS Y

    ; 128 -> 32768 pixels
    LDD ,Y
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW
    STD <IMAGEW2
    PSHS D
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    LDA <IMAGEW
    LDB <IMAGEH
    PSHS X,D

    JMP CLSBOX2YDB

@ENDIF

;;;;;;;;;;;;;;;--------------

CLSBOX2YDB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDB
    LDD <IMAGEW
    CMPD #127
    LBLE CLSBOX2YDEFDBW128

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; --- ORIGINAL VERSION
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDBL128

    ; LDA BASE_SEGMENT+$c0
    ; ORA #$01
    ; STA BASE_SEGMENT+$c0

@IF PC128OP

    LEAX $8000,X

@ELSE

@ENDIF

    LDD <IMAGEW2
    STD <IMAGEW

CLSBOX2L1DB000
    LDB <(IMAGEW+1)
    DECB
    CLRA
CLSBOX2L1DB
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L1DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE CLSBOX2L1DB001

    LEAY 128, Y
    LEAX 128, X
    JMP CLSBOX2L1DB000

CLSBOX2L1DB001

CLSBOX2L1DBN

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE2DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP CLSBOX2L1DB000

CLSBOXCOMMONE2DBA

CLSBOXCOMMONE2DBAY

    LDD <IMAGEW2
    LEAY D, Y
    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BNE CLSBOXCOMMONE2DBAY

CLSBOXCOMMONE2DB

    LDD <IMAGEY2
    STD <IMAGEY

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

@IF PC128OP

    LEAX $6000,X

@ELSE

    LEAX $2000,X

@ENDIF

CLSBOX2L12DB000
    LDB <(IMAGEW+1)
    DECB
    CLRA
CLSBOX2L12DB
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L12DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE CLSBOX2L12DB001

    LEAY 128, Y
    LEAX 128, X
    JMP CLSBOX2L12DB000

CLSBOX2L12DB001

CLSBOX2L12DBN

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ CLSBOXCOMMONE5DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP CLSBOX2L12DB000

CLSBOXCOMMONE5DB

CLSBOXCOMMONEDB

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    ANDCC #$AF
    
	RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; --- OPTIMIZED VERSION (w < 128, no double y)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDBW128

    CMPB #1
    LBEQ CLSBOX2YDEFDBW128EVEN1
    CMPB #2
    LBEQ CLSBOX2YDEFDBW128EVEN2
    CMPB #4
    LBEQ CLSBOX2YDEFDBW128EVEN4

@IF PC128OP

    LEAX $8000,X

@ELSE

@ENDIF

    LDB <(IMAGEW2+1)
    STB <(IMAGEW+1)

CLSBOX2L1DB000W128
    ; LDB <(IMAGEW+1)
    DECB
    CLRA
CLSBOX2L1DBW128
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L1DBW128

CLSBOX2L1DBNW128

    LDB <(IMAGEW2+1)
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE2DBW128

    LDB <(IMAGEW2+1)
    STB <(IMAGEW+1)
    JMP CLSBOX2L1DB000W128

CLSBOXCOMMONE2DBW128

    LDB <(IMAGEY2+1)
    STB <(IMAGEY+1)

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

@IF PC128OP

    LEAX $6000,X

@ELSE

    LEAX $2000,X

@ENDIF

    LDB <(IMAGEW+1)

CLSBOX2L12DB000W128
    DECB
    CLRA
CLSBOX2L12DBW128
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L12DBW128

    LDB <(IMAGEW2+1)
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ CLSBOXCOMMONE5DBW128

    LDB <(IMAGEW2+1)
    STB <(IMAGEW+1)
    JMP CLSBOX2L12DB000W128

CLSBOXCOMMONE5DBW128

CLSBOXCOMMONEDBW128

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    ANDCC #$AF
    
	RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; --- OPTIMIZED VERSION (w = 1)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDBW128EVEN1

    LDA CURRENTSL
    DECA
    STA <MATHPTR0

@IF PC128OP

    LEAX $8000,X

@ELSE

@ENDIF

CLSBOX2L1DB000W128EVEN1
    CLRB
    STB ,X+

CLSBOX2L1DBNW128EVEN1

    LDA <MATHPTR0
    LEAX A, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE2DBW128EVEN1

    JMP CLSBOX2L1DB000W128EVEN1

CLSBOXCOMMONE2DBW128EVEN1

    PULS X,D
    STB <IMAGEH
    PULS D

@IF PC128OP

    LEAX $6000,X

@ELSE

    LEAX $2000,X

@ENDIF

CLSBOX2L12DB000W128EVEN1
    CLRB
    STB ,X+
    
    LDA <MATHPTR0
    LEAX A, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ CLSBOXCOMMONE5DBW128EVEN1

    JMP CLSBOX2L12DB000W128EVEN1

CLSBOXCOMMONE5DBW128EVEN1
CLSBOXCOMMONEDBW128EVEN1

    JMP CLSBOXCOMMONEDBW128EVENFINAL

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; --- OPTIMIZED VERSION (w = 2)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDBW128EVEN2

    LDA CURRENTSL
    DECA
    DECA
    STA <MATHPTR0

@IF PC128OP

    LEAX $8000,X

@ELSE

@ENDIF

CLSBOX2L1DB000W128EVEN2
    LDD #0
    STD ,X++

CLSBOX2L1DBNW128EVEN2

    LDA <MATHPTR0
    LEAX A, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE2DBW128EVEN2

    JMP CLSBOX2L1DB000W128EVEN2

CLSBOXCOMMONE2DBW128EVEN2

    PULS X,D
    STB <IMAGEH
    PULS D

@IF PC128OP

    LEAX $6000,X

@ELSE

    LEAX $2000,X

@ENDIF

CLSBOX2L12DB000W128EVEN2
    LDD #0
    STD ,X++
    
    LDA <MATHPTR0
    LEAX A, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ CLSBOXCOMMONE5DBW128EVEN2

    JMP CLSBOX2L12DB000W128EVEN2

CLSBOXCOMMONE5DBW128EVEN2
CLSBOXCOMMONEDBW128EVEN2

    JMP CLSBOXCOMMONEDBW128EVENFINAL

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; --- OPTIMIZED VERSION (w = 4)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDBW128EVEN4

    LDA CURRENTSL
    DECA
    DECA
    DECA
    DECA
    STA <MATHPTR0

    LDA <IMAGEH
    CMPA #16
    BEQ CLSBOX2YDEFDBW128EVEN4HX
    CMPA #8
    BEQ CLSBOX2YDEFDBW128EVEN4HX
    CMPA #4
    BEQ CLSBOX2YDEFDBW128EVEN4HX

@IF PC128OP

    LEAX $8000,X

@ELSE

@ENDIF

CLSBOX2L1DB000W128EVEN4
    LDD #0
    STD ,X++
    STD ,X++

CLSBOX2L1DBNW128EVEN4

    LDA <MATHPTR0
    LEAX A, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE2DBW128EVEN4

    JMP CLSBOX2L1DB000W128EVEN4

CLSBOXCOMMONE2DBW128EVEN4

    LDB <(IMAGEY2+1)
    STB <(IMAGEY+1)

    PULS X,D
    STB <IMAGEH
    PULS D

@IF PC128OP

    LEAX $6000,X

@ELSE

    LEAX $2000,X

@ENDIF

CLSBOX2L12DB000W128EVEN4
    LDD #0
    STD ,X++
    STD ,X++
    
    LDA <MATHPTR0
    LEAX A, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ CLSBOXCOMMONE5DBW128EVEN4

    JMP CLSBOX2L12DB000W128EVEN4

CLSBOXCOMMONE5DBW128EVEN4
CLSBOXCOMMONEDBW128EVEN4

    JMP CLSBOXCOMMONEDBW128EVENFINAL

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; --- OPTIMIZED VERSION (w = 4, h = 16, 8, 4)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEFDBW128EVEN4HX

@IF PC128OP

    LEAX $8000,X

@ELSE

@ENDIF

    CMPA #8
    LBEQ CLSBOX2L1DB000W128EVEN4H8
    CMPA #4
    LBEQ CLSBOX2L1DB000W128EVEN4H4

CLSBOX2L1DB000W128EVEN4H16
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
CLSBOX2L1DB000W128EVEN4H8
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
CLSBOX2L1DB000W128EVEN4H4
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++

    LDB <(IMAGEY2+1)
    STB <(IMAGEY+1)

    PULS X,D
    STB <IMAGEH
    PULS D

@IF PC128OP

    LEAX $6000,X

@ELSE

    LEAX $2000,X

@ENDIF

    LDA <IMAGEH
    CMPA #8
    LBEQ CLSBOX2L1DB000W128EVEN4H8A
    CMPA #4
    LBEQ CLSBOX2L1DB000W128EVEN4H4A

CLSBOX2L1DB000W128EVEN4H16A
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
CLSBOX2L1DB000W128EVEN4H8A
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
CLSBOX2L1DB000W128EVEN4H4A
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++
    LDA <MATHPTR0
    LEAX A, X
    LDD #0
    STD ,X++
    STD ,X++

    JMP CLSBOXCOMMONEDBW128EVENFINAL

CLSBOXCOMMONEDBW128EVENFINAL

@IF PC128OP

    PSHS D
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS D

@ENDIF

    ANDCC #$AF
    
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

@IF !vestigialConfig.doubleBufferSelected || !vestigialConfig.doubleBuffer

CLSBOXORIG

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    CMPA #0
    BNE CLSBOX0X
    JMP CLSBOX0
CLSBOX0X
    CMPA #1
    BNE CLSBOX1X
    JMP CLSBOX1
CLSBOX1X
    CMPA #2
    BNE CLSBOX2X
    JMP CLSBOX2
CLSBOX2X
    CMPA #3
    BNE CLSBOX3X
    JMP CLSBOX3
CLSBOX3X
    CMPA #4
    BNE CLSBOX4X
    JMP CLSBOX4
CLSBOX4X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

CLSBOX1
CLSBOX4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

CLSBOX0
CLSBOX2

    PSHS Y

    LDX BITMAPADDRESS

    ANDCC #$FE
    LDD <IMAGEY
    STD <IMAGEY2
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA

    TFR D, Y

    ANDCC #$FE
    LDD <IMAGEY
    STD <IMAGEY2
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA

    LEAY D, Y
    TFR Y, D
    LEAX D, X

    ANDCC #$FE
    LDD <IMAGEX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    PULS Y

    LDA ,Y
    LDB 1,Y
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW
    STD <IMAGEW2
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP CLSBOX2Y

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

CLSBOX3

    PSHS Y

    CLRA
    LDB <IMAGEY+1
    STB <IMAGEY2+1
    LSLB
    ROLA
    ADDD #PLOTVBASE
    TFR D, X
    LDD , X
@IF TO8
    ADDD BITMAPADDRESS
@ENDIF
    TFR D, X

    LDB <(IMAGEX+1)
    LSRB
    LSRB
    LEAX B, X

    PULS Y

    LDA ,Y
    LDB 1,Y
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW
    STD <IMAGEW2
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP CLSBOX2Y

@ENDIF

CLSBOX2Y

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CLSBOX2YDEF

@IF TO8

    LDA BASE_SEGMENT+$c3
    ORA #$01
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ORA #$01
    STA BASE_SEGMENT+$c0

@ENDIF

    LDD <IMAGEW2
    STD <IMAGEW
CLSBOX2L1000
    LDB <(IMAGEW+1)
    DECB
    CLRA
CLSBOX2L1
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L1

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE CLSBOX2L1001

    LEAY 128, Y
    LEAX 128, X
    JMP CLSBOX2L1000

CLSBOX2L1001

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE2

    LDD <IMAGEW2
    STD <IMAGEW
    JMP CLSBOX2L1000

CLSBOXCOMMONE2A

CLSBOXCOMMONE2

    LDD <IMAGEY2
    STD <IMAGEY

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

@IF TO8

    LDA BASE_SEGMENT+$c3
    ANDA #$fe
    STA BASE_SEGMENT+$c3

@ELSE

    LDA BASE_SEGMENT+$c0
    ANDA #$fe
    STA BASE_SEGMENT+$c0

@ENDIF

    LDD <IMAGEW2
    STD <IMAGEW
CLSBOX2L12000
    LDB <(IMAGEW+1)
    DECB
    CLRA
CLSBOX2L12
    STA B,X
    DECB
    CMPB #0
    BGE CLSBOX2L12

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE CLSBOX2L12001

    LEAY 128, Y
    LEAX 128, X
    JMP CLSBOX2L12000

CLSBOX2L12001

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ CLSBOXCOMMONE5

    LDD <IMAGEW2
    STD <IMAGEW
    JMP CLSBOX2L12000

CLSBOXCOMMONE5A

CLSBOXCOMMONE5AY

    LDD <IMAGEW2
    LEAY D, Y
    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BNE CLSBOXCOMMONE5AY

CLSBOXCOMMONE5

CLSBOXCOMMONE
    RTS
