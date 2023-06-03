; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTSQR:

	AND $7F
	RET Z

	INC A
	JP P, FPFASTSQRL1
	DEC A
	RET

FPFASTSQRL1:

	ADD A, A
	SUB 65
	JR NC, $+4
	XOR A
	RET

	CP $7F
	JP NC, FPFASTMUL_RETURN_INF+1

	LD D,H
	LD E,L

	JP FPFASTMUL_SIGNIFICAND

