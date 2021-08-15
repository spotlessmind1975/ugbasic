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

RASTERLO = $90
RASTERHI = $92

;--------------

RASTERAT:
    SEI
    LDA TMPPTR
    STA $200
    LDA TMPPTR+1
    STA $201

    LDA $0230
    STA TMPPTR
    LDA $0231
    STA TMPPTR+1

    CLC
    LDA RASTERLO
    ADC #6
    STA RASTERLO

    LDY #5
RASTERATL2A:
    INY
RASTERATL3:
    LDA (TMPPTR),Y
    AND #$7F
    STA (TMPPTR),Y
    CPY RASTERLO
    BNE RASTERATL2A
    ORA #$80
    STA (TMPPTR),Y

    LDA #$C0
    STA $D40E
    CLI
    RTS
