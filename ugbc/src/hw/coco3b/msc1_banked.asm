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
;*                        MSC1 DECOMPRESSOR (OVER A BANK)                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Last address to be used to refill the MSC1 buffer.
MSC1SOURCE          FDB $0000

; The MSC1 buffer to be refilled.
MSC1BUFFER          RZB 2048

; Last address filled on buffer.
MSC1BUFFEREND       FDB $0000

; Number of bytes needed.
MSC1REFILLNEEDED    FDB $0000

; This routine must be called at the start of the
; MSC1 decoding, in order to reset the various pointers.
MSC1RESET
    STY MSC1SOURCE
    LDY #MSC1BUFFER
    STY MSC1BUFFEREND
    RTS

; This routine must be called everytime we need to check
; if the buffer is filled. The D register must contains
; the number of bytes needed.
MSC1REFILLBUFFER

    STD MSC1REFILLNEEDED

    ; If the remaining bytes into the MSC1 buffer are enough
    ; for the next elaboration, go ahead.
    STY <MATHPTR0
    LDD MSC1BUFFEREND
    SUBD <MATHPTR0
    CMPD MSC1REFILLNEEDED
    BHS MSC1REFILLBUFFERC

    ; Refill the buffer.
    BSR MSC1UNCOMPRESSBANKED

MSC1REFILLBUFFERC

    RTS

; This routine will uncompress a MSC1 compressed memory block
; from Y address into X address. Note that this routine will
; stop as soon as the buffer is filled. In order to be
; callable multiple times, to refill the buffer, the pointer
; will be rewinded to the last valid position, although it
; has partially filled the buffer.
MSC1UNCOMPRESSBANKED

    ; Save the registers.
    PSHS X,U

    ; First of all, we must "translate" the remaining data
    ; into the MSC1 buffer, from the last position to
    ; the actual one. This must be done only if the buffer
    ; is already used.

    LDB #0
    LDX MSC1BUFFEREND
    CMPX #MSC1BUFFER
    BEQ MSC1UNCOMPRESSBANKEDL10

    TFR X, D
    STY <MATHPTR0
    SUBD <MATHPTR0
    STB <MATHPTR0
    LSRB

    LDX #MSC1BUFFER
MSC1UNCOMPRESSBANKEDTRANSLATE
    LDU ,Y++
    STU ,X++
    DECB
    BNE MSC1UNCOMPRESSBANKEDTRANSLATE

    LDB <MATHPTR0
MSC1UNCOMPRESSBANKEDL0
    LDX #MSC1BUFFER
    ABX

    COMB
    COMA
    ADDD #512
    STD MSC1REFILLNEEDED

MSC1UNCOMPRESSBANKEDL10
    ; Now we continue to decode the data from the
    ; source position.
    LDY MSC1SOURCE

    ; Loop through the entire input stream.
MSC1UNCOMPRESSBANKEDL1
    LDD MSC1REFILLNEEDED
    CMPD #0
    BLE MSC1UNCOMPRESSBANKEDDONE
    
    ; Take the current token from the input stream
    ; and move to the next element of the stream.
    LDA ,Y+
    ; If token is zero the stream is finished.
    CMPA #$0
    BNE MSC1UNCOMPRESSBANKEDL1NE

    JMP MSC1UNCOMPRESSBANKEDDONE

    ; Check the kind of token.
MSC1UNCOMPRESSBANKEDL1NE
    ; If the upper bit of the token is clear,
    ; it means that there is a literal block
    ; to emit on the output stream.
    TFR A, B
    ANDB #$80
    CMPB #$0
    BNE MSC1UNCOMPRESSBANKEDL1NE3
    JMP MSC1LITERAL
MSC1UNCOMPRESSBANKEDL1NE3

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
    LEAY -1, Y
    LDD ,Y++
    ANDA #$03

    STD <MATHPTR0

    ; Recalculate the address from which to copy
    ; the output into the output again.
    TFR Y, D
    SUBD <MATHPTR0
    TFR D, U

    PULS D

    PSHS D
    LDA #4
    MUL
    COMB
    COMA
    ADDD MSC1REFILLNEEDED
    STD MSC1REFILLNEEDED
    PULS D

    ; Initialize the counter and copy the same 
    ; 4 bytes for each repetition.
MSC1DUPESL1
    LDA ,U+
    STA ,X+
    LDA ,U+
    STA ,X+
    LDA ,U+
    STA ,X+
    LDA ,U+
    STA ,X+
    LEAU -4, U
    DECB
    BNE MSC1DUPESL1
    JMP MSC1UNCOMPRESSBANKEDL1

MSC1UNCOMPRESSBANKEDDONE
    STX MSC1BUFFEREND
    STY MSC1SOURCE    
    LDY #MSC1BUFFER
    PULS X,U
    RTS

MSC1LITERAL
    TFR A, B
    ; Take the number of literals (1...127),
    ; and copy from the pointer to the output.
    ANDB #$7F   

    PSHS D
    CLRA
    COMB
    COMA
    ADDD MSC1REFILLNEEDED
    STD MSC1REFILLNEEDED
    PULS D

MSC1LITERALL1
    LDA ,Y+
    STA ,X+
    DECB
    BNE MSC1LITERALL1
    JMP MSC1UNCOMPRESSBANKEDL1
