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
;*                              DATA ENCRYPTION                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ENCRYPT
; Encrypt a memory area using a XOR algorithm, with an additional checksum.
;
; Input:
;       SI: address of the memory area to encrypt
;       DX: address of the key (must be equal to the area to encrypt)
;       DI: address of the destination area encrypted
;       CL: size of the memory area to encrypt
ENCRYPT:
    MOV BL, 0
    PUSH SI
    PUSH DX
    PUSH CX
ENCRYPTL1:
    MOV AL, [SI]
    ADD BL, AL
    MOV BL, AL
    INC SI
    DEC CL
    CMP CL, 0
    JNZ ENCRYPTL1
    POP CX
    POP DX
    POP SI
ENCRYPTL2:
    MOV AL, [DX]
    XOR [SI]
    MOV [DI], AL
    INC SI
    INC DX
    INC DI
    DEC CL
    CMP CL, 0
    JNZ ENCRYPTL2
    MOV AL, BL
    MOV [DI], AL
    RET
