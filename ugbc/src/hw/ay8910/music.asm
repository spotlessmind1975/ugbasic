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
;*                           MUSIC ROUTINE ON AY-3-8910                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: music address, B: blocks, C: last block
MUSICPLAYERRESET:
    LD A, $0
    LD (AY8910JIFFIES), A
    LD (AY8910TMPOFS), A
    LD A, $1
    LD (AY8910MUSICREADY), A
    LD (AY8910TMPPTR), HL
    LD (AY8910TMPPTR_BACKUP), HL
    LD A, C
    LD (AY8910LASTBLOCK), A
    LD (AY8910LASTBLOCK_BACKUP), A
    LD A, B
    LD (AY8910BLOCKS), A
    LD (AY8910BLOCKS_BACKUP), A
    CP 0
    JR Z, MUSICPLAYERRESET3
    LD A, $FF
    JP MUSICPLAYERRESET2
MUSICPLAYERRESET3:
    LD A, C
MUSICPLAYERRESET2:
    LD (AY8910TMPLEN), A
    RET

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PUSH AF
    LD A, (AY8910MUSICREADY)
    CP 0
    JR Z, MUSICPLAYERQ
    LD A, (AY8910MUSICPAUSE)
    CP 0
    JR NZ, MUSICPLAYERQ2
    PUSH BC
    PUSH DE
    PUSH HL
    CALL MUSICPLAYERR
    POP HL
    POP DE
    POP BC
    JP MUSICPLAYERQ2
MUSICPLAYERQ:
    LD A, (AY8910MUSICLOOP)
    CP 0
    JR Z, MUSICPLAYERQ2

    PUSH BC
    PUSH DE
    PUSH HL

    LD HL, (AY8910TMPPTR_BACKUP)
    LD A, (AY8910LASTBLOCK_BACKUP)
    LD C, A
    LD A, (AY8910BLOCKS_BACKUP)
    LD B, A
    CALL MUSICPLAYERRESET
    POP HL
    POP DE
    POP BC

MUSICPLAYERQ2:
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
    JR C, MUSICPLAYERL1X3
    JMP MUSICPROGRAM
MUSICPLAYERL1X3:
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

MUSICPROGRAM:
    CALL MUSICREADNEXTBYTE
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
    PUSH AF
    PUSH BC
    CALL MUSICREADNEXTBYTE
    LD A, $0
    LD B, A
    SLA C
    RL B
    LD DE, BC
    LD HL, (AY8910TMPPTR2)
    ADD HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD D, (HL)
    POP BC
    POP AF
    CALL AY8910PROGFREQ
    PUSH BC
    PUSH AF
    CALL MUSICREADNEXTBYTE
    SRL C
    SRL C
    SRL C
    SRL C
    LD E, C
    POP AF
    PUSH AF
    CALL AY8910STARTVOL
    POP AF
    POP BC
    CALL AY8910START
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
    ADD HL, DE
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
