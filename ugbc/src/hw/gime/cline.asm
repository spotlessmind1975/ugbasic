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
;  * distributed under the License is distributed on an "AS IS" BASIS,
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
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
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

CLINE
    LDA CURRENTTILEMODE
    BNE CLINET
    RTS

CLINET
    LDX TEXTADDRESS

    LDA CURRENTTILESWIDTH
    LDB CLINEY
    MUL
    LSLB
    ROLA
    LEAX D, X

CLINESKIP
    LDA CHARACTERS
    CMPA #0
    BEQ CLINEENTIRE

    ANDCC #$FE
    LDA CLINEX
    LEAX A, X
    LEAX A, X

    LDA #0
    LDB CHARACTERS
    TFR D, U

CLINEINCX
    LDA EMPTYTILE
    LDB _PEN
    LSLB
    LSLB
    LSLB
    ORB _PAPER
    STD ,X
    LEAX 2, X    
    INC CLINEX
    LEAU -1, U
    CMPU #0
    BEQ CLINEDONE
    LDA CLINEX
    CMPA CURRENTTILESWIDTH
    BNE CLINEINCX
     
CLINEDONE
    RTS

CLINEENTIRE

    LDA #0
    LDB CLINEX
    TFR D, U

CLINEINC2X
    LDA EMPTYTILE
    LDB _PEN
    LSLB
    LSLB
    LSLB
    ORB _PAPER
    STD , X
    LEAX 2, X
    INC CLINEX
    LDB CLINEX
    CMPB CURRENTTILESWIDTH
    BNE CLINEINC2X
    RTS
