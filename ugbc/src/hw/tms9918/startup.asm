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
@IF timerUsed || deployed.music || deployed.timer || (deployed.joystick && ! joystickConfig.sync) || ticksPerSecondUsed
        PUSH AF
        LD A, 1
        LD (VDPINUSE), A
        POP AF
@ENDIF
        RET

VDPUNLOCK:
        PUSH AF
@IF timerUsed || deployed.music || deployed.timer || (deployed.joystick && ! joystickConfig.sync) || ticksPerSecondUsed
        LD A, 0
        LD (VDPINUSE), A
@ENDIF
        IN A, ($bf)
        POP AF
        EI
        RET

VDPWRITEBIT: EQU     40H

@IF !COLECO || !vestigialConfig.biosAllowed

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

@ENDIF

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

@IF !COLECO || !vestigialConfig.biosAllowed

VDPOUTCHAR:
        CALL VDPLOCK
        PUSH AF
        CALL    VDPWRITEADDR
        POP AF
        CALL    VDPRAMOUT
        CALL VDPUNLOCK
        RET

@ELSE

VDPOUTCHAR:
        PUSH BC
        PUSH HL
        PUSH DE
        LD HL, DE
        LD DE, 1
        CALL CBIOS_FILL_VRAM
        POP DE
        POP HL
        POP BC
        RET

@ENDIF

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

; VDPWRITE8:
;         CALL VDPLOCK
;         CALL    VDPWRITEADDR
; VDPWRITE8LOOP:
;         LD      A, (HL)
;         CALL    VDPRAMOUT8
;         INC     HL
;         DEC     BC
;         LD      A, B
;         OR      C
;         JP      NZ, VDPWRITE8LOOP
;         CALL VDPUNLOCK
;         RET

VDPREAD:
        CALL VDPLOCK
        CALL    VDPREADADDR
        CALL    VDPRAMIN
        LD      H, A
        LD      L, A
        CALL VDPUNLOCK
        RET

@IF !COLECO || !vestigialConfig.biosAllowed

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

@ENDIF

@IF !COLECO || !vestigialConfig.biosAllowed

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

@ENDIF

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

@IF paletteNeeded

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

@ENDIF

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

;         LD E, $83
;         IN A, (VDPCONTROLPORTREAD)
;         AND $F0
;         LD B, A
;         LD E, $83
;         LD A, $0
;         AND $F0
;         OR B
; @IF !COLECO || !vestigialConfig.biosAllowed
;         CALL VDPSETREG
; @ELSE
;         LD B, $03
;         LD C, A
;         CALL CBIOS_VDPSETREG
; @ENDIF

	CALL TMS9918AUDCCHAR01
	CALL TMS9918SPRITEINIT        

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

@IF waitVblUsed

VBLFLAG:        DEFB $00

WAITVBL:
        LD A, 0
        LD (VBLFLAG), A
WAITVBL2:
        LD A, (VBLFLAG)
        CP 0
        JR Z, WAITVBL2
        RET

@ENDIF

@IF dynamicConsole

CONSOLECALCULATE:
    LD HL, (TEXTADDRESS)
    LD A, (CURRENTTILESWIDTH)
    LD E, A
    LD D, 0

@IF consoleUsed
    LD A, (CONSOLEY1)
@ELSE
    LD A, CONSOLEY1
@ENDIF   

    LD B, A
    CP 0
    JR Z, CONSOLECALCULATEL10
CONSOLECALCULATEL1:
    ADD HL, DE
    DEC B
    JR NZ, CONSOLECALCULATEL1
CONSOLECALCULATEL10:

@IF consoleUsed
    LD A, (CONSOLEX1)
@ELSE
    LD A, CONSOLEX1
@ENDIF

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

@EMIT defaultPenColor
@EMIT defaultPaperColor

@IF ( !vestigialConfig.screenModeUnique ) || ( ( currentMode == 0 ) )

SCREENMODE0:

        CALL VDPLOCK

@IF COLECO && vestigialConfig.biosAllowed

        ; Register 0 = 0000003E = 00000000
        ;     3 = M3 (0)
        ;     E = 0
        LD BC, $0000
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
        LD BC, $0700 + ( defaultPenColor * 16 ) + defaultPaperColor
        CALL CBIOS_VDPSETREG

@ELSE

        ; Register 0 = 0000003E = 00000000
        ;     3 = M3 (0)
        ;     E = 0
        LD E, VDP_R0
        LD A, $00
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
        LD A, ( defaultPenColor * 16 ) + defaultPaperColor
        CALL VDPSETREG



@ENDIF

        CALL VDPUNLOCK

        RET

@ENDIF

SCREENMODE1:

        CALL VDPLOCK

@IF COLECO && vestigialConfig.biosAllowed

        ; • Name Table (Schermo): 0x1800 (768 byte)
        ; • Color Table (Colori): 0x2000 (32 byte)
        ; • Pattern Table (Caratteri): 0x0000 (2048 byte)
        ; • Sprite Attribute Table: 0x1B00 (128 byte)
        ; • Sprite Pattern Table: 0x3800 (2048 byte)

        ; R0: M3=0 (Graphics I), Video esterno disabilitato
        LD BC, $0000
        CALL CBIOS_VDPSETREG

        ; R1: 16KB VRAM, Schermo ON, Interrupt ON, M1=0, M2=0, Sprite 8x8
        LD BC, $01e0
        CALL CBIOS_VDPSETREG

        ; R2: Name Table = 06h * 400h = 1800h
        LD BC, $0206
        CALL CBIOS_VDPSETREG

        ; R3: Color Table = 80h * 40h = 2000h
        LD BC, $0380
        CALL CBIOS_VDPSETREG

        ; R4: Pattern Table = 00h * 800h = 0000h
        LD BC, $0400
        CALL CBIOS_VDPSETREG

        ; R5: Sprite Attribute Table = 36h * 80h = 1B00h
        LD BC, $0536
        CALL CBIOS_VDPSETREG

        ; R6: Sprite Pattern Table = 07h * 800h = 3800h
        LD BC, $0607
        CALL CBIOS_VDPSETREG

        ; R7: Colore bordo = Nero (1)
        LD BC, $0700 + defaultPaperColor
        CALL CBIOS_VDPSETREG

@ELSE

        ; • Name Table (Schermo): 0x1800 (768 byte)
        ; • Color Table (Colori): 0x2000 (32 byte)
        ; • Pattern Table (Caratteri): 0x0000 (2048 byte)
        ; • Sprite Attribute Table: 0x1B00 (128 byte)
        ; • Sprite Pattern Table: 0x3800 (2048 byte)

        ; R0: M3=0 (Graphics I), Video esterno disabilitato
        LD E, VDP_R0
        LD A, $00
        CALL VDPSETREG

        ; R1: 16KB VRAM, Schermo ON, Interrupt ON, M1=0, M2=0, Sprite 8x8
        LD E, VDP_R1
        LD A, $e2
        CALL VDPSETREG

        ; R2: Name Table = 06h * 400h = 1800h
        LD E, VDP_RNAME
        LD A, $06
        CALL VDPSETREG

        ; R3: Color Table = 80h * 40h = 2000h
        LD E, VDP_RCOLORTABLE
        LD A, $80
        CALL VDPSETREG

        ; R4: Pattern Table = 00h * 800h = 0000h
        LD E, VDP_RPATTERN
        LD A, $00
        CALL VDPSETREG

        ; R5: Sprite Attribute Table = 36h * 80h = 1B00h
        LD E, VDP_RSPRITEA
        LD A, $36
        CALL VDPSETREG

        ; R6: Sprite Pattern Table = 07h * 800h = 3800h
        LD E, VDP_RSPRITEP
        LD A, $07
        CALL VDPSETREG

        ; R7: Colore bordo = Nero (1)
        LD E, VDP_RCOLOR
        LD A, defaultPaperColor
        CALL VDPSETREG

@ENDIF

        CALL VDPUNLOCK

        RET

@IF ( !vestigialConfig.screenModeUnique ) || ( ( currentMode == 2 ) || ( currentMode == 3 ) )

VDPFILLA:

@IF !COLECO || !vestigialConfig.biosAllowed

        PUSH    AF
        CALL VDPLOCK
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLALOOP:
        CALL    VDPRAMOUT
        INC     A
        DEC     C
        JP      NZ, VDPFILLALOOP
        DJNZ    VDPFILLALOOP
        CALL VDPUNLOCK

@ELSE

        LD HL, DE
VDPFILLALOOP:
        LD DE, 1
        PUSH BC
        PUSH AF
        CALL CBIOS_FILL_VRAM
        POP AF
        POP BC
        INC     HL
        INC     A
        DEC     C
        JP      NZ, VDPFILLALOOP
        DJNZ    VDPFILLALOOP

@ENDIF

        RET

SCREENMODE2:
SCREENMODE3:

        CALL VDPLOCK

@IF COLECO && vestigialConfig.biosAllowed

        ; • Name Table (Schermo): 0x1800 (768 byte)
        ; • Color Table (Colori): 0x2000 (6144 byte)
        ; • Pattern Table (Grafica): 0x0000 (6144 byte)
        ; • Sprite Attribute Table: 0x1B00 (128 byte)
        ; • Sprite Pattern Table: 0x3800 (2048 byte)

        ; R0: M3=1 (Abilita Graphics II)
        LD BC, $0002
        CALL CBIOS_VDPSETREG

        ; R1: 16KB VRAM, Schermo ON, Interrupt ON, M1=0, M2=0
        LD BC, $01e2
        CALL CBIOS_VDPSETREG

        ; R2: Name Table = 1800h
        LD BC, $0206
        CALL CBIOS_VDPSETREG

        ; R3: Color Table = 2000h (Maschera bit completa per 6KB)
        LD BC, $03ff
        CALL CBIOS_VDPSETREG

        ; R4: Pattern Table = 0000h (Maschera bit completa per 6KB)
        LD BC, $0403
        CALL CBIOS_VDPSETREG

        ; R5: Sprite Attribute Table = 1B00h
        LD BC, $0536
        CALL CBIOS_VDPSETREG

        ; R6: Sprite Pattern Table = 3800h
        LD BC, $0607
        CALL CBIOS_VDPSETREG

        ; R7: Colore bordo = Nero (1)
        LD BC, $0700 + defaultPaperColor
        CALL CBIOS_VDPSETREG

@ELSE

        ; • Name Table (Schermo): 0x1800 (768 byte)
        ; • Color Table (Colori): 0x2000 (6144 byte)
        ; • Pattern Table (Grafica): 0x0000 (6144 byte)
        ; • Sprite Attribute Table: 0x1B00 (128 byte)
        ; • Sprite Pattern Table: 0x3800 (2048 byte)

        ; R0: M3=1 (Abilita Graphics II)
        LD E, VDP_R0
        LD A, $02
        CALL VDPSETREG

        ; R1: 16KB VRAM, Schermo ON, Interrupt ON, M1=0, M2=0
        LD E, VDP_R1
        LD A, $e2
        CALL VDPSETREG

        ; R2: Name Table = 1800h
        LD E, VDP_RNAME
        LD A, $06
        CALL VDPSETREG

        ; R3: Color Table = 2000h (Maschera bit completa per 6KB)
        LD E, VDP_RCOLORTABLE
        LD A, $ff
        CALL VDPSETREG

        ; R4: Pattern Table = 0000h (Maschera bit completa per 6KB)
        LD E, VDP_RPATTERN
        LD A, $03
        CALL VDPSETREG

        ; R5: Sprite Attribute Table = 1B00h
        LD E, VDP_RSPRITEA
        LD A, $36
        CALL VDPSETREG

        ; R6: Sprite Pattern Table = 3800h
        LD E, VDP_RSPRITEP
        LD A, $07
        CALL VDPSETREG

        ; R7: Colore bordo = Nero (1)
        LD E, VDP_RCOLOR
        LD A, defaultPaperColor
        CALL VDPSETREG

@ENDIF

        LD A, 0
        LD DE, (TEXTADDRESS)
        LD BC, 256*3
        CALL VDPFILLA

        CALL VDPUNLOCK

        RET

@ENDIF
