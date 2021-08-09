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

PLOTX    = $22 ; $23
PLOTY    = $24
PLOTM    = $25

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
    SEI
    LDA #$36
    STA $01
    LDA (PLOTDEST),y           ;get row with point in it
    ORA PLOTORBIT,x            ;isolate AND set the point
    STA (PLOTDEST),y           ;write back to $A000
    LDY #0
    LDA (PLOTCDEST),y          ;get row with point in it
    AND #$0f                   ;isolate AND set the point
    ORA _PEN                   ;isolate OR set the point
    STA (PLOTCDEST),y          ;write back to $A000    
    LDA #$37
    STA $01
    CLI
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTE:                          ;handled same way as setting a point
    LDA #$36
    STA $01
    LDA (PLOTDEST),y            ;just with opposite bit-mask
    AND PLOTANDBIT,x            ;isolate AND erase the point
    STA (PLOTDEST),y            ;write back to $A000
    LDA #$37
    STA $01
    JMP PLOTP

PLOTG:      
    SEI
    LDA #$36
    STA $01
    LDA (PLOTDEST),y            
    AND PLOTORBIT,x            
    CMP #0
    BEQ PLOTG0
PLOTG1:
    LDA #$ff
    STA PLOTM
    LDA #$37
    STA $01    
    CLI
    JMP PLOTP
PLOTG0:
    LDA #$0
    STA PLOTM
    LDA #$37
    STA $01    
    CLI
    JMP PLOTP            

PLOTC:                          
    SEI
    LDA #$36
    STA $01
    LDY #0
    LDA (PLOTCDEST),y          ;get row with point in it
    LSR A
    LSR A
    LSR A
    LSR A
    STA PLOTM
    LDA #$37
    STA $01    
    CLI
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