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
;*                             DUFF DEVICE ON 6502                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DUFFDEVICE:
    LDA MATHPTR1
    BNE DUFFDEVICE2
    LDA MATHPTR0
    BNE DUFFDEVICE2
    
    RTS
    
DUFFDEVICE2:

    INC MATHPTR1

    LDA TMPPTR
    STA DUFFDEVICEL0+1
    LDA TMPPTR+1
    STA DUFFDEVICEL0+2

    LDA TMPPTR2
    STA DUFFDEVICEL1+1
    LDA TMPPTR2+1
    STA DUFFDEVICEL1+2

DUFFDEVICE3:

    DEC MATHPTR1
    BEQ DUFFDEVICE3B
    LDX #$FF
    JMP DUFFDEVICE3C

DUFFDEVICE3B:
    LDX MATHPTR0
    DEX

DUFFDEVICE3C:

DUFFDEVICEL0:
    LDA $ffff, X

DUFFDEVICEL1:
    STA $ffff, X

    DEX
    CPX #$FF
    BNE DUFFDEVICEL0

    INC DUFFDEVICEL0+2
    INC DUFFDEVICEL1+2

    LDA MATHPTR1
    BNE DUFFDEVICE3

    RTS

