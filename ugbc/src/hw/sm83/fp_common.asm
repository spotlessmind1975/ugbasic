; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2024 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from modules/z80float, copyright 2018 Zeda A.K. Thomas
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

ADC_HL_BC:
    JR      NC, ADC_HL_BC_CARRY0
    INC     HL
ADC_HL_BC_CARRY0:
    ADD     HL, BC
    RET

REPLACEMENT_CPI:
    JR      C, REPLACEMENT_CPI_CPIWCARRY

    CP      (HL)
    INC     HL
    DEC     BC

    PUSH    AF
    CALL EX_SP_HL
    RES     0, L                    ; CLEAR CARRY

REPLACEMENT_CPI_REJOIN:

    SET     2, L                    ; SET P/V -> BC != 0

    LD      A, B
    OR      C
    JR      NZ, REPLACEMENT_CPI_EXITCPI
    RES     2, L                    ; CLEAR P/V -> BC == 0

REPLACEMENT_CPI_EXITCPI:

    CALL EX_SP_HL
    POP     AF
    RET

REPLACEMENT_CPI_CPIWCARRY:

    CP      (HL)
    INC     HL
    DEC     BC

    PUSH    AF
    CALL EX_SP_HL
    SET     0, L                    ; SET CARRY
    JR      REPLACEMENT_CPI_REJOIN


REPLACEMENT_LDI:
    PUSH    AF                      ;SAVE INCOMING FLAGS
    LD      A, (HL+)
    LD      (DE+), A
    DEC     BC
    POP     AF                      ;AND RESTORE OUR MODIFIED AF
    RET


REPLACEMENT_CPIR:

    JR      NC, REPLACEMENT_CPIR_ENTERLOOP

    CALL    REPLACEMENT_CPIR_ENTERLOOP

    PUSH    AF
    CALL EX_SP_HL
    SET     0, L                    ; SET CARRY
    JR      REPLACEMENT_CPIR_RETFLAGS

REPLACEMENT_CPIR_LOOP:

    INC     HL

REPLACEMENT_CPIR_ENTERLOOP:

    DEC     BC
    CP      (HL)                    ; COMPARE, SET FLAGS
    JR      Z, REPLACEMENT_CPIR_MATCH

    INC     C
    DEC     C
    JR      NZ, REPLACEMENT_CPIR_LOOP

    INC     B
    DJNZ    REPLACEMENT_CPIR_LOOP

    CP      (HL)                    ; COMPARE, SET FLAGS
    INC     HL
    PUSH    AF

REPLACEMENT_CPIR_JOINBC0:

    CALL EX_SP_HL
    RES     0, L                    ; CLEAR CARRY
    RES     2, L                    ; CLEAR P/V -> BC == 0
    JR      REPLACEMENT_CPIR_RETFLAGS

REPLACEMENT_CPIR_MATCH:

    INC     HL
    PUSH    AF

    LD      A, B
    OR      C
    JR      Z, REPLACEMENT_CPIR_JOINBC0

    CALL EX_SP_HL
    RES     0, L                    ; CLEAR CARRY
    SET     2, L                    ; SET P/V -> BC != 0

REPLACEMENT_CPIR_RETFLAGS:
    CALL EX_SP_HL
    POP     AF
    RET

REPLACEMENT_LDDR:
        PUSH    AF

        DEC     BC
        INC     B
        INC     C
REPLACEMENT_LDDR_LOOP:
        LD      A, (HL-)
        LD      (DE-), A

        DEC     C
        JP      NZ, REPLACEMENT_LDDR_LOOP
        DEC     B
        JP      NZ, REPLACEMENT_LDDR_LOOP

        POP     AF
        RET

EX_SP_HL:
    PUSH    AF                      ;16
    PUSH    DE                      ;16
    LD      D, H                    ;4			DE = HL0
    LD      E, L                    ;4
    LD      HL, SP+6                ;12, (SP)	HL = & SP0
    LD      A, (HL)                 ;8
    LD      (HL), E                 ;8
    LD      E, A                    ;4			SWAP LOW HL0, SP0
    INC     HL                      ;8			HL = & SP0+1
    LD      A, (HL)                 ;8
    LD      (HL), D                 ;8
    LD      H, A                    ;4			SWAP HI HL0, SP0 -> HL
    LD      L, E                    ;4
    POP     DE                      ;12
    POP     AF                      ;12
    RET                             ;16

