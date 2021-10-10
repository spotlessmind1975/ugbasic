VIC1STARTUP:

    ; bits 4-7 select background color
    ; bits 0-2 select border color
    ; bit 3 selects inverted or normal mode

    LDA #$08
    STA $900F

    ; Lowercase font
    LDA $9005
    AND #$F0
    ORA #$02
    STA $9005

    RTS