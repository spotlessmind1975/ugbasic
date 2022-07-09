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
MSC1UNCOMPRESS

    ; Initialize the offsets for input and output streams.

    ; Loop through the entire input stream.
MSC1UNCOMPRESSL1
    ; Take the current token from the input stream
    ; and move to the next element of the stream.
    LDA ,X+
    ; If token is zero the stream is finished.
    CMPA #$0
    BNE MSC1UNCOMPRESSL1NE
    RTS

    ; Check the kind of token.
MSC1UNCOMPRESSL1NE
    ; If the upper bit of the token is clear,
    ; it means that there is a literal block
    ; to emit on the output stream.
    TFR A, B
    ANDB #$80
    BNE MSC1UNCOMPRESSL1NE3
    JMP MSC1LITERAL
MSC1UNCOMPRESSL1NE3

    ; This code will parse the token, in order to
    ; retrieve the number of repetitions and the
    ; starting offset. Then, it will copy the very 
    ; same 4 bytes for the number of repetitions given. 
MSC1DUPES
    TFR A, B

    ; Take out the number of repetitions.
    ANDB #$7F
    LSRB
    LSRB
    ; If repetitions is zero then repetitions
    ; will be 32 times.
    CMPB #$0
    BNE MSC1DUPESNE
    LDB #32
MSC1DUPESNE

    PSHS D

    ; Extract the offset.
    LEAX -1, X
    LDD ,X
    ANDA #$03
    LEAX 2, X

    STD <MATHPTR0

    ; Recalculate the address from which to copy
    ; the output into the output again.
    TFR X, D
    SUBD <MATHPTR0
    TFR D, U

    PULS D

    ; Initialize the counter and copy the same 
    ; 4 bytes for each repetition.
MSC1DUPESL1
    LDA ,U+
    STA ,Y+
    LDA ,U+
    STA ,Y+
    LDA ,U+
    STA ,Y+
    LDA ,U+
    STA ,Y+
    LEAU -4, U
    DECB
    BNE MSC1DUPESL1
    JMP MSC1UNCOMPRESSL1

MSC1LITERAL
    TFR A, B
    ; Take the number of literals (1...127),
    ; and copy from the pointer to the output.
    ANDB #$7F
MSC1LITERALL1
    LDA ,X+
    STA ,Y+
    DECB
    BNE MSC1LITERALL1
    JMP MSC1UNCOMPRESSL1

MSC1UNCOMPRESSFINISH
    RTS
