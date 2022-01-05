; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
    BHI CLINE0X
    JMP CLINET
CLINE0X
    RTS

CLINET
    LDX TEXTADDRESS

    LDA CURRENTWIDTH+1
    LDB CLINEY
    CMPB #0
    BEQ CLINESKIP
CLINEL1
    ANDCC #$FE
    LEAX A, X
    DECB
    CMPB #0
    BNE CLINEL1

CLINESKIP
    LDA CHARACTERS
    CMPA #0
    BEQ CLINEENTIRE

    ANDCC #$FE
    LDA CLINEX
    LEAX A, X

    LDB CHARACTERS
    LDU #0

CLINEINCX
    LDA EMPTYTILE
    STA ,X
    LEAX 1, X    
    INC CLINEX
    DECB
    CMPB #0
    BEQ CLINEDONE
    LDA CLINEX
    CMPA CURRENTWIDTH+1
    BNE CLINEINCX
     
CLINEDONE
    RTS

CLINEENTIRE
    LDB CLINEX

CLINEINC2X
    LDA EMPTYTILE
    STA B, X
        
    INCB
    INC CLINEX
    LDB CLINEX
    CMPB CURRENTWIDTH+1
    BNE CLINEINC2X
    RTS
