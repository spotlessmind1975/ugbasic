; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPURANDOM_SEED:              .BYTE $42, $45, $20, $21
CPURANDOM_ENTROPY           = MATHPTR3

CPURANDOM32:
    ASL CPURANDOM_SEED
    ROL CPURANDOM_SEED+1
    ROL CPURANDOM_SEED+2
    ROL CPURANDOM_SEED+3
    BCC CPURANDOM2
    LDA CPURANDOM_SEED
    EOR CPURANDOM_ENTROPY
    STA CPURANDOM_SEED
    LDA CPURANDOM_SEED+1
    EOR #$1D
    STA CPURANDOM_SEED+1
    LDA CPURANDOM_SEED+2
    EOR #$C1
    STA CPURANDOM_SEED+2
    LDA CPURANDOM_SEED+3
    EOR #$04
    STA CPURANDOM_SEED+3
CPURANDOM2:
    RTS

CPURANDOM16:
    ASL CPURANDOM_SEED
    ROL CPURANDOM_SEED+1
    BCC CPURANDOM162
    LDA CPURANDOM_SEED
    EOR CPURANDOM_ENTROPY
    STA CPURANDOM_SEED
    LDA CPURANDOM_SEED+1
    EOR #$1D
    STA CPURANDOM_SEED+1
CPURANDOM162:
    RTS
    