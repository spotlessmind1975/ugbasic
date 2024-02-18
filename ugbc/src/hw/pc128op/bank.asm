; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                   BANK ROUTINES ON OLIVETTI PRODEST PC128                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BANKSHADOWPREV     fcb     $0

; Move data from bank to main memory.
;
; U : number of bank 
; Y : address on bank 
; D : size to read
; X : address on memory 
BANKREAD

    ; Preserve size register.
    PSHS D

    ; Save actual bank number.
    ; LDA BANKSHADOW
    ; STA BANKSHADOWPREV

    ; Change bank number to the required one.
    TFR U, D
    ; STB BANKSHADOW
    STB $A7E5

    ; Restore size register.
    PULS D

    ; Copy memory at high speed.
    JSR DUFFDEVICE

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA $A7E5

    RTS

; Uncompress directly the data from bank.
;
; U : number of bank 
; X : address on bank 
; Y : address on memory 
BANKUNCOMPRESS

    ; Save actual bank number.
    ;LDA BANKSHADOW
    ;STA BANKSHADOWPREV

    ; Change bank number to the required one.
    TFR U, D
    ; STB BANKSHADOW
    STB $A7E5

    ; Uncompress memory at high speed.
    JSR MSC1UNCOMPRESS

    ; Restore the bank number to the previous.
    ;LDA BANKSHADOWPREV
    ;STA BANKSHADOW
    LDA #7
    STA $A7E5
    
    RTS
