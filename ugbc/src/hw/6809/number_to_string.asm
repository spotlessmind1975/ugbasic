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

; MATHPTR0...MATHPTR3 holds the number

N2STRING
    JSR N2STRINGH2D

    LDU #0
    LDX #RESBUFFER
    LDB #9
    LDY TMPPTR
N2STRINGL1
    LDA B, X
    BNE N2STRINGL2
    DECB
    BNE N2STRINGL1
N2STRINGL2
    LDA MATHPTR4
    CMPA #0
    BEQ N2STRINGL2A
    LDA #'-'
    STA ,Y
    LEAY 1, Y
N2STRINGL2A
    LDA B,X
    ORA #$30
    STA ,Y
    LEAY 1, Y
    LEAU 1, U
    DECB
    BGE N2STRINGL2A

    TFR U, D
    STB MATHPTR5
    RTS

N2STRINGH2D
    PSHS A,X,B,CC
    JSR N2STRINGSETDIVIDEND
    LDX #RESBUFFER
    LDB #0
N2STRINGL3
    JSR NSSTRINGDIV10
    LDA NSMODULUS+3
    STA B, X
    INCB
    CMPB #10
    BNE N2STRINGL3
    PULS A,X,B,CC
    RTS

NSSTRINGDIV10
    PSHS B,CC
    JSR N2STRINGCHECKDIVIDEND
    CMPA #0
    BEQ NSSTRINGDIV10D
    JSR N2STRINGINITQUOTIENT
    JSR N2STRINGPUSHDIVIDEND
    ; A >> 4 
    LDB #4
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 5 [ A >> 4 >> 1 ]
    ; JSR N2STRINGAB
    LDB #1
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 8 [ A >> 5 >> 3 ]
    ; JSR N2STRINGAB
    LDB #3
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 9 [ A >> 8 >> 1 ]
    ; JSR N2STRINGAB
    LDB #1
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 12 [ A >> 9 >> 3 ]
    ; JSR N2STRINGAB
    LDB #3
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 13 [ A >> 12 >> 1 ]
    ; JSR N2STRINGAB
    LDB #1
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 16 [ A >> 13 >> 3 ]
    ; JSR N2STRINGAB
    LDB #3
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 17 [ A >> 16 >> 1 ]
    ; JSR N2STRINGAB
    LDB #1
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    ; A >> 19 [ A >> 17 >> 2 ]
    ; JSR N2STRINGAB
    LDB #2
    JSR N2STRINGDIVIDEBYB
    JSR N2STRINGSUMDIVIDENDTOQUOTIENT
    JSR N2STRINGCOPYQUOTIENT

    ; A x 10 = A x 2 x 2 x 2 + A x 2
    LDB #3
    JSR N2STRINGMULCOPYQUOTIENT
    JSR N2STRINGSUMQUOTIENTONCOPY
    JSR N2STRINGSUMQUOTIENTONCOPY

    JSR N2STRINGPOPDIVIDEND

    ; NSMODULUS
    JSR NSSTRINGMODULUS

    JSR N2STRINGQUOTENTONDIVIDEND

    PULS B,CC
    RTS

NSSTRINGDIV10D
    JSR NSSTRINGCOPYDIVIDEND2MODULUS
    JSR NSSTRINGDIVIDEND0
    PULS B,CC
    RTS

N2STRINGSETDIVIDEND
    LDD MATHPTR0
    STD NSDIVIDEND
    LDD MATHPTR2
    STD NSDIVIDEND+2
    RTS

N2STRINGPUSHDIVIDEND
    LDD NSDIVIDEND
    STD NSDIVIDENDS
    LDD NSDIVIDEND+2
    STD NSDIVIDENDS+2
    RTS

N2STRINGPOPDIVIDEND
    LDD NSDIVIDENDS
    STD NSDIVIDEND
    LDD NSDIVIDENDS+2
    STD NSDIVIDEND+2
    RTS

N2STRINGSUMDIVIDENDTOQUOTIENT
    LDD NSDIVIDEND
    ADDD NSQUOTIENT
    STD NSQUOTIENT
    LDD NSDIVIDEND+2
    ADDD NSQUOTIENT+2
    STD NSQUOTIENT+2
    RTS

N2STRINGDIVIDEBYB
    ANDCC #$FE
    LSR NSDIVIDEND
    ROR NSDIVIDEND+1
    ROR NSDIVIDEND+2
    ROR NSDIVIDEND+3
    DECB
    BNE N2STRINGDIVIDEBYB
    RTS

N2STRINGCOPYQUOTIENT
    LDD NSQUOTIENT
    STD NSCQUOTIENT
    LDD NSQUOTIENT+2
    STD NSCQUOTIENT+2
    RTS

N2STRINGMULCOPYQUOTIENT
    LSL NSCQUOTIENT+3
    LSL NSCQUOTIENT+2
    LSL NSCQUOTIENT+1
    LSL NSCQUOTIENT
    DECB
    BNE N2STRINGMULCOPYQUOTIENT
    RTS

N2STRINGSUMQUOTIENTONCOPY
    LDD NSQUOTIENT
    ADDD NSCQUOTIENT
    STD NSCQUOTIENT
    LDD NSQUOTIENT+2
    ADDD NSCQUOTIENT+2
    STD NSCQUOTIENT+2
    RTS

NSSTRINGMODULUS
    ANDCC #$FE
    LDD NSDIVIDEND+2
    SUBD NSCQUOTIENT+2
    STD NSMODULUS+2
    LDD NSDIVIDEND
    SUBD NSCQUOTIENT
    STD NSMODULUS
    RTS

N2STRINGQUOTENTONDIVIDEND
    LDD NSQUOTIENT
    STD NSDIVIDEND
    LDD NSQUOTIENT+2
    STD NSDIVIDEND+2
    RTS

N2STRINGINITQUOTIENT
    LDD #0
    STD NSQUOTIENT
    LDD #1
    STD NSQUOTIENT+2
    RTS

NSSTRINGCOPYDIVIDEND2MODULUS
    LDD NSDIVIDEND
    STD NSMODULUS
    LDD NSDIVIDEND+2
    STD NSMODULUS+2
    RTS
    
N2STRINGCHECKDIVIDEND
    LDA #0
N2STRINGCHECKDIVIDEND0
    CMPA NSDIVIDEND
    BNE N2STRINGCHECKDIVIDEND1
    CMPA NSDIVIDEND+1
    BNE N2STRINGCHECKDIVIDEND1
    CMPA NSDIVIDEND+2
    BNE N2STRINGCHECKDIVIDEND1
    LDA NSDIVIDEND+3
    CMPA #10
    BGE N2STRINGCHECKDIVIDEND1
    LDD #0
    RTS
N2STRINGCHECKDIVIDEND1
    LDA #1
    RTS

NSSTRINGDIVIDEND0
    LDD #0
    STD NSDIVIDEND
    STD NSDIVIDEND+2
    RTS

NSDIVIDEND  rzb     4
NSQUOTIENT  rzb     4
NSCQUOTIENT rzb     4
NSMODULUS   rzb     4
NSDIVIDENDS rzb     4

RESBUFFER  rzb    10