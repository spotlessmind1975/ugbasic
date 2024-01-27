; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                            DSAVE ROUTINE ON C=64                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; TMPPTR : filename; MATHPTR0: filename size
; MATHPTR1: 1 if address is NULL; 0 if address is not NULL
; TMPPTR2: address
VIC20DSAVE:

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
    BNE VIC20DSAVESKIP
    LDX #$08      ; default to device 8
VIC20DSAVESKIP:
    LDY MATHPTR1      ; not $01 means: load to address stored in file
    PHA
    LDA #$BA
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA
    JSR SYSCALL

    LDY MATHPTR1
    BNE VIC20DSAVESKIP2

    LDX TMPPTR2
    LDY TMPPTR2+1

VIC20DSAVESKIP2:
    ; $FFD8 SAVEIO - Save memory to a device
    ; Description: This routine saves a section of memory. Memory is saved from 
    ;              an indirect address on page 0 specified by the accumulator to 
    ;              the address stored in the X and Y registers. It is then sent 
    ;              to a logical file on an input/output device. The SETLFS and 
    ;              SETNAM routines must be used before calling this routine. 
    ;              However, a file name is not required to SAVE to device 1 
    ;              (the Datassette™ recorder). Any attempt to save to other devices 
    ;              without using a file name results in an error.

    PHA
    LDA #$D8
    STA SYSCALL0+1
    LDA #$FF
    STA SYSCALL0+2
    PLA

    ; Load the X and Y registers with the low byte and high byte re- spectively of the location of the end of the save.

    CLC
    LDA TMPPTR2
    ADC MATHPTR4
    STA MATHPTR4
    LDA TMPPTR2+1
    ADC MATHPTR4+1
    STA MATHPTR4+1
    LDX MATHPTR4
    LDY MATHPTR4+1

    ; Load the accumulator with the single byte page zero offset to the pointer.
    
    LDA #TMPPTR2

    JSR SYSCALL

    BCS VIC20DSAVEERROR ; if carry set, a load error has happened
    RTS
VIC20DSAVEERROR:
    ; Accumulator contains BASIC error code
    STA DSAVEERROR
    RTS
