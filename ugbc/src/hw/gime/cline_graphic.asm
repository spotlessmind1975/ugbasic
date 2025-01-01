; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                       CLEAR LINE ROUTINE FOR GIME                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINEGDRAWCHAR
    PSHS D, X, Y, U, CC

    ; The PRINT primitive should have control if it is necessary to bank 
    ; in the RAM and, if necessary, to differentiate the drawing logic.
    ; However, since the font is probably in the screen segment,
    ; there is no reason to differentiate.

    LDA <CLINEY
    LDB #8
    MUL
    STD <PLOTY

    LDA <CLINEX
    LDB #8
    MUL
    STD <PLOTX

    JSR GIMECALCPOSBM

    LDA CURRENTMODE
    ANDA #$E0
    CMPA #$E0
    BEQ CLINEGDRAWCHARB16
    CMPA #$60
    LBEQ CLINEGDRAWCHARB4
    CMPA #$40
    LBEQ CLINEGDRAWCHARB2

    PULS D, X, Y, U, CC
    RTS

CLINEGDRAWCHARB16
    LDA CURRENTTILESWIDTH
    LDB #2
    MUL

    LDU #8
CLINEGDRAWCHARB16L1
    LDA #0
    JSR GIMEBANKVIDEO

    LEAX 3, X

    PSHS U, D
    LDU #2
    LDB #0
    STB , X
    LDB <PLOTC
CLINEGDRAWCHARB16L1A
    LSRA
    BCC CLINEGDRAWCHARB16L1A0
    ORB , X
    STB , X
CLINEGDRAWCHARB16L1A0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB16L1A
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #2
CLINEGDRAWCHARB16L1B
    LSRA
    BCC CLINEGDRAWCHARB16L1B0
    ORB , X
    STB , X
CLINEGDRAWCHARB16L1B0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB16L1B
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #2
CLINEGDRAWCHARB16L1C
    LSRA
    BCC CLINEGDRAWCHARB16L1C0
    ORB , X
    STB , X
CLINEGDRAWCHARB16L1C0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB16L1C
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #2
CLINEGDRAWCHARB16L1D
    LSRA
    BCC CLINEGDRAWCHARB16L1D0
    ORB , X
    STB , X
CLINEGDRAWCHARB16L1D0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB16L1D
    PULS D, U

    LEAX B, X
    LEAX B, X
    LEAU -1, U
    CMPU #0
    LBNE CLINEGDRAWCHARB16L1

    JSR GIMEBANKROM

    PULS D, X, Y, U, CC
    RTS

CLINEGDRAWCHARB4
    LDA CURRENTTILESWIDTH
    LDB #2
    MUL

    LDU #8
CLINEGDRAWCHARB4L1
    LDA #0
    JSR GIMEBANKVIDEO

    LEAX 1, X

    PSHS U, D
    LDU #4
    LDB #0
    STB , X
    LDB <PLOTC
CLINEGDRAWCHARB4L2
    LSRA
    BCC CLINEGDRAWCHARB4L10
    ORB , X
    STB , X
CLINEGDRAWCHARB4L10    
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB4L2
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #4
CLINEGDRAWCHARB4L2B
    LSRA
    BCC CLINEGDRAWCHARB4L10C
    ORB , X
    STB , X
CLINEGDRAWCHARB4L10C
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB4L2B
    PULS D, U

    LEAX B, X
    LEAU -1, U
    CMPU #0
    BNE CLINEGDRAWCHARB4L1

    JSR GIMEBANKROM

    PULS D, X, Y, U, CC
    RTS

CLINEGDRAWCHARB2
    LDA CURRENTTILESWIDTH
    LDB #1
    MUL

    LDU #8
CLINEGDRAWCHARB2L1
    LDA #0
    JSR GIMEBANKVIDEO
    STA , X
    LEAU -1, U
    LEAX B, X
    CMPU #0
    BNE CLINEGDRAWCHARB2L1

    JSR GIMEBANKROM

    PULS D, X, Y, U, CC
    RTS

    ; This small routine will print a string on the screen, when
    ; in bitmap mode. This routine will try to avoid to do anything
    ; if in text mode and / or the string is empty.

CLINEG

    LDB _PEN
    JSR GIMESELECTPALETTE
    STA <PLOTC

    ; Avoid to do anything if we are in text mode.
    LDA CURRENTTILEMODE
    BEQ CLINEGMODEGO
    RTS

CLINEGMODEGO

    ; The routine starts here!

CLINEGGO

    ; Prepare the color

    ; Load the starting address of the video ram
    ; in a specific location, as a copy. This makes
    ; possible to calculate the exact position where
    ; to write, based on the actual cursor position.

    ; Load in B the size of the string.

    LDB <CHARACTERS

    ; When program reach this point, we are going to
    ; print the next character.

CLINEGLOOP2

    DECB

CLINEGSP0

    JSR CLINEGDRAWCHAR

    ; Increment the current horizontal position.

    INC <CLINEX

    ; If the current horizontal position is at the end
    ; of the line, we must increment the vertical position.

    LDA <CLINEX
    CMPA CONSOLEX2
    BGT CLINEGNEXT2

    ; Move to the next character to print.

    JMP CLINEGNEXT

CLINEGNEXT2

    RTS

CLINEGNEXT

    ; If there are still characters to print,
    ; loop again.
    
    CMPB #0
    LBNE CLINEGLOOP2
    
    RTS
