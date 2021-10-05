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

CPUMATHDIV28BIT
    CMPB #0
    BEQ CPUMATHDIV28BITL1
CPUMATHDIV28BITL2
    ASRA
    DECB
    CMPB #0
    BNE CPUMATHDIV28BITL2
CPUMATHDIV28BITL1
    RTS

CPUMATHDIV28BIT_SIGNED
    PSHS A
    ANDA #$80
    CMPA #$0
    BEQ CPUMATHDIV28BIT_SIGNEDL1
    LDA #1
    STA MATHPTR0
    PULS A
    EORA #$FF
    ADDA #$1
    JMP CPUMATHDIV28BIT_SIGNEDL2
CPUMATHDIV28BIT_SIGNEDL1
    LDA #0
    STA MATHPTR0
    PULS A
CPUMATHDIV28BIT_SIGNEDL2
    JSR CPUMATHDIV28BIT
    PSHS A
    LDA MATHPTR0
    BEQ CPUMATHDIV28BIT_SIGNEDL3
    PULS A
    EORA #$FF
    ADDA #$1
    JMP CPUMATHDIV28BIT_SIGNEDL4
CPUMATHDIV28BIT_SIGNEDL3
    PULS A
CPUMATHDIV28BIT_SIGNEDL4
    RTS