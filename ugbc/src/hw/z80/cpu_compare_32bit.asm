; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                             COMPARE (32 BIT) Z80                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; [DE] = [HL] ?
;   true = IY, false = IX
CPUCOMPARE32:
    LD A, (DE)
    CP (HL)
    JR NZ, CPUCOMPARE32F
    INC DE
    INC HL
    LD A, (DE)
    CP (HL)
    JR NZ, CPUCOMPARE32F
    INC DE
    INC HL
    LD A, (DE)
    CP (HL)
    JR NZ, CPUCOMPARE32F
    INC DE
    INC HL
    LD A, (DE)
    CP (HL)
    JR NZ, CPUCOMPARE32F
    LD A, IXH
    RET
CPUCOMPARE32F:
    LD A, IXL
    RET

CPUCOMPARE32CONST:
    LD A, E
    CP (HL)
    JR NZ, CPUCOMPARE32FCONST
    INC HL
    LD A, D
    CP (HL)
    JR NZ, CPUCOMPARE32FCONST
    INC HL
    LD A, IYL
    CP (HL)
    JR NZ, CPUCOMPARE32FCONST
    INC HL
    LD A, IYH
    CP (HL)
    JR NZ, CPUCOMPARE32FCONST
    LD A, IXH
    RET
CPUCOMPARE32FCONST:
    LD A, IXL
    RET
