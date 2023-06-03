; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTFROM16S:
	BIT 7, H
	JR Z, FPFASTFROM16SPOS
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	LD B, $BF+16
	JR FPFASTFROM16L1

FPFASTFROM16SPOS:

FPFASTFROM16U:

	LD B, $3F+16

FPFASTFROM16L1:

	LD A, H
	OR L
	RET Z

	DEC B
	ADD HL, HL
	JR NC, $-2
	LD A, B
	RET
