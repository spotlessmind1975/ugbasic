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
;*                      CONVERT A NUMBER TO A STRING                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

N2STRING:
    JSR N2STRINGH2D
    LDX #9;
    LDY #0;
N2STRINGL1:
    LDA RESBUFFER,x
    BNE N2STRINGL2
    DEX
    BNE N2STRINGL1
N2STRINGL2:
    LDA RESBUFFER,X
    ORA #$30
    STA ($23),Y
    INY
    DEX
    BPL N2STRINGL2
    JMP N2STRINGEND
N2STRINGH2D:
    LDX #0
    N2STRINGL3:
    JSR N2STRINGDIV10
    STA RESBUFFER, X
    INX
    CPX #10
    BNE N2STRINGL3
    RTS
N2STRINGDIV10:
    LDY #32
    LDA #0
    CLC
N2STRINGL4:
    ROL
    CMP #10
    BCC N2STRINGSSKIP
    SBC #10
N2STRINGSSKIP:
    ROL $19
    ROL $20
    ROL $21
    ROL $22
    DEY
    BPL N2STRINGL4
    RTS
N2STRINGEND:
    TYA
    STA $25
    RTS

RESBUFFER:  .RES    10