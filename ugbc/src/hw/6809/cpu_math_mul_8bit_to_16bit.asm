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

CPUMATHMUL8BITTO16BIT_SIGNED
    PSHS  D
    EORA  1,S
    STA   1,S
    LDA   ,S+
    BPL   CPUMATHMUL8BITTO16BIT_SIGNED1
    NEGA
CPUMATHMUL8BITTO16BIT_SIGNED1
    TSTB
    BPL   CPUMATHMUL8BITTO16BIT_SIGNED2
    NEGB
CPUMATHMUL8BITTO16BIT_SIGNED2
    MUL
    TST   ,S+
    BPL   CPUMATHMUL8BITTO16BIT_SIGNED3
    NEGA
    NEGB
    SBCA  #0
CPUMATHMUL8BITTO16BIT_SIGNED3
    RTS
