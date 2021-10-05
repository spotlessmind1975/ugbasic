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

CPUMEMMOVE
    CMPB #0
    BEQ CPUMEMMOVEDONE
    PSHS B
    ANDB #$80
    BEQ CPUMEMMOVEL2
    LDB #$7F
    DECB
CPUMEMMOVEL1
    LDA B,Y
    STA B,X
    DECB
    CMPB #$FF
    BNE %s
    LEAY 127,Y
    LEAX 127,X
    LEAY 1,Y
    LEAX 1,X
CPUMEMMOVEL2
    PULS B
    ANDB #$7F
    BEQ CPUMEMMOVEDONE
    DECB
CPUMEMMOVEL3
    LDA B,Y
    STA B,X
    DECB
    CMPB #$FF
    BNE CPUMEMMOVEL3
CPUMEMMOVEDONE
    RTS