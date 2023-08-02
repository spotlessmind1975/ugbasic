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
;*                          IMAGES ROUTINE FOR MSX1                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; IMAGET:     DB 0      -> A
; IMAGEX:     DB 0      -> E
; IMAGEY:     DB 0      -> D
; IMAGEW:     DB 0      -> C
; IMAGEH:     DB 0      -> B
; IMAGEH2:    DB 0      -> ?
; PTR:        DW 0      -> HL

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------


; if __coleco__

; PUTIMAGE:
;     CALL WAIT_VDP_HOOK
;     CALL SET_VDP_HOOK_HL
;     LD HL, PUTIMAGENMI
;     CALL SET_VDP_HOOK
;     CALL WAIT_VDP_HOOK
;     RET

; PUTIMAGENMI:
;     CALL GET_VDP_HOOK

; else

PUTIMAGE:

; endif

PUTIMAGENMI2:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD A, D
    LD (IMAGEY), A

    LD A, (CURRENTMODE)
    CP 0
    JR NZ, PUTIMAGE0X
    JMP PUTIMAGE0
PUTIMAGE0X:
    CP 1
    JR NZ, PUTIMAGE1X
    JMP PUTIMAGE1
PUTIMAGE1X:
    CP 2
    JR NZ, PUTIMAGE2X
    JMP PUTIMAGE2
PUTIMAGE2X:
    CP 3
    JR NZ, PUTIMAGE3X
    JMP PUTIMAGE3
PUTIMAGE3X:
    JP PUTIMAGEDONE

PUTIMAGE0:
PUTIMAGE1:
PUTIMAGE3:
    JP PUTIMAGEDONE

PUTIMAGE2:

    LD A, D
    SRL A
    SRL A
    SRL A
    SLA A
    SLA A
    SLA A
    LD D, A


    LD A, (HL)
    INC HL
    LD B, (HL)
    SRL B
    RR A
    SRL B
    RR A
    SRL B
    RR A
    LD C, A
    INC HL
    LD A, (HL)
    SRL A
    SRL A
    SRL A
    LD B, A
    INC HL

    PUSH BC
    PUSH HL
    PUSH BC

    CALL VDPPOS

    LD DE, HL

    POP BC
    POP HL

PUTIMAGE0CPA:
    PUSH BC
PUTIMAGE0CP:
    PUSH BC
    LD B, 0
    SLA C
    SLA C
    SLA C
    CALL VDPWRITEOPT
    POP BC
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; LD A, (HL)
    ; CALL VDPOUTCHAR
    ; INC DE
    ; INC HL
    ; DEC C
    ; JR NZ, PUTIMAGE0CP
    POP BC
    PUSH HL
    PUSH BC
    LD HL, DE 
    ; LD D, 0
    ; LD A, (CURRENTTILESWIDTH)
    ; LD E, A
    ; ADC HL, DE
    ; ADC HL, DE
    ; ADC HL, DE
    ; ADC HL, DE
    ; ADC HL, DE
    ; ADC HL, DE
    ; ADC HL, DE
    ; ADC HL, DE
    LD DE, (CURRENTTILESWIDTHX8)
    ADC HL, DE
    ; LD B, 0
    ; SBC HL, BC
    ; SBC HL, BC
    ; SBC HL, BC
    ; SBC HL, BC
    ; SBC HL, BC
    ; SBC HL, BC
    ; SBC HL, BC
    ; SBC HL, BC
    LD DE, HL
    POP BC
    POP HL
PUTIMAGE0CP2:

    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, PUTIMAGE0CPAA

    DEC B
    JR NZ, PUTIMAGE0CPA

    JP PUTIMAGE0CPAAX

PUTIMAGE0CPAA:

    PUSH HL

    LD HL, DE 
    LD DE, (CURRENTTILESWIDTHX8)
    ADC HL, DE
    LD DE, HL

    POP HL

    DEC B
    JR NZ, PUTIMAGE0CPAA
    
PUTIMAGE0CPAAX:

    DI
    EXX
    PUSH HL
    EXX
    EI

    POP DE
    POP BC

PUTIMAGE0CPCA:
    PUSH BC
PUTIMAGE0CPC:
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    DEC C
    JR NZ, PUTIMAGE0CPC
    POP BC
    PUSH HL
    PUSH BC
    LD HL, DE 
    LD D, 0
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    ADC HL, DE
    ADC HL, DE
    ADC HL, DE
    ADC HL, DE
    ADC HL, DE
    ADC HL, DE
    ADC HL, DE
    ADC HL, DE
    LD B, 0
    SBC HL, BC
    SBC HL, BC
    SBC HL, BC
    SBC HL, BC
    SBC HL, BC
    SBC HL, BC
    SBC HL, BC
    SBC HL, BC
    LD DE, HL
    POP BC
    POP HL
PUTIMAGE0CP2C:
    DEC B
    JR NZ, PUTIMAGE0CPCA

    JP PUTIMAGEDONE

PUTIMAGEDONE:
    RET