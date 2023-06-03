; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining FPSCRAP RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLEHORNER_STEP:
	PUSH HL
	LD H, B
	LD L, C
	CALL FPSINGLEMUL
	EX DE, HL
	EX (SP), HL
	CALL FPSINGLEADD
	POP DE
	RET

