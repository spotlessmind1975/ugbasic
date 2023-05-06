; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                         STARTUP ROUTINE FOR VDC                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; The RAM used by the VDCZ is isolated from the main C128 memory map. 
; It can only be accessed through two registers that are mapped to $D600 
; (address register) and $D601 (data register).

VDCZADDRREG:  EQU     $D600
VDCZDATAREG:  EQU     $D601

; Early C128 machines came with 16K of VDCZ RAM, expandable to 64K by added 
; three additional 16K chips. Later models (C128, C128CR) had 64K RAM. The 
; VDCZ is configured to use 16K or 64K modules, and we can check that configuration 
; by reading bit 4 of register 28:
;
;  :SetBankConfiguration(15)  // set bank 15
;  ldx #28
;  jsr READ_VDCZ
;  sta $fb
;  lda #010000
;  bit $fb
;  bne small
;  lda #$31
;  jsr $ffd2
;  rts
; small:
;  lda #$30
;  jsr $ffd2
;  rts

; The following procedures must be used to read/write from the VDCZ RAM:
;
;  - put the required register # in the address register;
;  - wait for the ready bit in the address register to go high;
;  - store or load the value from the data register;

; Write a value to a VDCZ register
;   - IXH : register
;   - IXL : value
VDCZWRITE:
    PUSH AF
    PUSH BC
    LD A, IXH
    ; LD (VDCZADDRREG), A
    LD BC, VDCZADDRREG
    OUT (C), A
VDCZWRITEL1:
    ; LD A, (VDCZADDRREG)
    IN A, (C)
    AND $80
    CMP $0
    JR Z, VDCZWRITEL1
    LD A, IXL
    ; LD (VDCZDATAREG), A
    LD BC, VDCZDATAREG
    OUT (C), A
    POP BC
    POP AF
    RET

; Read a value from a VDCZ register
;   - IXH : register
;   - A : value
VDCZREAD:
    PUSH BC
    LD A, IXH
    ; LD (VDCZADDRREG), A
    LD BC, VDCZADDRREG
    OUT (C), A
VDCZREADL1:
    ; LD A, (VDCZADDRREG)
    IN A, (C)
    AND $80
    CMP $0
    JR Z, VDCZREADL1
    ; LD A, (VDCZDATAREG)
    LD BC, VDCZDATAREG
    IN A, (C)
    POP BC
    RET

; Writing to the VDCZ RAM takes two steps:
;  - Set the update address where you want to write to;
;  - Pass data through the internal data register of the VDCZ (register 31);
;
; This is the macro to set the update address:
;   - IY : address to set
VDCZSETADDR:
    PUSH AF
    LD A, 19
    LD IXH, A
    LD A, IYL
    LD IXL, A
    CALL VDCZWRITE
    LD A, 18
    LD IXH, A
    LD A, IYH
    LD IXL, A
    CALL VDCZWRITE
    POP AF
    RET

; Matrix Data
;
; The Matrix data area in the VDCZ is located at $0000-$07FF by default. 
; It's function is the same as screen memory in the C128 main memory map 
; ($0400 by default).  As we have 80 characters in a row, it takes 
; 2000 bytes, as opposed to the 1000 bytes on the 40 column display.
; The address in VDCZ RAM can be retrieved by reading registers 12 and 13. 
; You can also change the address of the matrix data by writing a new value 
; to these registers. This macro will read the current setting, and store 
; it in $FB and $FC:
;

; Get VDCZ display start
;   - IY : display
VDCZGETDISPLAYDSTART:
    LD IXH, 12
    CALL VDCZREAD
    LD IYH, A
    
    LD IXH, 13
    CALL VDCZREAD
    LD IYL, A

    RET

; Writing to this RAM:
;   - DE : address
;   - A : value
VDCZPUTCHAR:
    PUSH DE
    POP IY
    CALL VDCZSETADDR
    LD IXH, 31
    LD IXL, A
    CALL VDCZWRITE
    RET

; Reading from this RAM:
;   - DE : address
;   - A : value
VDCZGETCHAR:
    PUSH DE
    POP IY
    CALL VDCZSETADDR
    LD IXH, 31
    CALL VDCZREAD
    RET

VDCZSTARTUP:
    RET

VDCZVIDEOSTARTUP:
	RET
