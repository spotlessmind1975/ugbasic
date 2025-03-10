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
;*                          INTERNAL VARIABLES FOR CPC                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLOTVBASE:
    DW $C000, $C800, $D000, $D800, $E000, $E800, $F000, $F800
    DW $C050, $C850, $D050, $D850, $E050, $E850, $F050, $F850
    DW $C0A0, $C8A0, $D0A0, $D8A0, $E0A0, $E8A0, $F0A0, $F8A0
    DW $C0F0, $C8F0, $D0F0, $D8F0, $E0F0, $E8F0, $F0F0, $F8F0
    DW $C140, $C940, $D140, $D940, $E140, $E940, $F140, $F940
    DW $C190, $C990, $D190, $D990, $E190, $E990, $F190, $F990
    DW $C1E0, $C9E0, $D1E0, $D9E0, $E1E0, $E9E0, $F1E0, $F9E0
    DW $C230, $CA30, $D230, $DA30, $E230, $EA30, $F230, $FA30
    DW $C280, $CA80, $D280, $DA80, $E280, $EA80, $F280, $FA80
    DW $C2D0, $CAD0, $D2D0, $DAD0, $E2D0, $EAD0, $F2D0, $FAD0
    DW $C320, $CB20, $D320, $DB20, $E320, $EB20, $F320, $FB20
    DW $C370, $CB70, $D370, $DB70, $E370, $EB70, $F370, $FB70
    DW $C3C0, $CBC0, $D3C0, $DBC0, $E3C0, $EBC0, $F3C0, $FBC0
    DW $C410, $CC10, $D410, $DC10, $E410, $EC10, $F410, $FC10
    DW $C460, $CC60, $D460, $DC60, $E460, $EC60, $F460, $FC60
    DW $C4B0, $CCB0, $D4B0, $DCB0, $E4B0, $ECB0, $F4B0, $FCB0
    DW $C500, $CD00, $D500, $DD00, $E500, $ED00, $F500, $FD00
    DW $C550, $CD50, $D550, $DD50, $E550, $ED50, $F550, $FD50
    DW $C5A0, $CDA0, $D5A0, $DDA0, $E5A0, $EDA0, $F5A0, $FDA0
    DW $C5F0, $CDF0, $D5F0, $DDF0, $E5F0, $EDF0, $F5F0, $FDF0
    DW $C640, $CE40, $D640, $DE40, $E640, $EE40, $F640, $FE40
    DW $C690, $CE90, $D690, $DE90, $E690, $EE90, $F690, $FE90
    DW $C6E0, $CEE0, $D6E0, $DEE0, $E6E0, $EEE0, $F6E0, $FEE0
    DW $C730, $CF30, $D730, $DF30, $E730, $EF30, $F730, $FF30
    DW $C780, $CF80, $D780, $DF80, $E780, $EF80, $F780, $FF80

@IF vestigialConfig.palettePreserve

PALETTEPRESERVE:
    DB $00, $00

PALETTEPRESERVEMASK:
    DB $01, $02, $04, $08, $10, $20, $40, $80

; Check if color has been used.
;   IXL = color to look for
CPCPALETTEPRESERVECHECK:
    PUSH HL
    PUSH DE

    LD A, IXL
    AND $7
    LD HL, PALETTEPRESERVEMASK
    LD D, 0
    LD E, A
    ADD HL, DE
    LD A, (HL)
    LD B, A

    LD A, IXL
    AND $08
    CP $00
    JR Z, CPCPALETTEPRESERVECHECKLOWER

CPCPALETTEPRESERVECHECKHIGHER:
    LD A, (PALETTEPRESERVE+1)
    AND B
    JR CPCPALETTEPRESERVECHECKFINAL
    PUSH AF
    LD A, (PALETTEPRESERVE+1)
    OR B
    LD (PALETTEPRESERVE+1), A
    POP AF

CPCPALETTEPRESERVECHECKLOWER:
    LD A, (PALETTEPRESERVE)
    AND B
    PUSH AF
    LD A, (PALETTEPRESERVE)
    OR B
    LD (PALETTEPRESERVE), A
    POP AF

CPCPALETTEPRESERVECHECKFINAL:

    POP DE
    POP HL
    RET

@ENDIF

; Look for a specific color into the palette.
;   input: IXL = color to look for
;   output: IXH = index of ink, $FF if not found
CPCLOOKFORPALETTE:
    PUSH BC
    PUSH HL
    PUSH AF
    PUSH DE
    LD HL, PALETTE
    LD A, 0
    LD C, A
    LD A, IXL
    LD B, A
    ; INC C
    ; INC HL
CPCLOOKFORPALETTEL1:
    LD A, (HL)
    CP B
    JR Z, CPCLOOKFORPALETTEFOUND
    INC HL
    INC C
    LD A, (PALETTELIMIT)
    LD E, A
    LD A, C
    CP E
    JR C, CPCLOOKFORPALETTEL1
    JR NZ, CPCLOOKFORPALETTEL1
    LD A, $FF
    LD C, A
CPCLOOKFORPALETTEFOUND:
    POP DE
    POP AF
    POP HL
    LD A, C
    CALL CPCPALETTESETUSED
    LD IXH, A
    POP BC
    RET

CPCPALETTEFINDUNUSED:
    LD A, (PALETTEUSED)
    LD B, A
    LD A, 0
CPCPALETTEFINDUNUSEDL1:
    SRL B
    JR NC, CPCPALETTEFINDUNUSEDDONE
    INC A
    CMP 8
    JR NZ, CPCPALETTEFINDUNUSEDL1
    LD A, (PALETTEUSED+1)
    LD B, A
    LD A, 8
CPCPALETTEFINDUNUSEDL2:
    SRL B
    JR NC, CPCPALETTEFINDUNUSEDDONE
    INC A
    CMP 16
    JR NZ, CPCPALETTEFINDUNUSEDL2
    LD A, $FF
CPCPALETTEFINDUNUSEDDONE:
    RET

CPCPALETTESETUSED:
    PUSH AF
    PUSH BC
    CP 8
    JR NC, CPCPALETTESETUSED8
    PUSH AF
    LD A, (PALETTEUSED)
    LD B, A
    POP AF
    LD C, 1
    CP 0
    JR Z, CPCPALETTESETUSEDDONE
CPCPALETTESETUSEDL1:
    SLA C
    DEC A
    JR NZ, CPCPALETTESETUSEDL1
CPCPALETTESETUSEDDONE:
    LD A, (PALETTEUSED)
    OR C
    LD (PALETTEUSED), A
    POP BC
    POP AF
    RET
CPCPALETTESETUSED8:
    SUB 8
    PUSH AF
    LD A, (PALETTEUSED+1)
    LD B, A
    POP AF
    LD C, 1
    CP 0
    JR Z, CPCPALETTESETUSEDDONE8
CPCPALETTESETUSEDL2:
    SLA C
    DEC A
    JR NZ, CPCPALETTESETUSEDL2
CPCPALETTESETUSEDDONE8:
    LD A, (PALETTEUSED+1)
    OR C
    LD (PALETTEUSED+1), A
    POP BC
    POP AF
    RET

; Insert a specific color into the palette.
;   input: IXL = color to insert
;   output: IXH = index of ink allocated
CPCINSERTPALETTE:
    PUSH BC
    PUSH HL
    PUSH DE
    PUSH AF
    LD A, IXL
    CP $FF
    JR Z, CPCINSERTPALETTEDONE
    ; LD A, (PALETTELIMIT)
    ; LD B, A
    ; LD A, (PALETTEUNUSED)
    ; INC A
    ; CP B
    ; JR C, CPCINSERTPALETTEUNDER
    ; LD A, 1
    CALL CPCPALETTEFINDUNUSED
    CP $FF
    JR Z, CPCINSERTPALETTEDONE
CPCINSERTPALETTEUNDER:
    CALL CPCPALETTESETUSED
    ; LD (PALETTEUNUSED), A
    LD IXH, A
    ; LD A, (PALETTEUNUSED)
    LD HL, PALETTE
    LD E, A
    LD A, 0
    LD D, A
    ADD HL, DE
    LD A, IXL
    LD (HL), A

    LD A, IYL
    CP $0
    JR Z, CPCINSERTPALETTEDONE

@IF vestigialConfig.palettePreserve
    CALL CPCPALETTEPRESERVECHECK
    CP $0
    JR NZ, CPCINSERTPALETTEDONE
@ENDIF
    CALL SETHWPALETTE

CPCINSERTPALETTEDONE:
    POP AF
    POP DE
    POP HL
    POP BC
    RET

; Update a specific color into the palette.
;   input: 
;           IXH = index of ink to update
;           IXL = color to update
;           IYL > 0 update ink on GATE ARRAY, also
CPCUPDATEPALETTE:
    PUSH AF
    PUSH HL
    PUSH DE
    LD A, IXL
    CP $FF
    JR Z, CPCUPDATEPALETTEDONE
    LD E, IXH
    LD A, 0
    LD D, A
    LD HL, PALETTE
    ADD HL, DE
    LD A, IXL

    LD (HL), A
    LD A, IXH
    CALL CPCPALETTESETUSED
    LD A, IYL
    CP $0
    JR Z, CPCUPDATEPALETTEDONE

@IF vestigialConfig.palettePreserve
    CALL CPCPALETTEPRESERVECHECK
    CP $0
    JR NZ, CPCUPDATEPALETTEDONE
@ENDIF
    CALL SETHWPALETTE

CPCUPDATEPALETTEDONE:

    POP DE
    POP HL
    POP AF
    RET

; Get a specific color from the palette.
;   input: 
;           IXH = index of ink
;   output: 
;           IXL = color
CPCGETPALETTE:
    PUSH AF
    PUSH HL
    PUSH DE
    LD E, IXH
    LD A, 0
    LD D, A
    LD HL, PALETTE
    ADD HL, DE
    LD A, (HL)
    LD IXL, A
    POP DE
    POP HL
    POP AF
    RET

; Look for a specific color into the palette and, if missing,
; insert it into palette.
;   input: 
;           IXL = color to look for / insert
;           IYL > 0 update ink on GATE ARRAY, also
;   output: 
;           IXH = index of ink
CPCSELECTPALETTE:
    CALL CPCLOOKFORPALETTE
    LD A, IXH
    CP $FF
    RET NZ
    CALL CPCINSERTPALETTE
    RET

; CPCVIDEOMUL8:
;     PUSH HL
;     PUSH DE
;     PUSH BC
;     LD E, A
;     LD A, B
;     LD H, A
;     LD D,0
;     LD L,D
;     LD B,8
; CPCVIDEOMUL8L1:
;     ADD HL, HL
;     JR NC, CPCVIDEOMUL8L1A
;     ADD HL, DE
; CPCVIDEOMUL8L1A:
;     DJNZ CPCVIDEOMUL8L1
;     LD A, L
;     POP BC
;     POP DE
;     POP HL
;     RET

CPCVIDEOMUL82:
    PUSH HL
    PUSH BC
    PUSH AF
    LD A, B
    AND $2
    CP $0
    JR Z, CPCVIDEOMUL82L0
CPCVIDEOMUL82L1:
    POP AF
    PUSH AF
    AND $F
    LD L, A
    POP AF
    JP CPCVIDEOMUL82H
CPCVIDEOMUL82L0:
    LD A, 0
    LD L, A
    POP AF
CPCVIDEOMUL82H:    
    PUSH AF
    LD A, B
    AND $1
    CP $0
    JR Z, CPCVIDEOMUL82H0
CPCVIDEOMUL82H1:
    POP AF
    PUSH AF
    SLA A
    SLA A
    SLA A
    SLA A
    LD H, A
    POP AF
    JP CPCVIDEOMUL82E
CPCVIDEOMUL82H0:
    LD A, 0
    LD H, A
    POP AF
CPCVIDEOMUL82E:
    POP BC
    LD A, H
    OR L
    POP HL
    RET

; 01 01 01 01 <- A
; kk kk kk kk
; dd bb cc aa <- B

CPCVIDEOMUL84:
    PUSH HL
    PUSH BC
    PUSH AF
    LD A, B
    AND $1
    CP $0
    JR Z, CPCVIDEOMUL84L0
CPCVIDEOMUL84L1:
    POP AF
    PUSH AF
    AND $3
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    SLA A
    LD L, A
    POP AF
    JP CPCVIDEOMUL84H
CPCVIDEOMUL84L0:
    LD A, 0
    LD L, A
    POP AF
CPCVIDEOMUL84H:    
    PUSH AF
    LD A, B
    AND $2
    CP $0
    JR Z, CPCVIDEOMUL84H0
CPCVIDEOMUL84H1:
    POP AF
    PUSH AF
    AND $3
    SLA A
    SLA A
    OR L
    LD L, A
    POP AF
    JP CPCVIDEOMUL84I
CPCVIDEOMUL84H0:
    POP AF
CPCVIDEOMUL84I:
    PUSH AF
    LD A, B
    AND $4
    CP $0
    JR Z, CPCVIDEOMUL84I0
CPCVIDEOMUL84I1:
    POP AF
    PUSH AF
    AND $3
    SLA A
    SLA A
    SLA A
    SLA A
    OR L
    LD L, A
    POP AF
    JP CPCVIDEOMUL84J
CPCVIDEOMUL84I0:
    POP AF
CPCVIDEOMUL84J:
    PUSH AF
    LD A, B
    AND $8
    CP $0
    JR Z, CPCVIDEOMUL84J0
CPCVIDEOMUL84J1:
    POP AF
    PUSH AF
    OR L
    LD L, A
    POP AF
    JP CPCVIDEOMUL84K
CPCVIDEOMUL84J0:
    POP AF
CPCVIDEOMUL84K:
    POP BC
    LD A, L
    POP HL
    RET

CPCVIDEOPOS:

    PUSH DE

    LD HL, PLOTVBASE

    LD E, D
    LD D, 0
    ADD HL, DE
    ADD HL, DE

    LD A, (HL)
    LD E, A
    INC HL
    LD A, (HL)
    LD D, A
    LD HL, DE

    POP DE

    LD A, (CURRENTMODE)
    CP 0
    JR Z, CPCVIDEOPOS0
    CP 1
    JR Z, CPCVIDEOPOS1
    CP 2
    JR Z, CPCVIDEOPOS2
    CP 3
    JR Z, CPCVIDEOPOS3
    RET

CPCVIDEOPOS0:
    PUSH DE
    SRL E
    LD A, 0
    LD D, A
    ADD HL, DE
    POP DE
    RET

CPCVIDEOPOS1:
CPCVIDEOPOS3:
    PUSH DE
    LD A, IXL
    LD D, A
    SRL D
    RR E
    SRL D
    RR E
    ADD HL, DE
    POP DE
    RET

CPCVIDEOPOS2:
    PUSH DE
    LD A, IXL
    LD D, A
    SRL D
    RR E
    SRL D
    RR E
    SRL D
    RR E
    ADD HL, DE
    POP DE
    RET

CPCVIDEOBITMASK1:
    DB $00,$11,$22,$33
    DB $44,$55,$66,$77
    DB $88,$99,$aa,$bb
    DB $cc,$dd,$ee,$ff    

CPCVIDEOBITMASK2:
    DB $88,$44,$22,$11

CPCVIDEOBITMASK4:
    DB $80,$40,$20,$10
    DB $08,$04,$02,$01

TEXTATPIXPOSH:
    PUSH AF
    PUSH DE
    PUSH HL
    JMP TEXTATPIXPOSH2

TEXTATPIXPOS:
    PUSH AF
    PUSH DE
    PUSH HL
    LD HL, PLOTVBASE

    LD A, (YCURSYS)
    CP 0
    JR Z, TEXTATPIXPOSSKIPY

    LD E, A
    LD A, $0
    LD D, A

    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D
    SLA E
    RL D

    ADD HL, DE

TEXTATPIXPOSSKIPY:    
    LD A, (HL)
    LD (COPYOFTEXTADDRESS), A
    INC HL
    LD A, (HL)
    LD (COPYOFTEXTADDRESS+1), A

TEXTATPIXPOSH2:

    LD HL, (COPYOFTEXTADDRESS)

    LD A, (XCURSYS)
    LD E, A
    LD A, 0
    LD D, 0
    ; PUSH HL
    ; LD HL, DE
    ; ADD HL, HL
    ; ADD HL, HL
    ; ADD HL, HL
    ; LD DE, HL
    ; POP HL

    LD A, (CURRENTMODE)
    CP 0
    JP Z, TEXTATPIXPOSSKIPY0
    CP 1
    JP Z, TEXTATPIXPOSSKIPY1
    CP 2
    JP Z, TEXTATPIXPOSSKIPY2
    CP 3
    JP Z, TEXTATPIXPOSSKIPY3
    JP TEXTATPIXPOSSKIPY2

TEXTATPIXPOSSKIPY0:
TEXTATPIXPOSSKIPY3:
    ADD HL, DE
    ADD HL, DE
TEXTATPIXPOSSKIPY1:
    ADD HL, DE
TEXTATPIXPOSSKIPY2:
    ADD HL, DE
    LD (COPYOFTEXTADDRESS), HL

    POP HL
    POP DE
    POP AF
    RET

CONSOLECALCULATE:

    CALL TEXTATPIXPOS
    LD HL, (COPYOFTEXTADDRESS)
    LD (CONSOLESA), HL

    LD A, (CONSOLEH)
    SLA A
    SLA A
    SLA A
    LD (CONSOLEHB), A
    
    LD A, (CONSOLEW)
    LD B, A
    LD A, (CURRENTMODE)
    CP 0
    JR Z, CONSOLECALCULATE0
    CP 1
    JR Z, CONSOLECALCULATE1
    CP 2
    JR Z, CONSOLECALCULATE2

CONSOLECALCULATE0:
    LD A, B
    SLA A
    SLA A
    LD B, A
CONSOLECALCULATE1:
    LD A, B
    SLA A
    LD B, A
CONSOLECALCULATE2:
    LD A, B
    SLA A

    LD (CONSOLEWB), A

    RET


; Convert a color in range 0..15 to bitmask valid for mode 0
; Input: 
;       B = color (0...15)
;       A = 0 if pixel 0, 1 if pixel 1
; Output:
;       A = bitmask value

COLORBITMAPCONVERTERSETCARRY:
    SCF
    RET

COLORBITMAPCONVERT0:
    PUSH BC
    PUSH DE
    LD E, 0
    LD D, 0
    CP 0
    JR Z, COLORBITMAPCONVERT0P0
COLORBITMAPCONVERT0P1:
    LD E, 1
COLORBITMAPCONVERT0P0:
    ; pixel 0 bit 0
    LD A, B
    BIT 0, A
    CALL NZ, COLORBITMAPCONVERTERSETCARRY
    RL D
    ; pixel 1 bit 0
    AND A
    RL D
    ; pixel 0 bit 2
    LD A, B
    BIT 2, A
    CALL NZ, COLORBITMAPCONVERTERSETCARRY
    RL D
    ; pixel 1 bit 2
    AND A
    RL D
    ; pixel 0 bit 3
    LD A, B
    BIT 1, A
    CALL NZ, COLORBITMAPCONVERTERSETCARRY
    RL D
    ; pixel 1 bit 3
    AND A
    RL D
    ; pixel 0 bit 1
    LD A, B
    BIT 3, A
    CALL NZ, COLORBITMAPCONVERTERSETCARRY
    RL D
    ; pixel 1 bit 1
    AND A
    RL D
    LD A, E
    CP $0
    JR Z, COLORBITMAPCONVERT0DONE
    SRL D
COLORBITMAPCONVERT0DONE:
    LD A, D
    POP DE
    POP BC
    RET

; Convert a color in range 0..3 to bitmask valid for mode 1
; Input: 
;       B = color (0...3)
;       A = 0 if pixel 0, 1 if pixel 1, and so on
; Output:
;       A = bitmask value

COLORBITMAPCONVERT1:
    PUSH BC
    PUSH DE
    LD E, A
    LD D, 0
    ; pixel 0 (bit 0)	
    LD A, B
    BIT 0, A
    CALL NZ, COLORBITMAPCONVERTERSETCARRY
    RL D
    ; pixel 1 (bit 0)	
    AND A
    RL D
    ; pixel 2 (bit 0)	
    RL D
    ; pixel 3 (bit 0)	
    RL D
    ; pixel 0 (bit 1)	
    LD A, B
    BIT 1, A
    CALL NZ, COLORBITMAPCONVERTERSETCARRY
    RL D
    ; pixel 1 (bit 1)	
    AND A
    RL D
    ; pixel 2 (bit 1)	
    RL D
    ; pixel 3 (bit 1)
    RL D
    LD A, E
    ; pixel 0
    CP 0 
    JR Z, COLORBITMAPCONVERT1DONE
    ; pixel 1
    SRL D
    DEC A
    JR Z, COLORBITMAPCONVERT1DONE
    ; pixel 2
    SRL D
    DEC A
    JR Z, COLORBITMAPCONVERT1DONE
    ; pixel 3
    SRL D
COLORBITMAPCONVERT1DONE:
    LD A, D
    POP DE
    POP BC
    RET



