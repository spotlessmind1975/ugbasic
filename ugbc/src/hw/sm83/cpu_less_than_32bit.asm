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
;*                            lESS THAN (32 BIT) SM83                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Is [HL] < [DE] ? (signed)
;   A : $ff if true, $00 if false
CPULT32S:
    ADD HL, 3
    ADD DE, 3
    LD B, (HL)
    LD A, B
    AND $80
    CP 0
    JR NZ, CPULT32SNEGM1
    BIT 7, (DE)
    JR NZ, CPULT32SDONE
    LD A, B
    CP (DE)
    JR NZ, CPULT32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULT32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULT32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JP CPULT32SDONE
CPULT32SNEGM1:
    XOR (DE)
    RLA
    JR C, CPULT32SDONE
    LD A, B
    CP (DE)
    JR NZ, CPULT32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULT32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULT32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JMP CPULT32SDONE
CPULT32SDONE:
    JR C, CPULT32SMI
CPULT32SPL:
    LD A, $00
    RET
CPULT32SMI:            
    LD A, $ff
    RET

CPULT32U:
    ADD HL, 3
    ADD DE, 3
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULT32U2
    JR C, CPULT32UL
    JR CPULT32UOK
CPULT32U2:   
    DEC HL
    DEC DE         
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULT32U1
    JR C, CPULT32UL
    JR CPULT32UOK
CPULT32U1:   
    DEC HL
    DEC DE         
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULT32U0
    JR C, CPULT32UL
    JR CPULT32UOK
CPULT32U0:
    DEC HL
    DEC DE
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULT32UL
    JR C, CPULT32UL
CPULT32UOK:            
    LD A, $ff
    RET
CPULT32UL:
    LD A, $00
    RET

CPULTE32S:
    ADD HL, 3
    ADD DE, 3
    LD B, (HL)
    LD A, B
    AND $80
    CP 0
    JR NZ, CPULTE32SNEGM1
    BIT 7, (DE)
    JR NZ, CPULTE32SDONE
    LD A, B
    CP (DE)
    JR NZ, CPULTE32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULTE32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULTE32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JP CPULTE32SDONE
CPULTE32SNEGM1:            
    XOR (DE)
    RLA
    JR C, CPULTE32SDONE
    LD A, B
    CP (DE)
    JR NZ, CPULTE32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULTE32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JR NZ, CPULTE32SDONE
    DEC HL
    DEC DE
    LD A, (HL)
    CP (DE)
    JP CPULTE32SDONE
CPULTE32SDONE:
    JR Z, CPULTE32SMI
    JR C, CPULTE32SMI
CPULTE32SPL:
    LD A, $00
    RET
CPULTE32SMI:            
    LD A, $ff
    RET

CPULTE32U:
    ADD HL, 3
    ADD DE, 3
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULTE32U2
    JR C, CPULTE32UL
    JR CPULTE32UOK
CPULTE32U2:
    DEC HL
    DEC DE
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULTE32U1
    JR C, CPULTE32UL
    JR CPULTE32UOK
CPULTE32U1:
    DEC HL
    DEC DE
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULTE32U0
    JR C, CPULTE32UL
    JR CPULTE32UOK
CPULTE32U0:
    DEC HL
    DEC DE
    LD A, (HL)
    LD B, A
    LD A, (DE)
    CP B
    JR Z, CPULTE32UOK
    JR C, CPULTE32UL
CPULTE32UOK:            
    LD A, $ff
    RET
CPULTE32UL:
    LD A, $00
    RET
