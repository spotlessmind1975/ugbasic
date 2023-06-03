; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTCMP:

	LD B, A
	AND $7F
	INC A
	JP M, FPFASTCMP_SPECIAL
	LD A, B

	PUSH AF
	CALL FPFASTSUB

	POP BC

	XOR 80H
	RET Z
	XOR 80H
	RET Z

	LD C, A
	RES 7, B
	AND $7F
	ADD A, 14
	SUB B
	JR NC, $+4
	XOR A
	RET

	LD A, C
RETURN_NZ_SIGN_A:
	OR $7F
	ADD A, A
	RET

FPFASTCMP_SPECIAL:
	LD A, H
	OR L
	CCF
	RET NZ

	LD A, C
	AND $7F
	INC A
	LD A, B
	JP P, RETURN_NZ_SIGN_A

	LD A, D
	OR E
	RET NZ

	LD A, C
	CP B
	RET
	
