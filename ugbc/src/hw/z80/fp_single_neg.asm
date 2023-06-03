; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLENEG:

	PUSH HL
	PUSH DE
	PUSH BC
	PUSH AF
	LD D, B
	LD E, C
	LDI
	LDI
	LDI
	LD A, (HL)
	XOR 80H
	LD (DE), A
	POP AF
	POP BC
	POP DE
	POP HL
	RET
