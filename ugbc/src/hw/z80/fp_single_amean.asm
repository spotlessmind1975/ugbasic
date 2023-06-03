; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEAMEAN:

	CALL FPSINGLEADD
	PUSH HL
	PUSH AF
	LD H, B
	LD L, C
	INC HL
	INC HL
	LD A, (HL)
	ADD A, A
	INC HL
	LD A, (HL)
	ADC A, A
	JR Z, FPSINGLEAMEAN_DONE
	INC A
	JR Z, FPSINGLEAMEAN_DONE
	DEC A
	DEC A
	RRA
	LD (HL), A
	DEC HL
	RL (HL)
	RRC (HL)
FPSINGLEAMEAN_DONE:
	POP AF
	POP HL
	RET
