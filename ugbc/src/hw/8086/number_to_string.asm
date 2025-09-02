; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  * Inspired from source code by Alwin Henseler on:
;  * https://www.msx.org/forum/development/msx-development/32-bit-long-ascii
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

@EMIT numberConfig.maxDigits AS N2STRINGRESBUFFERSIZE
@EMIT numberConfig.maxBytes AS N2STRINGNUMBERMAXBYTES

N2DINV: times N2STRINGNUMBERMAXBYTES db 0x00
N2DBUF: times N2STRINGRESBUFFERSIZE db 0x00
N2DEND: db 0x00

N2STRING:
N2D8:    
N2D16:   
N2D24:   
N2D32:   
N2D48:   
N2D64:   

    MOV DI, N2DBUF
    MOV CH, 0
    MOV CL, N2STRINGRESBUFFERSIZE
    MOV AL, 32
N2STRINGCD1:
    MOV [DI], AL
    INC DI
    DEC CL
    CMP CL, 0
    JNZ N2STRINGCD1

    ; LD (N2DEND-1),BC ;set BCD value to "0" & place terminating 0
    MOV [N2DEND-1], CX

    ; LD E,1          ; no. of bytes in BCD value

    MOV DL, 1

    ; LD HL,N2DINV+N2STRINGNUMBERMAXBYTES  ; (address MSB input)+1

    MOV DI, N2DINV+N2STRINGNUMBERMAXBYTES

    ; LD A, N2STRINGNUMBERMAXBYTES+1
    ; LD B, A
    ; LD A, $09
    ; LD C, A
    MOV CH, N2STRINGNUMBERMAXBYTES+1
    MOV CL, 0x09
    ; XOR A
    MOV AL, 0
N2DSKP0: 
    ; DEC B
    DEC CH
    ; JR Z,N2DSIZ     ; all 0: continue with postprocessing
    CMP CH, 0
    JZ N2DSIZ
    ; DEC HL
    DEC DI
    ; OR (HL)         ; find first byte <>0
    ; JR Z,N2DSKP0
    OR AL, [DI]
    CMP AL, 0
    JZ N2DSKP0

N2DFND1: 
    ; DEC C
    DEC CL

    ; RLA
    ROL AL, 1

    ; JR NC,N2DFND1   ; determine no. of most significant 1-bit
    JNC N2DFND1

    ; RRA
    ROR AL, 1

    ; LD D,A          ; byte from binary input value
    MOV DH, AL
    
N2DLUS2: 
    ; PUSH HL
    PUSH DI

    ; PUSH BC
    PUSH CX

N2DLUS1: 
    ; LD HL,N2DEND-1  ; address LSB of BCD value
    MOV DI, N2DEND-1

    ; LD B,E          ; current length of BCD value in bytes
    MOV CH, DL

    ; RL D            ; highest bit from input value -> carry
    ROL DH, 1

N2DLUS0: 
    ; LD A, (HL)
    MOV AL, [DI]

    ; ADC A,A

    ADC AL, AL

    ; DAA
    DAA

    ; LD (HL),A       ; double 1 BCD byte from intermediate result
    MOV [DI], AL

    ; DEC HL
    DEC DI

    ; DJNZ N2DLUS0    ; and go on to double entire BCD value (+carry!)
    DEC CH
    
    JNZ N2DLUS0

    ; JR NC,N2DNXT
    JNC N2DNXT

    ; INC E           ; carry at MSB -> BCD value grew 1 byte larger
    INC DL
    ; LD (HL),1       ; initialize new MSB of BCD value

    MOV AL, 1
    MOV [SI], AL

N2DNXT:  
    ; DEC C
    DEC CL

    CMP CL, 0

    ; JR NZ,N2DLUS1   ; repeat for remaining bits from 1 input byte
    JNZ N2DLUS1

    ; POP BC          ; no. of remaining bytes in input value
    POP CX

    ; LD C,8          ; reset bit-counter
    MOV CL, 8

    ; POP HL          ; pointer to byte from input value
    POP DI

    ; DEC HL
    DEC DI

    ; LD D,(HL)       ; get next group of 8 bits

    MOV DH, [DI]

    ; DJNZ N2DLUS2    ; and repeat until last byte from input value
    DEC CH
    CMP CH, 0
    JNZ N2DLUS2

N2DSIZ:  
    ; LD HL,N2DEND    ; address of terminating 0
    MOV DI, N2DEND

    ; LD C,E          ; size of BCD value in bytes
    MOV CL, DL

    ; OR A
    CLC

    ; SBB HL,BC       ; calculate address of MSB BCD
    SBB DI, CX

    ; LD D,H
    ; LD E,L

    PUSH DI
    POP SI

    ; SBB HL,BC
    SBB DI, CX

    ; EX DE,HL        ; HL=address BCD value, DE=start of decimal value
    XCHG SI, DI

    ; LD B,C          ; no. of bytes BCD
    MOV CH, CL

    ; SLA C           ; no. of bytes decimal (possibly 1 too high)

    SAL CL, 1

    ; LD A, 48 ; 0 is ASCII 48
    MOV AL, 48

    ; RLD             ; shift bits 4-7 of (HL) into bit 0-3 of A

    CALL N2STRINGRLD
    
    ; The contents of the high-order 
    ; bits of the Accumulator are unaffected.

    ; CP 48           ; 0 is ASCII 48, (HL) was > 9h?
    CMP AL, 48

    ; JR NZ,N2DEXPH   ; if yes, start with recording high digit
    JNZ N2DEXPH

    ; DEC C           ; correct number of decimals
    DEC CL

    ; INC DE          ; correct start address
    INC SI

    ; JR N2DEXPL      ; continue with converting low digit
    JMP N2DEXPL

N2DEXP:  
    ; RLD             ; shift high digit (HL) into low digit of A
    CALL N2STRINGRLD

N2DEXPH: 
    ; LD (DE),A       ; record resulting ASCII-code
    MOV [SI], AL

    ; INC DE
    INC SI

N2DEXPL: 
    ; RLD
    CALL N2STRINGRLD

    ; LD (DE),A
    MOV [SI], AL

    ; INC DE
    INC SI

    ; INC HL          ; next BCD-byte
    INC DI

    ; DJNZ N2DEXP     ; and go on to convert each BCD-byte into 2 ASCII
    DEC CH
    CMP CH, 0
    JNZ N2DEXP

    ; SBB HL,BC       ; return with HL pointing to 1st decimal

    SBB DI, CX

    ; RET
    RET

N2STRINGRLD:
    ; the previous contents of those high-order four bits are 
    ; copied to the low-order four bits of the Accumulator (Register A); 

    MOV BL, [DI]
    AND BL, 0xf0
    CLC
    SHR BL, 1
    SHR BL, 1
    SHR BL, 1
    SHR BL, 1
    MOV AH, AL
    AND AL, 0xf0
    OR AL, BL

    ; The contents of the low-order four bits (bits 3, 2, 1, and 0) of the memory 
    ; location (HL) are copied to the high-order four bits (7, 6, 5, and 4) of that 
    ; same memory location; 

    MOV BL, [DI]
    CLC
    SAL BL, 1
    SAL BL, 1
    SAL BL, 1
    SAL BL, 1
    MOV [DI], BL

    ; and the previous contents of the low-order four bits of the Accumulator 
    ; are copied to the low-order four bits of memory location (HL). 
    
    PUSH AX
    AND AH, 0x0f
    MOV AL, [DI]
    AND AL, 0xf0
    OR AL, AH
    MOV [DI], AL
    POP AX
    RET
