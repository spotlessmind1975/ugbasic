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
;  * Unless required by applicaBLO law or agreed to in writing, software
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
;*                            FADE ROUTINE ON EF936X                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


FADEDONE
    fcb $0

FADEINDEX
    fcb $0

FADEOUT
    LDB #15
    STB FADEDONE
    LDB #0
    STB FADEINDEX
    LDX #SHADOWPALETTE
FADEOUTL1
    LDD , X
    SUBA #$01
    CMPA #0
    BGT FADEOUTL1B
    CLRA
FADEOUTL1B
    PSHS D
    TFR B, A
    ANDB #$0F
    SUBB #$01
    CMPB #0
    BGT FADEOUTL1C
    CLRB
FADEOUTL1C
    ANDA #$F0
    SUBB #$10
    CMPB #0
    BGT FADEOUTL1D
    CLRA
FADEOUTL1D
    STA <MATHPTR0
    ORB <MATHPTR0
    STA <MATHPTR0
    PULS D
    LDB <MATHPTR0
    CMPD #0
    BGT FADEOUTP
    DEC FADEDONE
FADEOUTP
    PSHS D
    LDB FADEINDEX
    ASLB
    STB BASE_SEGMENT+$DB
    PULS D
    STB BASE_SEGMENT+$DA
    STA BASE_SEGMENT+$DA
    STD ,X
    LEAX 2, X
    INC FADEINDEX
    LDB FADEINDEX
    CMPB #16
    BLE FADEOUTL1
FADEWL1
    LDB FADEDONE
    BLE FADEOUTDONE2
FADEOUTPERIOD
    LDD #1
    JSR WAITTIMER
    BRA FADEOUT
FADEOUTDONE2
    RTS

FADEIN
    LDB #15
    STB FADEDONE
    LDB #0
    STB FADEINDEX
    LDX #SHADOWPALETTE
    LDY #COMMONPALETTE
FADEINL1
    LDA , X
    ADDA #$01
    CMPA ,Y
    BLS FADEINL1B
    LDA , Y
FADEINL1B
    LDB 1,X
    ADDB #$11
    CMPB 1,Y
    BLS FADEINL2
    LDB 1,Y
FADEINL2
    CMPD ,Y
    BNE FADEINP
    DEC FADEDONE
FADEINP
    PSHS D
    LDB FADEINDEX
    ASLB
    STB BASE_SEGMENT+$DB
    PULS D
    STB BASE_SEGMENT+$DA
    STA BASE_SEGMENT+$DA
    STD ,X
    LEAX 2, X
    LEAY 2, Y
    INC FADEINDEX
    LDB FADEINDEX
    CMPB #16
    BLE FADEINL1
    LDB FADEDONE
    BLE FADEINDONE2
FADEINPERIOD
    LDD #1
    JSR WAITTIMER
    BRA FADEIN
FADEINDONE2
    RTS
