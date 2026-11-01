; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                          STARTUP ROUTINE FOR TMS9918                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VDPLOCK:
        DI
        PUSH AF
        LD A, 1
        LD (VDPINUSE), A
        POP AF
        RET

VDPUNLOCK:
        PUSH AF
        LD A, 0
        LD (VDPINUSE), A
        IN A, ($bf)
        POP AF
        EI
        RET

VDPWRITEBIT: EQU     40H

VDPRAMOUT:
        OUT     (VDPDATAPORTWRITE), A
        RET

VDPRAMOUT8:
        PUSH    BC
        LD      BC, VDPDATAPORTWRITE
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        OUT     (C), A
@IF MSX1
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
@ENDIF
        POP     BC
        RET

VDPRAMIN:
        IN      A, (VDPDATAPORTREAD)
        RET

VDPWRITEADDR:
        LD      A, E                    ; SEND LSB
        CALL    VDPREGOUT
        LD      A, D                    ; MASK OFF MSB TO MAX OF 16KB
        AND     3FH
        OR      VDPWRITEBIT             ; INDICATE THAT THIS IS A WRITE
        CALL    VDPREGOUT
        RET

VDPREADADDR:
        LD      A, E                    ; SEND LSB
        CALL    VDPREGOUT
        LD      A, D                    ; MASK OFF MSB TO MAX OF 16KB
        AND     3FH
        CALL    VDPREGOUT
        RET

VDPSETREGI:
        CALL    VDPREGOUT
        LD      A, E
VDPREGOUT:
        OUT     (VDPCONTROLPORTWRITE), A
        RET

@IF !COLECO || !vestigialConfig.biosAllowed

VDPSETREG:
        CALL VDPLOCK
        CALL    VDPSETREGI
        CALL VDPUNLOCK
        RET
@ENDIF

VDPOUTCHAR:
        CALL VDPLOCK
        PUSH AF
        CALL    VDPWRITEADDR
        POP AF
        CALL    VDPRAMOUT
        CALL VDPUNLOCK
        RET

VDPINCHAR:
        CALL VDPLOCK
        PUSH AF
        CALL    VDPREADADDR
        POP AF
        CALL    VDPRAMIN
        CALL VDPUNLOCK
        RET

@IF !COLECO || !vestigialConfig.biosAllowed

VDPWRITE:
        CALL VDPLOCK
        CALL    VDPWRITEADDR
VDPWRITELOOP:
        LD      A, (HL)
        CALL    VDPRAMOUT
        INC     HL
        DEC     BC
        LD      A, B
        OR      C
        JP      NZ, VDPWRITELOOP
        CALL VDPUNLOCK
        RET

@ENDIF

VDPWRITEOPT:
        CALL VDPLOCK
        CALL    VDPWRITEADDR
VDPWRITEOPTLOOP:
        PUSH    BC
        LD      A, C
        LD      BC, VDPDATAPORTWRITE
        LD      B, A

VDPWRITEOPTLOOP2:
        OUTI
        JP NZ, VDPWRITEOPTLOOP2

        POP     BC
        CALL VDPUNLOCK
        RET

VDPWRITEOPTB:
        CALL VDPLOCK
        CALL    VDPWRITEADDR
VDPWRITEOPTLOOPB:
        PUSH    BC
        LD      A, C
        LD      BC, VDPDATAPORTWRITE
        LD      B, A

VDPWRITEOPTLOOPB2:
        OUTI
        JP NZ, VDPWRITEOPTLOOPB2
        POP BC
        DJNZ VDPWRITEOPTLOOPB

        CALL VDPUNLOCK
        RET

VDPWRITE8:
        CALL VDPLOCK
        CALL    VDPWRITEADDR
VDPWRITE8LOOP:
        LD      A, (HL)
        CALL    VDPRAMOUT8
        INC     HL
        DEC     BC
        LD      A, B
        OR      C
        JP      NZ, VDPWRITE8LOOP
        CALL VDPUNLOCK
        RET

VDPREAD:
        CALL VDPLOCK
        CALL    VDPREADADDR
        CALL    VDPRAMIN
        LD      H, A
        LD      L, A
        CALL VDPUNLOCK
        RET

VDPFILL:
        CALL VDPLOCK
        PUSH    AF
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLLOOP:
        CALL    VDPRAMOUT
        DEC     C
        JP      NZ, VDPFILLLOOP
        DJNZ    VDPFILLLOOP
        CALL VDPUNLOCK
        RET

VDPFILL8:
        CALL VDPLOCK
        PUSH    AF
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLLOOP8:
        CALL    VDPRAMOUT8
        DEC     C
        JP      NZ, VDPFILLLOOP8
        CALL VDPUNLOCK
        RET

VDPFILLA:
        CALL VDPLOCK
        PUSH    AF
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLALOOP:
        CALL    VDPRAMOUT
        DEC     C
        INC     A
        JP      NZ, VDPFILLALOOP
        DJNZ    VDPFILLALOOP
        CALL VDPUNLOCK
        RET

VDP_R0              EQU 80H
VDP_R1              EQU 81H
VDP_RNAME           EQU 82H
VDP_RCOLORTABLE     EQU 83H
VDP_RPATTERN        EQU 84H
VDP_RSPRITEA        EQU 85H
VDP_RSPRITEP        EQU 86H
VDP_RCOLOR          EQU 87H

@IF deployed.scroll

ONSCROLLVOID:
    RET

@ENDIF

TMS9918STARTUP:
        
        LD A, 16
        LD C, A
        LD A, 0
        LD HL, PALETTE
TMS9918STARTUPL1:        
        LD (HL), A
        INC HL
        INC A
        DEC C
        JR NZ, TMS9918STARTUPL1

        CALL SCREENMODE1

@IF deployed.scroll
        LD A, $C3
        LD HL, ONSCROLLUP
        LD (HL), A
        INC HL
        LD DE, ONSCROLLVOID
        LD A, E
        LD (HL), A
        INC HL
        LD A, D
        LD (HL), A

        LD A, $C3
        LD HL, ONSCROLLDOWN
        LD (HL), A
        INC HL
        LD A, E
        LD (HL), A
        INC HL
        LD A, D
        LD (HL), A

        LD A, $C3
        LD HL, ONSCROLLLEFT
        LD (HL), A
        INC HL
        LD A, E
        LD (HL), A
        INC HL
        LD A, D
        LD (HL), A

        LD A, $C3
        LD HL, ONSCROLLRIGHT
        LD (HL), A
        INC HL
        LD A, E
        LD (HL), A
        INC HL
        LD A, D
        LD (HL), A

@ENDIF

        LD E, $83
        IN A, (VDPCONTROLPORTREAD)
        AND $F0
        LD B, A
        LD E, $83
        LD A, $0
        AND $F0
        OR B
@IF !COLECO || !vestigialConfig.biosAllowed
        CALL VDPSETREG
@ELSE
        LD B, $03
        LD C, A
        CALL CBIOS_VDPSETREG
@ENDIF
        CALL VDPUNLOCK

        RET

TMS9918AFTERINIT:
@IF vestigialConfig.clsImplicit
	CALL CLST
@ENDIF
        RET

TMS9918SPRITEINIT:

@IF deployed.sprite

        PUSH HL
        LD HL, (SPRITEAADDRESS)
        LD B, 0
        LD C, 32
TMS9918SPRITEINITL1:
        LD A, $D0
        LD DE, HL
        CALL VDPOUTCHAR
        INC HL
        INC HL
        INC HL
        INC HL
        DEC C
        JR NZ, TMS9918SPRITEINITL1
        POP HL
        RET
@ELSE
        RET
@ENDIF

WAITVBL:
        LD A, 0
        LD (VBLFLAG), A
WAITVBL2:
        LD A, (VBLFLAG)
        CP 0
        JR Z, WAITVBL2
        RET

@IF dynamicConsole

CONSOLECALCULATE:
    LD HL, (TEXTADDRESS)
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0
    LD A, (CONSOLEY1)
    LD B, A
    CP 0
    JR Z, CONSOLECALCULATEL10
CONSOLECALCULATEL1:
    ADD HL, DE
    DEC B
    JR NZ, CONSOLECALCULATEL1
CONSOLECALCULATEL10:
    LD A, (CONSOLEX1)
    LD E, A
    LD D, 0
    ADD HL, DE
    LD (CONSOLESA), HL
    RET

@ENDIF

; M1 M2 M3 DISPLAY MODE
;  0  0  0 Graphic Mode 1    (1)
;  0  0  1 Graphic Mode 2    (2)
;  0  1  0 Multicolor Mode   (3)
;  1  0  0 Text Mode         (0)


@IF ( !vestigialConfig.screenModeUnique ) || ( ( currentMode == 0 ) )

SCREENMODE0:

        CALL VDPLOCK

@IF COLECO && vestigialConfig.biosAllowed

        ; Register 0 = 0000003E = 00000000
        ;     3 = M3 (0)
        ;     E = 0
        LD BC, $0000
        CALL CBIOS_VDPSETREG

        ; Register 2 = 0000NNNN = 00000110
        ;     N = starting name table (0..F x $0400) = $1800
        LD BC, $0206
        CALL CBIOS_VDPSETREG

        ; Register 3 = CCCCCCCC = 10000000
        ;     C = starting name color table (0..F x $40) = $2000
        LD BC, $0380
        CALL CBIOS_VDPSETREG

        ; Register 4 = xxxxxPPP = 00000000
        ;     P = starting pattern table (x $800) = $0000
        LD BC, $0400
        CALL CBIOS_VDPSETREG

        ; Register 5 = xSSSSSSS = 01111111
        ;     S = starting sprite attribute table (x $80) = $3f80
        LD BC, $057f
        CALL CBIOS_VDPSETREG

        ; Register 6 = xxxxxSSS = 00000111
        ;     S = starting sprite table (x $800) = $3B00
        LD BC, $0607
        CALL CBIOS_VDPSETREG

        ; Register 7 = FFFFBBBB = 11110001
        ;     F = fore color = 0x0f
        ;     B = back color = 0x01
        LD BC, $07f1
        CALL CBIOS_VDPSETREG

        ; Register 1 = xSI1 20XM = 0111 0010
        ;     S = active display (0 = off, 1 = on)
        ;     I = interrupt enable
        ;     1 = M1 (1)
        ;     2 = M2 (0)
        ;     X = sprite size (0 = 8x8, 1  = 16x16)
        ;     M = sprite magnification (0 = single, 1 = double)
        LD BC, $0172
        CALL CBIOS_VDPSETREG

@ELSE

        ; Register 0 = 0000003E = 00000000
        ;     3 = M3 (0)
        ;     E = 0
        LD E, VDP_R0
        LD A, $00
        CALL VDPSETREG

        ; Register 2 = 0000NNNN = 00000110
        ;     N = starting name table (0..F x $0400) = $1800
        LD E, VDP_RNAME
        LD A, $06
        CALL VDPSETREG

        ; Register 3 = CCCCCCCC = 10000000
        ;     C = starting name color table (0..F x $40) = $2000
        LD E, VDP_RCOLORTABLE
        LD A, $80
        CALL VDPSETREG

        ; Register 4 = xxxxxPPP = 00000000
        ;     P = starting pattern table (x $800) = $0000
        LD E, VDP_RPATTERN
        LD A, $00
        CALL VDPSETREG

        ; Register 5 = xSSSSSSS = 01111111
        ;     S = starting sprite attribute table (x $80) = $3f80
        LD E, VDP_RSPRITEA
        LD A, $7f
        CALL VDPSETREG

        ; Register 6 = xxxxxSSS = 00000111
        ;     S = starting sprite table (x $800) = $3B00
        LD E, VDP_RSPRITEP
        LD A, $07
        CALL VDPSETREG

        ; Register 7 = FFFFBBBB = 11110001
        ;     F = fore color = 0x0f
        ;     B = back color = 0x01
        LD E, VDP_RCOLOR
        LD A, $F1
        CALL VDPSETREG

        ; Register 1 = xSI1 20XM = 0111 0010
        ;     S = active display (0 = off, 1 = on)
        ;     I = interrupt enable
        ;     1 = M1 (1)
        ;     2 = M2 (0)
        ;     X = sprite size (0 = 8x8, 1  = 16x16)
        ;     M = sprite magnification (0 = single, 1 = double)
        LD E, VDP_R1
        LD A, $72
        CALL VDPSETREG

@ENDIF

        CALL VDPUNLOCK

        RET

@ENDIF

SCREENMODE1:

        CALL VDPLOCK

@IF COLECO && vestigialConfig.biosAllowed

        ; Register 0 = 0000003E = 00000000
        ;     3 = M3 (0)
        ;     E = 0
        LD BC, $0000
        CALL CBIOS_VDPSETREG

        ; Register 2 = 0000NNNN = 00000110
        ;     N = starting name table (0..F x $0400) = $1800
        LD BC, $0206
        CALL CBIOS_VDPSETREG

        ; Register 3 = CCCCCCCC = 10000000
        ;     C = starting name color table (0..FF x $40) = $0480
        LD BC, $0312
        CALL CBIOS_VDPSETREG

        ; Register 4 = xxxxxPPP = 00000000
        ;     P = starting pattern table (x $800) = $0000
        LD BC, $0400
        CALL CBIOS_VDPSETREG

        ; Register 5 = xSSSSSSS = 00100000
        ;     S = starting sprite attribute table (x $80) = $1000
        LD BC, $0520
        CALL CBIOS_VDPSETREG

        ; Register 6 = xxxxxSSS = 00000000
        ;     S = starting sprite table (x $800) = $0000
        LD BC, $0600
        CALL CBIOS_VDPSETREG

        ; Register 7 = FFFFBBBB = 11110001
        ;     F = fore color = 0x0f
        ;     B = back color = 0x01
        LD BC, $07f1
        CALL CBIOS_VDPSETREG

        ; Register 1 = xSI1 20XM = 0110 0010
        ;     S = active display (0 = off, 1 = on)
        ;     I = interrupt enable
        ;     1 = M1 (0)
        ;     2 = M2 (0)
        ;     X = sprite size (0 = 8x8, 1  = 16x16)
        ;     M = sprite magnification (0 = single, 1 = double)
        LD BC, $0162
        CALL CBIOS_VDPSETREG

@ELSE

        ; Register 0 = 0000003E = 00000000
        ;     3 = M3 (0)
        ;     E = 0
        LD E, VDP_R0
        LD A, $00
        CALL VDPSETREG

        ; Register 2 = 0000NNNN = 00000110
        ;     N = starting name table (0..F x $0400) = $1800
        LD E, VDP_RNAME
        LD A, $06
        CALL VDPSETREG

        ; Register 3 = CCCCCCCC = 10000000
        ;     C = starting name color table (0..FF x $40) = $0480
        LD E, VDP_RCOLORTABLE
        LD A, $12
        CALL VDPSETREG

        ; Register 4 = xxxxxPPP = 00000000
        ;     P = starting pattern table (x $800) = $0000
        LD E, VDP_RPATTERN
        LD A, $00
        CALL VDPSETREG

        ; Register 5 = xSSSSSSS = 00100000
        ;     S = starting sprite attribute table (x $80) = $1000
        LD E, VDP_RSPRITEA
        LD A, $20
        CALL VDPSETREG

        ; Register 6 = xxxxxSSS = 00000000
        ;     S = starting sprite table (x $800) = $0000
        LD E, VDP_RSPRITEP
        LD A, $00
        CALL VDPSETREG

        ; Register 7 = FFFFBBBB = 11110001
        ;     F = fore color = 0x0f
        ;     B = back color = 0x01
        LD E, VDP_RCOLOR
        LD A, $F1
        CALL VDPSETREG

        ; Register 1 = xSI1 20XM = 0110 0010
        ;     S = active display (0 = off, 1 = on)
        ;     I = interrupt enable
        ;     1 = M1 (0)
        ;     2 = M2 (0)
        ;     X = sprite size (0 = 8x8, 1  = 16x16)
        ;     M = sprite magnification (0 = single, 1 = double)
        LD E, VDP_R1
        LD A, $62
        CALL VDPSETREG

@ENDIF

        CALL VDPUNLOCK

        RET

@IF ( !vestigialConfig.screenModeUnique ) || ( ( currentMode == 2 ) || ( currentMode == 3 ) )

SCREENMODE2:
SCREENMODE3:

        CALL VDPLOCK

@IF COLECO && vestigialConfig.biosAllowed

        ; Register 0 = 0000003E = 00000010
        ;     3 = M3 (1)
        ;     E = 0
        LD BC, $0002
        CALL CBIOS_VDPSETREG

        ; Register 2 = 0000NNNN = 00001110
        ;     N = starting name table (0..F x $0400) = $3800
        LD BC, $020e
        CALL CBIOS_VDPSETREG

        ; Register 3 = Cxxxxxxxx = 11111111
        ;     C = starting name color table
        ;           $7f = $0000
        ;           $ff = $2000
        LD BC, $03ff
        CALL CBIOS_VDPSETREG

        ; Register 4 = xxxxxPPP = 00000011
        ;     P = starting pattern table (x $800) = $1800
        LD BC, $0403
        CALL CBIOS_VDPSETREG

        ; Register 5 = xSSSSSSS = 001110110
        ;     S = starting sprite attribute table (x $80) = $3B00
        LD BC, $0576
        CALL CBIOS_VDPSETREG

        ; Register 6 = xxxxxSSS = 00000011
        ;     S = starting sprite table (x $800) = $1800
        LD BC, $0603
        CALL CBIOS_VDPSETREG

        ; Register 7 = FFFFBBBB = 11110001
        ;     F = fore color = 0x0f
        ;     B = back color = 0x01
        LD BC, $07f1
        CALL CBIOS_VDPSETREG

        ; Register 1 = xSI1 20XM = 0110 0010
        ;     S = active display (0 = off, 1 = on)
        ;     I = interrupt enable
        ;     1 = M1 (0)
        ;     2 = M2 (0)
        ;     X = sprite size (0 = 8x8, 1  = 16x16)
        ;     M = sprite magnification (0 = single, 1 = double)
        LD BC, $0162
        CALL CBIOS_VDPSETREG

@ELSE

        ; Register 0 = 0000003E = 00000010
        ;     3 = M3 (1)
        ;     E = 0
        LD E, VDP_R0
        LD A, $02
        CALL VDPSETREG

        ; Register 2 = 0000NNNN = 00001110
        ;     N = starting name table (0..F x $0400) = $3800
        LD E, VDP_RNAME
        LD A, $0e
        CALL VDPSETREG

        ; Register 3 = Cxxxxxxxx = 11111111
        ;     C = starting name color table
        ;           $7f = $0000
        ;           $ff = $2000
        LD E, VDP_RCOLORTABLE
        LD A, $ff
        CALL VDPSETREG

        ; Register 4 = xxxxxPPP = 00000011
        ;     P = starting pattern table (x $800) = $1800
        LD E, VDP_RPATTERN
        LD A, $03
        CALL VDPSETREG

        ; Register 5 = xSSSSSSS = 001110110
        ;     S = starting sprite attribute table (x $80) = $3B00
        LD E, VDP_RSPRITEA
        LD A, $76
        CALL VDPSETREG

        ; Register 6 = xxxxxSSS = 00000011
        ;     S = starting sprite table (x $800) = $1800
        LD E, VDP_RSPRITEP
        LD A, $03
        CALL VDPSETREG

        ; Register 7 = FFFFBBBB = 11110001
        ;     F = fore color = 0x0f
        ;     B = back color = 0x01
        LD E, VDP_RCOLOR
        LD A, $F1
        CALL VDPSETREG

        ; Register 1 = xSI1 20XM = 0110 0010
        ;     S = active display (0 = off, 1 = on)
        ;     I = interrupt enable
        ;     1 = M1 (0)
        ;     2 = M2 (0)
        ;     X = sprite size (0 = 8x8, 1  = 16x16)
        ;     M = sprite magnification (0 = single, 1 = double)
        LD E, VDP_R1
        LD A, $62
        CALL VDPSETREG

@ENDIF

        CALL VDPUNLOCK

        RET

@ENDIF
