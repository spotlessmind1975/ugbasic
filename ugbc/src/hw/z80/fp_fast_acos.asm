; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTACOS:

	RLCA
	OR A
	RRA
	JR NC, FPFASTACOSL1
	CALL FPFASTACOSL1
	LD C, $40
	LD DE, 37408
	JP FPFASTRSUB
FPFASTACOSL1:

	PUSH HL
	PUSH AF

	CALL FPFASTSQR
	LD C, $3F
	LD DE, 0
	CALL FPFASTRSUB
	CALL FPFASTSQRT

	POP BC
	EX (SP), HL
	PUSH AF
	LD A, B

	LD C, $3F
	LD DE, 0
	CALL FPFASTBG

	POP BC
	POP DE
	LD C, B
	JP FPFASTMUL
