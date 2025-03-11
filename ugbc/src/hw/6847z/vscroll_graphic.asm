; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                          VERTICAL SCROLL ON 6847                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



VSCROLLG
    RET

;     LDA CURRENTMODE
;     CMPA #6
;     BLE VSCROLLGX
;     JMP VSCROLLGT
; VSCROLLGX
;     RTS

; VSCROLLGT
;     PSHS A,B,X,Y,U
;     LDA <DIRECTION
;     CMPA #0
;     BGT VSCROLLGDOWN

; VSCROLLGUP
;     LDX CONSOLESA
;     TFR X, Y

;     LDB CONSOLEH
;     DECB
;     BEQ VSCROLLGUPYSCRNO

;     PSHS D
;     LDB CURRENTSL
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     PULS D

;     CLRA
;     LDB CONSOLEHB
;     SUBB #8
;     TFR D, U
; VSCROLLGUPYSCR
;     LDB #0
; VSCROLLGUPYSCR1
;     LDA B,X
;     STA B,Y
;     INCB
;     CMPB CONSOLEWB
;     BNE VSCROLLGUPYSCR1
;     LDB CURRENTSL
;     CLRA
;     LEAX D, X
;     LEAY D, Y
;     LEAU -1, U
;     CMPU #0
;     BNE VSCROLLGUPYSCR
;     JMP VSCROLLGUPYSCRNO2

; VSCROLLGUPYSCRNO
;     TFR X, Y
; VSCROLLGUPYSCRNO2
;     LDU #8
;     LDA #0
;     LDB #0
; VSCROLLGUPREFILL
;     STA B,Y
;     INCB
;     CMPB CONSOLEWB
;     BNE VSCROLLGUPREFILL
;     PSHS D
;     LDB CURRENTSL
;     CLRA
;     LEAY D, Y
;     PULS D
;     LEAU -1, U
;     LDB #0
;     CMPU #0
;     BNE VSCROLLGUPREFILL

;     JMP VSCROLLGE

; VSCROLLGDOWN
;     LDX CONSOLESA
;     LDB CONSOLEH
;     DECB
;     BEQ VSCROLLGDOWNYS31L1NO
;     PSHS D
;     LDB CURRENTSL
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     ABX
;     PULS D
;     TFR X, Y
;     LDA CONSOLEWB
;     NEGA
;     ADDA #1
;     LEAY A, Y

;     CLRA
;     LDB CONSOLEHB
;     TFR D, U
; VSCROLLGDOWNYS31L1
;     LDB #0
; VSCROLLGDOWNYS31
;     LDA B,X
;     STA B,Y
;     INCB
;     CMPB CONSOLEWB
;     BNE VSCROLLGDOWNYS31
;     LDB CURRENTSL
;     CLRA
;     NEGB
;     NEGA
;     SBCA #0
;     LEAX D, X
;     LEAY D, Y
;     LEAU -1, U
;     CMPU #0
;     BNE VSCROLLGDOWNYS31L1
;     JMP VSCROLLGDOWNYS31L1N2
; VSCROLLGDOWNYS31L1NO
;     TFR X, Y
; VSCROLLGDOWNYS31L1N2
;     LDU #8
;     LDA #0
;     LDB #0
; VSCROLLGDOWNREFILL
;     STA B,Y
;     INCB
;     CMPB CONSOLEWB
;     BNE VSCROLLGDOWNREFILL
;     PSHS D
;     LDB CURRENTSL
;     CLRA
;     LEAY D, Y
;     PULS D
;     LEAU -1, U
;     LDB #0
;     CMPU #0
;     BNE VSCROLLGDOWNREFILL

;     JMP VSCROLLGE

; VSCROLLGE
;     PULS A,B,X,Y,U
;     RTS