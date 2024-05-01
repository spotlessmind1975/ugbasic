; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*               JOYSTICK MOVEMENT DETECTION ON TRS-80 COLOR COMPUTER 3        *
;*                                                                             *
;* Based on code by R. Allen "Exile In Paradise" Murphey.                      *
;* Originally from https://exileinparadise.com/tandy_color_computer:joystick   *
;* Adapted to emulate a digital joystick                                       *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TRLBIT     rmb   1

JOYSTICK
    LDA PORT
    CMPA #0
    BEQ JOYSTICK0
    CMPA #1
    BEQ JOYSTICK1
    CLR DIRECTION
    RTS

JOYSTICK0
    JSR SOUNDOFF
    ; Axis 0 is left-right / X axis of left stick.
    JSR MUX1AOFF
    JSR MUX2BOFF
    JSR ADC0

    ; yes, I tend to divide the stick into "9 zones" - a center and 8 direction areas 
    ; around the center.; X or Y < 20 and X or Y > 44 or there abouts gives you a center 
    ; with slop and a zone at each edge that triggers the digital directions

    CMPA #44
    BGT JOYSTICK0RIGHT
    CMPA #20
    BLT JOYSTICK0LEFT
    JMP JOYSTICK0B

JOYSTICK0RIGHT
    LDA #8
    STA DIRECTION
    JMP JOYSTICK0B

JOYSTICK0LEFT
    LDA #4
    STA DIRECTION
    JMP JOYSTICK0B

JOYSTICK0B
    ; Axis 1 is up-down / Y axis of left stick
    JSR MUX1AON
    JSR MUX2BOFF
    JSR ADC0
    CMPA #44
    BGT JOYSTICK0DOWN
    CMPA #20
    BLT JOYSTICK0UP
    JMP JOYSTICK0D

JOYSTICK0DOWN
    LDA #1
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK0D

JOYSTICK0UP
    LDA #2
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK0D

JOYSTICK0D
    LDA #$FF
    STA PIA0BD
    LDA PIA0AD
    COMA
    ANDA #$05
    LSLA
    LSLA
    LSLA
    LSLA
    ORA DIRECTION
    STA DIRECTION
    RTS

JOYSTICK1
    JSR SOUNDOFF
    ; Axis 2 is left-right / X axis of right stick
    JSR MUX1AOFF
    JSR MUX2BON
    JSR ADC0

    ; yes, I tend to divide the stick into "9 zones" - a center and 8 direction areas 
    ; around the center.; X or Y < 20 and X or Y > 44 or there abouts gives you a center 
    ; with slop and a zone at each edge that triggers the digital directions

    CMPA #44
    BGT JOYSTICK1RIGHT
    CMPA #20
    BLT JOYSTICK1LEFT
    JMP JOYSTICK1B

JOYSTICK1RIGHT
    LDA #8
    STA DIRECTION
    JMP JOYSTICK1B

JOYSTICK1LEFT
    LDA #4
    STA DIRECTION
    JMP JOYSTICK1B

JOYSTICK1B
    ; Axis 3 is up-down / Y axis of right stick
    JSR MUX1AON
    JSR MUX2BON
    JSR ADC0

    CMPA #44
    BGT JOYSTICK1DOWN

    CMPA #20
    BLT JOYSTICK1UP
    JMP JOYSTICK1D

JOYSTICK1DOWN
    LDA #2
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK1D

JOYSTICK1UP
    LDA #1
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK1D

JOYSTICK1D
    LDA #$FF
    STA PIA0BD
    LDA PIA0AD
    COMA
    ANDA #$0a
    LSLA
    LSLA
    LSLA
    ORA DIRECTION
    STA DIRECTION
    RTS

;*********************************************************************
;* ADC Successive Approximation Search
;* from Musical Applications of Microprocessors pages 262-269
;* by Hal Chamberlin, (c) 1985 Hayden Books
;* 6502 Successive Approximation Figure 7-31 page 264
;* Adapted and modified for 6809 / Color Computer by R. Allen Murphey
;* Originally from https://exileinparadise.com/tandy_color_computer:joystick
;*********************************************************************

ADC0
    LDA #$20
    STA TRLBIT
    CLRA
ADC1
    ORA TRLBIT
    LSLA
    LSLA
    ORA #%00000010
    STA PIA1AD
    ANDA #%11111101
    LSRA
    LSRA
    LDB PIA0AD
    BMI ADC2
    EORA TRLBIT
ADC2
    LSR TRLBIT
    BCC ADC1
    RTS

SOUNDOFF
    LDA PIA1BC
    ANDA #%11110111
    STA PIA1BC
    RTS

MUX1AOFF
    LDA PIA0AC
    ANDA #%11110111
    STA PIA0AC
    RTS

MUX1AON
    LDA PIA0AC
    ORA #%00001000
    STA PIA0AC
    RTS

MUX2BOFF
    LDA PIA0BC
    ANDA #%11110111
    STA PIA0BC
    RTS

MUX2BON
    LDA PIA0BC
    ORA #%00001000
    STA PIA0BC
    RTS
