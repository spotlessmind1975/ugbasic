; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTTOS16:
	LD C, A
	ADD A, A
	JR Z, FPFASTTOI16_RETURN_0

	CP $FE
	JR NZ, FPFASTTOS16L1
	LD A, H
	OR L
	JR NZ,FPFASTTOI16_RETURN_0
FPFASTTOI16_RETURN_INF:
	SLA C
	LD HL, 32767
	RET NC
	INC HL
	RET
FPFASTTOS16L1:

	CP 63*2
	JR NC, FPFASTTOS16L2
FPFASTTOI16_RETURN_0:
	LD HL, 0
	RET
FPFASTTOS16L2:

	RRA
	SUB 63
	CP 15
	JR NC, FPFASTTOI16_RETURN_INF

	OR A
	LD B, A
	LD D, 0
	LD A, 1
	JR Z, FPFASTTOS16L3

	ADD HL, HL
	RLA
	RL D
	DJNZ $-4
FPFASTTOS16L3:
	SLA C
	LD E, A
	EX DE, HL
	RET NC
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	RET

FPFASTTOU16:
	LD C,A

	ADD A, A
	JR Z, FPFASTTOU16_RETURN_0

	CP $FE
	JR NZ, FPFASTTOU16L1
	LD A, H
	OR L
	JR NZ, FPFASTTOU16_RETURN_0
FPFASTTOU16_RETURN_INF:
	LD HL, -1
	RET
FPFASTTOU16L1:

	CP 63*2
	JR NC, FPFASTTOU16L2
FPFASTTOU16_RETURN_0:
	LD HL, 0
	RET
FPFASTTOU16L2:

	RRA
	SUB 63
	CP 16
	JR NC, FPFASTTOU16_RETURN_INF

	LD B, A
	OR A
	LD A, 1
	LD D, 0
	JR Z, FPFASTTOU16L3

	ADD HL, HL
	RLA
	RL D
	DJNZ $-4
FPFASTTOU16L3:
	SLA C
	LD E, A
	EX DE, HL
	RET NC
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	RET
