VBL:
    BIT $FF1C
    BPL VBL
VBL2:
    BIT $FF1C
    BMI VBL2
    RTS

