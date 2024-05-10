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
;*                          VERTICAL SCROLL ON 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



VSCROLLG
    LDA CURRENTMODE
    CMPA #2
    BLE VSCROLLGX
    JMP VSCROLLGT
VSCROLLGX
    RTS

VSCROLLGT
    PSHS A,B,X,Y,U
    LDA <DIRECTION
    CMPA #0
    BGT VSCROLLGDOWN

VSCROLLGUP
    LDA CONSOLEX1
    STA <MATHPTR0
    LDA CONSOLEY1
    STA <MATHPTR1
    JSR CALCPOSG
    TFR X, Y
    PSHS D
    LDB CURRENTSL
    ABX
    ABX
    ABX
    ABX
    ABX
    ABX
    ABX
    ABX
    PULS D

    CLRA
    LDB CONSOLEH
    ASLB
    ROLA
    ASLB
    ROLA
    ASLB
    ROLA
    TFR D, U
VSCROLLGUPYSCR
    LDB #0
VSCROLLGUPYSCR1
    LDA B,X
    STA B,Y
    INCB
    CMPB CONSOLESL
    BNE VSCROLLGUPYSCR1
    LDB CURRENTSL
    CLRA
    LEAX D, X
    LEAY D, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLGUPYSCR

    LDA #0
    LDB #0
VSCROLLGUPREFILL
    STA B,Y
    INCB
    CMPB CONSOLESL
    BNE VSCROLLGUPREFILL

    JMP VSCROLLGE

VSCROLLGDOWN
    LDA CONSOLEX1
    STA <MATHPTR0
    LDA CONSOLEY1
    STA <MATHPTR1
    JSR CALCPOSG
    PSHS D
    LDB CURRENTSL
    ABX
    ABX
    ABX
    ABX
    ABX
    ABX
    ABX
    ABX
    PULS D
    TFR X, Y
    LDA CURRENTSL
    NEGA
    ADDA #1
    LEAY A, Y

    CLRA
    LDB CONSOLEH
    ASLB
    ROLA
    ASLB
    ROLA
    ASLB
    ROLA
    TFR D, U
VSCROLLGDOWNYS31L1
    LDB #0
VSCROLLGDOWNYS31
    LDA B,X
    STA B,Y
    INCB
    CMPB CONSOLESL
    BNE VSCROLLGDOWNYS31
    LDB CURRENTSL
    CLRA
    NEGB
    NEGA
    SBCA #0
    LEAX D, X
    LEAY D, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLGDOWNYS31L1

    LDA #0
    LDB #0
VSCROLLGDOWNREFILL
    STA B,Y
    INCB
    CMPB CONSOLESL
    BNE VSCROLLGDOWNREFILL

    JMP VSCROLLGE

VSCROLLGE
    PULS A,B,X,Y,U
    RTS