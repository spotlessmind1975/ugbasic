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
;*                            lESS THAN (16 BIT) Z80                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Is BX < AX ? (signed)
;   AL : 0xff if true, 0x00 if false
CPULT16S:
    CMP BX, AX
    JL CPULT16SLOW
    MOV AL, 0
    RET
CPULT16SLOW:
    MOV AL, 0xff
    RET

CPULT16U:
    CMP BX, AX
    JB CPULT16ULOW
    MOV AL, 0
    RET
CPULT16ULOW:
    MOV AL, 0xff
    RET

CPULTE16S:
    CMP BX, AX
    JLE CPULTE16SLOW
    MOV AL, 0
    RET
CPULTE16SLOW:
    MOV AL, 0xff
    RET

CPULTE16U:
    CMP BX, AX
    JBE CPULTE16ULOW
    MOV AL, 0
    RET
CPULTE16ULOW:
    MOV AL, 0xff
    RET
