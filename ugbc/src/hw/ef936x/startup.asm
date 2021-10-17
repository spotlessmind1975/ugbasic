EF936XSTARTUP

    ; // { "BLACK", 
    ;     { 0x00, 0x00, 0x00, 0 },        
    LDA #0
    ; LSLA
    STA $A7DB
    LDD #$0000
    STB $A7DA
    STA $A7DA
    ; // { "WHITE", 
    ;     { 0xff, 0xff, 0xff, 1 },
    ; LDA #1
    ; LSLA
    ; STA $A7DB
    LDD #$0FFF
    STB $A7DA
    STA $A7DA
    ; // { "RED", 
    ;     { 0x88, 0x00, 0x00, 2 },
    ; LDA #2
    ; LSLA
    ; STA $A7DB
    LDD #$0008
    STB $A7DA
    STA $A7DA
    ; // { "CYAN", 
    ;     { 0xaa, 0xff, 0xe6, 3 },
    ; LDA #3
    ; LSLA
    ; STA $A7DB
    LDD #$0EFA
    STB $A7DA
    STA $A7DA
    ; // { "VIOLET", 
    ;     { 0xcc, 0x44, 0xcc, 4 },
    ; LDA #4
    ; LSLA
    ; STA $A7DB
    LDD #$0C4C
    STB $A7DA
    STA $A7DA
    ; // { "GREEN", 
    ;     { 0x00, 0xcc, 0x55, 5 },
    ; LDA #5
    ; LSLA
    ; STA $A7DB
    LDD #$05C0
    STB $A7DA
    STA $A7DA
    ; // { "BLUE", 
    ;     { 0x00, 0x00, 0xaa, 6 },
    ; LDA #6
    ; LSLA
    ; STA $A7DB
    LDD #$0A00
    STB $A7DA
    STA $A7DA
    ; // { "YELLOW", 
    ;     { 0xee, 0xee, 0x77, 7 },
    ; LDA #7
    ; LSLA
    ; STA $A7DB
    LDD #$07EE
    STB $A7DA
    STA $A7DA
    ; // { "ORANGE", 
    ;     { 0xa1, 0x68, 0x3c, 8 },
    ; LDA #8
    ; LSLA
    ; STA $A7DB
    LDD #$036A
    STB $A7DA
    STA $A7DA
    ; // { "BROWN", 
    ;     { 0xdd, 0x88, 0x65, 9 },
    ; LDA #9
    ; LSLA
    ; STA $A7DB
    LDD #$068D
    STB $A7DA
    STA $A7DA
    ; // { "LIGHT_RED", 
    ;     { 0xff, 0x77, 0x77, 10 },
    ; LDA #10
    ; LSLA
    ; STA $A7DB
    LDD #$07FF
    STB $A7DA
    STA $A7DA
    ; // { "DARK_GREY", 
    ;     { 0x33, 0x33, 0x33, 11 },
    ; LDA #11
    ; LSLA
    ; STA $A7DB
    LDD #$0333
    STB $A7DA
    STA $A7DA
    ; // { "GREY", 
    ;     { 0x77, 0x77, 0x77, 12 },
    ; LDA #12
    ; LSLA
    ; STA $A7DB
    LDD #$0777
    STB $A7DA
    STA $A7DA
    ; // { "LIGHT_GREEN", 
    ;     { 0xaa, 0xff, 0x66, 13 },
    ; LDA #13
    ; LSLA
    ; STA $A7DB
    LDD #$06FA
    STB $A7DA
    STA $A7DA
    ; // { "LIGHT_BLUE", 
    ;     { 0x00, 0x88, 0xff, 14 },
    ; LDA #14
    ; LSLA
    ; STA $A7DB
    LDD #$0F80
    STB $A7DA
    STA $A7DA
    ; // { "LIGHT_GREY", 
    ;     { 0xbb, 0xbb, 0xbb, 15 }
    ; LDA #15
    ; LSLA
    ; STA $A7DB
    LDD #$0BBB
    STB $A7DA
    STA $A7DA

    RTS