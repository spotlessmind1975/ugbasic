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
;*                           DIV2 CONST 16 BIT ON Z80                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL / 2^C -> HL (signed)
CPUDIV2CONST16S:
    ; INC C
    ; DEC C
    ; RET Z

    LD A, H
    AND $80
    PUSH AF
    JR Z, CPUDIV2CONST16SPOS

    LD A, H
    XOR $FF
    LD H, A

    LD A, L
    XOR $FF
    LD L, A

    INC HL

CPUDIV2CONST16SPOS:
    SRA H
    RR L
    DEC C
    JR NZ, CPUDIV2CONST16SPOS

    POP AF
    AND $80
    RET Z

    LD A, H
    XOR $FF
    LD H, A

    LD A, L
    XOR $FF
    LD L, A

    INC HL
    RET

CPUDIV2CONST16U:
    ; INC C
    ; DEC C
    ; RET Z

CPUDIV2CONST16UL1:
    SRA H
    RR L
    DEC C
    JR NZ, CPUDIV2CONST16UL1
    RET