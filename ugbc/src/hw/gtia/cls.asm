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
;*                      CLEAR SCREEN ROUTINE FOR GTIA                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLS:

    LDA CURRENTMODE
    CMP #8
    BEQ CLSANTIC8
    ; CMP #9
    ; BEQ PLOTANTIC9
    ; CMP #10
    ; BEQ PLOTANTIC10
    ; CMP #11
    ; BEQ PLOTANTIC11
    ; CMP #13
    ; BEQ PLOTANTIC13
    ; CMP #15
    ; BEQ PLOTANTIC15
    ; CMP #12
    ; BEQ PLOTANTIC12
    ; CMP #14
    ; BEQ PLOTANTIC14
    RTS
    
CLSANTIC8:
    LDA _PAPER
    STA $02C5
    LDA BITMAPADDRESS
    STA COPYOFBITMAPADDRESS
    LDA BITMAPADDRESS+1
    STA COPYOFBITMAPADDRESS+1
    LDY #0
    LDA TMPPTR
CLSANTIC8GC:
    STA (COPYOFBITMAPADDRESS),Y
    INY
    CPY #200
    BNE CLSANTIC8GC
    RTS
