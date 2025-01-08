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
;*                            PLOT ROUTINE ON PC1403                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Plot a point inside the LCD.
; Input:    K = x; L = y; A = mode
PLOT:

@IF optionClip
    PUSH
    LIDP CLIPX1
    LII 0x00
    LP 0x03
    MVWD
    LIP 8
    LDM
    LIP 3
    CPMA
    JRZP PLOTNOCLIPPEDX2
    JRCP PLOTNOCLIPPEDX2
    POP
    RTN
PLOTNOCLIPPEDX2:
    LIDP CLIPX2
    LII 0x00
    LP 0x03
    MVWD
    LIP 8
    LDM
    LIP 3
    CPMA
    JRNCP PLOTNOCLIPPEDY1
    POP
    RTN
PLOTNOCLIPPEDY1:
    LIDP CLIPY1
    LII 0x00
    LP 0x03
    MVWD
    LIP 9
    LDM
    LIP 3
    CPMA
    JRZP PLOTNOCLIPPEDY2
    JRCP PLOTNOCLIPPEDY2
    POP
    RTN
PLOTNOCLIPPEDY2:
    LIDP CLIPY2
    LII 0x00
    LP 0x03
    MVWD
    LIP 9
    LDM
    LIP 3
    CPMA
    JRNCP PLOTNOCLIPPEDOK
    POP
    RTN
PLOTNOCLIPPEDOK:
    POP

@ENDIF

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

    EXAB
    DX
    IXL
    LIP 3
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
