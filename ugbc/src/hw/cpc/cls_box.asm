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
;*                          CLS BOXED ROUTINE FOR CPC                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; input:
;       IXH:E           -> x
;       D               -> y
;       IXH:C           -> WIDTH
;       B               -> HEIGHT
CLSBOX:

    ; Skip if in TILE MODE

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    ; Retrieve the width (in pixel) and height (in pixel),
    
    ; Save IMAGEY
    LD A, D
    LD (IMAGEY), A

    ; Decrement the y position in order to calculate
    ; correctly the position on the first loop.
    DEC D

    ; Dispatch the execution to the proper
    ; function.
    PUSH DE
    LD A, (CURRENTMODE)
    CP 0
    JP Z, CLSBOX0
    CP 1
    JP Z, CLSBOX1
    CP 2
    JP Z, CLSBOX2
    CP 3
    JP Z, CLSBOX3
    POP DE
    RET

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3
    ; ------------------------------------------------------------------------

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3
    ; ------------------------------------------------------------------------

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE)
    ; ------------------------------------------------------------------------

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (DOUBLE)
    ; ------------------------------------------------------------------------

CLSBOX0:
CLSBOX3:

    ; Halves the width of the image to draw, since each byte keep two pixels.
    SRL C

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE)
    ; ------------------------------------------------------------------------

CLSBOX0SINGLE:

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE MATTE)
    ; ------------------------------------------------------------------------

CLSBOX0SINGLEMATTE:
CLSBOX0SINGLEL2:

    ; Move ahead of one row.

    POP DE
    INC D
    PUSH DE

    ; Recalculate the starting position on the video buffer.

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    ; Row copy loop.

    PUSH BC

    LD B, 0
    LD A, 0

CLSBOX0SINGLEL1N:

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    LD (DE), A
    DEC C
    JR NZ, CLSBOX0SINGLEL1N

CLSBOX0SINGLEDONEROW:

    ; The copy of the row has been completed.
    
    POP BC

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, CLSBOX0SINGLEL2

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE)
    ; ------------------------------------------------------------------------

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (DOUBLE)
    ; ------------------------------------------------------------------------


; ------------------------------------------------------------------------

CLSBOX0L2AX:

    ; The PUT IMAGE has finished!

    POP DE
    JP CLSBOXDONE

    ; ------------------------------------------------------------------------
    ; --- MODE 1
    ; ------------------------------------------------------------------------

CLSBOX1:

    ; Subdivide the width of the image to draw, since each byte keep four pixels.

    PUSH BC
    LD A, IXH
    LD B, A
    SRL B
    RR C
    SRL B
    RR C
    LD A, C
    POP BC
    LD C, A
    
CLSBOX1L2:

    ; Move ahead of one row.

    POP DE
    INC D
    PUSH DE

    ; Recalculate the starting position on the video buffer.

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    ; Row copy loop.

    PUSH BC
CLSBOX1L1:

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    LD A, 0
    LD (DE),A

    ; This is the end of the row copy loop.
    ; Move to the next source and destination byte.

    INC DE

    ; Decrement the number of byte to copy.
    ; Repeat until finished.

    DEC C
    JP NZ, CLSBOX1L1

CLSBOX1DONEROW:

    ; The copy of the row has been completed.

    POP BC

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, CLSBOX1L2

    ; The PUT IMAGE has finished!

    POP DE
    JP CLSBOXDONE

    ; ------------------------------------------------------------------------
    ; --- MODE 2
    ; ------------------------------------------------------------------------

CLSBOX2:

    ; Subdivide the width of the image to draw, since each byte keep eight pixels.

    PUSH BC
    LD A, IXH
    LD B, A
    SRL B
    RR C
    SRL B
    RR C
    SRL B
    RR C
    LD A, C
    POP BC
    LD C, A

CLSBOX2L2:

    ; Move ahead of one row.

    POP DE
    INC D
    PUSH DE

    ; Recalculate the starting position on the video buffer.

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    ; Row copy loop.

    PUSH BC
CLSBOX2L1:

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    
    LD A, 0
    LD (DE),A

    ; This is the end of the row copy loop.
    ; Move to the next source and destination byte.

    INC DE

    ; Decrement the number of byte to copy.
    ; Repeat until finished.

    DEC C
    JP NZ, CLSBOX2L1

CLSBOX2DONEROW:

    ; The copy of the row has been completed.

    POP BC

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, CLSBOX2L2

    ; The PUT IMAGE has finished!

    POP DE
    JP CLSBOXDONE

CLSBOXDONE:
    RET