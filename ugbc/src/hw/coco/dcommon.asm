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
;*                         COMMON DISK ROUTINE ON COCO                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCOFCB
    rzb    64

COCODCOMMONSETUP
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    LDA #$7E
    LDX #COCODCOMMONERRORHOOK
    LDB $0191
    LDU $0192
    CMPU #COCODCOMMONERRORHOOK
    beq COCODCOMMON000
    STA $0191
    STX $0192
    STB COCODCOMMONSAVEDERROR
    STU COCODCOMMONSAVEDERROR+1
COCODCOMMON000  
    LDX $C004
    CMPX #$D66C
    BEQ COCODCOMMONDISK10
    CMPX #$D75F
    BEQ COCODCOMMONDISK11
    LDX #COCODCOMMONDISKERROR
    BRA COCODCOMMON010
COCODCOMMONDISK10   
    LDX #$C483
    BRA COCODCOMMON010
COCODCOMMONDISK11   
    LDX #$C48D
COCODCOMMON010  
    STX COCODCOMMONDISKOPEN
    CLR COCODCOMMONERRORHANDLER
    CLR COCODCOMMONERRORHANDLER+1
    STA $FFDF
    RTS

COCODCOMMONDISKERROR
    LDB #255
COCODCOMMONERRORHOOK
    LDX COCODCOMMONERRORHANDLER
    BNE COCODCOMMONERRORHOOK000
    JMP COCODCOMMONSAVEDERROR
COCODCOMMONERRORHOOK000
    LDS COCODCOMMONERRORSTACK
    JMP ,X
COCODCOMMONERRORSETTRAP
    STX COCODCOMMONERRORHANDLER
    PULS Y
    STS COCODCOMMONERRORSTACK
    JMP ,Y
COCODCOMMONERRORCLEARTRAP
    PSHS CC
    CLR COCODCOMMONERRORHANDLER
    CLR COCODCOMMONERRORHANDLER+1
    PULS CC,PC

COCODCOMMONFILEOPEN
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOCOMMONFILEERR
    JSR COCODCOMMONERRORSETTRAP
    JSR [COCODCOMMONDISKOPEN]
    JSR COCODCOMMONERRORCLEARTRAP
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
COCODCOMMONFILECLOSE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOCOMMONFILEERR
    JSR COCODCOMMONERRORSETTRAP
    JSR $A426
    JSR COCODCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

COCODCOMMONFILEIOERROR
    STB 1,S
    BSR COCODCOMMONFILECLOSE
    COMA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC
