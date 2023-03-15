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
;*                      INTERNAL VARIABLES FOR GTIA HARDWARE                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

XGR:    .word 0
YGR:    .word 0
LINE:   .byte $ff, $ff

CLIPX1:    .word 0
CLIPY1:    .word 0
CLIPX2:    .word 319
CLIPY2:    .word 199
ORIGINX:   .word 0
ORIGINY:   .word 0
RESOLUTIONX: .word 0
RESOLUTIONY: .word 0

CURRENTWIDTH:      .word 40
CURRENTHEIGHT:      .word 24
CURRENTTILESWIDTH:      .byte 40
CURRENTTILESHEIGHT:      .byte 24
CURRENTTILES:      .byte 255
TEXTBLOCKREMAIN:      .byte 152
TEXTBLOCKREMAINPW:      .byte 192
CURRENTSL:          .byte 0
TEXTWW:             .byte 3
FONTWIDTH:          .byte 8
FONTHEIGHT:         .byte 8
IMAGEX = $F0
IMAGEY = $F2
IMAGEW = $F4 ; $F5
IMAGEH = $F6
IMAGEH2 = $F8
IMAGET = $F9
IMAGEF = $FA

XSCROLLPOS:         .byte 0
YSCROLLPOS:         .byte 0
XSCROLL:            .byte 0
YSCROLL:            .byte 0

YSCROLLOFFSET:  .byte 4, 3, 2, 1, 0, 7, 6, 5
XSCROLLOFFSET:  .byte 0, 1, 2, 3, 4, 5, 6, 7

PLOTDEST = $8a ; $8b
PLOTCDEST= $8c ; $8d
PLOTLDEST= $8e ; $8f
