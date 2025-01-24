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
;*                            lESS THAN (8 BIT) SM83                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Is D < H ? (unsigned)
;   A : $ff if true, $00 if false
CPULT8S:
    LD A, H
    XOR 80h
    LD B, A
    LD A, D
    XOR 80h
    CP B
    JR C, CPULT8UT
    JR CPULT8UF

CPULT8U:
    CP B
    JR C, CPULT8UT
CPULT8UF:
    LD A, $00
    RET
CPULT8UT:
    LD A, $ff
    RET

; Is D <= H ? (unsigned)
;   A : $ff if true, $00 if false
CPULTE8S:
    LD A, H
    CP D
    JR Z, CPULTE8UT
    XOR 80h
    LD B, A
    LD A, D
    XOR 80h
    CP B
    JR C, CPULTE8UT
    JR CPULTE8UF

CPULTE8U:
    CP B
    JR C, CPULTE8UT
    JR Z, CPULTE8UT
CPULTE8UF:
    LD A, $00
    RET
CPULTE8UT:
    LD A, $ff
    RET
