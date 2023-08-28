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
;*                          HSCROLL FOR ZX SPECTRUM                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

HSCROLLLINE:
    LD HL, (BITMAPADDRESS)
    LD DE, 32
    PUSH AF
    LD A, B
    CMP $0
    JR Z, HSCROLLLINEYPOS0
HSCROLLLINEYPOS:
    ADD HL, DE
    DEC B
    JP NZ, HSCROLLLINEYPOS

HSCROLLLINEYPOS0:
    LD DE, HL
    POP AF
    CP $FF
    JP Z, HSCROLLLINELEFT

HSCROLLLINERIGHT:
    LD HL, DE
    LD A, 0
    LD C, A
HSCROLLLINERIGHT3:
    LD A, 32
    LD B, A
    AND $0
HSCROLLLINERIGHT2:
    RR (HL)
    INC HL
    DEC B
    JP NZ, HSCROLLLINERIGHT2
    INC H
    LD A, L
    SUB A, 32
    LD L, A
    INC C
    LD A, C
    CP 8
    JP NZ, HSCROLLLINERIGHT3
    RET

HSCROLLLINELEFT:
    LD HL, DE
    LD A, 0
    LD D, A
    LD A, 31
    LD E, A
    ADD HL, DE
    LD A, 8
    LD C, A
HSCROLLLINELEFT3:    
    LD A, 32
    LD B, A
    AND $0
HSCROLLLINELEFT2:    
    RL (HL)
    DEC HL
    DEC B
    JP NZ, HSCROLLLINELEFT2
    INC H
    LD A, 0
    LD D, A
    LD A, 31
    LD E, A
    ADD HL, DE
    DEC C
    JP NZ, HSCROLLLINELEFT3
    RET
