; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                          VERTICAL SCROLL ON EF936X                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLT

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ VSCROLLTORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

VSCROLLTDB
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

VSCROLLTORIG

    ANDCC #$FE
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

    LDA CURRENTMODE
    CMPA #0
    BNE VSCROLLT0X
    JMP VSCROLLT0
VSCROLLT0X
    CMPA #1
    BNE VSCROLLT1X
    JMP VSCROLLT1
VSCROLLT1X
    CMPA #2
    BNE VSCROLLT2X
    JMP VSCROLLT2
VSCROLLT2X
    CMPA #3
    BNE VSCROLLT3X
    JMP VSCROLLT3
VSCROLLT3X
    CMPA #4
    BNE VSCROLLT4X
    JMP VSCROLLT4
VSCROLLT4X
    RTS

VSCROLLT0
VSCROLLT1
VSCROLLT2
VSCROLLT3
VSCROLLT4
    PSHS A,B,X,Y,U
    LDA <DIRECTION
    CMPA #0
    BGT VSCROLLTDOWN

VSCROLLTUP
    LDX BITMAPADDRESS
    LDY BITMAPADDRESS
    LDA CURRENTSL
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    
VSCROLLTUPYSCR

    LDA $a7c0
    ORA #$01
    STA $a7c0

VSCROLLTUPYSCR1
    LDA ,Y+
    STA ,X+
    CMPY CURRENTFRAMESIZE
    BNE VSCROLLTUPYSCR1
    LDA #0
VSCROLLTUPREFILL
    STA ,X+
    CMPX CURRENTFRAMESIZE
    BNE VSCROLLTUPREFILL

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDX BITMAPADDRESS
    LDY BITMAPADDRESS
    LDA CURRENTSL
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y
    LEAY A, Y

VSCROLLTUPYSCR1C
    LDA ,Y+
    STA ,X+
    CMPY CURRENTFRAMESIZE
    BNE VSCROLLTUPYSCR1C
    LDA <MATHPTR5
VSCROLLTUPREFILLC
    STA ,X+
    CMPX CURRENTFRAMESIZE
    BNE VSCROLLTUPREFILLC

    JMP VSCROLLTE

VSCROLLTDOWN
    LDX BITMAPADDRESS
    LDY BITMAPADDRESS
    LDA CURRENTFRAMESIZE
    LEAY A, Y
    LEAX A, X
    
    LDA CURRENTSL
    COMA
    LEAX A, X

VSCROLLTDOWNYSCR

    LDA $a7c0
    ORA #$01
    STA $a7c0

VSCROLLTDOWNYSCR1
    LDA ,-X
    STA ,-Y
    CMPX #$0
    BNE VSCROLLTDOWNYSCR1
    LDA #0
VSCROLLTDOWNREFILL
    STA ,-Y
    CMPY #$0
    BNE VSCROLLTDOWNREFILL

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

VSCROLLTDOWNYSCR1C
    LDA ,-X
    STA ,-Y
    CMPX #$0
    BNE VSCROLLTDOWNYSCR1C
    LDA <MATHPTR5
VSCROLLTDOWNREFILLC
    STA ,-Y
    CMPY #$0
    BNE VSCROLLTDOWNREFILLC

    JMP VSCROLLTE

VSCROLLTE
    PULS A,B,X,Y,U
    RTS