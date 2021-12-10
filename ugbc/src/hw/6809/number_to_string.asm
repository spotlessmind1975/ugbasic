; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

; input:
; <MATHPTR0...<MATHPTR3 holds the number
; <MATHPTR4 = sign
; A = number of bits
; X = result ptr

; output:
; A = string length

N2STRING
  STX   <TMPPTR
  LDY   #0
  LEAY  A,Y           ; number of bits

  LDX   #N2STRING_bcd
  LDU   #N2STRING_pwr
  LDD   #0            ; clear local data
  STD   ,X
  STD   2,X
  STD   4,X
  STD   6,X
  INCB
  STD   8,X           ; pwr=1

N2STRINGL1
  LSR   <MATHPTR0
  ROR   <MATHPTR1
  ROR   <MATHPTR2
  ROR   <MATHPTR3
  BCC   N2STRINGL2
  LDX   #N2STRING_bcd ; bcd += pwr
  BSR   N2STRING_add
N2STRINGL2
  LDX   #N2STRING_pwr ; pwr += pwr
  BSR   N2STRING_add
  LEAY  -1,Y          ; finished ?
  BNE   N2STRINGL1    ; no=>loop

  LDX   <TMPPTR
  LDA   #-5
  LDU   #N2STRING_bcd+4
  LDB   <MATHPTR4
  BPL   N2STRINGL3
  LDB   #'-
  STB   ,X+
; look for first non null digits
N2STRINGL3
  INCA
  BGT   N2STRINGL5  ; result==0
  LDB   A,U         ; LDB is faster than TST
  BEQ   N2STRINGL3
  BITB  #$F0
  BEQ   N2STRINGL5
N2STRINGL4
  LDB   A,U
  LSRB
  LSRB
  LSRB
  LSRB
  ADDB  #'0
  STB   ,X+
  LDB   A,U
  ANDB  #15
N2STRINGL5
  ADDB  #'0
  STB   ,X+
  INCA
  BLE   N2STRINGL4

  TFR   X,D
  SUBD  <TMPPTR
  TFR   B,A
  RTS

; *x += pwr
N2STRING_add
  LDB   #4
  CLRA        ; C=0
N2STRING_add1
  LDA   B,U
  ADCA  B,X
  DAA
  STA   B,X
  DECB
  BPL   N2STRING_add1
  RTS

; 2^32 is 10 digits long, so 5 BCD bytes are enough
N2STRING_bcd
  rzb 5       ; converted number in BCD
N2STRING_pwr
  rzb 5       ; powers of 2 in BCD
