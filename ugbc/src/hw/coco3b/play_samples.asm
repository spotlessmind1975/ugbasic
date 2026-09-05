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
;*                             PLAY SAMPLES ON COCO3B                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLESINIT
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
	RTS

PLAYSAMPLESCLEANUP
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
	RTS

PLAYSAMPLES
	ORCC #$50

	JSR PLAYSAMPLESINIT

PLAYSAMPLESL1
	LDA ,X+
	BEQ PLAYSAMPLESDONE

	PSHS D
	ANDA #$0F
	LSLA
	LSLA
	ANDA #$FC
    STA $FF20

	LDB #16
PLAYSAMPLESL2L
	DECB
	BNE PLAYSAMPLESL2L

	PULS D
	ANDA #$F0
	LSRA
	LSRA
	ANDA #$FC
    STA $FF20

	LDB #16
PLAYSAMPLESL2H
	DECB
	BNE PLAYSAMPLESL2H
	JMP PLAYSAMPLESL1

PLAYSAMPLESDONE

	JSR PLAYSAMPLESCLEANUP

    ANDCC #$AF
    RTS

PLAYSAMPLESEXP
	ORCC #$50

	STA <MATHPTR0
	STA $FFAC
    TFR X, D
    ADDD #$8000
    TFR D, X
	
	JSR PLAYSAMPLESINIT

    JSR GIMEBANKVIDEO
	
PLAYSAMPLESEXPL1
	LDA ,X+
	BEQ PLAYSAMPLESEXPDONE

	PSHS D
	ANDA #$0F
	LSLA
	LSLA
	ANDA #$FC
    STA $FF20

	LDB #16
PLAYSAMPLESEXPL2L
	DECB
	BNE PLAYSAMPLESEXPL2L

	PULS D
	ANDA #$F0
	LSRA
	LSRA
	ANDA #$FC
    STA $FF20

	LDB #16
PLAYSAMPLESEXPL2H
	DECB
	BNE PLAYSAMPLESEXPL2H

	CMPX #$9FFF
	BNE PLAYSAMPLESEXPCONTINUE

	LDX #$8000
	DEC <MATHPTR0
	LDA <MATHPTR0
	STA $FFAC

PLAYSAMPLESEXPCONTINUE
	JMP PLAYSAMPLESEXPL1

PLAYSAMPLESEXPDONE

    JSR GIMEBANKROM
    LDA #$3C
    STA $FFAC
	JSR PLAYSAMPLESCLEANUP

    ANDCC #$AF
    RTS
