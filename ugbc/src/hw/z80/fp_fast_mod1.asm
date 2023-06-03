; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTMOD1:

	LD C,A

	ADD A,A
	RET Z

	CP $FE
	RRCA
	JR NZ, FPFASTMOD1L1
	LD H, A
	RET

FPFASTMOD1L1:

	CP 63
	JR C, MOD_FINISHED

	SUB 63+16
	ADD A, 16
	JR C, FPFASTMOD1L2
	XOR A
	RET

FPFASTMOD1L2:

	LD B, A
	JR Z, FPFASTMOD1L3
	ADD HL, HL
	DJNZ $-1
FPFASTMOD1L3:

	LD A, H
	OR L
	RET Z
	LD A, 63
	DEC A
	ADD HL, HL
	JR NC, $-2
MOD_FINISHED:
	SLA C
	RET NC
	LD C, 63
	LD DE, 0
	JP FPFASTRSUB
