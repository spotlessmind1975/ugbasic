
CLS:
    LDA TEXTADDRESS
    STA $25
    LDA TEXTADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA #32

CLSY:
    STA ($25),Y
    INY
    BNE CLSY
    INC $26
    CPX #1
    BNE CLSNB
CLSY2:
    STA ($25),Y
    INY
    CPY #232
    BNE CLSY2
CLSNB:
    DEX
    BNE CLSY
    RTS
