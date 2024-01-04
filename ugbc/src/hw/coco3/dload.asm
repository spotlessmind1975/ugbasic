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
;*                            DLOAD ROUTINE ON COCO33                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCO3FCB
    rzb    64

COCO3DLOADSETUP
    STA $FFDE
    CLR RAMENABLED
    LDA #$7E
    LDX #COCO3DLOADERRORHOOK
    LDB $0191
    LDU $0192
    CMPU #COCO3DLOADERRORHOOK
    beq COCO3DLOAD000
    STA $0191
    STX $0192
    STB COCO3DLOADSAVEDERROR
    STU COCO3DLOADSAVEDERROR+1
COCO3DLOAD000  
    LDX $C004
    CMPX #$D66C
    BEQ COCO3DLOADDISK10
    CMPX #$D75F
    BEQ COCO3DLOADDISK11
    LDX #COCO3DLOADDISKERROR
    BRA COCO3DLOAD010
COCO3DLOADDISK10   
    LDX #$C483
    BRA COCO3DLOAD010
COCO3DLOADDISK11   
    LDX #$C48D
COCO3DLOAD010  
    STX COCO3DLOADDISKOPEN
    CLR COCO3DLOADERRORHANDLER
    CLR COCO3DLOADERRORHANDLER+1
    STA $FFDF
    RTS

COCO3DLOADDISKERROR
    LDB #255
COCO3DLOADERRORHOOK
    LDX COCO3DLOADERRORHANDLER
    BNE COCO3DLOADERRORHOOK000
    JMP COCO3DLOADSAVEDERROR
COCO3DLOADERRORHOOK000
    LDS COCO3DLOADERRORSTACK
    JMP ,X
COCO3DLOADERRORSETTRAP
    STX COCO3DLOADERRORHANDLER
    PULS Y
    STS COCO3DLOADERRORSTACK
    JMP ,Y
COCO3DLOADERRORCLEARTRAP
    PSHS CC
    CLR COCO3DLOADERRORHANDLER
    CLR COCO3DLOADERRORHANDLER+1
    PULS CC,PC

COCO3DLOADFILEOPEN
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCO3DLOADFILEERR
    JSR COCO3DLOADERRORSETTRAP
    JSR [COCO3DLOADDISKOPEN]
    BSR COCO3DLOADERRORCLEARTRAP
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC
COCO3DLOADFILEERR 
    COMA
    STB 1,S
    STA $FFDF
    PULS D,X,Y,U,PC
COCO3DLOADFILECLOSE
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCO3DLOADFILEERR
    JSR COCO3DLOADERRORSETTRAP
    JSR $A426
    BSR COCO3DLOADERRORCLEARTRAP
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC

COCO3DLOADFILEREAD
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCO3DLOADFILEIOERROR
    JSR COCO3DLOADERRORSETTRAP
    JSR $A176
    BSR COCO3DLOADERRORCLEARTRAP
    STA ,S
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC
COCO3DLOADFILEWRITE
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCO3DLOADFILEIOERROR
    JSR COCO3DLOADERRORSETTRAP
    JSR $A282
    BSR COCO3DLOADERRORCLEARTRAP
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC
COCO3DLOADFILEIOERROR
    STB 1,S
    BSR COCO3DLOADFILECLOSE
    COMA
    LDA #1
    STA $FFDF
    STA RAMENABLED
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
    LDY #COCO3FCB
    STY B,X
    PULS Y
    CLRA
    STA $00EB
    LDA #1
    STA $006F
    LDB #1
    LDA #'I'
    JSR COCO3DLOADFILEOPEN
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
    JSR COCO3DLOADFILECLOSE

COCO3DLOADERR
    STB DLOADERROR
    RTS
