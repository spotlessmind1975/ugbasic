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

; Division by a power of 2 using the duff device trick
CPUMATHMUL2CONST16BIT_SIGNED
CPUMATHMUL2CONST16BIT
    CMPX    #16
    BLT     CPUMATHMUL2CONST16BIT1
; X=16..    
    LDD     #0
    RTS
CPUMATHMUL2CONST16BIT1
    CMPX    #8
    BLO     CPUMATHMUL2CONST16BIT_duff2    
    TFR     B,A
; we could abuse illegal op and do TFR X,B here    
    PSHS    X
    LDB     1,S
    NEGB
    LDX     #CPUMATHMUL2CONST16BIT_duff1+16
    JMP     B,X
; X=8..15    
CPUMATHMUL2CONST16BIT_duff1
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    CLRB
    PULS    X,PC

; X=0..7
CPUMATHMUL2CONST16BITL1_duff2    
    PSHS    D,X
    LDX     #CPUMATHMUL2CONST16BITL1_duff2tab-2
    LDB     #8
    SUBB    3,S
    LSLB
    ABX
    PULS    D
    JMP     ,X
CPUMATHMUL2CONST16BITL1_duff2tab
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    LSLB
    ROLA
    PULS  X,PC
