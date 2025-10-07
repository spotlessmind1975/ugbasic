; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
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
;*                           BANK ROUTINE ON C=64 using geoRAM                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; General read data from geoRAM to memory
; TMPPTR: source memory address (0...16KB)
; TMPPTR2: destination memory address (0...64KB)
; MATHPTR01: size of data to read (up to 16KB)
BANKREADG:
    ; First of all, reset the source address from expanded
    ; memory, since we are going to refer to it in a relative way.
BANKREADGB:
    LDA #0
    STA GEORAMBANK
    STA GEORAMBANKSHADOW
    LDA TMPPTR+1
    STA GEORAMPAGE
    STA GEORAMPAGESHADOW

    ; Then, calculate the offset of the heading block to read.
    ;      +--- starting address on geoRAM's block (lo byte of address)
    ; |-y--v
    ; +----|-----+----------+----------+----------+....
    ; |    |     .          .          .          .
    ; +----+-----+----------+----------+----------+....
    ; |    |- x -|  <-- x = 256 - y is the number of bytes 
    ; |--- 256 --|      to copy from start of the block
    ;
    ; Skip head copying if reading from the beginning of a block.
    ;
    SEC
    LDA #$00
    SBC TMPPTR
    STA MATHPTR2
    BEQ BANKREADSKIPHEAD

    ; Copy head of the block.

BANKREADGBHL1:
    TAY
    LDA TMPPTR
    TAX
BANKREADGBHL2:
    LDA GEORAMSWAP, X
    STA (TMPPTR2), Y
    INX
    INY
    BNE BANKREADGBHL2

    ; After copying the bytes, reduce the number of bytes to copy...
    SEC
    LDA MATHPTR0
    SBC MATHPTR2
    STA MATHPTR0
    LDA MATHPTR1
    SBC #$0
    STA MATHPTR1

    ; ... and move the pointer forward.

    CLC
    LDA TMPPTR2
    ADC MATHPTR2
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC MATHPTR2
    STA TMPPTR2+1

    ; Move to the next page.
    INC GEORAMPAGESHADOW
    STA GEORAMPAGE

BANKREADSKIPHEAD:

    ; Now check if more blocks must be copied.

    LDA MATHPTR1
    BEQ BANKREADSKIPMIDDLE

BANKREADGBML1:
    LDY #0
    LDX #0
BANKREADGBML2:
    LDA GEORAMSWAP, X
    STA (TMPPTR2), Y
    INX
    INY
    BNE BANKREADGBML2

    DEC MATHPTR1

    ; ... and move the pointer forward.

    CLC
    LDA TMPPTR2
    ADC MATHPTR2
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1

    ; Move to the next page.
    INC GEORAMPAGESHADOW
    STA GEORAMPAGE

    JMP BANKREADSKIPHEAD

BANKREADSKIPMIDDLE:

    ; Now check if tail block must be copied.

    LDA MATHPTR0
    BEQ BANKREADSKIPTAIL

    ; Then, calculate the offset of the heading block to read.
    ;                       +--- starting copy from here
    ;                       V-y-| bytes to copy
    ; +----|-----+----------+---|------+----------+....
    ; |    |     .          .   |      .          .
    ; +----+-----+----------+---+------+----------+....
    ;

BANKREADGBTL1:
    LDY #0
    LDX #0
BANKREADGBTL2:
    LDA GEORAMSWAP, X
    STA (TMPPTR2), Y
    INX
    INY
    CPY MATHPTR0
    BNE BANKREADGBTL2

BANKREADSKIPTAIL:

    RTS

; Read 1 byte from geoRAM to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKREAD1:
    STA BANKREADGB+1
    LDA #1
    STA MATHPTR0
    LDA #0
    STA MATHPTR1
    JMP BANKREADG

; Read 2 byte(s) from geoRAM to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKREAD2:
    STA BANKREADGB+1
    LDA #2
    STA MATHPTR0
    LDA #0
    STA MATHPTR1
    JMP BANKREADG

; Read 4 byte(s) from geoRAM to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKREAD4:
    STA BANKREADGB
    LDA #4
    STA MATHPTR0
    LDA #0
    STA MATHPTR1
    JMP BANKREADG

; Read n byte(s) from geoRAM to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
; MATHPTR0-MATHPTR1: size
BANKREAD:
    STA BANKREADGB+1
    LDA MATHPTR0
    ORA MATHPTR1
    BEQ BANKREADX
    JMP BANKREADG
BANKREADX:
    RTS
    
; General write data to geoRAM from memory
; TMPPTR: source memory address (0...64KB)
; A : bank
; TMPPTR2: destination memory address (0...16KB)
; MATHPTR01: size of data to read
BANKWRITEG:
BANKWRITEGB:
    LDA #0
    STA GEORAMBANK
    STA GEORAMBANKSHADOW
    LDA TMPPTR2+1
    STA GEORAMPAGE
    STA GEORAMPAGESHADOW

    ; Then, calculate the offset of the heading block to read.
    ;      +--- starting address on geoRAM's block (lo byte of address)
    ; |-y--v
    ; +----|-----+----------+----------+----------+....
    ; |    |     .          .          .          .
    ; +----+-----+----------+----------+----------+....
    ; |    |- x -|  <-- x = 256 - y is the number of bytes 
    ; |--- 256 --|      to copy from start of the block
    ;
    ; Skip head copying if reading from the beginning of a block.
    ;
    SEC
    LDA #$00
    SBC TMPPTR2
    STA MATHPTR2
    BEQ BANKWRITESKIPHEAD

    ; Copy head of the block.

BANKWRITEGBHL1:
    TAY
    LDA TMPPTR2
    TAX
BANKWRITEGBHL2:
    LDA (TMPPTR), Y
    STA GEORAMSWAP, X
    INX
    INY
    BNE BANKWRITEGBHL2

    ; After copying the bytes, reduce the number of bytes to copy...
    SEC
    LDA MATHPTR0
    SBC MATHPTR2
    STA MATHPTR0
    LDA MATHPTR1
    SBC #$0
    STA MATHPTR1

    ; ... and move the pointer forward.

    CLC
    LDA TMPPTR
    ADC MATHPTR2
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Move to the next page.
    INC GEORAMPAGESHADOW
    STA GEORAMPAGE

BANKWRITESKIPHEAD:

    ; Now check if more blocks must be copied.

    LDA MATHPTR1
    BEQ BANKWRITESKIPMIDDLE

BANKWRITEGBML1:
    LDY #0
    LDX #0
BANKWRITEGBML2:
    LDA (TMPPTR), Y
    STA GEORAMSWAP, X
    INX
    INY
    BNE BANKWRITEGBML2

    DEC MATHPTR1

    ; ... and move the pointer forward.

    CLC
    LDA TMPPTR
    ADC MATHPTR2
    STA TMPPTR
    LDA TMPPTR+1
    ADC MATHPTR2
    STA TMPPTR+1

    ; Move to the next page.
    INC GEORAMPAGESHADOW
    STA GEORAMPAGE

    JMP BANKWRITESKIPHEAD

BANKWRITESKIPMIDDLE:

    ; Now check if tail block must be copied.

    LDA MATHPTR0
    BEQ BANKWRITESKIPTAIL

    ; Then, calculate the offset of the heading block to read.
    ;                       +--- starting copy from here
    ;                       V-y-| bytes to copy
    ; +----|-----+----------+---|------+----------+....
    ; |    |     .          .   |      .          .
    ; +----+-----+----------+---+------+----------+....
    ;

BANKWRITEGBTL1:
    LDY #0
    LDX #0
BANKWRITEGBTL2:
    LDA (TMPPTR), Y
    STA GEORAMSWAP, X
    INX
    INY
    CPY MATHPTR0
    BNE BANKWRITEGBTL2

BANKWRITESKIPTAIL:

    RTS

; Write 1 byte(s) to geoRAM from memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKWRITE1:
    STA BANKWRITEGB+1
    LDA #1
    STA MATHPTR0
    LDA #0
    STA MATHPTR1
    JMP BANKWRITEG

; Write 2 byte(s) to geoRAM from memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKWRITE2:
    STA BANKWRITEGB+1
    LDA #2
    STA MATHPTR0
    LDA #0
    STA MATHPTR1
    JMP BANKWRITEG

; Write 4 byte(s) to geoRAM from memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKWRITE4:
    STA BANKWRITEGB
    LDA #4
    STA MATHPTR0
    LDA #0
    STA MATHPTR1
    JMP BANKWRITEG

; Write n byte(s) to geoRAM from memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
; MATHPTR0-MATHPTR1: size
BANKWRITE:
    STA BANKWRITEGB+1
    LDA MATHPTR0
    ORA MATHPTR1
    BEQ BANKWRITEX
    JMP BANKWRITEG
BANKWRITEX:
    RTS
