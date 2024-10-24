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
;*                          VERTICAL SCROLL ON MSX1                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 			        NAME		COLOR		PATTERN
; VDPUPDATE0: 		$1800		            $0000 (coleco)
; VDPUPDATE1:		$0000		$0480		$0800
; VDPUPDATE2:		$3800		$2000
; VDPUPDATE3:		$3800		$2000		$0000

; if __coleco__

; VSCROLLTUP:
;     CALL WAIT_VDP_HOOK
;     LD HL, VSCROLLTUPNMI
;     CALL SET_VDP_HOOK0
;     CALL WAIT_VDP_HOOK
;     RET

; VSCROLLTUPNMI:

; else

VSCROLLTUP:

; endif

VSCROLLTUPNMI2:

    LD A, (CONSOLEH)
    CP 1
    JP Z, VSCROLLTUPXX

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, (CURRENTMODE)
    CP 0
    JR Z,VSCROLLTUP0
    CP 1
    JR Z,VSCROLLTUP1
    CP 2
    JR Z,VSCROLLTUP2
    CP 3
    JR Z,VSCROLLTUP3
    JP VSCROLLTUPDONE

VSCROLLTUP0:
    LD A, (CONSOLEH)
    LD B, A
    DEC B
    LD A, (CONSOLEW)
    LD C, A
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    LD HL, (CONSOLESA)
    PUSH HL
    JP VSCROLLTUPCOMMON

VSCROLLTUP1:
VSCROLLTUP2:
VSCROLLTUP3:
    LD A, (CONSOLEH)
    LD B, A
    DEC B
    DEC B
    LD A, (CONSOLEW)
    LD C, A
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    LD HL, (CONSOLESA)
    PUSH HL
    JP VSCROLLTUPCOMMON

VSCROLLTUPCOMMON:
    LD HL, (CONSOLESA)
    PUSH HL
    ADD HL, DE
    POP DE
    INC B

VSCROLLTUPPREP:
    PUSH HL
    PUSH DE
VSCROLLTUPLOOP:

    PUSH DE
    PUSH BC
    LD DE, HL
    LD BC, 1
    CALL VDPINCHAR
    POP BC
    POP DE

    PUSH BC
    LD BC, 1
    CALL VDPOUTCHAR
    POP BC

    INC     DE
    INC     HL

    DEC     C
    JP      NZ, VSCROLLTUPLOOP

    POP DE
    POP HL

    PUSH DE
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE

    PUSH HL
    LD HL, DE
    PUSH DE
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE
    LD DE, HL
    POP HL
    
    LD A, (CONSOLEW)
    LD C, A
    DEC B
    JR NZ, VSCROLLTUPPREP

    JMP VSCROLLTUPXX2

VSCROLLTUPXX:
    LD HL, (CONSOLESA)
    PUSH HL
    LD DE, HL
VSCROLLTUPXX2:
    LD A, (CURRENTMODE)
    CP 0
    JR Z,VSCROLLTUPX0
    CP 1
    JR Z,VSCROLLTUPX1
    CP 2
    JR Z,VSCROLLTUPX2
    POP DE
    JP VSCROLLTUPDONE

VSCROLLTUPX0:
    LD A, (CONSOLEW)
    LD C, A
    LD B, $1
    LD A, (EMPTYTILE)
    CALL VDPFILL
    POP DE
    JP VSCROLLTUPDONE

VSCROLLTUPX1:
VSCROLLTUPX2:
    LD A, (CONSOLEW)
    LD C, A
    LD B, $1
    LD A, (EMPTYTILE)
    CALL VDPFILL
    POP DE
    JP VSCROLLTUPDONE

VSCROLLTUPDONE:
    RET