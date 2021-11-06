; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                           PLOT ROUTINE ON VIC-I                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTX    = $F7 ; $F8
PLOTY    = $F9
PLOTM    = $FB
PLOTOMA  = $FD
PLOTAMA  = $FC

;--------------

PLOT:
    RTS
;     CLC

;     LDA PLOTY
;     CMP CLIPY2
;     BCC PLOTCLIP2
;     BEQ PLOTCLIP2
;     JMP PLOTP
; PLOTCLIP2:
;     CMP CLIPY1
;     BEQ PLOTCLIP3
;     BCS PLOTCLIP3
;     JMP PLOTP
; PLOTCLIP3:
;     LDA PLOTX+1
;     CMP CLIPX2+1
;     BCC PLOTCLIP4
;     BEQ PLOTCLIP3B
;     JMP PLOTP
; PLOTCLIP3B:
;     LDA PLOTX
;     CMP CLIPX2
;     BCC PLOTCLIP4
;     BEQ PLOTCLIP4
;     JMP PLOTP
; PLOTCLIP4:
;     LDA PLOTX+1
;     CMP CLIPX1+1
;     BCS PLOTCLIP5
;     BEQ PLOTCLIP4B
;     JMP PLOTP
; PLOTCLIP4B:
;     LDA PLOTX
;     CMP CLIPX1
;     BCS PLOTCLIP5
;     BEQ PLOTCLIP5
;     JMP PLOTP
; PLOTCLIP5:

; PLOTMODE:
;     LDA CURRENTMODE
;     ; BITMAP_MODE_STANDARD
;     CMP #1
;     BNE PLOT1X
;     JMP PLOT1
; PLOT1X:
;     ; BITMAP_MODE_EXTENDED
;     CMP #2
;     BNE PLOT2X
;     JMP PLOT2
; PLOT2X:
;     ; TILEMAP_MODE_STANDARD
;     CMP #0
;     BNE PLOT0X
;     JMP PLOT0
; PLOT0X:
;     RTS

; PLOT1:

;     ;-------------------------
;     ;calc Y-cell, divide by 8
;     ;y/8 is y-cell table index
;     ;-------------------------
;     LDA PLOTY
;     LSR                         ;/ 2
;     LSR                         ;/ 4
;     LSR                         ;/ 8
;     TAY                         ;tbl_8,y index

;     CLC

;     ;------------------------
;     ;calc X-cell, divide by 8
;     ;divide 2-byte PLOTX / 8
;     ;------------------------
;     LDA PLOTX
;     ROR PLOTX+1                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2 (rotate C into low byte)
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     LDA PLOTVBASELO,Y          ;table of row base addresses
;     ADC PLOT8LO,X              ;+ (8 * Xcell)
;     STA PLOTDEST               ;= cell address

;     LDA PLOTVBASEHI,Y          ;do the high byte
;     ADC PLOT8HI,X
;     STA PLOTDEST+1

;     CLC

;     TXA
;     ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTCDEST               ;= cell address

;     LDA #0
;     ADC PLOTCVBASEHI,Y          ;do the high byte
;     STA PLOTCDEST+1

;     ;---------------------------------
;     ;get in-cell offset to point (0-7)
;     ;---------------------------------
;     LDA PLOTX                  ;get PLOTX offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAX                        ;put into index register

;     LDA PLOTY                  ;get PLOTY offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAY                        ;put into index register

;     LDA #<PLOTORBIT
;     STA TMPPTR
;     LDA #>PLOTORBIT
;     STA TMPPTR+1

;     CLC
;     TXA
;     ADC TMPPTR
;     STA TMPPTR
;     LDA #0
;     ADC TMPPTR+1
;     STA TMPPTR+1
;     LDY #0
;     LDA (TMPPTR),Y
;     STA PLOTOMA

;     LDA PLOTX
;     AND #$07
;     TAX
;     LDA PLOTANDBIT,X
;     STA PLOTAMA

;     ;---------------------------------
;     ;get in-cell offset to point (0-7)
;     ;---------------------------------
;     LDA PLOTX                  ;get PLOTX offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAX                        ;put into index register

;     LDA PLOTY                  ;get PLOTY offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAY                        ;put into index register

;     JMP PLOTCOMMON

; PLOT2:

;     ;-------------------------
;     ;calc Y-cell, divide by 8
;     ;y/8 is y-cell table index
;     ;-------------------------
;     LDA PLOTY
;     LSR                         ;/ 2
;     LSR                         ;/ 4
;     LSR                         ;/ 8
;     TAY                         ;tbl_8,y index

;     CLC

;     ;------------------------
;     ;calc X-cell, divide by 8
;     ;divide 2-byte PLOTX / 8
;     ;------------------------
;     LDA PLOTX
;     ROR PLOTX+1                ;rotate the high byte into carry flag
;     ROR                        ;lo byte / 2 (rotate C into low byte)
;     LSR                        ;lo byte / 4
;     LSR                        ;lo byte / 8
;     TAX                        ;tbl_8,x index

;     ;----------------------------------
;     ;add x & y to calc cell point is in
;     ;----------------------------------
;     CLC

;     LDA PLOTV2BASELO,Y          ;table of row base addresses
;     ADC PLOT82LO,X              ;+ (8 * Xcell)
;     STA PLOTDEST               ;= cell address

;     LDA PLOTV2BASEHI,Y          ;do the high byte
;     ADC PLOT82HI,X
;     STA PLOTDEST+1

;     CLC

;     TXA
;     ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
;     STA PLOTCDEST               ;= cell address

;     LDA #0
;     ADC PLOTCVBASEHI,Y          ;do the high byte
;     STA PLOTCDEST+1

;     ;---------------------------------
;     ;get in-cell offset to point (0-7)
;     ;---------------------------------
;     LDA PLOTX                  ;get PLOTX offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAX                        ;put into index register

;     LDA PLOTY                  ;get PLOTY offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAY                        ;put into index register

;     LDA #<PLOTORBIT
;     STA TMPPTR
;     LDA #>PLOTORBIT
;     STA TMPPTR+1

;     CLC
;     TXA
;     ADC TMPPTR
;     STA TMPPTR
;     LDA #0
;     ADC TMPPTR+1
;     STA TMPPTR+1
;     LDY #0
;     LDA (TMPPTR),Y
;     STA PLOTOMA

;     LDA PLOTX
;     AND #$07
;     TAX
;     LDA PLOTANDBIT,X
;     STA PLOTAMA

;     ;---------------------------------
;     ;get in-cell offset to point (0-7)
;     ;---------------------------------
;     LDA PLOTX                  ;get PLOTX offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAX                        ;put into index register

;     LDA PLOTY                  ;get PLOTY offset from cell topleft
;     AND #%00000111             ;3 lowest bits = (0-7)
;     TAY                        ;put into index register

;     JMP PLOTCOMMON

; PLOT0:
;     RTS

; PLOTCOMMON:

;     ;----------------------------------------------
;     ;depending on PLOTM, routine draws or erases
;     ;----------------------------------------------

;     LDA PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
;     CMP #0
;     BEQ PLOTE                  ;if = 0 then branch to clear the point
;     CMP #1
;     BEQ PLOTD                  ;if = 1 then branch to draw the point
;     CMP #2
;     BEQ PLOTG                  ;if = 2 then branch to get the point (0/1)
;     CMP #3
;     BEQ PLOTC                  ;if = 3 then branch to get the color index (0...15)
;     JMP PLOTP

; PLOTD:
;     ;---------
;     ;set point
;     ;---------
;     LDA (PLOTDEST),y           ;get row with point in it
;     AND PLOTAMA
;     ORA PLOTOMA              ;isolate AND set the point
;     STA (PLOTDEST),y           ;write back to $A000
;     LDA CURRENTMODE
;     LDY #0
;     LDA _PEN
;     STA (PLOTCDEST),y          ;get row with point in it
; PLOTDE:
;     JMP PLOTP                  ;skip the erase-point section

;     ;-----------
;     ;erase point
;     ;-----------
; PLOTE:                          ;handled same way as setting a point
;     LDA (PLOTDEST),y            ;just with opposite bit-mask
;     AND PLOTAMA             ;isolate AND erase the point
;     STA (PLOTDEST),y            ;write back to $A000
;     JMP PLOTP

; PLOTG:      
;     LDA (PLOTDEST),y            
;     AND PLOTOMA            
;     CMP #0
;     BEQ PLOTG0
; PLOTG1:
;     LDA #$ff
;     STA PLOTM
;     JMP PLOTP
; PLOTG0:
;     LDA #$0
;     STA PLOTM
;     JMP PLOTP            

; PLOTC:                          
;     LDY #0
;     LDA CURRENTMODE

;     LDA (PLOTCDEST),y          ;get row with point in it
;     LSR A
;     LSR A
;     LSR A
;     LSR A
;     STA PLOTM
;     JMP PLOTP            

; PLOTP:
;     RTS

; ;----------------------------------------------------------------

; PLOTORBIT:
;     .byte %10000000
;     .byte %01000000
;     .byte %00100000
;     .byte %00010000
;     .byte %00001000
;     .byte %00000100
;     .byte %00000010
;     .byte %00000001

; PLOTANDBIT:
;     .byte %01111111
;     .byte %10111111
;     .byte %11011111
;     .byte %11101111
;     .byte %11110111
;     .byte %11111011
;     .byte %11111101
;     .byte %11111110
