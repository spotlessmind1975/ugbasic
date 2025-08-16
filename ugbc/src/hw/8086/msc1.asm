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
;*                              MSC1 DECOMPRESSOR                              *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; This routine will uncompress a MSC1 compressed memory block
; from an input stream to an output stream. Input stream must
; be pointed by TMPPTR while the output stream must be pointed
; by TMPPTR2.
MSC1UNCOMPRESS:

    ; Initialize the offsets for input and output streams.

    ; Loop through the entire input stream.
MSC1UNCOMPRESSL1:
    ; ; Take the current token from the input stream
    ; ; and move to the next element of the stream.
    ; LD A, (HL)
    MOV AL, [SI]
    ; INC HL
    INC SI
    ; ; If token is zero the stream is finished.
    ; CP 0
    CMP AL, 0
    ; JR NZ, MSC1UNCOMPRESSL1NE
    JNZ MSC1UNCOMPRESSL1NE
    ; RET
    RET

    ; Check the kind of token.
MSC1UNCOMPRESSL1NE:
    ; ; If the upper bit of the token is clear,
    ; ; it means that there is a literal block
    ; ; to emit on the output stream.
    ; PUSH AF
    PUSH AX
    ; AND $80
    AND AL, 0x80
    ; CP 0
    CMP AL, 0
    ; JR NZ, MSC1UNCOMPRESSL1NE3
    JNZ MSC1UNCOMPRESSL1NE3
    ; JP MSC1LITERAL
    JP MSC1LITERAL
MSC1UNCOMPRESSL1NE3:
    ; POP AF
    POP AX

    ; This code will parse the token, in order to
    ; retrieve the number of repetitions and the
    ; starting offset. Then, it will copy the very 
    ; same 4 bytes for the number of repetitions given. 
MSC1DUPES:

    ; PUSH AF
    PUSH AX

    ; ; Take out the number of repetitions.
    ; AND $7F
    AND AL, 0x7f
    ; SRL A
    ; SRL A
    SAL AL, 1
    SAL AL, 1
    ; ; If repetitions is zero then repetitions
    ; ; will be 32 times.
    ; CP 0
    CMP AL, 0
    ; JR NZ, MSC1DUPESNE
    JNZ MSC1DUPESNE
    ; LD A, 32
    MOV AL, 32
MSC1DUPESNE:
    ; LD B, A
    MOV BL, AL
    ; POP AF
    POP AX

    ; ; Extract the offset.
    PUSH SI
    PUSH BX
    ; AND $03
    AND AL, 0x03
    ; LD D, A
    LD BH, AL
    ; LD A, (HL)
    LD BL, [SI]
    ; INC HL
    INC SI
    ; LD E, A
    ; SBC HL, DE
    SUB SI, BX
    ; LD IX, HL
    MOV DI, SI
    POP BX
    POP SI

    ; PUSH HL
    PUSH SI
    ; LD HL, IX
    MOV SI, DI

    ; ; Recalculate the address from which to copy
    ; ; the output into the output again.

    ; ; Initialize the counter and copy the same 
    ; ; 4 bytes for each repetition.
MSC1DUPESL1:
    ; LD A, (HL)
    MOV AL, [SI]
    ; LD (DE), A
    MOV [DI], AL
    ; INC HL
    INC SI
    ; INC DE
    INC DI
    ; LD A, (HL)
    MOV AL, [SI]
    ; LD (DE), A
    MOV [DI], AL
    ; INC HL
    INC SI
    ; INC DE
    INC DI
    ; LD A, (HL)
    MOV AL, [SI]
    ; LD (DE), A
    MOV [DI], AL
    ; INC HL
    INC SI
    ; INC DE
    INC DI
    ; LD A, (HL)
    MOV AL, [SI]
    ; LD (DE), A
    MOV [DI], AL
    ; INC HL
    INC SI
    ; INC DE
    INC DI
    ; DEC HL
    DEC SI
    ; DEC HL
    DEC SI
    ; DEC HL
    DEC SI
    ; DEC HL
    DEC SI
    ; DEC B
    DEC BL
    ; JR NZ, MSC1DUPESL1
    CMP BL, 0
    JNZ MSC1DUPESL1
    ; POP HL
    POP SI
    ; INC HL
    INC SI
    ; JP MSC1UNCOMPRESSL1
    JP MSC1UNCOMPRESSL1

MSC1LITERAL:
    ; POP AF
    POP AX

    ; ; Take the number of literals (1...127),
    ; ; and copy from the pointer to the output.
    ; AND $7F
    AND AL, 0x7f
    ; LD B, A
    MOV BL, AL
MSC1LITERALL1:
    ; LD A, (HL)
    MOV AL, [SI]
    ; LD (DE), A
    MOV [DI], AL
    ; INC HL
    INC SI
    ; INC DE
    INC DI
    ; DEC B
    DEC BL
    ; JR NZ, MSC1LITERALL1
    CMP BL, 0
    JNZ MSC1LITERALL1
    ; JP MSC1UNCOMPRESSL1
    JP MSC1UNCOMPRESSL1
