; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                       CLEAR LINE ROUTINE FOR 6847                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINE
    LDA CURRENTMODE
    CMPA #2
    BHS CLINE0X
    JMP CLINET
CLINE0X
    RTS

CLINET
    LDX TEXTADDRESS
    STX COPYOFTEXTADDRESS

    LDB CLINEY
    CMPB #0
    BEQ CLINESKIP
CLINEL1
    ANDCC #$FE
    LEAX 32, X
    DECB
    BNE CLINEL1

    LDB CLINEY
CLINELC1
    ANDCC #$FE
    LDX COPYOFTEXTADDRESS
    LEAX 32, X
    STX COPYOFTEXTADDRESS
    DECB
    BNE CLINELC1

CLINESKIP
    LDA CHARACTERS
    CMPA #0
    BEQ CLINEENTIRE

    ANDCC #$FE
    LDA CLINEX
    LDX COPYOFTEXTADDRESS
    LEAX A, X
    STX COPYOFTEXTADDRESS

    LDB CHARACTERS
    LDU #0

CLINEINCX
    LDA EMPTYTILE
    STA ,Y
    LEAY 1, Y    
    INC CLINEX
    LDA CLINEX
    CMPA #32
    BNE CLINENEXT
    LDA #0
    STA CLINEX
    INC CLINEY
    LDA CLINEY
    CMPA #16
    BNE CLINENEXT

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

    DEC CLINEY
    LDX COPYOFTEXTADDRESS
    LEAX -40, X
    STX COPYOFTEXTADDRESS
     
CLINENEXT
    LEAU 1, U
    DECB
    CMPB #0
    BNE CLINEINCX
    RTS

CLINEENTIRE
    LDB #0

CLINEINC2X
    LDA EMPTYTILE
    STA B, X
        
    INCB
    INC CLINEX
    LDA CLINEX
    CMPB #32
    BNE CLINEINC2X
    RTS
