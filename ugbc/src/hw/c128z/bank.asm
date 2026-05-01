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
;*                           BANK ROUTINE ON C=128 using geoRAM                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

GEORAMBANK          EQU $DFFF
GEORAMPAGE          EQU $DFFE
GEORAMSWAP          EQU $DE00

GEORAMSETBANK:
    PUSH BC
    LD BC, GEORAMBANK
    OUT (C), A
    POP BC
    RET

GEORAMSETPAGE:
    PUSH BC
    LD BC, GEORAMPAGE
    OUT (C), A
    POP BC
    RET

GEORAMWRITEBYTE:
    PUSH BC
    LD BC, DE
    OUT (C), A
    POP BC
    RET

GEORAMREADBYTE:
    PUSH BC
    LD BC, HL
    IN A, (C)
    POP BC
    RET

; General read data from geoRAM to memory
; HL: source memory address (0...16KB)
; DE: destination memory address (0...64KB)
; BC: size of data to read (up to 16KB)
BANKREADG:
    ; First of all, reset the source address from expanded
    ; memory, since we are going to refer to it in a relative way.
BANKREADGB:
    LD A, 42
    CALL GEORAMSETBANK
    LD (GEORAMBANKSHADOW), A
    LD A, H
    CALL GEORAMSETPAGE
    LD (GEORAMPAGESHADOW), A

    LD A, 42
    PUSH HL
    PUSH DE
    LD DE, GEORAMSWAP
    LD H, 0
    ADD HL, DE
    POP DE
BANKREADGBHL1:
BANKREADGBHL2:
    CALL GEORAMREADBYTE
    LD (DE), A
    DEC BC
    LD A, B
    OR C
    CP 0
    JR Z, BANKREADGBHDONE
    INC HL
    INC DE
    LD A, L
    CP 0
    JR NZ, BANKREADGBNSKIPPAGE
    LD A, (GEORAMPAGESHADOW)
    INC A
    LD (GEORAMPAGESHADOW), A
    CALL GEORAMSETPAGE
BANKREADGBNSKIPPAGE:
    JP BANKREADGBHL1

BANKREADGBHDONE:
    RET

@IF bankAccessOptimization.read1

; Read 1 byte from geoRAM to memory
; A : bank
; HL: source memory address
; DE: destination memory address
BANKREAD1:
    LD (BANKREADGB+1), A
    LD BC, 1
    JP BANKREADG

@ENDIF

@IF bankAccessOptimization.read2

; Read 2 byte(s) from geoRAM to memory
; A : bank
; HL: source memory address
; DE: destination memory address
BANKREAD2:
    LD (BANKREADGB+1), A
    LD BC, 2
    JP BANKREADG

@ENDIF

@IF bankAccessOptimization.read4

; Read 4 byte(s) from geoRAM to memory
; A : bank
; HL: source memory address
; DE: destination memory address
BANKREAD4:
    LD (BANKREADGB+1), A
    LD BC, 4
    JP BANKREADG

@ENDIF

@IF bankAccessOptimization.readn

; Read n byte(s) from geoRAM to memory
; A : bank
; HL: source memory address
; DE: destination memory address
; BC: size
BANKREAD:
    LD (BANKREADGB+1), A
    LD A, B
    OR C
    CP 0
    JR Z, BANKREADX
    JP BANKREADG
BANKREADX:
    RET

@ENDIF

; General write data to geoRAM from memory
; HL: source memory address (0...64KB)
; DE: destination memory address (0...16KB)
; BC: size of data to read (up to 16KB)
BANKWRITEG:
    ; First of all, reset the source address from expanded
    ; memory, since we are going to refer to it in a relative way.
BANKWRITEGB:
    LD A, 42
    CALL GEORAMSETBANK
    LD (GEORAMBANKSHADOW), A
    LD A, D
    CALL GEORAMSETPAGE
    LD (GEORAMPAGESHADOW), A

    LD D, 0
    ADD DE, GEORAMSWAP
BANKWRITEGBHL1:
BANKWRITEGBHL2:
    LD A, (HL)
    CALL GEORAMWRITEBYTE
    DEC BC
    LD A, B
    OR C
    CP 0
    JR Z, BANKWRITEGBHDONE
    INC HL
    INC DE
    LD A, L
    CP 0
    JR NZ, BANKWRITEGBNSKIPPAGE
    LD A, (GEORAMPAGESHADOW)
    INC A
    LD (GEORAMPAGESHADOW), A
    CALL GEORAMSETPAGE
BANKWRITEGBNSKIPPAGE:
    JP BANKWRITEGBHL1

BANKWRITEGBHDONE:
    RET

@IF bankAccessOptimization.write1

; Write 1 byte(s) to geoRAM from memory
; A : bank
; HL: source memory address
; DE: destination memory address
BANKWRITE1:
    LD (BANKWRITEGB+1), A
    LD BC, 1
    JP BANKWRITEG

@ENDIF

@IF bankAccessOptimization.write2

; Write 2 byte(s) to geoRAM from memory
; A : bank
; HL: source memory address
; DE: destination memory address
BANKWRITE2:
    LD (BANKWRITEGB+1), A
    LD BC, 2
    JP BANKWRITEG

@ENDIF

@IF bankAccessOptimization.write4

; Write 4 byte(s) to geoRAM from memory
; A : bank
; HL: source memory address
; DE: destination memory address
BANKWRITE4:
    LD (BANKWRITEGB+1), A
    LD BC, 4
    JP BANKWRITEG

@ENDIF

@IF bankAccessOptimization.writen

; Write n byte(s) to geoRAM from memory
; A : bank
; TMPPTR: source memory address
; TMPPTR2: destination memory address
; MATHPTR0-MATHPTR1: size
BANKWRITE:
    LD (BANKWRITEGB+1), A
    LD A, B
    OR C
    JR Z, BANKWRITEX
    JP BANKWRITEG
BANKWRITEX:
    RET

@ENDIF
