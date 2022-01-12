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
    LD B, 8
SPRITEDATAL1:
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    DJNZ SPRITEDATAL1
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

SPRITEDISABLEFROM:

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
    INC HL
    LD A, H
    CALL VDPOUTCHAR
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

