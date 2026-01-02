; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                          JOYSTICK HANDLER ON ATARI                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JFIRELATCH:     .BYTE $00, $00, $00, $00

; Read the FIRE button's latch for a specific joystick
;
;   X = joystick button id
;   A = $00 FIRE was not pressed
;       $ff FIRE was pressed
;
STRIG:

    TXA
    
    ; Is the button odd? So we can read directly
    ; the fire button.

    LSR
    TAX
    BCS JFIRE

    ; Load the latch value.

    LDA JFIRELATCH, X

    ; Check if latch is not zero.
    
    BEQ STRIGNONE

    ; TRUE, the joystick fire was pressed in the past.

    LDA #$FF

    ; Reset the latch.
    PHA
    LDA #0
    STA JFIRELATCH, X
    PLA
    
STRIGNONE:
    RTS

; Read the FIRE button for a specific joystick
;
;   X = joystick number
;   A = $00 FIRE was not pressed
;       $01 FIRE was pressed
;
JFIREX:

    ; Load the STRIG register from the hardware port.

    LDA $D010, X

    ; Isolate the FIRE bit.

    AND #$01
    EOR #$01

    ; Update the FIRE latch.

    PHA
    ORA JFIRELATCH, X
    STA JFIRELATCH, X
    PLA

    ; Done.

    RTS

; Read the FIRE button for a specific joystick
;
;   X = joystick number
;   A = $00 FIRE was not pressed
;       $FF FIRE was pressed
;
JFIRE:
    JSR JFIREX
    BEQ JFIRENONE
    LDA #$FF
JFIRENONE:
    RTS

; Read the joystick port.
;  X = port number
;  A = value read
JOYSTICK:
    CPX #0
    BEQ JOYSTICK0
    DEX
    BEQ JOYSTICK1
    DEX
    BEQ JOYSTICK2
    DEX
    BEQ JOYSTICK3
    RTS

JOYSTICK0:
    LDX #0
    LDA $D300
    EOR #$FF
    AND #$0F
    ASL
    STA MATHPTR0
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICK1:
    LDX #1
    LDA $D300
    EOR #$FF
    AND #$F0
    LSR
    LSR
    LSR
    STA MATHPTR0
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICK2:
    LDX #2
    LDA $D301
    EOR #$FF
    AND #$0F
    ASL
    STA MATHPTR0
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICK3:
    LDX #3
    LDA $D301
    EOR #$FF
    AND #$F0
    LSR
    LSR
    LSR
    STA MATHPTR0
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    JMP JOYSTICKDONE

JOYSTICKDONE:
    LDA MATHPTR0
    AND #$1f

@IF joystickConfig.values

    JMP JOYSTICKDONE1

JOYSTICKTSBREMAP:
    .BYTE   $0, $1, $5, $0
    .BYTE   $7, $8, $6, $0
    .BYTE   $3, $2, $4, $0
    .BYTE   $0, $0, $0, $0

JOYSTICKDONE1:
    PHA
    ROR
    TAY
    LDA JOYSTICKTSBREMAP, Y
    TAX
    PLA
    ROR
    BCC JOYSTICKNOFIRE
    TXA
    ORA #$80
    TAX
JOYSTICKNOFIRE:
    TXA
@ENDIF

    RTS

WAITFIREX:
    JSR JFIREX
    BEQ WAITFIREX
    CPY #0
    BEQ WAITFIREXD
WAITFIREXL1:
    JSR JFIREX
    BNE WAITFIREXL1
WAITFIREXD:
    RTS

WAITFIRE:
    LDX #0
    JSR JFIREX
    STA MATHPTR0
    LDX #1
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    LDX #2
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    LDX #3
    JSR JFIREX
    ORA MATHPTR0
    BEQ WAITFIRE
    CPY #0
    BEQ WAITFIRED
WAITFIREL1:
    LDX #0
    JSR JFIREX
    STA MATHPTR0
    LDX #1
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    LDX #2
    JSR JFIREX
    ORA MATHPTR0
    STA MATHPTR0
    LDX #3
    JSR JFIREX
    ORA MATHPTR0
    BNE WAITFIREL1
WAITFIRED:
    RTS
