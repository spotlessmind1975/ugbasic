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
;*                       CLEAR SCREEN ROUTINE FOR GIME                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLSG
    LDA CURRENTTILEMODE
    BEQ CLSGX
    RTS

CLSGX
    PSHS A,B,X,Y,U
    LDB _PAPER
    JSR GIMESELECTPALETTE
    STA -42, S

    LDA CURRENTMODE
    ANDA #$E0
    CMPA #$E0
    BEQ CLSGB16
    CMPA #$60
    BEQ CLSGB4
    CMPA #$40
    LBEQ CLSGB2
    RTS

CLSGB16
    LDA -42, S
    LSLA
    LSLA
    LSLA
    LSLA
    ORA -42, S
    STA -42, S
    JMP CLSGGO

CLSGB4
    LDA -42, S
    LSLA
    LSLA
    ORA -42, S
    LSLA
    LSLA
    ORA -42, S
    LSLA
    LSLA
    ORA -42, S
    STA -42, S
    JMP CLSGGO

CLSGB2
    LDA -42, S
    LSLA
    ORA -42, S
    LSLA
    ORA -42, S
    LSLA
    ORA -42, S
    LSLA
    ORA -42, S
    LSLA
    ORA -42, S
    LSLA
    ORA -42, S
    LSLA
    ORA -42, S
    STA -42, S
    JMP CLSGGO

CLSGGO
    LDU CURRENTFRAMESIZE
    LDX BITMAPADDRESS

    LDA -42, S

CLSGX0
    STA ,X+
    LEAU -1, U
    CMPU #0
    BNE CLSGX0
    PULS A,B,X,Y,U
    RTS
