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

GETIMAGE:

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

    DEC IY
    PUSH IY
    PUSH DE

    LD A, (CURRENTMODE)
    CP 1
    JP Z, GETIMAGE1
    RET

GETIMAGE1:

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
    
GETIMAGE1L2:

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
GETIMAGE1L1:
    ; Draw them
    CALL VDCZGETCHAR
    ; Calculate new pixels
    LD (HL), A

    INC DE
    INC HL

    DEC C
    JP NZ, GETIMAGE1L1
    LD A, IXH
    CP $0
    JR Z, GETIMAGE1DONEROW

GETIMAGE1DONEROW:
    POP BC

    LD A, (IMAGEF)
    AND $41
    CP $41
    JP Z, GETIMAGE1DONEROW2
    AND $40
    CP $40
    JR NZ, GETIMAGE1DONEROW2
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
    JP GETIMAGE1L2

GETIMAGE1DONEROW2:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

    DEC B
    JP NZ, GETIMAGE1L2
    
    LD A, (IMAGET)
    AND $2
    CMP $2
    JR NZ, GETIMAGEC1DONE

    LD A, 26
    LD IXH, A
    CALL VDCZREAD
    LD (HL), A

GETIMAGEC1DONE:

    POP DE
    POP IY

    JP GETIMAGEDONE

GETIMAGEDONE:
    RET