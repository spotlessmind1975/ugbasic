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
        DEFW $3e80,$3ed0,$3f20,$3f70,$3fc0,$4010,$4060,$40b0
        DEFW $4100,$4150,$41a0,$41f0,$4240,$4290,$42e0,$4330
        DEFW $4380,$43d0,$4420,$4470,$44c0,$4510,$4560,$45b0
        DEFW $4600,$4650,$46a0,$46f0,$4740,$4790,$47e0,$4830
        DEFW $4880,$48d0,$4920,$4970,$49c0,$4a10,$4a60,$4ab0
        DEFW $4b00,$4b50,$4ba0,$4bf0,$4c40,$4c90,$4ce0,$4d30
        DEFW $4d80,$4dd0,$4e20,$4e70,$4ec0,$4f10,$4f60,$4fb0
        DEFW $5000,$5050,$50a0,$50f0,$5140,$5190,$51e0,$5230
        DEFW $5280,$52d0,$5320,$5370,$53c0,$5410,$5460,$54b0
        DEFW $5500,$5550,$55a0,$55f0,$5640,$5690,$56e0,$5730
        DEFW $5780,$57d0,$5820,$5870,$58c0,$5910,$5960,$59b0
        DEFW $5a00,$5a50,$5aa0,$5af0,$5b40,$5b90,$5be0,$5c30
        DEFW $5c80,$5cd0,$5d20,$5d70,$5dc0,$5e10,$5e60,$5eb0
        DEFW $5f00,$5f50,$5fa0,$5ff0,$6040,$6090,$60e0,$6130
        DEFW $6180,$61d0,$6220,$6270,$62c0,$6310,$6360,$63b0
        DEFW $6400,$6450,$64a0,$64f0,$6540,$6590,$65e0,$6630
        DEFW $6680,$66d0,$6720,$6770,$67c0,$6810,$6860,$68b0
        DEFW $6900,$6950,$69a0,$69f0,$6a40,$6a90,$6ae0,$6b30
        DEFW $6b80,$6bd0,$6c20,$6c70,$6cc0,$6d10,$6d60,$6db0
        DEFW $6e00,$6e50,$6ea0,$6ef0,$6f40,$6f90,$6fe0,$7030
        DEFW $7080,$70d0,$7120,$7170,$71c0,$7210,$7260,$72b0
        DEFW $7300,$7350,$73a0,$73f0,$7440,$7490,$74e0,$7530
        DEFW $7580,$75d0,$7620,$7670,$76c0,$7710,$7760,$77b0
        DEFW $7800,$7850,$78a0,$78f0,$7940,$7990,$79e0,$7a30
        DEFW $7a80,$7ad0,$7b20,$7b70,$7bc0,$7c10,$7c60,$7cb0

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
    LD A, IYH
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

    LD A, (CURRENTMODE)
    AND $2
    CP $2

    JR NZ, VDCZPOSDONE

    PUSH DE
    PUSH IY
    DI
    EXX
    EI
    POP IY
    POP DE

    LD A, IYL
    LD E, A
    LD A, IYH
    LD D, A
    LD HL, DE
    ADD HL, HL
    LD DE, HL
    LD HL, PLOTVBASE
    ADD HL, DE
    LD DE, $3700
    ADD HL, DE

    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E

    ADD HL, DE

    DI
    EXX
    EI

VDCZPOSDONE:
    POP AF
    RET
