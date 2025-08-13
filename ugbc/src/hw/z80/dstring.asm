; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                DINAMYC STRING MANAGEMENT WITH GARBAGE COLLECTION            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; DSEQUAL(IX=descriptor,HL=string) -> C / NC
DSEQUAL:
    PUSH BC
    PUSH DE
    PUSH HL
    LD A, (HL)
    LD B, A
    LD A, (IX)
    CP B
    JR NZ, DSEQUALNO
    INC HL
    LD A, (IX)
    LD B, A
    LD E, (IX+1)
    LD D, (IX+2)
DSEQUALL1:
    LD A, (DE)
    CP (HL)
    INC HL
    INC DE
    JR NZ, DSEQUALNO
    DEC B
    JR NZ, DSEQUALL1
DSEQUALYES:
    POP HL
    POP DE
    POP BC
    SCF
    RET
DSEQUALNO:
    POP HL
    POP DE
    POP BC
    SCF
    CCF
    RET

; DSFINDEQUAL(HL) -> B / 0
DSFINDEQUAL:
    LD B, 1
DSFINDEQUALL:
    CALL DSDESCRIPTOR
    LD A, (IX+3)
    AND $C0
    CP $C0
    JR Z, DSFINDEQUALF1
DSFINDEQUALF2:
    INC B
    LD A, B
    PUSH HL
	LD HL, MAXSTRINGS
    CP (HL)
    POP HL
    JR NZ, DSFINDEQUALL
DSFINDEQUALNO:
    LD B, 0
    RET
DSFINDEQUALF1:
    CALL DSEQUAL
    JR NC, DSFINDEQUALF2
DSFINDEQUALYES:
    RET

; DSDEFINE(HL) -> B
DSDEFINE:
    CALL DSFINDEQUAL
    LD A, B
    CP 0
    JR NZ, DSDEFINEE
    CALL DSFINDFREE
    CALL DSDESCRIPTOR
    LD A, (HL)
    INC HL
    LD (IX),A
    LD (IX+1),L
    LD (IX+2),H
    LD A, $C0
    LD (IX+3),A
DSDEFINEE:
    RET

; DSALLOC(C) -> B
DSALLOC:
    CALL DSFINDFREE
    CALL DSDESCRIPTOR
    LD A, (IX+3)
    OR A, $40
    LD (IX+3),A
    CALL DSCHECKFREE
DSALLOCOK:
    CALL DSUSING
    CALL DSMALLOC
    RET

; DSFREE(B)
DSFREE:
    CALL DSDESCRIPTOR
    LD A, 0
    LD (IX+3), A
    RET

; DSWRITE(B)
DSWRITE:
    CALL DSDESCRIPTOR
    LD A, (IX+3)
    AND $80
    CP $0
    JR Z, DSWRITED
    LD C, (IX)
    CALL DSCHECKFREE
    LD A, (IX+3)
    AND $7F
    LD (IX+3),A
    LD D, B
DSWRITEOK:
    LD C, (IX+1)
    LD B, (IX+2)
    PUSH BC
    CALL DSUSING
    LD C, (IX)
    LD B, D
    CALL DSMALLOC
    POP BC
    LD HL, BC
    LD E, (IX+1)
    LD D, (IX+2)
DSCOPY:
    LD C, (IX)
    LD A, C
    CP 0
    JR Z,DSWRITED
DSWRITECOPY:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC C
    JR NZ, DSWRITECOPY
DSWRITED:
    RET

; DSRESIZE(B,C)
DSRESIZE:
    CALL DSDESCRIPTOR
    LD A, C
    LD (IX), A    
    CP 0
    JR NZ, DSRESIZEDONE
    LD A, (IX+3)
    OR $80
    LD (IX+3), A
DSRESIZEDONE:
    RET

; DSGC()
DSGC:
    PUSH IX
    LD HL, FREE_STRING
    LD DE, max_free_string
    LD (HL), E
    INC HL
    LD (HL), D
    LD A, (USING)
    CP 0
    JR Z, DSGT
    JMP DSGW
DSGT:
    LD HL, TEMPORARY
    JMP BSGCLOOP0
DSGW:
    LD HL, WORKING
    JMP BSGCLOOP0
BSGCLOOP0:
    LD B, 1
DSGCLOOP:
    PUSH BC
    CALL DSDESCRIPTOR
    LD A, (IX+3)
    AND $80
    CP $0
    JR NZ, DSGCLOOP2
    LD A, (IX+3)
    AND $40
    CP $0
    JR Z, DSGCLOOP2
    LD A, (IX)
    CP 0
    JR Z, DSGCLOOP3
    LD A, B
    LD C, (IX+1)
    LD B, (IX+2)
    PUSH BC
    LD B, A
    LD C, (IX)
    CALL DSMALLOC
    POP BC
    LD E, (IX+1)
    LD D, (IX+2)
    PUSH HL
    LD HL, BC
    LD C, (IX)
    CALL DSWRITECOPY
    POP HL
    JMP DSGCLOOP3
DSGCLOOP2:
    ; LD A, 0
    ; LD (IX), A
    JMP DSGCLOOP3
DSGCLOOP3:
    POP BC
    INC B
    LD A, B
    LD DE, HL
	LD HL, MAXSTRINGS
    CP (HL)
    LD HL, DE
    JR NZ, DSGCLOOP
DSGCEND:
    LD A, (USING)
    XOR $FF
    LD (USING),A
    POP IX
    RET

; DSFINDFREE() -> B
DSFINDFREE:
    PUSH HL
    LD B, 1; // fix denote 0 as "unused slot"
DSFINDFREEL:
    CALL DSDESCRIPTOR
    LD A, (IX+3)
    AND $40
    CP $0
    JR Z, DSFINDFREEN
    INC B
    LD A, B
	LD HL, MAXSTRINGS
    CP (HL)
    JR NZ, DSFINDFREEL
    JMP OUT_OF_MEMORY   
DSFINDFREEN:
    POP HL
    RET

OUT_OF_MEMORY2:
    JMP OUT_OF_MEMORY

; DSMALLOC(HL,C,B)
DSMALLOC:
    CALL DSDESCRIPTOR
    PUSH HL
    LD A, 0
    LD D, A
    LD A, C
    LD E, A
    LD HL, (FREE_STRING)
    SBC HL, DE
    LD (FREE_STRING), HL
    PUSH HL
    POP DE
    POP HL
    PUSH HL
    ADD HL, DE
    LD (IX), C
    LD (IX+1), L
    LD (IX+2), H
    POP HL
    RET

; DSCHECKFREE()
DSCHECKFREE:
    PUSH AF
    PUSH BC
DSCHECKFREE2:
    LD A, (FREE_STRING+1)
    CP $80
    JR NC, DSCHECKFREEKO

    LD B, A
    LD A, 0
    CP B
    JR Z, DSCHECKFREEL2
    JR C, DSCHECKFREEOK
DSCHECKFREEL2:
    LD A, (FREE_STRING)
    LD B, A
    LD A, C
    CP B
    JR C, DSCHECKFREEOK

DSCHECKFREEKO:
    PUSH BC
    CALL DSGC
    POP BC
    JMP DSCHECKFREE2
DSCHECKFREEOK:
    POP BC
    POP AF
    RET

; DSUSING() -> HL
DSUSING:
    LD A, (USING)
    CP 0
    JR Z, DSUSINGW
    JR DSUSINGT
DSUSINGT:
    LD HL, TEMPORARY
    RET
DSUSINGW:
    LD HL, WORKING
    RET

; DSDESCRIPTOR(B) -> IX
DSDESCRIPTOR:
    PUSH HL
    PUSH BC
    LD A, B
    LD C, A
    LD A, 0
    LD B, A
    PUSH BC
    POP HL
    ADD HL, HL
    ADD HL, HL
    PUSH HL
    POP DE
    LD HL, DESCRIPTORS
    ADD HL, DE
    PUSH HL
    POP IX
    POP BC
    POP HL
    RET

OUT_OF_MEMORY:
    JMP OUT_OF_MEMORY

DSINIT:
    LD BC, stringscount*4+stringsspace*2
    LD A, 0
    LD HL, DESCRIPTORS
    LD DE, HL
    INC DE
    LD (HL), A
    LDIR
    LD A, stringscount
    LD (MAXSTRINGS), A
    LD DE, stringsspace
    LD (FREE_STRING), DE
    RET
