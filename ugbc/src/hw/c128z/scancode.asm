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
;*                      SCAN CODE ROUTINE FOR C128Z                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
;*                      KEYBOARD MATRIX DETECTION ON C=128                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

KEYBOARDMAP:
	; 		INST/DEL, Return, CRSR =>,  F7,  F1,  F3,  F5,  CRSR|V
	DEFB 	     $08,    $0d,     $00, $00, $00, $00, $00,     $00
	; 		     #/3,    W,       A,    $/4,   Z,   S,   E,   Left Shift/Shift Lock
	DEFB        '3',  'W',     'A',    '4', 'Z', 'S', 'E',    $00
	;            %/5,    R,       D,    &/6,   C,   F,   T,      X
	DEFB        '5',  'R',     'D',    '6', 'C', 'F', 'T',    'X'
	;            '/7,    Y,       G,    (/8,   B,   H,   U,      V
	DEFB        '7',  'Y',     'G',    '8', 'B', 'H', 'U',    'V'
	;	         )/9,    I,       J,      0,   M,   K,   O,      N
	DEFB        '9',  'I',     'J',    '0', 'M', 'K', 'O',    'N'
	;              +,    P,       L,      -, >/., [/:, @/<,      ,
	DEFB        '+',  'P',     'L',    '-', '.', ':', '<',    ','
	;              £,    *,     ]/;,     CH,  RS,  =,    ^,   ?//
	DEFB        'L',  '*',     ';',    $00, $00, '=', '^',    '/'
	;            !/1,   <-,    CTRL,    "/2, SPC,  C=,   Q, RUN STOP
	DEFB        '1',  $00,     $00,    '2', ' ', $00, 'Q',    $00
	;           HELP,    8,       5,    TAB,   2,   4,   7,      1
	DEFB		 $00,  '8',     '5',      9, '2', '4', '7',    '1'
	;            ESC,    +,       -,     LF, CR,    6,   9,      3
	DEFB         27,  '+',     '-',    $00,$0d,  '6', '9',    '3'
	;            ALT,    0,       .,     UP,DWN, LFT, RGT, NOSCROLL
	DEFB        $00,  '0',     '.',    $00,$00, $00, $00, $00

SCANCODEREAD:
	DEFB $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF

SCANCODEFULL:
    PUSH HL
    PUSH AF
    PUSH BC

	; Also note you must store $FF in the "row select register" you are not using. 
	; This means if you want to read from any 8 of the $DC00 rows (top 8 rows), 
	; you store $FF in $D02F because you are not using $D02F now. 
	; Likewise, to read any 3 of the $D02F rows, be sure to store $FF into $DC00.

	LD A, $FF

	; LD ($D02F), A
    LD BC, $D02F
    OUT (C), A

	; The normal way (like done by the KERNAL ROM) is to store a value in $DC00 
	; (or $D02F) as indicated on the left-most column that runs up-down the table. 
	; Which ever value you choose corresponds to the row of keys listed to the right. 
	; Then read a value from $DC01. If no key in that row is choosen, you will 
	; read $FF. Otherwise, the value you read will be listed at the top of the table, 
	; in the same column as the key that was pressed.

	LD C, 8
	LD A, $FE
	SCF
    LD HL, SCANCODEREAD
SCANCODEFULLL1:

	; LD ($DC00), A

    PUSH BC
    LD BC, $DC00
    OUT (C), A
    POP BC

	PUSH AF

	; LD A, ($DC01)

    PUSH BC
    LD BC, $DC01
    IN A, (C)
    POP BC

	LD (HL),A
	POP AF
	RL A
	INC HL
    DEC C
	JR NZ, SCANCODEFULLL1

	; Let's do an example. To read the second $DC00 row, notice the value in left column
	; is $FD. Store $FD in $DC00. In this row you can check 3(#), W, A, 4($), Z, S, E, 
	; and SHIFT keys.

	LD A, $FF
	; LD ($DC00), A

    PUSH BC
    LD BC, $DC00
    OUT (C), A
    POP BC

	; Next read $DC01. If you read $FF then no keys in second row are pressed. If you 
	; read $EF then the "Z" key is pressed (notice at top of table above "Z" is value $EF).

    LD C, 3
	LD A, $FE
	SCF
SCANCODEFULLL2:

	; LD ($D02F), A

    PUSH BC
    LD BC, $D02F
    OUT (C), A
    POP BC

	PUSH AF

	; LD A, ($DC01)

    PUSH BC
    LD BC, $DC01
    IN A, (C)
    POP BC

	LD (HL), A
	POP AF
	RL A
    INC HL
	DEC C
	JR NZ, SCANCODEFULLL2

	; Finally, when you are done checking the keyboard, it is a good idea to store $7F into $DC00 
	; (and also $FF into $D02F). This is because the eigth row contains the STOP key, and the 
	; KERNAL ROM expects this row to be active so it can check for STOP key pressed by 
	; simply reading $DC01.

	LD A, $7F
	; LD ($DC00), A
    PUSH BC
    LD BC, $DC00
    OUT (C), A
    POP BC


	LD A, $FF
	; LD ($D02F), A
    PUSH BC
    LD BC, $D02F
    OUT (C), A
    POP BC

    POP BC
    POP AF
    POP HL

	RET

SCANCODE:

    PUSH BC
    PUSH HL
    
	CALL SCANCODEFULL

    LD HL, SCANCODEREAD
    LD BC, 11

SCANCODEL1:
	LD A, (HL)
	CMP $FF
	JR NZ, SCANCODEKEY
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
    INC B
	INC HL
    DEC C
    JR NZ, SCANCODEL1

    POP HL
    POP BC
    LD A, 0    
	RET

SCANCODEKEY:
	XOR $FF
SCANCODEKEYL1:
	SRL A
	JR C, SCANCODEKEYPRESSED
	INC B
	CMP 0
	JR NZ, SCANCODEKEYL1
	LD A, 0
    POP HL
    POP BC
	RET

SCANCODEKEYPRESSED:
	LD A, B
    POP HL
    POP BC
	RET

INKEY:
    PUSH DE
    PUSH BC
    PUSH HL
	CALL SCANCODE
	CMP 0
	JR Z, INKEY0
	LD B, A
INKEYL1:
	CALL SCANCODE
	CMP B
	JR Z, INKEYL1 
	LD A, B
	LD E, A
    LD A, 0
    LD D, A
    LD HL, KEYBOARDMAP 
    ADD HL, DE
    LD A, (HL)
INKEY0:
    POP HL
    POP BC
    POP DE
	RET
