; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTATAN:

	RLCA
	OR A
	RRA
	JR NC, FPFASTATANL1
	CALL FPFASTATANL1
	XOR $80
	RET
FPFASTATANL1:

	CP 63
	JR C, FPFASTATANL2
	CALL FPFASTINV
	CALL FPFASTATANL2
	LD C, $3F
	LD DE, 37408
	JP FPFASTRSUB
FPFASTATANL2:
	PUSH AF
	PUSH HL
	CALL FPFASTSQR
	LD C, $3F
	LD DE, 0
	CALL FPFASTADD
	CALL FPFASTSQRT
	EX DE, HL
	LD C, A
	LD A, $3F
	LD HL, 0
	CALL FPFASTBG

	POP DE
	POP BC
	LD C, B
	JP FPFASTMUL
