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
;*                           DOJO PROTOCOL ON ATARI                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOJOPACKET:
DOJOPACKET_CMD:
DOJOPACKET_STATUS:
    .BYTE $0
DOJOPACKET_PAR1:
DOJOPACKET_RSIZE:
    .BYTE $0
DOJOPACKET_PAR2:
    .BYTE $0
DOJOPACKET_SIZE:
    .BYTE $0

DOJOSERIALPUTREQUEST0:
    PHA
    LDA #0
    STA DOJOSERIALPUTREQUEST0SIZE+1
    PLA
DOJOSERIALPUTREQUESTX:    
    STA DOJOPACKET_CMD
    STX DOJOPACKET_PAR1
    STY DOJOPACKET_PAR2
DOJOSERIALPUTREQUEST0SIZE:
    LDA #0
    STA DOJOPACKET_SIZE
    LDA #<DOJOPACKET
    STA TMPPTR
    LDA #>DOJOPACKET
    STA TMPPTR+1
    LDA #4
    STA MATHPTR0
    JSR SERIALWRITE
    RTS

DOJOSERIALPUTREQUEST:
    PHA
    LDA MATHPTR2
    STA DOJOSERIALPUTREQUEST0SIZE+1
    PLA
    JSR DOJOSERIALPUTREQUESTX
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    LDA MATHPTR2
    STA MATHPTR0
    JSR SERIALWRITE
    RTS

DOJOSERIALGETRESPONSE0:
    LDA #<DOJOPACKET
    STA TMPPTR
    LDA #>DOJOPACKET
    STA TMPPTR+1
    LDA #2
    STA MATHPTR0
    JSR SERIALREAD
    LDA DOJOPACKET_STATUS
    RTS

DOJOSERIALGETRESPONSE:
    JSR DOJOSERIALGETRESPONSE0
    LDX DOJOPACKET_RSIZE
    CPX #0
    BEQ DOJOSERIALGETRESPONSEDONE
    LDA TMPPTR2
    STA TMPPTR
    LDA TMPPTR2+1
    STA TMPPTR+1
    LDA DOJOPACKET_RSIZE
    STA MATHPTR0
    JSR SERIALREAD
    LDX DOJOPACKET_RSIZE
DOJOSERIALGETRESPONSEDONE:
    LDA DOJOPACKET_STATUS
    RTS
