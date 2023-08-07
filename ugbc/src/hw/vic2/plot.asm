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
;
; @thirdparts satpro on lemon64.com
;--------------------------------------------------------------------

PLOTX    = $BA ; $BB
PLOTY    = $BC ; $BD
PLOTM    = $BE
PLOTOMA  = $C0
PLOTAMA  = $BF

;--------------

PLOT:

    CLC

    LDA PLOTY
    CMP CLIPY2
    BCC PLOTCLIP2
    BEQ PLOTCLIP2
    JMP PLOTP
PLOTCLIP2:
    CMP CLIPY1
    BEQ PLOTCLIP3
    BCS PLOTCLIP3
    JMP PLOTP
PLOTCLIP3:
    LDA PLOTX+1
    CMP CLIPX2+1
    BCC PLOTCLIP4
    BEQ PLOTCLIP3B
    JMP PLOTP
PLOTCLIP3B:
    LDA PLOTX
    CMP CLIPX2
    BCC PLOTCLIP4
    BEQ PLOTCLIP4
    JMP PLOTP
PLOTCLIP4:
    LDA PLOTX+1
    CMP CLIPX1+1
    BCS PLOTCLIP5
    BEQ PLOTCLIP4B
    JMP PLOTP
PLOTCLIP4B:
    LDA PLOTX
    CMP CLIPX1
    BCS PLOTCLIP5
    BEQ PLOTCLIP5
    JMP PLOTP
PLOTCLIP5:

PLOTMODE:
    LDA CURRENTMODE
    ; BITMAP_MODE_STANDARD
    CMP #2
    BNE PLOT2X
    JMP PLOT2
PLOT2X:
    ; BITMAP_MODE_MULTICOLOR
    CMP #3
    BNE PLOT3X
    JMP PLOT3
PLOT3X:
    ; TILEMAP_MODE_STANDARD
    CMP #0
    BNE PLOT0X
    JMP PLOT0
PLOT0X:
    ; TILEMAP_MODE_MULTICOLOR
    CMP #1
    BNE PLOT1X
    JMP PLOT1
PLOT1X:
    ; TILEMAP_MODE_EXTENDED
    CMP #4
    BNE PLOT4X
    JMP PLOT4
PLOT4X:
    RTS

PLOT2:

    ;-------------------------
    ;calc Y-cell, divide by 8
    ;y/8 is y-cell table index
    ;-------------------------
    LDA PLOTY
    LSR                         ;/ 2
    LSR                         ;/ 4
    LSR                         ;/ 8
    TAY                         ;tbl_8,y index

    CLC

    ;------------------------
    ;calc X-cell, divide by 8
    ;divide 2-byte PLOTX / 8
    ;------------------------
    LDA PLOTX
    ROR PLOTX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2 (rotate C into low byte)
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    CLC

    TXA
    ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
    STA PLOTCDEST               ;= cell address

    LDA #0
    ADC PLOTCVBASEHI,Y          ;do the high byte
    STA PLOTCDEST+1

    ;---------------------------------
    ;get in-cell offset to point (0-7)
    ;---------------------------------
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAX                        ;put into index register

    LDA PLOTY                  ;get PLOTY offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAY                        ;put into index register

    LDA #<PLOTORBIT
    STA TMPPTR
    LDA #>PLOTORBIT
    STA TMPPTR+1

    CLC
    TXA
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
    LDA PLOTANDBIT,X
    STA PLOTAMA

    ;---------------------------------
    ;get in-cell offset to point (0-7)
    ;---------------------------------
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAX                        ;put into index register

    LDA PLOTY                  ;get PLOTY offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAY                        ;put into index register

    JMP PLOTCOMMON

PLOT3:

    ;-------------------------
    ;calc Y-cell, divide by 8
    ;y/8 is y-cell table index
    ;-------------------------
    LDA PLOTY
    LSR                         ;/ 2
    LSR                         ;/ 4
    LSR                         ;/ 8
    TAY                         ;tbl_8,y index

    CLC

    ;------------------------
    ;calc X-cell, divide by 8
    ;divide 2-byte PLOTX / 8
    ;------------------------
    LDA PLOTX
    ROR PLOTX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2 (rotate C into low byte)
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    ;----------------------------------
    ;add x & y to calc cell point is in
    ;----------------------------------
    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    CLC

    TXA
    ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
    STA PLOTCDEST               ;= cell address

    LDA #0
    ADC PLOTCVBASEHI,Y          ;do the high byte
    STA PLOTCDEST+1

    TXA
    ADC PLOTC2VBASELO,Y          ;table of $8400 row base addresses
    STA PLOTC2DEST               ;= cell address

    LDA #0
    ADC PLOTC2VBASEHI,Y          ;do the high byte
    STA PLOTC2DEST+1

    ;---------------------------------
    ;get in-cell offset to point (0-7)
    ;---------------------------------
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAX                        ;put into index register

    LDA PLOTY                  ;get PLOTY offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAY                        ;put into index register

    LDY #0
    LDA (PLOTCDEST),Y
    LSR
    LSR
    LSR
    LSR
    CMP _PEN
    BEQ PLOT3C1
    LDY #0
    LDA (PLOTCDEST),Y
    AND #$0F
    CMP _PEN
    BEQ PLOT3C2
    LDA (PLOTC2DEST),Y
    AND #$0F
    CMP _PEN
    BEQ PLOT3C3

    LDA LASTCOLOR
    CMP #1
    BEQ PLOT3SC2
    CMP #2
    BEQ PLOT3SC3
    CMP #3
    BEQ PLOT3SC1

PLOT3SC1:
    LDA (PLOTCDEST),Y
    AND #$0f
    STA (PLOTCDEST),Y
    LDA _PEN
    ASL
    ASL
    ASL
    ASL
    ORA (PLOTCDEST),Y
    STA (PLOTCDEST),Y
    LDA #1
    STA LASTCOLOR
PLOT3C1:
    LDA #<PLOTORBIT41
    STA TMPPTR
    LDA #>PLOTORBIT41
    STA TMPPTR+1
    JMP PLOT3PEN

PLOT3SC2:
    LDA (PLOTCDEST),Y
    AND #$f0
    STA (PLOTCDEST),Y
    LDA _PEN
    ORA (PLOTCDEST),Y
    STA (PLOTCDEST),Y
    LDA #2
    STA LASTCOLOR
PLOT3C2:
    LDA #<PLOTORBIT42
    STA TMPPTR
    LDA #>PLOTORBIT42
    STA TMPPTR+1
    JMP PLOT3PEN

PLOT3SC3:
    LDA _PEN
    LDY #0
    STA (PLOTC2DEST),Y
    LDA #3
    STA LASTCOLOR
PLOT3C3:
    LDA #<PLOTORBIT43
    STA TMPPTR
    LDA #>PLOTORBIT43
    STA TMPPTR+1
    JMP PLOT3PEN

PLOT3PEN:

    ;---------------------------------
    ;get in-cell offset to point (0-7)
    ;---------------------------------
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000011             ;2 lowest bits = (0-4)
    TAX                        ;put into index register

    LDA PLOTY                  ;get PLOTY offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAY                        ;put into index register

    CLC
    TXA
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
    LDA PLOTANDBIT4,X
    STA PLOTAMA

    ;---------------------------------
    ;get in-cell offset to point (0-7)
    ;---------------------------------
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000111             ;2 lowest bits = (0-4)
    TAX                        ;put into index register

    LDA PLOTY                  ;get PLOTY offset from cell topleft
    AND #%00000111             ;3 lowest bits = (0-7)
    TAY  

    JMP PLOTCOMMON

PLOT0:
PLOT1:
PLOT4:
    RTS

PLOTCOMMON:

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
    CMP #0
    BEQ PLOTE                  ;if = 0 then branch to clear the point
    CMP #1
    BEQ PLOTD                  ;if = 1 then branch to draw the point
    CMP #2
    BEQ PLOTG                  ;if = 2 then branch to get the point (0/1)
    CMP #3
    BEQ PLOTC                  ;if = 3 then branch to get the color index (0...15)
    JMP PLOTP

PLOTD:
    ;---------
    ;set point
    ;---------
    LDA (PLOTDEST),y           ;get row with point in it
    AND PLOTAMA
    ORA PLOTOMA              ;isolate AND set the point
    STA (PLOTDEST),y           ;write back to $A000
    LDA CURRENTMODE
    CMP #$2
    BNE PLOTDE
    LDY #0
    LDA (PLOTCDEST),y          ;get row with point in it
    AND #$0f                   ;isolate AND set the point
    STA (PLOTCDEST),y          ;get row with point in it
    LDA _PEN
    ASL
    ASL
    ASL
    ASL
    ORA (PLOTCDEST),y          ;write back to $A000    
    STA (PLOTCDEST),y          ;write back to $A000    
PLOTDE:
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    LDA (PLOTDEST),y            ;just with opposite bit-mask
    AND PLOTAMA             ;isolate AND erase the point
    STA (PLOTDEST),y            ;write back to $A000
    JMP PLOTP

PLOTG:      
    LDA (PLOTDEST),y            
    AND PLOTOMA            
    CMP #0
    BEQ PLOTG0
PLOTG1:
    LDA #$ff
    STA PLOTM
    JMP PLOTP
PLOTG0:
    LDA #$0
    STA PLOTM
    JMP PLOTP            

PLOTC:                          
    LDY #0
    LDA CURRENTMODE
    CMP #$3
    BEQ PLOTC3

    LDA (PLOTCDEST),y          ;get row with point in it
    LSR A
    LSR A
    LSR A
    LSR A
    STA PLOTM
    JMP PLOTCE

PLOTC3:
    LDA PLOTX                  ;get PLOTX offset from cell topleft
    AND #%00000011             ;2 lowest bits = (0-4)
    TAX                        ;put into index register
    LDA (PLOTDEST),y            
    AND PLOTOMA
PLOTC3L1:
    CPX #0
    BEQ PLOTC3L1F
    LSR
    LSR
    DEX
    JMP PLOTC3L1

PLOTC3L1F:
    CMP #0
    BEQ PLOTC3B
    CMP #1
    BEQ PLOTC3C1
    CMP #2
    BEQ PLOTC3C2
    CMP #3
    BEQ PLOTC3C3
    JMP PLOTCE

PLOTC3B:
    LDA $D021
    STA PLOTM
    JMP PLOTCE

PLOTC3C1:
    LDY #0
    LDA (PLOTCDEST),Y
    LSR
    LSR
    LSR
    LSR
    STA PLOTM
    JMP PLOTCE

PLOTC3C2:
    LDY #0
    LDA (PLOTCDEST),Y
    AND #$0f
    STA PLOTM
    JMP PLOTCE

PLOTC3C3:
    LDY #0
    LDA (PLOTC2DEST),Y
    AND #$0f
    STA PLOTM
    JMP PLOTCE

PLOTCE:
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

PLOTANDBIT4:
    .byte %00111111
    .byte %11001111
    .byte %11110011
    .byte %11111100
