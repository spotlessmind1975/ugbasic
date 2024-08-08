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
;*                      STARTUP ROUTINE FOR C128Z                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ALIGN $100, $00
    
C128ZIM2TABLEDUMMY:
    DB $00
C128ZIM2TABLE:
    DEFS    257, 0

IRQSVC:
    PUSH AF
    PUSH BC

@IF deployed.keyboard
    CALL KEYBOARDMANAGER
@ENDIF

    LD BC, $D019
    LD A, $FF
    OUT (C), A
    POP BC
    POP AF
    EI
    RETI

C128ZSTARTUP:

    LD A, $7F
    LD BC, $DC0D
    OUT (C), A

    LD BC, $D01A
    IN A, (C)
    OR $012
    OUT (C), A

    LD BC, $D011
    IN A, (C)
    AND $7F
    OUT (C), A

    LD HL, C128ZIM2TABLE
    LD A, $ff
    LD B, A
    LD A, H
C128ZSTARTUPL1:
    LD (HL), A
    INC HL
    DEC B
    JR NZ, C128ZSTARTUPL1
    LD (HL), A

    LD DE, IRQSVC

    LD L, A
    LD A, $C3
    LD (HL), A
    INC HL
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A

    LD HL, C128ZIM2TABLE
    LD A, H
    LD I, A
    IM 2
    LD BC, $D012
    LD A, 148
    OUT (C), A
    EI

    LD A, ($0A03)
    CMP 0
    JR Z, C128ZNTSC

C128ZPAL:
    LD A, 50
    LD (TICKSPERSECOND), A
    JP C128ZSTARTUPDONE

C128ZNTSC:
    LD A, 60
    LD (TICKSPERSECOND), A
    JP C128ZSTARTUPDONE    

C128ZSTARTUPDONE:

	LD A, $FF
    PUSH BC
    LD BC, $DC02
    OUT (C), A
    POP BC

	LD A, $00
    PUSH BC
    LD BC, $DC03
    OUT (C), A
    POP BC

SYSCALLDONE:
    RET

SYSCALL:
SYSCALL0:
	CALL $0000
	JP SYSCALLDONE
