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
    DEFW $0000,$0050,$00a0,$00f0,$0140,$0190,$01e0,$0230
    DEFW $0280,$02d0,$0320,$0370,$03c0,$0410,$0460,$04b0
    DEFW $0500,$0550,$05a0,$05f0,$0640,$0690,$06e0,$0730
    DEFW $0780,$07d0,$0820,$0870,$08c0,$0910,$0960,$09b0
    DEFW $0a00,$0a50,$0aa0,$0af0,$0b40,$0b90,$0be0,$0c30
    DEFW $0c80,$0cd0,$0d20,$0d70,$0dc0,$0e10,$0e60,$0eb0
    DEFW $0f00,$0f50,$0fa0,$0ff0,$1040,$1090,$10e0,$1130
    DEFW $1180,$11d0,$1220,$1270,$12c0,$1310,$1360,$13b0
    DEFW $1400,$1450,$14a0,$14f0,$1540,$1590,$15e0,$1630
    DEFW $1680,$16d0,$1720,$1770,$17c0,$1810,$1860,$18b0
    DEFW $1900,$1950,$19a0,$19f0,$1a40,$1a90,$1ae0,$1b30
    DEFW $1b80,$1bd0,$1c20,$1c70,$1cc0,$1d10,$1d60,$1db0
    DEFW $1e00,$1e50,$1ea0,$1ef0,$1f40,$1f90,$1fe0,$2030
    DEFW $2080,$20d0,$2120,$2170,$21c0,$2210,$2260,$22b0
    DEFW $2300,$2350,$23a0,$23f0,$2440,$2490,$24e0,$2530
    DEFW $2580,$25d0,$2620,$2670,$26c0,$2710,$2760,$27b0
    DEFW $2800,$2850,$28a0,$28f0,$2940,$2990,$29e0,$2a30
    DEFW $2a80,$2ad0,$2b20,$2b70,$2bc0,$2c10,$2c60,$2cb0
    DEFW $2d00,$2d50,$2da0,$2df0,$2e40,$2e90,$2ee0,$2f30
    DEFW $2f80,$2fd0,$3020,$3070,$30c0,$3110,$3160,$31b0
    DEFW $3200,$3250,$32a0,$32f0,$3340,$3390,$33e0,$3430
    DEFW $3480,$34d0,$3520,$3570,$35c0,$3610,$3660,$36b0
    DEFW $3700,$3750,$37a0,$37f0,$3840,$3890,$38e0,$3930
    DEFW $3980,$39d0,$3a20,$3a70,$3ac0,$3b10,$3b60,$3bb0
    DEFW $3c00,$3c50,$3ca0,$3cf0,$3d40,$3d90,$3de0,$3e30

PLOTORBIT:
    DEFB %10000000
    DEFB %01000000
    DEFB %00100000
    DEFB %00010000
    DEFB %00001000
    DEFB %00000100
    DEFB %00000010
    DEFB %00000001

PLOTANDBIT:
    DEFB %01111111
    DEFB %10111111
    DEFB %11011111
    DEFB %11101111
    DEFB %11110111
    DEFB %11111011
    DEFB %11111101
    DEFB %11111110

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
