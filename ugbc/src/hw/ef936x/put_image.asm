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
;*                           IMAGES ROUTINE FOR EF936X                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;--------------

PUTIMAGE

@IF vestigialConfig.doubleBufferSelected 

@ELSE

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    LBEQ PUTIMAGEORIG

@ENDIF

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

@IF !vestigialConfig.doubleBufferSelected || vestigialConfig.doubleBuffer

@IF vestigialConfig.screenModeUnique

@ELSE

PUTIMAGEDB
    LDA CURRENTMODE
    CMPA #0
    BNE PUTIMAGE0XDB
    JMP PUTIMAGE0DB
PUTIMAGE0XDB
    CMPA #1
    BNE PUTIMAGE1XDB
    JMP PUTIMAGE1DB
PUTIMAGE1XDB
    CMPA #2
    BNE PUTIMAGE2XDB
    JMP PUTIMAGE2DB
PUTIMAGE2XDB
    CMPA #3
    BNE PUTIMAGE3XDB
    JMP PUTIMAGE3DB
PUTIMAGE3XDB
    CMPA #4
    BNE PUTIMAGE4XDB
    JMP PUTIMAGE4DB
PUTIMAGE4XDB
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

PUTIMAGE1DB
PUTIMAGE4DB
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

PUTIMAGE0DB
PUTIMAGE2DB

    PSHS Y

    LDX BITMAPADDRESS

    ANDCC #$FE
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA

    TFR D, Y

    ANDCC #$FE
    LDD <IMAGEY
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
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    ; 128 -> 32768 pixels
    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP PUTIMAGE2YDB

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

PUTIMAGE3DB

    PSHS Y

    LDD <(IMAGEY)
    LSLB
    ROLA
    ADDD #PLOTVBASE
    TFR D, X
    LDD , X
    TFR D, X

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
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    LDA <IMAGEW
    LDB <IMAGEH
    PSHS X,D

    JMP PUTIMAGE2YDB

@ENDIF

PUTIMAGE2YDB
    LDA <IMAGET
    LBEQ PUTIMAGE2YDEFDB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGE2YTRANSDB
    LDA CURRENTMODE
    ; CMPA #2
    ; BEQ PUTIMAGE2YTRANS2
    CMPA #3
    BEQ PUTIMAGE2YTRANS3DB
    JMP PUTIMAGE2YDEFDB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGE2YTRANS3DB
    ; LDA $a7c0
    ; ORA #$01
    ; STA $a7c0

    LEAX $8000,X

    LDD <IMAGEW
    STD <IMAGEW2
PUTIMAGE2YTRANS3L1DB000
    LDB <(IMAGEW+1)
    ANDB #$7F
    DECB
PUTIMAGE2YTRANS3L1DB
    LDA #0
    STA <MATHPTR5
    LDA B,Y
    ; 00 01 10 00
    ANDA #$F0
    ; -> 00 00 00 00
    BEQ PUTIMAGE2YTRANS3L1P4XDB
    LDA <MATHPTR5
    ORA #$F0
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P4XDB
    LDA B,Y
    ; 00 01 10 00
    ANDA #$0F
    ; -> 00 01 00 00
    BEQ PUTIMAGE2YTRANS3L1P3XDB
    LDA <MATHPTR5
    ORA #$0F
    ; MATH PTR = 00 11 00 00
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P3XDB
    LDA <MATHPTR5
    ; 00 11 11 00
    EORA #$FF
    ; 11 00 00 11
    STA <MATHPTR6
    LDA B,X
    ; 00 00 00 00
    ANDA <MATHPTR6
    STA <MATHPTR6
    ; 00 00 00 00
    LDA B,Y
    ANDA <MATHPTR5
    ORA <MATHPTR6
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2YTRANS3L1DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2YTRANS3L1DB001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2YTRANS3L1DB000

PUTIMAGE2YTRANS3L1DB001
    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2YTRANS3L1DBN

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2YTRANS3L1DBN0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2YTRANS3L1DB000

PUTIMAGE2YTRANS3L1DBN0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2YTRANS3L1DBN

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGE2YTRANS3COMMONE2DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP PUTIMAGE2YTRANS3L1DB000

PUTIMAGE2YTRANS3COMMONE2DB

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW
    STD <IMAGEW2

    LEAX $6000,X

    ; LDA $a7c0
    ; ANDA #$fe
    ; STA $a7c0

PUTIMAGE2YTRANS3L12DB000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2YTRANS3L12DB
    LDA #0
    STA <MATHPTR5
    LDA B,Y
    ; 00 01 10 00
    ANDA #$F0
    ; -> 00 00 00 00
    BEQ PUTIMAGE2YTRANS3L12P4XDB
    LDA <MATHPTR5
    ORA #$F0
    STA <MATHPTR5
PUTIMAGE2YTRANS3L12P4XDB
    LDA B,Y
    ; 00 01 10 00
    ANDA #$0F
    ; -> 00 01 00 00
    BEQ PUTIMAGE2YTRANS3L12P3XDB
    LDA <MATHPTR5
    ORA #$0F
    ; MATH PTR = 00 11 00 00
    STA <MATHPTR5
PUTIMAGE2YTRANS3L12P3XDB
    LDA <MATHPTR5
    ; 00 11 11 00
    EORA #$FF
    ; 11 00 00 11
    STA <MATHPTR6
    LDA B,X
    ; 00 00 00 00
    ANDA <MATHPTR6
    STA <MATHPTR6
    ; 00 00 00 00
    LDA B,Y
    ANDA <MATHPTR5
    ORA <MATHPTR6
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2YTRANS3L12DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2YTRANS3L12DB001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2YTRANS3L12DB000

PUTIMAGE2YTRANS3L12DB001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2YTRANS3L12DBN

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2YTRANS3L12DBN0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2YTRANS3L12DB000

PUTIMAGE2YTRANS3L12DBN0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2YTRANS3L12DBN

    LDB <IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ PUTIMAGECOMMONE5DB

    LDB <(IMAGEW+1)
    DECB
    JMP PUTIMAGE2YTRANS3L12DB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGE2YDEFDB
    ; LDA $a7c0
    ; ORA #$01
    ; STA $a7c0

    LEAX $8000,X

    LDD <IMAGEW2
    STD <IMAGEW

PUTIMAGE2L1DB000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2L1DB
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L1DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2L1DB001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2L1DB000

PUTIMAGE2L1DB001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2L1DBN

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2L1DBN0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2L1DB000

PUTIMAGE2L1DBN0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2L1DBN

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE2DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP PUTIMAGE2L1DB000

PUTIMAGECOMMONE2DB

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

    LEAX $6000,X

    ; LDA $a7c0
    ; ANDA #$fe
    ; STA $a7c0

PUTIMAGE2L12DB000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2L12DB
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L12DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2L12DB001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2L12DB000

PUTIMAGE2L12DB001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2L12DBN

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2L12DBN0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2L12DB000

PUTIMAGE2L12DBN0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2L12DBN

    LDB <IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ PUTIMAGECOMMONE5DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP PUTIMAGE2L12DB000

PUTIMAGECOMMONE5DB
;     LDA CURRENTMODE
;     CMPA #3
;     BEQ PUTIMAGECOMMONE53
;     LDU #4
;     JMP PUTIMAGECOMMONE50
; PUTIMAGECOMMONE53
;     LDU #16
;     JMP PUTIMAGECOMMONE50

; PUTIMAGECOMMONE50
;     LDA #0
;     STA $A7DB
; PUTIMAGECOMMONE50L1
;     LDD ,Y
;     LEAY 2,Y
;     STB $A7DA
;     STA $A7DA
;     LEAU -1, U
;     CMPU #$FFFF
    ; BNE PUTIMAGECOMMONE50L1

PUTIMAGECOMMONEDB

	RTS

@ENDIF

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

@IF !vestigialConfig.doubleBufferSelected || !vestigialConfig.doubleBuffer

PUTIMAGEORIG

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    CMPA #0
    BNE PUTIMAGE0X
    JMP PUTIMAGE0
PUTIMAGE0X
    CMPA #1
    BNE PUTIMAGE1X
    JMP PUTIMAGE1
PUTIMAGE1X
    CMPA #2
    BNE PUTIMAGE2X
    JMP PUTIMAGE2
PUTIMAGE2X
    CMPA #3
    BNE PUTIMAGE3X
    JMP PUTIMAGE3
PUTIMAGE3X
    CMPA #4
    BNE PUTIMAGE4X
    JMP PUTIMAGE4
PUTIMAGE4X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

PUTIMAGE1
PUTIMAGE4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

PUTIMAGE0
PUTIMAGE2

    PSHS Y

    LDX BITMAPADDRESS

    ANDCC #$FE
    LDD <IMAGEY
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA

    TFR D, Y

    ANDCC #$FE
    LDD <IMAGEY
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
    STD <IMAGEW2
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 3,Y

    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP PUTIMAGE2Y

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

PUTIMAGE3

    PSHS Y

    LDD <(IMAGEY)
    LSLB
    ROLA
    ADDD #PLOTVBASE
    TFR D, X
    LDD , X
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

    JMP PUTIMAGE2Y

@ENDIF

PUTIMAGE2Y
    LDA <IMAGET
    LBEQ PUTIMAGE2YDEF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGE2YTRANS
    LDA CURRENTMODE
    ; CMPA #2
    ; BEQ PUTIMAGE2YTRANS2
    CMPA #3
    BEQ PUTIMAGE2YTRANS3
    JMP PUTIMAGE2YDEF

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGE2YTRANS3
    LDA $a7c0
    ORA #$01
    STA $a7c0

PUTIMAGE2YTRANS3L1000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2YTRANS3L1
    LDA #0
    STA <MATHPTR5
    LDA B,Y
    ; 00 01 10 00
    ANDA #$F0
    ; -> 00 00 00 00
    BEQ PUTIMAGE2YTRANS3L1P4X
    LDA <MATHPTR5
    ORA #$F0
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P4X
    LDA B,Y
    ; 00 01 10 00
    ANDA #$0F
    ; -> 00 01 00 00
    BEQ PUTIMAGE2YTRANS3L1P3X
    LDA <MATHPTR5
    ORA #$0F
    ; MATH PTR = 00 11 00 00
    STA <MATHPTR5
PUTIMAGE2YTRANS3L1P3X
    LDA <MATHPTR5
    ; 00 11 11 00
    EORA #$FF
    ; 11 00 00 11
    STA <MATHPTR6
    LDA B,X
    ; 00 00 00 00
    ANDA <MATHPTR6
    STA <MATHPTR6
    ; 00 00 00 00
    LDA B,Y
    ANDA <MATHPTR5
    ORA <MATHPTR6
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2YTRANS3L1

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2YTRANS3L1001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2YTRANS3L1000

PUTIMAGE2YTRANS3L1001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2YTRANS3L1N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2YTRANS3L1N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2YTRANS3L1000

PUTIMAGE2YTRANS3L1N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2YTRANS3L1N

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGE2YTRANS3COMMONE2

    LDD <IMAGEW2
    STD <IMAGEW
    JMP PUTIMAGE2YTRANS3L1000

PUTIMAGE2YTRANS3COMMONE2

    PULS X,D
    STB <IMAGEH
    PULS D
    STA <IMAGEW

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

PUTIMAGE2YTRANS3L12000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2YTRANS3L12
    LDA #0
    STA <MATHPTR5
    LDA B,Y
    ; 00 01 10 00
    ANDA #$F0
    ; -> 00 00 00 00
    BEQ PUTIMAGE2YTRANS3L12P4X
    LDA <MATHPTR5
    ORA #$F0
    STA <MATHPTR5
PUTIMAGE2YTRANS3L12P4X
    LDA B,Y
    ; 00 01 10 00
    ANDA #$0F
    ; -> 00 01 00 00
    BEQ PUTIMAGE2YTRANS3L12P3X
    LDA <MATHPTR5
    ORA #$0F
    ; MATH PTR = 00 11 00 00
    STA <MATHPTR5
PUTIMAGE2YTRANS3L12P3X
    LDA <MATHPTR5
    ; 00 11 11 00
    EORA #$FF
    ; 11 00 00 11
    STA <MATHPTR6
    LDA B,X
    ; 00 00 00 00
    ANDA <MATHPTR6
    STA <MATHPTR6
    ; 00 00 00 00
    LDA B,Y
    ANDA <MATHPTR5
    ORA <MATHPTR6
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2YTRANS3L12

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2YTRANS3L12001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2YTRANS3L12000

PUTIMAGE2YTRANS3L12001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2YTRANS3L12N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2YTRANS3L12N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW2
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2YTRANS3L12000

PUTIMAGE2YTRANS3L12N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2YTRANS3L12N

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ PUTIMAGECOMMONE5

    LDU <IMAGEW2
    STU >IMAGEW2
    JMP PUTIMAGE2YTRANS3L12000

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTIMAGE2YDEF
    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDD <IMAGEW2
    STD <IMAGEW
PUTIMAGE2L1000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2L1
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L1

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2L1001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2L1000

PUTIMAGE2L1001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2L1N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2L1N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2L1000

PUTIMAGE2L1N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2L1N

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE2

    LDD <IMAGEW2
    STD <IMAGEW
    JMP PUTIMAGE2L1000

PUTIMAGECOMMONE2

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDD <IMAGEW2
    STD <IMAGEW
PUTIMAGE2L12000
    LDB <(IMAGEW+1)
    DECB
PUTIMAGE2L12
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L12

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE PUTIMAGE2L12001

    LEAY 128, Y
    LEAX 128, X
    JMP PUTIMAGE2L12000

PUTIMAGE2L12001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ PUTIMAGE2L12N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ PUTIMAGE2L12N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP PUTIMAGE2L12000

PUTIMAGE2L12N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

PUTIMAGE2L12N

    LDD <IMAGEW2
    LEAY D, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE5

    LDD <IMAGEW2
    STD <IMAGEW
    JMP PUTIMAGE2L12000

PUTIMAGECOMMONE5
;     LDA CURRENTMODE
;     CMPA #3
;     BEQ PUTIMAGECOMMONE53
;     LDU #4
;     JMP PUTIMAGECOMMONE50
; PUTIMAGECOMMONE53
;     LDU #16
;     JMP PUTIMAGECOMMONE50

; PUTIMAGECOMMONE50
;     LDA #0
;     STA $A7DB
; PUTIMAGECOMMONE50L1
;     LDD ,Y
;     LEAY 2,Y
;     STB $A7DA
;     STA $A7DA
;     LEAU -1, U
;     CMPU #$FFFF
    ; BNE PUTIMAGECOMMONE50L1

PUTIMAGECOMMONE
    RTS

@ENDIF