; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEACOS:
	CALL FPPUSHPOP
	PUSH BC

	LD DE, FPSCRAP+12
	CALL FPMOV4

	LD DE, FPSCRAP+12
	LD H, D
	LD L, E
	LD BC, FPSCRAP+4
	CALL FPSINGLEMUL

    LD DE, FPSINGLE_CONST_1
	LD H, B
	LD L, C
	CALL FPSINGLERSUB

	CALL FPSINGLESQRT

	LD HL, FPSCRAP+12
	LD B, H
	LD C, L
	CALL FPSINGLEBGI

	LD DE, FPSCRAP+4
	POP BC
	JP FPSINGLEMUL
