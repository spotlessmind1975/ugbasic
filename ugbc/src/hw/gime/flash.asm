; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                            FLASH ROUTINE FOR GIME                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FLASHREGISTERADDRESSES
    fdb FLASHMANAGERL0ADDR+1
    fdb FLASHMANAGERL1ADDR+1
    fdb FLASHMANAGERL2ADDR+1
    fdb FLASHMANAGERL3ADDR+1
    
FLASHREGISTERINDEX
    fcb $00, $00, $00, $00

FLASHREGISTERTIMER
    fcb $00, $00, $00, $00

FLASHREGISTERS0
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS1
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS2
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS3
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    fcb $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

; Manager for FLASH command
FLASHMANAGER

    PULS X
    PULS D

    ; Load actual timer for register 0
    LDA FLASHREGISTERTIMER

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT0

    ; Otherwise, we must wait for the
    ; next tick to come.
    DECA
    STA FLASHREGISTERTIMER

    ; Move to register 1
    JMP FLASHMANAGER1

FLASHMANAGERRT0

    ; Load current index for register 0
    LDA FLASHREGISTERINDEX
    LDX FLASHREGISTERS0

    ; Load timer valure for this index.
    LDB A, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    BNE FLASHMANAGERL0

    ; ... we must reset the index for register 0.
    STB FLASHREGISTERINDEX

    ; Move to register 1
    JMP FLASHMANAGER1

FLASHMANAGERL0

    ; Store timer
    STB FLASHREGISTERTIMER

    ; Load color and store in the right register
    INCA
    LDB A, X
    PUSH D
FLASHMANAGERL0ADDR
    LDA #0
    JSR GIMEUPDATEPALETTE
    PULS D

    ; Increment index.
    INCA
    STA FLASHREGISTERINDEX

FLASHMANAGER1

    ; Load actual timer for register 0
    LDA FLASHREGISTERTIMER+1

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT1

    ; Otherwise, we must wait for the
    ; next tick to come.
    DECA
    STA FLASHREGISTERTIMER+1

    ; Move to register 1
    JMP FLASHMANAGER2

FLASHMANAGERRT1

    ; Load current index for register 0
    LDA FLASHREGISTERINDEX+1

    ; Load timer valure for this index.
    LDX FLASHREGISTERS1

    LDB A, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    BNE FLASHMANAGERL1

    ; ... we must reset the index for register 0.
    STB FLASHREGISTERINDEX+1

    ; Move to register 1
    JMP FLASHMANAGER2

FLASHMANAGERL1

    ; Store timer
    STB FLASHREGISTERTIMER+1

    ; Load color and store in the right register
    INCA
    LDB A, X
    PUSH D
FLASHMANAGERL1ADDR
    LDA #1
    JSR GIMEUPDATEPALETTE
    PULS D

FLASHMANAGER2

    ; Load actual timer for register 0
    LDB FLASHREGISTERTIMER+2

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT2

    ; Otherwise, we must wait for the
    ; next tick to come.
    DECB
    STB FLASHREGISTERTIMER+1

    ; Move to register 1
    JMP FLASHMANAGER3

FLASHMANAGERRT2

    ; Load current index for register 0
    LDA FLASHREGISTERINDEX+2

    ; Load timer valure for this index.
    LDX FLASHREGISTERS2
    LDB A, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    BNE FLASHMANAGERL2

    ; ... we must reset the index for register 0.
    STB FLASHREGISTERINDEX+2

    ; Move to register 1
    JMP FLASHMANAGER3

FLASHMANAGERL2

    ; Store timer
    STB FLASHREGISTERTIMER+2

    ; Load color and store in the right register
    INCA
    LDB A, X
    PUSH D
FLASHMANAGERL2ADDR
    LDA #2
    JSR GIMEUPDATEPALETTE
    PULS D

    ; Increment index.
    INCB
    STB FLASHREGISTERINDEX+2

FLASHMANAGER3

    ; Load actual timer for register 0
    LDB FLASHREGISTERTIMER+3

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT3

    ; Otherwise, we must wait for the
    ; next tick to come.
    DECB
    STB FLASHREGISTERTIMER+3

    ; Move to register 1
    JMP FLASHMANAGER4

FLASHMANAGERRT3

    ; Load current index for register 0
    LDB FLASHREGISTERINDEX+3

    ; Load timer valure for this index.
    LDX FLASHREGISTERS3

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    BNE FLASHMANAGERL3

    ; ... we must reset the index for register 0.
    STB FLASHREGISTERINDEX+3

    ; Move to register 1
    JMP FLASHMANAGER4

FLASHMANAGERL3

    ; Store timer
    STB FLASHREGISTERTIMER+3

    ; Load color and store in the right register
    INCA
    LDA A, X
    PUSH D
FLASHMANAGERL3ADDR
    LDA #3
    JSR GIMEUPDATEPALETTE
    PULS D

    ; Increment index.
    INX
    STX FLASHREGISTERINDEX+3

FLASHMANAGER4

    PULS D
    PULS X

    RTS

; B - color
; X - timer
FLASHREGISTER0
    PUSH D
    TFR X, D
    LDY FLASHREGISTERS0
    LDA FLASHREGISTERINDEX
    STB A, X
    INCA
    STA FLASHREGISTERINDEX
    PULS D
    LDA FLASHREGISTERINDEX
    STB A, X
    INCA
    STA FLASHREGISTERINDEX
    RTS
FLASHREGISTER1
    PUSH D
    TFR X, D
    LDY FLASHREGISTERS1
    LDA FLASHREGISTERINDEX+1
    STB A, X
    INCA
    STA FLASHREGISTERINDEX+1
    PULS D
    LDA FLASHREGISTERINDEX+1
    STB A, X
    INCA
    STA FLASHREGISTERINDEX+1
    RTS
FLASHREGISTER2
    PUSH D
    TFR X, D
    LDY FLASHREGISTERS2
    LDA FLASHREGISTERINDEX+2
    STB A, X
    INCA
    STA FLASHREGISTERINDEX+2
    PULS D
    LDA FLASHREGISTERINDEX+2
    STB A, X
    INCA
    STA FLASHREGISTERINDEX+2
    RTS
FLASHREGISTER3
    PUSH D
    TFR X, D
    LDY FLASHREGISTERS3
    LDA FLASHREGISTERINDEX+3
    STB A, X
    INCA
    STA FLASHREGISTERINDEX+3
    PULS D
    LDA FLASHREGISTERINDEX+3
    STB A, X
    INCA
    STA FLASHREGISTERINDEX+3
    RTS

FLASHBEGIN
    ORCC #$50
    LDA #0
    STA FLASHREGISTERINDEX
    STA FLASHREGISTERINDEX+1
    STA FLASHREGISTERINDEX+2
    STA FLASHREGISTERINDEX+3
    RTS

; A - register number
; B - color
; X - timer
FLASHREGISTER
    CMPA #0
    BEQ FLASHREGISTER0
    CMPA #1
    BEQ FLASHREGISTER1
    CMPA #2
    BEQ FLASHREGISTER2
    CMPA #3
    BEQ FLASHREGISTER3
    RTS
    
FLASHEND
    LDA #0
    LDB FLASHREGISTERINDEX
    BEQ FLASHEND1
    LDX FLASHREGISTERS0
    STA B, X
    STA FLASHREGISTERINDEX

FLASHEND1
    LDA #0
    LDB FLASHREGISTERINDEX+1
    BEQ FLASHEND2
    LDX FLASHREGISTERS1
    STA B, X
    STA FLASHREGISTERINDEX+1

FLASHEND2
    LDA #0
    LDB FLASHREGISTERINDEX+2
    BEQ FLASHEND3
    LDX FLASHREGISTERS2
    STA B, X
    STA FLASHREGISTERINDEX+2

FLASHEND3
    LDA #0
    LDB FLASHREGISTERINDEX+3
    BEQ FLASHEND4
    LDX FLASHREGISTERS3
    STA B, X
    STA FLASHREGISTERINDEX+3

FLASHEND4
    ANDCC #$AF
    RTS
