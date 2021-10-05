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

CPUMATHDIV8BITTO8BIT
    LDA MATHPTR1
    STA TMPPTR
    LDA MATHPTR0
    STA TMPPTR+1

CPUMATHDIV8BITTO8BITL1

    LDX #$0

    LDA #$8
    STA MATHPTR3

    LDA #$0
    LDB TMPPTR+1

CPUMATHDIV8BITTO8BITL1X
    ASLB
    ROLA
    
    CMPA TMPPTR
    
    BCS CPUMATHDIV8BITTO8BITL2
    SUBA TMPPTR
    INCB
CPUMATHDIV8BITTO8BITL2
    DEC MATHPTR3
    BNE CPUMATHDIV8BITTO8BITL1X
    STB MATHPTR2
    CMPX #$1
    BNE CPUMATHDIV8BITTO8BITL3
    ADDA 1

CPUMATHDIV8BITTO8BITL3
    STA MATHPTR3
    RTS

CPUMATHDIV8BITTO8BIT_SIGNED

    LDA MATHPTR1
    ANDA #$80
    CMPA #$0
    BEQ CPUMATHDIV8BITTO8BIT_SIGNEDL1
    LDX #$1
    LDA MATHPTR1
    EORA #$FF
    ADDA #$1
    STA TMPPTR
    JMP CPUMATHDIV8BITTO8BIT_SIGNEDL2
CPUMATHDIV8BITTO8BIT_SIGNEDL1
    STA TMPPTR
CPUMATHDIV8BITTO8BIT_SIGNEDL2

    LDA MATHPTR0
    ANDA #$80
    CMPA #$0
    BEQ CPUMATHDIV8BITTO8BIT_SIGNEDL3
    LDX #$1
    LDA MATHPTR0
    EORA #$FF
    ADDA #$1
    STA TMPPTR+1
    JMP CPUMATHDIV8BITTO8BIT_SIGNEDL4
CPUMATHDIV8BITTO8BIT_SIGNEDL3
    STA TMPPTR+1
CPUMATHDIV8BITTO8BIT_SIGNEDL4
    JMP CPUMATHDIV8BITTO8BITL1
