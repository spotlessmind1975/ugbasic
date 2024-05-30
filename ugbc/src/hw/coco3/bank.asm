; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                            BANK ROUTINE ON COCO3                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; General read data from GIME to memory
; Y: source memory address
; X: destination memory address
; D: size of data to read
BANKREADG
    JSR GIMEBANKSHADOWCHANGE
    PSHS D
    TFR Y, D
    ADDD #$C000
    TFR D, Y
    PULS D
    JSR DUFFDEVICE
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read 1 byte from GIME to memory
; A : bank
; Y : source memory address
; X : destination memory address
BANKREAD1
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    TFR Y, D
    ADDD #$C000
    TFR D, Y
    LDA , Y
    STA , X
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read 2 byte from GIME to memory
; A : bank
; Y : source memory address
; X : destination memory address
BANKREAD2
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    TFR Y, D
    ADDD #$C000
    TFR D, Y
    LDD , Y
    STD , X
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read 4 byte from GIME to memory
; A : bank
; Y : source memory address
; X : destination memory address
BANKREAD4
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    TFR Y, D
    ADDD #$C000
    TFR D, Y
    LDD , Y++
    STD , X++
    LDD , Y
    STD , X
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read n byte(s) from GIME to memory
; A: bank
; Y: source memory address
; X: destination memory address
; U: size
BANKREAD
    STA BANKSHADOW
    TFR U, D
    JSR BANKREADG
    RTS

; General write data to GIME from memory
; Y: source memory address
; X: destination memory address
; D: size of data to write
BANKWRITEG
    JSR GIMEBANKSHADOWCHANGE
    PSHS D
    TFR X, D
    ADDD #$C000
    TFR D, X
    PULS D
    JSR DUFFDEVICE
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read 1 byte from GIME to memory
; A : bank
; Y : source memory address
; X : destination memory address
BANKWRITE1
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    TFR X, D
    ADDD #$C000
    TFR D, X
    LDA , Y
    STA , X
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read 2 byte from GIME to memory
; A : bank
; Y : source memory address
; X : destination memory address
BANKWRITE2
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    TFR X, D
    ADDD #$C000
    TFR D, X
    LDD , Y
    STD , X
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read 4 byte from GIME to memory
; A : bank
; Y : source memory address
; X : destination memory address
BANKWRITE4
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE
    TFR X, D
    ADDD #$C000
    TFR D, X
    LDD , Y++
    STD , Y++
    LDD , X
    STD , X
    JSR GIMEBANKSHADOWCHANGERESET
    RTS

; Read n byte(s) from REU to memory
; A : bank
; <TMPPTR: source memory address
; <TMPPTR2: destination memory address
; U: size
BANKWRITE
    STA BANKSHADOW
    TFR U, D
    JSR BANKWRITEG
    RTS

; Uncompress directly the data from bank.
;
; A : bank
; X : source memory address
; Y : destination memory address
BANKUNCOMPRESS
    STA BANKSHADOW
    JSR GIMEBANKSHADOWCHANGE

    ; Save actual bank number.
    ;LDA BANKSHADOW
    ;STA BANKSHADOWPREV

    ; Uncompress memory at high speed.
    JSR MSC1UNCOMPRESS

    JSR GIMEBANKSHADOWCHANGERESET
    RTS

    RTS
