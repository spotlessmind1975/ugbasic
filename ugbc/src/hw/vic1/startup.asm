; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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


CPUMEMMOVE:
    LDY MATHPTR0+1
    BEQ CPUMEMMOVER
    LDY #$0
CPUMEMMOVE2:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    BNE CPUMEMMOVE2
    INC TMPPTR+1
    INC TMPPTR2+1
    DEC MATHPTR0+1
    BNE CPUMEMMOVE2

CPUMEMMOVER:
    LDY #$0
CPUMEMMOVER2:
    LDA (TMPPTR), Y
    STA (TMPPTR2), Y
    INY
    CPY MATHPTR0
    BNE CPUMEMMOVER2
    RTS
    
; VIC1LINES = 312
; VIC1CYCLESPERLINE = 71
; VIC1TIMERVALUE = ( VIC1LINES * VIC1CYCLESPERLINE - 2 ) / 4

; VIC1BANK:       .BYTE 1

VIC1IRQ:

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
    JSR MUSICPLAYER
    JMP $EABF

VIC1STARTUP:
    LDA #<VIC1FREQTABLE
    STA VIC1TMPPTR2
    LDA #>VIC1FREQTABLE
    STA VIC1TMPPTR2+1
    LDA #$0
    STA VIC1TMPPTR
    STA VIC1TMPPTR+1
    STA VIC1JIFFIES
    STA VIC1JIFFIES+1

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
     SEI
     LDA #<VIC1IRQ     ; set the raster IRQ routine pointer
     STA $314
     LDA #>VIC1IRQ
     STA $315
     CLI
;     LDA #$c0
;     STA $912e     ; enable Timer A underflow interrupts

    ; ; bits 4-7 select background color
    ; ; bits 0-2 select border color
    ; ; bit 3 selects inverted or normal mode

    LDA #$08
    STA $900F

    ; Lowercase font
@IF descriptors
    LDA $9005
    AND #$F0
    ORA #$0E
    STA $9005
@ENDIF

    LDA #$0
    STA XCURSYS
    LDA #$0
    STA YCURSYS

    RTS

IMF_TOKEN_WAIT1								= $ff
IMF_TOKEN_WAIT2								= $fe
IMF_TOKEN_CONTROL							= $d0
IMF_TOKEN_PROGRAM_CHANGE					= $e0
IMF_TOKEN_NOTE								= $40

IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO			= $01
IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO			= $02
IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO			= $03
IMF_INSTRUMENT_HONKY_TONK_PIANO				= $04
IMF_INSTRUMENT_ELECTRIC_PIANO1				= $05
IMF_INSTRUMENT_ELECTRIC_PIANO2				= $06
IMF_INSTRUMENT_HARPSICHORD					= $07
IMF_INSTRUMENT_CLAVI						= $08
IMF_INSTRUMENT_CELESTA						= $09
IMF_INSTRUMENT_GLOCKENSPIEL					= $0A
IMF_INSTRUMENT_MUSIC_BOX					= $0B
IMF_INSTRUMENT_VIBRAPHONE					= $0C
IMF_INSTRUMENT_MARIMBA						= $0D
IMF_INSTRUMENT_XYLOPHONE					= $0E
IMF_INSTRUMENT_TUBULAR_BELLS				= $0F
IMF_INSTRUMENT_DULCIMER						= $10
IMF_INSTRUMENT_DRAWBAR_ORGAN				= $11
IMF_INSTRUMENT_PERCUSSIVE_ORGAN				= $12
IMF_INSTRUMENT_ROCK_ORGAN					= $13
IMF_INSTRUMENT_CHURCH_ORGAN					= $14
IMF_INSTRUMENT_REED_ORGAN					= $15
IMF_INSTRUMENT_ACCORDION					= $16
IMF_INSTRUMENT_HARMONICA					= $17
IMF_INSTRUMENT_TANGO_ACCORDION				= $18
IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON			= $19
IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL			= $1A
IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ			= $1B
IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN			= $1C
IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED			= $1D
IMF_INSTRUMENT_OVERDRIVEN_GUITAR			= $1E
IMF_INSTRUMENT_DISTORTION_GUITAR			= $1F
IMF_INSTRUMENT_GUITAR_HARMONICS				= $20
IMF_INSTRUMENT_ACOUSTIC_BASS				= $21
IMF_INSTRUMENT_ELECTRIC_BASS_FINGER			= $22
IMF_INSTRUMENT_ELECTRIC_BASS_PICK			= $23
IMF_INSTRUMENT_FRETLESS_BASS				= $24
IMF_INSTRUMENT_SLAP_BASS_1					= $25
IMF_INSTRUMENT_SLAP_BASS_2					= $26
IMF_INSTRUMENT_SYNTH_BASS_1					= $27
IMF_INSTRUMENT_SYNTH_BASS_2					= $28
IMF_INSTRUMENT_VIOLIN						= $29
IMF_INSTRUMENT_VIOLA						= $2A
IMF_INSTRUMENT_CELLO						= $2B
IMF_INSTRUMENT_CONTRABASS					= $2C
IMF_INSTRUMENT_TREMOLO_STRINGS				= $2D
IMF_INSTRUMENT_PIZZICATO_STRINGS			= $2E
IMF_INSTRUMENT_ORCHESTRAL_HARP				= $2F
IMF_INSTRUMENT_TIMPANI						= $30
IMF_INSTRUMENT_STRING_ENSEMBLE_1			= $31
IMF_INSTRUMENT_STRING_ENSEMBLE_2			= $32
IMF_INSTRUMENT_SYNTHSTRINGS_1				= $33
IMF_INSTRUMENT_SYNTHSTRINGS_2				= $34
IMF_INSTRUMENT_CHOIR_AAHS					= $35
IMF_INSTRUMENT_VOICE_OOHS					= $36
IMF_INSTRUMENT_SYNTH_VOICE					= $37
IMF_INSTRUMENT_ORCHESTRA_HIT				= $38
IMF_INSTRUMENT_TRUMPET						= $39
IMF_INSTRUMENT_TROMBONE						= $3A
IMF_INSTRUMENT_TUBA							= $3B
IMF_INSTRUMENT_MUTED_TRUMPET				= $3C
IMF_INSTRUMENT_FRENCH_HORN					= $3D
IMF_INSTRUMENT_BRASS_SECTION				= $3E
IMF_INSTRUMENT_SYNTHBRASS_1					= $3F
IMF_INSTRUMENT_SYNTHBRASS_2					= $40
IMF_INSTRUMENT_SOPRANO_SAX					= $41
IMF_INSTRUMENT_ALTO_SAX						= $42
IMF_INSTRUMENT_TENOR_SAX					= $43
IMF_INSTRUMENT_BARITONE_SAX					= $44
IMF_INSTRUMENT_OBOE							= $45
IMF_INSTRUMENT_ENGLISH_HORN					= $46
IMF_INSTRUMENT_BASSOON						= $47
IMF_INSTRUMENT_CLARINET						= $48
IMF_INSTRUMENT_PICCOLO						= $49
IMF_INSTRUMENT_FLUTE						= $4A
IMF_INSTRUMENT_RECORDER						= $4B
IMF_INSTRUMENT_PAN_FLUTE					= $4C
IMF_INSTRUMENT_BLOWN_BOTTLE					= $4D
IMF_INSTRUMENT_SHAKUHACHI					= $4E
IMF_INSTRUMENT_WHISTLE						= $4F
IMF_INSTRUMENT_OCARINA						= $50
IMF_INSTRUMENT_LEAD_1_SQUARE				= $51
IMF_INSTRUMENT_LEAD_2_SAWTOOTH				= $52
IMF_INSTRUMENT_LEAD_3_CALLIOPE				= $53
IMF_INSTRUMENT_LEAD_4_CHIFF					= $54
IMF_INSTRUMENT_LEAD_5_CHARANG				= $55
IMF_INSTRUMENT_LEAD_6_VOICE					= $56
IMF_INSTRUMENT_LEAD_7_FIFTHS				= $57
IMF_INSTRUMENT_LEAD_8_BASS_LEAD				= $58
IMF_INSTRUMENT_PAD_1_NEW_AGE				= $59
IMF_INSTRUMENT_PAD_2_WARM					= $5A
IMF_INSTRUMENT_PAD_3_POLYSYNTH				= $5B
IMF_INSTRUMENT_PAD_4_CHOIR					= $5C
IMF_INSTRUMENT_PAD_5_BOWED					= $5D
IMF_INSTRUMENT_PAD_6_METALLIC				= $5E
IMF_INSTRUMENT_PAD_7_HALO					= $5F
IMF_INSTRUMENT_PAD_8_SWEEP					= $60
IMF_INSTRUMENT_FX_1_RAIN					= $61
IMF_INSTRUMENT_FX_2_SOUNDTRACK				= $62
IMF_INSTRUMENT_FX_3_CRYSTAL					= $63
IMF_INSTRUMENT_FX_4_ATMOSPHERE				= $64
IMF_INSTRUMENT_FX_5_BRIGHTNESS				= $65
IMF_INSTRUMENT_FX_6_GOBLINS					= $66
IMF_INSTRUMENT_FX_7_ECHOES					= $67
IMF_INSTRUMENT_FX_8_SCI_FI					= $68
IMF_INSTRUMENT_SITAR						= $69
IMF_INSTRUMENT_BANJO						= $6A
IMF_INSTRUMENT_SHAMISEN						= $6B
IMF_INSTRUMENT_KOTO							= $6C
IMF_INSTRUMENT_KALIMBA						= $6D
IMF_INSTRUMENT_BAG_PIPE						= $6E
IMF_INSTRUMENT_FIDDLE						= $6F
IMF_INSTRUMENT_SHANAI						= $70
IMF_INSTRUMENT_TINKLE_BELL					= $71
IMF_INSTRUMENT_AGOGO						= $72
IMF_INSTRUMENT_STEEL_DRUMS					= $73
IMF_INSTRUMENT_WOODBLOCK					= $74
IMF_INSTRUMENT_TAIKO_DRUM					= $75
IMF_INSTRUMENT_MELODIC_TOM					= $76
IMF_INSTRUMENT_SYNTH_DRUM					= $77
IMF_INSTRUMENT_REVERSE_CYMBAL				= $78
IMF_INSTRUMENT_GUITAR_FRET_NOISE			= $79
IMF_INSTRUMENT_BREATH_NOISE					= $7A
IMF_INSTRUMENT_SEASHORE						= $7B
IMF_INSTRUMENT_BIRD_TWEET					= $7C
IMF_INSTRUMENT_TELEPHONE_RING				= $7D
IMF_INSTRUMENT_HELICOPTER					= $7E
IMF_INSTRUMENT_APPLAUSE						= $7F
IMF_INSTRUMENT_GUNSHOT						= $80

VIC1START:
    LSR
    BCC VIC1START0X
    JSR VIC1START0
VIC1START0X:
    LSR
    BCC VIC1START1X
    JSR VIC1START1
VIC1START1X:
    LSR
    BCC VIC1START2X
    JSR VIC1START2
VIC1START2X:
    RTS

VIC1START0:
VIC1START1:
VIC1START2:
    LDA #$5
    STA $900e
    RTS

VIC1STARTVOL:
    RTS

VIC1FREQ:
    JSR VIC1CALCFREQ
    LSR
    BCC VIC1FREQ0X
    JSR VIC1FREQ0T
VIC1FREQ0X:
    LSR
    BCC VIC1FREQ1X
    JSR VIC1FREQ1T
VIC1FREQ1X:
    LSR
    BCC VIC1FREQ2X
    JSR VIC1FREQ2T
VIC1FREQ2X:
    RTS

VIC1CALCFREQ:
    ; TODO
    RTS

VIC1FREQ0:
    JSR VIC1CALCFREQ
VIC1FREQ0T:
    JMP VIC1PROGFREQ0

VIC1FREQ1:
    JSR VIC1CALCFREQ
VIC1FREQ1T:
    JMP VIC1PROGFREQ1

VIC1FREQ2:
    JSR VIC1CALCFREQ
VIC1FREQ2T:
    JMP VIC1PROGFREQ2

VIC1PROGFREQ:
    LSR
    BCC VIC1PROGFREQ0X
    JSR VIC1PROGFREQ0
VIC1PROGFREQ0X:
    LSR
    BCC VIC1PROGFREQ1X
    JSR VIC1PROGFREQ1
VIC1PROGFREQ1X:
    LSR
    BCC VIC1PROGFREQ2X
    JSR VIC1PROGFREQ2
VIC1PROGFREQ2X:
    RTS

VIC1PROGFREQ0:
    PHA
    TXA
    ORA #$80
    STA $900a
    PLA
    RTS

VIC1PROGFREQ1:
    PHA
    TXA
    ORA #$80
    STA $900b
    PLA
    RTS

VIC1PROGFREQ2:
    PHA
    TXA
    ORA #$80
    STA $900c
    PLA
    RTS

VIC1PROGPULSE:
VIC1PROGPULSE0:
VIC1PROGPULSE1:
VIC1PROGPULSE2:
    RTS

VIC1PROGCTR:
VIC1PROGCTR0:
VIC1PROGCTR1:
VIC1PROGCTR2:
    RTS

VIC1PROGAD:
VIC1PROGAD0:
VIC1PROGAD1:
VIC1PROGAD2:
    RTS

VIC1PROGSR:
VIC1PROGSR0:
VIC1PROGSR1:
VIC1PROGSR2:
    RTS

VIC1STOP:
    LSR
    BCC VIC1STOP0X
    JSR VIC1STOP0
VIC1STOP0X:
    LSR
    BCC VIC1STOP1X
    JSR VIC1STOP1
VIC1STOP1X:
    LSR
    BCC VIC1STOP2X
    JSR VIC1STOP2
VIC1STOP2X:
    RTS

VIC1STOP0:
    LDX #$0
    STX $900a
    RTS

VIC1STOP1:
    LDX #$0
    STX $900b
    RTS

VIC1STOP2:
    LDX #$0
    STX $900c
    RTS

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PHA
    LDA VIC1MUSICREADY
    BEQ MUSICPLAYERQ
    TXA
    PHA
    TYA
    PHA
    JSR MUSICPLAYERR
    PLA
    TAY
    PLA
    TAX
MUSICPLAYERQ:
    PLA
    RTS

MUSICPLAYERR:

; This is the entry point to wait until the waiting jiffies
; are exausted.
MUSICPLAYERL1:
    LDA VIC1JIFFIES
    BEQ MUSICPLAYERL1B
    DEC VIC1JIFFIES
    RTS

; This is the entry point to read the next instruction.
MUSICPLAYERL1B:
    ; Read the next byte.
    JSR MUSICREADNEXTBYTE

    ; Is the file NOT finished?
    CPX #$0
    BNE MUSICPLAYERL1X

MUSICPLAYERL1BD0:
    ; Let's stop the play!
    LDA #$0
    STA VIC1MUSICREADY
    STA VIC1TMPPTR
    STA VIC1TMPPTR+1
    STA VIC1JIFFIES
    LDA #$FF
    JSR VIC1STOP
    
    RTS

; This is the entry point to decode the instruction
; (contained into the A register).
MUSICPLAYERL1X:
    ASL
    BCS MUSICPLAYERL1X0
    JMP MUSICWAIT
MUSICPLAYERL1X0:
    ASL
    ASL
    BCS MUSICPLAYERL1X1
    JMP MUSICNOTEON
MUSICPLAYERL1X1:
    ASL
    BCS MUSICPLAYERL1X2
    JMP MUSICNOTEOFF
MUSICPLAYERL1X2:
    RTS

MUSICWAIT:
    LSR
    STA VIC1JIFFIES
    RTS

MUSICNOTEOFF:
    LSR
    LSR
    LSR
    LSR
    JSR VIC1STOP
    RTS    

MUSICNOTEON:
    LSR
    LSR
    LSR
    PHA
    JSR MUSICREADNEXTBYTE
    ASL
    TAY
    LDA (VIC1TMPPTR2),Y
    TAX
    INY
    LDA (VIC1TMPPTR2),Y
    TAY
    PLA
    JSR VIC1PROGFREQ
    RTS

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE:
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LDY VIC1TMPOFS
    CPY VIC1TMPLEN
    BEQ MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2:
    LDX #$ff
    LDA (VIC1TMPPTR), Y
    INY
    STY VIC1TMPOFS
    RTS

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE:
    ; Is file finished?
    LDA VIC1BLOCKS
    BEQ MUSICREADNEXTBYTEEND

    ; Put the index to 0
    LDY #$0
    STY VIC1TMPOFS

    ; Increment the base address by 256
    INC VIC1TMPPTR+1

    ; Decrement the number of remaining blocks
    DEC VIC1BLOCKS

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    BEQ MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LDY #$FF
    STY VIC1TMPLEN
    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2:
    LDY VIC1LASTBLOCK
    STY VIC1TMPLEN
    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND:
    LDX #$0
    RTS
