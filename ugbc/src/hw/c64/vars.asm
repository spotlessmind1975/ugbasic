; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR C64 TARGET                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS:        .BYTE   0, $84
BITMAPADDRESS:      .WORD   $A000
COLORMAPADDRESS:       .BYTE   0, $D8
CURRENTMODE:    .BYTE   0
CURRENTTILEMODE:    .BYTE   1
EVERYSTATUS:    .BYTE   0

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
EMPTYTILE:  .BYTE   32

TMPPTR = $22    ; $23
TMPPTR2 = $24    ; $25

OVFLO  = $26             ; overflow byte for the accumulator when it is shifted left or multiplied by ten.
MSB    = OVFLO+1         ; most-significant byte of the accumulator.
NMSB   = MSB+1           ; next-most-significant byte of the accumulator.
NLSB   = NMSB+1          ; next-least-significant byte of the accumulator.
LSB    = NLSB+1          ; least-significant byte of the accumulator.
BEXP   = LSB+1           ; contains the binary exponent, bit seven is the sign bit.
CHAR   = BEXP+1          ; used to store the character input from the keyboard.
MFLAG  = CHAR+1          ; set to $FF when a minus sign is entered.
DPFLAG = MFLAG+1         ; decimal point flag, set when decimal point is entered.
ESIGN  = DPFLAG+2        ; set to $FF when a minus sign is entered for the exponent.
MEM    = OVFLO           ; ???
ACC    = OVFLO           ; ???
ACCB   = OVFLO+16        ; ???
TEMP   = OVFLO+11        ; temporary storage location.
EVAL   = OVFLO+12        ; value of the decimal exponent entered after the "E."
DEXP   = OVFLO+23        ; current value of the decimal exponent.
BCDA   = OVFLO+32        ; BCD accumulator (5 bytes)
BCDN   = OVFLO+37        ; ???

SIGN = $DC
X2   = SIGN+1        ; EXPONENT 2
M2   = X2+1          ; MANTISSA 2
X1   = M2+3          ; EXPONENT 1
M1   = X1+1          ; MANTISSA 1
E    = M1+3          ; SCRATCH
ZZ   = E+4
T    = ZZ+4
SEXP = T+4
INT  = SEXP+4

MATHPTR0 = $F7
MATHPTR1 = $F8
MATHPTR2 = $F9
MATHPTR3 = $FA
MATHPTR4 = $FB
MATHPTR5 = $FC
MATHPTR6 = $FD
MATHPTR7 = $FE
MATHPTR8 = $FF

DSSTATUS = $32
DSSIZE = $21
DSADDRLO = $22
DSADDRHI = $23
DSBANKLO = $30
DSBANKHI = $31

COPYOFTEXTADDRESS = $25
COPYOFBITMAPADDRESS = $25
COPYOFCOLORMAPADDRESS = $2F
COPYOFTEXTADDRESS2 = $2D
COPYOFCOLORMAPADDRESS2 = $2B

DIRECTION = $32
PATTERN = $32
CHARACTERS = $25
CLINEX = $32
CLINEY = $33

BITSTOCONVERT = $25

XCURSYS = $D3
YCURSYS = $D6

BANKSHADOW: .BYTE 0
