; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
    CP 123
    JR NC, TEXTATDECODEX1F
    CP 97
    JR C, TEXTATDECODEX1F
    SUB 96
    JP TEXTATDECODE0
TEXTATDECODEX1F:
TEXTATDECODE0:
    RET

TEXTATBITMAPMODE:

    LD A, C
    CP 0
    JR NZ,TEXTATBITMAPMODEGO
    JP TEXTATBITMAPMODEDONE

TEXTATBITMAPMODEGO:

TEXTATBMSKIP:

    LD A, (CONSOLEX2)
    LD B, A
    LD A, (XCURSYS)
    CP B
    JR Z, TEXTATBMLOOP2
    JP NC, TEXTATBMNEXT2
    JP TEXTATBMLOOP2

TEXTATBMLOOP2:

    LD A, (TABSTODRAW)
    CP 0
    JR Z,TEXTATBMNSKIPTAB
    JP TEXTATBMSKIPTAB

TEXTATBMNSKIPTAB:
    LD A, (DE)

    CP 31
    JR C,TEXTATBMCC

TEXTATBMXCC:
    JP TEXTATBMSP0

TEXTATBMTAB:
    LD A, (TABCOUNT)
    LD B, A
    LD A, (XCURSYS)
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
    INC DE
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
    INC DE
    DEC C
    JP TEXTATBMNEXT2

TEXTATBMXAT:
    JP TEXTATBMAT

TEXTATBMPEN:
    INC DE
    DEC C
    LD A, (DE)
    CP $FF
    JR NZ, TEXTATBMPEN2
    LD A, 0
TEXTATBMPEN2:
    LD (_PEN), A
    INC DE
    JP TEXTATBMNEXT

TEXTATBMPAPER:
    INC DE
    DEC C
    LD A, (DE)
    LD (_PAPER), A
    ; STA $d021
    ; STA $d020
    INC DE
    DEC C
    JP TEXTATBMNEXT

TEXTATBMCMOVEPREPARE:
    INC DE
    DEC C
    LD A, (DE)
    LD (CLINEX), A
    INC DE
    DEC C
    LD A, (DE)
    LD (CLINEY), A
    INC DE
    DEC C

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
    JR NC, TEXTATBMCMOVESKIPX
    LD (XCURSYS), A
    LD A, (CLINEY)

;     CP $80
;     JR C, TEXTATBMCMOVEADDPX

; TEXTATBMCMOVESUBPX:
;     XOR $FF
;     ADD 1
;     LD (CLINEY), A

;     JP TEXTATBMCMOVESKIPX

; TEXTATBMCMOVEADDPX:

;     LD (CLINEY), A

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
    JP NC, TEXTATBMCMOVESKIPYL2

    LD (YCURSYS), A

TEXTATBMCMOVESKIPYL2:
    POP BC
    JP TEXTATBMNEXT

TEXTATBMAT:
    INC DE
    DEC C
    LD A, (XCURSYS)
    LD B, A
    LD A, (DE)
    SUB A, B
    LD B, A
    LD A, (CONSOLEX1)
    ADD A, B
    LD (CLINEX), A
    INC DE
    DEC C
    LD A, (YCURSYS)
    LD B, A
    LD A, (DE)
    SUB A, B
    LD B, A
    LD A, (CONSOLEY1)
    ADD A, B
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
    LD HL, UDCCHAR
    ADD HL, DE

    CALL TEXTATPIXPOS

    LD DE, (COPYOFTEXTADDRESS)

    ; We draw the text using a different approach,
    ; based on the current graphic mode.

    LD A, (CURRENTMODE)
    CP 0
    JP Z, TEXTATFONT0L1X
    CP 1
    JP Z, TEXTATFONT1L1X
    CP 2
    JP Z, TEXTATFONT2L1X
    CP 3
    JP Z, TEXTATFONT0L1X
    JP TEXTATFONT2L1

; Mode 0, 160×200, 16 colors (each byte of video memory represents 2 pixels):
; bit 7	bit 6	bit 5	bit 4	bit 3	bit 2	bit 1	bit 0
; pixel 0 (bit 0)	pixel 1 (bit 0)	pixel 0 (bit 2)	pixel 1 (bit 2)	pixel 0 (bit 1)	pixel 1 (bit 1)	pixel 0 (bit 3)	pixel 1 (bit 3)

;              3210
; COLOR => 0000abcd
;
;          01010101
; CHAR  => xxyyzzkk
;
; 01 01 01 01
; xx xx xx xx
; dd bb cc aa
;
; 01 01 01 01
; yy yy yy yy
; dd bb cc aa
;
; 01 01 01 01
; zz zz zz zz
; dd bb cc aa
;
; 01 01 01 01
; kk kk kk kk
; dd bb cc aa

; pixel 0 (bit 0)	pixel 1 (bit 0)	pixel 0 (bit 2)	pixel 1 (bit 2)	pixel 0 (bit 1)	pixel 1 (bit 1)	pixel 0 (bit 3)	pixel 1 (bit 3)

TEXTATFONT0L1X:
TEXTATFONT0L1:

    LD A, (_PEN)
    LD IXL, A
    LD A, 1
    LD IYL, A
    CALL CPCSELECTPALETTE
    LD A, IXH
    LD B, A

    PUSH DE

    LD A, (HL)
    SRL A
    SRL A
    SRL A
    SRL A
    SRL A
    SRL A
    CALL CPCVIDEOMUL84
    LD (DE), A
    
    INC DE

    LD A, (HL)
    SRL A
    SRL A
    SRL A
    SRL A
    AND $03
    CALL CPCVIDEOMUL84
    LD (DE), A

    INC DE

    LD A, (HL)
    SRL A
    SRL A
    AND $03
    CALL CPCVIDEOMUL84
    LD (DE), A

    INC DE

    LD A, (HL)
    AND $03
    CALL CPCVIDEOMUL84
    LD (DE), A

    POP DE

    ;;;;;;;;;; PAPER

    LD A, (_PAPER)
    LD IXL, A
    LD A, 1
    LD IYL, A
    CALL CPCSELECTPALETTE
    LD A, IXH
    LD B, A

    PUSH DE

    LD A, (HL)
    XOR $FF
    SRL A
    SRL A
    SRL A
    SRL A
    SRL A
    SRL A
    CALL CPCVIDEOMUL84
    LD IXH, A
    LD A, (DE)
    OR IXH
    LD (DE), A
    
    INC DE

    LD A, (HL)
    XOR $FF
    SRL A
    SRL A
    SRL A
    SRL A
    AND $03
    CALL CPCVIDEOMUL84
    LD IXH, A
    LD A, (DE)
    OR IXH
    LD (DE), A

    INC DE

    LD A, (HL)
    XOR $FF
    SRL A
    SRL A
    AND $03
    CALL CPCVIDEOMUL84
    LD IXH, A
    LD A, (DE)
    OR IXH
    LD (DE), A

    INC DE

    LD A, (HL)
    XOR $FF
    AND $03
    CALL CPCVIDEOMUL84
    LD IXH, A
    LD A, (DE)
    OR IXH
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
    JP NZ, TEXTATFONT0L1

    LD A, B
    LD H, A

    POP BC
    POP DE


    JP TEXTATFONTLE

; Mode 1, 320×200, 4 colors (each byte of video memory represents 4 pixels):
; bit 7	bit 6	bit 5	bit 4	bit 3	bit 2	bit 1	bit 0
; pixel 0 (bit 1)	pixel 1 (bit 1)	pixel 2 (bit 1)	pixel 3 (bit 1)	pixel 0 (bit 0)	pixel 1(bit 0)	pixel 2 (bit 0)	pixel 3 (bit 0)

TEXTATFONT1L1X:
TEXTATFONT1L1:

    LD A, (_PEN)
    LD IXL, A
    LD A, 1
    LD IYL, A
    CALL CPCSELECTPALETTE
    LD A, IXH
    LD B, A

    LD A, (HL)
    SRL A
    SRL A
    SRL A
    SRL A
    CALL CPCVIDEOMUL82
    LD (DE), A

    INC DE

    LD A, (HL)
    AND $0F
    CALL CPCVIDEOMUL82
    LD (DE), A

    DEC DE
    
    ; PAPER

    LD A, (_PAPER)
    LD IXL, A
    LD A, 1
    LD IYL, A
    CALL CPCSELECTPALETTE
    LD A, IXH
    LD B, A

    LD A, (HL)
    XOR $FF
    SRL A
    SRL A
    SRL A
    SRL A
    CALL CPCVIDEOMUL82
    LD IXH, A
    LD A, (DE)
    OR IXH
    LD (DE), A

    INC DE

    LD A, (HL)
    XOR $FF
    AND $0F
    CALL CPCVIDEOMUL82
    LD (DE), A
    LD IXH, A
    LD A, (DE)
    OR IXH

    DEC DE

    PUSH HL
    LD HL, DE
    LD DE, $800
    ADD HL, DE
    LD DE, HL
    POP HL

    INC HL
    DEC C
    JR NZ, TEXTATFONT1L1

    LD A, B
    LD H, A

    POP BC
    POP DE

    JP TEXTATFONTLE

TEXTATFONT2L1X:

    LD A, (_PAPER)
    LD IXH, 0
    LD IXL, A
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    LD A, (_PEN)
    LD IXH, 1
    LD IXL, A
    LD IYL, 1
    CALL CPCUPDATEPALETTE

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

    LD A, B
    LD H, A
    
    POP BC
    POP DE

TEXTATFONTLE:

    JP TEXTATBMINCX

TEXTATBMSKIPTAB:
    LD A, (TABSTODRAW)
    DEC A
    JR Z, TEXTATBMSKIPTAB2
    INC C ; Needed to continue to parsing the tab...
TEXTATBMSKIPTAB2:
    LD (TABSTODRAW),A
    JP TEXTATBMINCX

TEXTATBMINCX:
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, 1
    LD (COPYOFTEXTADDRESS), HL
    INC DE
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    DEC C
    JP Z, TEXTATBMEND2
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATBMNEXT
    JR NC, TEXTATBMNEXT2
    JP TEXTATBMNEXT
TEXTATBMNEXT2:
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

    JR Z, TEXTATBMNEXT3
    JR NC, TEXTATBMNEXT3
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
    LD A, C
    CP 0
    JR Z, TEXTATBMEND
    JP TEXTATBMLOOP2
TEXTATBMEND2:
TEXTATBMEND:
    JP TEXTATBITMAPMODEDONE

TEXTATBITMAPMODEDONE:
    RET
        