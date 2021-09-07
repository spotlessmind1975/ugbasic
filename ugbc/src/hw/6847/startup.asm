C6847STARTUP

    ; (4) Default screen mode is semigraphic-4

    STA $FFC0
    STA $FFC2
    STA $FFC4
    LDA $FF22
    ANDA #$7F
    STA $FF22  

    LDA $03
    STA $FF98
    RTS