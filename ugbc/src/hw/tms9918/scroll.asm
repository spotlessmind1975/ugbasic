; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                              SCROLL ON TMS                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SCROLL(B,C)
SCROLL:
    LD A, 0
    LD (XSCROLL), A
    LD (YSCROLL), A

    LD A, C
    CP 0
    JR NZ, SCROLLY
    JMP SCROLLX
SCROLLY:
    CP $80
    JR C, SCROLLYUP
SCROLLYDOWN:
    LD A, (YSCROLLPOS)
    CP 7
    JR Z, SCROLLYDOWN0
    INC A
    LD (YSCROLLPOS), A
    JMP SCROLLX
SCROLLYDOWN0:
    LD A, 0
    LD (YSCROLLPOS), A
    LD A, $1
    LD (YSCROLL), A
    JMP SCROLLX
SCROLLYUP:
    LD A, (YSCROLLPOS)
    CP 0
    JR Z, SCROLLYUP0
    DEC A
    LD (YSCROLLPOS), A
    JMP SCROLLX
SCROLLYUP0:
    LD A, 7
    LD (YSCROLLPOS), A
    LD A, $FF
    LD (YSCROLL), A
    JMP SCROLLX

SCROLLX:
    LD A, B
    CP 0
    JR NZ, SCROLLXX
    JMP SCROLLN
SCROLLXX:
    CP $80
    JR C, SCROLLXLEFT
SCROLLXRIGHT:
    LD A, (XSCROLLPOS)
    CP 7
    JR Z, SCROLLXRIGHT0
    INC A
    LD (XSCROLLPOS), A
    JMP SCROLLN
SCROLLXRIGHT0:
    LD A, 0
    LD (XSCROLLPOS), A
    LD A, $1
    LD (XSCROLL), A
    JMP SCROLLN
SCROLLXLEFT:
    LD A, (XSCROLLPOS)
    CP 0
    JR Z, SCROLLXLEFT0
    DEC A
    LD (XSCROLLPOS), A
    JMP SCROLLN
SCROLLXLEFT0:
    LD A, 7
    LD (XSCROLLPOS), A
    LD A, $FF
    LD (XSCROLL), A
    JMP SCROLLN

SCREENSCROLLVOID:
    RET
    
SCREENSCROLL:
    RET

SCREENSCROLLEMBED:
    JMP SCREENSCROLL

SCROLLN:
    CALL SCREENSCROLLEMBED

    LD A, (XSCROLL)
    JR Z, SCROLLN2
    CP $80
    JR C, SCROLLNLEFT
SCROLLNRIGHT:
    LD A, 1
    LD (DIRECTION), A
    CALL HSCROLLST
    CALL ONSCROLLRIGHT
    JMP SCROLLN2

SCROLLNLEFT:
    LD A, $FF
    LD (DIRECTION), A
    CALL HSCROLLST
    CALL ONSCROLLLEFT
    JMP SCROLLN2

SCROLLN2:
    LD A, (YSCROLL)
    CP 0
    JR Z, SCROLLN3
    CP $80
    JR C, SCROLLNUP
    CALL VSCROLLTDOWN
    CALL ONSCROLLDOWN
    JMP SCROLLN3
SCROLLNUP:
    CALL VSCROLLTUP
    CALL ONSCROLLUP
    JMP SCROLLN3
SCROLLN3:
    RET

