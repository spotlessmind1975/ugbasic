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
;*                      CLEAR LINE ROUTINE FOR TMS9918                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINEG:

; endif

CLINEGNMI2:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

CLINEGGO:
    PUSH BC
    PUSH DE

    LD A, (CLINEX)
    LD E, A
    LD A, (CLINEY)
    LD D, A

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

    LD A, (CLINEY)
    CP 0
    JR Z, CLINEGSKIP
    LD C, A
    LD HL, (COPYOFCOLORMAPADDRESS)
CLINEGLOOP1:
    ADD HL, DE
    DEC C
    JR NZ, CLINEGLOOP1
    LD (COPYOFCOLORMAPADDRESS), HL

    LD A, (CLINEY)
    CP 0
    JR Z, CLINEGSKIP
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
CLINEGLOOP1B:
    ADD HL, DE
    DEC C
    JR NZ, CLINEGLOOP1B
    LD (COPYOFTEXTADDRESS), HL

CLINEGSKIP:
    LD A, (CLINEX)
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
    
CLINEGLOOP2:

    PUSH DE
    PUSH BC
    LD A, 1
    LD C, A
    LD A, 0
    LD DE, (COPYOFTEXTADDRESS)
    CALL VDPFILL8
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

    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, 8
    LD (COPYOFTEXTADDRESS), HL
    LD HL, (COPYOFCOLORMAPADDRESS)
    ADD HL, 8
    LD (COPYOFCOLORMAPADDRESS), HL
    INC DE
    LD A, (CLINEX)
    INC A
    LD (CLINEX), A
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR Z, CLINEGNEXT
    JR NC, CLINEGNEXT2
    JP CLINEGNEXT
CLINEGNEXT2:
    RET

CLINEGNEXT:
    DEC C
    JR Z, CLINEGEND
    JP CLINEGLOOP2
CLINEGEND:
CLINEGDONE:
    RET
    