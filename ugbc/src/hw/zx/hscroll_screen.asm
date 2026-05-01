; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                          HSCROLL FOR ZX SPECTRUM                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                           HORIZONTAL SCREEN SCROLL ON ZX                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLSCREEN:
    PUSH AF
    CALL CALCULATECOLOR
    LD A, IXH
    LD IYH, A
    POP AF

    CP $80
    JP C, HSCROLLSCREENR

HSCROLLSCREENL:
    LD A, (CONSOLEY1)
    LD B, A
    LD A, (CONSOLEX1)
    LD D, A
    LD C, D
    LD A, (CONSOLEWB)
    LD D, A
    LD A, (CONSOLEHB)
    SRL A
    SRL A
    SRL A
    LD H, A
    LD E, H
    LD A, E
    OR A
    RET Z
    LD A, D
    OR A
    RET Z
    SUB 2
    INC A
    EX AF, AF'
    PUSH IX
    LD IXL, E
    LD L, B
    LD H, 0
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD A, L
    ADD A, C
    LD L, A
    LD DE, 22528
    ADD HL, DE
HSCROLLSCREENLL1:
    PUSH BC
    PUSH HL
    LD A, B
    AND %00011000
    LD H, A
    LD A, B
    AND %00000111
    RRCA
    RRCA
    RRCA
    ADD A, C
    LD L, A
    LD DE, 16384
    ADD HL, DE
    LD B, 0
    EX AF, AF'
    LD IXH, 7
HSCROLLSCREENLL2:
    PUSH HL
    JR C, HSCROLLSCREENLL3
    LD D, H
    LD E, L
    INC HL
    LD C, A
    LDIR 
    EX DE, HL
HSCROLLSCREENLL3:
    LD (HL), B
    POP HL
    INC H
    DEC IXH
    JP NZ, HSCROLLSCREENLL2
    JR C, HSCROLLSCREENLL4
    LD D, H
    LD E, L
    INC HL
    LD C, A
    LDIR
    EX DE, HL
HSCROLLSCREENLL4:
    LD (HL), B
    POP HL
    JR C, HSCROLLSCREENLL5
    LD D, H
    LD E, L
    INC HL
    LD C, A
    PUSH DE
    LDIR
    DEC HL
    LD B, IYH
    LD (HL), B
    LD B, 0
    POP HL
HSCROLLSCREENLL5:
    EX AF, AF'
    LD DE, 32
    ADD HL, DE
    POP BC
    INC B
    DEC IXL
    JP NZ, HSCROLLSCREENLL1
    POP IX
    RET

HSCROLLSCREENR:
    LD A, (CONSOLEY1)
    LD B, A
    LD A, (CONSOLEHB)
    SRL A
    SRL A
    SRL A
    LD H, A
    LD A, (CONSOLEX1)
    LD D, A
    LD A, (CONSOLEWB)
    ADD A, D
    DEC A
    LD C, A
    LD A, (CONSOLEWB)
    LD D, A
    LD E, H
    LD A, E
    OR A
    RET Z
    LD A, D
    OR A
    RET Z
    SUB 2
    INC A
    EX AF, AF'
    PUSH IX
    LD IXL, E
    LD L, B
    LD H, 0
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD A, L
    ADD A, C
    LD L, A
    LD DE, 22528
    ADD HL, DE
HSCROLLSCREENRL1:
    PUSH BC
    PUSH HL
    LD A, B
    AND %00011000
    LD H, A
    LD A, B
    AND %00000111
    RRCA
    RRCA
    RRCA
    ADD A, C
    LD L, A
    LD DE, 16384
    ADD HL, DE
    LD B, 0
    EX AF, AF'
    LD IXH, 7    
HSCROLLSCREENRL2:
    PUSH HL
    JR C, HSCROLLSCREENRL3
    LD D, H
    LD E, L
    DEC HL
    LD C, A
    LDDR
    EX DE, HL
HSCROLLSCREENRL3:
    LD (HL), B
    POP HL
    INC H
    DEC IXH
    JP NZ, HSCROLLSCREENRL2
    JR C, HSCROLLSCREENRL4
    LD D, H
    LD E, L
    DEC HL
    LD C, A
    LDDR
    EX DE, HL
HSCROLLSCREENRL4:
    LD (HL), B
    POP HL
    JR C, HSCROLLSCREENRL5
    LD D, H
    LD E, L
    DEC HL
    LD C, A
    PUSH DE
    LDDR
    INC HL
    LD B, IYH
    LD (HL), B
    LD B, 0
    POP HL    
HSCROLLSCREENRL5:
    EX AF, AF'
    LD DE, 32
    ADD HL, DE
    POP BC
    INC B
    DEC IXL
    JP NZ, HSCROLLSCREENRL1
    POP IX
    RET
