; -------------------------------------------------------------------------------
; Combined routine for conversion of different sized binary numbers into
; directly printable ASCII(Z)-string
; Input value in registers, number size and -related to that- registers to fill
; is selected by calling the correct entry:
;
;  entry  inputregister(s)  decimal value 0 to:
;   N2D8             A                    255  (3 digits)
;   N2D16           HL                  65535   5   "
;   N2D24         E:HL               16777215   8   "
;   N2D32        DE:HL             4294967295  10   "
; - N2D48     BC:DE:HL        281474976710655  15   "
; - N2D64  IX:BC:DE:HL   18446744073709551615  20   "
;
; The resulting string is placed into a small buffer attached to this routine,
; this buffer needs no initialization and can be modified as desired.
; The number is aligned to the right, and leading 0's are replaced with spaces.
; On exit HL points to the first digit, (B)C = number of decimals
; This way any re-alignment / postprocessing is made easy.
; Changes: AF,BC,DE,HL,IX
;
; Source code originally published by Alwin Henseler on:
; https://www.msx.org/forum/development/msx-development/32-bit-long-ascii
; Adapted by Marco Spedaletti for z88sdk compiler
;
; @thirdparts Alwin Henseler
; -------------------------------------------------------------------------------

N2D8:    LD H,0
         LD L,A
N2D16:   LD E,0
N2D24:   LD D,0
N2D32:   LD BC,0
N2D48:   
        ;  LD IX,0          ; zero all non-used bits
N2D64:   
         LD (N2DINV),HL
         LD (N2DINV+2),DE
        ;  LD (N2DINV+4),BC
        ;  LD (N2DINV+6),IX ; place full 64-bit input value in buffer
         LD HL,N2DBUF
         LD DE,N2DBUF+1
         LD (HL), 32 ; space is ASCII 32
N2DFILC: EQU $-1         ; address of fill-character
         LD BC,18
         LDIR            ; fill 1st 19 bytes of buffer with spaces
         LD (N2DEND-1),BC ;set BCD value to "0" & place terminating 0
         LD E,1          ; no. of bytes in BCD value
         LD HL,N2DINV+8  ; (address MSB input)+1
         LD BC, $0909
         XOR A
N2DSKP0: DEC B
         JR Z,N2DSIZ     ; all 0: continue with postprocessing
         DEC HL
         OR (HL)         ; find first byte <>0
         JR Z,N2DSKP0
N2DFND1: DEC C
         RLA
         JR NC,N2DFND1   ; determine no. of most significant 1-bit
         RRA
         LD D,A          ; byte from binary input value
N2DLUS2: PUSH HL
         PUSH BC
N2DLUS1: LD HL,N2DEND-1  ; address LSB of BCD value
         LD B,E          ; current length of BCD value in bytes
         RL D            ; highest bit from input value -> carry
N2DLUS0: LD A,(HL)
         ADC A,A
         DAA
         LD (HL),A       ; double 1 BCD byte from intermediate result
         DEC HL
         DJNZ N2DLUS0    ; and go on to double entire BCD value (+carry!)
         JR NC,N2DNXT
         INC E           ; carry at MSB -> BCD value grew 1 byte larger
         LD (HL),1       ; initialize new MSB of BCD value
N2DNXT:  DEC C
         JR NZ,N2DLUS1   ; repeat for remaining bits from 1 input byte
         POP BC          ; no. of remaining bytes in input value
         LD C,8          ; reset bit-counter
         POP HL          ; pointer to byte from input value
         DEC HL
         LD D,(HL)       ; get next group of 8 bits
         DJNZ N2DLUS2    ; and repeat until last byte from input value
N2DSIZ:  LD HL,N2DEND    ; address of terminating 0
         LD C,E          ; size of BCD value in bytes
         OR A
         SBC HL,BC       ; calculate address of MSB BCD
         LD D,H
         LD E,L
         SBC HL,BC
         EX DE,HL        ; HL=address BCD value, DE=start of decimal value
         LD B,C          ; no. of bytes BCD
         SLA C           ; no. of bytes decimal (possibly 1 too high)
         LD A, 48 ; 0 is ASCII 48
         RLD             ; shift bits 4-7 of (HL) into bit 0-3 of A
         CP 48           ; 0 is ASCII 48, (HL) was > 9h?
         JR NZ,N2DEXPH   ; if yes, start with recording high digit
         DEC C           ; correct number of decimals
         INC DE          ; correct start address
         JR N2DEXPL      ; continue with converting low digit
N2DEXP:  RLD             ; shift high digit (HL) into low digit of A
N2DEXPH: LD (DE),A       ; record resulting ASCII-code
         INC DE
N2DEXPL: RLD
         LD (DE),A
         INC DE
         INC HL          ; next BCD-byte
         DJNZ N2DEXP     ; and go on to convert each BCD-byte into 2 ASCII
         SBC HL,BC       ; return with HL pointing to 1st decimal
         RET

