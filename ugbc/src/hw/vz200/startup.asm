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
;*                      STARTUP ROUTINE FOR VZ200                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; @IF vestigialConfig.rchack_pick_the_star_1163

; PALETTEB:
; 	DB      1
; PALETTE:    
;     DB      4,  10,  19,  12 
;     DB     11,  20,  21,  13
;     DB      6,  30,  31,   7 
;     DB      18, 25,  10,   0

; @ELSE

; PALETTEB:
; 	DB      1

; @ENDIF

; PALETTEUNUSED:
;     DB $00
; PALETTEUSED:
;     DB $01, $00

; SETHWPALETTE:
; 	PUSH BC
; 	PUSH AF
;     LD BC, $7F00
;     LD A, IXH
;     LD C, A
;     OUT (C), C
;     LD A, IXL
;     OR A, $40
;     OUT (C), A
; 	POP AF
; 	POP BC
;     RET

; RESETPALETTE:
; 	LD B, 0
; 	LD HL, PALETTE
; RESETPALETTEL1:
; 	LD IXH, B
; 	LD A, (HL)
; 	LD IXL, A
; 	CALL SETHWPALETTE
; 	INC HL
; 	INC B
; 	LD A, B
; 	CP 16
; 	JR NZ, RESETPALETTEL1
; 	LD BC, $7F10
;     OUT (C), C
;     LD A, (PALETTEB)
;     OR A, 0x40
;     OUT (C), A
; 	RET

; IRQTIMERVOID:
; 	RET

; VZ200ISVC:
; 	PUSH	AF
; 	PUSH	BC
; 	PUSH	DE
; 	PUSH	HL
; 	PUSH	IX
; 	PUSH	IY
; 	EX	AF,AF'
; 	PUSH	AF
; 	EXX
; 	PUSH	BC
; 	PUSH	DE
; 	PUSH	HL
;     LD A, (VZ200TIMER2)
;     DEC A
;     LD (VZ200TIMER2), A
;     CP 0
;     JR NZ,IRQVECTORSKIP
;     LD A,6
;     LD (VZ200TIMER2), A
;     LD HL,(VZ200TIMER)
;     INC HL
;     LD (VZ200TIMER),HL
; @IF deployed.music
; 	CALL MUSICPLAYER
; @ENDIF
; @IF deployed.ay8910startup
; 	CALL AY8910MANAGER
; @ENDIF
; @IF deployed.keyboard && !keyboardConfig.sync
; 	CALL KEYBOARDMANAGER
; @ENDIF
; @IF deployed.joystick && !joystickConfig.sync
; 	CALL JOYSTICKMANAGER
; @ENDIF
; @IF deployed.timer
; 	CALL TIMERMANAGER
; @ENDIF
; @IF deployed.fade
; 	CALL FADET
; @ENDIF
; IRQTIMERADDR:
; 	CALL IRQTIMERVOID
; IRQVECTORSKIP:
; 	POP	HL
; 	POP	DE
; 	POP	BC
; 	EXX
; 	POP	AF
; 	EX	AF,AF'
; 	POP	IY
; 	POP	IX
; 	POP	HL
; 	POP	DE
; 	POP	BC
; 	POP	AF
;     EI
;     RET   

VZ200STARTUP:

; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;   Waits until Press <SPACE BAR>                
; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
DEBUGVZ00:
	LD A, ($68ef)
	AND $10
	JR NZ, DEBUGVZ00
	RET
	
; 	LD A, 50
; 	LD (TICKSPERSECOND), A

; @IF dataSegment
;     LD HL, DATAFIRSTSEGMENT
;     LD (DATAPTR), HL
; @ENDIF

; @IF sysCallUsed

; SYSCALLDONE:

; @ENDIF

;     ; LD DE, $40
;     ; LD HL, $B0FF
;     ; CALL $BCCB

; 	CALL VZ200IRQUGBASIC

; 	DI
; 	LD HL, IRQTIMERVOID
; 	LD A, L
; 	LD (IRQTIMERADDR+1), A
; 	LD A, H
; 	LD (IRQTIMERADDR+2), A
; 	EXX
; 	LD B, $7F
; 	LD A, (GAVALUE)
; 	OR A, $0C
; 	LD (GAVALUE), A
; 	LD C, A
; 	OUT (C), C
; 	EXX
; 	EI

;     LD BC,$7F10
;     OUT (C), C
;     LD A, $14
;     LD (PALETTEB), A
;     AND $1f
;     OR A, $40
;     OUT (C), A

; @IF vestigialConfig.clsImplicit
; 	CALL CLSG
; @ENDIF

;     RET

; @IF sysCallUsed

; SYSCALL:
; 	CALL VZ200IRQSYSTEM
; SYSCALL0:
; 	CALL $0000
; 	EI
; 	JP SYSCALLDONE

; @ENDIF

; VZ200IRQUGBASIC:
;     DI
; 	LD A, ($0038)
; 	LD (IRQVECTOR), A
;     LD HL, ($0039)
; 	LD (IRQVECTOR+1), HL
;     LD A, $C3
;     LD ($0038), A
;     LD HL, VZ200ISVC
;     LD ($0039), HL
;     EI
; 	RET

; VZ200IRQSYSTEM:
;     DI
;     LD A, (IRQVECTOR)
;     LD ($0038), A
;     LD HL, (IRQVECTOR+1)
;     LD ($0039), HL
;     EI
; 	RET

; VZ200VIDEOSTARTUP:
; 	LD HL, PALETTE
; 	LD A, 0
; 	LD BC, $0F00
; VZ200VIDEOSTARTUPL1:
; 	LD A, C
; 	LD IXH, A
; 	LD A, (HL)
; 	LD IXL, A
; 	CALL SETHWPALETTE
; 	INC HL
; 	INC C
; 	DEC B
; 	JR NZ, VZ200VIDEOSTARTUPL1

;     RET

; WAITTIMER:
;     LD A, (VZ200TIMER)
;     LD B, A
; WAITTIMERL1:
;     LD A, (VZ200TIMER)
;     CP B
;     JR Z, WAITTIMERL1
;     DEC L
;     LD A, L
;     CP $FF
;     JR NZ, WAITTIMER
;     DEC H
;     LD A, H
;     CP $FF
;     JR NZ, WAITTIMER
;     RET
