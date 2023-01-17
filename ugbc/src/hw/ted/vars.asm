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
;*                      INTERNAL VARIABLES FOR TED HARDWARE                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CURRENTWIDTH:      .word 40
CURRENTHEIGHT:      .word 25
CURRENTTILESWIDTH:      .byte 40
CURRENTTILESHEIGHT:      .byte 25
CURRENTTILES:      .byte 255
TEXTWW:             .byte 3
FONTWIDTH:          .byte 8
FONTHEIGHT:         .byte 8
CLIPX1:    .word 0
CLIPY1:    .word 0
CLIPX2:    .word 319
CLIPY2:    .word 199
ORIGINX:   .word 0
ORIGINY:   .word 0
XSCROLLPOS:         .byte 0
YSCROLLPOS:         .byte 4
XSCROLL:            .byte 0
YSCROLL:            .byte 0

.feature force_range

TEDFREQTABLE:    
    .word 0,		0,		0,		0,		0,		0,		0,		0,		0,		0
    .word 0,		0,		0,		0,		0,		0,		0,		0,		0,		0
    .word 0,		0,		0,		-5816,  -5432,  -5070,  -4728,  -4405,  -4100,  -3812
    .word -3541,  -3285,  -3043,  -2815,  -2599,  -2396,  -2204,  -2023,  -1852,  -1690
    .word -1538,  -1394,  -1258,  -1130,  -1009,  -895,   -788,   -686,   -590,   -499
    .word -414,   -333,   -257,   -185,   -117,   -53,    7,      64,     118,    169
    .word 217,    262,    305,    345,    383,    419,    453,    485,    516,    544
    .word 571,    597,    621,    643,    665,    685,    704,    722,    739,    755
    .word 770,    784,    798,    810,    822,    834,    844,    854,    864,    873
    .word 881,    889,    897,    904,    911,    917,    923,    929,    934,    939
    .word 944,    948,    953,    957,    960,    964,    967,    971,    974,    976
    .word 979,    982,    984,    986,    988,    990,    992,    994,    996

TEDMUSICREADY: .byte $0
TEDBLOCKS: .word $0
TEDLASTBLOCK: .byte $0

TEDTMPPTR2 = $03 ; $04
TEDTMPPTR = $05 ; $06
TEDTMPOFS = $07
TEDTMPLEN = $08
TEDJIFFIES = $09 ; $0A