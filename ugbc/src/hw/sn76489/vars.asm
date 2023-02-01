; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      INTERNAL VARIABLES FOR SN-76489 HARDWARE               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SN76489FREQTABLE:    
    DW 255,		255,		255,		255,		255,		255,		255,		255,		255,		255
    DW 255,		255,		255,		255,		255,		255,		255,		255,		255,		255
    DW 255,		255,		255,        255,        255,        255,        255,        255,        255,        255
    DW 255,        240,        227,        214,        202,        191,        180,        170,        160,        151
    DW 143,        135,        127,        120,        113,        107,        101,        95,         90,         85
    DW 80,         75,         71,         67,         63,         60,         56,         53,         50,         47
    DW 45,         42,         40,         37,         35,         33,         31,         30,         28,         26
    DW 25,         23,         22,         21,         20,         18,         17,         16,         15,         15
    DW 14,         13,         12,         11,         11,         10,         10,         9,          8,          8
    DW 7,          7,          7,          6,          6,          5,          5,          5,          5,          4
    DW 4,          4,          3,          3,          3,          3,          3,          2,          2,          2
    DW 2,          2,          2,          2,          1,          1,          1,          1,          1           
    
; SN76489MUSICREADY: .byte $0
; SN76489BLOCKS: .word $0
; SN76489LASTBLOCK: .byte $0

; SN76489TMPPTR2 = $03 ; $04
; SN76489TMPPTR = $05 ; $06
; SN76489TMPOFS = $07
; SN76489TMPLEN = $08
; SN76489JIFFIES = $09 ; $0A