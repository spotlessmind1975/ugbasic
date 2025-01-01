; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                          VERTICAL SCROLL ON ZX SPECTRUM                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLL:
    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    PUSH IY
    PUSH IX
    CP $80
    JP C, VSCROLLDOWN

; ------------------------------------------------------------
; | SCROLL UP
; ------------------------------------------------------------

VSCROLLUP:
    
    ; Calculate offset for scrolling (B 2 complemented)
    XOR $FF
    ADD A, 1
    LD B, A

VSCROLLUPL:

    ; Get the height of the window scrolling (in bytes).

    LD A, (CONSOLEH)
    SLA A
    SLA A
    SLA A
    LD C, A

    ; We have to scroll just the height minus 
    ; the number of rows to scroll.

    LD A, C
    SUB A, B
    LD C, A

    ; Lookup table will do the magic.

    LD IX, ROWSADDRESS

    ; Lookup for first row (CONSOLEY1)

    PUSH BC
    LD A, (CONSOLEY1)
    CP 0
    JR Z, ROWSELECTUP
    SLA A
    SLA A
    SLA A
    LD C, A
ROWSELECTUPC:
    INC IX
    INC IX
    DEC C
    JR NZ, ROWSELECTUPC
ROWSELECTUP:
    POP BC


    PUSH IX
ROWSELECTREPEAT:
    POP IX
    PUSH IX

    ; Retrieve the address of the first (n-th) row in DE.

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX

    ; Now we move ahead, to take address of the "second" row.

    PUSH B
    DEC B
    JR Z, ROWSELECTUP1
ROWSELECTUP0:
    INC IX
    INC IX
    DEC B
    JR NZ, ROWSELECTUP0
ROWSELECTUP1:
    POP B

    ; Retrieve the address of the "second" (nth+1) row in HL.

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    ; Now we can copy the row (HL -> DE)

    CALL ROWCOPY

    ; Move to the next row.
    
    POP IX
    INC IX
    INC IX
    PUSH IX

    ; Decrement the number of rows to copy. 
    ; If not finished, continue with the next row.

    DEC C
    JR NZ, ROWSELECTREPEAT

    ; The last line will be cleared.

    PUSH HL
    POP DE

;     ; Clear all lines scrolled.

    LD IYL, 0
    PUSH B
    DEC B
    JR Z, ROWSELECTUP5
ROWSELECTUP4:
    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX
    CALL ROWCLEAR
    DEC B
    JR NZ, ROWSELECTUP4
ROWSELECTUP5:
    POP B

    POP IX

    ;
    ; ---------------------------------------------

VSCROLLUPLC:

    ; Get the height of the window scrolling (in bytes).

    LD A, (CONSOLEH)
    LD C, A
    DEC C

    ; Lookup table will do the magic.

    LD IX, COLRADDRESS

    LD A, B
    SRL A
    SRL A
    SRL A
    LD B, A

    ; Lookup for first row (CONSOLEY1)

    PUSH BC
    LD A, (CONSOLEY1)
    CP 0
    JR Z, ROWSELECTUPC20
    LD C, A
ROWSELECTUPC2:
    INC IX
    INC IX
    DEC C
    JR NZ, ROWSELECTUPC2
ROWSELECTUPC20:
    POP BC

    ; Retrieve the address of the first row in DE.

ROWCSELECTUPC:

    PUSH IX
ROWSELECTREPEATC:
    POP IX
    PUSH IX

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX

    ; Now we move ahead, to take address of the "second" row.

    PUSH B
    LD A, B
    CP 1
    JR Z, ROWCSELECTUP1C
ROWCSELECTUP0C:
    INC IX
    INC IX
    DEC B
    JR NZ, ROWCSELECTUP0C
ROWCSELECTUP1C:
    POP B

    ; Retrieve the address of the "second" row in HL.

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    ; Now we can copy the row (HL -> DE)

    CALL ROWCOPY

    POP IX
    INC IX
    INC IX
    PUSH IX

    ; Decrement the number of rows to copy. 
    ; If not finished, continue with the next row.

    DEC C
    JR NZ, ROWSELECTREPEATC

    ; The last line will be cleared.

    LD A, (_PAPER)
    AND $7
    SLA A
    SLA A
    SLA A    
    LD IYL, A
    LD A, (CONSOLEH)
    CP 0
    JR Z, ROWCSELECTUPC5
    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX
    CALL ROWCLEAR
ROWCSELECTUPC5:

    POP IX

    JP VSCROLLE

; ------------------------------------------------------------
; | SCROLL DOWN
; ------------------------------------------------------------

VSCROLLDOWN:
    LD B, A
VSCROLLDOWNL:
    LD C, 192

    LD A, C
    SUB A, B
    LD C, A

    LD IX, ROWSADDRESSL
ROWSELECTDOWN:

    DEC IX
    DEC IX

    PUSH B
    DEC B
    JR NZ, ROWSELECTDOWN1
ROWSELECTDOWN0:
    DEC IX
    DEC IX
    DEC B
    JR NZ, ROWSELECTDOWN0
ROWSELECTDOWN1:
    POP B

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    PUSH B
    DEC B
    JR Z, ROWSELECTDOWN2
ROWSELECTDOWN3:
    INC IX
    INC IX
    JR NZ, ROWSELECTDOWN3
ROWSELECTDOWN2:
    POP B

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX

    DEC IX
    DEC IX
    DEC IX
    DEC IX

    PUSH B
    DEC B
    JR Z, ROWSELECTDOWN5
ROWSELECTDOWN4:
    DEC IX
    DEC IX
    DEC B
    JR NZ, ROWSELECTDOWN4
ROWSELECTDOWN5:
    POP B

    CALL ROWCOPY
    DEC C
    JR NZ, ROWSELECTDOWN

    PUSH B
    DEC B
    JR Z, ROWSELECTDOWN7
ROWSELECTDOWN6:
    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A
    INC IX
    CALL ROWCLEAR    
    DEC B
    JR NZ, ROWSELECTDOWN6
ROWSELECTDOWN7:
    POP B

    LD IX, COLRADDRESSL

    LD A, (IX)
    LD L, A
    INC IX
    LD A, (IX)
    LD H, A
    INC IX

    DEC IX
    DEC IX

    PUSH B
    DEC B
    JR Z, ROWCSELECTDOWNL2 
ROWCSELECTDOWNL:
    DEC IX
    DEC IX
    DEC B
    JR NZ, ROWCSELECTDOWNL
ROWCSELECTDOWNL2:
    POP B

    LD A, (IX)
    LD E, A
    INC IX
    LD A, (IX)
    LD D, A

    LD A, B

    SRA A
    SRA A
    SRA A
    SRA A
    SRA A

    JR NZ, ROWCSELECTDOWNL3A

    LD A, 1

ROWCSELECTDOWNL3A:

    PUSH HL
    PUSH DE
    LD HL, $280
    LD DE, $20
    DEC A
    JR Z, ROWCSELECTDOWNL4
ROWCSELECTDOWNL3:
    SBC HL, DE
    DEC A
    JR NZ, ROWCSELECTDOWNL3
ROWCSELECTDOWNL4:
    LD BC, HL
    POP DE
    POP HL
    LDIR

    JP VSCROLLE

;;;;;;;;;;;;;;;;;;;

ROWCOPY:
    PUSH HL
    PUSH BC
    PUSH DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD BC, DE
    POP DE
    PUSH HL
    LD HL, DE
    LD DE, BC
    ADD HL, DE
    LD DE, HL
    POP HL
    LD A, (CONSOLEW)
    LD B, A
ROWCOPYL:
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, ROWCOPYL
    POP BC
    POP HL
    RET

ROWCLEAR:
    PUSH BC
    LD HL, DE
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD DE, HL
    LD A, (CONSOLEW)
    LD B, A
    LD A, IYL
ROWCLEARL:
    LD (DE), A
    INC DE
    DEC B
    JR NZ, ROWCLEARL
    POP BC
    RET

VSCROLLE:
    POP IX
    POP IY
    POP HL
    POP DE
    POP BC
    POP AF
    RET

