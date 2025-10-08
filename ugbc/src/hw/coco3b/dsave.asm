; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                            DSAVE ROUTINE ON COCO3B3                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCO3BDSAVEFILEWRITE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCO3BDCOMMONFILEIOERROR
    JSR COCO3BDCOMMONERRORSETTRAP
    JSR $A282
    JSR COCO3BDCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

; X : filename, U : size of filename
; Y : destination area
COCO3BDSAVE
    PSHS Y
    LDY #$094C
    LDA #32
    LDB #11
COCO3BDSAVEL1
    STA B, Y
    DECB
    BNE COCO3BDSAVEL1

    LDB #0
COCO3BDSAVEL2
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPA #'.'
    BEQ COCO3BDSAVEL2E
    CMPU #0
    BEQ COCO3BDSAVEENDE
    CMPB #8
    BNE COCO3BDSAVEL2

COCO3BDSAVEL2E
    DECB
    LDA #$20
    STA B, Y
    INCB
    LEAX B, X
    LEAY 8, Y
    LDB #0
COCO3BDSAVEL3
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPU #0
    BEQ COCO3BDSAVEENDE
    CMPB #3
    BNE COCO3BDSAVEL3

COCO3BDSAVEENDE
    LDB #$92
    LDX #$0926
    LDY #COCOFCB
    STY B,X
    PULS Y
    CLRA
    STA $00EB
    LDA #1
    STA $006F
    LDB #1
    LDA #'O'
    JSR COCO3BDCOMMONFILEOPEN
    BCS COCO3BDSAVEERR

COCO3BDSAVEREADL1
    LDA #1
    STA $006F
    LDB #1
    JSR COCO3BDSAVEFILEWRITE
    LDB $0070
    BNE COCO3BDSAVEREADDONE
    STA , Y+
    JMP COCO3BDSAVEREADL1

COCO3BDSAVEREADDONE
    LDA #1
    STA $006F
    LDB #1
    JSR COCO3BDCOMMONFILECLOSE

COCO3BDSAVEERR
    STB DSAVEERROR
    RTS
