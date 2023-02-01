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
;*                             HEX TO STRING ON 6502                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

H2STRING:
    CPX #0
    BNE H2STRINGA
    RTS

H2STRINGA:
    DEX
H2STRINGL1:
    TXA
    TAY
    LDA (TMPPTR),Y
    JSR H2STRINGBYTE
    LDA MATHPTR2
    LDY #1
    STA (TMPPTR2),Y
    LDA MATHPTR1
    LDY #0
    STA (TMPPTR2),Y
    CLC
    LDA TMPPTR2
    ADC #2
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC #0
    STA TMPPTR2+1
H2STRINGL1A:
    DEX
    CPX #$FF
    BNE H2STRINGL1
    RTS

H2STRINGBYTE:
    PHA
    LSR A
    LSR A
    LSR A
    LSR A
    CMP #$0a
    BCS HEX2STRINGA
HEX2STRING0:
    ADC #48
    STA MATHPTR1
    JMP HEX2STRINGLSB
HEX2STRINGA:
    CLC
    ADC #55
    STA MATHPTR1
HEX2STRINGLSB:
    PLA
    AND #$0F
    CMP #$0A
    BCS HEX2STRINGA2
HEX2STRING02:
    ADC #48
    STA MATHPTR2
    RTS
HEX2STRINGA2:
    CLC
    ADC #55
    STA MATHPTR2
    RTS