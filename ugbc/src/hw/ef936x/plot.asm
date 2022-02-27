; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
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
;*                           PLOT ROUTINE FOR EF936X                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                     mc6809 optimization by Samuel Devulder                  *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTX   EQU $41 ; $42
PLOTY   EQU $43
PLOTM   EQU $45
PLOTOMA EQU $46
PLOTAMA EQU $47

;--------------

PLOTP
    RTS
    
; input X=X coord, U=Y coord, A=(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
; output B result if A=2 or 3
PLOT

    CMPX CLIPX2
    BGT PLOTP
    CMPX CLIPX1   ; check if plotting out of clipped area
    BLT PLOTP     ; yes => return

    CMPU CLIPY2
    BGT PLOTP
    CMPU CLIPY1
    BLT PLOTP

    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    LBEQ PLOTORIG

; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

PLOTDB

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

PLOTMODEDB
    LDA CURRENTMODE
    CMPA #0
    BNE PLOT0XDB
    JMP PLOT0DB
PLOT0XDB
    CMPA #1
    BNE PLOT1XDB
    JMP PLOT1DB
PLOT1XDB
    CMPA #2
    BNE PLOT2XDB
    JMP PLOT2DB
PLOT2XDB
    CMPA #3
    BNE PLOT3XDB
    JMP PLOT3DB
PLOT3XDB
    CMPA #4
    BNE PLOT4XDB
    JMP PLOT4DB
PLOT4XDB
    RTS

PLOT0DB
PLOT1DB
PLOT2DB
PLOT4DB

    ANDCC #$FE
    LDD <PLOTX
    LSRA
    RORB
    LSRA
    RORB
    LSRA
    RORB
    LEAX D, X

    LDY #PLOTORBIT
    LDB <(PLOTX+1)
    ANDB #$07
    LEAY B, Y

    LDU #PLOTANDBIT
    LEAU B, U

    JMP PLOTCOMMONDB

PLOT3DB

    LDD <(PLOTY)
    LSLB
    ROLA
    ADDD #PLOTVBASE
    TFR D, X
    LDD , X
    TFR D, X

    LDB <(PLOTX+1)
    LSRB
    LSRB
    LEAX B, X

    LDB <(PLOTX+1)
    ANDB #$03
    ; COMB
    ; LDY #3
    LEAY B, Y
    TFR Y, D
    LSRB

;     ANDB #$01
;     CMPB #$01
;     BEQ PLOT3PAGE1

; PLOT3PAGE0

;     LDA $a7c0
;     ORA #$01
;     STA $a7c0

;     JMP PLOT3PAGEF

; PLOT3PAGE1

;     LDA $a7c0
;     ANDA #$fe
;     STA $a7c0

;     JMP PLOT3PAGEF

; PLOT3PAGEF

    JMP PLOTCOMMONDB

PLOTCOMMONDB

    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------

    LDA <PLOTM                  ;(0 = erase, 1 = set, 2 = get pixel, 3 = get color)
    CMPA #0
    BNE PLOTEXDB                  ;if = 0 then branch to clear the point
    JMP PLOTEDB
PLOTEXDB
    CMPA #1
    BNE PLOTDXDB                  ;if = 1 then branch to draw the point
    JMP PLOTDDB
PLOTDXDB
    CMPA #2
    BEQ PLOTGXDB                  ;if = 2 then branch to get the point (0/1)
    JMP PLOTGDB
PLOTGXDB
    CMPA #3
    BEQ PLOTCXDB                  ;if = 3 then branch to get the color index (0...15)
    JMP PLOTCDB
PLOTCXDB
    JMP PLOTP

PLOTDDB

    LDA CURRENTMODE
    CMPA #0
    BNE PLOTD0XDB
    JMP PLOTD0DB
PLOTD0XDB
    CMPA #1
    BNE PLOTD1XDB
    JMP PLOTD1DB
PLOTD1XDB
    CMPA #2
    BNE PLOTD2XDB
    JMP PLOTD2DB
PLOTD2XDB
    CMPA #3
    BNE PLOTD3XDB
    JMP PLOTD3DB
PLOTD3XDB
    JMP PLOTP

PLOTD0DB
PLOTD1DB
PLOTD4DB

    ANDCC #$FE
    LDA _PEN
    ANDA #$0F
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    
    ;---------
    ;set point
    ;---------

    ; LDA $a7c0
    ; ORA #$01
    ; STA $a7c0

    LDA , X           ;get row with point in it
    ANDA , U
    ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000

    ; LDA $a7c0
    ; ANDA #$fe
    ; STA $a7c0

    LDA , X           ;get row with point in it
    ANDA #$0F
    ORA <MATHPTR5
    STA , X           ;write back to $A000

    JMP PLOTP                  ;skip the erase-point section

PLOTD2DB

    LDA _PEN
    ANDA #$03
    STA <MATHPTR5

    ;---------
    ;set point
    ;---------

    ; LDA $a7c0
    ; ORA #$01
    ; STA $a7c0

    LDA <MATHPTR5
    ANDA #$02
    CMPA #$02
    BNE PLOTD21DB

PLOTD20DB
    LDA , X           ;get row with point in it
    ANDA , U
    ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000
    JMP PLOTD22DB

PLOTD21DB
    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000
    JMP PLOTD22DB

PLOTD22DB
    ; LDA $a7c0
    ; ANDA #$fe
    ; STA $a7c0

    LDA <MATHPTR5
    ANDA #$01
    CMPA #$01
    BNE PLOTD24DB

PLOTD23DB
    LDA , X           ;get row with point in it
    ANDA , U
    ORA , Y               ;isolate AND set the point
    STA , X           ;write back to $A000
    JMP PLOTD25DB

PLOTD24DB
    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000
    JMP PLOTD25DB

PLOTD25DB
    JMP PLOTP                  ;skip the erase-point section

PLOTD3DB

    LDA _PEN
    ANDA #$0F
    STA <MATHPTR5

    ;---------
    ;set point
    ;---------

    LDB <(PLOTX+1)
    ANDB #$01
    CMPB #$01
    BEQ PLOTD3LODB

PLOTD3HIDB

    LDA <MATHPTR5
    ASLA
    ASLA
    ASLA
    ASLA
    STA <MATHPTR5
    LDA , X
    ORA <MATHPTR5
    STA , X
    JMP PLOTD3FDB

PLOTD3LODB

    LDA , X
    ORA <MATHPTR5
    STA , X
    JMP PLOTD3FDB

PLOTD3FDB
    JMP PLOTP                  ;skip the erase-point section

    ;-----------
    ;erase point
    ;-----------
PLOTEDB                          ;handled same way as setting a point
    ; LDA $a7c0
    ; ORA #$01
    ; STA $a7c0

    LDA , X           ;get row with point in it
    ANDA , U
    STA , X           ;write back to $A000

    JMP PLOTP                  ;skip the erase-point section

PLOTGDB      
    ; LDA $a7c0
    ; ORA #$01
    ; STA $a7c0

    LDA , X           ;get row with point in it
    ANDA , U

    CMPA #0
    BEQ PLOTG0DB
PLOTG1DB
    LDA #$ff
    STA PLOTM
    JMP PLOTP
PLOTG0DB
    LDA #$0
    STA PLOTM
    JMP PLOTP            

PLOTCDB
    ; LDA $a7c0
    ; ANDA #$fe
    ; STA $a7c0

    LDA , X           ;get row with point in it
    LSRA
    LSRA
    LSRA
    LSRA
    STA PLOTM
    JMP PLOTP

	RTS

PLOTORBIT4
    fcb %00000001
    fcb %00010000
    fcb %00000010
    fcb %00100000
    fcb %00000100
    fcb %01000000
    fcb %00001000
    fcb %10000000

PLOTANDBIT4
    fcb %11111110
    fcb %11101111
    fcb %11111101
    fcb %11011111
    fcb %11111011
    fcb %10111111
    fcb %11110111
    fcb %01111111

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

PLOTORIG

    STX <PLOTX
    STU <PLOTY
    STA <PLOTM
    
    LDB <PLOTY+1
    LDA #40
    MUL           ; no => compute video adress
    ADDD BITMAPADDRESS ; 7
    TFR D,X       ; 6
    
    LDU #$A7C0    ; that adress is handy
    
PLOTMODE
    LDA CURRENTMODE
    CMPA #3       ; mode 3 ?
    BNE PLOT0     ; no => goto common adress decoding

PLOT3             ; yes
    LDA ,U
    ORA #1        ; prepare A for plane 1
    
    LDB <PLOTX+1
    LSRB
    LSRB          ; carry = bit2
    ABX           ; adjust for X position

    SBCA #0       ; chose plane 0/1 according bit 2 of X coordinate
    STA ,U        ; select proper plane
    
    BRA PLOTCOMMON
    
PLOTD             ; plot draw (placed here to keep the jump small)
    LDA CURRENTMODE
    CMPA #2
    BEQ PLOTD2    ; plot in mode 2
    CMPA #3
    BEQ PLOTD3    ; plot in mode 3

PLOTD0
PLOTD1
PLOTD4     
    LDA _PEN      ; other modes - asked color
    EORA ,X       ; compare with bg colo
    ANDA #$0F
    BEQ PLOTE     ; equal ? yes ==> erase pixel
    
    LDA _PEN      ; no ==> regular plot
    LSLA          
    LSLA
    LSLA
    LSLA
    STA PLOTD4x+1 ; prepare paper colo
    
    LDA ,X        ; get color pair
    ANDA #$0F     ; clear paper color
PLOTD4x
    ORA #0        ; add current paper color
    STA ,X        ; set color
    
    ;---------
    ;set point
    ;---------
    INC ,U        ; form plane
    LDA ,X        ; get byte
    ORA ,Y        ; set bit
    STA ,X        ; write back to video memory
    RTS           ; done

    ;-----------
    ;erase point
    ;-----------
PLOTE
    INC ,U        ; form plane
    LDA ,X        ; get bit mask
    ANDA 8,Y      ; clear bit
    STA ,X        ; write back to video memory
    RTS           ; done
   
PLOT0
PLOT1
PLOT2
PLOT4
    LDD <PLOTX    ; common adress calculation for modes
    LSRA          ; 0/1/2/4
    RORB
    LSRB
    LSRB          ; B = PLOTX/8
    ABX           ; adjust for X position
    
    LDY #PLOTORBIT
    LDB <(PLOTX+1)
    ANDB #$07
    LEAY B,Y      ; Y point to "OR" bitmask, Y+8 to "AND" bitmask

    LDB ,U        ; select color plane
    ANDB #254
    STB ,U

PLOTCOMMON
    ;----------------------------------------------
    ;depending on PLOTM, routine draws or erases
    ;----------------------------------------------
    LDA <PLOTM    ; (0 = erase, 1 = set, 2 = get pixel, 3 = get color)
    BEQ PLOTE       
    DECA            
    BEQ PLOTD     ; if = 1 then branch to draw the point
    DECA            
    BEQ PLOTG     ; if = 2 then branch to get the point (0/1)
    DECA            
    BEQ PLOTC     ; if = 3 then branch to get the color index (0...15)
    RTS

PLOTD2            ; Draw point with mode 2 (we are in plane0)
    LDA ,X        ; get row with point in it
    LDB _PEN      
    LSRB          ; b0 of PEN set ?
    BCC PLOTD21   ; no => clear bit
    ORA ,Y        ; yes => set bit
    BRA PLOTD22
PLOTD21
    ANDA 8,Y
PLOTD22
    STA ,X        ; write back to video memory

    INC ,U        ; plane 1
    LDA ,X        ; get mask with point in it
    LSRB          ; b1 of PEN set ?
    BCC PLOTD24   ; no => clear BIT
    ORA ,Y        ; yes => set BIT
    BRA PLOTD25
PLOTD24
    ANDA 8,Y
PLOTD25
    STA ,X        ; write back to video memory
    RTS           ; done

PLOTD3
    LDA _PEN      ; Draw point in mode 3
    ANDA #$0F     ; isolate color
    LDB <(PLOTX+1)
    LSRB          ; odd column ?
    BCS PLOTD3LO  ; yes => set low nibble

PLOTD3HI
    ASLA          ; no => set high nibble
    ASLA
    ASLA
    ASLA
    STA PLOTD3nibble+1
    LDA ,X
    ANDA #$0F
PLOTD3nibble
    ORA #$55
    STA ,X
    RTS           ; done

PLOTD3LO
    STA PLOTD3nibble+1
    LDA ,X
    ANDA #$F0
    BRA PLOTD3nibble

PLOTG             ; get point $00=unset $ff=set
    LDA CURRENTMODE
    CMPA #2
    BEQ PLOTG2
    CMPA #3
    BEQ PLOTG3
    INC ,U        ; plane 1
    LDB ,X        ; get row with point in it
    ANDB ,Y       ; bit set ?
PLOTG0
    BEQ PLOTG1    ; no => return 0
    LDB #$FF      ; yes => return true
PLOTG1
;   STB <PLOTM
    RTS
PLOTG2
PLOTG3
    BSR PLOTC     ; get current color
    EORB _PAPER   ; same as paper ?
    ANDB #$0F     ; yes => return 0
    BRA PLOTG0    ; no => return true

; Get pixel color according to video mode
PLOTC
    LDA CURRENTMODE
    CMPA #2
    BEQ PLOT2C    ; mode 2 specific
    CMPA #3
    BEQ PLOT3C    ; mode 3 specific
PLOT0C
PLOT1C
PLOT4C            ; modes 0/1/4
    LDB ,X        ; get color byte
    INC ,U        ; bitmask plane
    LDA ,X        ; get pixels byte
    ANDA ,Y       ; bit set ?
    BEQ PLOTC01   ; no => get lowwer nibble
PLOTC00    
    LSRB          ; yes => get upper nibble
    LSRB
    LSRB
    LSRB
PLOTC01
    ANDB #15      ; result in B
;   STB <PLOTM
    RTS

PLOT2C
    CLRB          ; mode 2 - clear all bits
    LDA ,X        ; get bitmask at plane0
    ANDA ,Y       ; point set ?   
    BEQ PLOT2C0   ; no => skip
    INCB          ; yes => set b0
PLOT2C0
    INC ,U        ; bit plane 1
    LDA ,X        ; get bitmask
    ANDA ,Y       ; point set ?
    BEQ PLOT2C1   ; no => skip
    ORB #2        ; yes => set b1
PLOT2C1    
;   STB <PLOTM
    RTS           ; result in B

PLOT3C
    LDB ,X        ; mode 3 - get color pair
    LDA <PLOTX+1
    LSRA
    BCS PLOTC01   ; odd column => lower nibble
    BRA PLOTC00   ; even column => upper nibble

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

