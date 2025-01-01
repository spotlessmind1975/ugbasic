; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                          STARTUP ROUTINE FOR MSX1                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CHECKIF60HZ:
    IN A, ($bf)
    NOP
    NOP
    NOP
VDPSYNC:
    IN A, ($bf)
	AND $80
    CP 0
	JR Z, VDPSYNC
    LD HL, $0
VDPLOOP:
    INC HL
    IN A, ($bf)
    AND $80
    CP 0
	JR Z, VDPLOOP
VDPLOOPD:

    LD A, H
    CMP $06
    JR Z, VDPLOOPDQ0
    LD A, 1
    RET

VDPLOOPDQ0:
    LD A, 0
    RET

ISRSVC:
@IF deployed.ay8910startup
	CALL AY8910MANAGER
@ENDIF
@IF deployed.music
    CALL MUSICPLAYER
@ENDIF
@IF deployed.keyboard
    CALL KEYBOARDMANAGER
@ENDIF
@IF deployed.joystick && !joystickConfig.sync
    CALL JOYSTICKMANAGER
@ENDIF
@IF deployed.timer
    CALL TIMERMANAGER
@ENDIF
    PUSH AF
    PUSH HL
    LD A, 1
    LD (VBLFLAG), A
    ; LD HL, ($FC9E)
    ; ADD HL, 1
    ; LD ($FC9E), HL
    POP HL
    POP AF
    RET

MSX1STARTUP:

    DI

    ; LD HL, ($fd9f+1)
    ; LD DE, HL
    ; LD HL, ISRSVC2
    ; LD A, $c3
    ; LD (HL), A
    ; INC HL
    ; LD A, E
    ; LD (HL), A
    ; INC HL
    ; LD A, D
    ; LD (HL), A

    LD HL, ISRSVC
    LD ($fd9f+1), HL
    LD A, $c3
    LD ($fd9f), A
    EI
    
    CALL VDPLOCK
    CALL CHECKIF60HZ
    CMP 1
    JR Z, MSX1NTSC

MSX1PAL:
    LD A, 50
    LD (TICKSPERSECOND), A
    JP MSX1STARTUPDONE

MSX1NTSC:
    LD A, 60
    LD (TICKSPERSECOND), A
    JP MSX1STARTUPDONE    

MSX1STARTUPDONE:

@IF dataSegment
    LD HL, DATAFIRSTSEGMENT
    LD (DATAPTR), HL
@ENDIF

    RET

WAITTIMER:
    LD A, ($FC9E)
    LD B, A
WAITTIMERL1:
    LD A, ($FC9E)
    CP B
    JR Z, WAITTIMERL1
    DEC L
    LD A, L
    CP $FF
    JR NZ, WAITTIMER
    DEC H
    LD A, H
    CP $FF
    JR NZ, WAITTIMER
    RET
