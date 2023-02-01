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
;*                             HEX TO STRING ON 6809                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

H2STRING
    CMPB #0
    BNE H2STRINGA
    RTS

H2STRINGA
    LDA #0
    TFR D, U
    LDB #0
    LEAU -1, U
H2STRINGL1
    LDA B,X
    JSR H2STRINGBYTE
    LDA <MATHPTR2
    STA 1,Y
    LDA <MATHPTR1
    STA 0,Y
    LEAY 2, Y
H2STRINGL1A
    INCB
    LEAU -1, U
    CMPU #$FFFF
    BNE H2STRINGL1
    RTS

H2STRINGBYTE
    PSHS A
    LSRA
    LSRA
    LSRA
    LSRA
    CMPA #$0a
    BGE HEX2STRINGA
HEX2STRING0
    ADDA #48
    STA <MATHPTR1
    JMP HEX2STRINGLSB
HEX2STRINGA
    ADDA #55
    STA <MATHPTR1
HEX2STRINGLSB
    PULS A
    ANDA #$0F
    CMPA #$0A
    BGE HEX2STRINGA2
HEX2STRING02
    ADDA #48
    STA <MATHPTR2
    RTS
HEX2STRINGA2
    ADDA #55
    STA <MATHPTR2
    RTS