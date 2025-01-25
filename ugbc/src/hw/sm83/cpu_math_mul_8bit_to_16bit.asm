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
;*                            8BITx8BIT = 16BIT UNDER SM83                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; (IXLR) * (IYLR) -> HL (signed)
CPUMUL8B8T16S:
    XOR A, B
    AND $80
    LD B, A
    PUSH B

    LD A, (IXLR)
    AND $80
    CP 0
    JR Z, CPUMUL8B8T16SPOS
    LD A, (IXLR)
    XOR $FF
    INC A
    JMP CPUMUL8B8T16S1

CPUMUL8B8T16SPOS:
    LD A, (IXLR)

CPUMUL8B8T16S1:
    LD H, A

    LD A, (IYLR)
    AND $80
    CP 0
    JR Z, CPUMUL8B8T16SPOS2
    LD A, (IYLR)
    XOR $FF
    INC A
    JP CPUMUL8B8T16SDONE2

CPUMUL8B8T16SPOS2:
    LD A, (IYLR)

CPUMUL8B8T16SDONE2:
    LD C, A

    LD E, A
    LD D, 0
    LD L, D
    LD B, 8

CPUMUL8B8T16SL:
    ADD HL, HL
    JR NC, CPUMUL8B8T16SB2
    ADD HL, DE
CPUMUL8B8T16SB2:
    DJNZ CPUMUL8B8T16SL

    POP B
    LD A, B
    AND $80
    CP 0
    JR Z, CPUMUL8B8T16SNC

    LD A, L
    XOR $FF
    LD L, A
    
    LD A, H
    XOR $FF
    LD H, A
    INC HL

CPUMUL8B8T16SNC:            
    RET

CPUMUL8B8T16U:
    LD A, (IXLR)
    LD H, A
    LD A, (IYLR)
    LD E, A

    LD D, 0
    LD L, D
    LD B, 8

CPUMUL8B8T16UL:
    ADD HL, HL
    JR NC, CPUMUL8B8T16UB2
    ADD HL, DE
CPUMUL8B8T16UB2:
    DJNZ CPUMUL8B8T16UL
    RET
