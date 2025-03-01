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

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
SCREENCODE equ $08

    ; This small routine is useful to calculate the starting address of
    ; textual video ram, given the current X and Y cursors coordinates.

CALCPOS

    ; Start from the beginning of the video RAM.

    LDX TEXTADDRESS
    STX <COPYOFTEXTADDRESS

    ; Load the number of rows to move ahead.

    LDB <YCURSYS

    ; If zero, we can skip this step.

    BEQ CALCPOSSKIP

    ; Load the size of a video text screen line.

    LDA CURRENTTILESWIDTH

    ; For each row...

CALCPOSLOOP1

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

    BNE CALCPOSLOOP1

CALCPOSSKIP

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

