; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

S_NEGINF:
STR_NEGINF:
  DEFB '-'
S_INF:
STR_INF:
  DEFB "INF", 0
S_NAN:
STR_NAN:
  DEFB "NAN", 0
STR_ZERO:
  DEFB "0", 0

