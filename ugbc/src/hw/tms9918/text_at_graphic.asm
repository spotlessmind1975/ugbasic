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
;*                      TEXT AT GIVEN POSITION ON MSX1                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 			        NAME		COLOR		PATTERN
; VDPUPDATE0: 		$1800		            $0000 (coleco)
; VDPUPDATE1:		$1800		$0480		$0000 (coleco)
; VDPUPDATE2:		$3800		$2000
; VDPUPDATE3:		$3800		$2000		$0000

if __coleco__

TEXTATBITMAPMODE:
    CALL WAIT_VDP_HOOK
    CALL SET_VDP_HOOK_HL
    LD HL, TEXTATBITMAPMODENMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

TEXTATBITMAPMODENMI:
    CALL GET_VDP_HOOK

else

TEXTATBITMAPMODE:

endif

TEXTATBITMAPMODENMI2:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD A, C
    CP 0
    JR NZ,TEXTATBITMAPMODEGO
    JP TEXTATBITMAPMODEDONE

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
    LD HL, $0000
    LD (COPYOFTEXTADDRESS), HL

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

    ; PUSH DE
    LD E, A
    LD D, 0
    ; PUSH HL
    ; LD HL, DE
    ; ; ADD HL, HL
    ; ; ADD HL, HL
    ; ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

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

    ; PUSH DE
    LD E, A
    LD D, 0
    ; PUSH HL
    ; LD HL, DE
    ; ADD HL, HL
    ; ADD HL, HL
    ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

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
    ; PUSH HL
    ; LD HL, DE
    ; ADD HL, HL
    ; ADD HL, HL
    ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

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
    ; PUSH HL
    ; LD HL, DE
    ; ADD HL, HL
    ; ADD HL, HL
    ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

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
    ; PUSH HL
    ; LD HL, DE
    ; ADD HL, HL
    ; ADD HL, HL
    ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

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

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    if __coleco__
        CALL VSCROLLTUPNMI
    else
        CALL VSCROLLTUP
    endif
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
    JP TEXTATBITMAPMODEDONE

TEXTATBITMAPMODEDONE:
    RET
    