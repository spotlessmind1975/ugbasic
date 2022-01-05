; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

; unsigned division
; D=D/X X=D.mod.X
; http://www.logicielsmoto.com/phpBB/viewtopic.php?p=1090#p1090

CPUMATHDIV16BITTO16BIT_fast
    PSHS  X
    STB   ,S
    LDB   1,S
    DECB
    BITB  #1
    BNE   CPUMATHDIV16BITTO16BIT_remainder
    
    LDB   ,S
CPUMATHDIV16BITTO16BIT_slow
    STD   ,S
    BRA   CPUMATHDIV16BITTO16BIT0  

CPUMATHDIV16BITTO16BIT_remainder
    ANDB  ,S
    STB   1,S   
    LDB   ,S
    CLR   ,S
    JMP   [CPUMATHDIV16BITTO16BIT_tab-2,X]

CPUMATHDIV16BITTO16BIT_fast32
    LSRA
    RORB
CPUMATHDIV16BITTO16BIT_fast16    
    LSRA
    RORB
CPUMATHDIV16BITTO16BIT_fast8    
    LSRA
    RORB
CPUMATHDIV16BITTO16BIT_fast4    
    LSRA
    RORB
CPUMATHDIV16BITTO16BIT_fast2    
    LSRA
    RORB
    PULS  X,PC

CPUMATHDIV16BITTO16BIT_tab
    FDB   CPUMATHDIV16BITTO16BIT_fast2
    FDB   CPUMATHDIV16BITTO16BIT_fast4
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_fast8
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_fast16
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_slow
    FDB   CPUMATHDIV16BITTO16BIT_fast32
    
CPUMATHDIV16BITTO16BIT
    CMPX  #32
    BLS   CPUMATHDIV16BITTO16BIT_fast
    
    PSHS  D
CPUMATHDIV16BITTO16BIT0
    STX   CPUMATHDIV16BITTO16BITL2-2
    STX   CPUMATHDIV16BITTO16BITL2-7
    LEAY  1,S
    CLRA
    CLRB
    LDX   #16
CPUMATHDIV16BITTO16BITL1    
    ROL   ,Y
    ROL   ,S
    ROLB
    ROLA
    CMPD  #$5555
    BCS   CPUMATHDIV16BITTO16BITL2
    SUBD  #$5555
CPUMATHDIV16BITTO16BITL2
    LEAX  -1,X
    BNE CPUMATHDIV16BITTO16BITL1
    TFR   D,X
    PULS  D
    ROLB
    ROLA
    COMB
    COMA
    RTS

CPUMATHDIV16BITTO16BIT_SIGNED
    STD   <MATHPTR0
    STX   <MATHPTR2
    EORA  <MATHPTR2 ; compute sign of result
    STA   <MATHPTR5 ; store it on stack
    LDD   #0        ; D=-X
    SUBD  <MATHPTR2 ; X < 0 ?
    BMI   CPUMATHDIV16BITTO16BIT_SIGNED1
    STD   <MATHPTR2 ; yes ==> repmace with -X
CPUMATHDIV16BITTO16BIT_SIGNED1
    LDX   <MATHPTR2
    LDD   <MATHPTR0 ; D < 0 ?
    BPL   CPUMATHDIV16BITTO16BIT_SIGNED2
    NEGA            ; yes => negate D
    NEGB
    SBCA  #0
CPUMATHDIV16BITTO16BIT_SIGNED2    
    BSR   CPUMATHDIV16BITTO16BIT
    TST   <MATHPTR5 ; get sign of result
    BPL   CPUMATHDIV16BITTO16BIT_SIGNED3    
    NEGA            ; negative ? 
    NEGB            ; yes => negate D
    SBCA  #0
CPUMATHDIV16BITTO16BIT_SIGNED3
    RTS
