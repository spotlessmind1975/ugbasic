; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                          JOYSTICK ROUTINE FOR GB                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JOYSTICKREAD:
    PUSH DE
	LD A, $20
    LD (rP1), A
    LD A, (rP1)
    LD A, (rP1)
	AND	$0F
	LD E, A
	LD A, $10
    LD (rP1), A
    LD A, (rP1)
    LD A, (rP1)
    LD A, (rP1)
    LD A, (rP1)
    LD A, (rP1)
    LD A, (rP1)
	AND	$0F
    SWAP A
	OR E
	CPL
	LD E, A
	LD A, $30
    LD (rP1), A
	LD	A, E
    POP DE
	RET

JOYSTICKREAD0:

@IF joystickConfig.sync
    CALL JOYSTICKREAD
@ELSE
    LD A, (JOYSTICK0)
@ENDIF

    RET

WAITFIRE:
    CALL JOYSTICKREAD0
    AND $F0
    CP $00
    JR Z, WAITFIRE
    LD A, B
    CP $0
    RET Z
WAITFIREL1:
    CALL JOYSTICKREAD0
    AND $F0
    CP $00
    JR NZ, WAITFIREL1
    RET