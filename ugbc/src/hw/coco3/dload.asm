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
;*                            DLOAD ROUTINE ON COCO33                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCO3DLOADFILEREAD
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCO3DCOMMONFILEIOERROR
    JSR COCO3DCOMMONERRORSETTRAP
    JSR $A176
    JSR COCO3DCOMMONERRORCLEARTRAP
    STA ,S
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

; X : filename, U : size of filename
; Y : destination area
COCO3DLOAD
    PSHS Y
    LDY #$094C
    LDA #32
    LDB #11
COCO3DLOADL1
    STA B, Y
    DECB
    BNE COCO3DLOADL1

    LDB #0
COCO3DLOADL2
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPA #'.'
    BEQ COCO3DLOADL2E
    CMPU #0
    BEQ COCO3DLOADENDE
    CMPB #8
    BNE COCO3DLOADL2

COCO3DLOADL2E
    DECB
    LDA #$20
    STA B, Y
    INCB
    LEAX B, X
    LEAY 8, Y
    LDB #0
COCO3DLOADL3
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPU #0
    BEQ COCO3DLOADENDE
    CMPB #3
    BNE COCO3DLOADL3

COCO3DLOADENDE
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
    LDA #'I'
    JSR COCO3DCOMMONFILEOPEN
    BCS COCO3DLOADERR

COCO3DLOADREADL1
    LDA #1
    STA $006F
    LDB #1
    JSR COCO3DLOADFILEREAD
    LDB $0070
    BNE COCO3DLOADREADDONE
    STA , Y+
    JMP COCO3DLOADREADL1

COCO3DLOADREADDONE
    LDA #1
    STA $006F
    LDB #1
    JSR COCO3DCOMMONFILECLOSE

COCO3DLOADERR
    STB DLOADERROR
    RTS
