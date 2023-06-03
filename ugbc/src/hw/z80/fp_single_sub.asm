; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLESUB:
	CALL FPPUSHPOP

	PUSH BC
	EX DE, HL

	LD C, (HL)
	INC HL
	LD B, (HL)
	INC HL
	PUSH BC

	LD C, (HL)
	INC HL
	LD A, (HL)
	XOR 80H
	LD B, A
	JP FPSINGLEADD_PART2

FPSINGLERSUB:

	CALL FPPUSHPOP

	PUSH BC

	LD C, (HL)
	INC HL
	LD B, (HL)
	INC HL
	PUSH BC

	LD C, (HL)
	INC HL
	LD A, (HL)
	XOR 80H
	LD B,A
	JP FPSINGLEADD_PART2
