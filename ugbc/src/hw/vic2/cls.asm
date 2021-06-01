
CLS:
    LDA $D011
    AND #$20
    BEQ CLST
    JMP CLSG
    
CLSG:
    LDA BITMAPADDRESS
    STA $25
    LDA BITMAPADDRESS+1
    STA $26
    LDX #31
    LDY #0
    LDA #0
CLSGY:
    STA ($25),Y
    INY
    BNE CLSGY
    INC $26
    DEX
    BNE CLSGY

    LDA COLORMAPADDRESS
    STA $25
    LDA COLORMAPADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA _PEN
    ASL A
    ASL A
    ASL A
    ASL A
    ORA _PAPER
CLGC:
    STA ($25),Y
    INY
    BNE CLGC
    INC $26
    CPX #1
    BNE CLGCNB
CLGC2:
    STA ($25),Y
    INY
    CPY #232
    BNE CLGC2
CLGCNB:
    DEX
    BNE CLGC

    RTS

CLST:
    LDA TEXTADDRESS
    STA $25
    LDA TEXTADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA EMPTYTILE
CLST2:
    STA ($25),Y
    INY
    BNE CLST2
    INC $26
    CPX #1
    BNE CLSTNB
CLST2X:
    STA ($25),Y
    INY
    CPY #232
    BNE CLST2X
CLSTNB:
    DEX
    BNE CLST2

    LDA COLORMAPADDRESS
    STA $25
    LDA COLORMAPADDRESS+1
    STA $26
    LDX #3
    LDY #0
    LDA _PEN
CLSTC:
    STA ($25),Y
    INY
    BNE CLSTC
    INC $26
    CPX #1
    BNE CLSTCNB
CLSTC2:
    STA ($25),Y
    INY
    CPY #232
    BNE CLSTC2
CLSTCNB:
    DEX
    BNE CLSTC

    RTS
