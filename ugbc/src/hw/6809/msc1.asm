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
;*                              MSC1 DECOMPRESSOR                              *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; This routine will uncompress a MSC1 compressed memory block
; from an input stream to an output stream. Input stream must
; be pointed by <TMPPTR while the output stream must be pointed
; by <TMPPTR2.
; Optimized by Craig Allsop 2026/08.

;
; Finished decompression.
;
MSC1U_FINISH
    RTS

;
; Token(A) is positive (0-127) do literal copy.
;
MSC1U_LITERAL
    ;
    ; If token(A) is 0 the stream is finished.
    ;
    BEQ MSC1U_FINISH
    ;
    ; Take the number of literals (1...127),
    ; and copy from the pointer to the output.
    ; Divide count(A) by 2 and copy byte pairs.
    ;
    LSRA
    ;
    ; If count(A) was 1, then do one byte copy...
    ; Note: this probably shouldn't exist in the
    ; compressed stream as it costs 2 bytes for
    ; one output.
    ;
    BEQ MSC1U_LITERAL_ONE

;
; Copy byte pairs x count(A).
;
MSC1U_LITERAL_PAIRS
    LDU ,X++
    STU ,Y++
    DECA
    BNE MSC1U_LITERAL_PAIRS
    ;
    ; If count is even, then done.
    ;
    BCC MSC1U_UNCOMPRESS_NEXT

;
; Copy last/one byte.
;
MSC1U_LITERAL_ONE
    LDA ,X+
    STA ,Y+
    ;
    ; Fall through to next token...
    ;

;
; Entry Point:
;
MSC1UNCOMPRESS
MSC1U_UNCOMPRESS_NEXT
    ;
    ; Take the next token from the input stream.
    ;
    LDA ,X+
    ;
    ; If the upper bit of the token is clear,
    ; it means that there is a literal block
    ; to emit on the output stream.
    ;
    BPL MSC1U_LITERAL
    ;
    ; Token(A) bit 7 set, then its not end of stream,
    ; (saves testing for it), fall through to dups...
    ;

;
; This code will parse the token, in order to
; retrieve the number of repetitions and the
; starting offset. Then, it will copy the very 
; same 4 bytes for the number of repetitions given. 
;
MSC1U_DUPES
    ;
    ; Keep token(A) for count.
    ;
    STA MSC1U_DUPES_TOKEN
    ;
    ; Extract the offset and create new source(U)
    ;
    LDB ,X+
    ANDA #$03
    NEGA        ; NEGD
    NEGB
    SBCA #0
    LEAU D,X    ; U = X - D
    ;
    ; Restore token(B)
    ;
    LDB #$ff    ; *** must not be optimized away ***
MSC1U_DUPES_TOKEN EQU *-1
    ;
    ; Take out the number of repetitions.
    ; Mask top bit and shift off 2 low bits, and
    ; divide count by 2 for pairs loop.
    ;
    ANDB #$7F
    LSRB
    LSRB
    LSRB
    ;
    ; If count was >= 2
    ;
    BNE MSC1U_DUPES_PAIRS
    ;
    ; Else count was 0 or 1
    ; If count was 1, then copy one lot.
    ; A common case, this path should be short.
    ;
    BCS MSC1U_DUPES_ONE
    ;
    ; If count was zero then repetitions
    ; will be 32 times. (16 pairs)
    ;
    LDB #16
    ;
    ; Fall through to copy pairs
    ;

;
; Copy pairs of 4 bytes.
;
MSC1U_DUPES_PAIRS
    ;
    ; Keep source(X) and copy the same 
    ; 8 bytes for each repetition.
    ;
    STX <MATHPTR0
    ;
    ; Load the 4 bytes to repeat.
    ;
    LDX ,U
    LDU 2,U
;
; The loop for pairs of 4 bytes.
;
MSC1U_DUPES_LOOP
    ;
    ; Write two lots of 4 bytes.
    ;
    STX ,Y++
    STU ,Y++
    STX ,Y++
    STU ,Y++
    DECB
    BNE MSC1U_DUPES_LOOP
    ;
    ; If count is even, we're done with dups.
    ;
    BCC MSC1U_DUPES_END
    ;
    ; Else count is odd, write one more lot.
    ;
    STX ,Y++
    STU ,Y++
    ;
    ; Fall through to end of dups.
    ;

MSC1U_DUPES_END
    ;
    ; Reload source(X) and loop to next token.
    ;
    LDX <MATHPTR0
    BRA MSC1U_UNCOMPRESS_NEXT

;
; A highly common case, just copy one lot of
; 4 bytes..
;
MSC1U_DUPES_ONE
    LDD ,U
    LDU 2,U
    STD ,Y++
    STU ,Y++
    BRA MSC1U_UNCOMPRESS_NEXT
