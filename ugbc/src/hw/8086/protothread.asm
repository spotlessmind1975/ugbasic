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
;*                               PROTOTHREADING                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PROTOTHREADVOID:
    RET

PROTOTHREADINIT:
    MOV DI, PROTOTHREADLOOP
    MOV BL, (PROTOTHREADCOUNT)
    ADD DI, 7
PROTOTHREADINITL1:
    MOV [DI], PROTOTHREADVOID
    ADD DI, 8
    DEC BL
    CMP BL, 0
    JNZ PROTOTHREADINITL1
PROTOTHREADINITL2:
    RET

; PROTOTHREADREGAT(BL,SI)
PROTOTHREADREGAT:
    ; PUSH HL
    ; LD HL, PROTOTHREADLOOP
    LD DI, PROTOTHREADLOOP
    ; LD A, B
    ; SRL A
    ; SRL A
    ; SRL A
    MOV AL, BL
    SAL AL, 3
    ADD DI, AL
    ; ADD 6
    ADD DI, 7
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; POP DE
    MOV AX, SI
    MOV [DI], AX
    ; LD A, E
    ; LD (HL), A
    ; INC HL
    ; LD A, D
    ; LD (HL), A
    RET

; PROTOTHREADGETADDRESS(BL)->DI
PROTOTHREADGETADDRESS:
    ; PUSH HL
    ; LD HL, PROTOTHREADLOOP
    ; LD A, B
    ; SLA A
    ; SLA A
    ; SLA A
    ; ADD 6
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; LD A, (HL)
    ; LD E, A
    ; INC HL
    ; LD A, (HL)
    ; LD D, A
    ; POP HL

    LD DI, PROTOTHREADLOOP
    MOV AL, BL
    SAL AL, 3
    ADD DI, AL
    ADD DI, 7
    MOV AX, [DI]
    MOV DI, AX
    ; LD A, E
    ; LD (HL), A
    ; INC HL
    ; LD A, D
    ; LD (HL), A

    RET

; PROTOTHREADREG(SI)->BL
PROTOTHREADREG:
    ; LD A, (PROTOTHREADCOUNT)
    ; LD B, A
    ; LD A, 0
    ; LD C, A
    MOV CL, [PROTOTHREADCOUNT]
    ; PUSH HL
    ; LD HL, PROTOTHREADLOOP
    ; LD D, 0
    ; LD E, 6
    MOV DI, PROTOTHREADLOOP
    ADD DI, 7
    ; ADD HL, DE
PROTOTHREADREGL1:
    CMP [DI], PROTOTHREADVOID 
    ; LD DE, PROTOTHREADVOID
    ; LD A, (HL)
    ; CP E
    JNZ PROTOTHREADREGL2A
    ; JR NZ, PROTOTHREADREGL2A
    ; INC HL
    ; LD A, (HL)
    ; CP D
    ; JR NZ, PROTOTHREADREGL2
    ; POP DE
    ; DEC HL
    MOV [DI], SI
    ; LD (HL), E
    ; INC HL
    ; LD (HL), D
    ; LD B, C
    RET
PROTOTHREADREGL2A:
    ; LD D, 0
    ; LD E, 1
    ; ADD HL, DE
PROTOTHREADREGL2:
    ; LD D, 0
    ; LD E, 7
    ; ADD HL, DE
    ADD DI, 8
    ; INC C
    ; LD A, C
    ; CP B
    DEC CL
    CMP CL, 0
    JNZ PROTOTHREADREGL1
    ; JR NZ, PROTOTHREADREGL1
    ; LD B, $ff
    ; POP DE
    RET

; PROTOTHREADUNREG(BL)
PROTOTHREADUNREG:
    ; LD HL, PROTOTHREADLOOP
    ; LD A, B
    ; SLA A
    ; SLA A
    ; SLA A
    ; ADD 6
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; LD DE, PROTOTHREADVOID
    ; LD A, E
    ; LD (HL), A
    ; INC HL
    ; LD A, D
    ; LD (HL), A

    LD DI, PROTOTHREADLOOP
    MOV AL, BL
    SAL AL, 3
    ADD DI, AL
    ADD DI, 7
    MOV AX, PROTOTHREADVOID
    MOV [DI], AX

    RET

; PROTOTHREADSAVE(BL,AL)
PROTOTHREADSAVE:
    ; PUSH AF
    ; LD HL, PROTOTHREADLC
    ; LD A, B
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; POP AF
    ; LD (HL), A
    MOV DI, PROTOTHREADLC
    ADD DI, BL
    MOV [DI], AL
    RET

; PROTOTHREADRESTORE(BL)->AL
PROTOTHREADRESTORE:
    ; PUSH AF
    ; LD HL, PROTOTHREADLC
    ; LD A, B
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; POP AF
    ; LD A, (HL)
    MOV DI, PROTOTHREADLC
    ADD DI, BL
    MOV AL, [DI]
    RET

; PROTOTHREADSETSTATE(BL,AL)
PROTOTHREADSETSTATE:
    ; PUSH AF
    ; LD HL, PROTOTHREADST
    ; LD A, B
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; POP AF
    ; LD (HL), A
    MOV DI, PROTOTHREADST
    ADD DI, BL
    MOV [DI], AL
    RET

; PROTOTHREADGETSTATE(BL)->AL
PROTOTHREADGETSTATE:
    ; PUSH AF
    ; LD HL, PROTOTHREADST
    ; LD A, B
    ; LD D, 0
    ; LD E, A
    ; AND A
    ; ADD HL, DE
    ; POP AF
    ; LD A, (HL)
    MOV DI, PROTOTHREADST
    ADD DI, BL
    MOV AL, [DI]
    RET
