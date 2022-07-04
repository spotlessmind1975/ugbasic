; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
    ; Take the current token from the input stream
    ; and move to the next element of the stream.
    LD A, (HL)
    INC HL
    ; If token is zero the stream is finished.
    CP 0
    JR NZ, MSC1UNCOMPRESSL1NE
    RET

    ; Check the kind of token.
MSC1UNCOMPRESSL1NE:
    ; If the upper bit of the token is clear,
    ; it means that there is a literal block
    ; to emit on the output stream.
    PUSH A
    AND $80
    JR NZ, MSC1UNCOMPRESSL1NE3
    JP MSC1LITERAL
MSC1UNCOMPRESSL1NE3:
    POP A

    ; This code will parse the token, in order to
    ; retrieve the number of repetitions and the
    ; starting offset. Then, it will copy the very 
    ; same 4 bytes for the number of repetitions given. 
MSC1DUPES:

    PUSH A

    ; Take out the number of repetitions.
    AND $7F
    SRL A
    SRL A
    ; If repetitions is zero then repetitions
    ; will be 32 times.
    CP 0
    BNE MSC1DUPESNE
    LD A, 32
MSC1DUPESNE:
    LD B, A

    POP A

    ; Extract the offset.
    PUSH DE
    AND #$03
    LD D, A
    LD A, (HL)
    INC HL
    LD E, A

    ; Recalculate the address from which to copy
    ; the output into the output again.
    PUSH HL
    SBC HL, DE

    ; Initialize the counter and copy the same 
    ; 4 bytes for each repetition.
MSC1DUPESL1:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    SBC HL, 4
    DEC B
    JR NZ, MSC1DUPESL1
    POP HL
    POP DE
    JP MSC1UNCOMPRESSL1

MSC1LITERAL:
    POP A

    ; Take the number of literals (1...127),
    ; and copy from the pointer to the output.
    AND $7F
    LD B, A
MSC1LITERALL1:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, MSC1LITERALL1
    JP MSC1UNCOMPRESSL1
