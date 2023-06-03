; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTTAN:
	PUSH HL
	PUSH AF
	CALL FPFASTCOS
	POP BC
	EX (SP),HL
	PUSH AF
	LD A,B
	CALL FPFASTSIN
	POP BC
	POP DE
	LD C,B
	JP FPFASTDIV
