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
;*                          INTERNAL VARIABLES FOR VDC                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTVBASE:
    DW $0000,$0050,$00a0,$00f0,$0140,$0190,$01e0,$0230,
    DW $0280,$02d0,$0320,$0370,$03c0,$0410,$0460,$04b0,
    DW $0500,$0550,$05a0,$05f0,$0640,$0690,$06e0,$0730,
    DW $0780,$07d0,$0820,$0870,$08c0,$0910,$0960,$09b0,
    DW $0a00,$0a50,$0aa0,$0af0,$0b40,$0b90,$0be0,$0c30,
    DW $0c80,$0cd0,$0d20,$0d70,$0dc0,$0e10,$0e60,$0eb0,
    DW $0f00,$0f50,$0fa0,$0ff0,$1040,$1090,$10e0,$1130,
    DW $1180,$11d0,$1220,$1270,$12c0,$1310,$1360,$13b0,
    DW $1400,$1450,$14a0,$14f0,$1540,$1590,$15e0,$1630,
    DW $1680,$16d0,$1720,$1770,$17c0,$1810,$1860,$18b0,

PLOTORBIT
    DW %10000000
    DW %01000000
    DW %00100000
    DW %00010000
    DW %00001000
    DW %00000100
    DW %00000010
    DW %00000001

PLOTANDBIT
    DW %01111111
    DW %10111111
    DW %11011111
    DW %11101111
    DW %11110111
    DW %11111011
    DW %11111101
    DW %11111110

; Calculate the address of the pixel 
; and the relative bitmap
;
; input:
;   DE      = x
;   IY      = y
;
; output:
;   HL      = address
;   B       = bitmap OR
;   C       = bitmap AND
VCDZPOS:
    PUSH AF
    PUSH DE

    LD A, E
    AND $7
    LD E, A
    LD A, 0
    LD D, A

    LD HL, PLOTORBIT
    ADD HL, DE
    LD A, (HL)
    LD B, A

    LD HL, PLOTANDBIT
    ADD HL, DE
    LD A, (HL)
    LD C, A

    LD A, IYL
    LD E, A
    LD A, 0
    LD D, A
    LD HL, DE
    ADD HL, HL
    LD DE, HL
    LD HL, PLOTVBASE
    ADD HL, DE

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A

    LD HL, DE

    POP DE

    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E

    ADD HL, DE

    POP AF
    RET
