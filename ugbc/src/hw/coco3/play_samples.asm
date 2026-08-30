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
;*                             PLAY SAMPLES ON COCO                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLES
	ORCC #$50

	LDA $ff01
	ANDA #%11110111
	STA $ff01
	LDA $ff03
	ANDA #%11110111
	STA $ff03
	LDA $ff23
	ORA #%00001000
	STA $ff23
	LDA $ff21
	ANDA #%11111011
	STA $ff21
	LDA #%11111100
	STA $ff20
	LDA $ff21
	ORA #%00000100
	STA $ff21

PLAYSAMPLESL1
	LDA ,X+
	BEQ PLAYSAMPLESDONE
	LSLA
	LSLA
	ANDA #$FC
    STA $FF20
	LDB #20
PLAYSAMPLESL2
	DECB
	BNE PLAYSAMPLESL2
	JMP PLAYSAMPLESL1
PLAYSAMPLESDONE

	LDA $ff21
	ANDA #%11111011
	STA $ff21
	LDA #%11111111
	STA $ff20
	LDA $ff21
	ORA #%00000100
	STA $ff21
	LDA $ff23
	ANDA #%11110111
	STA $ff23

    ANDCC #$AF
    RTS
