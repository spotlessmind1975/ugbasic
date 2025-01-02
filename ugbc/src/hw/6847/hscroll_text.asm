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
;*                          HIRIZONTAL SCROLL ON 6847                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF horizontalOverlapRequired

HSCROLLBUFFERCHARACTER FCB  0

@ENDIF

HSCROLLST
    LDX TEXTADDRESS
    LDA CONSOLEY1
    LDB CURRENTTILESWIDTH
    MUL
    LEAX D, X

HSCROLLSTB
    LDB CONSOLEH
    DECB
    LDA #0
    TFR D, U
    LEAU 1,U

    TFR X, Y
    LEAY 1, Y

HSCROLLSTL1
    LDA <DIRECTION
    CMPA #$00
    BGT HSCROLLSTRIGHT

HSCROLLSTLEFT

@IF horizontalOverlapRequired

    LDA PORT
    BEQ HSCROLLSTLEFTNOW

HSCROLLSTLEFTW
    LDB CONSOLEX1
    LDA B,X
    STA HSCROLLBUFFERCHARACTER
    INCB

    BRA HSCROLLSTLEFTL1

HSCROLLSTLEFTNOW

@ENDIF

    LDB CONSOLEX1
    INCB
HSCROLLSTLEFTL1
    LDA B,Y
    STA B,X
    INCB
    CMPB CONSOLEX2
    BNE HSCROLLSTLEFTL1

@IF horizontalOverlapRequired

    LDA PORT
    BEQ HSCROLLSTLEFTFILLNOW

HSCROLLSTLEFTFILLW
    LDA HSCROLLBUFFERCHARACTER
    BRA HSCROLLSTLEFTL1XX

@ENDIF

HSCROLLSTLEFTFILLNOW
    LDA EMPTYTILE
HSCROLLSTLEFTL1XX
    STA B,X

    LDA CURRENTWIDTH+1
    LEAX A, X
    LEAY A, Y

    LEAU -1, U
    CMPU #0
    BNE HSCROLLSTLEFT
    RTS

HSCROLLSTRIGHT

@IF horizontalOverlapRequired

    LDA PORT
    BEQ HSCROLLSTRIGHTNOW

HSCROLLSTRIGHTW
    LDB CONSOLEX2
    LDA B,X
    STA HSCROLLBUFFERCHARACTER
    DECB

    BRA HSCROLLSTRIGHTL1

HSCROLLSTRIGHTNOW

@ENDIF

    LDB CONSOLEX2
    DECB
HSCROLLSTRIGHTL1
    LDA B,X
    STA B,Y
    DECB
    CMPB CONSOLEX1
    BGT HSCROLLSTRIGHTL1

@IF horizontalOverlapRequired

    LDA PORT
    BEQ HSCROLLSTRIGHTFILLNOW

HSCROLLSTRIGHTFILLW
    LDA HSCROLLBUFFERCHARACTER
    BRA HSCROLLSTRIGHTL1XX

HSCROLLSTRIGHTFILLNOW

@ENDIF

    LDA EMPTYTILE

HSCROLLSTRIGHTL1XX
    STA B,X

    LDA CURRENTTILESWIDTH
    LEAX A, X
    LEAY A, Y

    LEAU -1, U
    CMPU #$0
    BNE HSCROLLSTRIGHT
    RTS

HSCROLLLT
    LDA <DIRECTION
    CMPA #$0
    BGT HSCROLLLRIGHT

HSCROLLLLEFT
    LDX TEXTADDRESS
    LDA CONSOLEY1
    LDB CURRENTTILESWIDTH
    MUL
    LEAX D, X
    LDA CONSOLEX1
    LEAX A, X

    LDA CONSOLEW

    LDB <CLINEY
    CMPB #0
    BEQ HSCROLLLLEFTTLS
HSCROLLLTLL1
    LEAX A, X
    DECB
    CMPB #$0
    BNE HSCROLLLTLL1

HSCROLLLLEFTTLS
    TFR X, Y
    LEAY 1, Y

    LDB #0
HSCROLLLLEFTL1
    LDA B,Y
    STA B,X
    INCB
    CMPB CONSOLEW
    BNE HSCROLLLLEFTL1
    DECB
    LDA EMPTYTILE
    STA B,X
    RTS

HSCROLLLRIGHT
    LDX TEXTADDRESS
    LDA CONSOLEY1
    LDB CURRENTTILESWIDTH
    MUL
    LEAX D, X
    LDA CONSOLEX1
    LEAX A, X    
    LDA CONSOLEW

    LDB <CLINEY
    CMPB #0
    BEQ HSCROLLLRIGHTTLS
HSCROLLLTLL1B
    LEAX A, X
    DECB
    CMPB #$0
    BNE HSCROLLLTLL1B

HSCROLLLRIGHTTLS
    TFR X, Y
    LEAY 1, Y
    LDB CONSOLEW
    DECB
    DECB
HSCROLLLRIGHTL1
    LDA B,X
    STA B,Y
    DECB
    CMPB #$FF
    BNE HSCROLLLRIGHTL1
    INCB
    LDA EMPTYTILE
    STA B,X
    RTS
    