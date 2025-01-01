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
;*                          FLIP Y ROUTINE FOR GIME                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Flip image
; ----------------------------------------------------------------------------

FLIPIMAGEY

    LDA PALETTELIMIT
    CMPA #2
    BEQ FLIPIMAGEYL1T2
    CMPA #4
    BEQ FLIPIMAGEYL1T4

FLIPIMAGEYL1T16
    LDD , Y
    LSRA
    RORB
    STD <IMAGEW
    JMP FLIPIMAGEYCOMMON

FLIPIMAGEYL1T4
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW
    JMP FLIPIMAGEYCOMMON

FLIPIMAGEYL1T2
    LDD , Y
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW
    JMP FLIPIMAGEYCOMMON

FLIPIMAGEYCOMMON

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    ; Move the image pointer ahead of header.

    LEAY 3,Y

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

FLIPIMAGEYCOMMONCL0

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    CLRA
    LDB <IMAGEH
    TFR D, U 
    
    LDD <IMAGEW
    LEAU -1, U
FLIPIMAGEYCOMMONCL0L
    ; Move ahead the ending line pointer of 2 x IMAGE WIDTH - 1
    LEAX D, X
    LEAU -1, U
    CMPU #0
    BNE FLIPIMAGEYCOMMONCL0L

    CLRA
    LDB <IMAGEH
    LSRB
    TFR D, U

    CLRA
FLIPIMAGEYCOMMONCL1
    LDB #0
FLIPIMAGEYCOMMONCLN
    LDA B, Y
    PSHS D
    LDA B, X
    STA B, Y
    PULS D
    STA B, X
    ADDD #1
    CMPD <IMAGEW
    BNE FLIPIMAGEYCOMMONCLN

    LEAY D, Y
    EORA #$FF
    EORB #$FF
    ADDD #1
    LEAX D, X

    ; Decrement the number of lines to flip.

    LEAU -1, U

    ; If not finished, repeat the loop.

    CMPU #0
    BNE FLIPIMAGEYCOMMONCL1

    RTS
