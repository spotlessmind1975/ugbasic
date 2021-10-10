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

CPUMATHMUL16BITTO32BIT
    LDA <MATHPTR0
    LDB <MATHPTR2
    MUL
    STD <MATHPTR4

    LDA <MATHPTR1
    LDB <MATHPTR3
    MUL
    STD <MATHPTR6

    LDA <MATHPTR1
    LDB <MATHPTR2
    MUL
    TFR D, X
    
    LDA <MATHPTR0
    LDB <MATHPTR3
    MUL
    LEAX D, X
    TFR X, D
    
    ADDB <MATHPTR6
    STB <MATHPTR6

    ADDA <MATHPTR5
    STA <MATHPTR5

    RTS

CPUMATHMUL16BITTO32BIT_SIGNED
    LDA <MATHPTR0
    ANDA #$80
    BEQ CPUMATHMUL16BITTO32BIT_SIGNEDL1
    LDA <MATHPTR1
    EORA #$FF
    STA <MATHPTR1
    LDA <MATHPTR0
    EORA #$FF
    STA <MATHPTR0
    LDX <MATHPTR0
    LEAX 1,X
    STX <MATHPTR0
    JMP CPUMATHMUL16BITTO32BIT_SIGNEDL2
CPUMATHMUL16BITTO32BIT_SIGNEDL1

CPUMATHMUL16BITTO32BIT_SIGNEDL2

    LDA <MATHPTR2
    ANDA #$80
    BEQ CPUMATHMUL16BITTO32BIT_SIGNEDL3
    LDA <MATHPTR3
    EORA #$FF
    STA <MATHPTR3
    LDA <MATHPTR2
    EORA #$FF
    STA <MATHPTR2
    LDX <MATHPTR2
    LEAX 1,X
    STX <MATHPTR2
    JMP CPUMATHMUL16BITTO32BIT_SIGNEDL4
CPUMATHMUL16BITTO32BIT_SIGNEDL3

CPUMATHMUL16BITTO32BIT_SIGNEDL4
    LDA #0
    STA <TMPPTR
    LDA <MATHPTR0
    EORA <MATHPTR2
    ANDA #$80
    BEQ CPUMATHMUL16BITTO32BIT_SIGNEDL5
    STA <TMPPTR
CPUMATHMUL16BITTO32BIT_SIGNEDL5 
    JSR CPUMATHMUL16BITTO32BIT

    LDA <TMPPTR
    CMPA #0
    BEQ CPUMATHMUL16BITTO32BIT_SIGNEDL6
    LDA <MATHPTR0
    EORA #$FF
    STA <MATHPTR0
    LDA <MATHPTR1
    EORA #$FF
    STA <MATHPTR1
    LDA <MATHPTR2
    EORA #$FF
    STA <MATHPTR2
    LDA <MATHPTR3
    EORA #$FF
    STA <MATHPTR3
    LDA <MATHPTR3
    ADDA #1
    STA <MATHPTR3
    LDA <MATHPTR2
    ADDA #0
    STA <MATHPTR2
    LDA <MATHPTR1
    ADDA #0
    STA <MATHPTR1
    LDA <MATHPTR0
    ADDA #0
    STA <MATHPTR0
CPUMATHMUL16BITTO32BIT_SIGNEDL6
    RTS