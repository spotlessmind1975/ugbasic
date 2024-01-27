; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                            DSAVE ROUTINE ON COCO                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCODSAVEFILEWRITE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCODCOMMONFILEIOERROR
    JSR COCODCOMMONERRORSETTRAP
    JSR $A282
    JSR COCODCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

; X : filename, U : size of filename
; Y : destination area
COCODSAVE
    PSHS Y
    LDY #$094C
    LDA #32
    LDB #11
COCODSAVEL1
    STA B, Y
    DECB
    BNE COCODSAVEL1

    LDB #0
COCODSAVEL2
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPA #'.'
    BEQ COCODSAVEL2E
    CMPU #0
    BEQ COCODSAVEENDE
    CMPB #8
    BNE COCODSAVEL2

COCODSAVEL2E
    DECB
    LDA #$20
    STA B, Y
    INCB
    LEAX B, X
    LEAY 8, Y
    LDB #0
COCODSAVEL3
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPU #0
    BEQ COCODSAVEENDE
    CMPB #3
    BNE COCODSAVEL3

COCODSAVEENDE
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
    JSR COCODCOMMONFILEOPEN
    BCS COCODSAVEERR

COCODSAVEREADL1
    LDA #1
    STA $006F
    LDB #1
    JSR COCODSAVEFILEWRITE
    LDB $0070
    BNE COCODSAVEREADDONE
    STA , Y+
    JMP COCODSAVEREADL1

COCODSAVEREADDONE
    LDA #1
    STA $006F
    LDB #1
    JSR COCODCOMMONFILECLOSE

COCODSAVEERR
    STB DSAVEERROR
    RTS
