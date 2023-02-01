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
;*                           STARTUP ROUTINE ON AY-3-8910                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF MSX
PSG_AP: EQU          $a0
PSG_WP: EQU          $a1
PSG_RP: EQU          $a2
@ENDIF

; @IF CPC
; PSG_AP0: EQU          $F600
; PSG_AP1: EQU          $F6C0
; PSG_WP0: EQU          $F400
; PSG_WP1: EQU          $F680
; PSG_RP0: EQU          $F400
; PSG_RP1: EQU          $F440
; @ENDIF

; @IF LM80C
; PSG_AP: EQU          $40
; PSG_WP: EQU          $41
; PSG_RP: EQU          $41
; @ENDIF

PSG_R0: EQU          0
PSG_R1: EQU          1
PSG_R2: EQU          2
PSG_R3: EQU          3
PSG_R4: EQU          4
PSG_R5: EQU          5
PSG_R6: EQU          6
PSG_R7: EQU          7
PSG_R8: EQU          8
PSG_R9: EQU          9
PSG_R10: EQU          10
PSG_R11: EQU          11
PSG_R12: EQU          12
PSG_R13: EQU          13
PSG_R14: EQU          14
PSG_R15: EQU          15

IMF_TOKEN_WAIT1:								EQU $ff
IMF_TOKEN_WAIT2:								EQU $fe
IMF_TOKEN_CONTROL:							EQU $d0
IMF_TOKEN_PROGRAM_CHANGE:					EQU $e0
IMF_TOKEN_NOTE:								EQU $40

IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:			EQU $01
IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:			EQU $02
IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:			EQU $03
IMF_INSTRUMENT_HONKY_TONK_PIANO:				EQU $04
IMF_INSTRUMENT_ELECTRIC_PIANO1:				EQU $05
IMF_INSTRUMENT_ELECTRIC_PIANO2:				EQU $06
IMF_INSTRUMENT_HARPSICHORD:					EQU $07
IMF_INSTRUMENT_CLAVI:						EQU $08
IMF_INSTRUMENT_CELESTA:						EQU $09
IMF_INSTRUMENT_GLOCKENSPIEL:					EQU $0A
IMF_INSTRUMENT_MUSIC_BOX:					EQU $0B
IMF_INSTRUMENT_VIBRAPHONE:					EQU $0C
IMF_INSTRUMENT_MARIMBA:						EQU $0D
IMF_INSTRUMENT_XYLOPHONE:					EQU $0E
IMF_INSTRUMENT_TUBULAR_BELLS:				EQU $0F
IMF_INSTRUMENT_DULCIMER:						EQU $10
IMF_INSTRUMENT_DRAWBAR_ORGAN:				EQU $11
IMF_INSTRUMENT_PERCUSSIVE_ORGAN:				EQU $12
IMF_INSTRUMENT_ROCK_ORGAN:					EQU $13
IMF_INSTRUMENT_CHURCH_ORGAN:					EQU $14
IMF_INSTRUMENT_REED_ORGAN:					EQU $15
IMF_INSTRUMENT_ACCORDION:					EQU $16
IMF_INSTRUMENT_HARMONICA:					EQU $17
IMF_INSTRUMENT_TANGO_ACCORDION:				EQU $18
IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:			EQU $19
IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:			EQU $1A
IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:			EQU $1B
IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:			EQU $1C
IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:			EQU $1D
IMF_INSTRUMENT_OVERDRIVEN_GUITAR:			EQU $1E
IMF_INSTRUMENT_DISTORTION_GUITAR:			EQU $1F
IMF_INSTRUMENT_GUITAR_HARMONICS:				EQU $20
IMF_INSTRUMENT_ACOUSTIC_BASS:				EQU $21
IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:			EQU $22
IMF_INSTRUMENT_ELECTRIC_BASS_PICK:			EQU $23
IMF_INSTRUMENT_FRETLESS_BASS:				EQU $24
IMF_INSTRUMENT_SLAP_BASS_1:					EQU $25
IMF_INSTRUMENT_SLAP_BASS_2:					EQU $26
IMF_INSTRUMENT_SYNTH_BASS_1:					EQU $27
IMF_INSTRUMENT_SYNTH_BASS_2:					EQU $28
IMF_INSTRUMENT_VIOLIN:						EQU $29
IMF_INSTRUMENT_VIOLA:						EQU $2A
IMF_INSTRUMENT_CELLO:						EQU $2B
IMF_INSTRUMENT_CONTRABASS:					EQU $2C
IMF_INSTRUMENT_TREMOLO_STRINGS:				EQU $2D
IMF_INSTRUMENT_PIZZICATO_STRINGS:			EQU $2E
IMF_INSTRUMENT_ORCHESTRAL_HARP:				EQU $2F
IMF_INSTRUMENT_TIMPANI:						EQU $30
IMF_INSTRUMENT_STRING_ENSEMBLE_1:			EQU $31
IMF_INSTRUMENT_STRING_ENSEMBLE_2:			EQU $32
IMF_INSTRUMENT_SYNTHSTRINGS_1:				EQU $33
IMF_INSTRUMENT_SYNTHSTRINGS_2:				EQU $34
IMF_INSTRUMENT_CHOIR_AAHS:					EQU $35
IMF_INSTRUMENT_VOICE_OOHS:					EQU $36
IMF_INSTRUMENT_SYNTH_VOICE:					EQU $37
IMF_INSTRUMENT_ORCHESTRA_HIT:				EQU $38
IMF_INSTRUMENT_TRUMPET:						EQU $39
IMF_INSTRUMENT_TROMBONE:						EQU $3A
IMF_INSTRUMENT_TUBA:							EQU $3B
IMF_INSTRUMENT_MUTED_TRUMPET:				EQU $3C
IMF_INSTRUMENT_FRENCH_HORN:					EQU $3D
IMF_INSTRUMENT_BRASS_SECTION:				EQU $3E
IMF_INSTRUMENT_SYNTHBRASS_1:					EQU $3F
IMF_INSTRUMENT_SYNTHBRASS_2:					EQU $40
IMF_INSTRUMENT_SOPRANO_SAX:					EQU $41
IMF_INSTRUMENT_ALTO_SAX:						EQU $42
IMF_INSTRUMENT_TENOR_SAX:					EQU $43
IMF_INSTRUMENT_BARITONE_SAX:					EQU $44
IMF_INSTRUMENT_OBOE:							EQU $45
IMF_INSTRUMENT_ENGLISH_HORN:					EQU $46
IMF_INSTRUMENT_BASSOON:						EQU $47
IMF_INSTRUMENT_CLARINET:						EQU $48
IMF_INSTRUMENT_PICCOLO:						EQU $49
IMF_INSTRUMENT_FLUTE:						EQU $4A
IMF_INSTRUMENT_RECORDER:						EQU $4B
IMF_INSTRUMENT_PAN_FLUTE:					EQU $4C
IMF_INSTRUMENT_BLOWN_BOTTLE:					EQU $4D
IMF_INSTRUMENT_SHAKUHACHI:					EQU $4E
IMF_INSTRUMENT_WHISTLE:						EQU $4F
IMF_INSTRUMENT_OCARINA:						EQU $50
IMF_INSTRUMENT_LEAD_1_SQUARE:				EQU $51
IMF_INSTRUMENT_LEAD_2_SAWTOOTH:				EQU $52
IMF_INSTRUMENT_LEAD_3_CALLIOPE:				EQU $A7
IMF_INSTRUMENT_LEAD_4_CHIFF:					EQU $54
IMF_INSTRUMENT_LEAD_5_CHARANG:				EQU $55
IMF_INSTRUMENT_LEAD_6_VOICE:					EQU $56
IMF_INSTRUMENT_LEAD_7_FIFTHS:				EQU $57
IMF_INSTRUMENT_LEAD_8_BASS_LEAD:				EQU $58
IMF_INSTRUMENT_PAD_1_NEW_AGE:				EQU $59
IMF_INSTRUMENT_PAD_2_WARM:					EQU $5A
IMF_INSTRUMENT_PAD_3_POLYSYNTH:				EQU $5B
IMF_INSTRUMENT_PAD_4_CHOIR:					EQU $5C
IMF_INSTRUMENT_PAD_5_BOWED:					EQU $5D
IMF_INSTRUMENT_PAD_6_METALLIC:				EQU $5E
IMF_INSTRUMENT_PAD_7_HALO:					EQU $5F
IMF_INSTRUMENT_PAD_8_SWEEP:					EQU $60
IMF_INSTRUMENT_FX_1_RAIN:					EQU $61
IMF_INSTRUMENT_FX_2_SOUNDTRACK:				EQU $62
IMF_INSTRUMENT_FX_3_CRYSTAL:					EQU $63
IMF_INSTRUMENT_FX_4_ATMOSPHERE:				EQU $64
IMF_INSTRUMENT_FX_5_BRIGHTNESS:				EQU $65
IMF_INSTRUMENT_FX_6_GOBLINS:					EQU $66
IMF_INSTRUMENT_FX_7_ECHOES:					EQU $67
IMF_INSTRUMENT_FX_8_SCI_FI:					EQU $68
IMF_INSTRUMENT_SITAR:						EQU $69
IMF_INSTRUMENT_BANJO:						EQU $6A
IMF_INSTRUMENT_SHAMISEN:						EQU $6B
IMF_INSTRUMENT_KOTO:							EQU $6C
IMF_INSTRUMENT_KALIMBA:						EQU $6D
IMF_INSTRUMENT_BAG_PIPE:						EQU $6E
IMF_INSTRUMENT_FIDDLE:						EQU $6F
IMF_INSTRUMENT_SHANAI:						EQU $70
IMF_INSTRUMENT_TINKLE_BELL:					EQU $71
IMF_INSTRUMENT_AGOGO:						EQU $72
IMF_INSTRUMENT_STEEL_DRUMS:					EQU $73
IMF_INSTRUMENT_WOODBLOCK:					EQU $74
IMF_INSTRUMENT_TAIKO_DRUM:					EQU $75
IMF_INSTRUMENT_MELODIC_TOM:					EQU $76
IMF_INSTRUMENT_SYNTH_DRUM:					EQU $77
IMF_INSTRUMENT_REVERSE_CYMBAL:				EQU $78
IMF_INSTRUMENT_GUITAR_FRET_NOISE:			EQU $79
IMF_INSTRUMENT_BREATH_NOISE:					EQU $7A
IMF_INSTRUMENT_SEASHORE:						EQU $7B
IMF_INSTRUMENT_BIRD_TWEET:					EQU $7C
IMF_INSTRUMENT_TELEPHONE_RING:				EQU $7D
IMF_INSTRUMENT_HELICOPTER:					EQU $7E
IMF_INSTRUMENT_APPLAUSE:						EQU $7F
IMF_INSTRUMENT_GUNSHOT:						EQU $80

;; Read a register from AY8910
;;  input: C = register to read
;;  output: IXL = value read
AY8910READ:
@IF CPC
    PUSH BC
    PUSH AF
    
    ; Setup register index on PPI port A
    LD B, $F4 
    OUT (C), C

    ; Tell PSG to select register using data on PPI port A
    LD BC, $F6C0         
    OUT (C), C

    ; Put PSG into inactive state
    LD BC, $F600         
    OUT (C), C

    ; ** Set PPI port A to input mode. **
    LD B, $F7               ; 8255 PPI Control
    LD C, %10010010         ; mode and port configuration
    OUT (C), C              ; Port A input, Port B input, Port C output
                            ; All operating in mode 0. (see Programming
                            ; 8255 PPI)

    ; Tell PSG to put the data of the selected register to PPI port A to
    LD BC, $F640
    OUT (C),C

    ; Read data from PPI port A
    LD B, $F4            
    IN A, (C)

    ; ** Set PPI port A to output mode. *
    LD B, $F7            ; 8255 PPI control
    LD C, %10000010
    OUT (C), C           ; Port A output, Port B input, Port C output

    ; Return PSG to inactive mode.
    LD BC, $F600         
    OUT (C), C

    LD IXL, A

    POP AF
    POP BC
    RET
@ENDIF

@IF MSX
    PUSH BC
    PUSH AF
    LD A, C
    LD B, A
    LD A, PSG_AP
    LD C, A
    LD A, B
    OUT (C), A

    LD A, PSG_RP
    LD C, A
    IN A, (C)
    LD IXL, A

    POP AF
    POP BC
    RET
@ENDIF

;; Write a register to AY8910
;;  input: 
;;     C   = register to read
;;     IXL = register to write
AY8910WRITE:
@IF CPC
    PUSH BC
    PUSH AF
    ; setup PSG register number on PPI port A
    LD B, $F4
    OUT (C), C

    ; Tell PSG to select register from data on PPI port A
    LD BC, $F6C0
    OUT (C), C

    ; Put PSG into inactive state.
    LD BC, $F600
    OUT (C), C

    ; setup register data on PPI port A
    LD B, $F4
    LD A, IXL
    OUT (C), A

    ; Tell PSG to write data on PPI port A into selected register
    LD BC, $F680
    OUT (C), C

    ; Put PSG into inactive state
    LD BC, $F600
    OUT (C), C

    POP AF
    POP BC
    RET
@ENDIF

@IF MSX
    PUSH BC
    PUSH AF

    LD A, PSG_WP
    LD C, A
    LD A, B
    AND $FB
    OUT (C), A

    LD A, PSG_WP
    LD C, A
    LD A, B
    AND $FE
    OUT (C), A

    POP AF
    POP BC
    RET
@ENDIF

AY8910STARTUP:
    LD HL,AY8910FREQTABLE
    LD (AY8910TMPPTR2), HL
    LD HL, AY8910TMPPTR
    LD A, $0
    LD (HL), A
    INC HL
    LD (HL), A
    LD HL, AY8910JIFFIES
    LD (HL), A
    RET

AY8910START:
    SRL A
    JR NC,AY8910START0X
    CALL AY8910START0
AY8910START0X:
    SRL A
    JP NC, AY8910START1X
    CALL AY8910START1
AY8910START1X:
    SRL A
    JP NC, AY8910START2X
    CALL AY8910START2
AY8910START2X:
    RET

AY8910STARTSTOPGEN:
    LD A, PSG_R7
    LD C, A
    CALL AY8910READ
    LD A, IXL
    AND D
    OR E
    LD IXL, A
    CALL AY8910WRITE
    RET

AY8910START0:
    LD D, $FE
    LD E, $0
    CALL AY8910STARTSTOPGEN
    RET

AY8910START1:
    LD D, $FD
    LD E, $0
    CALL AY8910STARTSTOPGEN
    RET

AY8910START2:
    LD D, $FB
    LD E, $0
    CALL AY8910STARTSTOPGEN
    RET

AY8910STARTVOL:
    RET

AY8910FREQ:
    CALL AY8910CALCFREQ
    SRL A
    JR NC, AY8910FREQ0X
    CALL AY8910FREQ0T
AY8910FREQ0X:
    SRL A
    JP NC, AY8910FREQ1X
    CALL AY8910FREQ1T
AY8910FREQ1X:
    SRL A
    JP NC, AY8910FREQ2X
    CALL AY8910FREQ2T
AY8910FREQ2X:
    RET

AY8910CALCFREQ:
    RET

AY8910FREQ0:
    CALL AY8910CALCFREQ
AY8910FREQ0T:
    JMP AY8910PROGFREQ0

AY8910FREQ1:
    CALL AY8910CALCFREQ
AY8910FREQ1T:
    JMP AY8910PROGFREQ1

AY8910FREQ2:
    CALL AY8910CALCFREQ
AY8910FREQ2T:
    JMP AY8910PROGFREQ2

AY8910PROGFREQ:
    SRL A
    JP NC, AY8910PROGFREQ0X
    CALL AY8910PROGFREQ0
AY8910PROGFREQ0X:
    SRL A
    JP NC, AY8910PROGFREQ1X
    CALL AY8910PROGFREQ1
AY8910PROGFREQ1X:
    SRL A
    JP NC, AY8910PROGFREQ2X
    CALL AY8910PROGFREQ2
AY8910PROGFREQ2X:
    RET

AY8910PROGFREQ0:
    LD C, PSG_R0
    LD A, E
    LD IXL, A
    CALL AY8910WRITE

    LD C, PSG_R1
    LD A, D
    AND $0F
    LD IXL, A
    CALL AY8910WRITE

    LD C, PSG_R8
    LD A, $8
    LD IXL, A
    CALL AY8910WRITE

    RET

AY8910PROGFREQ1:
    LD C, PSG_R2
    LD A, E
    LD IXL, A
    CALL AY8910WRITE

    LD C, PSG_R3
    LD A, D
    AND $0F
    LD IXL, A
    CALL AY8910WRITE

    LD C, PSG_R9
    LD A, $8
    LD IXL, A
    CALL AY8910WRITE
    RET

AY8910PROGFREQ2:
    LD C, PSG_R4
    LD A, E
    LD IXL, A
    CALL AY8910WRITE

    LD C, PSG_R5
    LD A, D
    AND $0F
    LD IXL, A
    CALL AY8910WRITE

    LD C, PSG_R10
    LD A, $8
    LD IXL, A
    CALL AY8910WRITE

    RET

AY8910PROGPULSE:
AY8910PROGPULSE0:
AY8910PROGPULSE1:
AY8910PROGPULSE2:
    RET


AY8910PROGCTR:
AY8910PROGCTR0:
AY8910PROGCTR1:
AY8910PROGCTR2:
    RET

AY8910PROGAD:
AY8910PROGAD0:
AY8910PROGAD1:
AY8910PROGAD2:
    RET

AY8910PROGSR:
AY8910PROGSR0:
AY8910PROGSR1:
AY8910PROGSR2:
    RET
    
AY8910STOP:
    SRL A
    JP NC, AY8910STOP0X
    CALL AY8910STOP0
AY8910STOP0X:
    SRL A
    JP NC, AY8910STOP1X
    CALL AY8910STOP1
AY8910STOP1X:
    SRL A
    JP NC, AY8910STOP2X
    CALL AY8910STOP2
AY8910STOP2X:
    RET

AY8910STOP0:
    LD D, $FE
    LD E, $1
    CALL AY8910STARTSTOPGEN
    LD C, PSG_R8
    LD A, $0
    LD IXL, A
    CALL AY8910WRITE
    RET

AY8910STOP1:
    LD D, $FD
    LD E, $2
    CALL AY8910STARTSTOPGEN
    LD C, PSG_R9
    LD A, $0
    LD IXL, A
    CALL AY8910WRITE
    RET

AY8910STOP2:
    LD D, $FB
    LD E, $4
    CALL AY8910STARTSTOPGEN
    LD C, PSG_R10
    LD A, $0
    LD IXL, A
    CALL AY8910WRITE
    RET

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PUSH AF
    LD A, (AY8910MUSICREADY)
    CP 0
    JR Z, MUSICPLAYERQ
    PUSH BC
    PUSH DE
    PUSH HL
    CALL MUSICPLAYERR
    POP HL
    POP DE
    POP BC
MUSICPLAYERQ:
    POP AF
    RET

MUSICPLAYERR:

; This is the entry point to wait until the waiting jiffies
; are exausted.
MUSICPLAYERL1:
    LD HL, AY8910JIFFIES
    LD A, (HL)
    CP 0
    JR Z, MUSICPLAYERL1B
    DEC A
    LD (HL), A
    RET

; This is the entry point to read the next instruction.
MUSICPLAYERL1B:
    ; Read the next byte.
    CALL MUSICREADNEXTBYTE

    ; Is the file NOT finished?
    LD A, B
    CP $0
    JR NZ, MUSICPLAYERL1X

    ; Let's stop the play!
    LD A, $0
    LD (AY8910MUSICREADY), A
    LD HL, 0
    LD (AY8910TMPPTR), HL
    LD (AY8910JIFFIES), A
    RET

; This is the entry point to decode the instruction
; (contained into the A register).
MUSICPLAYERL1X:
    LD A, C
    SLA A
    JR C, MUSICPLAYERL1X0
    JMP MUSICWAIT
MUSICPLAYERL1X0:
    SLA A
    SLA A
    JR C, MUSICPLAYERL1X1
    JMP MUSICNOTEON
MUSICPLAYERL1X1:
    SLA A
    JR C, MUSICPLAYERL1X2
    JMP MUSICNOTEOFF
MUSICPLAYERL1X2:
    RET

MUSICWAIT:
    SRL A
    LD (AY8910JIFFIES), A
    RET

MUSICNOTEOFF:
    SRL A
    SRL A
    SRL A
    SRL A
    CALL AY8910STOP
    RET    

MUSICNOTEON:
    SRL A
    SRL A
    SRL A
    PUSH BC
    CALL MUSICREADNEXTBYTE
    LD A, $0
    LD B, A
    SLA C
    RL B
    LD DE, BC
    LD HL, (AY8910TMPPTR2)
    ADC HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD D, (HL)
    POP BC
    CALL AY8910PROGFREQ
    RET

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE:
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LD A, (AY8910TMPOFS)
    LD B, A
    LD A, (AY8910TMPLEN)
    CP B
    JR Z, MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2:
    LD B, $ff
    LD HL, AY8910TMPPTR
    LD E, (HL)
    INC HL
    LD D, (HL)
    LD A, 0
    LD H, A
    LD A, (AY8910TMPOFS)
    LD L, A
    ADC HL, DE
    INC A
    LD (AY8910TMPOFS), A
    LD A, (HL)
    LD C, A
    RET

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE:
    ; Is file finished?
    LD A, (AY8910BLOCKS)
    JR Z, MUSICREADNEXTBYTEEND

    ; Put the index to 0
    LD A, 0
    LD (AY8910TMPOFS), A

    ; Increment the base address by 256
    LD HL, AY8910TMPPTR
    INC HL
    LD A, (HL)
    INC A
    LD (HL), A 

    ; Decrement the number of remaining blocks
    LD A, (AY8910BLOCKS)
    DEC A
    LD (AY8910BLOCKS), A

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    JR Z, MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LD A, $FF
    LD (AY8910TMPLEN), A
    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2:
    LD A, (AY8910LASTBLOCK)
    LD (AY8910TMPLEN), A
    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND:
    LD B, $00
    RET
