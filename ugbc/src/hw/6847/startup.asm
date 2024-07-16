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
;*                            STARTUP ROUTINE FOR 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUMEMMOVE
    CMPU #0
    BEQ CPUMEMMOVEDONE
CPUMEMMOVEL1
    LDA ,Y+
    STA ,X+
    LEAU -1,U
    CMPU #$0
    BNE CPUMEMMOVEL1
CPUMEMMOVEDONE
    RTS
    
C6847STARTUP

    ; (4) Default screen mode is semigraphic-4

    STA $FFC0
    STA $FFC2
    STA $FFC4
    LDA $FF22
    ANDA #$7F
    STA $FF22  

    LDA $03
    STA $FF98
    RTS

; Change the start of the image in RAM to display in CoCo 1 and 2 text and
; graphics modes. The value in $F0-$F6 times 512 is the start of video RAM.
;
; Input : D - Address
;
C6847VIDEOSTARTATT
    ANDB #0
    ANDA #$FE
    STD TEXTADDRESS
    BRA C6847VIDEOSTARTAT

C6847VIDEOSTARTATB
    ANDB #0
    ANDA #$FE
    STD BITMAPADDRESS
    BRA C6847VIDEOSTARTAT

C6847VIDEOSTARTAT
    TFR A, B
    LSRA
    LDB #$07
    LDX #$FFC6
C6847VIDEOSTARTATL1
    RORA
    BCC C6847VIDEOSTARTATB0
    STA 1,X
    BRA C6847VIDEOSTARTATL1NX
C6847VIDEOSTARTATB0
    STA ,X
C6847VIDEOSTARTATL1NX
    LEAX 2,X
    DECB
    BNE C6847VIDEOSTARTATL1
    RTS

