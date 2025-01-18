
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

@IF keyboardConfig.async

JOYSTICK
    CMPA #0
    BNE JOYSTICK1

JOYSTICK0
    LDB #0

; #define KEY_UP                      0x0e
JOYSTICK0UP
    LDA #$0e
    JSR KEYSTATE
    BCC JOYSTICK0DOWN
    ORB #$01

; #define KEY_DOWN                    0x2b
JOYSTICK0DOWN
    LDA #$2b
    JSR KEYSTATE
    BCC JOYSTICK0LEFT
    ORB #$02

; #define KEY_LEFT                    0x1c
JOYSTICK0LEFT
    LDA #$1C
    JSR KEYSTATE
    BCC JOYSTICK0RIGHT
    ORB #$04

; #define KEY_RIGHT                   0x1d
JOYSTICK0RIGHT
    LDA #$1d
    JSR KEYSTATE
    BCC JOYSTICK0FIRE
    ORB #$08

; #define KEY_SPACE					0x39
JOYSTICK0FIRE
    LDA #$39
    JSR KEYSTATE
    BCC JOYSTICK0DONE
    ORB #$10

JOYSTICK0DONE
    TFR B, A
    RTS

JOYSTICK1
    LDA #0

; #define KEY_W						0x2d
JOYSTICK1UP
    LDA #$2d
    JSR KEYSTATE
    BCC JOYSTICK1DOWN
    ORB #$01

; #define KEY_S						0x21
JOYSTICK1DOWN
    LDA #$21
    JSR KEYSTATE
    BCC JOYSTICK1LEFT
    ORB #$02

; #define KEY_A						0x10
JOYSTICK1LEFT
    LDA #$10
    JSR KEYSTATE
    BCC JOYSTICK1RIGHT
    ORB #$04

; #define KEY_D						0x22
JOYSTICK1RIGHT
    LDA #$22
    JSR KEYSTATE
    BCC JOYSTICK1FIRE
    ORB #$08

; #define KEY_X						0x2e
JOYSTICK1FIRE
    LDA #$2e
    JSR KEYSTATE
    BCC JOYSTICK1DONE
    ORB #$10

JOYSTICK1DONE
    TFR B, A
    RTS

@ELSE

JOYVALUE    fcb     $0

JOYSTICK
    CMPA #0
    BNE JOYSTICK1

JOYSTICK0
    LDB #0
    STB JOYVALUE

; #define KEY2_UP                0x62
JOYSTICK0UP
    LDA #$62
    JSR KEYSTATE
    BCC JOYSTICK0DOWN
    ORB #$01

; #define KEY2_DOWN              0x42
JOYSTICK0DOWN
    LDA #$42
    JSR KEYSTATE
    BCC JOYSTICK0LEFT
    ORB #$02

;# define KEY2_LEFT              0x52
JOYSTICK0LEFT
    LDA #$52
    JSR KEYSTATE
    BCC JOYSTICK0RIGHT
    ORB #$04

; #define KEY2_RIGHT             0x32
JOYSTICK0RIGHT
    LDA #$32
    JSR KEYSTATE
    BCC JOYSTICK0FIRE
    ORB #$08

; #define KEY2_SPACE             0x40
JOYSTICK0FIRE
    LDA #$40
    JSR KEYSTATE
    BCC JOYSTICK0DONE
    ORB #$10

JOYSTICK0DONE
    TFR B, A
    RTS

JOYSTICK1
    LDA #0

; #define KEY2_W                 0x4a
JOYSTICK1UP
    LDA #$4a
    JSR KEYSTATE
    BCC JOYSTICK1DOWN
    ORB #$01

; #define KEY2_S                0x46
JOYSTICK1DOWN
    LDA #$46
    JSR KEYSTATE
    BCC JOYSTICK1LEFT
    ORB #$02

; #define KEY2_A                0x56
JOYSTICK1LEFT
    LDA #$56
    JSR KEYSTATE
    BCC JOYSTICK1RIGHT
    ORB #$04

; #define KEY2_D                0x36
JOYSTICK1RIGHT
    LDA #$36
    JSR KEYSTATE
    BCC JOYSTICK1FIRE
    ORB #$08

; #define KEY2_X                0x50
JOYSTICK1FIRE
    LDA #$50
    JSR KEYSTATE
    BCC JOYSTICK1DONE
    ORB #$10

JOYSTICK1DONE
    TFR B, A
    RTS
