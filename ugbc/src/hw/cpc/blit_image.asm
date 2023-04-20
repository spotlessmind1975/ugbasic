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
; MASK:       DW 0      -> HL'

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

BLITIMAGEBLITTING:
	JP (HL)

BLITIMAGE:

    LD A, (CURRENTTILEMODE)
    CP 1
    RET Z

    LD C, (HL)
    INC HL
    LD A, (HL)
    LD IXH, A
    INC HL
    LD B, (HL)
    INC HL

    DI
    EXX
    EI

    INC HL
    INC HL
    INC HL

    DI
    EXX
    EI

    DEC D
    PUSH DE

    LD A, (CURRENTMODE)
    CP 0
    JP Z, BLITIMAGE0
    CP 1
    JP Z, BLITIMAGE1
    CP 2
    JP Z, BLITIMAGE2
    CP 3
    JP Z, BLITIMAGE3
    POP DE
    RET

BLITIMAGE0:
BLITIMAGE3:

    SRL C

BLITIMAGE0L2:

    POP DE

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
BLITIMAGE0L1:

    ; SOURCE
    LD A, (HL)
    LD B, A

    ; DESTINATION
    LD A, (DE)
    LD IYL, A

    DI
    EXX
    EI

    ; MASK
    LD A, (HL)
    LD IYH, A

    PUSH DE

    DI
    EXX
    EI

    POP IX
    PUSH HL
    PUSH IX
    POP HL

    CALL BLITIMAGEBLITTING

    POP HL
    
    LD (DE),A

    INC DE
    INC HL

    DI
    EXX
    EI

    INC HL

    DI
    EXX
    EI

    DEC C
    JR NZ, BLITIMAGE0L1
    ; LD A, IXH
    ; CP $0
    ; JR Z, BLITIMAGE0DONEROW
    ; DEC IXH
    ; LD A, $FF
    ; LD C, A
    ; JP BLITIMAGE0L1
BLITIMAGE0DONEROW:
    POP BC

    LD A, (IMAGEF)
    AND $41
    CP $41
    JR Z, BLITIMAGE0DONEROW2
    AND $40
    CP $40
    JR NZ, BLITIMAGE0DONEROW2
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
    JP BLITIMAGE0L2

BLITIMAGE0DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    DEC B
    JP NZ, BLITIMAGE0L2
    
    LD A, 16
    LD B, A
    LD A, 0
    LD C, A

    LD A, (IMAGEF)
    AND $20
    CP $20
    JR NZ, BLITIMAGE0DONEROWL1

    INC HL
    INC C

BLITIMAGE0DONEROWL1:
    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, BLITIMAGEC0DONE

    LD A, (HL)
    LD IXL, A
    LD IXH, C
    LD IYL, 1
    CALL CPCUPDATEPALETTE
    INC HL
    INC C
    LD A, C
    CP 16
    JR NZ, BLITIMAGE0DONEROWL1

BLITIMAGEC0DONE:

    POP DE

    JP BLITIMAGEDONE

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

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
BLITIMAGE1L1:

    ; SOURCE
    LD A, (HL)
    LD B, A

    ; DESTINATION
    LD A, (DE)
    LD IYL, A

    DI
    EXX
    EI

    ; MASK
    LD A, (HL)
    LD IYH, A

    PUSH DE

    DI
    EXX
    EI

    POP IX
    PUSH HL
    PUSH IX
    POP HL

    CALL BLITIMAGEBLITTING

    POP HL
    
    LD (DE),A

    INC DE
    INC HL

    DI
    EXX
    EI

    INC HL

    DI
    EXX
    EI

    DEC C
    JP NZ, BLITIMAGE1L1
    LD A, IXH
    CP $0
    JR Z, BLITIMAGE1DONEROW
    ; DEC IXH
    ; LD A, $FF
    ; LD C, A
    ; JP BLITIMAGE1L1
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
    JP BLITIMAGE0L2

BLITIMAGE1DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    DEC B
    JP NZ, BLITIMAGE1L2
    
    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, BLITIMAGE1DONEROW2T

    LD A, (HL)
    LD IXL, A
    LD IXH, 0
    LD IYL, 1
    CALL CPCUPDATEPALETTE

BLITIMAGE1DONEROW2T:

    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, BLITIMAGEC1DONE

    INC HL

    LD A, (HL)
    LD IXL, A
    LD IXH, 1
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    INC HL

    LD A, (HL)
    LD IXL, A
    LD IXH, 2
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    INC HL

    LD A, (HL)
    LD IXL, A
    LD IXH, 3
    LD IYL, 1
    CALL CPCUPDATEPALETTE

BLITIMAGEC1DONE:

    POP DE

    JP BLITIMAGEDONE

BLITIMAGE2:

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

BLITIMAGE2L2:

    POP DE

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
BLITIMAGE2L1:
    ; SOURCE
    LD A, (HL)
    LD B, A

    ; DESTINATION
    LD A, (DE)
    LD IYL, A

    DI
    EXX
    EI

    ; MASK
    LD A, (HL)
    LD IYH, A

    PUSH DE

    DI
    EXX
    EI

    POP IX
    PUSH HL
    PUSH IX
    POP HL

    CALL BLITIMAGEBLITTING

    POP HL
    
    LD (DE),A

    INC DE
    INC HL

    DI
    EXX
    EI

    INC HL

    DI
    EXX
    EI

    DEC C
    JP NZ, BLITIMAGE2L1
    ; LD A, IXH
    ; CP $0
    ; JR Z, BLITIMAGE2DONEROW
    ; DEC IXH
    ; LD A, $FF
    ; LD C, A
    ; JP BLITIMAGE2L1
BLITIMAGE2DONEROW:
    POP BC

    LD A, (IMAGEF)
    AND $41
    CP $41
    JR Z, BLITIMAGE2DONEROW2
    AND $40
    CP $40
    JR NZ, BLITIMAGE2DONEROW2
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
    JP BLITIMAGE0L2

BLITIMAGE2DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    DEC B
    JP NZ, BLITIMAGE2L2

    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, BLITIMAGEC2DONE

    LD A, (IMAGEF)
    AND $20
    CP $20
    JP Z, BLITIMAGE2DONEROW2T

    LD A, (HL)
    LD IXL, A
    LD IXH, 0
    LD IYL, 1
    CALL CPCUPDATEPALETTE

BLITIMAGE2DONEROW2T:
    INC HL

    LD A, (HL)
    LD IXL, A
    LD IXH, 1
    LD IYL, 1
    CALL CPCUPDATEPALETTE

BLITIMAGEC2DONE:
    POP DE

    JP BLITIMAGEDONE

BLITIMAGEDONE:
    RET