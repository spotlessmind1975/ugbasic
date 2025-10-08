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
;*                            DCOMMON ROUTINE ON COCO3B3                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCOFCB
    rzb    64

COCO3BDCOMMONSETUP
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    LDA #$7E
    LDX #COCO3BDCOMMONERRORHOOK
    LDB $0191
    LDU $0192
    CMPU #COCO3BDCOMMONERRORHOOK
    beq COCO3BDCOMMON000
    STA $0191
    STX $0192
    STB COCO3BDCOMMONSAVEDERROR
    STU COCO3BDCOMMONSAVEDERROR+1
COCO3BDCOMMON000  
    LDX $C004
    CMPX #$D66C
    BEQ COCO3BDCOMMONDISK10
    CMPX #$D75F
    BEQ COCO3BDCOMMONDISK11
    LDX #COCO3BDCOMMONDISKERROR
    BRA COCO3BDCOMMON010
COCO3BDCOMMONDISK10   
    LDX #$C483
    BRA COCO3BDCOMMON010
COCO3BDCOMMONDISK11   
    LDX #$C48D
COCO3BDCOMMON010  
    STX COCO3BDCOMMONDISKOPEN
    CLR COCO3BDCOMMONERRORHANDLER
    CLR COCO3BDCOMMONERRORHANDLER+1
    STA $FFDF
    RTS

COCO3BDCOMMONDISKERROR
    LDB #255
COCO3BDCOMMONERRORHOOK
    LDX COCO3BDCOMMONERRORHANDLER
    BNE COCO3BDCOMMONERRORHOOK000
    JMP COCO3BDCOMMONSAVEDERROR
COCO3BDCOMMONERRORHOOK000
    LDS COCO3BDCOMMONERRORSTACK
    JMP ,X
COCO3BDCOMMONERRORSETTRAP
    STX COCO3BDCOMMONERRORHANDLER
    PULS Y
    STS COCO3BDCOMMONERRORSTACK
    JMP ,Y
COCO3BDCOMMONERRORCLEARTRAP
    PSHS CC
    CLR COCO3BDCOMMONERRORHANDLER
    CLR COCO3BDCOMMONERRORHANDLER+1
    PULS CC,PC

COCO3BDCOMMONFILEOPEN
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOCOMMONFILEERR
    JSR COCO3BDCOMMONERRORSETTRAP
    JSR [COCO3BDCOMMONDISKOPEN]
    JSR COCO3BDCOMMONERRORCLEARTRAP
    CLRA
    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF
    PULS D,X,Y,U,PC
COCOCOMMONFILEERR 
    COMA
    STB 1,S
    STA $FFDF
    PULS D,X,Y,U,PC
COCO3BDCOMMONFILECLOSE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOCOMMONFILEERR
    JSR COCO3BDCOMMONERRORSETTRAP
    JSR $A426
    JSR COCO3BDCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

COCO3BDCOMMONFILEIOERROR
    STB 1,S
    BSR COCO3BDCOMMONFILECLOSE
    COMA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC
