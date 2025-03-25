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
;*                   DLOAD ROUTINES ON OLIVETTI PRODEST PC128                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Y: destination address
; U: size
DLOAD
    
    STA <MATHPTR2
    CMPA #0
    BEQ DLOAD
    ; LEAX $6000, X
    
DLOAD2

    STU <MATHPTR0

    ORCC #$50

DLOADL1
    PSHS D,X

    LDA #1
    SWI
    FCB $22

DLOADL1REPEAT

    LDY #DLOADBLOCK

    LDA #1
    LDB #0
    SWI
    FCB $20

    CMPB #0
    BEQ DLOADL1REPEAT
    CMPB #$FF
    BEQ DLOADL1REPEAT

    LEAY 6,Y

    LDU <MATHPTR0
    CMPU #$00F9
    BLE DLOADL1MV2

    LEAU -$00F9, U
    STU <MATHPTR0

    LDU #$00F9
    JMP DLOADL1MV2L

DLOADL1MV2L

    LDA <MATHPTR2
    BEQ DLOADL1MV2LRAM

    PSHS D, U
    TFR U, D
    LDB <MATHPTR2
    CLRA
    TFR D, U
    JSR BANKWRITE
    PULS D, U

    BRA DLOADL1REPEAT2

DLOADL1MV2LRAM
    LDA ,Y+
    STA ,X+
    LEAU -1, U
    CMPU #0
    BNE DLOADL1MV2LRAM

DLOADL1REPEAT2

    LDY #DLOADBLOCK

    LDA #1
    LDB #0
    SWI
    FCB $20

    CMPB #0
    BEQ DLOADL1REPEAT
    CMPB #$FF
    BEQ DLOADL1REPEAT

    LEAY 1,Y

    LDU <MATHPTR0
    CMPU #$00FE
    BLE DLOADL1MV2

    LEAU -$00FE, U
    STU <MATHPTR0
    
    LDU #$00Fe
    JMP DLOADL1MV2L

DLOADL1MV2

    LDA <MATHPTR2
    BEQ DLOADL1MV2RAM

    PSHS D, U
    TFR U, D
    LDB <MATHPTR2
    CLRA
    TFR D, U
    JSR BANKWRITE
    PULS D, U

    BRA DLOADL1MV2DONE

DLOADL1MV2RAM
    LDA ,Y+
    STA ,X+
    LEAU -1, U
    CMPU #0
    BNE DLOADL1MV2RAM

DLOADL1MV2DONE

    LDA #0
    SWI
    FCB $22
    PULS D,X

    ANDCC #$AF

    RTS

