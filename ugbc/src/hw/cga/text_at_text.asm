; ; /*****************************************************************************
; ;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
; ;  *****************************************************************************
; ;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
; ;  *
; ;  * Licensed under the Apache License, Version 2.0 (the "License");
; ;  * you may not use this file except in compliance with the License.
; ;  * You may obtain a copy of the License at
; ;  *
; ;  * http://www.apache.org/licenses/LICENSE-2.0
; ;  *
; ;  * Unless required by applicable law or agreed to in writing, software
; ;  * distributed under the License is distributed on an "AS IS" BASIS,
; ;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; ;  * See the License for the specific language governing permissions and
; ;  * limitations under the License.
; ;  *----------------------------------------------------------------------------
; ;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
; ;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
; ;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
; ;  *
; ;  * http://www.apache.org/licenses/LICENSE-2.0
; ;  *
; ;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
; ;  * il software distribuito nei termini della Licenza è distribuito
; ;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
; ;  * implicite. Consultare la Licenza per il testo specifico che regola le
; ;  * autorizzazioni e le limitazioni previste dalla medesima.
; ;  ****************************************************************************/
; ;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; ;*                                                                             *
; ;*                      TEXT AT GIVEN POSITION ON MSX1                         *
; ;*                                                                             *
; ;*                             by Marco Spedaletti                             *
; ;*                                                                             *
; ;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SI - text to print
; CL - size of text
TEXTATTILEMODE:

;     LD A, (CURRENTTILEMODE)
;     CP 0
;     RET Z

    MOV AL, [CURRENTTILEMODE]
    CMP AL, 0
    JZ TEXTATTILEMODEDONE

;     LD A, C
;     CP 0
;     JNZ TEXTATTILEMODEGO
;     JP TEXTATTILEMODEDONE

    CMP CL, 0
    JZ TEXTATTILEMODEDONE

TEXTATTILEMODEGO:
    PUSH CX
;     PUSH DE

;     LD A, (CURRENTTILESWIDTH)
;     LD E, A
;     LD D, 0

;     LD A, (CURRENTMODE)
;     CP 0
;     JZ TEXTATTILEMODEGO0

    MOV AL, [CURRENTMODE]
    CMP AL, 0
    JZ TEXTATTILEMODEGO0

;     CP 1
;     JZ TEXTATTILEMODEGO1
;     CP 2
;     JZ TEXTATTILEMODEGO2
;     CP 3
;     JZ TEXTATTILEMODEGO3
    RET

TEXTATTILEMODEGO0:
; TEXTATTILEMODEGO1:
;     LD HL, (TEXTADDRESS)
;     LD [COPYOFTEXTADDRESS], HL
;     JMP TEXTATTILEMODEGOX

    MOV DI, [TEXTADDRESS]
    MOV [COPYOFTEXTADDRESS], DI
    JP TEXTATTILEMODEGOX

; TEXTATTILEMODEGO2:
; TEXTATTILEMODEGO3:
;     LD HL, (TEXTADDRESS)
;     LD [COPYOFTEXTADDRESS], HL
;     JMP TEXTATTILEMODEGOX

TEXTATTILEMODEGOX:
;     LD A, 0
;     LD B, A
;     LD (TABSTODRAW), A

    MOV BL, 0
    MOV [TABSTODRAW], BL

;     LD A, (YCURSYS)
;     CP 0
;     JZ  TEXTATSKIP

    MOV CL, [YCURSYS]
    CMP CL, 0
    JZ  TEXTATSKIP

;     LD C, A
;     LD HL, [COPYOFTEXTADDRESS]

    MOV DI, [COPYOFTEXTADDRESS]

TEXTATLOOP1:
;     ADD HL, DE
    ADD DI, [CURRENTTILESWIDTH]
;     DEC C
    DEC CL
;     JNZ  TEXTATLOOP1
    CMP CL, 0
    JNZ  TEXTATLOOP1
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI

TEXTATSKIP:
;     LD A, (XCURSYS)
    MOV CL, [XCURSYS]
    MOV CH, 0
;     LD E, A
;     LD A, 0
;     LD D, 0
;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]
;     ADD HL, DE
    ADD DI, CX
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI

;     POP DE
;     POP BC
    POP CX

TEXTATLOOP2:

;     LD A, (TABSTODRAW)
    MOV AL, [TABSTODRAW]
;     CP 0
    CMP AL, 0
;     JZ TEXTATNSKIPTAB
    JZ TEXTATNSKIPTAB
;     JMP TEXTATSKIPTAB
    JP TEXTATSKIPTAB

TEXTATNSKIPTAB:
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL

;     CP 31
;     JR C,TEXTATCC
    CMP AL, 31
    JC TEXTATCC

TEXTATXCC:
    CALL TEXTATDECODE
    JP TEXTATSP0

TEXTATTAB:
;     LD A, (TABCOUNT)
;     LD B, A
;     LD A, (XCURSYS)
    MOV AL, [XCURSYS]
TEXTATTAB2:
;     CP B
    CMP AL, [TABCOUNT]
;     JR C, TEXTATTAB3
    JC TEXTATTAB3
;     SUB A, B
    SUB AL, [TABCOUNT]
    JP TEXTATTAB2
TEXTATTAB3:
;     LD B, A
    MOV BL, AL
;     LD A, (TABCOUNT)
    MOV AL, [TABCOUNT]
;     SUB A, B
    SUB AL, BL
;     LD (TABSTODRAW), A
    MOV [TABSTODRAW], AL
    JP TEXTATNEXT

TEXTATCC:
    CMP AL, 13
    JZ TEXTATLF
    CMP AL, 10
    JZ TEXTATLF
    CMP AL, 9
    JZ TEXTATTAB
    CMP AL, 1
    JZ TEXTATPEN
    CMP AL, 2
    JZ TEXTATPAPER
    CMP AL, 3
    JZ TEXTATCMOVEPREPARE
    CMP AL, 4
    JZ TEXTATXAT
    CMP AL, 5
    JZ TEXTATCLS
    JMP TEXTATNEXT

TEXTATCLS:
;     PUSH AF
;     PUSH DE
;     PUSH HL
;     PUSH BC
;     CALL CLST
;     POP BC
;     POP HL
;     POP DE
;     POP AF
    JP TEXTATNEXT

TEXTATLF:
    JP TEXTATNEXT2

TEXTATXAT:
    JP TEXTATAT

TEXTATPEN:
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL
;     CP $FF
    CMP AL, 0xff
    JNZ TEXTATPEN2
;     JNZ  TEXTATPEN2
;     LD A, 0
    MOV AL, 0
TEXTATPEN2:
;     LD (_PEN), A
    MOV [_PEN], AL
    JP TEXTATNEXT

TEXTATPAPER:
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL
    JP TEXTATNEXT

TEXTATCMOVEPREPARE:
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL

;     LD (CLINEX), A

    MOV [CLINEX], AL
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL
;     LD (CLINEY), A
    MOV [CLINEY], AL

TEXTATCMOVE:
;     LD A, (XCURSYS)
;     LD B, A
    MOV AL, [XCURSYS]
;     LD A, (CLINEX)
;     ADD A, B
    ADD AL, [CLINEX]
;     CP $80
    CMP AL, 0x80
;     JR NC, TEXTATCMOVESKIPX
    JNC TEXTATCMOVESKIPX
;     PUSH AF
;     LD A, (CURRENTTILESWIDTH)
;     LD B, A
;     POP AF
;     CP B
    CMP AL, [CURRENTTILESWIDTH]
;     JR NC, TEXTATCMOVESKIPX
    JNC TEXTATCMOVESKIPX
;     LD (XCURSYS), A
;     LD A, (CLINEX)
    MOV [XCURSYS], AL
    MOV AL, [CLINEX]

;     CP $80
;     JR C, TEXTATCMOVEADDPX
    CMP AL, 0x80
    JC TEXTATCMOVEADDPX

TEXTATCMOVESUBPX:
;     XOR $FF
    XOR AL, 0xff
;     ADD 1
    INC AL
;     LD (CLINEX), A
    MOV [CLINEX], AL

;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]
;     PUSH DE
;     LD E, A
;     LD D, 0
;     SBC HL, DE
    MOV AH, 0
    SUB DI, AX
;     POP DE
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI
    JP TEXTATCMOVESKIPX

TEXTATCMOVEADDPX:

;     LD (CLINEX), A
    MOV [CLINEX], AL

;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]

;     PUSH DE
;     LD E, A
;     LD D, 0
;     ADD HL, DE
;     POP DE
    MOV AH, 0
    ADD DI, AX
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI
    JP TEXTATCMOVESKIPX

TEXTATCMOVESKIPX:

;     LD A, (YCURSYS)
;     LD B, A
;     LD A, (CLINEY)
;     ADD A,B

    MOV AL, [YCURSYS]
    ADD AL, [CLINEY]

;     CP $80
;     JR NC, TEXTATCMOVESKIPY

    CMP AL, 0x80
    JNC TEXTATCMOVESKIPY

;     CP 26
;     JR NC, TEXTATCMOVESKIPY

    CMP AL, 26
    JNC TEXTATCMOVESKIPY

;     LD (YCURSYS), A

    MOV [YCURSYS], AL

TEXTATCMOVEADDPY:
;     LD A, (CLINEY)
    MOV AL, [CLINEY]
;     CP $80
;     JR C, TEXTATCMOVELOOPYP
    CMP AL, 0x80
    JC TEXTATCMOVELOOPYP
;     JMP TEXTATCMOVELOOPYM
    JP TEXTATCMOVELOOPYM

TEXTATCMOVELOOPYP:
;     PUSH BC
    PUSH CX
;     LD C, A
    MOV CL, AL
;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]
;     PUSH DE
;     LD A, (CURRENTTILESWIDTH) 
;     LD E, A
;     LD D, 0
TEXTATCMOVELOOPY:
;     ADD HL, DE
    ADD DI, [CURRENTTILESWIDTH]
;     DEC C
    DEC CL
    CMP CL, 0
    JNZ TEXTATCMOVELOOPY
;     JNZ  TEXTATCMOVELOOPY
;     POP DE
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI
;     POP BC
    POP CX
    JP TEXTATCMOVESKIPY

TEXTATCMOVELOOPYM:
;     XOR $FF
;     ADD A, 1
;     LD (CLINEY), A
    XOR AL, 0xff
    INC AL
    MOV [CLINEY], AL

;     PUSH BC
    PUSH CX
;     LD C, A
    MOV CL, AL
;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]
TEXTATCMOVELOOPY2:
;     PUSH DE
;     LD A, (CURRENTTILESWIDTH) 
;     LD E, A
;     LD D, 0
;     SBC HL, DE
    SUB DI, [CURRENTTILESWIDTH]
;     POP DE
;     LD A, C
    DEC CL
    CMP CL, 0
;     JNZ  TEXTATCMOVELOOPY2
    JNZ TEXTATCMOVELOOPY2
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI
;     POP BC
    POP CX
    JP TEXTATCMOVESKIPY

TEXTATCMOVESKIPY:
    JMP TEXTATNEXT

TEXTATAT:
;     LD A, (XCURSYS)
;     LD B, A
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL
;     SUB A, B
    SUB AL, [XCURSYS]
;     LD B, A
;     LD A, (CONSOLEX1)
;     ADD A, B
    ADD AL, [CONSOLEX1]
;     LD (CLINEX), A
    MOV [CLINEX], AL
;     LD A, (YCURSYS)
    MOV AL, [YCURSYS]
;     LD B, A
    MOV BL, AL
;     LD A, (DE)
;     INC DE
;     DEC C
    MOV AL, [SI]
    INC SI
    DEC CL
;     SUB A, B
    SUB AL, BL
;     LD B, A
    MOV BL, AL
;     LD A, (CONSOLEY1)
;     ADD A, B
    ADD AL, [CONSOLEY1]
;     LD (CLINEY), A
    MOV [CLINEY], AL
    JP TEXTATCMOVE

TEXTATSP0:
;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]

;     PUSH AF
;     PUSH DE
;     PUSH BC
;     LD DE, HL
;     LD BC, 1
;     CALL VDPOUTCHAR
;     POP BC
;     POP DE
;     POP AF

    MOV BYTE [ES:DI], AL
    
;     PUSH AF
;     LD A, (CURRENTMODE)
;     CP 0
;     JZ TEXTAT20
;     CP 1
;     JZ TEXTAT21
;     CP 2
;     JZ TEXTAT22
;     CP 3
;     JZ TEXTAT23
;     POP AF
;     RET

; TEXTAT20:
; TEXTAT21:
;     POP AF
;     PUSH HL
;     PUSH AF
;     PUSH DE
;     PUSH BC

;     SRL A
;     SRL A
;     SRL A
;     LD E, A
;     LD A, 0
;     LD D, A

;     LD HL, $480
;     ADD HL, DE
;     LD DE, HL
;     LD A, (_PEN)
;     SLA A
;     SLA A
;     SLA A
;     SLA A
;     LD BC, 1
;     CALL VDPOUTCHAR
;     POP BC
;     POP DE
;     POP AF
;     POP HL

;     JMP TEXTAT2X

; TEXTAT22:
; TEXTAT23:
;     POP AF
;     PUSH HL
;     PUSH AF
;     PUSH DE
;     PUSH BC

;     LD L, A
;     LD A, 0
;     LD H, A
;     ADD HL, HL
;     ADD HL, HL
;     ADD HL, HL
;     LD DE, HL

;     PUSH DE
;     LD HL, (COLORMAPADDRESS)
;     ADD HL, DE
;     LD DE, HL
;     LD A, (_PEN)
;     SLA A
;     SLA A
;     SLA A
;     SLA A
;     LD BC, 1
;     CALL VDPFILL8
;     POP DE

;     PUSH DE
;     LD HL, (COLORMAPADDRESS)
;     LD DE, $800
;     ADD HL, DE
;     POP DE
;     PUSH DE
;     ADD HL, DE
;     LD DE, HL
;     LD A, (_PEN)
;     SLA A
;     SLA A
;     SLA A
;     SLA A
;     LD BC, 1
;     CALL VDPFILL8
;     POP DE

;     PUSH DE
;     LD HL, (COLORMAPADDRESS)
;     LD DE, $1000
;     ADD HL, DE
;     POP DE
;     PUSH DE
;     ADD HL, DE
;     LD DE, HL
;     LD A, (_PEN)
;     SLA A
;     SLA A
;     SLA A
;     SLA A
;     LD BC, 1
;     CALL VDPFILL8
;     POP DE

;     POP BC
;     POP DE
;     POP AF
;     POP HL

;     JMP TEXTAT2X

TEXTAT2X:
    JP TEXTATINCX

TEXTATSKIPTAB:
;     LD A, (TABSTODRAW)
;     DEC A
;     LD (TABSTODRAW),A
    MOV AL, [TABSTODRAW]
    DEC AL
    MOV [TABSTODRAW], AL
;     CP 0
    CMP AL, 0
;     JNZ  TEXTATSKIPTAB2
    JNZ TEXTATSKIPTAB2
TEXTATSKIPTAB2:
;     LD HL, [COPYOFTEXTADDRESS]
;     INC HL
;     LD [COPYOFTEXTADDRESS], HL
    MOV DI, [COPYOFTEXTADDRESS]
    INC DI
    MOV [COPYOFTEXTADDRESS], DI
;     LD A, (XCURSYS)
;     INC A
;     LD (XCURSYS), A
    MOV AL, [XCURSYS]
    INC AL
    MOV [XCURSYS], AL
    JP TEXTATCHECKCONSOLE

TEXTATINCX:
;     LD HL, [COPYOFTEXTADDRESS]
;     INC HL
;     LD [COPYOFTEXTADDRESS], HL
    MOV DI, [COPYOFTEXTADDRESS]
    INC DI
    MOV [COPYOFTEXTADDRESS], DI
;     LD A, (XCURSYS)
;     INC A
;     LD (XCURSYS), A
    MOV AL, [XCURSYS]
    INC AL
    MOV [XCURSYS], AL
;     LD A, C
    CMP CL, 0
    JZ TEXTATEND2
;     JP Z, TEXTATEND2

TEXTATCHECKCONSOLE:
;     PUSH AF
;     LD A, (CONSOLEX2)
;     LD B, A
;     POP AF
;     CP B
    CMP AL, [CONSOLEX2]
;     JNZ  TEXTATNEXT
    JNZ TEXTATNEXT
;     JR NC, TEXTATNEXT2
    JNC TEXTATNEXT2
    JP TEXTATNEXT
TEXTATNEXT2:
;     PUSH DE
;     LD A, (CURRENTTILESWIDTH)
;     LD E, A
;     LD D, 0
;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]
;     AND A
;     ADC HL, DE
    ADD DI, [CURRENTTILESWIDTH]
;     LD A, (XCURSYS)    
    MOV AL, [XCURSYS]
    MOV AH, 0
;     LD E, A
;     LD D, 0
;     AND A
;     SBC HL, DE
    SUB DI, AX
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI
;     POP DE
;     LD A, (CONSOLEX1)
    MOV AL, [CONSOLEX1]
;     LD (XCURSYS), A
    MOV [XCURSYS], AL
;     LD A, (YCURSYS)
;     INC A
;     LD (YCURSYS), A
    MOV AL, [YCURSYS]
    INC AL
    MOV [YCURSYS], AL
;     PUSH AF
;     LD A, (CONSOLEY2)
;     LD B, A
;     POP AF
;     CP B
    CMP AL, [CONSOLEY2]

;     JZ  TEXTATNEXT
    JZ TEXTATNEXT
;     JR NC, TEXTATNEXT3
    JNC TEXTATNEXT3
;     JMP TEXTATNEXT
    JP TEXTATNEXT

TEXTATNEXT3:

;     PUSH AF
;     PUSH BC
;     PUSH DE
;     PUSH HL
;     ; if __coleco__
;     ;     CALL VSCROLLTUPNMI
;     ; else
;         CALL VSCROLLTUP
;     ; endif
;     POP HL
;     POP DE
;     POP BC
;     POP AF

;     LD A, (YCURSYS)
;     DEC A
;     LD (YCURSYS), A
    MOV AL, [YCURSYS]
    DEC AL
    MOV [YCURSYS], AL
;     LD HL, [COPYOFTEXTADDRESS]
    MOV DI, [COPYOFTEXTADDRESS]
;     PUSH DE
;     LD A, (CURRENTTILESWIDTH) 
;     LD E, A
;     LD D, 0
;     SBC HL, DE
;     POP DE
    SUB DI, [CURRENTTILESWIDTH]
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI

TEXTATNEXT:
;     LD A, (TABSTODRAW)
;     CP 0
    MOV AL, [TABSTODRAW]
;     JZ  TEXTATXLOOP2
    JZ TEXTATXLOOP2
    JP TEXTATLOOP2

TEXTATXLOOP2:
;     LD A, C
;     CP 0
;     JZ  TEXTATTILEMODEDONE
    CMP CL, 0
    JZ TEXTATTILEMODEDONE
    JP TEXTATLOOP2
TEXTATEND:
TEXTATEND2:
    JP TEXTATTILEMODEDONE

TEXTATTILEMODEDONE:
    RET