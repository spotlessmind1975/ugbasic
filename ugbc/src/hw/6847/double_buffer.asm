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
;*                        DOUBLE BUFFER ROUTINE ON 6847                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DOUBLEBUFFERINIT

    LDA #1
    STA DOUBLEBUFFERENABLED
    JSR SWITCHSCREEN0
    JSR CLSG
    JSR SWITCHSCREEN1
    JSR CLSG
    JSR SWITCHSCREEN0
    RTS

DOUBLEBUFFERCLEANUP
    LDD #$0400
    STD BITMAPADDRESS
    CLRA
    STA DOUBLEBUFFERENABLED
DOUBLEBUFFERCLEANUP2
    LDA #$0
    STA SCREENVISIBLE
    RTS

SWITCHSCREEN
    LDA SCREENVISIBLE
    BEQ SWITCHSCREEN1

SWITCHSCREEN0
    STA $FFC6
    STA $FFC8
    STA $FFCA
    STA $FFCC
    STA $FFCE
    STA $FFD0
    STA $FFD2
    STA $FFC9
    LDD #$1C00
    STD BITMAPADDRESS
    LDA #$0
    STA SCREENVISIBLE
    LDD #$1800
    LDY #$0400
    LDX #$1C00
    JSR DUFFDEVICE
    RTS

SWITCHSCREEN1
    STA $FFC6
    STA $FFC8
    STA $FFCA
    STA $FFCC
    STA $FFCE
    STA $FFD0
    STA $FFD2
    STA $FFC9
    STA $FFCB
    STA $FFCD
    LDD #$0400
    STD BITMAPADDRESS
    LDA #$1
    STA SCREENVISIBLE
    LDD #$1800
    LDY #$1C00
    LDX #$0400
    JSR DUFFDEVICE
    RTS
    