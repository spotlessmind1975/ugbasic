; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTSUB:
	LD B, A
	LD A, C
	XOR $80
	LD C, A
	LD A, B

	JP FPFASTADD

FPFASTRSUB:
	XOR $80
	JMP FPFASTADD
