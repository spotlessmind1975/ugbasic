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
;*                            by Samuel Devulder                               *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@EMIT numberConfig.maxDigits AS N2STRINGRESBUFFERSIZE
@EMIT numberConfig.maxBytes AS N2STRINGNUMBERMAXBYTES

N2STRINGNUMBERSIGNED
  fcb $00
N2STRINGNUMBER
  rzb N2STRINGNUMBERMAXBYTES
N2STRINGNUMBERBYTES
  fcb $00

; input:
; N2STRINGNUMBER holds the number
; N2STRINGNUMBERSIGNED = sign
; A = number of bits
; X = result ptr

; output:
; A = string length

N2STRING

  ; First of all, we must clean all local data storage.

  PSHS  D, X

  ; Clear the BCD space.

  LDX   #N2STRING_bcd
  LDD   #0
  LDU   #N2STRINGRESBUFFERSIZE
N2STRINGCD1
  STD   ,X++
  LEAU  -2, U
  CMPU  #0
  BNE N2STRINGCD1

  ; Clear the PWR space.

  LDX   #N2STRING_pwr
  LDD   #0
  LDU   #N2STRINGRESBUFFERSIZE
N2STRINGCD2
  STD   ,X++
  LEAU  -2, U
  CMPU  #0
  BNE   N2STRINGCD2

  ; Initialize the PWR space with an 1.

  LDX   #N2STRING_pwr
  LDD   #1
  STD   (N2STRINGRESBUFFERSIZE/2)-2, X

  PULS  D, X

  ; Save the temporary pointer to the string
  ; with the converted number.

  STX   <TMPPTR

  ; Y will take care of the (actual) number of bits to convert.

  LDY   #0
  LEAY  A,Y           ; number of bits

  ; We calculate also the (actual) number of bytes to convert.

  PSHS  D
  LSRA
  LSRA
  LSRA
  STA   N2STRINGNUMBERBYTES
  PULS  D

  ; Initialize pointers: X for BCD, U for PWR

  LDX   #N2STRING_bcd
  LDU   #N2STRING_pwr

  ; Start the loop for each bit to convert.

N2STRINGL1

  ; We do a bit rotation of the number to be converted.
  ; Since it has dynamic size (1 up to N bytes), we must
  ; exploit the original LSR...ROR loop, in order to be
  ; a bit more dynamic.

  PSHS D, X

  ; Lets start to calculate the effective starting address
  ; to begin with the first LSR. Since 6809 is big endian,
  ; we must calculate it as a difference between the maximum
  ; number of bytes for number and the actual number of bytes.
  ;
  ; |<------   maximum size  ------>|
  ; +---+---+---+---+---+---+---+---+
  ; |   |   |   |   |   |   |   |   |
  ; +---+---+---+---+---+---+---+---+
  ;                         ^<------>
  ;                         |   real size
  ;                         +--- starting point

  LDX   #N2STRINGNUMBER
  LDA   #N2STRINGNUMBERMAXBYTES
  SUBA  N2STRINGNUMBERBYTES
  LEAX  A, X
  LDB   N2STRINGNUMBERBYTES
  LDA   #0

  ; The first byte must be shifted to the right.

  LSR   A,X
  INCA

  ; If the effective number is ended, we can finish.

  DECB
  BEQ N2STRINGL1DONE

N2STRINGL1D2

  ; The following bytes must be rotated to the right.

  ROR   A,X
  INCA

  ; If the effective number is ended, we can finish.

  DECB
  BNE N2STRINGL1D2
N2STRINGL1DONE
  PULS D, X

  ; Now we check if a carry bit has been setted.

  BCC   N2STRINGL2

  ; If the bit is setted, we must add the actual value
  ; of PWR to the BCD.

  LDX   #N2STRING_bcd ; bcd += pwr
  BSR   N2STRING_add

N2STRINGL2

  ; If the bit is clear, we must double the current PWR.

  LDX   #N2STRING_pwr ; pwr += pwr
  BSR   N2STRING_add

  ; Repeat the loop until all bits have been processed.

  LEAY  -1,Y          ; finished ?
  BNE   N2STRINGL1    ; no=>loop

  ; Now we can proceed to convert the number to an ASCII
  ; representation. Let's restore the destination string
  ; address.

  LDX   <TMPPTR

  ; Initialize the A register with the maximum number of
  ; digits to be used to represent the number.

  LDA   #-(N2STRINGRESBUFFERSIZE/2)

  ; Move the U pointer to the end of the BCD space.

  LDU   #N2STRING_bcd+N2STRINGNUMBERMAXBYTES

  ; If the number is positive, go ahead to printing.

  LDB   N2STRINGNUMBERSIGNED
  BPL   N2STRINGL3

  ; Store the negative sign into the destination string.

  LDB   #'-
  STB   ,X+

  ; Now we look for the first "non zero" digit.
N2STRINGL3

  ; First, increment the position and exit if
  ; end of the number has been reached.
  INCA
  BGT   N2STRINGL5  ; result==0

  ; Then, load the 2 digit BCS and go ahead if both are zero.

  LDB   A,U         ; LDB is faster than TST
  BEQ   N2STRINGL3

  ; Now we check if the higher part of the BCD is zero, so that
  ; we can start from the lower part to print the digits.

  BITB  #$F0
  BEQ   N2STRINGL5

  ; Print the higher part of BCD as a digit.
N2STRINGL4
  LDB   A,U
  LSRB
  LSRB
  LSRB
  LSRB
  ADDB  #'0
  STB   ,X+

  ; Print the lower part of BCD as a digit.

  LDB   A,U
  ANDB  #15
N2STRINGL5
  ADDB  #'0
  STB   ,X+

  ; Move ahead to the next BCD digit, and we start printing
  ; from the higher part of BCD.

  INCA
  BLE   N2STRINGL4

  ; Finally, calculate the size of the string.
  
  TFR   X,D
  SUBD  <TMPPTR
  TFR   B,A
  RTS

; This routine will add PWR to BCD / PWR variable.
; *x += pwr
N2STRING_add

  ; Load the effective size of the number, in bytes.

  LDB   #N2STRINGNUMBERMAXBYTES

  ; Clear the carry.
  CLRA
  
N2STRING_add1

  ; Load the addend coming from U.

  LDA   B,U

  ; Add the addend coming from X.

  ADCA  B,X

  ; Adjusts the value resulting from the binary addition 
  ; in accumulator A so that it contains the desired BCD 
  ; result instead of jsut a binary addition.

  DAA

  ; Store the result of BCD addition.

  STA   B,X

  ; Repeat until all bytes have been summed up.
  DECB
  BPL   N2STRING_add1

  RTS

; 2^32 is 10 digits long, so 5 BCD bytes are enough
N2STRING_bcd
  rzb N2STRINGRESBUFFERSIZE/2       ; converted number in BCD
N2STRING_pwr
  rzb N2STRINGRESBUFFERSIZE/2       ; powers of 2 in BCD
