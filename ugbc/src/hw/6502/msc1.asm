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

; Get a single byte from the input stream pointed by TMPPTRx2.
; This routine uses the MATHPTR0 to maintain the Y offset.
MSC1UNCOMPRESSGETBYTE:
    LDY MATHPTR0
    LDA (TMPPTR),Y
    INY
    BNE MSC1UNCOMPRESSGETBYTENE
    INC TMPPTR+1
MSC1UNCOMPRESSGETBYTENE:
    STY MATHPTR0
    RTS

; Put a single byte to the output stream pointed by TMPPTR2x2.
; This routine uses the MATHPTR1 to maintain the Y offset.
MSC1UNCOMPRESSPUTBYTE:
    LDY MATHPTR1
    STA (TMPPTR2),Y
    INY
    BNE MSC1UNCOMPRESSGETBYTENE
    INC TMPPTR2+1
MSC1UNCOMPRESSGETBYTENE:
    STY MATHPTR1
    RTS

; Get a single byte from the output stream pointed by MATHPTR3:4.
; This routine uses the MATHPTR2 to maintain the Y offset.
MSC1UNCOMPRESSREGETBYTE:
    LDY MATHPTR2
    LDA (MATHPTR3),Y
    INY
    BNE MSC1UNCOMPRESSREGETBYTENE
    INC MATHPTR4
MSC1UNCOMPRESSREGETBYTENE:
    STY MATHPTR2
    RTS

; This routine will uncompress a MSC1 compressed memory block
; from an input stream to an output stream. Input stream must
; be pointed by TMPPTR while the output stream must be pointed
; by TMPPTR2.
MSC1UNCOMPRESS:

    ; Initialize the offsets for input and output streams.
    LDY #0
    STY MATHPTR0
    STY MATHPTR1
    STY MATHPTR2

    ; Loop through the entire input stream.
MSC1UNCOMPRESSL1:
    ; Take the current token from the input stream
    ; and move to the next element of the stream.
    JSR MSC1UNCOMPRESSGETBYTE
    ; If token is zero the stream is finished.
    CMP #$0
    BNE MSC1UNCOMPRESSL1NE
    RTS

    ; Check the kind of token.
MSC1UNCOMPRESSL1NE:
    ; If the upper bit of the token is clear,
    ; it means that there is a literal block
    ; to emit on the output stream.
    PHA
    AND #$80
    BNE MSC1UNCOMPRESSL1NE3
    JMP MSC1LITERAL
MSC1UNCOMPRESSL1NE3:
    PLA

    ; This code will parse the token, in order to
    ; retrieve the number of repetitions and the
    ; starting offset. Then, it will copy the very 
    ; same 4 bytes for the number of repetitions given. 
MSC1DUPES:
    PHA

    ; Take out the number of repetitions.
    AND #$7F
    LSR A
    LSR A
    ; If repetitions is zero then repetitions
    ; will be 32 times.
    CMP #$0
    BNE MSC1DUPESNE
    LDA #32
MSC1DUPESNE:
    TAX

    ; Extract the offset.
    PLA
    AND #$03
    STA MATHPTR4
    JSR MSC1UNCOMPRESSGETBYTE
    STA MATHPTR3

    ; Recalculate the address from which to copy
    ; the output into the output again.
    SEC
    LDA TMPPTR2
    SBC MATHPTR3
    STA MATHPTR3
    LDA TMPPTR2+1
    SBC MATHPTR4
    STA MATHPTR4

    ; Initialize the counter and copy the same 
    ; 4 bytes for each repetition.
MSC1DUPESL1:
    LDY #0
    STY MATHPTR2
    JSR MSC1UNCOMPRESSREGETBYTE
    JSR MSC1UNCOMPRESSPUTBYTE
    JSR MSC1UNCOMPRESSREGETBYTE
    JSR MSC1UNCOMPRESSPUTBYTE
    JSR MSC1UNCOMPRESSREGETBYTE
    JSR MSC1UNCOMPRESSPUTBYTE
    JSR MSC1UNCOMPRESSREGETBYTE
    JSR MSC1UNCOMPRESSPUTBYTE
    DEX
    BNE MSC1DUPESL1
    JMP MSC1UNCOMPRESSL1

MSC1LITERAL:
    PLA
    ; Take the number of literals (1...127),
    ; and copy from the pointer to the output.
    AND #$7F
    TAX
MSC1LITERALL1:
    JSR MSC1UNCOMPRESSGETBYTE
    JSR MSC1UNCOMPRESSPUTBYTE
    DEX
    BNE MSC1LITERALL1
    JMP MSC1UNCOMPRESSL1

MSC1UNCOMPRESSFINISH:
    RTS
