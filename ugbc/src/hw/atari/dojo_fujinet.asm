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
;*                      DOJO PROTOCOL ON FUJINET ON ATARI                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJOFUJINETPUTREQUEST0:
    PHA
    LDA #0
    STA DOJOFUJINETPUTREQUEST0SIZE+1
    PLA
DOJOFUJINETPUTREQUESTX:    
    STA DOJOPACKET_CMD
    STX DOJOPACKET_PAR1
    STY DOJOPACKET_PAR2
DOJOFUJINETPUTREQUEST0SIZE:
    LDA #0
    STA DOJOPACKET_SIZE
    LDA #<DOJOPACKET
    STA TMPPTR2
    LDA #>DOJOPACKET
    STA TMPPTR2+1
    LDA #4
    STA MATHPTR2
    JSR FUJINETWRITE
    RTS

DOJOFUJINETPUTREQUEST:
    PHA
    LDA MATHPTR3
    STA DOJOFUJINETPUTREQUEST0SIZE+1
    PLA
    JSR DOJOFUJINETPUTREQUESTX
    LDA MATHPTR4
    STA TMPPTR2
    LDA MATHPTR5+1
    STA TMPPTR2+1
    LDA MATHPTR3
    STA MATHPTR2
    JSR FUJINETWRITE
    RTS

DOJOFUJINETGETRESPONSE0:
    LDA #<DOJOPACKET
    STA TMPPTR2
    LDA #>DOJOPACKET
    STA TMPPTR2+1
    LDA #2
    STA MATHPTR2
    JSR FUJINETREAD
    LDA DOJOPACKET_STATUS
    LDX DOJOPACKET_RSIZE
    RTS

DOJOFUJINETGETRESPONSE:
    JSR DOJOFUJINETGETRESPONSE0
DOJOFUJINETGETRESPONSEPAYLOAD:    
    LDX DOJOPACKET_RSIZE
    CPX #0
    BEQ DOJOFUJINETGETRESPONSEDONE
    LDA MATHPTR4
    STA TMPPTR2
    LDA MATHPTR5+1
    STA TMPPTR2+1
    LDA DOJOPACKET_RSIZE
    STA MATHPTR2
    JSR FUJINETREAD
    LDX DOJOPACKET_RSIZE
DOJOFUJINETGETRESPONSEDONE:
    LDA DOJOPACKET_STATUS
    RTS
