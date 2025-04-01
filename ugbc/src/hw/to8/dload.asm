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

; A: bank
; Y: destination address
; U: size
DLOAD
    
    ORCC  #$50

    ; motor on

    LDA #1
    STA $6029
    JSR $E815
    LBCS DLOADL2

    PSHS U

    ; move forward to the first data block

    LDU #50

DLOADL1SKIP
    LDA #2
    STA $6029
    JSR $E815
    LBCS DLOADL2
    LEAU -1, U
    CMPU #0
    LBNE DLOADL1SKIP

DLOADL1SIZE

    ; read size

    LDA #2
    STA $6029
    JSR $E815
    LBCS DLOADL2

    ; read bytes

    ; CLRA
    ; SUBD #5
    ; TFR D, U

    ; skip

    LDA #2
    STA $6029
    JSR $E815
    LBCS DLOADL2
    JSR $E815
    LBCS DLOADL2
    JSR $E815
    LBCS DLOADL2
    JSR $E815
    LBCS DLOADL2
    JSR $E815
    LBCS DLOADL2

    PULS U

DLOADL1REPEAT

    LDA #2
    STA $6029
    JSR $E815
    LBCS DLOADL2
    STB , X+
    LEAU -1, U
    CMPU #0
    BNE DLOADL1REPEAT

    ; skip checksum

    LDA #2
    STA $6029
    JSR $E815

DLOADL1END

    ; move forward to the next data type

    LDU #14

    ; read last block?

    LDA #2
    STA $6029
    JSR $E815
    BCS DLOADL2

    CMPB #$DC
    BEQ DLOADL2SKIP

    LEAU -2, U

DLOADL2SKIP
    LDA #2
    STA $6029
    JSR $E815
    BCS DLOADL2
    LEAU -1, U
    CMPU #0
    BNE DLOADL2SKIP

DLOADL2

    LDA #16
    STA $6029
    JSR $E815

    LDA #$1F
    STA $E7E5

    ANDCC #$AF

    RTS