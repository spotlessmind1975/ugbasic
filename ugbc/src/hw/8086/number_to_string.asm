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
    JNZ NUMBERTOSTRING0

NUMBERTOSTRINGL0:
    PUSH AX
    MOV AX, DX
    XOR DX, DX
    DIV BX
    XCHG DX, AX
    POP DX
    XCHG DX, AX

    PUSH AX
    MOV AX, DX
    XOR DX, DX
    DIV BX
    
    XCHG DX, AX
    MOV AX, DX
    MOV DX, [SP+2]
    MOV [SP+2], AX
    MOV DX, AX

    MOV AX, [SP+2]
    MOV DX, 0
    MOV AX, [SP+2]
    MOV DX, 0
    XOR DX, DX
    DIV BX

    ADD DL, '0'
    PUSH DX
    INC CX

    CMP AX, 0
    JNE NUMBERTOSTRINGL0
    CMP DX, 0
    JNE NUMBERTOSTRINGL0

NUMBERTOSTRINGD0:
    POP AX
    MOV [DI], AL
    INC DI
    LOOP NUMBERTOSTRINGD0

    MOV CX, DI
    SUB CX, SI

    RET

NUMBERTOSTRING0:
    MOV [DI], '0'
    INC DI
    MOV CX, 1
    RET