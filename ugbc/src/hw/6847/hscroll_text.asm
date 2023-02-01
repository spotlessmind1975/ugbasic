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
;*                          HIRIZONTAL SCROLL ON 6847                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLST
    LDX TEXTADDRESS
 
    LDU CURRENTHEIGHT
    LEAU 1,U

    TFR X, Y
    LEAY 1, Y

HSCROLLSTL1
    LDA DIRECTION
    CMPA #$00
    BGT HSCROLLSTRIGHT

HSCROLLSTLEFT
    LDB #0
HSCROLLSTLEFTL1
    LDA B,Y
    STA B,X
    INCB
    CMPB CURRENTWIDTH+1
    BNE HSCROLLSTLEFTL1
    DECB
    DECB
    LDA EMPTYTILE
    STA B,Y

    LDA CURRENTWIDTH+1
    LEAX A, X
    LEAY A, Y

    LEAU -1, U
    CMPU #0
    BNE HSCROLLSTLEFT
    RTS

HSCROLLSTRIGHT
    LDB CURRENTWIDTH+1
HSCROLLSTRIGHTL1
    LDA B,X
    STA B,Y
    DECB
    CMPB #0
    BNE HSCROLLSTRIGHTL1
    LDA EMPTYTILE
    STA B,Y

    LDA CURRENTWIDTH+1
    LEAX A, X
    LEAY A, Y

    LEAU -1, U
    CMPU #0
    BNE HSCROLLSTRIGHT
    RTS

HSCROLLLT
    LDA DIRECTION
    CMPA #$0
    BGT HSCROLLLRIGHT

HSCROLLLLEFT
    LDX TEXTADDRESS
    LDA CURRENTWIDTH+1

    LDB CLINEY
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
    CMPB CURRENTWIDTH+1
    BNE HSCROLLLLEFTL1
    DECB
    LDA EMPTYTILE
    STA B,X
    RTS


HSCROLLLRIGHT
    LDX TEXTADDRESS
    LDA CURRENTWIDTH+1

    LDB CLINEY
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
    LDB CURRENTWIDTH+1
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
    