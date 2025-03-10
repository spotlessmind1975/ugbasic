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

; PUT an IMAGE on the screen.
;
; input:
;       IXH:E           -> x
;       D               -> y
;       HL              -> start of bitmap data
;       IMAGET + IMAGEF ->  various flags       
PUTIMAGE:

    ; Skip if in TILE MODE

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    ; Retrieve the width (in pixel) and height (in pixel),
    ;   IXH:C -> WIDTH
    ;   B -> HEIGHT
    
    LD C, (HL)
    INC HL
    LD A, (HL)
    LD IXH, A
    INC HL
    LD B, (HL)
    INC HL

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
    JP Z, PUTIMAGE0
    CP 1
    JP Z, PUTIMAGE1
    CP 2
    JP Z, PUTIMAGE2
    CP 3
    JP Z, PUTIMAGE3
    POP DE
    RET

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3
    ; ------------------------------------------------------------------------

PUTIMAGE0PIXELTRANS:
    PUSH BC
    LD IYH, 0
    LD A, (HL)
    AND $AA
    JR Z, PUTIMAGE0PIXELTRANS2
    LD A, $AA
    LD IYH, A
PUTIMAGE0PIXELTRANS2:
    LD A, (HL)
    AND $55
    JR Z, PUTIMAGE0PIXELTRANS3
    LD A, IYH
    OR $55
    LD IYH, A
PUTIMAGE0PIXELTRANS3:
    LD A, IYH
    XOR $FF
    LD B, A
    LD A, (DE)
    AND B
    LD B, A
    LD A, (HL)
    AND IYH
    ORA B
    LD (DE),A
    POP BC
    RET

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3
    ; ------------------------------------------------------------------------

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE)
    ; ------------------------------------------------------------------------

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (DOUBLE)
    ; ------------------------------------------------------------------------

PUTIMAGE0:
PUTIMAGE3:

    ; Halves the width of the image to draw, since each byte keep two pixels.
    SRL C

    ; Check (and manage) if a "DOUBLE" flag has been requested.
    LD A, (IMAGEF)
    AND $40
    CP $40
    JP Z, PUTIMAGE0DOUBLE

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE)
    ; ------------------------------------------------------------------------

PUTIMAGE0SINGLE:

    ; Manage the "WITH TRANSPARENCY" flag.
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, PUTIMAGE0SINGLETRANSPARENT

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE MATTE)
    ; ------------------------------------------------------------------------

PUTIMAGE0SINGLEMATTE:
PUTIMAGE0SINGLEL2:

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

PUTIMAGE0SINGLEL1N:

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    LDIR

PUTIMAGE0SINGLEDONEROW:

    ; The copy of the row has been completed.
    
    POP BC

    ; Increment the vertical position
    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, PUTIMAGE0SINGLEDONEROW2B

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, PUTIMAGE0SINGLEL2

    JP PUTIMAGE0L2AX

PUTIMAGE0SINGLEDONEROW2B:

    ; Before skipping, decrement the number of rows last to copy.
    DEC B

    ; Skip only if there are any rows.
    JP NZ, PUTIMAGE0SINGLEL2A

    JP PUTIMAGE0L2AX

PUTIMAGE0SINGLEL2A:

    PUSH DE
    LD A, C
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE
    DEC B
    JP NZ, PUTIMAGE0SINGLEL2A

    JP PUTIMAGE0L2AX

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (SINGLE)
    ; ------------------------------------------------------------------------


PUTIMAGE0SINGLETRANSPARENT:
PUTIMAGE0SINGLETRANSPARENTL2:

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
PUTIMAGE0SINGLETRANSPARENTL1:
PUTIMAGE0SINGLETRANSPARENTL1N:

    ; Copy the bitmap data from the memory to the video.
    ; This is a copy that support the transparency.

    CALL PUTIMAGE0PIXELTRANS

    ; This is the end of the row copy loop.
    ; Move to the next source and destination byte.

    INC DE
    INC HL

    ; Decrement the number of byte to copy.
    ; Repeat until finished.

    DEC C
    JR NZ, PUTIMAGE0SINGLETRANSPARENTL1N

PUTIMAGE0SINGLETRANSPARENTDONEROW:

    ; The copy of the row has been completed.
    
    POP BC

    ; Increment the vertical position
    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, PUTIMAGE0SINGLETRANSPARENTDONEROW2B

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, PUTIMAGE0SINGLETRANSPARENTL2

    JP PUTIMAGE0L2AX

PUTIMAGE0SINGLETRANSPARENTDONEROW2B:

    ; Before skipping, decrement the number of rows last to copy.
    DEC B

    ; Skip only if there are any rows.
    JP NZ, PUTIMAGE0SINGLETRANSPARENTL2A

    JP PUTIMAGE0L2AX

PUTIMAGE0SINGLETRANSPARENTL2A:

    PUSH DE
    LD A, C
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE
    DEC B
    JP NZ, PUTIMAGE0SINGLETRANSPARENTL2A

    JP PUTIMAGE0L2AX

    ; ------------------------------------------------------------------------
    ; --- MODE 0 & 3 (DOUBLE)
    ; ------------------------------------------------------------------------

PUTIMAGE0DOUBLE:

    ; Manage the "WITH TRANSPARENCY" flag.
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, PUTIMAGE0DOUBLEST

PUTIMAGE0DOUBLESN:
    PUSH DE
    PUSH HL
    LD DE, PUTIMAGE0DOUBLEL1N 
    LD HL, PUTIMAGE0DOUBLEL1
    ADD HL, 1
    LD A, E
    LD (HL), A
    LD A, D
    ADD HL, 1
    LD (HL), A
    POP HL
    POP DE
    JP PUTIMAGE0DOUBLESDONE

PUTIMAGE0DOUBLEST:
    PUSH DE
    PUSH HL
    LD DE, PUTIMAGE0DOUBLEL1T 
    LD HL, PUTIMAGE0DOUBLEL1
    ADD HL, 1
    LD A, E
    LD (HL), A
    ADD HL, 1
    LD A, D
    LD (HL), A
    POP HL
    POP DE
    JP PUTIMAGE0DOUBLESDONE

PUTIMAGE0DOUBLESDONE:
PUTIMAGE0DOUBLEL2:

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
PUTIMAGE0DOUBLEL1:

    JP $0000

PUTIMAGE0DOUBLEL1N:

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    LD A, (HL)
    LD (DE),A

    ; Jump to the end of the loop.
    JP PUTIMAGE0DOUBLEL1T0

    ; Copy the bitmap data from the memory to the video.
    ; This is a copy that support the transparency.

PUTIMAGE0DOUBLEL1T:
    CALL PUTIMAGE0PIXELTRANS

PUTIMAGE0DOUBLEL1T0:

    ; This is the end of the row copy loop.
    ; Move to the next source and destination byte.

    INC DE
    INC HL

    ; Decrement the number of byte to copy.
    ; Repeat until finished.

    DEC C
    JR NZ, PUTIMAGE0DOUBLEL1

PUTIMAGE0DOUBLEDONEROW:

    ; The copy of the row has been completed.
    
    POP BC

    ; Check (and manage) if a "DOUBLE" flag has been requested.
    LD A, (IMAGEF)
    AND $41
    CP $41
    JR Z, PUTIMAGE0DOUBLEDONEROW2
    AND $40
    CP $40
    JR NZ, PUTIMAGE0DOUBLEDONEROW2
    OR $01
    LD (IMAGEF), A

    ; Move back of width pixels, to repeat the line for
    ; the DOUBLE flag support.
    PUSH DE
    LD A, C
    LD E, A
    LD A, 0
    LD D, A
    AND A
    SBC HL, DE
    POP DE
    JP PUTIMAGE0DOUBLEL2 ; Repeat the row copy.

    ; Disable if a "DOUBLE" flag has been requested.
PUTIMAGE0DOUBLEDONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    ; Increment the vertical position
    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, PUTIMAGE0DOUBLEDONEROW2B

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, PUTIMAGE0DOUBLEL2

    JP PUTIMAGE0L2AX

PUTIMAGE0DOUBLEDONEROW2B:

    ; Before skipping, decrement the number of rows last to copy.
    DEC B

    ; Skip only if there are any rows.
    JP NZ, PUTIMAGE0DOUBLEL2A

    JP PUTIMAGE0L2AX

PUTIMAGE0DOUBLEL2A:

    PUSH DE
    LD A, C
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE
    DEC B
    JP NZ, PUTIMAGE0DOUBLEL2A

; ------------------------------------------------------------------------

PUTIMAGE0L2AX:
    ; Prepare to store the palette (16 colors)
    LD A, 16
    LD B, A
    LD A, 0
    LD C, A

    ; Check if "WITH TRANSPARENCY" flag has been selected,
    ; so that the first index of the palette
    ; should not be changed.
    LD A, (IMAGEF)
    AND $20
    CP $20
    JR NZ, PUTIMAGE0DONEROWL1

    ; Skip the first color index

    INC HL
    INC C

PUTIMAGE0DONEROWL1:

    ; Check if "BITMAP" flag has been selected,
    ; so that the palette should not be touched

    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, PUTIMAGEC0DONE

PUTIMAGE0DONEROWL1L:

    ; Loop to update the 16 colors of the palette.

    LD A, (HL)
    LD IXL, A
    LD IXH, C
    LD IYL, 1
    CALL CPCUPDATEPALETTE
    INC HL
    INC C
    LD A, C
    CP 16
    JR NZ, PUTIMAGE0DONEROWL1L

PUTIMAGEC0DONE:

    ; The PUT IMAGE has finished!

    POP DE
    JP PUTIMAGEDONE

    ; ------------------------------------------------------------------------
    ; --- MODE 1
    ; ------------------------------------------------------------------------

PUTIMAGE1:

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
    
PUTIMAGE1L2:

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
PUTIMAGE1L1:

    ; Manage the "WITH TRANSPARENCY" flag.
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, PUTIMAGE1L1T

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    LD A, (HL)
    LD (DE),A

    ; Jump to the end of the loop.
    JP PUTIMAGE1L1T0

    ; Copy the bitmap data from the memory to the video.
    ; This is a copy that support the transparency.

PUTIMAGE1L1T:
    PUSH IX
    PUSH BC
    LD A, 0
    LD IXH, A
    LD A, (HL)
    AND $88
    CP $0
    JR Z, PUTIMAGE1L1T2
    LD A, IXH
    OR $88
    LD IXH, A
PUTIMAGE1L1T2:
    LD A, (HL)
    AND $44
    CP $0
    JR Z, PUTIMAGE1L1T3
    LD A, IXH
    OR $44
    LD IXH, A
PUTIMAGE1L1T3:
    LD A, (HL)
    AND $22
    CP $0
    JR Z, PUTIMAGE1L1T4
    LD A, IXH
    OR $22
    LD IXH, A
PUTIMAGE1L1T4:
    LD A, (HL)
    AND $11
    CP $0
    JR Z, PUTIMAGE1L1T5
    LD A, IXH
    OR $11
    LD IXH, A
PUTIMAGE1L1T5:
    LD A, IXH
    XOR $FF
    LD B, A
    LD A, (DE)
    AND B
    LD B, A
    LD A, (HL)
    AND IXH
    ORA B
    LD (DE),A
    POP BC
    POP IX

PUTIMAGE1L1T0:

    ; This is the end of the row copy loop.
    ; Move to the next source and destination byte.

    INC DE
    INC HL

    ; Decrement the number of byte to copy.
    ; Repeat until finished.

    DEC C
    JP NZ, PUTIMAGE1L1

    ; TODO: actually, up to 255 pixels images width are supported.
    ; TODO: this is the point where to change the behaviour.

    ; LD A, IXH
    ; CP $0
    ; JR Z, PUTIMAGE1DONEROW
    ; DEC IXH
    ; LD A, $FF
    ; LD C, A
    ; JP PUTIMAGE1L1

PUTIMAGE1DONEROW:

    ; The copy of the row has been completed.

    POP BC

    ; Check (and manage) if a "DOUBLE" flag has been requested.
    LD A, (IMAGEF)
    AND $41
    CP $41
    JP Z, PUTIMAGE1DONEROW2
    AND $40
    CP $40
    JR NZ, PUTIMAGE1DONEROW2
    OR $01
    LD (IMAGEF), A

    ; Move back of width pixels, to repeat the line for
    ; the DOUBLE flag support.
    PUSH DE
    LD A, C
    LD E, A
    LD A, 0
    LD D, A
    AND A
    SBC HL, DE
    POP DE
    JP PUTIMAGE1L2 ; Repeat the row copy.

    ; Disable if a "DOUBLE" flag has been requested.
PUTIMAGE1DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    ; Increment the vertical position
    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, PUTIMAGE1DONEROW2B

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, PUTIMAGE1L2

    JP PUTIMAGE1L2AX

PUTIMAGE1DONEROW2B:

    ; Before skipping, decrement the number of rows last to copy.
    DEC B

    ; Skip only if there are any rows.
    JP NZ, PUTIMAGE1L2A

    JP PUTIMAGE1L2AX

PUTIMAGE1L2A:

    PUSH DE
    LD A, C
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE
    DEC B
    JP NZ, PUTIMAGE1L2A

PUTIMAGE1L2AX:

    ; Check if "WITH TRANSPARENCY" flag has been selected,
    ; so that the first index of the palette
    ; should not be changed.
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, PUTIMAGE1DONEROW2T

    ; Update the first color index

    LD A, (HL)

    ; Check if the first index has $00 that means that
    ; a transparent image must be renderized as not transparent:
    ; this means that we must translate it to black.
    CP $0
    JR NZ, PUTIMAGE1L2AXY
    LD A, $14

PUTIMAGE1L2AXY:
    LD IXL, A
    LD IXH, 0
    LD IYL, 1
    CALL CPCUPDATEPALETTE

PUTIMAGE1DONEROW2T:

    ; Check if "BITMAP" flag has been selected,
    ; so that the palette should not be touched

    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, PUTIMAGEC1DONE

    ; Skip the first index since we already changed it.

    ; Update color #1

    INC HL
    LD A, (HL)
    LD IXL, A
    LD IXH, 1
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    ; Update color #2

    INC HL
    LD A, (HL)
    LD IXL, A
    LD IXH, 2
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    ; Update color #3

    INC HL
    LD A, (HL)
    LD IXL, A
    LD IXH, 3
    LD IYL, 1
    CALL CPCUPDATEPALETTE

PUTIMAGEC1DONE:

    ; The PUT IMAGE has finished!

    POP DE
    JP PUTIMAGEDONE

    ; ------------------------------------------------------------------------
    ; --- MODE 2
    ; ------------------------------------------------------------------------

PUTIMAGE2:

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

PUTIMAGE2L2:

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
PUTIMAGE2L1:

    ; Manage the "WITH TRANSPARENCY" flag.
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, PUTIMAGE2L1T

    ; Copy the bitmap data from the memory to the video.
    ; This is a direct copy.
    
    LD A, (HL)
    LD (DE),A

    ; Jump to the end of the loop.
    JP PUTIMAGE2L1T0

    ; Copy the bitmap data from the memory to the video.
    ; This is a copy that support the transparency.

PUTIMAGE2L1T:
    PUSH IX
    PUSH BC
    LD A, 0
    LD IXH, A
    LD A, (HL)
    AND $80
    CP $0
    JR Z, PUTIMAGE2L1T2
    LD A, IXH
    OR $80
    LD IXH, A
PUTIMAGE2L1T2:
    LD A, (HL)
    AND $40
    CP $0
    JR Z, PUTIMAGE2L1T3
    LD A, IXH
    OR $40
    LD IXH, A
PUTIMAGE2L1T3:
    LD A, (HL)
    AND $20
    CP $0
    JR Z, PUTIMAGE2L1T4
    LD A, IXH
    OR $20
    LD IXH, A
PUTIMAGE2L1T4:
    LD A, (HL)
    AND $10
    CP $0
    JR Z, PUTIMAGE2L1T5
    LD A, IXH
    OR $10
    LD IXH, A
PUTIMAGE2L1T5:
    LD A, (HL)
    AND $08
    CP $0
    JR Z, PUTIMAGE2L1T6
    LD A, IXH
    OR $08
    LD IXH, A
PUTIMAGE2L1T6:
    LD A, (HL)
    AND $04
    CP $0
    JR Z, PUTIMAGE2L1T7
    LD A, IXH
    OR $04
    LD IXH, A
PUTIMAGE2L1T7:
    LD A, (HL)
    AND $02
    CP $0
    JR Z, PUTIMAGE2L1T8
    LD A, IXH
    OR $02
    LD IXH, A
PUTIMAGE2L1T8:
    LD A, (HL)
    AND $01
    CP $0
    JR Z, PUTIMAGE2L1T9
    LD A, IXH
    OR $01
    LD IXH, A
PUTIMAGE2L1T9:
    LD A, IXH
    XOR $FF
    LD B, A
    LD A, (DE)
    AND B
    LD B, A
    LD A, (HL)
    AND IXH
    ORA B
    ; Draw them
    LD (DE),A
    POP BC
    POP IX

PUTIMAGE2L1T0:

    ; This is the end of the row copy loop.
    ; Move to the next source and destination byte.

    INC DE
    INC HL

    ; Decrement the number of byte to copy.
    ; Repeat until finished.

    DEC C
    JP NZ, PUTIMAGE2L1

    ; TODO: actually, up to 255 pixels images width are supported.
    ; TODO: this is the point where to change the behaviour.

    ; LD A, IXH
    ; CP $0
    ; JR Z, PUTIMAGE2DONEROW
    ; DEC IXH
    ; LD A, $FF
    ; LD C, A
    ; JP PUTIMAGE2L1

PUTIMAGE2DONEROW:

    ; The copy of the row has been completed.

    POP BC

    ; Check (and manage) if a "DOUBLE" flag has been requested.
    LD A, (IMAGEF)
    AND $41
    CP $41
    JR Z, PUTIMAGE2DONEROW2
    AND $40
    CP $40
    JR NZ, PUTIMAGE2DONEROW2
    OR $01
    LD (IMAGEF), A

    ; Move back of width pixels, to repeat the line for
    ; the DOUBLE flag support.

    PUSH DE
    LD A, C
    LD E, A
    LD A, 0
    LD D, A
    AND A
    SBC HL, DE
    POP DE
    JP PUTIMAGE2L2 ; Repeat the row copy.

    ; Disable if a "DOUBLE" flag has been requested.
PUTIMAGE2DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    ; Increment the vertical position
    PUSH BC
    LD A, (IMAGEY)
    ADD $1
    LD (IMAGEY), A
    LD B, A
    LD A, (CURRENTHEIGHT)
    CP B
    POP BC
    JR Z, PUTIMAGE2DONEROW2B

    ; Decrement the number of rows last to copy.
    DEC B

    ; Repeat the copy for the next row.
    JP NZ, PUTIMAGE2L2

    JP PUTIMAGE2L2X

PUTIMAGE2DONEROW2B:

    ; Before skipping, decrement the number of rows last to copy.
    DEC B

    ; Skip if there are rows
    JP NZ, PUTIMAGE2L2A

    JP PUTIMAGE2L2X

PUTIMAGE2L2A:

    PUSH DE
    LD A, C
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE
    DEC B
    JP NZ, PUTIMAGE2L2A

PUTIMAGE2L2X:

    ; Check if "WITH TRANSPARENCY" flag has been selected,
    ; so that the first index of the palette
    ; should not be changed.
    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, PUTIMAGEC2DONE

    ; Check if "BITMAP" flag has been selected,
    ; so that the palette should not be touched
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, PUTIMAGE2DONEROW2T

    ; Update the first color index

    LD A, (HL)

    ; Check if the first index has $00 that means that
    ; a transparent image must be renderized as not transparent:
    ; this means that we must translate it to black.
    CP $0
    JR NZ, PUTIMAGE2L2AXY
    LD A, $14

PUTIMAGE2L2AXY:
    LD IXL, A
    LD IXH, 0
    LD IYL, 1
    CALL CPCUPDATEPALETTE

PUTIMAGE2DONEROW2T:

    ; Update the second color index

    INC HL
    LD A, (HL)
    LD IXL, A
    LD IXH, 1
    LD IYL, 1
    CALL CPCUPDATEPALETTE

PUTIMAGEC2DONE:

    ; The PUT IMAGE has finished!

    POP DE
    JP PUTIMAGEDONE

PUTIMAGEDONE:
    RET