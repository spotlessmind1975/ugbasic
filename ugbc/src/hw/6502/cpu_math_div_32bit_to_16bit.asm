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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUMATHDIV32CARRY:  .BYTE   0

CPUMATHDIV32BITTO16BIT:
    SEC             
    LDA MATHPTR2
    SBC MATHPTR0
    LDA MATHPTR3
    SBC MATHPTR1
    BCS CPUMATHDIV32BITTO16BITL2  
    LDX #$11
CPUMATHDIV32BITTO16BITL4:
    ROL MATHPTR4
    ROL MATHPTR5
    DEX
    BEQ CPUMATHDIV32BITTO16BITL6
    ROL MATHPTR2
    ROL MATHPTR3
    PHA
    LDA #0
    STA CPUMATHDIV32CARRY
    PLA
    ROL CPUMATHDIV32CARRY
    SEC
    LDA MATHPTR2
    SBC MATHPTR0
    STA MATHPTR6
    LDA MATHPTR3
    SBC MATHPTR1
    TAY
    LDA CPUMATHDIV32CARRY
    SBC #0
    BCC CPUMATHDIV32BITTO16BITL4
    LDA MATHPTR6
    STA MATHPTR2
    STY MATHPTR3
    JMP CPUMATHDIV32BITTO16BITL4
  CPUMATHDIV32BITTO16BITL2: 
    LDA #$FF
    STA MATHPTR2
    STA MATHPTR3
    STA MATHPTR4
    STA MATHPTR5
CPUMATHDIV32BITTO16BITL6:	
    RTS
