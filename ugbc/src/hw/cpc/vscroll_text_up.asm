; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                          VERTICAL SCROLL ON CPC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VSCROLLTUP:

    PUSH IX

    ; On original routine, we scroll an entire line of 80 bytes (no matter
    ; resolution, in this case). Instead, we have to calculate the number
    ; of bytes effectively to copy. The number is given by CONSOLESL.

    LD A, (CONSOLEWB)
    ADD 8
    LD IXL, A

    ; LD BC, 192
    ; On original routine, we scroll an entire screen of 24 x 8 = 192 lines.
    ; In this case, however, we have to scroll a console of CONSOLEH x 8 lines.
    
    ; BC = CONSOLEH

    LD A, (CONSOLEH)
    LD C, A
    LD B, 0

    ; BC = BC x 8

    SLA C
    RL B
    SLA C
    RL B
    SLA C
    RL B

    ; Retrieve the starting address for line addresses.

    LD HL, PLOTVBASE

    ; Originally, we take the address of first and second text line.
    ; In this case, we must take the address of CONSOLEY1 and CONSOLEY+1
    ; line. 

    ; DE = CONSOLEY1

    LD A, (CONSOLEY1)
    LD E, A
    LD D, 0
    
    ; DE = CONSOLEY1 x 2

    SLA E
    RL D

    ; HL = HL + DE

    ADD HL, DE

    ; If just one line, we do not scroll!
    LD A, C
    SUB 8
    OR C
    JR Z, VSCROLLREFILL

VSCROLLTUPL1:

    PUSH BC
    PUSH HL

    ; Now we take the address of CONSOLEY1 line

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    INC HL

    ; Move forward to the address of CONSOLEY1+1 line

    ADD HL, 14

    ; Take the address of CONSOLEY1+1 line

    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A
    LD HL, BC

    ; We copy the calculated number of bytes.

    LD A, IXL
    LD C, A
    LD B, 0
    LDIR

    POP HL
    POP BC

    ; Move to the next line.

    INC HL
    INC HL

    ; Decrease the number of lines to copy.

    DEC C

    ; Repeat until finished.

    JP NZ, VSCROLLTUPL1

VSCROLLREFILL:

    ; Finally, we are to fill the lower (text) line.

    LD BC, 8

VSCROLLTUPL2:

    PUSH BC
    PUSH HL

    ; Retrieve the line to fill.

    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A
    LD HL, BC

    ; Fill with zero.

    LD A, 0
    LD (HL), A

    ; Move to the next byte

    LD E, L
    LD D, H
    INC DE

    ; Copy the exact number of bytes needed

    LD A, IXL
    LD C, A
    LD B, 0

    LDIR

    POP HL
    POP BC

    ; Move to the next line.

    INC HL
    INC HL

    ; Decrement the number of lines to fill.

    DEC C

    ; Repeat until finished.

    JP NZ, VSCROLLTUPL2

    POP IX

    RET
