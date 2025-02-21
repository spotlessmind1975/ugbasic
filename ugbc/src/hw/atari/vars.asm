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
;*                      INTERNAL VARIABLES FOR ATARI TARGET                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IOCB_OPEN           = $03       ; open
IOCB_GETREC         = $05       ; get record
IOCB_GETCHR         = $07       ; get character(s)
IOCB_PUTREC         = $09       ; put record
IOCB_PUTCHR         = $0B       ; put character(s)
IOCB_CLOSE          = $0C       ; close
IOCB_STATIS         = $0D       ; status
IOCB_SPECIL         = $0E       ; special
IOCB_DRAWLN         = $11       ; draw line
IOCB_FILLIN         = $12       ; draw line with right fill
IOCB_RENAME         = $20       ; rename disk file
IOCB_DELETE         = $21       ; delete disk file
IOCB_LOCKFL         = $23       ; lock file (set to read-only)
IOCB_UNLOCK         = $24       ; unlock file
IOCB_POINT          = $25       ; point sector
IOCB_NOTE           = $26       ; note sector
IOCB_GETFL          = $27       ; get file length
IOCB_CHDIR_MYDOS    = $29       ; change directory (MyDOS)
IOCB_MKDIR          = $2A       ; make directory (MyDOS/SpartaDOS)
IOCB_RMDIR          = $2B       ; remove directory (SpartaDOS)
IOCB_CHDIR_SPDOS    = $2C       ; change directory (SpartaDOS)
IOCB_GETCWD         = $30       ; get current directory (MyDOS/SpartaDOS)
IOCB_FORMAT         = $FE       ; format


IOCB                = $0340

ICHID               = $0340     ; DEVICE HANDLER IS (SET BY OS)
ICDNO               = $0341     ; DEVICE NUMBER (SET BY OS)
ICCOM               = $0342     ; I/O COMMAND
ICSTA               = $0343     ; I/O STATUS
ICBADRL             = $0344     ; BUFFER ADDRESS (LOW)
ICBADRH             = $0345     ; BUFFER ADDRESS (HIGH)
ICPUT               = $0346     ; DH PUT ROUTINE (ADR-1)
ICBLENL             = $0348     ; BUFFER LENGTH (LOW)
ICBLENH             = $0349     ; BUFFER LENGTH (HIGH)
ICAUX1              = $034A     ; AUX 1
ICAUX2              = $034B     ; AUX 2
ICAUX3              = $034C     ; AUX 3
ICAUX4              = $034D     ; AUX 4
ICAUX5              = $034E     ; AUX 5
ICAUX6              = $034F     ; AUX 6

CIOV                = $E456     ; JSR vector for CIO. All CIO operations go through this address

SIODDEVIC = $300
SIODUNIT = $301
SIODCOMND = $302
SIODSTATS = $303
SIODBUFLO = $304
SIODBUFHI = $305
SIODTIMLO = $306
SIODUNUSE = $307          	
SIODBYTLO = $308
SIODBYTHI = $309
SIODAUX1 = $30A
SIODAUX2 = $30B

SIOV = $E459

TEXTADDRESS:        .WORD   $A000
BITMAPADDRESS:      .WORD   $A000
COLORMAPADDRESS:       .BYTE   0, $0
EVERYSTATUS:         .BYTE   $00

TABCOUNT:   .BYTE    4
XCURS:      .BYTE    0
YCURS:      .BYTE    0
EMPTYTILE:  .BYTE   0
CURRENTMODE:    .BYTE   2
CURRENTTILEMODE:    .BYTE   1
LASTCOLOR:      .BYTE   0
KBDDELAYCT:    .BYTE   0

TICKSPERSECOND: .BYTE   0

TMPPTR = $80    ; $81
TMPPTR2 = $82    ; $83

MATHPTR0 = $84
MATHPTR1 = $85
MATHPTR2 = $86
MATHPTR3 = $87
MATHPTR4 = $88
MATHPTR5 = $89
MATHPTR6 = $8A
MATHPTR7 = $8B

DSSTATUS = $8C
DSSIZE = $8D
DSADDRLO = $8E
DSADDRHI = $8F
DSBANKLO = $90
DSBANKHI = $91

COPYOFTEXTADDRESS = $a1
COPYOFBITMAPADDRESS = $a2
COPYOFCOLORMAPADDRESS = $a3
COPYOFTEXTADDRESS2 = $a4
COPYOFCOLORMAPADDRESS2 = $a5

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

DIRECTION = $92
CHARACTERS = $93
PATTERN = $92
CLINEX = $97
CLINEY = $98
BITSTOCONVERT = $94

XCURSYS = $A7
YCURSYS = $A8 ; $B2 for graphical modes!

DATAPTR = $AA
DATAPTRY:    .BYTE $0

TIMERP0 = $A4
TIMERP1 = $A6

DLOADERROR:     .BYTE   $0
DSAVEERROR:     .BYTE   $0

