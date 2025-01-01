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
;*                         PLOT ROUTINE FOR ZX SPECTRUM                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOT:

@IF optionClip

    LD A, (CLIPX1)
    LD B, A
    LD A, (CLIPX2)
    LD D, A
    LD A, H
    CMP B
    JP C, PLOTCLIPPED
    CMP D
    JP Z, PLOTNOCLIPPED
    JP NC, PLOTCLIPPED
PLOTNOCLIPPED:
    LD A, (CLIPY1)
    LD B, A
    LD A, (CLIPY2)
    LD D, A
    LD A, L
    CMP B
    JP C, PLOTCLIPPED
    CMP D
    JR Z, PLOTNOCLIPPED2
    JP NC, PLOTCLIPPED
PLOTNOCLIPPED2: 

@ENDIF

    LD A, H
    AND $7
    LD B, A
    LD A, $8
    SUB B
    LD B, A
    LD E, 1
PLOTLOOP: 
    DEC B
    JR Z, PLOTLOOP2
    SLA E
    JMP PLOTLOOP
PLOTLOOP2:
    PUSH HL
    LD A, L
    LD B, A
    LD A, H
    LD C, A
    LD A,B
    AND %00000111
    OR %01000000
    LD H, A
    LD A, B
    RRA
    RRA
    RRA
    AND %00011000
    OR H
    LD H, A
    LD A, B 
    RLA
    RLA
    AND %11100000
    LD L, A
    LD A, C
    RRA
    RRA
    RRA
    AND %00011111
    OR L
    LD L, A

    LD A, (PLOTCPE)
    LD B, A
    LD A, (_PAPER)
    CP B
    JR Z, PLOTRESET

PLOTSET:
    LD A, (HL)
    OR E
    LD (HL),A

    POP BC

    LD A, H
    AND $18
    RRCA
    RRCA
    RRCA
    OR $58
    LD H, A

    LD A, (_PEN)
    AND $07
    LD B, A
    LD A, (HL)
    AND $F8
    OR A, B
    LD (HL), A
    RET

PLOTRESET:
    LD A, E
    XOR $FF
    LD B, A
    LD A, (HL)
    AND B
    LD (HL),A

    POP BC

    LD A, H
    AND $18
    RRCA
    RRCA
    RRCA
    OR $58
    LD H, A

    LD A, (_PAPER)
    AND $07
    SLA A
    SLA A
    SLA A
    OR A, B
    LD (HL), A
    RET


PLOTCLIPPED:
    RET

PLOTG:

@IF optionClip

    LD A, (CLIPX1)
    LD B, A
    LD A, (CLIPX2)
    LD D, A
    LD A, H
    CMP B
    JP C, PLOTGCLIPPED
    CMP D
    JP Z, PLOTGNOCLIPPED
    JP NC, PLOTGCLIPPED
PLOTGNOCLIPPED:
    LD A, (CLIPY1)
    LD B, A
    LD A, (CLIPY2)
    LD D, A
    LD A, L
    CMP B
    JP C, PLOTGCLIPPED
    CMP D
    JR Z, PLOTGNOCLIPPED2
    JR NC, PLOTGCLIPPED
PLOTGNOCLIPPED2: 

@ENDIF

    LD A, H
    AND $7
    LD B, A
    LD A, $8
    SUB B
    LD B, A
    LD E, 1
PLOTGLOOP: 
    DEC B
    JR Z, PLOTGLOOP2
    SLA E
    JMP PLOTGLOOP
PLOTGLOOP2:
    PUSH HL
    LD A, L
    LD B, A
    LD A, H
    LD C, A
    LD A,B
    AND %00000111
    OR %01000000
    LD H, A
    LD A, B
    RRA
    RRA
    RRA
    AND %00011000
    OR H
    LD H, A
    LD A, B 
    RLA
    RLA
    AND %11100000
    LD L, A
    LD A, C
    RRA
    RRA
    RRA
    AND %00011111
    OR L
    LD L, A

    LD A, (HL)
    AND E

    POP BC

    PUSH AF

    LD A, H
    AND $18
    RRCA
    RRCA
    RRCA
    OR $58
    LD H, A

    POP AF

    CP 0
    JR Z, PLOTGBACK

PLOTGFORE:
    LD A, (HL)
    AND $7
    RET

PLOTGBACK:
    LD A, (HL)
    SRL A
    SRL A
    SRL A
    AND $7
    RET

PLOTGCLIPPED:
    RET