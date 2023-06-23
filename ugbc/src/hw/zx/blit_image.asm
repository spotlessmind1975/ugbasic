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
;*                          IMAGES ROUTINE FOR ZX SPECTRUM                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

BLITIMAGEBLITTING:
	JP (HL)

BLITIMAGE:
    
    DI

    LD A, (IMAGEY)
    LD (IMAGEY2), A

;     LD A, (CURRENTMODE)
;     ; BITMAP_MODE_STANDARD
;     CP 0
;     JR NZ, BLITIMAGE0X
;     JMP BLITIMAGE0
; BLITIMAGE0X:
;     ; TILEMAP_MODE_STANDARD
;     CP 1
;     JR NZ, BLITIMAGE1X
;     JMP BLITIMAGE1
; BLITIMAGE1X:
;     RET

; BLITIMAGE1:
;     RET

BLITIMAGE0:
BLITIMAGE1:
    LD A, (HL)
    LD (IMAGEW), A
    ADD HL, 1
    LD A, (HL)
    SRL A
    SRL A
    SRL A
    LD (IMAGEH), A
    LD (IMAGEH2), A
    ADD HL, 1

    PUSH HL

    DI
    EXX
    EI

    ADD HL, 2

    DI
    EXX
    EI

    ; LD A, (IMAGEX)
    ; AND $7
    ; LD B, A
    ; LD A, $8
    ; SUB B
    ; LD B, A
    ; LD E, 1
; BLITIMAGE0A:
;     DEC B
;     JR Z,BLITIMAGE0B
;     SLA E
;     JMP BLITIMAGE0A

BLITIMAGE0B:
    LD A, (IMAGEY)
    LD B, A
    LD A, (IMAGEX)
    LD C, A

    LD A,B
    AND %00000111
    OR %01000000
    LD H,A
    LD A,B
    RRA
    RRA
    RRA
    AND %00011000
    OR H
    LD H,A
    LD A,B
    RLA
    RLA
    AND %11100000
    LD L,A
    LD A,C
    RRA
    RRA
    RRA
    AND %00011111
    OR L
    LD L,A

    PUSH HL
    POP DE
    POP HL

    ; LD A, (IMAGEY)
    ; LD IXL, A

    LD A, (IMAGEH)
    LD C, A
    SLA C
    SLA C
    SLA C
    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD B, A
BLITIMAGE0CP:

    PUSH BC
    
    ; SOURCE
    LD A, (HL)
    LD B, A

    ; DESTINATION
    LD A, (DE)
    LD IYL, A

    PUSH IY

    DI
    EXX
    EI

    POP IY

    ; MASK
    LD A, (HL)
    LD IYH, A

    PUSH DE
    PUSH IY

    DI
    EXX
    EI

    POP IY
    POP IX
    PUSH HL
    PUSH IX
    POP HL

    CALL BLITIMAGEBLITTING

    POP HL

    LD (DE), A

    INC HL
    INC DE

    DI
    EXX
    EI

    INC HL

    DI
    EXX
    EI

    POP BC

    DEC B
    JR NZ, BLITIMAGE0CP
    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD B, A

    PUSH BC
    PUSH HL
    
    ; INC IXL
    ; LD A, IXL
    LD A, (IMAGEY)
    LD B, A
    INC B
    LD A, B
    LD (IMAGEY), A
    LD A, (IMAGEX)
    LD C, A

    LD A,B
    AND %00000111
    OR %01000000
    LD H,A
    LD A,B
    RRA
    RRA
    RRA
    AND %00011000
    OR H
    LD H,A
    LD A,B
    RLA
    RLA
    AND %11100000
    LD L,A
    LD A,C
    RRA
    RRA
    RRA
    AND %00011111
    OR L
    LD L,A

    PUSH HL
    POP DE
    POP HL

    POP BC

    DEC C
    JR NZ, BLITIMAGE0CP

    ;;;;

    LD A, (IMAGET)
    AND $2
    CMP $0
    JP Z, BLITDONE

    LD A, (IMAGEY2)
    LD (IMAGEY), A

    PUSH HL

    LD A,(IMAGEX)
    LD L,A
    LD A,0
    LD H,A
    AND A
    SRA H
    RR L
    SRA H
    RR L
    SRA H
    RR L
    LD DE,HL

    LD A,(IMAGEY)
    AND $f8
    LD L,A
    LD A,0
    LD H,A
    AND A
    SLA L
    RL H
    SLA L
    RL H
    ADD HL,DE
    LD DE,(COLORMAPADDRESS)
    ADD HL,DE

    PUSH HL

    POP DE
    POP HL

    LD A, (IMAGEH)
    LD C, A
    ; INC C
    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD B, A

BLITIMAGE00CP:

    PUSH BC

    ; SOURCE
    LD A, (HL)
    LD B, A

    ; DESTINATION
    LD A, (DE)
    LD IYL, A

    PUSH IY

    DI
    EXX
    EI

    POP IY

    ; MASK
    LD A, (HL)
    LD IYH, A

    PUSH DE
    PUSH IY

    DI
    EXX
    EI

    POP IY
    POP IX
    PUSH HL
    PUSH IX
    POP HL

    CALL BLITIMAGEBLITTING

    POP HL

    LD (DE), A

    INC HL
    INC DE

    DI
    EXX
    EI

    INC HL

    DI
    EXX
    EI

    POP BC

    DEC B
    JR NZ, BLITIMAGE00CP

    PUSH BC

    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD C, A
    LD A, 0
    LD B, A

    PUSH HL
    LD HL, DE
    ADD HL, 32
    AND A
    SBC HL, BC
    LD DE, HL
    POP HL

    POP BC

    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD B, A
    DEC C
    JR NZ, BLITIMAGE00CP

BLITDONE:

    EI

    RET

