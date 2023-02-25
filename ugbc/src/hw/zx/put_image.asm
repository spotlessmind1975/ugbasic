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

PUTIMAGE:
    
    DI

;     LD A, (CURRENTMODE)
;     ; BITMAP_MODE_STANDARD
;     CP 0
;     JR NZ, PUTIMAGE0X
;     JMP PUTIMAGE0
; PUTIMAGE0X:
;     ; TILEMAP_MODE_STANDARD
;     CP 1
;     JR NZ, PUTIMAGE1X
;     JMP PUTIMAGE1
; PUTIMAGE1X:
;     RET

; PUTIMAGE1:
;     RET

PUTIMAGE0:
PUTIMAGE1:
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

    LD A, (IMAGEX)
    AND $7
    LD B, A
    LD A, $8
    SUB B
    LD B, A
    LD E, 1
PUTIMAGE0A:
    DEC B
    JR Z,PUTIMAGE0B
    SLA E
    JMP PUTIMAGE0A
PUTIMAGE0B:
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

    LD A, (IMAGEH)
    LD C, A
    SLA C
    SLA C
    SLA C
    INC C
    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD B, A
PUTIMAGE0CP:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, PUTIMAGE0CP
    LD A, (IMAGEW)
    SRL A
    SRL A
    SRL A
    LD B, A

    PUSH BC
    PUSH HL
    
    LD A, (IMAGEY)
    ADD A, 1
    LD (IMAGEY), A
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

    POP BC

    DEC C
    JR NZ, PUTIMAGE0CP

    ;;;;

    PUSH HL

    LD HL,(IMAGEX)
    SRA H
    RR L
    SRA H
    RR L
    SRA H
    RR L
    LD DE,HL

    LD HL,(IMAGEY)
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
    INC C
    LD A, (IMAGEW)
    LD B, A
PUTIMAGE00CP:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, PUTIMAGE00CP

    PUSH BC

    LD A, (IMAGEW)
    LD C, A
    LD A, 0
    LD B, A

    ADD HL, 64
    SBC HL, BC

    POP BC

    LD A, (IMAGEW)
    LD B, A
    DEC C
    JR NZ, PUTIMAGE00CP

    EI

    RET

