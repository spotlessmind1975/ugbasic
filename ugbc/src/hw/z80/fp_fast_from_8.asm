; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTFROM8S:

	OR A
	JP P, +FPFASTFROM8U
	NEG
	LD B, $BF+8
	JR FPFASTFROM8SL1

FPFASTFROM8U:

	OR A
	RET Z

	LD B, $3F+8

FPFASTFROM8SL1:

	DEC B
	ADD A, A
	JR NC, $-2
	LD H, A
	LD L, 0
	LD A, B
	RET
