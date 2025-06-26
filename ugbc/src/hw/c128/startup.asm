; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                           STARTUP ROUTINE ON C=128                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


JIFFYUPDATE:
    PHP
    PHA
    TXA
    PHA
	LDX	#$00			; clear X
	INC	$A2		; increment the jiffy clock low byte
	BNE	JIFFYNORO		; if no rollover ??

	INC	$A1		; increment the jiffy clock mid byte
	BNE	JIFFYNORO		; branch if no rollover

	INC	$A0		; increment the jiffy clock high byte

					; now subtract a days worth of jiffies from current count
					; and remember only the Cb result
JIFFYNORO:
	SEC				; set carry for subtract
	LDA	$A2		; get the jiffy clock low byte
	SBC	#$01			; subtract $4F1A01 low byte
	LDA	$A1		; get the jiffy clock mid byte
	SBC	#$1A			; subtract $4F1A01 mid byte
	LDA	$A0		; get the jiffy clock high byte
	SBC	#$4F			; subtract $4F1A01 high byte
	BCC	JIFFYDAY		; if less than $4F1A01 jiffies skip the clock reset

					; else ..
	STX	$A0		; clear the jiffy clock high byte
	STX	$A1		; clear the jiffy clock mid byte
	STX	$A2		; clear the jiffy clock low byte
					; this is wrong, there are $4F1A00 jiffies in a day so
					; the reset to zero should occur when the value reaches
					; $4F1A00 and not $4F1A01. this would give an extra jiffy
					; every day and a possible TI value of 24:00:00
JIFFYDAY:
    PLA
    TAX
    PLA
    PLP
	RTS

NMISVC:
    PHA
    LDA #$1
    STA $D019
    PLA
    RTI

IRQSVC:
    PHA
@IF deployed.msprites
    LDA $D019
    AND #1
    BEQ IRQSVCX 
    STA $D019
MSPRITESMANAGERADDRESS:
    JSR MSPRITESMANAGER

@IF deployed.joystick && !joystickConfig.sync
    JSR JOYSTICKMANAGER
@ENDIF
@IF deployed.keyboard
    JSR KEYBOARDMANAGER
@ENDIF

@ELSE
    LDA #1
    STA $D019

@IF deployed.joystick && !joystickConfig.sync
    JSR JOYSTICKMANAGER
@ENDIF
@IF deployed.keyboard
    JSR KEYBOARDMANAGER
@ENDIF

@ENDIF
    LDA $DC0D

@IF deployed.msprites

IRQSVCXX:
    PLA
    RTI

IRQSVCX:
    LDA $DC0D

@ENDIF

    JSR JIFFYUPDATE
@IF deployed.music
    JSR MUSICPLAYER
@ENDIF
@IF deployed.sidplayer
    JSR SIDPLAYER
@ENDIF
@IF deployed.sidstartup
    JSR SIDMANAGER
@ENDIF
@IF deployed.fade
    JSR FADET
@ENDIF
@IF deployed.timer
    JSR TIMERMANAGER
@ENDIF
    PLA
    JMP ($0314)    
    
IRQSVC2:
    RTI

C128STARTUP:

    LDA $0A03
    CMP #$0
    BEQ C128NTSC

C128PAL:
    LDA #50
    STA TICKSPERSECOND
    JMP C128STARTUPDONE

C128NTSC:
    LDA #60
    STA TICKSPERSECOND
    JMP C128STARTUPDONE    

C128STARTUPDONE:

    SEI

@IF sysCallUsed
    JSR SAVESYSTEMIRQVECTORS
@ENDIF

    LDA #<NMISVC
    STA $FFFA
    LDA #>NMISVC
    STA $FFFB

    JSR TIMERAINIT

    LDA #<IRQSVC
    STA $FFFE
    LDA #>IRQSVC
    STA $FFFF

    LDA #<IRQSVC2
    STA $0314
    LDA #>IRQSVC2
    STA $0315

@IF deployed.msprites

    ; msprites
    ; LDA #$7f                    ;CIA interrupt off
    ; STA $DC0D
    LDA #$01                    ;Raster interrupt on
    STA $D01A
    LDA #$30
    STA $D011
    LDA #IRQ1LINE               ;Line where next IRQ happens
    STA $D012
    LDA $DC0D
    
@ENDIF

@IF dataSegment
    LDA #<DATAFIRSTSEGMENT
    STA DATAPTR
    LDA #>DATAFIRSTSEGMENT
    STA DATAPTR+1
    LDY #0
    STY DATAPTRY
@ENDIF

@IF sysCallUsed

    JSR SAVEUGBASICIRQVECTORS
    CLI
SYSCALLDONE:
    SEI
    JSR RESTOREUGBASICIRQVECTORS

@ENDIF

    PHA
    ; ; DISABLE BASIC ROM & KERNAL ROM
    LDA #%00111110
    STA $FF00
    PLA
    ; LDA $FF06
    ; AND #$FC
    ; ORA #$03
    ; AND #$F3
    ; ORA #$04
    ; STA $FF06

    CLI

    RTS

@IF sysCallUsed

SYSCALL:
    SEI
    JSR RESTORESYSTEMIRQVECTORS
    CLI
    PHA
    LDA #$0
    STA $FF00
    PLA
SYSCALL0:
    JSR $0000
    JMP SYSCALLDONE

SAVESYSTEMIRQVECTORS:
    PHA
    LDA $FFFA
    STA NMISVC_SYSTEM
    LDA $FFFB
    STA NMISVC_SYSTEM+1

    LDA $FFFE
    STA IRQSVC_SYSTEM
    LDA $FFFF
    STA IRQSVC_SYSTEM+1

    LDA $0314
    STA IRQSVC2_SYSTEM
    LDA $0315
    STA IRQSVC2_SYSTEM+1
    PLA
    RTS

SAVEUGBASICIRQVECTORS:
    PHA

    LDA $D018
    STA OLDD018

    LDA $FFFA
    STA NMISVC_UGBASIC
    LDA $FFFB
    STA NMISVC_UGBASIC+1

    LDA $FFFE
    STA IRQSVC_UGBASIC
    LDA $FFFF
    STA IRQSVC_UGBASIC+1

    LDA $0314
    STA IRQSVC2_UGBASIC
    LDA $0315
    STA IRQSVC2_UGBASIC+1
    PLA
    RTS

RESTORESYSTEMIRQVECTORS:
    PHA
    LDA NMISVC_SYSTEM
    STA $FFFA
    LDA NMISVC_SYSTEM+1
    STA $FFFB

    LDA IRQSVC_SYSTEM
    STA $FFFE
    LDA IRQSVC_SYSTEM+1
    STA $FFFF

    LDA IRQSVC2_SYSTEM
    STA $0314
    LDA IRQSVC2_SYSTEM+1
    STA $0315
    PLA
    RTS

RESTOREUGBASICIRQVECTORS:
    PHA

    LDA OLDD018
    STA $D018

    LDA NMISVC_UGBASIC
    STA $FFFA
    LDA NMISVC_UGBASIC+1
    STA $FFFB

    LDA IRQSVC_UGBASIC
    STA $FFFE
    LDA IRQSVC_UGBASIC+1
    STA $FFFF

    LDA IRQSVC2_UGBASIC
    STA $0314
    LDA IRQSVC2_UGBASIC+1
    STA $0315
    PLA
    RTS

@ENDIF

WAITTIMER:
    LDA $A2
WAITTIMERL1:
    CMP $A2
    BEQ WAITTIMERL1
    DEX
    CPX #$FF
    BNE WAITTIMER
    DEY
    CPY #$FF
    BNE WAITTIMER
    RTS

TIMERAINIT:

TIMERAINITL1:
    LDA $D011
    CMP #$80
    BMI TIMERAINITL1
TIMERAINITL21:
    LDA $D012
    CMP #$24
    BCC TIMERAINITL21

    LDA #$81
    STA $DC0D

    LDA #$c7
    STA $dc04
    LDA #$4c
    STA $dc05

    LDA #%00010001
    STA $DC0E
    LDA #0
    STA $DC0F
    
    RTS
