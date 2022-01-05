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
;*                               PROTOTHREADING                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PROTOTHREADVOID:
    RET

PROTOTHREADINIT:
    LD C, 0
    LD HL, PROTOTHREADLOOP
    LD DE, PROTOTHREADVOID
    LD A, (PROTOTHREADCOUNT)
    LD B, A
PROTOTHREADINITL1:
    LD A, $3E
    LD (HL), A
    INC HL
    LD A, C
    LD (HL), A
    INC HL
    LD A, $32
    LD (HL), A
    INC HL
    LD A, $A2
    LD (HL), A
    INC HL
    LD A, $00
    LD (HL), A
    INC HL
    LD A, $CD
    LD (HL), A
    INC HL
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
    INC HL
PROTOTHREADINITL2:
    INC C
    LD A, C
    CP B
    JR NZ, PROTOTHREADINITL1
    LD A, $C9
    LD (HL), A
    INC HL
    RET

; PROTOTHREADREGAT(B,HL)
PROTOTHREADREGAT:
    PUSH HL
    LD HL, PROTOTHREADLOOP
    LD A, B
    SRL A
    SRL A
    SRL A
    ADD 7
    LD D, 0
    LD E, A
    ADC HL, DE
    POP DE
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
    RET

; PROTOTHREADREG(HL)->B
PROTOTHREADREG:
    LD A, (PROTOTHREADCOUNT)
    LD B, A
    LD A, 0
    LD C, A
    PUSH HL
    LD HL, PROTOTHREADLOOP
    LD D, 0
    LD E, 6
    ADD HL, DE
PROTOTHREADREGL1:
    LD DE, PROTOTHREADVOID
    LD A, (HL)
    CP E
    JR NZ, PROTOTHREADREGL2A
    INC HL
    LD A, (HL)
    CP D
    JR NZ, PROTOTHREADREGL2
    POP DE
    DEC HL
    LD (HL), E
    INC HL
    LD (HL), D
    LD B, C
    RET
PROTOTHREADREGL2A:
    LD D, 0
    LD E, 1
    ADD HL, DE
PROTOTHREADREGL2:
    LD D, 0
    LD E, 7
    ADD HL, DE
    INC C
    LD A, C
    CP B
    JR NZ, PROTOTHREADREGL1
    LD B, $ff
    POP DE
    RET

; PROTOTHREADUNREG(B)
PROTOTHREADUNREG:
    LD HL, PROTOTHREADLOOP
    LD A, B
    SRL A
    SRL A
    SRL A
    ADD 7
    LD D, 0
    LD E, A
    ADC HL, DE
    LD DE, PROTOTHREADVOID
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
    RET

; PROTOTHREADSAVE(B,A)
PROTOTHREADSAVE:
    PUSH AF
    LD HL, PROTOTHREADLC
    LD A, B
    LD D, 0
    LD E, A
    ADC HL, DE
    POP AF
    LD (HL), A
    RET

; PROTOTHREADRESTORE(B)->A
PROTOTHREADRESTORE:
    PUSH AF
    LD HL, PROTOTHREADLC
    LD A, B
    LD D, 0
    LD E, A
    ADC HL, DE
    POP AF
    LD A, 0
    LD (HL), A
    RET

; PROTOTHREADSETSTATE(B,A)
PROTOTHREADSETSTATE:
    PUSH AF
    LD HL, PROTOTHREADST
    LD A, B
    LD D, 0
    LD E, A
    ADC HL, DE
    POP AF
    LD (HL), A
    RET

; PROTOTHREADGETSTATE(B)->A
PROTOTHREADGETSTATE:
    PUSH AF
    LD HL, PROTOTHREADST
    LD A, B
    LD D, 0
    LD E, A
    ADC HL, DE
    POP AF
    LD A, (HL)
    RET
