; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

BLITIMAGEBLITADDR  fdb $0

;--------------

BLITIMAGE

@IF vestigialConfig.doubleBufferSelected 

@ELSE

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    LBEQ BLITIMAGEORIG

@ENDIF

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

@IF !vestigialConfig.doubleBufferSelected || vestigialConfig.doubleBuffer

@IF vestigialConfig.screenModeUnique

@ELSE

BLITIMAGEDB
    LDA CURRENTMODE
    CMPA #0
    BNE BLITIMAGE0XDB
    JMP BLITIMAGE0DB
BLITIMAGE0XDB
    CMPA #1
    BNE BLITIMAGE1XDB
    JMP BLITIMAGE1DB
BLITIMAGE1XDB
    CMPA #2
    BNE BLITIMAGE2XDB
    JMP BLITIMAGE2DB
BLITIMAGE2XDB
    CMPA #3
    BNE BLITIMAGE3XDB
    JMP BLITIMAGE3DB
BLITIMAGE3XDB
    CMPA #4
    BNE BLITIMAGE4XDB
    JMP BLITIMAGE4DB
BLITIMAGE4XDB
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

BLITIMAGE1DB
BLITIMAGE4DB
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

BLITIMAGE0DB
BLITIMAGE2DB

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

    LDY BLITTMPPTR
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

    LDY BLITTMPPTR
    LEAY 3, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 3, Y
    STY BLITTMPPTR2

    ; 128 -> 32768 pixels
    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP BLITIMAGE2YDB

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

BLITIMAGE3DB

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

    LDY BLITTMPPTR
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

    LDY BLITTMPPTR
    LEAY 3, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 3, Y
    STY BLITTMPPTR2

    LDA <IMAGEW
    LDB <IMAGEH
    PSHS X,D

    JMP BLITIMAGE2YDB

@ENDIF

BLITIMAGE2YDB

    LEAX $8000,X

    LDD <IMAGEW2
    STD <IMAGEW

BLITIMAGE2L1DB000
    LDB <(IMAGEW+1)
    DECB
BLITIMAGE2L1DB

    LDA B,X
    STA BLITS0
    LDY BLITTMPPTR
    LDA B, Y
    STA BLITS1
    LDY BLITTMPPTR2
    LDA B, Y
    STA BLITS2
    JSR [BLITIMAGEBLITADDR]
    STA B,X

    DECB
    CMPB #0
    BGE BLITIMAGE2L1DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE BLITIMAGE2L1DB001

    LDY BLITTMPPTR
    LEAY 128, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 128, Y
    STY BLITTMPPTR2
    LEAX 128, X
    JMP BLITIMAGE2L1DB000

BLITIMAGE2L1DB001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGE2L1DBN

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGE2L1DBN0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP BLITIMAGE2L1DB000

BLITIMAGE2L1DBN0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

BLITIMAGE2L1DBN

    LDD <IMAGEW2

    LDY BLITTMPPTR
    LEAY D, Y
    STY BLITTMPPTR

    LDY BLITTMPPTR2
    LEAY D, Y
    STY BLITTMPPTR2

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONE2DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP BLITIMAGE2L1DB000

BLITIMAGECOMMONE2DB

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

    LEAX $6000,X

    ; LDA $a7c0
    ; ANDA #$fe
    ; STA $a7c0

BLITIMAGE2L12DB000
    LDB <(IMAGEW+1)
    DECB
BLITIMAGE2L12DB

    LDA B,X
    STA BLITS0
    LDY BLITTMPPTR
    LDA B, Y
    STA BLITS1
    LDY BLITTMPPTR2
    LDA B, Y
    STA BLITS2
    JSR [BLITIMAGEBLITADDR]
    STA B,X

    DECB
    CMPB #0
    BGE BLITIMAGE2L12DB

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE BLITIMAGE2L12DB001

    LDY BLITTMPPTR
    LEAY 128, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 128, Y
    STY BLITTMPPTR2
    LEAX 128, X
    JMP BLITIMAGE2L12DB000

BLITIMAGE2L12DB001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGE2L12DBN

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGE2L12DBN0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP BLITIMAGE2L12DB000

BLITIMAGE2L12DBN0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

BLITIMAGE2L12DBN

    LDB <IMAGEW

    LDY BLITTMPPTR
    LEAY B, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY B, Y
    STY BLITTMPPTR2

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    LBEQ BLITIMAGECOMMONE5DB

    LDD <IMAGEW2
    STD <IMAGEW
    JMP BLITIMAGE2L12DB000

BLITIMAGECOMMONE5DB
;     LDY BLITTMPPTR
;     LEAY D, Y
;     STY BLITTMPPTR
;     LDA CURRENTMODE
;     CMPA #3
;     BEQ BLITIMAGECOMMONE53xx
;     LDU #4
;     JMP BLITIMAGECOMMONE50xx
; BLITIMAGECOMMONE53xx
;     LDU #16
;     JMP BLITIMAGECOMMONE50xx

; BLITIMAGECOMMONE50xx
;     LDA #0
;     STA $A7DB
; BLITIMAGECOMMONE50L1xx
;     LDD ,Y
;     LEAY 2,Y
;     STB $A7DA
;     STA $A7DA
;     LEAU -1, U
;     CMPU #$FFFF
;     BNE BLITIMAGECOMMONE50L1xx

BLITIMAGECOMMONEDB

	RTS

@ENDIF

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

@IF !vestigialConfig.doubleBufferSelected || !vestigialConfig.doubleBuffer

BLITIMAGEORIG

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    CMPA #0
    BNE BLITIMAGE0X
    JMP BLITIMAGE0
BLITIMAGE0X
    CMPA #1
    BNE BLITIMAGE1X
    JMP BLITIMAGE1
BLITIMAGE1X
    CMPA #2
    BNE BLITIMAGE2X
    JMP BLITIMAGE2
BLITIMAGE2X
    CMPA #3
    BNE BLITIMAGE3X
    JMP BLITIMAGE3
BLITIMAGE3X
    CMPA #4
    BNE BLITIMAGE4X
    JMP BLITIMAGE4
BLITIMAGE4X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) || ( currentMode == 4 ) )

BLITIMAGE1
BLITIMAGE4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

BLITIMAGE0
BLITIMAGE2

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

    LDY BLITTMPPTR
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

    LDY BLITTMPPTR
    LEAY 3, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 3, Y
    STY BLITTMPPTR2

    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP BLITIMAGE2Y

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

BLITIMAGE3

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

    LDY BLITTMPPTR
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

    LDY BLITTMPPTR
    LEAY 3, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 3, Y
    STY BLITTMPPTR2

    LDD <IMAGEW
    PSHS D
    LDB <IMAGEH
    PSHS X,D

    JMP BLITIMAGE2Y

@ENDIF

BLITIMAGE2Y
    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDD <IMAGEW2
    STD <IMAGEW
BLITIMAGE2L1000
    LDB <(IMAGEW+1)
    DECB
BLITIMAGE2L1

    LDA B,X
    STA BLITS0
    LDY BLITTMPPTR
    LDA B, Y
    STA BLITS1
    LDY BLITTMPPTR2
    LDA B, Y
    STA BLITS2
    JSR [BLITIMAGEBLITADDR]
    STA B,X

    DECB
    CMPB #0
    BGE BLITIMAGE2L1

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE BLITIMAGE2L1001

    LDY BLITTMPPTR
    LEAY 128, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 128, Y
    STY BLITTMPPTR2
    LEAX 128, X
    JMP BLITIMAGE2L1000

BLITIMAGE2L1001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGE2L1N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGE2L1N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP BLITIMAGE2L1000

BLITIMAGE2L1N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

BLITIMAGE2L1N

    LDD <IMAGEW2

    LDY BLITTMPPTR
    LEAY D, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY D, Y
    STY BLITTMPPTR2

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONE2

    LDD <IMAGEW2
    STD <IMAGEW
    JMP BLITIMAGE2L1000

BLITIMAGECOMMONE2

    PULS X,D
    STB <IMAGEH
    PULS D
    STD <IMAGEW

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDD <IMAGEW2
    STD <IMAGEW
BLITIMAGE2L12000
    LDB <(IMAGEW+1)
    DECB
BLITIMAGE2L12

    LDA B,X
    STA BLITS0
    LDY BLITTMPPTR
    LDA B, Y
    STA BLITS1
    LDY BLITTMPPTR2
    LDA B, Y
    STA BLITS2
    JSR [BLITIMAGEBLITADDR]
    STA B,X

    DECB
    CMPB #0
    BGE BLITIMAGE2L12

    LDU <IMAGEW
    LEAU -128, U
    STU <IMAGEW
    CMPU #0
    BLE BLITIMAGE2L12001

    LDY BLITTMPPTR
    LEAY 128, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY 128, Y
    STY BLITTMPPTR2

    LEAX 128, X
    JMP BLITIMAGE2L12000

BLITIMAGE2L12001

    LDA <IMAGEF
    ANDA #64
    CMPA #0
    BEQ BLITIMAGE2L12N

    LDA <IMAGEF
    ANDA #1
    CMPA #1
    BEQ BLITIMAGE2L12N0

    ORA #65
    STA <IMAGEF

    LDD <IMAGEW2
    STD <IMAGEW
    LDB CURRENTSL
    LEAX B, X
    JMP BLITIMAGE2L12000

BLITIMAGE2L12N0
    LDA <IMAGEF
    ANDA #$FE
    STA <IMAGEF

BLITIMAGE2L12N

    LDD <IMAGEW2

    LDY BLITTMPPTR
    LEAY D, Y
    STY BLITTMPPTR
    LDY BLITTMPPTR2
    LEAY D, Y
    STY BLITTMPPTR2

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ BLITIMAGECOMMONE5

    LDD <IMAGEW2
    STD <IMAGEW
    JMP BLITIMAGE2L12000

BLITIMAGECOMMONE5
    LDY BLITTMPPTR
    LEAY D, Y
    STY BLITTMPPTR
    LDA CURRENTMODE
    CMPA #3
    BEQ BLITIMAGECOMMONE53
    LDU #4
    JMP BLITIMAGECOMMONE50
BLITIMAGECOMMONE53
    LDU #16
    JMP BLITIMAGECOMMONE50

BLITIMAGECOMMONE50
;     LDA #0
;     STA $A7DB
; BLITIMAGECOMMONE50L1
;     LDD ,Y
;     LEAY 2,Y
;     STB $A7DA
;     STA $A7DA
;     LEAU -1, U
;     CMPU #$FFFF
;     BNE BLITIMAGECOMMONE50L1

BLITIMAGECOMMONE
    RTS

@ENDIF