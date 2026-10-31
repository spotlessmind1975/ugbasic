; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                      DEFDGR FOR TMS9918                                     *
;*                                                                             *
;*                      by Marco Spedaletti                                    *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DEFDGR:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, (CURRENTMODE)
    CP 0
    JR Z, DEFDGR0
    CP 1
    JR Z, DEFDGR1
    CP 2
    JR Z, DEFDGR2
    CP 3
    JR Z, DEFDGR3
    RET

DEFDGR2:
DEFDGR3:

    PUSH HL
    LD BC, 8
@IF COLECO
    CALL VDPWRITE
@ELSE
    CALL CBIOS_VDPWRITE
@ENDIF
    LD HL, DE
    ADD HL, $800
    LD DE, HL
    POP HL


    PUSH HL
    LD BC, 8
@IF COLECO
    CALL VDPWRITE
@ELSE
    CALL CBIOS_VDPWRITE
@ENDIF
    LD HL, DE
    ADD HL, $800
    LD DE, HL
    POP HL

DEFDGR0:
DEFDGR1:
    LD BC, 8
@IF COLECO
    CALL VDPWRITE
@ELSE
    CALL CBIOS_VDPWRITE
@ENDIF
    RET


