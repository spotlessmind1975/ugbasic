; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

TEXTATBMDRAWCHAR
    PSHS D, X, Y, U, CC

    LDB #$08
    MUL
    ADDD #UDCCHAR
    TFR D, Y

    LDA YCURSYS
    LDB #8
    MUL
    STD PLOTY

    LDA XCURSYS
    LDB #8
    MUL
    STD PLOTX

    JSR GIMECALCPOSBM

    LDA CURRENTMODE
    ANDA #$E0
    CMPA #$E0
    BEQ TEXTATBMDRAWCHARB16
    CMPA #$60
    LBEQ TEXTATBMDRAWCHARB4
    CMPA #$40
    LBEQ TEXTATBMDRAWCHARB2

    PULS D, X, Y, U, CC
    RTS

TEXTATBMDRAWCHARB16
    LDA CURRENTTILESWIDTH
    LDB #4
    MUL

    LDU #8
TEXTATBMDRAWCHARB16L1
    LDA , Y+

    LEAX 3, X

    PSHS U, D
    LDU #2
    LDB #0
    STB , X
    LDB PLOTC
TEXTATBMDRAWCHARB16L1A
    LSRA
    BCC TEXTATBMDRAWCHARB16L1A0
    ORB , X
    STB , X
TEXTATBMDRAWCHARB16L1A0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB16L1A
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB PLOTC
    LDU #2
TEXTATBMDRAWCHARB16L1B
    LSRA
    BCC TEXTATBMDRAWCHARB16L1B0
    ORB , X
    STB , X
TEXTATBMDRAWCHARB16L1B0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB16L1B
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB PLOTC
    LDU #2
TEXTATBMDRAWCHARB16L1C
    LSRA
    BCC TEXTATBMDRAWCHARB16L1C0
    ORB , X
    STB , X
TEXTATBMDRAWCHARB16L1C0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB16L1C
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB PLOTC
    LDU #2
TEXTATBMDRAWCHARB16L1D
    LSRA
    BCC TEXTATBMDRAWCHARB16L1D0
    ORB , X
    STB , X
TEXTATBMDRAWCHARB16L1D0
    LSLB
    LSLB
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB16L1D
    PULS D, U

    LEAX B, X
    LEAU -1, U
    CMPU #0
    LBNE TEXTATBMDRAWCHARB16L1

    PULS D, X, Y, U, CC
    RTS

TEXTATBMDRAWCHARB4
    LDA CURRENTTILESWIDTH
    LDB #2
    MUL

    LDU #8
TEXTATBMDRAWCHARB4L1
    LDA , Y+

    LEAX 1, X

    PSHS U, D
    LDU #4
    LDB #0
    STB , X
    LDB PLOTC
TEXTATBMDRAWCHARB4L2
    LSRA
    BCC TEXTATBMDRAWCHARB4L10
    ORB , X
    STB , X
TEXTATBMDRAWCHARB4L10    
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB4L2
    PULS U

    LEAX -1, X

    PSHS U
    LDB #0
    STB , X
    LDB PLOTC
    LDU #4
TEXTATBMDRAWCHARB4L2B
    LSRA
    BCC TEXTATBMDRAWCHARB4L10C
    ORB , X
    STB , X
TEXTATBMDRAWCHARB4L10C
    LSLB
    LSLB
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB4L2B
    PULS D, U

    LEAX B, X
    LEAU -1, U
    CMPU #0
    BNE TEXTATBMDRAWCHARB4L1

    PULS D, X, Y, U, CC
    RTS

TEXTATBMDRAWCHARB2
    LDA CURRENTTILESWIDTH
    LDB #1
    MUL

    LDU #8
TEXTATBMDRAWCHARB2L1
    LDA , Y+
    STA , X
    LEAU -1, U
    LEAX B, X
    CMPU #0
    BNE TEXTATBMDRAWCHARB2L1
    PULS D, X, Y, U, CC
    RTS

    ; This small routine will print a string on the screen, when
    ; in bitmap mode. This routine will try to avoid to do anything
    ; if in text mode and / or the string is empty.

TEXTATBITMAPMODE

    LDB _PEN
    JSR GIMESELECTPALETTE
    STA PLOTC

    ; Avoid to do anything if we are in text mode.
    LDA CURRENTTILEMODE
    BEQ TEXTATBMMODEGO
    RTS

TEXTATBMMODEGO

    ; Avoid to do anything if there is no text to print.
    LDA TEXTSIZE
    BNE TEXTATBMGO
    RTS

    ; The routine starts here!

TEXTATBMGO

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

TEXTATBMLOOP2

    ; If there are TABs to print, we have to skip the printing.

    LDA TABSTODRAW
    LBNE TEXTATBMSKIPTAB

    ; Load the character from the string and move it into the
    ; A register, offseted by Y. Move ahead of one character and
    ; decrement the size of the string.

    LDA ,Y+
    JSR TEXTATDECODE
    LDA SCREENCODE
    DECB

    ; All characters from 0 to 31 are special, so we mu9t
    ; parse it, if needed. If the character is higher,
    ; we can simply print it.

    CMPA #31
    LBHI TEXTATBMSP0

    ; Let's go to decode the special character.

    JMP TEXTATBMCC

    ; This code will be executed if a TAB character is found
    ; in the string. In that case, the character will be
    ; translated in enough spaces until we reach the next
    ; TAB marker on the screen.

TEXTATBMTAB

    ; In order to calculate where to print the next character
    ; after the TAB character, we start considering the
    ; current X position. If the current position is greater
    ; than the number of spaces equivalent to a TAB, we subtract
    ; the number of spaces from the current X position, until
    ; we reach that limit. The complement is the number of spaces
    ; that will be printed out to reach the next TAB marker.

    ; Loop until X cursor position is greater than tab count.

    LDA XCURSYS
TEXTATBMTAB2
    CMPA TABCOUNT
    BLO TEXTATBMTAB3
    ANDCC #$01
    SUBA TABCOUNT
    JMP TEXTATBMTAB2

    ; Calculate the complement for tab count.

TEXTATBMTAB3
    STA TMPPTR
    LDA TABCOUNT
    ANDCC #$01
    SUBA TMPPTR
    STA TABSTODRAW

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; This code will be executed if a special character
    ; has to be decoded. 

TEXTATBMCC

    ; CR -> move ahead and down like a line feed
    CMPA #13
    BEQ TEXTATBMLF

    ; LF -> move ahead and down like a line feed
    CMPA #10
    BEQ TEXTATBMLF

    ; TAB -> move to the next tab marker
    CMPA #09
    BEQ TEXTATBMTAB

    ; PEN -> change the pen color
    CMPA #01    
    BEQ TEXTATBMPEN

    ; PAPER -> change the paper color
    CMPA #02
    BEQ TEXTATBMPAPER

    ; CMOVE -> move the cursor to a relative position
    CMPA #03
    LBEQ TEXTATBMCMOVEPREPARE

    ; AT -> move the cursor to an absolute position
    CMPA #04
    LBEQ TEXTATBMAT

    ; CLS -> clear the screen
    CMPA #05
    BEQ TEXTATBMCLS

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; This routine will process a clear screen embedded command
    ; into the string to print.

TEXTATBMCLS

    JSR CLSG

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; This routine will process a LF command.

TEXTATBMLF

    ; In order to move to the next line, I have to move ahead of
    ; an entire line, and "come back" for a number of character
    ; that is equal to the horizontal position. Move one character
    ; back and update the address.

    LDA CURRENTTILESWIDTH
    SUBA XCURSYS
    SUBA #1
    LEAX A,X

    ; Move to the routine that should scroll the video if we are
    ; printing on the last line of the screen.

    JMP TEXTATBMNEXT2

    ; This routine will change the current pen color, used for
    ; the following writing texts.

TEXTATBMPEN

    ; We have to check if the current WRITING flags allows to
    ; change the pen color.

    LDA TEXTWW
    ANDA #$2
    BEQ TEXTATBMPENDISABLED

    ; Load the parameter from the next character.
    LDA , Y+
    DECB

    ; A parameter of $FF means $00.
    CMPA #$FF
    BNE TEXTATBMPEN2
    LDA #$0
TEXTATBMPEN2
    STA _PEN

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; Change pen color is disabled. So we can ignore the
    ; parameter, and move ahead.

TEXTATBMPENDISABLED
    LEAY 1,Y
    DECB

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; This routine will change the current paper color, used for
    ; the following writing texts.

TEXTATBMPAPER

    ; We have to check if the current WRITING flags allows to
    ; change the paper color.

    LDA TEXTWW
    ANDA #$1
    BEQ TEXTATBMPAPERDISABLED

    ; Load the parameter from the next character.
    LDA , Y+
    DECB

    ; Save the paper.
    ; A parameter of $FF means $00.
    CMPA #$FF
    BNE TEXTATBMPAPER2
    LDA #$0
TEXTATBMPAPER2
    STA _PAPER

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; Change paper color is disabled. So we can ignore the
    ; parameter, and move ahead.

TEXTATBMPAPERDISABLED
    LEAY 1,Y
    DECB
    JMP TEXTATBMNEXT

    ; This routine will move the current cursor position on a relative
    ; position.

TEXTATBMCMOVEPREPARE

    ; Load and store the delta on abscissa.

    LDA , Y+
    DECB
    STA CLINEX

    ; Load and store the delta on ordinate.
    
    LDA , Y+
    DECB
    STA CLINEY

    ; This routine will move the current cursor position
    ; on an absolute position.

TEXTATBMCMOVE

    ; To calculate the absolute position we are going to
    ; add the delta to the current horizontal position.

    ANDCC #$FE
    LDA CLINEX
    ADDA XCURSYS

    ; If the calculated horizontal position is negative,
    ; we have nothing to do.

    CMPA #$0
    BLT TEXTATBMCMOVESKIPX

    ; If the calculated horizontal position is over
    ; the lenght of the line, we have nothing to do.

    CMPA CURRENTTILESWIDTH
    BGE TEXTATBMCMOVESKIPX

    ; Store the new horizontal position.

    STA XCURSYS

    ; Update the address by delta.

TEXTATBMCMOVESKIPX

    ; To calculate the absolute position we are going to
    ; add the delta to the current vertical position.

    ANDCC #$FE
    LDA CLINEY
    ADDA YCURSYS

    ; If the calculated vertical position is negative,
    ; we have nothing to do.

    CMPA #$0
    BLT TEXTATBMCMOVESKIPY

    ; If the calculated vertical position is over
    ; the lenght of the screen, we have nothing to do.

    CMPA CURRENTTILESHEIGHT
    BGE TEXTATBMCMOVESKIPY

    ; Store the new vertical position.

    STA YCURSYS

    ; Update the address by delta.

TEXTATBMCMOVESKIPY

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

    ; This routine will prepare the delta to move the cursor
    ; to an absolute position, to print.

TEXTATBMAT

    ; The horizontal delta is calculated started from
    ; the current position.

    LDA , Y+
    DECB
    ANDCC #$01
    SUBA XCURSYS
    STA CLINEX

    ; The vertical delta is calculated started from
    ; the current position.

    LDA , Y+
    DECB
    ANDCC #$01
    SUBA YCURSYS
    STA CLINEY

    ; Change the position like a CMOVE.

    JMP TEXTATBMCMOVE

    ; Print the character on the screen.

TEXTATBMSP0

    JSR TEXTATBMDRAWCHAR

    JMP TEXTATBMINCX

    ; If the program reach this point, it means that must skip
    ; the character in order to move the cursor ahead by one
    ; character, to move to the next tab marker.

TEXTATBMSKIPTAB
    DEC TABSTODRAW
    JMP TEXTATBMINCX

    ; Go ahead by one character.

TEXTATBMINCX

    ; Increment the current horizontal position.

    INC XCURSYS

    ; If the current horizontal position is at the end
    ; of the line, we must increment the vertical position.

    LDA XCURSYS
    CMPA CURRENTTILESWIDTH
    BEQ TEXTATBMNEXT2

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

TEXTATBMNEXT2

    ; Put 0 as horizontal position.

    LDA #0
    STA XCURSYS

    ; Increment the vertical position.

    INC YCURSYS

    ; If the current vertical position is at the end
    ; of the screen, we must scroll the screen.

    LDA YCURSYS
    CMPA CURRENTTILESHEIGHT
    BEQ TEXTATBMNEXT3

    ; Move to the next character to print.

    JMP TEXTATBMNEXT

TEXTATBMNEXT3

    ; Let's scroll vertically

    ; LDA #$FE
    ; STA DIRECTION
    ; JSR VSCROLLG

    ; Decrement the current vertical position, since
    ; now the last line is not last anymore.

    DEC YCURSYS

    ; Manage for the next character to print.

TEXTATBMNEXT

    ; If there are characters to skip to reach
    ; tabs marker, move ahead and loop.

    LDA TABSTODRAW
    LBNE TEXTATBMLOOP2

    ; If there are still characters to print,
    ; loop again.
    
    CMPB #0
    LBNE TEXTATBMLOOP2
    
    RTS

TEXTATFLIP
    fcb $0, $8, $4, $c, $2, $a, $6, $e
    fcb $1, $9, $5, $d, $3, $b, $7, $f
