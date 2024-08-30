; CCGMS Terminal
;
; Copyright (c) 2016,2022, Craig Smith, alwyz, Michael Steil. All rights reserved.
; This project is licensed under the BSD 3-Clause License.
;
; RS232 Driver Dispatch
;

.include "rs232_kernal.inc"
.include "rs232.inc"

; settings
.import modem_type, baud_rate, is_pal_system

; drivers
.import rsuser_funcs, up9600_funcs, sw_funcs
.export rs232_rti

tmpzp		= $a7	; reused KERNAL RS-232 driver var
ram_flag	= $f9	; reused KERNAL RS-232 driver var

.segment "RS232"

;----------------------------------------------------------------------
; Dispatch: Init modem
rs232_init:
	jsr setup_ram_irq_nmi

	ldx #MODEM_TYPE_SWIFTLINK_DE
	lda modem_type
	cmp #MODEM_TYPE_SWIFTLINK_DE
	bcc :+
	txa
:	asl
	tax
	lda modem_drivers,x
	sta tmpzp
	lda modem_drivers+1,x
	sta tmpzp+1
	ldx #1
	ldy #0
:	lda (tmpzp),y
	sta rs232_funcs,x
	iny
	inx
	lda (tmpzp),y
	sta rs232_funcs,x
	iny
	inx
	inx
	cpy #2*6
	bne :-

	lda modem_type
	ldx baud_rate
	ldy is_pal_system
	jsr func_setup
	jmp rs232_clear

rs232_funcs:
func_setup:
	jmp $ffff
func_enable:
	jmp $ffff
func_disable:
	jmp $ffff
func_getxfer:
	jmp $ffff
func_putxfer:
	jmp $ffff
func_dropdtr:
	jmp $ffff

	.res 6*2

modem_drivers:
	.word rsuser_funcs	; MODEM_TYPE_USERPORT
	.word up9600_funcs	; MODEM_TYPE_UP9600
	.word sw_funcs		; MODEM_TYPE_SWIFTLINK_DE, ...

;----------------------------------------------------------------------
; Dispatch: Enable
rs232_on:
	pha
	txa
	pha
	tya
	pha
	jsr func_enable
	jmp xferout

;----------------------------------------------------------------------
; Dispatch: Disable
rs232_off:
	pha
	txa
	pha
	tya
	pha
	jsr func_disable
xferout:
	pla
	tay
	pla
	tax
	pla
	rts

;----------------------------------------------------------------------
; Dispatch: Get byte from modem
rs232_get:
	jsr func_getxfer
	pha
	php
	lda #0
	rol
	sta STATUS		; some callers want STATUS set
	plp			; others want C set on error/no data
	pla
	rts

;----------------------------------------------------------------------
; Dispatch: Send byte to modem
rs232_put:
	pha
	lda #0
	sta STATUS
	pla
	jmp func_putxfer

;----------------------------------------------------------------------
; Dispatch: Hang up
rs232_dropdtr	= func_dropdtr

;----------------------------------------------------------------------
; Clear RS232 buffer
rs232_clear:
	pha
	lda #0
	sta rtail
	sta rhead
	sta rfree
	pla
	rts

;----------------------------------------------------------------------
setup_ram_irq_nmi:
	lda #0
	sta ram_flag
	lda #<ramnmi
	sta $fffa
	lda #>ramnmi
	sta $fffb
	lda #<ramirq
	sta $fffe
	lda #>ramirq
	sta $ffff
	rts

;----------------------------------------------------------------------
; high-speed version to minimize NMI latency
ramnmi:
	inc $01
	dec ram_flag
	jmp ($0318)
rs232_rti:
	bit ram_flag
	bpl :+
	inc ram_flag
	dec $01
:	rti

;----------------------------------------------------------------------
; low-speed version - IRQs are not timing critical
ramirq:
	pha
	lda $01
	pha
	lda #$37
	sta $01
	lda #>ramirq2
	pha
	lda #<ramirq2
	pha
	lda #0		; P: B flag clear
	pha
	jmp $ff48
ramirq2:
	pla
	sta $01
	pla
	rti
