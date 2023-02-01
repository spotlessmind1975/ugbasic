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
;*                      INTERNAL VARIABLES FOR AY-3-8910 HARDWARE                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

AY8910FREQTABLE:    
    DW  6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841
    DW  6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841,		6841
    DW  6841,		6841,		6841,       6841,       6457,       6095,       5753,       5430,       5125,       4837
    DW  4566,       4310,       4068,       3839,       3624,       3420,       3229,       3047,       2876,       2715
    DW  2562,       2419,       2283,       2155,       2034,       1920,       1812,       1710,       1614,       1524
    DW  1438,       1357,       1281,       1209,       1141,       1077,       1017,       960,        906,        855
    DW  807,        762,        719,        679,        641,        605,        571,        539,        508,        480
    DW  453,        428,        404,        381,        360,        339,        320,        302,        285,        269
    DW  254,        240,        226,        214,        202,        190,        180,        170,        160,        151
    DW  143,        135,        127,        120,        113,        107,        101,        95,         90,         85
    DW  80,         76,         71,         67,         64,         60,         57,         53,         50,         48
    DW  45,         42,         40,         38,         36,         34,         32,         30,         28
    
; AY8910MUSICREADY: .byte $0
; AY8910BLOCKS: .word $0
; AY8910LASTBLOCK: .byte $0

; AY8910TMPPTR2 = $03 ; $04
; AY8910TMPPTR = $05 ; $06
; AY8910TMPOFS = $07
; AY8910TMPLEN = $08
; AY8910JIFFIES = $09 ; $0A