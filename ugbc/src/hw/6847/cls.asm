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

CLS
    LDA CURRENTMODE
    CMPA #0
    BNE CLS0X
    JMP CLS0
CLS0X
    CMPA #1
    BNE CLS1X
    JMP CLS1
CLS1X
    CMPA #2
    BNE CLS2X
    JMP CLS2
CLS2X
    CMPA #3
    BNE CLS3X
    JMP CLS3
CLS3X
    CMPA #4
    BNE CLS4X
    JMP CLS4
CLS4X
    CMPA #5
    BNE CLS5X
    JMP CLS5
CLS5X
    CMPA #6
    BNE CLS6X
    JMP CLS6
CLS6X
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

CLS0
CLS1
CLS2
CLS3
CLS4
CLS5
CLS6
    JMP CLST

CLS7
CLS9
CLS11
CLS13
    LDA _PAPER
    ANDA #$03
    LDB #$aa
    MUL
    JMP CLSG

CLS8
CLS10
CLS12
CLS14
    LDA _PAPER
    CMPA #0
    BEQ CLSG0
    LDA #$FF
    JMP CLSG
CLSG0    
    LDA #$0
    JMP CLSG

CLSG
    LDY BITMAPADDRESS
    LDX CURRENTFRAMESIZE
CLSGL1
    STA , Y+
    LEAX -1, X
    CMPX #0
    BNE CLSGL1

    RTS

CLST
    LDY TEXTADDRESS
    LDX CURRENTFRAMESIZE
    LDA EMPTYTILE
CLST2
    STA , Y+
    LEAX -1, X
    CMPX #0
    BNE CLST2

    RTS
