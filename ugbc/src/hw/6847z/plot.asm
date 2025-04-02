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
;*                            PLOT ROUTINE FOR 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;--------------

; IXL:E - x
; D - y
PLOT:
    PUSH AF

    LD A, (CURRENTTILEMODE)
    CP 1
    JP Z, PLOTPA

@IF scaleX > 0
    PUSH AF
    LD A, E
    SLA A
    LD E, A
    POP AF
@ENDIF

@IF scaleX > 1
    PUSH AF
    LD A, E
    SLA A
    LD E, A
    POP AF
@ENDIF

@IF offsetX > 0
@EMIT offsetX AS offsetX
    PUSH AF
    LD A, E
    ADD offsetX
    LD E, A
    POP AF
@ENDIF

@IF scaleY > 0
    PUSH AF
    LD A, D
    SLA A
    LD D, A
    POP AF
@ENDIF

@IF scaleY > 1
    PUSH AF
    LD A, D
    SLA A
    LD D, A
    POP AF
@ENDIF

@IF offsetY > 0
@EMIT offsetY AS offsetY
    PUSH AF
    LD A, D
    ADD offsetY
    LD D, A
    POP AF
@ENDIF

@IF optionClip

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
    JR Z, PLOTCLIP42
    JR NC, PLOTCLIP5
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

@ENDIF

@IF !vestigialConfig.screenModeUnique

PLOTMODE:
    LD A, (CURRENTMODE)
    CP 0
    JR Z, PLOT0
    CP 9
    JR Z, PLOT9
    JP PLOTPA

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 0) )

PLOT0:
    JP PLOTPA

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 9) )

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
PLOT9:

    LD A, 2
    LD (PLOTNB), A

    LD HL, (BITMAPADDRESS)

    PUSH DE
    LD B, E
    LD E, D
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE
    LD E, B
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE
    POP DE

    PUSH HL
    PUSH DE
    LD HL, PLOTORBIT40
    LD D, 0
    LD A, (PLOTCPE)
    AND 3
    LD E, A
    SLA E
    SLA E
    ADD HL, DE
    LD IX, (HL)
    POP DE
    LD A, E
    AND 3
    LD E, A
    LD D, 0
    ADD IX, DE
    POP HL

    LD IY, PLOTANDBIT4
    ADD IY, DE

    LD A, E
    LD B, A
    LD A, 3
    SUB B
    LD (PLOTND), A

    CALL PLOTPREPARE

    JP PLOTCOMMON

@ENDIF

PLOTPREPARE:
    LD A, (IY)
    LD (PLOTAMA), A
    LD A, (IX)
    LD (PLOTOMA), A
    RET

PLOTCOMMON:

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

    LD A, (PLOTAMA)
    LD B, A
    LD A, (PLOTOMA)
    LD C, A
    LD A, (HL)           ;get row with point in it
    AND B
    OR C
    LD (HL), A
    JP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    LD A, (PLOTAMA)
    LD B, A
    LD A, (HL)           ;get row with point in it
    AND B
    LD (HL), A
    JP PLOTP                  ;skip the erase-point section

PLOTC:
    JP PLOTP      

PLOTG:
    JP PLOTP

PLOTPA:
    POP AF
PLOTP:
    RET

;----------------------------------------------------------------

PLOTORBIT:
    defb  %10000000
    defb  %01000000
    defb  %00100000
    defb  %00010000
    defb  %00001000
    defb  %00000100
    defb  %00000010
    defb  %00000001

PLOTANDBIT:
    defb  %01111111
    defb  %10111111
    defb  %11011111
    defb  %11101111
    defb  %11110111
    defb  %11111011
    defb  %11111101
    defb  %11111110

PLOTORBIT40:
    defb  %00000000
    defb  %00000000
    defb  %00000000
    defb  %00000000

PLOTORBIT41:
    defb  %01000000
    defb  %00010000
    defb  %00000100
    defb  %00000001

PLOTORBIT42:
    defb  %10000000
    defb  %00100000
    defb  %00001000
    defb  %00000010

PLOTORBIT43:
    defb  %11000000
    defb  %00110000
    defb  %00001100
    defb  %00000011

PLOTANDBIT4:
    defb  %00111111
    defb  %11001111
    defb  %11110011
    defb  %11111100
