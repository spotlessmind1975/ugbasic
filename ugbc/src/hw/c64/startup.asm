NMISVC:
    PHA
    LDA $DD0D
    PLA
    RTI

IRQSVC:
    PHA
    LDA $DC0D ; (irq cia)
    PLA
    RTI

C64STARTUP:
    LDA #<NMISVC
    STA $FFFA
    LDA #>NMISVC
    STA $FFFB

    LDA #<IRQSVC
    STA $FFFE
    LDA #>IRQSVC
    STA $FFFF

    ; DISABLE KENAL AND BASIC ROM    
    LDA #$35
    STA $01

    RTS