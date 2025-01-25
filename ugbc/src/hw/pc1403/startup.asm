; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;*                          STARTUP ROUTINE FOR PC1403                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PC1403STARTUP:

    RTN

; Calculate the position inside the LCD.
; Input:    K = x; L = y
; Ouput:    Y = address to write to; A = "OR" mask
;
; REGION 1 : 00 ... 29     -> x'
; REGION 2 : 30 ... 44     -> x' = x + 15
; REGION 3 : 45 ... 59     -> x' = x - 15
; REGION 4 : 60 ... 74     -> x' = 108 - ( x - 60 )
; REGION 5 : 75 ... 89     -> x' = 123 - ( x - 75 )
; REGION 6 : 90 ... 104    -> x' = 93 - ( x - 90 )

CALCPOSG:
    LIP 8
    LDM
    LIP 3
    CPIA 90
    JRNCP CALCPOSGR6
    CPIA 75
    JRNCP CALCPOSGR5
    CPIA 60
    JRNCP CALCPOSGR4
    CPIA 45
    JRNCP CALCPOSGR3
    CPIA 30
    JRNCP CALCPOSGR2
    
    ; REGION 1 : 00 ... 29     -> A = x
CALCPOSGR1:
    JP CALCPOSGY

    ; REGION 6 : 90 ... 104    -> A = 93 - ( x - 90 )
CALCPOSGR6:
    EXAB
    LIA 90
    SBM
    LIA 93
    EXAB
    SBM
    EXAB
    JP CALCPOSGY

    ; REGION 5 : 75 ... 89     -> A = 123 - ( x - 75 )
CALCPOSGR5:
    EXAB
    LIA 75
    SBM
    LIA 123
    EXAB
    SBM
    EXAB
    JP CALCPOSGY

    ; REGION 4 : 60 ... 74     -> A = 108 - ( x - 60 )
CALCPOSGR4:
    EXAB
    LIA 60
    SBM
    LIA 108
    EXAB
    SBM
    EXAB
    JP CALCPOSGY

    ; REGION 3 : 45 ... 59     -> A = x - 15
CALCPOSGR3:
    EXAB
    LIA 15
    SBM
    EXAB
    JP CALCPOSGY

    ; REGION 2 : 30 ... 44     -> x = x + 15
CALCPOSGR2:
    EXAB
    LIA 15
    ADM
    EXAB
    JP CALCPOSGY

CALCPOSGY:
    LIP 0x06
    EXAM
    LIP 0x07
    LIA 0x30
    EXAM

    ; LIB 7
    LIP 9
    LDM
    ; LP 3
    ; SBM 
    ; EXAM
    CPIA 0
    JRZP CALCPOSDONE2
    LIP 1
    EXAM
    LIA 1
CALCPOSDONEL1:
    SL
    DECJ
    JRNZM CALCPOSDONEL1
    JP CALCPOSDONE3
CALCPOSDONE2:
    LIA 1
CALCPOSDONE3:
    RTN
