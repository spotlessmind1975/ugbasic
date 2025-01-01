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
;*                      TEXT AT GIVEN POSITION ON GIME                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATRAWBMDRAWCHAR
    PSHS D, X, Y, U, CC

    ; The PRINT primitive should have control if it is necessary to bank 
    ; in the RAM and, if necessary, to differentiate the drawing logic.
    ; However, since the font is probably in the screen segment,
    ; there is no reason to differentiate.

    LDB #$08
    MUL
    ADDD #UDCCHAR
    TFR D, Y

    LDA <YCURSYS
    LDB #8
    MUL
    STD <PLOTY

    LDA <XCURSYS
    LDB #8
    MUL
    STD <PLOTX

    JSR GIMECALCPOSBM

    LDA CURRENTMODE
    ANDA #$E0
    CMPA #$E0
    BEQ TEXTATRAWBMDRAWCHARB16
    CMPA #$60
    LBEQ TEXTATRAWBMDRAWCHARB4
    CMPA #$40
    LBEQ TEXTATRAWBMDRAWCHARB2

    PULS D, X, Y, U, CC
    RTS

TEXTATRAWBMDRAWCHARB16
    LDA CURRENTTILESWIDTH
    LDB #2
    MUL

    LDU #8
TEXTATRAWBMDRAWCHARB16L1
    JSR GIMEBANKROM
    LDA , Y+
    JSR GIMEBANKVIDEO

    LEAX 3, X

    PSHS U, D
    LDU #2
    LDB #0
    STB , X
    LDB <PLOTC
TEXTATRAWBMDRAWCHARB16L1A
    LSRA
    BCC TEXTATRAWBMDRAWCHARB16L1A0
    ORB , X
    STB , X
TEXTATRAWBMDRAWCHARB16L1A0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB16L1A
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #2
TEXTATRAWBMDRAWCHARB16L1B
    LSRA
    BCC TEXTATRAWBMDRAWCHARB16L1B0
    ORB , X
    STB , X
TEXTATRAWBMDRAWCHARB16L1B0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB16L1B
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #2
TEXTATRAWBMDRAWCHARB16L1C
    LSRA
    BCC TEXTATRAWBMDRAWCHARB16L1C0
    ORB , X
    STB , X
TEXTATRAWBMDRAWCHARB16L1C0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB16L1C
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #2
TEXTATRAWBMDRAWCHARB16L1D
    LSRA
    BCC TEXTATRAWBMDRAWCHARB16L1D0
    ORB , X
    STB , X
TEXTATRAWBMDRAWCHARB16L1D0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB16L1D
    PULS D, U

    LEAX B, X
    LEAX B, X
    LEAU -1, U
    CMPU #0
    LBNE TEXTATRAWBMDRAWCHARB16L1

    JSR GIMEBANKROM

    PULS D, X, Y, U, CC
    RTS

TEXTATRAWBMDRAWCHARB4
    LDA CURRENTTILESWIDTH
    LDB #2
    MUL

    LDU #8
TEXTATRAWBMDRAWCHARB4L1
    JSR GIMEBANKROM
    LDA , Y+
    JSR GIMEBANKVIDEO

    LEAX 1, X

    PSHS U, D
    LDU #4
    LDB #0
    STB , X
    LDB <PLOTC
TEXTATRAWBMDRAWCHARB4L2
    LSRA
    BCC TEXTATRAWBMDRAWCHARB4L10
    ORB , X
    STB , X
TEXTATRAWBMDRAWCHARB4L10    
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB4L2
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB <PLOTC
    LDU #4
TEXTATRAWBMDRAWCHARB4L2B
    LSRA
    BCC TEXTATRAWBMDRAWCHARB4L10C
    ORB , X
    STB , X
TEXTATRAWBMDRAWCHARB4L10C
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB4L2B
    PULS D, U

    LEAX B, X
    LEAU -1, U
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB4L1

    JSR GIMEBANKROM

    PULS D, X, Y, U, CC
    RTS

TEXTATRAWBMDRAWCHARB2
    LDA CURRENTTILESWIDTH
    LDB #1
    MUL

    LDU #8
TEXTATRAWBMDRAWCHARB2L1
    JSR GIMEBANKROM
    LDA , Y+
    JSR GIMEBANKVIDEO
    STA , X
    LEAU -1, U
    LEAX B, X
    CMPU #0
    BNE TEXTATRAWBMDRAWCHARB2L1

    JSR GIMEBANKROM

    PULS D, X, Y, U, CC
    RTS

    ; This small routine will print a string on the screen, when
    ; in bitmap mode. This routine will try to avoid to do anything
    ; if in text mode and / or the string is empty.

TEXTATBITMAPMODERAW

    LDB _PEN
    JSR GIMESELECTPALETTE
    STA <PLOTC

    ; Avoid to do anything if we are in text mode.
    LDA CURRENTTILEMODE
    BEQ TEXTATRAWBMMODEGO
    RTS

TEXTATRAWBMMODEGO

    ; Avoid to do anything if there is no text to print.
    LDA TEXTSIZE
    BNE TEXTATRAWBMGO
    RTS

    ; The routine starts here!

TEXTATRAWBMGO

    ; Prepare the color

    ; Load the starting address of the video ram
    ; in a specific location, as a copy. This makes
    ; possible to calculate the exact position where
    ; to write, based on the actual cursor position.

    ; Initialize the counter for printing tabs.

    LDA #0
    STA TABSTODRAW

    ; Load in Y register the starting address of the
    ; string to print on the video RAM.

    LDY TEXTPTR

    ; Load in B the size of the string.

    LDB TEXTSIZE

    ; When program reach this point, we are going to
    ; print the next character.

TEXTATRAWBMLOOP2

    ; Load the character from the string and move it into the
    ; A register, offseted by Y. Move ahead of one character and
    ; decrement the size of the string.

    LDA ,Y+
    DECB

    JSR TEXTATRAWBMDRAWCHAR

    ; Increment the current horizontal position.

    INC <XCURSYS

    ; Exit if the string is ended.
    
    CMPB #0
    LBEQ TEXTATRAWBMEND2

    ; If the current horizontal position is at the end
    ; of the line, we must increment the vertical position.

    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATRAWBMNEXT2

    ; Move to the next character to print.

    JMP TEXTATRAWBMNEXT

TEXTATRAWBMNEXT2

    ; Put 0 as horizontal position.

    LDA CONSOLEX1
    STA <XCURSYS

    ; Increment the vertical position.

    INC <YCURSYS

    ; If the current vertical position is at the end
    ; of the screen, we must scroll the screen.

    LDA <YCURSYS
    CMPA CONSOLEY2
    BGT TEXTATRAWBMNEXT3

    ; Move to the next character to print.

    JMP TEXTATRAWBMNEXT

TEXTATRAWBMNEXT3

    ; Let's scroll vertically

    ; LDA #$FE
    ; STA <DIRECTION
    ; JSR VSCROLLG

    ; Decrement the current vertical position, since
    ; now the last line is not last anymore.

    DEC <YCURSYS

    ; Manage for the next character to print.

TEXTATRAWBMNEXT

    ; Exit if the string is ended.
    
    CMPB #0
    BEQ TEXTATRAWBMEND2

    JMP TEXTATRAWBMLOOP2

TEXTATRAWBMEND2

    RTS

TEXTATRAWFLIP
    fcb $0, $8, $4, $c, $2, $a, $6, $e
    fcb $1, $9, $5, $d, $3, $b, $7, $f
