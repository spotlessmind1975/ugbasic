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
;*                      CLEAR LINE ROUTINE FOR GTIA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINE:
    LDA CURRENTMODE
    CMP #2
    BNE CLINEANTIC2X
    JMP CLINEANTIC2
CLINEANTIC2X:
    CMP #6
    BNE CLINEANTIC6X
    JMP CLINEANTIC6
CLINEANTIC6X:
    CMP #7
    BNE CLINEANTIC7X
    JMP CLINEANTIC7
CLINEANTIC7X:
    CMP #3
    BNE CLINEANTIC3X
    JMP CLINEANTIC3
CLINEANTIC3X:
    CMP #4
    BNE CLINEANTIC4X
    JMP CLINEANTIC4
CLINEANTIC4X:
    CMP #5
    BNE CLINEANTIC5X
    JMP CLINEANTIC5
CLINEANTIC5X:

;     CMP #8
;     BNE TEXTATANTIC8X
;     JMP TEXTATANTIC8
; TEXTATANTIC8X:
    ; CMP #9
    ; BEQ PLOTANTIC9
    ; CMP #10
    ; BEQ PLOTANTIC10
    ; CMP #11
    ; BEQ PLOTANTIC11
    ; CMP #13
    ; BEQ PLOTANTIC13
    ; CMP #15
    ; BEQ PLOTANTIC15
    ; CMP #12
    ; BEQ PLOTANTIC12
    ; CMP #14
    ; BEQ PLOTANTIC14
    RTS

CLINEANTIC2:
CLINEANTIC6:
CLINEANTIC7:
CLINEANTIC3:
CLINEANTIC4:
CLINEANTIC5:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDX CLINEY
    BEQ CLINEANTIC2SKIP
CLINEANTIC2L1:
    CLC
    LDA CURRENTWIDTH
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    DEX
    BNE CLINEANTIC2L1

CLINEANTIC2SKIP:
    LDA CHARACTERS
    BEQ CLINEANTIC2ENTIRE

    CLC
    LDA CLINEX
    ADC COPYOFTEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA #0
    ADC COPYOFTEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDX CHARACTERS
    LDY #0

CLINEANTIC2INCX:
    LDA #0
    STA (COPYOFTEXTADDRESS),y
        
    INC CLINEX
    LDA CLINEX
    CMP CURRENTWIDTH
    BNE CLINEANTIC2NEXT
    LDA #0
    STA CLINEX
    INC CLINEY
    LDA CLINEY
    CMP CURRENTHEIGHT
    BNE CLINEANTIC2NEXT

    LDA #$FE
    STA DIRECTION
    JSR VSCROLLT

    DEC CLINEY
    SEC
    LDA COPYOFTEXTADDRESS
    SBC CURRENTWIDTH 
    STA COPYOFTEXTADDRESS
    LDA COPYOFTEXTADDRESS+1
    SBC #0
    STA COPYOFTEXTADDRESS+1
 
CLINEANTIC2NEXT:
    INY
    DEX
    BNE CLINEANTIC2INCX
    RTS

CLINEANTIC2ENTIRE:
    LDY #0

CLINEANTIC2INC2X:
    LDA #0
    STA (COPYOFTEXTADDRESS),y
        
    INY
    INC CLINEX
    LDA CLINEX
    CMP CURRENTWIDTH
    BNE CLINEANTIC2INC2X
    RTS
