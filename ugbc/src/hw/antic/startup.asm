ANTICVBL:   .BYTE       0

IRQLISTENER:
    LDA #1
    STA ANTICVBL
    RTI

ANTICSTARTUP:
    LDA $0230
    STA TMPPTR
    LDA $0231
    STA TMPPTR+1

    CLC
    LDA TMPPTR
    ADC #4
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    LDY #0
    LDA (TMPPTR),Y
    STA TEXTADDRESS
    INY
    LDA (TMPPTR),Y
    STA TEXTADDRESS+1

    CLC
    LDA TMPPTR
    ADC #23
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    SEI
    LDA #<IRQLISTENER
    STA $0200
    LDA #>IRQLISTENER
    STA $0201
    CLI

    LDY #0
    LDA (TMPPTR),Y
    ORA #$80
    STA (TMPPTR),Y

    RTS