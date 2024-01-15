; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                            DSAVE ROUTINE ON COCO33                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCO3DSAVEFILEWRITE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCO3DCOMMONFILEIOERROR
    JSR COCO3DCOMMONERRORSETTRAP
    JSR $A282
    JSR COCO3DCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

; X : filename, U : size of filename
; Y : destination area
COCO3DSAVE
    PSHS Y
    LDY #$094C
    LDA #32
    LDB #11
COCO3DSAVEL1
    STA B, Y
    DECB
    BNE COCO3DSAVEL1

    LDB #0
COCO3DSAVEL2
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPA #'.'
    BEQ COCO3DSAVEL2E
    CMPU #0
    BEQ COCO3DSAVEENDE
    CMPB #8
    BNE COCO3DSAVEL2

COCO3DSAVEL2E
    DECB
    LDA #$20
    STA B, Y
    INCB
    LEAX B, X
    LEAY 8, Y
    LDB #0
COCO3DSAVEL3
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPU #0
    BEQ COCO3DSAVEENDE
    CMPB #3
    BNE COCO3DSAVEL3

COCO3DSAVEENDE
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
    JSR COCO3DCOMMONFILEOPEN
    BCS COCO3DSAVEERR

COCO3DSAVEREADL1
    LDA #1
    STA $006F
    LDB #1
    JSR COCO3DSAVEFILEWRITE
    LDB $0070
    BNE COCO3DSAVEREADDONE
    STA , Y+
    JMP COCO3DSAVEREADL1

COCO3DSAVEREADDONE
    LDA #1
    STA $006F
    LDB #1
    JSR COCO3DCOMMONFILECLOSE

COCO3DSAVEERR
    STB DSAVEERROR
    RTS
