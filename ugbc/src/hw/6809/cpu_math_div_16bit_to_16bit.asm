; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

CPUMATHDIV16BITTO16BIT
    PSHS  D
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
    BNE   CPUMATHDIV16BITTO16BITL1
    TFR   D,X
    PULS  D
    ROLB
    ROLA
    COMB
    COMA
    RTS

CPUMATHDIV16BITTO16BIT_SIGNED
    PSHS  D,X,Y   ; Y doesn't matter. It is just a placeholder for the sign
    EORA  2,S     ; compute sign of result
    STA   4,S     ; store it on stack
    LDD   #0      ; D=-X
    SUBD  2,S     ; X < 0 ?
    BMI   CPUMATHDIV16BITTO16BIT_SIGNED1
    STD   2,S     ; yes ==> repmace with -X
CPUMATHDIV16BITTO16BIT_SIGNED1
    PULS  D,X
    TSTA          ; D < 0 ?
    BPL   CPUMATHDIV16BITTO16BIT_SIGNED2
    NEGA          ; yes => negate D
    NEGB
    SBCA  #0
CPUMATHDIV16BITTO16BIT_SIGNED2    
    BSR   CPUMATHDIV16BITTO16BIT
    TST   ,S++    ; get sign of result
    BPL   CPUMATHDIV16BITTO16BIT_SIGNED3    
    NEGA          ; negative ? 
    NEGB          ; yes => negate D
    SBCA  #0
CPUMATHDIV16BITTO16BIT_SIGNED3
    RTS
