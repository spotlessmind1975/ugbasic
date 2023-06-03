; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTBG:

	PUSH AF
	PUSH HL

	PUSH BC
	PUSH DE

	CALL FPFASTAMEAN

	POP DE
	POP BC

	PUSH AF
	PUSH HL

	CALL FPFASTGEOMEAN

	POP DE
	POP BC

	PUSH AF
	PUSH HL

	LD A,B
	EX DE,HL
	CALL FPFASTMUL3
	LD B, 3
	CALL FPFASTDIV_POW2

	POP DE
	POP BC
	LD C, B

	CALL FPFASTADD

	POP DE
	POP BC

	PUSH AF
	PUSH HL

	LD A, B
	EX DE, HL
	LD B, 5
	CALL FPFASTDIV_POW2

	POP DE
	POP BC
	LD C, B

	CALL FPFASTADD

	EX DE, HL
	LD C, A
	LD A, $3F
    LD HL, 26624	;45/32
	JP FPFASTDIV