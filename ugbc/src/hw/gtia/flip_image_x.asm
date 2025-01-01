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
;*                          FLIP X ROUTINE FOR GTIA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FLIPIMAGEDATA1:
   .BYTE $00, $80, $40, $c0, $20, $a0, $60, $e0
   .BYTE $10, $90, $50, $d0, $30, $b0, $70, $f0
   .BYTE $08, $88, $48, $c8, $28, $a8, $68, $e8
   .BYTE $18, $98, $58, $d8, $38, $b8, $78, $f8
   .BYTE $04, $84, $44, $c4, $24, $a4, $64, $e4
   .BYTE $14, $94, $54, $d4, $34, $b4, $74, $f4
   .BYTE $0c, $8c, $4c, $cc, $2c, $ac, $6c, $ec
   .BYTE $1c, $9c, $5c, $dc, $3c, $bc, $7c, $fc
   .BYTE $02, $82, $42, $c2, $22, $a2, $62, $e2
   .BYTE $12, $92, $52, $d2, $32, $b2, $72, $f2
   .BYTE $0a, $8a, $4a, $ca, $2a, $aa, $6a, $ea
   .BYTE $1a, $9a, $5a, $da, $3a, $ba, $7a, $fa
   .BYTE $06, $86, $46, $c6, $26, $a6, $66, $e6
   .BYTE $16, $96, $56, $d6, $36, $b6, $76, $f6
   .BYTE $0e, $8e, $4e, $ce, $2e, $ae, $6e, $ee
   .BYTE $1e, $9e, $5e, $de, $3e, $be, $7e, $fe
   .BYTE $01, $81, $41, $c1, $21, $a1, $61, $e1
   .BYTE $11, $91, $51, $d1, $31, $b1, $71, $f1
   .BYTE $09, $89, $49, $c9, $29, $a9, $69, $e9
   .BYTE $19, $99, $59, $d9, $39, $b9, $79, $f9
   .BYTE $05, $85, $45, $c5, $25, $a5, $65, $e5
   .BYTE $15, $95, $55, $d5, $35, $b5, $75, $f5
   .BYTE $0d, $8d, $4d, $cd, $2d, $ad, $6d, $ed
   .BYTE $1d, $9d, $5d, $dd, $3d, $bd, $7d, $fd
   .BYTE $03, $83, $43, $c3, $23, $a3, $63, $e3
   .BYTE $13, $93, $53, $d3, $33, $b3, $73, $f3
   .BYTE $0b, $8b, $4b, $cb, $2b, $ab, $6b, $eb
   .BYTE $1b, $9b, $5b, $db, $3b, $bb, $7b, $fb
   .BYTE $07, $87, $47, $c7, $27, $a7, $67, $e7
   .BYTE $17, $97, $57, $d7, $37, $b7, $77, $f7
   .BYTE $0f, $8f, $4f, $cf, $2f, $af, $6f, $ef
   .BYTE $1f, $9f, $5f, $df, $3f, $bf, $7f, $ff

FLIPIMAGEDATA2:
   .BYTE $00, $40, $80, $c0, $10, $50, $90, $d0
   .BYTE $20, $60, $a0, $e0, $30, $70, $b0, $f0
   .BYTE $04, $44, $84, $c4, $14, $54, $94, $d4
   .BYTE $24, $64, $a4, $e4, $34, $74, $b4, $f4
   .BYTE $08, $48, $88, $c8, $18, $58, $98, $d8
   .BYTE $28, $68, $a8, $e8, $38, $78, $b8, $f8
   .BYTE $0c, $4c, $8c, $cc, $1c, $5c, $9c, $dc
   .BYTE $2c, $6c, $ac, $ec, $3c, $7c, $bc, $fc
   .BYTE $01, $41, $81, $c1, $11, $51, $91, $d1
   .BYTE $21, $61, $a1, $e1, $31, $71, $b1, $f1
   .BYTE $05, $45, $85, $c5, $15, $55, $95, $d5
   .BYTE $25, $65, $a5, $e5, $35, $75, $b5, $f5
   .BYTE $09, $49, $89, $c9, $19, $59, $99, $d9
   .BYTE $29, $69, $a9, $e9, $39, $79, $b9, $f9
   .BYTE $0d, $4d, $8d, $cd, $1d, $5d, $9d, $dd
   .BYTE $2d, $6d, $ad, $ed, $3d, $7d, $bd, $fd
   .BYTE $02, $42, $82, $c2, $12, $52, $92, $d2
   .BYTE $22, $62, $a2, $e2, $32, $72, $b2, $f2
   .BYTE $06, $46, $86, $c6, $16, $56, $96, $d6
   .BYTE $26, $66, $a6, $e6, $36, $76, $b6, $f6
   .BYTE $0a, $4a, $8a, $ca, $1a, $5a, $9a, $da
   .BYTE $2a, $6a, $aa, $ea, $3a, $7a, $ba, $fa
   .BYTE $0e, $4e, $8e, $ce, $1e, $5e, $9e, $de
   .BYTE $2e, $6e, $ae, $ee, $3e, $7e, $be, $fe
   .BYTE $03, $43, $83, $c3, $13, $53, $93, $d3
   .BYTE $23, $63, $a3, $e3, $33, $73, $b3, $f3
   .BYTE $07, $47, $87, $c7, $17, $57, $97, $d7
   .BYTE $27, $67, $a7, $e7, $37, $77, $b7, $f7
   .BYTE $0b, $4b, $8b, $cb, $1b, $5b, $9b, $db
   .BYTE $2b, $6b, $ab, $eb, $3b, $7b, $bb, $fb
   .BYTE $0f, $4f, $8f, $cf, $1f, $5f, $9f, $df
   .BYTE $2f, $6f, $af, $ef, $3f, $7f, $bf, $ff


; ----------------------------------------------------------------------------
; - Flip image
; ----------------------------------------------------------------------------

FLIPIMAGEX:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE FLIPIMAGEX8X
    JMP FLIPIMAGEX8
FLIPIMAGEX8X:
    CMP #9
    BNE FLIPIMAGEX9X
    JMP FLIPIMAGEX9
FLIPIMAGEX9X:
    CMP #10
    BNE FLIPIMAGEX10X
    JMP FLIPIMAGEX10
FLIPIMAGEX10X:
    CMP #11
    BNE FLIPIMAGEX11X
    JMP FLIPIMAGEX11
FLIPIMAGEX11X:
    CMP #13
    BNE FLIPIMAGEX13X
    JMP FLIPIMAGEX13
FLIPIMAGEX13X:
    CMP #15
    BNE FLIPIMAGEX15X
    JMP FLIPIMAGEX15
FLIPIMAGEX15X:
    CMP #12
    BNE FLIPIMAGEX12X
    JMP FLIPIMAGEX12
FLIPIMAGEX12X:
    CMP #14
    BNE FLIPIMAGEX14X
    JMP FLIPIMAGEX14
FLIPIMAGEX14X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

FLIPIMAGEX9:
    JMP FLIPIMAGEXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

FLIPIMAGEX11:
    JMP FLIPIMAGEXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

FLIPIMAGEX15:

    JMP FLIPIMAGEXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

FLIPIMAGEX12:

    JMP FLIPIMAGEXCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

FLIPIMAGEX8:

    JMP FLIPIMAGEXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

FLIPIMAGEX10:

    JMP FLIPIMAGEXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

FLIPIMAGEX13:

    JMP FLIPIMAGEXCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

FLIPIMAGEX14:

    JMP FLIPIMAGEXCOMMONC

@ENDIF

FLIPIMAGEXCOMMON:

    ; Retrieve the precalculated matrix for 2 bit colors

    LDA #<FLIPIMAGEDATA1
    STA MATHPTR0
    LDA #>FLIPIMAGEDATA1
    STA MATHPTR0+1

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (TMPPTR),Y
    STA IMAGEH
    STA IMAGEH2

    ; Move the image pointer ahead of header.

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; This is the beginning of the line flip loop.

    JMP FLIPIMAGEXCOMMONCL0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

FLIPIMAGEXCOMMONC:

    ; Retrieve the precalculated matrix for 2 bit colors

    LDA #<FLIPIMAGEDATA2
    STA MATHPTR0
    LDA #>FLIPIMAGEDATA2
    STA MATHPTR0+1

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (TMPPTR),Y
    STA IMAGEH
    STA IMAGEH2

    ; Move the image pointer ahead of header.

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; This is the beginning of the line flip loop.

FLIPIMAGEXCOMMONCL0:

    ; Copy the starting line pointer to the ending line pointer.

    LDA TMPPTR
    STA TMPPTR2
    LDA TMPPTR+1
    STA TMPPTR2+1

    ; Move ahead the ending line pointer of 2 x IMAGE WIDTH - 1

    CLC
    LDA TMPPTR2
    ADC IMAGEW
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC IMAGEW+1
    STA TMPPTR2+1

    SEC
    LDA TMPPTR2
    SBC #1
    STA TMPPTR2
    LDA TMPPTR2+1
    SBC #0
    STA TMPPTR2+1

    ; Loop in both directions
    ; TMPPTR ---->
    ;        <---- TMPPTR2

    LDA IMAGEW
    LSR
    STA IMAGEW2
    TAX 

FLIPIMAGEXCOMMONCL1:
    ; Take first left byte and invert it.
    LDY #0
    LDA (TMPPTR),Y
    TAY
    LDA (MATHPTR0),Y
    ; Save it on the stack.
    PHA
    ; Take first right byte and invert it.
    LDY #0
    LDA (TMPPTR2),Y
    TAY
    LDA (MATHPTR0),Y
    ; Store it on the first left byte.
    LDY #0
    STA (TMPPTR),Y
    ; Store the one stacked on the first right byte.
    PLA
    STA (TMPPTR2),Y

    ; Move back the TMPPTR2 pointer.

    DEC TMPPTR2
    LDA TMPPTR2
    CMP #$FF
    BNE FLIPIMAGEXCOMMONCL1A
    DEC TMPPTR2+1
FLIPIMAGEXCOMMONCL1A:

    ; Move ahead the TMPPTR pointer.

    INC TMPPTR
    BNE FLIPIMAGEXCOMMONCL1B
    INC TMPPTR+1
FLIPIMAGEXCOMMONCL1B:

    ; Decrement the number of bytes to flip.

    DEX

    ; If not finished, repeat the loop.

    BNE FLIPIMAGEXCOMMONCL1

    LDA TMPPTR
    CMP TMPPTR2
    BNE FLIPIMAGEXCOMMONCNEXTLINE

    LDY #0
    LDA (TMPPTR),Y
    TAY
    LDA (MATHPTR0),Y
    STA (TMPPTR),Y

    CLC
    LDA TMPPTR
    ADC #1
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Move to the next line.
FLIPIMAGEXCOMMONCNEXTLINE:
    CLC
    LDA TMPPTR
    ADC IMAGEW2
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; Decrement the number of line flipped.

    DEC IMAGEH

    ; If there are lines to flip, repeat the loop.

    LDA IMAGEH
    BEQ FLIPIMAGEXCOMMONCL0X
    JMP FLIPIMAGEXCOMMONCL0

FLIPIMAGEXCOMMONCL0X:
    RTS



