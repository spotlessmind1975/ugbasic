; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from source code by Alwin Henseler on:
;  * https://www.msx.org/forum/development/msx-development/32-bit-long-ascii
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

; =========================================================
; Routine: SQRT_32_to_16
; =========================================================
; Calcola la radice quadrata intera di un numero a 32 bit
;
; Ingresso:
;   - DX:AX  =  Numero a 32 bit di cui calcolare la radice
;
; Uscita:
;   - AX     =  Radice quadrata intera (16 bit)
;
; Modificati:
;   - BX, CX, DX
; =========================================================
SQROOT:
    XOR BX, BX
    XOR CX, CX

    MOV CX, 16

SQROOTL1:
    SHL BX, 1
    MOV DX, BX
    INC DX
    SUB AX, DX
    SBB DX, 0
    JNC SQROOTL2
    
    ADD AX, DX
    ADC DX, 0
    
SQROOTL2:
    LOOP SQROOTL1
    
    MOV AX, BX
    RET