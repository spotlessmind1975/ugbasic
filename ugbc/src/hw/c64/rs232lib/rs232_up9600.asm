; CCGMS Terminal
;
; Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
; This project is licensed under the BSD 3-Clause License.
;
; RS232 UP9600 Driver
;  based on source from "the UP9600 email", Nov 23 1997 by Daniel Dallmann
;  Message-Id: <199711301621.RAA01078@dosbuster.home.dd>
;

.include "rs232_kernal.inc"
.include "c64.inc"		; CIA#1/CIA#2 defines
.import ribuf, revtabup		; external
.import rs232_rti

; function table for dispatcher
.export up9600_funcs

oldirq	= $ea31
oldnmi	= $fe47

; zero page
sndtim  = $a7   ; reuse range $a7-$ab,
rcvtim  = $a9   ; which is used by the
outstat	= $ab	; KERNAL RS-232 driver

RTS_MIN	= 50	; buffer low mark, will enable Request To Send
RTS_MAX	= 200	; buffer high mark, will disable Request To Send

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

.segment "RS232"

;----------------------------------------------------------------------
up9600_funcs:
	.word up9600_setup
	.word up9600_enable
	.word up9600_disable
	.word up9600_getxfer
	.word up9600_putxfer
	.word up9600_dropdtr

;----------------------------------------------------------------------
up9600_nmi:
	bit cia2icr	; NMI caused by CIA#2?
nmi_bmi=*+1
	bmi nmi_startbit; yes (pointer to target will be overwritten!)
	jmp rs232_rti	; otherwise triggered by RESTORE key -> ignore

; NMI triggered by start bit (FLAG transition from 1 to 0)
nmi_startbit:
	pha

	; load and start timer B (which is in continuous mode) and
	; output a pulse to PB7 on every underflow
	; (The UP9600 hardware wires the PB7 output to the CNT2 input,
	; so timer B will clock the SDR!)
	lda #CR_LOAD|CR_PBON|CR_START
	sta cia2crb

	; disable timer and FLAG NMIs, leave SDR NMI on
	.assert ICR_FLG|ICR_TB|ICR_TA = CR_LOAD|CR_PBON|CR_START, error
	sta cia2icr	; (one bitmask used for two purposes!)

	; switch to other handler on next NMI (triggered by SDR full)
	lda #nmi_bytrdy-nmi_bmi-1
	sta nmi_bmi

	pla
	jmp rs232_rti

; NMI triggered by SDR full
nmi_bytrdy:
	pha
	txa
	pha

	; set up CIA#2 to tigger NMI on next start bit
	lda #CR_TOD|CR_LOAD|CR_PBON
	sta cia2crb	; stop timer B, signal at PB7
	.assert ICR_IR|ICR_FLG|ICR_TB = CR_TOD|CR_LOAD|CR_PBON, error
			; (use one bitmask for two purposes)
	sta cia2icr	; enable FLAG interrupt (and unused timer B)

	; switch to other handler on next NMI (triggered by start bit)
	lda #nmi_startbit-nmi_bmi-1
	sta nmi_bmi

	; read data byte and reverse bit order
	lda cia2sdr	; read data byte from SDR (bit order is reversed)
	cmp #$80	; move bit 7 into C
	and #$7f
	tax
	lda revtabup,x	; reverse bits 1-7 using lookup table
	adc #0		; move original bit 7 into bit 0

	; write data byte into receive buffer
	ldx rtail
	sta ribuf,x
	inx
	stx rtail

	; disable Request To Send (RTS) if buffer almost full
	sec
	txa
	sbc rhead
	cmp #RTS_MAX
	bcc :+
	lda cia2pb
	and #<~2	; disable Request To Send (RTS)
	sta cia2pb
:
	pla
	tax
	pla
	jmp rs232_rti

;----------------------------------------------------------------------
; A: modem_type
; X: baud_rate
; Y: is_pal_system
up9600_setup:
	sty is_pal_system
	jsr up9600_setbaud

; generate lookup table
	ldx #0
@1:	stx outstat	; (reuse outstat as temp)
	ldy #8
@2:	asl outstat
	ror
	dey
	bne @2
	sta revtabup,x
	inx
	bpl @1

; run into up9600_enable

;----------------------------------------------------------------------
; enable serial interface (IRQ+NMI)
up9600_enable:
	sei

	ldx #<new_irq	; install new IRQ handler
	ldy #>new_irq
	stx $0314
	sty $0315

	lda #nmi_startbit-nmi_bmi-1
	sta nmi_bmi
	ldx #<up9600_nmi; install new NMI handler
	ldy #>up9600_nmi
	stx $0318
	sty $0319

	; move KERNAL's 60 Hz timer interrupt to timer B
is_pal_system = *+1
	ldx #0
	lda ilotab,x
	sta cia1tblo
	lda ihitab,x
	sta cia1tbhi

	; set CIA#1 timer A start value: 1/(2*baudrate)
	lda rcvtim
	sta cia1talo
	lda rcvtim+1
	sta cia1tahi

	; set CIA#2 timer B start value: 1/baudrate
	lda sndtim
	sta cia2tblo
	lda sndtim+1
	sta cia2tbhi

	; start timer A of CIA#1, SP1 used as output
	; generates the sender's bit clock
	lda #CR_SPOUT|CR_START
	sta cia1cra

	lda #1
	sta outstat

	.assert ICR_TA = 1, error
	sta cia1icr	; disable timer A (CIA#1) interrupt

	.assert CR_START = 1, error
	sta cia1crb	; start timer B of CIA#1 (generates keyscan IRQ)

	lda #CR_TOD|CR_LOAD|CR_PBON; stop timer B of CIA#2 (enable signal at PB7)
	sta cia2crb

	; CIA#2: enable FLAG (start bit) and SDR (byte received) NMIs
	lda #ICR_IR|ICR_FLG|ICR_SP
	bit cia2icr	; clear pending NMIs
	sta cia2icr

	; CIA#1: enable timer B (60 Hz) and SDR (8 bits sent) IRQs
	lda #%10001010
	sta cia1icr

	lda #%11111111
	sta cia2pb	; PB0-7 default to 1
	sta cia1sdr	; SP1 defaults to 1

	lda #2		; enable Request To Send (RTS)
	sta cia2ddrb	; (the RTS line is the only output)

	cli
	rts

;----------------------------------------------------------------------
; new IRQ handler
new_irq:
	lda cia1icr	; read IRQ mask
	lsr
	lsr		; move bit 1 into C (timer B)
	and #2		; test bit 3 (SDR)
	beq @nsdr	; no

; SDR IRQ: count down expected SDR IRQ counter
	ldx outstat
	beq :+		; skip, if we're not waiting for an empty SDR
	dex
	stx outstat
:

	bcc @notim	; skip if there was no timer B underflow

@nsdr:	cli		; [XXX allow nested IRQs???]
			; [XXX label should be at bcc OR bcc should be removed]
			; [XXX there is no other source set up, so the bcc]
			; [XXX would never be taken anyway]
	jsr $ffea	; update jiffy clock
	jsr $ea87	; scan keyboard

@notim:	jmp $ea81

;----------------------------------------------------------------------
CLOCK_PAL	= 4433619 * 4 / 18	;   985,249 Hz
CLOCK_NTSC	= 3579545 * 4 / 14	; 1,022,727 Hz
TIMER_FREQ	= 60
ITIMER_NTSC	= (CLOCK_NTSC * 10 / TIMER_FREQ + 5) / 10	; $4295
ITIMER_PAL	= (CLOCK_PAL * 10 / TIMER_FREQ + 5) / 10	; $4025

.define itab ITIMER_NTSC, ITIMER_PAL
ilotab:	.lobytes itab
ihitab:	.hibytes itab

;----------------------------------------------------------------------
MIN_BAUD	= 300
TIMER_PAL	= CLOCK_PAL / MIN_BAUD
TIMER_NTSC	= CLOCK_NTSC / MIN_BAUD

up9600_setbaud:
; X: baud_rate
; Y: is_pal_system
; [XXX technically, the timer values need to be 1 less]
	txa
	pha		; baud_rate

	lda #<TIMER_NTSC
	ldx #>TIMER_NTSC
	cpy #0		; is_pal_system
	beq :+
	lda #<TIMER_PAL
	ldx #>TIMER_PAL
:	sta sndtim
	stx sndtim+1

	pla		; baud_rate
	tax		; 0=300, 1=1200, 2=2400 etc.
	beq :+
	inx		; -> 0=300, 2=1200, 3=2400 etc.
:	txa
	beq @skip
@loop:	lsr sndtim+1	; divide by 2 repeatedly
	ror sndtim
	dex
	bne @loop
@skip:	lda sndtim+1
	lsr
	sta rcvtim+1
	lda sndtim
	ror
	sta rcvtim
	rts

;----------------------------------------------------------------------
; get byte from serial interface
up9600_getxfer:
	ldx rhead
	cpx rtail
	beq @skip	; empty buffer, return with carry set
	lda ribuf,x
	inx
	stx rhead

	; if buffer is running low, enable Request To Send (RTS)
	pha
	txa
	sec
	sbc rtail
	cmp #RTS_MIN
	bcc :+
	lda #2
	ora cia2pb
	sta cia2pb
:  	clc
	pla

@skip:	rts

;----------------------------------------------------------------------
up9600_putxfer:
	stx save_x
	pha

	; reverse bit order (part 1)
	cmp #$80	; move bit 7 into C
	and #$7f
	tax		; (continue later...)

	; wait for previous transmission to finish (with timeout)
	cli
	lda #$100-3	; 50 ms timeout
	sta JIFFIES
:	lda outstat
	beq :+
	bit JIFFIES
	bmi :-
:

	; set TXD to 1 (stop bit)
	lda #%00000100
	ora cia2pa
	sta cia2pa

	; check Data Terminal Ready (DTR) and Clear To Send (CTS)
:	lda cia2pb
	and #%01000100	; CTS and DTR
	eor #%00000100
	beq :-		; loop while CTR=0 and DTR=1

	; reverse bit order (part 2)
	lda revtabup,x	; reverse bits 1-7 using lookup table
	adc #0		; add bit0

	; send first byte
	lsr		; start bit (0) into MSB, 7 data bits
	sta cia1sdr	; send through SDR

	lda #2		; expect 2 SDR IRQs per data byte sent
	sta outstat

	; send second byte
	ror		; bit 0 into MSB
	ora #$7f	; fill with 7 stop bits (1)
	sta cia1sdr	; send through SDR

	clc
save_x=*+1
	ldx #0
	pla
	rts

;----------------------------------------------------------------------
; disable serial interface
up9600_disable:
	sei
	lda #%01111111
	sta cia2icr	; disable all CIA#2 NMIs
	sta cia1icr	; disable all CIA#1 IRQs
	lda #$41	; quick (and dirty) hack to switch back
	sta cia1tahi	; to the default CIA#1 configuration [XXX use real numbers]
	lda #ICR_IR|ICR_TA
	sta cia1icr	; enable timer A (this is default)

	; restore original NMI handler
	lda #<oldnmi
	sta $0318
	lda #>oldnmi
	sta $0319
	; restore original IRQ handler
	lda #<oldirq
	sta $0314
	lda #>oldirq
	sta $0315
	cli
	rts

;----------------------------------------------------------------------
; Hang up
up9600_dropdtr:
	lda #%00000100
	sta cia2ddrb
	lda #%00000010
	sta cia2pb
	ldx #$100-30	; 1/2 sec
	stx JIFFIES
:	bit JIFFIES
	bmi :-
	lda #%00000010
	sta cia2ddrb
	rts
