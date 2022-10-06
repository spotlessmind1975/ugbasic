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
;*                          VERTICAL SCROLL ON MSX1                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; if __coleco__

; VSCROLLTDOWN:
;     CALL WAIT_VDP_HOOK
;     LD HL, VSCROLLTDOWNNMI
;     CALL SET_VDP_HOOK0
;     CALL WAIT_VDP_HOOK
;     RET

; VSCROLLTDOWNNMI:

; else

VSCROLLTDOWN:

; endif

VSCROLLTDOWNNMI2:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, (CURRENTMODE)
    CP 0
    JR Z,VSCROLLTDOWN0
    CP 1
    JR Z,VSCROLLTDOWN1
    CP 2
    JR Z,VSCROLLTDOWN2
    CP 3
    JR Z,VSCROLLTDOWN3
    JP VSCROLLTDOWNDONE

VSCROLLTDOWN0:
    LD BC, 40 * 24
    LD A, 40
    LD E, A
    LD D, 0
    LD HL, (TEXTADDRESS)
    PUSH HL
    JP VSCROLLTDOWNCOMMON

VSCROLLTDOWN1:
    LD BC, 32 * 24
    LD A, 32
    LD E, A
    LD D, 0
    LD HL, (TEXTADDRESS)
    PUSH HL
    LD HL, (TEXTADDRESS)
    ADD HL, BC
    SBC HL, DE
    PUSH HL
    LD HL, (TEXTADDRESS)
    ADC HL, BC
    LD DE, HL
    POP HL
    JP VSCROLLTDOWNCOMMON

VSCROLLTDOWN2:
VSCROLLTDOWN3:
    LD BC, 32 * 24
    LD A, 32
    LD E, A
    LD D, 0
    LD HL, (TEXTADDRESS)
    PUSH HL
    LD HL, (TEXTADDRESS)
    ADD HL, BC
    SBC HL, DE
    PUSH HL
    LD HL, (TEXTADDRESS)
    ADC HL, BC
    LD DE, HL
    POP HL
    JP VSCROLLTDOWNCOMMON

VSCROLLTDOWNCOMMON:
VSCROLLTDOWNLOOP:

    PUSH DE
    PUSH BC
    LD DE, HL
    LD BC, 1
    CALL VDPINCHAR
    POP BC
    POP DE

    PUSH DE
    PUSH BC
    LD BC, 1
    CALL VDPOUTCHAR
    POP BC
    POP DE

    DEC     DE
    DEC     HL

    DEC     C
    JP      NZ, VSCROLLTDOWNLOOP
    DEC     B
    JP      NZ, VSCROLLTDOWNLOOP

    LD A, (CURRENTMODE)
    CP 0
    JR Z,VSCROLLTDOWNX0
    CP 1
    JR Z,VSCROLLTDOWNX1
    POP DE
    JP VSCROLLTDOWNDONE

VSCROLLTDOWNX0:
    LD A, (EMPTYTILE)
    LD BC, $128
    POP DE
    CALL VDPFILL
    JP VSCROLLTDOWNDONE

VSCROLLTDOWNX1:
VSCROLLTDOWNX2:
VSCROLLTDOWNX3:
    LD A, (EMPTYTILE)
    LD BC, $120
    POP DE
    ; CALL VDPFILL
    JP VSCROLLTDOWNDONE

VSCROLLTDOWNDONE:
    RET