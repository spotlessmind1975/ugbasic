; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from source code by Alwin Henseler on:
;  * https://www.msx.org/forum/development/msx-development/32-bit-long-ascii
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

; Routine per convertire un numero a 32 bit (DX:AX) in una stringa ASCII
; Input:
;   DX:AX = il numero a 32 bit da convertire
;   DI = l'indirizzo di memoria dove salvare la stringa
; Output:
;   DI = l'indirizzo della fine della stringa
;   CX = Numero di caratteri che compongono il numero
;   Stringa salvata nella memoria a partire dall'indirizzo di DI
; Registri usati: AX, BX, CX, DX, DI, SP (implicitamente), SI

NUMBERTOSTRING:

    MOV SI, DI
    MOV CX, 0
    MOV BX, 10

    CMP DX, 0
    JNZ NUMBERTOSTRINGL0
    CMP AX, 0
    JZ NUMBERTOSTRING0

NUMBERTOSTRINGL0:

    PUSH DX
    PUSH AX

    ; DX = resto di ( AX / BX )
    DIV BX

    MOV BX, DX

    ADD DL, '0'
    MOV [DI], DL
    INC DI
    INC CX

    POP AX
    POP DX

    SUB AX, BX
    SBB DX, 0

    MOV BX, 10

    CMP DX, 0
    JNZ NUMBERTOSTRINGL0
    CMP AX, 0
    JNZ NUMBERTOSTRINGL0

    PUSH CX
    PUSH SI
NUMBERTOSTRINGL1:
    MOV AL, [SI]
    MOV [DI], AL
    DEC DI
    INC SI
    DEC CX
    CMP CX, 0
    JNZ NUMBERTOSTRINGL1
    POP SI
    POP CX
    RET

NUMBERTOSTRING0:
    MOV AL, '0'
    MOV [SI], AL
    MOV CX, 1
    RET
