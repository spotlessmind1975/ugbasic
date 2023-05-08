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
;*                        CLEAR LINE ROUTINE FOR VDC                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINE:
    LD A, (CURRENTMODE)
    CP 0
    JR Z,CLINE0
    JP CLINEDONE

CLINE0:
    LD HL, (TEXTADDRESS)
    LD (COPYOFTEXTADDRESS), HL

    PUSH BC
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

    LD A, (YCURSYS)
    CP 0
    JR Z, CLINE0SKIP
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
CLINE0LOOP1:
    ADD HL, DE
    DEC C
    JR NZ, CLINE0LOOP1
    LD (COPYOFTEXTADDRESS), HL

CLINE0SKIP:
    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP BC

    LD A, C
    CP 0
    JR Z, CLINE0CL
    LD (XCURSYS), A
CLINE0CL:
    LD A, (XCURSYS)
    LD B, A
    LD A, (CURRENTTILESWIDTH)
    SUB A, B
    LD C, A
    LD A, (EMPTYTILE)
CLINE0CL1:

    LD A, 18
    LD IXH, A
    LD A, (COPYOFTEXTADDRESS+1)
    LD IXL, A
    CALL VDCZWRITE
    LD A, 19
    LD IXH, A
    LD A, (COPYOFTEXTADDRESS)
    LD IXL, A
    CALL VDCZWRITE

    LD A, 24
    LD IXH, A
    CALL VDCZREAD
    AND $7F
    LD IXL, A
    CALL VDCZWRITE

    LD A, 31
    LD IXH, A
    LD A, (EMPTYTILE)
    LD IXL, A
    CALL VDCZWRITE

    LD A, 30
    LD IXH, A
    LD A, C
    LD IXL, A
    CALL VDCZWRITE

CLINEDONE:
    RET