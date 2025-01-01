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
;*                             FILL AREA ON 6502                               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUFILL8:
    CPX #0
    BEQ CPUFILLX
    LDY #0
CPUFILL2:
    STA (TMPPTR),Y
    INY
    DEX
    BNE CPUFILL2
CPUFILLX:
    RTS

CPUFILL16:
    PHA
    LDA MATHPTR0+1
    BNE CPUFILL16OK
    LDA MATHPTR0
    BNE CPUFILL16OK
    PLA
    RTS

CPUFILL16OK:
    PLA
    LDY #0
CPUFILL16LP:
    STA (TMPPTR),Y
    INC TMPPTR
    BNE CPUFILL16LP0
    INC TMPPTR+1
CPUFILL16LP0:
    PHA
    DEC MATHPTR0
    LDA MATHPTR0
    CMP #$FF
    BNE CPUFILL16LP1
    DEC MATHPTR0+1
    LDA MATHPTR0+1
    CMP #$FF
    BNE CPUFILL16LP1
    PLA
    RTS
CPUFILL16LP1:
    PLA
    JMP CPUFILL16LP
