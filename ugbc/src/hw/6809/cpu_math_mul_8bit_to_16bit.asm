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

CPUMATHMUL8BITTO16BIT_SIGNED
    LDA #0
    STA <MATHPTR0
    LDA <MATHPTR1
    EORA <MATHPTR2
    ANDA #$80
    BEQ CPUMATHMUL8BITTO16BIT_SIGNEDL1
    STA <MATHPTR0
CPUMATHMUL8BITTO16BIT_SIGNEDL1
    LDA <MATHPTR1
    ANDA #$80
    BEQ CPUMATHMUL8BITTO16BIT_SIGNEDL2
    LDA <MATHPTR1
    EORA #$FF
    ADDA #1
    JMP CPUMATHMUL8BITTO16BIT_SIGNEDL3

CPUMATHMUL8BITTO16BIT_SIGNEDL2
    LDA <MATHPTR1
CPUMATHMUL8BITTO16BIT_SIGNEDL3
    LDB <MATHPTR2
    ANDB #$80
    BEQ CPUMATHMUL8BITTO16BIT_SIGNEDL4
    LDB <MATHPTR2
    EORB #$FF
    ADDB #1
    JMP CPUMATHMUL8BITTO16BIT_SIGNEDL5

CPUMATHMUL8BITTO16BIT_SIGNEDL4
    LDB <MATHPTR2
CPUMATHMUL8BITTO16BIT_SIGNEDL5
    MUL
    PSHS D
    LDA <MATHPTR0
    CMPA #0
    BEQ CPUMATHMUL8BITTO16BIT_SIGNEDL6
    PULS D
    EORA #$FF
    EORB #$FF
    ADDD #1
    JMP CPUMATHMUL8BITTO16BIT_SIGNEDL7
CPUMATHMUL8BITTO16BIT_SIGNEDL6
    PULS D
CPUMATHMUL8BITTO16BIT_SIGNEDL7
    RTS
    
