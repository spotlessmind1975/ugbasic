; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                          KEYBOARD HANDLER ON ATARI                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODE:
    LDY $02FC
    CPY #$FF
    BEQ SCANCODENO
    LDX #$FF
    STX $02FC

    CPY KBDCHAR
    BNE SCANCODEDIFF3

    LDA KBDDELAYC
    BEQ SCANCODEDIFF2

    DEC KBDDELAYC
    BNE SCANCODEDELAYED

SCANCODEDIFF2:
    LDA KBDRATEC
    BEQ SCANCODEDIFF

    DEC KBDRATEC
    BEQ SCANCODEDIFF
    JMP SCANCODEDELAYED

SCANCODEDIFF:
    STY KBDCHAR
    LDA KBDRATE
    LDA KBDRATEC
    LDX #$FF
    RTS

SCANCODEDIFF3:
    STY KBDCHAR
    LDA KBDRATE
    LDA KBDRATEC
    LDA KBDDELAY
    LDA KBDDELAYC
SCANCDENODELAY:
    LDX #$FF
    RTS

INKEY:
    JSR SCANCODE
    BEQ INKEYNO

    LDA #<KEYCODE2ATASCII
    STA TMPPTR
    LDA #>KEYCODE2ATASCII
    STA TMPPTR+1
    LDA (TMPPTR),Y
    BEQ INKEYNO

    ; LDX #$FF
    ; STX $02FC
    RTS

SCANCODENO:
    LDA #$0
    STA KBDCHAR
SCANCODEDELAYED:    
    JSR KBDWAITVBL
    JSR KBDWAITVBL
    JSR KBDWAITVBL
    JSR KBDWAITVBL
    JSR KBDWAITVBL
    JSR KBDWAITVBL
    LDY #$0
INKEYNO:
    LDX #$0
    RTS

KBDWAITVBL:
    LDA $D40B
    BNE KBDWAITVBL
KBDWAITVBL2:
    LDA $D40B
    BEQ KBDWAITVBL2
    RTS
