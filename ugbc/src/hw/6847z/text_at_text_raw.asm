; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      RAW TEXT AT GIVEN POSITION ON 6847                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: text address, C : characters

TEXTATTILEMODERAW:

    LD A, (CURRENTTILEMODE)
    CP 0
    RET Z

    LD A, C
    CP 0
    RET Z

TEXTATTILEMODERAWGO:
    PUSH BC
    PUSH DE

    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

    LD HL, (TEXTADDRESS)
    LD (COPYOFTEXTADDRESS), HL

TEXTATTILEMODERAWGOX:
    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATSKIPRAW
    LD C, A
    LD HL, (COPYOFTEXTADDRESS)
TEXTATLOOP1RAW:
    ADD HL, DE
    DEC C
    JR NZ, TEXTATLOOP1RAW
    LD (COPYOFTEXTADDRESS), HL

TEXTATSKIPRAW:
    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    LD HL, (COPYOFTEXTADDRESS)
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP DE
    POP BC
    
TEXTATLOOP2RAW:

TEXTATNSKIPTABRAW:
    LD A, (DE)
    INC DE
    DEC C

TEXTATXCCRAW:
    CALL TEXTATDECODE

    LD HL, (COPYOFTEXTADDRESS)
    LD (HL), A
    
    LD HL, (COPYOFTEXTADDRESS)
    INC HL
    LD (COPYOFTEXTADDRESS), HL
    LD A, (XCURSYS)
    INC A
    LD (XCURSYS), A
    LD A, C
    JP Z, TEXTATEND2RAW

TEXTATCHECKCONSOLERAW:
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JR NZ, TEXTATNEXTRAW
    JR NC, TEXTATNEXT2RAW
    JMP TEXTATNEXTRAW
TEXTATNEXT2RAW:
    PUSH DE
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    LD HL, (COPYOFTEXTADDRESS)
    AND A
    ADC HL, DE
    LD A, (XCURSYS)    
    LD E, A
    LD D, 0
    AND A
    SBC HL, DE
    LD (COPYOFTEXTADDRESS), HL
    POP DE
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    PUSH AF
    LD A, (CONSOLEY2)
    LD B, A
    POP AF
    CP B

    JR Z, TEXTATNEXTRAW
    JR NC, TEXTATNEXT3RAW
    JMP TEXTATNEXTRAW
TEXTATNEXT3RAW:

    PUSH AF
    PUSH BC
    PUSH DE
    PUSH HL
    ; CALL VSCROLLTUP
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

TEXTATNEXTRAW:
    LD A, (TABSTODRAW)
    CP 0
    JR Z, TEXTATXLOOP2RAW
    JMP TEXTATLOOP2RAW
TEXTATXLOOP2RAW:
    LD A, C
    CP 0
    JR Z, TEXTATTILEMODERAWDONE
    JMP TEXTATLOOP2RAW
TEXTATENDRAW:
TEXTATEND2RAW:
    JP TEXTATTILEMODERAWDONE

TEXTATTILEMODERAWDONE:
    RET
