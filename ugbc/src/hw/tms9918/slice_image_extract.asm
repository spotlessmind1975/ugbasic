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
    SLA A
    LD IXL, A
    INC DE
    
    SRL B
    RR C
    SRL B
    RR C
    SRL B
    RR C

    ; Move to the start of the source bitmap.
    ; sliceImageY
    PUSH BC
    PUSH DE
    LD E, (HL)
    INC HL
    LD D, (HL)
    INC HL

    SRL D 
    RR E
    SRL D 
    RR E
    SRL D 
    RR E

    LD (SLICEDTARGET), DE

    LD BC, (SLICEY)
    LD A, C
    OR B
    JR Z, SLICELYY2
SLICELYY:
    ADD HL, DE
    DEC BC
    LD A, C
    OR B
    JR NZ, SLICELYY
SLICELYY2:
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

    ; Move to the start of the source bitmap.
    ; sliceImageX
    PUSH DE
    LD DE, (SLICEX)

    SRL D 
    RR E
    SRL D 
    RR E
    SRL D 
    RR E

    ADD HL, DE
    POP DE

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

    RET

