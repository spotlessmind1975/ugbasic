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
;*                       INTERNAL VARIABLES FOR EF936X HARDWARE                *
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

CLIPX1    fdb 0
CLIPY1    fdb 0
CLIPX2    fdb 319
CLIPY2    fdb 199
LASTCOLOR fcb 0
CURRENTWIDTH      fdb 320
CURRENTHEIGHT      fdb 200
CURRENTTILES        fcb 255
CURRENTTILESWIDTH      fcb 40
CURRENTTILESHEIGHT      fcb 25
CURRENTFRAMESIZE   fdb 40*200
CURRENTSL          fcb 40
TEXTWW      fcb 3
FONTWIDTH       fcb 8
FONTHEIGHT      fcb 8
TILEMAPVISIBLE  fcb 0
DOUBLEBUFFERENABLED  fcb 0
XSCROLL fcb 0
YSCROLL fcb 0
XSCROLLPOS fcb 0
YSCROLLPOS fcb 0

IMAGEX EQU $41 ; $42
IMAGEY EQU $43 ; $44
IMAGEW EQU $45
IMAGEH EQU $46
IMAGEH2 EQU $47
IMAGET EQU $48

; ------------------------------------------------------------------------------
; BITMAP MODE 16 (MODE #3)
; ------------------------------------------------------------------------------

PLOTVBASE
    fdb $0000, $0028, $0050, $0078, $00A0, $00C8, $00F0, $0118, $0140, $0168
    fdb $0190, $01B8, $01E0, $0208, $0230, $0258, $0280, $02A8, $02D0, $02F8
    fdb $0320, $0348, $0370, $0398, $03C0, $03E8, $0410, $0438, $0460, $0488
    fdb $04B0, $04D8, $0500, $0528, $0550, $0578, $05A0, $05C8, $05F0, $0618
    fdb $0640, $0668, $0690, $06B8, $06E0, $0708, $0730, $0758, $0780, $07A8
    fdb $07D0, $07F8, $0820, $0848, $0870, $0898, $08C0, $08E8, $0910, $0938
    fdb $0960, $0988, $09B0, $09D8, $0A00, $0A28, $0A50, $0A78, $0AA0, $0AC8
    fdb $0AF0, $0B18, $0B40, $0B68, $0B90, $0BB8, $0BE0, $0C08, $0C30, $0C58
    fdb $0C80, $0CA8, $0CD0, $0CF8, $0D20, $0D48, $0D70, $0D98, $0DC0, $0DE8
    fdb $0E10, $0E38, $0E60, $0E88, $0EB0, $0ED8, $0F00, $0F28, $0F50, $0F78
    fdb $0FA0, $0FC8, $0FF0, $1018, $1040, $1068, $1090, $10B8, $10E0, $1108
    fdb $1130, $1158, $1180, $11A8, $11D0, $11F8, $1220, $1248, $1270, $1298
    fdb $12C0, $12E8, $1310, $1338, $1360, $1388, $13B0, $13D8, $1400, $1428
    fdb $1450, $1478, $14A0, $14C8, $14F0, $1518, $1540, $1568, $1590, $15B8
    fdb $15E0, $1608, $1630, $1658, $1680, $16A8, $16D0, $16F8, $1720, $1748
    fdb $1770, $1798, $17C0, $17E8, $1810, $1838, $1860, $1888, $18B0, $18D8
    fdb $1900, $1928, $1950, $1978, $19A0, $19C8, $19F0, $1A18, $1A40, $1A68
    fdb $1A90, $1AB8, $1AE0, $1B08, $1B30, $1B58, $1B80, $1BA8, $1BD0, $1BF8
    fdb $1C20, $1C48, $1C70, $1C98, $1CC0, $1CE8, $1D10, $1D38, $1D60, $1D88
    fdb $1DB0, $1DD8, $1E00, $1E28, $1E50, $1E78, $1EA0, $1EC8, $1EF0, $1F18

    