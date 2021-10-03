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
;*                DINAMYC STRING MANAGEMENT WITH GARBAGE COLLECTION            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; DSDEFINE(HL) -> B
DSDEFINE:
    CALL DSFINDFREE
    CALL DSDESCRIPTOR
    LD A, (HL)
    INC HL
    LD (IX),A
    LD (IX+1),L
    LD (IX+2),H
    LD A, $C0
    LD (IX+3),A
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
    JR Z, DSWRITED
    LD A, (IX+3)
    AND $7F
    LD (IX+3),A
    LD D, B
    CALL DSCHECKFREE
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
    RET

; DSGC()
DSGC:
    PUSH IX
    LD HL, FREE_STRING
    LD (HL), 0
    INC HL
    LD A, max_free_string
    LD (HL), A
    LD A, (USING)
    CMP 0
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
    JR NZ, DSGCLOOP2
    LD A, (IX+3)
    AND $40
    JR Z, DSGCLOOP2
    LD C, (IX+1)
    LD B, (IX+2)
    PUSH BC
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
    LD A, 0
    LD (IX), A
    JMP DSGCLOOP3
DSGCLOOP3:
    POP BC
    INC B
    JR NZ, DSGCLOOP
DSGCEND:
    LD A,(USING)
    XOR $FF
    LD (USING),A
    POP IX
    RET

; DSFINDFREE() -> B
DSFINDFREE:
    LD B, 1; // fix denote 0 as "unused slot"
DSFINDFREEL:
    CALL DSDESCRIPTOR
    LD A, (IX+3)
    AND $40
    JR Z, DSFINDFREEN
    INC B
    JR NZ, DSFINDFREEL
    JMP OUT_OF_MEMORY   
DSFINDFREEN:
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
    SUB HL, DE
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
    CALL DSGC
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

USING:                  DB    0
    
primo:                  DB 0
secondo:                DB 0