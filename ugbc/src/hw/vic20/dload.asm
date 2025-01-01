; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                            DLOAD ROUTINE ON VIC20                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; TMPPTR : filename; MATHPTR0: filename size
; MATHPTR1: 1 if address is NULL; 0 if address is not NULL
; TMPPTR2: address
VIC20DLOAD:

    ; SETNAM. Set file name parameters.
    ; Input: A = File name length; X/Y = Pointer to file name.
    ; Output: –
    ; Used registers: –
    ; Real address: $FDF9.

    PHA
    LDA #$BD
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    LDA MATHPTR0
    LDX TMPPTR
    LDY TMPPTR+1
    JSR SYSCALL

    ; SETLFS. Set file parameters.
    ; Input: A = Logical number; X = Device number; Y = Secondary address.
    ; Output: –
    ; Used registers: –
    ; Real address: $FE00.

    LDA #$01
    LDX $BA       ; last used device number
    BNE VIC20DLOADSKIP
    LDX #$08      ; default to device 8
VIC20DLOADSKIP:
    LDY MATHPTR1      ; not $01 means: load to address stored in file
    PHA
    LDA #$BA
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDY MATHPTR1
    BNE VIC20DLOADSKIP2

    LDX TMPPTR2
    LDY TMPPTR2+1

VIC20DLOADSKIP2:
    ; LOAD. Load or verify file. (Must call SETLFS and SETNAM beforehands.)
    ; Input: A: 0 = Load, 1-255 = Verify; X/Y = Load address (if secondary address = 0).
    ; Output: Carry: 0 = No errors, 1 = Error; A = KERNAL error code (if Carry = 1); X/Y = Address of last byte loaded/verified (if Carry = 0).
    ; Used registers: A, X, Y.
    ; Real address: $F49E.

    PHA
    LDA #$D5
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    LDA #$00      ; $00 means: load to memory (not verify)
    JSR SYSCALL

    BCS VIC20DLOADERROR ; if carry set, a load error has happened
    RTS
VIC20DLOADERROR:
    ; Accumulator contains BASIC error code
    STA DLOADERROR
    RTS
