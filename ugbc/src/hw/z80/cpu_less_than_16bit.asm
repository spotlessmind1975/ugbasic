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
;*                            lESS THAN (16 BIT) Z80                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Is DE < HL ? (signed)
;   A : $ff if true, $00 if false
CPULT16S:
    LD A, H
    XOR D
    JP M, CPULT16STE2
    SBC HL, DE
    JR Z, CPULT16STE1
    JR NC, CPULT16STE3
CPULT16STE1:
    LD A, $00
    RET
CPULT16STE2:
    BIT 7, D
    JR Z, CPULT16STE1
CPULT16STE3:
    LD A, $ff
    RET

CPULT16U:
    LD A, H
    LD B, A
    LD A, D
    CP B
    JR Z, CPULT16U2
    JR C, CPULT16UL
    JR CPULT16UL0
CPULT16U2:
    LD A, L
    LD B, A
    LD A, E
    CP B
    JR C, CPULT16UL
CPULT16UL0:
    LD A, $00
    RET
CPULT16UL:
    LD A, $ff
    RET

CPULTE16S:
    LD A, H
    XOR D
    JP M, CPULTE16S2
    SBC HL, DE
    JR Z, CPULTE16S3
    JR NC, CPULTE16S3 
CPULTE16S1:
    LD A, $00
    RET
CPULTE16S2:
    BIT 7, D
    JR Z, CPULTE16S1
CPULTE16S3:
    LD A, $ff
    RET

CPULTE16U:
    LD A, H
    LD B, A
    LD A, D
    CP B
    JR Z, CPULTE16U2
    JR C, CPULTE16UL
    JR CPULTE16UL0
CPULTE16U2:
    LD A, L
    LD B, A
    LD A, E
    CP B
    JR C, CPULTE16UL
    JR Z, CPULTE16UL
CPULTE16UL0:
    LD A, $00
    RET
CPULTE16UL:
    LD A, $ff
    RET
