; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLESQRT:

	CALL FPPUSHPOP
	PUSH BC
	LD B, (HL)
	INC HL
	LD E, (HL)
	INC HL
	LD D, (HL)
	LD A, D
	ADD A, A
	INC HL
	LD A, (HL)
	ADC A, A
	JR C, FPSINGLESQRT_NEG
	JR Z, FPSINGLESQRT_ZERO
	INC A
	JR Z, FPSINGLESQRT_INFNAN

	SET 7,D

	LD C, 0
	RRA
	JR C, FPSINGLESQRTL1
	SRL D
	RR E
	RR B
	RR C
FPSINGLESQRTL1:

	ADD A,3FH

	PUSH AF

	CALL FPSQRT24_MANT

	LD B, L
	POP AF
	SLA D
	SRL A
	RR D
FPSINGLESQRT_ZERO:
	POP HL
	LD (HL), B
	INC HL
	LD (HL), E
	INC HL
	LD (HL), D
	INC HL
	LD (HL), A
	RET
FPSINGLESQRT_NEG:
	JR Z, FPSINGLESQRT_NEG0
	LD A, -1
FPSINGLESQRT_NEG0:
	POP HL
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	XOR %10000000
	LD (HL), A
	RET

FPSINGLESQRT_INFNAN:
	POP HL
	LD A, D
	AND %01111111 ;MASK OUT THE EXPONENT BIT
	OR E
	OR B
	LD (HL), A
	INC HL
	LD (HL), A
	INC HL
	OR %10000000
	LD (HL), A
	INC HL
	LD (HL), %01111111
	RET
