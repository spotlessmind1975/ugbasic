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
;*                      TEXT AT GIVEN POSITION ON VDCZ                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATRAWPIXPOS:
    PUSH AF
    PUSH DE
    PUSH HL
    LD HL, PLOTVBASE

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATRAWPIXPOSSKIPY

    LD E, A
    LD A, $0
    LD D, A

    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D

    ADD HL, DE

TEXTATRAWPIXPOSSKIPY:    
    LD A, (HL)
    LD (COPYOFTEXTADDRESS), A
    INC HL
    LD A, (HL)
    LD (COPYOFTEXTADDRESS+1), A

    LD HL, (COPYOFTEXTADDRESS)

    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0

    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP HL
    POP DE
    POP AF
    RET

TEXTATBITMAPMODERAW:

    LD A, C
    CP 0
    JR NZ,TEXTATRAWBITMAPMODEGO
    JP TEXTATRAWBITMAPMODEDONE

TEXTATRAWBITMAPMODEGO:

TEXTATRAWBMSKIP:
    
TEXTATRAWBMLOOP2:

    LD A, (DE)

    CALL TEXTATDECODE

    PUSH DE
    PUSH BC

    LD BC, 8

    LD H, 0
    LD L, A
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    LD HL, UDCCHAR
    ADD HL, DE

    CALL TEXTATRAWPIXPOS

    LD DE, (COPYOFTEXTADDRESS)

TEXTATRAWFONT1L1:

    LD A, (HL)
    CALL VDCZPUTCHAR

    INC HL

    PUSH HL
    LD A, (CURRENTTILESWIDTH)
    LD L, A
    LD A, 0
    LD H, A
    ADD HL, DE
    LD DE, HL
    POP HL

    DEC C
    JR NZ, TEXTATRAWFONT1L1

    POP BC
    POP DE

    JP TEXTATRAWBMINCX

TEXTATRAWBMSKIPTAB:
    LD A, (TABSTODRAW)
    DEC A
    LD (TABSTODRAW),A
    JP TEXTATRAWBMINCX

TEXTATRAWBMINCX:
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, 1
    LD (COPYOFTEXTADDRESS), HL
    INC DE
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    DEC C
    JP Z, TEXTATRAWBMEND2
    PUSH AF
    LD A, (CURRENTTILESWIDTH)
    LD B, A
    POP AF
    CP B
    JR Z, TEXTATRAWBMNEXT2
    JP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT2:
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

    JR Z, TEXTATRAWBMNEXT3
    JP TEXTATRAWBMNEXT
TEXTATRAWBMNEXT3:

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    CALL VSCROLLUP
    POP HL
    POP DE
    POP BC
    POP AF

    LD A, (YCURSYS)
    DEC A
    LD (YCURSYS), A

    PUSH DE
    LD A, (CURRENTTILESWIDTH) 
    LD E, A
    LD D, 0
    PUSH HL
    LD HL, DE
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    LD DE, HL
    POP HL

    LD HL, (COPYOFTEXTADDRESS)
    SBC HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE

TEXTATRAWBMNEXT:
TEXTATRAWBMXLOOP2:
    LD A, C
    CP 0
    JR Z, TEXTATRAWBMEND
    JP TEXTATRAWBMLOOP2
TEXTATRAWBMEND2:
TEXTATRAWBMEND:
    JP TEXTATRAWBITMAPMODEDONE

TEXTATRAWBITMAPMODEDONE:
    RET
        