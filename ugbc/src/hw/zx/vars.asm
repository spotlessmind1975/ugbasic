; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                 INTERNAL VARIABLES FOR ZX SPECTRUM TARGET                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; BITMAPADDRESS: DEFW $4000
; COLORMAPADDRESS: DEFW $5800
; TABCOUNT:   DEFB    4
; XCURS:      DEFB    0
; YCURS:      DEFB    0
; EMPTYTILE:  DEFB   32
; EVERYSTATUS:DEFB   0
; XCURSYS:      DEFB    0
; YCURSYS:      DEFB    0

; XGR:    DEFW 0
; YGR:    DEFW 0
; LINE:   DEFB $ff, $ff

; CLIPX1:    DEFW 0
; CLIPY1:    DEFW 0
; CLIPX2:    DEFW 255
; CLIPY2:    DEFW 191
; CURRENTWIDTH:   DEFW    256
; CURRENTHEIGHT:   DEFW    192
; CURRENTTILESWIDTH:   DEFB   32 
; CURRENTTILESHEIGHT:   DEFB    24
; CURRENTTILES:   DEFB    255
; CURRENTMODE:        DEFB 0
; TEXTWW:             DEFB 3
; FONTWIDTH:          DEFB 8
; FONTHEIGHT:         DEFB 8
; CPURANDOM_SEED:     DEFB $FF, $FF, $FF, $FF