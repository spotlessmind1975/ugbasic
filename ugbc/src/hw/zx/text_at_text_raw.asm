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

; Print String Data
; L: X coordinate
; H: Y coordinate
; C: String size
; IX: Address of string
;
LIBPRINTRAWSTRING:
    LD A, C
    CP 0
    RET Z
    ; LD L, (IX+0)			    ; Fetch the X coordinate
    ; INC IX				    ; Increase HL to the next memory location
    ; LD H,(IX+0)			    ; Fetch the Y coordinate
    ; INC IX				    ; Increase HL to the next memory location
    CALL LIBGETCHARADDRESS      ; Calculate the screen address (in DE)
LIBPRINTRAWSTRING0:
    LD A, (IX)			        ; Fetch the character to print
    INC IX				        ; Increase HL to the next character
    DEC C
    CALL LIBPRINTCHAR

    INC L				        ; Go to the next screen address
    INC IY
    LD A, (XCURSYS)
    ADD 1
    LD (XCURSYS), A
    LD A, C
    CP 0
    JP Z, LIBPRINTRAWSTRING1B
    LD A, (CONSOLEX2)
    LD B, A
    LD A, (XCURSYS)
    CP B
    JR Z, LIBPRINTRAWSTRING1A
    JR NC, LIBPRINTRAWSTRINGLF
    JP LIBPRINTRAWSTRING1A

LIBPRINTRAWSTRINGTABN:
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
    JP Z, LIBPRINTRAWSTRING1D
    JP C, LIBPRINTRAWSTRING1D
    JP LIBPRINTRAWSTRINGLF
LIBPRINTRAWSTRINGLF:
    LD A, (CONSOLEX1)
    LD (XCURSYS), A
    LD A, (YCURSYS)
    INC A
    LD (YCURSYS), A
    LD A, (CONSOLEY2)
    LD B, A
    LD A, (YCURSYS)
    CP B
    JR Z, LIBPRINTRAWSTRING1D
    JR NC, LIBPRINTRAWSTRING1C
    JP LIBPRINTRAWSTRING1D
LIBPRINTRAWSTRING1C:
    LD A, -8
    LD B, A
    CALL VSCROLL
    LD A, (YCURSYS)
    DEC A
    LD (YCURSYS), A
LIBPRINTRAWSTRING1D:
    LD A, (XCURSYS)
    LD L, A
    LD A, (YCURSYS)
    LD H, A
    CALL LIBGETCHARADDRESS
LIBPRINTRAWSTRING1A:
    JP NZ, LIBPRINTRAWSTRING0
LIBPRINTRAWSTRING1B:
    RET

; Print String Data
; C: String size
; IX: Address of string

TEXTATRAW:
    PUSH HL
    POP IX
    LD A, (XCURSYS)
    LD L, A
    LD A, (YCURSYS)
    LD H, A
    CALL LIBPRINTRAWSTRING
    RET

