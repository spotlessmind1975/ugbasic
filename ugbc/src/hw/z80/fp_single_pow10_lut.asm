; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FPSINGLE_POWN10_LUT:
DEFB $CD,$CC,$CC,$3D  ;1E-1
DEFB $0A,$D7,$23,$3C  ;1E-2
DEFB $17,$B7,$D1,$38  ;1E-4
DEFB $77,$CC,$2B,$32  ;1E-8
DEFB $95,$95,$E6,$24  ;1E-16
DEFB $1F,$B1,$4F,$0A  ;1E-32

FPSINGLE_POW10_LUT:
DEFB $00,$00,$20,$41  ;1E1
DEFB $00,$00,$C8,$42  ;1E2
DEFB $00,$40,$1C,$46  ;1E4
DEFB $20,$BC,$BE,$4C  ;1E8
DEFB $CA,$1B,$0E,$5A  ;1E16
DEFB $AE,$C5,$9D,$74  ;1E32
