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
;*                      TEXT AT GIVEN POSITION ON CPC                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATPIXPOS:
    PUSH AF
    PUSH DE
    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATBMSKIP
    LD E, A
    LD A, 0
    LD D, A
    LD HL, PLOTVBASE
    ADC HL, DE
    LD A, (HL)
    LD (COPYOFTEXTADDRESS), A
    INC HL
    LD A, (HL)
    LD (COPYOFTEXTADDRESS), A

    LD HL, (COPYOFTEXTADDRESS)

    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    PUSH HL
    LD HL, DE
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    POP HL

    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE
    POP AF
    RET

TEXTATBITMAPMODE:

    LD A, C
    CP 0
    JR NZ,TEXTATBITMAPMODEGO
    JP TEXTATBITMAPMODEDONE

TEXTATBITMAPMODEGO:

TEXTATBMSKIP:
    
TEXTATBMLOOP2:

    LD A, (TABSTODRAW)
    CP 0
    JR Z,TEXTATBMNSKIPTAB
    JP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB:
    LD A,(DE)

    CP 31
    JR C,TEXTATBMCC

TEXTATBMXCC:
    JP TEXTATBMSP0

TEXTATBMTAB:
    LD A, (TABCOUNT)
    LD B, A
    LD A,(XCURSYS)
TEXTATBMTAB2:
    CP B
    JR C, TEXTATBMTAB3
    SUB A, B
    JP TEXTATBMTAB2
TEXTATBMTAB3:
    LD B, A
    LD A, (TABCOUNT)
    SUB A, B
    LD (TABSTODRAW), A
    JP TEXTATBMNEXT

TEXTATBMCC:
    CP 13
    JR Z, TEXTATBMLF
    CP 10
    JR Z, TEXTATBMLF
    CP 9
    JR Z, TEXTATBMTAB
    CP 1
    JR Z, TEXTATBMPEN
    CP 2
    JR Z, TEXTATBMPAPER
    CP 3
    JR Z, TEXTATBMCMOVEPREPARE
    CP 4
    JR Z, TEXTATBMXAT
    CP 5
    JR Z, TEXTATBMCLS
    JP TEXTATBMNEXT

TEXTATBMCLS:
    PUSH AF
    PUSH DE
    PUSH HL
    PUSH BC
    CALL CLSG
    POP BC
    POP HL
    POP DE
    POP AF
    JP TEXTATBMNEXT

TEXTATBMLF:
    LD A, 0
    LD (XCURSYS), A
    JP TEXTATBMNEXT2

TEXTATBMXAT:
    JP TEXTATBMAT

TEXTATBMPEN:
    INC DE
    DEC C
    LD A, (TEXTWW)
    AND $2
    JR Z,TEXTATBMPENDISABLED
    LD A, (DE)
    LD (_PEN), A
TEXTATBMPENDISABLED:
    INC DE
    JP TEXTATBMNEXT

TEXTATBMPAPER:
    INC DE
    DEC C
    LD A,(TEXTWW)
    AND $1
    JR Z, TEXTATBMPAPERDISABLED
    LD A, (DE)
    ; STA $d021
    ; STA $d020
TEXTATBMPAPERDISABLED:
    INC DE
    JP TEXTATBMNEXT

TEXTATBMCMOVEPREPARE:
    INC DE
    DEC C
    LD A,(DE)
    LD (CLINEX), A
    INC DE
    DEC C
    LD A, (DE)
    LD (CLINEY), A

TEXTATBMCMOVE:
    LD A,(XCURSYS)
    LD B, A
    LD A,(CLINEX)
    ADD A, B
    CP $80
    JR NC, TEXTATBMCMOVESKIPX
    PUSH AF
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    POP AF
    CP B
    JR NC, TEXTATBMCMOVESKIPX
    LD (XCURSYS), A
    LD A,(CLINEX)

    CP $80
    JR C, TEXTATBMCMOVEADDPX

TEXTATBMCMOVESUBPX:
    XOR $FF
    ADD 1
    LD (CLINEX), A

    JP TEXTATBMCMOVESKIPX

TEXTATBMCMOVEADDPX:

    LD (CLINEX), A

    JP TEXTATBMCMOVESKIPX

TEXTATBMCMOVESKIPX:

    LD A,(YCURSYS)
    LD B, A
    LD A, (CLINEY)
    ADD A,B

    CP $80
    JP NC, TEXTATBMCMOVESKIPY
    CP 26
    JP NC, TEXTATBMCMOVESKIPY
    LD (YCURSYS), A

TEXTATBMCMOVESKIPY:
    INC DE
    JP TEXTATBMNEXT

TEXTATBMAT:
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
    JP TEXTATBMCMOVE

TEXTATBMSP0:
    LD A, (DE)
    CALL TEXTATDECODE

    PUSH DE

    LD BC, 8

    LD H, 0
    LD L, A
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    LD HL, TEXTATBMFONT
    ADD HL, DE

TEXTATFONTL1:
    
    CALL TEXTATPIXPOS

    LD DE, (COPYOFTEXTADDRESS)

    LD A, (HL)
    LD (DE), A

    INC HL
    DEC C
    JR NZ, TEXTATFONTL1

    POP DE

    LD A,(TEXTWW)
    AND $2
    JR Z, TEXTATBMCNOPEN

TEXTATBMCNOPEN:
    JP TEXTATBMINCX

TEXTATBMSKIPTAB:
    LD A, (TABSTODRAW)
    DEC A
    LD (TABSTODRAW),A
    JP TEXTATBMINCX

TEXTATBMINCX:
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, 8
    LD (COPYOFTEXTADDRESS), HL
    INC DE
    LD A,(XCURSYS)
    INC A
    LD (XCURSYS), A
    PUSH AF
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATBMNEXT2
    JP TEXTATBMNEXT
TEXTATBMNEXT2:
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

    JR Z, TEXTATBMNEXT3
    JP TEXTATBMNEXT
TEXTATBMNEXT3:

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    CALL VSCROLLTUP
    POP HL
    POP DE
    POP BC
    POP AF

    LD A, (YCURSYS)
    DEC A
    LD (YCURSYS), A

    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    PUSH HL
    LD HL, DE
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    POP HL

    LD HL, (COPYOFTEXTADDRESS)
    SBC HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE

TEXTATBMNEXT:
    LD A, (TABSTODRAW)
    CP 0
    JR Z, TEXTATBMXLOOP2
    JP TEXTATBMLOOP2
TEXTATBMXLOOP2:
    DEC C
    JR Z, TEXTATBMEND
    JP TEXTATBMLOOP2
TEXTATBMEND:
    JP TEXTATBITMAPMODEDONE

TEXTATBITMAPMODEDONE:
    RET
        