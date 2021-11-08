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
;*                       CLEAR SCREEN ROUTINE FOR EF936X                       *
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
    RTS

CLS0
CLS1
CLS4

    LDA _PEN
    ANDA #$0F
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    LDA _PAPER
    ANDA #$0F
    ORA <MATHPTR5
    STA <MATHPTR5

    LDY BITMAPADDRESS
    LDX CURRENTFRAMESIZE
CLSGL1

    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA #$0
    STA , Y

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDA <MATHPTR5
    STA , Y+

    LEAX -1, X
    CMPX #0
    BNE CLSGL1
    RTS

CLS2

    LDA _PAPER
    ANDA #$03
    LDB $55
    MUL
    ANDA #$03
    STA <MATHPTR5
    JMP CLSG

CLS3

    LDA _PAPER
    ANDA #$07
    LDB $11
    MUL
    STA <MATHPTR5
    JMP CLSG

CLSG
    LDY BITMAPADDRESS
    LDX CURRENTFRAMESIZE
CLSGL2

    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA <MATHPTR5
    STA , Y

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDA <MATHPTR5
    STA , Y+

    LEAX -1, X
    CMPX #0
    BNE CLSGL2

    RTS
