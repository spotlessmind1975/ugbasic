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
;*                       DOJO PROTOCOL ON FUJINET ON COCO                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJOFUJINETINITIALIZED
    fcb $00

DOJOFUJINETPUTREQUEST0
    PSHS D
    LDA #0
    STA DOJOFUJINETPUTREQUEST0SIZE+1
    PULS D
DOJOFUJINETPUTREQUESTX    
    STA DOJOPACKET_CMD
    STU DOJOPACKET_PAR1
DOJOFUJINETPUTREQUEST0SIZE
    LDA #42
    STA DOJOPACKET_SIZE
    LDY #DOJOPACKET
    LDB #4
    JSR FUJINETWRITE
    RTS

DOJOFUJINETPUTREQUEST
    PSHS D
    PSHS Y
    STB DOJOFUJINETPUTREQUEST0SIZE+1
    JSR DOJOFUJINETPUTREQUESTX
    PULS Y
    PULS D
    LDB DOJOFUJINETPUTREQUEST0SIZE+1
    BEQ DOJOFUJINETPUTREQUEST0DONE
    JSR FUJINETWRITE
DOJOFUJINETPUTREQUEST0DONE
    RTS

DOJOFUJINETGETRESPONSE0
    LDY #DOJOPACKET
    LDB #2
    JSR FUJINETREAD
    LDA DOJOPACKET_STATUS
    LDB DOJOPACKET_RSIZE
    RTS

DOJOFUJINETGETRESPONSEW0
    LDY #DOJOPACKET
    LDB #3
    JSR FUJINETREAD
    LDA DOJOPACKET_STATUS
    LDB DOJOPACKET_RSIZE
    RTS

DOJOFUJINETGETRESPONSE
    PSHS D
    PSHS Y
    JSR DOJOFUJINETGETRESPONSE0
    PULS Y
    PULS D
DOJOFUJINETGETRESPONSEPAYLOAD    
    LDB DOJOPACKET_RSIZE
    CMPB #0
    BEQ DOJOFUJINETGETRESPONSEDONE
    JSR FUJINETREAD
    LDb DOJOPACKET_RSIZE
DOJOFUJINETGETRESPONSEDONE
    LDA DOJOPACKET_STATUS
    RTS
