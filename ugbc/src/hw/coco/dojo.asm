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
;*                           DOJO PROTOCOL ON COCO                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJOSERIALPUTREQUEST0
    PSHS D
    LDA #0
    STA DOJOSERIALPUTREQUEST0SIZE+1
    PULS D
DOJOSERIALPUTREQUESTX    
    STA DOJOPACKET_CMD
    STU DOJOPACKET_PAR1
DOJOSERIALPUTREQUEST0SIZE
    LDA #42
    STA DOJOPACKET_SIZE
    LDX #DOJOPACKET
    LDB #4
    JSR SERIALWRITE
    TFR B, A
    RTS

DOJOSERIALPUTREQUEST
    STB DOJOSERIALPUTREQUEST0SIZE+1
    JSR DOJOSERIALPUTREQUESTX
    TFR Y, X
    LDB DOJOSERIALPUTREQUEST0SIZE+1
    BEQ DOJOSERIALPUTREQUESTDONE
    JSR SERIALWRITE
DOJOSERIALPUTREQUESTDONE
    TFR B, A
    RTS

DOJOSERIALGETRESPONSE0
    LDX #DOJOPACKET
    LDB #2
    JSR SERIALREAD
    LDA DOJOPACKET_STATUS
    LDB DOJOPACKET_RSIZE
    RTS

DOJOSERIALGETRESPONSE
    JSR DOJOSERIALGETRESPONSE0
DOJOSERIALGETRESPONSEPAYLOAD    
    LDB DOJOPACKET_RSIZE
    CMPB #0
    BEQ DOJOSERIALGETRESPONSEDONE
    TFR Y, X
    LDB DOJOPACKET_RSIZE
    JSR SERIALREAD
    LDB DOJOPACKET_RSIZE
DOJOSERIALGETRESPONSEDONE
    LDA DOJOPACKET_STATUS
    RTS

DOJOSERIALGETRESPONSEPAYLOADW
    LDU DOJOPACKET_RSIZE
    CMPU #0
    BEQ DOJOSERIALGETRESPONSEWDONE
    TFR Y, X
DOJOSERIALGETRESPONSEPAYLOADWL1
    CMPU #$100
    BLO DOJOSERIALGETRESPONSEPAYLOADWREMAIN
    LDB #$42
    JSR SERIALREAD
    LEAU -$42, U
    BRA DOJOSERIALGETRESPONSEPAYLOADWL1
DOJOSERIALGETRESPONSEPAYLOADWREMAIN
    TFR D, U
    JSR SERIALREAD
DOJOSERIALGETRESPONSEWDONE
    LDA DOJOPACKET_STATUS
    RTS
