; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

; included "fp_fast_mul.asm" by code
; included "fp_fast_pow10_lut" by code
; included "fp_format_str" by code

S_NAN:
DEFB	3, "NaN"
S_NEGINF:
DEFB	4, "-inf"
S_POSINF:
DEFB	4, "+inf"

FPFASTTOA:
	LD B, A

	ADD A, A
	JR NZ, +FPFASTTOAX
	EX DE, HL
	JR NC, $+5
	LD (HL), '-'
	INC HL
	LD (HL), '0'
	INC HL
	LD (HL), 0
	DEC HL
	RET NC
	DEC HL
	RET
FPFASTTOAX:

	PUSH DE
	CP $FE
	JR NZ, FPFASTTOA_FINITE
	LD A, H
	OR L
	LD HL, S_NAN
	JR NZ, +FPFASTTOAX2
	LD HL, S_NEGINF
	BIT 7, B
	JR NZ, +FPFASTTOAX2
	INC HL
FPFASTTOAX2:
	LDI
	LDI
	LDI
	LDI
	LD A, (HL)
	LD (DE), A
	POP HL
	RET
FPFASTTOA_FINITE:

	LD A, B
	ADD A, A
	JR NC, +FPFASTTOA_FINITEX
	EX DE, HL
	LD (HL), '-'
	INC HL
	EX DE, HL
FPFASTTOA_FINITEX:

	PUSH DE

	PUSH HL

	LD L, A
	LD H, 0
	RRCA
	LD E, A
	LD D, H

	ADD HL, HL
	ADD HL, HL
	ADD HL, DE
	ADD HL, HL
	ADD HL, DE
	ADD HL, HL
	ADD HL, HL
	ADD HL, DE

	LD E, H
	EX (SP), HL

	PUSH HL
	LD HL, FPFASTPOW10_LUT
	ADD HL, DE
	SLA E
	ADD HL, DE
	LD E, (HL)
	INC HL
	LD D, (HL)
	INC HL
	LD C, (HL)
	LD A, B
	AND $7F
	POP HL
	CALL FPFASTMUL

	CP 63
	JR NC,+FPFASTPOW10_LUTX

	POP DE
	DEC D
	PUSH DE
	LD C, $42
	LD DE, $4000
	CALL FPFASTMUL
FPFASTPOW10_LUTX:

	SUB 63
	LD B, A
	LD A, 1
	JR Z, +FPFASTPOW10_LUTX2
	ADD HL, HL
	RLA
	DJNZ $-2
FPFASTPOW10_LUTX2:

	LD BC, 3
	ADD HL, BC
	ADC A, B

	POP BC
	POP DE

	CP 10
	JR NC, +FPFASTPOW10_LUTX3
	ADD A, '0'
	LD (DE), A
	INC DE

	PUSH BC
	CALL FPFASTTOA_SUB
	JR FPFASTTOA_WRITE_DIGITS
FPFASTPOW10_LUTX3:
	INC B

	PUSH BC

	LD BC, 30
	ADD HL, BC
	ADC A, B

	EX DE, HL
	LD (HL), '1'
	SUB 20
	JR C, $+4
	INC (HL)
DEFB $01
	ADD A, 10
	INC HL
	EX DE, HL
	ADD A, '0'
	LD (DE), A
	INC DE
FPFASTTOA_WRITE_DIGITS:
	CALL FPFASTTOA_SUB
	CALL FPFASTTOA_SUB
	CALL FPFASTTOA_SUB
	XOR A
	LD (DE), A

	POP AF

	POP HL
	PUSH HL
	SUB 19
	LD E, A
	ADD A, A
	SBC A, A
	LD D, A
	CALL FORMATSTR
	POP HL
	RET
;
FPFASTTOA_SUB:
	XOR A
	LD B, H
	LD C, L
	ADD HL, HL
  RLA
	ADD HL, HL
  RLA
	ADD HL, BC
  ADC A, '0'/2
	ADD HL, HL
  RLA
	LD (DE), A
	INC DE
	RET
