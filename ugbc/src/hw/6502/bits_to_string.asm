; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; TMPPTR  : first byte of number to convert
; TMMPTR2 : first byte of (destination) string
; A : number of bits
BINTOSTR:

    ; Save the actual number of bits to convert.

    PHA

    SEC
    SBC #1
    ; Move the destination string to the last bit to write.

    CLC
    ADC TMPPTR2
    STA TMPPTR2
    LDA #0
    ADC TMPPTR2+1
    STA TMPPTR2+1

    ; Recover the actual number of bits to convert,
    ; and save in an external counter.

    PLA
    STA MATHPTR0

    ; Use indirect addressing.

    LDY #0

    ; Bit-in-byte counter.

    LDX #8

    ; Read the n-th byte to convert.

BINTOSTRL1:

    LDA (TMPPTR), Y

    ; Move the bit in the carry.

BINTOSTRL2:

    LSR

    ; If carry = 0 then bit is zero.

    BCC BINTOSTRZERO

    ; Write a one (1) on the output string.

BINTOSTRONE:

    ; Preserve the actual byte we are investigating.

    PHA

    ; Write a 1 on the output string.

    LDA #'1'
    STA (TMPPTR2), Y

    ; Move backward of one byte.
    DEC TMPPTR2
    LDA TMPPTR2
    CMP #$FF
    BNE BINTOSTRONEA1
    DEC TMPPTR2+1
BINTOSTRONEA1:

    ; Restore the value.

    PLA

    ; We have done with this bit. Go on!

    JMP BINTOSTRL2DONE

    ; Write a zero (0) on the output string.
BINTOSTRZERO:

    ; Preserve the actual byte we are investigating.

    PHA

    ; Write a 0 on the output string.

    LDA #'0'
    STA (TMPPTR2), Y

    ; Move backward of one byte.
    DEC TMPPTR2
    LDA TMPPTR2
    CMP #$FF
    BNE BINTOSTRZEROA1
    DEC TMPPTR2+1
BINTOSTRZEROA1:

    ; Restore the value.

    PLA

    ; We have done with this bit. Go on!

    JMP BINTOSTRL2DONE

BINTOSTRL2DONE:

    ; Decrement the number of bit to convert.

    DEC MATHPTR0

    ; If there are no more bit, we have finished!

    BEQ BINTOSTRFINISH

    ; Decrement the number of bit inside the byte

    DEX

    ; If there are bit in byte, continue to convert the last one.

    BNE BINTOSTRL2

    ; Move forward of one byte.
    INC TMPPTR
    BNE BINTOSTRNEXTBYTEA1
    INC TMPPTR+1
BINTOSTRNEXTBYTEA1:

    ; Take the next byte.

    JMP BINTOSTRL1

BINTOSTRFINISH:
    RTS