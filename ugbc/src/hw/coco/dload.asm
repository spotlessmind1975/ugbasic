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
;*                            DLOAD ROUTINE ON COCO                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCOFCB
    rzb    64

COCODLOADSETUP
    STA $FFDE
    CLR RAMENABLED
    LDA #$7E
    LDX #COCODLOADERRORHOOK
    LDB $0191
    LDU $0192
    CMPU #COCODLOADERRORHOOK
    beq COCODLOAD000
    STA $0191
    STX $0192
    STB COCODLOADSAVEDERROR
    STU COCODLOADSAVEDERROR+1
COCODLOAD000  
    LDX $C004
    CMPX #$D66C
    BEQ COCODLOADDISK10
    CMPX #$D75F
    BEQ COCODLOADDISK11
    LDX #COCODLOADDISKERROR
    BRA COCODLOAD010
COCODLOADDISK10   
    LDX #$C483
    BRA COCODLOAD010
COCODLOADDISK11   
    LDX #$C48D
COCODLOAD010  
    STX COCODLOADDISKOPEN
    CLR COCODLOADERRORHANDLER
    CLR COCODLOADERRORHANDLER+1
    STA $FFDF
    RTS

COCODLOADDISKERROR
    LDB #255
COCODLOADERRORHOOK
    LDX COCODLOADERRORHANDLER
    BNE COCODLOADERRORHOOK000
    JMP COCODLOADSAVEDERROR
COCODLOADERRORHOOK000
    LDS COCODLOADERRORSTACK
    JMP ,X
COCODLOADERRORSETTRAP
    STX COCODLOADERRORHANDLER
    PULS Y
    STS COCODLOADERRORSTACK
    JMP ,Y
COCODLOADERRORCLEARTRAP
    PSHS CC
    CLR COCODLOADERRORHANDLER
    CLR COCODLOADERRORHANDLER+1
    PULS CC,PC

COCODLOADFILEOPEN
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCODLOADFILEERR
    JSR COCODLOADERRORSETTRAP
    JSR [COCODLOADDISKOPEN]
    BSR COCODLOADERRORCLEARTRAP
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC
COCODLOADFILEERR 
    COMA
    STB 1,S
    STA $FFDF
    PULS D,X,Y,U,PC
COCODLOADFILECLOSE
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCODLOADFILEERR
    JSR COCODLOADERRORSETTRAP
    JSR $A426
    BSR COCODLOADERRORCLEARTRAP
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC

COCODLOADFILEREAD
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCODLOADFILEIOERROR
    JSR COCODLOADERRORSETTRAP
    JSR $A176
    BSR COCODLOADERRORCLEARTRAP
    STA ,S
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC
COCODLOADFILEWRITE
    STA $FFDE
    CLR RAMENABLED
    PSHS D,X,Y,U
    LDX #COCODLOADFILEIOERROR
    JSR COCODLOADERRORSETTRAP
    JSR $A282
    BSR COCODLOADERRORCLEARTRAP
    CLRA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC
COCODLOADFILEIOERROR
    STB 1,S
    BSR COCODLOADFILECLOSE
    COMA
    LDA #1
    STA $FFDF
    STA RAMENABLED
    PULS D,X,Y,U,PC

; X : filename, U : size of filename
; Y : destination area
COCODLOAD
    PSHS Y
    LDY #$094C
    LDA #32
    LDB #11
COCODLOADL1
    STA B, Y
    DECB
    BNE COCODLOADL1

    LDB #0
COCODLOADL2
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPA #'.'
    BEQ COCODLOADL2E
    CMPU #0
    BEQ COCODLOADENDE
    CMPB #8
    BNE COCODLOADL2

COCODLOADL2E
    DECB
    LDA #$20
    STA B, Y
    INCB
    LEAX B, X
    LEAY 8, Y
    LDB #0
COCODLOADL3
    LDA B, X
    STA B, Y
    INCB
    LEAU -1, U
    CMPU #0
    BEQ COCODLOADENDE
    CMPB #3
    BNE COCODLOADL3

COCODLOADENDE
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
    JSR COCODLOADFILEOPEN
    BCS COCODLOADERR

COCODLOADREADL1
    LDA #1
    STA $006F
    LDB #1
    JSR COCODLOADFILEREAD
    LDB $0070
    BNE COCODLOADREADDONE
    STA , Y+
    JMP COCODLOADREADL1

COCODLOADREADDONE
    LDA #1
    STA $006F
    LDB #1
    JSR COCODLOADFILECLOSE

COCODLOADERR
    STB DLOADERROR
    RTS
