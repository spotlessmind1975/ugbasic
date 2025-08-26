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
;*                            DLOAD ROUTINE ON C=64                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; DCOMMONP1 : filename; DCOMMON0: filename size
; DCOMMON1: 1 if address is NULL; 0 if address is not NULL
; DCOMMONP2: address
C64DLOAD:

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
    LDA DCOMMON0
    LDX DCOMMONP1
    LDY DCOMMONP1+1
    JSR SYSCALL

    ; SETLFS. Set file parameters.
    ; Input: A = Logical number; X = Device number; Y = Secondary address.
    ; Output: –
    ; Used registers: –
    ; Real address: $FE00.

    LDA #$01
    LDX $BA       ; last used device number
    BNE C64DLOADSKIP
    LDX #$08      ; default to device 8
C64DLOADSKIP:
    LDY DCOMMON1      ; not $01 means: load to address stored in file
    PHA
    LDA #$BA
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDY DCOMMON1
    BNE C64DLOADSKIP2

    LDX DCOMMONP2
    LDY DCOMMONP2+1

C64DLOADSKIP2:
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

    BCS C64DLOADERROR ; if carry set, a load error has happened
    RTS
C64DLOADERROR:
    ; Accumulator contains BASIC error code
    STA DLOADERROR
    RTS
