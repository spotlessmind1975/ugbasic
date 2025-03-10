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

    ; Calculate the size of bitmap to copy, in bytes: BC (columns) x A (rows).
    PUSH DE
    PUSH BC
    PUSH HL
    LD DE, BC
    LD HL, 0
    LD C, A
SLICEIMAGECOPYL:
    ADD HL, DE
    DEC C
    JR NZ, SLICEIMAGECOPYL
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

    ; Now we must copy the rest of bytes that are the
    ; palette, and it depends on the current graphic mode.
    LD A, (CURRENTMODE)
    CP 0
    JP Z, SLICEIMAGECOPY0
    CP 1
    JP Z, SLICEIMAGECOPY1
    CP 2
    JP Z, SLICEIMAGECOPY2
    CP 3
    JP Z, SLICEIMAGECOPY3
    RET

SLICEIMAGECOPY0:
SLICEIMAGECOPY3:
    LD BC, 16
    CALL DUFFDEVICE
    RET

SLICEIMAGECOPY1:
    LD BC, 4
    CALL DUFFDEVICE
    RET

SLICEIMAGECOPY2:
    LD BC, 2
    CALL DUFFDEVICE
    RET
