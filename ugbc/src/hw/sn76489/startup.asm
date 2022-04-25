; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                           STARTUP ROUTINE ON SN-76489                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF COLECO
    CSG_OUT: EQU         $ff
    CSG_IN: EQU          $ff
@ENDIF

@IF SC3000
    CSG_OUT: EQU         $7f
    CSG_IN: EQU          $7f
@ENDIF

@IF SG1000
    CSG_OUT: EQU         $7f
    CSG_IN: EQU          $7f
@ENDIF

; CSG_OUT: EQU         $06
; CSG_IN: EQU          $03

CSG_F1: EQU          00
CSG_A1: EQU          10
CSG_F2: EQU          20
CSG_A2: EQU          30
CSG_F3: EQU          40
CSG_A3: EQU          50
CSG_NC: EQU          60
CSG_NA: EQU          70

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

SN76489STARTUP:
    LD HL,SN76489FREQTABLE
    LD (SN76489TMPPTR2), HL
    LD HL, SN76489TMPPTR
    LD A, $0
    LD (HL), A
    INC HL
    LD (HL), A
    LD HL, SN76489JIFFIES
    LD (HL), A
    RET

SN76489START:
    SRL A
    JR C,SN76489START0X
    CALL SN76489START0
SN76489START0X:
    SRL A
    JP C, SN76489START1X
    CALL SN76489START1
SN76489START1X:
    SRL A
    JP C, SN76489START2X
    CALL SN76489START2
SN76489START2X:
    RET

SN76489START0:
    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_F1
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    OR CSG_F1
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A1
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A
    RET

SN76489START1:
    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_F2
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    OR CSG_F2
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A2
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A
    RET

SN76489START2:
    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_F3
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    OR CSG_F3
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A3
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A
    RET

SN76489STARTVOL:
    RET

SN76489FREQ:
    CALL SN76489CALCFREQ
    SRL A
    JR C,SN76489FREQ0X
    CALL SN76489FREQ0T
SN76489FREQ0X:
    SRL A
    JP C, SN76489FREQ1X
    CALL SN76489FREQ1T
SN76489FREQ1X:
    SRL A
    JP C, SN76489FREQ2X
    CALL SN76489FREQ2T
SN76489FREQ2X:
    RET

SN76489CALCFREQ:
    RET

SN76489FREQ0:
    CALL SN76489CALCFREQ
SN76489FREQ0T:
    JMP SN76489PROGFREQ0

SN76489FREQ1:
    CALL SN76489CALCFREQ
SN76489FREQ1T:
    JMP SN76489PROGFREQ1

SN76489FREQ2:
    CALL SN76489CALCFREQ
SN76489FREQ2T:
    JMP SN76489PROGFREQ2

SN76489PROGFREQ:
    SRL A
    JP C, SN76489PROGFREQ0X
    CALL SN76489PROGFREQ0
SN76489PROGFREQ0X:
    SRL A
    JP C, SN76489PROGFREQ1X
    CALL SN76489PROGFREQ1
SN76489PROGFREQ1X:
    SRL A
    JP C, SN76489PROGFREQ2X
    CALL SN76489PROGFREQ2
SN76489PROGFREQ2X:
    RET

SN76489PROGFREQ0:
    PUSH DE

    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    LD A, E
    AND $7
    LD E, A

    LD A, CSG_OUT
    LD C, A
    LD A, E
    OR CSG_F1
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    POP DE

    PUSH DE

    LD A, E
    AND $3F
    LD E, A

    LD A, CSG_OUT
    LD C, A
    LD A, E
    OR CSG_F1
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A1
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    POP DE

    RET

SN76489PROGFREQ1:
    PUSH DE
    
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    LD A, E
    AND $7
    LD E, A

    LD A, CSG_OUT
    LD C, A
    LD A, E
    OR CSG_F2
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    POP DE

    PUSH DE

    LD A, E
    AND $3F
    LD E, A

    LD A, CSG_OUT
    LD C, A
    LD A, E
    OR CSG_F2
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A2
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    POP DE

    RET

SN76489PROGFREQ2:
    PUSH DE
    
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    LD A, E
    AND $7
    LD E, A

    LD A, CSG_OUT
    LD C, A
    LD A, E
    OR CSG_F3
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    POP DE

    PUSH DE

    LD A, E
    AND $3F
    LD E, A

    LD A, CSG_OUT
    LD C, A
    LD A, E
    OR CSG_F3
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A3
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A

    POP DE

    RET

SN76489PROGPULSE:
SN76489PROGPULSE0:
SN76489PROGPULSE1:
SN76489PROGPULSE2:
    RET

SN76489PROGCTR:
SN76489PROGCTR0:
SN76489PROGCTR1:
SN76489PROGCTR2:
    RET

SN76489PROGAD:
SN76489PROGAD0:
SN76489PROGAD1:
SN76489PROGAD2:
    RET

SN76489PROGSR:
SN76489PROGSR0:
SN76489PROGSR1:
SN76489PROGSR2:
    RET
    
SN76489STOP:
    SRL A
    JP C, SN76489STOP0X
    CALL SN76489STOP0
SN76489STOP0X:
    SRL A
    JP C, SN76489STOP1X
    CALL SN76489STOP1
SN76489STOP1X:
    SRL A
    JP C, SN76489STOP2X
    CALL SN76489STOP2
SN76489STOP2X:
    RET

SN76489STOP0:
    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A1
    OR $F
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A
    RET

SN76489STOP1:
    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A2
    OR $F
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A
    RET

SN76489STOP2:
    LD A, CSG_OUT
    LD C, A
    LD A, $80
    OR CSG_A3
    OR $F
    OUT (C), A

    LD A, CSG_IN
    LD C, A
    IN A, (C)
    LD B, A
    RET

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PUSH AF
    LD A, (SN76489MUSICREADY)
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
    LD HL, SN76489JIFFIES
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
    LD (SN76489MUSICREADY), A
    LD HL, 0
    LD (SN76489TMPPTR), HL
    LD (SN76489JIFFIES), A
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
    LD (SN76489JIFFIES), A
    RET

MUSICNOTEOFF:
    SRL A
    SRL A
    SRL A
    SRL A
    CALL SN76489STOP
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
    LD HL, (SN76489TMPPTR2)
    ADC HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD D, (HL)
    POP BC
    CALL SN76489PROGFREQ
    RET

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE:
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LD A, (SN76489TMPOFS)
    LD B, A
    LD A, (SN76489TMPLEN)
    CP B
    JR Z, MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2:
    LD B, $ff
    LD HL, SN76489TMPPTR
    LD E, (HL)
    INC HL
    LD D, (HL)
    LD A, 0
    LD H, A
    LD A, (SN76489TMPOFS)
    LD L, A
    ADC HL, DE
    INC A
    LD (SN76489TMPOFS), A
    LD A, (HL)
    LD C, A
    RET

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE:
    ; Is file finished?
    LD A, (SN76489BLOCKS)
    JR Z, MUSICREADNEXTBYTEEND

    ; Put the index to 0
    LD A, 0
    LD (SN76489TMPOFS), A

    ; Increment the base address by 256
    LD HL, SN76489TMPPTR
    INC HL
    LD A, (HL)
    INC A
    LD (HL), A 

    ; Decrement the number of remaining blocks
    LD A, (SN76489BLOCKS)
    DEC A
    LD (SN76489BLOCKS), A

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    JR Z, MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LD A, $FF
    LD (SN76489TMPLEN), A
    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2:
    LD A, (SN76489LASTBLOCK)
    LD (SN76489TMPLEN), A
    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND:
    LD B, $00
    RET
