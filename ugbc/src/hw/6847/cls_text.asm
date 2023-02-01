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
;*                       CLEAR SCREEN ROUTINE FOR 6847                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLST
    LDA CURRENTMODE
    CMPA #0
    BNE CLS0X
    JMP CLS0
CLS0X
    CMPA #1
    BNE CLS1X
    JMP CLS1
CLS1X
    CMPA #2
    BNE CLS2X
    JMP CLS2
CLS2X
    CMPA #3
    BNE CLS3X
    JMP CLS3
CLS3X
    CMPA #4
    BNE CLS4X
    JMP CLS4
CLS4X
    CMPA #5
    BNE CLS5X
    JMP CLS5
CLS5X
    CMPA #6
    BNE CLS6X
    JMP CLS6
CLS6X
    RTS

CLS0
CLS1
CLS2
CLS3
CLS4
CLS5
CLS6
CLST2
    LDY TEXTADDRESS
    LDX CURRENTFRAMESIZE
    LDA EMPTYTILE
CLST3
    STA , Y+
    LEAX -1, X
    CMPX #0
    BNE CLST3

    RTS
