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
    CMP CLIPX2
    BCS PLOT5
    BEQ PLOT5
    JMP PLOTP
PLOT5:

    LDA CURRENTMODE
    CMP #8
    BEQ PLOTANTIC8
    ; CMP #9
    ; BEQ PLOTANTIC9
    ; CMP #10
    ; BEQ PLOTANTIC10
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

    ;-------------------------
    ;calc Y-cell
    ;-------------------------
    LDA PLOTY
    TAY                         ;tbl_8,y index

    CLC

    ;------------------------
    ;calc X-cell, divide by 4
    ;------------------------
    LDA PLOTX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOTVBASELO,Y          ;table of $9C40 row base addresses
    ADC PLOT4LO,X              ;+ (4 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT4HI,X
    STA PLOTDEST+1

    ;---------------------------------
    ;get in-cell offset to point (0-3)
    ;---------------------------------
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000011             ;2 lowest bits = (0-3)
    TAX                        ;put into index register

    LDA PLOTY                  ;get PLOTY offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAY                        ;put into index register

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
    LDA (PLOTDEST),y           ;get row with point in it
    ORA PLOTORBIT4,x           ;isolate AND set the point
    STA (PLOTDEST),y           ;write back to $A000
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE4:                          ;handled same way as setting a point
    LDA (PLOTDEST),y            ;just with opposite bit-mask
    AND PLOTANDBIT4,x           ;isolate AND erase the point
    STA (PLOTDEST),y            ;write back to $A000

    JMP PLOTP

PLOTG4:      
    LDA (PLOTDEST),y            
    AND PLOTORBIT4,x            
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

PLOTORBIT4:
    .byte %11000000
    .byte %00110000
    .byte %00001100
    .byte %00000011

