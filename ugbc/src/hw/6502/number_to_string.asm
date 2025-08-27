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
;*                      CONVERT A NUMBER TO A STRING                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@EMIT numberConfig.maxDigits AS N2STRINGRESBUFFERSIZE
@EMIT numberConfig.maxBytes AS N2STRINGNUMBERMAXBYTES

N2STRINGRESBUFFER:  .RES    N2STRINGRESBUFFERSIZE,0
N2STRINGNUMBERSIGNED: .BYTE $00
N2STRINGNUMBER: .RES N2STRINGNUMBERMAXBYTES, 0
N2STRINGBYTES = N2STRINGDIV10BYTES+1

N2STRING:
    LDX N2STRINGBYTES
    DEX
    LDA N2STRINGNUMBER,X
    AND #$80
    STA N2STRINGNUMBERSIGNED
    BEQ N2STRINGGO
    LDX #0
N2STRINGLS:
    EOR N2STRINGNUMBER,X
    INX
    CPX N2STRINGBYTES
    BNE N2STRINGLS
    LDX #0
    LDA #1
N2STRINGLSB:
    ADC N2STRINGNUMBER,X
    STA N2STRINGNUMBER,X
    LDA #0
    INX
    CPX N2STRINGBYTES
    BNE N2STRINGLSB
N2STRINGGO:
    JSR N2STRINGH2D
    LDX #9;
    LDY #0;
N2STRINGL1:
    LDA N2STRINGRESBUFFER,x
    BNE N2STRINGL2
    DEX
    BNE N2STRINGL1
N2STRINGL2:
    LDA N2STRINGNUMBERSIGNED
    BEQ N2STRINGL2A
    LDA #'-'
    STA (TMPPTR),Y
    INY
N2STRINGL2A:
    LDA N2STRINGRESBUFFER,X
    ORA #$30
    STA (TMPPTR),Y
    INY
    DEX
    BPL N2STRINGL2A
    TYA
    STA MATHPTR5
    RTS

; Convert a number to a BCD string.
;
; Input: 
;       N2STRINGNUMBERADDRESS = address of the number to divide (first byte)
;       N2STRINGBYTES = number of bytes
; Output:
;       NS2RESBUFFER = destination buffer with the translated number 
;       NS2RESBUFFERSIZE = size of the destination buffer

N2STRINGH2D:

    ; Let start from the first digit to convert on the
    ; destination buffer.

    LDX #0

N2STRINGL3:

    ; Extract the right most digit of the number.
    
    JSR N2STRINGDIV10

    ; Put it on the destination buffer.

    STA N2STRINGRESBUFFER, X

    ; Move to the next.

    INX

    ; Repeat until all digits have been extracted.
    CPX #N2STRINGRESBUFFERSIZE
    BNE N2STRINGL3

    ; Done!

    RTS

; Divide a number by 10.
; Input: 
;       N2STRINGNUMBER = number to be divided
;       N2STRINGBYTES = number of bytes
; Output:
;       A = remainder

N2STRINGDIV10:

    ; Preserve the X register

    STX MATHPTR0

    ; Calculate the number of effective bits, to perform
    ; bitwise division (bits = bytes * 8 ), and move them
    ; on the Y register.
N2STRINGDIV10BYTES:
    LDA #00
    ASL
    ASL
    ASL
    TAY

    ; Initialize the calculation.

    LDA #0
    CLC

    ; For each bit...

N2STRINGDIV10L1:

    ; ... collect the remainder into the register A.
    
    ROL
    CMP #10
    BCC N2STRINGSSKIP
    SBC #10

    ; Perform a bit rotation of the number, for a number
    ; of bytes equal to the number of bytes of the original
    ; number to divide.

N2STRINGSSKIP:

    ; We are using X register to index the target number,
    ; while the Y register will be used as a counter.

    LDX #0

    ; Preserve the Y register

    STY MATHPTR1

    LDY N2STRINGBYTES

N2STRINGSSKIP2:
    ROL N2STRINGNUMBER, X
    INX
    DEY
    BNE N2STRINGSSKIP2

    ; Restore the original Y value.

    LDY MATHPTR1

    ; Repeat the process for each bit.

    DEY
    BPL N2STRINGDIV10L1

    ; Restore the X register

    LDX MATHPTR0

    RTS
