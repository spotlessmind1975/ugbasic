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
;
; Routine per convertire un numero a 32 bit (DX:AX) in una stringa esadecimale
; Input:
;   DX:AX = il numero a 32 bit da convertire
;   DI = l'indirizzo di memoria dove salvare la stringa
; Output:
;   Stringa esadecimale di 8 caratteri (es. FFFFABCD) salvata a partire da DI
; Registri usati: AX, DX, CX, DI

HEXTOSTRING:
    PUSH CX
    MOV CX, 0

HEXTOSTRINGL0:
    ROL DX, 4
    MOV AL, DH
    AND AL, 0x0f
    CMP AL, 9
    JA HEXTOSTRINGAA
    ADD AL, '0'
    JP HEXTOSTRINGSA

HEXTOSTRINGAA:
    ADD AL, 'A' - 0x0a

HEXTOSTRINGSA:
    MOV [DI], AL
    INC DI
    LOOP HEXTOSTRINGL0

    POP CX
    RET
