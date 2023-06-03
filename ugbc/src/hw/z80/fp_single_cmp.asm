; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining FPSCRAP RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLECMP:
	PUSH BC
	PUSH HL
	PUSH DE
	INC HL
	INC HL
	LD A, (HL)
	ADD A, A
	INC HL
	LD A, H
	RLA
	DEC HL
	DEC HL
	DEC HL
	PUSH AF
	LD BC, FPSCRAP
	CALL FPSINGLESUB
	LD A, (FPSCRAP+2)
	ADD A, A
	LD A, (FPSCRAP+3)
	ADC A, A
	POP BC
	POP DE
	POP HL
	JR Z, FPSINGLECMP_EQUAL
	INC A
	JR NZ, FPSINGLECMP_EQUALL1

	LD BC, (FPSCRAP)
	LD A, (FPSCRAP+2)
	ADD A, A
	OR B
	OR C
	JR Z, FPSINGLECMP_NOTEQUAL
	LD A, -1
	ADD A, A
	POP BC
	RET

FPSINGLECMP_EQUALL1:
	SUB B
	ADD A, 2
	JR C, FPSINGLECMP_EQUAL
FPSINGLECMP_NOTEQUAL:
	POP BC

	LD A, (FPSCRAP+3)
	OR $7F
	ADD A, A
	RET

FPSINGLECMP_EQUAL:
	POP BC
	XOR A
	RET

