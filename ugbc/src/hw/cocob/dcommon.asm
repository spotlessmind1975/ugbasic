; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                         COMMON DISK ROUTINE ON COCOB                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCOBFCB
    rzb    64

COCOBDCOMMONSETUP
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    LDA #$7E
    LDX #COCOBDCOMMONERRORHOOK
    LDB $0191
    LDU $0192
    CMPU #COCOBDCOMMONERRORHOOK
    beq COCOBDCOMMON000
    STA $0191
    STX $0192
    STB COCOBDCOMMONSAVEDERROR
    STU COCOBDCOMMONSAVEDERROR+1
COCOBDCOMMON000  
    LDX $C004
    CMPX #$D66C
    BEQ COCOBDCOMMONDISK10
    CMPX #$D75F
    BEQ COCOBDCOMMONDISK11
    LDX #COCOBDCOMMONDISKERROR
    BRA COCOBDCOMMON010
COCOBDCOMMONDISK10   
    LDX #$C483
    BRA COCOBDCOMMON010
COCOBDCOMMONDISK11   
    LDX #$C48D
COCOBDCOMMON010  
    STX COCOBDCOMMONDISKOPEN
    CLR COCOBDCOMMONERRORHANDLER
    CLR COCOBDCOMMONERRORHANDLER+1
    STA $FFDF
    RTS

COCOBDCOMMONDISKERROR
    LDB #255
COCOBDCOMMONERRORHOOK
    LDX COCOBDCOMMONERRORHANDLER
    BNE COCOBDCOMMONERRORHOOK000
    JMP COCOBDCOMMONSAVEDERROR
COCOBDCOMMONERRORHOOK000
    LDS COCOBDCOMMONERRORSTACK
    JMP ,X
COCOBDCOMMONERRORSETTRAP
    STX COCOBDCOMMONERRORHANDLER
    PULS Y
    STS COCOBDCOMMONERRORSTACK
    JMP ,Y
COCOBDCOMMONERRORCLEARTRAP
    PSHS CC
    CLR COCOBDCOMMONERRORHANDLER
    CLR COCOBDCOMMONERRORHANDLER+1
    PULS CC,PC

COCOBDCOMMONFILEOPEN
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOBCOMMONFILEERR
    JSR COCOBDCOMMONERRORSETTRAP
    JSR [COCOBDCOMMONDISKOPEN]
    JSR COCOBDCOMMONERRORCLEARTRAP
    CLRA
    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF
    PULS D,X,Y,U,PC
COCOBCOMMONFILEERR 
    COMA
    STB 1,S
    STA $FFDF
    PULS D,X,Y,U,PC
COCOBDCOMMONFILECLOSE
    ORCC #$50
    STA $FFDE
    CLR RAMENABLED
    ANDCC #$AF
    PSHS D,X,Y,U
    LDX #COCOBCOMMONFILEERR
    JSR COCOBDCOMMONERRORSETTRAP
    JSR $A426
    JSR COCOBDCOMMONERRORCLEARTRAP
    CLRA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC

COCOBDCOMMONFILEIOERROR
    STB 1,S
    BSR COCOBDCOMMONFILECLOSE
    COMA

    ORCC #$50
    LDA #1
    STA $FFDF
    STA RAMENABLED
    ANDCC #$AF

    PULS D,X,Y,U,PC
