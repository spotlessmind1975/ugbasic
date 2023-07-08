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
;*                          IMAGES ROUTINE FOR CPC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SLICE IMAGE - generic copy to destination-sized image
SLICEIMAGEEXT:

    ; Take down the size of the destination frame
    ; It will be the size of the copy from the source
    ; frame.
    LD A, (DE)
    LD C, A
    INC DE
    LD A, (DE)
    LD B, A
    INC DE
    LD A, (DE)
    LD IXL, A
    INC DE
    
    ; Calculate the effective width in bytes.

    LD A, (CURRENTMODE)
    CP 0
    JP Z, SLICEIMAGEEXTLW0
    CP 1
    JP Z, SLICEIMAGEEXTLW1
    CP 2
    JP Z, SLICEIMAGEEXTLW2
    CP 3
    JP Z, SLICEIMAGEEXTLW3

SLICEIMAGEEXTLW2:
    SRL B
    RR C
SLICEIMAGEEXTLW1:
    SRL B
    RR C
SLICEIMAGEEXTLW3:
SLICEIMAGEEXTLW0:
    SRL B
    RR C

    ; Move to the start of the source bitmap.
    ; sliceImageX
    PUSH DE
    LD DE, (SLICEX)

    LD A, (CURRENTMODE)
    CP 0
    JP Z, SLICEIMAGEEXTLX0
    CP 1
    JP Z, SLICEIMAGEEXTLX1
    CP 2
    JP Z, SLICEIMAGEEXTLX2
    CP 3
    JP Z, SLICEIMAGEEXTLX3

SLICEIMAGEEXTLX2:
    SRL D 
    RR E
SLICEIMAGEEXTLX1:
    SRL D 
    RR E
SLICEIMAGEEXTLX3:
SLICEIMAGEEXTLX0:
    SRL D 
    RR E

    ADD HL, DE
    POP DE

    ; Move to the start of the source bitmap.
    ; sliceImageY
    PUSH BC
    PUSH DE
    LD E, (HL)
    INC HL
    LD D, (HL)
    INC HL

    LD A, (CURRENTMODE)
    CP 0
    JP Z, SLICEIMAGEEXTLY0
    CP 1
    JP Z, SLICEIMAGEEXTLY1
    CP 2
    JP Z, SLICEIMAGEEXTLY2
    CP 3
    JP Z, SLICEIMAGEEXTLY3

SLICEIMAGEEXTLY2:
    SRL D 
    RR E
SLICEIMAGEEXTLY1:
    SRL D 
    RR E
SLICEIMAGEEXTLY3:
SLICEIMAGEEXTLY0:
    SRL D 
    RR E

    LD (SLICEDTARGET), DE

    LD BC, (SLICEY)
SLICELYY:
    ADD HL, DE
    DEC BC
    LD A, C
    OR B
    JR NZ, SLICELYY
    POP DE
    POP BC

    ; Move to the effective beginning of the source bitmap.
    INC HL

    PUSH HL
    PUSH DE
    LD HL, (SLICEDTARGET)
    LD DE, BC
    SBC HL, DE
    LD (SLICEDTARGET), HL
    POP DE
    POP HL

SLICEIMAGEEXT0L:
    PUSH BC
    CALL DUFFDEVICE
    POP BC
    PUSH DE
    LD DE, (SLICEDTARGET)
    ADD HL, DE
    POP DE
    DEC IXL
    JR NZ, SLICEIMAGEEXT0L

    ; Move to the proper 
    LD A, (CURRENTMODE)
    CP 0
    JP Z, SLICEIMAGEEXTC0
    CP 1
    JP Z, SLICEIMAGEEXTC1
    CP 2
    JP Z, SLICEIMAGEEXTC2
    CP 3
    JP Z, SLICEIMAGEEXTC3
    RET

SLICEIMAGEEXTC0:
SLICEIMAGEEXTC3:
    LD BC, 16
    CALL DUFFDEVICE
    RET

SLICEIMAGEEXTC1:
    LD BC, 4
    CALL DUFFDEVICE
    RET

SLICEIMAGEEXTC2:
    LD BC, 2
    CALL DUFFDEVICE
    RET
