; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      TEXT AT GIVEN POSITION ON EF9345                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATDECODE:
    CP $61
    JR C, TEXTATDECODE0
    SUB $20
TEXTATDECODE0:
    RET

TEXTAT:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, C
    CP 0
    JR NZ,TEXTATGO
    JP TEXTATDONE

TEXTATGO:
    PUSH BC
    PUSH DE

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

    LD A, (CURRENTMODE)
    CP 0
    JR Z,TEXTATGO0

    POP DE
    POP BC

    RET

TEXTATGO0:
    POP DE
    ; LD HL, (TEXTADDRESS)
    ; LD (COPYOFTEXTADDRESS), HL
    JMP TEXTATGOX

TEXTATGOX:
    LD A, 0
    LD B, A
    LD (TABSTODRAW), A

TEXTATLOOP2:

    LD A, (TABSTODRAW)
    CP 0
    JR Z,TEXTATNSKIPTAB
    JMP TEXTATSKIPTAB

TEXTATNSKIPTAB:
    LD A, (DE)

    CP 31
    JR C,TEXTATCC

TEXTATXCC:
    CALL TEXTATDECODE
    JMP TEXTATSP0

TEXTATTAB:
    LD A, (TABCOUNT)
    LD B, A
    LD A,(XCURSYS)
TEXTATTAB2:
    CP B
    JR C, TEXTATTAB3
    SUB A, B
    JMP TEXTATTAB2
TEXTATTAB3:
    LD B, A
    LD A, (TABCOUNT)
    SUB A, B
    LD (TABSTODRAW), A
    JMP TEXTATNEXT

TEXTATCC:
    CP 13
    JR Z, TEXTATLF
    CP 10
    JR Z, TEXTATLF
    CP 9
    JR Z, TEXTATTAB
    CP 1
    JR Z, TEXTATPEN
    CP 2
    JR Z, TEXTATPAPER
    CP 3
    JR Z, TEXTATCMOVEPREPARE
    CP 4
    JR Z, TEXTATXAT
    CP 5
    JR Z, TEXTATCLS
    JMP TEXTATNEXT

TEXTATCLS:
    PUSH AF
    PUSH DE
    PUSH HL
    PUSH BC
    ; CALL CLS
    POP BC
    POP HL
    POP DE
    POP AF
    JMP TEXTATNEXT

TEXTATLF:
    LD A, (XCURSYS)
    LD B, A
    LD A, (CURRENTTILESWIDTH)
    SUB A, B
    DEC A

    PUSH DE
    LD HL, (COPYOFTEXTADDRESS)
    LD D, 0
    LD E, A
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL
    POP DE

    JMP TEXTATNEXT2

TEXTATXAT:
    JMP TEXTATAT

TEXTATPEN:
    INC DE
    DEC C
    LD A, (TEXTWW)
    AND $2
    JR Z,TEXTATPENDISABLED
    LD A, (DE)
    LD (_PEN), A
TEXTATPENDISABLED:
    INC DE
    JMP TEXTATNEXT

TEXTATPAPER:
    INC DE
    DEC C
    LD A,(TEXTWW)
    AND $1
    JR Z, TEXTATPAPERDISABLED
    LD A, (DE)
    ; STA $d021
    ; STA $d020
TEXTATPAPERDISABLED:
    INC DE
    JMP TEXTATNEXT

TEXTATCMOVEPREPARE:
    INC DE
    DEC C
    LD A,(DE)
    LD (CLINEX), A
    INC DE
    DEC C
    LD A, (DE)
    LD (CLINEY), A

TEXTATCMOVE:
    LD A,(XCURSYS)
    LD B, A
    LD A,(CLINEX)
    ADD A, B
    CP $80
    JR NC, TEXTATCMOVESKIPX
    PUSH AF
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    POP AF
    CP B
    JR NC, TEXTATCMOVESKIPX
    LD (XCURSYS), A

    LD A,(CLINEX)

    CP $80
    JR C, TEXTATCMOVEADDPX

TEXTATCMOVESUBPX:
    XOR $FF
    ADD 1
    LD (CLINEX), A

    LD HL, (COPYOFTEXTADDRESS)
    PUSH DE
    LD E, A
    LD D, 0
    SBC HL, DE
    POP DE
    LD (COPYOFTEXTADDRESS), HL

    JMP TEXTATCMOVESKIPX

TEXTATCMOVEADDPX:

    LD (CLINEX), A

    LD HL, (COPYOFTEXTADDRESS)
    PUSH DE
    LD E, A
    LD D, 0
    ADC HL, DE
    POP DE
    LD (COPYOFTEXTADDRESS), HL

    JMP TEXTATCMOVESKIPX

TEXTATCMOVESKIPX:

    LD A,(YCURSYS)
    LD B, A
    LD A, (CLINEY)
    ADD A,B

    CP $80
    JR NC, TEXTATCMOVESKIPY
    CP 26
    JR NC, TEXTATCMOVESKIPY
    LD (YCURSYS), A

TEXTATCMOVEADDPY:
    LD A, (CLINEY)
    CP $80
    JR C, TEXTATCMOVELOOPYP
    JMP TEXTATCMOVELOOPYM

TEXTATCMOVELOOPYP:
    PUSH BC
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
TEXTATCMOVELOOPY:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATCMOVELOOPY
    POP DE
    LD (COPYOFTEXTADDRESS), HL
    POP BC
    JMP TEXTATCMOVESKIPY

TEXTATCMOVELOOPYM:
    XOR $FF
    ADD A, 1
    LD (CLINEY), A


    PUSH BC
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
TEXTATCMOVELOOPY2:
    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    SBC HL, DE
    POP DE
    DEC C
    JR NZ, TEXTATCMOVELOOPY2
    LD (COPYOFTEXTADDRESS), HL
    POP BC
    JMP TEXTATCMOVESKIPY

TEXTATCMOVESKIPY:
    INC DE
    JMP TEXTATNEXT

TEXTATAT:
    INC DE
    DEC C
    LD A, (XCURSYS)
    LD B, A
    LD A, (DE)
    SUB A, B
    LD (CLINEX), A
    INC DE
    DEC C
    LD A, (YCURSYS)
    LD B, A
    LD A, (DE)
    SUB A, B
    LD (CLINEY), A
    JMP TEXTATCMOVE

TEXTATSP0:
    LD HL, (COPYOFTEXTADDRESS)

    PUSH DE
    PUSH AF

    LD D, REGISTER6
    LD A, (YCURSYS)
    LD E, A
    CALL EF9345LIB ; D=38 (registre R6) to say that we are going to give the line number, E line number

    LD D, REGISTER7
    LD A, (XCURSYS)
    LD E, A
    CALL EF9345LIB ; D=39 (registre R7) to say that we are going to give the column number, E column number

    LD D, REGISTER2
    LD E, 0
    CALL EF9345LIB  

    LD D, REGISTER3
    LD A, (_PEN)
    AND $07
    LD E, A
    CALL EF9345LIB  

    POP AF

    LD D, REGISTER1
    LD E, A
    CALL EF9345LIB

    LD D, REGISTERE
    LD E, 0
    CALL EF9345LIB

    PUSH AF
    LD A, (CURRENTMODE)
    CP 0
    JR Z,TEXTAT20
    POP AF

    POP DE
    POP BC

    RET

TEXTAT20:
    POP AF
    POP DE
    JMP TEXTAT2X

TEXTAT2X:
    LD A,(TEXTWW)
    AND $2
    JR Z, TEXTATCNOPEN
TEXTATCNOPEN:
    JMP TEXTATINCX

TEXTATSKIPTAB:
    LD A, (TABSTODRAW)
    DEC A
    LD (TABSTODRAW),A
    JMP TEXTATINCX

TEXTATINCX:
    INC DE
    LD A,(XCURSYS)
    INC A
    LD (XCURSYS), A
    PUSH AF
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATNEXT2
    JMP TEXTATNEXT
TEXTATNEXT2:
    LD A, 0
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    PUSH AF
    LD A, (CURRENTTILESHEIGHT)
    LD B, A
    POP AF
    CP B

    JR Z, TEXTATNEXT3
    JMP TEXTATNEXT
TEXTATNEXT3:

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    ; CALL VSCROLLTUP
    POP HL
    POP DE
    POP BC
    POP AF

    LD A, (YCURSYS)
    DEC A
    LD (YCURSYS), A
    LD HL, (COPYOFTEXTADDRESS)
    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    SBC HL, DE
    POP DE
    LD (COPYOFTEXTADDRESS), HL

TEXTATNEXT:
    LD A, (TABSTODRAW)
    CP 0
    JR Z, TEXTATXLOOP2
    JMP TEXTATLOOP2
TEXTATXLOOP2:
    DEC C
    JR Z, TEXTATEND
    JMP TEXTATLOOP2
TEXTATEND:
    JP TEXTATDONE

TEXTATDONE:
    POP BC

    RET