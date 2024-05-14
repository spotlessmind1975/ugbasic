; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                      STARTUP ROUTINE FOR ZX                                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ZXSTARTUP:

    DI
    LD A, 0
    LD (IRQVECTOR), A
    LD (IRQVECTOR+1), A
    LD (IRQVECTORREADY), A

    LD HL, ZXIRQSVC
    LD IX, $FFF0
    LD (IX+$04), $C3
    LD (IX+$05), L
    LD (IX+06h), H
    LD (IX+$0F), $18
    LD A, $39
    LD I, A
    IM 2
    EI

    LD A, 0
    LD ($5C08), A

    RET
         
ZXIRQSVC:
    DI
    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    PUSH IX
    PUSH IY
    EXX
    EX AF,AF'
    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    PUSH IX
    PUSH IY

    LD HL, (ZXTIMER)
    INC HL
    LD (ZXTIMER), HL

	LD A, (IRQVECTORREADY)
	CMP 0
	JR Z, IRQVECTORSKIP
    CALL IRQVECTOR
IRQVECTORSKIP:
    CALL TIMERMANAGER

    POP IY
    POP IX
    POP HL
    POP DE
    POP BC
    POP AF
    EXX
    EX AF,AF'
    POP IY
    POP IX
    POP HL
    POP DE
    POP BC
    POP AF
    EI
    RET

CHECKIF60HZ:
    LD DE, 0
    LD A, 0
    LD (ZXTIMER), A
    LD (ZXTIMER+1), A
VDPSYNC:
    INC DE
    LD A, D
    CP $D0
    JR NZ, VDPSYNC

    LD A, (ZXTIMER)
    CMP $0C
    JR Z, VDPLOOPDQ0
    JR NC, VDPLOOPDQ0
    LD A, 1
    RET

VDPLOOPDQ0:
    LD A, 0
    RET

ZXSTARTUP2:

@IF dataSegment
    LD HL, DATAFIRSTSEGMENT
    LD (DATAPTR), HL
@ENDIF

    CALL CHECKIF60HZ
    CMP 1
    JR Z, ZXNTSC

ZXPAL:
    LD A, 50
    LD (TICKSPERSECOND), A
    JP ZXSTARTUPDONE

ZXNTSC:
    LD A, 60
    LD (TICKSPERSECOND), A
    JP ZXSTARTUPDONE    

ZXSTARTUPDONE:
    RET
    