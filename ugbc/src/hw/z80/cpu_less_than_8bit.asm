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
;*                            lESS THAN (8 BIT) Z80                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Is A < B ? (signed)
;   A : $ff if true, $00 if false
CPULT8S:
    SUB A, B
    JP PO, CPULT8SNX
    XOR $80
CPULT8SNX:
    JP M, CPULT8ST
    JP PE, CPULT8SF
CPULT8SF:
    LD A, $00
    RET
CPULT8ST:
    LD A, $ff
    RET

; Is A < B ? (unsigned)
;   A : $ff if true, $00 if false
CPULT8U:
    CP B
    JR C, CPULT8UT
    LD A, $00
    RET
CPULT8UT:
    LD A, $ff
    RET

; Is A <= B ? (signed)
;   A : $ff if true, $00 if false
CPULTE8S:
    SUB A, B
    JP  Z, CPULTE8ST
    JP PO, CPULTE8SNX
    XOR $80
CPULTE8SNX:    
    JP M, CPULTE8ST
    JP PE, CPULTE8SF
CPULTE8SF:    
    LD A, $00
    RET
CPULTE8ST:    
    LD A, $ff
    RET

; Is A <= B ? (unsigned)
;   A : $ff if true, $00 if false
CPULTE8U:
    CP B
    JR C, CPULTE8UT
    JR Z, CPULTE8UT
    LD A, $00
    RET
CPULTE8UT:
    LD A, $ff
    RET
