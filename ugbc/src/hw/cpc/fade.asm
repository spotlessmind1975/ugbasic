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
;*                            FADE ROUTINE FOR CPC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FADETOBLACKCOLORS: 

    ; $00 (WHITE)
    DB $14, $14, $14, $14
    ; $01 (none)
    DB $14, $14, $14, $14
    ; $02 (SEA GREEN)
    DB $16, $14, $14, $14
    ; $03 (PASTEL YELLOW)
    DB $1e, $14, $14, $14
    ; $04 (BLUE)
    DB $14, $14, $14, $14
    ; $05 (none)
    DB $14, $14, $14, $14
    ; $06 (CYAN)
    DB $14, $14, $14, $14
    ; $07 (PINK)
    DB $1C, $14, $14, $14
    ; $08 (PURPLE)
    DB $1C, $14, $14, $14
    ; $09 (none)
    DB $14, $14, $14, $14
    ; $0A (LIGHT YELLOW)
    DB $1e, $14, $14, $14
    ; $0b (LIGHT WHITE)
    DB $00, $14, $14, $14
    ; $0c (LIGHT RED)
    DB $1C, $14, $14, $14
    ; $0d (LIGHT MAGENTA)
    DB $18, $14, $14, $14
    ; $0e (ORANGE)
    DB $1C, $14, $14, $14
    ; $0f (PASTEL MAGENTA)
    DB $18, $14, $14, $14
    ; $10 (none)
    DB $14, $14, $14, $14
    ; $11 (none)
    DB $14, $14, $14, $14
    ; $12 (LIGHT GREEN)
    DB $16, $14, $14, $14
    ; $13 (LIGHT CYAN)
    DB $06, $14, $14, $14
    ; $14 (BLACK)
    DB $14, $14, $14, $14
    ; $15 (LIGHT BLUE)
    DB $04, $14, $14, $14
    ; $16 (GREEN)
    DB $14, $14, $14, $14
    ; $17 (DARK CYAN)
    DB $04, $14, $14, $14
    ; $18 (MAGENTA)
    DB $14, $14, $14, $14
    ; $19 (PASTEL GREEN)
    DB $16, $14, $14, $14
    ; $1a (LIME)
    DB $16, $14, $14, $14
    ; $1b (PASTEL CYAN)
    DB $06, $14, $14, $14
    ; $1c (RED)
    DB $14, $14, $14, $14
    ; $1d (MAUVE)
    DB $04, $14, $14, $14
    ; $1e (YELLOW)
    DB $14, $14, $14, $14

FADESTEP:   DB 4
FADEDURATION: DW 0
FADERESETDURATION: DW 0

FADET:
    PUSH DE
    PUSH HL
    PUSH BC

    LD A, (FADESTEP)
    CP 4
    JP Z, FADETDONE

FADET2:
    LD DE, (FADEDURATION)
    DEC DE
    LD (FADEDURATION), DE
    LD A, E
    OR D
    JR NZ, FADETDONE

    LD HL, PALETTE
    LD IXH, 0
FADET4:
    LD A, (HL)
    PUSH HL
    LD HL, FADETOBLACKCOLORS
    SLA A
    SLA A
    LD B, A
    LD A, (FADESTEP)
    ADD B
    LD E, A
    LD D, 0
    ADC HL, DE
    LD A, (HL)
    POP HL
    LD (HL), A
    LD IXL, A
    CALL SETHWPALETTE
    INC IXH
    INC HL
    LD A, IXH
    CP 16
    JR NZ, FADET4

    LD DE, (FADERESETDURATION)
    LD (FADEDURATION), DE

    LD A, (FADESTEP)
    INC A
    LD (FADESTEP), A

FADETDONE:

    POP BC
    POP HL
    POP DE

    RET

    