; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      RAW TEXT AT GIVEN POSITION ON 6847                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TEXTATTILEMODERAW
    RET

;     LDA <TEXTSIZE
;     BNE TEXTATRAWGO
;     RTS

; TEXTATRAWGO
;     LDY TEXTADDRESS
;     STY <COPYOFTEXTADDRESS
;     LDA #0
;     STA <TABSTODRAW

;     LDY TEXTPTR
;     LDA CURRENTMODE
;     CMPA #7
;     LBCS TEXTATRAW
;     RTS

; CALCPOSRAW
;     LDX TEXTADDRESS
;     STX <COPYOFTEXTADDRESS
;     LDB <YCURSYS
;     BEQ CALCPOSRAWSKIP
; CALCPOSRAWLOOP1
;     ANDCC #$FE
;     LDX <COPYOFTEXTADDRESS
;     LDA CURRENTTILESWIDTH
;     LEAX A, X
;     STX <COPYOFTEXTADDRESS
;     DECB
;     BNE CALCPOSRAWLOOP1

; CALCPOSRAWSKIP
;     ANDCC #$FE
;     LDA #0
;     LDB <XCURSYS
;     ADDD <COPYOFTEXTADDRESS
;     STD <COPYOFTEXTADDRESS
;     LDX <COPYOFTEXTADDRESS
;     RTS

; TEXTATRAW
;     JSR CALCPOSRAW

;     LDB <TEXTSIZE
; TEXTATRAWLOOP2

;     LDA ,Y
;     STA , X
;     LEAY 1, Y
;     JMP TEXTATRAWINCX

; TEXTATRAWINCX
;     INC <XCURSYS
;     DECB
;     LBEQ TEXTATRAWEND2
; TEXTATRAWNEXTX
;     LDA <XCURSYS
;     CMPA CONSOLEX2
;     BGT TEXTATRAWNEXT2
;     JMP TEXTATRAWNEXT
; TEXTATRAWNEXT2
;     LDA CONSOLEX1
;     STA <XCURSYS
;     LDA CURRENTTILESWIDTH
;     SUBA CONSOLEW
;     LEAX A,X
;     INC <YCURSYS
;     LDA <YCURSYS
;     CMPA CONSOLEY2
;     BGT TEXTATRAWNEXT3
;     JMP TEXTATRAWNEXT
; TEXTATRAWNEXT3

;     LDA #$FE
;     STA <DIRECTION
;     JSR VSCROLLT

;     DEC <YCURSYS
;     ANDCC #$01
;     PSHS D
;     LDB CURRENTTILESWIDTH
;     CLRA
;     NEGA
;     NEGB
;     SBCA #0
;     ; ADDD #1
;     LEAX D, X
;     PULS D

; TEXTATRAWNEXT
; TEXTATRAWXLOOP2
;     LEAX 1, X
;     CMPB #0
;     BEQ TEXTATRAWEND
;     JMP TEXTATRAWLOOP2
; TEXTATRAWEND2
; TEXTATRAWEND
    
;     RTS
