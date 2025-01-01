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
;*                      TEXT AT GIVEN POSITION ON ZX SPECTRUM                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;
; Title:	ZX Spectrum Standard Output Routines
; Author:	Dean Belfield
; Created:	29/07/2011
; Last Updated:	13/05/2025
;
; Requires:
;
; Modinfo:
;
; 13/05/2025:	Adapted for ugBASIC by Marco Spedaletti
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
