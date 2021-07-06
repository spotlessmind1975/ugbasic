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
;*                      FILL BACKGROUND COLOR SCREEN  FOR VIC-II               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BACK:
    LDA $D011
    AND #$20
    BEQ BACKT
    JMP BACKG
    
BACKG:
    SEI
    LDA #$36
    STA $01
    LDA COLORMAPADDRESS
    STA $25
    LDA COLORMAPADDRESS+1
    STA $26
    LDX #3
    LDY #0
BACKGC:
    LDA ($25),Y
    AND #$F0
    ORA _PAPER
    STA ($25),Y
    INY
    BNE BACKGC
    INC $26
    CPX #1
    BNE BACKGCNB
BACKGC2:
    LDA ($25),Y
    AND #$F0
    ORA _PAPER
    STA ($25),Y
    INY
    CPY #232
    BNE BACKGC2
BACKGCNB:
    DEX
    BNE BACKGC
    LDA #$37
    STA $01
    CLI

    RTS

BACKT:
    LDA _PAPER
    STA $d021
    RTS
