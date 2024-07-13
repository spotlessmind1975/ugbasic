; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                       FLOATING POINT ROUTINES UNDER 6502                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;-----------------------------------------------------------------------------
; FPFP1ZERO
;-----------------------------------------------------------------------------
; Routine to put register FP1 to zero.
;
; INPUT:  -
; OUTPUT: FS1
;

FPFP1ZERO:
       LDA #0
       STA FP1X
       STA FP1M
       STA FP1M+1
       STA FP1M+2
       RTS

;-----------------------------------------------------------------------------
; FPFP1TOFS1
;-----------------------------------------------------------------------------
; Routine to convert IEEE-754 floating point register FP1 to 
; internal representation to floating point register FS1.
;
;          X        M        M+1      M+2
;      +--------+--------+--------+--------+
; FP1: |SEEEEEEE|EMMMMMMM|MMMMMMMM|MMMMMMMM|
;      +--------+--------+--------+--------+
;
;          X        M        M+1      M+2
;      +--------+--------+--------+--------+
; FS1: |EEEEEEEE|SMMMMMMM|MMMMMMMM|MMMMMMMM|
;      +--------+--------+--------+--------+
;
; INPUT:  FP1
; OUTPUT: FS1

FPFP1TOFS1:

       ; FP1 X (SEEEEEEE) -> FS1 X (EEEEEEE0)
       LDA FP1X
       STA FS1X
       ASL FS1X

       ; FP1 M (EMMMMMMM) -> A (0000000E)
       LDA FP1M
       ROL
       ROL
       AND #$01

       ; FS1 X (EEEEEEEE)
       ORA FS1X
       STA FS1X

       ; FP1 M -> FS1 M
       LDA FP1M
       AND #$7F
       STA FS1M
       LDA FP1M+1
       STA FS1M+1
       LDA FP1M+2
       STA FS1M+2

       ; FP1 X (S0000000) -> FS1 M(SMMMMMMM)
       LDA FP1X
       AND #$80
       ORA FS1M
       STA FS1M

       RTS

;-----------------------------------------------------------------------------
; FPFS1TOFP1
;-----------------------------------------------------------------------------
; Routine to convert internal representation to floating point register FS1
; to IEEE-754 floating point register FP1.
; 
;          X        M        M+1      M+2
;      +--------+--------+--------+--------+
; FS1: |EEEEEEEE|SMMMMMMM|MMMMMMMM|MMMMMMMM|
;      +--------+--------+--------+--------+
;
;          X        M        M+1      M+2
;      +--------+--------+--------+--------+
; FP1: |SEEEEEEE|EMMMMMMM|MMMMMMMM|MMMMMMMM|
;      +--------+--------+--------+--------+
;
; INPUT:  FS1
; OUTPUT: FP1

FPFS1TOFP1:

       JSR FPFP1ZERO

       ; FS1 X (EEEEEEEE) -> FP1 X (0EEEEEEE)
       LDA FS1X
       LSR
       STA FP1X

       ; FS1 M (SMMMMMMM) -> A (S0000000)
       LDA FS1M
       AND #$80

       ; FP1 X (SEEEEEEE)
       ORA FP1X
       STA FP1X

       ; FS1 M -> FP1 M
       LDA FS1M
       AND #$7F
       STA FP1M
       LDA FS1M+1
       STA FP1M+1
       LDA FS1M+2
       STA FP1M+2

       ; FS1 X (EEEEEEEE) -> FP1 M(EMMMMMMM)
       LDA FS1X
       AND #$01
       ROR
       ROR
       AND #$80
       ORA FP1M
       STA FP1M

       RTS

;-----------------------------------------------------------------------------
; FPFP2TOFS2
;-----------------------------------------------------------------------------
; Routine to convert IEEE-754 floating point register FP2 to 
; internal representation to floating point register FS2.
;
; INPUT:  FP2
; OUTPUT: FS2

FPFP2TOFS2:

       LDA FP2X
       STA FS2X
       ASL FS2X

       LDA FP2M
       ROL
       ROL
       AND #$01

       ORA FS2X
       STA FS2X

       LDA FP2M
       AND #$7F
       STA FS2M
       LDA FP2M+1
       STA FS2M+1
       LDA FP2M+2
       STA FS2M+2

       LDA FP2X
       AND #$80
       ORA FS2M
       STA FS2M

       RTS

;-----------------------------------------------------------------------------
; FPFS1FS2ALIGN
;-----------------------------------------------------------------------------
; Routine to align the exponents of both FS1 and FS2 registers. Alignment means
; that the FS2 will be "scaled" to the same magnitude of FS1 (in term of 
; exponent). If FS1 or FS2 has 0 as exponent, nothing is done.
;
; INPUT:  FS1 FS2
; OUTPUT: FS1 FS2
;
FPFS1FS2ALIGN:

       ; Check if the exponent of FS1 is zero:
       ; if it is so, nothing is done.
       LDA FS1X
       BNE FPFS1FS2ALIGN0

       ; Check if the exponent of FS2 is zero:
       ; if it is so, nothing is done.
       LDA FS2X
       BNE FPFS1FS2ALIGN0

FPFS1FS2ALIGNR:

       ; Check if the exponent of FS2 is the same of FS1.
       ; In that case, we have finished
       LDA FS1X
       CMP FS2X 
       BNE FPFS1FS2ALIGNL1

FPFS1FS2ALIGN0:
       RTS

FPFS1FS2ALIGNL1:

       ; X2 - X1 > 0 => X2 > X1 ?
       BCS FPFS1FS2ALIGNG

       JSR FPFS1SCALEUP
       JMP FPFS1FS2ALIGNR

FPFS1FS2ALIGNG:
       JSR FPFS2SCALEUP
       JMP FPFS1FS2ALIGNR

;-----------------------------------------------------------------------------
; FPFS1SCALEUP
;-----------------------------------------------------------------------------
; Routine to scale up register FS1. This means that the number will be doubled.
;
; INPUT:  FS1
; OUTPUT: FS1
;

FPFS1SCALEUP:

       ; Increase exponent.
       INC FS1X

       ; Preserve the sign
       LDA FS1M
       AND #$80
       PHA

       ; Halve the mantissa.
       LSR FS1M
       ROR FS1M+1
       ROR FS1M+2

       ; Preserve the sign
       PLA
       ORA FS1M
       STA FS1M

       RTS

;-----------------------------------------------------------------------------
; FPFS2SCALEUP
;-----------------------------------------------------------------------------
; Routine to scale up register FS2. This means that the number will be doubled.
;
; INPUT:  FS2
; OUTPUT: FS2
;

FPFS2SCALEUP:

       ; Increase exponent.
       INC FS2X

       ; Preserve the sign
       LDA FS2M
       AND #$80
       PHA

       ; Halve the mantissa.
       LSR FS2M
       ROR FS2M+1
       ROR FS2M+2

       ; Preserve the sign
       PLA
       ORA FS2M
       STA FS2M

       RTS

;-----------------------------------------------------------------------------
; FPFS1PREPEND
;-----------------------------------------------------------------------------
; Routine to prepend a '1' in front of the mantissa, retaining the sign.
;
; INPUT:  FS1
; OUTPUT: FS1, C
;

FPFS1PREPEND:

       ; Preserve the sign
       LDA FS1M
       AND #$80
       PHA

       ; Exponent is zero?
       LDA FS1X
       BEQ FPFS1PREPENDL1

       ; Put 1 in front of mantissa
       LDA FS1M
       ORA #$80
       STA FS1M

FPFS1PREPENDL1:
       ; Retrieve the sign
       PLA
       ROL

       RTS

;-----------------------------------------------------------------------------
; FPFS2PREPEND
;-----------------------------------------------------------------------------
; Routine to prepend a '1' in front of the mantissa, retaining the sign.
;
; INPUT:  FS2
; OUTPUT: FS2, C
;

FPFS2PREPEND:

       ; Preserve the sign
       LDA FS2M
       AND #$80
       PHA

       ; Exponent is zero?
       LDA FS2X
       BEQ FPFS2PREPENDL1

       ; Put 1 in front of mantissa
       LDA FS2M
       ORA #$80
       STA FS2M

FPFS2PREPENDL1:

       ; Retrieve the sign
       PLA
       ROL

       RTS

;-----------------------------------------------------------------------------
; FPFS1NORMALIZE
;-----------------------------------------------------------------------------
; Routine to normalize FS1. It can happen that after adding, the binary point 
; no longer appears after the first 1. In this case, the binary point must be 
; shifted behind the first 1 again and the exponent is adjusted accordingly.
;
; INPUT:  FS1
; OUTPUT: FS1
;

FPFS1NORMALIZE:

       ; Check if carry bit is 1.
       BCS FPFS1NORMALIZEL1
       RTS

FPFS1NORMALIZEL1:

       JSR FPFS1SCALEUP
       RTS

BEGIN:

FADD:
FPADD:
       ; 1. Convert exponents to decimal numbers, or:
       ;    convert IEEE-754 into internal rappresentation.
       JSR FPFP1TOFS1
       JSR FPFP2TOFS2

       ; 2. Prepend implicit 1 to mantissas:
       JSR FPFS1PREPEND
       JSR FPFS2PREPEND

       ; 3. Shift binary point to align exponents:
       JSR FPFS1FS2ALIGN

       ; 4. Add mantissas:
       CLC
       LDA FS2M+2
       ADC FS1M+2
       STA FS1M+2
       LDA FS2M+1
       ADC FS1M+1
       STA FS1M+1
       LDA FS2M
       ADC FS1M
       STA FS1M

       ; 5. Normalization:
       JSR FPFS1NORMALIZE

       ; 6. Rounding:
       ; 7. Convert exponent to binary number
       ; 8. Assemble floating point number:
       ; convert internal rappresentation to IEEE-754
       JSR FPFS1TOFP1

       RTS

FCMP:
FCOS:
FDIV:
FIX:
FLOAT:
FMUL:
FPEXP:
FPLOG:
FSIN:
FSUB:
FTAN:
       RTS