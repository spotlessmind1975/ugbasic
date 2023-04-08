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
;*                           PLOT ROUTINE FOR CPC                              *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; PLOTX    = $F7 ; $F8  -> E
; PLOTY    = $F9        -> D
; PLOTM    = $FB        -> B
; PLOTOMA  = $FD
; PLOTAMA  = $FC

PLOT:

    PUSH AF

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

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
    LD A, (CLIPX2+1)
    LD B, A
    LD A, IXL
    CP B
    JR C, PLOTCLIP4
    JR Z, PLOTCLIP32
    JP PLOTP
PLOTCLIP32:
PLOTCLIP32B:
    LD A, (CLIPX2)
    LD B, A
    LD A, E
    CP B
    JR C, PLOTCLIP4
    JR Z, PLOTCLIP4
    JP PLOTP
PLOTCLIP4:
PLOTCLIP4B:
    LD A, (CLIPX1+1)
    LD B, A
    LD A, IXL
    CP B
    JR NC, PLOTCLIP5
    JR Z, PLOTCLIP42
    JP PLOTP
PLOTCLIP42:
PLOTCLIP42B:
    LD A, (CLIPX1)
    LD B, A
    LD A, E
    CP B
    JR NC, PLOTCLIP5
    JR Z, PLOTCLIP5
    JP PLOTP
PLOTCLIP5:

PLOTMODE:

    CALL CPCVIDEOPOS

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    POP AF
    CP 0
    JP Z, PLOTE                  ;if = 0 then branch to clear the point
    CP 1
    JP Z, PLOTD                  ;if = 1 then branch to draw the point
    CP 2
    JP Z, PLOTG                  ;if = 2 then branch to get the point (0/1)
    CP 3
    JP Z, PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JP PLOTP2

PLOTD:

    LD A, (_PEN)
    LD IXL, A
    LD A, 1
    LD IYL, A
    LD A, (_PEN)
    CALL CPCSELECTPALETTE
    LD A, IXH
    LD B, A

    LD A, (CURRENTMODE)
    CP 0
    JP Z, PLOTD0
    CP 1
    JP Z, PLOTD1
    CP 2
    JP Z, PLOTD2
    CP 3
    JP Z, PLOTD3
    RET

PLOTD0:
    LD A, E
    AND $01
    CP 0
    JR Z, PLOTD00
    LD A, $55
    JR PLOTD00X
PLOTD00:
    LD A, $aa
PLOTD00X:

    LD DE, HL

    ; H = bitmask of pixels
    ; B = color index
    ; L = masking against existing pixels / existing pixels 
    ; DE = starting memory location on screen
    LD H, A

    ; Calculate mask for this pixel component
    LD A, H
    ; Calculate color components for mask if color was
    ; all 1's ($ff)
    PUSH BC
    LD B, $F
    CALL CPCVIDEOMUL84

    ; Negate it for masking
    XOR $FF
    LD L, A

    POP BC

    ; Masquerade existing pixels
    LD A, (DE)
    AND L
    LD L, A

    ; Calculate new pixels
    LD A, H
    CALL CPCVIDEOMUL84

    ; Sum up old and new pixels.
    OR L

    ; Draw them
    LD (DE),A
    
    JP PLOTDONE


PLOTD1:
    PUSH HL
    PUSH DE
    LD HL, CPCVIDEOBITMASK2
    LD A, 0
    LD D, A
    LD A, E
    AND $3
    LD E, A
    ADD HL, DE
    LD A, (HL)
    POP DE
    POP HL

    LD DE, HL

    ; H = bitmask of pixels
    ; B = color index
    ; L = masking against existing pixels / existing pixels 
    ; DE = starting memory location on screen
    LD H, A

    ; Calculate mask for this pixel component
    LD A, H
    ; Calculate color components for mask if color was
    ; all 1's ($ff)
    PUSH BC
    LD B, $3
    CALL CPCVIDEOMUL82

    ; Negate it for masking
    XOR $FF
    LD L, A

    POP BC

    ; Masquerade existing pixels
    LD A, (DE)
    AND L
    LD L, A

    ; Calculate new pixels
    LD A, H
    CALL CPCVIDEOMUL82

    ; Sum up old and new pixels.
    OR L

    ; Draw them
    LD (DE),A
    
    JP PLOTDONE

PLOTD2:
    PUSH HL
    PUSH DE
    LD HL, CPCVIDEOBITMASK4
    LD A, 0
    LD D, A
    LD A, E
    AND $7
    LD E, A
    ADD HL, DE
    LD A, (HL)
    POP DE
    POP HL

    LD DE, HL

    ; H = bitmask of pixels
    ; B = color index
    ; L = masking against existing pixels / existing pixels 
    ; DE = starting memory location on screen
    LD H, A

    ; Calculate mask for this pixel component
    LD A, H
    ; Calculate color components for mask if color was
    ; all 1's ($ff)
    ; Negate it for masking
    XOR $FF
    LD L, A

    ; Masquerade existing pixels
    LD A, (DE)
    AND L
    LD L, A

    ; Calculate new pixels
    LD A, H

    ; Sum up old and new pixels.
    OR L

    ; Draw them
    LD (DE),A
    
    JP PLOTDONE

PLOTD3:
    JP PLOTDONE

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    LD A, (CURRENTMODE)
    CP 0
    JR Z, PLOTE0
    CP 1
    JR Z, PLOTE1
    CP 2
    JR Z, PLOTE2
    CP 3
    JR Z, PLOTE3
    RET

PLOTE0:
PLOTE1:
PLOTE2:
PLOTE3:
    JP PLOTDONE

PLOTC:
    LD A, (CURRENTMODE)
    CP 0
    JP Z, PLOTC0
    CP 1
    JP Z, PLOTC1
    CP 2
    JP Z, PLOTC2
    CP 3
    JP Z, PLOTC3
    RET

PLOTC0:
    LD A, E
    AND $01
    CP 1
    JR NZ, PLOTC00

    LD DE, HL
    LD A, (DE)
    SRL A

    JR PLOTC00X

PLOTC00:

    LD DE, HL
    LD A, (DE)

PLOTC00X:

    PUSH AF
    AND $01
    SLA A
    SLA A
    SLA A
    LD D, A
    POP AF

    PUSH AF
    AND $04
    SRL A
    SRL A
    LD E, A
    POP AF

    PUSH AF
    AND $10
    SRL A
    SRL A
    LD IXL, A
    POP AF

    PUSH AF
    AND $40
    SRL A
    SRL A
    SRL A
    LD IXH, A
    POP AF

    LD A, D
    OR E
    OR IXL
    OR IXH
    JP PLOTCDONE


PLOTC1:
    LD A, E
    AND $03
    CP 3
    JR Z, PLOTC13
    CP 2
    JR Z, PLOTC12
    CP 1
    JR Z, PLOTC11
PLOTC10:
    LD DE, HL    
    LD A, (DE)
    SRL A
    SRL A
    SRL A
    JR PLOTC100
PLOTC11:
    LD DE, HL    
    LD A, (DE)
    SRL A
    SRL A
    JR PLOTC100
PLOTC12:
    LD DE, HL    
    LD A, (DE)
    SRL A
    JR PLOTC100
PLOTC13:
    LD DE, HL    
    LD A, (DE)
    JR PLOTC100
PLOTC100:
    PUSH AF
    AND $01
    SLA A
    SLA A
    SLA A
    SLA A
    LD D, A
    POP AF

    PUSH AF
    AND $10
    SRL A
    SRL A
    SRL A
    SRL A
    LD E, A
    POP AF

    LD A, D
    OR E
    JP PLOTCDONE

PLOTC2:
    LD A, E
    AND $07
    LD C, A
    LD A, 8
    SUB C
    LD C, A
    LD DE, HL
    LD A, (DE)
PLOTC2L:
    SRL A
    DEC C
    JR NZ, PLOTC2L

    JR NC, PLOTC2N
    LD A, 1
    JP PLOTCDONE
PLOTC2N:
    LD A, 0
    JP PLOTCDONE

PLOTC3:
    JP PLOTCDONE

PLOTCDONE:
    LD IXH, A
    CALL CPCGETPALETTE
    LD A, IXL
    JP PLOTDONE

PLOTG:      
    JP PLOTDONE

PLOTP:
    POP AF
PLOTP2:
    JP PLOTDONE

PLOTDONE:
    RET