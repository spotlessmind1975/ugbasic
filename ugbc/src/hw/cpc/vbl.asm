; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                          WAIT VERTICAL BLANK ON CPC                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

WAITVBL:
    PUSH DE
    DI
    LD B, $F5
    LD HL, 19968-23
    LD DE, -11
WAITVBL1:
    IN A, (C)
    RRA
    JR NC, WAITVBL1

WAITVBL2:
    IN A, (C)
    RRA
    JR C, WAITVBL2

WAITVBL3:
    IN A, (C)
    RRA
    JR NC, WAITVBL3

WAITVBL4:
    ADD HL, DE
    IN A, (C)
    RRA
    JR C, WAITVBL4
    EX DE, HL    
    CALL WAITUSEC

WAITVBL5:
    LD B, $F5
    IN A, (C)
    RRA
    JR C, WAITVBL6
    ; LD DE, 19969-20
    ; CALL WAITUSEC

     JR WAITVBL5
WAITVBL6:
    POP DE
    EI
    JP WAITUSEC

WAITUSEC:
    LD HL, WAITUSEC2
    LD B, 0
    LD A, E
    AND %111
    LD C, A
    SBC HL, BC
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    DEC DE
    DEC DE
    DEC DE
    DEC DE
    DEC DE
    NOP
WAITUSEC_01:
    DEC DE
    LD A, D
    OR E
    NOP
    JP NZ, WAITUSEC_01
    JP (HL)
    NOP
    NOP
    NOP 
    NOP
    NOP
    NOP
    NOP
WAITUSEC2:
    RET

; WAITVBL:
;     LD B, $f5
; WAITVBLL1:    
;     IN A, (C)
;     RRA
;     JP C, WAITVBLL1
; WAITVBLL2:    
;     IN A, (C)
;     RRA
;     JP NC, WAITVBLL2
;     RET
    