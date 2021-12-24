; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                       CLEAR SCREEN ROUTINE FOR 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLSG
    LDA CURRENTMODE
    CMPA #7
    BNE CLS7X
    JMP CLS7
CLS7X
    CMPA #8
    BNE CLS8X
    JMP CLS8
CLS8X
    CMPA #9
    BNE CLS9X
    JMP CLS9
CLS9X
    CMPA #10
    BNE CLS10X
    JMP CLS10
CLS10X
    CMPA #11
    BNE CLS11X
    JMP CLS11
CLS11X
    CMPA #12
    BNE CLS12X
    JMP CLS12
CLS12X
    CMPA #13
    BNE CLS13X
    JMP CLS13
CLS13X
    CMPA #14
    BNE CLS14X
    JMP CLS14
CLS14X
    RTS

CLS7
CLS9
CLS11
CLS13
    LDA _PAPER
    ANDA #$03
    LDB #$aa
    MUL
    JMP CLSG2

CLS8
CLS10
CLS12
CLS14
    LDA _PAPER
    CMPA #0
    BEQ CLSG0
    LDA #$FF
    JMP CLSG2
CLSG0    
    LDA #$0
    JMP CLSG2

CLSG2
    LDY BITMAPADDRESS
    LDX CURRENTFRAMESIZE
CLSGL1
    STA , Y+
    LEAX -1, X
    CMPX #0
    BNE CLSGL1

    RTS