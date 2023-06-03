; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTAMEAN:

	LD B, A
	AND $7F
	JR Z, FPFASTAMEAN_NOOVERFLOW
	CP $7E
	JR Z, FPFASTAMEAN_OVERFLOW

	LD A, C
	AND $7F
	JR Z, FPFASTAMEAN_NOOVERFLOW
	CP $7E
	JR Z, FPFASTAMEAN_OVERFLOW

FPFASTAMEAN_NOOVERFLOW:
	LD A, B
	CALL FPFASTADD
; #IFDEF INCLUDED_FPFASTDIV2
; 	JP FPFASTDIV2
; #ELSE
; #DEFINE INCLUDED_FPFASTDIV2
FPFASTDIV2:
	LD B, A
	AND $7F
	LD A, B
	RET Z

	LD B, A
	AND $7F
	INC A
	LD A, B
	RET M
	DEC A
	RET

FPFASTAMEAN_OVERFLOW:

	LD A, B
	PUSH DE
	PUSH BC
	CALL FPFASTDIV2
	POP BC
	EX (SP), HL
	PUSH AF
	LD A, C
	CALL FPFASTDIV2
	POP BC
	POP DE
	LD C, B
	JP FPFASTADD
