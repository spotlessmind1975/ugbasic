CLS:

    LD A, 0
    LD HL, (BITMAPADDRESS)
    LD (HL), A
    LD DE, (BITMAPADDRESS)
    INC DE
    LD BC, 6144
    LDIR

    LD HL, (COLORMAPADDRESS)
    LD A, (_PAPER)
    AND $07
    SLA A
    SLA A
    SLA A
    LD B, A
    LD A, (_PEN)
    AND $07
    OR A, B
    LD (HL), A
    LD DE, (COLORMAPADDRESS)
    INC DE
    LD BC, 768
    LDIR
    RET
