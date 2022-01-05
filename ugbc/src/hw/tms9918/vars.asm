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
;*                          INTERNAL VARIABLES FOR TMS9918                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SECTION data_user
; ORG $c000

; TEXTADDRESS: DEFW FRAMEBUFFER
; BITMAPADDRESS: DEFW FRAMEBUFFER
; COLORMAPADDRESS: DEFW COLORBUFFER
; COPYOFTEXTADDRESS: DEFW $0000
; COPYOFBITMAPADDRESS: DEFW $0000
; COPYOFCOLORMAPADDRESS: DEFW $0000
; TABCOUNT:   DEFB    4
; XCURS:      DEFB    0
; YCURS:      DEFB    0
; EMPTYTILE:  DEFB   0
; EVERYSTATUS:DEFB   0
; XCURSYS:      DEFB    0
; YCURSYS:      DEFB    0
; CLINEX:      DEFB    0
; CLINEY:      DEFB    0

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

; TABSTODRAW: DEFB 0

; SECTION code_user

; TMS9918VARINIT:

;     LD HL, FRAMEBUFFER
;     LD (TEXTADDRESS), HL
;     LD HL, FRAMEBUFFER
;     LD (BITMAPADDRESS), HL
;     LD HL, COLORBUFFER
;     LD (COLORMAPADDRESS), HL

;     LD HL, 0
;     LD (COPYOFTEXTADDRESS), HL
;     LD (COPYOFBITMAPADDRESS), HL
;     LD (COPYOFCOLORMAPADDRESS), HL
;     LD (XGR), HL
;     LD (YGR), HL
    
;     LD A, 4
;     LD (TABCOUNT), A

;     LD A, 0
;     LD (XCURS), A
;     LD (YCURS), A
;     LD (EVERYSTATUS), A
;     LD (XCURSYS), A
;     LD (YCURSYS), A
;     LD (CLINEX), A
;     LD (CLINEY), A
;     LD (YGR), A

;     LD (CLIPX1), HL
;     LD (CLIPY1), HL
;     LD HL, 255
;     LD (CLIPX2), HL
;     LD HL, 191
;     LD (CLIPY2), HL

;     LD HL, 256
;     LD (CURRENTWIDTH), HL
;     LD HL, 192
;     LD (CURRENTHEIGHT), HL

;     LD A, 32
;     LD (EMPTYTILE), A

;     LD HL, $ffff
;     LD (LINE), HL

;     LD A, 32
;     LD (CURRENTTILESWIDTH), A
;     LD A, 24
;     LD (CURRENTTILESHEIGHT), A

;     LD A, 255
;     LD (CURRENTTILES), A

;     LD A, 0
;     LD (CURRENTMODE), A

;     LD A, 3
;     LD (TEXTWW), A

;     LD A, 8
;     LD (FONTWIDTH), A

;     LD A, 8
;     LD (FONTHEIGHT), A

;     LD A, $ff
;     LD HL, CPURANDOM_SEED
;     LD (HL),A
;     INC HL
;     LD (HL),A
;     INC HL
;     LD (HL),A
;     INC HL
;     LD (HL),A
;     INC HL

;     LD A, 098H
;     LD (VDPDATAPORTREAD), A
;     LD (VDPDATAPORTWRITE), A
;     LD A, 099H
;     LD (VDPCONTROLPORTREAD), A
;     LD (VDPCONTROLPORTWRITE), A

;     LD A, (EMPTYTILE)
;     LD HL, FRAMEBUFFER
;     LD (HL), A
;     LD DE, FRAMEBUFFER
;     INC DE
;     LD BC, 40*24
;     LDIR

;     LD A, 0
;     LD HL, COLORBUFFER
;     LD (HL), A
;     LD DE, COLORBUFFER
;     INC DE
;     LD BC, 32*24
;     LDIR

;     LD A, 0
;     LD HL, TILEBUFFER
;     LD (HL), A
;     LD DE, TILEBUFFER
;     INC DE
;     LD BC, 32*24
;     LDIR

;     RET
