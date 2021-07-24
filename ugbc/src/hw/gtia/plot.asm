;--------------------------------------------------------------------
;This routine sets or erases a point on the hires $A000 based
;on coordinates AND PLOTM determined before-hand.  you can change
;"$A000" to wherever your hires $A000 is located.
;plotPoint works by first determining which 8x8 cell the point is
;located in AND uses tables to figure that out.
;The in-cell offset is determined by just isolating the lowest 3 bits
;of each point (0-7).  The pixel masking uses tables, too.
;
; Originally posted by satpro on:
; https://www.lemon64.com/forum/viewtopic.php?p=599219#599219
;
; Adapted by Marco Spedaletti for ugbasic
;--------------------------------------------------------------------

PLOTX    = $90 ; $91
PLOTY    = $92
PLOTM    = $93
PLOTOMA  = $94
PLOTAMA  = $95

;--------------

PLOT:

    CLC

    LDA PLOTY
    CMP CLIPY2
    BCC PLOT2
    BEQ PLOT2
    JMP PLOTP
PLOT2:
    CMP CLIPY1
    BEQ PLOT3
    BCS PLOT3
    JMP PLOTP
PLOT3:
    LDA PLOTX+1
    CMP CLIPX2+1
    BCC PLOT4
    BEQ PLOT3B
    JMP PLOTP
PLOT3B:
    LDA PLOTX
    CMP CLIPX2
    BCC PLOT4
    BEQ PLOT4
    JMP PLOTP
PLOT4:
    LDA PLOTX+1
    CMP CLIPX1+1
    BCS PLOT5
    BEQ PLOT4B
    JMP PLOTP
PLOT4B:
    LDA PLOTX
    CMP CLIPX1
    BCS PLOT5
    BEQ PLOT5
    JMP PLOTP
PLOT5:

    LDA CURRENTMODE
    CMP #8
    BEQ PLOTANTIC8
    CMP #9
    BNE PLOTANTIC9X
    JMP PLOTANTIC9
PLOTANTIC9X:
    CMP #10
    BNE PLOTANTIC10X
    JMP PLOTANTIC10
PLOTANTIC10X:
    ; CMP #11
    ; BEQ PLOTANTIC11
    ; CMP #13
    ; BEQ PLOTANTIC13
    ; CMP #15
    ; BEQ PLOTANTIC15
    ; CMP #12
    ; BEQ PLOTANTIC12
    ; CMP #14
    ; BEQ PLOTANTIC14
    JMP PLOTP

; Graphics 3 (ANTIC 8)
; This four-color graphics mode turns a split screen into 20 rows of 40 graphics cells or pixels. 
; Each pixel is 8 x 8 or the size of a normal character. The data in each pixel is encoded as two bit pairs, 
; four per byte. The four possible bit pair combinations 00, 01, 10, and 11 point to one of the four color registers. 
; The bits 00 is assigned to the background color register and the rest refer to the three foreground color registers. 
; When the CTIA/GTIA chip interprets the data for the four adjacent pixels stored within the byte, it refers to the color 
; register encoded in the bit pattern to plot the color.

PLOTANTIC8:

    LDA _PEN
    CMP $2C5
    BEQ PLOTANTIC8C1
    CMP $2C6
    BEQ PLOTANTIC8C2
    CMP $2C7
    BEQ PLOTANTIC8C3

    LDA LASTCOLOR
    CMP #1
    BEQ PLOTANTIC8SC1
    CMP #2
    BEQ PLOTANTIC8SC2
    CMP #3
    BEQ PLOTANTIC8SC3

    LDA #1
    STA LASTCOLOR
    JMP PLOTANTIC8SC1

; PLOTANTIC8SC0:
;     LDA _PEN
;     STA $2C4
;     INC LASTCOLOR
; PLOTANTIC8C0:
;     LDA #<PLOTORBIT40
;     STA TMPPTR
;     LDA #>PLOTORBIT40
;     STA TMPPTR+1
;     JMP PLOTANTIC8PEN

PLOTANTIC8SC1:
    LDA _PEN
    STA $2C5
    INC LASTCOLOR
PLOTANTIC8C1:
    LDA #<PLOTORBIT41
    STA TMPPTR
    LDA #>PLOTORBIT41
    STA TMPPTR+1
    JMP PLOTANTIC8PEN

PLOTANTIC8SC2:
    LDA _PEN
    STA $2C6
    INC LASTCOLOR
PLOTANTIC8C2:
    LDA #<PLOTORBIT42
    STA TMPPTR
    LDA #>PLOTORBIT42
    STA TMPPTR+1
    JMP PLOTANTIC8PEN

PLOTANTIC8SC3:
    LDA _PEN
    STA $2C7
    LDA #1
    STA LASTCOLOR
PLOTANTIC8C3:
    LDA #<PLOTORBIT43
    STA TMPPTR
    LDA #>PLOTORBIT43
    STA TMPPTR+1
    JMP PLOTANTIC8PEN

PLOTANTIC8PEN:

    CLC

    ;------------------------
    ;calc X-cell, divide by 4
    ;------------------------
    LDA PLOTX
    AND #$03

    CLC

    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1
    LDY #0
    LDA (TMPPTR),Y
    STA PLOTOMA

    LDA PLOTX
    AND #$03
    TAX
    LDA PLOTANDBIT4,x
    STA PLOTAMA

    LDA PLOTX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA PLOTY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    ADC PLOT4LO,X              ;+ (4 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOT4VBASEHI,Y          ;do the high byte
    ADC PLOT4HI,X
    STA PLOTDEST+1
    
    JMP PLOTGENERIC

; Graphics 4 (ANTIC 9)
; This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
; pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
; color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
; Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
; memory is needed for a display of similiar-sized pixels.
; 80x48, 2 colors

PLOTANTIC9:

    LDA _PEN
    CMP $2C5
    BEQ PLOTANTIC9C1

PLOTANTIC9SC1:
    LDA _PEN
    STA $2C5
PLOTANTIC9C1:
    LDA #<PLOTORBIT21
    STA TMPPTR
    LDA #>PLOTORBIT21
    STA TMPPTR+1
    JMP PLOTANTIC9PEN

PLOTANTIC9PEN:

    CLC

    ;------------------------
    ;calc X-cell, divide by 8
    ;------------------------
    LDA PLOTX
    AND #$07

    CLC

    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1
    LDY #0
    LDA (TMPPTR),Y
    STA PLOTOMA

    LDA PLOTX
    AND #$07
    TAX
    LDA PLOTANDBIT2,x
    STA PLOTAMA

    LDA PLOTX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA PLOTY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT4VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1
    
    JMP PLOTGENERIC

; Graphics 5 (ANTIC A or 10)
; This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
; the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
; about 1K.
; 80x48, 4 colors

PLOTANTIC10:

    LDA _PEN
    CMP $2C5
    BEQ PLOTANTIC10C1
    CMP $2C6
    BEQ PLOTANTIC10C2
    CMP $2C7
    BEQ PLOTANTIC10C3

    LDA LASTCOLOR
    CMP #1
    BEQ PLOTANTIC10SC1
    CMP #2
    BEQ PLOTANTIC10SC2
    CMP #3
    BEQ PLOTANTIC10SC3

    LDA #1
    STA LASTCOLOR
    JMP PLOTANTIC10SC1

; PLOTANTIC8SC0:
;     LDA _PEN
;     STA $2C4
;     INC LASTCOLOR
; PLOTANTIC8C0:
;     LDA #<PLOTORBIT40
;     STA TMPPTR
;     LDA #>PLOTORBIT40
;     STA TMPPTR+1
;     JMP PLOTANTIC8PEN

PLOTANTIC10SC1:
    LDA _PEN
    STA $2C5
    INC LASTCOLOR
PLOTANTIC10C1:
    LDA #<PLOTORBIT41
    STA TMPPTR
    LDA #>PLOTORBIT41
    STA TMPPTR+1
    JMP PLOTANTIC10PEN

PLOTANTIC10SC2:
    LDA _PEN
    STA $2C6
    INC LASTCOLOR
PLOTANTIC10C2:
    LDA #<PLOTORBIT42
    STA TMPPTR
    LDA #>PLOTORBIT42
    STA TMPPTR+1
    JMP PLOTANTIC10PEN

PLOTANTIC10SC3:
    LDA _PEN
    STA $2C7
    LDA #1
    STA LASTCOLOR
PLOTANTIC10C3:
    LDA #<PLOTORBIT43
    STA TMPPTR
    LDA #>PLOTORBIT43
    STA TMPPTR+1
    JMP PLOTANTIC10PEN

PLOTANTIC10PEN:

    CLC

    ;------------------------
    ;calc X-cell, divide by 4
    ;------------------------
    LDA PLOTX
    AND #$03

    CLC

    ADC TMPPTR
    STA TMPPTR
    LDA #0
    ADC TMPPTR+1
    STA TMPPTR+1
    LDY #0
    LDA (TMPPTR),Y
    STA PLOTOMA

    LDA PLOTX
    AND #$03
    TAX
    LDA PLOTANDBIT4,x
    STA PLOTAMA

    LDA PLOTX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA PLOTY
    TAY                         ;tbl_8,y index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1
    
    JMP PLOTGENERIC

PLOTGENERIC:

    ;---------------------------------
    ;get in-cell offset to point (0-3)
    ;---------------------------------
    ; LDA PLOTX                  ;get PLOTX offset from cell topleft
    ; AND #%00000011             ;2 lowest bits = (0-3)
    ; TAX                        ;put into index register

    ; LDA PLOTY                  ;get PLOTY offset from cell topleft
    ; AND #%00000111             ;3 lowest bits = (0-7)
    ; TAY                        ;put into index register

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
    CMP #0
    BEQ PLOTE4                  ;if = 0 then branch to clear the point
    CMP #1
    BEQ PLOTD4                  ;if = 1 then branch to draw the point
    CMP #2
    BEQ PLOTG4                  ;if = 2 then branch to get the point (0...3)
    CMP #3
    BEQ PLOTC4                  ;if = 3 then branch to get the color index (0...15)
    JMP PLOTP

PLOTD4:
    ;---------
    ;set point
    ;---------
    LDY #0
    LDA (PLOTDEST),y           ;get row with point in it
    AND PLOTAMA
    ORA PLOTOMA
    STA (PLOTDEST),y           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE4:                          ;handled same way as setting a point
    LDY #0
    LDA (PLOTDEST),y            ;just with opposite bit-mask
    AND PLOTAMA
    STA (PLOTDEST),y            ;write back to $A000

    JMP PLOTP

PLOTG4:      
    LDY #0
    LDA (PLOTDEST),y            
    AND PLOTAMA
    ORA PLOTOMA
    CPX #0
    BEQ PLOTG0
PLOTG1:
    LSR A
    LSR A
    DEX
    BNE PLOTG1
PLOTG0:
    STA PLOTM
    JMP PLOTP            

PLOTC4:
    JSR PLOTG4
    LDX PLOTM
    JMP PLOTP            

PLOTP:
    RTS

;----------------------------------------------------------------

PLOTORBIT:
    .byte %10000000
    .byte %01000000
    .byte %00100000
    .byte %00010000
    .byte %00001000
    .byte %00000100
    .byte %00000010
    .byte %00000001

PLOTANDBIT:
    .byte %01111111
    .byte %10111111
    .byte %11011111
    .byte %11101111
    .byte %11110111
    .byte %11111011
    .byte %11111101
    .byte %11111110

PLOTANDBIT4:
    .byte %00111111
    .byte %11001111
    .byte %11110011
    .byte %11111100

PLOTORBIT40:
    .byte %00000000
    .byte %00000000
    .byte %00000000
    .byte %00000000

PLOTORBIT41:
    .byte %01000000
    .byte %00010000
    .byte %00000100
    .byte %00000001

PLOTORBIT42:
    .byte %10000000
    .byte %00100000
    .byte %00001000
    .byte %00000010

PLOTORBIT43:
    .byte %11000000
    .byte %00110000
    .byte %00001100
    .byte %00000011

PLOTORBIT21:
    .byte %10000000
    .byte %01000000
    .byte %00100000
    .byte %00010000
    .byte %00001000
    .byte %00000100
    .byte %00000010
    .byte %00000001

PLOTANDBIT2:
    .byte %01111111
    .byte %10111111
    .byte %11011111
    .byte %11101111
    .byte %11110111
    .byte %11111011
    .byte %11111101
    .byte %11111110
