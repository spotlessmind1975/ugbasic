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

CPUMATHDIV2CONST16BIT
    ANDCC #$FE
    ASRA
    RORB
    LEAX -1, X
    CMPX #0
    BNE %sloop
    RTS

CPUMATHDIV2CONST16BIT_SIGNED
    LDA #0
    STA <MATHPTR0
    TFR D, Y
    ANDA #$80
    BEQ CPUMATHDIV2CONST16BIT_SIGNEDL1
    LDA #1
    STA <MATHPTR0
    TFR Y, D
    EORA #$FF
    EORB #$FF
    ADDD #1
    JMP CPUMATHDIV2CONST16BIT_SIGNEDL2
CPUMATHDIV2CONST16BIT_SIGNEDL1
CPUMATHDIV2CONST16BIT_SIGNEDL2
    JSR CPUMATHDIV2CONST16BIT
    LDA <MATHPTR0
    BEQ CPUMATHDIV2CONST16BIT_SIGNEDL3
    EORA #$FF
    EORB #$FF
    ADDD #1
CPUMATHDIV2CONST16BIT_SIGNEDL3
    RTS

