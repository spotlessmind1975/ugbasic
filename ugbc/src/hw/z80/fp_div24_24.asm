; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPDIV24_24:
	XOR A
	SUB E
	LD E, A

	LD A, 0
	SBC A, D
	LD D, A

	SBC A, A
	SUB A, C
	LD C, A

	LD A, B
	CALL FPDIV24_24_SUB_1
	CALL FPDIV24_24_SUB_8
	PUSH BC
	CALL FPDIV24_24_SUB_8
	PUSH BC
	CALL FPDIV24_24_SUB_8

	POP DE
	LD E,B
	POP BC
	RET

FPDIV24_24_SUB_8:
	CALL FPDIV24_24_SUB_4
FPDIV24_24_SUB_4:
	CALL FPDIV24_24_SUB_2
FPDIV24_24_SUB_2:
	CALL FPDIV24_24_SUB_1
FPDIV24_24_SUB_1:
	RL B
	ADD HL, HL
	ADC A, A
	JR C, FPDIV24_24_SUB_OVERFLOW
	ADD HL, DE
	ADC A, C
	RET C
	SBC HL, DE
	SBC A, C
	RET
FPDIV24_24_SUB_OVERFLOW:
	ADD HL, DE
	ADC A, C
	SCF
	RET
