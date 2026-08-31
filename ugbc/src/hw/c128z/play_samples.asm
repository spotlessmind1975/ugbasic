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
;*                             PLAY SAMPLES ON C128Z                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLES:
	DI
PLAYSAMPLESL1:
	LD A, (HL)
	CP 0
	JR Z, PLAYSAMPLESDONE

	PUSH AF
	AND $0F
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	LD BC, $DC02
    OUT (C), A
	LD B, 20
PLAYSAMPLESL2L:	
	DEC B
	JR NZ, PLAYSAMPLESL2L

	POP AF
	AND $F0
	SRL A
	SRL A
	SRL A
	SRL A
	LD BC, $DC02
    OUT (C), A
	LD B, 20
PLAYSAMPLESL2H:	
	DEC B
	JR NZ, PLAYSAMPLESL2H

	INC HL
	JR PLAYSAMPLESL1
PLAYSAMPLESDONE:
    EI
    RET
