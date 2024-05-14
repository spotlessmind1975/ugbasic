; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                      TEXT AT GIVEN POSITION ON ZX SPECTRUM                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;
; Title:	ZX Spectrum Standard Output Routines
; Author:	Dean Belfield
; Created:	29/07/2011
; Last Updated:	13/05/2024
;
; Requires:
;
; Modinfo:
;
; 13/05/2024:	Adapted for ugBASIC by Marco Spedaletti
; 02/07/2012:	Added Pixel_Address_Down and Pixel_Address_Up routines
; 04/07/2012:	Moved Clear_Screen to Screen_Buffer
; 08/02/2010:	Added Print_BC
;		Moved Clear_Screen into here (originally in screen_buffer.z80)
;		All output routines refactored to use HL for screen address
;		Added Fill_Attr routine
;

; Fill a box of the screen with a solid colour
;  A: The colour
; HL: Address in the attribute map
;  C: Width
;  B: Height
;
LIBFILLATTR:
    LD DE,32
LIBFILLATTRL1:
    PUSH HL	
    PUSH BC
LIBFILLATTRL2:
    LD (HL), A
    INC L
    DEC C
    JR NZ, LIBFILLATTRL2
    POP BC
    POP HL
    ADD HL, DE
    DJNZ LIBFILLATTRL1
    RET

; Get screen address
; H = Y character position
; L = X character position
; Returns text address in HL and colormap address in IY
;
LIBGETCHARADDRESS:
    PUSH HL
    POP IY
    LD A,H
    AND %00000111
    RRA
    RRA
    RRA
    RRA
    OR L
    LD L,A
    LD A,H
    AND %00011000
    OR %01000000
    LD H,A

    PUSH HL
    LD HL, $5800
    LD A, IYH
    CP 0
    JP Z, LIBGETCHARADDRESSR
LIBGETCHARADDRESSL1:
    ADD HL, 32
    DEC IYH
    JR NZ, LIBGETCHARADDRESSL1
LIBGETCHARADDRESSR:
    PUSH DE
    LD D,0
    LD A, IYL
    LD E, A
    ADD HL, DE
    POP DE
    PUSH HL
    POP IY
    POP HL
    RET				; Returns screen address in HL

; Move HL down one character line
;
LIBCHARADDRESSDOWN:
    LD A, L
    ADD A, 32
    LD L, A
    RET NC 
    LD A, H 
    ADD A, 8 
    LD H, A
    RET 

; Print a single character out to a screen address
;  A:  Character to print
;  HL: Screen address to print character at
;  DE: Address of character set (if entering at Print_Char_UDG)
; No SM code here - needs to be re-enterent if called on interrupt
;
LIBPRINTCHAR:
    PUSH BC
    LD DE, 0x3C00			; Address of character set in ROM
    PUSH HL
    LD B, 0				    ; Get index into character set
    LD C, A
    SLA C
    RL B
    SLA C
    RL B
    SLA C
    RL B
    EX DE, HL
    ADD HL, BC 
    EX DE, HL	
    CALL LIBPRINTUDG8
    POP HL
    POP BC   
    RET 	

; Print a UDG (Single Height)
; DE - Character data
; HL - Screen address
; IY - Color address
;
LIBPRINTUDG8:
    PUSH IX
    LD A, (_PAPER)
    AND $07
    SLA A
    SLA A
    SLA A
    LD B, A
    PUSH BC
    LD A, (_PEN)
    AND $07
    LD B, A
    LD A, (_PEN)
    AND $08
    SLA A
    SLA A
    SLA A
    OR A, B    
    POP BC
    OR A, B
    LD IXH, A
    LD B, 8 			    ; Loop counter
LIBPRINTUDG82:
    LD A, (DE)			    ; Get the byte from the ROM into A
    LD (HL), A			    ; Stick A onto the screen
    INC DE				    ; Goto next byte of character
    INC H				    ; Goto next line on screen
    DJNZ LIBPRINTUDG82      ; Loop around whilst it is Not Zero (NZ)
    LD A, IXH
    LD (IY), A
    POP IX
    RET

; Print String Data
; L: X coordinate
; H: Y coordinate
; C: String size
; IX: Address of string
;
LIBPRINTSTRING:
    LD A, C
    CP 0
    RET Z
    ; LD L, (IX+0)			    ; Fetch the X coordinate
    ; INC IX				    ; Increase HL to the next memory location
    ; LD H,(IX+0)			    ; Fetch the Y coordinate
    ; INC IX				    ; Increase HL to the next memory location
    CALL LIBGETCHARADDRESS      ; Calculate the screen address (in DE)
LIBPRINTSTRING0:
    LD A, (IX)			        ; Fetch the character to print
    INC IX				        ; Increase HL to the next character
    CP 13
    JP Z, LIBPRINTSTRINGLF
    CP 10
    JP Z, LIBPRINTSTRINGLF
    CP 9
    JP Z, LIBPRINTSTRINGTAB
    CP 1
    JP Z, LIBPRINTSTRINGPEN
    CP 2
    JP Z, LIBPRINTSTRINGPAPER
    CP 3
    JP Z, LIBPRINTSTRINGCMOVE
    CP 4
    JP Z, LIBPRINTSTRINGATAT
    CALL LIBPRINTCHAR
    INC L				        ; Go to the next screen address
    INC IY
    LD A, (XCURSYS)
    ADD 1
    LD (XCURSYS), A
    LD A, (CONSOLEX2)
    LD B, A
    LD A, (XCURSYS)
    CP B
    JR Z, LIBPRINTSTRING1A
    JR NC, LIBPRINTSTRINGLF
    JP LIBPRINTSTRING1A

LIBPRINTSTRINGTAB:
    LD A, (TABCOUNT)
    LD B, A
    LD A, (XCURSYS)
LIBPRINTSTRINGTABL:
    SBC A, B
    JP Z, LIBPRINTSTRINGTABN
    JP M, LIBPRINTSTRINGTABN
    JR LIBPRINTSTRINGTABL
LIBPRINTSTRINGTABN:
    XOR $FF
    ADD 1
    LD B, A
    LD A, (XCURSYS)
    ADD A, B
    LD (XCURSYS), A
    PUSH AF
    LD A, (CONSOLEX2)
    LD B, A
    POP AF
    CP B
    JP C, LIBPRINTSTRING1D
    JP LIBPRINTSTRINGLF
LIBPRINTSTRINGLF:
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    LD A, (CONSOLEY2)
    LD B, A
    LD A, (YCURSYS)
    CP B
    JR Z, LIBPRINTSTRING1D
    JR NC, LIBPRINTSTRING1C
    JP LIBPRINTSTRING1D
LIBPRINTSTRING1C:
    LD A, -8
    LD B, A
    CALL VSCROLL
    LD A, (YCURSYS)
    DEC A
    LD (YCURSYS), A
LIBPRINTSTRING1D:
    LD A, (XCURSYS)
    LD L, A
    LD A, (YCURSYS)
    LD H, A
    CALL LIBGETCHARADDRESS
LIBPRINTSTRING1A:
    DEC C                       ; Decrease C of the string
    JP NZ, LIBPRINTSTRING0
    RET

LIBPRINTSTRINGATAT:
    LD A, (IX)
    INC IX
    DEC C
    LD (XCURSYS), A
    LD A, (IX)
    INC IX
    DEC C
    LD (YCURSYS), A
    JP LIBPRINTSTRING1D

LIBPRINTSTRINGCMOVE:
    LD A, (IX)
    INC IX
    DEC C
    LD B, A
    LD A, (XCURSYS)
    ADD B
    LD (XCURSYS), A
    LD A, (IX)
    INC IX
    DEC C
    LD B, A
    LD A, (YCURSYS)
    ADD B
    LD (YCURSYS), A
    JP LIBPRINTSTRING1D

LIBPRINTSTRINGPEN:
    LD A, (IX)
    INC IX
    DEC C
    LD (_PEN), A
    JP LIBPRINTSTRING1A

LIBPRINTSTRINGPAPER:
    LD A, (IX)
    INC IX
    DEC C
    LD (_PAPER), A
    JP LIBPRINTSTRING1A

; Print String Data
; C: String size
; IX: Address of string

TEXTAT:
    PUSH HL
    POP IX
    LD A, (XCURSYS)
    LD L, A
    LD A, (YCURSYS)
    LD H, A
    CALL LIBPRINTSTRING
    RET

; TEXTAT:
; TEXTATL:
;     INC HL
;     CP 14
;     JP C, TEXTATCC
;     CP 32
;     JP C, TEXTATL
;     PUSH DE
;     PUSH HL
;     PUSH BC
;     CALL TEXTATPC
;     POP BC
;     POP HL
;     POP DE
;     INC E
; TEXTATNEXTCOLCHK:    
;     LD A, E
;     CP 32
;     JP C, TEXTATNEXTCOL
;     LD E, 0
;     INC D
;     LD A, D
;     CP 24
;     JP C, TEXTATNEXTCOL

; TEXTATVSCROLL:
;     DEC D

;     PUSH DE
;     PUSH HL
;     PUSH BC

;     LD A, $F8
;     CALL VSCROLL

;     POP BC
;     POP HL
;     POP DE
;     JMP TEXTATNEXTCOL

; TEXTATCC:
;     CP 13
;     JP Z, TEXTATLF
;     CP 10
;     JP Z, TEXTATLF
;     CP 9
;     JP Z, TEXTATTAB
;     CP 1
;     JP Z, TEXTATPEN
;     CP 2
;     JP Z, TEXTATPAPER
;     CP 3
;     JP Z, TEXTATCMOVE
;     CP 4
;     JP Z, TEXTATAT
;     JMP TEXTATNEXTCOL

; TEXTATTAB:
;     LD A, E
; TEXTATTABL:
;     LD A, (TABCOUNT)
;     LD B, A
;     SBC A, B
;     JP Z, TEXTATTABN
;     JP M, TEXTATTABN
;     JMP TEXTATTABL
; TEXTATTABN:
;     ADD A, B
;     ADD A, E
;     LD E, A
;     CP 32
;     JP C, TEXTATNEXTCOL
;     LD E, 0
;     INC D
;     CP 24
;     JP C, TEXTATNEXTCOL
;     JMP TEXTATVSCROLL

; TEXTATPEN:
;     LD A, (HL)
;     CP $FF
;     JR NZ, TEXTATPEN2
;     LD A, 0
; TEXTATPEN2:    
;     INC HL
;     DEC C
;     LD (_PEN), A
;     JMP TEXTATNEXTCOL

; TEXTATPAPER:
;     LD A, (HL)
;     INC HL
;     DEC C
;     LD (_PAPER), A
;     JMP TEXTATNEXTCOL

; TEXTATAT:
;     LD A, (HL)
;     INC HL
;     DEC C
;     LD E, A   
;     LD A, (HL)
;     INC HL
;     DEC C
;     LD D, A
;     CP 24
;     JP C, TEXTATAT2
;     JMP TEXTATVSCROLL
; TEXTATAT2:
;     LD A, E
;     CP 32
;     JP C, TEXTATNEXTCOLCHK
;     LD E, 0
;     INC D
;     CP 24
;     JP C, TEXTATNEXTCOLCHK
;     JMP TEXTATVSCROLL

; TEXTATCMOVE:
;     LD A, (HL)
;     INC HL
;     DEC C
;     ADD A, E
;     LD E, A
;     LD A, (HL)
;     INC HL
;     DEC C
;     ADD A, D
;     LD D, A
;     CP 24
;     JP C, TEXTATCMOVE2
;     JMP TEXTATVSCROLL
; TEXTATCMOVE2:
;     LD A, E
;     CP 32
;     JP C, TEXTATNEXTCOLCHK
;     LD E, 0
;     INC D
;     CP 24
;     JP C, TEXTATNEXTCOLCHK
;     JMP TEXTATVSCROLL

; TEXTATLF:
;     LD A, 32
;     LD E, A
;     JMP TEXTATNEXTCOLCHK

; TEXTATNEXTCOL:
;     INC C
;     DEC C
;     JP NZ, TEXTATL
;     LD A, D
;     LD (YCURSYS), A
;     LD A, E
;     LD (XCURSYS), A
;     RET

; TEXTATPC:
;     PUSH AF
;     PUSH DE
;     LD HL, $5800
;     LD A, D
;     CP 0
;     JP Z, TEXTATROW

; TEXTATPC2:
;     ADD HL, 32
;     DEC D
;     JP NZ, TEXTATPC2
; TEXTATROW:
;     PUSH DE
;     LD D,0
;     ADD HL, DE
;     POP DE
;     POP DE
;     LD A, (HL)
;     AND $38
;     LD B, A
;     LD A, (_PAPER)
;     AND $0F
;     SLA A
;     SLA A
;     SLA A
;     LD B, A
;     PUSH BC
;     LD A, (_PEN)
;     AND $07
;     OR A, B
;     LD B, A
;     LD A, (_PEN)
;     AND $08
;     SLA A
;     SLA A
;     SLA A
;     OR A, B    
;     POP BC
;     JMP TEXTATPC5
;     LD A, (HL)
;     AND $07
; TEXTATPC5:
;     OR A, B
;     LD (HL), A

;     POP AF
;     LD HL, $3C00
;     LD B,0
;     LD C, A
;     SLA C
;     RL B
;     SLA C
;     RL B
;     SLA C
;     RL B
;     ADD HL, BC
;     CALL TEXTATGC
;     LD B,8
; TEXTATL1:
;     LD A, (HL)
;     LD (DE),A
;     INC HL
;     INC D
;     DJNZ TEXTATL1
;     RET
; TEXTATGC:
;     LD A,D
;     AND %00000111
;     RRA
;     RRA
;     RRA
;     RRA
;     OR E
;     LD E,A
;     LD A,D
;     AND %00011000
;     OR %01000000
;     LD D,A
;     RET

