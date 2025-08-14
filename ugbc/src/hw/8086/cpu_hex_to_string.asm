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
;*                      CONVERT A NUMBER TO A HEXADECIMAL NUMBER               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Routine per convertire un numero a 32 bit in esadecimale
; Input:  DX:BX = numero a 32 bit
;         DI    = indirizzo del buffer per la stringa esadecimale (8 byte)
; Output: Buffer in DI contiene la stringa esadecimale
; Registri modificati: AX, BX, CX, DX, DI

HEXTOSTRING32:

    MOV AL, DH
    SHR AL, 4
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

    MOV AL, DH
    AND AL, 0x0f
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

    MOV AL, DL
    SHR AL, 4
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

    MOV AL, DL
    AND AL, 0x0f
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

HEXTOSTRING16:

    MOV AL, BH
    SHR AL, 4
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

    MOV AL, BH
    AND AL, 0x0f
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

HEXTOSTRING8:

    MOV AL, BL
    SHR AL, 4
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI

    MOV AL, BL
    AND AL, 0x0f
    CALL HEXTOSTRINGNB
    MOV [DI], AL
    INC DI
    
    RET             ; Ritorna dalla routine

HEXTOSTRINGNB:
    CMP AL, 9       ; Confronta se il nibble è un numero (0-9)
    JBE HEXTOSTRINGNBN      ; Se <= 9, salta a IS_NUM
    ADD AL, 7       ; Se è una lettera (A-F), aggiunge 7
HEXTOSTRINGNBN:
    ADD AL, '0'     ; Aggiunge il valore ASCII di '0'
    RET             ; Ritorna dalla sottoroutine