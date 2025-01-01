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
;*                         BASIC DISK LOADER FOR COCO3                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

         ORG $0E00

; ---------------------------------------------------
; ROUTINE TO PRESERVE STACK 
; ---------------------------------------------------

COPYSTACK
        
        ; Disable interrupts

        ORCC    #$50

        ; Save X and D registers

        PSHS X
        PSHS D
        
        LDX     #$0E00
        STX     $001F
        TFR     S, X

        LDS     #$0F00
        STS     $0021

        LDB     #$FF

        ; Move stack from $0E00 to $0F00
COPYSTACKL1
        LDA     B,X
        STA     B,S
        DECB
        BNE     COPYSTACKL1

        ; Restore X and D registers

        PULS D
        PULS X

        ; Re-enable interrupts

        ANDCC   #$9F

        RTS

; ---------------------------------------------------
; SINGLE BLOCK COPY TO RAM
; ---------------------------------------------------

COPYBLOCK

        ; Disable interrupts
        
        ORCC    #$50

        ; Copy 4096 bytes from X to Y

        LDU     #$1000
        LDX     #$2A00
        LDY     #$2A00 ; <-- this will be replaced by BASIC

        ; Enable RAM under ROM

        STA     $FFDF

        ; Copy one byte at a time
COPYBLOCKL1
        LDA     ,X+
        STA     ,Y+
        LEAU    -1, U
        CMPU    #0000
        BNE     COPYBLOCKL1

        ; Re-enable ROM

        STA     $FFDE

        ; Re-enable interrupts

        ANDCC   #$9F

        RTS

; ---------------------------------------------------
; SINGLE BLOCK COPY TO GIME
; ---------------------------------------------------

COPYBLOCKGIME

        ; Disable interrupts

        ORCC    #$50

        ; Copy 4096 from RAM to (fixed) GIME RAM

        LDU     #$1000
        LDX     #$2A00
        LDY     #$C000  ; <--- replaced by BASIC ($c000/$d000)

        ; Enable RAM under ROM

        STA     $FFDF

        ; Move to the correct bank

        LDA     #$00    ; <--- replaced by BASIC ($00)
        STA     $FFA6

        ; Copy one byte at a time
COPYBLOCKGIMEL1
        LDA     ,X+
        STA     ,Y+
        LEAU    -1, U
        CMPU    #0000
        BNE     COPYBLOCKGIMEL1

        ; Restore bank

        LDA     #$3E
        STA     $FFA6

        ; Re-enable ROM

        STA     $FFDE

        ; Re-enable interrupts

        ANDCC   #$9F

        RTS
