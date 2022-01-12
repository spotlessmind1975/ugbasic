if __coleco__

WAIT_VDP_HOOK:
        LD A,(VDP_HOOK)
        CP $cd
        JR Z,WAIT_VDP_HOOK
        RET

SET_VDP_HOOK0:
        LD (VDP_HOOK+1),HL
        LD A,$c9
        LD (VDP_HOOK+3),A
        LD A,$cd
        LD (VDP_HOOK),A
        RET

SET_VDP_HOOK:
        LD (VDP_HOOK+1),HL
        LD A,$c9
        LD (VDP_HOOK+3),A
        LD A, B
        LD (VDP_HOOK+4),A
        LD A, C
        LD (VDP_HOOK+5),A
        LD A, D
        LD (VDP_HOOK+6),A
        LD A, E
        LD (VDP_HOOK+7),A
        LD A,$cd
        LD (VDP_HOOK),A
        RET

SET_VDP_HOOK_HL:
        LD A, H
        LD (VDP_HOOK+8),A
        LD A, L
        LD (VDP_HOOK+9),A
        RET

GET_VDP_HOOK:
        LD A, (VDP_HOOK+4)
        LD B, A
        LD A, (VDP_HOOK+5)
        LD C, A
        LD A, (VDP_HOOK+6)
        LD D, A
        LD A, (VDP_HOOK+7)
        LD E, A
        LD A, (VDP_HOOK+8)
        LD H, A
        LD A, (VDP_HOOK+9)
        LD L, A
        RET

DONE_VDP_HOOK:
        LD A,0
        LD (VDP_HOOK),A
        RET

endif

VDPWRITEBIT: EQU     40H

VDPSETREG:
        CALL    VDPREGOUT
        LD      A, E
VDPREGOUT:
        PUSH    BC
        LD      BC, (VDPCONTROLPORTWRITE)
        OUT     (C), A
        POP     BC
        RET

VDPREGIN:
        PUSH    BC
        LD      BC, (VDPCONTROLPORTREAD)
        IN      A, (C)
        POP     BC
        RET

VDPRAMOUT:
        PUSH    BC
        LD      BC, (VDPDATAPORTWRITE)
        OUT     (C), A
        POP     BC
        RET

VDPRAMOUT8:
        PUSH    BC
        LD      BC, (VDPDATAPORTWRITE)
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        OUT     (C), A
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        NOP
        POP     BC
        RET

VDPRAMIN:
        PUSH    BC
        LD      BC, (VDPDATAPORTREAD)
        IN      A, (C)
        POP     BC
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

VDPOUTCHAR:
        DI
        PUSH AF
        CALL    VDPWRITEADDR
        POP AF
        CALL    VDPRAMOUT
        EI
        RET

VDPINCHAR:
        DI
        PUSH AF
        CALL    VDPREADADDR
        POP AF
        CALL    VDPRAMIN
        EI
        RET

VDPWRITE:
        DI
        CALL    VDPWRITEADDR
VDPWRITELOOP:
        LD      A, (HL)
        CALL    VDPRAMOUT
        INC     HL
        DEC     BC
        LD      A, B
        OR      C
        JP      NZ, VDPWRITELOOP
        EI
        RET

VDPWRITE8:
        DI
        CALL    VDPWRITEADDR
VDPWRITE8LOOP:
        LD      A, (HL)
        CALL    VDPRAMOUT8
        INC     HL
        DEC     BC
        LD      A, B
        OR      C
        JP      NZ, VDPWRITE8LOOP
        EI
        RET

VDPREAD:
        DI
        CALL    VDPREADADDR
        CALL    VDPRAMIN
        LD      H, A
        LD      L, A
        EI
        RET

VDPFILL:
        DI
        PUSH    AF
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLLOOP:
        CALL    VDPRAMOUT
        DEC     C
        JP      NZ, VDPFILLLOOP
        DJNZ    VDPFILLLOOP
        EI
        RET

VDPFILL8:
        DI
        PUSH    AF
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLLOOP8:
        CALL    VDPRAMOUT8
        DEC     C
        JP      NZ, VDPFILLLOOP8
        EI
        RET

VDPFILLA:
        DI
        PUSH    AF
        CALL    VDPWRITEADDR
        POP     AF
VDPFILLALOOP:
        CALL    VDPRAMOUT
        DEC     C
        INC     A
        JP      NZ, VDPFILLALOOP
        DJNZ    VDPFILLALOOP
        EI
        RET

VDP_OUT:
	; LD	HL, 2
	; ADD	HL, SP
	; LD	A, (HL)			; VAL
	; INC 	HL
	; INC 	HL
	; LD	E, (HL)			; REG
	JP 	VDPSETREG

VDP_IN:
	CALL	VDPREGIN
	RET

VDP_PUT:
	LD	HL, 2
	ADD	HL, SP
    LD C,(HL)
    INC HL
    LD B,(HL)              ; BYTE COUNT
    INC HL
    LD E,(HL)
    INC HL
    LD D,(HL)              ; VRAM DESTINATION ADDRESS
    INC HL
    LD A, (HL)
    INC HL
    EX AF,AF'
    LD A, (HL)
    INC HL
    LD H, A
    EX AF,AF'
    LD L, A
    JP VDPWRITE

VDP_PUT8:
	LD	HL, 2
	ADD	HL, SP
    LD C,(HL)
    INC HL
    LD B,(HL)              ; BYTE COUNT
    INC HL
    LD E,(HL)
    INC HL
    LD D,(HL)              ; VRAM DESTINATION ADDRESS
    INC HL
    LD A, (HL)
    INC HL
    EX AF,AF'
    LD A, (HL)
    INC HL
    LD H, A
    EX AF,AF'
    LD L, A
    JP VDPWRITE8

VDP_FILL8:
	LD	HL, 2
	ADD	HL, SP
    LD C,(HL)
    INC HL
    LD B,(HL)              ; BYTE COUNT
    INC HL
    LD E,(HL)
    INC HL
    LD D,(HL)              ; VRAM DESTINATION ADDRESS
    INC HL
	LD	A, (HL)			    ; VALUE TO FILL
    JP VDPFILL8

VDP_FILL:
	LD	HL, 2
	ADD	HL, SP
    LD C,(HL)
    INC HL
    LD B,(HL)              ; BYTE COUNT
    INC HL
    LD E,(HL)
    INC HL
    LD D,(HL)              ; VRAM DESTINATION ADDRESS
    INC HL
	LD	A, (HL)			    ; VALUE TO FILL
    JP VDPFILL

VDP_GET:
	LD	HL, 2
	ADD	HL, SP
    LD E,(HL)
    INC HL
    LD D,(HL)              ; VRAM SOURCE ADDRESS
    JP VDPREAD

VDP_PORT:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPDATAPORTREAD), A
    LD (VDPDATAPORTWRITE), A
    INC A
    LD (VDPCONTROLPORTREAD), A
    LD (VDPCONTROLPORTWRITE), A
    RET

VDP_PORT_READ:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPDATAPORTREAD), A
    INC A
    LD (VDPCONTROLPORTREAD), A
    RET

VDP_PORT_WRITE:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPDATAPORTWRITE), A
    INC A
    LD (VDPCONTROLPORTWRITE), A
    RET

VDP_DATA_PORT:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPDATAPORTREAD), A
    LD (VDPDATAPORTWRITE), A
    RET

VDP_DATA_PORT_READ:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPDATAPORTREAD), A
    RET

VDP_DATA_PORT_WRITE:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPDATAPORTWRITE), A
    RET

VDP_CONTROL_PORT:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPCONTROLPORTREAD), A
    LD (VDPCONTROLPORTWRITE), A
    RET

VDP_CONTROL_PORT_READ:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPCONTROLPORTREAD), A
    RET

VDP_CONTROL_PORT_WRITE:
	LD	HL, 2
	ADD	HL, SP
	LD	A, (HL)			; PORT
    LD (VDPCONTROLPORTWRITE), A
    RET

VDP_R0              EQU 80H
VDP_R1              EQU 81H
VDP_RNAME           EQU 82H
VDP_RCOLORTABLE     EQU 83H
VDP_RPATTERN        EQU 84H
VDP_RSPRITEA        EQU 85H
VDP_RSPRITEP        EQU 86H
VDP_RCOLOR          EQU 87H

TMS9918STARTUP:

        DI
        LD A, VDP_R0
        LD E, A
        LD A, $00
        CALL VDPSETREG

        LD A, VDP_RNAME
        LD E, A
        LD A, $06
        CALL VDPSETREG

        LD A, VDP_RCOLORTABLE
        LD E, A
        LD A, $80
        CALL VDPSETREG

        LD A, VDP_RPATTERN
        LD E, A
        LD A, $00
        CALL VDPSETREG

        LD A, VDP_RSPRITEA
        LD E, A
        LD A, $36
        CALL VDPSETREG

        LD A, VDP_RSPRITEP
        LD E, A
        LD A, $07
        CALL VDPSETREG

        LD A, VDP_RCOLOR
        LD E, A
        LD A, $F1
        CALL VDPSETREG

        LD A, VDP_R1
        LD E, A
        LD A, $f0
        CALL VDPSETREG

        EI

        RET

