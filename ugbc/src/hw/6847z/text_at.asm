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
;*                      TEXT AT GIVEN POSITION ON 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR equ $01
TEXTSIZE equ $03
TABSTODRAW equ $04
SCREENCODE equ $08

TEXTATDECODE
    CMPA #$1F
    BHI TEXTATDECODEX1F
    LDA 32
    JMP TEXTATDECODE0
TEXTATDECODEX1F
    CMPA #$40
    BHS TEXTATDECODEX39
    ADDA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX39
    CMPA #$5F
    BHI TEXTATDECODEX5A
    ; SUBA #$40
    JMP TEXTATDECODE0
TEXTATDECODEX5A
    CMPA #$7F
    BHI TEXTATDECODEX7F
    SUBA #$60
    JMP TEXTATDECODE0
TEXTATDECODEX7F
    ; LDA #$60
    JMP TEXTATDECODE0
TEXTATDECODE0
    STA <SCREENCODE
    RTS
