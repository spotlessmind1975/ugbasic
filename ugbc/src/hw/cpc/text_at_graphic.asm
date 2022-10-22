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

TEXTATDECODE:
    CP 97
    JR C, TEXTATDECODEX1F
    SUB 96
    JP TEXTATDECODE0
TEXTATDECODEX1F:
    ; CP 64
    ; JR C, TEXTATDECODEX39
    ; SUB 64
    ; JP TEXTATDECODE0
; TEXTATDECODEX39:
;     CP $5F
;     JR C, TEXTATDECODEX5A
;     SUB $40
;     JP TEXTATDECODE0
; TEXTATDECODEX5A:
;     CP $7F
;     JR C, TEXTATDECODEX7F
;     SUB $20
;     JP TEXTATDECODE0
; TEXTATDECODEX7F:
;     LD A, $60
;     JP TEXTATDECODE0
TEXTATDECODE0:
    ; AND $3F
    RET

TEXTATPIXPOS:
    PUSH AF
    PUSH DE
    PUSH HL
    LD HL, PLOTVBASE

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATPIXPOSSKIPY

    LD E, A
    LD A, $0
    LD D, A

    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D

    ADD HL, DE

TEXTATPIXPOSSKIPY:    
    LD A, (HL)
    LD (COPYOFTEXTADDRESS), A
    INC HL
    LD A, (HL)
    LD (COPYOFTEXTADDRESS+1), A

    LD HL, (COPYOFTEXTADDRESS)

    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    ; PUSH HL
    ; LD HL, DE
    ; ADD HL, HL
    ; ADD HL, HL
    ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

    LD A, (CURRENTMODE)
    CP 0
    JP Z, TEXTATPIXPOSSKIPY0
    CP 1
    JP Z, TEXTATPIXPOSSKIPY1
    CP 2
    JP Z, TEXTATPIXPOSSKIPY2
    CP 3
    JP Z, TEXTATPIXPOSSKIPY3
    JP TEXTATPIXPOSSKIPY2

TEXTATPIXPOSSKIPY0:
TEXTATPIXPOSSKIPY3:
    ADD HL, DE
    ADD HL, DE
TEXTATPIXPOSSKIPY1:
    ADD HL, DE
TEXTATPIXPOSSKIPY2:
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP HL
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
    PUSH BC

    LD BC, 8

    LD H, 0
    LD L, A
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    LD HL, TEXTATBMFONTLC
    ADD HL, DE

    CALL TEXTATPIXPOS

    LD DE, (COPYOFTEXTADDRESS)

    LD A, (CURRENTMODE)
    CP 0
    JP Z, TEXTATFONT0L1
    CP 1
    JP Z, TEXTATFONT1L1
    CP 2
    JP Z, TEXTATFONT2L1
    CP 3
    JP Z, TEXTATFONT0L1
    JP TEXTATFONT2L1

; Mode 0, 160×200, 16 colors (each byte of video memory represents 2 pixels):
; bit 7	bit 6	bit 5	bit 4	bit 3	bit 2	bit 1	bit 0
; pixel 0 (bit 0)	pixel 1 (bit 0)	pixel 0 (bit 2)	pixel 1 (bit 2)	pixel 0 (bit 1)	pixel 1 (bit 1)	pixel 0 (bit 3)	pixel 1 (bit 3)

TEXTATFONT0L1:

    PUSH DE

    LD A, (HL)
    AND $03
    LD B, A
    SRA A
    SRA A
    OR B
    LD B, A
    SRA A
    SRA A
    OR B
    LD (DE), A
    
    INC DE

    LD A, (HL)
    AND $0C
    LD B, A
    SRA A
    SRA A
    OR B
    LD B, A
    SRA A
    SRA A
    OR B
    LD (DE), A

    INC DE

    LD A, (HL)
    AND $30
    LD B, A
    SRA A
    SRA A
    OR B
    LD B, A
    SRA A
    SRA A
    OR B
    LD (DE), A

    INC DE

    LD A, (HL)
    AND $C0
    LD B, A
    SRA A
    SRA A
    OR B
    LD B, A
    SRA A
    SRA A
    OR B
    LD (DE), A

    POP DE

    PUSH HL
    LD HL, DE
    LD DE, $800
    ADD HL, DE
    LD DE, HL
    POP HL

    INC HL
    DEC C
    JR NZ, TEXTATFONT0L1

    JP TEXTATFONTLE

; Mode 1, 320×200, 4 colors (each byte of video memory represents 4 pixels):
; bit 7	bit 6	bit 5	bit 4	bit 3	bit 2	bit 1	bit 0
; pixel 0 (bit 1)	pixel 1 (bit 1)	pixel 2 (bit 1)	pixel 3 (bit 1)	pixel 0 (bit 0)	pixel 1(bit 0)	pixel 2 (bit 0)	pixel 3 (bit 0)

TEXTATFONT1L1:

    PUSH DE

    PUSH DE
    LD A, 0
    LD D, A
    LD A, (HL)
    SRL A
    SRL A
    SRL A
    SRL A
    LD E, A
    PUSH HL
    LD HL, CPCVIDEOBITMASK1
    ADD HL, DE
    LD A, (HL)
    POP HL
    POP DE
    LD (DE), A

    INC DE

    PUSH DE
    LD A, 0
    LD D, A
    LD A, (HL)
    AND $0F
    LD E, A
    PUSH HL
    LD HL, CPCVIDEOBITMASK1
    ADD HL, DE
    LD A, (HL)
    POP HL
    POP DE
    LD (DE), A

    POP DE

    PUSH HL
    LD HL, DE
    LD DE, $800
    ADD HL, DE
    LD DE, HL
    POP HL

    INC HL
    DEC C
    JR NZ, TEXTATFONT1L1

    JP TEXTATFONTLE

TEXTATFONT2L1:

    LD A, (HL)
    LD (DE), A

    PUSH HL
    LD HL, DE
    LD DE, $800
    ADD HL, DE
    LD DE, HL
    POP HL

    INC HL

    DEC C
    JR NZ, TEXTATFONT2L1

TEXTATFONTLE:
    POP BC
    POP DE

    LD A,(TEXTWW)
    AND $2
    JR Z, TEXTATBMCNOPEN

    PUSH BC
    PUSH AF

    LD BC, $7F01
    OUT (C), C
    LD A, (_PEN)
    OR A, $40
    OUT (C), A

    POP AF
    POP BC

TEXTATBMCNOPEN:
    JP TEXTATBMINCX

TEXTATBMSKIPTAB:
    LD A, (TABSTODRAW)
    DEC A
    LD (TABSTODRAW),A
    JP TEXTATBMINCX

TEXTATBMINCX:
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, 1
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
        