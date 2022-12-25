; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

; if __coleco__

; WAIT_VDP_HOOK:
;         LD A,(VDP_HOOK)
;         CP $cd
;         JR Z,WAIT_VDP_HOOK
;         RET

; SET_VDP_HOOK0:
;         LD (VDP_HOOK+1),HL
;         LD A,$c9
;         LD (VDP_HOOK+3),A
;         LD A,$cd
;         LD (VDP_HOOK),A
;         RET

; SET_VDP_HOOK:
;         LD (VDP_HOOK+1),HL
;         LD A,$c9
;         LD (VDP_HOOK+3),A
;         LD A, B
;         LD (VDP_HOOK+4),A
;         LD A, C
;         LD (VDP_HOOK+5),A
;         LD A, D
;         LD (VDP_HOOK+6),A
;         LD A, E
;         LD (VDP_HOOK+7),A
;         LD A,$cd
;         LD (VDP_HOOK),A
;         RET

; SET_VDP_HOOK_HL:
;         LD A, H
;         LD (VDP_HOOK+8),A
;         LD A, L
;         LD (VDP_HOOK+9),A
;         RET

; GET_VDP_HOOK:
;         LD A, (VDP_HOOK+4)
;         LD B, A
;         LD A, (VDP_HOOK+5)
;         LD C, A
;         LD A, (VDP_HOOK+6)
;         LD D, A
;         LD A, (VDP_HOOK+7)
;         LD E, A
;         LD A, (VDP_HOOK+8)
;         LD H, A
;         LD A, (VDP_HOOK+9)
;         LD L, A
;         RET

; DONE_VDP_HOOK:
;         LD A,0
;         LD (VDP_HOOK),A
;         RET

; endif

VDPWRITEBIT: EQU     40H

VDPSETREGI:
        CALL    VDPREGOUT
        LD      A, E
VDPREGOUT:
        PUSH    BC
        LD      BC, (VDPCONTROLPORTWRITE)
; if __sc3000__
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
; endif
        OUT     (C), A
        POP     BC
        RET

VDPREGIN:
        PUSH    BC
        LD      BC, (VDPCONTROLPORTREAD)
; if __sc3000__
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
; endif
        IN      A, (C)
        POP     BC
        RET

VDPRAMOUT:
        PUSH    BC
        LD      BC, (VDPDATAPORTWRITE)
; if __sc3000__
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
; endif
        OUT     (C), A
        POP     BC
        RET

VDPRAMOUT8:
        PUSH    BC
        LD      BC, (VDPDATAPORTWRITE)
; if __sc3000__
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
; endif
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
; if __sc3000__
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
;         NOP
; endif
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

VDPSETREG:
        DI
        CALL    VDPSETREGI
        EI
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

VDP_R0              EQU 80H
VDP_R1              EQU 81H
VDP_RNAME           EQU 82H
VDP_RCOLORTABLE     EQU 83H
VDP_RPATTERN        EQU 84H
VDP_RSPRITEA        EQU 85H
VDP_RSPRITEP        EQU 86H
VDP_RCOLOR          EQU 87H

ONSCROLLVOID:
    RET

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
        LD A, $e0
        CALL VDPSETREG

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

        EI

        RET

TMS9918SPRITEINIT:
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

        RET

WAITVBL:
    CALL VDPREGIN
    AND $80
    CP $80
    JR Z, WAITVBL
WAITVBL2:
    CALL VDPREGIN
    AND $80
    CP 0
    JR Z, WAITVBL2
    RET
