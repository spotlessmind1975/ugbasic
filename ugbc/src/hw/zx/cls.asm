CLS:

    LD HL, $4000
    LD (HL), A
    LD DE, $4001
    LD BC, 6144
    LDIR

    LD HL, $5800
    LD A, (LOCALPAPER)
    AND $07
    SLA A
    SLA A
    SLA A
    LD B, A
    LD A, (LOCALPEN)
    AND $07
    OR A, B
    LD (HL), A
    LD DE, $5801
    LD BC, 768
    LDIR
    RET
