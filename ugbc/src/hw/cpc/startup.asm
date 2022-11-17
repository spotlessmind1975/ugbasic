; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;*                      STARTUP ROUTINE FOR CPC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PALETTE:    
    DB      4,  10,  19,  12 
    DB     11,  20,  21,  13
    DB      6,  30,  31,   7 
    DB      18, 25,  10,   7
PALETTEUNUSED:
    DB $01

SETHWPALETTE:
	PUSH BC
	PUSH AF
    LD BC, $7F00
    LD A, IXH
    LD C, A
    OUT (C), C
    LD A, IXL
    OR A, $40
    OUT (C), A
	POP AF
	POP BC
    RET

CPCISVC:
	PUSH	AF
	PUSH	BC
	PUSH	DE
	PUSH	HL
	PUSH	IX
	PUSH	IY
	EX	AF,AF'
	PUSH	AF
	EXX
	PUSH	BC
	PUSH	DE
	PUSH	HL
    LD A,(CPCTIMER2)
    DEC A
    LD (CPCTIMER2), A
    CP 0
    JR NZ,IRQVECTORSKIP
    LD A,6
    LD (CPCTIMER2), A
    LD HL,(CPCTIMER)
    INC HL
    LD (CPCTIMER),HL
	CALL MUSICPLAYER
IRQVECTORSKIP:
	POP	HL
	POP	DE
	POP	BC
	EXX
	POP	AF
	EX	AF,AF'
	POP	IY
	POP	IX
	POP	HL
	POP	DE
	POP	BC
	POP	AF
    EI
    RET   

CPCSTARTUP:
    RET

CPCVIDEOSTARTUP:
    DI
    LD A, $C3
    LD ($0038), A
    LD HL, CPCISVC
    LD ($0039), HL
    EI

	LD HL, PALETTE
	LD A, 0
	LD BC, $0F00
CPCVIDEOSTARTUPL1:
	LD A, C
	LD IXH, A
	LD A, (HL)
	LD IXL, A
	CALL SETHWPALETTE
	INC HL
	INC C
	DEC B
	JR NZ, CPCVIDEOSTARTUPL1

    RET
