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
;*                      TEXT AT GIVEN POSITION ON VDC                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATTILEMODERAW:

TEXTATTILEMODENMI2RAW:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, C
    CP 0
    JR NZ,TEXTATRAWTILEMODEGO
    JP TEXTATRAWTILEMODEDONE

TEXTATRAWTILEMODEGO:
    PUSH BC
    PUSH DE

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

    LD A, (CURRENTMODE)
    CP 0
    JR Z,TEXTATRAWTILEMODEGO0
    RET

TEXTATRAWTILEMODEGO0:
TEXTATRAWTILEMODEGO1:
    LD HL, (TEXTADDRESS)
    LD (COPYOFTEXTADDRESS), HL
    LD HL, (COLORMAPADDRESS)
    LD (COPYOFCOLORMAPADDRESS), HL
    JMP TEXTATRAWTILEMODEGOX

TEXTATRAWTILEMODEGOX:

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATRAWSKIP
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
TEXTATRAWLOOP1:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATRAWLOOP1
    LD (COPYOFTEXTADDRESS), HL

TEXTATRAWSKIP:
    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    LD HL, (TEXTADDRESS)
    LD DE, HL
    LD HL, (COPYOFTEXTADDRESS)
    AND A
    SBC HL, DE
    LD DE, HL
    LD HL, (COLORMAPADDRESS)
    ADD HL, DE
    LD (COPYOFCOLORMAPADDRESS), HL
    LD HL, (COPYOFTEXTADDRESS)
    
    POP DE
    POP BC
    
TEXTATRAWLOOP2:

    LD A, (DE)

    CALL TEXTATDECODE

    PUSH DE
    PUSH BC
    LD HL, (COPYOFTEXTADDRESS)

    LD DE, HL
    CALL VDCZPUTCHAR

    PUSH AF
    LD A, (CURRENTMODE)
    CP 0
    JR Z,TEXTATRAW20
    POP AF
    POP BC
    POP DE
    RET

TEXTATRAW20:
TEXTATRAW21:
    PUSH HL
    PUSH AF
    PUSH DE
    PUSH BC

    LD HL, (COPYOFCOLORMAPADDRESS)
    LD DE, HL
    LD A, (_PEN)
    OR $80
    CALL VDCZPUTCHAR
    POP BC
    POP DE
    POP AF
    POP HL
    POP AF

    POP BC
    POP DE

    LD HL, (COPYOFTEXTADDRESS)
    INC HL
    LD (COPYOFTEXTADDRESS), HL
    LD HL, (COPYOFCOLORMAPADDRESS)
    INC HL
    LD (COPYOFCOLORMAPADDRESS), HL
    INC DE
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    DEC C
    JP Z, TEXTATRAWEND2
    PUSH AF
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATRAWNEXT2
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT2:
    LD A, 0
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    PUSH AF
    LD A, (CURRENTTILESHEIGHT)
    LD B, A
    POP AF
    CP B

    JR Z, TEXTATRAWNEXT3
    JMP TEXTATRAWNEXT
TEXTATRAWNEXT3:

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    CALL VSCROLLTUP
    POP HL
    POP DE
    POP BC
    POP AF

    LD A, (YCURSYS)
    DEC A
    LD (YCURSYS), A
    LD HL, (COPYOFTEXTADDRESS)
    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    SBC HL, DE
    POP DE
    LD (COPYOFTEXTADDRESS), HL

    LD HL, (COPYOFCOLORMAPADDRESS)
    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    SBC HL, DE
    POP DE
    LD (COPYOFCOLORMAPADDRESS), HL

TEXTATRAWNEXT:
    LD A, C
    CP 0
    JR Z, TEXTATRAWEND2
    JMP TEXTATRAWLOOP2
TEXTATRAWEND2:
TEXTATRAWEND:
    JP TEXTATRAWTILEMODEDONE

TEXTATRAWTILEMODEDONE:
    RET