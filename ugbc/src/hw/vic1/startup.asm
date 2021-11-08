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
;*                           STARTUP ROUTINE ON VIC-I                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; VIC1LINES = 312
; VIC1CYCLESPERLINE = 71
; VIC1TIMERVALUE = ( VIC1LINES * VIC1CYCLESPERLINE - 2 ) / 4

; VIC1BANK:       .BYTE 1

; VIC1IRQ:

; VIC1IRQX2:
; ;   lda $9114     ; get the NMI timer A value
; ;                 ; (42 to 49 cycles delay at this stage)
; ; ; sta $1e00     ; uncomment these if you want to monitor
; ; ; ldy $9115     ; the reference timer on the screen
; ; ; sty $1e01
; ;   cmp #8        ; are we more than 7 cycles ahead of time?
; ;   bcc VIC1IRQX0
; ;   pha           ; yes, spend 8 extra cycles
; ;   pla
; ;   and #7        ; and reset the high bit
; ; VIC1IRQX0:
; ;   cmp #4
; ;   bcc VIC1IRQX1
; ;   bit $24       ; waste 4 cycles
; ;   and #3
; ; VIC1IRQX1:
;   ; cmp #2        ; spend the rest of the cycles
;   ; bcs *+2
;   ; bcs *+2
;   ; lsr
;   ; bcs *+2       ; now it has taken 82 cycles from the beginning of the IRQ

; ;     LDA VIC1BANK
; ;     BEQ VIC1IRQL4A
; ; VIC1IRQL4B:
; ;     LDA $9004
; ;     CMP #82
; ;     BCS VIC1IRQEX
; ; VIC1IRQL4B1:
; ;     LDA $9004
; ;     CMP #82
; ;     BNE VIC1IRQL4B1
; ;     LDA #$CF
; ;     STA $9005
; ;     LDA #6
; ;     STA $900F
; ;     LDA #0
; ;     STA VIC1BANK    
; ;     JMP VIC1IRQEX
; ; VIC1IRQL4A:    
; ;     LDA $9004
; ;     CMP #0
; ;     BNE VIC1IRQL4A
; ;     LDA #$CD
; ;     STA $9005
; ;     LDA #2
; ;     STA $900F
; ;     LDA #1
; ;     STA VIC1BANK    
; ;     JMP VIC1IRQEX
; ; VIC1IRQEX:
;     JMP $EABF

VIC1STARTUP:

;     LDA #$7f
;     STA $912e     ; disable and acknowledge interrupts
;     STA $912d
;     STA $911e     ; disable NMIs (Restore key)

; ;synchronize with the screen
; VIC1STARTUPSYNC:
;     LDX #28       ; wait for this raster line (times 2)
; VIC1STARTUPSYNC2:
;     CPX $9004
;     BNE VIC1STARTUPSYNC2
;                 ; at this stage, the inaccuracy is 7 clock cycles
;                 ; the processor is in this place 2 to 9 cycles
;                 ; after $9004 has changed
;     LDY #9
;     BIT $24
; VIC1STARTUPSYNC3:
;     LDX $9004
;     TXA
;     BIT $24
;     LDX #24
; VIC1STARTUPSYNC4:
;     DEX
;     BNE VIC1STARTUPSYNC4
;                     ; first spend some time (so that the whole
;     CMP $9004       ; loop will be 2 raster lines)
;     BCS *+2       ; save one cycle if $9004 changed too late
;     DEY
;     BNE VIC1STARTUPSYNC3
; VIC1STARTUPSYNC5:
;                 ; now it is fully synchronized
;                 ; 6 cycles have passed since last $9004 change
;                 ; and we are on line 2(28+9)=74

; VIC1STARTUPTIMERS:
;     LDA #$40      ; enable Timer A free run of both VIAs
;     STA $911b
;     STA $912b

;     LDA #<VIC1TIMERVALUE
;     LDX #>VIC1TIMERVALUE
;     STA $9116     ; load the timer low byte latches
;     STA $9126

;     LDY #7
; VIC1STARTUPTIMERS2:
;     DEY
;     BNE VIC1STARTUPTIMERS2
;     NOP
;     NOP

;     STX $9125     
;                 ; start the IRQ timer A
;                 ; 6560-101: 65 cycles from $9004 change
;                 ; 6561-101: 77 cycles from $9004 change
;     LDY #10       
;                 ; spend some time (1+5*9+4=55 cycles)
; VIC1STARTUPTIMERS3:
;     DEY           
;                 ; before starting the reference timer
;     BNE VIC1STARTUPTIMERS3
;     STX $9115     ; start the reference timer

; VIC1POINTERS:
;     SEI
;     LDA #<VIC1IRQ     ; set the raster IRQ routine pointer
;     STA $314
;     LDA #>VIC1IRQ
;     STA $315
;     CLI
;     LDA #$c0
;     STA $912e     ; enable Timer A underflow interrupts

    ; ; bits 4-7 select background color
    ; ; bits 0-2 select border color
    ; ; bit 3 selects inverted or normal mode

    LDA #$00
    STA $900F

    ; Lowercase font
    LDA $9005
    AND #$F0
    ORA #$0E
    STA $9005

    LDA #$0
    STA XCURSYS
    LDA #$0
    STA YCURSYS

    RTS