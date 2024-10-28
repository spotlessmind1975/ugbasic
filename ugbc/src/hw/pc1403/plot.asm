; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                            PLOT ROUTINE ON PC1403                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 3000-3039                  3079-3041
;         ------>                 <------
; |-----------------------||-----------------------|
; |7                      ||                       |
; |                       ...
; |0                      ||                       |
; |-----------------------||-----------------------|

; x,y
; if x > 63 then
;    px = &h3079 - x
; else
;    px = &h3000 + x
; endif
; py = 1 << sl(7-y)

; Calculate the position inside the LCD.
; Input:    I = x; J = y
; Ouput:    Y = address to write to (A=1); A = "OR" mask
CALCPOSG:

    ; if x > 63 then
    LP 0
    LDM
    CPIA 63
    JRCP CALCPOSG2

    ;    px = &h3079 - x
CALCPOSG1:
    ; save x
    EXAB

    ; A = &H79
    LIA 0x79
    LP 0x03
    EXAM

    ; restore x, B = &H79
    EXAB

    ; B = B(79) - A(x)
    LP 0x04
    SBM

    ; XL = A(79-x)
    LP 0x06
    EXAB
    EXAM

    ; XH = &H30
    LP 0x05
    LIA 0x30
    EXAM

    JP CALCPOSDONE

    ; else
    ;    px = &h3000 + x
CALCPOSG2:
    ; XL = A(x)
    LP 0x06
    EXAM

    ; XH = &H30
    LP 0x05
    LIA 0x30
    EXAM

    JP CALCPOSDONE

; endif
CALCPOSDONE:
    ; J = J - A
    ; A = 7-y
    LIB 7
    LP 1
    LDM
    SBM 

    CPIA 0
    JRZP CALCPOSDONE2

    ; J = A
    EXAM

    LIA 1

    JP CALCPOSDONE3

    ; A = 1 << sl(7-y)
CALCPOSDONEL1:
    SL
    DECJ
    JRNZM CALCPOSDONEL1
    
CALCPOSDONE2:
    LIA 1
CALCPOSDONE3:
    ; X = Y
    LIP 4
    LDM
    LIP 6
    EXAM
    LIP 5
    LDM
    LIP 7
    EXAM
    
    RTN

; Plot a point inside the LCD.
; Input:    I = x; J = y; A = mode
PLOT:

    CPIA 0
    JRZP PLOTE                  ;if = 0 then branch to clear the point
    CPIA 1
    JRZP PLOTD                  ;if = 1 then branch to draw the point
    CPIA 2
    JRZP PLOTG                  ;if = 2 then branch to get the point (0...3)
    CPIA 3
    JRZP PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JP PLOTP

PLOTE:
    JP PLOTP

PLOTD:
    CALL CALCPOSG
    IYS     
    JP PLOTP

PLOTG:
    JP PLOTP

PLOTC:
    JP PLOTP

PLOTP:
    RTN