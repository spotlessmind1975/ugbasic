; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
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
;*                               DUFF'S DEVICE                                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

    ; This is a special device that should transform the memory movement into
    ; an optimized one. This is done by using some tricks and automodification
    ; assembly code.

DUFFDEVICE

    ; First of all, we avoid to do anything if the memory to copy is equa
    ; to zero. It means that nothing is needed to do, so move to the end
    ; of the routine.

    CMPD #0
    LBEQ DUFFDEVICEDONE

    ; Then, we disable, at startup, the 16 byte copy loop, by assigning
    ; a couple of "NOP" (opcode $12) at the place of the branching.

    LDU #$1212
    STU DUFFDEVICEL0C

    ; So, we must manage the fact that the size is odd: in this case,
    ; the first byte will be copied directly. This is done by dividing
    ; the size by 2 and taking apart the carry bit.

    LSRA
    RORB

    ; CARRY CLEAR (BCC) -> Size was even
    ; CARRY SET   (BCS) -> Size was odd

    BCC DUFFDEVICELX

    ; The size was odd, so copy the first byte and move ahead
    ; source (Y) and destination (X) address.

    PSHS D
    LDA , Y+
    STA , X+
    PULS D

    ; We reach this point having the original size halved. So now we
    ; have to "unroll" the copy. Unrolling is a process that try to
    ; transform a "generic" size copy in a "modulus" size copy.
    ; We use a modulus of 16 bytes (using a 2 byte register for 8 times).
    ; If the size is multiple of 16 bytes, the process is complete as
    ; described. Otherwise, we are going to calculate the "rest" 
    ; (modulus) of the copy. In order to make the process efficient, 
    ; we will first calculate the remaining part (the "modulus", in fact) 
    ; and then we will proceed to copy the rest as quickly as possible,
    ;  which will be a multiple of 16 bytes,

DUFFDEVICELX

    ; Let's put up some numbers (we consider only even sizes):
    ;
    ; - (original) size:  2    (16 byte) blocks: 0     (rest) block size:  2 bytes
    ; - "             ":  4    "              ": 0     "               ":  4 bytes
    ; - "             ":  6    "              ": 0     "               ":  6 bytes
    ; - "             ":  8    "              ": 0     "               ":  8 bytes
    ; - "             ": 10    "              ": 0     "               ": 10 bytes
    ; - "             ": 12    "              ": 0     "               ": 12 bytes
    ; - "             ": 14    "              ": 0     "               ": 14 bytes
    ; - "             ": 16    "              ": 1     "               ":  0 bytes
    ; - "             ": 18    "              ": 1     "               ":  2 bytes
    ; - ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ...
    ; - ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ...
    ; - ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ...
    ;
    ; In D register we have the original size (divided by 2). So we have to 
    ; calculate, first of all, the size of the rest block size.
    ;
    ; RBS = ( 2 * D ) MOD 16 = ( 2 * D ) MOD ( 2 * 8 ) = D MOD 8 = B AND #$7
    
    ; So we save the (halved) size to copy.

    PSHS D

    ; and calculate the block size.

    ANDB #7
    LSLB

    ; If it is zero, it means that no (rest) block size has to be managed.

    BEQ DUFFDEVICELXNR

    ; Othewise, we have to replace the standard block size (16 bytes) with
    ; the rest block size. This is done by automodification technique.

    STB DUFFDEVICEL0A + 2
    STB DUFFDEVICEL0B + 2

    ; Moreover, we must replace the subtraction terms for the loop counter.
    ; Again, this is done by automodification technique. Note that the
    ; loop counter thinks in terms of "2 bytes" so we must store the
    ; half of the block size.

    LSRB
    STB DUFFDEVICEL0D + 2

    ; Finally, we must calculate the address (offset) of the first command 
    ; needed to copy the memory from source to destination. In order to 
    ; understand which is the offset, we must take in count of this
    ; numbers:
    ;
    ; - (original) size:  2    (rest) block size:  2 bytes  offset:     28
    ; - "             ":  4    "               ":  4 bytes              24
    ; - "             ":  6    "               ":  6 bytes              20
    ; - "             ":  8    "               ":  8 bytes              16
    ; - "             ": 10    "               ": 10 bytes              12
    ; - "             ": 12    "               ": 12 bytes              08
    ; - "             ": 14    "               ": 14 bytes              04
    ;
    ; 00: LDU 14, Y
    ; 02: STU 14, X
    ; 04: LDU 12, Y
    ; 06: STU 12, X
    ; .....
    ; 24: LDU 2, Y
    ; 26: STU 2, X
    ; 28: LDU , Y
    ; 30: STU , X
    ;
    ; The formula is 32 - 4 * ( rest block size / 2 ) = 32 - 4 * B

    LDA #4
    MUL
    STB DUFFDELTA
    LDB #32
    SUBB DUFFDELTA
    STB DUFFDEVICEL0+1

    ; If we reach this point, nothing has to be customized since the
    ; memory to copy is multiple of 16 bytes.

DUFFDEVICELXNR
    
    ; Restore the (halved) size to copy.

    PULS D

    ; Move to the first command of the unrolled loop.
    ; This address could be different if (rest) block size.

DUFFDEVICEL0
    BRA DUFFDEVICEL1

    ; This is the unrolled loop to copy 16 bytes at each round.
    ; If the memory to copy is not multiple of 16 bytes, the
    ; first time we will jump "inside" the loop, in order to copy
    ; only a part of the block (< 16 bytes).

DUFFDEVICEL1
    LDU 14, Y
    STU 14, X
    LDU 12, Y
    STU 12, X
    LDU 10, Y
    STU 10, X
    LDU 8, Y
    STU 8, X
    LDU 6, Y
    STU 6, X
    LDU 4, Y
    STU 4, X
    LDU 2, Y
    STU 2, X
    LDU , Y
    STU , X

    ; Move the destination address ahead of the *actual*
    ; block size. Normally it is 16 but not in the first
    ; block copied, that is equal to the (rest) block size.

DUFFDEVICEL0A
    LEAX 16, X

    ; Move the source address ahead of the *actual*
    ; block size. Normally it is 16 but not in the first
    ; block copied, that is equal to the (rest) block size.

DUFFDEVICEL0B
    LEAY 16,Y

    ; Decrement the counter of the size of the block. Normally
    ; it is 8 (2x8 = 16 bytes) but it could be lesser in case
    ; of the first loop for a movement that is not multiple
    ; of 16 bytes.

DUFFDEVICEL0D
    SUBD #$8

    ; Finally, if D <= 0 we can exit the copy process.
    ; Actually, we could just check for D = 0 but I am not
    ; sure that the algorithm is corrected.

    BMI DUFFDEVICEDONE
    BEQ DUFFDEVICEDONE

    ; We can reach this point in two different moments: 
    ; on the first run of the loop, or the n-th one.
    ; If this is the first time we reach this label,
    ; the BRA DUFFDEVICEL1 has been replaced by NOP NOP:
    ; this means that the execution will continue to the
    ; following istructions. Otherwise, this will move
    ; to the next round.

DUFFDEVICEL0C
    BRA DUFFDEVICEL1

    ; If we reached this line, we have copied the very
    ; first block, that could be smaller than 16 bytes.
    ; At this point, we must replace the block size 
    ; with the standard block size (16 bytes)
    ; This is done by automodification technique.
    
    PSHS D

    ; Replace the displacement for each loop.

    LDB #16
    STB DUFFDEVICEL0A+2
    STB DUFFDEVICEL0B+2

    ; Replace the decrement for each loop.

    LDB #8
    STB DUFFDEVICEL0D+2

    ; Replace the NOPs with a jump to the first
    ; instruction of the unrolled loop.

    LDD #$20D1
    STD DUFFDEVICEL0C

    PULS D

    ; Finally, jump to the first instruction
    ; of the unrolled loop.

    BRA DUFFDEVICEL1

DUFFDEVICEDONE
    RTS

DUFFDELTA
    FCB $0
