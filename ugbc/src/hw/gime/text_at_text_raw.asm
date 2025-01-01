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

    ; This small routine is useful to calculate the starting address of
    ; textual video ram, given the current X and Y cursors coordinates.

CALCPOSRAW

    ; Start from the beginning of the video RAM.

    LDX TEXTADDRESS
    STX <COPYOFTEXTADDRESS

    ; Load the number of rows to move ahead.

    LDB <YCURSYS

    ; If zero, we can skip this step.

    BEQ CALCPOSRAWSKIP

    ; Load the size of a video text screen line.

    LDA CURRENTTILESWIDTH

    ; For each row...

CALCPOSRAWLOOP1

    ; Increment the address of the size of a row:
    ; we have to increment the address twice,
    ; since each character has a character code
    ; and a character attribute.

    ANDCC #$FE
    PSHS D
    TFR A, B
    ABX
    ABX
    PULS D

    ; Decrement the number of rows.

    DECB

    ; Until the rows are finished, let's go ahead!

    BNE CALCPOSRAWLOOP1

CALCPOSRAWSKIP

    ; Now we can add the X position. Again, twice.
    LDA <XCURSYS
    PSHS D
    TFR A, B
    ABX
    ABX
    PULS D    

    ; Store the position.
    STX <COPYOFTEXTADDRESS

    RTS

    ; This small routine will print a string on the screen, when
    ; in text mode. This routine will try to avoid to do anything
    ; if in graphic mode and / or the string is empty.

TEXTATTILEMODERAW

    ; Avoid to do anything if we are in graphic mode.
    LDA CURRENTMODE
    ANDA #$10
    BEQ TEXTATRAWTILEMODEGO
    RTS

TEXTATRAWTILEMODEGO

    ; Avoid to do anything if there is no text to print.
    LDA <TEXTSIZE
    BNE TEXTATRAWGO
    RTS

    ; The routine starts here!

TEXTATRAWGO

    ; Prepare the color

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

    ; Load the starting address of the video ram
    ; in a specific location, as a copy. This makes
    ; possible to calculate the exact position where
    ; to write, based on the actual cursor position.

    JSR CALCPOSRAW

    ; Initialize the counter for printing tabs.

    LDA #0
    STA <TABSTODRAW

    ; Load in Y register the starting address of the
    ; string to print on the video RAM.

    LDY <TEXTPTR

    ; Load in B the size of the string.

    LDB <TEXTSIZE

    ; When program reach this point, we are going to
    ; print the next character.

TEXTATRAWLOOP2

    ; Load the character from the string and move it into the
    ; A register, offseted by Y. Move ahead of one character and
    ; decrement the size of the string.

    ; The PRINT primitive should have control if it is necessary to bank 
    ; in the RAM and, if necessary, to differentiate the drawing logic.
    ; However, since the font is probably in the screen segment,
    ; there is no reason to differentiate.

    JSR GIMEBANKROM
    LDA ,Y+
    DECB

    JSR GIMEBANKVIDEO
    STA , X+

TEXTATRAWSP0C

    LDA <PLOTC
    STA , X
    LEAX 1, X
    JMP TEXTATRAWINCX

    ; Go ahead by one character.

TEXTATRAWINCX

    ; Increment the current horizontal position.

    INC <XCURSYS

    ; Exit if the string is ended
    
    CMPB #0
    LBEQ TEXTATRAWEND2

    ; If the current horizontal position is at the end
    ; of the line, we must increment the vertical position.

    LDA <XCURSYS
    CMPA CONSOLEX2
    BGT TEXTATRAWNEXT2

    ; Move to the next character to print.

    JMP TEXTATRAWNEXT

TEXTATRAWNEXT2

    ; Put 0 as horizontal position.

    LDA CONSOLEX1
    STA <XCURSYS

    ; Increment the vertical position.

    INC <YCURSYS

    ; Update the video ram address.

    STX <COPYOFTEXTADDRESS

    ; If the current vertical position is at the end
    ; of the screen, we must scroll the screen.

    LDA <YCURSYS
    CMPA CONSOLEY2
    BGT TEXTATRAWNEXT3

    ; Move to the next character to print.

    JMP TEXTATRAWNEXT

TEXTATRAWNEXT3

    ; Let's scroll vertically

    LDA #$FE
    STA <DIRECTION
    JSR VSCROLLT

    ; Decrement the current vertical position, since
    ; now the last line is not last anymore.

    DEC <YCURSYS

    ; Update the current address video RAM, as well.

    ANDCC #$01
    LDA #0
    SUBA CURRENTTILESWIDTH
    LDX <COPYOFTEXTADDRESS
    PSHS D
    TFR A, B
    ABX
    ABX
    PULS D
    STX <COPYOFTEXTADDRESS

    ; Manage for the next character to print.

TEXTATRAWNEXT

    ; If there are characters to skip to reach
    ; tabs marker, move ahead and loop.

    LDA <TABSTODRAW
    LBNE TEXTATRAWLOOP2

    ; If there are still characters to print,
    ; loop again.
    
    CMPB #0
    BEQ TEXTATRAWEND2
    
    ; JSR GIMEBANKROM

    JMP TEXTATRAWLOOP2

TEXTATRAWEND2
    RTS
