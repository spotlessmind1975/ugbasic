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
;*                          IMAGES ROUTINE FOR VDCZ                            *
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

BLITIMAGEBLITTING:
    LD HL, (BLITIMAGEBLITTINGADDR)
	JP (HL)

BLITIMAGE:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD HL, (BLITTMPPTR)
    LD C, (HL)
    INC HL
    LD A, (HL)
    LD IXH, A
    INC HL
    LD B, (HL)
    INC HL
    LD (BLITTMPPTR), HL

    LD HL, (BLITTMPPTR2)
    INC HL
    INC HL
    INC HL
    LD (BLITTMPPTR2), HL

    DEC IY
    PUSH IY
    PUSH DE

    LD A, (CURRENTMODE)
    CP 1
    JP Z, BLITIMAGE1
    RET

BLITIMAGE1:

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
    
BLITIMAGE1L2:

    POP DE
    POP IY

    INC IY

    PUSH IY
    PUSH DE

    PUSH HL
    PUSH BC
    CALL VCDZPOS
    LD DE, HL
    POP BC
    POP HL

    PUSH BC
BLITIMAGE1L1:
    PUSH HL
    ; SOURCE
    LD HL, (BLITTMPPTR)
    LD A, (HL)
    LD B, A

    ; DESTINATION
    CALL VDCZGETCHAR
    LD IYL, A

    LD HL, (BLITTMPPTR2)
    LD A, (HL)
    LD IYH, A

    POP HL

    PUSH HL
    CALL BLITIMAGEBLITTING
    POP HL

    ; Draw them
    CALL VDCZPUTCHAR

    INC DE

    LD HL, (BLITTMPPTR)
    INC HL
    LD (BLITTMPPTR), HL

    LD HL, (BLITTMPPTR2)
    INC HL
    LD (BLITTMPPTR2), HL

    DEC C
    JP NZ, BLITIMAGE1L1
    LD A, IXH
    CP $0
    JR Z, BLITIMAGE1DONEROW

BLITIMAGE1DONEROW:
    POP BC

    LD A, (IMAGEF)
    AND $41
    CP $41
    JP Z, BLITIMAGE1DONEROW2
    AND $40
    CP $40
    JR NZ, BLITIMAGE1DONEROW2
    OR $01
    LD (IMAGEF), A

    PUSH DE
    LD A, C
    LD E, A
    LD A, 0
    LD D, A
    AND A
    SBC HL, DE
    POP DE
    JP BLITIMAGE1L2

BLITIMAGE1DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    DEC B
    JP NZ, BLITIMAGE1L2
    
    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, BLITIMAGEC1DONE

    LD HL, (BLITTMPPTR)
    LD A, (HL)
    LD IXL, A
    LD A, 26
    LD IXH, A
    CALL VDCZWRITE

BLITIMAGEC1DONE:

    POP DE
    POP IY

    JP BLITIMAGEDONE

BLITIMAGEDONE:
    RET