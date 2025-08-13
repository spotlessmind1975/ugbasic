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

; DSEQUAL(DX=descriptor,SI=string) -> C / NC
DSEQUAL:
    ; PUSH BC
    ; PUSH DE
    ; PUSH HL
    PUSH AX
    PUSH DI
    PUSH SI
    ; LD A, (HL)
    ; LD B, A
    ; LD A, (IX)
    ; CP B
    MOV AL, [SI]
    CMP AL, [DX]
    ; JR NZ, DSEQUALNO
    JNZ DSEQUALNO
    ; INC HL
    INC SI
    ; LD A, (IX)
    ; LD B, A
    MOV CL, [DX]
    ; LD E, (IX+1)
    ; LD D, (IX+2)
    MOV DI, [DX+1]
DSEQUALL1:
    REPE CMPSB
    ; LD A, (DE)
    ; CP (HL)
    ; INC HL
    ; INC DE
    ; JR NZ, DSEQUALNO
    JNZ DSEQUALNO
    ; DEC B
    ; JR NZ, DSEQUALL1
DSEQUALYES:
    ; POP HL
    ; POP DE
    ; POP BC
    PUSH SI
    PUSH DI
    PUSH AX
    ; SCF
    STC
    ; RET
    RET
DSEQUALNO:
    ; POP HL
    ; POP DE
    ; POP BC
    PUSH SI
    PUSH DI
    PUSH AX
    ; SCF
    ; CCF
    CLC
    ; RET
    RET

; DSFINDEQUAL(SI) -> BL / 0
DSFINDEQUAL:
    ; LD B, 1
    MOV BL, 1
DSFINDEQUALL:
    CALL DSDESCRIPTOR
    ; LD A, (IX+3)
    MOV AL, [DX+3]
    ; AND $C0
    AND AL, 0xc0
    ; CP $C0
    CMP AL, 0xc0
    ; JR Z, DSFINDEQUALF1
    JZ DSFINDEQUALF1
DSFINDEQUALF2:
    ; INC B
    INC BL
    ; LD A, B
    ; PUSH HL
	; LD HL, MAXSTRINGS
    ; CP (HL)
    ; POP HL
    CMP BL, [MAXSTRINGS]
    ; JR NZ, DSFINDEQUALL
    JNZ DSFINDEQUALL
DSFINDEQUALNO:
    ; LD B, 0
    MOV BL, 0
    ; RET
    RET
DSFINDEQUALF1:
    CALL DSEQUAL
    ; JR NC, DSFINDEQUALF2
    JNC DSFINDEQUALF2
DSFINDEQUALYES:
    RET

; DSDEFINE(SI) -> BL
DSDEFINE:
    CALL DSFINDEQUAL
    ; LD A, B
    ; CP 0
    CMP BL, 0
    ; JR NZ, DSDEFINEE
    JNZ DSDEFINEE
    CALL DSFINDFREE
    CALL DSDESCRIPTOR
    ; LD A, (HL)
    MOV AL, [SI]
    ; INC HL
    INC SI
    ; LD (IX),A
    MOV [DX], AL
    ; LD (IX+1),L
    ; LD (IX+2),H
    MOV [DX+1], SI
    ; LD A, $C0
    ; LD (IX+3),A
    MOV [DX+3], 0xc0
DSDEFINEE:
    RET

; DSALLOC(CL) -> BL
DSALLOC:
    CALL DSFINDFREE
    CALL DSDESCRIPTOR
    MOV AL, [DX+3]
    ; LD A, (IX+3)
    ; OR A, $40
    OR AL, 0x40
    ; LD (IX+3),A
    MOV [DX+3], AL
    CALL DSCHECKFREE
DSALLOCOK:
    CALL DSUSING
    CALL DSMALLOC
    RET

; DSFREE(BL)
DSFREE:
    CALL DSDESCRIPTOR
    ; LD A, 0
    ; LD (IX+3), A
    MOV [DX+3], 0
    RET

; DSWRITE(BL)
DSWRITE:
    CALL DSDESCRIPTOR
    ; LD A, (IX+3)
    MOV AL, [DX+3]
    ; AND $80
    AND AL, 0x80
    ; CP $0
    CMP AL, 0
    ; JR Z, DSWRITED
    JZ, DSWRITED
    ; LD C, (IX)
    MOV CL, [DX]
    CALL DSCHECKFREE
    ; LD A, (IX+3)
    MOV AL, [DX+3]
    ; AND $7F
    AND AL, 0x7f
    ; LD (IX+3),A
    MOV [DX+3], AL
    ; LD D, B
    MOV DL, BL
DSWRITEOK:
    ; LD C, (IX+1)
    ; LD B, (IX+2)
    MV BX, [DX+1]
    ; PUSH BC
    PUSH BX
    CALL DSUSING
    ; LD C, (IX)
    MOV CL, [DX]
    ; LD B, D
    MOV BL, DL
    CALL DSMALLOC
    ; POP BC
    POP BX
    ; LD HL, BC
    MOV SI, BX
    ; LD E, (IX+1)
    ; LD D, (IX+2)
    MOV DI, [DX+1]
DSCOPY:
    ; LD C, (IX)
    MOV CL, [DX]
    ; LD A, C
    CMP CL, 0
    ; JR Z,DSWRITED
    JZ DSWRITED
DSWRITECOPY:
    ; LD A, (HL)
    ; LD (DE), A
    ; INC HL
    ; INC DE
    ; DEC C
    ; JR NZ, DSWRITECOPY
    REPE MOVSB
DSWRITED:
    RET

; DSRESIZE(BL,CL)
DSRESIZE:
    CALL DSDESCRIPTOR
    ; LD A, C
    ; LD (IX), A    
    MOV [DX], CL
    ; CP 0
    CMP CL, 0
    ; JR NZ, DSRESIZEDONE
    JNZ DSRESIZEDONE
    ; LD A, (IX+3)
    ; OR $80
    ; LD (IX+3), A
    MOV AL, [DX+3]
    OR AL, 0x80
    MOV [DX+3], AL
DSRESIZEDONE:
    RET

; DSGC()
DSGC:
    ; PUSH IX
    PUSH DX
    ; LD HL, FREE_STRING
    MOV SI, FREE_STRING
    ; LD DE, max_free_string
    MOV [SI], max_free_string
    ; LD (HL), E
    ; INC HL
    ; LD (HL), D
    ; LD A, (USING)
    MOV AL, [USING]
    ; CP 0
    CMP AL, 0
    ; JR Z, DSGT
    JZ DSGT
    ; JMP DSGW
    JP DSGW
DSGT:
    ; LD HL, TEMPORARY
    MOV SI, TEMPORARY
    JP BSGCLOOP0
DSGW:
    ; LD HL, WORKING
    MOV SI, WORKING
    ; JMP BSGCLOOP0
    JP BSGCLOOP0
BSGCLOOP0:
    ; LD B, 1
    MOV BL, 1
DSGCLOOP:
    ; PUSH BC
    PUSH BX
    CALL DSDESCRIPTOR
    ; LD A, (IX+3)
    MOV AL, [DX+3]
    ; AND $80
    AND AL, 0x80
    ; CP $0
    CMP AL, 0
    ; JR NZ, DSGCLOOP2
    JNZ DSGCLOOP2
    ; LD A, (IX+3)
    MOV AL, [DX+3]
    ; AND $40
    AND AL, 0x40
    ; CP $0
    CMP AL, 0x00
    ; JR Z, DSGCLOOP2
    JZ DSGCLOOP2
    ; LD A, (IX)
    MOV AL, [DX]
    ; CP 0
    CMP AL, 0
    ; JR Z, DSGCLOOP3
    JZ DSGCLOOP3
    ; LD A, B
    MOV AL, BL
    ; LD C, (IX+1)
    ; LD B, (IX+2)
    NOV BX, [DX+1]
    ; PUSH BC
    PUSH BX
    ; LD B, A
    MOV BL, AL
    ; LD C, (IX)
    MOV CL, [DX]
    CALL DSMALLOC
    ; POP BC
    POP BX
    ; LD E, (IX+1)
    ; LD D, (IX+2)
    MOV DI, [IX+1]
    ; PUSH HL
    PUSH SI
    ; LD HL, BC
    MOV SI, BX
    ; LD C, (IX)
    MOV XL, [IX]
    CALL DSWRITECOPY
    ; POP HL
    POP SI
    ; JMP DSGCLOOP3
    JP DSGCLOOP3
DSGCLOOP2:
    JP DSGCLOOP3
DSGCLOOP3:
    ; POP BC
    POP BX
    ; INC B
    INC BL
    ; LD A, B
    ; LD DE, HL
	; LD HL, MAXSTRINGS
    ; CP (HL)
    CMP BL, [MAXSTRINGS]
    ; LD HL, DE
    ; JR NZ, DSGCLOOP
    JNZ DSGCLOOP
DSGCEND:
    ; LD A, (USING)
    ; XOR $FF
    ; LD (USING),A
    MOV AL, [USING]
    XOR AL, 0xff
    MOV [USING], AL
    ; POP IX
    POP DX
    RET

; DSFINDFREE() -> BL
DSFINDFREE:
    ; PUSH HL
    PUSH SI
    ; LD B, 1; // fix denote 0 as "unused slot"
    MOV BL, 1
DSFINDFREEL:
    CALL DSDESCRIPTOR
    ; LD A, (IX+3)
    MOV AL, [DX+3]
    ; AND $40
    AND AL, 0x40
    ; CP $0
    CMP AL, 0
    ; JR Z, DSFINDFREEN
    JZ DSFINDFREEN
    ; INC B
    INC BL
    ; LD A, B
	; LD HL, MAXSTRINGS
    ; CP (HL)
    CMP BL, [MAXSTRINGS]
    ; JR NZ, DSFINDFREEL
    JNZ DSFINDFREEL
    ; JMP OUT_OF_MEMORY   
    JP OUT_OF_MEMORY
DSFINDFREEN:
    POP SI
    RET

OUT_OF_MEMORY2:
    JP OUT_OF_MEMORY

; DSMALLOC(SI,CL,BL)
DSMALLOC:
    CALL DSDESCRIPTOR
    ; PUSH HL
    PUSH BX
    ; LD A, 0
    ; LD D, A
    ; LD A, C
    ; LD E, A
    ; LD HL, (FREE_STRING)
    MOV BX, [FREE_STRING]
    ; SBC HL, DE
    MOV CH, 0
    SUB BX, CX
    ; LD (FREE_STRING), HL
    MOV [FREE_STRING], BX
    ; PUSH HL
    ; POP DE
    ; POP HL
    ; PUSH HL
    PUSH SI
    ADD SI, BX
    ; ADD HL, DE
    MOV [DX], CL
    ; LD (IX), C
    ; LD (IX+1), L
    ; LD (IX+2), H
    MOV [DX+1], SI
    ; POP HL
    POP SI
    RET

; DSCHECKFREE()
DSCHECKFREE:
    PUSH AX
    PUSH BX
DSCHECKFREE2:
    MOV CH, 0    
    ; LD A, (FREE_STRING+1)
    MOV AX, [FREE_STRING]
    ; CP $80
    ; JR NC, DSCHECKFREEKO
    CMP AX, CX
    JBE DSCHECKFREEKO
    JP DSCHECKFREEOK
    ; LD B, A
    ; LD A, 0
    ; CP B
    ; JR Z, DSCHECKFREEL2
    ; JR C, DSCHECKFREEOK
DSCHECKFREEL2:
    ; LD A, (FREE_STRING)
    ; LD B, A
    ; LD A, C
    ; CP B
    ; JR C, DSCHECKFREEOK

DSCHECKFREEKO:
    PUSH BX
    CALL DSGC
    POP BX
    JP DSCHECKFREE2
DSCHECKFREEOK:
    POP BX
    POP AX
    RET

; DSUSING() -> SI
DSUSING:
    ; LD A, (USING)
    ; CP 0
    MOV AL, (USING)
    CMP AL, 0
    ; JR Z, DSUSINGW
    JZ DSUSINGW
    ; JR DSUSINGT
    JP DSUSINGT
DSUSINGT:
    ; LD HL, TEMPORARY
    MOV SI, TEMPORARY
    RET
DSUSINGW:
    ; LD HL, WORKING
    MOV SI, WORKING
    RET

; DSDESCRIPTOR(BL) -> DX
DSDESCRIPTOR:
    ; PUSH HL
    ; PUSH BC
    PUSH BX
    ; LD A, B
    ; LD C, A
    ; LD A, 0
    ; LD B, A
    ; PUSH BC
    ; POP HL
    ; ADD HL, HL
    ; ADD HL, HL
    ADD BX, BX
    ADD BX, BX
    ; PUSH HL
    ; POP DE
    ; LD HL, DESCRIPTORS
    ; ADD HL, DE
    MOV DX, DESCRIPTORS
    ADD DX, BX
    ; PUSH HL
    ; POP IX
    ; POP BC
    ; POP HL
    POP BX
    RET

OUT_OF_MEMORY:
    JP OUT_OF_MEMORY

DSINIT:
    ; LD BC, stringscount*4+stringsspace*2
    MOV CX, stringscount*4+stringsspace*2
    ; LD A, 0
    ; LD HL, DESCRIPTORS
    LD SI, DESCRIPTORS
    MOV [SI], 0
    LD DI, DESCRIPTORS
    INC DI
    ; LD DE, HL
    ; INC DE
    ; LD (HL), A
    ; LDIR
    REP MOVSB
    ; LD A, stringscount
    MOV AL, stringscount
    ; LD (MAXSTRINGS), A
    MOV [MAXSTRINGS], AL
    ; LD DE, stringsspace
    MOV DE, stringsspace
    ; LD (FREE_STRING), DE
    MOV [FREE_STRING], DE
    RET
