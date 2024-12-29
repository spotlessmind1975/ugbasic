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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; 8x8 bit multiplication to 16 bit (signed)
; Input:
;   I -> first operand
;   A -> second operand
; Output:
;   B:A -> result
CPUMUL8B8T16S:
    PUSH 
    ANIA 0x80
    LP 0x0a
    EXAM
    LP 0x00
    EXAM
    ANIA 0x80
    LIDP CPUMUL8B8T16SV+1
    STD
    LP 0x0a
    EXAM
CPUMUL8B8T16SV:    
    ANIA 0xff
    LIDP CPUMUL8B8T16SV2+1
    STD
    POP
    CALL CPUMUL8B8T16U
    LP 0x03
CPUMUL8B8T16SV2:
    ORIM 0xff
    RTN    

; 8x8 bit multiplication to 16 bit (unsigned)
; Input:
;   I -> first operand
;   A -> second operand
; Output:
;   B:A -> result
CPUMUL8B8T16U:
    LP 1
    ANIM 0
    LP 3
    ANIM 0

; 16x16 bit multiplication to 16 bit (unsigned)
; Input:
;   J:I -> first operand
;   B:A -> second operand
; Output:
;   B:A -> result
CPUMUL16B16T16U:

CPUMUL8B8T16UL1:
    LP	1
    EXAM
    RC
    SR
    EXAM
    DECP
    EXAM
    SR
    EXAM
    JRNCP
    LP	6
    ADB
    RC
    SL
    EXAB
    SL
    EXAB
    LP	0
    CPIM	0
    JRNZP	CPUMUL8B8T16UL1
    LP	1
    CPIM	0
    JRNZP	CPUMUL8B8T16UL1

    LP	7
    EXAM
    EXAB
    LP	6
    EXAM
    RTN
