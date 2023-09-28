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
;*               JOYSTICK MOVEMENT DETECTION ON TRS-80 COLOR COMPUTER 3        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;*********************************************************************
;* Title: JOY.ASM
;*********************************************************************
;* Author: R. Allen Murphey
;*
;* Description: CoCo DAC Joystick input
;*
;* Assembler: lwasm 1.4.2
;* lwasm -o JOY.BIN JOY.ASM
;*   decb dskinit JOY.DSK
;* OR
;*   decb kill JOY.DSK,JOY.BIN
;* decb copy JOY.BIN JOY.DSK,JOY.BIN -2
;* LOADM"JOY":EXEC
;*
;* Revision History:
;* Rev #     Date      Who     Comments
;* -----  -----------  ------  ---------------------------------------
;* 00     2020         RAM     Initial test code
;*********************************************************************

PIA0AD     equ   $FF00
PIA0AC     equ   $FF01
PIA0BD     equ   $FF02
PIA0BC     equ   $FF03

PIA1AD     equ   $FF20
PIA1AC     equ   $FF21
PIA1BD     equ   $FF22
PIA1BC     equ   $FF23

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
    JSR MUX1AOFF
    JSR MUX2BOFF
    JSR ADC0
    CMPA #0
    BGT JOYSTICK0UP
    BLT JOYSTICK0DOWN
    JMP JOYSTICK0B

JOYSTICK0UP
    LDA #1
    STA DIRECTION
    JMP JOYSTICK0B

JOYSTICK0DOWN
    LDA #2
    STA DIRECTION
    JMP JOYSTICK0B

JOYSTICK0B
    JSR MUX1AON
    JSR MUX2BOFF
    JSR ADC0
    CMPA #0
    BGT JOYSTICK0LEFT
    BLT JOYSTICK0RIGHT
    JMP JOYSTICK0D

JOYSTICK0LEFT
    LDA #4
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK0D

JOYSTICK0RIGHT
    LDA #8
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK0D

JOYSTICK0D
    LDA #$FF
    STA PIA0BD
    LDA PIA0AD
    ANDA #$0a
    LSLA
    LSLA
    LSLA
    ORA DIRECTION
    STA DIRECTION
    RTS

; ---

JOYSTICK1
    JSR SOUNDOFF
    JSR MUX1AOFF
    JSR MUX2BON
    JSR ADC0
    CMPA #0
    BGT JOYSTICK1UP
    BLT JOYSTICK1DOWN
    JMP JOYSTICK1B

JOYSTICK1UP
    LDA #1
    STA DIRECTION
    JMP JOYSTICK1B

JOYSTICK1DOWN
    LDA #2
    STA DIRECTION
    JMP JOYSTICK1B

JOYSTICK1B
    JSR MUX1AON
    JSR MUX2BON
    JSR ADC0
    CMPA #0
    BGT JOYSTICK1LEFT
    BLT JOYSTICK1RIGHT
    JMP JOYSTICK1D

JOYSTICK1LEFT
    LDA #4
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK1D

JOYSTICK1RIGHT
    LDA #8
    ORA DIRECTION
    STA DIRECTION
    JMP JOYSTICK1D

JOYSTICK1D
    LDA #$FF
    STA PIA0BD
    LDA PIA0AD
    ANDA #$05
    LSLA
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
