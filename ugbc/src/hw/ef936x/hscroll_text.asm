; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                          HORIZONTAL SCROLL ON EF936X                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLST

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ HSCROLLSTORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

HSCROLLSTDB
	RTS

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

HSCROLLSTORIG

	PSHS A,B,X,Y,U
    LDA <DIRECTION
	CMPA #0
    BGT HSCROLLSTRIGHT
	
HSCROLLSTLEFT
	ORCC #$50
	LDA #2
	PSHS A
	LDA $A7C0
	ANDA #$FE
	STA $A7C0
HSCROLLSTLEFT0X
	LDU #0
	LDA #10
HSCROLLSTLEFT1X
	LDB ,U+
HSCROLLSTLEFT2X
	PULU Y,X
	STX -5,U
	STY -3,U
	DECA
	BNE HSCROLLSTLEFT2X
	LDA #10
	LEAU -2,U
	STB ,U+
	CMPU #$1F40
	BLO HSCROLLSTLEFT1X
	INC $A7C0
	DEC ,S
	BNE HSCROLLSTLEFT0X
	PULS A
	ANDCC #$AF
	PULS D,X,Y,U
	RTS
HSCROLLSTRIGHT
	ORCC #$50
	LDA #2
	PSHS A
	LDA $A7C0
	ANDA #$FE
	STA $A7C0
HSCROLLSTRIGHT0X
	LDU #$1F3F
	LDA #10
HSCROLLSTRIGHT1X
	LDB ,U+
HSCROLLSTRIGHT2X
	LDY -3,U
	LDX -5,U
	PSHU X,Y
	DECA
	BNE HSCROLLSTRIGHT2X
	LDA #10
	STB ,U
	LEAU -1,U
	CMPU #$FFFF
	BNE HSCROLLSTRIGHT1X
	INC $A7C0
	DEC ,S
	BNE HSCROLLSTRIGHT0X
	PULS A
	ANDCC #$AF
	PULS D,X,Y,U
	RTS
 



HSCROLLLT
    RTS