; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                      CONVERT A NUMBER TO A STRING                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                     mc68089 optimizations by S.Devulder                     *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; input:
; <MATHPTR0...<MATHPTR3 holds the number
; <MATHPTR4 = sign
; A = number of bits
; X = result ptr

; output:
; A = string length

    LDD #9
NSSTRINGLC
    STA B,X
    DECB
    BGE NSSTRINGLC

    LDU #N2STRINGMASK
    LDD <MATHPTR2
N2STRINGL1
    SUBD ,U
    BMI N2STRINGF
    INC ,X
    BRA N2STRINGL1

N2STRINGF
    ADDD ,U

    LEAY ,Y
    BNE NSSTRINGL2
    TST ,X
    BEQ NSSTRINGL3
    LEAY 1,Y

NSSTRINGL2
    LEAX  1,X
    
NSSTRINGL3
    LEAU 2,U
    CMPU #N2STRINGMASKE
    BLE N2STRINGL1

    TFR X,D
    SUBD #RESBUFFER
    BNE NSSTRINGL3B

    STB ,X
    INCB

NSSTRINGL3B
    LDY <TMPPTR
    LDX #RESBUFFER

    LDA <MATHPTR4
    BPL NSSTRINGA

    LDA #'-'
    STA , Y+
    INCB

NSSTRINGA
    STB <MATHPTR5
NSSTRINGL4
    LDA ,X+
    ADDA #$30
    STA ,Y+
    DECB
    BNE NSSTRINGL4
    RTS

N2STRINGMASK
    fdb 10000
    fdb 1000
    fdb 100
    fdb 10
N2STRINGMASKE
    fdb 1

RESBUFFER  rzb    10
