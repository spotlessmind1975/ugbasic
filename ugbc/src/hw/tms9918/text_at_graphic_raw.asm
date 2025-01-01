; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

; if __coleco__

; TEXTATRAWBITMAPMODE:
;     CALL WAIT_VDP_HOOK
;     CALL SET_VDP_HOOK_HL
;     LD HL, TEXTATRAWBITMAPMODENMI
;     CALL SET_VDP_HOOK
;     CALL WAIT_VDP_HOOK
;     RET

; TEXTATRAWBITMAPMODENMI:
;     CALL GET_VDP_HOOK

; else

TEXTATBITMAPMODERAW:

; endif

TEXTATRAWBITMAPMODENMI2RAW:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD A, C
    CP 0
    JR NZ,TEXTATRAWBITMAPMODEGO
    JP TEXTATRAWBITMAPMODEDONE

TEXTATRAWBITMAPMODEGO:
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

    LD HL, (COLORMAPADDRESS)
    LD (COPYOFCOLORMAPADDRESS), HL
    LD HL, (PATTERNADDRESS)
    LD (COPYOFTEXTADDRESS), HL

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATRAWBMSKIP
    LD C, A
    LD HL, (COPYOFCOLORMAPADDRESS)
TEXTATRAWBMLOOP1:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATRAWBMLOOP1
    LD (COPYOFCOLORMAPADDRESS), HL

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATRAWBMSKIP
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
TEXTATRAWBMLOOP1B:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATRAWBMLOOP1B
    LD (COPYOFTEXTADDRESS), HL

TEXTATRAWBMSKIP:
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
    
TEXTATRAWBMLOOP2:

TEXTATRAWBMSP0:
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
    LD HL, UDCCHAR
    ADD HL, DE
    LD DE, (COPYOFTEXTADDRESS)
    LD BC, 8
    CALL VDPWRITE
    POP BC
    POP DE

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

TEXTATRAWBMINCX:
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, 8
    LD (COPYOFTEXTADDRESS), HL
    LD HL, (COPYOFCOLORMAPADDRESS)
    ADD HL, 8
    LD (COPYOFCOLORMAPADDRESS), HL
    INC DE
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    DEC C
    JP Z, TEXTATRAWBMEND2
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATRAWBMNEXT
    JR NC, TEXTATRAWBMNEXT2
    JP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT2:
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B

    JR Z, TEXTATRAWBMNEXT
    JR NC, TEXTATRAWBMNEXT3
    JP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT3:

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    ; if __coleco__
    ;     CALL VSCROLLTUPNMI
    ; else
        CALL VSCROLLTUP
    ; endif
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

TEXTATRAWBMNEXT:
    LD A, C
    CP 0
    JR Z, TEXTATRAWBMEND
    JP TEXTATRAWBMLOOP2
TEXTATRAWBMEND2:
TEXTATRAWBMEND:
    JP TEXTATRAWBITMAPMODEDONE

TEXTATRAWBITMAPMODEDONE:
    RET
    