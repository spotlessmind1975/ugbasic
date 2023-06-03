; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEATAN:

	CALL FPPUSHPOP
	PUSH BC

	LD DE, FPSCRAP+12
	CALL MOV4

	LD DE, FPSCRAP+12
	LD H, D
	LD L, E
	LD BC, FPSINGLEBGI_G
	CALL FPSINGLEMUL

	LD DE, FPSINGLE_CONST_1
	LD H, B
	LD L, C
	CALL FPSINGLEADD

	CALL FPSINGLESQRT

	EX DE, HL
	CALL FPSINGLEBGI

	LD HL, FPSCRAP+12
	POP BC
	JP FPSINGLEMUL
