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
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; <MATHPTR2...<MATHPTR3 holds the number

N2STRING
    LDY #0
    LDX #RESBUFFER

    LDB #10
    LDA #0
    DECB
NSSTRINGLC
    STA B,X
    DECB
    CMPB #$FF
    BNE NSSTRINGLC

    LDU #N2STRINGMASK
    LDB #0
N2STRINGL1
    ORCC #$01
    LDD <MATHPTR2
    SUBD , U
    STD <MATHPTR2
N2STRINGL1C
    ANDA #$80
    CMPA #0
    BNE N2STRINGF
    INC , X
    JMP N2STRINGL1

N2STRINGF
    ANDCC #$FE
    LDD <MATHPTR2
    ADDD , U
    STD <MATHPTR2

    CMPY #0
    BNE NSSTRINGL2
    LDB , X
    CMPB #0
    BEQ NSSTRINGL3

    LEAY 1, Y

NSSTRINGL2
    LDB , X
    ADDB #$30
    STB , X
    LEAX 1, X

NSSTRINGL3
    LEAU 2, U
    CMPU #N2STRINGMASKE
    BLE N2STRINGL1

    TFR X, D
    SUBD #RESBUFFER

    CMPB #0
    BNE NSSTRINGL3B

    PSHS B
    LDB , X
    ADDB #$30
    STB , X
    PULS B
    
    INCB
NSSTRINGL3B
    STB <MATHPTR5

    LDY <TMPPTR
    LDX #RESBUFFER

    LDA <MATHPTR4
    ANDA #$80
    BEQ NSSTRINGA

    LDA #'-'
    STA , Y
    LEAY 1, Y
    INC <MATHPTR5

NSSTRINGA
    DECB
NSSTRINGL4
    LDA B,X
    STA B,Y
    DECB
    CMPB #$FF
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