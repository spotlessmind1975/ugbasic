; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                      TEXT AT GIVEN POSITION ON MSX1                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 			        NAME		COLOR		PATTERN
; VDPUPDATE0: 		$0000		
; VDPUPDATE1:		$0000		$0480		$0800
; VDPUPDATE2:		$3800		$2000
; VDPUPDATE3:		$3800		$2000		$0000

TEXTATDECODE:
    CP 97
    JR C, TEXTATDECODEX1F
    SUB 96
    JP TEXTATDECODE0
TEXTATDECODEX1F:
    ; CP 64
    ; JR C, TEXTATDECODEX39
    ; SUB $40
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

TEXTATBITMAPMODE:
    LD A, C
    CP 0
    JR NZ,TEXTATBITMAPMODEGO
    RET

TEXTATBITMAPMODEGO:
    PUSH BC
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

    LD HL, $2000
    LD (COPYOFCOLORMAPADDRESS), HL

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATBMSKIP
    LD C, A
    LD HL, (COPYOFCOLORMAPADDRESS)
TEXTATBMLOOP1:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATBMLOOP1
    LD (COPYOFCOLORMAPADDRESS), HL

    LD HL, $0000
    LD (COPYOFTEXTADDRESS), HL

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATBMSKIP
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
TEXTATBMLOOP1B:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATBMLOOP1B
    LD (COPYOFTEXTADDRESS), HL

TEXTATBMSKIP:
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

    LD HL, (COPYOFCOLORMAPADDRESS)
    ADD HL, DE
    LD (COPYOFCOLORMAPADDRESS), HL

    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE
    POP BC
    
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
    ; CALL TEXTATBMDECODE
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
    LD A, (XCURSYS)
    LD B, A
    LD A, (CURRENTTILESWIDTH)
    SUB A, B
    DEC A

    PUSH DE
    LD E, A
    LD D, 0
    PUSH HL
    LD HL, DE
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    POP HL

    LD HL, (COPYOFCOLORMAPADDRESS)
    ADD HL, DE
    LD (COPYOFCOLORMAPADDRESS), HL

    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE

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

    PUSH DE
    LD E, A
    LD D, 0
    PUSH HL
    LD HL, DE
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    POP HL

    LD HL, (COPYOFCOLORMAPADDRESS)
    SBC HL, DE
    LD (COPYOFCOLORMAPADDRESS), HL

    LD HL, (COPYOFTEXTADDRESS)
    SBC HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE

    JP TEXTATBMCMOVESKIPX

TEXTATBMCMOVEADDPX:

    LD (CLINEX), A

    PUSH DE
    LD E, A
    LD D, 0
    PUSH HL
    LD HL, DE
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    POP HL

    LD HL, (COPYOFCOLORMAPADDRESS)
    ADC HL, DE
    LD (COPYOFCOLORMAPADDRESS), HL

    LD HL, (COPYOFTEXTADDRESS)
    ADC HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE

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

TEXTATBMCMOVEADDPY:
    LD A, (CLINEY)
    CP $80
    JR C, TEXTATBMCMOVELOOPYP
    JMP TEXTATBMCMOVELOOPYM

TEXTATBMCMOVELOOPYP:
    PUSH BC
    PUSH AF
    LD C, A
    LD B, 0

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

    LD HL, (COPYOFCOLORMAPADDRESS)
TEXTATBMCMOVELOOPYC:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATBMCMOVELOOPYC
    LD (COPYOFCOLORMAPADDRESS), HL

    LD HL, DE
    POP DE

    POP AF
    LD C, A
    LD B, 0

    PUSH DE
    LD DE, HL
    
    LD HL, (COPYOFTEXTADDRESS)
TEXTATBMCMOVELOOPY:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATBMCMOVELOOPY
    POP DE
    LD (COPYOFTEXTADDRESS), HL
    POP BC
    JP TEXTATBMCMOVESKIPY

TEXTATBMCMOVELOOPYM:
    XOR $FF
    ADD A, 1
    LD (CLINEY), A

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

    PUSH AF
    PUSH BC
    LD A, (CLINEY)
    LD C, A
    LD B, 0
    LD HL, (COPYOFCOLORMAPADDRESS)
TEXTATBMCMOVELOOPY2C:
    SBC HL, DE
    DEC C
    JR NZ, TEXTATBMCMOVELOOPY2C
    LD (COPYOFCOLORMAPADDRESS), HL
    POP BC
    POP AF

    PUSH AF
    PUSH BC
    LD A, (CLINEY)    
    LD C, A
    LD B, 0
    LD HL, (COPYOFTEXTADDRESS)
TEXTATBMCMOVELOOPY2:
    SBC HL, DE
    DEC C
    JR NZ, TEXTATBMCMOVELOOPY2
    LD (COPYOFTEXTADDRESS), HL
    POP BC
    POP AF
    POP DE

    JP TEXTATBMCMOVESKIPY

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
    LD H, 0
    LD L, A
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    LD HL, TEXTATBMFONT
    ADD HL, DE
    LD DE, (COPYOFTEXTADDRESS)
    LD BC, 8
    CALL VDPWRITE
    POP BC
    POP DE

    LD A,(TEXTWW)
    AND $2
    JR Z, TEXTATBMCNOPEN

    PUSH AF
    PUSH BC
    PUSH DE
    LD A, (_PAPER)
    LD B, A
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    OR B
    LD DE, (COPYOFCOLORMAPADDRESS)
    LD BC, $108
    CALL VDPFILL
    POP DE
    POP BC
    POP AF

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
    LD HL, (COPYOFCOLORMAPADDRESS)
    ADD HL, 8
    LD (COPYOFCOLORMAPADDRESS), HL
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

    CALL VSCROLLTUP

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

    LD HL, (COPYOFCOLORMAPADDRESS)
    SBC HL, DE
    LD (COPYOFCOLORMAPADDRESS), HL

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
    RET

TEXTATBMFONT:
   DB $3c, $66, $6e, $6e, $60, $62, $3c, $00
   DB $18, $3c, $66, $7e, $66, $66, $66, $00
   DB $7c, $66, $66, $7c, $66, $66, $7c, $00
   DB $3c, $66, $60, $60, $60, $66, $3c, $00
   DB $78, $6c, $66, $66, $66, $6c, $78, $00
   DB $7e, $60, $60, $78, $60, $60, $7e, $00
   DB $7e, $60, $60, $78, $60, $60, $60, $00
   DB $3c, $66, $60, $6e, $66, $66, $3c, $00
   DB $66, $66, $66, $7e, $66, $66, $66, $00
   DB $3c, $18, $18, $18, $18, $18, $3c, $00
   DB $1e, $0c, $0c, $0c, $0c, $6c, $38, $00
   DB $66, $6c, $78, $70, $78, $6c, $66, $00
   DB $60, $60, $60, $60, $60, $60, $7e, $00
   DB $63, $77, $7f, $6b, $63, $63, $63, $00
   DB $66, $76, $7e, $7e, $6e, $66, $66, $00
   DB $3c, $66, $66, $66, $66, $66, $3c, $00
   DB $7c, $66, $66, $7c, $60, $60, $60, $00
   DB $3c, $66, $66, $66, $66, $3c, $0e, $00
   DB $7c, $66, $66, $7c, $78, $6c, $66, $00
   DB $3c, $66, $60, $3c, $06, $66, $3c, $00
   DB $7e, $18, $18, $18, $18, $18, $18, $00
   DB $66, $66, $66, $66, $66, $66, $3c, $00
   DB $66, $66, $66, $66, $66, $3c, $18, $00
   DB $63, $63, $63, $6b, $7f, $77, $63, $00
   DB $66, $66, $3c, $18, $3c, $66, $66, $00
   DB $66, $66, $66, $3c, $18, $18, $18, $00
   DB $7e, $06, $0c, $18, $30, $60, $7e, $00
   DB $3c, $30, $30, $30, $30, $30, $3c, $00
   DB $00, $40, $60, $30, $18, $0c, $06, $00
   DB $3c, $0c, $0c, $0c, $0c, $0c, $3c, $00
   DB $00, $18, $3c, $7e, $18, $18, $18, $18
   DB $00, $10, $30, $7f, $7f, $30, $10, $00
   DB $00, $00, $00, $00, $00, $00, $00, $00
   DB $18, $18, $18, $18, $00, $00, $18, $00
   DB $66, $66, $66, $00, $00, $00, $00, $00
   DB $66, $66, $ff, $66, $ff, $66, $66, $00
   DB $18, $3e, $60, $3c, $06, $7c, $18, $00
   DB $62, $66, $0c, $18, $30, $66, $46, $00
   DB $3c, $66, $3c, $38, $67, $66, $3f, $00
   DB $06, $0c, $18, $00, $00, $00, $00, $00
   DB $0c, $18, $30, $30, $30, $18, $0c, $00
   DB $30, $18, $0c, $0c, $0c, $18, $30, $00
   DB $00, $66, $3c, $ff, $3c, $66, $00, $00
   DB $00, $18, $18, $7e, $18, $18, $00, $00
   DB $00, $00, $00, $00, $00, $18, $18, $30
   DB $00, $00, $00, $7e, $00, $00, $00, $00
   DB $00, $00, $00, $00, $00, $18, $18, $00
   DB $00, $03, $06, $0c, $18, $30, $60, $00
   DB $3c, $66, $6e, $76, $66, $66, $3c, $00
   DB $18, $18, $38, $18, $18, $18, $7e, $00
   DB $3c, $66, $06, $0c, $30, $60, $7e, $00
   DB $3c, $66, $06, $1c, $06, $66, $3c, $00
   DB $06, $0e, $1e, $66, $7f, $06, $06, $00
   DB $7e, $60, $7c, $06, $06, $66, $3c, $00
   DB $3c, $66, $60, $7c, $66, $66, $3c, $00
   DB $7e, $66, $0c, $18, $18, $18, $18, $00
   DB $3c, $66, $66, $3c, $66, $66, $3c, $00
   DB $3c, $66, $66, $3e, $06, $66, $3c, $00
   DB $00, $00, $18, $00, $00, $18, $00, $00
   DB $00, $00, $18, $00, $00, $18, $18, $30
   DB $0e, $18, $30, $60, $30, $18, $0e, $00
   DB $00, $00, $7e, $00, $7e, $00, $00, $00
   DB $70, $18, $0c, $06, $0c, $18, $70, $00
   DB $3c, $66, $06, $0c, $18, $00, $18, $00
   DB $00, $00, $00, $ff, $ff, $00, $00, $00
   DB $08, $1c, $3e, $7f, $7f, $1c, $3e, $00
   DB $18, $18, $18, $18, $18, $18, $18, $18
   DB $00, $00, $00, $ff, $ff, $00, $00, $00
   DB $00, $00, $ff, $ff, $00, $00, $00, $00
   DB $00, $ff, $ff, $00, $00, $00, $00, $00
   DB $00, $00, $00, $00, $ff, $ff, $00, $00
   DB $30, $30, $30, $30, $30, $30, $30, $30
   DB $0c, $0c, $0c, $0c, $0c, $0c, $0c, $0c
   DB $00, $00, $00, $e0, $f0, $38, $18, $18
   DB $18, $18, $1c, $0f, $07, $00, $00, $00
   DB $18, $18, $38, $f0, $e0, $00, $00, $00
   DB $c0, $c0, $c0, $c0, $c0, $c0, $ff, $ff
   DB $c0, $e0, $70, $38, $1c, $0e, $07, $03
   DB $03, $07, $0e, $1c, $38, $70, $e0, $c0
   DB $ff, $ff, $c0, $c0, $c0, $c0, $c0, $c0
   DB $ff, $ff, $03, $03, $03, $03, $03, $03
   DB $00, $3c, $7e, $7e, $7e, $7e, $3c, $00
   DB $00, $00, $00, $00, $00, $ff, $ff, $00
   DB $36, $7f, $7f, $7f, $3e, $1c, $08, $00
   DB $60, $60, $60, $60, $60, $60, $60, $60
   DB $00, $00, $00, $07, $0f, $1c, $18, $18
   DB $c3, $e7, $7e, $3c, $3c, $7e, $e7, $c3
   DB $00, $3c, $7e, $66, $66, $7e, $3c, $00
   DB $18, $18, $66, $66, $18, $18, $3c, $00
   DB $06, $06, $06, $06, $06, $06, $06, $06
   DB $08, $1c, $3e, $7f, $3e, $1c, $08, $00
   DB $18, $18, $18, $ff, $ff, $18, $18, $18
   DB $c0, $c0, $30, $30, $c0, $c0, $30, $30
   DB $18, $18, $18, $18, $18, $18, $18, $18
   DB $00, $00, $03, $3e, $76, $36, $36, $00
   DB $ff, $7f, $3f, $1f, $0f, $07, $03, $01
   DB $00, $00, $00, $00, $00, $00, $00, $00
   DB $f0, $f0, $f0, $f0, $f0, $f0, $f0, $f0
   DB $00, $00, $00, $00, $ff, $ff, $ff, $ff
   DB $ff, $00, $00, $00, $00, $00, $00, $00
   DB $00, $00, $00, $00, $00, $00, $00, $ff
   DB $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   DB $cc, $cc, $33, $33, $cc, $cc, $33, $33
   DB $03, $03, $03, $03, $03, $03, $03, $03
   DB $00, $00, $00, $00, $cc, $cc, $33, $33
   DB $ff, $fe, $fc, $f8, $f0, $e0, $c0, $80
   DB $03, $03, $03, $03, $03, $03, $03, $03
   DB $18, $18, $18, $1f, $1f, $18, $18, $18
   DB $00, $00, $00, $00, $0f, $0f, $0f, $0f
   DB $18, $18, $18, $1f, $1f, $00, $00, $00
   DB $00, $00, $00, $f8, $f8, $18, $18, $18
   DB $00, $00, $00, $00, $00, $00, $ff, $ff
   DB $00, $00, $00, $1f, $1f, $18, $18, $18
   DB $18, $18, $18, $ff, $ff, $00, $00, $00
   DB $00, $00, $00, $ff, $ff, $18, $18, $18
   DB $18, $18, $18, $f8, $f8, $18, $18, $18
   DB $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   DB $e0, $e0, $e0, $e0, $e0, $e0, $e0, $e0
   DB $07, $07, $07, $07, $07, $07, $07, $07
   DB $ff, $ff, $00, $00, $00, $00, $00, $00
   DB $ff, $ff, $ff, $00, $00, $00, $00, $00
   DB $00, $00, $00, $00, $00, $ff, $ff, $ff
   DB $03, $03, $03, $03, $03, $03, $ff, $ff
   DB $00, $00, $00, $00, $f0, $f0, $f0, $f0
   DB $0f, $0f, $0f, $0f, $00, $00, $00, $00
   DB $18, $18, $18, $f8, $f8, $00, $00, $00
   DB $f0, $f0, $f0, $f0, $00, $00, $00, $00
   DB $f0, $f0, $f0, $f0, $0f, $0f, $0f, $0f
   DB $c3, $99, $91, $91, $9f, $99, $c3, $ff
   DB $e7, $c3, $99, $81, $99, $99, $99, $ff
   DB $83, $99, $99, $83, $99, $99, $83, $ff
   DB $c3, $99, $9f, $9f, $9f, $99, $c3, $ff
   DB $87, $93, $99, $99, $99, $93, $87, $ff
   DB $81, $9f, $9f, $87, $9f, $9f, $81, $ff
   DB $81, $9f, $9f, $87, $9f, $9f, $9f, $ff
   DB $c3, $99, $9f, $91, $99, $99, $c3, $ff
   DB $99, $99, $99, $81, $99, $99, $99, $ff
   DB $c3, $e7, $e7, $e7, $e7, $e7, $c3, $ff
   DB $e1, $f3, $f3, $f3, $f3, $93, $c7, $ff
   DB $99, $93, $87, $8f, $87, $93, $99, $ff
   DB $9f, $9f, $9f, $9f, $9f, $9f, $81, $ff
   DB $9c, $88, $80, $94, $9c, $9c, $9c, $ff
   DB $99, $89, $81, $81, $91, $99, $99, $ff
   DB $c3, $99, $99, $99, $99, $99, $c3, $ff
   DB $83, $99, $99, $83, $9f, $9f, $9f, $ff
   DB $c3, $99, $99, $99, $99, $c3, $f1, $ff
   DB $83, $99, $99, $83, $87, $93, $99, $ff
   DB $c3, $99, $9f, $c3, $f9, $99, $c3, $ff
   DB $81, $e7, $e7, $e7, $e7, $e7, $e7, $ff
   DB $99, $99, $99, $99, $99, $99, $c3, $ff
   DB $99, $99, $99, $99, $99, $c3, $e7, $ff
   DB $9c, $9c, $9c, $94, $80, $88, $9c, $ff
   DB $99, $99, $c3, $e7, $c3, $99, $99, $ff
   DB $99, $99, $99, $c3, $e7, $e7, $e7, $ff
   DB $81, $f9, $f3, $e7, $cf, $9f, $81, $ff
   DB $c3, $cf, $cf, $cf, $cf, $cf, $c3, $ff
   DB $f3, $ed, $cf, $83, $cf, $9d, $03, $ff
   DB $c3, $f3, $f3, $f3, $f3, $f3, $c3, $ff
   DB $ff, $e7, $c3, $81, $e7, $e7, $e7, $e7
   DB $ff, $ef, $cf, $80, $80, $cf, $ef, $ff
   DB $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   DB $e7, $e7, $e7, $e7, $ff, $ff, $e7, $ff
   DB $99, $99, $99, $ff, $ff, $ff, $ff, $ff
   DB $99, $99, $00, $99, $00, $99, $99, $ff
   DB $e7, $c1, $9f, $c3, $f9, $83, $e7, $ff
   DB $9d, $99, $f3, $e7, $cf, $99, $b9, $ff
   DB $c3, $99, $c3, $c7, $98, $99, $c0, $ff
   DB $f9, $f3, $e7, $ff, $ff, $ff, $ff, $ff
   DB $f3, $e7, $cf, $cf, $cf, $e7, $f3, $ff
   DB $cf, $e7, $f3, $f3, $f3, $e7, $cf, $ff
   DB $ff, $99, $c3, $00, $c3, $99, $ff, $ff
   DB $ff, $e7, $e7, $81, $e7, $e7, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $e7, $e7, $cf
   DB $ff, $ff, $ff, $81, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $e7, $e7, $ff
   DB $ff, $fc, $f9, $f3, $e7, $cf, $9f, $ff
   DB $c3, $99, $91, $89, $99, $99, $c3, $ff
   DB $e7, $e7, $c7, $e7, $e7, $e7, $81, $ff
   DB $c3, $99, $f9, $f3, $cf, $9f, $81, $ff
   DB $c3, $99, $f9, $e3, $f9, $99, $c3, $ff
   DB $f9, $f1, $e1, $99, $80, $f9, $f9, $ff
   DB $81, $9f, $83, $f9, $f9, $99, $c3, $ff
   DB $c3, $99, $9f, $83, $99, $99, $c3, $ff
   DB $81, $99, $f3, $e7, $e7, $e7, $e7, $ff
   DB $c3, $99, $99, $c3, $99, $99, $c3, $ff
   DB $c3, $99, $99, $c1, $f9, $99, $c3, $ff
   DB $ff, $ff, $e7, $ff, $ff, $e7, $ff, $ff
   DB $ff, $ff, $e7, $ff, $ff, $e7, $e7, $cf
   DB $f1, $e7, $cf, $9f, $cf, $e7, $f1, $ff
   DB $ff, $ff, $81, $ff, $81, $ff, $ff, $ff
   DB $8f, $e7, $f3, $f9, $f3, $e7, $8f, $ff
   DB $c3, $99, $f9, $f3, $e7, $ff, $e7, $ff
   DB $ff, $ff, $ff, $00, $00, $ff, $ff, $ff
   DB $f7, $e3, $c1, $80, $80, $e3, $c1, $ff
   DB $e7, $e7, $e7, $e7, $e7, $e7, $e7, $e7
   DB $ff, $ff, $ff, $00, $00, $ff, $ff, $ff
   DB $ff, $ff, $00, $00, $ff, $ff, $ff, $ff
   DB $ff, $00, $00, $ff, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $00, $00, $ff, $ff
   DB $cf, $cf, $cf, $cf, $cf, $cf, $cf, $cf
   DB $f3, $f3, $f3, $f3, $f3, $f3, $f3, $f3
   DB $ff, $ff, $ff, $1f, $0f, $c7, $e7, $e7
   DB $e7, $e7, $e3, $f0, $f8, $ff, $ff, $ff
   DB $e7, $e7, $c7, $0f, $1f, $ff, $ff, $ff
   DB $3f, $3f, $3f, $3f, $3f, $3f, $00, $00
   DB $3f, $1f, $8f, $c7, $e3, $f1, $f8, $fc
   DB $fc, $f8, $f1, $e3, $c7, $8f, $1f, $3f
   DB $00, $00, $3f, $3f, $3f, $3f, $3f, $3f
   DB $00, $00, $fc, $fc, $fc, $fc, $fc, $fc
   DB $ff, $c3, $81, $81, $81, $81, $c3, $ff
   DB $ff, $ff, $ff, $ff, $ff, $00, $00, $ff
   DB $c9, $80, $80, $80, $c1, $e3, $f7, $ff
   DB $9f, $9f, $9f, $9f, $9f, $9f, $9f, $9f
   DB $ff, $ff, $ff, $f8, $f0, $e3, $e7, $e7
   DB $3c, $18, $81, $c3, $c3, $81, $18, $3c
   DB $ff, $c3, $81, $99, $99, $81, $c3, $ff
   DB $e7, $e7, $99, $99, $e7, $e7, $c3, $ff
   DB $f9, $f9, $f9, $f9, $f9, $f9, $f9, $f9
   DB $f7, $e3, $c1, $80, $c1, $e3, $f7, $ff
   DB $e7, $e7, $e7, $00, $00, $e7, $e7, $e7
   DB $3f, $3f, $cf, $cf, $3f, $3f, $cf, $cf
   DB $e7, $e7, $e7, $e7, $e7, $e7, $e7, $e7
   DB $ff, $ff, $fc, $c1, $89, $c9, $c9, $ff
   DB $00, $80, $c0, $e0, $f0, $f8, $fc, $fe
   DB $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   DB $0f, $0f, $0f, $0f, $0f, $0f, $0f, $0f
   DB $ff, $ff, $ff, $ff, $00, $00, $00, $00
   DB $00, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $ff, $ff, $00
   DB $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   DB $33, $33, $cc, $cc, $33, $33, $cc, $cc
   DB $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   DB $ff, $ff, $ff, $ff, $33, $33, $cc, $cc
   DB $00, $01, $03, $07, $0f, $1f, $3f, $7f
   DB $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   DB $e7, $e7, $e7, $e0, $e0, $e7, $e7, $e7
   DB $ff, $ff, $ff, $ff, $f0, $f0, $f0, $f0
   DB $e7, $e7, $e7, $e0, $e0, $ff, $ff, $ff
   DB $ff, $ff, $ff, $07, $07, $e7, $e7, $e7
   DB $ff, $ff, $ff, $ff, $ff, $ff, $00, $00
   DB $ff, $ff, $ff, $e0, $e0, $e7, $e7, $e7
   DB $e7, $e7, $e7, $00, $00, $ff, $ff, $ff
   DB $ff, $ff, $ff, $00, $00, $e7, $e7, $e7
   DB $e7, $e7, $e7, $07, $07, $e7, $e7, $e7
   DB $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   DB $1f, $1f, $1f, $1f, $1f, $1f, $1f, $1f
   DB $f8, $f8, $f8, $f8, $f8, $f8, $f8, $f8
   DB $00, $00, $ff, $ff, $ff, $ff, $ff, $ff
   DB $00, $00, $00, $ff, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $00, $00, $00
   DB $fc, $fc, $fc, $fc, $fc, $fc, $00, $00
   DB $ff, $ff, $ff, $ff, $0f, $0f, $0f, $0f
   DB $f0, $f0, $f0, $f0, $ff, $ff, $ff, $ff
   DB $e7, $e7, $e7, $07, $07, $ff, $ff, $ff
   DB $0f, $0f, $0f, $0f, $ff, $ff, $ff, $ff
   DB $0f, $0f, $0f, $0f, $f0, $f0, $f0, $f0
   DB $3c, $66, $6e, $6e, $60, $62, $3c, $00
   DB $00, $00, $3c, $06, $3e, $66, $3e, $00
   DB $00, $60, $60, $7c, $66, $66, $7c, $00
   DB $00, $00, $3c, $60, $60, $60, $3c, $00
   DB $00, $06, $06, $3e, $66, $66, $3e, $00
   DB $00, $00, $3c, $66, $7e, $60, $3c, $00
   DB $00, $0e, $18, $3e, $18, $18, $18, $00
   DB $00, $00, $3e, $66, $66, $3e, $06, $7c
   DB $00, $60, $60, $7c, $66, $66, $66, $00
   DB $00, $18, $00, $38, $18, $18, $3c, $00
   DB $00, $06, $00, $06, $06, $06, $06, $3c
   DB $00, $60, $60, $6c, $78, $6c, $66, $00
   DB $00, $38, $18, $18, $18, $18, $3c, $00
   DB $00, $00, $66, $7f, $7f, $6b, $63, $00
   DB $00, $00, $7c, $66, $66, $66, $66, $00
   DB $00, $00, $3c, $66, $66, $66, $3c, $00
   DB $00, $00, $7c, $66, $66, $7c, $60, $60
   DB $00, $00, $3e, $66, $66, $3e, $06, $06
   DB $00, $00, $7c, $66, $60, $60, $60, $00
   DB $00, $00, $3e, $60, $3c, $06, $7c, $00
   DB $00, $18, $7e, $18, $18, $18, $0e, $00
   DB $00, $00, $66, $66, $66, $66, $3e, $00
   DB $00, $00, $66, $66, $66, $3c, $18, $00
   DB $00, $00, $63, $6b, $7f, $3e, $36, $00
   DB $00, $00, $66, $3c, $18, $3c, $66, $00
   DB $00, $00, $66, $66, $66, $3e, $0c, $78
   DB $00, $00, $7e, $0c, $18, $30, $7e, $00
   DB $3c, $30, $30, $30, $30, $30, $3c, $00
   DB $0c, $12, $30, $7c, $30, $62, $fc, $00
   DB $3c, $0c, $0c, $0c, $0c, $0c, $3c, $00
   DB $00, $18, $3c, $7e, $18, $18, $18, $18
   DB $00, $10, $30, $7f, $7f, $30, $10, $00
   DB $00, $00, $00, $00, $00, $00, $00, $00
   DB $18, $18, $18, $18, $00, $00, $18, $00
   DB $66, $66, $66, $00, $00, $00, $00, $00
   DB $66, $66, $ff, $66, $ff, $66, $66, $00
   DB $18, $3e, $60, $3c, $06, $7c, $18, $00
   DB $62, $66, $0c, $18, $30, $66, $46, $00
   DB $3c, $66, $3c, $38, $67, $66, $3f, $00
   DB $06, $0c, $18, $00, $00, $00, $00, $00
   DB $0c, $18, $30, $30, $30, $18, $0c, $00
   DB $30, $18, $0c, $0c, $0c, $18, $30, $00
   DB $00, $66, $3c, $ff, $3c, $66, $00, $00
   DB $00, $18, $18, $7e, $18, $18, $00, $00
   DB $00, $00, $00, $00, $00, $18, $18, $30
   DB $00, $00, $00, $7e, $00, $00, $00, $00
   DB $00, $00, $00, $00, $00, $18, $18, $00
   DB $00, $03, $06, $0c, $18, $30, $60, $00
   DB $3c, $66, $6e, $76, $66, $66, $3c, $00
   DB $18, $18, $38, $18, $18, $18, $7e, $00
   DB $3c, $66, $06, $0c, $30, $60, $7e, $00
   DB $3c, $66, $06, $1c, $06, $66, $3c, $00
   DB $06, $0e, $1e, $66, $7f, $06, $06, $00
   DB $7e, $60, $7c, $06, $06, $66, $3c, $00
   DB $3c, $66, $60, $7c, $66, $66, $3c, $00
   DB $7e, $66, $0c, $18, $18, $18, $18, $00
   DB $3c, $66, $66, $3c, $66, $66, $3c, $00
   DB $3c, $66, $66, $3e, $06, $66, $3c, $00
   DB $00, $00, $18, $00, $00, $18, $00, $00
   DB $00, $00, $18, $00, $00, $18, $18, $30
   DB $0e, $18, $30, $60, $30, $18, $0e, $00
   DB $00, $00, $7e, $00, $7e, $00, $00, $00
   DB $70, $18, $0c, $06, $0c, $18, $70, $00
   DB $3c, $66, $06, $0c, $18, $00, $18, $00
   DB $00, $00, $00, $ff, $ff, $00, $00, $00
   DB $18, $3c, $66, $7e, $66, $66, $66, $00
   DB $7c, $66, $66, $7c, $66, $66, $7c, $00
   DB $3c, $66, $60, $60, $60, $66, $3c, $00
   DB $78, $6c, $66, $66, $66, $6c, $78, $00
   DB $7e, $60, $60, $78, $60, $60, $7e, $00
   DB $7e, $60, $60, $78, $60, $60, $60, $00
   DB $3c, $66, $60, $6e, $66, $66, $3c, $00
   DB $66, $66, $66, $7e, $66, $66, $66, $00
   DB $3c, $18, $18, $18, $18, $18, $3c, $00
   DB $1e, $0c, $0c, $0c, $0c, $6c, $38, $00
   DB $66, $6c, $78, $70, $78, $6c, $66, $00
   DB $60, $60, $60, $60, $60, $60, $7e, $00
   DB $63, $77, $7f, $6b, $63, $63, $63, $00
   DB $66, $76, $7e, $7e, $6e, $66, $66, $00
   DB $3c, $66, $66, $66, $66, $66, $3c, $00
   DB $7c, $66, $66, $7c, $60, $60, $60, $00
   DB $3c, $66, $66, $66, $66, $3c, $0e, $00
   DB $7c, $66, $66, $7c, $78, $6c, $66, $00
   DB $3c, $66, $60, $3c, $06, $66, $3c, $00
   DB $7e, $18, $18, $18, $18, $18, $18, $00
   DB $66, $66, $66, $66, $66, $66, $3c, $00
   DB $66, $66, $66, $66, $66, $3c, $18, $00
   DB $63, $63, $63, $6b, $7f, $77, $63, $00
   DB $66, $66, $3c, $18, $3c, $66, $66, $00
   DB $66, $66, $66, $3c, $18, $18, $18, $00
   DB $7e, $06, $0c, $18, $30, $60, $7e, $00
   DB $18, $18, $18, $ff, $ff, $18, $18, $18
   DB $c0, $c0, $30, $30, $c0, $c0, $30, $30
   DB $18, $18, $18, $18, $18, $18, $18, $18
   DB $33, $33, $cc, $cc, $33, $33, $cc, $cc
   DB $33, $99, $cc, $66, $33, $99, $cc, $66
   DB $00, $00, $00, $00, $00, $00, $00, $00
   DB $f0, $f0, $f0, $f0, $f0, $f0, $f0, $f0
   DB $00, $00, $00, $00, $ff, $ff, $ff, $ff
   DB $ff, $00, $00, $00, $00, $00, $00, $00
   DB $00, $00, $00, $00, $00, $00, $00, $ff
   DB $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   DB $cc, $cc, $33, $33, $cc, $cc, $33, $33
   DB $03, $03, $03, $03, $03, $03, $03, $03
   DB $00, $00, $00, $00, $cc, $cc, $33, $33
   DB $cc, $99, $33, $66, $cc, $99, $33, $66
   DB $03, $03, $03, $03, $03, $03, $03, $03
   DB $18, $18, $18, $1f, $1f, $18, $18, $18
   DB $00, $00, $00, $00, $0f, $0f, $0f, $0f
   DB $18, $18, $18, $1f, $1f, $00, $00, $00
   DB $00, $00, $00, $f8, $f8, $18, $18, $18
   DB $00, $00, $00, $00, $00, $00, $ff, $ff
   DB $00, $00, $00, $1f, $1f, $18, $18, $18
   DB $18, $18, $18, $ff, $ff, $00, $00, $00
   DB $00, $00, $00, $ff, $ff, $18, $18, $18
   DB $18, $18, $18, $f8, $f8, $18, $18, $18
   DB $c0, $c0, $c0, $c0, $c0, $c0, $c0, $c0
   DB $e0, $e0, $e0, $e0, $e0, $e0, $e0, $e0
   DB $07, $07, $07, $07, $07, $07, $07, $07
   DB $ff, $ff, $00, $00, $00, $00, $00, $00
   DB $ff, $ff, $ff, $00, $00, $00, $00, $00
   DB $00, $00, $00, $00, $00, $ff, $ff, $ff
   DB $01, $03, $06, $6c, $78, $70, $60, $00
   DB $00, $00, $00, $00, $f0, $f0, $f0, $f0
   DB $0f, $0f, $0f, $0f, $00, $00, $00, $00
   DB $18, $18, $18, $f8, $f8, $00, $00, $00
   DB $f0, $f0, $f0, $f0, $00, $00, $00, $00
   DB $f0, $f0, $f0, $f0, $0f, $0f, $0f, $0f
   DB $c3, $99, $91, $91, $9f, $99, $c3, $ff
   DB $ff, $ff, $c3, $f9, $c1, $99, $c1, $ff
   DB $ff, $9f, $9f, $83, $99, $99, $83, $ff
   DB $ff, $ff, $c3, $9f, $9f, $9f, $c3, $ff
   DB $ff, $f9, $f9, $c1, $99, $99, $c1, $ff
   DB $ff, $ff, $c3, $99, $81, $9f, $c3, $ff
   DB $ff, $f1, $e7, $c1, $e7, $e7, $e7, $ff
   DB $ff, $ff, $c1, $99, $99, $c1, $f9, $83
   DB $ff, $9f, $9f, $83, $99, $99, $99, $ff
   DB $ff, $e7, $ff, $c7, $e7, $e7, $c3, $ff
   DB $ff, $f9, $ff, $f9, $f9, $f9, $f9, $c3
   DB $ff, $9f, $9f, $93, $87, $93, $99, $ff
   DB $ff, $c7, $e7, $e7, $e7, $e7, $c3, $ff
   DB $ff, $ff, $99, $80, $80, $94, $9c, $ff
   DB $ff, $ff, $83, $99, $99, $99, $99, $ff
   DB $ff, $ff, $c3, $99, $99, $99, $c3, $ff
   DB $ff, $ff, $83, $99, $99, $83, $9f, $9f
   DB $ff, $ff, $c1, $99, $99, $c1, $f9, $f9
   DB $ff, $ff, $83, $99, $9f, $9f, $9f, $ff
   DB $ff, $ff, $c1, $9f, $c3, $f9, $83, $ff
   DB $ff, $e7, $81, $e7, $e7, $e7, $f1, $ff
   DB $ff, $ff, $99, $99, $99, $99, $c1, $ff
   DB $ff, $ff, $99, $99, $99, $c3, $e7, $ff
   DB $ff, $ff, $9c, $94, $80, $c1, $c9, $ff
   DB $ff, $ff, $99, $c3, $e7, $c3, $99, $ff
   DB $ff, $ff, $99, $99, $99, $c1, $f3, $87
   DB $ff, $ff, $81, $f3, $e7, $cf, $81, $ff
   DB $c3, $cf, $cf, $cf, $cf, $cf, $c3, $ff
   DB $f3, $ed, $cf, $83, $cf, $9d, $03, $ff
   DB $c3, $f3, $f3, $f3, $f3, $f3, $c3, $ff
   DB $ff, $e7, $c3, $81, $e7, $e7, $e7, $e7
   DB $ff, $ef, $cf, $80, $80, $cf, $ef, $ff
   DB $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   DB $e7, $e7, $e7, $e7, $ff, $ff, $e7, $ff
   DB $99, $99, $99, $ff, $ff, $ff, $ff, $ff
   DB $99, $99, $00, $99, $00, $99, $99, $ff
   DB $e7, $c1, $9f, $c3, $f9, $83, $e7, $ff
   DB $9d, $99, $f3, $e7, $cf, $99, $b9, $ff
   DB $c3, $99, $c3, $c7, $98, $99, $c0, $ff
   DB $f9, $f3, $e7, $ff, $ff, $ff, $ff, $ff
   DB $f3, $e7, $cf, $cf, $cf, $e7, $f3, $ff
   DB $cf, $e7, $f3, $f3, $f3, $e7, $cf, $ff
   DB $ff, $99, $c3, $00, $c3, $99, $ff, $ff
   DB $ff, $e7, $e7, $81, $e7, $e7, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $e7, $e7, $cf
   DB $ff, $ff, $ff, $81, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $e7, $e7, $ff
   DB $ff, $fc, $f9, $f3, $e7, $cf, $9f, $ff
   DB $c3, $99, $91, $89, $99, $99, $c3, $ff
   DB $e7, $e7, $c7, $e7, $e7, $e7, $81, $ff
   DB $c3, $99, $f9, $f3, $cf, $9f, $81, $ff
   DB $c3, $99, $f9, $e3, $f9, $99, $c3, $ff
   DB $f9, $f1, $e1, $99, $80, $f9, $f9, $ff
   DB $81, $9f, $83, $f9, $f9, $99, $c3, $ff
   DB $c3, $99, $9f, $83, $99, $99, $c3, $ff
   DB $81, $99, $f3, $e7, $e7, $e7, $e7, $ff
   DB $c3, $99, $99, $c3, $99, $99, $c3, $ff
   DB $c3, $99, $99, $c1, $f9, $99, $c3, $ff
   DB $ff, $ff, $e7, $ff, $ff, $e7, $ff, $ff
   DB $ff, $ff, $e7, $ff, $ff, $e7, $e7, $cf
   DB $f1, $e7, $cf, $9f, $cf, $e7, $f1, $ff
   DB $ff, $ff, $81, $ff, $81, $ff, $ff, $ff
   DB $8f, $e7, $f3, $f9, $f3, $e7, $8f, $ff
   DB $c3, $99, $f9, $f3, $e7, $ff, $e7, $ff
   DB $ff, $ff, $ff, $00, $00, $ff, $ff, $ff
   DB $e7, $c3, $99, $81, $99, $99, $99, $ff
   DB $83, $99, $99, $83, $99, $99, $83, $ff
   DB $c3, $99, $9f, $9f, $9f, $99, $c3, $ff
   DB $87, $93, $99, $99, $99, $93, $87, $ff
   DB $81, $9f, $9f, $87, $9f, $9f, $81, $ff
   DB $81, $9f, $9f, $87, $9f, $9f, $9f, $ff
   DB $c3, $99, $9f, $91, $99, $99, $c3, $ff
   DB $99, $99, $99, $81, $99, $99, $99, $ff
   DB $c3, $e7, $e7, $e7, $e7, $e7, $c3, $ff
   DB $e1, $f3, $f3, $f3, $f3, $93, $c7, $ff
   DB $99, $93, $87, $8f, $87, $93, $99, $ff
   DB $9f, $9f, $9f, $9f, $9f, $9f, $81, $ff
   DB $9c, $88, $80, $94, $9c, $9c, $9c, $ff
   DB $99, $89, $81, $81, $91, $99, $99, $ff
   DB $c3, $99, $99, $99, $99, $99, $c3, $ff
   DB $83, $99, $99, $83, $9f, $9f, $9f, $ff
   DB $c3, $99, $99, $99, $99, $c3, $f1, $ff
   DB $83, $99, $99, $83, $87, $93, $99, $ff
   DB $c3, $99, $9f, $c3, $f9, $99, $c3, $ff
   DB $81, $e7, $e7, $e7, $e7, $e7, $e7, $ff
   DB $99, $99, $99, $99, $99, $99, $c3, $ff
   DB $99, $99, $99, $99, $99, $c3, $e7, $ff
   DB $9c, $9c, $9c, $94, $80, $88, $9c, $ff
   DB $99, $99, $c3, $e7, $c3, $99, $99, $ff
   DB $99, $99, $99, $c3, $e7, $e7, $e7, $ff
   DB $81, $f9, $f3, $e7, $cf, $9f, $81, $ff
   DB $e7, $e7, $e7, $00, $00, $e7, $e7, $e7
   DB $3f, $3f, $cf, $cf, $3f, $3f, $cf, $cf
   DB $e7, $e7, $e7, $e7, $e7, $e7, $e7, $e7
   DB $cc, $cc, $33, $33, $cc, $cc, $33, $33
   DB $cc, $66, $33, $99, $cc, $66, $33, $99
   DB $ff, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   DB $0f, $0f, $0f, $0f, $0f, $0f, $0f, $0f
   DB $ff, $ff, $ff, $ff, $00, $00, $00, $00
   DB $00, $ff, $ff, $ff, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $ff, $ff, $00
   DB $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   DB $33, $33, $cc, $cc, $33, $33, $cc, $cc
   DB $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   DB $ff, $ff, $ff, $ff, $33, $33, $cc, $cc
   DB $33, $66, $cc, $99, $33, $66, $cc, $99
   DB $fc, $fc, $fc, $fc, $fc, $fc, $fc, $fc
   DB $e7, $e7, $e7, $e0, $e0, $e7, $e7, $e7
   DB $ff, $ff, $ff, $ff, $f0, $f0, $f0, $f0
   DB $e7, $e7, $e7, $e0, $e0, $ff, $ff, $ff
   DB $ff, $ff, $ff, $07, $07, $e7, $e7, $e7
   DB $ff, $ff, $ff, $ff, $ff, $ff, $00, $00
   DB $ff, $ff, $ff, $e0, $e0, $e7, $e7, $e7
   DB $e7, $e7, $e7, $00, $00, $ff, $ff, $ff
   DB $ff, $ff, $ff, $00, $00, $e7, $e7, $e7
   DB $e7, $e7, $e7, $07, $07, $e7, $e7, $e7
   DB $3f, $3f, $3f, $3f, $3f, $3f, $3f, $3f
   DB $1f, $1f, $1f, $1f, $1f, $1f, $1f, $1f
   DB $f8, $f8, $f8, $f8, $f8, $f8, $f8, $f8
   DB $00, $00, $ff, $ff, $ff, $ff, $ff, $ff
   DB $00, $00, $00, $ff, $ff, $ff, $ff, $ff
   DB $ff, $ff, $ff, $ff, $ff, $00, $00, $00
   DB $fe, $fc, $f9, $93, $87, $8f, $9f, $ff
   DB $ff, $ff, $ff, $ff, $0f, $0f, $0f, $0f
   DB $f0, $f0, $f0, $f0, $ff, $ff, $ff, $ff
   DB $e7, $e7, $e7, $07, $07, $ff, $ff, $ff
   DB $0f, $0f, $0f, $0f, $ff, $ff, $ff, $ff
   DB $0f, $0f, $0f, $0f, $f0, $f0, $f0, $f0
