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
;*                      CONVERT A NUMBER TO A STRING OF BITS (1/0)             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; AX:BX - number to convert to bits
; DI - string where to put the bits
BINSTR:
    PUSH DI
    PUSH AX
    MOV AH, 32
BINSTRXZ:
    MOV [DI], AL
    INC DI
    DEC AH
    CMP AH, 0
    JNZ BINSTRXZ
    POP AX
    POP DI
    MOV DX, 31
    ADD DI, 31
BINSTRL:
    SHR AX, 1
    ROR BX, 1
    JC BINSTRO1
    JP BINSTRO0
BINSTRO0:
    MOV CL, '0'
    MOV [DI], CL
    DEC DI
    JP BINSTRO
BINSTRO1:
    MOV CL, '1'
    MOV [DI], CL
    DEC DI
    JP BINSTRO
BINSTRO:
    DEC DX
    CMP DX, 0
    JNZ BINSTRL
    RET
