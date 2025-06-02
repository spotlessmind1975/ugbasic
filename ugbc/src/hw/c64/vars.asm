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
;*                      INTERNAL VARIABLES FOR C64 TARGET                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTADDRESS:        .WORD   $8400
BITMAPADDRESS:      .WORD   $A000
COLORMAPADDRESS:       .BYTE   0, $D8
CURRENTMODE:    .BYTE   0
CURRENTTILEMODE:    .BYTE   1
EVERYSTATUS:    .BYTE   0

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
EMPTYTILE:  .BYTE   32
TICKSPERSECOND: .BYTE   0

TMPPTR = $22    ; $23
TMPPTR2 = $24    ; $25

OVFLO  = $47             ; overflow byte for the accumulator when it is shifted left or multiplied by ten.
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

SIGN = $7E
X2   = SIGN+1        ; EXPONENT 2
M2   = X2+1          ; MANTISSA 2
X1   = M2+3          ; EXPONENT 1
M1   = X1+1          ; MANTISSA 1
E    = M1+3          ; SCRATCH
ZZ   = E+4
T    = ZZ+4
SEXP = T+4
INT  = SEXP+4

MATHPTR0 = $D9
MATHPTR1 = $DA
MATHPTR2 = $DB
MATHPTR3 = $DC
MATHPTR4 = $DD
MATHPTR5 = $DE
MATHPTR6 = $DF
MATHPTR7 = $E0
MATHPTR8 = $E1

DSSTATUS = $E4
DSSIZE: .BYTE 0
DSADDRLO = $E2
DSADDRHI = $E3
DSBANKLO: .BYTE 0
DSBANKHI: .BYTE 0

COPYOFTEXTADDRESS = $10; $11
COPYOFBITMAPADDRESS = $12; $13
COPYOFCOLORMAPADDRESS = $4C; $4D
COPYOFTEXTADDRESS2 = $1E; $1F
COPYOFCOLORMAPADDRESS2 = $1C; $1D

KEYBPREV: .BYTE 0
KEYBLEN: .BYTE 0

DIRECTION: .BYTE 0
PATTERN: .BYTE 0
CHARACTERS: .BYTE 0
CLINEX: .BYTE 0
CLINEY: .BYTE 0

BITSTOCONVERT: .BYTE 0

XCURSYS = $D3
YCURSYS = $D6

BANKSHADOW: .BYTE 0

DATAPTR = $AA
DATAPTRY:    .BYTE $0

TIMERP0 = $1E
TIMERP1 = $1c

JOYSTICK0:      .BYTE   $0
JOYSTICK1:      .BYTE   $0

NMISVC_SYSTEM:      .WORD   $0
IRQSVC_SYSTEM:      .WORD   $0
IRQSVC2_SYSTEM:     .WORD   $0
NMISVC_UGBASIC:     .WORD   $0
IRQSVC_UGBASIC:     .WORD   $0
IRQSVC2_UGBASIC:    .WORD   $0

DLOADERROR:         .BYTE   $0
DSAVEERROR:         .BYTE   $0

OLDD018:            .BYTE   $0
DOJOERROR:          .BYTE $00
