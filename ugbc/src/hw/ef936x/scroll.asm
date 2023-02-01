; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                              SCROLL ON VIC-II                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ONSCROLLVOID
    RTS

ONSCROLLUP
    JMP ONSCROLLVOID

ONSCROLLDOWN
    JMP ONSCROLLVOID

ONSCROLLLEFT
    JMP ONSCROLLVOID

ONSCROLLRIGHT
    JMP ONSCROLLVOID

; SCROLL(MATHPTR0,MATHPTR1)
SCROLL
    LDA #0
    STA XSCROLL
    STA YSCROLL

    LDA MATHPTR1
    CMPA #0
    BNE SCROLLY
    JMP SCROLLX
SCROLLY
    CMPA #$80
    BCS SCROLLYUP
SCROLLYDOWN
    LDA YSCROLLPOS
    CMPA #7
    BEQ SCROLLYDOWN0
    INC YSCROLLPOS
    JMP SCROLLX
SCROLLYDOWN0
    LDA #0
    STA YSCROLLPOS
    LDA #$1
    STA YSCROLL
    JMP SCROLLX
SCROLLYUP
    LDA YSCROLLPOS
    CMPA #0
    BEQ SCROLLYUP0
    DEC YSCROLLPOS
    JMP SCROLLX
SCROLLYUP0
    LDA #7
    STA YSCROLLPOS
    LDA #$FF
    STA YSCROLL
    JMP SCROLLX

SCROLLX
    LDA MATHPTR0
    CMPA #0
    BNE SCROLLXX
    JMP SCROLLN
SCROLLXX
    CMPA #$80
    BCS SCROLLXLEFT
SCROLLXRIGHT
    LDA XSCROLLPOS
    CMPA #7
    BEQ SCROLLXRIGHT0
    INC XSCROLLPOS
    JMP SCROLLN
SCROLLXRIGHT0
    LDA #0
    STA XSCROLLPOS
    LDA #$1
    STA XSCROLL
    JMP SCROLLN
SCROLLXLEFT
    LDA XSCROLLPOS
    CMPA #0
    BEQ SCROLLXLEFT0
    DEC XSCROLLPOS
    JMP SCROLLN
SCROLLXLEFT0
    LDA #7
    STA XSCROLLPOS
    LDA #$FF
    STA XSCROLL
    JMP SCROLLN

SCREENSCROLLVOID
    RTS
    
SCREENSCROLL
    RTS

SCREENSCROLLEMBED
    JMP SCREENSCROLL

SCROLLN
    JSR SCREENSCROLLEMBED

    LDA XSCROLL
    BEQ SCROLLN2
    CMPA #$80
    BCS SCROLLNLEFT
SCROLLNRIGHT
    LDA #1
    STA DIRECTION
    JSR HSCROLLST
    JSR ONSCROLLRIGHT
    JMP SCROLLN2

SCROLLNLEFT
    LDA #$FF
    STA DIRECTION
    JSR HSCROLLST
    JSR ONSCROLLLEFT
    JMP SCROLLN2

SCROLLN2
    LDA YSCROLL
    BEQ SCROLLN3
    CMPA #$80
    BCS SCROLLNUP
    JSR VSCROLLTDOWN
    JSR ONSCROLLDOWN
    JMP SCROLLN3
SCROLLNUP
    JSR VSCROLLTUP
    JSR ONSCROLLUP
    JMP SCROLLN3
SCROLLN3
    RTS