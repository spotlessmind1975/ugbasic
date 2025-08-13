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
;*                      TEXT AT GIVEN POSITION ON CGA                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SI - text to print
; CL - size of text
TEXTATTILEMODE:

    MOV AL, [CURRENTTILEMODE]
    CMP AL, 0
    JZ TEXTATTILEMODEDONE

    CMP CL, 0
    JZ TEXTATTILEMODEDONE

TEXTATTILEMODEGO:
    MOV AL, [CURRENTMODE]
    CMP AL, 3
    JBE TEXTATTILEMODEGO0
    RET

TEXTATTILEMODEGO0:
    PUSH CX

    MOV DI, [TEXTADDRESS]
    MOV [COPYOFTEXTADDRESS], DI
    JMP TEXTATTILEMODEGOX

TEXTATTILEMODEGOX:
    MOV BL, 0
    MOV [TABSTODRAW], BL

    MOV CL, [YCURSYS]
    CMP CL, 0
    JZ  TEXTATSKIP

    MOV DI, [COPYOFTEXTADDRESS]
    MOV AL, [CURRENTTILESWIDTH]
    MOV AH, 0

TEXTATLOOP1:
    ADD DI, AX
    ADD DI, AX
    DEC CL
    CMP CL, 0
    JNZ  TEXTATLOOP1
    MOV [COPYOFTEXTADDRESS], DI

TEXTATSKIP:
    MOV CL, [XCURSYS]
    MOV CH, 0
    MOV DI, [COPYOFTEXTADDRESS]
    ADD DI, CX
    MOV [COPYOFTEXTADDRESS], DI
    POP CX

TEXTATLOOP2:

    MOV AL, [TABSTODRAW]
    CMP AL, 0
    JZ TEXTATNSKIPTAB
    JMP TEXTATSKIPTAB

TEXTATNSKIPTAB:
    MOV AL, [SI]
    INC SI
    DEC CL

    CMP AL, 31
    JC TEXTATCC

TEXTATXCC:
    JMP TEXTATSP0

TEXTATTAB:
    MOV AL, [XCURSYS]
TEXTATTAB2:
    CMP AL, [TABCOUNT]
    JC TEXTATTAB3
    SUB AL, [TABCOUNT]
    JMP TEXTATTAB2
TEXTATTAB3:
    MOV BL, AL
    MOV AL, [TABCOUNT]
    SUB AL, BL
    MOV [TABSTODRAW], AL
    JMP TEXTATNEXT

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
    PUSH SI
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    CALL CLST
    POP DX
    POP CX
    POP BX
    POP AX
    POP SI
    JMP TEXTATNEXT

TEXTATLF:
    JMP TEXTATNEXT2

TEXTATXAT:
    JMP TEXTATAT

TEXTATPEN:
    MOV AL, [SI]
    INC SI
    DEC CL
    CMP AL, 0xff
    JNZ TEXTATPEN2
    MOV AL, 0
TEXTATPEN2:
    MOV [_PEN], AL
    JMP TEXTATNEXT

TEXTATPAPER:
    MOV AL, [SI]
    INC SI
    DEC CL
    JMP TEXTATNEXT

TEXTATCMOVEPREPARE:
    MOV AL, [SI]
    INC SI
    DEC CL

    MOV [CLINEX], AL
    MOV AL, [SI]
    INC SI
    DEC CL
    MOV [CLINEY], AL

TEXTATCMOVE:
    MOV AL, [XCURSYS]
    ADD AL, [CLINEX]
    CMP AL, 0x80
    JNC TEXTATCMOVESKIPX
    CMP AL, [CURRENTTILESWIDTH]
    JNC TEXTATCMOVESKIPX
    MOV [XCURSYS], AL
    MOV AL, [CLINEX]
    CMP AL, 0x80
    JC TEXTATCMOVEADDPX

TEXTATCMOVESUBPX:
    XOR AL, 0xff
    INC AL
    MOV [CLINEX], AL

    MOV DI, [COPYOFTEXTADDRESS]
    MOV AH, 0
    SUB DI, AX
    MOV [COPYOFTEXTADDRESS], DI
    JMP TEXTATCMOVESKIPX

TEXTATCMOVEADDPX:

    MOV [CLINEX], AL

    MOV DI, [COPYOFTEXTADDRESS]

    MOV AH, 0
    ADD DI, AX
    MOV [COPYOFTEXTADDRESS], DI
    JMP TEXTATCMOVESKIPX

TEXTATCMOVESKIPX:

    MOV AL, [YCURSYS]
    ADD AL, [CLINEY]

    CMP AL, 0x80
    JNC TEXTATCMOVESKIPY

    CMP AL, 26
    JNC TEXTATCMOVESKIPY

    MOV [YCURSYS], AL

TEXTATCMOVEADDPY:
    MOV AL, [CLINEY]
    CMP AL, 0x80
    JC TEXTATCMOVELOOPYP
    JMP TEXTATCMOVELOOPYM

TEXTATCMOVELOOPYP:
    PUSH CX
    MOV CL, AL
    MOV DI, [COPYOFTEXTADDRESS]
    MOV AL, [CURRENTTILESWIDTH]
    MOV AH, 0
TEXTATCMOVELOOPY:
    ADD DI, AX
    ADD DI, AX
    DEC CL
    CMP CL, 0
    JNZ TEXTATCMOVELOOPY
    MOV [COPYOFTEXTADDRESS], DI
    POP CX
    JMP TEXTATCMOVESKIPY

TEXTATCMOVELOOPYM:
    XOR AL, 0xff
    INC AL
    MOV [CLINEY], AL

    PUSH CX
    MOV CL, AL
    MOV DI, [COPYOFTEXTADDRESS]
    MOV AL, [CURRENTTILESWIDTH]
    MOV AH, 0    
TEXTATCMOVELOOPY2:
    SUB DI, AX
    SUB DI, AX
    DEC CL
    CMP CL, 0
    JNZ TEXTATCMOVELOOPY2
    MOV [COPYOFTEXTADDRESS], DI
    POP CX
    JMP TEXTATCMOVESKIPY

TEXTATCMOVESKIPY:
    JMP TEXTATNEXT

TEXTATAT:
    MOV AL, [SI]
    INC SI
    DEC CL
    SUB AL, [XCURSYS]
    ADD AL, [CONSOLEX1]
    MOV [CLINEX], AL
    MOV AL, [YCURSYS]
    MOV BL, AL
    MOV AL, [SI]
    INC SI
    DEC CL
    SUB AL, BL
    MOV BL, AL
    ADD AL, [CONSOLEY1]
    MOV [CLINEY], AL
    JMP TEXTATCMOVE

TEXTATSP0:
    MOV DI, [COPYOFTEXTADDRESS]

    MOV AH, [_PAPER]
    SAL AH, 1
    SAL AH, 1
    SAL AH, 1
    SAL AH, 1
    OR AH, [_PEN]
    MOV WORD [ES:DI], AX
    
TEXTAT2X:
    JMP TEXTATINCX

TEXTATSKIPTAB:
    MOV AL, [TABSTODRAW]
    DEC AL
    MOV [TABSTODRAW], AL
    CMP AL, 0
    JNZ TEXTATSKIPTAB2
TEXTATSKIPTAB2:
    MOV DI, [COPYOFTEXTADDRESS]
    INC DI
    INC DI
    MOV [COPYOFTEXTADDRESS], DI
    MOV AL, [XCURSYS]
    INC AL
    MOV [XCURSYS], AL
    JMP TEXTATCHECKCONSOLE

TEXTATINCX:
    MOV DI, [COPYOFTEXTADDRESS]
    INC DI
    INC DI
    MOV [COPYOFTEXTADDRESS], DI
    MOV AL, [XCURSYS]
    INC AL
    MOV [XCURSYS], AL
    CMP CL, 0
    JZ TEXTATEND2

TEXTATCHECKCONSOLE:
    CMP AL, [CONSOLEX2]
    JNZ TEXTATNEXT
    JNC TEXTATNEXT2
    JMP TEXTATNEXT
TEXTATNEXT2:
    MOV DI, [COPYOFTEXTADDRESS]
    MOV AL, [CURRENTTILESWIDTH]
    MOV AH, 0
    ADD DI, AX
    ADD DI, AX
    MOV AL, [XCURSYS]
    MOV AH, 0
    SUB DI, AX
    MOV [COPYOFTEXTADDRESS], DI
    MOV AL, [CONSOLEX1]
    MOV [XCURSYS], AL
    MOV AL, [YCURSYS]
    INC AL
    MOV [YCURSYS], AL
    CMP AL, [CONSOLEY2]

    JZ TEXTATNEXT
    JNC TEXTATNEXT3
    JMP TEXTATNEXT

TEXTATNEXT3:

    CALL VSCROLLTUP

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
    MOV AL, [CURRENTTILESWIDTH]
    MOV AH, 0
    SUB DI, AX
    SUB DI, AX
;     LD [COPYOFTEXTADDRESS], HL
    MOV [COPYOFTEXTADDRESS], DI

TEXTATNEXT:
;     LD A, (TABSTODRAW)
;     CP 0
    MOV AL, [TABSTODRAW]
    CMP AL, 0
;     JZ  TEXTATXLOOP2
    JZ TEXTATXLOOP2
    JMP TEXTATLOOP2

TEXTATXLOOP2:
;     LD A, C
;     CP 0
;     JZ  TEXTATTILEMODEDONE
    CMP CL, 0
    JZ TEXTATTILEMODEDONE
    JMP TEXTATLOOP2
TEXTATEND:
TEXTATEND2:
    JMP TEXTATTILEMODEDONE

TEXTATTILEMODEDONE:
    RET