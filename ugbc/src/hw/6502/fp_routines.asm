;           JULY 5, 1976
;     BASIC FLOATING POINT ROUTINES
;       FOR 6502 MICROPROCESSOR
;       BY R. RANKIN AND S. WOZNIAK
;
;     CONSISTING OF:
;        NATURAL LOG
;        COMMON LOG
;        EXPONENTIAL (E**X)
;        FLOAT      FIX
;        FADD       FSUB
;        FMUL       FDIV
;
;
;     FLOATING POINT REPRESENTATION (4-BYTES)
;                    EXPONENT BYTE 1
;                    MANTISSA BYTES 2-4
;
;     MANTISSA:    TWO'S COMPLEMENT REPRESENTATION WITH SIGN IN
;       MSB OF HIGH-ORDER BYTE.  MANTISSA IS NORMALIZED WITH AN
;       ASSUMED DECIMAL POINT BETWEEN BITS 5 AND 6 OF THE HIGH-ORDER
;       BYTE.  THUS THE MANTISSA IS IN THE RANGE 1. TO 2. EXCEPT
;       WHEN THE NUMBER IS LESS THAN 2**(-128).
;
;     EXPONENT:    THE EXPONENT REPRESENTS POWERS OF TWO.  THE
;       REPRESENTATION IS 2'S COMPLEMENT EXCEPT THAT THE SIGN
;       BIT (BIT 7) IS COMPLEMENTED.  THIS ALLOWS DIRECT COMPARISON
;       OF EXPONENTS FOR SIZE SINCE THEY ARE STORED IN INCREASING
;       NUMERICAL SEQUENCE RANGING FROM $00 (-128) TO $FF (+127)
;       ($ MEANS NUMBER IS HEXADECIMAL).
;
;     REPRESENTATION OF DECIMAL NUMBERS:    THE PRESENT FLOATING
;       POINT REPRESENTATION ALLOWS DECIMAL NUMBERS IN THE APPROXIMATE
;       RANGE OF 10**(-38) THROUGH 10**(38) WITH 6 TO 7 SIGNIFICANT
;       DIGITS.
;
;
;
WOZFP:
;
;
;     NATURAL LOG OF MANT/EXP1 WITH RESULT IN MANT/EXP1
;
LOG:    LDA M1
        BEQ ERROR
        BPL CONT    ; IF ARG>0 OK
ERROR:  BRK         ; ERROR ARG<=0
;
CONT:  JSR SWAP    ; MOVE ARG TO EXP/MANT2
       LDX #0      ; LOAD X FOR HIGH BYTE OF EXPONENT
       LDA X2      ; HOLD EXPONENT
       LDY #$80
       STY X2      ; SET EXPONENT 2 TO 0 ($80)
       EOR #$80    ; COMPLEMENT SIGN BIT OF ORIGINAL EXPONENT
       STA M1+1    ; SET EXPONENT INTO MANTISSA 1 FOR FLOAT
       BPL *+3     ; IS EXPONENT NEGATIVE
       DEX         ; YES, SET X TO $FF
       STX M1      ; SET UPPER BYTE OF EXPONENT
       JSR FLOAT   ; CONVERT TO FLOATING POINT
       LDX #3      ; 4 BYTE TRANSFERS
SEXP1: 
@IF C128
       LDA X2+3
       STA ZZ+3
       LDA X1+3
       STA SEXP+3
       LDA R22+3
       STA X1+3

       LDA X2+2
       STA ZZ+2
       LDA X1+2
       STA SEXP+2
       LDA R22+2
       STA X1+2

       LDA X2+1
       STA ZZ+1
       LDA X1+1
       STA SEXP+1
       LDA R22+1
       STA X1+1

       LDA X2
       STA ZZ
       LDA X1
       STA SEXP
       LDA R22
       STA X1

@ELSE
       LDA X2,X
       STA ZZ,X    ; COPY MANTISSA TO Z
       LDA X1,X
       STA SEXP,X  ; SAVE EXPONENT IN SEXP
       LDA R22,X   ; LOAD EXP/MANT1 WITH SQRT(2)
       STA X1,X
       DEX
       BPL SEXP1
@ENDIF
       JSR FSUB    ; Z-SQRT(2)

       LDX #3      ; 4 BYTE TRANSFER
SAVET: 

@IF C128
       LDA X1+3
       STA T+3
       LDA ZZ+3
       STA X1+3
       LDA R22+3
       STA X2+3

       LDA X1+2
       STA T+2
       LDA ZZ+2
       STA X1+2
       LDA R22+2
       STA X2+2

       LDA X1+1
       STA T+1
       LDA ZZ+1
       STA X1+1
       LDA R22+1
       STA X2+1

       LDA X1
       STA T
       LDA ZZ
       STA X1
       LDA R22
       STA X2
@ELSE
       LDA X1,X    ; SAVE EXP/MANT1 AS T
       STA T,X
       LDA ZZ,X    ; LOAD EXP/MANT1 WITH Z
       STA X1,X
       LDA R22,X   ; LOAD EXP/MANT2 WITH SQRT(2)
       STA X2,X
       DEX
       BPL SAVET
@ENDIF

       JSR FADD    ; Z+SQRT(2)
       LDX #3      ; 4 BYTE TRANSFER
TM2:   

@IF C128
       LDA T+3
       STA X2+3

       LDA T+2
       STA X2+2

       LDA T+1
       STA X2+1

       LDA T
       STA X2
@ELSE
       LDA T,X
       STA X2,X    ; LOAD T INTO EXP/MANT2
       DEX
       BPL TM2
@ENDIF

       JSR FDIV    ; T=(Z-SQRT(2))/(Z+SQRT(2))
       LDX #3      ; 4 BYTE TRANSFER
MIT:   

@IF C128
       LDA X1+3
       STA T+3
       STA X2+3

       LDA X1+2
       STA T+2
       STA X2+2

       LDA X1+1
       STA T+1
       STA X2+1

       LDA X1
       STA T
       STA X2

@ELSE
       LDA X1,X
       STA T,X     ; COPY EXP/MANT1 TO T AND
       STA X2,X    ; LOAD EXP/MANT2 WITH T
       DEX
       BPL MIT
@ENDIF

       JSR FMUL    ; T*T
       JSR SWAP    ; MOVE T*T TO EXP/MANT2
       LDX #3      ; 4 BYTE TRANSFER
MIC:   

@IF C128
       LDA C+3
       STA X1+3

       LDA C+2
       STA X1+2

       LDA C+1
       STA X1+1

       LDA C
       STA X1
@ELSE
       LDA C,X
       STA X1,X    ; LOAD EXP/MANT1 WITH C
       DEX
       BPL MIC
@ENDIF
       JSR FSUB    ; T*T-C
       LDX #3      ; 4 BYTE TRANSFER
M2MB:  

@IF C128

       LDA MB+3
       STA X2+3

       LDA MB+2
       STA X2+2

       LDA MB+1
       STA X2+1

       LDA MB
       STA X2

@ELSE
       LDA MB,X
       STA X2,X    ; LOAD EXP/MANT2 WITH MB
       DEX
       BPL M2MB
@ENDIF
       JSR FDIV    ; MB/(T*T-C)
       LDX #3
M2A1:  

@IF C128
       LDA A1+3
       STA X2+3
       
       LDA A1+2
       STA X2+2

       LDA A1+1
       STA X2+1

       LDA A1
       STA X2

@ELSE
       LDA A1,X
       STA X2,X    ; LOAD EXP/MANT2 WITH A1
       DEX
       BPL M2A1
@ENDIF
       JSR FADD    ; MB/(T*T-C)+A1
       LDX #3      ; 4 BYTE TRANSFER
M2T:   

@IF C128

       LDA T+3
       STA X2+3

       LDA T+2
       STA X2+2

       LDA T+1
       STA X2+1

       LDA T
       STA X2

@ELSE
       LDA T,X
       STA X2,X    ; LOAD EXP/MANT2 WITH T
       DEX
       BPL M2T

@ENDIF

       JSR FMUL    ; (MB/(T*T-C)+A1)*T
       LDX #3      ; 4 BYTE TRANSFER
M2MHL: 

@IF C128
       LDA MHLF+3
       STA X2+3

       LDA MHLF+2
       STA X2+2

       LDA MHLF+1
       STA X2+1

       LDA MHLF
       STA X2
@ELSE
       LDA MHLF,X
       STA X2,X    ; LOAD EXP/MANT2 WITH MHLF (.5)
       DEX
       BPL M2MHL
@ENDIF
       JSR FADD    ; +.5
       LDX #3      ; 4 BYTE TRANSFER
LDEXP: 

@IF C128

       LDA SEXP+3
       STA X2+3

       LDA SEXP+2
       STA X2+2

       LDA SEXP+1
       STA X2+1

       LDA SEXP
       STA X2

@ELSE
       LDA SEXP,X
       STA X2,X    ; LOAD EXP/MANT2 WITH ORIGINAL EXPONENT
       DEX
       BPL LDEXP
@ENDIF

       JSR FADD    ; +EXPN
       LDX #3      ; 4 BYTE TRANSFER
MLE2:  

@IF C128
       LDA LE2+3
       STA X2+3

       LDA LE2+2
       STA X2+2

       LDA LE2+1
       STA X2+1

       LDA LE2
       STA X2
@ELSE
       LDA LE2,X
       STA X2,X    ; LOAD EXP/MANT2 WITH LN(2)
       DEX
       BPL MLE2
@ENDIF
       JSR FMUL    ; *LN(2)
       RTS         ; RETURN RESULT IN MANT/EXP1
;
;     COMMON LOG OF MANT/EXP1 RESULT IN MANT/EXP1
;
LOG10: JSR LOG     ; COMPUTE NATURAL LOG
       LDX #3
L10:   

@IF C128
       LDA LN10+3
       STA X2+3

       LDA LN10+2
       STA X2+2

       LDA LN10+1
       STA X2+1

       LDA LN10
       STA X2
@ELSE
       LDA LN10,X
       STA X2,X    ; LOAD EXP/MANT2 WITH 1/LN(10)
       DEX
       BPL L10
@ENDIF
       JSR FMUL    ; LOG10(X)=LN(X)/LN(10)
       RTS
;
LN10:  .byte $7E, $6F, $2D, $ED ; 0.4342945

R22:   .byte $80, $5A, $82, $7A ; 1.4142136 SQRT(2)

LE2:   .byte $7F, $58, $B9, $0C ; 0.69314718 LOG BASE E OF 2

A1:    .byte $80, $52, $B0, 40 ; 1.2920074

MB:    .byte $81, $AB, $86, $49 ; -2.6398577

C:     .byte $80, $6A, $08, $66 ; 1.6567626

MHLF:  .byte $7F, $40, $00, $00 ; 0.5

;
;
;     EXP OF MANT/EXP1 RESULT IN MANT/EXP1
;
EXP:   LDX #3      ; 4 BYTE TRANSFER

@IF C128
       LDA L2E+3
       STA X2+3

       LDA L2E+2
       STA X2+2

       LDA L2E+1
       STA X2+1

       LDA L2E
       STA X2
@ELSE
EXP2:
       LDA L2E,X
       STA X2,X    ; LOAD EXP/MANT2 WITH LOG BASE 2 OF E
       DEX
       BPL EXP2
@ENDIF

       JSR FMUL    ; LOG2(3)*X
       LDX #3      ; 4 BYTE TRANSFER
FSA:   

@IF C128
       LDA X1+3
       STA ZZ+3

       LDA X1+2
       STA ZZ+2

       LDA X1+1
       STA ZZ+1

       LDA X1
       STA ZZ
@ELSE
       LDA X1,X
       STA ZZ,X    ; STORE EXP/MANT1 IN Z
       DEX
       BPL FSA     ; SAVE Z=LN(2)*X
@ENDIF

       JSR FIX     ; CONVERT CONTENTS OF EXP/MANT1 TO AN INTEGER
       LDA M1+1
       STA INT     ; SAVE RESULT AS INT
       SEC         ; SET CARRY FOR SUBTRACTION
       SBC #124    ; INT-124
       LDA M1
       SBC #0
       BPL OVFLW   ; OVERFLOW INT>=124
       CLC         ; CLEAR CARRY FOR ADD
       LDA M1+1
       ADC #120    ; ADD 120 TO INT
       LDA M1
       ADC #0
       BPL CONTIN  ; IF RESULT POSITIVE CONTINUE
       LDA #0      ; INT<-120 SET RESULT TO ZERO AND RETURN
       LDX #3      ; 4 BYTE MOVE
ZERO:  

@IF C128
       STA X1+3
       STA X1+2
       STA X1+1
       STA X1
@ELSE
       STA X1,X    ; SET EXP/MANT1 TO ZERO
       DEX
       BPL ZERO
@ENDIF
       RTS         ; RETURN
;
OVFLW: BRK         ; OVERFLOW
;
CONTIN: JSR FLOAT   ; FLOAT INT
       LDX #3
ENTD:  

@IF C128
       LDA ZZ+3
       STA X2+3

       LDA ZZ+2
       STA X2+2

       LDA ZZ+1
       STA X2+1

       LDA ZZ
       STA X2
@ELSE
       LDA ZZ,X
       STA X2,X    ; LOAD EXP/MANT2 WITH Z
       DEX
       BPL ENTD
@ENDIF

       JSR FSUB    ; Z*Z-FLOAT(INT)
       LDX #3      ; 4 BYTE MOVE
ZSAV:  

@IF C128
       LDA X1+3
       STA ZZ+3
       STA X2+3

       LDA X1+2
       STA ZZ+2
       STA X2+2

       LDA X1+1
       STA ZZ+1
       STA X2+1

       LDA X1
       STA ZZ
       STA X2
@ELSE
       LDA X1,X
       STA ZZ,X    ; SAVE EXP/MANT1 IN Z
       STA X2,X    ; COPY EXP/MANT1 TO EXP/MANT2
       DEX
       BPL ZSAV
@ENDIF

       JSR FMUL    ; Z*Z
       LDX #3      ; 4 BYTE MOVE
LA2:   

@IF C128
       LDA A2+3
       STA X2+3
       LDA X1+3
       STA SEXP+3

       LDA A2+2
       STA X2+2
       LDA X1+2
       STA SEXP+2

       LDA A2+1
       STA X2+1
       LDA X1+1
       STA SEXP+1

       LDA A2
       STA X2
       LDA X1
       STA SEXP
@ELSE
       LDA A2,X
       STA X2,X    ; LOAD EXP/MANT2 WITH A2
       LDA X1,X
       STA SEXP,X  ; SAVE EXP/MANT1 AS SEXP
       DEX
       BPL LA2
@ENDIF

       JSR FADD    ; Z*Z+A2
       LDX #3      ; 4 BYTE MOVE
LB2:   

@IF C128
       LDA B2+3
       STA X2+3

       LDA B2+2
       STA X2+2

       LDA B2+1
       STA X2+1

       LDA B2
       STA X2
@ELSE
       LDA B2,X
       STA X2,X    ; LOAD EXP/MANT2 WITH B2
       DEX
       BPL LB2
@ENDIF
       JSR FDIV    ; T=B/(Z*Z+A2)
       LDX #3      ; 4 BYTE MOVE
DLOAD: 

@IF C128
       LDA X1+3
       STA T+3
       LDA C2+3
       STA X1+3
       LDA SEXP+3
       STA X2+3

       LDA X1+2
       STA T+2
       LDA C2+2
       STA X1+2
       LDA SEXP+2
       STA X2+2

       LDA X1+1
       STA T+1
       LDA C2+1
       STA X1+1
       LDA SEXP+1
       STA X2+1

       LDA X1
       STA T
       LDA C2
       STA X1
       LDA SEXP
       STA X2

@ELSE
       LDA X1,X
       STA T,X     ; SAVE EXP/MANT1 AS T
       LDA C2,X
       STA X1,X    ; LOAD EXP/MANT1 WITH C2
       LDA SEXP,X
       STA X2,X    ; LOAD EXP/MANT2 WITH SEXP
       DEX
       BPL DLOAD
@ENDIF

       JSR FMUL    ; Z*Z*C2
       JSR SWAP    ; MOVE EXP/MANT1 TO EXP/MANT2
       LDX #3      ; 4 BYTE TRANSFER
LTMP:  

@IF C128
       LDA T+3
       STA X1+3

       LDA T+2
       STA X1+2

       LDA T+1
       STA X1+1

       LDA T
       STA X1
@ELSE
       LDA T,X
       STA X1,X    ; LOAD EXP/MANT1 WITH T
       DEX
       BPL LTMP
@ENDIF

       JSR FSUB    ; C2*Z*Z-B2/(Z*Z+A2)
       LDX #3      ; 4 BYTE TRANSFER
LDD:   

@IF C128
       LDA D+3
       STA X2+3

       LDA D+2
       STA X2+2

       LDA D+1
       STA X2+1

       LDA D
       STA X2
@ELSE
       LDA D,X
       STA X2,X    ; LOAD EXP/MANT2 WITH D
       DEX
       BPL LDD
@ENDIF

       JSR FADD    ; D+C2*Z*Z-B2/(Z*Z+A2)
       JSR SWAP    ; MOVE EXP/MANT1 TO EXP/MANT2
       LDX #3      ; 4 BYTE TRANSFER
LFA:   

@IF C128
       LDA ZZ+3
       STA X1+3

       LDA ZZ+2
       STA X1+2

       LDA ZZ+1
       STA X1+1

       LDA ZZ
       STA X1
@ELSE
       LDA ZZ,X
       STA X1,X    ; LOAD EXP/MANT1 WITH Z
       DEX
       BPL LFA
@ENDIF

       JSR FSUB    ; -Z+D+C2*Z*Z-B2/(Z*Z+A2)
       LDX #3      ; 4 BYTE TRANSFER
LF3:   

@IF C128
       LDA ZZ+3
       STA X2+3

       LDA ZZ+2
       STA X2+2

       LDA ZZ+1
       STA X2+1

       LDA ZZ
       STA X2
@ELSE
       LDA ZZ,X
       STA X2,X    ; LOAD EXP/MANT2 WITH Z
       DEX
       BPL LF3
@ENDIF

       JSR FDIV    ; Z/(**** )
       LDX #3      ; 4 BYTE TRANSFER
LD12:  

@IF C128
       LDA MHLF+3
       STA X2+3

       LDA MHLF+2
       STA X2+2

       LDA MHLF+1
       STA X2+1

       LDA MHLF
       STA X2
@ELSE
       LDA MHLF,X
       STA X2,X    ; LOAD EXP/MANT2 WITH .5
       DEX
       BPL LD12
@ENDIF

       JSR FADD    ; +Z/(***)+.5
       SEC         ; ADD INT TO EXPONENT WITH CARRY SET
       LDA INT     ; TO MULTIPLY BY
       ADC X1      ; 2**(INT+1)
       STA X1      ; RETURN RESULT TO EXPONENT
       RTS         ; RETURN ANS=(.5+Z/(-Z+D+C2*Z*Z-B2/(Z*Z+A2))*2**(INT+1)

L2E:   .byte $80, $5C, $55, $1E ; 1.4426950409 LOG BASE 2 OF E
A2:    .byte $86, $57, $6A, $E1 ; 87.417497202
B2:    .byte $89, $4D, $3F, $1D ; 617.9722695
C2:    .byte $7B, $46, $FA, $70 ; .03465735903
D:     .byte $83, $4F, $A3, $03 ; 9.9545957821

;
;
;     BASIC FLOATING POINT ROUTINES
;
ADD:   CLC         ; CLEAR CARRY
       LDX #$02    ; INDEX FOR 3-BYTE ADD
ADD1:  

@IF C128
       LDA M1+2
       ADC M2+2
       STA M1+2

       LDA M1+1
       ADC M2+1
       STA M1+1

       LDA M1
       ADC M2
       STA M1
@ELSE
       LDA M1,X
       ADC M2,X    ; ADD A BYTE OF MANT2 TO MANT1
       STA M1,X
       DEX         ; ADVANCE INDEX TO NEXT MORE SIGNIF.BYTE
       BPL ADD1    ; LOOP UNTIL DONE.
@ENDIF
       RTS         ; RETURN

MD1:   ASL SIGN    ; CLEAR LSB OF SIGN
       JSR ABSWAP  ; ABS VAL OF MANT1, THEN SWAP MANT2
ABSWAP: BIT M1     ; MANT1 NEG?
       BPL ABSWP1  ; NO,SWAP WITH MANT2 AND RETURN
       JSR FCOMPL  ; YES, COMPLEMENT IT.
       INC SIGN    ; INCR SIGN, COMPLEMENTING LSB
ABSWP1: SEC        ; SET CARRY FOR RETURN TO MUL/DIV
;
;     SWAP EXP/MANT1 WITH EXP/MANT2
;
SWAP:  LDX #$04    ; INDEX FOR 4-BYTE SWAP.
SWAP1: 

@IF C128
       STY E-1+4
       LDA X1-1+4
       LDY X2-1+4
       STY X1-1+4
       STA X2-1+4

       STY E-1+3
       LDA X1-1+3
       LDY X2-1+3
       STY X1-1+3
       STA X2-1+3

       STY E-1+2
       LDA X1-1+2
       LDY X2-1+2
       STY X1-1+2
       STA X2-1+2

       STY E-1+1
       LDA X1-1+1
       LDY X2-1+1
       STY X1-1+1
       STA X2-1+1
@ELSE
       STY E-1,X
       LDA X1-1,X  ; SWAP A BYTE OF EXP/MANT1 WITH
       LDY X2-1,X  ; EXP/MANT2 AND LEAVEA COPY OF
       STY X1-1,X  ; MANT1 IN E(3BYTES). E+3 USED.
       STA X2-1,X
       DEX         ; ADVANCE INDEX TO NEXT BYTE
       BNE SWAP1   ; LOOP UNTIL DONE.
@ENDIF
       RTS
;
;
;
;     CONVERT 16 BIT INTEGER IN M1(HIGH) AND M1+1(LOW) TO F.P.
;     RESULT IN EXP/MANT1.  EXP/MANT2 UNEFFECTED
;
;
FLOAT: LDA #$8E
       STA X1      ; SET EXPN TO 14 DEC
       LDA #0      ; CLEAR LOW ORDER BYTE
       STA M1+2
       BEQ NORML   ; NORMALIZE RESULT
NORM1: DEC X1      ; DECREMENT EXP1
       ASL M1+2
       ROL M1+1    ; SHIFT MANT1 (3 BYTES) LEFT
       ROL M1
NORML: LDA M1      ; HIGH ORDER MANT1 BYTE
       ASL         ; UPPER TWO BITS UNEQUAL?
       EOR M1
       BMI RTS1    ; YES,RETURN WITH MANT1 NORMALIZED
       LDA X1      ; EXP1 ZERO?
       BNE NORM1   ; NO, CONTINUE NORMALIZING
RTS1:  RTS         ; RETURN
;
;
;     EXP/MANT2-EXP/MANT1 RESULT IN EXP/MANT1
;
FSUB:  JSR FCOMPL  ; CMPL MANT1 CLEARS CARRY UNLESS ZERO
SWPALG: JSR ALGNSW ; RIGHT SHIFT MANT1 OR SWAP WITH MANT2 ON CARRY
;
;     ADD EXP/MANT1 AND EXP/MANT2 RESULT IN EXP/MANT1
;
FADD:  LDA X2
       CMP X1      ; COMPARE EXP1 WITH EXP2
       BNE SWPALG  ; IF UNEQUAL, SWAP ADDENDS OR ALIGN MANTISSAS
       JSR ADD     ; ADD ALIGNED MANTISSAS
ADDEND: BVC NORML  ; NO OVERFLOW, NORMALIZE RESULTS
       BVS RTLOG   ; OV: SHIFT MANT1 RIGHT. NOTE CARRY IS CORRECT SIGN
ALGNSW: BCC SWAP   ; SWAP IF CARRY CLEAR, ELSE SHIFT RIGHT ARITH.
RTAR:  LDA M1      ; SIGN OF MANT1 INTO CARRY FOR
       ASL         ; RIGHT ARITH SHIFT
RTLOG: INC X1      ; INCR EXP1 TO COMPENSATE FOR RT SHIFT

@IF C128
       BNE OVFLX    ; EXP1 OUT OF RANGE.
       JMP OVFL
OVFLX:
@ELSE
       BEQ OVFL    ; EXP1 OUT OF RANGE.
@ENDIF

RTLOG1: LDX #$FA   ; INDEX FOR 6 BYTE RIGHT SHIFT
@IF C128
ROR1:  
       LDA #$80
       BCS ROR26
       ASL
ROR26: LSR E+3-6
       ORA E+3-6
       STA E+3-6

       LDA #$80
       BCS ROR25
       ASL
ROR25: LSR E+3-5
       ORA E+3-5
       STA E+3-5

       LDA #$80
       BCS ROR24
       ASL
ROR24: LSR E+3-4
       ORA E+3-4
       STA E+3-4

       LDA #$80
       BCS ROR23
       ASL
ROR23: LSR E+3-3
       ORA E+3-3
       STA E+3-3

       LDA #$80
       BCS ROR22
       ASL
ROR22: LSR E+3-2
       ORA E+3-2
       STA E+3-2

       LDA #$80
       BCS ROR21
       ASL
ROR21: LSR E+3-1
       ORA E+3-1
       STA E+3-1
@ELSE
ROR1:  
       LDA #$80
       BCS ROR2
       ASL
ROR2:  LSR E+3,X   ; SIMULATE ROR E+3,X
       ORA E+3,X
       STA E+3,X
       INX         ; NEXT BYTE OF SHIFT
       BNE ROR1    ; LOOP UNTIL DONE
@ENDIF

       RTS         ; RETURN
;
;
;     EXP/MANT1 X EXP/MANT2 RESULT IN EXP/MANT1
;
FMUL:  JSR MD1     ; ABS. VAL OF MANT1, MANT2
       ADC X1      ; ADD EXP1 TO EXP2 FOR PRODUCT EXPONENT
       JSR MD2     ; CHECK PRODUCT EXP AND PREPARE FOR MUL
       CLC         ; CLEAR CARRY
MUL1:  JSR RTLOG1  ; MANT1 AND E RIGHT.(PRODUCT AND MPLIER)
       BCC MUL2    ; IF CARRY CLEAR, SKIP PARTIAL PRODUCT
       JSR ADD     ; ADD MULTIPLICAN TO PRODUCT
MUL2:  DEY         ; NEXT MUL ITERATION
       BPL MUL1    ; LOOP UNTIL DONE
MDEND: LSR SIGN    ; TEST SIGN (EVEN/ODD)

@IF C128
NORMX: BCS NORMLX   ; IF EXEN, NORMALIZE PRODUCT, ELSE COMPLEMENT
       JMP NORML
NORMLX:
@ELSE
NORMX: BCC NORML   ; IF EXEN, NORMALIZE PRODUCT, ELSE COMPLEMENT
@ENDIF

FCOMPL: SEC        ; SET CARRY FOR SUBTRACT
       LDX #$03    ; INDEX FOR 3 BYTE SUBTRACTION
COMPL1:

@IF C128
       LDA #$00   ; CLEAR A
       SBC X1+3
       STA X1+3

       LDA #$00   ; CLEAR A
       SBC X1+2
       STA X1+2

       LDA #$00   ; CLEAR A
       SBC X1+1
       STA X1+1
@ELSE
       LDA #$00   ; CLEAR A
       SBC X1,X    ; SUBTRACT BYTE OF EXP1
       STA X1,X    ; RESTORE IT
       DEX         ; NEXT MORE SIGNIFICANT BYTE
       BNE COMPL1  ; LOOP UNTIL DONE
@ENDIF

@IF C128
       JMP ADDEND  ; NORMALIZE (OR SHIFT RIGHT IF OVERFLOW)
@ELSE
       BEQ ADDEND  ; NORMALIZE (OR SHIFT RIGHT IF OVERFLOW)
@ENDIF
;
;
;     EXP/MANT2 / EXP/MANT1 RESULT IN EXP/MANT1
;
FDIV:  JSR MD1     ; TAKE ABS VAL OF MANT1, MANT2
       SBC X1      ; SUBTRACT EXP1 FROM EXP2
       JSR MD2     ; SAVE AS QUOTIENT EXP
DIV1:  SEC         ; SET CARRY FOR SUBTRACT
       LDX #$02    ; INDEX FOR 3-BYTE INSTRUCTION
DIV2:  

@IF C128
       LDA M2+2
       SBC E+2
       PHA

       LDA M2+1
       SBC E+1
       PHA

       LDA M2
       SBC E
       PHA
@ELSE
       LDA M2,X
       SBC E,X     ; SUBTRACT A BYTE OF E FROM MANT2
       PHA         ; SAVE ON STACK
       DEX         ; NEXT MORE SIGNIF BYTE
       BPL DIV2    ; LOOP UNTIL DONE
@ENDIF

       LDX #$FD    ; INDEX FOR 3-BYTE CONDITIONAL MOVE
DIV3:  

@IF C128
       PLA         ; PULL A BYTE OF DIFFERENCE OFF STACK
       BCC DIV43    ; IF MANT2<E THEN DONT RESTORE MANT2
       STA M2+3-3
DIV43: 
       PLA         ; PULL A BYTE OF DIFFERENCE OFF STACK
       BCC DIV42    ; IF MANT2<E THEN DONT RESTORE MANT2
       STA M2+3-2
DIV42: 
       PLA         ; PULL A BYTE OF DIFFERENCE OFF STACK
       BCC DIV41    ; IF MANT2<E THEN DONT RESTORE MANT2
       STA M2+3-1
DIV41: 
@ELSE
       PLA         ; PULL A BYTE OF DIFFERENCE OFF STACK
       BCC DIV4    ; IF MANT2<E THEN DONT RESTORE MANT2
       STA M2+3,X
DIV4:  INX         ; NEXT LESS SIGNIF BYTE
       BNE DIV3    ; LOOP UNTIL DONE
@ENDIF

       ROL M1+2
       ROL M1+1    ; ROLL QUOTIENT LEFT, CARRY INTO LSB
       ROL M1
       ASL M2+2
       ROL M2+1    ; SHIFT DIVIDEND LEFT
       ROL M2
       BCS OVFL    ; OVERFLOW IS DUE TO UNNORMALIZED DIVISOR
       DEY         ; NEXT DIVIDE ITERATION
       BNE DIV1    ; LOOP UNTIL DONE 23 ITERATIONS
       BEQ MDEND   ; NORMALIZE QUOTIENT AND CORRECT SIGN
MD2:   STX M1+2
       STX M1+1    ; CLR MANT1 (3 BYTES) FOR MUL/DIV
       STX M1
       BCS OVCHK   ; IF EXP CALC SET CARRY, CHECK FOR OVFL
       BMI MD3     ; IF NEG NO UNDERFLOW
       PLA         ; POP ONE
       PLA         ; RETURN LEVEL
       BCC NORMX   ; CLEAR X1 AND RETURN
MD3:   EOR #$80    ; COMPLEMENT SIGN BIT OF EXP
       STA X1      ; STORE IT
       LDY #$17    ; COUNT FOR 24 MUL OR 23 DIV ITERATIONS
       RTS         ; RETURN
OVCHK: BPL MD3     ; IF POS EXP THEN NO OVERFLOW
OVFL:  BRK
;
;
;     CONVERT EXP/MANT1 TO INTEGER IN M1 (HIGH) AND M1+1(LOW)
;      EXP/MANT2 UNEFFECTED
;
       JSR RTAR    ; SHIFT MANT1 RT AND INCREMENT EXPNT
FIX:   LDA X1      ; CHECK EXPONENT
       CMP #$8E    ; IS EXPONENT 14?
       BNE FIX-3   ; NO, SHIFT
RTRN:  RTS         ; RETURN

FCMP:
       JSR FSUB
       LDA X1
       CMP #$0
       BEQ FCMPE
       LDA M1
       AND #$80
       CMP #$80
       BEQ FCMPG
       LDA #$FF
       RTS
FCMPG:
       LDA #$1
       RTS
FCMPE:
       LDA #$0
       RTS

;
;
;

; A BCD to Floating-Point Binary Routine
; Marvin L. De Jong
; from Compute! Issue 9 / February 1981 / Page 46

; A Floating-Point Binary to BCD  Routine
; Marvin L. De Jong
; from Compute! Issue 11 / April 1981 / Page 66

; Note: The original listing had many errors (e.g. "#" missing). These have been corrected.



; Listing 3. A Floating-Point Binary to BCD Routine.

BEGIN:  

        LDA #0
        STA MFLAG               ; Initially set MFLAG to 0.
        STA LSB                 ; LSB is always zero
        STA DEXP

        LDA M1                  ; If M1 is negative
        BPL BEGINPLUS
        LDA #$FF                ; Store $FF in MFLAG
        STA MFLAG
BEGINPLUS:
        CLC                     ; Shift all mantissa bytes left one position.
        LDA M1+2
        ROL A
        STA NLSB
        LDA M1+1
        ROL A
        STA NMSB
        LDA M1
        ROL A
        STA MSB

        LDA X1                  ; Handle exponent
        EOR #%10000000          ; Toggle bit 7
        CLC                     ; Add one
        ADC #1
        STA BEXP

        LDA MSB         ; Test MSB to see if mantissa is zero.
        BNE BRT         ; If it is, print a zero and then get out.
        LDA M1
        CMP #$80
        BEQ BRTM1
        LDA #'0'        ; Get ASCII zero.
        STA MATHPTR0
        JSR OUTCH       ; Jump to output subroutine.
        RTS             ; Return to calling routine.
BRTM1:
        LDA #'-'
        STA MATHPTR0
        JSR OUTCH
        LDA #'1'
        STA MATHPTR0
        JSR OUTCH       ; Jump to output subroutine.
        RTS
BRT:    LDA #$00        ; Clear OVFLO location.
        STA OVFLO
BRY:    LDA BEXP        ; Is the binary exponent negative?
        BPL BRZ         ; No.
        JSR TENX        ; Yes. Multiply by ten until the exponent is not negative.
        JSR NORM
        DEC DEXP        ; Decrement decimal exponent.
        CLV             ; Force a jump.
        BVC BRY         ; Repeat.
BRZ:    LDA BEXP        ; Compare the binary exponent to
        CMP #$20        ; $20 = 32.
        BEQ BCD         ; Equal. Convert binary to BCD.
        BCC BRX1        ; Less than.
        JSR DIVTEN      ; Greater than. Divide by ten until BEXP is less than 32.
        INC DEXP
        CLV             ; Force a jump.
        BVC BRZ
BRX1:   LDA #$00        ; Clear OVFLO
        STA OVFLO
BRW:    JSR TENX        ; Multiply by ten.
        JSR NORM        ; Then normalize.
        DEC DEXP        ; Decrement decimal exponent.
        LDA BEXP        ; Test binary exponent.
        CMP #$20        ; Is it 32?
        BEQ BCD         ; Yes.
        BCC BRW         ; It's less than 32 so multiply by 10.
        JSR DIVTEN      ; It's greater than 32 so divide.
        INC DEXP        ; Increment decimal exponent.
BRU:    LDA BEXP        ; Test binary exponent.
        CMP #$20        ; Compare with 32.
        BEQ BRV         ; Shift mantissa right until exponent
        LSR MSB         ; is 32.
        ROR NMSB
        ROR NLSB
        ROR LSB
        ROR TEMP        ; Least-significant bit into TEMP.
        INC BEXP        ; Increment exponent for each shift
        CLV             ; right.
        BVC BRU
BRV:    LDA TEMP        ; Test to see if we need to round
        BPL BCD         ; up. No.
        SEC             ; Yes. Add one to mantissa.
        LDX #$04
BRS:    
@IF C128
        LDA ACC+4
        ADC #$00
        STA ACC+4

        LDA ACC+3
        ADC #$00
        STA ACC+3

        LDA ACC+2
        ADC #$00
        STA ACC+2

        LDA ACC+1
        ADC #$00
        STA ACC+1
@ELSE
        LDA ACC,X
        ADC #$00
        STA ACC,X
        DEX
        BNE BRS
@ENDIF

BCD:    JSR CONVD       ; Jump to 32 bit binary-to-BCD routine.
BRMA:   LDY #$04        ; Rotate BCD accumulator right until non-significant zeros are shifted out or DEXP is zero, whichever comes first.
BRP:    

@IF C128
BRQ:    CLC
        ROR BCDA+4
        ROR BCDA+3
        ROR BCDA+2
        ROR BCDA+1
        ROR BCDA
@ELSE
        LDX #$04
        CLC
BRQ:    ROR BCDA,X
        DEX
        BPL BRQ
@ENDIF

        DEY
        BNE BRP
        INC DEXP        ; Increment exponent for each shift right. Get out when DEXP = 0.
        BEQ BROA
        LDA BCDA        ; Has a non-zero digit been shifted into the least-significant place?
        AND #$0F
        BEQ BRMA        ; No. Shift another digit.
BROA:
        LDA MFLAG
        BEQ BRNA        ; If the sign of the number is minus, output a minus sign first.
        LDA #'-'
        STA MATHPTR0
        JSR OUTCH       ; ASCII " - " = $2D. Output character.
BRNA:   LDA #$0B        ; Set digit counter to eleven.
        STA TEMP
BRI:    LDY #$04        ; Rotate BCD accumulator left to output most-significant digits first. But first bypass zeros.
BRH:    CLC
        LDX #$FB
BRG:    

@IF C128
        ROL BCDN-5
        ROL BCDN-4
        ROL BCDN-3
        ROL BCDN-2
        ROL BCDN-1
@ELSE
        ROL BCDN,X
        INX
        BNE BRG
@ENDIF

        ROL OVFLO       ; Rotate digit into OVFLO.
        DEY
        BNE BRH
        DEC TEMP        ; Decrement digit counter.
        LDA OVFLO       ; Is the rotated digit zero?
        BEQ BRI         ; Yes. Rotate again.
BRX:    CLC             ; Convert digit to ASCII and output it.
        ADC #'0'
        STA MATHPTR0
        JSR OUTCH
        LDA #$00        ; Clear OVFLO for next digit.
        STA OVFLO
        LDY #$04        ; Output the remaining digits.
BRL:    CLC
        LDX #$FB
BRJ:    

@IF C128
        ROL BCDN-5
        ROL BCDN-4
        ROL BCDN-3
        ROL BCDN-2
        ROL BCDN-1
@ELSE
        ROL BCDN,X      ; Rotate a digit at a time into
        INX             ; OVFLO, then output it. One digit is four bits or one nibble.
        BNE BRJ
@ENDIF

        ROL OVFLO
        DEY
        BNE BRL
        LDA OVFLO       ; Get digit.
        DEC TEMP        ; Decrement digit counter.
        BNE BRX
        LDA DEXP        ; Is the decimal exponent zero?
        BEQ ARND1       ; Yes. No need to output exponent.
        LDA #'.'        ; Get ASCII decimal point.
        STA MATHPTR0
        JSR OUTCH       ; Output it.
        LDA #'E'        ; Get ASCII "E".
        STA MATHPTR0
        JSR OUTCH
        LDA DEXP        ; Is the decimal exponent plus?
        BPL THERE       ; Yes.
        LDA #'-'        ; No. Output ASCII " - "
        STA MATHPTR0
        JSR OUTCH
        LDA DEXP        ; It's minus, so complement it and add one to form the twos complement.
        EOR #$FF
        STA DEXP
        INC DEXP
THERE:  LDA #$00        ; Clear OVFLO.
        STA OVFLO
        SED             ; Convert exponent to BCD.
        LDY #$08
BR1A:   ROL DEXP
        LDA OVFLO
        ADC OVFLO
        STA OVFLO
        DEY
        BNE BR1A
        CLD
        CLC
        LDA OVFLO       ; Get BCD exponent.
        AND #$F0        ; Mask low-order nibble (digit).
        BEQ BR2A
        ROR A           ; Rotate nibble to the right.
        ROR A
        ROR A
        ROR A
        ADC #'0'        ; Convert to ASCII.
        STA MATHPTR0
        JSR OUTCH       ; Output the most-significant digit.
BR2A:   LDA OVFLO       ; Get the least-significant digit.
        AND #$0F        ; Mask the high nibble.
        CLC
        ADC #'0'        ; Convert to ASCII.
        STA MATHPTR0
        JSR OUTCH
ARND1:
        RTS             ; All finished.

; Listing 2. Multiply by Ten Subroutine.

TENX:   CLC             ; Shift accumulator left.
        LDX #$04        ; Accumulator contains four bytes so X is set to four.
BR1:    

@IF C128
        LDA ACC+4
        ROL A
        STA ACCB+4

        LDA ACC+3
        ROL A
        STA ACCB+3

        LDA ACC+2
        ROL A
        STA ACCB+2

        LDA ACC+1
        ROL A
        STA ACCB+1

        LDA ACC
        ROL A
        STA ACCB
@ELSE
        LDA ACC,X
        ROL A           ; Shift a byte left.
        STA ACCB,X      ; Store it in accumulator B.
        DEX
        BPL BR1         ; Back to get another byte.
@ENDIF

        LDX #$04        ; Now shift accumulator B left once again to get "times four."
        CLC
BR2:    

@IF C128
        ROL ACCB+4
        ROL ACCB+3
        ROL ACCB+2
        ROL ACCB+1
        ROL ACCB+0
@ELSE
        ROL ACCB,X      ; Shift one byte left.
        DEX
        BPL BR2         ; Back to get another byte.
@ENDIF

        LDX #$04        ; Add accumulator to accumulator B to get A + 4* A = 5* A.
        CLC
BR3:    

@IF C128
        LDA ACC+4
        ADC ACCB+4
        STA ACC+4

        LDA ACC+3
        ADC ACCB+3
        STA ACC+3

        LDA ACC+2
        ADC ACCB+2
        STA ACC+2

        LDA ACC+1
        ADC ACCB+1
        STA ACC+1

        LDA ACC
        ADC ACCB
        STA ACC
@ELSE
        LDA ACC,X
        ADC ACCB,X
        STA ACC,X       ; Result into accumulator.
        DEX
        BPL BR3
@ENDIF

        LDX #$04        ; Finally, shift accumulator left one bit to get 2*5* A = 10* A.
        CLC
BR4:    

@IF C128
        ROL ACC+4
        ROL ACC+3
        ROL ACC+2
        ROL ACC+1
        ROL ACC
@ELSE
        ROL ACC,X
        DEX
        BPL BR4         ; Get another byte.
@ENDIF

        RTS

; Listing 3. Normalize the Mantissa Subroutine.

NORM:   CLC
BR6:    LDA OVFLO       ; Any bits set in the overflow byte? Yes, then rotate right.
        BEQ BR5
        LSR OVFLO       ; No, then rotate left.
        ROR MSB
        ROR NMSB
        ROR NLSB
        ROR LSB         ; For each shift right, increment binary exponent.
        INC BEXP
        CLV             ; Force a jump back.
        BVC BR6
BR5:    BCC BR7         ; Did the last rotate cause a carry? Yes, then round the mantissa upward.
        LDX #$04
BR8:    

@IF C128
        LDA ACC+4
        ADC #$00        ; Carry is set so one is added
        STA ACC+4

        LDA ACC+3
        ADC #$00        ; Carry is set so one is added
        STA ACC+3

        LDA ACC+2
        ADC #$00        ; Carry is set so one is added
        STA ACC+2

        LDA ACC+1
        ADC #$00        ; Carry is set so one is added
        STA ACC+1

        LDA ACC
        ADC #$00        ; Carry is set so one is added
        STA ACC
@ELSE
        LDA ACC,X
        ADC #$00        ; Carry is set so one is added
        STA ACC,X
        DEX
        BPL BR8
@ENDIF

        BMI BR6         ; Check overflow byte once more.

BR7:    LDY #$20        ; Y will limit the number of left shifts to 32.
BR10:   LDA MSB
        BMI BR11        ; If mantissa has a one in its most-significant bit, get out.
        CLC
        LDX #$04
BR9:    

@IF C128
        ROL ACC+4
        ROL ACC+3
        ROL ACC+2
        ROL ACC+1
@ELSE
        ROL ACC,X       ; Shift accumulator left one bit.
        DEX
        BNE BR9
@ENDIF

        DEC BEXP        ; Decrement binary exponent for each left shift.
        DEY
        BNE BR10        ; No more than $20 = 32 bits shifted.

BR11:   RTS             ; That's it.

; Listing 5. A 32 Bit Binary-to-BCD Subroutine.

CONVD:  LDX #$05        ; Clear BCD accumulator.
        LDA #$00
BRM:    

@IF C128
        STA BCDA+5
        STA BCDA+4
        STA BCDA+3
        STA BCDA+2
        STA BCDA+1
        STA BCDA
@ELSE
        STA BCDA,X      ; Zeros into BCD accumulator.
        DEX
        BPL BRM
@ENDIF

        SED             ; Decimal mode for add.
        LDY #$20        ; Y has number of bits to be converted. Rotate binary number into carry.
BRN:    ASL LSB
        ROL NLSB
        ROL NMSB
        ROL MSB
        LDX #$FB        ; X will control a five byte addition. Get least-significant byte of the BCD accumulator, add is to itself, then store.
BRO:    

@IF C128
        LDA BCDN-5
        ADC BCDN-5
        STA BCDN-5

        LDA BCDN-4
        ADC BCDN-4
        STA BCDN-4

        LDA BCDN-3
        ADC BCDN-3
        STA BCDN-3

        LDA BCDN-2
        ADC BCDN-2
        STA BCDN-2

        LDA BCDN-1
        ADC BCDN-1
        STA BCDN-1
@ELSE
        LDA BCDN,X
        ADC BCDN,X
        STA BCDN,X
        INX             ; Repeat until all five bytes have been added.
        BNE BRO
@ENDIF

        DEY             ; Get another bit from the binary number.
        BNE BRN
        CLD             ; Back to binary mode.
        RTS             ; And back to the program.

; Listing 1: ASCII to Floating-Point Binary Conversion Program

START:  CLD             ; Decimal mode not required
        LDX #$20        ; Clear all the memory locations used for storage by this routine by loading them with zeros.
        LDA #$00
CLEAR:  

@IF C128
        STA MEM+32
        STA MEM+31
        STA MEM+30
        STA MEM+29
        STA MEM+28
        STA MEM+27
        STA MEM+26
        STA MEM+25

        STA MEM+24
        STA MEM+23
        STA MEM+22
        STA MEM+21
        STA MEM+20
        STA MEM+19
        STA MEM+18
        STA MEM+17

        STA MEM+16
        STA MEM+15
        STA MEM+14
        STA MEM+13
        STA MEM+12
        STA MEM+11
        STA MEM+10
        STA MEM+9

        STA MEM+8
        STA MEM+7
        STA MEM+6
        STA MEM+5
        STA MEM+4
        STA MEM+3
        STA MEM+2
        STA MEM+1

        STA MEM
@ELSE
        STA MEM,X
        DEX
        BPL CLEAR
@ENDIF

        JSR INPUT       ; Get ASCII representation of
        LDA MATHPTR0
        CMP #'+'        ; BCD digit. Is it a + sign?
        BEQ PLUS        ; Yes, get another character.   
        CMP #'-'        ; Is it a minus sign?
        BNE NTMNS
        DEC MFLAG       ; Yes, set minus flag to $FF.
PLUS:   JSR INPUT       ; Get the next character.
        LDA MATHPTR0
NTMNS:  CMP #'.'        ; Is character a decimal point?
        BNE DIGIT       ; No. Perhaps it is a digit. Yes, check flag.
        LDA DPFLAG      ; Was the decimal point flag set?
        BNE NORMIZ      ; Time to normalize the mantissa.
        INC DPFLAG      ; Set decimal point flag, and get the next character.
        BNE PLUS
DIGIT:  CMP #$30        ; Is the character a digit?
        BCC NORMIZ      ; No, then normalize the mantissa.
        CMP #$3A        ; Digits have ASCII representations between $30 and $39.
        BCS NORMIZ
        JSR TENX        ; It was a digit, so multiply the accumulator by ten and add the new digit. First strip the ASCII prefix by subtracting $30.
        LDA CHAR
        SEC
        SBC #$30
        CLC             ; Add the new digit to the least-significant byte of the accumulator.
        ADC LSB
        STA LSB         ; Next, any "carry" will be added to the other bytes of the accumulator.
        LDX #$03
ADDIG:  

@IF C128
        LDA #$00
        ADC ACC+3
        STA ACC+3

        LDA #$00
        ADC ACC+2
        STA ACC+2

        LDA #$00
        ADC ACC+1
        STA ACC+1

        LDA #$00
        ADC ACC
        STA ACC
@ELSE
        LDA #$00
        ADC ACC,X       ; Add carry here.
        STA ACC,X       ; And save result.
        DEX
        BPL ADDIG       ; The new digit has been added.
@ENDIF

        LDA DPFLAG      ; Check the decimal point flag.
        BEQ PLUS        ; If not set, get another character.
        DEC DEXP        ; If set, decrement the exponent, then get another character.
        BMI PLUS
NORMIZ: JSR NORM        ; Normalize the mantissa.
        CLC             ; Clear carry for addition.
        LDA BEXP        ; Get binary exponent.
        ADC #$20        ; Add $20 = 32 to place binary
        STA BEXP        ; point properly.
        LDA MSB         ; If the MSB of the accumulator is zero, then the number is zero, and its all over. Otherwise, check if the last character was an "E".
        BEQ FINISH1     ; Original listing branched to FINISH but that is too far to reach.
        LDA CHAR
        CMP #'E'
        BNE TENPRW      ; If not, move to TENPRW.
        JSR INPUT       ; If so, get another character.
        CMP #'+'        ; Is it a plus?
        BEQ PAST        ; Yes, then get another character.
        CMP #'-'        ; Perhaps it was a minus?
        BNE NUMB        ; No, then maybe it was a number.
        DEC ESIGN       ; Set exponent sign flag.
PAST:   JSR INPUT       ; Get another character.
NUMB:   CMP #'0'        ; Is it a digit?
        BCC TENPRW      ; No, more to TENPRW.
        CMP #$3A
        BCS TENPRW
        SEC             ; It was a digit, so strip ASCII prefix.
        SBC #'0'        ; ASCII prefix is $30.
        STA TEMP        ; Keep the first digit here.
        JSR INPUT       ; Get another character.
        CMP #'0'        ; Is it a digit?
        BCC HERE        ; No. Then finish handling the exponent.
        CMP #$3A
        BCS HERE
        SEC             ; Yes. Decimal exponent is new digit plus 10 times the old digit.
        SBC #'0'
        STA EVAL        ; Strip ASCII prefix from new digit.
        LDA TEMP        ; Get the old character and multiply it by ten. First times two.
        ASL A
        ASL A           ; Times two again makes times four.
        CLC
        ADC TEMP        ; Added to itself makes times five.
        ASL A           ; Times two again makes time ten.
        STA TEMP        ; Store it.
HERE:   CLC             ; Add the new digit, to the exponent.
        LDA TEMP
        ADC EVAL
        STA EVAL        ; Here is the exponent, except for its sign. Was it a negative?
        LDA ESIGN
        BEQ POSTV       ; No.
        LDA EVAL        ; Yes, then form its twos complement by complementation followed by adding one.
        EOR #$FF
        SEC
        ADC #$00
        STA EVAL        ; Result into exponent value location.
POSTV:  CLC             ; Prepare to add exponents.
        LDA EVAL        ; Get "E" exponent.
        ADC DEXP        ; Add exponent from input and norm.
        STA DEXP        ; All exponent work finished.
TENPRW: LDA DEXP        ; Get decimal exponent.
FINISH1:
        BEQ FINISH      ; If it is zero, routine is done
        BPL MLTPLY      ; If it is plus, go multiply by ten.

ONCMOR: JSR DIVTEN      ; Jump to divide-by-ten subroutine.
        CLV             ; Force a jump around the routine.
        BVC ARND        ; The new subroutine is inserted here. Clear accumulator for use as a register. Do $28 = 40 bit divide. OVFLO will be used as "guard" byte.
DIVTEN: LDA #$00
        LDY #$28
BRA:    ASL OVFLO
        ROL LSB
        ROL NLSB        ; Roll one bit at a time into the accumulator which serves to hold the partial dividend.
        ROL NMSB
        ROL MSB
        ROL A           ; Check to see if A is larger than the divisor, $0A = 10.
        CMP #$0A
        BCC BRB         ; No. Decrease the bit counter.
        SEC             ; Yes. Subtract divisor from A.
        SBC #$0A
        INC OVFLO       ; Set a bit in the quotient.
BRB:    DEY             ; Decrease the bit counter.
        BNE BRA
BRC:    DEC BEXP        ; Division is finished, now normalize.
        ASL OVFLO       ; For each shift left, decrease the binary exponent.
        ROL LSB
        ROL NLSB        ; Rotate the mantissa left until a one is in the most-significant bit.
        ROL NMSB
        ROL MSB
        BPL BRC
        LDA OVFLO       ; If the most-significant bit in the guard byte is one, round up.
        BPL BRE
        SEC             ; Add one.
        LDX #$04        ; X is byte counter.
BRD:    

@IF C128
        LDA ACC+4
        ADC #$00        ; Add the carry.
        STA ACC+4

        LDA ACC+3
        ADC #$00        ; Add the carry.
        STA ACC+3

        LDA ACC+2
        ADC #$00        ; Add the carry.
        STA ACC+2

        LDA ACC+1
        ADC #$00        ; Add the carry.
        STA ACC+1
@ELSE
        LDA ACC,X       ; Get the LSB.
        ADC #$00        ; Add the carry.
        STA ACC,X       ; Result into mantissa.
        DEX
        BNE BRD         ; Back to complete addition.
@ENDIF

        BCC BRE         ; No carry from MSB so finish.
        ROR MSB         ; A carry, put in bit seven, and increase the binary exponent.
        INC BEXP
BRE:    LDA #$00        ; Clear the OVFLO position, then get out.
        STA OVFLO
        RTS
ARND:   LDA #$00        ; Clear overflow byte.
        STA OVFLO
        INC DEXP        ; For each divide-by-10, increment the decimal exponent until it is zero. Then its all over.
        BNE ONCMOR
        BEQ FINISH
MLTPLY: LDA #$00        ; Clear overflow byte.
        STA OVFLO
STLPLS: JSR TENX        ; Jump to multiply-by-ten subroutine.
        JSR NORM        ; Then normalize the mantissa.
        DEC DEXP        ; For each multiply-by-10, decrement the decimal exponent until it's zero. All finished now.
        BNE STLPLS
FINISH: RTS

; Replica 1 I/O Routines

OUTCH:
        PHA
        TYA
        PHA
        LDY TMPPTR2
        LDA MATHPTR0
        STA (TMPPTR), Y
        INC TMPPTR2
        PLA
        TYA
        PLA
        RTS

INPUT:
        PHA
        TYA
        PHA
        LDY TMPPTR2
        LDA (TMPPTR), Y
        STA MATHPTR0
        INC TMPPTR2
        PLA
        TYA
        PLA
        RTS

;
;     EXP/MANT1^2 RESULT IN EXP/MANT1
;      (DESTROY EXP/MANT2!!)
;

FSQR:
       LDA X1
       STA X2
       LDA M1
       STA M2
       LDA M1+1
       STA M2+1
       LDA M1+2
       STA M2+2
       JSR FMUL
       RTS

;
;     EXP/MAN12 RESULT IN EXP/MANT1
;

FFLOOR:
       LDA X1
       CMP #$9F
       BCC FFLOORP
       LDA M1
       AND $80
       STA SIGN
       JSR FIX ; CONVERT TO INT (TRUNCATION)
       JSR FLOAT ; CONVERT BACK TO FLOAT
       LDA SIGN
       BEQ FFLOORP
       JSR FCOMPL
FFLOORP:
       RTS

;
;     EXP/MANT2 MOD EXP/MANT1 RESULT IN EXP/MANT1
;

FMOD:
       LDA X1
       STA DX
       LDA M1
       STA DX+1
       LDA M1+1
       STA DX+2
       LDA M1+1
       STA DX+3

       LDA X2
       STA RES
       LDA M2
       STA RES+1
       LDA M2+1
       STA RES+2
       LDA M2+1
       STA RES+3

       JSR FDIV
       JSR FFLOOR

       LDA RES
       STA X2
       LDA RES+1
       STA M2
       LDA RES+2
       STA M2+1
       LDA RES+3
       STA M2+3

       JSR FMUL ;mULTIPLY QUOTIENT AND DIVISOR

       LDA DX
       STA X2
       LDA DX+1
       STA M2
       LDA DX+2
       STA M2+1
       LDA DX+3
       STA M2+3

	JMP FSUB	;DIVIDEND - QUOTIENT*DIVISOR = MODULUS.		
       RTS

PI4:   .BYTE $7f, $49, $0F, $DA
PI2:   .BYTE $80, $64, $87, $ED
DX:    .BYTE $00, $00, $00, $00
QX:    .BYTE $00, $00, $00, $00
TX:    .BYTE $00, $00, $00, $00
N1:    .BYTE $80, $00, $00, $00
N2:    .BYTE $81, $40, $00, $00
N24:   .BYTE $84, $60, $00, $00
N720:  .BYTE $89, $5a, $00, $00
RES:   .BYTE $00, $00, $00, $00
RES2:  .BYTE $00, $00, $00, $00
RESS:  .BYTE $00, $00, $00, $00
RESC:  .BYTE $00, $00, $00, $00

FSIN:
       ; sin x = cos(x - pi/2)
       LDA X1
       STA X2
       LDA M1
       STA M2
       LDA M1+1
       STA M2+1
       LDA M1+2
       STA M2+2

       LDA PI2
       STA X1
       LDA PI2+1
       STA M1
       LDA PI2+2
       STA M1+1
       LDA PI2+3
       STA M1+2

       JSR FSUB ; x - pi/2
FCOS:
       ; 
       ; cos x = 1
       LDA N1
       STA RES
       LDA N1+1
       STA RES+1
       LDA N1+2
       STA RES+2
       LDA N1+3
       STA RES+3

       ; dx = x*x
       JSR FSQR

       LDA X1
       STA DX
       LDA M1
       STA DX+1
       LDA M1+1
       STA DX+2
       LDA M1+2
       STA DX+3

       ; ; qx = dx*dx

       JSR FSQR

       LDA X1
       STA QX
       LDA M1
       STA QX+1
       LDA M1+1
       STA QX+2
       LDA M1+2
       STA QX+3

       ; ; tx = qx*dx

       LDA DX
       STA X2
       LDA DX+1
       STA M2
       LDA DX+2
       STA M2+1
       LDA DX+3
       STA M2+2

       JSR FMUL

       LDA X1
       STA TX
       LDA M1
       STA TX+1
       LDA M1+1
       STA TX+2
       LDA M1+2
       STA TX+3

       ; ; dxc2 = dx/c2

       LDA DX
       STA X2
       LDA DX+1
       STA M2
       LDA DX+2
       STA M2+1
       LDA DX+3
       STA M2+2

       LDA N2
       STA X1
       LDA N2+1
       STA M1
       LDA N2+2
       STA M1+1
       LDA N2+3
       STA M1+2

       JSR FDIV

       LDA RES
       STA X2
       LDA RES+1
       STA M2
       LDA RES+2
       STA M2+1
       LDA RES+3
       STA M2+2

       JSR FSUB ; 1 - dxc2

       LDA X1
       STA RES
       LDA M1
       STA RES+1
       LDA M1+1
       STA RES+2
       LDA M1+2
       STA RES+3

       ; qxc24 = qx/c24

       LDA QX
       STA X2
       LDA QX+1
       STA M2
       LDA QX+2
       STA M2+1
       LDA QX+3
       STA M2+2

       LDA N24
       STA X1
       LDA N24+1
       STA M1
       LDA N24+2
       sta M1+1
       LDA N24+3
       STA M1+2

       JSR FDIV

       LDA RES
       STA X2
       LDA RES+1
       STA M2
       LDA RES+2
       STA M2+1
       LDA RES+3
       STA M2+2

       JSR FADD ; + ( qxc24 )

       LDA X1
       STA RES
       LDA M1
       STA RES+1
       LDA M1+1
       STA RES+2
       LDA M1+2
       STA RES+3

       ; txc720 = tx/c720

       LDA TX
       STA X2
       LDA TX+1
       STA M2
       LDA TX+2
       STA M2+1
       LDA TX+3
       STA M2+2

       LDA N720
       STA X1
       LDA N720+1
       STA M1
       LDA N720+2
       STA M1+1
       LDA N720+3
       STA M1+2

       JSR FDIV

       LDA RES
       STA X2
       LDA RES+1
       STA M2
       LDA RES+2
       STA M2+1
       LDA RES+3
       STA M2+2

       JSR FSUB ; - ( txc720 )

       ; R1 ---> cos x = 1 - ( dxc2 ) + ( qxc24 ) - ( txc720 )

       RTS

FTAN:
       ; tan(x) = sin(x) / cos(x)

       LDA X1
       STA RES2
       LDA M1
       STA RES2+1
       LDA M1+1
       STA RES2+2
       LDA M1+2
       STA RES2+3

       JSR FSIN

       LDA X1
       STA RESS
       LDA M1
       STA RESS+1
       LDA M1+1
       STA RESS+2
       LDA M1+2
       STA RESS+3

       LDA RES2
       STA X1
       LDA RES2+1
       STA M1
       LDA RES2+2
       STA M1+1
       LDA RES2+3
       STA M1+2

       JSR FCOS

       LDA RESS
       STA X2
       LDA RESS+1
       STA M2
       LDA RESS+2
       STA M2+1
       LDA RESS+3
       STA M2+2

       JSR FDIV

       RTS
       