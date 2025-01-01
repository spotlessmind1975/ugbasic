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
;*                      TEXT AT GIVEN POSITION ON VIC-II                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTPTR = $0B
TEXTSIZE = $0F
TABSTODRAW = $5D
SCREENCODE = $20

TEXTATDECODE:
    CMP #32
    BCS TEXTATXSP128
    JMP TEXTATSP128
TEXTATXSP128:
    CMP #64
    BCS TEXTATXSP0
    JMP TEXTATDECODE0
TEXTATXSP0:
    CMP #96
    BCS TEXTATXSM64
    JMP TEXTATSM64
TEXTATXSM64:
    CMP #160
    BCS TEXTATXSP64
    JMP TEXTATSP64
TEXTATXSP64:
    CMP #192
    BCS TEXTATX2SM64
    JMP TEXTATSM64
TEXTATX2SM64:
    CMP #224
    BCS TEXTATX2SM128
    JMP TEXTATSM128
TEXTATX2SM128:
    JMP TEXTATDECODE0
TEXTATSP64:
    CLC
    ADC #64
    JMP TEXTATDECODE0
TEXTATSP128:
    ADC #128
    JMP TEXTATDECODE0
TEXTATSM64:
    SBC #63
    JMP TEXTATDECODE0
TEXTATSM128:
    SBC #127
    JMP TEXTATDECODE0
TEXTATDECODE0:
    STA SCREENCODE
    RTS

; Read a char from the text buffer to print.
; Input: TEXTPTR - pointer to the string to print
;        X - characters left to print
; Output: TEXTPTR is updated; X is updated
TEXTATREADCHAR:
    LDA (TEXTPTR),Y
    DEX
    INC TEXTPTR
    BNE TEXTATREADCHARL1
    INC TEXTPTR+1
TEXTATREADCHARL1:
    RTS

; Parse TAB character.
; Input: XCURSYS - current X cursor position
;        TABCOUNT - size of TAB spacing
; Output: TABSTODRAW - number of characters to skip
TEXTATTAB:
    LDA XCURSYS
TEXTATTAB2:
    CMP TABCOUNT
    BCC TEXTATTAB3
    SEC
    SBC TABCOUNT
    JMP TEXTATTAB2
TEXTATTAB3:
    STA TMPPTR
    LDA TABCOUNT
    SEC
    SBC TMPPTR
    STA TABSTODRAW
    RTS

