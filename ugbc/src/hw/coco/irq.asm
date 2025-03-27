; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                    IRQ ROUTINE ON TRS-80 COLOR COMPUTER                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IRQSVC
    PSHS D
    PSHS X
    PSHS Y
    PSHS U
    PSHS DP
    PSHS CC
IRQSVC2
    NOP
    NOP
    NOP
    PULS CC
    PULS DP
    PULS U
    PULS Y
    PULS X
    PULS D
    RTS
    
; OLDISVC
;     fdb $0

OLDISVC2
    fdb $0

OLDNMIISVC
    fdb $0

OLDNMIISVC2
    fdb $0

OLDCC
    fcb $0

OLDD
    fdb $0

@IF deployed.joystick && !joystickConfig.sync
JOYSTICKCOUNTER
    fcb $A
@ENDIF

@IF deployed.keyboard
KEYBOARDCOUNTER
    fcb $A
@ENDIF

    ; Arriving here, we have 12 registers on the stack, as follow:
    ; S     -> CC
    ; S+1   -> A
    ; S+2   -> B
    ; S+3   -> DP
    ; S+4   -> X
    ; S+6   -> Y
    ; S+8   -> U or S
    ; S+10  -> PC
    ;
ISVCIRQ

    ; Save CC!

    PSHS D
    TFR CC, A
    STA OLDCC
    PULS D

    JSR IRQSVC
@IF deployed.timer
    JSR TIMERMANAGER
@ENDIF
@IF deployed.keyboard && !keyboardConfig.sync
    JSR KEYBOARDMANAGER
@ENDIF
@IF deployed.joystick && !joystickConfig.sync
    DEC JOYSTICKCOUNTER
    BNE ISVCIRQJ
    JSR JOYSTICKMANAGER
    LDA #$A
    STA JOYSTICKCOUNTER
ISVCIRQJ
@ENDIF
@IF deployed.music
    JSR MUSICPLAYER
@ENDIF
    PSHS D
    LDD COCOTIMER
    ADDD #$1
    STD COCOTIMER

    LDD #0
    STD $00e3
    STA $FFDE

    LDD 12,S
    STD OLDISVC2

    PULS D
ISVCIRQFAILSAFE

    PSHS D
    LDD #ISVCIRQ2
    STD 12,S

    ; Disable interrupts when exiting (*sigh*)
    LDA 2,S
    ORA #$50
    STA 2,S

    PULS D

    ; By calling the old IRQ service routine,
    ; we give him the original values BUT PC.
    ; S     -> CC
    ; S+1   -> A
    ; S+2   -> B
    ; S+3   -> DP
    ; S+4   -> X
    ; S+6   -> Y
    ; S+8   -> U or S
    ; S+10  -> PC <--- now it points to ISVCIRQ2

    ; JMP [OLDISVC]

    LDA $ff03
    LDA $ff02

    RTI
    
ISVCIRQ2

    ; Arriving here, we have all registers restored.
    ; So we need to have additional values, ready
    ; to be used by a PULS CC, PC
    ; S     -> CC
    ; S+1   -> PC

    ORCC #$50

    ; Save the actual D register
    STD OLDD

    LDA RAMENABLED
    BEQ ISVCIRQ2NORAM
    STA $FFDF
ISVCIRQ2NORAM

    ; Push PC
    LDD OLDISVC2
    PSHS D

    ; Push CC (restore CC!)
    LDA OLDCC
    ANDA #$AF
    PSHS A

    ; Restore D register
    LDD OLDD

    ; We finished!
    PULS CC, PC    

NMIISVCIRQ
    PSHS D
    PSHS X
    LDD COCOTIMER
    ADDD #$1
    STD COCOTIMER
    LDD #0
    STD $00e3
    STA $FFDE
    TFR S, X
    LEAX +14,X
    LDD ,X
    STD OLDNMIISVC2
    LDD #NMIISVCIRQ2
    STD ,X
    PULS X
    PULS D
    JMP [OLDNMIISVC]
NMIISVCIRQ2
    PSHS D
    LDA RAMENABLED
    BEQ NMIISVCIRQ2NORAM
    STA $FFDF
NMIISVCIRQ2NORAM
    PULS D
    JMP [OLDNMIISVC2]

