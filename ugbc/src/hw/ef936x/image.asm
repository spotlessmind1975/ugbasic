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
;*                          IMAGES ROUTINE FOR OLIVETTI PC128 PRODEST          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IMAGEX EQU $41 ; $42
IMAGEY EQU $43 ; $44
IMAGEW EQU $45
IMAGEH EQU $46
IMAGEH2 EQU $47

;--------------

PUTIMAGE
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

PUTIMAGE1
PUTIMAGE4
    RTS

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
    LSRA
    LSRA
    LSRA
    STA <IMAGEW
    LDA 1,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 2,Y

    LDA <IMAGEW
    LDB <IMAGEH
    PSHS X,D

    JMP PUTIMAGE2Y

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
    LSRA
    LSRA
    STA <IMAGEW
    LDA 1,Y
    STA <IMAGEH
    STA <IMAGEH2

    LEAY 2,Y

    LDA <IMAGEW
    LDB <IMAGEH
    PSHS X,D

    JMP PUTIMAGE2Y

PUTIMAGE2Y
    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDB <IMAGEW
    DECB
PUTIMAGE2L1
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L1

    LDB <IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE2

    LDB <IMAGEW
    DECB
    JMP PUTIMAGE2L1

PUTIMAGECOMMONE2

    PULS X,D

    STA <IMAGEW
    STB <IMAGEH

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDB <IMAGEW
    DECB
PUTIMAGE2L12
    LDA B,Y
    STA B,X
    DECB
    CMPB #0
    BGE PUTIMAGE2L12

    LDB <IMAGEW
    LEAY B, Y

    LDB CURRENTSL
    LEAX B, X

    DEC <IMAGEH
    LDB <IMAGEH
    CMPB #0
    BEQ PUTIMAGECOMMONE5

    LDB <IMAGEW
    DECB
    JMP PUTIMAGE2L12

PUTIMAGECOMMONE5
    LDA CURRENTMODE
    CMPA #3
    BEQ PUTIMAGECOMMONE53
    LDU #4
    JMP PUTIMAGECOMMONE50
PUTIMAGECOMMONE53
    LDU #16
    JMP PUTIMAGECOMMONE50

PUTIMAGECOMMONE50
    LDA #0
    STA $A7DB
PUTIMAGECOMMONE50L1
    LDD ,Y
    LEAY 2,Y
    STB $A7DA
    STA $A7DA
    LEAU -1, U
    CMPU #$FFFF
    BNE PUTIMAGECOMMONE50L1

PUTIMAGECOMMONE
    RTS
