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
;*                           MUSIC ROUTINE ON POKEY                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

POKEYMUSICREADY: .byte $0
POKEYMUSICPAUSE: .byte $0
POKEYMUSICLOOP: .byte $0

POKEYBLOCKS: .word $0
POKEYLASTBLOCK: .byte $0

POKEYBLOCKS_BACKUP: .word $0
POKEYLASTBLOCK_BACKUP: .byte $0
POKEYTMPPTR_BACKUP: .word $0

POKEYTMPOFS = $07
POKEYTMPLEN = $08

MUSICPLAYERRESET:
    SEI
    LDA #$0
    STA POKEYJIFFIES
    STA POKEYTMPOFS
    LDA #$1
    STA POKEYMUSICREADY
    LDA POKEYTMPPTR_BACKUP
    STA POKEYTMPPTR
    LDA POKEYTMPPTR_BACKUP+1
    STA POKEYTMPPTR+1
    LDA POKEYLASTBLOCK_BACKUP
    STA POKEYLASTBLOCK
    LDA POKEYBLOCKS_BACKUP
    STA POKEYBLOCKS
    BEQ MUSICPLAYERRESET3
    LDA #$FF
    JMP MUSICPLAYERRESET2
MUSICPLAYERRESET3:
    LDA POKEYLASTBLOCK_BACKUP
MUSICPLAYERRESET2:
    STA POKEYTMPLEN
    CLI
    RTS

; This is the entry point for music play routine
; using the interrupt. 
MUSICPLAYER:
    PHA
    LDA POKEYMUSICREADY
    BEQ MUSICPLAYERQ4
    LDA POKEYMUSICPAUSE
    BNE MUSICPLAYERQ3
    TXA
    PHA
    TYA
    PHA
    JSR MUSICPLAYERR
    PLA
    TAY
    PLA
    TAX
    JMP MUSICPLAYERQ4
MUSICPLAYERQ3:
    LDA POKEYMUSICLOOP
    BEQ MUSICPLAYERQ4
    JSR MUSICPLAYERRESET
MUSICPLAYERQ4:
    PLA
    RTS

MUSICPLAYERR:

; This is the entry point to wait until the waiting jiffies
; are exausted.
MUSICPLAYERL1:
    LDA POKEYJIFFIES
    BEQ MUSICPLAYERL1B
    DEC POKEYJIFFIES
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
    STA POKEYMUSICREADY
    STA POKEYTMPPTR
    STA POKEYTMPPTR+1
    STA POKEYJIFFIES
    RTS

; This is the entry point to decode the instruction
; (contained into the A register).
MUSICPLAYERL1X:
    ASL
    BCS MUSICPLAYERL1X0
    JMP MUSICWAIT
MUSICPLAYERL1X0:
    ASL
    BCS MUSICPLAYERL1X1
    JMP MUSICSETPROGRAM
MUSICPLAYERL1X1:
    ASL
    BCS MUSICPLAYERL1X3
    JMP MUSICNOTEON
MUSICPLAYERL1X3:
    ASL
    BCS MUSICPLAYERL1X2
    JMP MUSICNOTEOFF
MUSICPLAYERL1X2:
    RTS

MUSICWAIT:
    LSR
    STA POKEYJIFFIES
    RTS

MUSICSETPROGRAM:
    PHA
    JSR MUSICREADNEXTBYTE
    PLA
    RTS

MUSICNOTEOFF:
    LSR
    LSR
    LSR
    LSR
    JSR POKEYSTOP
    RTS    

MUSICNOTEON:
    LSR
    LSR
    LSR
    PHA
    JSR MUSICREADNEXTBYTE
    ASL
    TAY
    LDA (POKEYTMPPTR2),Y
    TAX
    INY
    LDA (POKEYTMPPTR2),Y
    TAY
    PLA
    PHA
    JSR POKEYPROGFREQ
    PLA
    PHA
    JSR MUSICREADNEXTBYTE
    LSR
    LSR
    LSR
    LSR
    TAX
    PLA
    JSR POKEYSETVOL
    LDX #$0A
    JSR POKEYPROGDIST
    RTS

; This routine has been added in order to read the
; next byte in a "blocked" byte stream.
MUSICREADNEXTBYTE:
    ; Let's check if we arrived at the end of the block.
    ; In that case, we must "load" the next block (or end
    ; the reading).
    LDY POKEYTMPOFS
    CPY POKEYTMPLEN
    BEQ MUSICREADNEXTBYTELE

MUSICREADNEXTBYTE2:
    LDX #$ff
    LDA (POKEYTMPPTR), Y
    INY
    STY POKEYTMPOFS
    RTS

; This is the entry point if a block (256 or less bytes)
; is finished, and we must move forward to the next block.
MUSICREADNEXTBYTELE:
    ; Is file finished?
    LDA POKEYBLOCKS
    BEQ MUSICREADNEXTBYTEEND

    ; Increment the base address by 256
    INC POKEYTMPPTR+1

    ; Decrement the number of remaining blocks
    DEC POKEYBLOCKS

    ; If remaining blocks are 0, the last block
    ; length is different from 256 bytes.
    BEQ MUSICPLAYERLE2

    ; Remaining block is 256 bytes lenght.
    LDY #$FF
    STY POKEYTMPLEN

    ; Put the index to 0
    LDY #$0
    STY POKEYTMPOFS

    JMP MUSICREADNEXTBYTE2

    ; Remaining block is <256 bytes lenght.
MUSICPLAYERLE2:
    LDY POKEYLASTBLOCK
    STY POKEYTMPLEN

    ; Put the index to 0
    LDY #$0
    STY POKEYTMPOFS

    JMP MUSICREADNEXTBYTE2

MUSICREADNEXTBYTEEND:
    LDX #$0
    RTS

