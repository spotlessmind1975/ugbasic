; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                            PLAY SAMPLES ON ZX                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLE:
	LD D, A        
	LD A, $10
	OUT ($FE), A
	PUSH DE
PLAYSAMPLESL1ON:
	DEC D
	JP NZ, PLAYSAMPLESL1ON
	POP DE
	LD A, 15
	SUB D
	LD D, A
	XOR A
	OUT ($FE), A
PLAYSAMPLESL1OFF:
	DEC D
	JP NZ, PLAYSAMPLESL1OFF
	RET

PLAYSAMPLES:
	DI
PLAYSAMPLESL1:
    LD A, (HL)
	CMP 0
	JR Z, PLAYSAMPLESDONE

	PUSH AF
	AND $0F
	NOP
	NOP
	NOP
	CALL PLAYSAMPLE

	POP AF
	SRL A
	SRL A
	SRL A
	SRL A
	CALL PLAYSAMPLE

	INC HL
    JR PLAYSAMPLESL1
PLAYSAMPLESDONE:
	EI
    RET
