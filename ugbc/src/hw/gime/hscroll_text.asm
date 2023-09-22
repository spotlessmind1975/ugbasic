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
;*                          HORIZONTAL SCROLL ON GIME                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLSINGLELINELEFT
    PSHS U
    LDA #0
    LDB CURRENTTILESWIDTH
    TFR D, U
HSCROLLSINGLELINELEFTL2
    LDD , Y
    STD , X
    LEAX 2, X
    LEAY 2, Y
    LEAU -1, U
    CMPU #0
    BNE HSCROLLSINGLELINELEFTL2

    LDA EMPTYTILE
    LDB MATHPTR0
    
    STD , Y
    PULS U
    RTS

HSCROLLST
    LDA CURRENTTILEMODE
    BNE HSCROLLSTX
    RTS

HSCROLLSTX
    PSHS A,B,X,Y,U

    LDB _PEN
    JSR GIMESELECTPALETTEPEN
    LSLA
    LSLA
    LSLA
    STA MATHPTR0
    LDB _PAPER
    JSR GIMESELECTPALETTEPAPER
    ORA MATHPTR0
    STA MATHPTR0

    LDX TEXTADDRESS
    LDY TEXTADDRESS
    LEAY 2, Y

    LDA DIRECTION
    CMPA #0
    BGT HSCROLLSTRIGHT

HSCROLLSTLEFT
    LDA #0
    LDB CURRENTTILESHEIGHT
    TFR D, U
HSCROLLSTLEFTL1
    JSR HSCROLLSINGLELINELEFT
    LEAU -1, U
    CMPU #0
    BNE HSCROLLSTLEFTL1
    PULS A,B,X,Y,U
    RTS    

HSCROLLSINGLELINERIGHT
    PSHS U
    LDB CURRENTTILESWIDTH
    DECB
    LSLB
HSCROLLSINGLELINERIGHTL2
    LDU B, X
    STU B, Y
    DECB
    DECB
    BNE HSCROLLSINGLELINERIGHTL2

    LDA EMPTYTILE
    LDB MATHPTR0

    STD , X
    PULS U
    RTS

HSCROLLSTRIGHT
    LDA #0
    LDB CURRENTTILESHEIGHT
    TFR D, U
HSCROLLSTRIGHTL1
    JSR HSCROLLSINGLELINERIGHT
    LDB CURRENTTILESWIDTH
    LEAX B, X
    LEAX B, X
    LEAY B, Y
    LEAY B, Y
    LEAU -1, U
    CMPU #0
    BNE HSCROLLSTRIGHTL1
    PULS A,B,X,Y,U
    RTS    

HSCROLLLT
    LDA CURRENTTILEMODE
    BNE HSCROLLLTX
    RTS

HSCROLLLTX
    PSHS A,B,X,Y,U

    LDB _PEN
    JSR GIMESELECTPALETTEPEN
    LSLA
    LSLA
    LSLA
    STA MATHPTR0
    LDB _PAPER
    JSR GIMESELECTPALETTEPAPER
    ORA MATHPTR0
    STA MATHPTR0

    LDA CLINEY
    LDB CURRENTTILESWIDTH
    MUL
    LSLB
    ROLA
    ADDD TEXTADDRESS
    TFR D, X
    TFR D, Y
    LEAY 2, X

    LDA DIRECTION
    CMPA #0
    BGT HSCROLLTTRIGHT

HSCROLLTLEFT
    JSR HSCROLLSINGLELINELEFT
    PULS A,B,X,Y,U
    RTS    

HSCROLLTTRIGHT
    JSR HSCROLLSINGLELINERIGHT
    PULS A,B,X,Y,U
    RTS    
    