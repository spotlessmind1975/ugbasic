; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers   *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;*                         TEXT ROUTINES FOR GB                                *
;*                                                                             *
;*                          by Marco Spedaletti                                *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

WRITECHAR:
    LD HL, (TEXTADDRESS)
    LD D, 0
    LD A, (YCURSYS)
    LD E, A
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL,DE

    LD A, (XCURSYS)
    LD D, 0
    LD E,A
    ADD HL,DE

    CALL WAITSTATE

    LD A, C
    LD (HL), A
    RET

; Read a char from the text buffer to print.
; Input: DE - pointer to the string to print
;        C - characters left to print
; Output: DE is updated; C is updated
TEXTATREADCHAR:
    LD A, (DE)
    INC DE
    DEC C
    RET

TEXTATBITMAPMODE:

    LD A, C
    CP 0
    JR NZ,TEXTATBMGO
    RET

TEXTATBMGO:

    LD A, 0
    LD (TABSTODRAW), A

TEXTATBMSKIP:

    LD A, (CONSOLEX2)
    LD B, A
    LD A, (XCURSYS)
    CP B
    JR Z, TEXTATBMLOOP
    JP NC, TEXTATBMINCY
    JP TEXTATBMLOOP

TEXTATBMLOOP:

    LD A, (TABSTODRAW)
    CP 0
    JR Z,TEXTATBMMAIN
    JP TEXTATBMSKIPTAB

TEXTATBMMAIN:
    CALL TEXTATREADCHAR

    CP 31
    JR C,TEXTATBMPARSE
    JP TEXTATBMPRINT

TEXTATBMPARSETAB:
    LD A, (TABCOUNT)
    LD B, A
    LD A, (XCURSYS)
TEXTATBMPARSETAB2:
    CP B
    JR Z, TEXTATBMPARSETAB3
    JR C, TEXTATBMPARSETAB3
    SUB A, B
    JP TEXTATBMPARSETAB2
TEXTATBMPARSETAB3:
    LD B, A
    LD A, (TABCOUNT)
    SUB A, B
    LD (TABSTODRAW), A
    JP TEXTATBMNEXT

TEXTATBMPARSE:
    CP 13
    JR Z, TEXTATBMPARSELF
    CP 10
    JR Z, TEXTATBMPARSELF
    CP 9
    JR Z, TEXTATBMPARSETAB
    CP 1
    JR Z, TEXTATBMPARSEPEN
    CP 2
    JR Z, TEXTATBMPARSEPAPER
    CP 3
    JR Z, TEXTATBMCPARSECMOVE
    CP 4
    JR Z, TEXTATBMPARSEAT
    CP 5
    JR Z, TEXTATBMPARSECLS
    JP TEXTATBMNEXT

TEXTATBMPARSECLS:
    PUSH AF
    PUSH DE
    PUSH HL
    PUSH BC
    ; CALL CLSG
    POP BC
    POP HL
    POP DE
    POP AF
    JP TEXTATBMNEXT

TEXTATBMPARSELF:
    JP TEXTATBMINCY

TEXTATBMPARSEAT:
    LD A, (XCURSYS)
    LD B, A
    CALL TEXTATREADCHAR
    SUB A, B
    LD B, A
    LD A, (CONSOLEX1)
    ADD A, B
    LD (CLINEX), A
    LD A, (YCURSYS)
    LD B, A
    CALL TEXTATREADCHAR
    SUB A, B
    LD B, A
    LD A, (CONSOLEY1)
    ADD A, B
    LD (CLINEY), A
    JP TEXTATBMCMOVE

TEXTATBMPARSEPEN:
    CALL TEXTATREADCHAR
    CP $FF
    JR NZ, TEXTATBMPARSEPEN2
    LD A, 0
TEXTATBMPARSEPEN2:
    LD (_PEN), A
    JP TEXTATBMNEXT

TEXTATBMPARSEPAPER:
    CALL TEXTATREADCHAR
    LD (_PAPER), A
    JP TEXTATBMNEXT

TEXTATBMCPARSECMOVE:
    CALL TEXTATREADCHAR
    LD (CLINEX), A
    CALL TEXTATREADCHAR
    LD (CLINEY), A

TEXTATBMCMOVE:
    PUSH BC
    LD A, (XCURSYS)
    LD B, A
    LD A, (CLINEX)
    ADD A, B
    PUSH AF
    LD A, (CONSOLEX1)
    LD B, A
    POP AF
    CP B
    JR C, TEXTATBMCMOVESKIPX
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATBMCMOVESKIPXA
    JR NC, TEXTATBMCMOVESKIPX
TEXTATBMCMOVESKIPXA:
    LD (XCURSYS), A

    LD A, (CLINEY)

TEXTATBMCMOVESKIPX:
    LD B, A
    LD A, (YCURSYS)
    ADD A,B

TEXTATBMCMOVESKIPX2:

    PUSH AF
    LD A, (CONSOLEY1)
    LD B, A
    POP AF
    CP B
    JP C, TEXTATBMCMOVESKIPYL2
    PUSH AF
    LD A, (CONSOLEY2)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATBMCMOVESKIPYA
    JP NC, TEXTATBMCMOVESKIPYL2
TEXTATBMCMOVESKIPYA:
    LD (YCURSYS), A

TEXTATBMCMOVESKIPYL2:
    POP BC
    JP TEXTATBMNEXT

TEXTATBMPRINT:

    PUSH HL
    PUSH DE
    PUSH BC

    LD C, A
    CALL WRITECHAR

    POP BC
    POP DE
    POP HL

    JP TEXTATBMINCX

TEXTATBMSKIPTAB:
    LD A, (TABSTODRAW)
    DEC A
    JR Z, TEXTATBMSKIPTAB2
TEXTATBMSKIPTAB2:
    LD (TABSTODRAW),A
    JP TEXTATBMINCX

TEXTATBMINCX:
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    LD A, C
    CP 0
    JP Z, TEXTATBMDONE
    LD A, (XCURSYS)
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATBMNEXT
    JR NC, TEXTATBMINCY
    JP TEXTATBMNEXT
TEXTATBMINCY:
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    PUSH AF
    LD A, (CONSOLEY2)
    LD B, A
    POP AF
    CP B

    JR Z, TEXTATBMNEXT
    JR NC, TEXTATBMSCROLLY
    JP TEXTATBMNEXT
TEXTATBMSCROLLY:

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

TEXTATBMNEXT:
    LD A, (TABSTODRAW)
    CP 0
    JR Z, TEXTATBMXLOOP
    JP TEXTATBMLOOP
TEXTATBMXLOOP:
    LD A, C
    CP 0
    JR Z, TEXTATBMDONE
    JP TEXTATBMLOOP
TEXTATBMDONE:

    RET
