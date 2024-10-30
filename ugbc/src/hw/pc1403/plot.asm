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

; Calculate the position inside the LCD.
; Input:    K = x; L = y
; Ouput:    Y = address to write to; A = "OR" mask
CALCPOSG:
    LP 8
    LDM
    CPIA 63
    JRCP CALCPOSG2
CALCPOSG1:
    EXAB
    LIA 0x79
    LP 0x03
    EXAM
    EXAB
    LP 0x04
    SBM
    LP 0x06
    EXAB
    EXAM
    LP 0x05
    LIA 0x30
    EXAM
    JP CALCPOSDONE
CALCPOSG2:
    LP 0x06
    EXAM
    LP 0x05
    LIA 0x30
    EXAM
    JP CALCPOSDONE
CALCPOSDONE:
    LIB 7
    LP 9
    LDM
    LP 3
    SBM 
    EXAM
    CPIA 0
    JRZP CALCPOSDONE2
    LP 1
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
    PUSH
    LIP 6
    LDM
    LIP 4
    EXAM
    LIP 7
    LDM
    LIP 5
    EXAM
    POP 
    RTN

; Plot a point inside the LCD.
; Input:    K = x; L = y; A = mode
PLOT:
    CPIA 0
    JRZP PLOTE
    CPIA 1
    JRZP PLOTD
    CPIA 2
    JRZP PLOTG
    CPIA 3
    JRZP PLOTC
    JP PLOTP
PLOTE:
    JP PLOTP
PLOTD:
    CALL CALCPOSG
    EXAB
    DX
    IXL
    LP 3
    ORMA
    EXAB
    DY
    IYS     
    JP PLOTP
PLOTG:
    JP PLOTP
PLOTC:
    JP PLOTP
PLOTP:
    RTN
