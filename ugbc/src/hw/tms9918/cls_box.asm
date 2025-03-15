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
;*                          CLS BOX ROUTINE FOR MSX1                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLSBOX:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD A, D
    LD (IMAGEY), A

    LD A, (CURRENTMODE)
    CP 0
    JR NZ, CLSBOX0X
    JMP CLSBOX0
CLSBOX0X:
    CP 1
    JR NZ, CLSBOX1X
    JMP CLSBOX1
CLSBOX1X:
    CP 2
    JR NZ, CLSBOX2X
    JMP CLSBOX2
CLSBOX2X:
    CP 3
    JR NZ, CLSBOX3X
    JMP CLSBOX3
CLSBOX3X:
    JP CLSBOXDONE

CLSBOX0:
CLSBOX1:
CLSBOX3:
    JP CLSBOXDONE

CLSBOX2:

    LD A, D
    SRL A
    SRL A
    SRL A
    SLA A
    SLA A
    SLA A
    LD D, A

    SRL B
    SRL B
    SRL B
    SRL C
    SRL C
    SRL C

    PUSH BC
    PUSH HL
    PUSH BC

    CALL VDPPOS

    LD DE, HL

    POP BC
    POP HL

CLSBOX0CPA:
    PUSH BC
CLSBOX0CP:
    PUSH BC
    LD B, 0
    SLA C
    SLA C
    SLA C
    CALL VDPWRITEOPT
    POP BC
    POP BC
    PUSH HL
    PUSH BC
    LD HL, DE 
    LD DE, (CURRENTTILESWIDTHX8)
    ADD HL, DE
    LD DE, HL
    POP BC
    POP HL
CLSBOX0CP2:

    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, CLSBOX0CPAA

    DEC B
    JR NZ, CLSBOX0CPA

    JP CLSBOX0CPAAX

CLSBOX0CPAA:

    PUSH HL

    LD HL, DE 
    LD DE, (CURRENTTILESWIDTHX8)
    ADD HL, DE
    LD DE, HL

    POP HL

    DEC B
    JR NZ, CLSBOX0CPAA
    
CLSBOX0CPAAX:

    DI
    EXX
    PUSH HL
    EXX
    EI

    POP DE
    POP BC

CLSBOX0CPCA:
    PUSH BC
CLSBOX0CPC:
    LD A, 0
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    CALL VDPOUTCHAR
    INC DE
    DEC C
    JR NZ, CLSBOX0CPC
    POP BC
    PUSH HL
    PUSH BC
    LD HL, DE 
    LD D, 0
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    ADD HL, DE
    ADD HL, DE
    ADD HL, DE
    ADD HL, DE
    ADD HL, DE
    ADD HL, DE
    ADD HL, DE
    ADD HL, DE
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
CLSBOX0CP2C:
    DEC B
    JR NZ, CLSBOX0CPCA

    JP CLSBOXDONE

CLSBOXDONE:
    RET