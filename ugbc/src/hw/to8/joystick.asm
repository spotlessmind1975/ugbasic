
; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
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
;*                           JOYSTICK EMULATION ON PC128OP                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JFIRELATCH  fcb     $00

; Read the FIRE button's latch for a specific joystick
;
;   B = joystick button id
;   A = $00 FIRE was not pressed
;       $ff FIRE was pressed
;
STRIG

    LSRB
    
    ; Is the button odd? So we can read directly
    ; the fire button.

    BCS JFIRE

    ; Load the latch value.

    LDX #JFIRELATCH
    LDA B, X

    ; Check if latch is not zero.
    
    BEQ STRIGNONE

    ; TRUE, the joystick fire was pressed in the past.

    LDA #$FF

    ; Reset the latch.
    LDA #0
    STA B, X
    
STRIGNONE
    RTS

; Read the FIRE button for a specific joystick
;
;   B = joystick number
;   A = $00 FIRE was not pressed
;       $01 FIRE was pressed
;
JFIREX

    ; Load the STRIG register from the hardware port.

    LDA #' '
    JSR KEYSTATE
    BCC JFIREX0DONE
    LDA #$1

JFIREX0

    ; Update the FIRE latch.

    PSHS D

    ORA JFIRELATCH
    STA JFIRELATCH

    PULS D

JFIREX0DONE:
    CMPA #0
    
    ; Done.

    RTS

; Read the FIRE button for a specific joystick
;
;   X = joystick number
;   A = $00 FIRE was not pressed
;       $FF FIRE was pressed
;
JFIRE
    JSR JFIREX
    BEQ JFIRENONE
    LDA #$FF
JFIRENONE
    RTS

JOYSTICK
    CMPA #0
    BNE JOYSTICK1

JOYSTICK0
    LDB #0

; #define KEY_UP                       0x0b
JOYSTICK0UP
    LDA #$0b
    JSR KEYSTATE
    BCC JOYSTICK0DOWN
    ORB #$01

; #define KEY_DOWN                     0x0a
JOYSTICK0DOWN
    LDA #$0D
    JSR KEYSTATE
    BCC JOYSTICK0LEFT
    ORB #$02

; #define KEY_LEFT                     0x08
JOYSTICK0LEFT
    LDA #$08
    JSR KEYSTATE
    BCC JOYSTICK0RIGHT
    ORB #$04

; #define KEY_RIGHT                    0x09
JOYSTICK0RIGHT
    LDA #$09
    JSR KEYSTATE
    BCC JOYSTICK0FIRE
    ORB #$08

; #define KEY_SPACE					' '
JOYSTICK0FIRE
    LDA #' '
    JSR KEYSTATE
    BCC JOYSTICK0DONE
    ORB #$10

JOYSTICK0DONE
    TFR B, A
    RTS

JOYSTICK1
    LDA #0

; #define KEY_W						'W'
JOYSTICK1UP
    LDA #'W'
    JSR KEYSTATE
    BCC JOYSTICK1DOWN
    ORB #$01

; #define KEY_S						'S'
JOYSTICK1DOWN
    LDA #'S'
    JSR KEYSTATE
    BCC JOYSTICK1LEFT
    ORB #$02

; #define KEY_A						'A'
JOYSTICK1LEFT
    LDA #'A'
    JSR KEYSTATE
    BCC JOYSTICK1RIGHT
    ORB #$04

; #define KEY_D						'D'
JOYSTICK1RIGHT
    LDA #'D'
    JSR KEYSTATE
    BCC JOYSTICK1FIRE
    ORB #$08

; #define KEY_X						'X'
JOYSTICK1FIRE
    LDA #'X'
    JSR KEYSTATE
    BCC JOYSTICK1DONE
    ORB #$10

JOYSTICK1DONE
    TFR B, A
    RTS

WAITFIREX
    CMPA #0
    BNE WAITFIRE1

WAITFIRE0
    LDA #' '
    JSR KEYSTATE
    BCC WAITFIRE0
    RTS

WAITFIRE1
    LDA #'X'
    JSR KEYSTATE
    BCC WAITFIRE1
    RTS

WAITFIRE
    LDA #' '
    JSR KEYSTATE
    BCC WAITFIREL1
    RTS
WAITFIREL1
    LDA #'X'
    JSR KEYSTATE
    BCC WAITFIRE
    RTS
