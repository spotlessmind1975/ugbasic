; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                           STARTUP ROUTINE ON C=64                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

JIFFYUPDATE:
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
	RTS

NMISVC:
    PHA
    LDA $DC0D
    PLA
    RTI

IRQSVC:
    JSR JIFFYUPDATE
    JSR MUSICPLAYER
    JMP ($0314)    

IRQSVC2:
    PHA
    LDA $DC0D
    PLA
    RTI

C64STARTUP:

C64STARTUPW0:  
    LDA $D012
C64STARTUPW1:
    CMP $D012
    BEQ C64STARTUPW1
    BMI C64STARTUPW0
    AND #$03

    CMP #$03
    BNE C64NTSC

C64PAL:
    LDA #50
    STA TICKSPERSECOND
    JMP C64STARTUPDONE

C64NTSC:
    LDA #60
    STA TICKSPERSECOND
    JMP C64STARTUPDONE    

C64STARTUPDONE:

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

SYSCALLDONE:
    PHA
    LDA #$35
    STA $01
    PLA
    CLI
    
    RTS
SYSCALL:
    SEI
    PHA
    LDA #$37
    STA $01
    PLA
SYSCALL0:
    JSR $0000
    JMP SYSCALLDONE

SAVEPAGE0:
    LDA #$00
    STA $FE
    LDA #$02
    STA $FF
    LDA #$00
    STA $FC
    LDA #$00
    STA $FD
    LDY #0
SAVEPAGE0Y:
    LDA ($FC), Y
    STA ($FE), Y
    INY
    BNE SAVEPAGE0Y
    RTS

RESTOREPAGE0:
    LDA #$00
    STA $FE
    LDA #$00
    STA $FF
    LDA #$00
    STA $FC
    LDA #$02
    STA $FD
    LDY #0
RESTOREPAGE0Y:
    LDA ($FC), Y
    STA ($FE), Y
    INY
    BNE RESTOREPAGE0Y
    RTS

