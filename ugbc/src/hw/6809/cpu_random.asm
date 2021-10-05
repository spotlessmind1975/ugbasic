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

CPURANDOMSEED              equ MATHPTR0; MATHPTR1 MATHPTR2 MATHPTR2
CPURANDOMENTROPY           equ MATHPTR3
CPURANDOMINTERNALSEED      fcb $42, $45, $20, $21

CPURANDOM0
    LDD CPURANDOMINTERNALSEED
    STD CPURANDOMSEED
    LDD CPURANDOMINTERNALSEED+2
    STD CPURANDOMSEED+2
CPURANDOM
    LDD CPURANDOMSEED
    ASLB
    ASLB
    ROLA
    ADDD CPURANDOMSEED+2
    LSR CPURANDOMSEED
    ROR CPURANDOMSEED+1
    ASLB
    ROLA
    ADDA PATTERN ; (entropy)
    ASLB
    ROLA
    ASLB
    ROLA
    ADDD CPURANDOMSEED+1
    STD CPURANDOMSEED+1

    LDD CPURANDOMSEED
    STD CPURANDOMINTERNALSEED
    LDD CPURANDOMSEED+2    
    STD CPURANDOMINTERNALSEED+2
    RTS