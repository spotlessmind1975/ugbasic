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
;*                            lESS THAN (32 BIT) Z80                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Is AX:BX < CX:DX ? (signed)
;   AL : 0xff if true, 0x00 if false
CPULT32S:
    CMP AX, CX
    JL CPULT32SLOW
    MOV AL, 0
    RET
CPULT32SLOW:
    CMP BX, DX
    JL CPULT32SLOW2
    MOV AL, 0
    RET
CPULT32SLOW2:
    MOV AL, 0xff
    RET

CPULT32U:
    CMP AX, CX
    JB CPULT32ULOW
    MOV AL, 0
    RET
CPULT32ULOW:
    CMP BX, DX
    JB CPULT32ULOW2
    MOV AL, 0
    RET
CPULT32ULOW2:
    MOV AL, 0xff
    RET

CPULTE32S:
    CMP AX, CX
    JL CPULTE32SLOW
    MOV AL, 0
    RET
CPULTE32SLOW:
    CMP BX, DX
    JL CPULTE32SLOW2
    MOV AL, 0
    RET
CPULTE32SLOW2:
    MOV AL, 0xff
    RET

CPULT32U:
    CMP AX, CX
    JBE CPULTE32ULOW
    MOV AL, 0
    RET
CPULTE32ULOW:
    CMP BX, DX
    JBE CPULTE32ULOW2
    MOV AL, 0
    RET
CPULT16ULOW2:
    MOV AL, 0xff
    RET
