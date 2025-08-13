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
;*                          VERTICAL SCROLL ON CGA                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLTUP:

    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSH SI
    PUSH DI
    PUSH ES

    MOV SI, [CONSOLESA]
    MOV AL, [CURRENTTILESWIDTH]
    ADD AL, [CURRENTTILESWIDTH]
    MOV AH, 0
    MOV BL, [CONSOLEH]
    MUL BL
    ADD SI, AX

    MOV DI, SI
    SUB DI, AX
    SUB DI, AX

    MOV CL, [CONSOLEH]
    MOV CH, 0
VSCROLLTUPL1:
    PUSH CX
    MOV CL, [CONSOLEWB]
    MOV CH, 0
    PUSH DS
    MOV AX, ES
    MOV DS, AX
    CLD
    REP MOVSB
    POP DS
    POP CX
    DEC CL
    CMP CL, 0
    JZ VSCROLLTUPL2
    MOV AL, [CURRENTTILESWIDTH]
    MOV AH, 0
    MOV BL, [CURRENTTILESWIDTH]
    MOV BH, 0
    ADD SI, BX
    SUB SI, AX
    ADD DI, BX
    SUB DI, AX
    JMP VSCROLLTUPL1

VSCROLLTUPL2:
    MOV AL, [EMPTYTILE]
    MOV AH, [_PAPER]
    SAL AH, 1
    SAL AH, 1
    SAL AH, 1
    SAL AH, 1
    OR AH, [_PEN]
    MOV CL, [CONSOLEW]
    MOV SI, DI

VSCROLLTUPL3:
    MOV ES:[SI], AX
    ADD SI, 2
    DEC CL
    CMP CL, 0
    JNE VSCROLLTUPL3

    POP ES
    POP DI
    POP SI
    POP DX
    POP CX
    POP BX
    POP AX
    RET
