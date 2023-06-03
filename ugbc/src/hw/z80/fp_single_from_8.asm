; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEFROM8S:

	PUSH HL
	PUSH AF

	OR A
	JP P, $+6
	NEG
	SCF

	LD H, B
	LD L, C
	LD (HL), 0
	INC HL
	LD (HL), 0
	INC HL

	JR NZ, $+8
	LD (HL), A
	INC HL
	LD (HL), A
	POP AF
	POP HL
	RET

	PUSH BC
	RL C
	LD B, $7F+8

	DEC B
	ADD A, A
	JR NC, $-2

	RR C
	RR B
	RRA
	LD (HL), A
	INC HL
	LD (HL), B

	POP BC
	POP AF
	POP HL
	RET

FPSINGLEFROM8U:

	PUSH HL
	PUSH AF

	LD H,B
	LD L,C
	LD (HL),0
	INC HL
	LD (HL),0
	INC HL

	OR A
	JR NZ,$+8
	LD (HL),A
	INC HL
	LD (HL),A
	POP AF
	POP HL
	RET

	PUSH BC
	RL C
	LD B, $7F+8

	DEC B
	ADD A, A
	JR NC, $-2

	RR C
	RR B
	RRA
	LD (HL), A
	INC HL
	LD (HL),B

	POP BC
	POP AF
	POP HL
	RET



