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
;*                          VERTICAL SCROLL ON GIME                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF verticalOverlapRequired

VSCROLLBUFFERLINE RZB 80*2,  0

@ENDIF

VSCROLLT
    LDA CURRENTTILEMODE
    BNE VSCROLLTX
    RTS

VSCROLLTX
    PSHS A,B,X,Y,U

    LDB _PEN
    JSR GIMESELECTPALETTEPEN
    LSLA
    LSLA
    LSLA
    STA <PLOTC
    LDB _PAPER
    JSR GIMESELECTPALETTEPAPER
    ORA <PLOTC
    STA <PLOTC

    LDA <DIRECTION
    CMPA #0
    LBGT VSCROLLTDOWN

VSCROLLTUP
    LDB CURRENTTILESWIDTH
    LDA CONSOLEY1
    MUL
    ASLB
    ROLA
    LDX TEXTADDRESS
    LDY TEXTADDRESS
    LEAX D, X
    LEAY D, Y
    LDB CURRENTTILESWIDTH
    LDA #0
    ASLB
    ROLA
    LEAY D, Y

    ; LDA CONSOLEW
    ; LDB CONSOLEH
    ; MUL
    ; LSLB
    ; ROLA
    ; TFR D, U
    ; LDA #0
    ; LDB CONSOLEW
    ; NEGA
    ; NEGB
    ; SBCA #0
    ; LEAU D, U
    ; LEAU D, U

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKVIDEO

    LDB CONSOLEX2
    ASLB
    STB MATHPTR3

@IF verticalOverlapRequired

    LDB <PORT
    BEQ VSCROLLTUPNOW

    PSHS X
    PSHS Y

    LDY #VSCROLLBUFFERLINE
    LDB CONSOLEX1
    ASLB
VSCROLLTUPWCOPYL1
    LDA B,X
    STA ,Y+
    INCB
    CMPB MATHPTR3
    BLE VSCROLLTUPWCOPYL1
    
    PULS Y
    PULS X

VSCROLLTUPNOW

@ENDIF

    CLRA
    LDB CONSOLEH
    DECB
    BEQ VSCROLLTUPYSCR1NO
    TFR D, U
VSCROLLTUPYSCR1L1
    LDB CONSOLEX1
    ASLB
VSCROLLTUPYSCR1
    LDA B,Y
    STA B,X
    INCB
    CMPB MATHPTR3
    BLE VSCROLLTUPYSCR1
    PSHS D
    CLRA
    LDB CURRENTTILESWIDTH
    ASLB
    LEAY D, Y
    LEAX D, X
    PULS D
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTUPYSCR1L1

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    ; JSR GIMEBANKROM

VSCROLLTUPYSCR1NO

@IF verticalOverlapRequired
    LDA <PORT
    BNE VSCROLLTUPREFILLW
@ENDIF

VSCROLLTUPREFILLNOW
    LDA #0
    LDB CONSOLEW
    TFR D, U

    LDA #0
    LDB CONSOLEX1
    ASLB
    LEAX D, X

    LDA EMPTYTILE
    LDB <PLOTC

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    ; JSR GIMEBANKVIDEO

VSCROLLTUPYSCR2
    STD ,X
    LEAX 2,X
    LEAU -1, U
    CMPU #0
    BNE VSCROLLTUPYSCR2

    JMP VSCROLLTE

@IF verticalOverlapRequired

VSCROLLTUPREFILLW
    LDB CONSOLEX1
    ASLB
    LDY #VSCROLLBUFFERLINE
VSCROLLTUPREFILLWL1
    LDA ,Y+
    STA B,X
    INCB
    CMPB MATHPTR3
    BLE VSCROLLTUPREFILLWL1
    JMP VSCROLLTE

@ENDIF

VSCROLLTDOWN
    LDX TEXTADDRESS
    LDA CURRENTTILESWIDTH
    LDB CONSOLEY2
    MUL
    LSLB
    ROLA
    LEAX D, X
    LDB CONSOLEX1
    LSLB
    LEAX B, X

    LDB CONSOLEX2
    ASLB
    STB MATHPTR3
    
    TFR X, Y
    LDA #0
    LDB CURRENTTILESWIDTH
    LSLB
    ROLA
    NEGA
    NEGB
    SBCA #0
    LEAY D, Y

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKVIDEO

@IF verticalOverlapRequired

    LDB <PORT
    BEQ VSCROLLTDOWNNOW

    PSHS X
    PSHS Y

    LDX TEXTADDRESS
    LDA CURRENTTILESWIDTH
    LDB CONSOLEY2
    MUL
    LSLB
    ROLA
    LEAX D, X

    LDY #VSCROLLBUFFERLINE
    LDB CONSOLEX1
    ASLB
VSCROLLTDOWNWCOPYL1
    LDA B,X
    STA ,Y+
    INCB
    CMPB MATHPTR3
    BLE VSCROLLTDOWNWCOPYL1
    
    PULS Y
    PULS X

VSCROLLTDOWNNOW

@ENDIF

    LDB CONSOLEH
    DECB
VSCROLLTDOWNSCR1L2
    PSHS D
    LDB CONSOLEW
    LSLB
    DECB
VSCROLLTDOWNSCR1
    LDA B, Y
    STA B, X
    DECB
    CMPB #$FF
    BNE VSCROLLTDOWNSCR1

    LDA #0
    LDB CURRENTTILESWIDTH

    LSLB
    ROLA
    NEGA
    NEGB
    SBCA #0
    LEAX D, X
    LEAY D, Y

    PULS D

    DECB
    BNE VSCROLLTDOWNSCR1L2

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

@IF verticalOverlapRequired
    LDA <PORT
    BNE VSCROLLTDOWNREFILLW
@ENDIF

VSCROLLTDOWNREFILLB

    JSR GIMEBANKROM
    
    LDA EMPTYTILE
    LDB <PLOTC

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKVIDEO
    
    TFR D, U

    LDB CONSOLEW
    LSLB
    DECB
    DECB

VSCROLLTDOWNSCR2
    STU B, X
    DECB
    DECB
    CMPB #$FE
    BNE VSCROLLTDOWNSCR2

    JMP VSCROLLTE

@IF verticalOverlapRequired

VSCROLLTDOWNREFILLW

    LDX TEXTADDRESS
    LDA CURRENTTILESWIDTH
    LDB CONSOLEY1
    MUL
    LSLB
    ROLA
    LEAX D, X
    TFR X, Y
    LDB CONSOLEX1
    ASLB
    LDX #VSCROLLBUFFERLINE
VSCROLLTDOWNREFILLWL1
    LDA ,X+
    STA B,Y
    INCB
    CMPB MATHPTR3
    BLE VSCROLLTDOWNREFILLWL1
    JMP VSCROLLTE

@ENDIF

VSCROLLTE

    ; The VSCROLL command do not need to switch from one bank to another 
    ; during video RAM operation. This routine can simply bank in video 
    ; memory at the beginning of execution and bank out at the end.

    JSR GIMEBANKROM

    PULS A,B,X,Y,U
    RTS