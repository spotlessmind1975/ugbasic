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
	.BYTE 	     $08,    $0d,     $00, $00, $00, $00, $00,     $00
	; 		     #/3,    W,       A,    $/4,   Z,   S,   E,   Left Shift/Shift Lock
	.BYTE        '3',  'W',     'A',    '4', 'Z', 'S', 'E',    $00
	;            %/5,    R,       D,    &/6,   C,   F,   T,      X
	.BYTE        '5',  'R',     'D',    '6', 'C', 'F', 'T',    'X'
	;            '/7,    Y,       G,    (/8,   B,   H,   U,      V
	.BYTE        '7',  'Y',     'G',    '8', 'B', 'H', 'U',    'V'
	;	         )/9,    I,       J,      0,   M,   K,   O,      N
	.BYTE        '9',  'I',     'J',    '0', 'M', 'K', 'O',    'N'
	;              +,    P,       L,      -, >/., [/:, @/<,      ,
	.BYTE        '+',  'P',     'L',    '-', '.', ':', '<',    ','
	;              £,    *,     ]/;,     CH,  RS,  =,    ^,   ?//
	.BYTE        'L',  '*',     ';',    $00, $00, '=', '^',    '/'
	;            !/1,   <-,    CTRL,    "/2, SPC,  C=,   Q, RUN STOP
	.BYTE        '1',  $00,     $00,    '2', ' ', $00, 'Q',    $00
	;           HELP,    8,       5,    TAB,   2,   4,   7,      1
	.BYTE		 $00,  '8',     '5',      9, '2', '4', '7',    '1'
	;            ESC,    +,       -,     LF, CR,    6,   9,      3
	.BYTE         27,  '+',     '-',    $00,$0d,  '6', '9',    '3'
	;            ALT,    0,       .,     UP,DWN, LFT, RGT, NOSCROLL
	.BYTE        $00,  '0',     '.',    $00,$00, $00, $00, $00


SCANCODEREAD:
	.BYTE $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF, $FF

SCANCODEFULL:

	; Also note you must store $FF in the "row select register" you are not using. 
	; This means if you want to read from any 8 of the $DC00 rows (top 8 rows), 
	; you store $FF in $D02F because you are not using $D02F now. 
	; Likewise, to read any 3 of the $D02F rows, be sure to store $FF into $DC00.

	LDA #$FF
	STA $D02F

	; The normal way (like done by the KERNAL ROM) is to store a value in $DC00 
	; (or $D02F) as indicated on the left-most column that runs up-down the table. 
	; Which ever value you choose corresponds to the row of keys listed to the right. 
	; Then read a value from $DC01. If no key in that row is choosen, you will 
	; read $FF. Otherwise, the value you read will be listed at the top of the table, 
	; in the same column as the key that was pressed.

	LDY #0
	LDA #$FE
	SEC
SCANCODEFULLL1:
	STA $DC00
	PHA
	LDA $DC01
	STA (TMPPTR),Y
	PLA
	ROL A
	INY
	CPY #8
	BNE SCANCODEFULLL1

	; Let's do an example. To read the second $DC00 row, notice the value in left column
	; is $FD. Store $FD in $DC00. In this row you can check 3(#), W, A, 4($), Z, S, E, 
	; and SHIFT keys.

	LDA #$FF
	STA $DC00

	; Next read $DC01. If you read $FF then no keys in second row are pressed. If you 
	; read $EF then the "Z" key is pressed (notice at top of table above "Z" is value $EF).

	LDA #$FE
	SEC
SCANCODEFULLL2:
	STA $D02F
	PHA
	LDA $DC01
	STA (TMPPTR),Y
	PLA
	ROL A
	INY
	CPY #11
	BNE SCANCODEFULLL2

	; Finally, when you are done checking the keyboard, it is a good idea to store $7F into $DC00 
	; (and also $FF into $D02F). This is because the eigth row contains the STOP key, and the 
	; KERNAL ROM expects this row to be active so it can check for STOP key pressed by 
	; simply reading $DC01.

	LDA $7F
	STA $DC00
	LDA $FF
	STA $D02F

	RTS

SCANCODE:

	LDA #<SCANCODEREAD
	STA TMPPTR
	LDA #>SCANCODEREAD
	STA TMPPTR+1

	JSR SCANCODEFULL

	LDX #0
	LDY #0
SCANCODEL1:
	LDA (TMPPTR),Y
	CMP #$FF
	BNE SCANCODEKEY
	INx
	INx
	INx
	INx
	INx
	INx
	INx
	INx
	INY
	CPY #11
	BNE SCANCODEL1

	JMP SCANCODENO

SCANCODEKEY:
	EOR #$FF
SCANCODEKEYL1:
	LSR A
	BCS SCANCODEKEYPRESSED
	INX
	CMP #$0
	BNE SCANCODEKEYL1

	JMP SCANCODENO

SCANCODEKEYPRESSED:
	
    CPX KBDCHAR
    BNE SCANCODEDIFF3

    LDA KBDDELAYC
    BEQ SCANCODEDIFF2

    DEC KBDDELAYC
    BNE SCANCODEDELAYED

SCANCODEDIFF2:
    LDA KBDRATEC
    BEQ SCANCODEDIFF

    DEC KBDRATEC
    BEQ SCANCODEDIFF
    JMP SCANCODEDELAYED

SCANCODEDIFF:
    STX KBDCHAR
    LDA KBDRATE
    STA KBDRATEC
	TXA
    RTS

SCANCODEDIFF3:
    STX KBDCHAR
    LDA KBDRATE
    STA KBDRATEC
    LDA KBDDELAY
    STA KBDDELAYC
SCANCDENODELAY:
    TXA
    RTS

SCANCODENO:
    LDA #$0
    STA KBDCHAR
SCANCODEDELAYED:    
    ; JSR KBDWAITVBL
INKEYNO:
    LDA #$0
    RTS

KBDWAITVBL:
    LDA $d012
    BNE KBDWAITVBL
KBDWAITVBL2:
    LDA $d012
    BEQ KBDWAITVBL2
    RTS


INKEY:
	JSR SCANCODE
	CMP #0
	BEQ INKEY0
	TAY
	LDA #<KEYBOARDMAP
	STA TMPPTR
	LDA #>KEYBOARDMAP
	STA TMPPTR+1
	LDA (TMPPTR),Y
	RTS
INKEY0:
	RTS
