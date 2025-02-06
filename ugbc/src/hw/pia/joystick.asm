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
;*               JOYSTICK MOVEMENT DETECTION ON TRS-80 COLOR COMPUTER          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

IO		equ		$ff00		; IO page on Dragon

DPPIA0DA	EQU		$00		; Side A Data/DDR
DPPIA0CRA	EQU		$01		; Side A Control.
DPPIA0DB	EQU		$02		; Side B Data/DDR
DPPIA0CRB	EQU		$03		; Side B Control.

PIA0DA		EQU		DPPIA0DA+IO	; Side A Data/DDR
PIA0CRA		EQU		DPPIA0CRA+IO	; Side A Control.
PIA0DB		EQU		DPPIA0DB+IO	; Side A Data/DDR
PIA0CRB		EQU		DPPIA0CRB+IO	; Side A Control.

DPPIA1DA	EQU		$20		; Side A Data/DDR
DPPIA1CRA	EQU		$21		; Side A Control.
DPPIA1DB	EQU		$22		; Side B Data/DDR
DPPIA1CRB	EQU		$23		; Side B Control.

PIA1DA		EQU		DPPIA1DA+IO	; Side A Data/DDR
PIA1CRA		EQU		DPPIA1CRA+IO	; Side A Control.
PIA1DB		EQU		DPPIA1DB+IO	; Side A Data/DDR
PIA1CRB		EQU		DPPIA1CRB+IO	; Side A Control.

@IF joystickConfig.values

;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;- (TUNED) SIMON'S BASIC COMPATIBLE LAYER
;-
;- Change the reading values based on its convention.
;-
;- To enable: DEFINE JOYSTICK VALUES TSB
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

JOYSTICKTSBREMAP
    fcb     $0, $1, $5, $0
    fcb     $7, $8, $6, $0
    fcb     $3, $2, $4, $0
    fcb     $0, $0, $0, $0

JOYSTICKTSB
    PSHS D
    PSHS X
    LDX #JOYSTICKTSBREMAP
    LDA <DIRECTION    
    ANDA #$0F
    LDB A, X
    LDA <DIRECTION    
    ANDA #$20
    BEQ JOYSTICKNOFIRE0
    ORB #$80
JOYSTICKNOFIRE0
    STB <DIRECTION
    PULS X
    PULS D
    RTS

@ENDIF

@EMIT joystickConfig.retries AS JOYSTICKRETRIES

TEMPJOYSTICK       
    fcb 0, 0, 0, 0

SELJOYSTICK
LBD41   
    LDU     #PIA0CRA		; point U at PIAs
    BSR     LBD46
LBD46   
    LDA     ,U			; get the control register
    ANDA    #$F7			; mask out current bit
    RORB				; get bit 0 of B into carry
    BCC     LBD4F			; carry clear, skip on, bit is zero
    ORA     #$08			; set bit in control register
LBD4F
    STA     ,U++			; save it back and select side B control
    RTS

JOYSTICK

    CLR <DIRECTION
    LDA #$FF
    STA $FF02
    LDA $FF00
    COMA
    LDB <PORT
    BEQ JOYSTICKP0
JOYSTICKP1
    ANDA #$01
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    STA <DIRECTION
    JMP JOYSTICKD
JOYSTICKP0
    ANDA #$02
    LSLA
    LSLA
    LSLA
    LSLA
    STA <DIRECTION
    JMP JOYSTICKD

JOYSTICKD
    LDA $FF01
    LDB $FF03
    PSHS D
LBD52   
    LEAS    -3,S			; make room on stack for temporary values
    LDX     #TEMPJOYSTICK
    LDB     #$03			; get values for 3+1 joystick axies
	
LBD59   
    LDA     #(JOYSTICKRETRIES+1)			; 10 retries to get a stable value
    STD     1,S			; store joystic axis number and try number on stack
    JSR     SELJOYSTICK 		; select the joystick to read

; A is a shift counter, how many bits to convert and will be  $40 (6 bits).
; B contains a value equal to 1/2 the current trial difference, initially $80 (2.5V).
LBD5F   
    LDD     #$4080			
LBD62   
    STA     ,S			; store shift counter on stack	
    STB     PIA1DA			; send value to D/A converter
    TST     PIA0DA			; read result value, comparito output in bit 7
    BMI     LBD70			; branch if comparitor output is high
	
    SUBB    ,S			; subtract half the current trial difference
    BRA     LBD72			; branch ahead

LBD70
    ADDB    ,S			; add half the current trial difference
LBD72
    LSRA				; shift it right once
    CMPA    #$01			; have all the shifts been done?
    BNE     LBD62			; no go get next bit
        
    LSRB				; move data from top 6 bits of B
    LSRB				; to bottom 6 bits of B
    CMPB    -1,X			; is this value equal to last try?
    BEQ     LBD81			; yes, go save the value
        
	DEC     1,S			; else decrement the retry counter
    BNE     LBD5F			; branch if we havn't tried 10 times
	
; if you get here you have failed to read the same value twice after 10 times.
; as a result we just fall through and use the last read value
	
LBD81
    STB     ,X			; save the digitized value
    LEAX    1, X
    LDB     2,S			; get the current joystick axis number
    DECB				; decrement
    BPL     LBD59			; loop if still have axies to read

    LDX #TEMPJOYSTICK
    LDB <PORT
    LSLB
    LDA B,X

    CMPA #24
    BEQ JOYSTICKUP
    BLT JOYSTICKUP
    CMPA #40
    BEQ JOYSTICKDOWN
    BGT JOYSTICKDOWN
    JMP JOYSTICKHZ

JOYSTICKUP
    LDA <DIRECTION
    ORA #$01
    STA <DIRECTION
    JMP JOYSTICKHZ

JOYSTICKDOWN
    LDA <DIRECTION
    ORA #$02
    STA <DIRECTION
    JMP JOYSTICKHZ

JOYSTICKHZ
    INCB
    LDA B,X
    CMPA #40
    BEQ JOYSTICKRIGHT
    BGT JOYSTICKRIGHT
    CMPA #24
    BEQ JOYSTICKLEFT
    BLT JOYSTICKLEFT
    JMP JOYSTICKDONE

JOYSTICKLEFT
    LDA <DIRECTION
    ORA #$04
    STA <DIRECTION
    JMP JOYSTICKDONE

JOYSTICKRIGHT
    LDA <DIRECTION
    ORA #$08
    STA <DIRECTION
    JMP JOYSTICKDONE

JOYSTICKDONE
    LEAS    3,S
    PULS D
    STA $FF01
    STB $FF03

    LDA <DIRECTION

    RTS

JOYY
    JSR JOYSTICK
    LDX #TEMPJOYSTICK
    LDB <PORT
    LSLB
    LDA B,X
    RTS

JOYX
    JSR JOYSTICK
    LDX #TEMPJOYSTICK
    LDB <PORT
    LSLB
    INCB
    LDA B,X
    RTS

JOYSTICKREAD0
    LDA #0
    STA <PORT
    JSR JOYSTICK
    RTS

JOYSTICKREAD1
    LDA #1
    STA <PORT
    JSR JOYSTICK
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

WAITFIRE0
    JSR JOYSTICKREAD0
    ANDA #$20
    BEQ WAITFIRE0
    RTS

WAITFIREA
    CMPA #0
    BEQ WAITFIRE0

WAITFIRE1
    JSR JOYSTICKREAD1
    ANDA #$20
    BEQ WAITFIRE1
    RTS

WAITFIRE
    JSR JOYSTICKREAD0
    ANDA #$20
    STA MATHPTR0
    JSR JOYSTICKREAD1
    ANDA #$20
    ORA MATHPTR0
    BEQ WAITFIRE
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

; IRQ service routine

JOYSTICKMANAGER

    ; Save registers

    PSHS D
    PSHS U
    PSHS X

    ; Read JOY(0)

    JSR JOYSTICKREAD0
@IF joystickConfig.values
    JSR JOYSTICKTSB    
@ENDIF
    LDA <DIRECTION
    STA JOYSTICK0

    ; Read JOY(1)

    JSR JOYSTICKREAD1
@IF joystickConfig.values
    JSR JOYSTICKTSB    
@ENDIF
    LDA <DIRECTION
    STA JOYSTICK1

    ; Restore registers

    PULS X
    PULS U
    PULS D

    RTS

WAITFIRE0
    LDA JOYSTICK0
    ANDA #$20
    BEQ WAITFIRE0
    RTS

WAITFIREA
    CMPA #0
    BEQ WAITFIRE0

WAITFIRE1
    LDA JOYSTICK1
    ANDA #$20
    BEQ WAITFIRE1
    RTS

WAITFIRE
    LDA JOYSTICK0
    ANDA #$20
    STA MATHPTR0
    LDA JOYSTICK1
    ANDA #$20
    ORA MATHPTR0
    BEQ WAITFIRE
    RTS
    
@ENDIF
