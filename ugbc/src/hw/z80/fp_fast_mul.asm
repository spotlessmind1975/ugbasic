; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

; included "fp_mul16.asm" by code

FPFASTMUL:

	LD B, A
	LD A, C
	AND $80
	XOR B

	LD B, A
	AND $7F
	JR Z, FPFASTMUL_OP1_0
	INC A
	JP M, FPFASTMUL_OP1_INF_NAN

	LD A, C
	AND $7F
	LD C, A
	RET Z
	INC A
	JP P, FPFASTMUL_RETURN_CDEL1
FPFASTMUL_RETURN_CDE:
	LD A, C
	EX DE, HL
	RET
FPFASTMUL_RETURN_CDEL1:

	LD A, B
	AND $7F
	ADD A, C
	SUB 63
	JR NC, $+4
	XOR A
	RET

	CP $7F
	JR C, FPFASTMUL_RETURN_INFX
FPFASTMUL_RETURN_INF:
	LD A, B
	OR %01111111
	LD HL, 0
	RET
FPFASTMUL_RETURN_INFX:

	XOR B
	AND $7F
	XOR B
FPFASTMUL_SIGNIFICAND:
	PUSH AF

	LD B, H
	LD C, L
	PUSH HL
	PUSH DE
	CALL FPMUL16
	XOR A
	SLA H
	EX DE, HL
	POP BC
	ADC HL, BC
	ADC A, 0
	POP BC
	ADD HL, BC
	ADC A, 0
	RRA
	POP BC
	LD A, B
	RET Z
	CCF
	RR H
	RR L
	INC A
	INC A
	ADD A, A
	JR Z, FPFASTMUL_RETURN_INF
	RRA
	DEC A
	RET

FPFASTMUL_OP1_0:
	LD A, C
	AND $7F
	RET Z
	INC A
	JP M, FPFASTMUL_RETURN_NAN
	XOR A
	RET

FPFASTMUL_OP1_INF_NAN:
	LD A, H
	OR L
	LD A, B
	RET NZ

	LD A, C
	AND $7F
	JR NZ, +FPFASTMUL_RETURN_NANX
FPFASTMUL_RETURN_NAN:
	DEC A
	LD H, A
	LD L, A
	RET
FPFASTMUL_RETURN_NANX:
	INC A
	JP M, +FPFASTMUL_RETURN_NANX2
	LD A, B
	RET
FPFASTMUL_RETURN_NANX2:

	LD A, C
	EX DE, HL
	RET
