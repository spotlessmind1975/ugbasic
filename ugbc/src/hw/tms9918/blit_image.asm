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
;*                          IMAGES ROUTINE FOR TMS9918                         *
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

BLITIMAGEPIXEL:

    PUSH HL
    LD HL, (BLITTMPPTR)
    LD A, (HL)
    POP HL
    LD B, A
    CALL VDPINCHAR
    LD IYL, A
    PUSH HL
    LD HL, (BLITTMPPTR2)
    LD A, (HL)
    POP HL
    LD IYH, A
    PUSH HL
    CALL BLITIMAGEBLITTING
    POP HL
    CALL VDPOUTCHAR
    PUSH HL
    LD HL, (BLITTMPPTR)
    INC HL
    LD (BLITTMPPTR), HL
    LD HL, (BLITTMPPTR2)
    INC HL
    LD (BLITTMPPTR2), HL
    POP HL

    INC DE
    INC HL

    RET

BLITIMAGEBLITTING:
    LD HL, (BLITIMAGEBLITTINGADDR)
	JP (HL)

    NOP
    NOP
    NOP
    NOP

; if __coleco__

; BLITIMAGE:
;     CALL WAIT_VDP_HOOK
;     CALL SET_VDP_HOOK_HL
;     LD HL, BLITIMAGENMI
;     CALL SET_VDP_HOOK
;     CALL WAIT_VDP_HOOK
;     RET

; BLITIMAGENMI:
;     CALL GET_VDP_HOOK

; else

BLITIMAGE:
    NOP
    NOP
    NOP
    NOP

; endif

BLITIMAGENMI2:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD A, (CURRENTMODE)
    CP 0
    JR NZ, BLITIMAGE0X
    JMP BLITIMAGE0
BLITIMAGE0X:
    CP 1
    JR NZ, BLITIMAGE1X
    JMP BLITIMAGE1
BLITIMAGE1X:
    CP 2
    JR NZ, BLITIMAGE2X
    JMP BLITIMAGE2
BLITIMAGE2X:
    CP 3
    JR NZ, BLITIMAGE3X
    JMP BLITIMAGE3
BLITIMAGE3X:
    JP BLITIMAGEDONE

BLITIMAGE0:
BLITIMAGE1:
BLITIMAGE3:
    JP BLITIMAGEDONE

BLITIMAGE2:

    LD A, D
    SRL A
    SRL A
    SRL A
    SLA A
    SLA A
    SLA A
    LD D, A

    LD HL, (BLITTMPPTR)

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
    LD (BLITTMPPTR), HL

    PUSH HL
    LD HL, (BLITTMPPTR2)
    INC HL
    INC HL
    INC HL
    LD (BLITTMPPTR2), HL
    POP HL

    PUSH BC
    PUSH HL
    PUSH BC

    CALL VDPPOS

    LD DE, HL

    POP BC
    POP HL

BLITIMAGE0CPA:
    PUSH BC
BLITIMAGE0CP:

    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL
    CALL BLITIMAGEPIXEL

    DEC C
    JP NZ, BLITIMAGE0CP
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
BLITIMAGE0CP2:
    DEC B
    JP NZ, BLITIMAGE0CPA

    DI
    EXX
    PUSH HL
    EXX
    EI

    POP DE
    POP BC

    LD A, (IMAGET)
    AND $02
    CMP $02
    JP NZ, BLITIMAGEDONE

BLITIMAGE0CPCA:
    PUSH BC

    LD HL, (BLITTMPPTR)

BLITIMAGE0CPC:
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
    
    LD (BLITTMPPTR), HL

    DEC C
    JR NZ, BLITIMAGE0CPC
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
BLITIMAGE0CP2C:
    DEC B
    JP NZ, BLITIMAGE0CPCA

    JP BLITIMAGEDONE

BLITIMAGEDONE:
    RET