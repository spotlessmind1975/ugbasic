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
;*                       CLEAR LINE ROUTINE FOR 6847                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINEG
CLINEGGO
    LDA CURRENTMODE
    CMPA #7
    BNE CLINEG7X
    JMP CLINEG7
CLINEG7X
    CMPA #8
    BNE CLINEG8X
    JMP CLINEG8
CLINEG8X
    CMPA #9
    BNE CLINEG9X
    JMP CLINEG9
CLINEG9X
    CMPA #10
    BNE CLINEG10X
    JMP CLINEG10
CLINEG10X
    CMPA #11
    BNE CLINEG11X
    JMP CLINEG11
CLINEG11X
    CMPA #12
    BNE CLINEG12X
    JMP CLINEG12
CLINEG12X
    CMPA #13
    BNE CLINEG13X
    JMP CLINEG13
CLINEG13X
    CMPA #14
    BNE CLINEG14X
    JMP CLINEG14
CLINEG14X
    RTS

;-----------------------------------------------------------------------------
; BITMAP MODE
;-----------------------------------------------------------------------------

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
CLINEG7

    JSR CALCPOS7

    JMP CLINEGCOMMON

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
CLINEG8

    JSR CALCPOS8

    JMP CLINEGCOMMON

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
CLINEG9

    JSR CALCPOS9

    JMP CLINEGCOMMON

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
CLINEG10

    JSR CALCPOS10

    JMP CLINEGCOMMON

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
CLINEG11

    JSR CALCPOS11

    JMP CLINEGCOMMON

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
CLINEG12

    JSR CALCPOS12

    JMP CLINEGCOMMON

;  The 128 x 192 Color Graphics mode generates a display 128 elements 
;  wide by 192 elements high. Each element may be one of four colors.
;  A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
;  by one scan line.
CLINEG13

    JSR CALCPOS13

    JMP CLINEGCOMMON

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
CLINEG14

    JSR CALCPOS14

    JMP CLINEGCOMMON

CLINEGCOMMON

    LDD #0
    STA   <MATHPTR4
    STB   <MATHPTR5    

    LDB <CHARACTERS
CLINEGLOOP2

    PSHS D
    LDA <CLINEX
    STA <MATHPTR0
    LDA <CLINEY
    STA <MATHPTR1
    JSR CALCPOSG
    PULS D

    LDU #0
    
CLINEGSP0

    PSHS D,Y,X

CLINEGSP0L1
    LDA CURRENTMODE
    CMPA #7
    BEQ CLINEGSP0L1M
    CMPA #9
    BEQ CLINEGSP0L1M
    CMPA #11
    BEQ CLINEGSP0L1M
    CMPA #13
    BEQ CLINEGSP0L1M

    LDA #0
    STA ,X
    JMP CLINEGSP0L1M2

CLINEGSP0L1M

    LDA #0
    STA , X+
    STA , X
    JMP CLINEGSP0L1M2

CLINEGSP0L1M2
    
    LDA CURRENTSL
    LEAX A, X 

    ANDCC #$FE
    LDA <PATTERN
    EORA #$FF
    ADDA #1
    LEAX A, X 
    LEAU 1, U
    CMPU #8
    BEQ CLINEGSP0L1X
    JMP CLINEGSP0L1

CLINEGSP0L1X

    PULS D,Y,X

    LDA <PATTERN
    LEAX A, X 
    LEAX 1, X

    INC <CLINEX
CLINEGNEXTX
    LDA <CLINEX
    CMPA CONSOLEX2
    BEQ CLINEGNEXT2
    JMP CLINEGNEXT
CLINEGNEXT2
    RTS
CLINEGNEXT
    DECB
    BEQ CLINEGEND
    JMP CLINEGLOOP2
CLINEGEND
    RTS
