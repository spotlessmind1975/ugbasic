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
;*                              SPRITES FOR MSX1                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SET SPRITE DATA(B,HL)
if __coleco__

SPRITEDATAFROM:
    CALL WAIT_VDP_HOOK
    CALL SET_VDP_HOOK_HL
    LD HL, SPRITEDATAFROMNMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

SPRITEDATAFROMNMI:
    CALL GET_VDP_HOOK

else

SPRITEDATAFROM:

endif

SPRITEDATAFROMNMI2:

    PUSH HL
    LD HL, $1000
    LD D, 0
    LD E, B
    SLA E
    SLA E
    ADD HL, DE
    INC HL
    INC HL
    LD DE, HL
    POP HL
    LD A, B
    CALL VDPOUTCHAR

    PUSH HL
    LD HL, $0000
    LD D, 0
    LD E, B
    SLA E
    SLA E
    SLA E
    ADD HL, DE
    LD DE, HL
    POP HL
    INC HL
    INC HL
    PUSH B
    LD B, 8
SPRITEDATAL1:
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    DJNZ SPRITEDATAL1
    POP B

    PUSH HL
    LD HL, $1000
    LD D, 0
    LD E, B
    SLA E
    SLA E
    ADD HL, DE
    INC HL
    INC HL
    INC HL
    LD DE, HL
    POP HL

    PUSH B
    LD B, 8
SPRITEDATAL1C:
    LD A, (HL)
    AND $F0
    CP 0
    JR Z, SPRITEDATAL1C2
    SRA A
    SRA A
    SRA A
    SRA A
    AND $0F
    CALL VDPOUTCHAR
    JP SPRITEDATAL1C3
SPRITEDATAL1C2:
    INC HL
    DJNZ SPRITEDATAL1C
SPRITEDATAL1C3:
    POP B

    JP SPRITEDATADONE

SPRITEDATADONE:
    RET

; SET SPRITE DISABLE(B)
if __coleco__

SPRITEDISABLE:
    CALL WAIT_VDP_HOOK
    LD HL, SPRITEDISABLENMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

SPRITEDISABLENMI:
    CALL GET_VDP_HOOK

else

SPRITEDISABLE:

endif

SPRITEDISABLENMI2:
SPRITEDISABLEDONE:
    RET

; SET SPRITE ENABLE(B)
if __coleco__

SPRITEENABLE:
    CALL WAIT_VDP_HOOK
    LD HL, SPRITEENABLENMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

SPRITEENABLENMI:
    CALL GET_VDP_HOOK

else

SPRITEENABLE:

endif

SPRITEENABLENMI2:

    RET

; SPRITE AT(B,D,E)
if __coleco__

SPRITEAT:
    CALL WAIT_VDP_HOOK
    CALL SET_VDP_HOOK_HL
    LD HL, SPRITEATNMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

SPRITEATNMI:
    CALL GET_VDP_HOOK

else

SPRITEAT:

endif

SPRITEATNMI2:
    CALL SPRITEDECODEB
    LD A, C
    CP 0
    JR Z, SPRITEATNMI2SINGLE
SPRITEATNMI2L1:
    CALL SPRITEATNMI2SINGLE
    INC B
    DEC C
    JR NZ, SPRITEATNMI2L1
    RET
SPRITEATNMI2SINGLE:
    PUSH HL
    LD HL, $1000
    LD D, 0
    LD E, B
    SLA E
    SLA E
    ADD HL, DE
    LD DE, HL
    POP HL
    LD A, L
    CALL VDPOUTCHAR
    INC DE
    LD A, H
    CALL VDPOUTCHAR
    ; LD DE, HL
    ; LD HL, SPRITEXY
    ; LD D, 0
    ; LD E, B
    ; SLA E
    ; ADD HL, DE
    ; LD (HL), D
    ; INC HL
    ; LD (HL), E
    JP SPRITEATADONE

SPRITEATADONE:
    RET

; SPRITE EXPAND()
if __coleco__

SPRITEEXPAND:
    CALL WAIT_VDP_HOOK
    LD HL, SPRITEEXPANDNMI
    CALL SET_VDP_HOOK0
    CALL WAIT_VDP_HOOK
    RET

SPRITEEXPANDNMI:

else

SPRITEEXPAND:

endif

SPRITEEXPANDNMI2:

    RET

; SPRITE COMPRESS()
if __coleco__

SPRITECOMPRESS:
    CALL WAIT_VDP_HOOK
    LD HL, SPRITECOMPRESSNMI
    CALL SET_VDP_HOOK0
    CALL WAIT_VDP_HOOK
    RET

SPRITECOMPRESSNMI:

else

SPRITECOMPRESS:

endif

SPRITECOMPRESSNMI2:

    RET

; SPRITE COLOR(B,C)
if __coleco__

SPRITECOLOR:
    CALL WAIT_VDP_HOOK
    LD HL, SPRITECOLORNMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

SPRITECOLORNMI:
    CALL GET_VDP_HOOK

else

SPRITECOLOR:

endif

SPRITECOLORNMI2:
    LD A, C
    LD E, A
    CALL SPRITEDECODEB
    LD A, C
    CP 0
    JR Z, SPRITECOLORNMI2SINGLE
SPRITECOLORNMI2L1:
    PUSH DE
    CALL SPRITECOLORNMI2SINGLE
    POP DE
    INC B
    DEC C
    JR NZ, SPRITECOLORNMI2L1
    RET
SPRITECOLORNMI2SINGLE:
    LD A, E
    LD C, A
    LD HL, $1000
    LD D, 0
    LD E, B
    SLA E
    SLA E
    ADD HL, DE
    INC HL
    INC HL
    INC HL
    LD DE, HL
    LD A, C
    AND $0F
    CALL VDPOUTCHAR
    JP SPRITECOLORDONE

SPRITECOLORDONE:
    RET


; SPRITE COLOR(B,C)
if __coleco__

SPRITECOL:
    CALL WAIT_VDP_HOOK
    LD HL, SPRITECOLNMI
    CALL SET_VDP_HOOK
    CALL WAIT_VDP_HOOK
    RET

SPRITECOLNMI:
    CALL GET_VDP_HOOK

else

SPRITECOL:

endif

SPRITECOLNMI2:
    CALL VDPREGIN
    AND $20
    CP 0
    JR NZ, SPRITECOLNMI2YES
    RET

SPRITECOLNMI2YES:
    LD A, $FF
    RET

SPRITEDECODEB:
    LD A, 0
    LD C, A
    LD A, B
    CP $20
    JR C, SPRITEDECODEB0
    LD A, B
    AND $E0
    SRL A
    SRL A
    SRL A
    SRL A
    SRL A
    LD C, A
    LD A, B
    AND $1F
    LD B, A
SPRITEDECODEB0:
    RET

