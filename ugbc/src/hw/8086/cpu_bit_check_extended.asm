; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                        SET/UNSET A BIT INSIDE A BYTE                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Check bit A of byte/word/dword at DI
;  - DI = byte/word/dword to operate
;  - AL = position
;  - set to 1 if carry flag is set
CPUBITCHECKEXTENDED:
    MOV BL, AL
    SHR AL, 1
    SHR AL, 1
    SHR AL, 1
    CMP AL, 3
    JZ CPUBITCHECKEXTENDED3
    CMP AL, 2
    JZ CPUBITCHECKEXTENDED2
    CMP AL, 1
    JZ CPUBITCHECKEXTENDED1
    JMP CPUBITCHECKEXTENDEDEND
CPUBITCHECKEXTENDED3:
    INC DI
CPUBITCHECKEXTENDED2:
    INC DI
CPUBITCHECKEXTENDED1:
    INC DI
CPUBITCHECKEXTENDEDEND:
    MOV AL, BL
    AND AL, 0x07
    MOV BL, 1
    CMP AL, 0
    JZ CPUBITCHECKEXTENDEDDONE2
CPUBITCHECKEXTENDEDLOOP2:
    SAL BL, 1
    DEC AL
    CMP AL, 0
    JNZ CPUBITCHECKEXTENDEDLOOP2
CPUBITCHECKEXTENDEDDONE2:
    MOV AL, [DI]
    AND AL, BL
    CMP AL, 0
    JZ CPUBITCHECKEXTENDEDZERO
    MOV AL, 0
    CMP AL, 0xff
    MOV AL, 0xFF
    RET
CPUBITCHECKEXTENDEDZERO:
    MOV AL, 0
    CMP AL, 0
    RET
