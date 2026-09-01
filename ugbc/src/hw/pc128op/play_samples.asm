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
;*                           PLAY SAMPLES ON PC128OP                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLES

	ORCC #$50

	LDA $A7CF
	ANDA #$FB 
	STA $A7CF
	LDB #$3F
	STB $A7CD
	ORA #$04
	STA $A7CF

PLAYSAMPLESL1
	LDA ,X+
	BEQ PLAYSAMPLESDONE

	PSHS D
	ANDA #$0F
	ASLA
	ASLA
    STA $A7CD

	LDB #20
PLAYSAMPLESL2L
	DECB
	BNE PLAYSAMPLESL2L

	PULS D
	ANDA #$F0
	LSRA
	LSRA
    STA $A7CD

	LDB #20
PLAYSAMPLESL2H
	DECB
	BNE PLAYSAMPLESL2H

	JMP PLAYSAMPLESL1
PLAYSAMPLESDONE
    ANDCC #$AF
    RTS
