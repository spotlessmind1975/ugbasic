; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

PROTOTHREADVOID:
    RTS

; PROTOTHREADREGAT(Y,TMPPTR)
PROTOTHREADREGAT:
    TYA
    ASL A
    ASL A
    ASL A
    TAY
    INY
    INY
    INY
    INY
    INY
    LDA #<PROTOTHREADLOOP
    STA MATHPTR0
    LDA #>PROTOTHREADLOOP
    STA MATHPTR0+1
    LDA TMPPTR
    STA (MATHPTR0),Y
    INY
    LDA TMPPTR+1
    STA (MATHPTR0),Y
    RTS

; PROTOTHREADREG(TMPPTR)->Y
PROTOTHREADREG:
    LDX #0
    LDY #6
    LDA #<PROTOTHREADLOOP
    STA MATHPTR0
    LDA #>PROTOTHREADLOOP
    STA MATHPTR0+1
PROTOTHREADREGL1:
    LDA (MATHPTR0),Y
    CMP #<PROTOTHREADVOID
    BNE PROTOTHREADREGNEXT
    INY
    LDA (MATHPTR0),Y
    CMP #>PROTOTHREADVOID
    BNE PROTOTHREADREGNEXT
    DEY
    LDA TMPPTR
    STA (MATHPTR0),Y
    INY
    LDA TMPPTR+1
    STA (MATHPTR0),Y
    TXA
    TAY
    RTS
PROTOTHREADREGNEXT:
    INX
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    INY
    JMP PROTOTHREADREGL1

; PROTOTHREADUNREG(Y)
PROTOTHREADUNREG:
    TYA
    ASL A
    ASL A
    ASL A
    TAY
    INY
    INY
    INY
    INY
    INY
    LDA #<PROTOTHREADLOOP
    STA MATHPTR0
    LDA #>PROTOTHREADLOOP
    STA MATHPTR0+1
    LDA #<PROTOTHREADVOID
    STA (MATHPTR0),Y
    INY
    LDA #>PROTOTHREADVOID
    STA (MATHPTR0),Y
    RTS

; PROTOTHREADSAVE(Y,X)
PROTOTHREADSAVE:
    LDA #<PROTOTHREADLC
    STA MATHPTR0
    LDA #>PROTOTHREADLC
    STA MATHPTR0+1
    TXA
    STA (MATHPTR0),Y
    RTS

; PROTOTHREADRESTORE(Y)->X
PROTOTHREADRESTORE:
    LDA #<PROTOTHREADLC
    STA MATHPTR0
    LDA #>PROTOTHREADLC
    STA MATHPTR0+1
    LDA (MATHPTR0),Y
    TAX
    RTS

; PROTOTHREADSETSTATE(Y,X)
PROTOTHREADSETSTATE:
    LDA #<PROTOTHREADST
    STA MATHPTR0
    LDA #>PROTOTHREADST
    STA MATHPTR0+1
    TXA
    STA (MATHPTR0),Y
    RTS

; PROTOTHREADGETSTATE(Y)->X
PROTOTHREADGETSTATE:
    LDA #<PROTOTHREADST
    STA MATHPTR0
    LDA #>PROTOTHREADST
    STA MATHPTR0+1
    LDA (MATHPTR0),Y
    TAX
    RTS

PROTOTHREADLC:      .RES        16
PROTOTHREADST:      .RES        16
PROTOTHREADCT:      .BYTE       0

PROTOTHREADLOOP:
    LDX #0
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #1
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #2
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #3
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #4
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #5
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #6
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #7
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #8
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #9
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #10
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #11
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #12
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #13
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #14
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    LDX #15
    STX PROTOTHREADCT
    JSR PROTOTHREADVOID
    RTS
