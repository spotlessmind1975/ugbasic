; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                           STARTUP ROUTINE ON C=64 + REU                     *
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
    LDA $DC0D
    PLA
    RTI

IRQSVC:
@IF deployed.msprites
MSPRITESMANAGERADDRESS:
    JSR MSPRITESMANAGER
@ENDIF
    JSR JIFFYUPDATE
@IF deployed.music
    JSR MUSICPLAYER
@ENDIF
@IF deployed.sidstartup
    JSR SIDMANAGER
@ENDIF
@IF deployed.joystick
    JSR JOYSTICKMANAGER
@ENDIF
@IF deployed.keyboard
    JSR KEYBOARDMANAGER
@ENDIF
@IF deployed.timer
    JSR TIMERMANAGER
@ENDIF
    JMP ($0314)    

IRQSVC2:
    PHA
    LDA $DC0D
    PLA
    RTI

C64REUSTARTUP:

C64REUSTARTUPW0:  
    LDA $D012
C64REUSTARTUPW1:
    CMP $D012
    BEQ C64REUSTARTUPW1
    BMI C64REUSTARTUPW0
    AND #$03

    CMP #$03
    BNE C64REUNTSC

C64REUPAL:
    LDA #50
    STA TICKSPERSECOND
    JMP C64REUSTARTUPDONE

C64REUNTSC:
    LDA #60
    STA TICKSPERSECOND
    JMP C64REUSTARTUPDONE    

C64REUSTARTUPDONE:

    SEI

    JSR SAVESYSTEMIRQVECTORS

    PHA
    LDA #$37
    STA $01
    PLA

    JSR RESTORESYSTEMIRQVECTORS

    LDA #$BF
    STA REUCONTROL
    LDA #<C64REUBANKTMPBUF
    STA REUC64BASE
    LDA #>C64REUBANKTMPBUF
    STA REUC64BASE+1
    LDA #1
    STA REUTRANSLEN
    LDA #0
    STA REUTRANSLEN+1

@IF ( outputFileType == D64 )
    JSR C64REUBANKSLOAD
@ENDIF

    LDA #0
    STA REUCONTROL
    LDA #0
    STA REUC64BASE
    LDA #0
    STA REUC64BASE+1
    LDA #0
    STA REUREUBASE
    STA REUREUBASE+1
    STA REUREUBASE+2
    LDA #0
    STA REUTRANSLEN
    LDA #0
    STA REUTRANSLEN+1

    PHA
    LDA #$37
    STA $01
    PLA

    LDA #0
    STA KEYBLEN

    SEI

    LDA #<NMISVC
    STA $FFFA
    LDA #>NMISVC
    STA $FFFB

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
    LDA #$7f                    ;CIA interrupt off
    STA $DC0D
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

    PHA
    LDA #$35
    STA $01
    PLA

    JSR SAVEUGBASICIRQVECTORS
    CLI
SYSCALLDONE:
    SEI

    PHA
    LDA #$35
    STA $01
    PLA

    JSR RESTOREUGBASICIRQVECTORS

    CLI

    ; LDA #0
    ; STA $C6
    
    RTS
SYSCALL:
    SEI
    JSR RESTORESYSTEMIRQVECTORS
    PHA
    LDA #$37
    STA $01
    PLA
    CLI
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

C64REUBANKTMPBUF:
    .BYTE   $00

@IF outputFileType == D64

C64REUBANKFILENAME:
    .BYTE   "bank0"

C64REUBANKLOADDEVICE:
    .BYTE   $08

C64REUBANKLOAD:
C64REUBANKLOADREPEAT:

    LDA #5
    LDX #<C64REUBANKFILENAME
    LDY #>C64REUBANKFILENAME
    JSR $FFBD

    LDA #$02
    LDX C64REUBANKLOADDEVICE
C64REUBANKLOAD0:
    LDY #$02
    JSR $FFBA
    JSR $FFC0
errore:
    BCS C64REUBANKLOADERR
    LDX #$02
    JSR $FFC6
    LDY #$00
C64REUBANKLOADL1:    
    JSR $FFB7
    BNE C64REUBANKLOADEOF
    JSR $FFCF
    STA C64REUBANKTMPBUF
    LDA #%10010000
    STA REUCOMMAND    
    JMP C64REUBANKLOADL1
C64REUBANKLOADEOF:
    AND #$02
    CMP #$02
    BEQ C64REUBANKLOADERR
C64REUBANKLOADCLOSE:
    LDA #$02
    JSR $FFC3
    JSR $FFCC
    RTS

C64REUBANKLOADERR:
    PHA
    JSR C64REUBANKLOADCLOSE
    PLA
C64REUBANKLOADNEXTDEVICE:
    LDX C64REUBANKLOADDEVICE
    INX
    STX C64REUBANKLOADDEVICE
    CPX #12
    BEQ C64REUBANKASKDISK
    JMP C64REUBANKLOADREPEAT

C64REUBANKASKDISK:
    JSR $E544
    
    LDX #$01
    LDY #$01
    JSR $E50C

    LDA C64REUBANKFILENAME+4
    STA C64REUBANKASKDISKPROMPT2
    LDA #<C64REUBANKASKDISKPROMPT
    LDY #>C64REUBANKASKDISKPROMPT
    JSR $AB1E

    LDX #$02
    LDY #$01
    JSR $E50C
    LDA #<C64REUBANKASKDISKPROMPT3
    LDY #>C64REUBANKASKDISKPROMPT3
    JSR $AB1E

C64REUBANKASKDISKL1:
    JSR $FFE4
    BEQ C64REUBANKASKDISKL1

    LDX #8
    STX C64REUBANKLOADDEVICE    

    JMP C64REUBANKLOADREPEAT

C64REUBANKASKDISKPROMPT:
    .BYTE "please insert disk with file bank"
C64REUBANKASKDISKPROMPT2:
    .BYTE "0 ",0
C64REUBANKASKDISKPROMPT3:
    .BYTE "and press any key to continue", 0

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
    
