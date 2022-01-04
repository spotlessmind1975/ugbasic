; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                          IMAGES ROUTINE FOR MSX1                            *
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
    LD A, (CURRENTMODE)
    CP 0
    JR NZ, PUTIMAGE0X
    JMP PUTIMAGE0
PUTIMAGE0X:
    CP 1
    JR NZ, PUTIMAGE1X
    JMP PUTIMAGE1
PUTIMAGE1X:
    CP 2
    JR NZ, PUTIMAGE2X
    JMP PUTIMAGE2
PUTIMAGE2X:
    CP 3
    JR NZ, PUTIMAGE3X
    JMP PUTIMAGE3
PUTIMAGE3X:
    RET

PUTIMAGE0:
PUTIMAGE1:
PUTIMAGE3:
    RET

PUTIMAGE2:
    LD A, (HL)
    LD C, A
    INC HL
    LD A, (HL)
    SRL A
    SRL A
    SRL A
    LD B, A
    INC HL

    PUSH DE
    PUSH BC
    PUSH HL
    PUSH BC

    CALL VDPPOS

    LD DE, HL

    POP BC
    POP HL

PUTIMAGE0CPA:
    PUSH DE
    PUSH BC
PUTIMAGE0CP:
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    DEC C
    JR NZ, PUTIMAGE0CP
    POP BC
    LD A, (CURRENTWIDTH)
    SUB C
    ADD E
    JR NC,PUTIMAGE0CP2
    INC D    
PUTIMAGE0CP2:
    DEC B
    JR NZ, PUTIMAGE0CPA

    DI

    EXX

    POP BC
    POP DE

PUTIMAGE0CPCA:
    PUSH DE
    PUSH BC
PUTIMAGE0CPC:
    LD A, (HL)
    CALL VDPOUTCHAR
    INC DE
    INC HL
    DEC C
    JR NZ, PUTIMAGE0CPC
    POP BC
    LD A, (CURRENTWIDTH)
    SUB C
    ADD E
    JR NC,PUTIMAGE0CPC2
    INC D    
PUTIMAGE0CPC2:
    DEC B
    JR NZ, PUTIMAGE0CPCA

    EXX

    EI

    RET

