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
;*                      JOYSTICK ROUTINE FOR    VTECH                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; @IF joystickConfig.values

;     ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;     ;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
;     ;-
;     ;- Change the reading values based on its convention.
;     ;-
;     ;- To enable: DEFINE JOYSTICK VALUES TSB
;     ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

;     JOYSTICKTSBREMAP:
;         db   $0, $1, $5, $0
;         db   $7, $8, $6, $0
;         db   $3, $2, $4, $0
;         db   $0, $0, $0, $0

;     JOYSTICKTSB:
;         PUSH BC
;         PUSH HL
;         PUSH DE
;         LD B, A
;         AND $0F
;         LD HL, JOYSTICKTSBREMAP
;         LD E, A
;         LD D, 0
;         ADD HL, DE
;         LD A, (HL)
;         LD C, A
;         LD A, B
;         AND $10
;         CP 0
;         JR Z, JOYSTICKTSBNOFIRE
;     JOYSTICKXTSBNOFIRE:
;         LD A, C
;         OR $80
;         LD C, A
;     JOYSTICKTSBNOFIRE:
;         LD A, C
;         POP DE
;         POP HL
;         POP BC
;         RET    

; @ENDIF

; JOYSTICKC:
;     LD IXL, $0
; JOYSTICK1UP:
;     LD A, (HL)
;     BIT 0, A
;     JR Z, JOYSTICK1DOWN
;     LD IXL, $1
; JOYSTICK1DOWN:
;     BIT 1, A
;     JR Z, JOYSTICK1LEFT
;     PUSH AF
;     LD A, IXL
;     OR $2
;     LD IXL, A
;     POP AF
; JOYSTICK1LEFT:
;     BIT 2, A
;     JR Z, JOYSTICK1RIGHT
;     PUSH AF
;     LD A, IXL
;     OR $4
;     LD IXL, A
;     POP AF
; JOYSTICK1RIGHT:
;     BIT 3, A
;     JR Z, JOYSTICK1FIRE
;     PUSH AF
;     LD A, IXL
;     OR $8
;     LD IXL, A
;     POP AF
; JOYSTICK1FIRE:
;     BIT 4, A
;     JR Z, JOYSTICK1DONE
;     PUSH AF
;     LD A, IXL
;     OR $10
;     LD IXL, A
;     POP AF
; JOYSTICK1DONE:
;     LD A, IXL
;     RET

; JOYSTICKREAD0:
;     LD HL, SCANCODEREAD
;     ADD HL, 9
;     CALL JOYSTICKC
;     RET

; JOYSTICKREAD1:
;     LD HL, SCANCODEREAD
;     ADD HL, 6
;     CALL JOYSTICKC
;     RET

; @IF joystickConfig.sync

;     WAITFIRE0:

; @IF keyboardConfig.sync    
;         CALL SCANCODERAW
; @ENDIF

;         CALL JOYSTICKREAD0
;         AND $10
;         CP 0
;         JR Z, WAITFIRE0
;         RET

;     WAITFIRE1:

; @IF keyboardConfig.sync    
;         CALL SCANCODERAW
; @ENDIF

;         CALL JOYSTICKREAD1
;         AND $10
;         CP 0
;         JR Z, WAITFIRE1
;         RET

;     WAITFIRE:

; @IF keyboardConfig.sync    
;         CALL SCANCODERAW
; @ENDIF

;         CALL JOYSTICKREAD0
;         AND $10
;         LD B, A
;         CALL JOYSTICKREAD1
;         AND $10
;         OR B
;         CP 0
;         JR Z, WAITFIRE
;         RET

; @ELSE

;     JOYSTICKMANAGER:

;         PUSH IX
;         PUSH HL
;         PUSH AF

; @IF keyboardConfig.sync    
;         CALL SCANCODERAW
; @ENDIF

;         CALL JOYSTICKREAD0
;         LD (JOYSTICK0), A

;         CALL JOYSTICKREAD1
;         LD (JOYSTICK1), A

;         POP AF
;         POP HL
;         POP IX

;         RET

;     WAITFIRE0:
;         LD A, (JOYSTICK0)
;         AND $10
;         CP 0
;         JR Z, WAITFIRE0
;         RET

;     WAITFIRE1:
;         LD A, (JOYSTICK1)
;         AND $10
;         CP 0
;         JR Z, WAITFIRE1
;         RET

;     WAITFIRE:
;         LD A, (JOYSTICK0)
;         AND $10
;         LD B, A
;         LD A, (JOYSTICK1)
;         AND $10
;         OR B
;         CP 0
;         JR Z, WAITFIRE
;         RET

; @ENDIF
