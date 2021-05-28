BINSTR:
    LD HL, BINSTRBUF
    ADD HL, 31
BINSTRL:
    SRA B
    RR C
    RR D
    RR E
    JR C, BINSTRO1
    JMP BINSTRO0
BINSTRO0:
    PUSH AF
    LD A, '0'
    LD (HL), A
    DEC HL
    POP AF
    JMP BINSTRO
BINSTRO1:
    PUSH AF
    LD A, '1'
    LD (HL), A
    DEC HL
    POP AF
    JMP BINSTRO
BINSTRO:
    DEC A
    JR NZ, BINSTRL
    RET

BINSTRBUF:  DS  32