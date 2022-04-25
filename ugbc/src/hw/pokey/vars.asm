; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR POKEY HARDWARE                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

POKEYFREQTABLE:    
    .word 255,		255,		255,		255,		255,		255,		255,		255,		255,		255
    .word 255,		255,		255,		255,		255,		255,		255,		255,		255,		255
    .word 255,		255,		255,		255,        255,        255,        255,        255,        255,        255
    .word 255,        255,        255,        255,        255,        255,        255,        255,        255,        255
    .word 255,        255,        255,        255,        255,        255,        255,        255,        255,        255
    .word 255,        255,        255,        255,        255,        255,        255,        255,        255,        243
    .word 230,        217,        204,        193,        182,        172,        162,        153,        144,        136
    .word 128,        121,        114,        108,        102,        96,         91,         85,         81,         76
    .word 72,         68,         64,         60,         57,         53,         50,         47,         45,         42
    .word 40,         37,         35,         33,         31,         30,         28,         26,         25,         23
    .word 22,         21,         19,         18,         17,         16,         15,         14,         13,         12
    .word 11,         10,         9,          8,          7,          6,          5,          4,          3,          2
    .word 1
    
POKEYMUSICREADY: .byte $0
POKEYBLOCKS: .word $0
POKEYLASTBLOCK: .byte $0

POKEYTMPPTR2 = $03 ; $04
POKEYTMPPTR = $05 ; $06
POKEYTMPOFS = $07
POKEYTMPLEN = $08
POKEYJIFFIES = $09 ; $0A