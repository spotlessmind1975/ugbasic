; z80float is a floating point library targeting the Z80 processor. While this
; project is tested on a TI-84+, the code should be generic enough to run on any
; Z80 CPU with very little modification (mostly defining scrap RAM locations).
;
; adapted by Marco Spedaletti

FP_C_TIMES_BDE:
  LD A, B
  LD H, D
  LD L, E
  SLA C
  JR C, FPMUL_24_1
  SLA C
  JR C, FPMUL_24_2
  SLA C
  JR C, FPMUL_24_3
  SLA C
  JR C, FPMUL_24_4
  SLA C
  JR C, FPMUL_24_5
  SLA C
  JR C, FPMUL_24_6
  SLA C
  JR C, FPMUL_24_7
  SLA C
  RET C

  LD A, C
  LD H, C
  LD L, C
  RET

FPMUL_24_1:
    ADD HL,HL
    RLA
    RL C 
    JR NC,$+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_2:
    ADD HL, HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_3:
    ADD HL,HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_4:
    ADD HL,HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_5:
    ADD HL, HL
    RLA
    RL C
    JR NC, $+7
    ADD HL, DE
    ADC A, B
    JR NC, $+3
    INC C
FPMUL_24_6:
    ADD HL, HL
    RLA
    RL C
    JR NC, $+7
    ADD HL ,DE
    ADC A, B
    JR NC,  $+3
    INC C
FPMUL_24_7:
    ADD HL, HL 
    RLA
    RL C
    RET NC
    ADD HL, DE
    ADC A, B
    RET NC
    INC C
    RET

