; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTSIN:

	LD B,A

	ADD A, A
	RET Z

	RRCA
	CP $7F
	JR NZ, FPFASTSINL1
	LD H, A
	RET

FPFASTSINL1:

	LD A, B

	LD C, $3C
	LD DE, $45F3
	CALL FPFASTMUL

	LD C, $3D
	LD DE, $0
	CALL FPFASTADD

	CALL FPFASTMOD1

	JP XCOS_STEPIN

FPFASTSIN_RANGE_REDUCED:

	LD C, $41
	LD DE, $9220
	CALL FPFASTMUL

	PUSH HL
	PUSH AF

	CALL FPFASTSQR
	XOR $80

	PUSH HL
	LD C, A
	PUSH BC

	LD C, $38
	LD DE, $0B7A
	CALL FPFASTMUL

	LD C, $3C
	LD DE, $5544
	CALL FPFASTADD

	POP BC
	POP DE
	CALL FPFASTMUL

	LD C, $3F
	LD DE, $0
	CALL FPFASTADD

	POP BC
	POP DE
	LD C, B
	JP FPFASTMUL
