; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
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
;*                         BASIC DISK LOADER FOR COCO3                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

    SETDP $00

GETCHR          EQU $a176
CLOSEF          EQU $a426
OPEN10          EQU $c483
OPEN11          EQU $c48d
DSKVER          EQU $c004
DSKVER10        EQU $d66c
DSKVER11        EQU $d75f

ERRHK1          EQU $0191
ERRHK2          EQU $0192
FILNUM          EQU $006f
EOFFLG          EQU $0070
FNBUF           EQU $094c
DRVNUM          EQU $00eb

    ORG $0e00

START
    JSR INITDSK
    LDA $FF91
    ANDA #$FE
    STA $FF91
    LDX #FILETAB

NEXTFIL
    LDA ,X
    BEQ ALLDONE
    JSR LOADONE
    LDY CURPOS
    LDA #'.'
    STA ,Y+
    STY CURPOS
    BCC NEXTFIL
ALLDONE         
    JMP $2a00

COPYBLOCK
    PSHS X
    ORCC #$50
    LDU #$2000
    LDX #$1100
COPYBLOCKDEST
    LDY #$0000
    STA $ffdf
COPYBLOCKL1
    LDA ,X+
    STA ,Y+
    LEAU -1, U
    CMPU #0000
    BNE COPYBLOCKL1
    STA $ffde
    ANDCC #$9f
    PULS X
    RTS

COPYBLOCKGIME
    ORCC #$50
    LDU #$2000
    LDX #$1100
    LDY #$c000
    STA $ffdf
COPYBLOCKGIMEBANK
    LDA #$00
    STA $ffa6
COPYBLOCKGIMEL1
    LDA ,X+
    STA ,Y+
    LEAU -1, U
    CMPU #0000
    BNE COPYBLOCKGIMEL1
    LDA #$3e
    STA $ffa6
    STA $ffde
    ANDCC #$9f
    RTS

LOADONE
    PSHS X
    LDU #FNBUF
    LDB #11
CPYNAM
    LDA ,X+
    STA ,U+
    DECB
    BNE CPYNAM
    LDD ,X++
    STD COPYBLOCKDEST+2
    CMPD #$2A00
    BEQ CPYNAM2
    LDD #$1100
CPYNAM2
    STD DESTPTR
    LDB ,X+
    STB COPYBLOCKGIMEBANK+1
    CLR DRVNUM
    JSR OPENFIL
    BCS LOADERR
    JSR GETBYTE
    JSR GETBYTE
    JSR GETBYTE
    JSR GETBYTE
    JSR GETBYTE
READLOOP
    JSR GETBYTE
    BCS LOADERR
    TST EOFFLG
    BNE CLOSEOK
    LDX DESTPTR
    STA ,X+
    STX DESTPTR
    BRA READLOOP
CLOSEOK         
    JSR CLOSEFIL
    BCS LOADERR
    ANDCC #$fe
    LDA COPYBLOCKGIMEBANK+1
    BEQ CLOSEOKNB
    JSR COPYBLOCKGIME
    BRA CLOSEOKNBDONE
CLOSEOKNB
    LDD COPYBLOCKDEST+2
    CMPD #$2a00
    BEQ CLOSEOKNBDONE
    JSR COPYBLOCK
CLOSEOKNBDONE
    PULS X
    LEAX 14,X
    RTS
LOADERR
    STB LASTERR
    JSR CLOSEFIL
    ORCC #$01
    PULS X
    LEAX 14,X
    RTS

INITDSK
    LDA #$7e
    LDX #ERRHOOK
    LDB ERRHK1
    LDU ERRHK2
    CMPU #ERRHOOK
    BEQ IDVER                ; il nostro hook e' gia' installato
    STA ERRHK1
    STX ERRHK2
    STB SAVEDERR
    STU SAVEDERR+1
IDVER
    LDX DSKVER
    CMPX #DSKVER10
    BEQ ISV10
    CMPX #DSKVER11
    BEQ ISV11
    LDX #BADROM
    BRA GOTVER
ISV10
    LDX #OPEN10
    BRA GOTVER
ISV11
    LDX #OPEN11
GOTVER
    STX OPENVEC
    CLR ERRHNDL
    CLR ERRHNDL+1
    RTS

BADROM
    COMA
    LDB #255
    RTS

OPENFIL
    LDB #2
    STB FILNUM
    LDA #'I'
    LDX #OPNERR
    BSR SETTRAP
    JSR [OPENVEC]
    BSR CLRTRAP
    RTS
OPNERR
    COMA
    RTS

CLOSEFIL
    LDX #CLSERR
    BSR SETTRAP
    JSR CLOSEF
    BSR CLRTRAP
    RTS
CLSERR
    COMA
    RTS

GETBYTE
    LDX #RDERR
    BSR SETTRAP
    JSR GETCHR
    BSR CLRTRAP
    ANDCC #$fe
    RTS
RDERR
    JSR CLOSEFIL
    COMA
    RTS

SETTRAP
    STX ERRHNDL
    STS ERRSTACK
    RTS

CLRTRAP
    PSHS CC
    CLR ERRHNDL
    CLR ERRHNDL+1
    PULS CC
    RTS

ERRHOOK
    LDX ERRHNDL
    BNE TRAPPED
    JMP SAVEDERR
    
TRAPPED
    LDS ERRSTACK
    JMP ,X

SAVEDERR        RZB 3
OPENVEC         RZB 2
ERRHNDL         RZB 2
ERRSTACK        RZB 2
DESTPTR         RZB 2
LASTERR         RZB 1
CURPOS          FDB $0400

FILETAB
    fcb $42, $42
    RZB 14 * 64

