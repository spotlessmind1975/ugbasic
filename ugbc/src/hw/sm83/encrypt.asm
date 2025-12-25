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
;       HL: address of the memory area to encrypt
;       IX: address of the key (must be equal to the area to encrypt)
;       B: size of the key
;       DE: address of the destination area encrypted
;       C: size of the memory area to encrypt
ENCRYPT:
    LD A, B
    CP C
    JR Z, ENCRYPTLS
    JR C, ENCRYPTLS
    LD B, C
    LD A, B
ENCRYPTLS:
    LD A, B
    LD (IYLR), A
    LD (IYHR), A
    LD B, 0
    PUSH HL
    PUSH DE
    PUSH BC
ENCRYPTL1:
    LD A, (HL)
    ADD B
    LD B, A
    INC HL
    DEC C
    LD A, C
    CP 0
    JR NZ, ENCRYPTL1
    POP BC
    POP DE
    POP HL
ENCRYPTL2:
    LD A, (IXR)
    XOR (HL)
    LD (DE), A
    INC HL
    PUSH HL
    LD HL, (IXR)
    INC HL
    LD (IXR), HL
    POP HL
    DEC (IYLR)
    LD A, (IYLR)
    CP 0
    JR NZ, ENCRYPTL2A
    LD A, (IYHR)
    LD (IYLR), A
ENCRYPTL2A:
    INC DE
    DEC C
    LD A, C
    CP 0
    JR NZ, ENCRYPTL2
    LD A, B
    LD (DE), A
    RET
