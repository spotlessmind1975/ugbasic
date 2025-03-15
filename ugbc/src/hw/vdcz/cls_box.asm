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
;*                          CLS BOXED ROUTINE FOR VDCZ                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLSBOX:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD C, (HL)
    INC HL
    LD A, (HL)
    LD IXH, A
    INC HL
    LD B, (HL)
    INC HL

    DEC IY
    PUSH IY
    PUSH DE

    LD A, (CURRENTMODE)
    CP 1
    JP Z, CLSBOX1
    RET

CLSBOX1:

    PUSH BC
    LD A, IXH
    LD B, A
    SRL B
    RR C
    SRL B
    RR C
    SRL B
    RR C
    LD A, C
    POP BC
    LD C, A
    
CLSBOX1L2:

    POP DE
    POP IY

    INC IY

    PUSH IY
    PUSH DE

    PUSH HL
    PUSH BC
    CALL VCDZPOS
    LD DE, HL
    POP BC
    POP HL

    PUSH BC
CLSBOX1L1:
    ; Calculate new pixels
    LD A, 0
    ; Draw them
    CALL VDCZPUTCHAR

    INC DE
    INC HL

    DEC C
    JP NZ, CLSBOX1L1

CLSBOX1DONEROW:
    POP BC

    DEC B
    JP NZ, CLSBOX1L2

    POP DE
    POP IY

    JP CLSBOXDONE

CLSBOXDONE:
    RET