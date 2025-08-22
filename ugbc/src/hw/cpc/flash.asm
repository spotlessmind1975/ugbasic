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
;*                           FLASH ROUTINE FOR CPC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FLASHREGISTERADDRESSES:
    dw FLASHMANAGERL0ADDR+2
    dw FLASHMANAGERL1ADDR+2
    dw FLASHMANAGERL2ADDR+2
    dw FLASHMANAGERL3ADDR+2
    
FLASHREGISTERINDEX:
    db $00, $00, $00, $00

FLASHREGISTERTIMER:
    db $00, $00, $00, $00

FLASHREGISTERS0:
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS1:
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS2:
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

FLASHREGISTERS3:
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
    db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

; Manager for FLASH command
FLASHMANAGER:

    PUSH AF
    PUSH BC
    PUSH HL
    PUSH DE

    ; Load actual timer for register 0
    ; LDX FLASHREGISTERTIMER
    LD A, (FLASHREGISTERTIMER)

    ; If it is zero then we can load
    ; the next couple color + timer.
    ; BEQ FLASHMANAGERRT0
    CP 0
    JR Z, FLASHMANAGERRT0

    ; Otherwise, we must wait for the
    ; next tick to come.
    ; DEX
    ; STX FLASHREGISTERTIMER
    DEC A
    LD (FLASHREGISTERTIMER), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER1

FLASHMANAGERRT0:

    ; Load current index for register 0
    ; LDX FLASHREGISTERINDEX
    PUSH AF
    LD A, (FLASHREGISTERINDEX)
    LD B, A
    POP AF

    ; Load timer valure for this index.
    ; LDA FLASHREGISTERS0, X
    LD HL, FLASHREGISTERS0
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    ; CMP #$00
    ; BNE FLASHMANAGERL0
    CP 0
    JR NZ, FLASHMANAGERL0

    ; ... we must reset the index for register 0.
    ; STA FLASHREGISTERINDEX
    LD (FLASHREGISTERINDEX), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER1

FLASHMANAGERL0:

    ; Store timer
    ; STA FLASHREGISTERTIMER
    LD (FLASHREGISTERTIMER), A

    ; Load color and store in the right register
    ; INX
    ; LDA FLASHREGISTERS0, X
    INC B
    LD HL, FLASHREGISTERS0
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)    

FLASHMANAGERL0ADDR:
    LD IXH, 0
    LD IXL, A
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    ; Increment index.
    ; INX
    ; STX FLASHREGISTERINDEX
    INC B
    LD A, B
    LD (FLASHREGISTERINDEX), A

FLASHMANAGER1:

    ; Load actual timer for register 0
    ; LDX FLASHREGISTERTIMER
    LD A, (FLASHREGISTERTIMER+1)

    ; If it is zero then we can load
    ; the next couple color + timer.
    ; BEQ FLASHMANAGERRT0
    CP 0
    JR Z, FLASHMANAGERRT1

    ; Otherwise, we must wait for the
    ; next tick to come.
    ; DEX
    ; STX FLASHREGISTERTIMER
    DEC A
    LD (FLASHREGISTERTIMER+1), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER1

FLASHMANAGERRT1:

    ; Load current index for register 0
    ; LDX FLASHREGISTERINDEX
    PUSH AF
    LD A, (FLASHREGISTERINDEX+1)
    LD B, A
    POP AF

    ; Load timer valure for this index.
    ; LDA FLASHREGISTERS0, X
    LD HL, FLASHREGISTERS1
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    ; CMP #$00
    ; BNE FLASHMANAGERL0
    CP 0
    JR NZ, FLASHMANAGERL1

    ; ... we must reset the index for register 0.
    ; STA FLASHREGISTERINDEX
    LD (FLASHREGISTERINDEX+1), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER2

FLASHMANAGERL1:

    ; Store timer
    ; STA FLASHREGISTERTIMER
    LD (FLASHREGISTERTIMER+1), A

    ; Load color and store in the right register
    ; INX
    ; LDA FLASHREGISTERS0, X
    INC B
    LD HL, FLASHREGISTERS1
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)    

FLASHMANAGERL1ADDR:
    LD IXH, 1
    LD IXL, A
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    ; Increment index.
    ; INX
    ; STX FLASHREGISTERINDEX
    INC B
    LD A, B
    LD (FLASHREGISTERINDEX+1), A

FLASHMANAGER2:

    ; Load actual timer for register 0
    ; LDX FLASHREGISTERTIMER
    LD A, (FLASHREGISTERTIMER+2)

    ; If it is zero then we can load
    ; the next couple color + timer.
    ; BEQ FLASHMANAGERRT0
    CP 0
    JR Z, FLASHMANAGERRT2

    ; Otherwise, we must wait for the
    ; next tick to come.
    ; DEX
    ; STX FLASHREGISTERTIMER
    DEC A
    LD (FLASHREGISTERTIMER+2), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER3

FLASHMANAGERRT2:

    ; Load current index for register 0
    ; LDX FLASHREGISTERINDEX
    PUSH AF
    LD A, (FLASHREGISTERINDEX+2)
    LD B, A
    POP AF

    ; Load timer valure for this index.
    ; LDA FLASHREGISTERS0, X
    LD HL, FLASHREGISTERS2
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    ; CMP #$00
    ; BNE FLASHMANAGERL0
    CP 0
    JR NZ, FLASHMANAGERL2

    ; ... we must reset the index for register 0.
    ; STA FLASHREGISTERINDEX
    LD (FLASHREGISTERINDEX+2), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER3

FLASHMANAGERL2:

    ; Store timer
    ; STA FLASHREGISTERTIMER
    LD (FLASHREGISTERTIMER+2), A

    ; Load color and store in the right register
    ; INX
    ; LDA FLASHREGISTERS0, X
    INC B
    LD HL, FLASHREGISTERS2
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)    

FLASHMANAGERL2ADDR:
    LD IXH, 2
    LD IXL, A
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    ; Increment index.
    ; INX
    ; STX FLASHREGISTERINDEX
    INC B
    LD A, B
    LD (FLASHREGISTERINDEX+2), A

FLASHMANAGER3:

    ; Load actual timer for register 0
    ; LDX FLASHREGISTERTIMER
    LD A, (FLASHREGISTERTIMER+3)

    ; If it is zero then we can load
    ; the next couple color + timer.
    ; BEQ FLASHMANAGERRT0
    CP 0
    JR Z, FLASHMANAGERRT3

    ; Otherwise, we must wait for the
    ; next tick to come.
    ; DEX
    ; STX FLASHREGISTERTIMER
    DEC A
    LD (FLASHREGISTERTIMER+3), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER4

FLASHMANAGERRT3:

    ; Load current index for register 0
    ; LDX FLASHREGISTERINDEX
    PUSH AF
    LD A, (FLASHREGISTERINDEX+3)
    LD B, A
    POP AF

    ; Load timer valure for this index.
    ; LDA FLASHREGISTERS0, X
    LD HL, FLASHREGISTERS3
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)

    ; If it is not zero, we can consider it
    ; a real couple (timer, color); otherwise...
    ; CMP #$00
    ; BNE FLASHMANAGERL0
    CP 0
    JR NZ, FLASHMANAGERL3

    ; ... we must reset the index for register 0.
    ; STA FLASHREGISTERINDEX
    LD (FLASHREGISTERINDEX+3), A

    ; Move to register 1
    ; JMP FLASHMANAGER1
    JR FLASHMANAGER4

FLASHMANAGERL3:

    ; Store timer
    ; STA FLASHREGISTERTIMER
    LD (FLASHREGISTERTIMER+3), A

    ; Load color and store in the right register
    ; INX
    ; LDA FLASHREGISTERS0, X
    INC B
    LD HL, FLASHREGISTERS3
    LD E, B
    LD D, 0
    ADD HL, DE
    LD A, (HL)    

FLASHMANAGERL3ADDR:
    LD IXH, 3
    LD IXL, A
    LD IYL, 1
    CALL CPCUPDATEPALETTE

    ; Increment index.
    ; INX
    ; STX FLASHREGISTERINDEX
    INC B
    LD A, B
    LD (FLASHREGISTERINDEX+3), A

FLASHMANAGER4:

    POP DE
    POP HL
    POP BC
    POP AF

    RET

; B - timer
; C - color
FLASHREGISTER0:
    LD A, (FLASHREGISTERINDEX)
    LD HL, FLASHREGISTERS0
    LD E, A
    LD D, 0
    ADD HL, DE
    LD (HL), B
    INC HL
    LD (HL), C
    INC A
    INC A
    LD (FLASHREGISTERINDEX), A
    RET
FLASHREGISTER1:
    LD A, (FLASHREGISTERINDEX+1)
    LD HL, FLASHREGISTERS1
    LD E, A
    LD D, 0
    ADD HL, DE
    LD (HL), B
    INC HL
    LD (HL), C
    INC A
    INC A
    LD (FLASHREGISTERINDEX+1), A
    RET
FLASHREGISTER2:
    LD A, (FLASHREGISTERINDEX+2)
    LD HL, FLASHREGISTERS2
    LD E, A
    LD D, 0
    ADD HL, DE
    LD (HL), B
    INC HL
    LD (HL), C
    INC A
    INC A
    LD (FLASHREGISTERINDEX+2), A
    RET
FLASHREGISTER3:
    LD A, (FLASHREGISTERINDEX+3)
    LD HL, FLASHREGISTERS3
    LD E, A
    LD D, 0
    ADD HL, DE
    LD (HL), B
    INC HL
    LD (HL), C
    INC A
    INC A
    LD (FLASHREGISTERINDEX+3), A
    RET

FLASHBEGIN:
    DI
    LD A, 0
    LD (FLASHREGISTERINDEX), A
    LD (FLASHREGISTERINDEX+1), A
    LD (FLASHREGISTERINDEX+2), A
    LD (FLASHREGISTERINDEX+3), A
    RET

; A - register number
; C - color
; B - timer
FLASHREGISTER:
    CP 0
    JR Z, FLASHREGISTER0
    CP 1
    JR Z, FLASHREGISTER1
    CP 2
    JR Z, FLASHREGISTER2
    CP 3
    JR Z, FLASHREGISTER3
    RET
    
FLASHEND:
    LD A, (FLASHREGISTERINDEX)
    CP 0
    JR Z, FLASHEND1
    LD B, A
    LD A, 0
    LD HL, FLASHREGISTERS0
    LD E, B
    LD D, 0
    ADD HL, DE
    LD (HL), A
    LD (FLASHREGISTERINDEX), A
FLASHEND1:
    LD A, (FLASHREGISTERINDEX+1)
    CP 0
    JR Z, FLASHEND2
    LD B, A
    LD A, 0
    LD HL, FLASHREGISTERS1
    LD E, B
    LD D, 0
    ADD HL, DE
    LD (HL), A
    LD (FLASHREGISTERINDEX+1), A
FLASHEND2:
    LD A, (FLASHREGISTERINDEX+2)
    CP 0
    JR Z, FLASHEND3
    LD B, A
    LD A, 0
    LD HL, FLASHREGISTERS2
    LD E, B
    LD D, 0
    ADD HL, DE
    LD (HL), A
    LD (FLASHREGISTERINDEX+2), A
FLASHEND3:
    LD A, (FLASHREGISTERINDEX+3)
    CP 0
    JR Z, FLASHEND4
    LD B, A
    LD A, 0
    LD HL, FLASHREGISTERS3
    LD E, B
    LD D, 0
    ADD HL, DE
    LD (HL), A
    LD (FLASHREGISTERINDEX+3), A
FLASHEND4:
    EI
    RET
    