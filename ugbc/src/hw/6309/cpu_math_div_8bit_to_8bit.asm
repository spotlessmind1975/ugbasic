; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

; unsigned 8 bit division B=B/A A=B.mod.A
; http://www.logicielsmoto.com/phpBB/viewtopic.php?p=1098#p1098


CPUMATHDIV8BITTO8BIT
    STA     CPUMATHDIV8BITTO8BIT1+3
    STA     CPUMATHDIV8BITTO8BIT2-1
    CLRA
    LDX     #8
CPUMATHDIV8BITTO8BIT1
    ROLB
    ROLA
    CMPA    #0
    BCS     CPUMATHDIV8BITTO8BIT2
    SUBA    #0
CPUMATHDIV8BITTO8BIT2
    LEAX    -1,X
    BNE     CPUMATHDIV8BITTO8BIT1
    ROLB
    COMB
    RTS

CPUMATHDIV8BITTO8BIT_SIGNED
    PSHS D
    ANDA #$80
    STA <MATHPTR0
    ANDB #$80
    EORB <MATHPTR0
    STB <MATHPTR0
    PULS D
    PSHS D
    STA <MATHPTR1
    ANDA #$80
    BEQ CPUMATHDIV8BITTO8BIT_SIGNEDA0
    NEG <MATHPTR1
CPUMATHDIV8BITTO8BIT_SIGNEDA0
    STB <MATHPTR2
    ANDB #$80
    BEQ CPUMATHDIV8BITTO8BIT_SIGNEDB0
    NEG <MATHPTR2
CPUMATHDIV8BITTO8BIT_SIGNEDB0
    PULS D

    LDA <MATHPTR1
    LDB <MATHPTR2

    BSR CPUMATHDIV8BITTO8BIT
    PSHS D
    LDA <MATHPTR0
    BEQ CPUMATHDIV8BITTO8BIT_SIGNED0
    NEGB
    STB <MATHPTR0
    PULS D
    LDB <MATHPTR0
    RTS

CPUMATHDIV8BITTO8BIT_SIGNED0
    PULS D
    RTS
