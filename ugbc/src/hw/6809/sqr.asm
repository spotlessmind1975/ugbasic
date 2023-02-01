; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      SQUARE ROOT CALCULATION ON 6809                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Numberl		equ $14		; number to find square root of low byte
Numberh		equ Numberl+1	; number to find square root of high byte
Reml		equ $16		; remainder low byte
Remh		equ Reml+1	; remainder high byte
templ		equ $18		; temp partial low byte
temph		equ templ+1	; temp partial high byte
Root		equ $20		; square root

SQROOT
	LDA	#$00		; clear A
	STA	<Reml		; clear remainder low byte
	STA	<Remh		; clear remainder high byte
	STA	<Root		; clear Root
	LDU	#$08		; 8 pairs of bits to do
SQROOTL1
	LSL	<Root		; Root = Root * 2

	LSL	<Numberl		; shift highest bit of number ..
	ROL	<Numberh		;
    LDB <Numberl
    LDB <Numberh
    LDB <Root
	ROL	<Reml		; .. into remainder
	ROL	<Remh		;

	LSL	<Numberl		; shift highest bit of number ..
	ROL	<Numberh		;
	ROL	<Reml		; .. into remainder
	ROL	<Remh		;

	LDA	<Root		; copy Root ..
	STA	<templ		; .. to templ
	LDA	#$00		; clear byte
	STA	<temph		; clear temp high byte

	ORCC #$01    	; +1
	ROL <templ		; temp = temp * 2 + 1
	ROL <temph		;

	LDA	 <Remh		; get remainder high byte
	CMPA <temph		; comapre with partial high byte

	BLT	SQROOTNX		; skip sub if remainder high byte smaller

	BNE	SQROOTSB		; do sub if <> (must be remainder>partial !)

	LDA	<Reml		; get remainder low byte
	CMPA	<templ		; comapre with partial low byte

	BLT	SQROOTNX		; skip sub if remainder low byte smaller

				; else remainder>=partial so subtract then
				; and add 1 to root. carry is always set here
SQROOTSB
	LDA	<Reml		; get remainder low byte
	SUBA	<templ		; subtract partial low byte
	STA	<Reml		; save remainder low byte
	LDA	<Remh		; get remainder high byte
	SUBA	<temph		; subtract partial high byte
	STA	<Remh		; save remainder high byte

	INC	<Root		; increment Root
SQROOTNX
	LEAU -1, U			; decrement bit pair count
    CMPU #0
	BNE	SQROOTL1		; loop if not all done

	RTS