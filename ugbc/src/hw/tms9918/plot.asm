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
;*                           PLOT ROUTINE FOR TMS9918                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; PLOTX    = $F7 ; $F8  -> E
; PLOTY    = $F9        -> D
; PLOTM    = $FB        -> B
; PLOTOMA  = $FD
; PLOTAMA  = $FC

;--------------

PLOT:

    PUSH AF

    LD A, (CLIPY2)
    LD B, A
    LD A, D
    CP B
    JR C, PLOTCLIP2
    JR Z, PLOTCLIP2
    JP PLOTP
PLOTCLIP2:
    LD A, (CLIPY1)
    LD B, A
    LD A, D
    CP B
    JR Z, PLOTCLIP3
    JR NC, PLOTCLIP3
    JP PLOTP
PLOTCLIP3:
PLOTCLIP3B:
    LD A, (CLIPX2)
    LD B, A
    LD A, E
    CP B
    JR C, PLOTCLIP4
    JR Z, PLOTCLIP4
    JP PLOTP
PLOTCLIP4:
PLOTCLIP4B:
    LD A, (CLIPX1)
    LD B, A
    LD A, E
    CP B
    JR NC, PLOTCLIP5
    JR Z, PLOTCLIP5
    JP PLOTP
PLOTCLIP5:

PLOTMODE:
    LD A, (CURRENTMODE)
    ; TILEMAP_MODE_STANDARD
    CP 0
    JR NZ, PLOT0X
    JP PLOT0
PLOT0X:
    ; TILEMAP_MODE_GRAPHIC1
    CP 1
    JR NZ,PLOT1X
    JP PLOT1
PLOT1X:
    ; BITMAP_MODE_GRAPHIC2
    CP 2
    JR NZ,PLOT2X
    JP PLOT2
PLOT2X:
    ; BITMAP_MODE_MULTICOLOR
    CP 3
    JR NZ,PLOT3X
    JP PLOT3
PLOT3X:
    POP AF
    RET

PLOT0:
PLOT1:
    POP AF
    RET

PLOT2:
PLOT3:


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

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    POP AF
    CP 0
    JR Z, PLOTE                  ;if = 0 then branch to clear the point
    CP 1
    JR Z, PLOTD                  ;if = 1 then branch to draw the point
    CP 2
    JR Z, PLOTG                  ;if = 2 then branch to get the point (0/1)
    CP 3
    JR Z, PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JP PLOTP

PLOTD:
    ;---------
    ;set point
    ;---------
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    OR B
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE

    DI

    EXX

    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD B, A
    LD A, (_PAPER)
    OR B
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE

    EXX

    EI

    JMP PLOTP

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    PUSH DE
    LD DE, HL
    CALL VDPOUTCHAR
    POP DE
    JMP PLOTP

PLOTG:      
    PUSH DE
    LD DE, HL
    CALL VDPINCHAR
    POP DE
    AND C
    CP 0
    JR Z, PLOTG0
PLOTG1:
    LD A, $ff
    JMP PLOTP
PLOTG0:
    LD A, $0
    JMP PLOTP

PLOTC:                          
    JMP PLOTP

PLOTP:
    RET

;----------------------------------------------------------------

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
