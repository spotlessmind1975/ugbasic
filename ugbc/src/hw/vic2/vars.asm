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
;*                      INTERNAL VARIABLES FOR VIC-II HARDWARE                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTDEST = $1A ; $1B
PLOTCDEST= $18 ; $19
PLOTC2DEST= $16 ; $17

TILEMAPVISIBLE:     .byte 0

XGR:    .word 0
YGR:    .word 0
LINE:   .byte $ff, $ff

SPRITECOUNT:    .byte 0

CLIPX1:    .word 0
CLIPY1:    .word 0
ORIGINX:   .word 0
ORIGINY:   .word 0
CLIPX2:    .word 319
CLIPY2:    .word 199
LASTCOLOR: .byte 0
CURRENTWIDTH:      .word 40
CURRENTHEIGHT:      .word 25
RESOLUTIONX:       .word 0
RESOLUTIONY:      .word 0
CURRENTTILESWIDTH:      .byte 40
CURRENTTILESHEIGHT:      .byte 25
CURRENTSL:          .byte 0
TEXTWW:             .byte 3
FONTWIDTH:          .byte 8
FONTHEIGHT:         .byte 8
CURRENTTILES:      .byte 255
XSCROLLPOS:         .byte 0
YSCROLLPOS:         .byte 4
XSCROLL:            .byte 0
YSCROLL:            .byte 0

IMAGEX = $54; $55
IMAGEY = $56; $57
IMAGEW = $59 ; $5A
IMAGEH = $53
IMAGEH2 = $52
IMAGET = $51
IMAGEF = $58

BLITTMPPTR = $B8 ; $B9
BLITTMPPTR2 = $B6 ; $B7
BLITS0 = $A8 ; $A9
BLITS1 = $AA ; $AB
BLITS2 = $AC ; $AD
BLITR0 = $AE ; $AF
BLITR1 = $B0 ; $B1
BLITR2 = $B2 ; $B3
BLITR3 = $B4 ; $B5
