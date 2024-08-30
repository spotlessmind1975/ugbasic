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
;*                        DOJO PROTOCOL ON COMMODORE 64                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJO_CMD_PING           = $00         ; PING
DOJO_CMD_LOGIN          = $01         ; LOGIN username password
DOJO_CMD_CREATE_PORT    = $02         ; CREATE PORT application sessionId
DOJO_CMD_DESTROY_PORT   = $03         ; DESTROY PORT portId
DOJO_CMD_FIND_PORT      = $04         ; FIND PORT username application sessionId
DOJO_CMD_PUT_MESSAGE    = $05         ; PUT MESSAGE message portId
DOJO_CMD_PEEK_MESSAGE   = $06         ; PEEK MESSAGE portId
DOJO_CMD_GET_MESSAGE    = $07         ; GET MESSAGE portId

DOJOCURRENTID:          .BYTE $0          ; Current packet ID

DOJOHELLOSTRING:        .BYTE "****9910"

DOJOINITARGS:           .BYTE 08, 00

DOJOHANDSHAKE:          .BYTE "atdtdojo.ugbasic.iwashere.eu:50666",13
DOJOHANDSHAKEE:

DOJOCHARACTERP:         .BYTE $00
DOJOCHARACTERV:         .BYTE $FF

DOJOCURRENTKAPTR:       .BYTE $0, $0
DOJOCURRENTKAPTR2:      .BYTE $0, $0

; ============================================================================
; SERIAL I/O PRIMITIVES
; ============================================================================

MODEM_TYPE = MODEM_TYPE_SWIFTLINK_DE
BAUD_RATE = 1

RIBUF: .RES 256
REVTABUP: .RES 128


CIA1TALO	    = $DC04
CIA1TAHI	    = $DC05
CIA1TBLO	    = $DC06
CIA1TBHI	    = $DC07
CIA1SDR         = $DC0C
CIA1ICR         = $DC0D
CIA1CRA         = $DC0E
CIA1CRB         = $DC0F
CIA2PA		= $DD00
CIA2PB		= $DD01
CIA2DDRB	= $DD03
CIA2TBLO	= $DD06
CIA2TBHI	= $DD07
CIA2SDR         = $DD0C
CIA2ICR         = $DD0D
CIA2CRB         = $DD0F

STATUS	= $90
RIDBE   = $029B
RIDBS   = $029C
RODBS   = $029D
RODBE   = $029E
ENABL	= $02A1
RTAIL	= RIDBE
RHEAD	= RIDBS
RFREE	= RODBS

JIFFIES	= $A2	; TIME+2

MODEM_TYPE_USERPORT	= 0
MODEM_TYPE_UP9600	= 1
MODEM_TYPE_SWIFTLINK_DE	= 2
MODEM_TYPE_SWIFTLINK_DF	= 3
MODEM_TYPE_SWIFTLINK_D7	= 4

BAUD_300	= 0
BAUD_1200	= 1
BAUD_2400	= 2
BAUD_4800	= 3
BAUD_9600	= 4
BAUD_19200	= 5
BAUD_38400	= 6

STOPSW	= 1
STARTSW	= 0

SWIFT	= $DE00
SW_DATA	= SWIFT
SW_STAT	= SWIFT+1
SW_CMD	= SWIFT+2
SW_CTRL	= SWIFT+3
SW_BAUD	= SWIFT+7

SW_FUNCS:
	.WORD SW_SETUP
	.WORD SW_ENABLE
	.WORD SW_DISABLE
	.WORD SW_GETXFER
	.WORD SW_PUTXFER
	.WORD SW_DROPDTR

NMISW:
	PHA
	TXA
	PHA
	TYA
	PHA
SM1:
    LDA SW_STAT
	AND #%00001000	; MASK OUT ALL BUT RECEIVE INTERRUPT REG
	BNE SM2		; GET OUTTA HERE IF INTERRUPTS ARE DISABLED (DISK ACCESS ETC)
	SEC		; SET CARRY UPON RETURN
	BCS RECCH1
SM2:	LDA SW_CMD
	ORA #%00000010	; DISABLE RECEIVE INTERRUPTS
SM3:	STA SW_CMD
SM4:	LDA SW_DATA
	LDX RTAIL
	STA RIBUF,X
	INC RTAIL
	INC RFREE
	LDA RFREE
	CMP #200	; CHECK BYTE COUNT AGAINST TOLERANCE
	BCC :+		; IS IT OVER THE TOP?
	LDX #STOPSW
	STX PAUSED	; X=1 FOR STOP, BY THE WAY
	JSR FLOW
:
SM5:	LDA SW_CMD
	AND #%11111101	; RE-ENABLE RECEIVE INTERRUPT
SM6:	STA SW_CMD
	CLC
RECCH1:	PLA
	TAY
	PLA
	TAX
	PLA
	JMP NMISVCRS232

;----------------------------------------------------------------------
FLOW:
SM7:	LDA SW_CMD
	AND #%11110011
	CPX #STOPSW
	BEQ :+
	ORA #%00001000
:
SM8:	STA SW_CMD
	RTS

;----------------------------------------------------------------------
SWWAIT:
SM9:	LDA SW_CMD
	ORA #%00001000	; ENABLE TRANSMITTER
SM10:	STA SW_CMD
SM11:	LDA SW_STAT
	AND #%00110000
	BEQ SWWAIT
	RTS

;----------------------------------------------------------------------
SW_DISABLE:
SM12:	LDA SW_CMD
	ORA #%00000010	; DISABLE RECEIVE INTERRUPT
SM13:	STA SW_CMD
	RTS

;----------------------------------------------------------------------
SW_ENABLE:
SM14:	LDA SW_CMD
	AND #%11111101	; ENABLE RECEIVE INTERRUPT
SM15:	STA SW_CMD
	RTS

;----------------------------------------------------------------------
; A: MODEM_TYPE
; X: BAUD_RATE
SW_SETUP:
; SET SWIFTLINK ADDRESS BY MODIFYING ALL ACCESS CODE
	CMP #MODEM_TYPE_SWIFTLINK_DE
	BEQ LBL_DE
	CMP #MODEM_TYPE_SWIFTLINK_DF
	BEQ LBL_DF
	LDA #$D7	; ELSE MODEM_TYPE_SWIFTLINK_D7
	BNE LBL_CONT
LBL_DE:	LDA #$DE
	BNE LBL_CONT
LBL_DF:	LDA #$DF
LBL_CONT:	STA SM1+2
	STA SM2+2
	STA SM3+2
	STA SM4+2
	STA SM5+2
	STA SM6+2
	STA SM7+2
	STA SM8+2
	STA SM9+2
	STA SM10+2
	STA SM11+2
	STA SM12+2
	STA SM13+2
	STA SM14+2
	STA SM15+2
	STA SM16+2
	STA SM17+2
	STA SM18+2
	STA SM19+2
	STA SM20+2
	STA SM21+2
	STA SM22+2
	STA SM23+2
	STA SM24+2
	STA SM25+2

	SEI
;             .------------------------- PARITY CONTROL,
;             :.------------------------ BITS 5-7
;             ::.----------------------- 000 = NO PARITY
;             :::
;             :::.------------------- ECHO MODE, 0 = NORMAL (NO ECHO)
;             ::::
;             ::::.----------- TRANSMIT INTERRUPT CONTROL, BITS 2-3
;             :::::.---------- 10 = XMIT INTERRUPT OFF, RTS LOW
;             ::::::
;             ::::::.------ RECEIVE INTERRUPT CONTROL, 0 = ENABLED
;             :::::::
;             :::::::.--- DTR CONTROL, 1=DTR LOW
	LDA #%00001001
SM16:	STA SW_CMD
;             .------------------------- 0 = ONE STOP BIT
;             :
;             :.-------------------- WORD LENGTH, BITS 6-7
;             ::.------------------- 00 = EIGHT-BIT WORD
;             :::
;             :::.------------- CLOCK SOURCE, 1 = INTERNAL GENERATOR
;             ::::
;             ::::.----- BAUD
;             :::::.---- RATE
;             ::::::.--- BITS   ;1010 == 4800 BAUD, CHANGES LATER
;             :::::::.-- 0-3
	LDA #%00010000
SM17:	STA SW_CTRL

SM18:	LDA SW_CTRL
	AND #$F0
	ORA SWBAUD,X	; BAUD_RATE
SM19:	STA SW_CTRL

	LDA #<NMISW
	LDX #>NMISW
	STA $0318 ; NMINV
	STX $0319

	CLI
	RTS

;----------------------------------------------------------------------
SW_PUTXFER:
	PHA
SM20:	LDA SW_CMD
	STA RS232TEMP
	JSR SWWAIT
	PLA
	PHA
SM21:	STA SW_DATA
	JSR SWWAIT
RS232TEMP=*+1
	LDA #0		; RESTORE RTS STATE
SM22:	STA SW_CMD
	PLA
	CLC
	RTS

;----------------------------------------------------------------------
; HANG UP
SW_DROPDTR:
SM23:	LDA SW_CMD
	AND #%11111110
SM24:	STA SW_CMD
	LDX #226
	STX JIFFIES
:	BIT JIFFIES
	BMI :-
	ORA #%00000001
SM25:	STA SW_CMD
	RTS

;----------------------------------------------------------------------
; GET BYTE FROM SERIAL INTERFACE
SW_GETXFER:
	LDX RHEAD
	CPX RTAIL
	BEQ LBL_1		; SKIP (EMPTY BUFFER, RETURN WITH CARRY SET)
	LDA RIBUF,X
	PHA
	INC RHEAD
	DEC RFREE
	LDX PAUSED	; ARE WE STOPPED?
	BEQ :+		; NO, DON'T BOTHER
	LDA RFREE	; CHECK BUFFER FREE
	CMP #50		; AGAINST RESTART LIMIT
	BCS :+		; IS IT LARGER THAN 50?
	LDX #STARTSW	; IF NO, THEN DON'T START YET
	STX PAUSED
	JSR FLOW
:	CLC
	PLA
LBL_1:	RTS

;----------------------------------------------------------------------
PAUSED:
	.BYTE 0

;----------------------------------------------------------------------
; MOS 6551 ACIA BAUD RATE CONSTANTS
SW_BAUD_50	= %10001
SW_BAUD_75	= %10010
SW_BAUD_109_92	= %10011
SW_BAUD_134_58	= %10100
SW_BAUD_150	= %10101
SW_BAUD_300	= %10110
SW_BAUD_600	= %10111
SW_BAUD_1200	= %11000
SW_BAUD_1800	= %11001
SW_BAUD_2400	= %11010
SW_BAUD_3600	= %11011
SW_BAUD_4800	= %11100
SW_BAUD_7200	= %11101
SW_BAUD_9600	= %11110
SW_BAUD_19200	= %11111

SWBAUD:
; THE SWIFTLINK/TURBO232 BAUD RATE GENERATOR IS 2X THAT OF THE SPEC,
; SO THE ACIA HAS HALF THE RATES SET UP.
	.BYTE SW_BAUD_150	; 300
	.BYTE SW_BAUD_600	; 1200
	.BYTE SW_BAUD_1200	; 2400
	.BYTE SW_BAUD_2400	; 2400
	.BYTE SW_BAUD_4800	; 4800
	.BYTE SW_BAUD_9600	; 9600
	.BYTE SW_BAUD_19200	; 38400

	.BYTE $10,$10,$10	; [XXX UNUSED]

; CCGMS TERMINAL
;
; COPYRIGHT (C) 2016,2022, CRAIG SMITH, ALWYZ, MICHAEL STEIL. ALL RIGHTS RESERVED.
; THIS PROJECT IS LICENSED UNDER THE BSD 3-CLAUSE LICENSE.
;
; RS232 UP9600 DRIVER
;  BASED ON SOURCE FROM "THE UP9600 EMAIL", NOV 23 1997 BY DANIEL DALLMANN
;  MESSAGE-ID: <199711301621.RAA01078LBL_DOSBUSTER.HOME.DD>
;

OLDIRQ	= $EA31
OLDNMI	= $FE47

; ZERO PAGE
SNDTIM  = $A7   ; REUSE RANGE $A7-$AB,
RCVTIM  = $A9   ; WHICH IS USED BY THE
OUTSTAT	= $AB	; KERNAL RS-232 DRIVER

RTS_MIN	= 50	; BUFFER LOW MARK, WILL ENABLE REQUEST TO SEND
RTS_MAX	= 200	; BUFFER HIGH MARK, WILL DISABLE REQUEST TO SEND

; CIA ICR
ICR_TA	= %00000001
ICR_TB	= %00000010
ICR_SP	= %00001000
ICR_FLG	= %00010000
ICR_IR	= %10000000
; CIA CR
CR_START= %00000001
CR_PBON	= %00000010
CR_LOAD	= %00010000
CR_SPOUT= %01000000
CR_TOD	= %10000000

;----------------------------------------------------------------------
UP9600_FUNCS:
	.WORD UP9600_SETUP
	.WORD UP9600_ENABLE
	.WORD UP9600_DISABLE
	.WORD UP9600_GETXFER
	.WORD UP9600_PUTXFER
	.WORD UP9600_DROPDTR

;----------------------------------------------------------------------
UP9600_NMI:
	BIT CIA2ICR	; NMI CAUSED BY CIA#2?
NMI_BMI=*+1
	BMI NMI_STARTBIT; YES (POINTER TO TARGET WILL BE OVERWRITTEN!)
	JMP NMISVCRS232	; OTHERWISE TRIGGERED BY RESTORE KEY -> IGNORE

; NMI TRIGGERED BY START BIT (FLAG TRANSITION FROM 1 TO 0)
NMI_STARTBIT:
	PHA

	; LOAD AND START TIMER B (WHICH IS IN CONTINUOUS MODE) AND
	; OUTPUT A PULSE TO PB7 ON EVERY UNDERFLOW
	; (THE UP9600 HARDWARE WIRES THE PB7 OUTPUT TO THE CNT2 INPUT,
	; SO TIMER B WILL CLOCK THE SDR!)
	LDA #CR_LOAD|CR_PBON|CR_START
	STA CIA2CRB

	; DISABLE TIMER AND FLAG NMIS, LEAVE SDR NMI ON
	.ASSERT ICR_FLG|ICR_TB|ICR_TA = CR_LOAD|CR_PBON|CR_START, ERROR
	STA CIA2ICR	; (ONE BITMASK USED FOR TWO PURPOSES!)

	; SWITCH TO OTHER HANDLER ON NEXT NMI (TRIGGERED BY SDR FULL)
	LDA #NMI_BYTRDY-NMI_BMI-1
	STA NMI_BMI

	PLA
	JMP NMISVCRS232

; NMI TRIGGERED BY SDR FULL
NMI_BYTRDY:
	PHA
	TXA
	PHA

	; SET UP CIA#2 TO TIGGER NMI ON NEXT START BIT
	LDA #CR_TOD|CR_LOAD|CR_PBON
	STA CIA2CRB	; STOP TIMER B, SIGNAL AT PB7
	.ASSERT ICR_IR|ICR_FLG|ICR_TB = CR_TOD|CR_LOAD|CR_PBON, ERROR
			; (USE ONE BITMASK FOR TWO PURPOSES)
	STA CIA2ICR	; ENABLE FLAG INTERRUPT (AND UNUSED TIMER B)

	; SWITCH TO OTHER HANDLER ON NEXT NMI (TRIGGERED BY START BIT)
	LDA #NMI_STARTBIT-NMI_BMI-1
	STA NMI_BMI

	; READ DATA BYTE AND REVERSE BIT ORDER
	LDA CIA2SDR	; READ DATA BYTE FROM SDR (BIT ORDER IS REVERSED)
	CMP #$80	; MOVE BIT 7 INTO C
	AND #$7F
	TAX
	LDA REVTABUP,X	; REVERSE BITS 1-7 USING LOOKUP TABLE
	ADC #0		; MOVE ORIGINAL BIT 7 INTO BIT 0

	; WRITE DATA BYTE INTO RECEIVE BUFFER
	LDX RTAIL
	STA RIBUF,X
	INX
	STX RTAIL

	; DISABLE REQUEST TO SEND (RTS) IF BUFFER ALMOST FULL
	SEC
	TXA
	SBC RHEAD
	CMP #RTS_MAX
	BCC :+
	LDA CIA2PB
	AND #<~2	; DISABLE REQUEST TO SEND (RTS)
	STA CIA2PB
:
	PLA
	TAX
	PLA
	JMP NMISVCRS232

;----------------------------------------------------------------------
; A: MODEM_TYPE
; X: BAUD_RATE
; Y: IS_PAL_SYSTEM
UP9600_SETUP:
	STY IS_PAL_SYSTEM
	JSR UP9600_SETBAUD

; GENERATE LOOKUP TABLE
	LDX #0
LBL_1X:	STX OUTSTAT	; (REUSE OUTSTAT AS RS232TEMP)
	LDY #8
LBL_2:	ASL OUTSTAT
	ROR
	DEY
	BNE LBL_2
	STA REVTABUP,X
	INX
	BPL LBL_1X

; RUN INTO UP9600_ENABLE

;----------------------------------------------------------------------
; ENABLE SERIAL INTERFACE (IRQ+NMI)
UP9600_ENABLE:
	SEI

	LDX #<NEW_IRQ	; INSTALL NEW IRQ HANDLER
	LDY #>NEW_IRQ
	STX $0314
	STY $0315

	LDA #NMI_STARTBIT-NMI_BMI-1
	STA NMI_BMI
	LDX #<UP9600_NMI; INSTALL NEW NMI HANDLER
	LDY #>UP9600_NMI
	STX $0318
	STY $0319

	; MOVE KERNAL'S 60 HZ TIMER INTERRUPT TO TIMER B
IS_PAL_SYSTEM = *+1
	LDX #0
	LDA ILOTAB,X
	STA CIA1TBLO
	LDA IHITAB,X
	STA CIA1TBHI

	; SET CIA#1 TIMER A START VALUE: 1/(2*BAUDRATE)
	LDA RCVTIM
	STA CIA1TALO
	LDA RCVTIM+1
	STA CIA1TAHI

	; SET CIA#2 TIMER B START VALUE: 1/BAUDRATE
	LDA SNDTIM
	STA CIA2TBLO
	LDA SNDTIM+1
	STA CIA2TBHI

	; START TIMER A OF CIA#1, SP1 USED AS OUTPUT
	; GENERATES THE SENDER'S BIT CLOCK
	LDA #CR_SPOUT|CR_START
	STA CIA1CRA

	LDA #1
	STA OUTSTAT

	.ASSERT ICR_TA = 1, ERROR
	STA CIA1ICR	; DISABLE TIMER A (CIA#1) INTERRUPT

	.ASSERT CR_START = 1, ERROR
	STA CIA1CRB	; START TIMER B OF CIA#1 (GENERATES KEYSCAN IRQ)

	LDA #CR_TOD|CR_LOAD|CR_PBON; STOP TIMER B OF CIA#2 (ENABLE SIGNAL AT PB7)
	STA CIA2CRB

	; CIA#2: ENABLE FLAG (START BIT) AND SDR (BYTE RECEIVED) NMIS
	LDA #ICR_IR|ICR_FLG|ICR_SP
	BIT CIA2ICR	; CLEAR PENDING NMIS
	STA CIA2ICR

	; CIA#1: ENABLE TIMER B (60 HZ) AND SDR (8 BITS SENT) IRQS
	LDA #%10001010
	STA CIA1ICR

	LDA #%11111111
	STA CIA2PB	; PB0-7 DEFAULT TO 1
	STA CIA1SDR	; SP1 DEFAULTS TO 1

	LDA #2		; ENABLE REQUEST TO SEND (RTS)
	STA CIA2DDRB	; (THE RTS LINE IS THE ONLY OUTPUT)

	CLI
	RTS

;----------------------------------------------------------------------
; NEW IRQ HANDLER
NEW_IRQ:
	LDA CIA1ICR	; READ IRQ MASK
	LSR
	LSR		; MOVE BIT 1 INTO C (TIMER B)
	AND #2		; TEST BIT 3 (SDR)
	BEQ LBL_NSDR	; NO

; SDR IRQ: COUNT DOWN EXPECTED SDR IRQ COUNTER
	LDX OUTSTAT
	BEQ :+		; SKIP, IF WE'RE NOT WAITING FOR AN EMPTY SDR
	DEX
	STX OUTSTAT
:

	BCC LBL_NOTIM	; SKIP IF THERE WAS NO TIMER B UNDERFLOW

LBL_NSDR:	CLI		; [XXX ALLOW NESTED IRQS???]
			; [XXX LABEL SHOULD BE AT BCC OR BCC SHOULD BE REMOVED]
			; [XXX THERE IS NO OTHER SOURCE SET UP, SO THE BCC]
			; [XXX WOULD NEVER BE TAKEN ANYWAY]
	JSR $FFEA	; UPDATE JIFFY CLOCK
	JSR $EA87	; SCAN KEYBOARD

LBL_NOTIM:	JMP $EA81

;----------------------------------------------------------------------
CLOCK_PAL	= 4433619 * 4 / 18	;   985,249 HZ
CLOCK_NTSC	= 3579545 * 4 / 14	; 1,022,727 HZ
TIMER_FREQ	= 60
ITIMER_NTSC	= (CLOCK_NTSC * 10 / TIMER_FREQ + 5) / 10	; $4295
ITIMER_PAL	= (CLOCK_PAL * 10 / TIMER_FREQ + 5) / 10	; $4025

.DEFINE ITAB ITIMER_NTSC, ITIMER_PAL
ILOTAB:	.LOBYTES ITAB
IHITAB:	.HIBYTES ITAB

;----------------------------------------------------------------------
MIN_BAUD	= 300
TIMER_PAL	= CLOCK_PAL / MIN_BAUD
TIMER_NTSC	= CLOCK_NTSC / MIN_BAUD

UP9600_SETBAUD:
; X: BAUD_RATE
; Y: IS_PAL_SYSTEM
; [XXX TECHNICALLY, THE TIMER VALUES NEED TO BE 1 LESS]
	TXA
	PHA		; BAUD_RATE

	LDA #<TIMER_NTSC
	LDX #>TIMER_NTSC
	CPY #0		; IS_PAL_SYSTEM
	BEQ :+
	LDA #<TIMER_PAL
	LDX #>TIMER_PAL
:	STA SNDTIM
	STX SNDTIM+1

	PLA		; BAUD_RATE
	TAX		; 0=300, 1=1200, 2=2400 ETC.
	BEQ :+
	INX		; -> 0=300, 2=1200, 3=2400 ETC.
:	TXA
	BEQ LBL_SKIP3
LBL_LOOP:	LSR SNDTIM+1	; DIVIDE BY 2 REPEATEDLY
	ROR SNDTIM
	DEX
	BNE LBL_LOOP
LBL_SKIP3:	LDA SNDTIM+1
	LSR
	STA RCVTIM+1
	LDA SNDTIM
	ROR
	STA RCVTIM
	RTS

;----------------------------------------------------------------------
; GET BYTE FROM SERIAL INTERFACE
UP9600_GETXFER:
	LDX RHEAD
	CPX RTAIL
	BEQ LBL_SKIP2	; EMPTY BUFFER, RETURN WITH CARRY SET
	LDA RIBUF,X
	INX
	STX RHEAD

	; IF BUFFER IS RUNNING LOW, ENABLE REQUEST TO SEND (RTS)
	PHA
	TXA
	SEC
	SBC RTAIL
	CMP #RTS_MIN
	BCC :+
	LDA #2
	ORA CIA2PB
	STA CIA2PB
:  	CLC
	PLA

LBL_SKIP2:	RTS

;----------------------------------------------------------------------
UP9600_PUTXFER:
	STX SAVE_X
	PHA

	; REVERSE BIT ORDER (PART 1)
	CMP #$80	; MOVE BIT 7 INTO C
	AND #$7F
	TAX		; (CONTINUE LATER...)

	; WAIT FOR PREVIOUS TRANSMISSION TO FINISH (WITH TIMEOUT)
	CLI
	LDA #$100-3	; 50 MS TIMEOUT
	STA JIFFIES
:	LDA OUTSTAT
	BEQ :+
	BIT JIFFIES
	BMI :-
:

	; SET TXD TO 1 (STOP BIT)
	LDA #%00000100
	ORA CIA2PA
	STA CIA2PA

	; CHECK DATA TERMINAL READY (DTR) AND CLEAR TO SEND (CTS)
:	LDA CIA2PB
	AND #%01000100	; CTS AND DTR
	EOR #%00000100
	BEQ :-		; LOOP WHILE CTR=0 AND DTR=1

	; REVERSE BIT ORDER (PART 2)
	LDA REVTABUP,X	; REVERSE BITS 1-7 USING LOOKUP TABLE
	ADC #0		; ADD BIT0

	; SEND FIRST BYTE
	LSR		; START BIT (0) INTO MSB, 7 DATA BITS
	STA CIA1SDR	; SEND THROUGH SDR

	LDA #2		; EXPECT 2 SDR IRQS PER DATA BYTE SENT
	STA OUTSTAT

	; SEND SECOND BYTE
	ROR		; BIT 0 INTO MSB
	ORA #$7F	; FILL WITH 7 STOP BITS (1)
	STA CIA1SDR	; SEND THROUGH SDR

	CLC
SAVE_X=*+1
	LDX #0
	PLA
	RTS

;----------------------------------------------------------------------
; DISABLE SERIAL INTERFACE
UP9600_DISABLE:
	SEI
	LDA #%01111111
	STA CIA2ICR	; DISABLE ALL CIA#2 NMIS
	STA CIA1ICR	; DISABLE ALL CIA#1 IRQS
	LDA #$41	; QUICK (AND DIRTY) HACK TO SWITCH BACK
	STA CIA1TAHI	; TO THE DEFAULT CIA#1 CONFIGURATION [XXX USE REAL NUMBERS]
	LDA #ICR_IR|ICR_TA
	STA CIA1ICR	; ENABLE TIMER A (THIS IS DEFAULT)

	; RESTORE ORIGINAL NMI HANDLER
	LDA #<OLDNMI
	STA $0318
	LDA #>OLDNMI
	STA $0319
	; RESTORE ORIGINAL IRQ HANDLER
	LDA #<OLDIRQ
	STA $0314
	LDA #>OLDIRQ
	STA $0315
	CLI
	RTS

;----------------------------------------------------------------------
; HANG UP
UP9600_DROPDTR:
	LDA #%00000100
	STA CIA2DDRB
	LDA #%00000010
	STA CIA2PB
	LDX #$100-30	; 1/2 SEC
	STX JIFFIES
:	BIT JIFFIES
	BMI :-
	LDA #%00000010
	STA CIA2DDRB
	RTS

; CCGMS TERMINAL
;
; COPYRIGHT (C) 2016,2022, CRAIG SMITH, ALWYZ, MICHAEL STEIL. ALL RIGHTS RESERVED.
; THIS PROJECT IS LICENSED UNDER THE BSD 3-CLAUSE LICENSE.
;
; RS232 USERPORT DRIVER, 300-2400 BAUD
;  BASED ON NOVATERM 9.6
;

; ZERO PAGE: THIS REUSES THE KERNAL'S RS232 LOCATIONS
INBITS	= $A8	; BITCI: BIT COUNTER DURING RS232 INPUT
INBYTE	= $AA	; RIDATA: BYTE BUFFER DURING RS232 INPUT
OUTBITS	= $B4	; BITTS: BIT COUNTER AND STOP BIT SWITCH DURING RS232 OUTPUT
OUTBIT	= $B5	; NXTBIT: BIT BUFFER (IN BIT #2) DURING RS232 OUTPUT
OUTBYTE	= $B6	; RODATA: BYTE BUFFER DURING RS232 OUTPUT

; FUNCTION TABLE FOR DISPATCHER

;----------------------------------------------------------------------
RSUSER_FUNCS:
	.WORD RSUSER_SETUP
	.WORD RSUSER_ENABLE
	.WORD RSUSER_DISABLE
	.WORD RSUSER_GETXFER
	.WORD RSUSER_PUTXFER
	.WORD RSUSER_DROPDTR

;----------------------------------------------------------------------
RSUSER_SETUP:
	SEI

	JSR RSUSER_SETBAUD

	LDA #<NMI64
	LDY #>NMI64
	STA $0318 ; NMINV
	STY $0319

	CLI
	RTS

;----------------------------------------------------------------------
BDLOC:
BNTSC:	.WORD 3408,851,425	; NTSC: TRANSMIT TIMES
	.WORD 4915,1090,459	; NTSC: STARTUP BIT TIMES
	.WORD 3410,845,421	; NTSC: FULL BIT TIMES
BPAL:	.WORD 3283,820,409	; PAL:  TRANSMIT TIMES
	.WORD 4735,1050,442	; PAL:  STARTUP BIT TIMES
	.WORD 3285,814,406	; PAL:  FULL BIT TIMES
OFFSET		= BPAL-BNTSC

;----------------------------------------------------------------------
ISBYTE:
	.BYTE 0
LASTRING:		; [XXX UNUSED]
	.BYTE 0

;----------------------------------------------------------------------
; GET BYTE FROM SERIAL INTERFACE
RSUSER_GETXFER:
	JSR $F04F	; KERNAL CODE TO SET UP USER PORT
	LDX RHEAD
	CPX RTAIL
	BEQ :+		; SKIP (EMPTY BUFFER, RETURN WITH CARRY SET)
	LDA RIBUF,X
	PHA
	INC RHEAD
	CLC
	PLA
:	RTS

;----------------------------------------------------------------------
; NEW NMI HANDLER
NMI64:
	PHA
	TXA
	PHA
	TYA
	PHA
	CLD
	LDX $DD07	; SAMPLE TIMER B HI BYTE
	LDA #$7F	; DISABLE CIA NMI'S
	STA $DD0D
	LDA $DD0D	; READ/CLEAR FLAGS
	;BPL NOTCIA	; (RESTORE KEY)
	CPX $DD07	; TIMER B TIMEOUT?
	LDY $DD01	; SAMPLE PIN C FOR RECEIVE NMI
	BCS :+		; NO TIMEOUT
	ORA #$02	; SET FLAG
	ORA $DD0D	; READ FLAGS AGAIN (CHANGED SINCE TIMEOUT)
:	AND ENABL	; MASK OUT NON-ENABLED INTERRUPTS
	TAX		; BITMASK OF INTS TO BE SERVICED
	LSR		; CHECK TIMER A
	BCC :+
	LDA $DD00	; PUT OUTPUT BIT ON PIN M
	AND #$FB
	ORA OUTBIT
	STA $DD00
:	TXA		; CHECK FLAG NMI
	AND #$10	; INDICATES NEW BYTE COMING IN
	BEQ NMION
STRTLO=*+1
	LDA #0		; INITIALIZE TIMER B WITH START BIT TIME
	STA $DD06
STRTHI=*+1
	LDA #0
	STA $DD07
	LDA #$11
	STA $DD0F	; START TIMER B, LOAD LATCHED VALUE TO COUNTER
	LDA #$12
	EOR ENABL
	STA ENABL
	STA $DD0D	; ENABLE FLAG, TIMER B INTERRUPTS
FULLLO=*+1
	LDA #0		; LATCH FULL BIT VALUE FOR NEXT COUNTDOWN
	STA $DD06
FULLHI=*+1
	LDA #0
	STA $DD07
	LDA #8
	STA INBITS
	JMP CHKTXD

;NOTCIA	LDY #0
;	JMP RSTKEY	; OR JMP NOREST

NMION:	LDA ENABL	; RECEIVE A BIT
	STA $DD0D
	TXA
	AND #$02
	BEQ CHKTXD
	TYA
	LSR
	ROR INBYTE
	DEC INBITS
	BNE TXD
	LDA INBYTE
	LDX RTAIL	; INDEX TO BUFFER
	STA RIBUF,X	; AND STORE IT
	INC RTAIL	; MOVE INDEX TO NEXT SLOT
	LDA #0
	STA $DD0F
	LDA #$12
SWITCH:	LDY #$7F
	STY $DD0D
	STY $DD0D
	EOR ENABL
	STA ENABL
	STA $DD0D
TXD:	TXA
	LSR
CHKTXD:	BCC LBL_NMIFLOW
	DEC OUTBITS
	BMI LBL_ENDBYTE
	LDA #4
	ROR OUTBYTE
	BCS :+
	LDA #0
:	STA OUTBIT
LBL_NMIFLOW:
	LDA INBITS
	AND #8
	BEQ :+
	CLC
:	PLA
	TAY
	PLA
	TAX
	PLA
	JMP NMISVCRS232

LBL_ENDBYTE:
	LDA #0
	STA ISBYTE
	LDX #0		;  TURN TRANSMIT INT OFF
	STX $DD0E
	LDA #1
	BNE SWITCH
	JMP RSUSER_DISABLE

;----------------------------------------------------------------------
RSUSER_PUTXFER:
	PHA
	STX SAVE_X2
	STY SAVE_Y2
	STA OUTBYTE
	LDA #0
	STA OUTBIT
	LDA #9
	STA OUTBITS
	LDA #$FF
	STA ISBYTE
XMITLO=*+1
	LDA #0
	STA $DD04
XMITHI=*+1
	LDA #0
	STA $DD05
	LDA #$11
	STA $DD0E
	LDA #$81
	JSR CHANGE
	CLC
SAVE_X2=*+1
	LDX #0
SAVE_Y2=*+1
	LDY #0
	PLA
	RTS

;----------------------------------------------------------------------
; DISABLE RS232 INPUT
RSUSER_DISABLE:
	PHA
:
;	LDA ENABL;THIS FUCKS SHIT UP... GET RID OF IT...
;	AND #$03
;	BNE :-
	LDA ISBYTE
	BNE :-
	LDA #$10
	STA $DD0D
	LDA #2
	AND ENABL
	BNE :-
	STA ENABL
	PLA
	RTS

;----------------------------------------------------------------------
; ENABLE RS232 INPUT
RSUSER_ENABLE:
	LDA ENABL
	AND #$12
	BEQ :+
	RTS
:	STA $DD0F
	LDA #$90
CHANGE:
	STA $DD0D
	PHP
	SEI
	LDY #$7F
	STY $DD0D
	STY $DD0D
	ORA ENABL
	STA ENABL
	STA $DD0D
	PLP
:	BIT ISBYTE
	BMI :-
	RTS

;----------------------------------------------------------------------
; X: BAUD_RATE
; Y: IS_PAL_SYSTEM
RSUSER_SETBAUD:
	TXA		; BAUD_RATE
	ASL
	CPY #0		; IS_PAL_SYSTEM
	BEQ :+
	CLC
	ADC #OFFSET
:	TAY
	LDA BDLOC,Y
	STA XMITLO
	LDA BDLOC+1,Y
	STA XMITHI
	LDA BDLOC+6,Y
	STA STRTLO
	LDA BDLOC+7,Y
	STA STRTHI
	LDA BDLOC+12,Y
	STA FULLLO
	LDA BDLOC+13,Y
	STA FULLHI
	RTS

;----------------------------------------------------------------------
; HANG UP
RSUSER_DROPDTR:
	LDA #%00000100
	STA $DD03
	LDA #0
	STA CIA2PB
	LDX #$100-30
	STX JIFFIES
:	BIT JIFFIES
	BMI :-
	LDA #4
	STA CIA2PB
	RTS

; CCGMS TERMINAL
;
; COPYRIGHT (C) 2016,2022, CRAIG SMITH, ALWYZ, MICHAEL STEIL. ALL RIGHTS RESERVED.
; THIS PROJECT IS LICENSED UNDER THE BSD 3-CLAUSE LICENSE.
;
; RS232 DRIVER DISPATCH
;

TMPZP		= $A7	; REUSED KERNAL RS-232 DRIVER VAR
RAM_FLAG	= $F9	; REUSED KERNAL RS-232 DRIVER VAR

;----------------------------------------------------------------------
; DISPATCH: INIT MODEM
RS232_INIT:
	JSR SETUP_RAM_IRQ_NMI

	LDX #MODEM_TYPE_SWIFTLINK_DE
	LDA #MODEM_TYPE
	CMP #MODEM_TYPE_SWIFTLINK_DE
	BCC :+
	TXA
:	ASL
	TAX
	LDA MODEM_DRIVERS,X
	STA TMPZP
	LDA MODEM_DRIVERS+1,X
	STA TMPZP+1
	LDX #1
	LDY #0
:	LDA (TMPZP),Y
	STA RS232_FUNCS,X
	INY
	INX
	LDA (TMPZP),Y
	STA RS232_FUNCS,X
	INY
	INX
	INX
	CPY #2*6
	BNE :-

	LDA #MODEM_TYPE
	LDX #BAUD_RATE
	LDY IS_PAL_SYSTEM
	JSR FUNC_SETUP
	JMP RS232_CLEAR

RS232_FUNCS:
FUNC_SETUP:
	JMP $FFFF
FUNC_ENABLE:
	JMP $FFFF
FUNC_DISABLE:
	JMP $FFFF
FUNC_GETXFER:
	JMP $FFFF
FUNC_PUTXFER:
	JMP $FFFF
FUNC_DROPDTR:
	JMP $FFFF

	.RES 6*2

MODEM_DRIVERS:
	.WORD RSUSER_FUNCS	; MODEM_TYPE_USERPORT
	.WORD UP9600_FUNCS	; MODEM_TYPE_UP9600
	.WORD SW_FUNCS		; MODEM_TYPE_SWIFTLINK_DE, ...

;----------------------------------------------------------------------
; DISPATCH: ENABLE
RS232_ON:
	PHA
	TXA
	PHA
	TYA
	PHA
	JSR FUNC_ENABLE
	JMP XFEROUT

;----------------------------------------------------------------------
; DISPATCH: DISABLE
RS232_OFF:
	PHA
	TXA
	PHA
	TYA
	PHA
	JSR FUNC_DISABLE
XFEROUT:
	PLA
	TAY
	PLA
	TAX
	PLA
	RTS

;----------------------------------------------------------------------
; DISPATCH: GET BYTE FROM MODEM
RS232_GET:
	JSR FUNC_GETXFER
	PHA
	PHP
	LDA #0
	ROL
	STA STATUS		; SOME CALLERS WANT STATUS SET
	PLP			; OTHERS WANT C SET ON ERROR/NO DATA
	PLA
	RTS

;----------------------------------------------------------------------
; DISPATCH: SEND BYTE TO MODEM
RS232_PUT:
	PHA
	LDA #0
	STA STATUS
	PLA
	JMP FUNC_PUTXFER

;----------------------------------------------------------------------
; DISPATCH: HANG UP
RS232_DROPDTR	= FUNC_DROPDTR

;----------------------------------------------------------------------
; CLEAR RS232 BUFFER
RS232_CLEAR:
	PHA
	LDA #0
	STA RTAIL
	STA RHEAD
	STA RFREE
	PLA
	RTS

;----------------------------------------------------------------------
SETUP_RAM_IRQ_NMI:
	LDA #0
	STA RAM_FLAG
	LDA #<NMISVCCHAINED
	STA $FFFA
	LDA #>NMISVCCHAINED
	STA $FFFB
	LDA #<IRQSVC
	STA $FFFE
	LDA #>IRQSVC
	STA $FFFF
	RTS

NMISVCCHAINED:
	INC $01
	DEC RAM_FLAG
	JMP ($0318)
NMISVCRS232:
	BIT RAM_FLAG
	BPL :+
	INC RAM_FLAG
	DEC $01
:	RTI

; ----------------------------------------------------------------------------
; DOJO READY
; ----------------------------------------------------------------------------
; We call this routine to check if any data is available from DOJO server.
;
; Output:
;           Z  = data is available
;           NZ = data is unavailable
;

DOJOISREADY:
	JSR RS232_GET
	BCC DOJOISREADY1
    LDX #$0
    STX DOJOCHARACTERP
    CPX #$FE
    RTS
DOJOISREADY1:
    LDX #1
    STX DOJOCHARACTERP
    STA DOJOCHARACTERV
    CMP DOJOCHARACTERV
    RTS

; ----------------------------------------------------------------------------
; DOJO READ BYTE
; ----------------------------------------------------------------------------
; We call this routine to read the next byte from DOJO server. If the byte
; is not available, the routine will wait for the available data.
;
; Output:
;           A = data received from DOJO server
;
DOJOREADBYTE:
	LDX DOJOCHARACTERP
	BNE DOJOREADBYTE2
DOJOREADBYTEL1:
    JSR DOJOISREADY
    BNE DOJOREADBYTEL1
DOJOREADBYTE2:
    LDA #0
    STA DOJOCHARACTERP
    LDA DOJOCHARACTERV
    RTS

; ----------------------------------------------------------------------------
; DOJO WRITE BYTE
; ----------------------------------------------------------------------------
; We call this routine to write a byte to DOJO server.
;
; Input:
;           A = data to write to DOJO server
;
DOJOWRITEBYTE:
	JSR RS232_PUT
    RTS

; ============================================================================
; DOJO PROTOCOL
; ============================================================================

; ----------------------------------------------------------------------------
; DOJO WAIT PACKET
; ----------------------------------------------------------------------------
; We call this routine to wait for a packet with the current ID.

DOJOWAITPACKET:

    ; Read the ID of the packet

    JSR DOJOREADBYTE

    ; If the ID is equal to the one awaited for, go ahead.

    CMP DOJOCURRENTID
    BEQ DOJOWAITPACKET0
    JSR DOJOSKIPPACKET

    ; Wait for the next packet.

    JMP DOJOWAITPACKET

DOJOWAITPACKET0:
    RTS

; ----------------------------------------------------------------------------
; DOJO SKIP PACKET
; ----------------------------------------------------------------------------
; We call this routine to skip a packet that has a different ID from the
; one we are waiting for. Note that this routine must be called just after
; read the (wrong) ID.

DOJOSKIPPACKET:

    ; Read the size of the packet to skip.

    JSR DOJOREADBYTE

    ; If size = 0 we can finish the execution.

    CMP #0
    BEQ DOJOSKIPPACKET0

    ; Use the size as a counter.

    TAX

    ; Read "size" bytes from the stream.

DOJOSKIPPACKETL1:
    JSR DOJOREADBYTE
    DEX
    BNE DOJOSKIPPACKETL1

DOJOSKIPPACKET0:
    RTS

; ============================================================================
; ============================================================================
; ============================================================================
; DOJO GAME PROTOCOL
; ============================================================================
; ============================================================================
; ============================================================================

; ----------------------------------------------------------------------------
; DOJO PING
; ----------------------------------------------------------------------------
; We call this routine to check if the server is alive.
;
; Input:
;
; Output:
;           C = server is alive
;          NC = server is gone
;

DOJOPING:

    LDA DOJOHANDSHAKE
    BEQ DOJOPING3

	JSR RS232_INIT
    PHA
    LDA #$37
    STA $01
    PLA
    JSR $FFE7
    PHA
    LDA #$35
    STA $01
    PLA
	JSR RS232_OFF
    JSR RS232_ON

    LDX #0
    LDY #(DOJOHANDSHAKEE-DOJOHANDSHAKE)

DOJOPING2:
    LDA DOJOHANDSHAKE, X
    JSR DOJOWRITEBYTE
    INX
    DEY
    BNE DOJOPING2

    LDA #0
    STA DOJOHANDSHAKE

DOJOPING3:

    LDA #<DOJOHELLOSTRING
    STA TMPPTR
    LDA #>DOJOHELLOSTRING
    STA TMPPTR+1

    LDX #8
    LDY #0

DOJOPINGL3:
    LDA (TMPPTR),Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPINGL3

DOJOPINGL3A:
    JSR DOJOREADBYTE
    CMP #$42
    BNE DOJOPINGL3A

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_PING
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #0
    JSR DOJOWRITEBYTE

    ; Wait response packet

    JSR DOJOWAITPACKET

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish

    CPX #0
    BEQ DOJOPINGN1DE

    ; Read (and skip) any data

DOJOPINGL1:
    JSR DOJOREADBYTE
    DEX
    BNE DOJOPINGL1
    SEC
    RTS

DOJOPINGN1DE:
    SEC
    RTS

; ----------------------------------------------------------------------------
; DOJO LOGIN
; ----------------------------------------------------------------------------
; We call this routine to identify the user. This call will allow to 
; "read"/"write" anything on the shared space of this user.
;
; Input:
;           TMPPTR = username
;           X = size of username
;           TMPPTR2 = password
;           Y = size of password
;
; Output:
;           DOJOCURRENTKAPTR = the unique key access (8 bytes)
;

DOJOLOGIN:

    PHA

    STX MATHPTR0
    TYA
    CLC
    ADC MATHPTR0
    STA MATHPTR0
    INC MATHPTR0

    PLA

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_LOGIN
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send username, letter by letter

    TYA 
    PHA

    LDY #0

DOJOLOGINL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOLOGINL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    ; Send password, letter by letter

    PLA
    TAX
    LDY #0

DOJOLOGINL2:
    
    LDA (TMPPTR2), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOLOGINL2

    ; Retrieve the response.

DOJOLOGINL3:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOLOGINN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOLOGINN1DE

    ; Read the session ID (8 bytes)

    LDA DOJOCURRENTKAPTR
    STA TMPPTR
    LDA DOJOCURRENTKAPTR+1
    STA TMPPTR+1

    LDY #0

DOJOLOGINN1L1:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOLOGINN1L1

    RTS

DOJOLOGINN1DE:
    RTS

; ----------------------------------------------------------------------------
; DOJO SUCCESS
; ----------------------------------------------------------------------------
; We call this routine to check if the session id / port id is valid.
;
; Input:
;           TMPPTR = session id / port id
;
; Output:
;           C = is valid
;          NC = is not valid
;

DOJOSUCCESS:

    LDX #8
    LDY #0

    ; Send username, letter by letter

DOJOSUCCESSL1:
    
    LDA (TMPPTR), Y
    BNE DOJOSUCCESSL1Y
    INY
    DEX
    BNE DOJOSUCCESSL1
    CLC
    RTS

DOJOSUCCESSL1Y:
    SEC
    RTS

; ----------------------------------------------------------------------------
; DOJO CREATE PORT
; ----------------------------------------------------------------------------
; We call this routine to create a port for receiving messages from other
; applications.
;
; Input:
;           TMPPTR = application name
;           X = size of application name
;           TMPPTR2 = session id (8 bytes)
;
; Output:
;           DOJOCURRENTKAPTR = address where to put the port id (8 bytes)
;

DOJOCREATEPORT:

    STX MATHPTR0
    LDA MATHPTR0
    CLC
    ADC #9
    STA MATHPTR0

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_CREATE_PORT
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send application name, letter by letter

    LDY #0    

DOJOCREATEPORTL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOCREATEPORTL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    LDA DOJOCURRENTKAPTR
    STA TMPPTR
    LDA DOJOCURRENTKAPTR+1
    STA TMPPTR+1

    LDX #8

    ; Send session id, letter by letter

    LDY #0

DOJOCREATEPORTL2:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOCREATEPORTL2

    ; Retrieve the response.

DOJOCREATEPORTL3:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOCREATEPORTN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOCREATEPORTN1DE

    ; Read the port ID (8 bytes)

    LDY #0

DOJOCREATEPORTN1L1:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOCREATEPORTN1L1

    RTS

DOJOCREATEPORTN1DE:
    RTS

; ----------------------------------------------------------------------------
; DOJO DESTROY PORT
; ----------------------------------------------------------------------------
; We call this routine to destroy an existent port.
;
; Input:
;           TMPPTR = port id
;
; Output:
;           C = port destroyed
;           NC = unexistent port
;

DOJODESTROYPORT:
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_DESTROY_PORT
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #8
    JSR DOJOWRITEBYTE

    ; Send sessionId, letter by letter

    LDX #8
    LDY #0

DOJODESTROYPORTL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJODESTROYPORTL1

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJODESTROYPORTN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJODESTROYPORTN1DE

    ; Read the returned byte.

    JSR DOJOREADBYTE
    CMP #0
    BEQ DOJODESTROYPORTN1DE

DOJODESTROYPORTN1L1:
    SEC
    RTS

DOJODESTROYPORTN1DE:
    CLC
    RTS

; ----------------------------------------------------------------------------
; DOJO FIND PORT
; ----------------------------------------------------------------------------
; We call this routine to find out a port for sending messages to other
; applications.
;
; Input:
;           TMPPTR = address to username
;           X = size of username
;           TMPPTR2 = address to application
;           Y = size of application
;           DOJOCURRENTPTR = address of session id (8 bytes)
;
; Output:
;           DOJOCURRENTPTR2 = address of (public) port id (8 bytes)
;

DOJOFINDPORT:

    STX MATHPTR0
    TYA
    CLC
    ADC MATHPTR0
    STA MATHPTR0
    LDA #10
    ADC MATHPTR0
    STA MATHPTR0

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_FIND_PORT
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send username name, letter by letter

    TYA
    PHA

    LDY #0
DOJOFINDPORTL1:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOFINDPORTL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    PLA
    TAX

    ; Send application name, letter by letter

    LDY #0
DOJOFINDPORTL2:
    LDA (TMPPTR2), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOFINDPORTL2

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    LDA DOJOCURRENTKAPTR
    STA TMPPTR
    LDA DOJOCURRENTKAPTR+1
    STA TMPPTR+1

    LDX #8

    ; Send session id, letter by letter
    LDY #0
DOJOFINDPORTL3:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOFINDPORTL3

    ; Retrieve the response.

DOJOFINDPORTL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOFINDPORTN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOFINDPORTN1DE

    LDA DOJOCURRENTKAPTR2
    STA TMPPTR
    LDA DOJOCURRENTKAPTR2+1
    STA TMPPTR+1
    
    ; Read the (public) port ID (8 bytes)

    LDX #8
    LDY #0

DOJOFINDPORTN1L1:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOFINDPORTN1L1

    RTS

DOJOFINDPORTN1DE:
    RTS

; ----------------------------------------------------------------------------
; DOJO PUT MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to put a message to a port.
;
; Input:
;           TMPPTR = address of message
;           X = size of message
;           TMPPTR2 = address of port id (8 bytes)
;
; Output:
;           C = message send
;          NC = message not sent
;

DOJOPUTMESSAGE:

    STX MATHPTR0
    LDA #9
    CLC
    ADC MATHPTR0
    STA MATHPTR0

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_PUT_MESSAGE
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA MATHPTR0
    JSR DOJOWRITEBYTE

    ; Send message, letter by letter

    LDY #0

DOJOPUTMESSAGEL1:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPUTMESSAGEL1

    ; Send 0 char as separator.

    LDA #0
    JSR DOJOWRITEBYTE

    ; Send port id, letter by letter

    LDX #8
    LDY #0

DOJOPUTMESSAGEL2:
    LDA (TMPPTR2), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPUTMESSAGEL2

    ; Retrieve the response.

DOJOPUTMESSAGEL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOPUTMESSAGEN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOPUTMESSAGEN1DE

    ; Read the status byte

    JSR DOJOREADBYTE
    CMP #0
    BEQ DOJOPUTMESSAGEN1DE

DOJOPUTMESSAGEN1L1:
    SEC
    RTS

DOJOPUTMESSAGEN1DE:
    CLC
    RTS

; ----------------------------------------------------------------------------
; DOJO PEEK MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to peek the presence (and size of) next message
; that can be took using DOJO GET MESSAGE.
;
; Input:
;           TMPPTR = address of port id (8 bytes)
;
; Output:
;           X = size of message (if C = 1)
;           C = message present
;          NC = message absent

DOJOPEEKMESSAGE:
    
    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_PEEK_MESSAGE
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #8
    JSR DOJOWRITEBYTE

    LDX #8

    ; Send port id, letter by letter

DOJOPEEKMESSAGEL1:
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOPEEKMESSAGEL1

    ; Retrieve the response.

DOJOPEEKMESSAGEL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOPEEKMESSAGEN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE
    TAX

    ; If the packet has size = 0, we finish with an error.

    CPX #0
    BEQ DOJOPEEKMESSAGEN1DE

    ; Read the message size byte

    JSR DOJOREADBYTE
    TAX
    CPX #0
    BEQ DOJOPEEKMESSAGEN1DE

DOJOPEEKMESSAGEN1L1:
    SEC
    RTS

DOJOPEEKMESSAGEN1DE:
    CLC
    RTS

; ----------------------------------------------------------------------------
; DOJO GET MESSAGE
; ----------------------------------------------------------------------------
; We call this routine to get the next message. It imply call DOJO PEEK 
; MESSAGE. 
;
; Input:
;           TMPPTR = address of port id (8 bytes)
;
; Output:
;           X = dynamic string index
;           C = message present
;          NC = message absent

DOJOGETMESSAGE:
    
    JSR DOJOPEEKMESSAGE
    BCC DOJOGETMESSAGEN1DE

    ; Send ID

    INC DOJOCURRENTID
    LDA DOJOCURRENTID
    JSR DOJOWRITEBYTE

    ; Send CMD

    LDA #DOJO_CMD_GET_MESSAGE
    JSR DOJOWRITEBYTE

    ; Send LEN

    LDA #8
    JSR DOJOWRITEBYTE

    ; Send message, letter by letter

    LDX #8
    LDY #0

DOJOGETMESSAGEL1:
    
    LDA (TMPPTR), Y
    JSR DOJOWRITEBYTE
    INY
    DEX
    BNE DOJOGETMESSAGEL1

    ; Retrieve the response.

DOJOGETMESSAGEL4:

    ; Wait response packet

    JSR DOJOWAITPACKET

DOJOGETMESSAGEN1:

    ; Retrieve the SIZE

    JSR DOJOREADBYTE

    ; If the packet has size = 0, we finish with an error.

    CMP #0
    BEQ DOJOGETMESSAGEN1DE

    ; Allocate a dynamic string big enough
    ; to store the incoming message.

    STA DSSIZE
    JSR DSALLOC

    ; Retrieve the address of the dynamic
    ; string space and use it as final
    ; storage space.

    JSR DSDESCRIPTOR
    LDA DSADDRLO
    STA TMPPTR2
    LDA DSADDRHI
    STA TMPPTR2+1

    TXA
    PHA

    ; Read the message size byte

    LDX DSSIZE
    LDY #0

DOJOGETMESSAGEL2:
    JSR DOJOREADBYTE
    STA (TMPPTR), Y
    INY
    DEX
    BNE DOJOGETMESSAGEL2
DOJOGETMESSAGEN1L1:

    PLA
    TAX

    SEC
    RTS

DOJOGETMESSAGEN1DE:
    LDA #0
    STA DSSIZE
    JSR DSALLOC
    CLC
    RTS

