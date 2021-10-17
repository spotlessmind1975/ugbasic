PLOTX   EQU $41 ; $42
PLOTY   EQU $43
PLOTM   EQU $45
PLOTOMA EQU $46
PLOTAMA EQU $47

;--------------

PLOT
    LDD <PLOTY
    CMPD CLIPY2
    BLE PLOTCLIP2
    JMP PLOTP
PLOTCLIP2
    CMPD CLIPY1
    BGE PLOTCLIP3
    JMP PLOTP
PLOTCLIP3
    LDD <PLOTX
    CMPD CLIPX2
    BLE PLOTCLIP4
    JMP PLOTP
PLOTCLIP4
    CMPD CLIPX1
    BGE PLOTCLIP5
    JMP PLOTP
PLOTCLIP5

PLOTMODE
    LDA CURRENTMODE
    CMPA #0
    BNE PLOT0X
    JMP PLOT0
PLOT0X
    CMPA #1
    BNE PLOT1X
    JMP PLOT1
PLOT1X
    CMPA #2
    BNE PLOT2X
    JMP PLOT2
PLOT2X
    CMPA #3
    BNE PLOT3X
    JMP PLOT3
PLOT3X
    CMPA #4
    BNE PLOT4X
    JMP PLOT4
PLOT4X
    RTS

PLOT0
PLOT1
PLOT3
PLOT2
PLOT4

    LDX BITMAPADDRESS

    ANDCC #$FE
    LDD <PLOTY
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA

    TFR D, Y

    ANDCC #$FE
    LDD <PLOTY
    LSLB
    ROLA
    LSLB
    ROLA

    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA

    LEAY D, Y
    TFR Y, D
    LEAX D, X

    ANDCC #$FE
    LDD <PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    ANDCC #$FE
    LDA _PEN
    ANDA #$0F
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    
    LDY #PLOTORBIT
    LDB <(PLOTX+1)
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    JMP PLOTCOMMON

PLOTCOMMON

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA <PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
    CMPA #0
    BEQ PLOTE                  ;if = 0 then branch to clear the point
    CMPA #1
    BEQ PLOTD                  ;if = 1 then branch to draw the point
    CMPA #2
    BEQ PLOTG                  ;if = 2 then branch to get the point (0/1)
    CMPA #3
    BEQ PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JMP PLOTP

PLOTD
    ;---------
    ;set point
    ;---------

    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA , X           ;get row with point in it
    ANDA , U
    ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000

    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDA , X           ;get row with point in it
    ANDA #$0F
    ORA <MATHPTR5
    STA , X           ;write back to $A000

    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE                          ;handled same way as setting a point
    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000

    JMP PLOTP                  ;skip the erase-point section

PLOTG      
    LDA $a7c0
    ORA #$01
    STA $a7c0

    LDA , X           ;get row with point in it
    ANDA , U

    CMPA #0
    BEQ PLOTG0
PLOTG1
    LDA #$ff
    STA PLOTM
    JMP PLOTP
PLOTG0
    LDA #$0
    STA PLOTM
    JMP PLOTP            

PLOTC
    LDA $a7c0
    ANDA #$fe
    STA $a7c0

    LDA , X           ;get row with point in it
    LSRA
    LSRA
    LSRA
    LSRA
    STA PLOTM
    JMP PLOTP

PLOTP
    RTS

;----------------------------------------------------------------

PLOTORBIT
    fcb %10000000
    fcb %01000000
    fcb %00100000
    fcb %00010000
    fcb %00001000
    fcb %00000100
    fcb %00000010
    fcb %00000001

PLOTANDBIT
    fcb %01111111
    fcb %10111111
    fcb %11011111
    fcb %11101111
    fcb %11110111
    fcb %11111011
    fcb %11111101
    fcb %11111110

PLOTORBIT40
    fcb %00000000
    fcb %00000000
    fcb %00000000
    fcb %00000000

PLOTORBIT41
    fcb %01000000
    fcb %00010000
    fcb %00000100
    fcb %00000001

PLOTORBIT42
    fcb %10000000
    fcb %00100000
    fcb %00001000
    fcb %00000010

PLOTORBIT43
    fcb %11000000
    fcb %00110000
    fcb %00001100
    fcb %00000011

PLOTANDBIT4
    fcb %00111111
    fcb %11001111
    fcb %11110011
    fcb %11111100
