; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTCOS:

	ADD A,A
	RET Z

	RRCA
	CP $7F
	JR NZ, FPFASTCOSL1
	LD H,A
	RET
FPFASTCOSL1:

	LD C, $3C
	LD DE, $45F3
	CALL FPFASTMUL

	LD C, $3E
	LD DE, $0
	CALL FPFASTADD

	CALL FPFASTMOD1

XCOS_STEPIN:

	LD C, $BE
	LD DE, $0
	CALL FPFASTADD

	AND $7F

	CP $3D
	JR C, FPFASTCOSL2
	XOR 80H
	LD C, $3E
	LD DE, $0
	CALL FPFASTADD
	CALL FPFASTCOSL2
	XOR 80H
	RET
FPFASTCOSL2:

	CP $3C
	JR C, FPFASTCOSL3
	XOR $80
	LD C, $3D
	LD DE, $0
	CALL FPFASTADD
	JP FPFASTSIN_RANGE_REDUCED

FPFASTCOSL3:

FPFASTCOS_RANGE_REDUCED:

	LD C, $41
	LD DE, $9220
	CALL FPFASTMUL

	CALL FPFASTSQR
	XOR $80

	PUSH HL
	LD C, A
	PUSH BC

	LD C, $35
	LD DE, $65A9
	CALL FPFASTMUL

	LD C, $3A
	LD DE, $5549
	CALL FPFASTADD

	POP BC
	POP DE
	PUSH DE
	PUSH BC
	CALL FPFASTMUL

	LD C, $3E
	LD DE, $0
	CALL FPFASTADD

	POP BC
	POP DE
	CALL FPFASTMUL

	LD C, $3F
	LD DE, $0
	JP FPFASTADD
