; CCGMS Terminal
;
; Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
; This project is licensed under the BSD 3-Clause License.
;
; RS232 SwiftLink/Turbo232 (MOS 6551 ACIA) Driver
;  based on Jeff Brown adaptation of Novaterm version
;

.include "rs232_kernal.inc"
.include "rs232.inc"		; for MODEM_TYPE_*
.import ribuf			; external
.import rs232_rti

; function table for dispatcher
.export sw_funcs

stopsw	= 1
startsw	= 0

; SwiftLink registers
swift	= $de00		; will be runtime-patched to $DE00/$DF00/$D700
sw_data	= swift
sw_stat	= swift+1
sw_cmd	= swift+2
sw_ctrl	= swift+3
sw_baud	= swift+7

.segment "RS232"

;----------------------------------------------------------------------
sw_funcs:
	.word sw_setup
	.word sw_enable
	.word sw_disable
	.word sw_getxfer
	.word sw_putxfer
	.word sw_dropdtr

;----------------------------------------------------------------------
; new NMI handler
nmisw:
	pha
	txa
	pha
	tya
	pha
sm1:	lda sw_stat
	and #%00001000	; mask out all but receive interrupt reg
	bne sm2		; get outta here if interrupts are disabled (disk access etc)
	sec		; set carry upon return
	bcs recch1
sm2:	lda sw_cmd
	ora #%00000010	; disable receive interrupts
sm3:	sta sw_cmd
sm4:	lda sw_data
	ldx rtail
	sta ribuf,x
	inc rtail
	inc rfree
	lda rfree
	cmp #200	; check byte count against tolerance
	bcc :+		; is it over the top?
	ldx #stopsw
	stx paused	; x=1 for stop, by the way
	jsr flow
:
sm5:	lda sw_cmd
	and #%11111101	; re-enable receive interrupt
sm6:	sta sw_cmd
	clc
recch1:	pla
	tay
	pla
	tax
	pla
	jmp rs232_rti

;----------------------------------------------------------------------
flow:
sm7:	lda sw_cmd
	and #%11110011
	cpx #stopsw
	beq :+
	ora #%00001000
:
sm8:	sta sw_cmd
	rts

;----------------------------------------------------------------------
swwait:
sm9:	lda sw_cmd
	ora #%00001000	; enable transmitter
sm10:	sta sw_cmd
sm11:	lda sw_stat
	and #%00110000
	beq swwait
	rts

;----------------------------------------------------------------------
sw_disable:
sm12:	lda sw_cmd
	ora #%00000010	; disable receive interrupt
sm13:	sta sw_cmd
	rts

;----------------------------------------------------------------------
sw_enable:
sm14:	lda sw_cmd
	and #%11111101	; enable receive interrupt
sm15:	sta sw_cmd
	rts

;----------------------------------------------------------------------
; A: modem_type
; X: baud_rate
sw_setup:
; set SwiftLink address by modifying all access code
	cmp #MODEM_TYPE_SWIFTLINK_DE
	beq @de
	cmp #MODEM_TYPE_SWIFTLINK_DF
	beq @df
	lda #$d7	; else MODEM_TYPE_SWIFTLINK_D7
	bne @cont
@de:	lda #$de
	bne @cont
@df:	lda #$df
@cont:	sta sm1+2
	sta sm2+2
	sta sm3+2
	sta sm4+2
	sta sm5+2
	sta sm6+2
	sta sm7+2
	sta sm8+2
	sta sm9+2
	sta sm10+2
	sta sm11+2
	sta sm12+2
	sta sm13+2
	sta sm14+2
	sta sm15+2
	sta sm16+2
	sta sm17+2
	sta sm18+2
	sta sm19+2
	sta sm20+2
	sta sm21+2
	sta sm22+2
	sta sm23+2
	sta sm24+2
	sta sm25+2

	sei
;             .------------------------- parity control,
;             :.------------------------ bits 5-7
;             ::.----------------------- 000 = no parity
;             :::
;             :::.------------------- echo mode, 0 = normal (no echo)
;             ::::
;             ::::.----------- transmit interrupt control, bits 2-3
;             :::::.---------- 10 = xmit interrupt off, RTS low
;             ::::::
;             ::::::.------ receive interrupt control, 0 = enabled
;             :::::::
;             :::::::.--- DTR control, 1=DTR low
	lda #%00001001
sm16:	sta sw_cmd
;             .------------------------- 0 = one stop bit
;             :
;             :.-------------------- word length, bits 6-7
;             ::.------------------- 00 = eight-bit word
;             :::
;             :::.------------- clock source, 1 = internal generator
;             ::::
;             ::::.----- baud
;             :::::.---- rate
;             ::::::.--- bits   ;1010 == 4800 baud, changes later
;             :::::::.-- 0-3
	lda #%00010000
sm17:	sta sw_ctrl

sm18:	lda sw_ctrl
	and #$f0
	ora swbaud,x	; baud_rate
sm19:	sta sw_ctrl

	lda #<nmisw
	ldx #>nmisw
	sta $0318 ; NMINV
	stx $0319

	cli
	rts

;----------------------------------------------------------------------
sw_putxfer:
	pha
sm20:	lda sw_cmd
	sta temp
	jsr swwait
	pla
	pha
sm21:	sta sw_data
	jsr swwait
temp=*+1
	lda #0		; restore rts state
sm22:	sta sw_cmd
	pla
	clc
	rts

;----------------------------------------------------------------------
; Hang up
sw_dropdtr:
sm23:	lda sw_cmd
	and #%11111110
sm24:	sta sw_cmd
	ldx #226
	stx JIFFIES
:	bit JIFFIES
	bmi :-
	ora #%00000001
sm25:	sta sw_cmd
	rts

;----------------------------------------------------------------------
; get byte from serial interface
sw_getxfer:
	ldx rhead
	cpx rtail
	beq @1		; skip (empty buffer, return with carry set)
	lda ribuf,x
	pha
	inc rhead
	dec rfree
	ldx paused	; are we stopped?
	beq :+		; no, don't bother
	lda rfree	; check buffer free
	cmp #50		; against restart limit
	bcs :+		; is it larger than 50?
	ldx #startsw	; if no, then don't start yet
	stx paused
	jsr flow
:	clc
	pla
@1:	rts

;----------------------------------------------------------------------
paused:
	.byte 0

;----------------------------------------------------------------------
; MOS 6551 ACIA baud rate constants
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

swbaud:
; The SwiftLink/Turbo232 baud rate generator is 2x that of the spec,
; so the ACIA has half the rates set up.
	.byte SW_BAUD_150	; 300
	.byte SW_BAUD_600	; 1200
	.byte SW_BAUD_1200	; 2400
	.byte SW_BAUD_2400	; 2400
	.byte SW_BAUD_4800	; 4800
	.byte SW_BAUD_9600	; 9600
	.byte SW_BAUD_19200	; 38400

	.byte $10,$10,$10	; [XXX unused]
