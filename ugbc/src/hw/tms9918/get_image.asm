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
;*                          IMAGES ROUTINE FOR MSX1                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Get image from bitmap
; ----------------------------------------------------------------------------

; if __coleco__

; GETIMAGE:
;     CALL WAIT_VDP_HOOK
;     CALL SET_VDP_HOOK_HL
;     LD HL, GETIMAGENMI
;     CALL SET_VDP_HOOK
;     CALL WAIT_VDP_HOOK
;     RET

; GETIMAGENMI:
;     CALL GET_VDP_HOOK

; else

GETIMAGE:

; endif

GETIMAGENMI2:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD A, (CURRENTMODE)
    CP 0
    JR NZ, GETIMAGE0X
    JMP GETIMAGE0
GETIMAGE0X:
    CP 1
    JR NZ, GETIMAGE1X
    JMP GETIMAGE1
GETIMAGE1X:
    CP 2
    JR NZ, GETIMAGE2X
    JMP GETIMAGE2
GETIMAGE2X:
    CP 3
    JR NZ, GETIMAGE3X
    JMP GETIMAGE3
GETIMAGE3X:
    JP GETIMAGEDONE

GETIMAGE0:
GETIMAGE1:
GETIMAGE3:
    JP GETIMAGEDONE

GETIMAGE2:
    LD A, (HL)
    SRL A
    SRL A
    SRL A
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

    LD IXL, 0

    CALL VDPPOS

    LD DE, HL

    POP BC
    POP HL

GETIMAGE0CPA:
    PUSH BC
GETIMAGE0CP:
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    DEC C
    JR NZ, GETIMAGE0CP
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
GETIMAGE0CP2:
    DEC B
    JR NZ, GETIMAGE0CPA

    DI
    EXX
    PUSH HL
    EXX
    EI

    POP DE
    POP BC

GETIMAGE0CPCA:
    PUSH BC
GETIMAGE0CPC:
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    CALL VDPINCHAR
    LD (HL), A
    INC DE
    INC HL
    DEC C
    JR NZ, GETIMAGE0CPC
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
GETIMAGE0CP2C:
    DEC B
    JR NZ, GETIMAGE0CPCA

    JP GETIMAGEDONE

GETIMAGEDONE:
    RET