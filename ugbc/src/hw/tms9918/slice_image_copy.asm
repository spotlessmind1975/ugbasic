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

; SLICE IMAGE - speed optimized for copying images with the very same size
SLICEIMAGECOPY:

    ; Take down the size of the source frame
    ; and copy it to the destination frame.
    LD A, (HL)
    LD (DE), A
    LD C, A
    INC HL
    INC DE
    LD A, (HL)
    LD (DE), A
    LD B, A
    INC HL
    INC DE
    LD A, (HL)
    LD (DE), A
    INC HL
    INC DE

    ; Calculate the size of bitmap to copy, in bytes: 2 x (BC/8) (columns) x A (rows).
    PUSH DE
    PUSH BC
    PUSH HL
    LD DE, BC
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    LD HL, 0
    LD C, A
SLICEIMAGECOPYL:
    ADD HL, DE
    DEC C
    JR NZ, SLICEIMAGECOPYL
    ADD HL, HL
    LD IX, HL
    POP HL
    POP BC
    POP DE
    PUSH IX
    POP BC

    ; The bitmap copy is indifferent to current graphic mode.
    ; It is enough to call the DUFF DEVICE, since HL, DE and BC
    ; are already beet configured properly
    CALL DUFFDEVICE

    RET
