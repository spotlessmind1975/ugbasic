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

GETIMAGE:

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
    CP 0
    JP Z, GETIMAGE0
    CP 1
    JP Z, GETIMAGE1
    CP 2
    JP Z, GETIMAGE2
    CP 3
    JP Z, GETIMAGE3
    POP DE
    RET

GETIMAGE0:
GETIMAGE3:

    SRL C

GETIMAGE0L2:

    POP DE

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
GETIMAGE0L1:
    ; Calculate new pixels
    LD A, (DE)
    ; Draw them
    LD (HL),A

    INC DE
    INC HL

    DEC C
    JR NZ, GETIMAGE0L1
    LD A, IXL
    CP $0
    JR Z, GETIMAGE0DONEROW
    DEC IXL
    LD A, $FF
    LD C, A
    JP GETIMAGE0L1
GETIMAGE0DONEROW:
    POP BC

    DEC B
    JR NZ, GETIMAGE0L2
    
    LD A, 16
    LD B, A
    LD A, 0
    LD C, A

GETIMAGE0DONEROWL1:
    LD A, IXH
    CP 0
    JR Z, GETIMAGE0PALETTEDONE
GETIMAGE0DONEROWL10:
    LD IXH, C
    CALL CPCGETPALETTE
    LD A, IXL
    LD (HL), A
    INC HL
    INC C
    DEC B
    JR NZ, GETIMAGE0DONEROWL10

GETIMAGE0PALETTEDONE:
    POP DE

    JP GETIMAGEDONE

GETIMAGE1:

    SRA C
    SRA C

GETIMAGE1L2:

    POP DE

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
GETIMAGE1L1:
    ; Calculate new pixels
    LD A, (DE)
    ; Draw them
    LD (HL),A

    INC DE
    INC HL

    DEC C
    JR NZ, GETIMAGE1L1
    LD A, IXL
    CP $0
    JR Z, GETIMAGE1DONEROW
    DEC IXL
    LD A, $FF
    LD C, A
    JP GETIMAGE1L1
GETIMAGE1DONEROW:
    POP BC

    LD A, IXH
    CP 0
    JR Z, GETIMAGE1PALETTEDONE

    DEC B
    JR NZ, GETIMAGE1L2
    
    LD IXH, 0
    CALL CPCGETPALETTE
    LD A,IXL
    LD (HL), A

    INC HL

    LD IXH, 1
    CALL CPCGETPALETTE
    LD A,IXL
    LD (HL), A

    INC HL

    LD IXH, 2
    CALL CPCGETPALETTE
    LD A,IXL
    LD (HL), A

    INC HL

    LD IXH, 3
    CALL CPCGETPALETTE
    LD A,IXL
    LD (HL), A

GETIMAGE1PALETTEDONE:

    POP DE

    JP GETIMAGEDONE

GETIMAGE2:

    SRA C
    SRA C
    SRA C

GETIMAGE2L2:

    POP DE

    INC D

    PUSH DE

    PUSH HL
    CALL CPCVIDEOPOS
    LD DE, HL
    POP HL

    PUSH BC
GETIMAGE2L1:
    ; Calculate new pixels
    LD A, (DE)
    ; Draw them
    LD (HL),A

    INC DE
    INC HL

    DEC C
    JR NZ, GETIMAGE2L1
    LD A, IXL
    CP $0
    JR Z, GETIMAGE2DONEROW
    DEC IXL
    LD A, $FF
    LD C, A
    JP GETIMAGE2L1
GETIMAGE2DONEROW:
    POP BC

    LD A, IXH
    CP 0
    JR Z, GETIMAGE2PALETTEDONE

    DEC B
    JR NZ, GETIMAGE2L2

    LD IXH, 0
    CALL CPCGETPALETTE
    LD A,IXL
    LD (HL), A

    INC HL

    LD IXH, 1
    CALL CPCGETPALETTE
    LD A,IXL
    LD (HL), A

GETIMAGE2PALETTEDONE:

    POP DE

    JP GETIMAGEDONE

GETIMAGEDONE:
    RET