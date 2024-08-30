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
;*                           MUSIC PLAYER ROUTINE ON SID                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SIDMUSICLOOP: .byte $0
SIDMUSICREADY: .byte $0
SIDMUSICPAUSE: .byte $0
SIDBLOCKS: .word $0
SIDLASTBLOCK: .byte $0

SIDBLOCKS_BACKUP: .word $0
SIDLASTBLOCK_BACKUP: .byte $0
SIDTMPPTR_BACKUP: .word $0

SIDTMPPTR2 = $03 ; $04
SIDTMPPTR = $05 ; $06
SIDTMPOFS = $07
SIDTMPLEN = $08
SIDJIFFIES = $09 ; $0A

MUSICPLAYERRESET:
    LDA #$0
    STA SIDJIFFIES
    STA SIDTMPOFS
    LDA #$1
    STA SIDMUSICREADY
    LDA SIDTMPPTR_BACKUP
    STA SIDTMPPTR
    LDA SIDTMPPTR_BACKUP+1
    STA SIDTMPPTR+1
    LDA SIDLASTBLOCK_BACKUP
    STA SIDLASTBLOCK
    LDA SIDBLOCKS_BACKUP
    STA SIDBLOCKS
    BEQ MUSICPLAYERRESET3
    LDA #$FF
    JMP MUSICPLAYERRESET2
MUSICPLAYERRESET3:
    LDA SIDLASTBLOCK_BACKUP
MUSICPLAYERRESET2:
    STA SIDTMPLEN
    RTS

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PHP
    PHA
    LDA SIDMUSICREADY
    BEQ MUSICPLAYERQ
    LDA SIDMUSICPAUSE
    BEQ MUSICPLAYERQ2
    TXA
    PHA
    TYA
    PHA
    JSR MUSICPLAYERR
    PLA
    TAY
    PLA
    TAX
    JMP MUSICPLAYERQ2
MUSICPLAYERQ:
    LDA SIDTIMER
    BEQ MUSICPLAYERQ0
    DEC SIDTIMER
    BNE MUSICPLAYERQ0
    JSR SIDSTOP0
MUSICPLAYERQ0:
    LDA SIDTIMER+1
    BEQ MUSICPLAYERQ1
    DEC SIDTIMER+1
    BNE MUSICPLAYERQ1
    JSR SIDSTOP1
MUSICPLAYERQ1:
    LDA SIDTIMER+2
    BEQ MUSICPLAYERQ2
    DEC SIDTIMER+2
    BNE MUSICPLAYERQ2
    JSR SIDSTOP2
MUSICPLAYERQ2:
    PLA
    PLP
    RTS

MUSICPLAYERR:

; This is the entry point to wait until the waiting jiffies
; are exausted.
MUSICPLAYERL1:
    LDA SIDJIFFIES
    BEQ MUSICPLAYERL1B
    DEC SIDJIFFIES
    RTS

; This is the entry point to read the next instruction.
MUSICPLAYERL1B:
    ; Read the next byte.
    JSR MUSICREADNEXTBYTE

    ; Is the file NOT finished?
    CPX #$0
    BNE MUSICPLAYERL1X

    ; Let's stop the play!
    LDA #$0
    STA SIDMUSICREADY
    STA SIDTMPPTR
    STA SIDTMPPTR+1
    STA SIDJIFFIES
    RTS

; This is the entry point to decode the instruction
; (contained into the A register).
MUSICPLAYERL1X:
    ASL
    BCS MUSICPLAYERL1X0
    JMP MUSICWAIT
MUSICPLAYERL1X0:
    ASL
    BCS MUSICPLAYERL1X0A
    JMP MUSICSETPROGRAM
MUSICPLAYERL1X0A:
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
    STA SIDJIFFIES
    RTS

MUSICSETPROGRAM:
    LSR
    LSR
    TAX
    JSR MUSICREADNEXTBYTE
    JSR SIDSETPROGRAM
    RTS    

MUSICNOTEOFF:
    LSR
    LSR
    LSR
    LSR
    JSR SIDSTOP
    RTS    

MUSICNOTEON:
    LSR
    LSR
    LSR
    PHA
    JSR MUSICREADNEXTBYTE
    ASL
    TAY
    LDA (SIDTMPPTR2),Y
    TAX
    INY
    LDA (SIDTMPPTR2),Y
    TAY
    PLA
    JSR SIDPROGFREQ
    RTS

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE:
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LDY SIDTMPOFS
    CPY SIDTMPLEN
    BEQ MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2:
    LDX #$ff
    LDA (SIDTMPPTR), Y
    INY
    STY SIDTMPOFS
    RTS

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE:
    ; Is file finished?
    LDA SIDBLOCKS
    BEQ MUSICREADNEXTBYTEEND

    ; Increment the base address by 256
    INC SIDTMPPTR+1

    ; Decrement the number of remaining blocks
    DEC SIDBLOCKS

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    BEQ MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LDY #$FF
    STY SIDTMPLEN

    ; Put the index to 0
    LDY #$0
    STY SIDTMPOFS

    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2:
    LDY SIDLASTBLOCK
    STY SIDTMPLEN

    ; Put the index to 0
    LDY #$0
    STY SIDTMPOFS

    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND:
    LDX #$0
    RTS
