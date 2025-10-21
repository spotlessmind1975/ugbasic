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
;*                          IMAGES ROUTINE FOR CGA                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Put image on bitmap
; ----------------------------------------------------------------------------

; HL : image data
; D : y
; E : x
PUTIMAGE:
    
@IF !vestigialConfig.screenModeUnique

    LD A, (CURRENTMODE)
    CP 9
    JR Z, PUTIMAGE9
    RET

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 0) )

PUTIMAGE0:
    RET

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( (currentMode == 9) )

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
PUTIMAGE9:
    
    PUSH HL
    LD HL, (BITMAPADDRESS)
    PUSH DE
    LD A, D
    LD E, A
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE
    POP DE
    LD D, 0
    SLA E
    RL D
    SLA E
    RL D
    ADD HL, DE
    LD DE, HL
    POP HL

    JMP PUTIMAGECOMMONC

@ENDIF

PUTIMAGECOMMONC:

    LD A, (HL)
    INC HL
    SRL A
    SRL A
    CP 0
    JR NZ, PUTIMAGECL0
    LD A, 64
PUTIMAGECL0:
    LD B, A
    LD A, (HL)
    INC HL
    LD C, A
    LD IXL, A

    INC HL

    PUSH BC
PUTIMAGE2CL1:
    LD A, (IMAGEF)
    AND 32
    CP 0 
    JR Z, PUTIMAGE2CL1DEF

PUTIMAGE2YTRANS3L1:
    LD A, 0
    LD IXH, A
    LD A, (HL)
    ; 00 01 10 00
    AND $C0
    ; -> 00 00 00 00
    CP 0
    JR Z, PUTIMAGE2YTRANS3L1P4X
    LD A, IXH
    OR $C0
    LD IXH, A
PUTIMAGE2YTRANS3L1P4X:
    LD A, (HL)
    ; 00 01 10 00
    AND $30
    ; -> 00 01 00 00
    CP 0
    JR Z, PUTIMAGE2YTRANS3L1P3X
    LD A, IXH
    OR $30
    ; MATH PTR = 00 11 00 00
    LD IXH, A
PUTIMAGE2YTRANS3L1P3X:
    LD A, (HL)
    ; 00 01 10 00
    AND $0C
    ; -> 00 00 00 00
    CP 0
    JR Z, PUTIMAGE2YTRANS3L1P2X
    LD A, IXH
    OR $0C
    LD IXH, A
PUTIMAGE2YTRANS3L1P2X:
    LD A, (HL)
    ; 00 01 10 00
    AND $03
    ; -> 00 01 00 00
    JR Z, PUTIMAGE2YTRANS3L1P1X
    LD A, IXH
    OR $03
    ; MATH PTR = 00 11 00 00
    LD IXH, A
PUTIMAGE2YTRANS3L1P1X:
    LD A, IXH
    ; 00 11 11 00
    XOR $FF
    ; 11 00 00 11
    LD IYH, A
    LD A, (DE)
    ; 00 00 00 00
    AND IYH
    LD IYH, A
    ; 00 00 00 00
    LD A, (DE)
    AND IXH
    OR IYH
    JMP PUTIMAGE2CL1FINAL

PUTIMAGE2CL1DEF:
    LD A, (HL)
PUTIMAGE2CL1FINAL:
    LD (DE), A
    INC HL
    INC DE
    DEC B
    JR NZ, PUTIMAGE2CL1

    LD A, (IMAGEF)
    AND 64
    CP 0
    JR Z, PUTIMAGE2CL1N

    LD A, (IMAGEF)
    AND 1
    CP 1
    JR Z, PUTIMAGE2CL1N0

    OR 65
    LD (IMAGEF), A

    POP BC

    PUSH HL
    LD HL, DE
    LD A, (CURRENTSL)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD A, B
    LD E, A
    LD D, 0
    CALL SUB_HL_DE
    LD DE, HL
    POP HL

    PUSH BC
    JMP PUTIMAGE2CL1

PUTIMAGE2CL1N0:
    LD A, (IMAGEF)
    AND $FE
    LD (IMAGEF), A

PUTIMAGE2CL1N:
    POP BC

    PUSH HL
    LD HL, DE
    LD A, (CURRENTSL)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD A, B
    LD E, A
    LD D, 0
    CALL SUB_HL_DE
    LD DE, HL
    POP HL

    DEC C
    LD A, C
    CP 0
    JR Z, PUTIMAGECOMMONCE

    PUSH BC
    JMP PUTIMAGE2CL1

PUTIMAGECOMMONCE:
    RET
