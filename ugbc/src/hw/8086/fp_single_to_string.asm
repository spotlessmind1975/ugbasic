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

FPSTRINGBUF: times 16 db 0
FPFLOAT: dd 0
FPINTEGERPART:  dw 0
FPDECIMALPART:  dw 0
FP1000: dw 1000

FPSINGLETOA:
    FST DWORD [FPFLOAT]
    FISTP WORD [FPINTEGERPART]
    FLD DWORD [FPFLOAT]
    FILD WORD [FPINTEGERPART]
    FSUB
    FILD WORD [FP1000]
    FMUL
    FISTP WORD [FPDECIMALPART]

    MOV AX, [FPDECIMALPART]
    CMP AX, 0
    JE FPSINGLETOANODECIMAL

    PUSH DI

    MOV AX, [FPINTEGERPART]
    CWD
    MOV DI, FPSTRINGBUF
    CALL NUMBERTOSTRINGSIGNED

    MOV SI, FPSTRINGBUF    
    POP DI    
    PUSH CX

    PUSH DI
    CALL DUFFDEVICE
    POP DI

    POP CX
    PUSH CX

    ADD DI, CX
    MOV AL, '.'
    MOV [DI], AL
    INC DI

    PUSH DI

    MOV AX, [FPDECIMALPART]
    CWD
    MOV DI, FPSTRINGBUF
    CALL NUMBERTOSTRINGSIGNED

    MOV SI, FPSTRINGBUF
    POP DI

    PUSH CX
    CALL DUFFDEVICE
    POP BX

    POP CX
    ADD CX, BX
    INC CX
    RET

FPSINGLETOANODECIMAL:
    MOV AX, [FPINTEGERPART]
    CWD
    CALL NUMBERTOSTRINGSIGNED
    RET


