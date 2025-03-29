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
;*                   BANK ROUTINES ON OLIVETTI PRODEST PC128                   *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BANKSHADOWPREV     fcb     $0

; Move data from bank to main memory.
;
; B : number of bank 
; Y : address on bank 
; U : size to read
; X : address on memory 
; -> returns $ffff into D
BANKREAD

    ORCC #$50

    ; Preserve size register.
    ; PSHS D

    ; Save actual bank number.
    ; LDA BANKSHADOW
    ; STA BANKSHADOWPREV

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5

    ; Restore size register.
    ; PULS D
    TFR U, D

    ; Copy memory at high speed.
    JSR DUFFDEVICE

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

@IF residentDetectionEnabled

    ; We load $FFFF into D, in order to be able
    ; to use this value to set a "used" BANK ID.
    
    LDD #$FFFF

@ENDIF

    RTS

; Move data (1 byte) from bank to main memory.
;
; B : number of bank 
; Y : address on bank 
; X : address on memory 
BANKREAD1

    ORCC #$50

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5
    
    ; copy 1 byte
    LDA ,Y
    STA ,X

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS

; Move data (2 bytes) from bank to main memory.
;
; B : number of bank 
; Y : address on bank 
; X : address on memory 
BANKREAD2

    ORCC #$50

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5
    
    ; copy 2 bytes
    LDD ,Y
    STD ,X

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS

; Move data (4 bytes) from bank to main memory.
;
; B : number of bank 
; Y : address on bank 
; X : address on memory 
BANKREAD4

    ORCC #$50

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5
    
    ; copy 4 bytes
    LDD ,Y++
    STD ,X++
    LDD ,Y
    STD ,X

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS

; Uncompress directly the data from bank.
;
; B : number of bank 
; X : address on bank 
; Y : address on memory 
BANKUNCOMPRESS

    ORCC #$50

    ; Save actual bank number.
    ;LDA BANKSHADOW
    ;STA BANKSHADOWPREV

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5

    ; Uncompress memory at high speed.
    JSR MSC1UNCOMPRESS

    ; Restore the bank number to the previous.
    ;LDA BANKSHADOWPREV
    ;STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5
    
    ANDCC #$AF

@IF residentDetectionEnabled

    ; We load $FFFF into D, in order to be able
    ; to use this value to set a "used" BANK ID.
    
    LDD #$FFFF

@ENDIF

    RTS

; Move data to bank from main memory.
;
; Y : address from memory 
; U : size to write
; B : number of bank 
; X : address on bank 
BANKWRITE

    ORCC #$50

    ; Preserve size register.
    ; PSHS D

    ; Save actual bank number.
    ; LDA BANKSHADOW
    ; STA BANKSHADOWPREV

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5

    ; Restore size register.
    ; PULS D
    TFR U, D

    ; Copy memory at high speed.
    JSR DUFFDEVICE

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS

; Move data (1 byte) to bank from main memory.
;
; X : address from memory 
; B : number of bank 
; Y : address on bank 
BANKWRITE1

    ORCC #$50

    ; Save actual bank number.
    ; LDA BANKSHADOW
    ; STA BANKSHADOWPREV

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5

    LDA ,X
    STA ,Y

    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS

; Move data (2 bytes) to bank from main memory.
;
; X : address from memory 
; B : number of bank 
; Y : address on bank 
BANKWRITE2

    ORCC #$50

    ; Save actual bank number.
    ; LDA BANKSHADOW
    ; STA BANKSHADOWPREV

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5

    LDD ,X
    STD ,Y
    
    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS

; Move data (4 bytes) to bank from main memory.
;
; X : address from memory 
; B : number of bank 
; Y : address on bank 
BANKWRITE4

    ORCC #$50

    ; Save actual bank number.
    ; LDA BANKSHADOW
    ; STA BANKSHADOWPREV

    ; Change bank number to the required one.
    ; TFR U, D
    ; STB BANKSHADOW
    STB BASE_SEGMENT+$E5

    LDD ,X++
    STD ,Y++
    LDD ,X
    STD ,Y
    
    ; Restore the bank number to the previous.
    ; LDA BANKSHADOWPREV
    ; STA BANKSHADOW
    LDA #7
    STA BASE_SEGMENT+$E5

    ANDCC #$AF

    RTS
