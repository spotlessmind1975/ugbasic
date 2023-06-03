; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEGEOMEAN:

	PUSH HL
	CALL FPSINGLEMUL
	LD H, B
	LD L, C
	CALL FPSINGLESQRT
	POP HL
	RET
