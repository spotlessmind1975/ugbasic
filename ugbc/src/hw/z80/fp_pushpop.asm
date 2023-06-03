; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPPUSHPOP:
	EX (SP), HL
	PUSH DE
	PUSH BC
	PUSH AF
	PUSH HL
	LD HL, FPPUSHPOPRET
	EX (SP), HL
	PUSH HL
	PUSH AF
	LD HL, 12
	ADD HL, SP
	LD A, (HL)
	INC HL
	LD H, (HL)
	LD L, A
	POP AF
	RET

FPPUSHPOPRET:
	POP AF
	POP BC
	POP DE
	POP HL
	RET
