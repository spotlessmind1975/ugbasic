; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                          INTERNAL VARIABLES FOR TMS9918                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ------------------------------------------------------------------------------
; BITMAP_MODE_GRAPHIC2
; ------------------------------------------------------------------------------

PLOTVBASE:
    DW ($0000+(0*256)),($0000+(1*256)),($0000+(2*256)),($0000+(3*256))
    DW ($0000+(4*256)),($0000+(5*256)),($0000+(6*256)),($0000+(7*256))
    DW ($0000+(8*256)),($0000+(9*256)),($0000+(10*256)),($0000+(11*256))
    DW ($0000+(12*256)),($0000+(13*256)),($0000+(14*256)),($0000+(15*256))
    DW ($0000+(16*256)),($0000+(17*256)),($0000+(18*256)),($0000+(19*256))
    DW ($0000+(20*256)),($0000+(21*256)),($0000+(22*256)),($0000+(23*256))

PLOT8:
    DW (0*8),(1*8),(2*8),(3*8),(4*8),(5*8),(6*8),(7*8),(8*8),(9*8)
    DW (10*8),(11*8),(12*8),(13*8),(14*8),(15*8),(16*8),(17*8),(18*8),(19*8)
    DW (20*8),(21*8),(22*8),(23*8),(24*8),(25*8),(26*8),(27*8),(28*8),(29*8)
    DW (30*8),(31*8)

PLOTCVBASE:
    DW ($2000+(0*256)),($2000+(1*256)),($2000+(2*256)),($2000+(3*256))
    DW ($2000+(4*256)),($2000+(5*256)),($2000+(6*256)),($2000+(7*256))
    DW ($2000+(8*256)),($2000+(9*256)),($2000+(10*256)),($2000+(11*256))
    DW ($2000+(12*256)),($2000+(13*256)),($2000+(14*256)),($2000+(15*256))
    DW ($2000+(16*256)),($2000+(17*256)),($2000+(18*256)),($2000+(19*256))
    DW ($2000+(20*256)),($2000+(21*256)),($2000+(22*256)),($2000+(23*256))

VDPPOS:

; 4) Use the re~nainder of (X/8) to look up in a table (below) the actual data to plot. The values
; corresponding to different remainders are as follows: The actual bit we need to plot is determined 
; by whatever remainder is left after calculating (X/8).

    PUSH HL
    PUSH DE

    LD D,0
    LD A, E
    AND $07
    LD E, A
    LD HL, PLOTORBIT
    ADD HL, DE
    LD A, (HL)
    LD B, A
    LD HL, PLOTANDBIT
    ADD HL, DE
    LD A, (HL)
    LD C, A

    POP DE
    POP HL

    PUSH DE

    ;-------------------------
    ;calc Y-cell, divide by 8
    ;y/8 is y-cell table index
    ;-------------------------
    SRL D                         ;/ 2
    SRL D                         ;/ 4
    SRL D                         ;/ 8

    ;------------------------
    ;calc X-cell, divide by 8
    ;divide 2-byte PLOTX / 8
    ;------------------------
    SRL E
    SRL E
    SRL E

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------

; 1) Take the integer value of (X/8) and multiply it times 8. This will give the horizontal byte
; offset. 

    PUSH BC
    PUSH DE

    LD D, 0
    LD HL, PLOT8
    ADD HL, DE
    ADD HL, DE
    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A

; 2) Take the integer value of (Y/8) and multiply it times Hex 100. This will give the vertical
; byte offset to the nearest eight bits. 

    LD HL, PLOTVBASE

    POP DE
    PUSH DE

    LD E, D
    LD D, 0
    ADD HL, DE
    ADD HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    LD HL, DE

; 3) Add the horizontal byte offset to the vertical starting address. This will give the actual
; address of the byte we need to write data to in order to plot our pixel.

    ADD HL, BC

    POP DE

; If there is any remainder after calculating (Y/8), add
; it to the vertical byte offset. This gives the vertical 
; starting address.    

    POP BC
    POP DE
    
    PUSH DE
    LD A, D
    AND $07
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE

    DI
    PUSH DE
    EXX
    POP DE

    LD HL, $2000
    PUSH DE
    LD D, 0
    SRL E
    SRL E
    SRL E
    LD HL, PLOT8
    ADD HL, DE
    ADD HL, DE
    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    LD B, A
    LD HL, PLOTCVBASE
    POP DE
    PUSH DE
    LD E, D
    SRL E
    SRL E
    SRL E
    LD D, 0
    ADD HL, DE
    ADD HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    LD HL, DE
    ADD HL, BC
    POP DE
    PUSH DE
    LD A, D
    AND $07
    LD E, A
    LD D, 0
    ADD HL, DE
    POP DE

    EXX

    EI

    RET


PLOTORBIT:
    DB %10000000
    DB %01000000
    DB %00100000
    DB %00010000
    DB %00001000
    DB %00000100
    DB %00000010
    DB %00000001

PLOTANDBIT:
    DB %01111111
    DB %10111111
    DB %11011111
    DB %11101111
    DB %11110111
    DB %11111011
    DB %11111101
    DB %11111110
