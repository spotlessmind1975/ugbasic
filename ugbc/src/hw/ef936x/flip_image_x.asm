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
;*                          FLIP X ROUTINE FOR EF936X                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

FLIPIMAGEDATA1
   fcb $00, $80, $40, $c0, $20, $a0, $60, $e0
   fcb $10, $90, $50, $d0, $30, $b0, $70, $f0
   fcb $08, $88, $48, $c8, $28, $a8, $68, $e8
   fcb $18, $98, $58, $d8, $38, $b8, $78, $f8
   fcb $04, $84, $44, $c4, $24, $a4, $64, $e4
   fcb $14, $94, $54, $d4, $34, $b4, $74, $f4
   fcb $0c, $8c, $4c, $cc, $2c, $ac, $6c, $ec
   fcb $1c, $9c, $5c, $dc, $3c, $bc, $7c, $fc
   fcb $02, $82, $42, $c2, $22, $a2, $62, $e2
   fcb $12, $92, $52, $d2, $32, $b2, $72, $f2
   fcb $0a, $8a, $4a, $ca, $2a, $aa, $6a, $ea
   fcb $1a, $9a, $5a, $da, $3a, $ba, $7a, $fa
   fcb $06, $86, $46, $c6, $26, $a6, $66, $e6
   fcb $16, $96, $56, $d6, $36, $b6, $76, $f6
   fcb $0e, $8e, $4e, $ce, $2e, $ae, $6e, $ee
   fcb $1e, $9e, $5e, $de, $3e, $be, $7e, $fe
   fcb $01, $81, $41, $c1, $21, $a1, $61, $e1
   fcb $11, $91, $51, $d1, $31, $b1, $71, $f1
   fcb $09, $89, $49, $c9, $29, $a9, $69, $e9
   fcb $19, $99, $59, $d9, $39, $b9, $79, $f9
   fcb $05, $85, $45, $c5, $25, $a5, $65, $e5
   fcb $15, $95, $55, $d5, $35, $b5, $75, $f5
   fcb $0d, $8d, $4d, $cd, $2d, $ad, $6d, $ed
   fcb $1d, $9d, $5d, $dd, $3d, $bd, $7d, $fd
   fcb $03, $83, $43, $c3, $23, $a3, $63, $e3
   fcb $13, $93, $53, $d3, $33, $b3, $73, $f3
   fcb $0b, $8b, $4b, $cb, $2b, $ab, $6b, $eb
   fcb $1b, $9b, $5b, $db, $3b, $bb, $7b, $fb
   fcb $07, $87, $47, $c7, $27, $a7, $67, $e7
   fcb $17, $97, $57, $d7, $37, $b7, $77, $f7
   fcb $0f, $8f, $4f, $cf, $2f, $af, $6f, $ef
   fcb $1f, $9f, $5f, $df, $3f, $bf, $7f, $ff

FLIPIMAGEDATA2
   fcb $00, $40, $80, $c0, $10, $50, $90, $d0
   fcb $20, $60, $a0, $e0, $30, $70, $b0, $f0
   fcb $04, $44, $84, $c4, $14, $54, $94, $d4
   fcb $24, $64, $a4, $e4, $34, $74, $b4, $f4
   fcb $08, $48, $88, $c8, $18, $58, $98, $d8
   fcb $28, $68, $a8, $e8, $38, $78, $b8, $f8
   fcb $0c, $4c, $8c, $cc, $1c, $5c, $9c, $dc
   fcb $2c, $6c, $ac, $ec, $3c, $7c, $bc, $fc
   fcb $01, $41, $81, $c1, $11, $51, $91, $d1
   fcb $21, $61, $a1, $e1, $31, $71, $b1, $f1
   fcb $05, $45, $85, $c5, $15, $55, $95, $d5
   fcb $25, $65, $a5, $e5, $35, $75, $b5, $f5
   fcb $09, $49, $89, $c9, $19, $59, $99, $d9
   fcb $29, $69, $a9, $e9, $39, $79, $b9, $f9
   fcb $0d, $4d, $8d, $cd, $1d, $5d, $9d, $dd
   fcb $2d, $6d, $ad, $ed, $3d, $7d, $bd, $fd
   fcb $02, $42, $82, $c2, $12, $52, $92, $d2
   fcb $22, $62, $a2, $e2, $32, $72, $b2, $f2
   fcb $06, $46, $86, $c6, $16, $56, $96, $d6
   fcb $26, $66, $a6, $e6, $36, $76, $b6, $f6
   fcb $0a, $4a, $8a, $ca, $1a, $5a, $9a, $da
   fcb $2a, $6a, $aa, $ea, $3a, $7a, $ba, $fa
   fcb $0e, $4e, $8e, $ce, $1e, $5e, $9e, $de
   fcb $2e, $6e, $ae, $ee, $3e, $7e, $be, $fe
   fcb $03, $43, $83, $c3, $13, $53, $93, $d3
   fcb $23, $63, $a3, $e3, $33, $73, $b3, $f3
   fcb $07, $47, $87, $c7, $17, $57, $97, $d7
   fcb $27, $67, $a7, $e7, $37, $77, $b7, $f7
   fcb $0b, $4b, $8b, $cb, $1b, $5b, $9b, $db
   fcb $2b, $6b, $ab, $eb, $3b, $7b, $bb, $fb
   fcb $0f, $4f, $8f, $cf, $1f, $5f, $9f, $df
   fcb $2f, $6f, $af, $ef, $3f, $7f, $bf, $ff

FLIPIMAGEDATA4
   fcb $00, $10, $20, $30, $40, $50, $60, $70
   fcb $80, $90, $a0, $b0, $c0, $d0, $e0, $f0
   fcb $01, $11, $21, $31, $41, $51, $61, $71
   fcb $81, $91, $a1, $b1, $c1, $d1, $e1, $f1
   fcb $02, $12, $22, $32, $42, $52, $62, $72
   fcb $82, $92, $a2, $b2, $c2, $d2, $e2, $f2
   fcb $03, $13, $23, $33, $43, $53, $63, $73
   fcb $83, $93, $a3, $b3, $c3, $d3, $e3, $f3
   fcb $04, $14, $24, $34, $44, $54, $64, $74
   fcb $84, $94, $a4, $b4, $c4, $d4, $e4, $f4
   fcb $05, $15, $25, $35, $45, $55, $65, $75
   fcb $85, $95, $a5, $b5, $c5, $d5, $e5, $f5
   fcb $06, $16, $26, $36, $46, $56, $66, $76
   fcb $86, $96, $a6, $b6, $c6, $d6, $e6, $f6
   fcb $07, $17, $27, $37, $47, $57, $67, $77
   fcb $87, $97, $a7, $b7, $c7, $d7, $e7, $f7
   fcb $08, $18, $28, $38, $48, $58, $68, $78
   fcb $88, $98, $a8, $b8, $c8, $d8, $e8, $f8
   fcb $09, $19, $29, $39, $49, $59, $69, $79
   fcb $89, $99, $a9, $b9, $c9, $d9, $e9, $f9
   fcb $0a, $1a, $2a, $3a, $4a, $5a, $6a, $7a
   fcb $8a, $9a, $aa, $ba, $ca, $da, $ea, $fa
   fcb $0b, $1b, $2b, $3b, $4b, $5b, $6b, $7b
   fcb $8b, $9b, $ab, $bb, $cb, $db, $eb, $fb
   fcb $0c, $1c, $2c, $3c, $4c, $5c, $6c, $7c
   fcb $8c, $9c, $ac, $bc, $cc, $dc, $ec, $fc
   fcb $0d, $1d, $2d, $3d, $4d, $5d, $6d, $7d
   fcb $8d, $9d, $ad, $bd, $cd, $dd, $ed, $fd
   fcb $0e, $1e, $2e, $3e, $4e, $5e, $6e, $7e
   fcb $8e, $9e, $ae, $be, $ce, $de, $ee, $fe
   fcb $0f, $1f, $2f, $3f, $4f, $5f, $6f, $7f
   fcb $8f, $9f, $af, $bf, $cf, $df, $ef, $ff

FLIPTMP
    fcb $00, $00

; ----------------------------------------------------------------------------
; - Flip image
; ----------------------------------------------------------------------------

FLIPIMAGEX

@IF vestigialConfig.screenModeUnique

@ELSE

    LDA CURRENTMODE
    CMPA #0
    BNE FLIPIMAGEX0X
    JMP FLIPIMAGEX0
FLIPIMAGEX0X
    CMPA #1
    BNE FLIPIMAGEX1X
    JMP FLIPIMAGEX1
FLIPIMAGEX1X
    CMPA #2
    BNE FLIPIMAGEX2X
    JMP FLIPIMAGEX2
FLIPIMAGEX2X
    CMPA #3
    BNE FLIPIMAGEX3X
    JMP FLIPIMAGEX3
FLIPIMAGEX3X
    CMPA #4
    BNE FLIPIMAGEX4X
    JMP FLIPIMAGEX4
FLIPIMAGEX4X
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 1 ) )

FLIPIMAGEX1
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 4 ) )

FLIPIMAGEX4
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 0 ) || ( currentMode == 2 ) )

FLIPIMAGEX0
FLIPIMAGEX2

    ORCC #$50

    ; Retrieve the precalculated matrix for 2 bit colors

    LDU #FLIPIMAGEDATA1

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDD , Y
    STD <IMAGEW
    LSR <IMAGEW
    ROR <IMAGEW+1
    LSR <IMAGEW
    ROR <IMAGEW+1
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    ; Move the image pointer ahead of header.

    LEAY 3, Y

    ; This is the beginning of the line flip loop.

FLIPIMAGEXCOMMONCL0

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDD <IMAGEW
    LSRA
    RORB
    LEAX D, X
    LEAX -1, X

    ; Loop in both directions
    ; <TMPPTR ---->
    ;        <---- <TMPPTR2

    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW2

FLIPIMAGEXCOMMONCL1
    CLRA
    ; Take first left byte and invert it.
    LDB , Y
    LDB D, U
    ; Save it on the stack.
    PSHS D
    ; Take first right byte and invert it.
    LDB , X
    LDB D, U
    STB , Y
    ; Store it on the first left byte.
    ; Store the one stacked on the first right byte.
    PULS D
    STB , X

    ; Move back the <TMPPTR2 pointer.

    LEAX -1, X

FLIPIMAGEXCOMMONCL1A

    ; Move ahead the <TMPPTR pointer.

    LEAY 1, Y

FLIPIMAGEXCOMMONCL1B

    ; Decrement the number of bytes to flip.

    LDD <IMAGEW2
    SUBD #1
    STD <IMAGEW2

    ; If not finished, repeat the loop.

    BNE FLIPIMAGEXCOMMONCL1

    STX FLIPTMP
    CMPY FLIPTMP

    BNE FLIPIMAGEXCOMMONCNEXTLINE

    CLRA
    LDB , Y
    LDB D, U
    STB , Y

    LEAX 1, Y

    ; Move to the next line.
FLIPIMAGEXCOMMONCNEXTLINE
    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    LEAY D, Y

    ; Decrement the number of line flipped.

    DEC <IMAGEH

    ; If there are lines to flip, repeat the loop.

    LDA <IMAGEH
    BEQ FLIPIMAGEXCOMMONCL0XX
    JMP FLIPIMAGEXCOMMONCL0

FLIPIMAGEXCOMMONCL0XX

    LDA <IMAGEH2
    STA <IMAGEH

FLIPIMAGE2XCOMMONCL0X2

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDD <IMAGEW
    LSRA
    RORB
    LEAX D, X
    LEAX -1, X

    ; Loop in both directions
    ; <TMPPTR ---->
    ;        <---- <TMPPTR2

    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW2

FLIPIMAGE2XCOMMONCL1
    CLRA
    ; Take first left byte and invert it.
    LDB , Y
    LDB D, U
    ; Save it on the stack.
    PSHS D
    ; Take first right byte and invert it.
    LDB , X
    LDB D, U
    STB , Y
    ; Store it on the first left byte.
    ; Store the one stacked on the first right byte.
    PULS D
    STB , X

    ; Move back the <TMPPTR2 pointer.

    LEAX -1, X

FLIPIMAGE2XCOMMONCL1A

    ; Move ahead the <TMPPTR pointer.

    LEAY 1, Y

FLIPIMAGE2XCOMMONCL1B

    ; Decrement the number of bytes to flip.

    LDD <IMAGEW2
    SUBD #1
    STD <IMAGEW2

    ; If not finished, repeat the loop.

    BNE FLIPIMAGE2XCOMMONCL1

    STX FLIPTMP
    CMPY FLIPTMP

    BNE FLIPIMAGE2XCOMMONCNEXTLINE

    CLRA
    LDB , Y
    LDB D, U
    STB , Y

    LEAX 1, Y

    ; Move to the next line.
FLIPIMAGE2XCOMMONCNEXTLINE
    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    LEAY D, Y

    ; Decrement the number of line flipped.

    DEC <IMAGEH

    ; If there are lines to flip, repeat the loop.

    LDA <IMAGEH
    BEQ FLIPIMAGE2XCOMMONCL0X
    JMP FLIPIMAGE2XCOMMONCL0X2

FLIPIMAGE2XCOMMONCL0X

    ANDCC #$AF

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 3 ) )

FLIPIMAGEX3

    ORCC #$50
    
    PSHS Y

    ; Retrieve the precalculated matrix for 2 bit colors

    LDU #FLIPIMAGEDATA4

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDD , Y
    STD <IMAGEW
    LSR <IMAGEW
    ROR <IMAGEW+1
    LDA 2,Y
    STA <IMAGEH
    STA <IMAGEH2

    ; Move the image pointer ahead of header.

    LEAY 3, Y

    ; This is the beginning of the line flip loop.

FLIPIMAGEX3COMMONCL0

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDD <IMAGEW
    LSRA
    RORB
    LEAX D, X
    LEAX -1, X

    ; Loop in both directions
    ; <TMPPTR ---->
    ;        <---- <TMPPTR2

    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW2

FLIPIMAGEX3COMMONCL1
    CLRA
    ; Take first left byte and invert it.
    LDB , Y
    LDB D, U
    ; Save it on the stack.
    PSHS D
    ; Take first right byte and invert it.
    LDB , X
    LDB D, U
    STB , Y
    ; Store it on the first left byte.
    ; Store the one stacked on the first right byte.
    PULS D
    STB , X

    ; Move back the <TMPPTR2 pointer.

    LEAX -1, X

FLIPIMAGEX3COMMONCL1A

    ; Move ahead the <TMPPTR pointer.

    LEAY 1, Y

FLIPIMAGEX3COMMONCL1B

    ; Decrement the number of bytes to flip.

    LDD <IMAGEW2
    SUBD #1
    STD <IMAGEW2

    ; If not finished, repeat the loop.

    BNE FLIPIMAGEX3COMMONCL1

    STX FLIPTMP
    CMPY FLIPTMP

    BNE FLIPIMAGEX3COMMONCNEXTLINE

    CLRA
    LDB , Y
    LDB D, U
    STB , Y

    LEAX 1, Y

    ; Move to the next line.
FLIPIMAGEX3COMMONCNEXTLINE
    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    LEAY D, Y

    ; Decrement the number of line flipped.

    DEC <IMAGEH

    ; If there are lines to flip, repeat the loop.

    LDA <IMAGEH
    BEQ FLIPIMAGEX3COMMONCL0XX
    JMP FLIPIMAGEX3COMMONCL0

FLIPIMAGEX3COMMONCL0XX

    LDA <IMAGEH2
    STA <IMAGEH

FLIPIMAGE3XCOMMONCL0X2

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDD <IMAGEW
    LSRA
    RORB
    LEAX D, X
    LEAX -1, X

    ; Loop in both directions
    ; <TMPPTR ---->
    ;        <---- <TMPPTR2

    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    STD <IMAGEW2

FLIPIMAGE3XCOMMONCL1
    CLRA
    ; Take first left byte and invert it.
    LDB , Y
    LDB D, U
    ; Save it on the stack.
    PSHS D
    ; Take first right byte and invert it.
    LDB , X
    LDB D, U
    STB , Y
    ; Store it on the first left byte.
    ; Store the one stacked on the first right byte.
    PULS D
    STB , X

    ; Move back the <TMPPTR2 pointer.

    LEAX -1, X

FLIPIMAGE3XCOMMONCL1A

    ; Move ahead the <TMPPTR pointer.

    LEAY 1, Y

FLIPIMAGE3XCOMMONCL1B

    ; Decrement the number of bytes to flip.

    LDD <IMAGEW2
    SUBD #1
    STD <IMAGEW2

    ; If not finished, repeat the loop.

    BNE FLIPIMAGE3XCOMMONCL1

    STX FLIPTMP
    CMPY FLIPTMP

    BNE FLIPIMAGE3XCOMMONCNEXTLINE

    CLRA
    LDB , Y
    LDB D, U
    STB , Y

    LEAX 1, Y

    ; Move to the next line.
FLIPIMAGE3XCOMMONCNEXTLINE
    LDD <IMAGEW
    LSRA
    RORB
    LSRA
    RORB
    LEAY D, Y

    ; Decrement the number of line flipped.

    DEC <IMAGEH

    ; If there are lines to flip, repeat the loop.

    LDA <IMAGEH
    BEQ FLIPIMAGE3XCOMMONCL0X
    JMP FLIPIMAGE3XCOMMONCL0X2

FLIPIMAGE3XCOMMONCL0X

;;;;;;;;;;;;;;;;;;;;;

    LDA <IMAGEH2
    STA <IMAGEH

FLIPIMAGE3XCOMMONCL0X2V

    PULS Y
    LEAY 3,Y

    ; Copy the starting line pointer to the ending line pointer.

    TFR Y, X

    LDA <(IMAGEW+1)
    LDB <IMAGEH
    MUL
    LSRA
    RORB
    LEAX D, X

    TFR D, U

FLIPIMAGE3XCOMMONCL1V
    CLRA
    ; Take first left byte and invert it.
    LDB , Y
    LDA , X
    STB , X
    STA , Y

    ; Move back the <TMPPTR2 pointer.

    LEAX 1, X

FLIPIMAGE3XCOMMONCL1AV

    ; Move ahead the <TMPPTR pointer.

    LEAY 1, Y

FLIPIMAGE3XCOMMONCL1BV

    ; Decrement the number of bytes to flip.

    LEAU -1, U

    CMPU #0

    ; If not finished, repeat the loop.

    BNE FLIPIMAGE3XCOMMONCL1V

FLIPIMAGE3XCOMMONCL0XV
    RTS

@ENDIF

