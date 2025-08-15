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
;*                           PLOT ROUTINE FOR TMS9918                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; PLOTX    = $F7 ; $F8  -> E
; PLOTY    = $F9        -> D
; PLOTM    = $FB        -> B
; PLOTOMA  = $FD
; PLOTAMA  = $FC

;--------------

; if __coleco__

; PLOT:
;     LD H, A
;     CALL WAIT_VDP_HOOK
;     CALL SET_VDP_HOOK_HL
;     LD HL, PLOTNMI
;     CALL SET_VDP_HOOK
;     CALL WAIT_VDP_HOOK
;     RET

; PLOTNMI:
;     CALL GET_VDP_HOOK
;     LD A, H

; else

PLOT:

; endif

PLOTNMI2:

    PUSH AF

    LD A, (CURRENTTILEMODE)
    CP 1
    JP Z, PLOTP

@IF scaleX > 0
    PUSH AF
    LD A, E
    SLA A
    LD E, A
    POP AF
@ENDIF

@IF scaleX > 1
    PUSH AF
    LD A, E
    SLA A
    LD E, A
    POP AF
@ENDIF

@IF offsetX > 0
@EMIT offsetX AS offsetX
    PUSH AF
    LD A, E
    ADD offsetX
    LD E, A
    POP AF
@ENDIF

@IF scaleY > 0
    PUSH AF
    LD A, D
    SLA A
    LD D, A
    POP AF
@ENDIF

@IF scaleY > 1
    PUSH AF
    LD A, D
    SLA A
    LD D, A
    POP AF
@ENDIF

@IF offsetY > 0
@EMIT offsetY AS offsetY
    PUSH AF
    LD A, D
    ADD offsetY
    LD D, A
    POP AF
@ENDIF

@IF optionClip

    LD A, (CLIPY2)
    LD B, A
    LD A, D
    CP B
    JR C, PLOTCLIP2
    JR Z, PLOTCLIP2
    JP PLOTP
PLOTCLIP2:
    LD A, (CLIPY1)
    LD B, A
    LD A, D
    CP B
    JR Z, PLOTCLIP3
    JR NC, PLOTCLIP3
    JP PLOTP
PLOTCLIP3:
PLOTCLIP3B:
    LD A, (CLIPX2+1)
    LD B, A
    LD A, IXH
    CP B
    JR C, PLOTCLIP4X
    JR Z, PLOTCLIP4X
    JP PLOTP
PLOTCLIP4X:
    LD A, (CLIPX2)
    LD B, A
    LD A, E
    CP B
    JR C, PLOTCLIP4
    JR Z, PLOTCLIP4
    JP PLOTP
PLOTCLIP4:
PLOTCLIP4B:
    LD A, (CLIPX1)
    LD B, A
    LD A, E
    CP B
    JR NC, PLOTCLIP5
    JR Z, PLOTCLIP5
    JP PLOTP
PLOTCLIP5:

@ENDIF

PLOTMODE:
    LD A, (CURRENTMODE)
    ; TILEMAP_MODE_STANDARD
    CP 0
    JR NZ, PLOT0X
    JP PLOT0
PLOT0X:
    ; TILEMAP_MODE_GRAPHIC1
    CP 1
    JR NZ,PLOT1X
    JP PLOT1
PLOT1X:
    ; BITMAP_MODE_GRAPHIC2
    CP 2
    JR NZ,PLOT2X
    JP PLOT2
PLOT2X:
    ; BITMAP_MODE_MULTICOLOR
    CP 3
    JR NZ,PLOT3X
    JP PLOT3
PLOT3X:
    POP AF
    JP PLOTDONE

PLOT0:
PLOT1:
    POP AF
    JP PLOTDONE

PLOT2:
PLOT3:

    CALL VDPPOS

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    POP AF
    CP 0
    JR Z, PLOTE                  ;if = 0 then branch to clear the point
    CP 1
    JR Z, PLOTD                  ;if = 1 then branch to draw the point
    CP 2
    JR Z, PLOTG                  ;if = 2 then branch to get the point (0/1)
    CP 3
    JP Z, PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JP PLOTP2

PLOTD:

    PUSH BC
    LD A, (PLOTCPE)
    LD B, A
    LD A, (_PAPER)
    CP B
    POP BC
    JR Z, PLOTDN0

PLOTDN1:
    ;---------
    ;set point
    ;---------
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    OR B
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE

    JR PLOTDC

PLOTDN0:
    ;---------
    ;set point
    ;---------
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE

PLOTDC:

    DI

    EXX

    PUSH BC
    LD A, (PLOTCPE)
    LD B, A
    LD A, (_PAPER)
    CP B
    POP BC
    JR Z, PLOTDNC

    LD A, (PLOTCPE)
    SLA A
    SLA A
    SLA A
    SLA A
    LD B, A
    LD A, (_PAPER)
    OR B
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE

PLOTDNC:

    EXX

    EI

    JMP PLOTP2

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE
    JMP PLOTP2

PLOTG:    
    LD A, C
    XOR $FF
    LD C, A
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    CP $0
    JR Z, PLOTG0
PLOTG1:
    LD A, $ff
    JP PLOTP2
PLOTG0:
    LD A, $0
    JP PLOTP2

PLOTC:
    CALL PLOTG
    CP $0
    JR Z, PLOTC0

PLOTC1:

    DI

    EXX

    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE

    AND $F0
    SRL A
    SRL A
    SRL A
    SRL A

    EXX

    EI

    JMP PLOTP2

PLOTC0:

    DI

    EXX

    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE

    AND $0F

    EXX

    EI

    JMP PLOTP2

PLOTP:
    POP AF
PLOTP2:
    JP PLOTDONE

PLOTDONE:
    PUSH AF
    CALL VDPREGIN
    POP AF
    RET