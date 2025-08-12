; ; /*****************************************************************************
; ;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
; ;  *****************************************************************************
; ;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
; ;  *
; ;  * Licensed under the Apache License, Version 2.0 (the "License");
; ;  * you may not use this file except in compliance with the License.
; ;  * You may obtain a copy of the License at
; ;  *
; ;  * http://www.apache.org/licenses/LICENSE-2.0
; ;  *
; ;  * Unless required by applicable law or agreed to in writing, software
; ;  * distributed under the License is distributed on an "AS IS" BASIS,
; ;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; ;  * See the License for the specific language governing permissions and
; ;  * limitations under the License.
; ;  *----------------------------------------------------------------------------
; ;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
; ;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
; ;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
; ;  *
; ;  * http://www.apache.org/licenses/LICENSE-2.0
; ;  *
; ;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
; ;  * il software distribuito nei termini della Licenza è distribuito
; ;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
; ;  * implicite. Consultare la Licenza per il testo specifico che regola le
; ;  * autorizzazioni e le limitazioni previste dalla medesima.
; ;  ****************************************************************************/
; ;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; ;*                                                                             *
; ;*                           STARTUP ROUTINE FOR CGA                           *
; ;*                                                                             *
; ;*                             by Marco Spedaletti                             *
; ;*                                                                             *
; ;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Horizontal Total
;   - 0x38 for 40x25 alphanumeric or Graphic modes
;   - 0x71 for 80x25 alphanumeric
CGA_REG_HZ_TOTAL = 0x00

; Horizontal Displayed
;   - 0x28 for 40x25 alphanumeric or Graphic modes
;   - 0x50 for 80x25 alphanumeric
CGA_REG_HZ_DISP = 0x01

; Horizontal Sync Position
;   - 0x2d for 40x25 alphanumeric or Graphic modes
;   - 0x5a for 80x25 alphanumeric
CGA_REG_HZ_SYNC_POS = 0x02

; Horizontal Sync Width
;   - 0x0a for any mode
CGA_REG_HZ_SYNC_WIDTH = 0x03

; Vertical Total
;   - 0x1f
CGA_REG_VT_TOTAL = 0x04

; Vertical Total Ajust
;   - 0x06
CGA_REG_VT_TOTAL_ADJUST = 0x05

; Vertical Displayed
;   - 0x19 for 40x25 alphanumeric
;   - 0x19 for 80x25 alphanumeric
;   - 0x64 for Graphic modes
CGA_REG_VT_VERT_TOTAL_ADJUST = 0x06

; Vertical Sync Position
;   - 0x1c for 40x25 alphanumeric
;   - 0x1c for 80x25 alphanumeric
;   - 0x70 for Graphic modes
CGA_REG_VT_VERT_SYNC_POSITION = 0x07

; Interlace Mode
;   - 0x02 for any mode
CGA_REG_INTERLACE_MODE = 0x08

; Maximum Scan Line Address
;   - 0x07 for any mode
CGA_REG_MAX_SCAN_LINE_ADDRESS = 0x09

; Cursor Start
;   - 0x06 for any mode
CGA_REG_CURSOR_START = 0x0a

; Cursor End
;   - 0x07 for any mode
CGA_REG_CURSOR_END = 0x0b

; Start Address (H)
;   - 0x00 for any mode
CGA_REG_START_ADDRESS_H = 0x0c

; Start Address (L)
;   - 0x00 for any mode
CGA_REG_START_ADDRESS_L = 0x0d

; Cursor Address (H)
;   - 0x?? for any mode
CGA_REG_CURSOR_ADDRESS_H = 0x0e

; Cursor Address (L)
;   - 0x?? for any mode
CGA_REG_CURSOR_ADDRESS_L = 0x0f

; Light Pen Address (H)
;   - 0x?? for any mode
CGA_REG_LPEN_ADDRESS_H = 0x10

; Light Pen Address (L)
;   - 0x?? for any mode
CGA_REG_LPEN_ADDRESS_L = 0x11

; Write a specific value to the internal CGA register. 
; Input: 
;       AH = CGA register (0...16)
;       AL = CGA value (0...255)

WRITECGAREG:
    MOV DX, 0x3d4
    PUSH AX
    MOV AL, AH
    OUT DX, AL
    INC DX
    POP AX
    OUT DX, AL
    RET

; Write a value to the color select register
; Input: 
;       AL = xx543210 
;              |||||+--- blue border (40x25), blue background (320x200), blue foreground (640x200)
;              ||||+---- green border (40x25), green background (320x200), green foreground (640x200)
;              |||+---- red border (40x25), red background (320x200), red foreground (640x200)
;              ||+---- intensified color (any mode)
;              |+---- intensified color (graphic mode) or background colors (text mode)
;              +---- active color set: 
;                       0 = green, red, brown
;                       1 = cyan, magenta, white

WRITECGACOLORSELECTREG:
    MOV DX, 0x3d9
    OUT DX, AL
    RET

; Write a value to the mode control register
; Input: 
;       AL = xx543210 
;              |||||+--- 1 = 80x25, 0 = 40x25
;              ||||+---- 1 = 320x200, 0 = text mode
;              |||+---- 1 = b/w mode, 0 = color mode
;              ||+---- 1 = enable video, 0 = disable video
;              |+---- 1 = 640x200, 0 = 320x200 / text mode
;              +---- 1 = enable blink, 0 = disable blink

WRITECGAMODECONTROLREG:
    MOV DX, 0x3d8
    OUT DX, AL
    RET

; Read a value from the status register
; Output: 
;       AL = xxxx3210 
;                |||+--- 1 = free access to frame buffer, 0 = frame buffer in use
;                ||+---- 1 = light pen edge reached, 0 = light pen edge left
;                |+---- 1 = light pen switch off, 0 = light pen switch on
;                +---- 1 = vertical blank occurring, 0 = no vertical blank occurring

READCGASTATUSREG:
    MOV DX, 0x3da
    IN AL, DX
    RET
