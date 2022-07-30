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
;*                          STARTUP ROUTINE FOR EF9345                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; WAIT UNTIL EF9345 IS FREE
EF9345WAIT:
    LD A, $20
    OUT ($8F), A
EF9345WAITL1:
    IN A, ($CF)
    OR A
    JP M, EF9345WAITL1
    RET

; INITIALIZE THE GRAPHIC CARD
;   HL = address of commands to execute
EF9345INIT:
    LD B, (HL)
    INC HL
EF9345INIT2:
    CALL EF9345WAIT
    LD C, $8F
    OUTI
    LD C, $CF
    OUTI
    JR NZ, EF9345INIT2
    RET

; SET A REGISTER
;    D = register number
;    E = register value
EF9345SETREG:
    LD C, $8F
    OUT (C), D
    LD C, $CF
    OUT (C), E
    RET

; GET A REGISTER
;    D = register number
;    E = register value
EF9345GETREG:
    PUSH AF
    LD C, $8F
    OUT (C), D
    LD C, $CF
    IN A, (C)
    LD E, A
    POP AF
    RET

; SET A REGISTER WHEN CARD IS READY
;    D = register number
;    E = register value
EF9345LIB:
    PUSH BC
    PUSH AF
    CALL EF9345WAIT
    CALL EF9345SETREG
    POP AF
    POP BC
    RET

; GET A REGISTER WHEN CARD IS READY
;    D = register number
;    E = register value
EF9345LIBR:
    PUSH BC
    PUSH AF
    CALL EF9345WAIT
    CALL EF9345GETREG
    POP AF
    POP BC
    RET

; Startup for EF9345
EF9345STARTUP:

    ; Disable interrupt.
    DI

    ; Save used registers
    PUSH HL
    PUSH IX

    ; Initialize the graphic card
    LD HL, EF9345CONFIG
    CALL EF9345INIT

    ; Restore registers
    POP IX
    POP HL

    ; Re-enable interrupts.
    EI

    RET

EF9345CONFIG:
    DB  $16                 ; size of configuration
    DB  $21, $00, $28, $81  ; Long command mode
    DB  $21, $7F, $28, $83  ; PAT
    DB  $21, $02, $28, $82  ; MAT green margin color no cursor fixed characters
    DB  $21, $23, $28, $84  ; DOR video memory sharing

