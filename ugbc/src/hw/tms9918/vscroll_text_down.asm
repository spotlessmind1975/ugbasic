; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

VSCROLLTDOWN:
    LD A, (CURRENTMODE)
    CP 0
    JR Z,VSCROLLTDOWN0
    CP 1
    JR Z,VSCROLLTDOWN1
    RET

VSCROLLTDOWN0:
    LD BC, 40 * 23
    LD A, 40
    LD E, A
    LD D, 0
    LD HL, $0000
    PUSH HL
    JP VSCROLLTDOWNCOMMON

VSCROLLTDOWN1:
    LD BC, 32 * 23
    LD A, 32
    LD E, A
    LD D, 0
    LD HL, $0000
    PUSH HL
    JP VSCROLLTDOWNCOMMON

VSCROLLTDOWNCOMMON:
    LD HL, $0000
    ADD HL, DE
    PUSH HL
    LD HL, $0000
    ADD HL, BC
    INC B
    
VSCROLLTDOWNLOOP:

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

    DEC     DE
    DEC     HL

    DEC     C
    JP      NZ, VSCROLLTDOWNLOOP
    DJNZ    VSCROLLTDOWNLOOP

    LD A, (CURRENTMODE)
    CP 0
    JR Z,VSCROLLTDOWNX0
    CP 1
    JR Z,VSCROLLTDOWNX1
    RET

VSCROLLTDOWNX0:
    LD A, (EMPTYTILE)
    LD BC, 40
    POP DE
    CALL VDPFILL
    RET

VSCROLLTDOWNX1:
    LD A, (EMPTYTILE)
    LD BC, 32
    POP DE
    CALL VDPFILL
    RET
