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
;*                            PLOT ROUTINE FOR CGA                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Plot / erase a pixel
; Input:
;       AL : mode
;       DX : x
;       CL : y
PLOT:

    ; PUSH AF

    PUSH AX

    ; LD A, (CURRENTTILEMODE)
    ; CP 1
    ; JP Z, PLOTP

    MOV AL, [CURRENTMODE]
    CMP AL, 3
    JB PLOTP

@IF scaleX > 0
    SLA DX, 1
@ENDIF

@IF scaleX > 1
    SLA DX, 1
@ENDIF

@IF offsetX > 0
@EMIT offsetX AS offsetX
    ADD DX, offsetX
@ENDIF

@IF scaleY > 0
    SLA CL, 1
@ENDIF

@IF scaleY > 1
    SLA CL, 1
@ENDIF

@IF offsetY > 0
@EMIT offsetY AS offsetY
    ADD CL, offsetY
@ENDIF

@IF optionClip

    CMP CL, [CLIPY2]
    JA PLOTP
    CMP CL, [CLIPY1]
    JB PLOTP
    CMP DX, [CLIPX2]
    JA PLOTP
    CMP DX, [CLIPX1]
    JB PLOTP

@ENDIF

PLOTMODE:
    MOV AL, [CURRENTMODE]
    CMP AL, 4
    JZ PLOT4
    CMP AL, 5
    JZ PLOT5
    CMP AL, 6
    JZ PLOT6
    JMP PLOTP

PLOT4:
PLOT5:
PLOT6:

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    POP AX
    CMP AL, 0
    JZ PLOTE                  ;if = 0 then branch to clear the point
    CMP AL, 1
    JZ PLOTD                  ;if = 1 then branch to draw the point
    CMP AL, 2
    JZ PLOTG                  ;if = 2 then branch to get the point (0/1)
    CMP AL, 3
    JZ PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JP PLOTDONE

PLOTD:

    MOV AL, [PLOTCPE]
    CMP AL, [_PAPER]
    JZ PLOTE

    CALL CALCPOS

    MOV DL, [PLOTCPE]
    ROR DL, CL
    MOV AL, 0xfc
    ROR AL, CL
    AND AL, ES:[DI]
    OR AL, DL
    STOSB
    JZ PLOTDONE

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    
    CALL CALCPOS

    MOV AL, 0xfc
    ROR AL, CL
    AND AL, ES:[DI]
    STOSB
    JZ PLOTDONE

PLOTG:    
    JP PLOTDONE

PLOTC:
    JMP PLOTDONE

PLOTP:
    POP AX

PLOTDONE:
    RET