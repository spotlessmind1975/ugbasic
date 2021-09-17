PLOTX   EQU $41 ; $42
PLOTY   EQU $43
PLOTM   EQU $45
PLOTOMA EQU $46
PLOTAMA EQU $47

;--------------

PLOT

    LDA PLOTY
    CMPA CLIPY2+1
    BLT PLOTCLIP2
    BEQ PLOTCLIP2
    JMP PLOTP
PLOTCLIP2
    CMPA CLIPY1+1
    BEQ PLOTCLIP3
    BGT PLOTCLIP3
    JMP PLOTP
PLOTCLIP3
    LDA PLOTX
    CMPA CLIPX2
    BLT PLOTCLIP4
    BEQ PLOTCLIP3B
    JMP PLOTP
PLOTCLIP3B
    LDA PLOTX+1
    CMPA CLIPX2+1
    BLT PLOTCLIP4
    BEQ PLOTCLIP4
    JMP PLOTP
PLOTCLIP4
    LDA PLOTX
    CMPA CLIPX1
    BGT PLOTCLIP5
    BEQ PLOTCLIP4B
    JMP PLOTP
PLOTCLIP4B
    LDA PLOTX+1
    CMPA CLIPX1+1
    BGT PLOTCLIP5
    BEQ PLOTCLIP5
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
    CMPA #5
    BNE PLOT5X
    JMP PLOT5
PLOT5X
    CMPA #6
    BNE PLOT6X
    JMP PLOT6
PLOT6X
    CMPA #7
    BNE PLOT7X
    JMP PLOT7
PLOT7X
    CMPA #8
    BNE PLOT8X
    JMP PLOT8
PLOT8X
    CMPA #9
    BNE PLOT9X
    JMP PLOT9
PLOT9X
    CMPA #10
    BNE PLOT10X
    JMP PLOT10
PLOT10X
    CMPA #11
    BNE PLOT11X
    JMP PLOT11
PLOT11X
    CMPA #12
    BNE PLOT12X
    JMP PLOT12
PLOT12X
    CMPA #13
    BNE PLOT13X
    JMP PLOT13
PLOT13X
    CMPA #14
    BNE PLOT14X
    JMP PLOT14
PLOT14X
    RTS

PLOT0
PLOT1
    RTS

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
PLOT2
    RTS

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
PLOT3
    RTS

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
PLOT4
    RTS

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
PLOT5
    RTS

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
PLOT6
    RTS

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
PLOT7

    LDX BITMAPADDRESS
    LDB PLOTY
    LDA #0
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    LDD PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT40
    LDB _PEN
    ANDB #$03
    LSLB
    LSLB
    LEAY B, Y
    LDB PLOTX+1
    ANDB #$03
    LEAY B, Y

    LDU #PLOTANDBIT4
    LEAU B, U

    JMP PLOTCOMMON

PLOT8
PLOT9
PLOT10
PLOT11
PLOT12
PLOT13
PLOT14
    RTS

PLOTCOMMON

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
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

    LDA , X           ;get row with point in it
    ANDA , U
    ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE                          ;handled same way as setting a point
    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

PLOTG      
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
    LDA , X           ;get row with point in it
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
