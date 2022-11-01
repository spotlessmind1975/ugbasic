; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

; IMAGET:     DB 0      -> A
; IMAGEX:     DB 0      -> E
; IMAGEY:     DB 0      -> D
; IMAGEW:     DB 0      -> C
; IMAGEH:     DB 0      -> B
; IMAGEH2:    DB 0      -> ?
; PTR:        DW 0      -> HL

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

PUTIMAGE:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD C, (HL)
    INC HL
    LD A, (HL)
    LD IXL, A
    INC HL
    LD B, (HL)
    INC HL

    DEC D
    PUSH DE

    LD A, (CURRENTMODE)
    ; CP 0
    ; JP Z, PUTIMAGE0
    ; CP 1
    ; JP Z, PUTIMAGE1
    CP 2
    JP Z, PUTIMAGE2
    ; CP 3
    ; JP Z, PUTIMAGE3
    POP DE
    RET

PUTIMAGE0:
;     LD A, E
;     AND $01
;     CP 0
;     JR Z, PLOTD00
;     LD A, $55
;     JR PLOTD00X
; PLOTD00:
;     LD A, $aa
; PLOTD00X:

;     LD DE, HL

;     ; H = bitmask of pixels
;     ; B = color index
;     ; L = masking against existing pixels / existing pixels 
;     ; DE = starting memory location on screen
;     LD H, A

;     ; Calculate mask for this pixel component
;     LD A, H
;     ; Calculate color components for mask if color was
;     ; all 1's ($ff)
;     PUSH BC
;     LD B, $F
;     CALL CPCVIDEOMUL84

;     ; Negate it for masking
;     XOR $FF
;     LD L, A

;     POP BC

;     ; Masquerade existing pixels
;     LD A, (DE)
;     AND L
;     LD L, A

;     ; Calculate new pixels
;     LD A, H
;     CALL CPCVIDEOMUL84

;     ; Sum up old and new pixels.
;     OR L

;     ; Draw them
;     LD (DE),A
    
;     JP PLOTDONE


; PLOTD1:
;     PUSH HL
;     PUSH DE
;     LD HL, CPCVIDEOBITMASK2
;     LD A, 0
;     LD D, A
;     LD A, E
;     AND $3
;     LD E, A
;     ADD HL, DE
;     LD A, (HL)
;     POP DE
;     POP HL

;     LD DE, HL

;     ; H = bitmask of pixels
;     ; B = color index
;     ; L = masking against existing pixels / existing pixels 
;     ; DE = starting memory location on screen
;     LD H, A

;     ; Calculate mask for this pixel component
;     LD A, H
;     ; Calculate color components for mask if color was
;     ; all 1's ($ff)
;     PUSH BC
;     LD B, $3
;     CALL CPCVIDEOMUL82

;     ; Negate it for masking
;     XOR $FF
;     LD L, A

;     POP BC

;     ; Masquerade existing pixels
;     LD A, (DE)
;     AND L
;     LD L, A

;     ; Calculate new pixels
;     LD A, H
;     CALL CPCVIDEOMUL82

;     ; Sum up old and new pixels.
;     OR L

;     ; Draw them
;     LD (DE),A
    
;     JP PLOTDONE

PUTIMAGE2:

    SRA C
    SRA C
    SRA C

PUTIMAGE2L2:

    POP DE

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
PUTIMAGE2L1:
    ; Calculate new pixels
    LD A, (HL)
    ; Draw them
    LD (DE),A

    INC DE
    INC HL

    DEC C
    JR NZ, PUTIMAGE2L1
    LD A, IXL
    CP $0
    JR Z, PUTIMAGE2DONEROW
    DEC IXL
    LD A, $FF
    LD C, A
    JP PUTIMAGE2L1
PUTIMAGE2DONEROW:
    POP BC
    DEC B
    JR NZ, PUTIMAGE2L2
    
    LD A, (HL)
    LD IXL, A
    LD A, 0
    LD IXH, A
    LD A, 1
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    INC HL

    LD A, (HL)
    LD IXL, A
    LD A, 1
    LD IXH, A
    LD A, 1
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    POP DE

    JP PUTIMAGEDONE

PUTIMAGE3:
    JP PUTIMAGEDONE

PUTIMAGEDONE:
    RET