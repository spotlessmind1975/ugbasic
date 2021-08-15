VIC2STARTUP:

    SEI
    LDX #$10
    LDA #$33
    STA $01
    LDA #$D0
    STA $FC
    LDY #$00
    STY $FB
    LDA #$90
    STA $FE
    LDY #$00
    STY $FD
VIC2STARTUPL1:
    LDA ($FB),Y
    STA ($FD),Y
    INY
    BNE VIC2STARTUPL1
    INC $FC
    INC $FE
    DEX
    BNE VIC2STARTUPL1
    LDA #$37
    STA $01
    CLI

    ; SET_DATA_DIRECTION();
    LDA $dd02
    ORA #$03
    STA $dd02

    ; SET_BANK(2);
    LDA $dd00
    AND #$fc
    ORA #$01
    STA $dd00

    ; SET_BACKGROUND_COLOR( MR_COLOR_BLACK );
    LDA #0
    STA $d021

    ; SET_VIDEO(MR_SCREEN_DEFAULT);
    LDA $d018
    AND #$0f
    ORA #$10
    STA $d018

    ; SET_BASIC_VIDEO(MR_SCREEN_DEFAULT);
    AND #$84
    STA $0288

    ; SET_CHARSET(MR_TILESET_DEFAULT);
    LDA $d018
    AND #$f1
    ORA #$04
    STA $d018
        
    RTS