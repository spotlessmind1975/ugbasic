; CCGMS Terminal
;
; Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
; This project is licensed under the BSD 3-Clause License.
;
; RS232 Userport Driver, 300-2400 baud
;  based on Novaterm 9.6
;

.include "rs232_kernal.inc"
.include "c64.inc"		; CIA#1/CIA#2 defines
.import ribuf			; external
.import rs232_rti

; zero page: this reuses the KERNAL's RS232 locations
inbits	= $a8	; BITCI: Bit counter during RS232 input
inbyte	= $aa	; RIDATA: Byte buffer during RS232 input
outbits	= $b4	; BITTS: Bit counter and stop bit switch during RS232 output
outbit	= $b5	; NXTBIT: Bit buffer (in bit #2) during RS232 output
outbyte	= $b6	; RODATA: Byte buffer during RS232 output

; function table for dispatcher
.export rsuser_funcs

.segment "RS232"

;----------------------------------------------------------------------
rsuser_funcs:
	.word rsuser_setup
	.word rsuser_enable
	.word rsuser_disable
	.word rsuser_getxfer
	.word rsuser_putxfer
	.word rsuser_dropdtr

;----------------------------------------------------------------------
rsuser_setup:
	sei

	jsr rsuser_setbaud

	lda #<nmi64
	ldy #>nmi64
	sta $0318 ; NMINV
	sty $0319

	cli
	rts

;----------------------------------------------------------------------
bdloc:
bntsc:	.word 3408,851,425	; NTSC: transmit times
	.word 4915,1090,459	; NTSC: startup bit times
	.word 3410,845,421	; NTSC: full bit times
bpal:	.word 3283,820,409	; PAL:  transmit times
	.word 4735,1050,442	; PAL:  startup bit times
	.word 3285,814,406	; PAL:  full bit times
OFFSET		= bpal-bntsc

;----------------------------------------------------------------------
isbyte:
	.byte 0
lastring:		; [XXX unused]
	.byte 0

;----------------------------------------------------------------------
; get byte from serial interface
rsuser_getxfer:
	jsr $f04f	; KERNAL code to set up user port
	ldx rhead
	cpx rtail
	beq :+		; skip (empty buffer, return with carry set)
	lda ribuf,x
	pha
	inc rhead
	clc
	pla
:	rts

;----------------------------------------------------------------------
; new NMI handler
nmi64:
	pha
	txa
	pha
	tya
	pha
	cld
	ldx $dd07	; sample timer b hi byte
	lda #$7f	; disable cia nmi's
	sta $dd0d
	lda $dd0d	; read/clear flags
	;bpl notcia	; (restore key)
	cpx $dd07	; timer B timeout?
	ldy $dd01	; sample pin C for receive NMI
	bcs :+		; no timeout
	ora #$02	; set flag
	ora $dd0d	; read flags again (changed since timeout)
:	and ENABL	; mask out non-enabled interrupts
	tax		; bitmask of ints to be serviced
	lsr		; check timer A
	bcc :+
	lda $dd00	; put output bit on pin M
	and #$fb
	ora outbit
	sta $dd00
:	txa		; check flag NMI
	and #$10	; indicates new byte coming in
	beq nmion
strtlo=*+1
	lda #0		; initialize timer B with start bit time
	sta $dd06
strthi=*+1
	lda #0
	sta $dd07
	lda #$11
	sta $dd0f	; start timer B, load latched value to counter
	lda #$12
	eor ENABL
	sta ENABL
	sta $dd0d	; enable flag, timer B interrupts
fulllo=*+1
	lda #0		; latch full bit value for next countdown
	sta $dd06
fullhi=*+1
	lda #0
	sta $dd07
	lda #8
	sta inbits
	jmp chktxd

;notcia	ldy #0
;	jmp rstkey	; or jmp norest

nmion:	lda ENABL	; receive a bit
	sta $dd0d
	txa
	and #$02
	beq chktxd
	tya
	lsr
	ror inbyte
	dec inbits
	bne txd
	lda inbyte
	ldx rtail	; index to buffer
	sta ribuf,x	; and store it
	inc rtail	; move index to next slot
	lda #0
	sta $dd0f
	lda #$12
switch:	ldy #$7f
	sty $dd0d
	sty $dd0d
	eor ENABL
	sta ENABL
	sta $dd0d
txd:	txa
	lsr
chktxd:	bcc @nmiflow
	dec outbits
	bmi @endbyte
	lda #4
	ror outbyte
	bcs :+
	lda #0
:	sta outbit
@nmiflow:
	lda inbits
	and #8
	beq :+
	clc
:	pla
	tay
	pla
	tax
	pla
	jmp rs232_rti

@endbyte:
	lda #0
	sta isbyte
	ldx #0		;  turn transmit int off
	stx $dd0e
	lda #1
	bne switch
	jmp rsuser_disable

;----------------------------------------------------------------------
rsuser_putxfer:
	pha
	stx save_x
	sty save_y
	sta outbyte
	lda #0
	sta outbit
	lda #9
	sta outbits
	lda #$ff
	sta isbyte
xmitlo=*+1
	lda #0
	sta $dd04
xmithi=*+1
	lda #0
	sta $dd05
	lda #$11
	sta $dd0e
	lda #$81
	jsr change
	clc
save_x=*+1
	ldx #0
save_y=*+1
	ldy #0
	pla
	rts

;----------------------------------------------------------------------
; disable rs232 input
rsuser_disable:
	pha
:
;	lda ENABL;this fucks shit up... get rid of it...
;	and #$03
;	bne :-
	lda isbyte
	bne :-
	lda #$10
	sta $dd0d
	lda #2
	and ENABL
	bne :-
	sta ENABL
	pla
	rts

;----------------------------------------------------------------------
; enable rs232 input
rsuser_enable:
	lda ENABL
	and #$12
	beq :+
	rts
:	sta $dd0f
	lda #$90
change:
	sta $dd0d
	php
	sei
	ldy #$7f
	sty $dd0d
	sty $dd0d
	ora ENABL
	sta ENABL
	sta $dd0d
	plp
:	bit isbyte
	bmi :-
	rts

;----------------------------------------------------------------------
; X: baud_rate
; Y: is_pal_system
rsuser_setbaud:
	txa		; baud_rate
	asl
	cpy #0		; is_pal_system
	beq :+
	clc
	adc #OFFSET
:	tay
	lda bdloc,y
	sta xmitlo
	lda bdloc+1,y
	sta xmithi
	lda bdloc+6,y
	sta strtlo
	lda bdloc+7,y
	sta strthi
	lda bdloc+12,y
	sta fulllo
	lda bdloc+13,y
	sta fullhi
	rts

;----------------------------------------------------------------------
; Hang up
rsuser_dropdtr:
	lda #%00000100
	sta $dd03
	lda #0
	sta cia2pb
	ldx #$100-30
	stx JIFFIES
:	bit JIFFIES
	bmi :-
	lda #4
	sta cia2pb
	rts
