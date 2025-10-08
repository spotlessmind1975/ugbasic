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
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                        CONVERT A STRING TO A (SIGNED) WORD                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Convert a string into a 8 bit number
;  Input:
;       U = string to convert
;       B = original len
;  Output:
;       B = result
CPUCONVERTSTRING8BIT
    JSR CPUCONVERTSTRING16BIT
    TFR X, D
    RTS

; Convert a string into a 16 bit number
;  Input:
;       U = string to convert
;       B = original len
;  Output:
;       X = result
CPUCONVERTSTRING16BIT
    CLR MATHPTR1
    LDX #0
    CMPB #0
    BEQ CPUCONVERTSTRING16BITDONE
    STB MATHPTR0
CPUCONVERTSTRING16BITL1
    DEC MATHPTR0
        
    LDB , U+

    CMPB #'-'
    BNE CPUCONVERTSTRING16BITN0
    LDA #$FF
    STA MATHPTR1
    JMP CPUCONVERTSTRING16BITL1
CPUCONVERTSTRING16BITN0
    SUBB #48
    BMI CPUCONVERTSTRING16BITDONE
    CMPB #9
    BHI CPUCONVERTSTRING16BITDONE

    PSHS D

    TFR X, D
    LSLB
    ROLA
    TFR D, X
    LSLB
    ROLA
    LSLB
    ROLA
    LEAX D, X

    PULS D

    ABX
        
    LDB MATHPTR0
    BNE CPUCONVERTSTRING16BITL1
CPUCONVERTSTRING16BITDONE
    LDA MATHPTR1
    CMPA #$FF
    BNE CPUCONVERTSTRING16BITDONES
    TFR X, D
    NEGA
    NEGB
    SBCA #0
    TFR D, X
CPUCONVERTSTRING16BITDONES
    RTS
