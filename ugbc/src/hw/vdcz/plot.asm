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
;*                           PLOT ROUTINE FOR VDC                              *
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
    JP Z, PLOTP2

    LD A, (CLIPY2)
    LD B, A
    LD A, IYL
    CP B
    JR C, PLOTCLIP2
    JR Z, PLOTCLIP2
    JP PLOTP
PLOTCLIP2:
    LD A, (CLIPY1)
    LD B, A
    LD A, IYL
    CP B
    JR Z, PLOTCLIP3
    JR NC, PLOTCLIP3
    JP PLOTP
PLOTCLIP3:
PLOTCLIP3B:
    LD A, (CLIPX2+1)
    LD B, A
    LD A, D
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
    LD A, D
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

    CALL VCDZPOS

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

    LD DE, HL
    CALL VDCZGETCHAR
    AND C
    OR B
    LD DE, HL
    CALL VDCZPUTCHAR

    LD DE, (COLORMAPADDRESS)
    ADD HL, DE
    LD DE, (TEXTADDRESS)
    SUB HL, DE
    LD DE, HL
    LD A, (_PEN)
    SLA A
    SLA A
    SLA A
    SLA A
    LD B, A
    LD A, (_PEN)
    OR B    
    CALL VDCZPUTCHAR

    JP PLOTDONE

PLOTE:

    LD DE, HL
    CALL VDCZGETCHAR
    AND C
    LD DE, HL
    CALL VDCZPUTCHAR

    JP PLOTDONE

PLOTC:
PLOTG:
    JR PLOTDONE

PLOTP2:
PLOTP:
    POP AF
PLOTDONE:
    RET