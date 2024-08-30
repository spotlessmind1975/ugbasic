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
;*                            MUSIC ROUTINE ON SN-76489                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: music address, B: blocks, C: last block
MUSICPLAYERRESET:
    LD A, $0
    LD (SN76489JIFFIES), A
    LD (SN76489TMPOFS), A
    LD A, $1
    LD (SN76489MUSICREADY), A
    LD (SN76489TMPPTR), HL
    LD (SN76489TMPPTR_BACKUP), HL
    LD A, C
    LD (SN76489LASTBLOCK), A
    LD (SN76489LASTBLOCK_BACKUP), A
    LD A, B
    LD (SN76489BLOCKS), A
    LD (SN76489BLOCKS_BACKUP), A
    CP 0
    JR Z, MUSICPLAYERRESET3
    LD A, $FF
    JP MUSICPLAYERRESET2
MUSICPLAYERRESET3:
    LD A, C
MUSICPLAYERRESET2:
    LD (SN76489TMPLEN), A
    RET

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PUSH AF
    LD A, (SN76489MUSICREADY)
    CP 0
    JR Z, MUSICPLAYERQ
    LD A, (SN76489MUSICPAUSE)
    CP 0
    JR NZ, MUSICPLAYERQ2

    LD A, (SN76489MUSICTYPE)
    SRL A
    JR NC, MUSICPLAYER2
    JP MUSICPLAYERIAF
MUSICPLAYER2:
    SRL A
    JR NC, MUSICPLAYER4
    JR MUSICPLAYER8
MUSICPLAYER4:
    SRL A
    JR NC, MUSICPLAYER8
    CALL MUSICPLAYERPSG
MUSICPLAYER8:
    POP AF
    RET

MUSICPLAYERIAF:
    PUSH BC
    PUSH DE
    PUSH HL
    CALL MUSICPLAYERR
    POP HL
    POP DE
    POP BC
    JP MUSICPLAYERQ2
MUSICPLAYERQ:
    LD A, (SN76489MUSICLOOP)
    CP 0
    JR Z, MUSICPLAYERQ2
    PUSH BC
    PUSH DE
    PUSH HL
    LD HL, (SN76489TMPPTR_BACKUP)
    LD A, (SN76489LASTBLOCK_BACKUP)
    LD C, A
    LD A, (SN76489BLOCKS_BACKUP)
    LD B, A
    CALL MUSICPLAYERRESET
    POP HL
    POP DE
    POP BC
MUSICPLAYERQ2:
    LD DE, (SN76489TIMER)
    LD A, E
    OR D
    JR Z, MUSICPLAYERQ2D1
    LD DE, (SN76489TIMER)
    DEC DE
    LD (SN76489TIMER), DE    
    LD DE, (SN76489TIMER)
    LD A, E
    OR D
    JR NZ, MUSICPLAYERQ2D1
    CALL SN76489STOP0
MUSICPLAYERQ2D1:
    LD DE, (SN76489TIMER+2)
    LD A, E
    OR D
    JR Z, MUSICPLAYERQ2D2
    LD DE, (SN76489TIMER+2)
    DEC DE
    LD (SN76489TIMER+2), DE    
    LD DE, (SN76489TIMER+2)
    LD A, E
    OR D
    JR NZ, MUSICPLAYERQ2D2
    CALL SN76489STOP1
MUSICPLAYERQ2D2:
    LD DE, (SN76489TIMER+4)
    LD A, E
    OR D
    JR Z, MUSICPLAYERQ2D3
    LD DE, (SN76489TIMER+4)
    DEC DE
    LD (SN76489TIMER+4), DE    
    LD DE, (SN76489TIMER+4)
    LD A, E
    OR D
    JR NZ, MUSICPLAYERQ2D3
    CALL SN76489STOP2
MUSICPLAYERQ2D3:
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
    ADD HL, DE
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
    ADD HL, DE
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

; Original code by Dino Florenzi:
; https://github.com/dinoflorenzi/THOMSON-MO-TO-SOUNDCARD/blob/efed15f2510d181f550dca5f3da296c8e39fe80d/SN76489AN/DEMOS/VAMPIRE/vampire_music.asm
; Adapted by Marco Spedaletti for ugBASIC and Zilog Z80

MUSICPLAYERPSG:
    PUSH AF
    PUSH HL
	LD A, (SN76489JIFFIES)		    ;load delay counter value 		
    CP 0
	JR NZ, MUSICPLAYERPSGSKIP		;equal to zero? YES continue, NO jump to SKIP 
MUSICPLAYERPSGLOOP:
	LD HL, (SN76489TMPPTR)	        ;load music track execution address
    LD A, (HL)                      ;load music data
    LD B, A
    INC HL
    CP 0
	JR Z, MUSICPLAYERPSGRESET		;equal to ZERO? YES jump to RESET 
    PUSH AF
    AND $C0		                ;test the A register with %11000000 mask (delay data bit)
    CP 0
    POP AF
    JR Z, MUSICPLAYERPSGSTOSKIP	    ;is delay data? YES jump to STOSKIP, NO continue

                                    ;write register A to PSG device (update sound)
    PUSH BC
    PUSH AF
    LD A, CSG_OUT
    LD C, A
    POP AF
    OUT (C), A
    POP BC
	LD (SN76489TMPPTR), HL       	;update the music execution address
	JR MUSICPLAYERPSGLOOP		    ;jump to LOOP
MUSICPLAYERPSGSKIP:
    LD A, (SN76489JIFFIES)          ;decrement delay value in memory
    DEC A
    LD (SN76489JIFFIES), A
MUSICPLAYERPSGEXIT:
    POP HL
    POP AF
	RET				            ;return
MUSICPLAYERPSGSTOSKIP:
	AND $07		                ;get the delay value (7*1/50 sec max)
	LD (SN76489JIFFIES), A	    ;store to delay memory address
	LD (SN76489TMPPTR), HL     	;update the music execution address
	JR MUSICPLAYERPSGEXIT		;jump to EXIT
MUSICPLAYERPSGRESET:
	LD HL, (SN76489TMPPTR_BACKUP)	;reset the execution address (restart music to the start)
	LD (SN76489TMPPTR), HL
	JR MUSICPLAYERPSGEXIT	    ;jump to EXIT
