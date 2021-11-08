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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUMATHDIV32BITTO16BIT_SOURCEX       =   MATHPTR4 ; MATHPTR5
CPUMATHDIV32BITTO16BIT_SOURCEY       =   MATHPTR2 ; MATHPTR3
CPUMATHDIV32BITTO16BIT_DESTINATION   =   MATHPTR0 ; MATHPTR1

CPUMATHDIV32BITTO16BIT:
    SEC
    LDA CPUMATHDIV32BITTO16BIT_SOURCEY
    SBC CPUMATHDIV32BITTO16BIT_DESTINATION
    LDA CPUMATHDIV32BITTO16BIT_SOURCEY+1
    SBC CPUMATHDIV32BITTO16BIT_DESTINATION+1
    
    BCS CPUMATHDIV32BITTO16BIT2
    LDX #$11
CPUMATHDIV32BITTO16BIT3:
    ROL CPUMATHDIV32BITTO16BIT_SOURCEX
    ROL CPUMATHDIV32BITTO16BIT_SOURCEX+1
    DEX
    BEQ CPUMATHDIV32BITTO16BIT4
    
    ROL CPUMATHDIV32BITTO16BIT_SOURCEY
    ROL CPUMATHDIV32BITTO16BIT_SOURCEY+1
    STA MATHPTR7
    ROL MATHPTR8
    SEC
    LDA CPUMATHDIV32BITTO16BIT_SOURCEY
    SBC CPUMATHDIV32BITTO16BIT_DESTINATION
    STA MATHPTR6
    LDA MATHPTR3
    SBC CPUMATHDIV32BITTO16BIT_DESTINATION+1
    TAY
    LDA MATHPTR8
    SBC #0
    BCC CPUMATHDIV32BITTO16BIT3
    LDA MATHPTR6
    STA CPUMATHDIV32BITTO16BIT_SOURCEY
    STY CPUMATHDIV32BITTO16BIT_SOURCEY+1
    JMP CPUMATHDIV32BITTO16BIT3

CPUMATHDIV32BITTO16BIT2:
    LDA #$ff
    STA CPUMATHDIV32BITTO16BIT_SOURCEY
    STA CPUMATHDIV32BITTO16BIT_SOURCEY+1
    STA CPUMATHDIV32BITTO16BIT_SOURCEX
    STA CPUMATHDIV32BITTO16BIT_SOURCEX+1
CPUMATHDIV32BITTO16BIT4:
    RTS
