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

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
SCREENCODE equ $08

TEXTATDECODE
    CMPA #32
    BCC TEXTATXSP128
    JMP TEXTATSP128
TEXTATXSP128
    CMPA #64
    BCC TEXTATXSP0
    JMP TEXTATDECODE0
TEXTATXSP0
    CMPA #96
    BCC TEXTATXSM64
    JMP TEXTATSM64
TEXTATXSM64
    CMPA #160
    BCC TEXTATXSP64
    JMP TEXTATSP64
TEXTATXSP64
    CMPA #192
    BCC TEXTATX2SM64
    JMP TEXTATSM64
TEXTATX2SM64
    CMPA #224
    BCC TEXTATX2SM128
    JMP TEXTATSM128
TEXTATX2SM128
    JMP TEXTATDECODE0
TEXTATSP64
    ANDCC #$FE
    ADDA #32
    JMP TEXTATDECODE0
TEXTATSP128
    ; ADDA #128
    JMP TEXTATDECODE0
TEXTATSM64
    SBCA #63
    JMP TEXTATDECODE0
TEXTATSM128
    SBCA #127
    JMP TEXTATDECODE0
TEXTATDECODE0
    STA SCREENCODE
    RTS
