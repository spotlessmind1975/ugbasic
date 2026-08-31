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
;*                            PLAY SAMPLES ON SN76489                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLES:
	LD A, %10000001
    OUT (CSG_OUT), A
    
    LD A, %00000000
    OUT (CSG_OUT), A

PLAYSAMPLESL1:
	LD A, (HL)

	CP 0
	JR Z, PLAYSAMPLESDONE

	INC HL

	LD DE, PAYSAMPLESLUT
	EX DE, HL
	LD C, A
	LD B, 0
	ADD HL, BC
	EX DE, HL
	LD A, (DE)
    
    OR %10010000
    OUT (CSG_OUT), A

	LD B, 20
PLAYSAMPLESL2:  
	DJNZ PLAYSAMPLESL2
	JR PLAYSAMPLESL1

PLAYSAMPLESDONE:
    LD A, %10011111
    OUT (CSG_OUT), A
	RET

PAYSAMPLESLUT:
    db $0F, $0C, $09, $07, $06, $05, $04, $04
    db $03, $03, $02, $02, $01, $01, $00, $00