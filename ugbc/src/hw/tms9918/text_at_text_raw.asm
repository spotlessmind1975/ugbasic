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

; TEXTATRAWTILEMODE:
;     CALL WAIT_VDP_HOOK
;     CALL SET_VDP_HOOK_HL
;     LD HL, TEXTATRAWTILEMODENMI
;     CALL SET_VDP_HOOK
;     CALL WAIT_VDP_HOOK
;     RET

; TEXTATRAWTILEMODENMI:
;     CALL GET_VDP_HOOK

; else

TEXTATTILEMODERAW:

; endif

TEXTATTILEMODENMI2RAW:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, C
    CP 0
    JR NZ,TEXTATRAWTILEMODEGO
    JP TEXTATRAWTILEMODEDONE

TEXTATRAWTILEMODEGO:
    PUSH BC
    PUSH DE

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

    LD A, (CURRENTMODE)
    CP 0
    JR Z,TEXTATRAWTILEMODEGO0
    CP 1
    JR Z,TEXTATRAWTILEMODEGO1
    CP 2
    JR Z,TEXTATRAWTILEMODEGO2
    CP 3
    JR Z,TEXTATRAWTILEMODEGO3
    RET

TEXTATRAWTILEMODEGO0:
TEXTATRAWTILEMODEGO1:
    LD HL, (TEXTADDRESS)
    LD (COPYOFTEXTADDRESS), HL
    JMP TEXTATRAWTILEMODEGOX

TEXTATRAWTILEMODEGO2:
TEXTATRAWTILEMODEGO3:
    LD HL, (TEXTADDRESS)
    LD (COPYOFTEXTADDRESS), HL
    JMP TEXTATRAWTILEMODEGOX

TEXTATRAWTILEMODEGOX:

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATRAWSKIP
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
TEXTATRAWLOOP1:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATRAWLOOP1
    LD (COPYOFTEXTADDRESS), HL

TEXTATRAWSKIP:
    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE
    POP BC
    
TEXTATRAWLOOP2:

    LD A, (DE)

    CALL TEXTATDECODE

TEXTATRAWSP0:
    LD HL, (COPYOFTEXTADDRESS)

    PUSH AF
    PUSH DE
    PUSH BC
    LD DE, HL
    LD BC, 1
    CALL VDPOUTCHAR
    POP BC
    POP DE
    POP AF

    PUSH AF
    LD A, (CURRENTMODE)
    CP 0
    JR Z,TEXTATRAW20
    CP 1
    JR Z,TEXTATRAW21
    CP 2
    JR Z,TEXTATRAW22
    CP 3
    JR Z,TEXTATRAW23
    POP AF
    RET

TEXTATRAW20:
TEXTATRAW21:
    POP AF
    PUSH HL
    PUSH AF
    PUSH DE
    PUSH BC

    SRL A
    SRL A
    SRL A
    LD E, A
    LD A, 0
    LD D, A

    LD HL, $480
    ADD HL, DE
    LD DE, HL
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD BC, 1
    CALL VDPOUTCHAR
    POP BC
    POP DE
    POP AF
    POP HL

    JMP TEXTATINCX

TEXTATRAW22:
TEXTATRAW23:
    POP AF
    PUSH HL
    PUSH AF
    PUSH DE
    PUSH BC

    LD L, A
    LD A, 0
    LD H, A
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL

    PUSH DE
    LD HL, (COLORMAPADDRESS)
    ADD HL, DE
    LD DE, HL
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD BC, 1
    CALL VDPFILL8
    POP DE

    PUSH DE
    LD HL, (COLORMAPADDRESS)
    LD DE, $800
    ADD HL, DE
    POP DE
    PUSH DE
    ADD HL, DE
    LD DE, HL
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD BC, 1
    CALL VDPFILL8
    POP DE

    PUSH DE
    LD HL, (COLORMAPADDRESS)
    LD DE, $1000
    ADD HL, DE
    POP DE
    PUSH DE
    ADD HL, DE
    LD DE, HL
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD BC, 1
    CALL VDPFILL8
    POP DE

    POP BC
    POP DE
    POP AF
    POP HL

TEXTATRAWINCX:
    LD HL, (COPYOFTEXTADDRESS)
    INC HL
    LD (COPYOFTEXTADDRESS), HL
    INC DE
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    DEC C
    JP Z, TEXTATRAWEND2
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATRAWNEXT
    JR NC, TEXTATRAWNEXT2
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT2:
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

    JR Z, TEXTATRAWNEXT
    JR NC, TEXTATRAWNEXT3
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT3:

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
    LD HL, (COPYOFTEXTADDRESS)
    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    SBC HL, DE
    POP DE
    LD (COPYOFTEXTADDRESS), HL

TEXTATRAWNEXT:
    LD A, C
    CP 0
    JR Z, TEXTATRAWTILEMODEDONE
    JMP TEXTATRAWLOOP2
TEXTATRAWEND:
TEXTATRAWEND2:
    JP TEXTATRAWTILEMODEDONE

TEXTATRAWTILEMODEDONE:
    RET