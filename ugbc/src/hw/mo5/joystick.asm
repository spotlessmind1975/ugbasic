
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
;*                           JOYSTICK EMULATION ON MO5                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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

WAITFIREX
    CMPA #0
    BNE WAITFIRE1

WAITFIRE0
    LDA #$39
    JSR KEYSTATE
    BCC WAITFIRE0
    RTS

WAITFIRE1
    LDA #$2e
    JSR KEYSTATE
    BCC WAITFIRE1
    RTS

WAITFIRE
    LDA #$39
    JSR KEYSTATE
    BCC WAITFIREL1
    RTS
WAITFIREL1
    LDA #$2e
    JSR KEYSTATE
    BCC WAITFIRE
    RTS
