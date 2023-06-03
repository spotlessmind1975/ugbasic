; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPDIV32_16:

	PUSH BC
	LD A, B
	SRL A
	CPL
	LD B, A
	LD A, C
	RRA
	CPL
	LD C, A
	INC BC
	LD A, D
	ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	LD D, A
	LD A,E
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
    ADD HL, BC
    JR C, $+4
    SBC HL, BC
	RLA
    ADC HL, HL
	LD E, A
	POP BC
	BIT 0, C
	RET Z

	SBC HL, DE
	RET NC
	ADD HL, BC
	DEC DE
	RET C
	ADD HL, BC
	DEC DE
	RET
