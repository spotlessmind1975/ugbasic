; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                      STARTUP ROUTINE FOR COLECO                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VDPDATAPORTWRITE        = $be
VDPDATAPORTREAD         = $be
VDPCONTROLPORTREAD      = $bf
VDPCONTROLPORTWRITE     = $bf

CBIOS_VDPSETREG         = $1fd9
CBIOS_VDPWRITE          = $1fdf
CBIOS_POLLER            = $1feb
CBIOS_CONTROLLER_INIT   = $1105

rst_8:
    RETI
    NOP

rst_10:
    RETI
    NOP

rst_18:
    JP $1ffd

rst_20:
    RETI
    NOP

rst_28:
    RETI
    NOP

rst_30:
    RETI
    NOP

rst_38:
    RETI
    NOP

jp NMI

@IF customIrqNeeded || ticksPerSecondUsed
IRQVOID:
    RET
@ENDIF

@IF customIrqNeeded || timerUsed || deployed.music || deployed.timer || (deployed.joystick && ! joystickConfig.sync) || ticksPerSecondUsed
section data_user
IRQVECTOR:      DEFS 3, 0
IRQVECTORREADY: DEFB $00
@ENDIF

NMI:
@IF timerUsed || deployed.music || deployed.timer || (deployed.joystick && ! joystickConfig.sync) || ticksPerSecondUsed
	PUSH	AF
    LD A, (VDPINUSE)
    CP 1
    JR Z, NMI2
	PUSH	BC
	PUSH	DE
	PUSH	HL
	PUSH	IX
	PUSH	IY
	EX	AF,AF'
	PUSH	AF
	EXX
	PUSH	BC
	PUSH	DE
	PUSH	HL
@IF timerUsed || ticksPerSecondUsed
    LD HL,(COLECOTIMER)
    INC HL
    LD (COLECOTIMER),HL
@ENDIF

@IF customIrqNeeded
	LD A, (IRQVECTORREADY)
	CMP 0
	JR Z, IRQVECTORSKIP
    CALL IRQVECTOR
IRQVECTORSKIP:
@ENDIF

@IF deployed.sn76489startup
	CALL SN76489MANAGER
@ENDIF
@IF deployed.music
    CALL MUSICPLAYER
@ENDIF
@IF deployed.timer
    CALL TIMERMANAGER
@ENDIF
@IF deployed.joystick && ! joystickConfig.sync
    CALL JOYSTICKMANAGER
@ENDIF
	POP	HL
	POP	DE
	POP	BC
	EXX
	POP	AF
	EX	AF,AF'
	POP	IY
	POP	IX
	POP	HL
	POP	DE
	POP	BC
    IN A, ($bf)
NMI2:
	POP	AF
@ENDIF
	RETN

; SET_GAMELOOP_HOOK:
;         LD (GAMELOOP_HOOK+1),HL
;         LD A,$c9
;         LD (GAMELOOP_HOOK+3),A
;         LD A,$cd
;         LD (GAMELOOP_HOOK),A
;         RET

@IF vestigialConfig.biosAllowed
section data_user
CONTROLLER_BUFFER: DEFB $9b, $9b, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
section code_user
@ENDIF

@IF ticksPerSecondUsed
@IF videoOutputStandard == VOS_PAL
section data_user
TICKSPERSECOND: DEFB 50
section code_user
@ELSE
section data_user
TICKSPERSECOND: DEFB 60
section code_user
@ENDIF
@ENDIF

COLECOSTARTUP:

@IF vestigialConfig.biosAllowed
    CALL CBIOS_CONTROLLER_INIT
@ENDIF

@IF customIrqNeeded || timerUsed || deployed.music || deployed.timer || (deployed.joystick && ! joystickConfig.sync)  || ticksPerSecondUsed
    LD DE, IRQVOID
    LD HL, IRQVECTOR
    LD A, $c3
    LD (HL), A
    INC HL
    LD A, E
    LD (HL), A
    INC HL
    LD A, D
    LD (HL), A
	LD A, 1
	LD (IRQVECTORREADY), A
@ENDIF

@IF ticksPerSecondUsed && ( videoOutputStandard == VOS_NONE )

    LD A, ($0069)
    LD (TICKSPERSECOND), A

@ENDIF

@IF deployed.protothread
    CALL PROTOTHREADINIT
@ENDIF

@IF deployed.sn76489startup
    CALL SN76489STARTUP
@ENDIF

    RET

OOMHALTL1:
    OUT ($BF), A
    LD A, $87
    OUT ($BF), A
    RET

OOMHALT:
    LD A, $f4
    CALL OOMHALTL1
    LD A, $f1
    CALL OOMHALTL1
    JR OOMHALT
