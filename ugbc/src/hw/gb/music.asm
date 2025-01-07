; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                             MUSIC ROUTINE ON GB                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: music address, B: blocks, C: last block
MUSICPLAYERRESET:
    LD A, $0
    LD (GBJIFFIES), A
    LD (GBTMPOFS), A
    LD A, $1
    LD (GBMUSICREADY), A
    LD (GBTMPPTR), HL
    LD (GBTMPPTR_BACKUP), HL
    LD A, C
    LD (GBLASTBLOCK), A
    LD (GBLASTBLOCK_BACKUP), A
    LD A, B
    LD (GBBLOCKS), A
    LD (GBBLOCKS_BACKUP), A
    CP 0
    JR Z, MUSICPLAYERRESET3
    LD A, $FF
    JP MUSICPLAYERRESET2
MUSICPLAYERRESET3:
    LD A, C
MUSICPLAYERRESET2:
    LD (GBTMPLEN), A
    RET

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PUSH AF
    LD A, (GBMUSICREADY)
    CP 0
    JR Z, MUSICPLAYERQ
    LD A, (GBMUSICPAUSE)
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
    LD A, (GBMUSICLOOP)
    CP 0
    JR Z, MUSICPLAYERQ2

    PUSH BC
    PUSH DE
    PUSH HL

    LD HL, (GBTMPPTR_BACKUP)
    LD A, (GBLASTBLOCK_BACKUP)
    LD C, A
    LD A, (GBBLOCKS_BACKUP)
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
    LD HL, GBJIFFIES
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
    LD (GBMUSICREADY), A
    LD HL, 0
    LD (GBTMPPTR), HL
    LD (GBJIFFIES), A
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
    LD (GBJIFFIES), A
    RET

MUSICPROGRAM:
    CALL MUSICREADNEXTBYTE
    RET

MUSICNOTEOFF:
    SRL A
    SRL A
    SRL A
    SRL A
    CALL GBSTOP
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
    LD HL, (GBTMPPTR2)
    ADD HL, DE
    LD A, (HL)
    LD E, A
    INC HL
    LD D, (HL)
    POP BC
    POP AF
    CALL GBPROGFREQ
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
    CALL GBSTARTVOL
    POP AF
    POP BC
    CALL GBSTART
    RET

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE:
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LD A, (GBTMPOFS)
    LD B, A
    LD A, (GBTMPLEN)
    CP B
    JR Z, MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2:
    LD B, $ff
    LD HL, GBTMPPTR
    LD E, (HL)
    INC HL
    LD D, (HL)
    LD A, 0
    LD H, A
    LD A, (GBTMPOFS)
    LD L, A
    ADD HL, DE
    INC A
    LD (GBTMPOFS), A
    LD A, (HL)
    LD C, A
    RET

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE:
    ; Is file finished?
    LD A, (GBBLOCKS)
    JR Z, MUSICREADNEXTBYTEEND

    ; Put the index to 0
    LD A, 0
    LD (GBTMPOFS), A

    ; Increment the base address by 256
    LD HL, GBTMPPTR
    INC HL
    LD A, (HL)
    INC A
    LD (HL), A 

    ; Decrement the number of remaining blocks
    LD A, (GBBLOCKS)
    DEC A
    LD (GBBLOCKS), A

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    JR Z, MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LD A, $FF
    LD (GBTMPLEN), A
    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2:
    LD A, (GBLASTBLOCK)
    LD (GBTMPLEN), A
    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND:
    LD B, $00
    RET
