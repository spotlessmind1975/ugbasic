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
;*                             PLAY SAMPLES ON C64                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLESREU:
	SEI
	LDA #$0
	STA REUCONTROL
	LDA #%10010001
	STA REUCOMMAND

	LDX #0
PLAYSAMPLESREUL1:
	LDA $FFFF,X
	BEQ PLAYSAMPLESREUDONE

	PHA
	NOP
	NOP
	NOP
	NOP
	AND #$0F
	STA $d418
	LDY #20
PLAYSAMPLESREUL2L:	
	DEY
	BNE PLAYSAMPLESREUL2L

	NOP
	NOP
	NOP
	PLA
	LSR
	LSR
	LSR
	LSR
	AND #$0F
	STA $d418
	LDY #20
PLAYSAMPLESREUL2H:	
	DEY
	BNE PLAYSAMPLESREUL2H

	INX
	BNE PLAYSAMPLESREUL1
	LDA PLAYSAMPLESREUL1+1
	STA REUC64BASE
	LDA PLAYSAMPLESREUL1+2
	STA REUC64BASE+1
	LDA #$0
	STA REUTRANSLEN
	LDA #$1
	STA REUTRANSLEN+1
	LDA #%10010001
	STA REUCOMMAND
	JMP PLAYSAMPLESREUL1
PLAYSAMPLESREUDONE:
    CLI
    RTS

PLAYSAMPLES:
	SEI
	LDX #0
PLAYSAMPLESL1:
	LDA $FFFF,X
	BEQ PLAYSAMPLESDONE

	PHA
	NOP
	NOP
	NOP
	NOP
	AND #$0F
	STA $d418
	LDY #20
PLAYSAMPLESL2L:	
	DEY
	BNE PLAYSAMPLESL2L
	
	PLA
	LSR
	LSR
	LSR
	LSR
	AND #$0F
	STA $d418
	LDY #20
PLAYSAMPLESL2H:	
	DEY
	BNE PLAYSAMPLESL2H

	INX
	BNE PLAYSAMPLESL1
	INC PLAYSAMPLESL1+2
	JMP PLAYSAMPLESL1
PLAYSAMPLESDONE:
    CLI
    RTS
