VBL:
    LDA #0
    STA ANTICVBL
VBL2:
    LDA ANTICVBL
    BEQ VBL2
    LDA #0
    STA VBL
    RTS

