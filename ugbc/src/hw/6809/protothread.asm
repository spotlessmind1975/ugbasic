; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                               PROTOTHREADING                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PROTOTHREADVOID
    RTS

; PROTOTHREADREGAT(B,Y)
PROTOTHREADREGAT
    LDX #PROTOTHREADLOOP
    LDA #0
    ROLB
    ASLA
    TFR D,X
    ROLB
    ASLA
    LEAX D,X
    STY ,X    
    RTS

; PROTOTHREADREG(Y)->B
PROTOTHREADREG
    LDB #0
    LDU #PROTOTHREADLOOP
    LEAU 6,U
PROTOTHREADREGL1
    PSHS B
    LDD ,U
    CMPD #PROTOTHREADVOID
    BNE PROTOTHREADREGNEXT
    STY ,U
    PULS B
    RTS
PROTOTHREADREGNEXT
    PULS B
    INCB
    LEAU 8,U
    JMP PROTOTHREADREGL1

; PROTOTHREADUNREG(B)
PROTOTHREADUNREG
    LDX #PROTOTHREADLOOP
    LDA #0
    ROLB
    ASLA
    TFR D,X
    ROLB
    ASLA
    LEAX D,X
    LDY #PROTOTHREADVOID
    STY ,X    
    RTS

; PROTOTHREADSAVE(B,A)
PROTOTHREADSAVE
    LDY #PROTOTHREADLC
    PSHS A
    LDA #0
    LEAY D, Y
    PULS A
    STA ,Y
    RTS

; PROTOTHREADRESTORE(B)->A
PROTOTHREADRESTORE
    LDY #PROTOTHREADLC
    LDA #0
    LEAY D, Y
    LDA ,Y
    RTS

; PROTOTHREADSETSTATE(B,A)
PROTOTHREADSETSTATE
    LDY #PROTOTHREADST
    PSHS A
    LDA #0
    LEAY D, Y
    PULS A
    STA ,Y
    RTS

; PROTOTHREADGETSTATE(B)->A
PROTOTHREADGETSTATE
    LDY #PROTOTHREADST
    LDA #0
    LEAY D, Y
    LDA ,Y
    RTS
