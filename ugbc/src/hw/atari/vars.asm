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
;*                      INTERNAL VARIABLES FOR ATARI TARGET                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
KBDCHAR:      .BYTE   $ff
KBDRATE:      .BYTE   16
KBDDELAY:      .BYTE   32
KBDDELAYCT:    .BYTE   0

KBDRATEC:      .BYTE   16
KBDDELAYC:      .BYTE   32
TICKSPERSECOND: .BYTE   0

TMPPTR = $80    ; $81
TMPPTR2 = $82    ; $83

MATHPTR0 = $8B
MATHPTR1 = $84
MATHPTR2 = $85
MATHPTR3 = $86
MATHPTR4 = $87
MATHPTR5 = $88
MATHPTR6 = $89
MATHPTR7 = $8A

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

; ----------------------------------------------------------------------------
; FLOATING POINT ZERO PAGED REGISTERS
; ----------------------------------------------------------------------------
; --- FIRST FP REGISTER (FP1) --- 
FP1X: .byte $00
FP1M: .byte $00, $00, $00
; --- SECOND FP REGISTER (FP1) --- 
FP2X: .byte $00
FP2M: .byte $00, $00, $00
; --- FIRST SCRATCH FP REGISTER (FS1) --- 
FS1X: .byte $00
FS1M: .byte $00, $00, $00
; --- SECOND SCRATCH FP REGISTER (FS2) --- 
FS2X: .byte $00
FS2M: .byte $00, $00, $00
; ----------------------------------------------------------------------------

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

@IF deployed.timer

TIMERP0 = $A4
TIMERP1 = $A6

TIMERRUNNING:   .BYTE   $0
TIMERSTATUS:    .BYTE   $0
TIMERCOUNTER:   .WORD   $0, $0, $0, $0, $0, $0, $0, $0
TIMERINIT:      .WORD   $0, $0, $0, $0, $0, $0, $0, $0
TIMERADDRESS:   .WORD   $0, $0, $0, $0, $0, $0, $0, $0

@ENDIF

DLOADERROR:     .BYTE   $0
DSAVEERROR:     .BYTE   $0
