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
;*                            DCOMMON ROUTINE ON COCO33                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCOFCB
    rzb    64

COCO3DCOMMONSETUP
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    LDA #$7E
    LDX #COCO3DCOMMONERRORHOOK
    LDB $0191
    LDU $0192
    CMPU #COCO3DCOMMONERRORHOOK
    beq COCO3DCOMMON000
    STA $0191
    STX $0192
    STB COCO3DCOMMONSAVEDERROR
    STU COCO3DCOMMONSAVEDERROR+1
COCO3DCOMMON000  
    LDX $C004
    CMPX #$D66C
    BEQ COCO3DCOMMONDISK10
    CMPX #$D75F
    BEQ COCO3DCOMMONDISK11
    LDX #COCO3DCOMMONDISKERROR
    BRA COCO3DCOMMON010
COCO3DCOMMONDISK10   
    LDX #$C483
    BRA COCO3DCOMMON010
COCO3DCOMMONDISK11   
    LDX #$C48D
COCO3DCOMMON010  
    STX COCO3DCOMMONDISKOPEN
    CLR COCO3DCOMMONERRORHANDLER
    CLR COCO3DCOMMONERRORHANDLER+1
    STA $FFDF
    RTS

COCO3DCOMMONDISKERROR
    LDB #255
COCO3DCOMMONERRORHOOK
    LDX COCO3DCOMMONERRORHANDLER
    BNE COCO3DCOMMONERRORHOOK000
    JMP COCO3DCOMMONSAVEDERROR
COCO3DCOMMONERRORHOOK000
    LDS COCO3DCOMMONERRORSTACK
    JMP ,X
COCO3DCOMMONERRORSETTRAP
    STX COCO3DCOMMONERRORHANDLER
    PULS Y
    STS COCO3DCOMMONERRORSTACK
    JMP ,Y
COCO3DCOMMONERRORCLEARTRAP
    PSHS CC
    CLR COCO3DCOMMONERRORHANDLER
    CLR COCO3DCOMMONERRORHANDLER+1
    PULS CC,PC

COCO3DCOMMONFILEOPEN
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOCOMMONFILEERR
    JSR COCO3DCOMMONERRORSETTRAP
    JSR [COCO3DCOMMONDISKOPEN]
    JSR COCO3DCOMMONERRORCLEARTRAP
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
COCO3DCOMMONFILECLOSE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOCOMMONFILEERR
    JSR COCO3DCOMMONERRORSETTRAP
    JSR $A426
    JSR COCO3DCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

COCO3DCOMMONFILEIOERROR
    STB 1,S
    BSR COCO3DCOMMONFILECLOSE
    COMA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC
