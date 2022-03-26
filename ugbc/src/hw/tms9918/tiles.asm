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
;*                          TILES ROUTINE FOR TMS9918                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; TILEA = A
; TILEX = ..
; TILEY = ..
; TILET = B
; TILEW = D
; TILEH = E
; >> TILEX2

; ----------------------------------------------------------------------------
; - Put tile on tilemap
; ----------------------------------------------------------------------------

; if __coleco__

; PUTTILE:
;     CALL WAIT_VDP_HOOK
;     LD HL, PUTTILENMI
;     CALL SET_VDP_HOOK0
;     CALL WAIT_VDP_HOOK
;     RET

; PUTTILENMI:

; else

PUTTILE:

; endif

PUTTILENMI2:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, (TILEH2)
    CP 0
    RET Z
    LD A, (TILEW2)
    CP 0
    RET Z

    LD A, (CURRENTMODE)
    CP 0
    JR Z,PUTTILENMI20
    CP 1
    JR Z,PUTTILENMI21
    CP 2
    JR Z,PUTTILENMI22
    CP 3
    JR Z,PUTTILENMI23
    RET

PUTTILENMI20:
PUTTILENMI21:
    LD HL, $1800
    JMP PUTTILENMI2X

PUTTILENMI22:
PUTTILENMI23:
    LD HL, $3800
    JMP PUTTILENMI2X

PUTTILENMI2X:
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    LD A, (TILEX)
    CP B
    JR Z, PUTTILEEX
    JR NC, PUTTILEEX

    LD A, (CURRENTTILESHEIGHT)
    LD B, A
    LD A, (TILEY)
    CP 0
    JR Z, PUTTILEL1
    CP B
    JR Z, PUTTILEEX
    JR NC, PUTTILEEX

    JMP PUTTILEL0

PUTTILEEX:
    JMP PUTTILEE

PUTTILEL0:
    LD A, (TILEY)
    LD B, A

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

PUTTILEL0B:
    ADD HL, DE
    DEC B
    JR NZ, PUTTILEL0B

PUTTILEL1:
    LD A, (TILEX)
    LD E, A
    LD D, 0
    ADD HL, DE

PUTTILEL2A:
    LD A, (TILEX)
    LD (TILEX2), A
    LD A, (TILEW2)
    LD B, A
PUTTILEL2:
    PUSH BC
    LD A, (TILET)
    LD DE, HL
    LD BC, 1
    CALL VDPOUTCHAR
    POP BC

    PUSH HL
    PUSH AF
    PUSH DE
    PUSH BC

    LD A, (CURRENTMODE)
    CP 0
    JR Z,PUTTILECOL20
    CP 1
    JR Z,PUTTILECOL21
    CP 2
    JR Z,PUTTILECOL22
    CP 3
    JR Z,PUTTILECOL23
    RET

PUTTILECOL20:
PUTTILECOL21:
    LD A, (TILET)
    SRL A
    SRL A
    SRL A
    LD E, A
    LD A, 0
    LD D, A
    LD HL, $480
    ADD HL, DE
    LD DE, HL
    LD BC, 1
    CALL VDPINCHAR
    AND $F0
    CP 0
    JR NZ, TILENOCOLOR
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD BC, 1
    CALL VDPOUTCHAR
    JMP PUTTILECOL2X

PUTTILECOL22:
PUTTILECOL23:

    LD A, (TILEX2)
    LD E, A
    LD D, 0
    LD HL, PLOT8
    ADD HL, DE
    ADD HL, DE
    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A

    LD HL, PLOTCVBASE
    LD A, (TILEY)
    LD E, A
    LD D, 0
    ADD HL, DE
    ADD HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    LD HL, DE
    ADD HL, BC
    LD DE, HL
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD BC, 1
    CALL VDPFILL8
    JMP PUTTILECOL2X

PUTTILECOL2X:
TILENOCOLOR:    
    POP BC
    POP DE
    POP AF
    POP HL

    LD A, (TILET)
    INC A
    LD (TILET), A

    PUSH BC
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    LD A, (TILEX2)
    INC A
    LD (TILEX2), A

    CP B
    POP BC
    JR Z, PUTTILERE
    JR NC, PUTTILERE

    INC HL
    DEC B
    JP NZ, PUTTILEL2
    JMP PUTTILENL

PUTTILERE:
    LD A, (TILET)
PUTTILEREL:
    INC A
    DEC B
    JR NZ, PUTTILEREL
    DEC A
    LD (TILET), A

PUTTILENL:

    PUSH BC
    LD A, (TILEW2)
    LD B, A
    LD A, (TILEW)
    SUB A, B
    LD B, A
    LD A, (TILET)
    ADD A, B
    LD (TILET), A
    POP BC

    LD A, (TILEH2)
    CP 0
    JR Z, PUTTILEE

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD A, (TILEW)
    LD E, A
    LD D, 0
    SBC HL, DE

    LD A, (TILEH2)
    DEC A
    LD (TILEH2), A

    LD A, (CURRENTTILESHEIGHT)
    LD B, A
    LD A, (TILEY)
    INC A
    LD (TILEY), A
    CP B
    JR Z, PUTTILEE
    JR NC, PUTTILEE

    JMP PUTTILEL2A

PUTTILEE:
    RET

;;;;;;;;;;;;;;;

; if __coleco__

; USETILESET:
;     CALL WAIT_VDP_HOOK
;     LD HL, USETILESETNMI
;     CALL SET_VDP_HOOK0
;     CALL WAIT_VDP_HOOK
;     RET

; USETILESETNMI:

; else

USETILESET:

; endif

USETILESETNMI2:
    RET

;;;;;;;;;;;;;;;

; if __coleco__

; MOVETILE:
;     CALL WAIT_VDP_HOOK
;     LD HL, MOVETILENMI
;     CALL SET_VDP_HOOK0
;     CALL WAIT_VDP_HOOK
;     RET

; MOVETILENMI:

; else

MOVETILE:

; endif

MOVETILENMI2:

    LD A, (TILEA)
    AND $80
    CP $80
    JR NZ, MOVETILEX

MOVETILEY:
    LD A, (TILEY)
    AND $07
    SLA A
    JMP MOVETILEZ

MOVETILEX:
    LD A, (TILEX)
    AND $07
    SLA A

MOVETILEZ:
    LD E, A
    LD D, 0
    LD HL, (TILEO)
    ADD HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    LD HL, DE
    LD A, (TILET)
    LD E, A
    LD D, 0
    ADD HL, DE   
    LD A, L 
    LD (TILET), A

    LD A, (TILEX)
    SRA A
    SRA A
    SRA A
    LD (TILEX), A

    LD A, (TILEY)
    SRA A
    SRA A
    SRA A
    LD (TILEY), A

    CALL PUTTILENMI2

    RET

; if __coleco__

; TILEAT:
;     CALL WAIT_VDP_HOOK
;     LD HL, PUTTILENMI
;     CALL SET_VDP_HOOK0
;     CALL WAIT_VDP_HOOK
;     RET

; TILEATNMI:

; else

TILEAT:

; endif

TILEATNMI2:

    LD HL, $1800

    LD A, (CURRENTTILESHEIGHT)
    LD B, A
    LD A, (TILEY)
    CP 0
    JR Z, TILEATL1
    CP B
    JR Z, TILEATEX
    JR NC, TILEATEX

    JMP TILEATL0

TILEATEX:
    JMP TILEATEE

TILEATL0:
    LD A, (TILEY)
    LD B, A

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

TILEATL0B:
    ADD HL, DE
    DEC B
    JR NZ, TILEATL0B

TILEATL1:
    LD A, (TILEX)
    LD E, A
    LD D, 0
    ADD HL, DE

    CALL VDPINCHAR

    LD (TILET), A
TILEATEE:
    RET
    