; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTDIV_POW2:
	LD C, A
	AND $7F
	SUB B
	JR NC, $+4
	XOR A
	RET
	LD A, C
	SUB B
	RET
