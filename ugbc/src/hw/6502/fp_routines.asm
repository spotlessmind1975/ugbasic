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
; FP1TOSCRATCH1
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

FP1TOSCRATCH1:

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

       RTS

;-----------------------------------------------------------------------------
; FP1FROMSCRATCH1
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

FP1FROMSCRATCH1:

       ; FS1 X (EEEEEEEE) -> FP1 X (0EEEEEEE)
       LDA FS1X
       LSR
       STA FP1X

       ; FP1 M (SMMMMMMM) -> A (S0000000)
       LDA FP1M
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
       ORA FP1M
       STA FP1M

       RTS

;-----------------------------------------------------------------------------
; FP2TOSCRATCH2
;-----------------------------------------------------------------------------
; Routine to convert IEEE-754 floating point register FP2 to 
; internal representation to floating point register FS2.
;
; INPUT:  FP2
; OUTPUT: FS2

FP2TOSCRATCH2:

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

       RTS

;-----------------------------------------------------------------------------
; FPNORMALIZE
;-----------------------------------------------------------------------------
; Routine to normalize the second FS2 register in respect of the
; FS1 register. Normalization means that the FS2 will be "scaled"
; to the same magnitude of FS1 (in term of exponent), and they
; will have first bit put to one.
;
; INPUT:  FS1 FS2
; OUTPUT: FS1 FS2
;
FPNORMALIZE:

       ; Check if the exponent of FS2 is the same of FS1.
       ; In that case, we have finished!

       LDA FS1X
       CMP FS2X 
       BNE FPNORMALIZEL1

       RTS

FPNORMALIZEL1:

       ; X2 - X1 > 0 => X2 > X1 ?
       BCS FPNORMALIZEG

       JSR FPSCALEUPX1
       JMP FPNORMALIZE

FPNORMALIZEG:
       JSR FPSCALEUPX2
       JMP FPNORMALIZE

;-----------------------------------------------------------------------------
; FPSCALEUPX1
;-----------------------------------------------------------------------------
; Routine to scale up register FS1. This means that the number will be
; doubled and, if mantissa will arrive to zero, a 1 will be put at the
; very beginning of the mantissa.
;
; INPUT:  FS1
; OUTPUT: FS1
;

FPSCALEUPX1:

       ; Increase exponent.
       INC FS1X

       ; Halve the mantissa.
       LSR FS1M
       ROR FS1M+1
       ROR FS1M+2

       ; Check if mantissa is zero.
       LDA FS1M
       ORA FS1M+1
       ORA FS1M+2
       BNE FPSCALEUPX1DONE

       ; Mantissa is zero: put a 1 on 
       ; the first mantissa's bit
       LDA #$40
       STA FS1M

FPSCALEUPX1DONE:
       ; Next step!
       RTS

;-----------------------------------------------------------------------------
; FPSCALEUPX2
;-----------------------------------------------------------------------------
; Routine to scale up register FS2. This means that the number will be
; doubled and, if mantissa will arrive to zero, a 1 will be put at the
; very beginning of the mantissa.
;
; INPUT:  FS2
; OUTPUT: FS2
;

FPSCALEUPX2:

       ; Increase exponent.
       INC FS2X

       ; Halve the mantissa.
       LSR FS2M
       ROR FS2M+1
       ROR FS2M+2

       ; Check if mantissa is zero.
       LDA FS2M
       ORA FS2M+1
       ORA FS2M+2
       BNE FPSCALEUPX2DONE

       ; Mantissa is zero: put a 1 on 
       ; the first mantissa's bit
       LDA #$40
       STA FS2M

FPSCALEUPX2DONE:
       ; Next step!
       RTS

BEGIN:

FADD:
FPADD:
       JSR FP1TOSCRATCH1
       JSR FP2TOSCRATCH2
       JSR FPNORMALIZE

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

       JSR FP1FROMSCRATCH1
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