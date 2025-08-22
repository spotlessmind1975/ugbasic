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
;*                           FLASH ROUTINE FOR VIC-II                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FLASHREGISTERADDRESSES:
    .WORD FLASHMANAGERL0ADDR+1
    .WORD FLASHMANAGERL1ADDR+1
    .WORD FLASHMANAGERL2ADDR+1
    .WORD FLASHMANAGERL3ADDR+1
    
FLASHREGISTERINDEX:
    .BYTE $00, $00, $00, $00

FLASHREGISTERTIMER:
    .BYTE $00, $00, $00, $00

FLASHREGISTERS0:
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS1:
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS2:
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS3:
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    .BYTE $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

; Manager for FLASH command
FLASHMANAGER:

	PHP
	PHA
	TXA
	PHA
	TYA
	PHA

    ; Load actual timer for register 0
    LDX FLASHREGISTERTIMER

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT0

    ; Otherwise, we must wait for the
    ; next tick to come.
    DEX
    STX FLASHREGISTERTIMER

    ; Move to register 1
    JMP FLASHMANAGER1

FLASHMANAGERRT0:

    ; Load current index for register 0
    LDX FLASHREGISTERINDEX

    ; Load timer valure for this index.
    LDA FLASHREGISTERS0, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    CMP #$00
    BNE FLASHMANAGERL0

    ; ... we must reset the index for register 0.
    STA FLASHREGISTERINDEX

    ; Move to register 1
    JMP FLASHMANAGER1

FLASHMANAGERL0:

    ; Store timer
    STA FLASHREGISTERTIMER

    ; Load color and store in the right register
    INX
    LDA FLASHREGISTERS0, X
FLASHMANAGERL0ADDR:
    STA $D021

    ; Increment index.
    INX
    STX FLASHREGISTERINDEX

FLASHMANAGER1:

    ; Load actual timer for register 0
    LDX FLASHREGISTERTIMER+1

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT1

    ; Otherwise, we must wait for the
    ; next tick to come.
    DEX
    STX FLASHREGISTERTIMER+1

    ; Move to register 1
    JMP FLASHMANAGER2

FLASHMANAGERRT1:

    ; Load current index for register 0
    LDX FLASHREGISTERINDEX+1

    ; Load timer valure for this index.
    LDA FLASHREGISTERS1, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    CMP #$00
    BNE FLASHMANAGERL1

    ; ... we must reset the index for register 0.
    STA FLASHREGISTERINDEX+1

    ; Move to register 1
    JMP FLASHMANAGER2

FLASHMANAGERL1:

    ; Store timer
    STA FLASHREGISTERTIMER+1

    ; Load color and store in the right register
    INX
    LDA FLASHREGISTERS1, X
FLASHMANAGERL1ADDR:
    STA $D022

FLASHMANAGER2:

    ; Load actual timer for register 0
    LDX FLASHREGISTERTIMER+1

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT2

    ; Otherwise, we must wait for the
    ; next tick to come.
    DEX
    STX FLASHREGISTERTIMER+1

    ; Move to register 1
    JMP FLASHMANAGER3

FLASHMANAGERRT2:

    ; Load current index for register 0
    LDX FLASHREGISTERINDEX+2

    ; Load timer valure for this index.
    LDA FLASHREGISTERS2, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    CMP #$00
    BNE FLASHMANAGERL2

    ; ... we must reset the index for register 0.
    STA FLASHREGISTERINDEX+2

    ; Move to register 1
    JMP FLASHMANAGER3

FLASHMANAGERL2:

    ; Store timer
    STA FLASHREGISTERTIMER+2

    ; Load color and store in the right register
    INX
    LDA FLASHREGISTERS2, X
FLASHMANAGERL2ADDR:
    STA $D023

    ; Increment index.
    INX
    STX FLASHREGISTERINDEX+2

    ; Increment index.
    INX
    STX FLASHREGISTERINDEX+2

FLASHMANAGER3:

    ; Load actual timer for register 0
    LDX FLASHREGISTERTIMER+2

    ; If it is zero then we can load
    ; the next couple color + timer.
    BEQ FLASHMANAGERRT3

    ; Otherwise, we must wait for the
    ; next tick to come.
    DEX
    STX FLASHREGISTERTIMER+2

    ; Move to register 1
    JMP FLASHMANAGER4

FLASHMANAGERRT3:

    ; Load current index for register 0
    LDX FLASHREGISTERINDEX+3

    ; Load timer valure for this index.
    LDA FLASHREGISTERS3, X

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    CMP #$00
    BNE FLASHMANAGERL3

    ; ... we must reset the index for register 0.
    STA FLASHREGISTERINDEX+3

    ; Move to register 1
    JMP FLASHMANAGER4

FLASHMANAGERL3:

    ; Store timer
    STA FLASHREGISTERTIMER+3

    ; Load color and store in the right register
    INX
    LDA FLASHREGISTERS3, X
FLASHMANAGERL3ADDR:
    STA $D024

    ; Increment index.
    INX
    STX FLASHREGISTERINDEX+3

FLASHMANAGER4:

    PLA
    TAY
	PLA
	TAX
	PLA
	PLP
	RTS

    RTS

; Y - color
; A - timer
FLASHREGISTER0:
    LDX FLASHREGISTERINDEX
    STA FLASHREGISTERS0, X
    INX
    TYA
    STA FLASHREGISTERS0, X
    INX
    STX FLASHREGISTERINDEX
    RTS
FLASHREGISTER1:
    LDX FLASHREGISTERINDEX+1
    STA FLASHREGISTERS1, X
    INX
    TYA
    STA FLASHREGISTERS1, X
    INX
    STX FLASHREGISTERINDEX+1
    RTS
FLASHREGISTER2:
    LDX FLASHREGISTERINDEX+2
    STA FLASHREGISTERS2, X
    INX
    TYA
    STA FLASHREGISTERS2, X
    INX
    STX FLASHREGISTERINDEX+2
    RTS
FLASHREGISTER3:
    LDX FLASHREGISTERINDEX+3
    STA FLASHREGISTERS3, X
    INX
    TYA
    STA FLASHREGISTERS3, X
    INX
    STX FLASHREGISTERINDEX+3
    RTS

FLASHBEGIN:
    SEI
    LDA #0
    STA FLASHREGISTERINDEX
    STA FLASHREGISTERINDEX+1
    STA FLASHREGISTERINDEX+2
    STA FLASHREGISTERINDEX+3
    RTS

; X - register number
; Y - color
; A - timer
FLASHREGISTER:
    CPX #0
    BEQ FLASHREGISTER0
    CPX #1
    BEQ FLASHREGISTER1
    CPX #2
    BEQ FLASHREGISTER2
    CPX #3
    BEQ FLASHREGISTER3
    RTS
    
FLASHEND:
    LDA #0
    LDX FLASHREGISTERINDEX
    BEQ FLASHEND1
    STA FLASHREGISTERS0, X
    STA FLASHREGISTERINDEX

FLASHEND1:
    LDX FLASHREGISTERINDEX+1
    BEQ FLASHEND2
    STA FLASHREGISTERS1, X
    STA FLASHREGISTERINDEX+1

FLASHEND2:
    LDX FLASHREGISTERINDEX+2
    BEQ FLASHEND3
    STA FLASHREGISTERS2, X
    STA FLASHREGISTERINDEX+2

FLASHEND3:
    LDX FLASHREGISTERINDEX+3
    BEQ FLASHEND4
    STA FLASHREGISTERS3, X
    STA FLASHREGISTERINDEX+3

FLASHEND4:
    CLI
    RTS
