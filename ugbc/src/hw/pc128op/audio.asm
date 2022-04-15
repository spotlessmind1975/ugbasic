; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo
;  *
;  * http//www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                   AUDIO ROUTINE ON OLIVETTI PRODEST PC128                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; TIMER service routine
; PC128IRQ
;     PSHS D,X
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     JSR SAMPLE    
;     PULS D,X
;     RTI
; ;     LDA #10
; ; NOTEUP
; ;     INC $A7C1
; ;     LDB COUNT
; ;     BEQ NOTEDOWN
; ; NOTEUPL1
; ;     DECB
; ;     BNE NOTEUPL1
; ; NOTEDOWN
; ;     DEC $A7C1
; ;     LDB COUNT
; ;     BEQ NOTEDONE
; ; NOTEDOWNL1
; ;     DECB
; ;     BNE NOTEDOWNL1
; ; NOTEDONE
; ;     DECA 
; ;     BNE NOTEUP
; ; PC128IRQDONE
;     ; Initialisation CNA en sortie

PC128OPAUDIOFREQTABLE
    FDB 0,		0,		0,		0,		0,		0,		0,		0,		0,		0
    FDB 0,		0,		0,		0,		0,		0,		0,		0,		0,		0
    FDB 0,		0,		0,		268,	284,	301,	318,	337,	358,	379
    FDB 401,	425,	451,	477,	506,	536,	568,	602,	637,	675
    FDB 716,	758,	803,	851,	902,	955,	1012,	1072,	1136,	1204
    FDB 1275,	1351,	1432,	1517,	1607,	1703,	1804,	1911,	2025,	2145
    FDB 2273,	2408,	2551,	2703,	2864,	3034,	3215,	3406,	3608,	3823
    FDB 4050,	4291,	4547,	4817,	5103,	5407,	5728,	6069,	6430,	6812
    FDB 7217,	7647,	8101,	8583,	9094,	9634,	10207,	10814,	11457,	12139
    FDB 12860,	13625,	14435,	15294,	16203,	17167,	18188,	19269,	20415,	21629
    FDB 22915,	24278,	25721,	27251,	28871,	30588,	32407,	34334,	36376,	38539
    FDB 40830,	43258,	45830,	48556,	51443,	54502,	57743,	61176,	64814

PC128OPAUDIOMUSICREADY FCB $0
PC128OPAUDIOBLOCKS FDB $0
PC128OPAUDIOLASTBLOCK FCB $0

PC128OPAUDIOTMPPTR2 EQU $03 ; $04
PC128OPAUDIOTMPPTR EQU $05 ; $06
PC128OPAUDIOTMPOFS EQU $07
PC128OPAUDIOTMPLEN EQU $08
PC128OPAUDIOJIFFIES EQU $09 ; $0A

AUDIOBUFFER         
    ; FCB     $20,$22,$23,$25,$26,$28,$29,$2b
    ; FCB     $2c,$2e,$2f,$30,$32,$33,$34,$35,
    ; FCB     $37,$38,$39,$3a,$3b,$3b,$3c,$3d,
    ; FCB     $3e,$3e,$3f,$3f,$3f,$40,$40,$40,
    ; FCB     $40,$40,$40,$40,$3f,$3f,$3f,$3e,
    ; FCB     $3e,$3d,$3c,$3b,$3b,$3a,$39,$38,
    ; FCB     $37,$35,$34,$33,$32,$30,$2f,$2e,
    ; FCB     $2c,$2b,$29,$28,$26,$25,$23,$22,
    ; FCB     $20,$1e,$1d,$1b,$1a,$18,$17,$15,
    ; FCB     $14,$12,$11,$10,$e,$d,$c,$b,
    ; FCB     $9,$8,$7,$6,$5,$5,$4,$3,
    ; FCB     $2,$2,$1,$1,$1,$0,$0,$0,
    ; FCB     $0,$0,$0,$0,$1,$1,$1,$2,
    ; FCB     $2,$3,$4,$5,$5,$6,$7,$8,
    ; FCB     $9,$b,$c,$d,$e,$10,$11,$12,
    ; FCB     $14,$15,$17,$18,$1a,$1b,$1d,$1e,

    FCB $10,$10,$11,$12,$13,$13,$14,$15,
    FCB $15,$16,$17,$17,$18,$19,$19,$1a,
    FCB $1a,$1b,$1b,$1c,$1c,$1d,$1d,$1e,
    FCB $1e,$1e,$1e,$1f,$1f,$1f,$1f,$1f,
    FCB $1f,$1f,$1f,$1f,$1f,$1f,$1e,$1e,
    FCB $1e,$1e,$1d,$1d,$1c,$1c,$1b,$1b,
    FCB $1a,$1a,$19,$19,$18,$17,$17,$16,
    FCB $15,$15,$14,$13,$13,$12,$11,$10,
    FCB $10,$f,$e,$d,$c,$c,$b,$a,
    FCB $a,$9,$8,$8,$7,$6,$6,$5,
    FCB $5,$4,$4,$3,$3,$2,$2,$1,
    FCB $1,$1,$1,$0,$0,$0,$0,$0,
    FCB $0,$0,$0,$0,$0,$0,$1,$1,
    FCB $1,$1,$2,$2,$3,$3,$4,$4,
    FCB $5,$5,$6,$6,$7,$8,$8,$9,
    FCB $a,$a,$b,$c,$c,$d,$e,$f,

AUDIOPOSR            FCB $00

PC128AUDIOOPSAMPLE
    LDX #AUDIOBUFFER
    LDB AUDIOPOSR
    LDA B,X
    STA $A7CD
    INCB
    CMPB #128
    BNE PC128AUDIOOPSAMPLEDONE
    LDB #0
PC128AUDIOOPSAMPLEDONE
    LBSR  TEMP14   		; temporisation 14 cycles
	LBSR  TEMP14   		; temporisation 14 cycles
	LBSR  TEMP14   		; temporisation 14 cycles
	LBSR  TEMP14   		; temporisation 14 cycles
	LBSR  TEMP14   		; temporisation 14 cycles
	LBSR  TEMP14   		; temporisation 14 cycles
	LBSR  TEMP14   		; temporisation 14 cycles
	LBRN  $FFFF		;temporisation    5 cycles            (5) 
    STB AUDIOPOSR
    RTS

TEMP14
    RTS

PC128OPAUDIOSTARTUP
    LDA   $A7CF
    ANDA  #$FB
    STA   $A7CF
    LDB   #$3F
    STB   $A7CD
    ORA   #$04
    STA   $A7CF
    RTS

PC128OPAUDIOSTART
    LSRA
    BCC PC128OPAUDIOSTART0X
    JSR PC128OPAUDIOSTART0
PC128OPAUDIOSTART0X
    RTS

PC128OPAUDIOSTART0
    RTS

PC128OPAUDIOSTARTVOL
    RTS

PC128OPAUDIOFREQ
    JSR PC128OPAUDIOCALCFREQ
    LSRA
    BCC PC128OPAUDIOFREQ0X
    JSR PC128OPAUDIOFREQ0T
PC128OPAUDIOFREQ0X
    RTS

PC128OPAUDIOCALCFREQ
    RTS

PC128OPAUDIOFREQ0
    JSR PC128OPAUDIOCALCFREQ
PC128OPAUDIOFREQ0T
    JMP PC128OPAUDIOPROGFREQ0

PC128OPAUDIOPROGFREQ
    LSRA
    BCC PC128OPAUDIOPROGFREQ0X
    JSR PC128OPAUDIOPROGFREQ0
PC128OPAUDIOPROGFREQ0X
    RTS

PC128OPAUDIOPROGFREQ0
    RTS

PC128OPAUDIOPROGPULSE
    LSRA
    BCC PC128OPAUDIOPROGPULSE0X
    JSR PC128OPAUDIOPROGPULSE0
PC128OPAUDIOPROGPULSE0X
    RTS

PC128OPAUDIOPROGPULSE0
    RTS

PC128OPAUDIOPROGCTR
    LSRA
    BCC PC128OPAUDIOPROGCTR0X
    JSR PC128OPAUDIOPROGCTR0
PC128OPAUDIOPROGCTR0X
    RTS

PC128OPAUDIOPROGCTR0
    RTS

PC128OPAUDIOPROGAD
    LSRA
    BCC PC128OPAUDIOPROGAD0X
    JSR PC128OPAUDIOPROGAD0
PC128OPAUDIOPROGAD0X
    RTS

PC128OPAUDIOPROGAD0
    RTS

PC128OPAUDIOPROGSR
    LSRA
    BCC PC128OPAUDIOPROGSR0X
    JSR PC128OPAUDIOPROGSR0
PC128OPAUDIOPROGSR0X
    RTS

PC128OPAUDIOPROGSR0
    RTS

PC128OPAUDIOSTOP
    LSRA
    BCC PC128OPAUDIOSTOP0X
    JSR PC128OPAUDIOSTOP0
PC128OPAUDIOSTOP0X
    RTS

PC128OPAUDIOSTOP0
    RTS

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER
    PSHS D
    LDA PC128OPAUDIOMUSICREADY
    BEQ MUSICPLAYERQ
    JSR MUSICPLAYERR
MUSICPLAYERQ
    PULS D
    RTS

MUSICPLAYERR

; This is the entry point to wait until the waiting jiffies
; are exausted.
MUSICPLAYERL1
    LDA PC128OPAUDIOJIFFIES
    BEQ MUSICPLAYERL1B
    DEC PC128OPAUDIOJIFFIES
    RTS

; This is the entry point to read the next instruction.
MUSICPLAYERL1B
    ; Read the next byte.
    JSR MUSICREADNEXTBYTE

    ; Is the file NOT finished?
    CMPB #$0
    BNE MUSICPLAYERL1X

    ; Let's stop the play!
    LDA #$0
    STA PC128OPAUDIOMUSICREADY
    STA PC128OPAUDIOTMPPTR
    STA PC128OPAUDIOTMPPTR+1
    STA PC128OPAUDIOJIFFIES
    RTS

; This is the entry point to decode the instruction
; (contained into the A register).
MUSICPLAYERL1X
    ASLA
    BCS MUSICPLAYERL1X0
    JMP MUSICWAIT
MUSICPLAYERL1X0
    ASLA
    ASLA
    BCS MUSICPLAYERL1X1
    JMP MUSICNOTEON
MUSICPLAYERL1X1
    ASLA
    BCS MUSICPLAYERL1X2
    JMP MUSICNOTEOFF
MUSICPLAYERL1X2
    RTS

MUSICWAIT
    LSRA
    STA PC128OPAUDIOJIFFIES
    RTS

MUSICNOTEOFF
    LSRA
    LSRA
    LSRA
    LSRA
    JSR PC128OPAUDIOSTOP
    RTS    

MUSICNOTEON
    LSRA
    LSRA
    LSRA
    PSHS D
    JSR MUSICREADNEXTBYTE
    ASLA
    PSHS X
    LDX PC128OPAUDIOTMPPTR2
    LDA A,X
    PULS X
    
    JSR PC128OPAUDIOPROGFREQ
    RTS

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LDA PC128OPAUDIOTMPOFS
    CMPA PC128OPAUDIOTMPLEN
    BEQ MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2
    LDB #$ff
    PSHS X
    LDX PC128OPAUDIOTMPPTR
    LDA A,X
    INC PC128OPAUDIOTMPOFS
    RTS

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE
    ; Is file finished?
    LDA PC128OPAUDIOBLOCKS
    BEQ MUSICREADNEXTBYTEEND

    ; Put the index to 0
    LDA #$0
    STA PC128OPAUDIOTMPOFS

    ; Increment the base address by 256
    INC PC128OPAUDIOTMPPTR

    ; Decrement the number of remaining blocks
    DEC PC128OPAUDIOBLOCKS

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    BEQ MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LDA #$7F
    STA PC128OPAUDIOTMPLEN
    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2
    LDA PC128OPAUDIOLASTBLOCK
    STA PC128OPAUDIOTMPLEN
    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND
    LDB #$0
    RTS

