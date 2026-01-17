; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                    BANK ROUTINE ON MSX1 using ASCII-8 MAPPER                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; General read data from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (A000...BFFF)
; DE: destination memory address (C000...FFFF)
; BC: size of data to read (up to 8 KB)
BANKREADG:
BANKREADGB:
    LD ($7800), A
    LD (A8BANK), A
BANKREADGBHL1:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC BC
    LD A, B
    OR C
    JR NZ, BANKREADGBHL1
    RET

@IF bankAccessOptimization.read1

; Read 1 byte from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (A000...BFFF)
; DE: destination memory address (C000...FFFF)
BANKREAD1:
    LD BC, 1
    JR BANKREADG

@ENDIF

@IF bankAccessOptimization.read2

; Read 2 byteS from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (A000...BFFF)
; DE: destination memory address (C000...FFFF)
BANKREAD2:
    LD BC, 2
    JR BANKREADG

@ENDIF

@IF bankAccessOptimization.read4

; Read 4 bytes from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (A000...BFFF)
; DE: destination memory address (C000...FFFF)
BANKREAD4:
    LD BC, 4
    JR BANKREADG

@ENDIF

@IF bankAccessOptimization.readn

; Read N bytes from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (A000...BFFF)
; DE: destination memory address (C000...FFFF)
; BC: size to read
BANKREAD:
    JR BANKREADG

@ENDIF

; General write data to ASCII-8 from memory
; It is a NOP -- ASCII-8 is a ROM!
BANKWRITEG:
BANKWRITEGB:
    RET

@IF bankAccessOptimization.write1

; Write 1 byte from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (C000...FFFF)
; DE: destination memory address (A000...BFFF)
BANKWRITE1:
    LD BC, 1
    JR BANKWRITEG

@ENDIF

@IF bankAccessOptimization.write2

; Write 2 byteS from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (C000...FFFF)
; DE: destination memory address (A000...BFFF)
BANKWRITE2:
    LD BC, 2
    JR BANKWRITEG

@ENDIF

@IF bankAccessOptimization.write4

; Write 4 byte from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (C000...FFFF)
; DE: destination memory address (A000...BFFF)
BANKWRITE4:
    LD BC, 4
    JR BANKWRITEG

@ENDIF

@IF bankAccessOptimization.writen

; Write n bytes from ASCII-8 MAPPER to memory
; A: bank to use (4..)
; HL: source memory address (C000...FFFF)
; DE: destination memory address (A000...BFFF)
BANKWRITE1:
    JR BANKWRITEG

@ENDIF

