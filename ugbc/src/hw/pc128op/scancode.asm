; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
;*                      KEYBOARD MATRIX DETECTION ON THOMSON MO5/MO6           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODETBL
    FCB $76, $78, $7A, $7C, $7E
    FCB $30, $6E, $5E, $4E, $3E, $2E, $1E, $0E
    FCB      $6C, $5C, $4C, $3C, $2C, $1C, $0C, $62
    FCB      $6A, $5A, $4A, $3A, $2A, $1A, $0A
    FCB      $68, $58, $48, $38, $28, $18, $08, $52, $32
    FCB $66, $22, $56, $46, $36, $26, $16, $06
    FCB                     $34, $24, $14, $04, $68, $42
    FCB $80, $60, $50, $64, $54, $44, $00, $10, $20, $30
    FCB $72, $12, $02, $40

    FCB     $FF

KEYPRESSED
    STA $A7C1
    LDA $A7C1
    ANDA #$80
    CMPA #$80
    RTS
    
SCANCODE
    CLRB
    LDX #SCANCODETBL
    LDA B, X
SCANCODEL1
    JSR KEYPRESSED
    BEQ SCANCODEL2
    LDA B, X
    TFR A, B
    RTS

SCANCODEL2
    INCB
    LDA B, X
    CMPA #$FF
    BNE SCANCODEL1
    LDB #$FF
    RTS

KEYBOARDTBL
    ; $0x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     'N', $00, $00, $00, 'J', $00, 'H', $00, 'U', $00, 'Y', $00, '7', $00, '6', $00
    ; $1x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     $00, $00, $00, $00, 'K', $00, 'G', $00, 'I', $00, 'T', $00, '8', $00, '5', $00
    ; $2x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     '.', $00, $00, $00, 'L', $00, 'F', $00, 'O', $00, 'R', $00, '9', $00, '4', $00
    ; $3x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     '@', $00, $00, $00, 'M', $00, 'D', $00, 'P', $00, 'E', $00, '0', $00, '3', $00
    ; $4x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     ' ', $00, $00, $00, 'B', $00, 'S', $00, '/', $00, 'Z', $00, '-', $00, '2', $00
    ; $5x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     'X', $00, $00, $00, 'V', $00, 'Q', $00, '*', $00, 'A', $00, '+', $00, '1', $00
    ; $6x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     'W', $00, $00, $00, 'C', $00, $00, $00, $0d, $00, $00, $00, $00, $00, $00, $00
    ; $7x     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
    FCB     $00, $00, $00, $00, 'C', $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

INKEY
    JSR SCANCODE
    CMPB #$FF
    BEQ INKEYDONE
    LDX #KEYBOARDTBL
    ANDB #$7F
    LDA B, X
    TFR A, B
    RTS

INKEYDONE
    LDB #$00
    RTS
