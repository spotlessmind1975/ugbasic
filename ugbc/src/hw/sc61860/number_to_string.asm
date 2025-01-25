; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from source code by Alwin Henseler on:
;  * https://www.msx.org/forum/development/msx-development/32-bit-long-ascii
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

; X = TMPPTR
; MATHPTR0 = $0c
; MATHPTR1 = $0d
; MATHPTR2 = $0e
; MATHPTR3 = $0f
; MATHPTR4 = $10
; MATHPTR5 = $11

N2STRING:
    ; JSR N2STRINGH2D
    CALL N2STRINGH2D
    ; LDX #9;
    LII 9
    ; LDY #0;
    LIJ 0
N2STRINGL1:
    ; LDA RESBUFFER,x
    PUSH
    LIP 0x06
    LIA RESBUFFER
    EXAM
    LIP 0x07
    LIA RESBUFFER
    EXAM
    LIA 0
    EXAB
    LIP 0
    LDM
    ADB
    POP
    LDD
    ; BNE N2STRINGL2
    CPIA 0
    JRNZP N2STRINGL2
    ; DEX
    DECI
    ; BNE N2STRINGL1
    JRNZM N2STRINGL1

N2STRINGL2:
    ; LDA MATHPTR4
    LIP 0x10
    LDM
    CPIA 0
    ; BEQ N2STRINGL2A
    JRZP N2STRINGL2A
    ; LDA #'-'
    LIA 45
    PUSH
    ; STA (TMPPTR),Y
    LIP 0x04
    LDM
    LIP 0x06
    EXAM
    LIP 0x05
    LDM
    LIP 0x07
    EXAM
    LIP 1
    LDM
    LIB 0
    LIP 0x06
    ADB
    POP
    DY
    IYS
    ; INY
    INCJ

N2STRINGL2A:
    ; LDA RESBUFFER,X
    PUSH
    LIP 0x04
    LIA RESBUFFER
    EXAM
    LIP 0x05
    LIA RESBUFFER
    EXAM
    LIA 0
    EXAB
    LIP 0
    LDM
    ADB
    POP
    LDD
    ; ORA #$30
    ORIA 0x30
    ; STA (TMPPTR),Y
    PUSH
    LIP 0x04
    LDM
    LIP 0x06
    EXAM
    LIP 0x05
    LDM
    LIP 0x07
    EXAM
    LIA 0
    EXAB
    LIP 1
    LDM
    ADB
    POP
    STD
    ; INY
    INCJ
    ; DEX
    DECI
    ; BPL N2STRINGL2A
    LIP 0
    EXAM
    CPIA 0xff
    JRNZM N2STRINGL2A
    JP N2STRINGEND

N2STRINGH2D:
    ; LDX #0
    LII 0
N2STRINGL3:
    ; JSR N2STRINGDIV10
    CALL N2STRINGDIV10
    ; STA RESBUFFER, X
    PUSH
    LIP 0x06
    LIA RESBUFFER
    EXAM
    LIP 0x07
    LIA RESBUFFER
    EXAM
    LIA 0
    EXAB
    LIP 0
    LDM
    ADB
    POP
    STD
    ; INX
    INCI
    ; BNE N2STRINGL3
    JRNZM N2STRINGL3
    RTN

N2STRINGDIV10:
    ; LDY #32
    LIJ 32
    ; LDA #0
    LIA 0
    ; CLC
    EXAB    
N2STRINGL4:
    EXAB
    ; ROL
    SL
    ; CMP #10
    CPIA 10
    ; BCC N2STRINGSSKIP
    JRNCP N2STRINGSSKIP
    ; SBC #10
    SBIA 10
N2STRINGSSKIP:
    EXAB
    ; ROL MATHPTR0
    LIP 0x0c
    EXAM
    SL
    EXAM
    ; ROL MATHPTR1
    LIP 0x0d
    EXAM
    SL
    EXAM
    ; ROL MATHPTR2
    LIP 0x0e
    EXAM
    SL
    EXAM
    ; ROL MATHPTR3
    LIP 0x0f
    EXAM
    SL
    EXAM
    ; DEY
    DECJ
    ; BPL N2STRINGL4
    LIP 1
    EXAM
    ANIA 0x80
    CPIA 0x80
    JRNZM N2STRINGL4
    EXAB
    RTN

N2STRINGEND:
    ; TYA
    LIP 0x01
    LDM
    ; STA MATHPTR5
    LIP 0x11
    EXAM
    ; RTS
    RTN

RESBUFFER:  .db    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
