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
;*                          JOYSTICK DETECTION ON CIA                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JFIRELATCH:     .BYTE $00, $00

@IF joystickConfig.values

    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
    ;-
    ;- Change the reading values based on its convention.
    ;-
    ;- To enable: DEFINE JOYSTICK VALUES TSB
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ; This is the four bit map used to "map" each read value with the TSB.
    JOYSTICKTSBREMAP:
        .BYTE   $0, $1, $5, $0
        .BYTE   $7, $8, $6, $0
        .BYTE   $3, $2, $4, $0
        .BYTE   $0, $0, $0, $0

    JOYSTICKTSB:
        PHA
        AND #$0F
        TAY
        LDA JOYSTICKTSBREMAP, Y
        TAX
        PLA
        AND #$10
        BEQ JOYSTICKNOFIRE0
        TXA
        ORA #$80
        TAX
    JOYSTICKNOFIRE0:
        TXA
        RTS

@ENDIF

; Read the position and button for first joystick (JOY(0))
; (using the ugBASIC convention)
JOYSTICKREAD0:
    LDA #$7F
    STA $DC00
    LDA $DC01
    AND #$1F
    EOR #$1F
    RTS

; Read the position and button for second joystick (JOY(1))
JOYSTICKREAD1:
    LDA #$E0
    LDY #$FF
    STA $DC02
    LDA $DC00
    STY $DC02
    AND #$1F
    EOR #$1F
    RTS

@IF joystickConfig.sync

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;- SYNCHRONIZED JOYSTICK READING
;-
;- This is the actual implementation that will be used, where the programmer 
;- chooses to read the joystick position at the specific moment the JOY or 
;- similar instruction is executed.
;-
;- To enable: DEFINE JOYSTICK SYNC
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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
        BCS JFIRE

        TAX

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

    JOYSTICKREAD:
        CPX #0
        BNE JOYSTICKREAD1
        BEQ JOYSTICKREAD0
        
    ; Read the FIRE button for a specific joystick
    ;
    ;   X = joystick number
    ;   A = $00 FIRE was not pressed
    ;       $01 FIRE was pressed
    ;
    JFIREX:

        ; Load the STRIG register from the hardware port.

        JSR JOYSTICKREAD

        ; Isolate the FIRE bit.

        AND #$10

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


    ; Wait for any fire is pressed on JOY(0)

    WAITFIRE0:
        JSR JFIRE
        BEQ WAITFIRE0
        CPY #0
        BEQ WAITFIRE0D
    WAITFIRE0L1:
        JSR JFIRE
        BNE WAITFIRE0L1
    WAITFIRE0D:
        RTS

    WAITFIREA:
        CPX #0
        BEQ WAITFIRE0

    ; Wait for any fire is pressed on JOY(1)

    WAITFIRE1:
        JSR JFIRE
        BEQ WAITFIRE1
        CPY #0
        BEQ WAITFIRE1D
    WAITFIRE1L1:
        JSR JFIRE
        BNE WAITFIRE1L1
    WAITFIRE1D:
        RTS

    ; Wait for any fire is pressed, for any joystick.
    WAITFIRE:
        LDX #0
        JSR JFIRE
        STA MATHPTR0
        LDX #1
        JSR JFIRE
        ORA MATHPTR0
        BEQ WAITFIRE
        CPY #0
        BEQ WAITFIRED
    WAITFIREL1:
        LDX #0
        JSR JFIRE
        STA MATHPTR0
        LDX #1
        JSR JFIRE
        ORA MATHPTR0
        BNE WAITFIREL1
    WAITFIRED:
        RTS

@ELSE

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;- ASYNCRONOUS JOYSTICK READING (default)
;-
;- This is the implementation used where the programmer chooses to use 
;- interrupts to read the joystick position.
;-
;- To enable: DEFINE JOYSTICK ASYNC
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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
        BCS JFIRE

        TAX

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

        LDA JOYSTICK0, X

        ; Isolate the FIRE bit.

        AND #$10

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

    ; Dedicated storage space for JOY(0) and JOY(1)

    JOYSTICK0:      .BYTE   $0
    JOYSTICK1:      .BYTE   $0

    ; IRQ service for joystick

    JOYSTICKMANAGER:

        ; Save registers on stack, just in case.

        PHP
        PHA
        TXA
        PHA
        TYA
        PHA

        ; Read JOY(0)

        JSR JOYSTICKREAD0

        ; Store the value into the dedicated storage.

        STA JOYSTICK0

        ; Read JOY(1)

        JSR JOYSTICKREAD1

        ; Store value into the dedicated storage.
        
        STA JOYSTICK1

        ; Restore registers on stack, just in case.

        PLA
        TAY
        PLA
        TAX
        PLA
        PLP

        RTS

    ; Wait for any fire is pressed on JOY(0)

    WAITFIRE0:
        JSR JFIRE
        BEQ WAITFIRE0
        CPY #0
        BEQ WAITFIRE0D
    WAITFIRE0L1:
        JSR JFIRE
        BNE WAITFIRE0L1
    WAITFIRE0D:
        RTS

    WAITFIREX:
        CPX #0
        BEQ WAITFIRE0

    ; Wait for any fire is pressed on JOY(1)

    WAITFIRE1:
        JSR JFIRE
        BEQ WAITFIRE1
        CPY #0
        BEQ WAITFIRE1D
    WAITFIRE1L1:
        JSR JFIRE
        BNE WAITFIRE1L1
    WAITFIRE1D:
        RTS

    ; Wait for any fire is pressed, for any joystick.
    
    WAITFIRE:

        ; Read dedicated storage for JOY(0)

        LDX #0
        JSR JFIRE
        STA MATHPTR0

        ; Read dedicated storage for JOY(1)

        LDX #1
        JSR JFIRE
        ORA MATHPTR0

        ; If both are zero, recheck again.
        BEQ WAITFIRE

        CPY #0
        BEQ WAITFIRED

    WAITFIREDL1:
    
        ; Read dedicated storage for JOY(0)

        LDX #0
        JSR JFIRE
        STA MATHPTR0

        ; Read dedicated storage for JOY(1)

        LDX #1
        JSR JFIRE
        ORA MATHPTR0

        ; If both are zero, recheck again.
        BNE WAITFIREDL1

    WAITFIRED:
        RTS

@ENDIF
