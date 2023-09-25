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
;*                       INTERNAL VARIABLES FOR GIME HARDWARE                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTDEST equ $0b ; $29
PLOTCDEST equ $0d ; $27
PLOTC2DEST equ $0f ; $25

XGR    fdb 0
YGR    fdb 0
LINE   fcb $ff, $ff

ORIGINX    fdb 0
ORIGINY    fdb 0
RESOLUTIONX    fdb 0
RESOLUTIONY    fdb 0

CLIPX1    fdb 0
CLIPY1    fdb 0
CLIPX2    fdb 319
CLIPY2    fdb 199

LASTCOLOR fcb 0
CURRENTWIDTH      fdb 32
CURRENTHEIGHT      fdb 16
CURRENTTILESWIDTH      fcb 32
CURRENTTILESHEIGHT      fcb 16
CURRENTTILES            fcb 128
CURRENTFRAMESIZE   fdb 32*16
CURRENTSL          fcb 32
TEXTWW      fcb 3
FONTWIDTH       fcb 8
FONTHEIGHT      fcb 8

IMAGEX EQU $41 ; $42
IMAGEY EQU $43 ; $44
IMAGEW EQU $45
IMAGEH EQU $46
IMAGEH2 EQU $47
IMAGET EQU $48
IMAGEF EQU $49

BLITTMPPTR EQU $50 ; $51
BLITTMPPTR2 EQU $52 ; $53
BLITS0 EQU $54
BLITS1 EQU $55
BLITS2 EQU $56
BLITR0 EQU $57
BLITR1 EQU $58
BLITR2 EQU $59
BLITR3 EQU $60

; PALETTEPAPER               fcb $12, $24, $0b, $07, $3f, $1f, $09, $26
; PALETTEPEN                 fcb $00, $12, $00, $3f, $00, $12, $00, $26
PALETTEPAPER               fcb $00, $00, $00, $00, $00, $00, $00, $00
PALETTEPEN                 fcb $00, $00, $00, $00, $00, $00, $00, $00

PALETTEPENUNUSED           fcb 0
PALETTEPAPERUNUSED         fcb 0
PALETTELIMIT               fcb 0
GIMEVIDMSHADOW             fcb 0
GIMEMMUSTART               fcb 3
