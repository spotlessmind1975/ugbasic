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
;*                           BANK ROUTINE ON C=64 + REU                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; General read data from REU to memory
; TMPPTR: source memory address
; TMPPTR2: destination memory address
; MATHPTR01: size of data to read
BANKREADG:
    ; First of all, reset the source address from expanded
    ; memory, since we are going to refer to it in a relative way.
BANKREADGB:
    LDA #0
    STA REUREUBASE+2
    LDA TMPPTR
    STA REUREUBASE
    LDA TMPPTR+1
    STA REUREUBASE+1

    ; Then, reset the destination address to the auxiliary area
    ; with the space for the header, that is the first thing we read.
    LDA TMPPTR2
    STA REUC64BASE
    LDA TMPPTR2+1
    STA REUC64BASE+1

    ; Set the legth of the header and read it.
BANKREADG0:
    LDA #0
    STA REUTRANSLEN
BANKREADG1:
    LDA #0
    STA REUTRANSLEN+1

    LDA #0
    STA REUCONTROL
    LDA #%10010001
    STA REUCOMMAND

    RTS

; Read 1 byte from REU to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKREAD1:
    STA BANKREADGB+1
    LDA #1
    STA BANKREADG0+1
    LDA #0
    STA BANKREADG1+1
    JMP BANKREADG

; Read 2 byte(s) from REU to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKREAD2:
    STA BANKREADGB+1
    LDA #2
    STA BANKREADG0+1
    LDA #0
    STA BANKREADG1+1
    JMP BANKREADG

; Read 4 byte(s) from REU to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
BANKREAD4:
    STA BANKREADGB
    LDA #4
    STA BANKREADG0+1
    LDA #0
    STA BANKREADG1+1
    JMP BANKREADG

; Read n byte(s) from REU to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
; MATHPTR0-MATHPTR1: size
BANKREAD:
    STA BANKREADGB+1
    LDA MATHPTR0
    STA BANKREADG0+1
    LDA MATHPTR1
    STA BANKREADG1+1
    JMP BANKREADG

; General write data to REU from memory
; TMPPTR: source memory address
; A : bank
; TMPPTR2: destination memory address
; MATHPTR01: size of data to read
BANKWRITEG:
    ; First of all, reset the source address from expanded
    ; memory, since we are going to refer to it in a relative way.
BANKWRITEGB:
    LDA #0
    STA REUREUBASE+2
    LDA TMPPTR2
    STA REUREUBASE
    LDA TMPPTR2+1
    STA REUREUBASE+1

    ; Then, reset the destination address to the auxiliary area
    ; with the space for the header, that is the first thing we read.
    LDA TMPPTR
    STA REUC64BASE
    LDA TMPPTR+1
    STA REUC64BASE+1

    ; Set the legth of the header and read it.
BANKWRITEG0:
    LDA #0
    STA REUTRANSLEN
BANKWRITEG1:
    LDA #0
    STA REUTRANSLEN+1

    LDA #0
    STA REUCONTROL
    LDA #%10010000
    STA REUCOMMAND
    
    RTS

; Write 1 byte from REU to memory
; TMPPTR: source memory address
; A : bank
; TMPPTR2: destination memory address
BANKWRITE1:
    STA BANKWRITEGB+1
    LDA #1
    STA BANKWRITEG0+1
    LDA #0
    STA BANKWRITEG1+1
    JMP BANKWRITEG

; Read 2 byte(s) from REU to memory
; TMPPTR: source memory address
; A : bank
; TMPPTR2: destination memory address
BANKWRITE2:
    STA BANKWRITEGB+1
    LDA #2
    STA BANKWRITEG0+1
    LDA #0
    STA BANKWRITEG1+1
    JMP BANKWRITEG

; Read 4 byte(s) from REU to memory
; TMPPTR: source memory address
; A : bank
; TMPPTR2: destination memory address
BANKWRITE4:
    STA BANKWRITEGB+1
    LDA #4
    STA BANKWRITEG0+1
    LDA #0
    STA BANKWRITEG1+1
    JMP BANKWRITEG

; Read n byte(s) from REU to memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
; MATHPTR0-MATHPTR1: size
BANKWRITE:
    STA BANKWRITEGB+1
    LDA MATHPTR0
    STA BANKWRITEG0+1
    LDA MATHPTR1
    STA BANKWRITEG1+1
    JMP BANKWRITEG

