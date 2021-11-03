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
;*                      TEXT AT GIVEN POSITION ON ZX SPECTRUM                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTAT:
    LD A, (XCURS)
    LD E, A
    LD A, (YCURS)
    LD D, A
TEXTATL:
    LD A, (HL)
    INC HL
    CP 10
    JP C, TEXTATCC
    CP 32
    JP C, TEXTATL
    PUSH DE
    PUSH HL
    PUSH BC
    CALL TEXTATPC
    POP BC
    POP HL
    POP DE
    INC E
TEXTATNEXTCOLCHK:    
    LD A, E
    CP 32
    JP C, TEXTATNEXTCOL
    LD E, 0
    INC D
    LD A, D
    CP 24
    JP C, TEXTATNEXTCOL

TEXTATVSCROLL:
    DEC D

    PUSH DE
    PUSH HL
    PUSH BC

    LD A, $F8
    CALL VSCROLL

    POP BC
    POP HL
    POP DE
    JMP TEXTATNEXTCOL

TEXTATCC:
    CP 9
    JP Z, TEXTATTAB
    CP 1
    JP Z, TEXTATPEN
    CP 2
    JP Z, TEXTATPAPER
    CP 3
    JP Z, TEXTATCMOVE
    CP 4
    JP Z, TEXTATAT
    JMP TEXTATNEXTCOL

TEXTATTAB:
    LD A, E
TEXTATTABL:
    LD A, (TABCOUNT)
    LD B, A
    SBC A, B
    JP Z, TEXTATTABN
    JP M, TEXTATTABN
    JMP TEXTATTABL
TEXTATTABN:
    ADD A, B
    ADD A, E
    LD E, A
    CP 32
    JP C, TEXTATNEXTCOL
    LD E, 0
    INC D
    CP 24
    JP C, TEXTATNEXTCOL
    JMP TEXTATVSCROLL

TEXTATPEN:
    LD A, (HL)
    INC HL
    LD (_PEN), A
    JMP TEXTATNEXTCOL

TEXTATPAPER:
    LD A, (HL)
    INC HL
    LD (_PAPER), A
    JMP TEXTATNEXTCOL

TEXTATAT:
    LD A, (HL)
    INC HL
    LD E, A   
    LD A, (HL)
    INC HL
    LD D, A
    CP 24
    JP C, TEXTATAT2
    JMP TEXTATVSCROLL
TEXTATAT2:
    LD A, E
    CP 32
    JP C, TEXTATNEXTCOLCHK
    LD E, 0
    INC D
    CP 24
    JP C, TEXTATNEXTCOLCHK
    JMP TEXTATVSCROLL

TEXTATCMOVE:
    LD A, (HL)
    INC HL
    ADD A, E
    LD E, A
    LD A, (HL)
    INC HL
    ADD A, D
    LD D, A
    CP 24
    JP C, TEXTATCMOVE2
    JMP TEXTATVSCROLL
TEXTATCMOVE2:
    LD A, E
    CP 32
    JP C, TEXTATNEXTCOLCHK
    LD E, 0
    INC D
    CP 24
    JP C, TEXTATNEXTCOLCHK
    JMP TEXTATVSCROLL

TEXTATNEXTCOL:
    DEC C
    JP NZ, TEXTATL
    LD A, D
    LD (YCURS), A
    LD A, E
    LD (XCURS), A
    RET

TEXTATPC:
    PUSH AF
    PUSH DE
    LD HL, $5800
    LD A, D
    CP 0
    JP Z, TEXTATROW

TEXTATPC2:
    ADD HL, 32
    DEC D
    JP NZ, TEXTATPC2
TEXTATROW:
    LD A, E
    ADD HL, A
    POP DE
    LD A, (HL)
    AND $38
    LD B, A
    LD A, (TEXTWW)
    AND 1
    JP Z, TEXTATPC3
    LD A, (_PAPER)
    AND $07
    SLA A
    SLA A
    SLA A
    LD B, A
TEXTATPC3:
    LD A, (TEXTWW)
    AND 2
    JP Z, TEXTATPC4
    LD A, (_PEN)
    AND $07
    JMP TEXTATPC5
TEXTATPC4:
    LD A, (HL)
    AND $07
TEXTATPC5:
    OR A, B
    LD (HL), A

    POP AF
    LD HL, $3C00
    LD B,0
    LD C, A
    SLA C
    RL B
    SLA C
    RL B
    SLA C
    RL B
    ADD HL, BC
    CALL TEXTATGC
    LD B,8
TEXTATL1:
    LD A,(HL)
    LD (DE),A
    INC HL
    INC D
    DJNZ TEXTATL1
    RET
TEXTATGC:
    LD A,D
    AND %00000111
    RRA
    RRA
    RRA
    RRA
    OR E
    LD E,A
    LD A,D
    AND %00011000
    OR %01000000
    LD D,A
    RET

    