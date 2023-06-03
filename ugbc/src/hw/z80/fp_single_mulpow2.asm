; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEMULPOW2:
	
    CALL FPPUSHPOP
	LD D, B
	LD E, C
	LD C, A	;COPY A TO BC, EXTENDING THE SIGN
	ADD A, A
	SBC A, A
	LD B, A
	LDI
	LDI
	INC BC
	INC BC
	LD A, (HL)
	ADD A, A
	LD (DE), A
	INC HL
	LD A, (HL)
	ADC A, A
	JR Z, FPSINGLEMULPOW2_RETURN
	INC A
	JR Z, FPSINGLEMULPOW2_RETURN_INFNAN
	DEC A
	RL L	; SAVE THE SIGN
	ADD A, C
	JR NC, $+3
	INC B

	INC B
	JR Z, FPSINGLEMULPOW2_ZERO
	DJNZ FPSINGLEMULPOW2_RETURN_INFNAN
	DEFB $06 ; START OF `LD B,*` TO EAT THE NEXT BYTE
FPSINGLEMULPOW2_RETURN_INFNAN:
	DEC A
FPSINGLEMULPOW2_RETURN:
	RR L	; SHIFT OUT THE SIGN
	RRA
	EX DE, HL
	RR (HL)
	INC HL
	LD (HL) ,A
	RET

FPSINGLEMULPOW2_INF:
	LD D, -1
	DEFB 1 ;START OF `LD BC,**` TO EAT THE NEXT TWO BYTES
FPSINGLEMULPOW2_ZERO:
	LD D, 0
	RR D
	LD (HL), A
	DEC HL
	LD A, 0
	RRA
	LD (HL), A
	DEC HL
	XOR A
	LD (HL), A
	DEC HL
	LD (HL), A
	RET
