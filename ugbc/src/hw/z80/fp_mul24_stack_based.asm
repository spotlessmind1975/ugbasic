; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPMUL24:
	PUSH HL
	POP IX
	CALL FP_C_TIMES_BDE
	PUSH HL
	LD L, A
	LD H, C
	EX (SP), HL
	PUSH HL

	LD A, B
	PUSH IX
	POP BC
	LD B, A
	CALL FP_C_TIMES_BDE

	EX (SP), HL
	ADD A, L
	LD L, A
	LD A, C
	ADC A, H
	LD H, A

	LD A, B
	PUSH IX
	POP BC
	LD C, B
	LD B, A
	POP IX

	JR NC, FPMUL24L1
	EX (SP), HL
	INC HL
	EX (SP), HL
FPMUL24L1:
	PUSH HL
	PUSH IX

	CALL FP_C_TIMES_BDE
	DEC SP

	POP DE
	LD B, D
	POP DE
	ADD HL, DE
	LD D, C
	LD E, A
	EX (SP), HL
	ADC HL, DE
	POP DE
	LD A, B
	DEC SP
	POP BC
	RET NC
	INC B
	RET
