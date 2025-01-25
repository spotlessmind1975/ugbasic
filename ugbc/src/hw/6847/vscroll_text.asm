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
;*                          VERTICAL SCROLL ON 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF verticalOverlapRequired

VSCROLLBUFFERLINE RZB 32,  0

@ENDIF

VSCROLLT
    LDA CURRENTMODE
    CMPA #6
    BHI VSCROLLTX
    JMP VSCROLLTT
VSCROLLTX
    RTS

VSCROLLTT
    PSHS A,B,X,Y,U
    LDA <DIRECTION
    CMPA #0
    LBGT VSCROLLTDOWN

VSCROLLTUP

@IF verticalOverlapRequired

    LDB <PORT
    BEQ VSCROLLTUPNOW

    LDX TEXTADDRESS
    LDA CURRENTTILESWIDTH
    LDB CONSOLEY1
    BEQ VSCROLLTUP2    
VSCROLLTUPYL1
    LEAX A, X
    DECB
    BNE VSCROLLTUPYL1
VSCROLLTUP2

    LDY #VSCROLLBUFFERLINE
    LDB CONSOLEX1
VSCROLLTUPWCOPYL1
    LDA B,X
    STA ,Y+
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTUPWCOPYL1
    
VSCROLLTUPNOW

@ENDIF

    LDX TEXTADDRESS
    LDA CURRENTTILESWIDTH
    LDB CONSOLEY1
    BEQ VSCROLLTUP2X
VSCROLLTUPYL1X
    LEAX A, X
    DECB
    BNE VSCROLLTUPYL1X
VSCROLLTUP2X
    TFR X, Y
    LEAY A, Y

    CLRA
    LDB CONSOLEH
    DECB
    BEQ VSCROLLTUPYSCRNO
    TFR D, U
VSCROLLTUPYSCR
    LDB CONSOLEX1
VSCROLLTUPYSCR1
    LDA B,Y
    STA B,X
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTUPYSCR1
    LDA CURRENTTILESWIDTH
    LEAX A, X
    LEAY A, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTUPYSCR

VSCROLLTUPYSCRNO

@IF verticalOverlapRequired
    LDA <PORT
    BNE VSCROLLTUPREFILLW
@ENDIF

VSCROLLTUPREFILLB
    LDA EMPTYTILE
    LDB CONSOLEX1
VSCROLLTUPREFILLBL1
    STA B,X
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTUPREFILLBL1

    JMP VSCROLLTE

@IF verticalOverlapRequired

VSCROLLTUPREFILLW
    LDB CONSOLEX1
    LDY #VSCROLLBUFFERLINE
VSCROLLTUPREFILLWL1
    LDA ,Y+
    STA B,X
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTUPREFILLWL1
    JMP VSCROLLTE

@ENDIF

VSCROLLTDOWN

@IF verticalOverlapRequired

    LDB <PORT
    BEQ VSCROLLTDOWNNOW

    LDX TEXTADDRESS
    LDA CURRENTTILESWIDTH
    LDB CONSOLEY2
    BEQ VSCROLLTDOWN2X    
VSCROLLTDOWNYL1
    LEAX A, X
    DECB
    BNE VSCROLLTDOWNYL1
VSCROLLTDOWN2X

    LDY #VSCROLLBUFFERLINE
    LDB CONSOLEX1
VSCROLLTDOWNWCOPYL1
    LDA B,X
    STA ,Y+
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTDOWNWCOPYL1
    
VSCROLLTDOWNNOW

@ENDIF

    LDA CURRENTTILESWIDTH
    LDX TEXTADDRESS
    LDB CONSOLEY2
    BEQ VSCROLLTDOWN2
VSCROLLTDOWNYL1X
    LEAX A, X
    DECB
    BNE VSCROLLTDOWNYL1X
VSCROLLTDOWN2
    TFR X, Y
    LDA CURRENTTILESWIDTH
    NEGA
    LEAY A, Y

    CLRA
    LDB CONSOLEH
    TFR D, U
    CMPB #0
    BEQ VSCROLLTDOWNYS31L1NO
VSCROLLTDOWNYS31L1
    LDB CONSOLEX2
VSCROLLTDOWNYS31
    LDA B,Y
    STA B,X
    DECB
    CMPB CONSOLEX1
    BGE VSCROLLTDOWNYS31
VSCROLLTDOWNYS31L1NO    
    LDA CURRENTTILESWIDTH
    NEGA
    LEAX A, X
    LEAY A, Y
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTDOWNYS31L1

    LDA CURRENTTILESWIDTH
    LEAX A, X
    TFR X, Y

@IF verticalOverlapRequired
    LDA <PORT
    BNE VSCROLLTDOWNREFILLW
@ENDIF

VSCROLLTDOWNREFILLB
    LDA EMPTYTILE
    LDB CONSOLEX1
VSCROLLTDOWNREFILLBL1
    STA B,Y
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTDOWNREFILLBL1
    JMP VSCROLLTE

@IF verticalOverlapRequired

VSCROLLTDOWNREFILLW
    LDB CONSOLEX1
    LDX #VSCROLLBUFFERLINE
VSCROLLTDOWNREFILLWL1
    LDA ,X+
    STA B,Y
    INCB
    CMPB CONSOLEX2
    BLE VSCROLLTDOWNREFILLWL1
    JMP VSCROLLTE

@ENDIF

VSCROLLTE
    PULS A,B,X,Y,U
    RTS