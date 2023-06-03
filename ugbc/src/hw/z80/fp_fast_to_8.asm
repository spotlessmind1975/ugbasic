; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPFASTTOS8:
	LD C,A

	ADD A, A
	RET Z

	CP $FE
	JR NZ, FPFASTTOS8L1
	LD A, H
	OR L
	JR NZ, FPFASTTOI8_RETURN_0
FPFASTTOI8_RETURN_INF:
	SLA C
	LD A, 127
	ADC A, 0
	RET
FPFASTTOS8L1:
	CP 63*2
	JR NC, FPFASTTOS8L2
FPFASTTOI8_RETURN_0:
	XOR A
	RET
FPFASTTOS8L2:

	RRA
	SUB 63
	CP 7
	JR NC, FPFASTTOI8_RETURN_INF

	LD B, A
	OR A
	LD A, 1
	JR Z, FPFASTTOS8L3

	ADD HL, HL
	RLA
	DJNZ $-2
FPFASTTOS8L3:
	SLA C
	RET NC
	NEG
	RET

FPFASTTOU8:
	LD C, A

	ADD A, A
	RET Z

	CP $FE
	JR NZ, FPFASTTOU8L1
	LD A, H
	OR L
	JR NZ, FPFASTTOU8_RETURN_0
FPFASTTOU8_RETURN_INF:
	LD A, 255
	RET
FPFASTTOU8L1:

	CP 63*2
	JR NC, FPFASTTOU8L2
FPFASTTOU8_RETURN_0:
	XOR A
	RET
FPFASTTOU8L2:

	RRA
	SUB 63
	CP 8
	JR NC, FPFASTTOU8_RETURN_INF

	LD B, A
	OR A
	LD A, 1
	JR Z, FPFASTTOU8L3

	ADD HL, HL
	RLA
	DJNZ $-2
FPFASTTOU8L3:
	SLA C
	RET NC
	NEG
	RET

	