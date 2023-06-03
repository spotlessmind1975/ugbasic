; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEFROM16S:
;
	CALL FPPUSHPOP

	XOR A
	LD (BC), A
	INC BC

	LD A, L
	OR H
	LD D, A
	JR Z, I16TOF32_FINISH

	LD A, H
	OR A
	JP P, $+10
	XOR A
	SUB L
	LD L, A
	SBC A, A
	SUB H
	LD H, A
	SCF

	RLA
	LD D, $7F+16

	DEC D
	ADD HL, HL
	JR NC, $-2

	RRA
	RR D
	RR H
	RR L

	LD A, L
I16TOF32_FINISH:
	LD (BC), A
	INC BC
	LD A, H
	LD (BC), A
	INC BC
	LD A, D
	LD (BC), A
	RET

FPSINGLEFROM16U:

	CALL FPPUSHPOP

	XOR A
	LD (BC), A
	INC BC

	LD A, L
	OR H
	LD D, A
	JR Z, U16TOFPSINGLE_FINISH

	LD D, $7F+16

	DEC D
	ADD HL, HL
	JR NC, $-2

	SRL D
	RR H
	RR L

	LD A, L
U16TOFPSINGLE_FINISH:
	LD (BC), A
	INC BC
	LD A, H
	LD (BC), A
	INC BC
	LD A, D
	LD (BC), A
	RET
