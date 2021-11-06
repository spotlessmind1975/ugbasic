; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                  MOVABLE OBJECTS UNDER VIC-I (specific algorithms)         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

MOBDRAW_TMP: .byte 0
MOBDRAW_PD: .byte 0
MOBDRAW_DY: .byte 0
MOBDRAW_DY2: .byte 0
MOBDRAW_DX: .byte 0
MOBDRAW_I: .byte 0
MOBDRAW_J: .byte 0
MOBDRAW_K: .byte 0
MOBDRAW_C: .byte 0
MOBDRAW_R: .byte 0

; ---------------------------------------------------------------------------
; Chipset specific initialization
; MOBINITCS(X:index,draw)
; ---------------------------------------------------------------------------
MOBINITCS:
;     LDA CURRENTMODE
;     ; BITMAP_MODE_STANDARD
;     CMP #2
;     BNE MOBINITCS2X
;     JMP MOBINITCS2
; MOBINITCS2X:
;     ; BITMAP_MODE_MULTICOLOR
;     CMP #3
;     BNE MOBINITCS3X
;     JMP MOBINITCS3
; MOBINITCS3X:
;     ; TILEMAP_MODE_STANDARD
;     CMP #0
;     BNE MOBINITCS0X
;     JMP MOBINITCS0
; MOBINITCS0X:
;     ; TILEMAP_MODE_MULTICOLOR
;     CMP #1
;     BNE MOBINITCS1X
;     JMP MOBINITCS1
; MOBINITCS1X:
;     ; TILEMAP_MODE_EXTENDED
;     CMP #4
;     BNE MOBINITCS4X
;     JMP MOBINITCS4
; MOBINITCS4X:
    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; MOBSAVE(X:indeX) -> chipset
MOBSAVE:
;     LDA CURRENTMODE
;     ; BITMAP_MODE_STANDARD
;     CMP #2
;     BNE MOBSAVE2X
;     JMP MOBSAVE2
; MOBSAVE2X:
;     ; BITMAP_MODE_MULTICOLOR
;     CMP #3
;     BNE MOBSAVE3X
;     JMP MOBSAVE3
; MOBSAVE3X:
;     ; TILEMAP_MODE_STANDARD
;     CMP #0
;     BNE MOBSAVE0X
;     JMP MOBSAVE0
; MOBSAVE0X:
;     ; TILEMAP_MODE_MULTICOLOR
;     CMP #1
;     BNE MOBSAVE1X
;     JMP MOBSAVE1
; MOBSAVE1X:
;     ; TILEMAP_MODE_EXTENDED
;     CMP #4
;     BNE MOBSAVE4X
;     JMP MOBSAVE4
; MOBSAVE4X:
    RTS
; MOBRESTORE(X:indeX) -> chipset
MOBRESTORE:
;     LDA CURRENTMODE
;     ; BITMAP_MODE_STANDARD
;     CMP #2
;     BNE MOBRESTORE2X
;     JMP MOBRESTORE2
; MOBRESTORE2X:
;     ; BITMAP_MODE_MULTICOLOR
;     CMP #3
;     BNE MOBRESTORE3X
;     JMP MOBRESTORE3
; MOBRESTORE3X:
;     ; TILEMAP_MODE_STANDARD
;     CMP #0
;     BNE MOBRESTORE0X
;     JMP MOBRESTORE0
; MOBRESTORE0X:
;     ; TILEMAP_MODE_MULTICOLOR
;     CMP #1
;     BNE MOBRESTORE1X
;     JMP MOBRESTORE1
; MOBRESTORE1X:
;     ; TILEMAP_MODE_EXTENDED
;     CMP #4
;     BNE MOBRESTORE4X
;     JMP MOBRESTORE4
; MOBRESTORE4X:
    RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Chipset specific drawing routine
; MOBDRAW(X:indeX) -> chipset
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MOBDRAW:
    RTS

MOBATCS:
    RTS