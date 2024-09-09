; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                           MUSIC ROUTINE ON SN-76489                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SN76489MUSICTYPE        fcb $0
SN76489MUSICREADY       fcb $0
SN76489MUSICPAUSE       fcb $0
SN76489BLOCKS           fdb $0
SN76489LASTBLOCK        fcb $0
SN76489MUSICLOOP        fcb $0

SN76489TMPPTR           fdb $0
SN76489TMPOFS           fdb $0
SN76489TMPLEN           fdb $0
SN76489JIFFIES          fdb $0
SN76489BANK             fdb $0

SN76489TMPPTR_BACKUP    fdb $0
SN76489LASTBLOCK_BACKUP fdb $0
SN76489BLOCKS_BACKUP    fdb $0

; X: music address
; A: blocks
; B: last block
MUSICPLAYERRESET
    PSHS D
    CLRA
    STA SN76489JIFFIES
    STA SN76489TMPOFS
    LDA #$1
    STA SN76489MUSICREADY
    PULS D
    STX SN76489TMPPTR
    STX SN76489TMPPTR_BACKUP
    STB SN76489LASTBLOCK
    STB SN76489LASTBLOCK_BACKUP
    STA SN76489BLOCKS
    STA SN76489BLOCKS_BACKUP
    CMPA #0
    BEQ MUSICPLAYERRESET3
    LDA #$FF
    JMP MUSICPLAYERRESET2
MUSICPLAYERRESET3
    TFR B, A
MUSICPLAYERRESET2
    STA SN76489TMPLEN
    RTS

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER
    PSHS D
    LDD SN76489TIMER
    CMPD #0
    BEQ MUSICPLAYERD1
    SUBD #1
    STD SN76489TIMER
    BNE MUSICPLAYERD1
    JSR SN76489STOP0
MUSICPLAYERD1
    LDD SN76489TIMER+2
    CMPD #0
    BEQ MUSICPLAYERD2
    SUBD #1
    STD SN76489TIMER+2
    BNE MUSICPLAYERD2
    JSR SN76489STOP1
MUSICPLAYERD2
    LDD SN76489TIMER+4
    CMPD #0
    BEQ MUSICPLAYERD3
    SUBD #1
    STD SN76489TIMER+4
    BNE MUSICPLAYERD3
    JSR SN76489STOP2
MUSICPLAYERD3
    LDA SN76489MUSICREADY
    BEQ MUSICPLAYERQ
    LDA SN76489MUSICPAUSE
    BNE MUSICPLAYERQ2
    LDA SN76489MUSICTYPE
    LSRA
    BCC MUSICPLAYER2
    JMP MUSICPLAYERIAF
MUSICPLAYER2
    LSRA
    BCC MUSICPLAYER4
    JMP MUSICPLAYER8
MUSICPLAYER4
    LSRA
    BCC MUSICPLAYER8
    JSR MUSICPLAYERPSG
MUSICPLAYER8
    PULS D
    RTS

MUSICPLAYERIAF
    PSHS D
    PSHS X
    PSHS Y
    PSHS U
    JSR MUSICPLAYERR
    PULS U
    PULS Y
    PULS X
    PULS D
    JMP MUSICPLAYERQ2
MUSICPLAYERQ
    LDA SN76489MUSICLOOP
    BEQ MUSICPLAYERQ2
    PSHS D
    PSHS X
    PSHS Y
    PSHS U
    LDX SN76489TMPPTR_BACKUP
    LDB SN76489LASTBLOCK_BACKUP
    LDA SN76489BLOCKS_BACKUP
    JSR MUSICPLAYERRESET
    PULS U
    PULS Y
    PULS X
    PULS D
MUSICPLAYERQ2
    PULS D
    RTS

MUSICPLAYERR

; This is the entry point to wait until the waiting jiffies
; are exausted.
MUSICPLAYERL1
    LDA SN76489JIFFIES
    BEQ MUSICPLAYERL1B
    DEC SN76489JIFFIES
    RTS

; This is the entry point to read the next instruction.
MUSICPLAYERL1B
    ; Read the next byte.
    JSR MUSICREADNEXTBYTE

    ; Is the file NOT finished?
    CMPB #0
    BNE MUSICPLAYERL1X

    ; Let's stop the play!
    CLRA
    STA SN76489MUSICREADY
    LDX #0
    STX SN76489TMPPTR
    STA SN76489JIFFIES
    RTS

; This is the entry point to decode the instruction
; (contained into the A register).
MUSICPLAYERL1X
    LSLA
    BCS MUSICPLAYERL1X0
    JMP MUSICWAIT
MUSICPLAYERL1X0
    LSLA
    LSLA
    BCS MUSICPLAYERL1X1
    JMP MUSICNOTEON
MUSICPLAYERL1X1
    LSLA
    BCS MUSICPLAYERL1X2
    JMP MUSICNOTEOFF
MUSICPLAYERL1X2
    RTS

MUSICWAIT
    LSRA
    STA SN76489JIFFIES
    RTS

MUSICNOTEOFF
    LSRA
    LSRA
    LSRA
    LSRA
    JSR SN76489STOP
    RTS

MUSICNOTEON
    LSRA
    LSRA
    LSRA
    PSHS D
    JSR MUSICREADNEXTBYTE
    TFR A, B
    CLRA
    LSLB
    ROLA
    LDX SN76489TMPPTR2
    LDU D,X
    PULS D
    JSR SN76489PROGFREQ
    RTS

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE
    PSHS X
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LDA SN76489TMPOFS
    CMPA SN76489TMPLEN
    BEQ MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2
@IF COCO3
    LDA SN76489BANK
    CMPA #$FF
    BNE MUSICREADNEXTBYTE2BANKED
@ENDIF
    LDX SN76489TMPPTR
    LDA SN76489TMPOFS
    INC SN76489TMPOFS
    LDA A,X
    PULS X
    LDB #$ff
    RTS


; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE
    ; Is file finished?
    LDA SN76489BLOCKS
    BEQ MUSICREADNEXTBYTEEND

    ; Put the index to 0
    CLRA
    STA SN76489TMPOFS

    ; Increment the base address by 256
    LDA SN76489TMPPTR
    INCA
    STA SN76489TMPPTR

    ; Decrement the number of remaining blocks
    DEC SN76489BLOCKS

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    BEQ MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LDA #$FF
    STA SN76489TMPLEN
    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2
    LDA SN76489LASTBLOCK
    STA SN76489TMPLEN
    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND
    LDB #$00
    PULS X
    RTS

@IF PC128OP

MUSICREADNEXTBYTE2BANKED
    LDB SN76489BANK
    STB BASE_SEGMENT+$E5
    LDX SN76489TMPPTR
    LDA SN76489TMPOFS
    INC SN76489TMPOFS
    LDA A,X
    LDA #7
    STA BASE_SEGMENT+$E5
    PULS X
    LDB #$ff
    RTS

; Original code by Dino Florenzi:
; https://github.com/dinoflorenzi/THOMSON-MO-TO-SOUNDCARD/blob/efed15f2510d181f550dca5f3da296c8e39fe80d/SN76489AN/DEMOS/VAMPIRE/vampire_music.asm
; Adapted by Marco Spedaletti for ugBASIC.

MUSICPLAYERPSG
    PSHS D
    PSHS X
	LDA SN76489JIFFIES		    ;load delay counter value 		
	BNE MUSICPLAYERPSGSKIP		;equal to zero? YES continue, NO jump to SKIP 
MUSICPLAYERPSGLOOP
	LDX SN76489TMPPTR	        ;load music track execution address
    LDB SN76489BANK
    CMPB #$FF
    BNE MUSICPLAYERPSGLOOPBANKED
	LDA ,X+			            ;load music data
    JMP MUSICPLAYERPSGLOOPREAD
MUSICPLAYERPSGLOOPBANKED
    STB BASE_SEGMENT+$E5
	LDA ,X+			            ;load music data
    LDB #7
    STB BASE_SEGMENT+$E5
    CMPA #0
MUSICPLAYERPSGLOOPREAD
	BEQ MUSICPLAYERPSGRESET		;equal to ZERO? YES jump to RESET 
	BITA #$C0		            ;test the A register with %11000000 mask (delay data bit)
	BEQ MUSICPLAYERPSGSTOSKIP	;is delay data? YES jump to STOSKIP, NO continue
    TFR A,B
    JSR SN76489WRITE            ;write register A to PSG device (update sound)
	STX SN76489TMPPTR       	;update the music execution address
	BRA MUSICPLAYERPSGLOOP		;jump to LOOP
MUSICPLAYERPSGSKIP
	DEC SN76489JIFFIES		    ;decrement delay value in memory
MUSICPLAYERPSGEXIT
    PULS X
    PULS D
	RTS				            ;return
MUSICPLAYERPSGSTOSKIP
	ANDA #$07		            ;get the delay value (7*1/50 sec max)
	STA SN76489JIFFIES		    ;store to delay memory address
	STX SN76489TMPPTR       	;update the music execution address
	BRA MUSICPLAYERPSGEXIT		;jump to EXIT
MUSICPLAYERPSGRESET
	LDX SN76489TMPPTR_BACKUP	;reset the execution address (restart music to the start)
	STX SN76489TMPPTR
	BRA MUSICPLAYERPSGEXIT	    ;jump to EXIT

@ENDIF

@IF COCO3

MUSICREADNEXTBYTE2BANKED
    LDB SN76489BANK
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    LDX SN76489TMPPTR
    TFR X, D
    ADDD #$C000
    TFR D, X
    LDA SN76489TMPOFS
    INC SN76489TMPOFS
    LDA A,X
    JSR GIMEBANKSHADOWCHANGERESET
    PULS X
    LDB #$ff
    RTS

@ENDIF

@IF COCO || COCO3

; Original code by Dino Florenzi:
; https://github.com/dinoflorenzi/THOMSON-MO-TO-SOUNDCARD/blob/efed15f2510d181f550dca5f3da296c8e39fe80d/SN76489AN/DEMOS/VAMPIRE/vampire_music.asm
; Adapted by Marco Spedaletti for ugBASIC.

MUSICPLAYERPSG
    PSHS D
    PSHS X
	LDA SN76489JIFFIES		    ;load delay counter value 		
	BNE MUSICPLAYERPSGSKIP		;equal to zero? YES continue, NO jump to SKIP 
MUSICPLAYERPSGLOOP
	LDX SN76489TMPPTR	        ;load music track execution address
@IF COCO3
    LDB SN76489BANK
    CMPB #$FF
    BNE MUSICPLAYERPSGLOOPBANKED
@ENDIF
	LDA ,X+			            ;load music data
@IF COCO3
    JMP MUSICPLAYERPSGLOOPREAD
MUSICPLAYERPSGLOOPBANKED
    STB BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    LDX SN76489TMPPTR
    TFR X, D
    ADDD #$C000
    TFR D, X
    LDA SN76489TMPOFS
    INC SN76489TMPOFS
    LDA A,X
    JSR GIMEBANKSHADOWCHANGERESET
    CMPA #0
MUSICPLAYERPSGLOOPREAD
@ENDIF
	BEQ MUSICPLAYERPSGRESET		;equal to ZERO? YES jump to RESET 
	BITA #$C0		            ;test the A register with %11000000 mask (delay data bit)
	BEQ MUSICPLAYERPSGSTOSKIP	;is delay data? YES jump to STOSKIP, NO continue
    TFR A, B
    JSR SN76489WRITE            ;write register A to PSG device (update sound)
    NOP
    NOP
	STX SN76489TMPPTR       	;update the music execution address
	BRA MUSICPLAYERPSGLOOP		;jump to LOOP
MUSICPLAYERPSGSKIP
	DEC SN76489JIFFIES		    ;decrement delay value in memory
MUSICPLAYERPSGEXIT
    PULS X
    PULS D
	RTS				            ;return
MUSICPLAYERPSGSTOSKIP
	ANDA #$07		            ;get the delay value (7*1/50 sec max)
	STA SN76489JIFFIES		    ;store to delay memory address
	STX SN76489TMPPTR       	;update the music execution address
	BRA MUSICPLAYERPSGEXIT		;jump to EXIT
MUSICPLAYERPSGRESET
	LDX SN76489TMPPTR_BACKUP	;reset the execution address (restart music to the start)
	STX SN76489TMPPTR
	BRA MUSICPLAYERPSGEXIT	    ;jump to EXIT

@ENDIF
